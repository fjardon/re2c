#ifndef _RE2C_IR_RULE_
#define _RE2C_IR_RULE_

#include <set>
#include <string>
#include <vector>

#include "src/ir/ctx.h"
#include "src/parse/code.h"
#include "src/parse/loc.h"
#include "src/util/forbid_copy.h"

namespace re2c
{

struct RuleInfo
{
	const Loc loc;
	const Code *code;
	const std::string newcond;

	RuleInfo(const Loc &l, const Code *c,
		const std::string *cond)
		: loc(l)
		, code(c)
		, newcond(cond ? *cond : "")
	{}

	FORBID_COPY(RuleInfo);
};

struct Rule
{
	static const size_t NONE;

	const RuleInfo *info;

	std::vector<size_t> ctxvar;
	std::vector<CtxFix> ctxfix;
	Trail trail;
	bool nullable;

	std::set<uint32_t> shadow;
	bool reachable;

	explicit Rule(const RuleInfo *i)
		: info(i)
		, ctxvar()
		, ctxfix()
		, trail()
		, nullable(false)
		, shadow()
		, reachable(false)
	{}
	Rule (const Rule &rule)
		: info(rule.info)
		, ctxvar(rule.ctxvar)
		, ctxfix(rule.ctxfix)
		, trail(rule.trail)
		, nullable(rule.nullable)
		, shadow(rule.shadow)
		, reachable(rule.reachable)
	{}
	Rule& operator=(const Rule &rule)
	{
		info = rule.info;
		ctxvar = rule.ctxvar;
		ctxfix = rule.ctxfix;
		trail = rule.trail;
		nullable = rule.nullable;
		shadow = rule.shadow;
		reachable = rule.reachable;
		return *this;
	}

//	FORBID_COPY(Rule);
};

} // namespace re2c

#endif // _RE2C_IR_RULE_