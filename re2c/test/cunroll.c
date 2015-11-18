/* Generated by re2c */
#line 1 "cunroll.re"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define	ADDEQ	257
#define	ANDAND	258
#define	ANDEQ	259
#define	ARRAY	260
#define	ASM	261
#define	AUTO	262
#define	BREAK	263
#define	CASE	264
#define	CHAR	265
#define	CONST	266
#define	CONTINUE	267
#define	DECR	268
#define	DEFAULT	269
#define	DEREF	270
#define	DIVEQ	271
#define	DO	272
#define	DOUBLE	273
#define	ELLIPSIS	274
#define	ELSE	275
#define	ENUM	276
#define	EQL	277
#define	EXTERN	278
#define	FCON	279
#define	FLOAT	280
#define	FOR	281
#define	FUNCTION	282
#define	GEQ	283
#define	GOTO	284
#define	ICON	285
#define	ID	286
#define	IF	287
#define	INCR	288
#define	INT	289
#define	LEQ	290
#define	LONG	291
#define	LSHIFT	292
#define	LSHIFTEQ	293
#define	MODEQ	294
#define	MULEQ	295
#define	NEQ	296
#define	OREQ	297
#define	OROR	298
#define	POINTER	299
#define	REGISTER	300
#define	RETURN	301
#define	RSHIFT	302
#define	RSHIFTEQ	303
#define	SCON	304
#define	SHORT	305
#define	SIGNED	306
#define	SIZEOF	307
#define	STATIC	308
#define	STRUCT	309
#define	SUBEQ	310
#define	SWITCH	311
#define	TYPEDEF	312
#define	UNION	313
#define	UNSIGNED	314
#define	VOID	315
#define	VOLATILE	316
#define	WHILE	317
#define	XOREQ	318
#define	EOI	319

typedef unsigned int uint;
typedef unsigned char uchar;

#define	BSIZE	8192

#define	YYCTYPE		uchar
#define	YYCURSOR	cursor
#define	YYLIMIT		s->lim
#define	YYMARKER	s->ptr
#define	YYFILL(n)	{cursor = fill(s, cursor);}

#define	RET(i)	{s->cur = cursor; return i;}

typedef struct Scanner {
    int			fd;
    uchar		*bot, *tok, *ptr, *cur, *pos, *lim, *top, *eof;
    uint		line;
} Scanner;

uchar *fill(Scanner *s, uchar *cursor){
    if(!s->eof){
	uint cnt = s->tok - s->bot;
	if(cnt){
	    memcpy(s->bot, s->tok, s->lim - s->tok);
	    s->tok = s->bot;
	    s->ptr -= cnt;
	    cursor -= cnt;
	    s->pos -= cnt;
	    s->lim -= cnt;
	}
	if((s->top - s->lim) < BSIZE){
	    uchar *buf = (uchar*) malloc(((s->lim - s->bot) + BSIZE)*sizeof(uchar));
	    memcpy(buf, s->tok, s->lim - s->tok);
	    s->tok = buf;
	    s->ptr = &buf[s->ptr - s->bot];
	    cursor = &buf[cursor - s->bot];
	    s->pos = &buf[s->pos - s->bot];
	    s->lim = &buf[s->lim - s->bot];
	    s->top = &s->lim[BSIZE];
	    free(s->bot);
	    s->bot = buf;
	}
	if((cnt = read(s->fd, (char*) s->lim, BSIZE)) != BSIZE){
	    s->eof = &s->lim[cnt]; *(s->eof)++ = '\n';
	}
	s->lim += cnt;
    }
    return cursor;
}

int scan(Scanner *s){
	uchar *cursor = s->cur;
std:
	s->tok = cursor;
#line 135 "cunroll.re"



#line 130 "cunroll.c"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	if ((YYLIMIT - YYCURSOR) < 9) YYFILL(9);
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case '\v':
	case '\f':
	case ' ':	goto yy58;
	case '\n':	goto yy60;
	case '!':	goto yy34;
	case '"':	goto yy13;
	case '%':	goto yy24;
	case '&':	goto yy26;
	case '\'':	goto yy9;
	case '(':	goto yy46;
	case ')':	goto yy48;
	case '*':	goto yy22;
	case '+':	goto yy18;
	case ',':	goto yy42;
	case '-':	goto yy20;
	case '.':	goto yy11;
	case '/':	goto yy2;
	case '0':	goto yy6;
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy8;
	case ':':	goto yy44;
	case ';':	goto yy36;
	case '<':	goto yy16;
	case '=':	goto yy32;
	case '>':	goto yy14;
	case '?':	goto yy56;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy4;
	case '[':	goto yy50;
	case ']':	goto yy52;
	case '^':	goto yy28;
	case '{':	goto yy38;
	case '|':	goto yy30;
	case '}':	goto yy40;
	case '~':	goto yy54;
	default:	goto yy62;
	}
yy2:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '*':	goto yy183;
	case '=':	goto yy181;
	default:	goto yy3;
	}
yy3:
#line 200 "cunroll.re"
	{ RET('/'); }
#line 243 "cunroll.c"
yy4:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy164;
	default:	goto yy5;
	}
yy5:
#line 141 "cunroll.re"
	{ RET(ID); }
#line 315 "cunroll.c"
yy6:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy140;
	case 'X':
	case 'x':	goto yy157;
	default:	goto yy156;
	}
yy7:
#line 153 "cunroll.re"
	{ RET(ICON); }
#line 331 "cunroll.c"
yy8:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	goto yy138;
yy9:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\n':	goto yy10;
	default:	goto yy128;
	}
yy10:
#line 219 "cunroll.re"
	{
		printf("unexpected character: %c\n", *s->tok);
		goto std;
	    }
#line 349 "cunroll.c"
yy11:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '.':	goto yy116;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy117;
	default:	goto yy12;
	}
yy12:
#line 193 "cunroll.re"
	{ RET('.'); }
#line 370 "cunroll.c"
yy13:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\n':	goto yy10;
	default:	goto yy106;
	}
yy14:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy99;
	case '>':	goto yy101;
	default:	goto yy15;
	}
yy15:
#line 203 "cunroll.re"
	{ RET('>'); }
#line 388 "cunroll.c"
yy16:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '<':	goto yy95;
	case '=':	goto yy93;
	default:	goto yy17;
	}
yy17:
#line 202 "cunroll.re"
	{ RET('<'); }
#line 399 "cunroll.c"
yy18:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '+':	goto yy89;
	case '=':	goto yy91;
	default:	goto yy19;
	}
yy19:
#line 198 "cunroll.re"
	{ RET('+'); }
#line 410 "cunroll.c"
yy20:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '-':	goto yy85;
	case '=':	goto yy87;
	case '>':	goto yy83;
	default:	goto yy21;
	}
yy21:
#line 197 "cunroll.re"
	{ RET('-'); }
#line 422 "cunroll.c"
yy22:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy81;
	default:	goto yy23;
	}
yy23:
#line 199 "cunroll.re"
	{ RET('*'); }
#line 432 "cunroll.c"
yy24:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy79;
	default:	goto yy25;
	}
yy25:
#line 201 "cunroll.re"
	{ RET('%'); }
#line 442 "cunroll.c"
yy26:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '&':	goto yy75;
	case '=':	goto yy77;
	default:	goto yy27;
	}
yy27:
#line 194 "cunroll.re"
	{ RET('&'); }
#line 453 "cunroll.c"
yy28:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy73;
	default:	goto yy29;
	}
yy29:
#line 204 "cunroll.re"
	{ RET('^'); }
#line 463 "cunroll.c"
yy30:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy71;
	case '|':	goto yy69;
	default:	goto yy31;
	}
yy31:
#line 205 "cunroll.re"
	{ RET('|'); }
#line 474 "cunroll.c"
yy32:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy67;
	default:	goto yy33;
	}
yy33:
#line 188 "cunroll.re"
	{ RET('='); }
#line 484 "cunroll.c"
yy34:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy65;
	default:	goto yy35;
	}
yy35:
#line 195 "cunroll.re"
	{ RET('!'); }
#line 494 "cunroll.c"
yy36:
	++YYCURSOR;
#line 183 "cunroll.re"
	{ RET(';'); }
#line 499 "cunroll.c"
yy38:
	++YYCURSOR;
#line 184 "cunroll.re"
	{ RET('{'); }
#line 504 "cunroll.c"
yy40:
	++YYCURSOR;
#line 185 "cunroll.re"
	{ RET('}'); }
#line 509 "cunroll.c"
yy42:
	++YYCURSOR;
#line 186 "cunroll.re"
	{ RET(','); }
#line 514 "cunroll.c"
yy44:
	++YYCURSOR;
#line 187 "cunroll.re"
	{ RET(':'); }
#line 519 "cunroll.c"
yy46:
	++YYCURSOR;
#line 189 "cunroll.re"
	{ RET('('); }
#line 524 "cunroll.c"
yy48:
	++YYCURSOR;
#line 190 "cunroll.re"
	{ RET(')'); }
#line 529 "cunroll.c"
yy50:
	++YYCURSOR;
#line 191 "cunroll.re"
	{ RET('['); }
#line 534 "cunroll.c"
yy52:
	++YYCURSOR;
#line 192 "cunroll.re"
	{ RET(']'); }
#line 539 "cunroll.c"
yy54:
	++YYCURSOR;
#line 196 "cunroll.re"
	{ RET('~'); }
#line 544 "cunroll.c"
yy56:
	++YYCURSOR;
#line 206 "cunroll.re"
	{ RET('?'); }
#line 549 "cunroll.c"
yy58:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy64;
yy59:
#line 209 "cunroll.re"
	{ goto std; }
#line 557 "cunroll.c"
yy60:
	++YYCURSOR;
#line 212 "cunroll.re"
	{
		if(cursor == s->eof) RET(EOI);
		s->pos = cursor; s->line++;
		goto std;
	    }
#line 566 "cunroll.c"
yy62:
	yych = *++YYCURSOR;
	goto yy10;
yy63:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy64:
	switch (yych) {
	case '\t':
	case '\v':
	case '\f':
	case ' ':	goto yy63;
	default:	goto yy59;
	}
yy65:
	++YYCURSOR;
#line 182 "cunroll.re"
	{ RET(NEQ); }
#line 586 "cunroll.c"
yy67:
	++YYCURSOR;
#line 181 "cunroll.re"
	{ RET(EQL); }
#line 591 "cunroll.c"
yy69:
	++YYCURSOR;
#line 178 "cunroll.re"
	{ RET(OROR); }
#line 596 "cunroll.c"
yy71:
	++YYCURSOR;
#line 171 "cunroll.re"
	{ RET(OREQ); }
#line 601 "cunroll.c"
yy73:
	++YYCURSOR;
#line 170 "cunroll.re"
	{ RET(XOREQ); }
#line 606 "cunroll.c"
yy75:
	++YYCURSOR;
#line 177 "cunroll.re"
	{ RET(ANDAND); }
#line 611 "cunroll.c"
yy77:
	++YYCURSOR;
#line 169 "cunroll.re"
	{ RET(ANDEQ); }
#line 616 "cunroll.c"
yy79:
	++YYCURSOR;
#line 168 "cunroll.re"
	{ RET(MODEQ); }
#line 621 "cunroll.c"
yy81:
	++YYCURSOR;
#line 166 "cunroll.re"
	{ RET(MULEQ); }
#line 626 "cunroll.c"
yy83:
	++YYCURSOR;
#line 176 "cunroll.re"
	{ RET(DEREF); }
#line 631 "cunroll.c"
yy85:
	++YYCURSOR;
#line 175 "cunroll.re"
	{ RET(DECR); }
#line 636 "cunroll.c"
yy87:
	++YYCURSOR;
#line 165 "cunroll.re"
	{ RET(SUBEQ); }
#line 641 "cunroll.c"
yy89:
	++YYCURSOR;
#line 174 "cunroll.re"
	{ RET(INCR); }
#line 646 "cunroll.c"
yy91:
	++YYCURSOR;
#line 164 "cunroll.re"
	{ RET(ADDEQ); }
#line 651 "cunroll.c"
yy93:
	++YYCURSOR;
#line 179 "cunroll.re"
	{ RET(LEQ); }
#line 656 "cunroll.c"
yy95:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy97;
	default:	goto yy96;
	}
yy96:
#line 173 "cunroll.re"
	{ RET(LSHIFT); }
#line 666 "cunroll.c"
yy97:
	++YYCURSOR;
#line 163 "cunroll.re"
	{ RET(LSHIFTEQ); }
#line 671 "cunroll.c"
yy99:
	++YYCURSOR;
#line 180 "cunroll.re"
	{ RET(GEQ); }
#line 676 "cunroll.c"
yy101:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '=':	goto yy103;
	default:	goto yy102;
	}
yy102:
#line 172 "cunroll.re"
	{ RET(RSHIFT); }
#line 686 "cunroll.c"
yy103:
	++YYCURSOR;
#line 162 "cunroll.re"
	{ RET(RSHIFTEQ); }
#line 691 "cunroll.c"
yy105:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy106:
	switch (yych) {
	case '\n':	goto yy107;
	case '"':	goto yy109;
	case '\\':	goto yy108;
	default:	goto yy105;
	}
yy107:
	YYCURSOR = YYMARKER;
	switch (yyaccept) {
	case 0: 	goto yy7;
	case 1: 	goto yy10;
	case 2: 	goto yy12;
	default:	goto yy119;
	}
yy108:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '"':
	case '\'':
	case '?':
	case '\\':
	case 'a':
	case 'b':
	case 'f':
	case 'n':
	case 'r':
	case 't':
	case 'v':	goto yy105;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy112;
	case 'x':	goto yy111;
	default:	goto yy107;
	}
yy109:
	++YYCURSOR;
#line 159 "cunroll.re"
	{ RET(SCON); }
#line 742 "cunroll.c"
yy111:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy114;
	default:	goto yy107;
	}
yy112:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\n':	goto yy107;
	case '"':	goto yy109;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy112;
	case '\\':	goto yy108;
	default:	goto yy105;
	}
yy114:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\n':	goto yy107;
	case '"':	goto yy109;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy114;
	case '\\':	goto yy108;
	default:	goto yy105;
	}
yy116:
	yych = *++YYCURSOR;
	switch (yych) {
	case '.':	goto yy125;
	default:	goto yy107;
	}
yy117:
	yyaccept = 3;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy117;
	case 'E':
	case 'e':	goto yy120;
	case 'F':
	case 'L':
	case 'f':
	case 'l':	goto yy121;
	default:	goto yy119;
	}
yy119:
#line 156 "cunroll.re"
	{ RET(FCON); }
#line 855 "cunroll.c"
yy120:
	yych = *++YYCURSOR;
	switch (yych) {
	case '+':
	case '-':	goto yy122;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy123;
	default:	goto yy107;
	}
yy121:
	yych = *++YYCURSOR;
	goto yy119;
yy122:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy123;
	default:	goto yy107;
	}
yy123:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy123;
	case 'F':
	case 'L':
	case 'f':
	case 'l':	goto yy121;
	default:	goto yy119;
	}
yy125:
	++YYCURSOR;
#line 161 "cunroll.re"
	{ RET(ELLIPSIS); }
#line 916 "cunroll.c"
yy127:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy128:
	switch (yych) {
	case '\n':	goto yy107;
	case '\'':	goto yy130;
	case '\\':	goto yy129;
	default:	goto yy127;
	}
yy129:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '"':
	case '\'':
	case '?':
	case '\\':
	case 'a':
	case 'b':
	case 'f':
	case 'n':
	case 'r':
	case 't':
	case 'v':	goto yy127;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy132;
	case 'x':	goto yy131;
	default:	goto yy107;
	}
yy130:
	yych = *++YYCURSOR;
	goto yy7;
yy131:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy134;
	default:	goto yy107;
	}
yy132:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\n':	goto yy107;
	case '\'':	goto yy130;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy132;
	case '\\':	goto yy129;
	default:	goto yy127;
	}
yy134:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\n':	goto yy107;
	case '\'':	goto yy130;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy134;
	case '\\':	goto yy129;
	default:	goto yy127;
	}
yy136:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'E':
	case 'e':	goto yy147;
	default:	goto yy146;
	}
yy137:
	yyaccept = 0;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
yy138:
	switch (yych) {
	case '.':	goto yy136;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy137;
	case 'E':
	case 'e':	goto yy139;
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy140;
	default:	goto yy7;
	}
yy139:
	yych = *++YYCURSOR;
	switch (yych) {
	case '+':
	case '-':	goto yy142;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy143;
	default:	goto yy107;
	}
yy140:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy140;
	default:	goto yy7;
	}
yy142:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy143;
	default:	goto yy107;
	}
yy143:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy143;
	case 'F':
	case 'L':
	case 'f':
	case 'l':	goto yy121;
	default:	goto yy119;
	}
yy145:
	yyaccept = 3;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
yy146:
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy145;
	case 'E':
	case 'e':	goto yy151;
	case 'F':
	case 'L':
	case 'f':
	case 'l':	goto yy121;
	default:	goto yy119;
	}
yy147:
	yych = *++YYCURSOR;
	switch (yych) {
	case '+':
	case '-':	goto yy148;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy149;
	default:	goto yy107;
	}
yy148:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy149;
	default:	goto yy107;
	}
yy149:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy149;
	case 'F':
	case 'L':
	case 'f':
	case 'l':	goto yy121;
	default:	goto yy119;
	}
yy151:
	yych = *++YYCURSOR;
	switch (yych) {
	case '+':
	case '-':	goto yy152;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy153;
	default:	goto yy107;
	}
yy152:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy153;
	default:	goto yy107;
	}
yy153:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy153;
	case 'F':
	case 'L':
	case 'f':
	case 'l':	goto yy121;
	default:	goto yy119;
	}
yy155:
	yyaccept = 0;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
yy156:
	switch (yych) {
	case '.':	goto yy136;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy155;
	case 'E':
	case 'e':	goto yy139;
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy162;
	default:	goto yy7;
	}
yy157:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy158;
	default:	goto yy107;
	}
yy158:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy158;
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy160;
	default:	goto yy7;
	}
yy160:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy160;
	default:	goto yy7;
	}
yy162:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'L':
	case 'U':
	case 'l':
	case 'u':	goto yy162;
	default:	goto yy7;
	}
yy164:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy166;
	default:	goto yy165;
	}
yy165:
#line 142 "cunroll.re"
	{ RET(ID); }
#line 1445 "cunroll.c"
yy166:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy168;
	default:	goto yy167;
	}
yy167:
#line 143 "cunroll.re"
	{ RET(ID); }
#line 1517 "cunroll.c"
yy168:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy170;
	default:	goto yy169;
	}
yy169:
#line 144 "cunroll.re"
	{ RET(ID); }
#line 1589 "cunroll.c"
yy170:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy172;
	default:	goto yy171;
	}
yy171:
#line 145 "cunroll.re"
	{ RET(ID); }
#line 1661 "cunroll.c"
yy172:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy174;
	default:	goto yy173;
	}
yy173:
#line 146 "cunroll.re"
	{ RET(ID); }
#line 1733 "cunroll.c"
yy174:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy176;
	default:	goto yy175;
	}
yy175:
#line 147 "cunroll.re"
	{ RET(ID); }
#line 1805 "cunroll.c"
yy176:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy178;
	default:	goto yy177;
	}
yy177:
#line 148 "cunroll.re"
	{ RET(ID); }
#line 1877 "cunroll.c"
yy178:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy178;
	default:	goto yy180;
	}
yy180:
#line 149 "cunroll.re"
	{ RET(ID); }
#line 1951 "cunroll.c"
yy181:
	++YYCURSOR;
#line 167 "cunroll.re"
	{ RET(DIVEQ); }
#line 1956 "cunroll.c"
yy183:
	++YYCURSOR;
#line 138 "cunroll.re"
	{ goto comment; }
#line 1961 "cunroll.c"
}
#line 223 "cunroll.re"


comment:

#line 1968 "cunroll.c"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 8) YYFILL(8);
	yych = *YYCURSOR;
	switch (yych) {
	case '\n':	goto yy189;
	case '*':	goto yy187;
	case '/':	goto yy193;
	default:	goto yy191;
	}
yy187:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '/':	goto yy208;
	default:	goto yy188;
	}
yy188:
#line 242 "cunroll.re"
	{ goto comment; }
#line 1988 "cunroll.c"
yy189:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '*':
	case '/':	goto yy190;
	default:	goto yy194;
	}
yy190:
#line 229 "cunroll.re"
	{
		if(cursor == s->eof) RET(EOI);
		s->tok = s->pos = cursor; s->line++;
		goto comment;
	    }
#line 2003 "cunroll.c"
yy191:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '*':
	case '/':	goto yy192;
	default:	goto yy194;
	}
yy192:
#line 234 "cunroll.re"
	{ goto comment; }
#line 2014 "cunroll.c"
yy193:
	yych = *++YYCURSOR;
	goto yy188;
yy194:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '*':
	case '/':	goto yy195;
	default:	goto yy196;
	}
yy195:
#line 235 "cunroll.re"
	{ goto comment; }
#line 2028 "cunroll.c"
yy196:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '*':
	case '/':	goto yy197;
	default:	goto yy198;
	}
yy197:
#line 236 "cunroll.re"
	{ goto comment; }
#line 2039 "cunroll.c"
yy198:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '*':
	case '/':	goto yy199;
	default:	goto yy200;
	}
yy199:
#line 237 "cunroll.re"
	{ goto comment; }
#line 2050 "cunroll.c"
yy200:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '*':
	case '/':	goto yy201;
	default:	goto yy202;
	}
yy201:
#line 238 "cunroll.re"
	{ goto comment; }
#line 2061 "cunroll.c"
yy202:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '*':
	case '/':	goto yy203;
	default:	goto yy204;
	}
yy203:
#line 239 "cunroll.re"
	{ goto comment; }
#line 2072 "cunroll.c"
yy204:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '*':
	case '/':	goto yy205;
	default:	goto yy206;
	}
yy205:
#line 240 "cunroll.re"
	{ goto comment; }
#line 2083 "cunroll.c"
yy206:
	++YYCURSOR;
#line 241 "cunroll.re"
	{ goto comment; }
#line 2088 "cunroll.c"
yy208:
	++YYCURSOR;
#line 227 "cunroll.re"
	{ goto std; }
#line 2093 "cunroll.c"
}
#line 243 "cunroll.re"

}

main(){
    Scanner in;
    int t;
    memset((char*) &in, 0, sizeof(in));
    in.fd = 0;
    while((t = scan(&in)) != EOI){
/*
	printf("%d\t%.*s\n", t, in.cur - in.tok, in.tok);
	printf("%d\n", t);
*/
    }
    close(in.fd);
}