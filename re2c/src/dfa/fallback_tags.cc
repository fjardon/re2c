#include "src/dfa/dfa.h"

namespace re2c
{

static void find_overwritten_tags(const dfa_t &dfa, size_t state, bool *been, bool *owrt);

/* note [fallback tags]
 *
 * We need to backup tags in fallback states, because they may be
 * overwritten on some non-accepting path from fallback state.
 * Two different things may cause overwrites:
 *
 * (1) self-overlapping rules: if DFA has tagged cycles, new iteration
 *     may overwrite tags from previous iteration and then fail
 *
 * (2) overlapping rules: intially all rules have different tags, but
 *     optiizations may merge them; then shorter rule's tags may be
 *     overwritten by an unsuccessful attempt to match longer rule
 *
 * In case (2) we can prevent merging by propagating tag liveness on
 * all non-accepting paths from fallback state.
 *
 * Case (1) is not so easy: overwrites are already embedded in DFA.
 * We have to create backup copies for all potentially overwritten
 * tags. If tag is overwritten on just one path, it should be backed
 * up on all non-accepting paths from fallback state (because paths
 * may join later along the way and they need common tag version).
 * However, redundant backups cause artificial interference, so we
 * only create backup if the origin is overwritten on some path.
 */

void find_overwritten_tags(const dfa_t &dfa, size_t state,
	bool *been, bool *owrt)
{
	if (been[state]) return;
	been[state] = true;

	const dfa_state_t *s = dfa.states[state];
	for (size_t c = 0; c < dfa.nchars; ++c) {
		for (const tcmd_t *p = s->tcmd[c]; p; p = p->next) {
			owrt[p->lhs] = true;
		}

		size_t dest = s->arcs[c];
		if (dest != dfa_t::NIL && dfa.states[dest]->fallthru) {
			find_overwritten_tags(dfa, dest, been, owrt);
		}
	}
}

// overwritten tags need 'copy' on all outgoing non-accepting paths
// ('copy' commands must go first, before potential overwrites)
static void backup(dfa_t &dfa, dfa_state_t *s, tagver_t l, tagver_t r)
{
	for (size_t c = 0; c < dfa.nchars; ++c) {
		size_t i = s->arcs[c];
		if (i != dfa_t::NIL && dfa.states[i]->fallthru) {
			tcmd_t *&p = s->tcmd[c];
			p = dfa.tcpool.make_copy(p, l, r);
		}
	}
}

// WARNING: this function assumes that falthrough and fallback
// attributes of DFA states have already been calculated, see
// note [fallback states]
void insert_fallback_tags(dfa_t &dfa)
{
	tcpool_t &pool = dfa.tcpool;
	const size_t
		nstates = dfa.states.size(),
		nsym = dfa.nchars,
		nver = static_cast<size_t>(dfa.maxtagver) + 1;
	bool *been = new bool[nstates];
	bool *owrt = new bool[nver];

	for (size_t i = 0; i < nstates; ++i) {
		dfa_state_t *s = dfa.states[i];
		if (!s->fallback) continue;

		std::fill(been, been + nstates, false);
		std::fill(owrt, owrt + nver, false);
		find_overwritten_tags(dfa, i, been, owrt);

		tcmd_t *p = s->tcmd[nsym], *f = NULL, *t = NULL, **pf;
		for (; p; p = p->next) {
			const tagver_t l = p->lhs, r = p->rhs, *h = p->history;

			// 'copy' commands
			if (tcmd_t::iscopy(p)) {
				if (!owrt[r]) {
					f = pool.make_copy(f, l, r);
				} else {
					backup(dfa, s, l, r);
				}

			// 'save without history' commands
			} else if (tcmd_t::isset(p)) {
				t = pool.make_set(t, l, h[0]);

			// 'save with history' commands
			} else {
				if (!owrt[r]) {
					t = pool.copy_add(t, l, r, h);
				} else {
					t = pool.copy_add(t, l, l, h);
					backup(dfa, s, l, r);
				}
			}
		}

		// join 'copy' (fallback) and 'save' commands
		for (pf = &f; *pf; pf = &(*pf)->next);
		*pf = t;
		s->tcmd[nsym + 1] = f;
	}

	delete[] been;
	delete[] owrt;
}

} // namespace re2c