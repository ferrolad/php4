
/*  A Bison parser, made from parsedate.y
 by  GNU Bison version 1.27
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	tAGO	257
#define	tDAY	258
#define	tDAY_UNIT	259
#define	tDAYZONE	260
#define	tDST	261
#define	tHOUR_UNIT	262
#define	tID	263
#define	tMERIDIAN	264
#define	tMINUTE_UNIT	265
#define	tMONTH	266
#define	tMONTH_UNIT	267
#define	tSEC_UNIT	268
#define	tSNUMBER	269
#define	tUNUMBER	270
#define	tYEAR_UNIT	271
#define	tZONE	272

#line 1 "parsedate.y"

/*
**  Originally written by Steven M. Bellovin <smb@research.att.com> while
**  at the University of North Carolina at Chapel Hill.  Later tweaked by
**  a couple of people on Usenet.  Completely overhauled by Rich $alz
**  <rsalz@bbn.com> and Jim Berets <jberets@bbn.com> in August, 1990.
**
**  This code is in the public domain and has no copyright.
*/

/* $Id: parsedate.y,v 1.34.2.7 2004/04/08 19:21:46 derick Exp $ */

#include "php.h"

#ifdef PHP_WIN32
#include <malloc.h>
#endif

#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <ctype.h>

#ifdef HAVE_SYS_TIME_H
# include <sys/time.h>
#endif
#ifdef PHP_WIN32
# include "win32/time.h"
#endif

#include "php_parsedate.h"

#if HAVE_STDLIB_H
# include <stdlib.h> /* for `free'; used by Bison 1.27 */
#endif

#if defined(_HPUX_SOURCE)
#include <alloca.h>
#endif

#if defined (STDC_HEADERS) || (!defined (isascii) && !defined (HAVE_ISASCII))
# define IN_CTYPE_DOMAIN(c) 1
#else
# define IN_CTYPE_DOMAIN(c) isascii(c)
#endif

#define ISSPACE(c) (IN_CTYPE_DOMAIN (c) && isspace (c))
#define ISALPHA(c) (IN_CTYPE_DOMAIN (c) && isalpha (c))
#define ISUPPER(c) (IN_CTYPE_DOMAIN (c) && isupper (c))
#define ISDIGIT_LOCALE(c) (IN_CTYPE_DOMAIN (c) && isdigit (c))

/* ISDIGIT differs from ISDIGIT_LOCALE, as follows:
   - Its arg may be any int or unsigned int; it need not be an unsigned char.
   - It's guaranteed to evaluate its argument exactly once.
   - It's typically faster.
   Posix 1003.2-1992 section 2.5.2.1 page 50 lines 1556-1558 says that
   only '0' through '9' are digits.  Prefer ISDIGIT to ISDIGIT_LOCALE unless
   it's important to use the locale's definition of `digit' even when the
   host does not conform to Posix.  */
#define ISDIGIT(c) ((unsigned) (c) - '0' <= 9)

#if defined (STDC_HEADERS) || defined (USG)
# include <string.h>
#endif

#if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 7)
# define __attribute__(x)
#endif

#ifndef ATTRIBUTE_UNUSED
# define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#endif

/* Some old versions of bison generate parsers that use bcopy.
   That loses on systems that don't provide the function, so we have
   to redefine it here.  */
#if !defined (HAVE_BCOPY) && defined (HAVE_MEMCPY) && !defined (bcopy)
# define bcopy(from, to, len) memcpy ((to), (from), (len))
#endif

/* Remap normal yacc parser interface names (yyparse, yylex, yyerror, etc),
   as well as gratuitiously global symbol names, so we can have multiple
   yacc generated parsers in the same program.  Note that these are only
   the variables produced by yacc.  If other parser generators (bison,
   byacc, etc) produce additional global names that conflict at link time,
   then those parser generators need to be fixed instead of adding those
   names to this list. */

#define yyparse php_gd_parse
#define yylex   php_gd_lex

static int yyerror ();

#define EPOCH		1970
#define HOUR(x)		((x) * 60)

#define MAX_BUFF_LEN    128   /* size of buffer to read the date into */

/*
**  An entry in the lexical lookup table.
*/
typedef struct _TABLE {
    const char	*name;
    int		type;
    int		value;
} TABLE;


/*
**  Meridian:  am, pm, or 24-hour style.
*/
typedef enum _MERIDIAN {
    MERam, MERpm, MER24
} MERIDIAN;

struct date_yy {
	const char	*yyInput;
	int	yyDayOrdinal;
	int	yyDayNumber;
	int	yyHaveDate;
	int	yyHaveDay;
	int	yyHaveRel;
	int	yyHaveTime;
	int	yyHaveZone;
	int	yyTimezone;
	int	yyDay;
	int	yyHour;
	int	yyMinutes;
	int	yyMonth;
	int	yySeconds;
	int	yyYear;
	MERIDIAN	yyMeridian;
	int	yyRelDay;
	int	yyRelHour;
	int	yyRelMinutes;
	int	yyRelMonth;
	int	yyRelSeconds;
	int	yyRelYear;
};

typedef union _date_ll {
    int			Number;
    enum _MERIDIAN	Meridian;
} date_ll;

#define YYPARSE_PARAM parm
#define YYLEX_PARAM parm
#define YYSTYPE date_ll
#define YYLTYPE void

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		70
#define	YYFLAG		-32768
#define	YYNTBASE	22

#define YYTRANSLATE(x) ((unsigned)(x) <= 272 ? yytranslate[x] : 32)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    20,     2,     2,    21,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    19,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     4,     6,     8,    10,    12,    14,    16,    19,
    24,    29,    34,    41,    48,    55,    57,    59,    62,    64,
    67,    70,    74,    83,    89,    93,    97,   101,   104,   109,
   112,   116,   119,   121,   124,   127,   129,   132,   135,   137,
   140,   143,   145,   148,   151,   153,   156,   159,   161,   164,
   167,   169,   171,   172
};

static const short yyrhs[] = {    -1,
    22,    23,     0,    24,     0,    25,     0,    27,     0,    26,
     0,    28,     0,    30,     0,    16,    10,     0,    16,    19,
    16,    31,     0,    16,    19,    16,    28,     0,    16,    19,
    16,    15,     0,    16,    19,    16,    19,    16,    31,     0,
    16,    19,    16,    19,    16,    28,     0,    16,    19,    16,
    19,    16,    15,     0,    18,     0,     6,     0,    18,     7,
     0,     4,     0,     4,    20,     0,    16,     4,     0,    16,
    21,    16,     0,    12,    16,    16,    19,    16,    19,    16,
    16,     0,    16,    21,    16,    21,    16,     0,    16,    15,
    15,     0,    16,    12,    15,     0,    12,    16,    16,     0,
    12,    16,     0,    12,    16,    20,    16,     0,    16,    12,
     0,    16,    12,    16,     0,    29,     3,     0,    29,     0,
    16,    17,     0,    15,    17,     0,    17,     0,    16,    13,
     0,    15,    13,     0,    13,     0,    16,     5,     0,    15,
     5,     0,     5,     0,    16,     8,     0,    15,     8,     0,
     8,     0,    16,    11,     0,    15,    11,     0,    11,     0,
    16,    14,     0,    15,    14,     0,    14,     0,    16,     0,
     0,    10,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   168,   169,   172,   175,   178,   181,   184,   187,   190,   199,
   208,   216,   228,   237,   246,   265,   268,   271,   277,   281,
   285,   291,   295,   306,   324,   330,   336,   341,   349,   354,
   362,   369,   383,   386,   389,   392,   395,   398,   401,   404,
   407,   410,   413,   416,   419,   422,   425,   428,   431,   434,
   437,   442,   477,   481
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","tAGO","tDAY",
"tDAY_UNIT","tDAYZONE","tDST","tHOUR_UNIT","tID","tMERIDIAN","tMINUTE_UNIT",
"tMONTH","tMONTH_UNIT","tSEC_UNIT","tSNUMBER","tUNUMBER","tYEAR_UNIT","tZONE",
"':'","','","'/'","spec","item","time","zone","day","date","rel","relunit","number",
"o_merid", NULL
};
#endif

static const short yyr1[] = {     0,
    22,    22,    23,    23,    23,    23,    23,    23,    24,    24,
    24,    24,    24,    24,    24,    25,    25,    25,    26,    26,
    26,    27,    27,    27,    27,    27,    27,    27,    27,    27,
    27,    28,    28,    29,    29,    29,    29,    29,    29,    29,
    29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
    29,    30,    31,    31
};

static const short yyr2[] = {     0,
     0,     2,     1,     1,     1,     1,     1,     1,     2,     4,
     4,     4,     6,     6,     6,     1,     1,     2,     1,     2,
     2,     3,     8,     5,     3,     3,     3,     2,     4,     2,
     3,     2,     1,     2,     2,     1,     2,     2,     1,     2,
     2,     1,     2,     2,     1,     2,     2,     1,     2,     2,
     1,     1,     0,     1
};

static const short yydefact[] = {     1,
     0,    19,    42,    17,    45,    48,     0,    39,    51,     0,
    52,    36,    16,     2,     3,     4,     6,     5,     7,    33,
     8,    20,    28,    41,    44,    47,    38,    50,    35,    21,
    40,    43,     9,    46,    30,    37,    49,     0,    34,     0,
     0,    18,    32,    27,     0,    26,    31,    25,    53,    22,
     0,    29,    54,    12,     0,     0,    11,    10,     0,     0,
    53,    24,     0,    15,    14,    13,     0,    23,     0,     0
};

static const short yydefgoto[] = {     1,
    14,    15,    16,    17,    18,    19,    20,    21,    58
};

static const short yypact[] = {-32768,
     0,   -10,-32768,-32768,-32768,-32768,     6,-32768,-32768,    56,
    15,-32768,    17,-32768,-32768,-32768,-32768,-32768,-32768,    28,
-32768,-32768,   -13,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   -14,-32768,-32768,    18,-32768,    21,
    23,-32768,-32768,    31,    26,-32768,-32768,-32768,    30,    34,
    36,-32768,-32768,    56,    63,    46,-32768,-32768,    47,    53,
    43,-32768,    49,    56,-32768,-32768,    50,-32768,    75,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,-32768,-32768,   -40,-32768,-32768,    20
};


#define	YYLAST		81


static const short yytable[] = {    69,
    46,    47,    44,     2,     3,     4,    45,     5,    57,    22,
     6,     7,     8,     9,    10,    11,    12,    13,    30,    31,
    65,    23,    32,    42,    33,    34,    35,    36,    37,    38,
    43,    39,    48,    40,     3,    41,    49,     5,    50,    53,
     6,    52,     8,     9,    54,    55,    12,     3,    56,    51,
     5,    60,    53,     6,    59,     8,     9,    64,    55,    12,
    24,    61,    62,    25,    67,    68,    26,    31,    27,    28,
    32,    63,    29,    34,    70,    36,    37,     0,     0,    39,
    66
};

static const short yycheck[] = {     0,
    15,    16,    16,     4,     5,     6,    20,     8,    49,    20,
    11,    12,    13,    14,    15,    16,    17,    18,     4,     5,
    61,    16,     8,     7,    10,    11,    12,    13,    14,    15,
     3,    17,    15,    19,     5,    21,    16,     8,    16,    10,
    11,    16,    13,    14,    15,    16,    17,     5,    19,    19,
     8,    16,    10,    11,    21,    13,    14,    15,    16,    17,
     5,    16,    16,     8,    16,    16,    11,     5,    13,    14,
     8,    19,    17,    11,     0,    13,    14,    -1,    -1,    17,
    61
};
#define YYPURE 1

/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"
/* This file comes from bison-1.27.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 216 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 3:
#line 172 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyHaveTime++;
	;
    break;}
case 4:
#line 175 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyHaveZone++;
	;
    break;}
case 5:
#line 178 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyHaveDate++;
	;
    break;}
case 6:
#line 181 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyHaveDay++;
	;
    break;}
case 7:
#line 184 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyHaveRel++;
	;
    break;}
case 9:
#line 190 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyHour = yyvsp[-1].Number;
	    ((struct date_yy *)parm)->yyMinutes = 0;
	    ((struct date_yy *)parm)->yySeconds = 0;
	    ((struct date_yy *)parm)->yyMeridian = yyvsp[0].Meridian;
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
		printf("[U M]\n");
#endif
	;
    break;}
case 10:
#line 199 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyHour = yyvsp[-3].Number;
	    ((struct date_yy *)parm)->yyMinutes = yyvsp[-1].Number;
	    ((struct date_yy *)parm)->yySeconds = 0;
	    ((struct date_yy *)parm)->yyMeridian = yyvsp[0].Meridian;
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
		printf("[U:U M]\n");
#endif
	;
    break;}
case 11:
#line 208 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyHour = yyvsp[-3].Number;
	    ((struct date_yy *)parm)->yyMinutes = yyvsp[-1].Number;
	    ((struct date_yy *)parm)->yyMeridian = MER24;
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
		printf("[U:U rel]\n");
#endif
	;
    break;}
case 12:
#line 216 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyHour = yyvsp[-3].Number;
	    ((struct date_yy *)parm)->yyMinutes = yyvsp[-1].Number;
	    ((struct date_yy *)parm)->yyMeridian = MER24;
	    ((struct date_yy *)parm)->yyHaveZone++;
	    ((struct date_yy *)parm)->yyTimezone = (yyvsp[0].Number < 0
			  ? -yyvsp[0].Number % 100 + (-yyvsp[0].Number / 100) * 60
			  : - (yyvsp[0].Number % 100 + (yyvsp[0].Number / 100) * 60));
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
		printf("[U:U S]\n");
#endif
	;
    break;}
case 13:
#line 228 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyHour = yyvsp[-5].Number;
	    ((struct date_yy *)parm)->yyMinutes = yyvsp[-3].Number;
	    ((struct date_yy *)parm)->yySeconds = yyvsp[-1].Number;
	    ((struct date_yy *)parm)->yyMeridian = yyvsp[0].Meridian;
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
		printf("[U:U:U M]\n");
#endif
	;
    break;}
case 14:
#line 237 "parsedate.y"
{
	    /* ISO 8601 format.  hh:mm:ss[+-][0-9]{2}([0-9]{2})?.  */
	    ((struct date_yy *)parm)->yyHour = yyvsp[-5].Number;
	    ((struct date_yy *)parm)->yyMinutes = yyvsp[-3].Number;
	    ((struct date_yy *)parm)->yySeconds = yyvsp[-1].Number;
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
		printf("[U:U:U rel]\n");
#endif
	;
    break;}
case 15:
#line 246 "parsedate.y"
{
	    /* ISO 8601 format.  hh:mm:ss[+-][0-9]{2}([0-9]{2})?.  */
	    ((struct date_yy *)parm)->yyHour = yyvsp[-5].Number;
	    ((struct date_yy *)parm)->yyMinutes = yyvsp[-3].Number;
	    ((struct date_yy *)parm)->yySeconds = yyvsp[-1].Number;
	    ((struct date_yy *)parm)->yyMeridian = MER24;
	    ((struct date_yy *)parm)->yyHaveZone++;
		if (yyvsp[0].Number <= -100 || yyvsp[0].Number >= 100) {
			((struct date_yy *)parm)->yyTimezone =  
				-yyvsp[0].Number % 100 + (-yyvsp[0].Number / 100) * 60;
		} else {
			((struct date_yy *)parm)->yyTimezone =  -yyvsp[0].Number * 60;
		}
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
		printf("[U:U:U S]\n");
#endif
	;
    break;}
case 16:
#line 265 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyTimezone = yyvsp[0].Number;
	;
    break;}
case 17:
#line 268 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyTimezone = yyvsp[0].Number - 60;
	;
    break;}
case 18:
#line 272 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyTimezone = yyvsp[-1].Number - 60;
	;
    break;}
case 19:
#line 277 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyDayOrdinal = 1;
	    ((struct date_yy *)parm)->yyDayNumber = yyvsp[0].Number;
	;
    break;}
case 20:
#line 281 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyDayOrdinal = 1;
	    ((struct date_yy *)parm)->yyDayNumber = yyvsp[-1].Number;
	;
    break;}
case 21:
#line 285 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyDayOrdinal = yyvsp[-1].Number;
	    ((struct date_yy *)parm)->yyDayNumber = yyvsp[0].Number;
	;
    break;}
case 22:
#line 291 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyMonth = yyvsp[-2].Number;
	    ((struct date_yy *)parm)->yyDay = yyvsp[0].Number;
	;
    break;}
case 23:
#line 295 "parsedate.y"
{
		((struct date_yy *)parm)->yyYear = yyvsp[0].Number;
		((struct date_yy *)parm)->yyMonth = yyvsp[-7].Number;
		((struct date_yy *)parm)->yyDay = yyvsp[-6].Number;

		((struct date_yy *)parm)->yyHour = yyvsp[-5].Number;
		((struct date_yy *)parm)->yyMinutes = yyvsp[-3].Number;
		((struct date_yy *)parm)->yySeconds = yyvsp[-1].Number;

		((struct date_yy *)parm)->yyHaveTime = 1;
	;
    break;}
case 24:
#line 306 "parsedate.y"
{
	  /* Interpret as YYYY/MM/DD if $1 >= 1000, otherwise as MM/DD/YY.
	     The goal in recognizing YYYY/MM/DD is solely to support legacy
	     machine-generated dates like those in an RCS log listing.  If
	     you want portability, use the ISO 8601 format.  */
	  if (yyvsp[-4].Number >= 1000)
	    {
	      ((struct date_yy *)parm)->yyYear = yyvsp[-4].Number;
	      ((struct date_yy *)parm)->yyMonth = yyvsp[-2].Number;
	      ((struct date_yy *)parm)->yyDay = yyvsp[0].Number;
	    }
	  else
	    {
	      ((struct date_yy *)parm)->yyMonth = yyvsp[-4].Number;
	      ((struct date_yy *)parm)->yyDay = yyvsp[-2].Number;
	      ((struct date_yy *)parm)->yyYear = yyvsp[0].Number;
	    }
	;
    break;}
case 25:
#line 324 "parsedate.y"
{
	    /* ISO 8601 format.  yyyy-mm-dd.  */
	    ((struct date_yy *)parm)->yyYear = yyvsp[-2].Number;
	    ((struct date_yy *)parm)->yyMonth = -yyvsp[-1].Number;
	    ((struct date_yy *)parm)->yyDay = -yyvsp[0].Number;
	;
    break;}
case 26:
#line 330 "parsedate.y"
{
	    /* e.g. 17-JUN-1992.  */
	    ((struct date_yy *)parm)->yyDay = yyvsp[-2].Number;
	    ((struct date_yy *)parm)->yyMonth = yyvsp[-1].Number;
	    ((struct date_yy *)parm)->yyYear = -yyvsp[0].Number;
	;
    break;}
case 27:
#line 336 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyMonth = yyvsp[-2].Number;
	    ((struct date_yy *)parm)->yyDay = yyvsp[-1].Number;
		((struct date_yy *)parm)->yyYear = yyvsp[0].Number;
	;
    break;}
case 28:
#line 341 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyMonth = yyvsp[-1].Number;
	    if (yyvsp[0].Number > 1000) {
		((struct date_yy *)parm)->yyYear = yyvsp[0].Number;
	    } else {
		((struct date_yy *)parm)->yyDay = yyvsp[0].Number;
	    }
	;
    break;}
case 29:
#line 349 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyMonth = yyvsp[-3].Number;
	    ((struct date_yy *)parm)->yyDay = yyvsp[-2].Number;
	    ((struct date_yy *)parm)->yyYear = yyvsp[0].Number;
	;
    break;}
case 30:
#line 354 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyMonth = yyvsp[0].Number;
	    if (yyvsp[-1].Number > 1000) {
		((struct date_yy *)parm)->yyYear = yyvsp[-1].Number;
	    } else {
		((struct date_yy *)parm)->yyDay = yyvsp[-1].Number;
	    }
	;
    break;}
case 31:
#line 362 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyMonth = yyvsp[-1].Number;
	    ((struct date_yy *)parm)->yyDay = yyvsp[-2].Number;
	    ((struct date_yy *)parm)->yyYear = yyvsp[0].Number;
	;
    break;}
case 32:
#line 369 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelSeconds =
			-((struct date_yy *)parm)->yyRelSeconds;
	    ((struct date_yy *)parm)->yyRelMinutes =
			-((struct date_yy *)parm)->yyRelMinutes;
	    ((struct date_yy *)parm)->yyRelHour =
			-((struct date_yy *)parm)->yyRelHour;
	    ((struct date_yy *)parm)->yyRelDay =
			-((struct date_yy *)parm)->yyRelDay;
	    ((struct date_yy *)parm)->yyRelMonth =
			-((struct date_yy *)parm)->yyRelMonth;
	    ((struct date_yy *)parm)->yyRelYear =
			-((struct date_yy *)parm)->yyRelYear;
	;
    break;}
case 34:
#line 386 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelYear += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 35:
#line 389 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelYear += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 36:
#line 392 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelYear += yyvsp[0].Number;
	;
    break;}
case 37:
#line 395 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelMonth += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 38:
#line 398 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelMonth += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 39:
#line 401 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelMonth += yyvsp[0].Number;
	;
    break;}
case 40:
#line 404 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelDay += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 41:
#line 407 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelDay += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 42:
#line 410 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelDay += yyvsp[0].Number;
	;
    break;}
case 43:
#line 413 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelHour += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 44:
#line 416 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelHour += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 45:
#line 419 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelHour += yyvsp[0].Number;
	;
    break;}
case 46:
#line 422 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelMinutes += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 47:
#line 425 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelMinutes += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 48:
#line 428 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelMinutes += yyvsp[0].Number;
	;
    break;}
case 49:
#line 431 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelSeconds += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 50:
#line 434 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelSeconds += yyvsp[-1].Number * yyvsp[0].Number;
	;
    break;}
case 51:
#line 437 "parsedate.y"
{
	    ((struct date_yy *)parm)->yyRelSeconds += yyvsp[0].Number;
	;
    break;}
case 52:
#line 443 "parsedate.y"
{
	    if (((struct date_yy *)parm)->yyHaveTime && 
			((struct date_yy *)parm)->yyHaveDate && 
			!((struct date_yy *)parm)->yyHaveRel)
	      ((struct date_yy *)parm)->yyYear = yyvsp[0].Number;
	    else
	      {
		if (yyvsp[0].Number>10000)
		  {
		    ((struct date_yy *)parm)->yyHaveDate++;
		    ((struct date_yy *)parm)->yyDay= (yyvsp[0].Number)%100;
		    ((struct date_yy *)parm)->yyMonth= (yyvsp[0].Number/100)%100;
		    ((struct date_yy *)parm)->yyYear = yyvsp[0].Number/10000;
		  }
		else
		  {
		    ((struct date_yy *)parm)->yyHaveTime++;
		    if (yyvsp[0].Number < 100)
		      {
			((struct date_yy *)parm)->yyHour = yyvsp[0].Number;
			((struct date_yy *)parm)->yyMinutes = 0;
		      }
		    else
		      {
		    	((struct date_yy *)parm)->yyHour = yyvsp[0].Number / 100;
		    	((struct date_yy *)parm)->yyMinutes = yyvsp[0].Number % 100;
		      }
		    ((struct date_yy *)parm)->yySeconds = 0;
		    ((struct date_yy *)parm)->yyMeridian = MER24;
		  }
	      }
	  ;
    break;}
case 53:
#line 478 "parsedate.y"
{
	    yyval.Meridian = MER24;
	  ;
    break;}
case 54:
#line 482 "parsedate.y"
{
	    yyval.Meridian = yyvsp[0].Meridian;
	  ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 542 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 487 "parsedate.y"


time_t get_date (char *p, time_t *now);

#ifndef PHP_WIN32
extern struct tm	*gmtime();
extern struct tm	*localtime();
extern time_t		mktime();
#endif

/* Month and day table. */
static TABLE const MonthDayTable[] = {
    { "january",	tMONTH,  1 },
    { "february",	tMONTH,  2 },
    { "march",		tMONTH,  3 },
    { "april",		tMONTH,  4 },
    { "may",		tMONTH,  5 },
    { "june",		tMONTH,  6 },
    { "july",		tMONTH,  7 },
    { "august",		tMONTH,  8 },
    { "september",	tMONTH,  9 },
    { "sept",		tMONTH,  9 },
    { "october",	tMONTH, 10 },
    { "november",	tMONTH, 11 },
    { "december",	tMONTH, 12 },
    { "sunday",		tDAY, 0 },
    { "monday",		tDAY, 1 },
    { "tuesday",	tDAY, 2 },
    { "tues",		tDAY, 2 },
    { "wednesday",	tDAY, 3 },
    { "wednes",		tDAY, 3 },
    { "thursday",	tDAY, 4 },
    { "thur",		tDAY, 4 },
    { "thurs",		tDAY, 4 },
    { "friday",		tDAY, 5 },
    { "saturday",	tDAY, 6 },
    { NULL, 0, 0 }
};

/* Time units table. */
static TABLE const UnitsTable[] = {
    { "year",		tYEAR_UNIT,	1 },
    { "month",		tMONTH_UNIT,	1 },
    { "fortnight",	tDAY_UNIT,	14 },
    { "week",		tDAY_UNIT,	7 },
    { "day",		tDAY_UNIT,	1 },
    { "hour",		tHOUR_UNIT,	1 },
    { "minute",		tMINUTE_UNIT,	1 },
    { "min",		tMINUTE_UNIT,	1 },
    { "second",		tSEC_UNIT,	1 },
    { "sec",		tSEC_UNIT,	1 },
    { NULL, 0, 0 }
};

/* Assorted relative-time words. */
static TABLE const OtherTable[] = {
    { "tomorrow",	tDAY_UNIT,	1 },
    { "yesterday",	tDAY_UNIT,	-1 },
    { "today",		tDAY_UNIT,	0 },
    { "now",		tDAY_UNIT,	0 },
    { "last",		tUNUMBER,	-1 },
    { "this",		tUNUMBER,	0 },
    { "next",		tUNUMBER,	2 },
    { "first",		tUNUMBER,	1 },
/*  { "second",		tUNUMBER,	2 }, */
    { "third",		tUNUMBER,	3 },
    { "fourth",		tUNUMBER,	4 },
    { "fifth",		tUNUMBER,	5 },
    { "sixth",		tUNUMBER,	6 },
    { "seventh",	tUNUMBER,	7 },
    { "eighth",		tUNUMBER,	8 },
    { "ninth",		tUNUMBER,	9 },
    { "tenth",		tUNUMBER,	10 },
    { "eleventh",	tUNUMBER,	11 },
    { "twelfth",	tUNUMBER,	12 },
    { "ago",		tAGO,	1 },
    { NULL, 0, 0 }
};

/* The timezone table. */
static TABLE const TimezoneTable[] = {
    { "gmt",	tZONE,     HOUR ( 0) },	/* Greenwich Mean */
    { "ut",	tZONE,     HOUR ( 0) },	/* Universal (Coordinated) */
    { "utc",	tZONE,     HOUR ( 0) },
    { "wet",	tZONE,     HOUR ( 0) },	/* Western European */
    { "bst",	tDAYZONE,  HOUR ( 0) },	/* British Summer */
    { "wat",	tZONE,     HOUR ( 1) },	/* West Africa */
    { "at",	tZONE,     HOUR ( 2) },	/* Azores */
#if	0
    /* For completeness.  BST is also British Summer, and GST is
     * also Guam Standard. */
    { "bst",	tZONE,     HOUR ( 3) },	/* Brazil Standard */
    { "gst",	tZONE,     HOUR ( 3) },	/* Greenland Standard */
#endif
#if 0
    { "nft",	tZONE,     HOUR (3.5) },	/* Newfoundland */
    { "nst",	tZONE,     HOUR (3.5) },	/* Newfoundland Standard */
    { "ndt",	tDAYZONE,  HOUR (3.5) },	/* Newfoundland Daylight */
#endif
    { "ast",	tZONE,     HOUR ( 4) },	/* Atlantic Standard */
    { "adt",	tDAYZONE,  HOUR ( 4) },	/* Atlantic Daylight */
    { "est",	tZONE,     HOUR ( 5) },	/* Eastern Standard */
    { "edt",	tDAYZONE,  HOUR ( 5) },	/* Eastern Daylight */
    { "cst",	tZONE,     HOUR ( 6) },	/* Central Standard */
    { "cdt",	tDAYZONE,  HOUR ( 6) },	/* Central Daylight */
    { "mst",	tZONE,     HOUR ( 7) },	/* Mountain Standard */
    { "mdt",	tDAYZONE,  HOUR ( 7) },	/* Mountain Daylight */
    { "pst",	tZONE,     HOUR ( 8) },	/* Pacific Standard */
    { "pdt",	tDAYZONE,  HOUR ( 8) },	/* Pacific Daylight */
    { "yst",	tZONE,     HOUR ( 9) },	/* Yukon Standard */
    { "ydt",	tDAYZONE,  HOUR ( 9) },	/* Yukon Daylight */
    { "hst",	tZONE,     HOUR (10) },	/* Hawaii Standard */
    { "hdt",	tDAYZONE,  HOUR (10) },	/* Hawaii Daylight */
    { "cat",	tZONE,     HOUR (10) },	/* Central Alaska */
    { "akst",	tZONE,     HOUR (10) }, /* Alaska Standard */
    { "akdt",	tZONE,     HOUR (10) }, /* Alaska Daylight */
    { "ahst",	tZONE,     HOUR (10) },	/* Alaska-Hawaii Standard */
    { "nt",	tZONE,     HOUR (11) },	/* Nome */
    { "idlw",	tZONE,     HOUR (12) },	/* International Date Line West */
    { "cet",	tZONE,     -HOUR (1) },	/* Central European */
    { "cest",	tDAYZONE,  -HOUR (1) },	/* Central European Summer */
    { "met",	tZONE,     -HOUR (1) },	/* Middle European */
    { "mewt",	tZONE,     -HOUR (1) },	/* Middle European Winter */
    { "mest",	tDAYZONE,  -HOUR (1) },	/* Middle European Summer */
    { "mesz",	tDAYZONE,  -HOUR (1) },	/* Middle European Summer */
    { "swt",	tZONE,     -HOUR (1) },	/* Swedish Winter */
    { "sst",	tDAYZONE,  -HOUR (1) },	/* Swedish Summer */
    { "fwt",	tZONE,     -HOUR (1) },	/* French Winter */
    { "fst",	tDAYZONE,  -HOUR (1) },	/* French Summer */
    { "eet",	tZONE,     -HOUR (2) },	/* Eastern Europe, USSR Zone 1 */
    { "bt",	tZONE,     -HOUR (3) },	/* Baghdad, USSR Zone 2 */
#if 0
    { "it",	tZONE,     -HOUR (3.5) },/* Iran */
#endif
    { "zp4",	tZONE,     -HOUR (4) },	/* USSR Zone 3 */
    { "zp5",	tZONE,     -HOUR (5) },	/* USSR Zone 4 */
#if 0
    { "ist",	tZONE,     -HOUR (5.5) },/* Indian Standard */
#endif
    { "zp6",	tZONE,     -HOUR (6) },	/* USSR Zone 5 */
#if	0
    /* For completeness.  NST is also Newfoundland Standard, and SST is
     * also Swedish Summer. */
    { "nst",	tZONE,     -HOUR (6.5) },/* North Sumatra */
    { "sst",	tZONE,     -HOUR (7) },	/* South Sumatra, USSR Zone 6 */
#endif	/* 0 */
    { "wast",	tZONE,     -HOUR (7) },	/* West Australian Standard */
    { "wadt",	tDAYZONE,  -HOUR (7) },	/* West Australian Daylight */
#if 0
    { "jt",	tZONE,     -HOUR (7.5) },/* Java (3pm in Cronusland!) */
#endif
    { "cct",	tZONE,     -HOUR (8) },	/* China Coast, USSR Zone 7 */
    { "jst",	tZONE,     -HOUR (9) },	/* Japan Standard, USSR Zone 8 */
#if 0
    { "cast",	tZONE,     -HOUR (9.5) },/* Central Australian Standard */
    { "cadt",	tDAYZONE,  -HOUR (9.5) },/* Central Australian Daylight */
#endif
    { "east",	tZONE,     -HOUR (10) },	/* Eastern Australian Standard */
    { "eadt",	tDAYZONE,  -HOUR (10) },	/* Eastern Australian Daylight */
    { "gst",	tZONE,     -HOUR (10) },	/* Guam Standard, USSR Zone 9 */
    { "nzt",	tZONE,     -HOUR (12) },	/* New Zealand */
    { "nzst",	tZONE,     -HOUR (12) },	/* New Zealand Standard */
    { "nzdt",	tDAYZONE,  -HOUR (12) },	/* New Zealand Daylight */
    { "idle",	tZONE,     -HOUR (12) },	/* International Date Line East */
    {  NULL, 0, 0  }
};

/* Military timezone table. */
static TABLE const MilitaryTable[] = {
    { "a",	tZONE,	HOUR (- 1) },
    { "b",	tZONE,	HOUR (- 2) },
    { "c",	tZONE,	HOUR (- 3) },
    { "d",	tZONE,	HOUR (- 4) },
    { "e",	tZONE,	HOUR (- 5) },
    { "f",	tZONE,	HOUR (- 6) },
    { "g",	tZONE,	HOUR (- 7) },
    { "h",	tZONE,	HOUR (- 8) },
    { "i",	tZONE,	HOUR (- 9) },
    { "k",	tZONE,	HOUR (-10) },
    { "l",	tZONE,	HOUR (-11) },
    { "m",	tZONE,	HOUR (-12) },
    { "n",	tZONE,	HOUR (  1) },
    { "o",	tZONE,	HOUR (  2) },
    { "p",	tZONE,	HOUR (  3) },
    { "q",	tZONE,	HOUR (  4) },
    { "r",	tZONE,	HOUR (  5) },
    { "s",	tZONE,	HOUR (  6) },
    { "t",	tZONE,	HOUR (  7) },
    { "u",	tZONE,	HOUR (  8) },
    { "v",	tZONE,	HOUR (  9) },
    { "w",	tZONE,	HOUR ( 10) },
    { "x",	tZONE,	HOUR ( 11) },
    { "y",	tZONE,	HOUR ( 12) },
    { "z",	tZONE,	HOUR (  0) },
    { NULL, 0, 0 }
};




/* ARGSUSED */
static int
yyerror (s)
     char *s ATTRIBUTE_UNUSED;
{
  return 0;
}

static int
ToHour (Hours, Meridian)
     int Hours;
     MERIDIAN Meridian;
{
  switch (Meridian)
    {
    case MER24:
      if (Hours < 0 || Hours > 23)
	return -1;
      return Hours;
    case MERam:
      if (Hours < 1 || Hours > 12)
	return -1;
      if (Hours == 12)
	Hours = 0;
      return Hours;
    case MERpm:
      if (Hours < 1 || Hours > 12)
	return -1;
      if (Hours == 12)
	Hours = 0;
      return Hours + 12;
    default:
      abort ();
    }
  /* NOTREACHED */
}

static int
ToYear (Year)
     int Year;
{
  if (Year < 0)
    Year = -Year;

  /* XPG4 suggests that years 00-68 map to 2000-2068, and
     years 69-99 map to 1969-1999.  */
  if (Year < 69)
    Year += 2000;
  else if (Year < 100)
    Year += 1900;

  return Year;
}

static int
LookupWord (lvalp,buff)
	YYSTYPE *lvalp;
     char *buff;
{
  register char *p;
  register char *q;
  register const TABLE *tp;
  int i;
  int abbrev;

  /* Make it lowercase. */
  for (p = buff; *p; p++)
    if (ISUPPER ((unsigned char) *p))
      *p = tolower (*p);

  if (strcmp (buff, "am") == 0 || strcmp (buff, "a.m.") == 0)
    {
      lvalp->Meridian = MERam;
      return tMERIDIAN;
    }
  if (strcmp (buff, "pm") == 0 || strcmp (buff, "p.m.") == 0)
    {
      lvalp->Meridian = MERpm;
      return tMERIDIAN;
    }

  /* See if we have an abbreviation for a month. */
  if (strlen (buff) == 3)
    abbrev = 1;
  else if (strlen (buff) == 4 && buff[3] == '.')
    {
      abbrev = 1;
      buff[3] = '\0';
    }
  else
    abbrev = 0;

  for (tp = MonthDayTable; tp->name; tp++)
    {
      if (abbrev)
	{
	  if (strncmp (buff, tp->name, 3) == 0)
	    {
	      lvalp->Number = tp->value;
	      return tp->type;
	    }
	}
      else if (strcmp (buff, tp->name) == 0)
	{
	  lvalp->Number = tp->value;
	  return tp->type;
	}
    }

  for (tp = TimezoneTable; tp->name; tp++)
    if (strcmp (buff, tp->name) == 0)
      {
	lvalp->Number = tp->value;
	return tp->type;
      }

  if (strcmp (buff, "dst") == 0)
    return tDST;

  for (tp = UnitsTable; tp->name; tp++)
    if (strcmp (buff, tp->name) == 0)
      {
	lvalp->Number = tp->value;
	return tp->type;
      }

  /* Strip off any plural and try the units table again. */
  i = strlen (buff) - 1;
  if (buff[i] == 's')
    {
      buff[i] = '\0';
      for (tp = UnitsTable; tp->name; tp++)
	if (strcmp (buff, tp->name) == 0)
	  {
	    lvalp->Number = tp->value;
	    return tp->type;
	  }
      buff[i] = 's';		/* Put back for "this" in OtherTable. */
    }

  for (tp = OtherTable; tp->name; tp++)
    if (strcmp (buff, tp->name) == 0)
      {
	lvalp->Number = tp->value;
	return tp->type;
      }

  /* Military timezones. */
  if (buff[1] == '\0' && ISALPHA ((unsigned char) *buff))
    {
      for (tp = MilitaryTable; tp->name; tp++)
	if (strcmp (buff, tp->name) == 0)
	  {
	    lvalp->Number = tp->value;
	    return tp->type;
	  }
    }

  /* Drop out any periods and try the timezone table again. */
  for (i = 0, p = q = buff; *q; q++)
    if (*q != '.')
      *p++ = *q;
    else
      i++;
  *p = '\0';
  if (i)
    for (tp = TimezoneTable; tp->name; tp++)
      if (strcmp (buff, tp->name) == 0)
	{
	  lvalp->Number = tp->value;
	  return tp->type;
	}

  return tID;
}

yylex (YYSTYPE *lvalp, void *parm)
{
  register unsigned char c;
  register char *p;
  char buff[20];
  int Count;
  int sign;
  struct date_yy * date = (struct date_yy *)parm;

  for (;;)
    {
      while (ISSPACE ((unsigned char) *date->yyInput))
	date->yyInput++;

      if (ISDIGIT (c = *date->yyInput) || c == '-' || c == '+')
	{
	  if (c == '-' || c == '+')
	    {
	      sign = c == '-' ? -1 : 1;
	      if (!ISDIGIT (*++date->yyInput))
		/* skip the '-' sign */
		continue;
	    }
	  else
	    sign = 0;
	  for (lvalp->Number = 0; ISDIGIT (c = *date->yyInput++);)
	    lvalp->Number = 10 * lvalp->Number + c - '0';
	  date->yyInput--;
	  if (sign < 0)
	    lvalp->Number = -lvalp->Number;
	  /* Ignore ordinal suffixes on numbers */
	  c = *date->yyInput;
	  if (c == 's' || c == 'n' || c == 'r' || c == 't') {
	    c = *++date->yyInput;
	    if (c == 't' || c == 'd' || c == 'h') {
	      date->yyInput++;
	    } else {
	      date->yyInput--;
	    }
	  }
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
	  printf ("T: %s\n", sign ? "tS" : "tU");
#endif
	  return sign ? tSNUMBER : tUNUMBER;
	}
      if (ISALPHA (c))
	{
	  for (p = buff; (c = *date->yyInput++, ISALPHA (c)) || c == '.';)
	    if (p < &buff[sizeof buff - 1])
	      *p++ = c;
	  *p = '\0';
	  date->yyInput--;
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
	  printf ("T: LW\n");
#endif
	  return LookupWord (lvalp, buff);
	}
      if (c != '(') {
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
	printf ("T: %c\n", *date->yyInput);
#endif
	return *date->yyInput++;
	  }
      Count = 0;
      do
	{
	  c = *date->yyInput++;
	  if (c == '\0') {
#ifdef PHP_DEBUG_PARSE_DATE_PARSER
	printf ("T: %c\n", c);
#endif
	    return c;
	  }
	  if (c == '(')
	    Count++;
	  else if (c == ')')
	    Count--;
	}
      while (Count > 0);
    }
}

#define TM_YEAR_ORIGIN 1900

/* Yield A - B, measured in seconds.  */
static long
difftm (struct tm *a, struct tm *b)
{
  int ay = a->tm_year + (TM_YEAR_ORIGIN - 1);
  int by = b->tm_year + (TM_YEAR_ORIGIN - 1);
  long days = (
  /* difference in day of year */
		a->tm_yday - b->tm_yday
  /* + intervening leap days */
		+ ((ay >> 2) - (by >> 2))
		- (ay / 100 - by / 100)
		+ ((ay / 100 >> 2) - (by / 100 >> 2))
  /* + difference in years * 365 */
		+ (long) (ay - by) * 365
  );
  return (60 * (60 * (24 * days + (a->tm_hour - b->tm_hour))
		+ (a->tm_min - b->tm_min))
	  + (a->tm_sec - b->tm_sec));
}

time_t php_parse_date(char *p, time_t *now)
{
  struct tm tm, tm0, *tmp;
  time_t Start;
  struct date_yy date;

  date.yyInput = p;
  Start = now ? *now : time ((time_t *) NULL);
  tmp = localtime (&Start);
  if (!tmp)
    return -1;
  date.yyYear = tmp->tm_year + TM_YEAR_ORIGIN;
  date.yyMonth = tmp->tm_mon + 1;
  date.yyDay = tmp->tm_mday;
  date.yyHour = tmp->tm_hour;
  date.yyMinutes = tmp->tm_min;
  date.yySeconds = tmp->tm_sec;
  tm.tm_isdst = tmp->tm_isdst;
  date.yyMeridian = MER24;
  date.yyRelSeconds = 0;
  date.yyRelMinutes = 0;
  date.yyRelHour = 0;
  date.yyRelDay = 0;
  date.yyRelMonth = 0;
  date.yyRelYear = 0;
  date.yyHaveDate = 0;
  date.yyHaveDay = 0;
  date.yyHaveRel = 0;
  date.yyHaveTime = 0;
  date.yyHaveZone = 0;

  if (yyparse ((void *)&date)
      || date.yyHaveTime > 1 || date.yyHaveZone > 1 
	  || date.yyHaveDate > 1 || date.yyHaveDay > 1)
    return -1;

  tm.tm_year = ToYear (date.yyYear) - TM_YEAR_ORIGIN + date.yyRelYear;
  tm.tm_mon = date.yyMonth - 1 + date.yyRelMonth;
  tm.tm_mday = date.yyDay + date.yyRelDay;
  if (date.yyHaveTime || (date.yyHaveRel && !date.yyHaveDate && !date.yyHaveDay))
    {
      tm.tm_hour = ToHour (date.yyHour, date.yyMeridian);
      if (tm.tm_hour < 0)
	return -1;
      tm.tm_min = date.yyMinutes;
      tm.tm_sec = date.yySeconds;
    }
  else
    {
      tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
    }
  tm.tm_hour += date.yyRelHour;
  tm.tm_min += date.yyRelMinutes;
  tm.tm_sec += date.yyRelSeconds;

  /* Let mktime deduce tm_isdst if we have an absolute timestamp,
     or if the relative timestamp mentions days, months, or years.  */
  if (date.yyHaveDate | date.yyHaveDay | date.yyHaveTime | date.yyRelDay | date.yyRelMonth | date.yyRelYear)
    tm.tm_isdst = -1;

  tm0 = tm;

  Start = mktime (&tm);

  if (Start == (time_t) -1)
    {

      /* Guard against falsely reporting errors near the time_t boundaries
         when parsing times in other time zones.  For example, if the min
         time_t value is 1970-01-01 00:00:00 UTC and we are 8 hours ahead
         of UTC, then the min localtime value is 1970-01-01 08:00:00; if
         we apply mktime to 1970-01-01 00:00:00 we will get an error, so
         we apply mktime to 1970-01-02 08:00:00 instead and adjust the time
         zone by 24 hours to compensate.  This algorithm assumes that
         there is no DST transition within a day of the time_t boundaries.  */
      if (date.yyHaveZone)
	{
	  tm = tm0;
	  if (tm.tm_year <= EPOCH - TM_YEAR_ORIGIN)
	    {
	      tm.tm_mday++;
	      date.yyTimezone -= 24 * 60;
	    }
	  else
	    {
	      tm.tm_mday--;
	      date.yyTimezone += 24 * 60;
	    }
	  Start = mktime (&tm);
	}

      if (Start == (time_t) -1)
	return Start;
    }

  if (date.yyHaveDay && !date.yyHaveDate)
    {
      tm.tm_mday += ((date.yyDayNumber - tm.tm_wday + 7) % 7
		     + 7 * (date.yyDayOrdinal - (0 < date.yyDayOrdinal)));
      Start = mktime (&tm);
      if (Start == (time_t) -1)
	return Start;
    }

  if (date.yyHaveZone)
    {
      long delta;
      struct tm *gmt = gmtime (&Start);
      if (!gmt)
	return -1;
      delta = date.yyTimezone * 60L + difftm (&tm, gmt);
      if ((Start + delta < Start) != (delta < 0))
	return -1;		/* time_t overflow */
      Start += delta;
    }

  return Start;
}
