/* Generated by re2c */
#line 1 "calc_004.re"
/* re2c lesson_001, calc_004, (c) M. Boerger 2006 */
#line 20 "calc_004.re"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * tokendup(const char *t, const char *l)
{
	size_t n = l -t + 1;
	char *r = (char*)malloc(n);
	
	memmove(r, t, n-1);
	r[n] = '\0';
	return r;
}

int scan(char *s, int l)
{
	char *p = s;
	char *q = 0;
	char *t;
	#define YYCTYPE         char
	#define YYCURSOR        p
	#define YYLIMIT         (s+l+2)
	#define YYMARKER        q
	#define YYFILL(n)		{ printf("OOD\n"); return 2; }
	
	for(;;)
	{
		t = p;

#line 36 "<stdout>"
		{
			YYCTYPE yych;

			if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
			yych = *YYCURSOR;
			switch(yych){
			case 0x00:	goto yy9;
			case '+':	goto yy5;
			case '-':	goto yy7;
			case '0':	goto yy2;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy4;
			default:	goto yy11;
			}
yy2:
			++YYCURSOR;
			switch((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy15;
			default:	goto yy3;
			}
yy3:
#line 57 "calc_004.re"
			{ t = tokendup(t, p); printf("Num: %s\n", t); free(t); continue; }
#line 76 "<stdout>"
yy4:
			yych = *++YYCURSOR;
			goto yy14;
yy5:
			++YYCURSOR;
#line 58 "calc_004.re"
			{ printf("+\n");	continue; }
#line 84 "<stdout>"
yy7:
			++YYCURSOR;
#line 59 "calc_004.re"
			{ printf("+\n");	continue; }
#line 89 "<stdout>"
yy9:
			++YYCURSOR;
#line 60 "calc_004.re"
			{ printf("EOF\n");	return 0; }
#line 94 "<stdout>"
yy11:
			++YYCURSOR;
#line 61 "calc_004.re"
			{ printf("ERR\n");	return 1; }
#line 99 "<stdout>"
yy13:
			++YYCURSOR;
			if(YYLIMIT == YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
yy14:
			switch(yych){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy13;
			default:	goto yy3;
			}
yy15:
			++YYCURSOR;
			if(YYLIMIT == YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
			switch(yych){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy15;
			default:	goto yy17;
			}
yy17:
#line 56 "calc_004.re"
			{ t = tokendup(t, p); printf("Oct: %s\n", t); free(t); continue; }
#line 138 "<stdout>"
		}
#line 62 "calc_004.re"

	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		return scan(argv[1], strlen(argv[1]));
	}
	else
	{
		fprintf(stderr, "%s <expr>\n", argv[0]);
		return 0;
	}
}
