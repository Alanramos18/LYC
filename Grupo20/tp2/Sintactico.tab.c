
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ErrorDim "La cantidad de tipos de variables es distinta a la cantidad de variables"
#define BUFFER_SIZE 1000

struct node 
{
    char data[255];
    struct node* left;
    struct node* right;
};

FILE *yyin;
FILE *fptr;
FILE *ftemp;

int dimVariable = 0;
int dimTipo = 0;
int flag = 0;
int ifflag = 0;
int listflag = 0;
int body = 0;
char step[255];
char buffer[BUFFER_SIZE];
char dimVariableList[5][20];
char dimTipoList[5][20];
char idToAssign[20];
int value;
char condition[2];
char signo[1];
char auxConvert[255];
char auxConvert2[255];
void yyerror(char *s);
int yylex(void);
int CheckDim(void);
void SaveInFile(void);
void SaveValue(void);
void AddValue(char *str, const char *id, const int value);

struct node* progptr; 
struct node* linesptr; 
struct node* lineptr; 
struct node* Aptr;
struct node* Fptr;
struct node* saltoPtr;
struct node* Vptr;
struct node* Wptr;
struct node* selPtr;
struct node* condfinPtr;
struct node* accionPtr;
struct node* bodyPtr;
struct node* elsePtr;
struct node* auxPtr;
struct node* disPtr;
struct node* getPtr;
struct node* retFalsePtr;
struct node* retTruePtr;
struct node* expPtr;
struct node* maxPtr;
struct node* EPtr;

struct node* create_leaf(char data[255]);
struct node* create_node(char data[255], struct node* right, struct node* left);
void ReadTree(struct node* tree);



/* Line 189 of yacc.c  */
#line 143 "Sintactico.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     INT = 259,
     ID = 260,
     WHILE = 261,
     PARAB = 262,
     PARCE = 263,
     CORAB = 264,
     CORCE = 265,
     OP_MAY = 266,
     IF = 267,
     ELSE = 268,
     OP_AS = 269,
     DIM = 270,
     AS = 271,
     COMA = 272,
     STRINGT = 273,
     INTEGER = 274,
     REAL = 275,
     CUAAB = 276,
     CUACE = 277,
     FOR = 278,
     TO = 279,
     NEXT = 280,
     EQUMAX = 281,
     EQUMIN = 282,
     FIN = 283,
     OP_MEN = 284,
     OP_MAYIGU = 285,
     OP_MENIGU = 286,
     OP_IGU = 287,
     OP_DIST = 288,
     DISPLAY = 289,
     GET = 290,
     NOT = 291,
     AND = 292,
     OR = 293,
     REA = 294,
     MAS = 295,
     MENOS = 296,
     POR = 297,
     DIV = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 69 "Sintactico.y"

    char name[20];
    int num;



/* Line 214 of yacc.c  */
#line 229 "Sintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 241 "Sintactico.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   89

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    12,    14,    16,    19,
      22,    26,    29,    31,    35,    39,    40,    47,    51,    53,
      56,    57,    62,    63,    68,    70,    74,    76,    78,    80,
      82,    84,    86,    87,    88,    94,    98,   101,   104,   109,
     113,   115,   119,   123,   125,   129,   131,   133,   135,   136,
     148,   151,   155,   162,   164,   166,   170,   172,   174,   176,
     178,   182,   184,   185,   190,   192
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    -1,    48,    -1,    -1,    48,    47,
      46,    -1,    49,    -1,    50,    -1,    61,    28,    -1,    62,
      28,    -1,    35,     5,    28,    -1,    63,    28,    -1,    69,
      -1,     6,    52,    58,    -1,    12,    52,    58,    -1,    -1,
      12,    52,    58,    51,    13,    58,    -1,     7,    53,     8,
      -1,    56,    -1,    36,    56,    -1,    -1,    56,    54,    38,
      56,    -1,    -1,    56,    55,    37,    56,    -1,    72,    -1,
       5,    57,    79,    -1,    11,    -1,    29,    -1,    30,    -1,
      31,    -1,    32,    -1,    33,    -1,    -1,    -1,     9,    59,
      46,    60,    10,    -1,     5,    14,    79,    -1,    34,     3,
      -1,    34,     5,    -1,    15,    64,    16,    66,    -1,    21,
      65,    22,    -1,     5,    -1,    65,    17,     5,    -1,    21,
      67,    22,    -1,    68,    -1,    67,    17,    68,    -1,    18,
      -1,    20,    -1,    19,    -1,    -1,    23,     5,    14,     4,
      24,     4,    71,    70,    46,    25,     5,    -1,    21,    22,
      -1,    21,     4,    22,    -1,    73,     7,    74,    28,    76,
       8,    -1,    26,    -1,    27,    -1,     4,    75,     4,    -1,
      40,    -1,    41,    -1,    42,    -1,    43,    -1,    21,    77,
      22,    -1,    79,    -1,    -1,    79,    17,    78,    77,    -1,
       5,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    85,    96,    96,   118,   119,   120,   121,
     122,   123,   124,   128,   132,   133,   133,   137,   139,   140,
     141,   141,   142,   142,   143,   145,   147,   148,   149,   150,
     151,   152,   154,   154,   154,   158,   162,   163,   166,   168,
     170,   171,   173,   175,   176,   178,   179,   180,   186,   186,
     198,   199,   203,   212,   213,   215,   222,   223,   224,   225,
     227,   229,   244,   244,   260,   261
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "INT", "ID", "WHILE", "PARAB",
  "PARCE", "CORAB", "CORCE", "OP_MAY", "IF", "ELSE", "OP_AS", "DIM", "AS",
  "COMA", "STRINGT", "INTEGER", "REAL", "CUAAB", "CUACE", "FOR", "TO",
  "NEXT", "EQUMAX", "EQUMIN", "FIN", "OP_MEN", "OP_MAYIGU", "OP_MENIGU",
  "OP_IGU", "OP_DIST", "DISPLAY", "GET", "NOT", "AND", "OR", "REA", "MAS",
  "MENOS", "POR", "DIV", "$accept", "prog", "lines", "$@1", "line", "W",
  "I", "$@2", "COMPARATION", "COND", "$@3", "$@4", "CONDFINAL",
  "CONDITION", "BODY", "$@5", "$@6", "A", "DIS", "D", "LISTAVARIABLE",
  "VARIABLES", "LISTATIPO", "TIPOS", "TIPO", "F", "$@7", "STEP", "E",
  "EQU", "EXPRESIONEQU", "SIGNO", "LISTAEQU", "ELEMENTOEQU", "$@8", "V", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    47,    46,    48,    48,    48,    48,
      48,    48,    48,    49,    50,    51,    50,    52,    53,    53,
      54,    53,    55,    53,    53,    56,    57,    57,    57,    57,
      57,    57,    59,    60,    58,    61,    62,    62,    63,    64,
      65,    65,    66,    67,    67,    68,    68,    68,    70,    69,
      71,    71,    72,    73,    73,    74,    75,    75,    75,    75,
      76,    77,    78,    77,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     3,     1,     1,     2,     2,
       3,     2,     1,     3,     3,     0,     6,     3,     1,     2,
       0,     4,     0,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     0,     0,     5,     3,     2,     2,     4,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     0,    11,
       2,     3,     6,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     0,     4,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       4,     6,     7,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,    36,    37,     0,     1,     0,     8,
       9,    11,    65,    64,    35,     0,    53,    54,     0,     0,
      18,    24,     0,    32,    13,    14,    40,     0,     0,     0,
      10,     5,    26,    27,    28,    29,    30,    31,     0,    19,
      17,     0,     0,     0,     0,     0,     0,    39,     0,    38,
       0,    25,     0,     0,     0,     0,    33,     0,    41,    45,
      47,    46,     0,    43,     0,    21,    23,    56,    57,    58,
      59,     0,     0,     0,    16,     0,    42,     0,    55,     0,
       0,    34,    44,     0,    48,     0,    61,    52,     0,    50,
       0,    60,    62,    51,     0,     0,     0,    63,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    28,    10,    11,    12,    65,    19,    39,
      61,    62,    40,    58,    44,    64,    93,    13,    14,    15,
      22,    47,    69,    82,    83,    16,   110,   104,    41,    42,
      75,    91,   100,   105,   115,   106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -36
static const yytype_int8 yypact[] =
{
       5,    -5,    11,    11,    -2,    36,    19,    37,    21,   -36,
       6,   -36,   -36,    26,    27,    28,   -36,    25,    -1,    35,
      35,    52,    43,    46,   -36,   -36,    33,   -36,     5,   -36,
     -36,   -36,   -36,   -36,   -36,    16,   -36,   -36,    57,    55,
     -23,   -36,    58,   -36,   -36,    51,   -36,   -10,    45,    63,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,    25,   -36,
     -36,    30,    32,    66,     5,    59,    68,   -36,    14,   -36,
      47,   -36,    57,    57,    10,    48,   -36,    35,   -36,   -36,
     -36,   -36,    -9,   -36,    70,   -36,   -36,   -36,   -36,   -36,
     -36,    71,    56,    69,   -36,    14,   -36,    60,   -36,    25,
      72,   -36,   -36,     1,   -36,    61,    67,   -36,    64,   -36,
       5,   -36,   -36,   -36,    53,    25,    80,   -36,   -36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   -28,   -36,   -36,   -36,   -36,   -36,    84,   -36,
     -36,   -36,   -35,   -36,   -19,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,    -7,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -26,   -36,   -15
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -23
static const yytype_int8 yytable[] =
{
      51,    45,    34,    59,    35,   108,    -3,    66,    95,    17,
       1,     2,    67,    96,   -22,   -20,    -3,     3,    18,    21,
       4,    27,    24,   109,    25,    36,    37,    52,     5,    32,
      33,    -3,    79,    80,    81,    38,    76,    85,    86,     6,
       7,    23,    26,    71,    43,    53,    54,    55,    56,    57,
      87,    88,    89,    90,    29,    30,    31,    46,    94,    48,
      49,    50,    35,    60,   -15,    63,    68,    70,    72,    73,
      74,    84,    77,    78,    97,    98,    92,    99,   116,   101,
     107,   103,   114,   111,   112,   118,   113,    20,   102,   117
};

static const yytype_uint8 yycheck[] =
{
      28,    20,    17,    38,     5,     4,     0,    17,    17,    14,
       5,     6,    22,    22,    37,    38,    10,    12,     7,    21,
      15,     0,     3,    22,     5,    26,    27,    11,    23,     4,
       5,    25,    18,    19,    20,    36,    64,    72,    73,    34,
      35,     5,     5,    58,     9,    29,    30,    31,    32,    33,
      40,    41,    42,    43,    28,    28,    28,     5,    77,    16,
      14,    28,     5,     8,    13,     7,    21,     4,    38,    37,
       4,    24,    13,     5,     4,     4,    28,    21,    25,    10,
       8,    21,   110,    22,    17,     5,    22,     3,    95,   115
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    12,    15,    23,    34,    35,    45,    46,
      48,    49,    50,    61,    62,    63,    69,    14,     7,    52,
      52,    21,    64,     5,     3,     5,     5,     0,    47,    28,
      28,    28,     4,     5,    79,     5,    26,    27,    36,    53,
      56,    72,    73,     9,    58,    58,     5,    65,    16,    14,
      28,    46,    11,    29,    30,    31,    32,    33,    57,    56,
       8,    54,    55,     7,    59,    51,    17,    22,    21,    66,
       4,    79,    38,    37,     4,    74,    46,    13,     5,    18,
      19,    20,    67,    68,    24,    56,    56,    40,    41,    42,
      43,    75,    28,    60,    58,    17,    22,     4,     4,    21,
      76,    10,    68,    21,    71,    77,    79,     8,     4,    22,
      70,    22,    17,    22,    46,    78,    25,    77,     5
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 83 "Sintactico.y"
    { progptr = linesptr; ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 85 "Sintactico.y"
    { 
    if(body == 1) {
        if(ifflag == 0)
        {
            bodyPtr = lineptr;
        } else {
            bodyPtr = create_node("L", lineptr, linesptr);
        }
    } else {
        linesptr = create_node("L", lineptr, linesptr);
    };}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 96 "Sintactico.y"
    {
        if(body == 1)
        {
            if(ifflag == 0)
            {
                ifflag = 1;
                auxPtr = linesptr;
                linesptr = lineptr;
            } else {
                bodyPtr = create_node("L", lineptr, linesptr);
            }
        } else {
            if(flag == 0)
            {
                flag = 1;
                linesptr = lineptr;
            } else {
                linesptr = create_node("L", lineptr, linesptr);
            }
        }
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 118 "Sintactico.y"
    {lineptr = Wptr;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 119 "Sintactico.y"
    {lineptr = selPtr;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 120 "Sintactico.y"
    {lineptr = Aptr;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 121 "Sintactico.y"
    {lineptr = disPtr;;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 122 "Sintactico.y"
    {lineptr = create_node("GET", NULL, create_leaf((yyvsp[(2) - (3)].name)));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 123 "Sintactico.y"
    {CheckDim(); printf("Se ha analizado un DIM\n\n\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 124 "Sintactico.y"
    {lineptr = Fptr;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 128 "Sintactico.y"
    { Wptr = create_node("WHILE", bodyPtr, condfinPtr); if(ifflag == 1) { linesptr = auxPtr; }; ifflag = 0;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 132 "Sintactico.y"
    {selPtr = create_node("IF", bodyPtr, condfinPtr); if(ifflag == 1) { linesptr = auxPtr; }; ifflag = 0; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 133 "Sintactico.y"
    {accionPtr = bodyPtr;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 133 "Sintactico.y"
    { elsePtr = bodyPtr;
                                                            bodyPtr = create_node("ELSE", elsePtr, accionPtr);
                                                            selPtr = create_node("IF", bodyPtr, condfinPtr);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 140 "Sintactico.y"
    {condfinPtr = create_node("!", NULL, condfinPtr);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 141 "Sintactico.y"
    {expPtr = condfinPtr;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 141 "Sintactico.y"
    { condfinPtr = create_node("||", condfinPtr, expPtr);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 142 "Sintactico.y"
    {expPtr = condfinPtr;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 142 "Sintactico.y"
    { condfinPtr = create_node("&&", condfinPtr, expPtr);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 143 "Sintactico.y"
    {condfinPtr = EPtr;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 145 "Sintactico.y"
    {condfinPtr = create_node(condition, Vptr, create_leaf((yyvsp[(1) - (3)].name)));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 147 "Sintactico.y"
    {strcpy(condition, ">");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 148 "Sintactico.y"
    {strcpy(condition, "<");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 149 "Sintactico.y"
    {strcpy(condition, ">=");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 150 "Sintactico.y"
    {strcpy(condition, "<=");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 151 "Sintactico.y"
    {strcpy(condition, "==");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 152 "Sintactico.y"
    {strcpy(condition, "!=");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 154 "Sintactico.y"
    {body = 1;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 154 "Sintactico.y"
    {body = 0;;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 158 "Sintactico.y"
    {strcpy(idToAssign, (yyvsp[(1) - (3)].name)); SaveValue(); Aptr = create_node(":=", Vptr, create_leaf((yyvsp[(1) - (3)].name)));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 162 "Sintactico.y"
    {printf("<DIS> --> DISPLAY STRING\n"); disPtr = create_node("Display", NULL, create_leaf((yyvsp[(2) - (2)].name)));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 163 "Sintactico.y"
    { disPtr = create_node("Display", NULL, create_leaf((yyvsp[(2) - (2)].name)));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 166 "Sintactico.y"
    {printf("<D> --> DIM LISTAVARIABLE AS LISTATIPO\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 168 "Sintactico.y"
    {printf("<LISTAVARIABLE> --> [ VARIABLES ]\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 170 "Sintactico.y"
    {strcpy(dimVariableList[dimVariable++], (yyvsp[(1) - (1)].name)); printf("<VARIABLES> --> ID\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 171 "Sintactico.y"
    {strcpy(dimVariableList[dimVariable++], (yyvsp[(3) - (3)].name)); printf("<VARIABLES> --> VARIABLES , ID\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 173 "Sintactico.y"
    {printf("<LISTATIPO> --> [ TIPOS ]\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 175 "Sintactico.y"
    {strcpy(dimTipoList[dimTipo++], (yyvsp[(1) - (1)].name)); printf("<TIPOS> --> TIPO\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 176 "Sintactico.y"
    {strcpy(dimTipoList[dimTipo++], (yyvsp[(3) - (3)].name)); printf("<TIPOS> --> TIPOS , TIPO\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 178 "Sintactico.y"
    {strcpy((yyval.name),"string"); printf("<TIPO> --> STRINGT\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 179 "Sintactico.y"
    {strcpy((yyval.name),"real"); printf("<TIPO> --> REAL\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 180 "Sintactico.y"
    {strcpy((yyval.name),"integer"); printf("<TIPO> --> INTEGER\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 186 "Sintactico.y"
    {body = 1;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 186 "Sintactico.y"
    {
        sprintf(auxConvert, "%d", (yyvsp[(4) - (11)].num));
        lineptr = create_node("=", create_leaf(auxConvert), create_leaf((yyvsp[(2) - (11)].name))); 
        sprintf(auxConvert, "%d", (yyvsp[(6) - (11)].num));
        condfinPtr = create_node("<=", create_leaf(auxConvert), create_leaf((yyvsp[(2) - (11)].name)));
        saltoPtr = create_node("=", create_node("+", create_leaf(step), create_leaf((yyvsp[(2) - (11)].name))), create_leaf((yyvsp[(2) - (11)].name)));
        body = 0;
        bodyPtr = create_node("BODYWHILE", saltoPtr, bodyPtr);
        Wptr = create_node("WHILE-FOR", bodyPtr, condfinPtr);
        Fptr = create_node("FOR", Wptr, lineptr);
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 199 "Sintactico.y"
    { sprintf(auxConvert, "%d", (yyvsp[(2) - (3)].num)); strcpy(step, auxConvert); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 203 "Sintactico.y"
    {
    condfinPtr = create_node("==", create_leaf("@max"), create_leaf("@num"));
    retFalsePtr = create_node("Return", NULL, create_leaf("False"));
    retTruePtr = create_node("Return", NULL, create_leaf("True"));
    expPtr = create_node("L", retFalsePtr, retTruePtr);
    selPtr = create_node("IF", expPtr, condfinPtr);
    EPtr = create_node("L", selPtr, EPtr);
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 215 "Sintactico.y"
    { 
    sprintf(auxConvert, "%d", (yyvsp[(1) - (3)].num));
    sprintf(auxConvert2, "%d", (yyvsp[(3) - (3)].num));
    expPtr = create_node(signo, create_leaf(auxConvert2), create_leaf(auxConvert));
    EPtr = create_node("=", expPtr, create_leaf("@num"));
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 222 "Sintactico.y"
    {strcpy(signo, "+");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 223 "Sintactico.y"
    {strcpy(signo, "-");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 224 "Sintactico.y"
    {strcpy(signo, "*");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 225 "Sintactico.y"
    {strcpy(signo, "/");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 229 "Sintactico.y"
    { 
        if (listflag == 0) {
            maxPtr = create_node("=", Vptr, create_leaf("@max"));
            listflag = 1;
        } else {
            expPtr = create_node("=", Vptr, create_leaf("@aux"));
            expPtr = create_node("L", expPtr, maxPtr);
            maxPtr = NULL;
            EPtr = create_node("L", expPtr, EPtr);
            condfinPtr = create_node(">", create_leaf("@max"), create_leaf("@aux"));
            expPtr = create_node("=", create_leaf("@aux"), create_leaf("@max"));
            selPtr = create_node("IF-EQU", expPtr, condfinPtr);
            EPtr = create_node("L", selPtr, EPtr);
        }
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 244 "Sintactico.y"
    {
    if (listflag == 0) {
        maxPtr = create_node("=", Vptr, create_leaf("@max"));
        listflag = 1;
    } else {
        expPtr = create_node("=", Vptr, create_leaf("@aux"));
        expPtr = create_node("L", expPtr, maxPtr);
        maxPtr = NULL;
        EPtr = create_node("L", expPtr, EPtr);
        condfinPtr = create_node(">", create_leaf("@max"), create_leaf("@aux"));
        expPtr = create_node("=", create_leaf("@aux"), create_leaf("@max"));
        selPtr = create_node("IF", expPtr, condfinPtr);
        EPtr = create_node("L", selPtr, EPtr);
    }
;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 260 "Sintactico.y"
    {Vptr = create_leaf((yyvsp[(1) - (1)].name));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 261 "Sintactico.y"
    {sprintf(auxConvert, "%d", (yyvsp[(1) - (1)].num)); Vptr = create_leaf(auxConvert);;}
    break;



/* Line 1455 of yacc.c  */
#line 1999 "Sintactico.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 264 "Sintactico.y"


int main(int argc,char *argv[])
{
    if ((yyin = fopen(argv[1], "rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
    }
    else
    {
        while(feof(yyin) == 0)
        {
            yyparse();
        }
    }
    
    fclose(yyin);
    
    if ((fptr = fopen("intermedia.txt", "w")) == NULL)
    {
        printf("\nNo se puede abrir el archivo intermedio\n");
    }
    else
    {
        ReadTree(progptr);
    }
    
    fclose(fptr);

    return 1;
}

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}

int CheckDim()
{
    if(dimVariable != dimTipo)
    {
        printf(ErrorDim);
        return 1;
    }
    
    SaveInFile();
}

void SaveInFile()
{
    if ((fptr = fopen("ts.txt", "w")) == NULL)
    {
        printf("\nNo se puede abrir el archivo de la tabla de simbolo\n");
    }
    else
    {
        fprintf(fptr,"%-15s %-15s %-15s %-15s\n", "NOMBRE", "TIPODATO", "VALOR", "LONGITUD");

        int x = 0;
        for(x = 0; x < dimVariable; x++)
        {
            fprintf(fptr,"%-15s %-15s %-15s %-15s\n", dimVariableList[x], dimTipoList[x], "-", "-");
        }
    }
    
    fclose(fptr);
}

void SaveValue()
{
    fptr = fopen("ts.txt", "r");
    ftemp = fopen("temp.txt", "w");

    if (fptr == NULL || ftemp == NULL)
    {
        printf("\nNo se puede abrir el archivo de la tabla de simbolo\n");
        exit(1);
    }
    
    while((fgets(buffer, BUFFER_SIZE, fptr)) != NULL)
    {
        AddValue(buffer, idToAssign, value);

        fputs(buffer, ftemp);
    }
    
    fclose(fptr);
    fclose(ftemp);

    remove("ts.txt");

    rename("temp.txt", "ts.txt");
}

void AddValue(char *str, const char *id, const int value)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen, valen;
    char valueConverted[20];
    itoa(value, valueConverted, 10);

    owlen = strlen(id);
    valen = strlen(valueConverted);
    pos = strstr(str, id);
    if(pos != NULL)
    {
        strcpy(temp, str);
        index = pos - str + 32;
        str[index] = '\0';    
        strcat(str, valueConverted);
        strcat(str, temp + 32 + valen);
    }
}

struct node* create_leaf(char data[255])
{
    struct node* node = (struct node*) malloc(sizeof(struct node));

    strcpy(node->data, data);
    node->right = NULL;
    node->left = NULL;

    return node;
}

struct node* create_node(char data[255], struct node* right, struct node* left)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    strcpy(node->data, data);
    node->right = right;
    node->left = left;

    return node;
}

void ReadTree(struct node* tree)
{
    if(tree != NULL)
    {
        ReadTree(tree->left);
        if(strcmp(tree->data, "L"))
        {
            fprintf(fptr,"%s ", tree->data);
            printf("%s ", tree->data);            
        } else {
            fprintf(fptr,"\n");
            printf("\n");
        }    
        ReadTree(tree->right);
    }
}