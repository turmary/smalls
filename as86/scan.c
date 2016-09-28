/* scan.c - lexical analyser for assembler */

#include "syshead.h"
#include "const.h"
#include "type.h"
#include "globvar.h"
#include "source.h"
#undef EXTERN
#define EXTERN
#include "scan.h"

PRIVATE int numbase;		/* base for number */

PRIVATE char symofchar[256] =	/* table to convert chars to their symbols */
{
	EOLSYM, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, EOLSYM, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,

	WHITESPACE, EOLSYM, STRINGCONST, IMMEDIATE,	/*  !"# */
	HEXCONST, BINCONST, ANDOP, CHARCONST,	/* $%&' */
	LPAREN, RPAREN, STAR, ADDOP,	/* ()*+ */
	COMMA, SUBOP, IDENT, SLASH,	/* ,-./ */

	INTCONST, INTCONST, INTCONST, INTCONST,	/* 0123 */
	INTCONST, INTCONST, INTCONST, INTCONST,	/* 4567 */
	INTCONST, INTCONST, COLON, EOLSYM,	/* 89:; */
	LESSTHAN, EQOP, GREATERTHAN, MACROARG,	/* <=>? */

	INDIRECT, IDENT, IDENT, IDENT,	/* @ABC */
	IDENT, IDENT, IDENT, IDENT,	/* DEFG */
	IDENT, IDENT, IDENT, IDENT,	/* HIJK */
	IDENT, IDENT, IDENT, IDENT,	/* LMNO */
	IDENT, IDENT, IDENT, IDENT,	/* PQRS */
	IDENT, IDENT, IDENT, IDENT,	/* TUVW */
	IDENT, IDENT, IDENT, LBRACKET,	/* XYZ[ */
	OTHERSYM, RBRACKET, OTHERSYM, IDENT,	/* \]^_ */

	OTHERSYM, IDENT, IDENT, IDENT,	/* `abc */
	IDENT, IDENT, IDENT, IDENT,	/* defg */
	IDENT, IDENT, IDENT, IDENT,	/* hijk */
	IDENT, IDENT, IDENT, IDENT,	/* lmno */
	IDENT, IDENT, IDENT, IDENT,	/* pqrs */
	IDENT, IDENT, IDENT, IDENT,	/* tuvw */
	IDENT, IDENT, IDENT, OTHERSYM,	/* xyz{ */
	OROP, OTHERSYM, NOTOP, OTHERSYM,	/* |}~  */

	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,

	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,

	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,

	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE,
	WHITESPACE, WHITESPACE, WHITESPACE, WHITESPACE
};

static const char* symnames[] = {
	"IDENT",
	"INTCONST",

/* The next few are best for other possibly-multi-char tokens. */
	"ADDOP",		/* also ++ */
	"BINCONST",
	"CHARCONST",
	"GREATERTHAN",		/* also >> and context-sensitive */
	"HEXCONST",
	"LESSTHAN",		/* also << and context-sensitive */
	"SUBOP",		/* also -- */
	"WHITESPACE",

	"ANDOP",
	"COMMA",
	"EOLSYM",
	"EQOP",
	"IMMEDIATE",
	"INDIRECT",
	"LBRACKET",
	"LPAREN",
	"MACROARG",
	"NOTOP",
	"OROP",
	"OTHERSYM",
	"POSTINCOP",
	"PREDECOP",
	"RBRACKET",
	"RPAREN",
	"SLASH",		/* context-sensitive */
	"SLOP",
	"SROP",
	"STAR",			/* context-sensitive */
	"STRINGCONST",
	"COLON",
};

FORWARD void intconst P((void));

PUBLIC void context_hexconst()
{
	numbase = 16;
	intconst();
}

PUBLIC void getsym()
{
	register char *reglineptr;

	reglineptr = lineptr;
      advance:
	symname = reglineptr;
	switch (sym = symofchar[(unsigned char) *reglineptr++]) {
	case WHITESPACE:
		goto advance;
	case ADDOP:
		if (*reglineptr == '+') {
			sym = POSTINCOP;
			++reglineptr;
		}
		break;
	case BINCONST:
		numbase = 2;
		lineptr = reglineptr;
		intconst();
		goto ret_dbg;
	case CHARCONST:
		if ((number = *reglineptr) < ' ')
			number = ' ';
		if (*reglineptr != EOL)
			++reglineptr;
		sym = INTCONST;
		break;
	case GREATERTHAN:	/* context-sensitive */
		if (*reglineptr == '>') {
			sym = SROP;
			++reglineptr;
		}
		break;
	case HEXCONST:
		numbase = 16;
		lineptr = reglineptr;
		intconst();
		goto ret_dbg;
	case IDENT:
		/* walk to end of identifier - magic INTCONST is max of INT, IDENT */
		while (symofchar[(unsigned char) *reglineptr] <= INTCONST)
			++reglineptr;
		lineptr = reglineptr;
		gsymptr = lookup();
		goto ret_dbg;
	case INTCONST:
		if (*(reglineptr - 1) == '0') {
			if (*reglineptr != 'x' && *reglineptr != 'X')
				numbase = 8;
			else {
				numbase = 16;
				++reglineptr;
			}
		} else {
			--reglineptr;
			numbase = 10;
		}
		lineptr = reglineptr;
		intconst();
		goto ret_dbg;
	case LESSTHAN:		/* context-sensitive */
		if (*reglineptr == '<') {
			sym = SLOP;
			++reglineptr;
		}
		break;
	case SUBOP:
		if (*reglineptr == '-') {
			sym = PREDECOP;
			++reglineptr;
		}
		break;
	}
	lineptr = reglineptr;
ret_dbg:
	{	// TARY DEBUG
		static int s_linum = 0;

		if (linum != s_linum) {
			s_linum = linum;
			printf("### LINE%d ### ", linum);
		}
		printf("%s ", symnames[sym]);
		if (sym == EOLSYM) {
			printf("\n");
		}
	}
	return;
}

PUBLIC void getsym_nolookup()
{
	bool_t old_ifflag;

	old_ifflag = ifflag;
	ifflag = FALSE;
	getsym();
	ifflag = old_ifflag;
}

PRIVATE void intconst()
{
	register char *reglineptr;

	number = 0;
	reglineptr = lineptr;
	for (; *reglineptr >= '0'; ++reglineptr) {
		if (*reglineptr > '9') {
			if (numbase != 16)
				break;
			if (*reglineptr >= 'a' && *reglineptr <= 'f') {
				if (number != 0)
					number = numbase * number + (*reglineptr - 'a' + 10);
				else
					number = *reglineptr - 'a' + 10;
			} else if (*reglineptr >= 'A' && *reglineptr <= 'F') {
				if (number != 0)
					number = numbase * number + (*reglineptr - 'A' + 10);
				else
					number = *reglineptr - 'A' + 10;
			} else
				break;
		} else if (number != 0)
			number = numbase * number + (*reglineptr - '0');
		else
			number = *reglineptr - '0';
	}
	if (*reglineptr == 'L' || *reglineptr == 'l')
		++reglineptr;
	sym = INTCONST;
	lineptr = reglineptr;
}

PUBLIC void initscan()
{
#ifndef MC6809
	if (asld_compatible) {
		lindirect = LPAREN;
		rindexp = RPEXP;
		rindirect = RPAREN;
	} else {
#endif
		lindirect = LBRACKET;
		rindexp = RBEXP;
		rindirect = RBRACKET;
#ifndef MC6809
	}
#endif
}
