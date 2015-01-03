/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 2 "parser.ypp"

extern int yylineno;
extern char lexeme[64];
int error_count = 0;
int num_var=3;
int te=0;
int num_label=0;
int num_print=0;
int next_saved_reg=0,next_saved_float=20,next_loc_reg=3;
int break_allowed=0;
bool jump_found=false;
int method_count=0;
char newswitch[64],oldswitch[64],thisclass[64];
int offset_temp[100];

#define DEBUG_MODE 0
#define BYTE_CODE 0
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

enum Basic
{
	tbyte,tshort,tint,tlong,tfloat,tdouble,tfinal,tboolean,tnull,tvoid,tchar,tstring,tnone
};

enum Modifier
{
	mpublic,mprivate,mstatic,mprotected,mabstract,mfinal,mnative,msynchronized,mtransient,mvolatile,mstrictfp
};

typedef struct STE
{
	char *lexeme;
	enum Basic btype;
	char ref[64];
	int dimension;
	int offset;			//offset in the stack
	vector<int> modifiers;
	struct ST *table;
}STE;

typedef struct ST
{
	struct ST *prev;
	vector<STE> entries;
}ST;

stack<int> break_label,continue_label,ident_label;
ST *currenter=NULL;
ST *node=NULL;
void createtable(ST *parent);
void removetable(ST *tab);
STE *findentry(ST *tab,char *lexeme);
void insertentry(ST *tab,char *lexeme,vector<int> m,enum Basic b,char *ref,int dimension,int offset);
bool compare(vector<struct attribute *>,vector<struct attribute *>);
char *getNewTemp(); 
char *offToAddr(int offset);
char *Address(char *var,int val=0);

enum refType
{
	memory,reg,constant
};

enum refType Ref(char *str)
{
	if(str[0]=='$')
		return reg;
	else if(str[0]!='\"' && (str[0]=='(' || str[1]=='(' || str[2]=='(' || str[3]=='(' || str[4]=='('))
		return memory;
	return constant;
}

enum Basic findType(char tmp[],int size);

struct attribute
{
	int token;
	union
	{
		enum Basic type;
		char ref[64];
	};
	int dimension;
	char value[64];
	char contains[64];
	vector<int> modifier;
};

struct ClassInterface
{
        char name[64];
        vector<int> modifiers;
	vector<struct methodConstructor *> listOfMethods;
        ST *table;
        struct ClassInterface *implements;
        struct ClassInterface *extends;
};

struct methodConstructor
{
	vector<struct attribute *>param;
	char name[64];
	int number;
	int token;
	union
	{
		enum Basic type;
		char ref[64];
	};
	vector<int> modifier;
};

ST *temp;
int currenterpointer=-1;
bool publicFound=false;
bool returnFound=false;
int forSt=0;
char *publicName;
char id[64];
vector<ClassInterface>listOfClasses;
vector<int>listOfModifiers;
vector<struct attribute *> variables;		
vector<struct attribute *> param;
stack<char *> switches;

stack<int> labels;
FILE *fcg;				/*code generator*/
struct attribute *typeinfo;
struct attribute *returninfo;
struct attribute *currentobject=NULL;
struct methodConstructor *m;

int num_temp=0;					/*for code generation*/

extern "C"
{
	void yyerror(const char *str)
	{
        	error_count++;
        	fprintf(stderr,"error: %s on line %d\n",str,yylineno);
	}
	int yywrap()
	{		
		return 1;
	}
	int yylex(void);
}


/* Line 268 of yacc.c  */
#line 227 "parser.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     ERROR = 258,
     PRINTL = 259,
     PRINT = 260,
     STRING = 261,
     CHARACTERS = 262,
     BOOL = 263,
     NULLER = 264,
     IDENTIFIER = 265,
     HEX_INT = 266,
     BIN_INT = 267,
     OCT_INT = 268,
     INTEGER = 269,
     HEX_INT_LONG = 270,
     BIN_INT_LONG = 271,
     OCT_INT_LONG = 272,
     INTEGER_LONG = 273,
     FLOATING = 274,
     HEX_FLOAT = 275,
     FLOATING_FL = 276,
     HEX_FLOAT_FL = 277,
     ABSTRACT = 278,
     ASSERT = 279,
     BOOLEAN = 280,
     BREAK = 281,
     BYTE = 282,
     CASE = 283,
     CATCH = 284,
     CHAR = 285,
     CLASS = 286,
     CONST = 287,
     CONTINUE = 288,
     DEFAULT = 289,
     DO = 290,
     DOUBLE = 291,
     ELSE = 292,
     ENUM = 293,
     EXTENDS = 294,
     FINAL = 295,
     FINALLY = 296,
     FLOAT = 297,
     FOR = 298,
     IF = 299,
     GOTO = 300,
     IMPLEMENTS = 301,
     IMPORT = 302,
     INSTANCEOF = 303,
     INT = 304,
     INTERFACE = 305,
     LONG = 306,
     NATIVE = 307,
     NEW = 308,
     PACKAGE = 309,
     PRIVATE = 310,
     PROTECTED = 311,
     PUBLIC = 312,
     RETURN = 313,
     SHORT = 314,
     STATIC = 315,
     STRICTFP = 316,
     SUPER = 317,
     SWITCH = 318,
     SYNCHRONIZED = 319,
     THIS = 320,
     THROW = 321,
     THROWS = 322,
     TRANSIENT = 323,
     TRY = 324,
     VOID = 325,
     VOLATILE = 326,
     WHILE = 327,
     LRBRACE = 328,
     RRBRACE = 329,
     LCBRACE = 330,
     RCBRACE = 331,
     LSBRACE = 332,
     RSBRACE = 333,
     COMMA = 334,
     SEMICOLON = 335,
     DOT = 336,
     COLON = 337,
     TERNARY = 338,
     INCREMENT = 339,
     DECREMENT = 340,
     UNOT = 341,
     NEQ = 342,
     NOT = 343,
     COMPARE = 344,
     EQUAL = 345,
     MULTEQUAL = 346,
     PLUSEQUAL = 347,
     DIVEQUAL = 348,
     MINUSEQUAL = 349,
     MODEQUAL = 350,
     DIV = 351,
     MULT = 352,
     MOD = 353,
     PLUS = 354,
     MINUS = 355,
     LEFTSHIFTEQUAL = 356,
     RIGHTSHIFTEQUAL = 357,
     URIGHTSHIFTEQUAL = 358,
     LEFTSHIFT = 359,
     RIGHTSHIFT = 360,
     URIGHTSHIFT = 361,
     LEQ = 362,
     LT = 363,
     GT = 364,
     GEQ = 365,
     ANDEQUAL = 366,
     BAND = 367,
     OREQUAL = 368,
     BOR = 369,
     AND = 370,
     OR = 371,
     XOR = 372,
     XOREQUAL = 373,
     CAST = 374,
     UMINUS = 375,
     UPLUS = 376,
     PREDECREMENT = 377,
     PREINCREMENT = 378
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 158 "parser.ypp"

	struct attribute *attr;
	char str[1024];



/* Line 293 of yacc.c  */
#line 393 "parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 405 "parser.tab.cpp"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  124
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  151
/* YYNRULES -- Number of rules.  */
#define YYNRULES  453
/* YYNRULES -- Number of states.  */
#define YYNSTATES  753

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   378

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    49,    51,    53,    55,    57,
      59,    61,    63,    65,    67,    69,    71,    73,    75,    77,
      79,    81,    83,    87,    91,    95,   100,   105,   110,   114,
     117,   120,   122,   123,   127,   131,   133,   136,   140,   146,
     153,   160,   164,   169,   171,   174,   176,   178,   180,   182,
     183,   192,   193,   201,   202,   209,   210,   218,   219,   225,
     226,   233,   234,   240,   241,   246,   251,   255,   258,   260,
     262,   264,   266,   268,   270,   272,   274,   276,   278,   280,
     282,   285,   287,   290,   294,   298,   300,   303,   305,   307,
     310,   312,   314,   316,   318,   319,   325,   329,   333,   335,
     339,   341,   345,   350,   354,   359,   361,   363,   365,   368,
     373,   377,   381,   385,   390,   392,   396,   397,   401,   405,
     408,   412,   415,   416,   422,   423,   428,   433,   437,   442,
     448,   450,   454,   456,   460,   464,   468,   471,   478,   484,
     486,   488,   490,   494,   497,   500,   505,   509,   514,   519,
     521,   525,   531,   536,   542,   547,   553,   558,   564,   569,
     575,   580,   585,   589,   593,   598,   604,   609,   614,   619,
     623,   627,   631,   634,   641,   647,   653,   659,   664,   669,
     674,   678,   680,   684,   688,   691,   694,   696,   699,   701,
     705,   708,   712,   713,   721,   722,   729,   730,   736,   737,
     742,   747,   751,   755,   758,   760,   763,   765,   767,   769,
     773,   776,   780,   783,   786,   790,   794,   796,   799,   801,
     803,   805,   806,   809,   811,   814,   815,   820,   821,   829,
     833,   834,   843,   847,   848,   849,   857,   861,   862,   871,
     875,   876,   877,   885,   889,   893,   898,   901,   905,   909,
     914,   917,   921,   925,   928,   932,   933,   934,   938,   940,
     942,   944,   946,   948,   950,   953,   954,   958,   960,   963,
     967,   970,   975,   980,   985,   989,   990,   997,   998,  1005,
    1006,  1009,  1010,  1012,  1013,  1015,  1017,  1021,  1023,  1025,
    1027,  1029,  1033,  1035,  1037,  1039,  1041,  1047,  1052,  1058,
    1064,  1066,  1070,  1075,  1079,  1084,  1088,  1090,  1093,  1097,
    1100,  1104,  1108,  1112,  1116,  1121,  1127,  1131,  1136,  1142,
    1146,  1150,  1155,  1159,  1164,  1169,  1173,  1180,  1186,  1193,
    1201,  1207,  1214,  1221,  1229,  1235,  1242,  1247,  1252,  1258,
    1264,  1266,  1268,  1270,  1273,  1275,  1278,  1281,  1283,  1287,
    1290,  1294,  1296,  1301,  1305,  1307,  1312,  1316,  1318,  1323,
    1327,  1329,  1334,  1338,  1340,  1345,  1349,  1351,  1356,  1360,
    1362,  1367,  1371,  1373,  1378,  1379,  1384,  1386,  1391,  1392,
    1397,  1399,  1404,  1406,  1407,  1408,  1416,  1421,  1423,  1425,
    1429,  1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,
    1452,  1456,  1460,  1464,  1468,  1472,  1476,  1480,  1482,  1484,
    1486,  1488,  1490,  1492,  1494,  1496,  1498,  1500,  1502,  1504,
    1506,  1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,  1524,
    1526,  1528,  1530,  1532
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     125,     0,    -1,    -1,   126,   141,    -1,    10,    -1,   129,
      -1,   130,    -1,     8,    -1,     7,    -1,     6,    -1,     9,
      -1,     3,    -1,    14,    -1,    11,    -1,    12,    -1,    13,
      -1,    18,    -1,    15,    -1,    16,    -1,    17,    -1,    20,
      -1,    19,    -1,    22,    -1,    21,    -1,   132,    -1,   136,
      -1,   133,    -1,    25,    -1,   134,    -1,   135,    -1,    27,
      -1,    59,    -1,    49,    -1,    51,    -1,    30,    -1,    42,
      -1,    36,    -1,   137,    -1,   140,    -1,   138,    -1,   139,
      -1,   127,    -1,   132,    77,    78,    -1,   138,    77,    78,
      -1,   140,    77,    78,    -1,   132,    77,     1,    80,    -1,
     138,    77,     1,    80,    -1,   140,    77,     1,    80,    -1,
     142,   143,   145,    -1,   142,   145,    -1,   143,   146,    -1,
     145,    -1,    -1,    54,   138,    80,    -1,    54,     1,    80,
      -1,   144,    -1,   143,   144,    -1,    47,   138,    80,    -1,
      47,   138,    81,    97,    80,    -1,    47,    60,   138,    81,
     127,    80,    -1,    47,    60,   138,    81,    97,    80,    -1,
      47,     1,    80,    -1,    47,    60,     1,    80,    -1,   146,
      -1,   145,   146,    -1,   147,    -1,   194,    -1,   148,    -1,
     188,    -1,    -1,   157,    31,   127,    39,   137,   159,   149,
     161,    -1,    -1,    31,   127,    39,   137,   159,   150,   161,
      -1,    -1,   157,    31,   127,   159,   151,   161,    -1,    -1,
     157,    31,   127,    39,   137,   152,   161,    -1,    -1,    31,
     127,   159,   153,   161,    -1,    -1,    31,   127,    39,   137,
     154,   161,    -1,    -1,   157,    31,   127,   155,   161,    -1,
      -1,    31,   127,   156,   161,    -1,   157,    31,     1,   161,
      -1,    31,     1,   161,    -1,   157,   158,    -1,   158,    -1,
      57,    -1,    55,    -1,    56,    -1,    23,    -1,    60,    -1,
      40,    -1,    52,    -1,    64,    -1,    68,    -1,    71,    -1,
      61,    -1,    46,   160,    -1,   137,    -1,    75,    76,    -1,
      75,   162,    76,    -1,    75,     1,    76,    -1,   163,    -1,
     162,   163,    -1,   164,    -1,   203,    -1,    60,   203,    -1,
     184,    -1,   165,    -1,   173,    -1,    80,    -1,    -1,   157,
     131,   167,   166,    80,    -1,   131,   167,    80,    -1,   131,
       1,    80,    -1,   168,    -1,   167,    79,   168,    -1,   169,
      -1,   169,    90,   170,    -1,   169,    90,     1,    80,    -1,
     169,    77,    78,    -1,   169,    77,     1,    80,    -1,   127,
      -1,   263,    -1,   171,    -1,    75,    76,    -1,    75,   172,
      79,    76,    -1,    75,    79,    76,    -1,    75,   172,    76,
      -1,    75,     1,    76,    -1,    75,   172,     1,    80,    -1,
     170,    -1,   172,    79,   170,    -1,    -1,   175,   174,   183,
      -1,   157,    70,   176,    -1,    70,   176,    -1,   157,   131,
     176,    -1,   131,   176,    -1,    -1,   127,    73,   179,   177,
      74,    -1,    -1,   127,    73,   178,    74,    -1,   127,     1,
     179,    74,    -1,   127,     1,    74,    -1,   127,    73,     1,
      80,    -1,   127,    73,   179,     1,    80,    -1,   182,    -1,
     180,    79,   182,    -1,   181,    -1,   180,    79,   181,    -1,
     180,    79,     1,    -1,    40,   131,   169,    -1,   131,   169,
      -1,    40,   131,    81,    81,    81,   169,    -1,   131,    81,
      81,    81,   169,    -1,   181,    -1,   203,    -1,    80,    -1,
     157,   185,   186,    -1,   185,   186,    -1,   185,     1,    -1,
     139,    73,   179,    74,    -1,   139,    73,    74,    -1,   139,
      73,     1,    80,    -1,    75,   187,   204,    76,    -1,   203,
      -1,    75,   187,    76,    -1,    65,    73,   236,    74,    80,
      -1,    65,    73,    74,    80,    -1,    62,    73,   236,    74,
      80,    -1,    62,    73,    74,    80,    -1,    65,    73,   236,
       1,    80,    -1,    65,    73,     1,    80,    -1,    62,    73,
     236,     1,    80,    -1,    62,    73,     1,    80,    -1,   157,
      38,   127,   159,   189,    -1,    38,   127,   159,   189,    -1,
     157,    38,   127,   189,    -1,    38,   127,   189,    -1,    38,
       1,   189,    -1,   157,    38,     1,   189,    -1,    75,   190,
      79,   192,    76,    -1,    75,   190,   192,    76,    -1,    75,
      79,   192,    76,    -1,    75,   190,    79,    76,    -1,    75,
     192,    76,    -1,    75,   190,    76,    -1,    75,    79,    76,
      -1,    75,    76,    -1,    75,   190,    79,   192,     1,    80,
      -1,    75,   190,   192,     1,    80,    -1,    75,    79,   192,
       1,    80,    -1,    75,   190,    79,     1,    80,    -1,    75,
     192,     1,    80,    -1,    75,   190,     1,    80,    -1,    75,
      79,     1,    80,    -1,    75,     1,    80,    -1,   191,    -1,
     190,    79,   191,    -1,   127,   193,   161,    -1,   127,   161,
      -1,   127,   193,    -1,   127,    -1,    80,   162,    -1,    80,
      -1,    73,   236,    74,    -1,    73,    74,    -1,    73,     1,
      74,    -1,    -1,   157,    50,   127,    39,   160,   195,   199,
      -1,    -1,    50,   127,    39,   160,   196,   199,    -1,    -1,
     157,    50,   127,   197,   199,    -1,    -1,    50,   127,   198,
     199,    -1,   157,    50,     1,   199,    -1,    50,     1,   199,
      -1,    75,   200,    76,    -1,    75,    76,    -1,   201,    -1,
     200,   201,    -1,   165,    -1,   202,    -1,    80,    -1,   157,
     131,   176,    -1,   131,   176,    -1,   157,    70,   176,    -1,
      70,   176,    -1,    75,    76,    -1,    75,   204,    76,    -1,
      75,     1,    76,    -1,   205,    -1,   204,   205,    -1,   165,
      -1,   147,    -1,   206,    -1,    -1,   207,   203,    -1,    80,
      -1,   218,    80,    -1,    -1,   127,    82,   208,   206,    -1,
      -1,    44,    73,   263,    74,   209,   206,   216,    -1,    44,
       1,    80,    -1,    -1,    63,    73,   263,    74,   210,    75,
     219,    76,    -1,    63,     1,    80,    -1,    -1,    -1,    72,
      73,   211,   263,    74,   212,   206,    -1,    72,     1,    80,
      -1,    -1,    35,   213,   206,    72,    73,   263,    74,    80,
      -1,    35,     1,    80,    -1,    -1,    -1,    43,   214,    73,
     224,    74,   215,   206,    -1,    43,     1,    80,    -1,    26,
     127,    80,    -1,    26,   127,     1,    80,    -1,    26,    80,
      -1,    26,     1,    80,    -1,    33,   127,    80,    -1,    33,
     127,     1,    80,    -1,    33,    80,    -1,    33,     1,    80,
      -1,    58,   263,    80,    -1,    58,    80,    -1,    58,     1,
      76,    -1,    -1,    -1,    37,   217,   206,    -1,   264,    -1,
     247,    -1,   245,    -1,   242,    -1,   235,    -1,   220,    -1,
     219,   220,    -1,    -1,   222,   221,   204,    -1,   223,    -1,
     222,   223,    -1,    28,   263,    82,    -1,    34,    82,    -1,
      28,   263,     1,    80,    -1,   230,    80,   229,    80,    -1,
     230,    80,   227,    80,    -1,   230,     1,    80,    -1,    -1,
     230,    80,   227,    80,   225,   231,    -1,    -1,   230,    80,
     229,    80,   226,   231,    -1,    -1,   228,   263,    -1,    -1,
     232,    -1,    -1,   232,    -1,   218,    -1,   232,    79,   218,
      -1,   234,    -1,   237,    -1,   128,    -1,    65,    -1,    73,
     263,    74,    -1,   235,    -1,   241,    -1,   242,    -1,   243,
      -1,    53,   138,    73,   236,    74,    -1,    53,   138,    73,
      74,    -1,    53,   138,    73,     1,    80,    -1,    53,   138,
      73,   236,     1,    -1,   263,    -1,   236,    79,   263,    -1,
      53,   132,   238,   240,    -1,    53,   132,   238,    -1,    53,
     137,   238,   240,    -1,    53,   137,   238,    -1,   239,    -1,
     238,   239,    -1,    77,   263,    78,    -1,    77,    78,    -1,
     240,    77,    78,    -1,   127,    81,   127,    -1,   233,    81,
     127,    -1,    62,    81,   127,    -1,     4,    73,   263,    74,
      -1,     4,    73,   263,     1,    80,    -1,     4,     1,    80,
      -1,     5,    73,   263,    74,    -1,     5,    73,   263,     1,
      80,    -1,     5,     1,    80,    -1,     5,    73,    74,    -1,
       5,    73,     1,    80,    -1,     4,    73,    74,    -1,     4,
      73,     1,    80,    -1,   127,    73,   236,    74,    -1,   127,
      73,    74,    -1,   127,    81,   127,    73,   236,    74,    -1,
     127,    81,   127,    73,    74,    -1,   233,    81,   127,    73,
     236,    74,    -1,   233,    81,   127,    73,   236,     1,    80,
      -1,   233,    81,   127,    73,    74,    -1,   233,    81,   127,
      73,     1,    80,    -1,    62,    81,   127,    73,   236,    74,
      -1,    62,    81,   127,    73,   236,     1,    80,    -1,    62,
      81,   127,    73,    74,    -1,    62,    81,   127,    73,     1,
      80,    -1,   138,    77,   263,    78,    -1,   234,    77,   263,
      78,    -1,   234,    77,   263,     1,    80,    -1,   138,    77,
     263,     1,    80,    -1,   233,    -1,   127,    -1,   245,    -1,
     244,   266,    -1,   244,    -1,   267,   246,    -1,   268,   246,
      -1,   247,    -1,   267,     1,    80,    -1,   266,   246,    -1,
     248,   269,   246,    -1,   246,    -1,   248,   269,     1,    80,
      -1,   249,   270,   248,    -1,   248,    -1,   249,   270,     1,
      80,    -1,   250,   271,   249,    -1,   249,    -1,   250,   271,
       1,    80,    -1,   251,   272,   250,    -1,   250,    -1,   251,
     272,     1,    80,    -1,   252,   273,   251,    -1,   251,    -1,
     252,   273,     1,    80,    -1,   253,   112,   252,    -1,   252,
      -1,   253,   112,     1,    80,    -1,   254,   117,   253,    -1,
     253,    -1,   254,   117,     1,    80,    -1,   255,   114,   254,
      -1,   254,    -1,   255,   114,     1,    80,    -1,    -1,   256,
     115,   257,   255,    -1,   255,    -1,   256,   115,     1,    80,
      -1,    -1,   258,   116,   259,   256,    -1,   256,    -1,   258,
     116,     1,    80,    -1,   258,    -1,    -1,    -1,   258,    83,
     261,   263,   262,    82,   260,    -1,   258,    83,     1,    80,
      -1,   260,    -1,   264,    -1,   265,   274,   263,    -1,   265,
     274,     1,    80,    -1,   127,    -1,   241,    -1,   243,    -1,
      84,    -1,    85,    -1,    99,    -1,   100,    -1,    88,    -1,
      86,    -1,    73,    49,    74,    -1,    73,    27,    74,    -1,
      73,    59,    74,    -1,    73,    51,    74,    -1,    73,    30,
      74,    -1,    73,    36,    74,    -1,    73,    42,    74,    -1,
      97,    -1,    96,    -1,    98,    -1,    99,    -1,   100,    -1,
     104,    -1,   105,    -1,   106,    -1,   108,    -1,   107,    -1,
     109,    -1,   110,    -1,    48,    -1,    89,    -1,    87,    -1,
      90,    -1,    92,    -1,    94,    -1,    91,    -1,    93,    -1,
      95,    -1,   111,    -1,   118,    -1,   113,    -1,   101,    -1,
     102,    -1,   103,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   371,   371,   371,   379,   383,   385,   387,   398,   400,
     402,   404,   408,   425,   427,   429,   431,   448,   450,   452,
     457,   459,   476,   478,   497,   505,   515,   517,   520,   522,
     525,   527,   529,   531,   533,   536,   538,   541,   543,   547,
     550,   553,   556,   558,   560,   576,   578,   580,   584,   586,
     588,   590,   591,   595,   597,   601,   603,   607,   609,   611,
     613,   615,   617,   621,   623,   627,   629,   633,   635,   639,
     638,   693,   692,   741,   740,   783,   782,   823,   822,   859,
     858,   896,   895,   925,   924,   950,   952,   956,   969,   983,
     992,   994,   996,   998,  1000,  1002,  1004,  1006,  1008,  1010,
    1014,  1018,  1022,  1024,  1026,  1030,  1032,  1036,  1038,  1040,
    1042,  1046,  1048,  1054,  1059,  1058,  1066,  1070,  1074,  1076,
    1080,  1117,  1373,  1377,  1394,  1396,  1411,  1431,  1452,  1454,
    1469,  1471,  1486,  1488,  1491,  1493,  1573,  1572,  1659,  1696,
    1731,  1778,  1824,  1824,  1826,  1826,  1828,  1830,  1832,  1834,
    1837,  1839,  1843,  1845,  1847,  1851,  1871,  1893,  1913,  1933,
    1936,  1938,  1941,  2000,  2058,  2061,  2124,  2167,  2170,  2172,
    2174,  2177,  2248,  2278,  2356,  2391,  2393,  2395,  2397,  2401,
    2403,  2405,  2407,  2409,  2411,  2414,  2416,  2418,  2420,  2422,
    2424,  2426,  2428,  2430,  2432,  2434,  2436,  2438,  2440,  2442,
    2444,  2447,  2449,  2452,  2454,  2456,  2458,  2461,  2463,  2466,
    2468,  2470,  2474,  2473,  2517,  2516,  2556,  2555,  2583,  2582,
    2605,  2607,  2610,  2612,  2615,  2617,  2620,  2622,  2628,  2631,
    2646,  2661,  2673,  2686,  2688,  2690,  2694,  2696,  2700,  2702,
    2704,  2707,  2707,  2709,  2711,  2714,  2713,  2719,  2718,  2735,
    2738,  2737,  2772,  2774,  2775,  2774,  2808,  2811,  2810,  2846,
    2849,  2860,  2848,  2884,  2886,  2888,  2890,  2898,  2900,  2908,
    2910,  2918,  2920,  3026,  3039,  3042,  3045,  3044,  3057,  3059,
    3061,  3063,  3065,  3069,  3071,  3085,  3084,  3125,  3127,  3140,
    3201,  3208,  3211,  3221,  3231,  3233,  3233,  3242,  3242,  3252,
    3252,  3286,  3304,  3305,  3309,  3313,  3315,  3318,  3320,  3323,
    3325,  3338,  3340,  3342,  3344,  3346,  3349,  3456,  3578,  3580,
    3583,  3598,  3613,  3620,  3653,  3660,  3689,  3691,  3694,  3697,
    3699,  3702,  3863,  3996,  4027,  4115,  4117,  4119,  4202,  4204,
    4206,  4208,  4210,  4219,  4221,  4336,  4412,  4581,  4712,  4842,
    4844,  4939,  4941,  5045,  5047,  5111,  5114,  5190,  5245,  5247,
    5250,  5252,  5505,  5508,  5707,  5709,  5856,  5863,  5865,  5868,
    5935,  6280,  6282,  6285,  6630,  6632,  6635,  6829,  6831,  6834,
    7273,  7275,  7278,  7641,  7643,  7646,  7839,  7841,  7844,  8038,
    8040,  8043,  8235,  8237,  8241,  8240,  8296,  8298,  8302,  8301,
    8358,  8360,  8363,  8366,  8379,  8365,  8480,  8483,  8485,  8488,
    8914,  8917,  9044,  9046,  9049,  9051,  9055,  9057,  9059,  9061,
    9064,  9066,  9068,  9070,  9072,  9074,  9076,  9079,  9081,  9083,
    9086,  9088,  9091,  9093,  9095,  9098,  9100,  9102,  9104,  9106,
    9109,  9111,  9114,  9116,  9118,  9120,  9122,  9124,  9126,  9128,
    9130,  9132,  9134,  9136
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "PRINTL", "PRINT", "STRING",
  "CHARACTERS", "BOOL", "NULLER", "IDENTIFIER", "HEX_INT", "BIN_INT",
  "OCT_INT", "INTEGER", "HEX_INT_LONG", "BIN_INT_LONG", "OCT_INT_LONG",
  "INTEGER_LONG", "FLOATING", "HEX_FLOAT", "FLOATING_FL", "HEX_FLOAT_FL",
  "ABSTRACT", "ASSERT", "BOOLEAN", "BREAK", "BYTE", "CASE", "CATCH",
  "CHAR", "CLASS", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE",
  "ENUM", "EXTENDS", "FINAL", "FINALLY", "FLOAT", "FOR", "IF", "GOTO",
  "IMPLEMENTS", "IMPORT", "INSTANCEOF", "INT", "INTERFACE", "LONG",
  "NATIVE", "NEW", "PACKAGE", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN",
  "SHORT", "STATIC", "STRICTFP", "SUPER", "SWITCH", "SYNCHRONIZED", "THIS",
  "THROW", "THROWS", "TRANSIENT", "TRY", "VOID", "VOLATILE", "WHILE",
  "LRBRACE", "RRBRACE", "LCBRACE", "RCBRACE", "LSBRACE", "RSBRACE",
  "COMMA", "SEMICOLON", "DOT", "COLON", "TERNARY", "INCREMENT",
  "DECREMENT", "UNOT", "NEQ", "NOT", "COMPARE", "EQUAL", "MULTEQUAL",
  "PLUSEQUAL", "DIVEQUAL", "MINUSEQUAL", "MODEQUAL", "DIV", "MULT", "MOD",
  "PLUS", "MINUS", "LEFTSHIFTEQUAL", "RIGHTSHIFTEQUAL", "URIGHTSHIFTEQUAL",
  "LEFTSHIFT", "RIGHTSHIFT", "URIGHTSHIFT", "LEQ", "LT", "GT", "GEQ",
  "ANDEQUAL", "BAND", "OREQUAL", "BOR", "AND", "OR", "XOR", "XOREQUAL",
  "CAST", "UMINUS", "UPLUS", "PREDECREMENT", "PREINCREMENT", "$accept",
  "Goal", "$@1", "Identifier", "Literal", "IntegerLiteral",
  "FloatingPointLiteral", "Type", "Primitive", "Numeric", "Integral",
  "FloatingPointType", "Reference", "ClassOrInterfaceType", "TypeName",
  "SimpleName", "ArrayType", "CompilationUnit", "PackageDeclaration",
  "ImportDeclarations", "ImportDeclaration", "TypeDeclarations",
  "TypeDeclaration", "ClassDeclaration", "NormalClassDeclaration", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "Modifiers", "Modifier",
  "Interfaces", "InterfaceTypeList", "ClassBody", "ClassBodyDeclarations",
  "ClassBodyDeclaration", "ClassMemberDeclaration", "FieldDeclaration",
  "$@10", "VariableDeclarators", "VariableDeclarator",
  "VariableDeclaratorID", "VariableInitialiser", "ArrayInitialiser",
  "VariableInitialisers", "MethodDeclaration", "$@11", "MethodHeader",
  "MethodDeclarator", "$@12", "$@13", "FormalParameterList",
  "FormalParameters", "FormalParameter", "LastFormalParameter",
  "MethodBody", "ConstructorDeclaration", "ConstructorDeclarator",
  "ConstructorBody", "ExplicitConstructorInvocation", "EnumDeclaration",
  "EnumBody", "EnumConstants", "EnumConstant", "EnumBodyDeclarations",
  "Arguments", "InterfaceDeclaration", "$@14", "$@15", "$@16", "$@17",
  "InterfaceBody", "InterfaceMemberDeclarations",
  "InterfaceMemberDeclaration", "AbstractMethodDeclaration", "Block",
  "BlockStatements", "BlockStatement", "Statement", "$@18", "$@19", "$@20",
  "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "Other", "$@27",
  "StatementExpression", "SwitchBlockStatementGroups",
  "SwitchBlockStatementGroup", "$@28", "SwitchLabels", "SwitchLabel",
  "ForControl", "$@29", "$@30", "Check", "$@31", "NoCheck", "ForInit",
  "ForUpdate", "StatementExpressionList", "Primary", "PrimaryNoNewArray",
  "ClassInstanceCreationExpression", "ArgumentList",
  "ArrayCreationExpression", "DimExprs", "DimExpr", "Dims", "FieldAccess",
  "MethodInvocation", "ArrayAccess", "OpExpression", "PostFixOp",
  "UnaryExpression", "PreFixOp", "MultExpression", "AddExpression",
  "ShiftExpression", "RelExpression", "CompExpression", "BitAndExpression",
  "XORExpression", "BORExpression", "ANDExpression", "$@32",
  "ORExpression", "$@33", "TernaryExpression", "$@34", "$@35",
  "Expression", "Assignment", "LeftHandSide", "UnaryRtoL", "UnaryLtoR",
  "Cast", "MultOperator", "AddOperator", "ShiftOperator", "RelOperator",
  "CompOperator", "AssignmentOperator", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   124,   126,   125,   127,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   130,   130,   130,   131,   131,   132,   132,   133,   133,
     134,   134,   134,   134,   134,   135,   135,   136,   136,   137,
     138,   139,   140,   140,   140,   140,   140,   140,   141,   141,
     141,   141,   141,   142,   142,   143,   143,   144,   144,   144,
     144,   144,   144,   145,   145,   146,   146,   147,   147,   149,
     148,   150,   148,   151,   148,   152,   148,   153,   148,   154,
     148,   155,   148,   156,   148,   148,   148,   157,   157,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     159,   160,   161,   161,   161,   162,   162,   163,   163,   163,
     163,   164,   164,   164,   166,   165,   165,   165,   167,   167,
     168,   168,   168,   169,   169,   169,   170,   170,   171,   171,
     171,   171,   171,   171,   172,   172,   174,   173,   175,   175,
     175,   175,   177,   176,   178,   176,   176,   176,   176,   176,
     179,   179,   180,   180,   180,   181,   181,   182,   182,   182,
     183,   183,   184,   184,   184,   185,   185,   185,   186,   186,
     186,   187,   187,   187,   187,   187,   187,   187,   187,   188,
     188,   188,   188,   188,   188,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   190,   190,   191,   191,   191,   191,   192,   192,   193,
     193,   193,   195,   194,   196,   194,   197,   194,   198,   194,
     194,   194,   199,   199,   200,   200,   201,   201,   201,   202,
     202,   202,   202,   203,   203,   203,   204,   204,   205,   205,
     205,   207,   206,   206,   206,   208,   206,   209,   206,   206,
     210,   206,   206,   211,   212,   206,   206,   213,   206,   206,
     214,   215,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   216,   217,   216,   218,   218,
     218,   218,   218,   219,   219,   221,   220,   222,   222,   223,
     223,   223,   224,   224,   224,   225,   224,   226,   224,   228,
     227,   229,   230,   230,   231,   232,   232,   233,   233,   234,
     234,   234,   234,   234,   234,   234,   235,   235,   235,   235,
     236,   236,   237,   237,   237,   237,   238,   238,   239,   240,
     240,   241,   241,   241,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   243,   243,   243,   243,
     244,   244,   244,   245,   246,   246,   246,   246,   246,   247,
     248,   248,   248,   249,   249,   249,   250,   250,   250,   251,
     251,   251,   252,   252,   252,   253,   253,   253,   254,   254,
     254,   255,   255,   255,   257,   256,   256,   256,   259,   258,
     258,   258,   260,   261,   262,   260,   260,   263,   263,   264,
     264,   265,   265,   265,   266,   266,   267,   267,   267,   267,
     268,   268,   268,   268,   268,   268,   268,   269,   269,   269,
     270,   270,   271,   271,   271,   272,   272,   272,   272,   272,
     273,   273,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     4,     4,     4,     3,     2,
       2,     1,     0,     3,     3,     1,     2,     3,     5,     6,
       6,     3,     4,     1,     2,     1,     1,     1,     1,     0,
       8,     0,     7,     0,     6,     0,     7,     0,     5,     0,
       6,     0,     5,     0,     4,     4,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     3,     1,     2,     1,     1,     2,
       1,     1,     1,     1,     0,     5,     3,     3,     1,     3,
       1,     3,     4,     3,     4,     1,     1,     1,     2,     4,
       3,     3,     3,     4,     1,     3,     0,     3,     3,     2,
       3,     2,     0,     5,     0,     4,     4,     3,     4,     5,
       1,     3,     1,     3,     3,     3,     2,     6,     5,     1,
       1,     1,     3,     2,     2,     4,     3,     4,     4,     1,
       3,     5,     4,     5,     4,     5,     4,     5,     4,     5,
       4,     4,     3,     3,     4,     5,     4,     4,     4,     3,
       3,     3,     2,     6,     5,     5,     5,     4,     4,     4,
       3,     1,     3,     3,     2,     2,     1,     2,     1,     3,
       2,     3,     0,     7,     0,     6,     0,     5,     0,     4,
       4,     3,     3,     2,     1,     2,     1,     1,     1,     3,
       2,     3,     2,     2,     3,     3,     1,     2,     1,     1,
       1,     0,     2,     1,     2,     0,     4,     0,     7,     3,
       0,     8,     3,     0,     0,     7,     3,     0,     8,     3,
       0,     0,     7,     3,     3,     4,     2,     3,     3,     4,
       2,     3,     3,     2,     3,     0,     0,     3,     1,     1,
       1,     1,     1,     1,     2,     0,     3,     1,     2,     3,
       2,     4,     4,     4,     3,     0,     6,     0,     6,     0,
       2,     0,     1,     0,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     5,     4,     5,     5,
       1,     3,     4,     3,     4,     3,     1,     2,     3,     2,
       3,     3,     3,     3,     4,     5,     3,     4,     5,     3,
       3,     4,     3,     4,     4,     3,     6,     5,     6,     7,
       5,     6,     6,     7,     5,     6,     4,     4,     5,     5,
       1,     1,     1,     2,     1,     2,     2,     1,     3,     2,
       3,     1,     4,     3,     1,     4,     3,     1,     4,     3,
       1,     4,     3,     1,     4,     3,     1,     4,     3,     1,
       4,     3,     1,     4,     0,     4,     1,     4,     0,     4,
       1,     4,     1,     0,     0,     7,     4,     1,     1,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,    52,     1,    92,     0,     0,    94,     0,     0,
      95,     0,    90,    91,    89,    93,    99,    96,    97,    98,
       3,     0,     0,    55,    51,    63,    65,    67,     0,    88,
      68,    66,     0,     4,    83,     0,     0,     0,     0,    41,
       0,    40,     0,   218,     0,     0,     0,    49,    56,    50,
      64,     0,     0,     0,    87,     0,    86,     0,     0,     0,
      77,     0,   183,     0,   182,    61,     0,     0,    57,     0,
       0,   221,     0,     0,    54,    53,    48,     0,    81,     0,
       0,     0,   216,     0,    27,    30,    34,    36,    35,    32,
      33,    31,    93,     0,     0,   102,   113,     0,    24,    26,
      28,    29,    25,    37,    39,    40,    38,     0,     0,   105,
     107,   111,   112,   136,   110,     0,   108,    79,    39,   101,
     100,    84,     0,     0,   192,     0,   208,   206,     0,   201,
       0,   180,    62,     0,     0,     0,   223,   228,     0,     0,
     226,     0,   224,   227,   214,   219,    85,     0,     0,    73,
     184,     0,   181,   220,     0,     0,   104,   109,     0,   139,
       0,    11,     0,     0,     9,     8,     7,    10,    13,    14,
      15,    12,    17,    18,    19,    16,    21,    20,    23,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   310,
       0,     0,   233,   243,   414,   415,   411,   309,     5,     6,
       0,    39,   239,     0,   238,   241,   236,   240,     0,     0,
     360,   307,   282,   308,   313,   281,   315,     0,   280,   279,
     278,     0,     0,     0,     0,     0,   118,   120,   141,     0,
       0,     0,     0,     0,     0,     0,   103,   106,     0,   164,
       0,   163,   169,     0,    71,    78,   200,     0,   191,     0,
     207,     0,   204,   205,     0,   190,     0,     0,     0,   189,
       0,     0,    58,   232,   230,     0,     0,   222,   225,     0,
      75,    82,     0,   179,   212,   217,     0,     0,   235,     0,
       0,     0,     0,     0,   266,     0,     0,   270,     0,     0,
     241,     0,     0,     0,     0,     0,     0,    39,     0,     0,
     273,   419,   418,   416,   417,   361,     0,   312,   314,   364,
     362,   371,   367,   374,   377,   380,   383,   386,   389,   392,
     396,   400,   402,   407,     0,   408,     0,     0,     0,     0,
       0,     0,   253,     0,     0,     0,   245,   125,     0,     0,
     234,   237,   242,   244,     0,     0,   363,   442,   445,   443,
     446,   444,   447,   451,   452,   453,   448,   450,   449,     0,
     361,   313,   315,   369,   117,     0,   116,     0,     0,     0,
      42,     0,    43,     0,     0,   166,     0,     0,     0,   159,
     150,     0,    44,   138,   114,   140,   162,   161,   137,   160,
       0,   310,   241,    80,     0,   199,     0,   187,     0,   210,
       0,   320,   203,   198,     0,   188,   202,     0,     0,   186,
     197,    60,    59,   231,   229,   215,     0,    69,    74,     0,
     147,     0,     0,     0,     0,   336,     0,   342,     0,   339,
       0,   340,     0,   267,     0,   264,   271,     0,   268,   259,
       0,   263,   303,   249,     0,     0,   323,   326,   325,     0,
     274,     0,     0,     0,     0,     0,     0,     0,     0,   428,
     427,   429,     0,   430,   431,     0,   432,   433,   434,     0,
     439,   436,   435,   437,   438,     0,   441,   440,     0,     0,
       0,     0,     0,     0,     0,   272,     0,   365,   366,   333,
     252,     0,   256,     0,   311,   345,     0,   331,   241,     0,
     332,     0,     0,   409,   119,     0,   123,     0,     0,   121,
     127,   126,    45,    46,   167,     0,     0,   156,   165,     0,
      47,     0,     0,     0,   170,   241,    72,   195,   211,   209,
       0,   196,     0,   185,   194,    76,     0,   213,   146,   148,
     145,     0,     0,   343,     0,   334,   341,     0,   337,   265,
     269,     0,   305,     0,     0,   302,   247,     0,     0,   327,
     322,   324,     0,   317,     0,   421,   424,   425,   426,   420,
     423,   422,     0,   370,     0,   373,     0,   376,     0,   379,
       0,   382,     0,   385,     0,   388,     0,   391,     0,     0,
       0,     0,     0,     0,   368,     0,   250,     0,   344,     0,
     246,     0,   356,     0,     0,   357,   410,   124,   122,     0,
     128,     0,   134,     0,     0,   155,     0,   154,   159,   151,
     115,     0,     0,     0,     0,     0,     0,   168,   321,   193,
      70,   149,   143,   335,   338,     0,   261,     0,   299,     0,
     241,   328,   329,     0,   318,   319,   316,   372,   375,   378,
     381,   384,   387,   390,   393,   397,   395,   406,   404,   401,
     399,     0,   354,     0,     0,   254,   347,     0,   359,     0,
     350,     0,   358,   132,   130,     0,   131,     0,     0,     0,
     178,   174,     0,     0,   176,   172,     0,     0,     0,   241,
     294,     0,     0,     0,   306,   275,   330,     0,   355,     0,
     352,     0,   241,   346,   351,     0,   348,   133,   129,   135,
       0,   158,   177,   173,   175,   171,     0,   262,   295,   300,
     297,   276,   248,     0,   353,     0,     0,     0,   283,   285,
     287,   255,   349,   157,   258,     0,     0,   241,   405,     0,
     290,   251,   284,   241,   288,   296,   304,   298,   277,     0,
     289,   286,   291
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   305,   197,   198,   199,   200,    98,    99,
     100,   101,   102,   103,   306,    41,   106,    20,    21,    22,
      23,    24,    25,    26,    27,   536,   394,   272,   416,   122,
     243,   148,    59,    28,    29,    60,   120,    56,   108,   109,
     110,   204,   521,   225,   226,   227,   509,   510,   613,   112,
     238,   113,   159,   542,   423,   377,   378,   379,   380,   388,
     114,   115,   241,   392,    30,    62,   128,   129,   130,   253,
      31,   419,   269,   155,    73,    71,   141,   142,   143,   116,
     205,   206,   207,   208,   498,   640,   664,   493,   702,   290,
     292,   689,   722,   737,   209,   727,   728,   743,   729,   730,
     553,   735,   736,   691,   692,   693,   554,   745,   746,   210,
     211,   307,   400,   213,   446,   447,   560,   214,   308,   216,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   589,   322,   593,   323,   591,   697,   401,
     325,   221,   222,   326,   327,   462,   465,   469,   475,   478,
     359
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -500
static const yytype_int16 yypact[] =
{
    -500,    34,  4070,  -500,  -500,   226,   389,  -500,    22,   394,
    -500,   396,  -500,  -500,  -500,  -500,  -500,  -500,  -500,  -500,
    -500,  4105,  4105,  -500,  4140,  -500,  -500,  -500,  4175,  -500,
    -500,  -500,   -11,  -500,   408,     6,    45,   104,   400,  -500,
     399,  -500,    39,   167,   142,   145,  4105,  4140,  -500,  -500,
    -500,   406,   416,   434,  -500,  3719,  -500,   256,   256,   -11,
    -500,   163,  -500,     6,  -500,  -500,   189,   202,  -500,   218,
    3831,  -500,   256,    39,  -500,  -500,  4140,   -11,   426,     6,
      45,    39,   280,   261,  -500,  -500,  -500,  -500,  -500,  -500,
    -500,  -500,   284,   256,  2927,  -500,  -500,   445,   299,  -500,
    -500,  -500,  -500,  -500,   326,   306,   336,  3991,  3775,  -500,
    -500,  -500,  -500,  -500,  -500,    43,  -500,   381,  -500,  -500,
    -500,  -500,   -11,   379,  -500,    20,  3883,   327,   168,  -500,
      30,  -500,  -500,    15,   391,   256,  -500,  -500,   445,  4043,
    -500,  3939,  -500,  -500,  -500,  -500,  -500,   256,   -11,  -500,
    -500,     6,  -500,  -500,   256,    39,  -500,  -500,   139,  -500,
     430,  -500,   231,   233,  -500,  -500,  -500,  -500,  -500,  -500,
    -500,  -500,  -500,  -500,  -500,  -500,  -500,  -500,  -500,  -500,
      25,    70,  3097,   240,   263,   747,   962,   409,   273,  -500,
     285,  2827,  -500,  -500,  -500,  -500,   404,  -500,  -500,  -500,
     445,   436,  -500,  2846,  -500,  3180,  -500,  -500,   284,   435,
     437,   451,   414,  -500,   444,   419,   763,   417,   424,  -500,
    -500,   898,  2827,   449,   304,   432,  -500,   243,  -500,    41,
      78,   748,    83,   256,   256,   455,  -500,  -500,   193,  -500,
    3012,  -500,  -500,   -11,  -500,  -500,  -500,   452,  -500,    48,
    3883,  1062,  -500,   -11,   453,  -500,   187,   176,   460,  -500,
     461,   463,  -500,  -500,  -500,   256,   256,  -500,  -500,    39,
     381,  -500,   -11,  -500,  -500,  -500,   977,   883,  -500,   469,
    1090,   476,  1190,   478,  -500,    58,   481,  -500,    73,   483,
    3595,   484,   458,   485,  2827,   490,   490,   495,   493,  2477,
    -500,  -500,  -500,  -500,  -500,  4160,   496,  -500,  -500,   417,
    -500,  -500,  -500,   333,   422,   378,   330,   362,   462,   459,
     456,   464,   -23,  -500,   497,  -500,  1699,  2827,   256,   498,
    2827,   500,  -500,   507,  2603,   256,  -500,  -500,  1215,   256,
    -500,  -500,  -500,  -500,   256,  2827,  -500,  -500,  -500,  -500,
    -500,  -500,  -500,  -500,  -500,  -500,  -500,  -500,  -500,  1724,
     342,  -500,  -500,  -500,  -500,   256,  -500,    89,  1315,   505,
    -500,   509,  -500,   510,   747,  -500,   210,   513,   512,   514,
    -500,   515,  -500,  -500,   517,  -500,  -500,  -500,  -500,  -500,
     352,   519,  3263,  -500,   -11,  -500,   518,  -500,   520,  -500,
     301,  -500,  -500,  -500,   521,  -500,  -500,   206,   523,  -500,
    -500,  -500,  -500,  -500,  -500,  -500,   -11,  -500,  -500,    39,
    -500,   530,   525,   532,   215,  -500,   527,  -500,   237,  -500,
     528,  -500,   255,  -500,   531,  -500,  -500,   534,  -500,  -500,
     540,  -500,  3678,  -500,   541,  2827,   539,  -500,   539,  1343,
    -500,   544,   545,   546,   549,   550,   551,   552,  2827,  -500,
    -500,  -500,  1824,  -500,  -500,  1849,  -500,  -500,  -500,  1949,
    -500,  -500,  -500,  -500,  -500,  1974,  -500,  -500,  2074,  2099,
    2199,  2224,  2324,  2349,  2449,  -500,   547,  -500,  -500,   524,
    -500,   554,  -500,  2827,  -500,  -500,   374,   556,  3595,   130,
     557,   171,   553,  -500,  -500,   558,  -500,   559,   830,  -500,
    -500,  -500,  -500,  -500,  -500,   227,   555,   560,  -500,   901,
    -500,   561,  1443,  1471,  -500,  3346,  -500,  -500,  -500,  -500,
    2827,  -500,   562,  -500,  -500,  -500,   -11,  -500,  -500,  -500,
    -500,   563,   570,  -500,   569,  -500,  -500,   571,  -500,  -500,
    -500,   577,  -500,   578,    75,   574,  -500,   582,  2701,  -500,
     587,   587,   585,  -500,    53,  -500,  -500,  -500,  -500,  -500,
    -500,  -500,   586,  -500,   588,   333,   590,   422,   592,   378,
     593,   330,   595,   362,   596,   462,   597,   459,   601,  2827,
     602,  2827,   603,  2827,  -500,  1571,  -500,   611,  -500,  2729,
    -500,   607,  -500,  1599,   608,  -500,  -500,  -500,  -500,   591,
    -500,   615,  -500,   178,   612,   560,   614,  -500,   613,  -500,
    -500,   616,   618,   191,   619,   620,   201,  -500,  -500,  -500,
    -500,  -500,  -500,  -500,  -500,  2827,  -500,   621,   622,  3678,
    3595,  -500,  -500,   625,  -500,  -500,  -500,  -500,  -500,  -500,
    -500,  -500,  -500,  -500,  -500,  -500,   456,  -500,  -500,  -500,
     464,   624,  -500,   252,   631,  -500,  -500,   388,  -500,   627,
    -500,   317,  -500,  -500,  -500,   629,  -500,  2575,   630,   256,
    -500,  -500,   635,   636,  -500,  -500,   639,   642,   649,  3595,
    -500,   644,  2827,   645,  -500,   673,  -500,   646,  -500,   647,
    -500,   329,  3595,  -500,  -500,   651,  -500,  -500,  -500,  -500,
     256,   560,  -500,  -500,  -500,  -500,   653,  -500,   652,  -500,
     655,  -500,  -500,  2827,  -500,  2827,   654,   322,  -500,   329,
    -500,  -500,  -500,   560,  -500,  3678,  3678,  3595,  -500,    35,
    -500,  -500,  -500,  3512,  -500,  -500,   574,  -500,  -500,   657,
    -500,  3429,  -500
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -500,  -500,  -500,    -5,  -500,  -500,  -500,   247,   565,  -500,
    -500,  -500,  -500,   235,     0,   -39,  -500,  -500,  -500,   713,
     302,   241,   346,   -82,  -500,  -500,  -500,  -500,  -500,  -500,
    -500,  -500,  -500,   -31,   -10,    79,   -43,   -49,   508,   -88,
    -500,    -4,  -500,  -204,   370,  -363,  -499,  -500,  -500,  -500,
    -500,  -500,   -52,  -500,  -500,   250,  -500,   221,   222,  -500,
    -500,   637,   526,  -500,  -500,   107,  -500,   486,   -85,  -500,
    -500,  -500,  -500,  -500,  -500,   -54,  -500,   604,  -500,   -17,
    -377,  -198,  -268,  -500,  -500,  -500,  -500,  -500,  -500,  -500,
    -500,  -500,  -500,  -500,  -440,  -500,    21,  -500,  -500,    18,
    -500,  -500,  -500,  -500,  -500,  -500,  -500,    17,   318,  -500,
    -500,   -89,  -171,  -500,   468,    59,   311,  -181,   -80,  -137,
     -57,    19,  -161,    50,   303,   298,   294,   293,   300,   312,
     310,   192,   207,  -500,  -500,  -500,    71,  -500,  -500,   272,
      74,  -500,  -200,  -500,  -500,  -500,  -500,  -500,  -500,  -500,
    -500
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -414
static const yytype_int16 yytable[] =
{
      34,    36,   552,    39,    43,   212,    39,   341,    40,   612,
     121,    45,   202,   517,   215,   525,   105,   346,    54,   145,
     237,   247,   440,    37,   107,    33,   283,   153,   146,   144,
     384,   258,    33,    39,     3,    33,   749,   217,    67,   139,
     249,   361,   369,   257,   239,   228,    78,    80,    82,   396,
      39,   111,    39,    39,   645,   104,   127,   118,   118,   434,
     483,   363,   384,   203,    55,    39,   140,    39,   105,   105,
     104,   286,   118,   245,   437,   157,   637,   107,   252,   371,
      33,    61,    38,   263,   381,   362,   264,   105,   158,   196,
     505,    58,   224,   484,   201,   107,   248,    54,   242,   271,
     126,   275,    39,    39,   111,   284,   259,   104,   104,   346,
     139,   274,   260,   218,    70,    63,   212,   750,   240,   370,
      61,    39,   111,   202,   397,   215,   104,   646,   261,    54,
     158,   601,   530,   224,    39,   384,    39,   140,   435,   104,
     276,   104,    39,    64,   219,   361,   361,   118,   217,    39,
     287,   212,   615,   438,   118,   638,   372,   149,   202,   151,
     215,   382,   237,   496,   123,   487,   488,   506,   220,   254,
     131,   407,   604,    33,   203,   285,   288,   408,   709,   675,
      39,   383,   385,   217,    65,   297,   150,   152,   404,   362,
     362,   342,   682,    54,   393,   337,   244,    33,    39,   694,
     196,   212,   686,   104,   402,   201,    72,   532,   602,   203,
     215,   105,   277,   413,   414,   415,   541,   360,   242,   107,
      33,   389,    74,   418,   218,    75,    39,    32,   158,   224,
     600,   104,   279,   217,   281,   196,    33,    33,   544,   124,
     201,   291,   125,   126,   255,    39,   111,   256,   126,   605,
     104,   127,   409,   699,   676,   219,   547,   677,   273,   218,
     158,   224,    47,   405,   293,   683,    33,   126,    94,   132,
     530,    39,    39,   387,   329,   687,   104,   104,   564,   220,
     530,   361,   533,   133,   361,   196,   331,    76,   361,  -142,
     219,   516,   117,   119,   361,   552,   552,   361,   361,   361,
     361,   573,    97,   212,   280,   276,   282,   119,   614,   218,
     202,   545,   215,  -260,   220,   134,   711,   138,   705,   154,
     367,   360,   360,   489,    48,   362,   700,   341,   362,   548,
     497,   530,   362,   368,   337,   217,   294,   156,   362,   500,
     219,   362,   362,   362,   362,   526,   330,   733,    48,   417,
     725,   623,   626,   212,   234,    97,   726,   725,   332,    94,
     337,   203,   215,   726,   220,   537,   751,   535,    49,    39,
      50,   337,   695,    97,   104,   529,   229,   277,   470,   231,
     530,  -125,   270,  -125,  -125,   217,   266,   196,   138,   119,
      35,   706,   201,    50,  -125,    42,   530,    44,   741,    33,
     251,    66,    55,   230,    33,   -41,    33,    77,   361,   212,
      33,   218,   361,   232,   -41,   334,    33,    79,   215,   -41,
     296,   717,    50,   335,   663,   522,    33,    58,   667,   459,
     460,   461,   671,   328,   731,    81,   212,   471,   472,   473,
     474,   217,   219,   202,    33,   215,   223,    57,   598,   476,
     339,   477,   362,   530,    58,    33,   362,   360,   324,   246,
     360,   218,   703,   333,   360,   147,   220,   530,   217,   748,
     360,   262,    58,   360,   360,   360,   360,   334,   376,    68,
      69,   -41,   466,   467,   468,   335,   336,   630,  -361,  -361,
     328,  -312,   219,   196,   203,  -312,  -314,    97,  -312,  -312,
    -314,   194,   195,  -314,  -314,   559,   278,   559,  -362,  -362,
     337,   365,   366,   338,    39,   343,   220,   218,   344,   104,
     196,   463,   464,   376,   376,   201,   421,   424,   345,   364,
     240,   442,   395,   403,  -412,  -412,  -412,  -412,  -412,  -412,
     410,   411,   361,   412,   218,  -412,  -412,  -412,   219,   425,
     212,   212,   428,   341,   432,  -412,   429,  -412,   433,   215,
     215,   436,  -412,   439,   441,   443,   444,   445,   449,   450,
     481,   333,   220,   458,   479,   219,   480,   485,   490,   482,
     492,   494,   217,   217,   360,   512,   362,   518,   360,   513,
     514,   519,   523,  -152,   528,   520,   365,   595,   527,   220,
     212,   531,   491,   534,   538,   539,   540,   543,   546,   215,
     499,   549,   551,   212,   550,   556,   558,   501,   565,   566,
     567,   515,   215,   568,   569,   570,   571,   594,   596,   599,
     603,   503,   217,   606,   250,   196,   616,   367,   607,   608,
     511,   620,   629,   631,   632,   217,   212,   212,   212,   633,
     635,   634,   636,   639,   212,   215,   215,   215,   218,   218,
     641,   202,   212,   215,   643,   644,   647,   673,   648,   202,
     649,   215,   650,   651,   337,   652,   653,   654,   217,   217,
     217,   655,   657,   659,   196,   665,   217,   668,   672,   219,
     219,   674,  -153,   678,   217,   679,   680,   196,   681,   684,
     685,   690,  -301,   696,   698,   337,   701,   704,   218,   707,
     721,   710,   203,   220,   220,   712,   713,   557,   360,   714,
     203,   218,   715,   716,   718,   720,  -293,   724,   723,  -292,
     499,   732,   196,   734,    46,   504,   740,   752,   196,   219,
     618,   619,   406,   201,   235,   268,   196,   744,   742,   373,
     295,   201,   219,   747,   218,   218,   218,    33,    33,   561,
     555,   386,   218,   220,   448,   597,   376,   577,   575,   579,
     218,   581,    84,    84,    85,    85,   220,    86,    86,   583,
     511,   656,     0,    87,    87,   219,   219,   219,   374,    88,
      88,   587,   585,   219,   738,     0,    89,    89,    90,    90,
     660,   219,   628,     0,     0,     0,    91,    91,     0,   220,
     220,   220,     0,     0,     0,     0,     0,   220,     0,     0,
       0,     0,   375,     0,     0,   220,     0,     0,     0,     0,
     557,   609,     0,   161,   162,   163,   164,   165,   166,   167,
      33,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,  -413,  -413,  -413,  -413,  -413,  -413,     0,
       0,     0,     0,   658,  -413,  -413,  -413,     0,     0,     0,
       0,     0,     0,     0,  -413,     0,  -413,     0,     0,     0,
       0,  -413,     0,   185,   422,     0,     0,     0,     0,     0,
       0,     0,   187,    33,     0,   189,     0,     0,     0,     0,
       0,     0,   617,   299,     0,   508,   610,   688,    84,   611,
      85,    33,     0,    86,   194,   195,   301,     0,   302,    87,
       0,     0,     0,   374,     0,    88,    84,     0,    85,   303,
     304,    86,    89,     0,    90,     0,     0,    87,     0,     0,
       0,   374,    91,    88,     0,     0,     0,     0,     0,   511,
      89,     0,    90,     0,     0,     0,     0,  -144,     0,     0,
      91,     0,     0,   298,   719,   161,   162,   163,   164,   165,
     166,   167,    33,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,     0,    33,   347,   348,
     349,   350,   351,   352,     0,     0,     0,   739,     0,   353,
     354,   355,    84,     0,    85,     0,     0,    86,     0,   356,
       0,   357,     0,    87,     0,   185,   358,   374,     0,    88,
       0,     0,     0,     0,   187,     0,    89,   189,    90,     0,
       0,     0,     0,     0,     0,   299,    91,     0,     0,     0,
       0,     0,   300,     0,     0,     0,   194,   195,   301,     0,
     302,   420,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   303,   304,   398,     0,   161,   162,   163,   164,   165,
     166,   167,    33,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,     0,     0,     0,     0,
       0,   426,     0,   161,   162,   163,   164,   165,   166,   167,
      33,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,   185,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,   189,     0,     0,
       0,     0,     0,     0,     0,   299,   399,     0,     0,     0,
       0,     0,     0,   185,     0,     0,   194,   195,   301,     0,
     302,     0,   187,     0,     0,   189,     0,     0,     0,     0,
       0,   303,   304,   299,   427,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   195,   301,     0,   302,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   303,
     304,   430,     0,   161,   162,   163,   164,   165,   166,   167,
      33,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,   371,     0,   161,   162,
     163,   164,   165,   166,   167,    33,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,     0,     0,   185,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,   189,     0,     0,     0,     0,
       0,     0,     0,   299,   431,     0,     0,     0,   185,     0,
       0,     0,     0,     0,   194,   195,   301,   187,   302,     0,
     189,     0,     0,     0,     0,     0,     0,     0,   299,   303,
     304,     0,     0,   372,     0,     0,     0,     0,     0,   194,
     195,   301,     0,   302,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   303,   304,   507,     0,   161,   162,
     163,   164,   165,   166,   167,    33,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,   562,     0,   161,   162,   163,   164,
     165,   166,   167,    33,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     0,     0,   185,     0,
       0,     0,     0,     0,     0,     0,     0,   187,     0,     0,
     189,     0,     0,     0,     0,     0,     0,     0,   299,     0,
     508,     0,     0,     0,     0,     0,   185,     0,     0,   194,
     195,   301,     0,   302,     0,   187,     0,     0,   189,     0,
       0,     0,     0,     0,   303,   304,   299,   563,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,   195,   301,
       0,   302,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   303,   304,   621,     0,   161,   162,   163,   164,
     165,   166,   167,    33,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     0,     0,     0,     0,
       0,     0,   624,     0,   161,   162,   163,   164,   165,   166,
     167,    33,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,     0,     0,   185,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,     0,   189,     0,
       0,     0,     0,     0,     0,     0,   299,   622,     0,     0,
       0,     0,     0,     0,   185,     0,     0,   194,   195,   301,
       0,   302,     0,   187,     0,     0,   189,     0,     0,     0,
       0,     0,   303,   304,   299,   625,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,   195,   301,     0,   302,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     303,   304,   661,     0,   161,   162,   163,   164,   165,   166,
     167,    33,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,     0,     0,     0,     0,     0,     0,
     669,     0,   161,   162,   163,   164,   165,   166,   167,    33,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,   185,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,     0,   189,     0,     0,     0,
       0,     0,     0,     0,   299,   662,     0,     0,     0,     0,
       0,     0,   185,     0,     0,   194,   195,   301,     0,   302,
       0,   187,     0,     0,   189,     0,     0,     0,     0,     0,
     303,   304,   299,   670,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   195,   301,     0,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,   304,
     486,     0,   161,   162,   163,   164,   165,   166,   167,    33,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,     0,   502,     0,   161,   162,   163,
     164,   165,   166,   167,    33,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
       0,     0,   185,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,     0,   189,     0,     0,     0,     0,     0,
       0,     0,   299,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,   194,   195,   301,   187,   302,     0,   189,
       0,     0,     0,     0,     0,     0,     0,   299,   303,   304,
       0,     0,     0,     0,     0,     0,     0,     0,   194,   195,
     301,     0,   302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   303,   304,   572,     0,   161,   162,   163,
     164,   165,   166,   167,    33,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
     574,     0,   161,   162,   163,   164,   165,   166,   167,    33,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,   187,     0,     0,   189,
       0,     0,     0,     0,     0,     0,     0,   299,     0,     0,
       0,     0,   185,     0,     0,     0,     0,     0,   194,   195,
     301,   187,   302,     0,   189,     0,     0,     0,     0,     0,
       0,     0,   299,   303,   304,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   195,   301,     0,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,   304,
     576,     0,   161,   162,   163,   164,   165,   166,   167,    33,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,     0,   578,     0,   161,   162,   163,
     164,   165,   166,   167,    33,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
       0,     0,   185,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,     0,   189,     0,     0,     0,     0,     0,
       0,     0,   299,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,   194,   195,   301,   187,   302,     0,   189,
       0,     0,     0,     0,     0,     0,     0,   299,   303,   304,
       0,     0,     0,     0,     0,     0,     0,     0,   194,   195,
     301,     0,   302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   303,   304,   580,     0,   161,   162,   163,
     164,   165,   166,   167,    33,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
     582,     0,   161,   162,   163,   164,   165,   166,   167,    33,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,   187,     0,     0,   189,
       0,     0,     0,     0,     0,     0,     0,   299,     0,     0,
       0,     0,   185,     0,     0,     0,     0,     0,   194,   195,
     301,   187,   302,     0,   189,     0,     0,     0,     0,     0,
       0,     0,   299,   303,   304,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   195,   301,     0,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,   304,
     584,     0,   161,   162,   163,   164,   165,   166,   167,    33,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,     0,   586,     0,   161,   162,   163,
     164,   165,   166,   167,    33,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
       0,     0,   185,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,     0,   189,     0,     0,     0,     0,     0,
       0,     0,   299,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,   194,   195,   301,   187,   302,     0,   189,
       0,     0,     0,     0,     0,     0,     0,   299,   303,   304,
       0,     0,     0,     0,     0,     0,     0,     0,   194,   195,
     301,     0,   302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   303,   304,   588,     0,  -394,  -394,  -394,
    -394,  -394,  -394,  -394,  -394,  -394,  -394,  -394,  -394,  -394,
    -394,  -394,  -394,  -394,  -394,  -394,  -394,     0,     0,     0,
     590,     0,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,     0,     0,     0,     0,     0,  -394,     0,     0,
       0,     0,     0,     0,     0,     0,  -394,     0,     0,  -394,
       0,     0,     0,     0,     0,     0,     0,  -394,     0,     0,
       0,     0,  -403,     0,     0,     0,     0,     0,  -394,  -394,
    -394,  -403,  -394,     0,  -403,     0,     0,     0,     0,     0,
       0,     0,  -403,  -394,  -394,     0,     0,     0,     0,     0,
       0,     0,     0,  -403,  -403,  -403,     0,  -403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -403,  -403,
     592,     0,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,     0,     0,     0,     0,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   167,    33,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
       0,     0,  -398,     0,   451,     0,     0,   452,     0,     0,
       0,  -398,     0,   453,  -398,     0,     0,     0,     0,   454,
       0,     0,  -398,     0,     0,     0,   455,     0,   456,     0,
     185,     0,     0,  -398,  -398,  -398,   457,  -398,     0,   187,
       0,     0,   189,     0,     0,     0,     0,     0,  -398,  -398,
     299,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   195,   301,     0,   302,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   303,   304,   161,   162,
     163,   164,   165,   166,   167,    33,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,   161,   162,   163,   164,
     165,   166,   167,    33,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     0,     0,   185,     0,
       0,     0,     0,     0,     0,     0,     0,   187,     0,     0,
     189,     0,     0,     0,     0,     0,     0,     0,   299,     0,
     508,   708,     0,     0,     0,     0,   185,     0,     0,   194,
     195,   301,     0,   302,     0,   187,     0,     0,   189,     0,
       0,     0,     0,     0,   303,   304,   299,   495,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,   195,   301,
       0,   302,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   303,   304,   161,   162,   163,   164,   165,   166,
     167,    33,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,     0,     0,     0,     0,     0,     0,
       0,     0,   161,   162,   163,   164,   165,   166,   167,    33,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,   185,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,     0,   189,     0,     0,     0,
       0,     0,     0,     0,   299,     0,     0,     0,     0,   642,
       0,     0,   185,     0,     0,   194,   195,   301,     0,   302,
       0,   187,     0,     0,   189,     0,     0,     0,     0,     0,
     303,   304,   299,   666,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   195,   301,     0,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,   304,
     161,   162,   163,   164,   165,   166,   167,    33,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,    84,     0,    85,     0,     0,    86,    51,     0,     0,
     185,     0,    87,     0,    52,     0,     7,     0,    88,   187,
       0,     0,   189,     0,     0,    89,     0,    90,    10,     0,
     299,    12,    13,    14,     0,    91,    15,    16,     0,     0,
      17,   194,   195,   301,    18,   302,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,   303,   304,   160,     0,
     161,   162,   163,   164,   165,   166,   167,    33,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
       4,     0,    84,   180,    85,     0,     0,    86,     5,     0,
     181,     0,   182,    87,     0,     6,     0,     7,     0,    88,
     183,   184,     0,     0,     0,     0,    89,     0,    90,    10,
     185,     0,    12,    13,    14,   186,    91,    15,    16,   187,
     188,    17,   189,     0,     0,    18,     0,     0,    19,   190,
     191,     0,  -241,   192,     0,     0,     0,   193,     0,     0,
       0,   194,   195,   160,     0,   161,   162,   163,   164,   165,
     166,   167,    33,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     4,     0,    84,   180,    85,
       0,     0,    86,     5,     0,   181,     0,   182,    87,     0,
       6,     0,     7,     0,    88,   183,   184,     0,     0,     0,
       0,    89,     0,    90,    10,   185,     0,    12,    13,    14,
     186,    91,    15,    16,   390,   188,    17,   391,     0,     0,
      18,     0,     0,    19,   190,   191,     0,  -241,   192,     0,
       0,     0,   193,     0,     0,     0,   194,   195,   289,     0,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
       0,     0,     0,  -257,     0,     0,     0,     0,     0,     0,
    -257,     0,  -257,     0,     0,     0,     0,     0,     0,     0,
    -257,  -257,     0,     0,     0,     0,     0,     0,     0,     0,
    -257,     0,     0,     0,     0,  -257,     0,     0,     0,  -257,
    -257,     0,  -257,     0,     0,     0,     0,     0,     0,  -257,
    -257,     0,  -257,     0,     0,     0,     0,  -257,     0,     0,
       0,  -257,  -257,   161,   162,   163,   164,   165,   166,   167,
      33,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     4,     0,    84,   180,    85,     0,     0,
      86,     5,     0,   181,     0,   182,    87,     0,     6,     0,
       7,     0,    88,   183,   184,     0,     0,     0,     0,    89,
       0,    90,    10,   185,     0,    12,    13,    14,   186,    91,
      15,    16,   187,   188,    17,   189,     0,     0,    18,     0,
       0,    19,   190,   191,     0,     0,   340,     0,     0,     0,
     193,     0,     0,     0,   194,   195,   161,   162,   163,   164,
     165,   166,   167,    33,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     4,     0,    84,   180,
      85,     0,     0,    86,     5,     0,   181,     0,   182,    87,
       0,     6,     0,     7,     0,    88,   183,   184,     0,     0,
       0,     0,    89,     0,    90,    10,   185,     0,    12,    13,
      14,   186,    91,    15,    16,   187,   188,    17,   189,     0,
       0,    18,     0,     0,    19,   190,   191,     0,     0,   524,
       0,     0,     0,   193,     0,     0,     0,   194,   195,   161,
     162,   163,   164,   165,   166,   167,    33,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,     4,
       0,    84,   180,    85,     0,     0,    86,     5,     0,   181,
       0,   182,    87,     0,     6,     0,     7,     0,    88,   183,
     184,     0,     0,     0,     0,    89,     0,    90,    10,   185,
       0,    12,    13,    14,   186,    91,    15,    16,   187,   188,
      17,   189,     0,     0,    18,     0,     0,    19,   190,   191,
       0,     0,   627,     0,     0,     0,   193,     0,     0,     0,
     194,   195,   161,   162,   163,   164,   165,   166,   167,    33,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     4,     0,    84,   180,    85,     0,     0,    86,
       5,     0,   181,     0,   182,    87,     0,     6,     0,     7,
       0,    88,   183,   184,     0,     0,     0,     0,    89,     0,
      90,    10,   185,     0,    12,    13,    14,   186,    91,    15,
      16,   187,   188,    17,   189,     0,     0,    18,     0,     0,
      19,   190,   191,     0,  -241,     0,     0,     0,     0,   193,
       0,     0,     0,   194,   195,   161,   162,   163,   164,   165,
     166,   167,    33,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     4,     0,    84,   180,    85,
       0,     0,    86,     5,     0,   181,     0,   182,    87,     0,
       6,     0,     7,     0,    88,   183,   184,     0,     0,     0,
       0,    89,     0,    90,    10,   185,     0,    12,    13,    14,
     186,    91,    15,    16,   187,   188,    17,   189,     0,     0,
      18,     0,     0,    19,   190,   191,     0,     0,     0,     0,
       0,     0,   193,     0,     0,     0,   194,   195,   161,   162,
     163,   164,   165,   166,   167,    33,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,   181,     0,
     182,     0,     0,     0,     0,     0,     0,     0,   183,   184,
       0,     0,     0,     0,     0,     0,     0,     0,   185,     0,
       0,     0,     0,   186,     0,     0,     0,   187,   188,     0,
     189,     0,     0,     0,     0,     0,     0,   190,   191,     0,
       0,     0,     0,     0,     0,   193,     0,     0,     0,   194,
     195,   161,   162,   163,   164,   165,   166,   167,    33,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,   185,     0,     0,     0,     0,     0,     0,     0,     0,
     187,     0,     4,   189,    84,     0,    85,     0,     0,    86,
       0,   191,     0,     0,     0,    87,     0,     0,     0,     7,
       0,    88,   194,   195,     0,     0,     0,     0,    89,     0,
      90,    10,     0,     0,    12,    13,    14,     0,    91,    92,
      16,     0,     0,    17,     0,    33,     0,    18,     0,    93,
      19,     0,     0,     0,    94,    95,     0,     0,     4,    96,
      84,     0,    85,     0,     0,    86,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     7,     0,    88,     0,     0,
       0,     0,     0,     0,    89,     0,    90,    10,     0,     0,
      12,    13,    14,     0,    91,    92,    16,     0,     0,    17,
       0,    33,     0,    18,     0,    93,    19,     0,     0,     0,
      94,   236,     0,     0,     4,    96,    84,     0,    85,     0,
       0,    86,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     7,     0,    88,     0,     0,     0,     0,     0,     0,
      89,     0,    90,    10,     0,     0,    12,    13,    14,     0,
      91,    15,    16,    33,     0,    17,     0,     0,     0,    18,
       0,   135,    19,     0,     0,     0,     4,   136,    84,     0,
      85,   137,     0,    86,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     7,     0,    88,     0,     0,     0,     0,
       0,     0,    89,     0,    90,    10,     0,     0,    12,    13,
      14,     0,    91,    92,    16,     0,     0,    17,     0,    33,
       0,    18,     0,    93,    19,     0,     0,     0,    94,     0,
       0,     0,     4,    96,    84,     0,    85,     0,     0,    86,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     7,
       0,    88,     0,     0,     0,     0,     0,     0,    89,     0,
      90,    10,     0,     0,    12,    13,    14,     0,    91,    15,
      16,    33,     0,    17,     0,     0,     0,    18,     0,   135,
      19,     0,     0,     0,     4,   267,    84,     0,    85,   137,
       0,    86,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     7,     0,    88,     0,     0,     0,     0,     0,     0,
      89,     0,    90,    10,     0,     0,    12,    13,    14,     0,
      91,    15,    16,    33,     0,    17,     0,     0,     0,    18,
       0,   233,    19,     0,     0,     0,     4,     0,    84,     0,
      85,     0,     0,    86,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     7,     0,    88,     0,     0,     0,     0,
       0,     0,    89,     4,    90,    10,     0,     0,    12,    13,
      14,     5,    91,    15,    16,     0,     0,    17,     6,     0,
       7,    18,     0,   265,    19,     0,     0,     8,     0,     0,
       9,     0,    10,     0,    11,    12,    13,    14,     4,     0,
      15,    16,     0,     0,    17,     0,     5,     0,    18,     0,
       0,    19,     0,     6,     0,     7,     0,     0,     0,     0,
       0,     0,     8,     0,     0,     9,     0,    10,     0,     0,
      12,    13,    14,     4,     0,    15,    16,     0,     0,    17,
       0,     5,     0,    18,     0,     0,    19,     0,     6,     0,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,    10,     0,     0,    12,    13,    14,     4,     0,
      15,    16,     0,     0,    17,     0,    51,     0,    18,     0,
       0,    19,     0,    52,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,    10,     0,     0,
      12,    13,    14,   334,     0,    15,    16,   -41,     0,    17,
       0,   335,     0,    18,     0,     0,    19,     0,     0,     0,
    -411,  -411,  -411,  -411,  -411,  -411,     0,     0,     0,     0,
       0,  -411,  -411,  -411,     0,     0,     0,     0,     0,     0,
       0,  -411,     0,  -411,     0,     0,     0,     0,  -411
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-500))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       5,     6,   442,     8,     9,    94,    11,   205,     8,   508,
      59,    11,    94,   376,    94,   392,    55,   217,    28,    73,
     108,     1,   290,     1,    55,    10,     1,    81,    77,    72,
     234,     1,    10,    38,     0,    10,     1,    94,    38,    70,
     125,   222,     1,   128,     1,    97,    51,    52,    53,     1,
      55,    55,    57,    58,     1,    55,    61,    57,    58,     1,
      83,   222,   266,    94,    75,    70,    70,    72,   107,   108,
      70,     1,    72,   122,     1,    92,     1,   108,   127,     1,
      10,    75,    60,   135,     1,   222,   138,   126,    93,    94,
       1,    46,    97,   116,    94,   126,    76,   107,   115,   148,
      80,   155,   107,   108,   108,    80,    76,   107,   108,   309,
     141,   154,    97,    94,    75,    36,   205,    82,    75,    78,
      75,   126,   126,   205,    76,   205,   126,    74,   133,   139,
     135,     1,    79,   138,   139,   339,   141,   141,    80,   139,
       1,   141,   147,    36,    94,   326,   327,   147,   205,   154,
      80,   240,   515,    80,   154,    80,    78,    78,   240,    80,
     240,    78,   250,   334,     1,   326,   327,    78,    94,     1,
      63,   256,     1,    10,   205,   180,   181,     1,   677,     1,
     185,   233,   234,   240,    80,   185,    79,    80,     1,   326,
     327,   208,     1,   203,   243,   200,   117,    10,   203,   639,
     205,   290,     1,   203,   253,   205,    39,     1,    78,   240,
     290,   250,    73,   265,   266,   269,     1,   222,   235,   250,
      10,   238,    80,   272,   205,    80,   231,     1,   233,   234,
     498,   231,     1,   290,     1,   240,    10,    10,     1,    76,
     240,     1,    79,    80,    76,   250,   250,    79,    80,    78,
     250,   256,    76,     1,    76,   205,     1,    79,   151,   240,
     265,   266,    21,    76,     1,    74,    10,    80,    75,    80,
      79,   276,   277,    80,     1,    74,   276,   277,   449,   205,
      79,   462,    76,    81,   465,   290,     1,    46,   469,    74,
     240,    81,    57,    58,   475,   735,   736,   478,   479,   480,
     481,   462,    55,   392,    73,     1,    73,    72,    81,   290,
     392,    74,   392,    73,   240,    97,   679,    70,     1,    39,
      77,   326,   327,   328,    22,   462,    74,   525,   465,    74,
     335,    79,   469,    90,   339,   392,    73,    76,   475,   344,
     290,   478,   479,   480,   481,   394,    73,   710,    46,   270,
      28,   522,   523,   442,   107,   108,    34,    28,    73,    75,
     365,   392,   442,    34,   290,   419,   743,   416,    22,   374,
      24,   376,   640,   126,   374,    74,    77,    73,    48,    73,
      79,    77,   147,    79,    80,   442,   139,   392,   141,   154,
       1,    74,   392,    47,    90,     1,    79,     1,    76,    10,
      73,     1,    75,    77,    10,     1,    10,     1,   589,   498,
      10,   392,   593,    77,    10,    73,    10,     1,   498,    77,
     185,   689,    76,    81,   595,    73,    10,    46,   599,    96,
      97,    98,   603,    81,   702,     1,   525,   107,   108,   109,
     110,   498,   392,   525,    10,   525,     1,    39,    74,    87,
     203,    89,   589,    79,    46,    10,   593,   462,   186,    80,
     465,   442,    74,   191,   469,    39,   392,    79,   525,   737,
     475,    80,    46,   478,   479,   480,   481,    73,   231,    80,
      81,    77,   104,   105,   106,    81,    82,   536,    84,    85,
      81,    77,   442,   498,   525,    81,    77,   250,    84,    85,
      81,    84,    85,    84,    85,   446,    76,   448,    84,    85,
     515,    79,    80,    77,   519,    80,   442,   498,    81,   519,
     525,    99,   100,   276,   277,   525,   276,   277,    77,    80,
      75,    73,    80,    80,    90,    91,    92,    93,    94,    95,
      80,    80,   723,    80,   525,   101,   102,   103,   498,    80,
     639,   640,   280,   751,   282,   111,    80,   113,    80,   639,
     640,    80,   118,    80,    80,    80,   294,    77,    73,    76,
     114,   299,   498,    77,   112,   525,   117,    80,    80,   115,
      80,    74,   639,   640,   589,    80,   723,    74,   593,    80,
      80,    79,    73,    79,    74,    80,    79,    73,    80,   525,
     689,    80,   330,    80,    74,    80,    74,    80,    80,   689,
     338,    80,    72,   702,    80,    74,    77,   345,    74,    74,
      74,   374,   702,    74,    74,    74,    74,    80,    74,    73,
      73,   359,   689,    80,   126,   640,    81,    77,    80,    80,
     368,    80,    80,    80,    74,   702,   735,   736,   737,    80,
      73,    80,    74,    79,   743,   735,   736,   737,   639,   640,
      78,   743,   751,   743,    77,    80,    80,    76,    80,   751,
      80,   751,    80,    80,   679,    80,    80,    80,   735,   736,
     737,    80,    80,    80,   689,    74,   743,    80,    80,   639,
     640,    76,    79,    81,   751,    81,    80,   702,    80,    80,
      80,    80,    80,    78,    80,   710,    75,    80,   689,    80,
      37,    81,   743,   639,   640,    80,    80,   445,   723,    80,
     751,   702,    80,    74,    80,    80,    74,    80,    82,    74,
     458,    80,   737,    80,    21,   365,    82,    80,   743,   689,
     519,   519,   256,   743,   107,   141,   751,   729,   727,     1,
     185,   751,   702,   736,   735,   736,   737,    10,    10,   448,
     442,   235,   743,   689,   296,   493,   519,   469,   465,   475,
     751,   478,    25,    25,    27,    27,   702,    30,    30,   479,
     508,   589,    -1,    36,    36,   735,   736,   737,    40,    42,
      42,   481,   480,   743,   723,    -1,    49,    49,    51,    51,
     593,   751,   530,    -1,    -1,    -1,    59,    59,    -1,   735,
     736,   737,    -1,    -1,    -1,    -1,    -1,   743,    -1,    -1,
      -1,    -1,    74,    -1,    -1,   751,    -1,    -1,    -1,    -1,
     558,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    90,    91,    92,    93,    94,    95,    -1,
      -1,    -1,    -1,   591,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,   118,    -1,    53,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    10,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    73,    -1,    75,    76,   635,    25,    79,
      27,    10,    -1,    30,    84,    85,    86,    -1,    88,    36,
      -1,    -1,    -1,    40,    -1,    42,    25,    -1,    27,    99,
     100,    30,    49,    -1,    51,    -1,    -1,    36,    -1,    -1,
      -1,    40,    59,    42,    -1,    -1,    -1,    -1,    -1,   677,
      49,    -1,    51,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      59,    -1,    -1,     1,   692,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    10,    90,    91,
      92,    93,    94,    95,    -1,    -1,    -1,   725,    -1,   101,
     102,   103,    25,    -1,    27,    -1,    -1,    30,    -1,   111,
      -1,   113,    -1,    36,    -1,    53,   118,    40,    -1,    42,
      -1,    -1,    -1,    -1,    62,    -1,    49,    65,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    59,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    85,    86,    -1,
      88,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    84,    85,    86,    -1,
      88,    -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    99,   100,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    62,    88,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    99,
     100,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    84,
      85,    86,    -1,    88,    -1,    62,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    99,   100,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    84,    85,    86,
      -1,    88,    -1,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    99,   100,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    84,    85,    86,    -1,    88,
      -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      99,   100,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    62,    88,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    62,    88,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    62,    88,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    62,    88,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    62,    88,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    84,    85,
      86,    62,    88,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    53,    -1,    27,    -1,    -1,    30,    -1,    -1,
      -1,    62,    -1,    36,    65,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    73,    -1,    -1,    -1,    49,    -1,    51,    -1,
      53,    -1,    -1,    84,    85,    86,    59,    88,    -1,    62,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    99,   100,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      75,    76,    -1,    -1,    -1,    -1,    53,    -1,    -1,    84,
      85,    86,    -1,    88,    -1,    62,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    99,   100,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    53,    -1,    -1,    84,    85,    86,    -1,    88,
      -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      99,   100,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    25,    -1,    27,    -1,    -1,    30,    31,    -1,    -1,
      53,    -1,    36,    -1,    38,    -1,    40,    -1,    42,    62,
      -1,    -1,    65,    -1,    -1,    49,    -1,    51,    52,    -1,
      73,    55,    56,    57,    -1,    59,    60,    61,    -1,    -1,
      64,    84,    85,    86,    68,    88,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    -1,    -1,    30,    31,    -1,
      33,    -1,    35,    36,    -1,    38,    -1,    40,    -1,    42,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,
      73,    -1,    75,    76,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    85,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      -1,    -1,    30,    31,    -1,    33,    -1,    35,    36,    -1,
      38,    -1,    40,    -1,    42,    43,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      68,    -1,    -1,    71,    72,    73,    -1,    75,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    85,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,
      63,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    75,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    85,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    -1,    -1,
      30,    31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,
      40,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    -1,    68,    -1,
      -1,    71,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    85,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    -1,    -1,    30,    31,    -1,    33,    -1,    35,    36,
      -1,    38,    -1,    40,    -1,    42,    43,    44,    -1,    -1,
      -1,    -1,    49,    -1,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      -1,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    -1,    -1,    30,    31,    -1,    33,
      -1,    35,    36,    -1,    38,    -1,    40,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    -1,    -1,    30,
      31,    -1,    33,    -1,    35,    36,    -1,    38,    -1,    40,
      -1,    42,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,
      71,    72,    73,    -1,    75,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    85,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      -1,    -1,    30,    31,    -1,    33,    -1,    35,    36,    -1,
      38,    -1,    40,    -1,    42,    43,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      68,    -1,    -1,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    85,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      85,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    23,    65,    25,    -1,    27,    -1,    -1,    30,
      -1,    73,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,
      -1,    42,    84,    85,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    -1,    59,    60,
      61,    -1,    -1,    64,    -1,    10,    -1,    68,    -1,    70,
      71,    -1,    -1,    -1,    75,    76,    -1,    -1,    23,    80,
      25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    -1,    59,    60,    61,    -1,    -1,    64,
      -1,    10,    -1,    68,    -1,    70,    71,    -1,    -1,    -1,
      75,    76,    -1,    -1,    23,    80,    25,    -1,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    -1,
      59,    60,    61,    10,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    71,    -1,    -1,    -1,    23,    76,    25,    -1,
      27,    80,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    51,    52,    -1,    -1,    55,    56,
      57,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    10,
      -1,    68,    -1,    70,    71,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    23,    80,    25,    -1,    27,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    55,    56,    57,    -1,    59,    60,
      61,    10,    -1,    64,    -1,    -1,    -1,    68,    -1,    70,
      71,    -1,    -1,    -1,    23,    76,    25,    -1,    27,    80,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    51,    52,    -1,    -1,    55,    56,    57,    -1,
      59,    60,    61,    10,    -1,    64,    -1,    -1,    -1,    68,
      -1,    70,    71,    -1,    -1,    -1,    23,    -1,    25,    -1,
      27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    23,    51,    52,    -1,    -1,    55,    56,
      57,    31,    59,    60,    61,    -1,    -1,    64,    38,    -1,
      40,    68,    -1,    70,    71,    -1,    -1,    47,    -1,    -1,
      50,    -1,    52,    -1,    54,    55,    56,    57,    23,    -1,
      60,    61,    -1,    -1,    64,    -1,    31,    -1,    68,    -1,
      -1,    71,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,    52,    -1,    -1,
      55,    56,    57,    23,    -1,    60,    61,    -1,    -1,    64,
      -1,    31,    -1,    68,    -1,    -1,    71,    -1,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    -1,    -1,    55,    56,    57,    23,    -1,
      60,    61,    -1,    -1,    64,    -1,    31,    -1,    68,    -1,
      -1,    71,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    -1,
      55,    56,    57,    73,    -1,    60,    61,    77,    -1,    64,
      -1,    81,    -1,    68,    -1,    -1,    71,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,
      -1,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,   118
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   125,   126,     0,    23,    31,    38,    40,    47,    50,
      52,    54,    55,    56,    57,    60,    61,    64,    68,    71,
     141,   142,   143,   144,   145,   146,   147,   148,   157,   158,
     188,   194,     1,    10,   127,     1,   127,     1,    60,   127,
     138,   139,     1,   127,     1,   138,   143,   145,   144,   146,
     146,    31,    38,    50,   158,    75,   161,    39,    46,   156,
     159,    75,   189,   159,   189,    80,     1,   138,    80,    81,
      75,   199,    39,   198,    80,    80,   145,     1,   127,     1,
     127,     1,   127,     1,    25,    27,    30,    36,    42,    49,
      51,    59,    60,    70,    75,    76,    80,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   157,   162,   163,
     164,   165,   173,   175,   184,   185,   203,   137,   138,   137,
     160,   161,   153,     1,    76,    79,    80,   127,   190,   191,
     192,   189,    80,    81,    97,    70,    76,    80,   131,   157,
     165,   200,   201,   202,   160,   199,   161,    39,   155,   159,
     189,   159,   189,   199,    39,   197,    76,   203,   127,   176,
       1,     3,     4,     5,     6,     7,     8,     9,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      26,    33,    35,    43,    44,    53,    58,    62,    63,    65,
      72,    73,    76,    80,    84,    85,   127,   128,   129,   130,
     131,   138,   147,   157,   165,   204,   205,   206,   207,   218,
     233,   234,   235,   237,   241,   242,   243,   244,   245,   247,
     264,   265,   266,     1,   127,   167,   168,   169,   176,    77,
      77,    73,    77,    70,   131,   185,    76,   163,   174,     1,
      75,   186,   203,   154,   159,   161,    80,     1,    76,   192,
     162,    73,   161,   193,     1,    76,    79,   192,     1,    76,
      97,   127,    80,   176,   176,    70,   131,    76,   201,   196,
     137,   161,   151,   189,   160,   199,     1,    73,    76,     1,
      73,     1,    73,     1,    80,   127,     1,    80,   127,     1,
     213,     1,   214,     1,    73,   132,   137,   138,     1,    73,
      80,    86,    88,    99,   100,   127,   138,   235,   242,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   258,   260,   263,   264,   267,   268,    81,     1,
      73,     1,    73,   263,    73,    81,    82,   127,    77,   131,
      76,   205,   203,    80,    81,    77,   266,    90,    91,    92,
      93,    94,    95,   101,   102,   103,   111,   113,   118,   274,
     127,   241,   243,   246,    80,    79,    80,    77,    90,     1,
      78,     1,    78,     1,    40,    74,   131,   179,   180,   181,
     182,     1,    78,   176,   167,   176,   186,    80,   183,   203,
      62,    65,   187,   161,   150,    80,     1,    76,     1,    74,
     236,   263,   161,    80,     1,    76,   191,   192,     1,    76,
      80,    80,    80,   176,   176,   199,   152,   159,   161,   195,
      74,   179,     1,   178,   179,    80,     1,    74,   263,    80,
       1,    74,   263,    80,     1,    80,    80,     1,    80,    80,
     206,    80,    73,    80,   263,    77,   238,   239,   238,    73,
      76,    27,    30,    36,    42,    49,    51,    59,    77,    96,
      97,    98,   269,    99,   100,   270,   104,   105,   106,   271,
      48,   107,   108,   109,   110,   272,    87,    89,   273,   112,
     117,   114,   115,    83,   116,    80,     1,   246,   246,   127,
      80,   263,    80,   211,    74,    74,   236,   127,   208,   263,
     127,   263,     1,   263,   168,     1,    78,     1,    75,   170,
     171,   263,    80,    80,    80,   131,    81,   169,    74,    79,
      80,   166,    73,    73,    76,   204,   161,    80,    74,    74,
      79,    80,     1,    76,    80,   161,   149,   199,    74,    80,
      74,     1,   177,    80,     1,    74,    80,     1,    74,    80,
      80,    72,   218,   224,   230,   232,    74,   263,    77,   239,
     240,   240,     1,    74,   236,    74,    74,    74,    74,    74,
      74,    74,     1,   246,     1,   248,     1,   249,     1,   250,
       1,   251,     1,   252,     1,   253,     1,   254,     1,   257,
       1,   261,     1,   259,    80,    73,    74,   263,    74,    73,
     206,     1,    78,    73,     1,    78,    80,    80,    80,     1,
      76,    79,   170,   172,    81,   169,    81,     1,   181,   182,
      80,     1,    74,   236,     1,    74,   236,    76,   263,    80,
     161,    80,    74,    80,    80,    73,    74,     1,    80,    79,
     209,    78,    78,    77,    80,     1,    74,    80,    80,    80,
      80,    80,    80,    80,    80,    80,   255,    80,   263,    80,
     256,     1,    74,   236,   210,    74,    74,   236,    80,     1,
      74,   236,    80,    76,    76,     1,    76,    79,    81,    81,
      80,    80,     1,    74,    80,    80,     1,    74,   263,   215,
      80,   227,   228,   229,   218,   206,    78,   262,    80,     1,
      74,    75,   212,    74,    80,     1,    74,    80,    76,   170,
      81,   169,    80,    80,    80,    80,    74,   206,    80,   263,
      80,    37,   216,    82,    80,    28,    34,   219,   220,   222,
     223,   206,    80,   169,    80,   225,   226,   217,   260,   263,
      82,    76,   220,   221,   223,   231,   232,   231,   206,     1,
      82,   204,    80
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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

/* Line 1806 of yacc.c  */
#line 371 "parser.ypp"
    {
		fprintf(fcg,".data\n");
		fprintf(fcg,"newline:\t.asciiz \"\\n\"\n\n");
		fprintf(fcg,".text\n");
	}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 375 "parser.ypp"
    {printf("Compilation complete\n");}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 379 "parser.ypp"
    { strcpy((yyval.str),yylval.str);}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 383 "parser.ypp"
    { (yyval.attr)=(yyvsp[(1) - (1)].attr); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 385 "parser.ypp"
    { (yyval.attr)=(yyvsp[(1) - (1)].attr); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 388 "parser.ypp"
    {  	(yyval.attr)=new struct attribute;
		(yyval.attr)->type=tboolean; 
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		if(!strcmp(lexeme,"true"))
			strcpy((yyval.attr)->contains,"1");
		else
			strcpy((yyval.attr)->contains,"0");	
	}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 398 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tchar;strcpy((yyval.attr)->contains,lexeme);(yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 400 "parser.ypp"
    {  (yyval.attr)=new struct attribute;strcpy((yyval.attr)->ref,"String");strcpy((yyval.attr)->contains,lexeme); (yyval.attr)->token=2;(yyval.attr)->dimension=0;}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 402 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tnull;strcpy((yyval.attr)->contains,lexeme); (yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 404 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tnone;printf("ERROR:Erraneous literal at line %d\n",yylineno);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 409 "parser.ypp"
    {  
		(yyval.attr)=new struct attribute;
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		char val[64];
		int j=0;
		for(int i=0;i<strlen(lexeme);i++)
		{
			if(lexeme[i]>='0' && lexeme[i]<='9')
				val[j++]=lexeme[i];
		}
		val[j]='\0';
		strcpy((yyval.attr)->contains,val);
		(yyval.attr)->type=findType(val,strlen(val)); 
	}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 425 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tint; (yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 427 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tint; (yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 429 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tint; (yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 432 "parser.ypp"
    {  
		(yyval.attr)=new struct attribute;
		(yyval.attr)->type=tlong; 
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		char val[64];
		int j=0;
		for(int i=0;i<strlen(lexeme);i++)
		{
			if(lexeme[i]>='0' && lexeme[i]<='9')
				val[j++]=lexeme[i];
		}
		val[j]='\0';
		strcpy((yyval.attr)->contains,val);
	}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 448 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tlong; (yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 450 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tlong; (yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 452 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tlong; (yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 457 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tdouble; (yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 460 "parser.ypp"
    {  
		(yyval.attr)=new struct attribute;
		(yyval.attr)->type=tdouble; 
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		char val[64];
		int j=0;
		for(int i=0;i<strlen(lexeme);i++)
		{
			if((lexeme[i]>='0' && lexeme[i]<='9') || (lexeme[i]=='.'))
				val[j++]=lexeme[i];
		}
		val[j]='\0';
		strcpy((yyval.attr)->contains,val);
	}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 476 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->type=tfloat; (yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 479 "parser.ypp"
    {  
		(yyval.attr)=new struct attribute;
		(yyval.attr)->type=tfloat; 
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		char val[64];
		int j=0;
		for(int i=0;i<strlen(lexeme);i++)
		{
			if((lexeme[i]>='0' && lexeme[i]<='9') || (lexeme[i]=='.'))
				val[j++]=lexeme[i];
		}
		val[j]='\0';
		strcpy((yyval.attr)->contains,val);
	}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 498 "parser.ypp"
    { 	(yyval.attr)=(yyvsp[(1) - (1)].attr);
		typeinfo=new struct attribute;
		typeinfo->type=(yyval.attr)->type;
		typeinfo->token=(yyval.attr)->token;
		typeinfo->dimension=(yyval.attr)->dimension;
	}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 506 "parser.ypp"
    { 	(yyval.attr)=(yyvsp[(1) - (1)].attr);
		typeinfo=new struct attribute;
		typeinfo->token=(yyval.attr)->token;
		//printf("%d\n",typeinfo->token);
		strcpy(typeinfo->ref,(yyval.attr)->ref);
		typeinfo->dimension=(yyval.attr)->dimension;
	}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 515 "parser.ypp"
    { (yyval.attr)=(yyvsp[(1) - (1)].attr); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 517 "parser.ypp"
    {  (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tboolean; (yyval.attr)->token=1; (yyval.attr)->dimension=0;}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 520 "parser.ypp"
    { (yyval.attr)=(yyvsp[(1) - (1)].attr); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 522 "parser.ypp"
    { (yyval.attr)=(yyvsp[(1) - (1)].attr); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 525 "parser.ypp"
    {  (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tbyte; (yyval.attr)->token=1; (yyval.attr)->dimension=0;}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 527 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tshort; (yyval.attr)->token=1; (yyval.attr)->dimension=0;}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 529 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tint; (yyval.attr)->token=1; (yyval.attr)->dimension=0;}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 531 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute)); (yyval.attr)->type=tlong; (yyval.attr)->token=1; (yyval.attr)->dimension=0;}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 533 "parser.ypp"
    {  (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tchar; (yyval.attr)->token=1; (yyval.attr)->dimension=0;}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 536 "parser.ypp"
    {  (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tfloat; (yyval.attr)->token=1; (yyval.attr)->dimension=0;}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 538 "parser.ypp"
    {  (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tdouble; (yyval.attr)->token=1; (yyval.attr)->dimension=0;}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 541 "parser.ypp"
    { (yyval.attr)=(yyvsp[(1) - (1)].attr); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 543 "parser.ypp"
    { (yyval.attr)=(yyvsp[(1) - (1)].attr); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 547 "parser.ypp"
    { (yyval.attr)=(yyvsp[(1) - (1)].attr); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 550 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));strcpy((yyval.attr)->ref,(yyvsp[(1) - (1)].str));strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].str)); (yyval.attr)->token=2; (yyval.attr)->dimension=0;}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 553 "parser.ypp"
    {  strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 556 "parser.ypp"
    {  (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=(yyvsp[(1) - (3)].attr)->type;(yyval.attr)->token=3;(yyval.attr)->dimension=1;}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 558 "parser.ypp"
    {  (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));strcpy((yyval.attr)->ref,(yyvsp[(1) - (3)].attr)->ref); (yyval.attr)->token=4;(yyval.attr)->dimension=1;}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 561 "parser.ypp"
    { 	
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		if((yyvsp[(1) - (3)].attr)->token==3)
		{
			(yyval.attr)->type=(yyvsp[(1) - (3)].attr)->type;	
			(yyval.attr)->token=3;
		}
		else if((yyvsp[(1) - (3)].attr)->token==4)
		{
			strcpy((yyval.attr)->ref,(yyvsp[(1) - (3)].attr)->ref);
			(yyval.attr)->token=4;
		}
		(yyval.attr)->dimension=(yyvsp[(1) - (3)].attr)->dimension+1;
	}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 576 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:missing ] on %d\n",yylineno);}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 578 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:missing ] on %d\n",yylineno);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 580 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:missing ] on %d\n",yylineno);}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 639 "parser.ypp"
    {
		for(int i=0;i<listOfModifiers.size();i++) {
		if(!(listOfModifiers[i]==mpublic||listOfModifiers[i]==mprivate||\
		listOfModifiers[i]==mprotected||listOfModifiers[i]==mabstract||listOfModifiers[i]==mstatic||listOfModifiers[i]==mfinal||listOfModifiers[i]==mstrictfp )) 
				printf("ERROR:Incorrect modifier at line %d\n",yylineno);}
		currenterpointer++;
                	createtable(currenter);
                	ClassInterface cl;
                	strcpy(cl.name,(yyvsp[(3) - (6)].str));
                	cl.table=new ST;
			cl.extends=(ClassInterface *)malloc(sizeof(ClassInterface));
			cl.implements=(ClassInterface *)malloc(sizeof(ClassInterface));
                	cl.table=currenter;
			int i;
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,(yyvsp[(5) - (6)].attr)->ref)==0)
                                        break;
                        }
                        if(i==listOfClasses.size())
			{
				cl.extends=NULL;
                                printf("ERROR:error in class declaration.No class/interface of name %s found\n",(yyvsp[(5) - (6)].attr)->ref);
			}
                        else
                                *(cl.extends)=listOfClasses[i];  
			//printf("here\n");
                        for(i=0;i<listOfClasses.size();i++)
                        {
                                if(strcmp(listOfClasses[i].name,(yyvsp[(6) - (6)].attr)->ref)==0)
                                        break;
                        }
                        if(i==listOfClasses.size())
			{
				cl.implements=NULL;
                                printf("ERROR:Error in class declaration.No class/interface of name %s found\n",(yyvsp[(6) - (6)].attr)->ref);
			}
                        else
                                *(cl.implements)=listOfClasses[i]; 
                        cl.modifiers=listOfModifiers;
                        listOfModifiers.clear();
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{currenterpointer--;printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);}
        }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 690 "parser.ypp"
    {currenter=NULL;}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 693 "parser.ypp"
    {
			currenterpointer++;
                        createtable(currenter);
                        ClassInterface cl;
                        strcpy(cl.name,(yyvsp[(2) - (5)].str));
                        cl.table=(ST *)malloc(sizeof(ST));
                        cl.table=currenter;
			cl.extends=(ClassInterface *)malloc(sizeof(ClassInterface));
			cl.implements=(ClassInterface *)malloc(sizeof(ClassInterface));	
			int i;
                        for(i=0;i<listOfClasses.size();i++)
                        {
                                if(strcmp(listOfClasses[i].name,(yyvsp[(4) - (5)].attr)->ref)==0)
                                        break;
                        }
                        if(i==listOfClasses.size())
			{
				cl.extends=NULL;
                                printf("ERROR:Error in class declaration.No class/interface of name %s found\n",(yyvsp[(4) - (5)].attr)->ref);
			}
                        else
                                *(cl.extends)=listOfClasses[i];
                        for(i=0;i<listOfClasses.size();i++)
                        {
                                if(strcmp(listOfClasses[i].name,(yyvsp[(5) - (5)].attr)->ref)==0)
                                        break;
                        }
                        if(i==listOfClasses.size())
			{
				cl.implements=NULL;
                                printf("ERROR:Error in class declaration.No class/interface of name %s found\n",(yyvsp[(5) - (5)].attr)->ref);
			}
                        else
                                *(cl.implements)=listOfClasses[i];
                        cl.modifiers.push_back(mnative);
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{currenterpointer--;printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);}
                        
        }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 738 "parser.ypp"
    {currenter=NULL;}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 741 "parser.ypp"
    { 
		for(int i=0;i<listOfModifiers.size();i++) {if(!(listOfModifiers[i]==mpublic || listOfModifiers[i]==mprivate ||listOfModifiers[i]==mprotected || listOfModifiers[i]==mabstract || listOfModifiers[i]==mstatic ||listOfModifiers[i]==mfinal || listOfModifiers[i]==mstrictfp) ) 
                                printf("ERROR:Incorrect modifier at line %d\n",yylineno);}
		currenterpointer++;
                createtable(currenter);
                ClassInterface cl;
                strcpy(cl.name,(yyvsp[(3) - (4)].str));
                cl.table=(ST *)malloc(sizeof(ST));
		cl.table=currenter;
		cl.extends=(ClassInterface *)malloc(sizeof(ClassInterface));
		cl.implements=(ClassInterface *)malloc(sizeof(ClassInterface));	
		cl.extends=NULL;
                cl.table=currenter;
		int i;
		for(i=0;i<listOfClasses.size();i++)
                {
                        if(strcmp(listOfClasses[i].name,(yyvsp[(4) - (4)].attr)->ref)==0)
                                break;
                }
                if(i==listOfClasses.size())
		{
		       cl.implements=NULL;	
                       printf("ERROR:Error in class declaration.No class/interface of name %s found\n",(yyvsp[(4) - (4)].attr)->ref);
		}
                else
                       *(cl.implements)=listOfClasses[i];
                cl.modifiers=listOfModifiers;
                listOfModifiers.clear();
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{currenterpointer--;printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);}
                
        }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 780 "parser.ypp"
    {currenter=NULL;}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 783 "parser.ypp"
    {
		int i;
		for(i=0;i<listOfModifiers.size();i++) {if(!(listOfModifiers[i]==mpublic || listOfModifiers[i]==mprivate ||listOfModifiers[i]==mprotected || listOfModifiers[i]==mabstract || listOfModifiers[i]==mstatic ||listOfModifiers[i]==mfinal || listOfModifiers[i]==mstrictfp) ) 
                                printf("ERROR:Incorrect modifier at line %d\n",yylineno);}
		currenterpointer++;
                createtable(currenter);
                ClassInterface cl;
                strcpy(cl.name,(yyvsp[(3) - (5)].str));
                cl.table=(ST *)malloc(sizeof(ST));
                cl.table=currenter;
                cl.implements=(ClassInterface *)malloc(sizeof(ClassInterface));
		cl.implements=NULL;
		cl.extends=(ClassInterface *)malloc(sizeof(ClassInterface));	
                for(i=0;i<listOfClasses.size();i++)
                {
                         if(strcmp(listOfClasses[i].name,(yyvsp[(5) - (5)].attr)->ref)==0)
                               break;
                }
                if(i==listOfClasses.size())
		{
			cl.extends=NULL;
                        printf("ERROR:Error in class declaration.No class/interface of name %s found\n",(yyvsp[(5) - (5)].attr)->ref);
		}
                else
                    	*(cl.extends)=listOfClasses[i];
                cl.modifiers=listOfModifiers;
                listOfModifiers.clear();
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{currenterpointer--;printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);}
               
       }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 820 "parser.ypp"
    {currenter=NULL;}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 823 "parser.ypp"
    {
		currenterpointer++;
                createtable(currenter);
                ClassInterface cl;
                strcpy(cl.name,(yyvsp[(2) - (3)].str));
                cl.table=(ST *)malloc(sizeof(ST));
                cl.implements=(ClassInterface *)malloc(sizeof(ClassInterface));
		cl.extends=(ClassInterface *)malloc(sizeof(ClassInterface));	
          	cl.extends=NULL;
                cl.table=currenter;
		int i;
                for(i=0;i<listOfClasses.size();i++)
                {
                                if(strcmp(listOfClasses[i].name,(yyvsp[(3) - (3)].attr)->ref)==0)
                                        break;
                }
                if(i==listOfClasses.size())
		{
			cl.implements=NULL;
                        printf("ERROR:Error in class declaration.No class/interface of name %s found\n",(yyvsp[(3) - (3)].attr)->ref);
		}
                else
                        *(cl.implements)=listOfClasses[i];
                cl.modifiers.push_back(mnative);
		        for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{currenterpointer--;printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);}
        }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 856 "parser.ypp"
    {currenter=NULL;}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 859 "parser.ypp"
    {
			currenterpointer++;
                        createtable(currenter);
                        ClassInterface cl;
                        strcpy(cl.name,(yyvsp[(2) - (4)].str));
                        cl.table=(ST *)malloc(sizeof(ST));
                        cl.extends=(ClassInterface *)malloc(sizeof(ClassInterface));
                        cl.implements=(ClassInterface *)malloc(sizeof(ClassInterface));
			cl.implements=NULL;				
                        cl.table=currenter;
			int i;
                        for(i=0;i<listOfClasses.size();i++)
                        {
                                if(strcmp(listOfClasses[i].name,(yyvsp[(4) - (4)].attr)->ref)==0)
                                        break;
                        }
                        if(i==listOfClasses.size())
			{
				cl.extends=NULL;
                                printf("ERROR:Error in class declaration.No class/interface of name %s found\n",(yyvsp[(4) - (4)].attr)->ref);
			}
                        else
                                *(cl.extends)=listOfClasses[i];
                        cl.modifiers.push_back(mnative);
                        
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{currenterpointer--;printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);}
        }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 893 "parser.ypp"
    {currenter=NULL;}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 896 "parser.ypp"
    {
			int i;
			for(i=0;i<listOfModifiers.size();i++) {if(!(listOfModifiers[i]==mpublic || listOfModifiers[i]==mprivate ||listOfModifiers[i]==mprotected || listOfModifiers[i]==mabstract || listOfModifiers[i]==mstatic ||listOfModifiers[i]==mfinal || listOfModifiers[i]==mstrictfp )) 
                                printf("ERROR:Incorrect modifier at line %d\n",yylineno);}
			currenterpointer++;
                        createtable(currenter);
                        ClassInterface cl;
                        strcpy(cl.name,(yyvsp[(3) - (3)].str));
                        cl.table=(ST *)malloc(sizeof(ST));
                        cl.table=currenter;
                        cl.extends=(ClassInterface *)malloc(sizeof(ClassInterface));
                        cl.implements=(ClassInterface *)malloc(sizeof(ClassInterface));
			cl.implements=NULL;				
			cl.extends=NULL;
                        cl.modifiers=listOfModifiers;
                        listOfModifiers.clear();
                        
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{currenterpointer--;printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);}
        }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 922 "parser.ypp"
    {currenter=NULL;}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 925 "parser.ypp"
    {
			currenterpointer++;
                        createtable(currenter);
                        ClassInterface cl;
                        strcpy(cl.name,(yyvsp[(2) - (2)].str));
                        cl.table=(ST *)malloc(sizeof(ST));
                        cl.table=currenter;
                        cl.modifiers=listOfModifiers;
                        cl.extends=(ClassInterface *)malloc(sizeof(ClassInterface));
                        cl.implements=(ClassInterface *)malloc(sizeof(ClassInterface));
			cl.implements=NULL;				
			cl.extends=NULL;
			cl.modifiers.push_back(mnative);
			int i;
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{currenterpointer--;printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);}
        }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 948 "parser.ypp"
    {currenter=NULL;}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 957 "parser.ypp"
    {	int i;
		//printf("%d\n",$2->modifier[0]);	
		for(i=0;i<listOfModifiers.size();i++) {
			if((yyvsp[(2) - (2)].attr)->modifier[0]==listOfModifiers[i]) break;
		} 
		if(i==listOfModifiers.size()) 
			listOfModifiers.push_back((yyvsp[(2) - (2)].attr)->modifier[0]) ;
		else 
			printf("ERROR:Erroneous modifier declaration at line %d\n",yylineno);
		publicFound=false;
	}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 970 "parser.ypp"
    {	
		//printf("%d\n",$1->modifier[0]);
		int i;
		for(i=0;i<listOfModifiers.size();i++) {
			if((yyvsp[(1) - (1)].attr)->modifier[0]==listOfModifiers[i]) break;}
		if(i==listOfModifiers.size()) 
			listOfModifiers.push_back((yyvsp[(1) - (1)].attr)->modifier[0]);
		else 
			printf("ERROR:Erroneous modifier declaration at line %d\n",yylineno);
		publicFound=false;
	}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 984 "parser.ypp"
    {(yyval.attr)=new struct attribute;
	if(listOfModifiers.size()==0 && !publicFound) 
		publicFound=true; 
	else if(listOfModifiers.size()>0 && publicFound) 
		printf("ERROR:Error at line %d,public modifier already exists\n",yylineno);
		(yyval.attr)->modifier.push_back(mpublic);
	}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 992 "parser.ypp"
    { (yyval.attr)=new struct attribute;(yyval.attr)->modifier.push_back(mprivate); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 994 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->modifier.push_back(mprotected); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 996 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->modifier.push_back(mabstract); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 998 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->modifier.push_back(mstatic); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1000 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->modifier.push_back(mfinal); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1002 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->modifier.push_back(mnative); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1004 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->modifier.push_back(msynchronized); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1006 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->modifier.push_back(mtransient); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1008 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->modifier.push_back(mvolatile); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1010 "parser.ypp"
    {  (yyval.attr)=new struct attribute;(yyval.attr)->modifier.push_back(mstrictfp); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1014 "parser.ypp"
    { (yyval.attr)=(yyvsp[(2) - (2)].attr); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1018 "parser.ypp"
    { (yyval.attr)=(yyvsp[(1) - (1)].attr); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1059 "parser.ypp"
    {
                for(int i=0;i<listOfModifiers.size();i++)
                {if(!(listOfModifiers[i]==mpublic || listOfModifiers[i]==mprivate || listOfModifiers[i]==mprotected \
		|| listOfModifiers[i]==mstatic || listOfModifiers[i]==mtransient ||listOfModifiers[i]==mfinal|| listOfModifiers[i]==mvolatile) ) printf("Incorrect modifier at line %d\n",yylineno);}   
		listOfModifiers.clear();
	}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1070 "parser.ypp"
    {printf("ERROR:missing identifiers at line %d\n",yylineno);}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1081 "parser.ypp"
    {
		if(listOfModifiers.size()==0)
			typeinfo->modifier.push_back(mnative);
		else
			typeinfo->modifier=listOfModifiers;
		if(findentry(currenter,id))	
			printf("ERROR:redefinition of variable %s at line %d\n",id,yylineno); 
		else
		{
			printf("installing %s in the symbol table %p\n",id,currenter);
			int offset;
			if(find(typeinfo->modifier.begin(),typeinfo->modifier.end(),mstatic)==typeinfo->modifier.end())
			{
				offset=-num_var*4;		//currently all types have fixed sizes
				num_var++;
			}
			else
			{
				if((typeinfo->type!=tfloat && typeinfo->type!=tdouble) || ((yyvsp[(1) - (1)].attr)->dimension+typeinfo->dimension!=0))
				{
					offset=50+next_saved_reg;
					next_saved_reg=(next_saved_reg+1)%7;
				}
				else
				{
					offset=60+next_saved_float;
					next_saved_float=(next_saved_float+1)%30>=20?(next_saved_float+1)%30:20;
				}
			}
			if(typeinfo->token==1 || typeinfo->token==3)
				insertentry(currenter,id,typeinfo->modifier,typeinfo->type,NULL,(yyvsp[(1) - (1)].attr)->dimension+typeinfo->dimension,offset);
			else if(typeinfo->token==2 || typeinfo->token==4)
				insertentry(currenter,id,typeinfo->modifier,tnone,typeinfo->ref,typeinfo->dimension+(yyvsp[(1) - (1)].attr)->dimension,offset);
		}
	}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 1118 "parser.ypp"
    {
		if(listOfModifiers.size()==0)
			typeinfo->modifier.push_back(mnative);
		else
			typeinfo->modifier=listOfModifiers;
		if(typeinfo->token!=(yyvsp[(3) - (3)].attr)->token && (yyvsp[(1) - (3)].attr)->token!=(yyvsp[(3) - (3)].attr)->token)
			printf("ERROR:Type mismatch at line %d\n",yylineno);
		else if((typeinfo->dimension+(yyvsp[(1) - (3)].attr)->dimension) !=(yyvsp[(3) - (3)].attr)->dimension)
			printf("ERROR:Type mismatch at lien %d\n",yylineno);
		else if(typeinfo->token==1 || typeinfo->token==3)
		{
			//printf("%d %d\n",typeinfo->type,$3->type);
			if(typeinfo->type==tdouble && ((yyvsp[(3) - (3)].attr)->type==tstring || (yyvsp[(3) - (3)].attr)->type==tboolean || (yyvsp[(3) - (3)].attr)->type==tnull || (yyvsp[(3) - (3)].attr)->type==tvoid))
				printf("ERROR:Type mismatch at line %d\n",yylineno);
			else if(typeinfo->type==tfloat && ((yyvsp[(3) - (3)].attr)->type==tdouble || (yyvsp[(3) - (3)].attr)->type==tstring || (yyvsp[(3) - (3)].attr)->type==tboolean || (yyvsp[(3) - (3)].attr)->type==tnull || (yyvsp[(3) - (3)].attr)->type==tvoid)) 
				printf("ERROR:Type mismatch at line %d\n",yylineno);
			else if(typeinfo->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tfloat || (yyvsp[(3) - (3)].attr)->type==tdouble || (yyvsp[(3) - (3)].attr)->type==tstring || (yyvsp[(3) - (3)].attr)->type==tboolean || (yyvsp[(3) - (3)].attr)->type==tnull || (yyvsp[(3) - (3)].attr)->type==tvoid))
				printf("ERROR:Type mismatch at lien %d\n",yylineno);
			else if(typeinfo->type==tint && ((yyvsp[(3) - (3)].attr)->type!=tint && (yyvsp[(3) - (3)].attr)->type!=tbyte && (yyvsp[(3) - (3)].attr)->type!=tshort && (yyvsp[(3) - (3)].attr)->type!=tchar))
				printf("ERROR:Type mismatch at line %d\n",yylineno);
			else if(typeinfo->type==tshort && ((yyvsp[(3) - (3)].attr)->type!=tbyte && (yyvsp[(3) - (3)].attr)->type!=tshort))
                                printf("ERROR:Type mismatch at line %d\n",yylineno);
			else if(typeinfo->type==tbyte && (yyvsp[(3) - (3)].attr)->type!=tbyte)
                                printf("ERROR:Type mismatch at line %d\n",yylineno);
			else if(typeinfo->type==tchar && (yyvsp[(3) - (3)].attr)->type!=tchar)
                                printf("ERROR:Type mismatch at line %d\n",yylineno);
			else if(typeinfo->type==tboolean && (yyvsp[(3) - (3)].attr)->type!=tboolean)	
				printf("ERROR:Type mismatch at line %d\n",yylineno);
			else
			{
				if(findentry(currenter,id))	
					printf("ERROR:redefinition of variable %s at line %d\n",id,yylineno); 
				else
				{
					int offset;
					if(find(typeinfo->modifier.begin(),typeinfo->modifier.end(),mstatic)==typeinfo->modifier.end())
					{
						offset=-num_var*4;		//currently all types have fixed sizes
						num_var++;
					}
					else
					{
						if(typeinfo->type!=tfloat && typeinfo->type!=tdouble)
						{
							offset=50+next_saved_reg;
							next_saved_reg=(next_saved_reg+1)%7;
						}
						else
						{
							offset=60+next_saved_float;
							next_saved_float=(next_saved_float+1)%30>=20?(next_saved_float+1)%30:20;
						}			
					}
					printf("installing %s in the symbol table %p\n",id,currenter);
					insertentry(currenter,id,typeinfo->modifier,typeinfo->type,NULL,typeinfo->dimension+(yyvsp[(1) - (3)].attr)->dimension,offset);
					char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
					if(typeinfo->dimension+(yyvsp[(1) - (3)].attr)->dimension>0 && !jump_found)
					{
						fprintf(fcg,"li $a0,%d\n",(variables.size()+1)*4);
						fprintf(fcg,"li $v0,9\n");
						fprintf(fcg,"syscall\n");
						if(Ref(val1)==memory)
							fprintf(fcg,"sw $v0,%s\n",val1);
						else
							fprintf(fcg,"move $v0,%s\n",val1);
					}
					else if(typeinfo->dimension+(yyvsp[(1) - (3)].attr)->dimension>0 && jump_found)
					{
						fprintf(fcg,"lw $t0,%s\n",Address((yyvsp[(3) - (3)].attr)->contains));
						if(Ref(val1)==memory)
							fprintf(fcg,"sw $t0,%s\n",val1);
						else
							fprintf(fcg,"move $t0,%s\n",val1);
					}	
					int i;
					//printf("%s %d %d\n",$1->contains,variables.size(),jump_found);
					for(i=0;i<variables.size() && !jump_found;i++)
					{
						if(typeinfo->dimension+(yyvsp[(1) - (3)].attr)->dimension>0)
						{
							val1=Address((yyvsp[(1) - (3)].attr)->contains);
							if(Ref(val1)==memory)
								fprintf(fcg,"\nlw $t0,%s\n",val1);
							else
								fprintf(fcg,"\nmove $t0,%s\n",val1);
							fprintf(fcg,"li $t1,%d\n",(i+1)*4);
							fprintf(fcg,"addu $t3,$t0,$t1\n");
							strcpy(val1,"0($t3)");
						}
						char *val2=Address(variables[i]->contains);
						enum refType t1=Ref(val1);
						enum refType t2=Ref(val2);
						if(t1==memory)
						{
							if(t2==constant)
							{
								if(variables[i]->type!=tdouble && variables[i]->type!=tfloat)
								{
									fprintf(fcg,"li $t0,%s\n",val2);
									if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat && (yyvsp[(1) - (3)].attr)->type!=tchar)
										fprintf(fcg,"sw $t0,%s\n",val1);
									else if((yyvsp[(1) - (3)].attr)->type==tchar)
										fprintf(fcg,"sb $t0,%s\n",val1);
									else
									{	
										fprintf(fcg,"mtc1 $t0,$f1\n");
										fprintf(fcg,"cvt.s.w $f1,$f1\n");
										fprintf(fcg,"s.s $f1,%s\n",val1);
									}
								}
								else
								{
									fprintf(fcg,"li.s $f0,%s\n",val2);
									fprintf(fcg,"s.s $f0,%s\n",val1);
								}
							}
							else if(t2==memory)
							{
								if(variables[i]->type!=tdouble && variables[i]->type!=tfloat)
								{
									fprintf(fcg,"lw $t0,%s\n",val2);
									if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat && (yyvsp[(1) - (3)].attr)->type!=tchar)
										fprintf(fcg,"sw $t0,%s\n",val1);
									else if((yyvsp[(1) - (3)].attr)->type==tchar)
										fprintf(fcg,"sb $t0,%s\n",val1);
									else
									{	
										fprintf(fcg,"mtc1 $t0,$f1\n");
										fprintf(fcg,"cvt.s.w $f1,$f1\n");
										fprintf(fcg,"s.s $f1,%s\n",val1);
									}
								}
								else
								{
									fprintf(fcg,"l.s $f0,%s\n",val2);
									fprintf(fcg,"s.s $f0,%s\n",val1);
								}
							}
							else
							{
								if(variables[i]->type!=tdouble && variables[i]->type!=tfloat)
								{
									if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat && (yyvsp[(1) - (3)].attr)->type!=tchar)
										fprintf(fcg,"sw %s,%s\n",val2,val1);
									else if((yyvsp[(1) - (3)].attr)->type==tchar)
										fprintf(fcg,"sb %s,%s\n",val2,val1);
									else
									{	
										fprintf(fcg,"move $t0,%s\n",val2);
										fprintf(fcg,"mtc1 $t0,$f1\n");
										fprintf(fcg,"cvt.s.w $f1,$f1\n");
										fprintf(fcg,"s.s $f1,%s\n",val1);
									}
								}
								else
									fprintf(fcg,"s.s %s,%s\n",val2,val1);
							}
						}
						else if(t1==reg)
						{
							if(t2==constant)
							{
								if(variables[i]->type!=tdouble && variables[i]->type!=tfloat)
								{
									if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
										fprintf(fcg,"li %s,%s\n",val1,val2);
									else
									{	
										fprintf(fcg,"li $t0,%s\n",val2);
										fprintf(fcg,"mtc1 $t0,$f1\n");
										fprintf(fcg,"cvt.s.w $f1,$f1\n");
										fprintf(fcg,"mov.s %s\n,$f1",val1);
									}
								}
								else
									fprintf(fcg,"li.s %s,%s\n",val1,val2);
							}
							else if(t2==memory)
							{
								if(variables[i]->type!=tdouble && variables[i]->type!=tfloat)
								{
									fprintf(fcg,"lw $t0,%s\n",val2);
									if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
										fprintf(fcg,"move %s,$t0\n",val1);
									else
									{	
										fprintf(fcg,"mtc1 $t0,$f1\n");
										fprintf(fcg,"cvt.s.w $f1,$f1\n");
										fprintf(fcg,"mov.s %s,$f1\n",val1);
									}
								}
								else
								{
									fprintf(fcg,"l.s $f0,%s\n",val2);
									fprintf(fcg,"mov.s %s,$f0\n",val1);
								}
							}
							else
							{
								if(variables[i]->type!=tdouble && variables[i]->type!=tfloat)
								{
									if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
										fprintf(fcg,"move %s,%s\n",val1,val2);
									else
									{	
										fprintf(fcg,"move $t0,%s\n",val1);
										fprintf(fcg,"mtc1 $t0,$f1\n");
										fprintf(fcg,"cvt.s.w $f1,$f1\n");
										fprintf(fcg,"mov.s %s,$f1\n",val1);
									}
								}
								else
									fprintf(fcg,"mov.s %s,%s\n",val1,val2);
							}
						}
					}
					jump_found=false;
					variables.clear();
				}
                	}
		}
		else if(typeinfo->token==2 || typeinfo->token==4)
		{
			if(findentry(currenter,id))
				printf("ERROR:redefinition of variable %s at line %d\n",id,yylineno);
			else
			{
				bool found=false;
				if(!strcmp(typeinfo->ref,(yyvsp[(3) - (3)].attr)->ref))
				{
					int offset=-num_var*4;
					num_var++;
					insertentry(currenter,id,typeinfo->modifier,tnone,typeinfo->ref,typeinfo->dimension+(yyvsp[(1) - (3)].attr)->dimension,offset);
					char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
					//if($1->dimension+typeinfo->dimension==0)
					//{
						if(Ref(Address((yyvsp[(3) - (3)].attr)->contains))==memory)
							fprintf(fcg,"lw $t0,%s\n",Address((yyvsp[(3) - (3)].attr)->contains));
						else
							fprintf(fcg,"move $t0,%s\n",Address((yyvsp[(3) - (3)].attr)->contains));
						if(Ref(val1)==memory)
							fprintf(fcg,"sw $t0,%s\n",val1);
						else
							fprintf(fcg,"move %s\n,$t0",val1);
					//}
				}
				else
					printf("ERROR:Type mismatch at line %d\n",yylineno);
			}
			jump_found=false;
		}		
		else
			printf("ERROR:Type mismatch at line %d\n",yylineno);
	}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 1373 "parser.ypp"
    {printf("ERROR:missing expression after = at line %d\n",yylineno);}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1378 "parser.ypp"
    {
		(yyval.attr) = new struct attribute;
		if(typeinfo->token==1 || typeinfo->token==3)
		{
			(yyval.attr)->type=typeinfo->type;
			(yyval.attr)->token=3;
		}
		else
		{
			strcpy((yyval.attr)->ref,typeinfo->ref);
			(yyval.attr)->token=4;
		}
		(yyval.attr)->dimension=(yyvsp[(1) - (3)].attr)->dimension+1;
		strcpy((yyval.attr)->contains,(yyvsp[(1) - (3)].attr)->contains);
	}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1394 "parser.ypp"
    {(yyval.attr)=new struct attribute;(yyval.attr)->dimension=0;printf("ERROR:missing ] at line %d\n",yylineno);}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1397 "parser.ypp"
    {	
		(yyval.attr) = new struct attribute;
		(yyval.attr)->dimension=0;
		(yyval.attr)->token=typeinfo->token;
		if(typeinfo->token==2 || typeinfo->token==4)
			strcpy((yyval.attr)->ref,typeinfo->ref);
		else
			(yyval.attr)->type=typeinfo->type;
		strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].str));
		strcpy(id,(yyvsp[(1) - (1)].str));
	}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1412 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		if((yyvsp[(1) - (1)].attr)->token==1 || (yyvsp[(1) - (1)].attr)->token==3)
		{
			(yyval.attr)->type=(yyvsp[(1) - (1)].attr)->type;
			(yyval.attr)->dimension=(yyvsp[(1) - (1)].attr)->dimension;
			(yyval.attr)->token=(yyvsp[(1) - (1)].attr)->token;
			strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].attr)->contains);
			variables.push_back((yyval.attr));
		}
		else
		{
			strcpy((yyval.attr)->ref,(yyvsp[(1) - (1)].attr)->ref);
                        (yyval.attr)->dimension=(yyvsp[(1) - (1)].attr)->dimension;
                        (yyval.attr)->token=(yyvsp[(1) - (1)].attr)->token;
			strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].attr)->contains);
		}
	}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1432 "parser.ypp"
    {	
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
                if((yyvsp[(1) - (1)].attr)->token==3)
                {
                        (yyval.attr)->type=(yyvsp[(1) - (1)].attr)->type;
                        (yyval.attr)->dimension=(yyvsp[(1) - (1)].attr)->dimension;
                        (yyval.attr)->token=(yyvsp[(1) - (1)].attr)->token;
                }
                else if((yyvsp[(1) - (1)].attr)->token==4)
  		{
                        strcpy((yyval.attr)->ref,(yyvsp[(1) - (1)].attr)->ref);
                        (yyval.attr)->dimension=(yyvsp[(1) - (1)].attr)->dimension;
                        (yyval.attr)->token=(yyvsp[(1) - (1)].attr)->token;
                }
		else
			(yyval.attr)->type=tnone;
        }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1452 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tchar;(yyval.attr)->dimension=1;(yyval.attr)->token=3;}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1455 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		if((yyvsp[(2) - (4)].attr)->token==1 || (yyvsp[(2) - (4)].attr)->token==3)
		{
			(yyval.attr)->token=3;
			(yyval.attr)->type=(yyvsp[(2) - (4)].attr)->type;
		}
		else
		{
			(yyval.attr)->token=4;
			strcpy((yyval.attr)->ref,(yyvsp[(2) - (4)].attr)->ref);
		}
		(yyval.attr)->dimension=1+(yyvsp[(2) - (4)].attr)->dimension;
	}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1469 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tchar;(yyval.attr)->dimension=1;(yyval.attr)->token=3;}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 1472 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		if((yyvsp[(2) - (3)].attr)->token==1 || (yyvsp[(2) - (3)].attr)->token==3)
		{
			(yyval.attr)->token=3;
			(yyval.attr)->type=(yyvsp[(2) - (3)].attr)->type;
		}
		else
		{
			(yyval.attr)->token=4;
			strcpy((yyval.attr)->ref,(yyvsp[(2) - (3)].attr)->ref);
		}
		(yyval.attr)->dimension=1+(yyvsp[(2) - (3)].attr)->dimension;
        }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 1486 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 1488 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing } on line %d\n",yylineno);}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 1491 "parser.ypp"
    { (yyval.attr)=(yyvsp[(1) - (1)].attr); }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 1494 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		if(!((yyvsp[(1) - (3)].attr)->token==2 || (yyvsp[(3) - (3)].attr)->token==2 || (yyvsp[(1) - (3)].attr)->token==4 || (yyvsp[(3) - (3)].attr)->token==4))
		{
			//printf("%d %d\n",$1->token,$3->token);
			(yyval.attr)->token=(yyvsp[(1) - (3)].attr)->token;
			(yyval.attr)->dimension=(yyvsp[(1) - (3)].attr)->dimension;
			if((yyvsp[(1) - (3)].attr)->dimension!=(yyvsp[(3) - (3)].attr)->dimension)
			{
				(yyval.attr)->type=tnone;
				printf("ERROR:array dimension mismatch at line %d\n",yylineno);
			}
			else if((yyvsp[(1) - (3)].attr)->type==tdouble && (yyvsp[(3) - (3)].attr)->type!=tstring && \
			(yyvsp[(3) - (3)].attr)->type!=tboolean && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tnone)
				(yyval.attr)->type=tdouble;
			else if((yyvsp[(1) - (3)].attr)->type==tfloat && (yyvsp[(3) - (3)].attr)->type!=tdouble \
			&& (yyvsp[(3) - (3)].attr)->type!=tstring && (yyvsp[(3) - (3)].attr)->type!=tboolean && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tnone)
				(yyval.attr)->type=tfloat;
			else if((yyvsp[(1) - (3)].attr)->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tlong || (yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
                        	(yyval.attr)->type=tlong;
                	else if((yyvsp[(1) - (3)].attr)->type==tint && ((yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
                        	(yyval.attr)->type=tint;
                	else if((yyvsp[(1) - (3)].attr)->type==tshort && ((yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                        	(yyval.attr)->type=tshort;
                	else if((yyvsp[(1) - (3)].attr)->type==tbyte && (yyvsp[(3) - (3)].attr)->type==tbyte)
                        	(yyval.attr)->type=tbyte;
                	else if((yyvsp[(1) - (3)].attr)->type==tchar && (yyvsp[(3) - (3)].attr)->type==tchar)
                        	(yyval.attr)->type=tchar;	
			else if((yyvsp[(3) - (3)].attr)->type==tdouble && (yyvsp[(1) - (3)].attr)->type!=tstring && \
			(yyvsp[(1) - (3)].attr)->type!=tboolean && (yyvsp[(1) - (3)].attr)->type!=tnull && (yyvsp[(1) - (3)].attr)->type!=tvoid && (yyvsp[(1) - (3)].attr)->type!=tnone)
				(yyval.attr)->type=tdouble;
			else if((yyvsp[(3) - (3)].attr)->type==tfloat && (yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tstring && (yyvsp[(1) - (3)].attr)->type!=tboolean \
			&& (yyvsp[(1) - (3)].attr)->type!=tnull && (yyvsp[(1) - (3)].attr)->type!=tvoid && (yyvsp[(1) - (3)].attr)->type!=tnone) 
				(yyval.attr)->type=tfloat;
			else if((yyvsp[(3) - (3)].attr)->type==tlong && ((yyvsp[(1) - (3)].attr)->type==tlong || \
			(yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                        	(yyval.attr)->type=tlong;
                	else if((yyvsp[(3) - (3)].attr)->type==tint && ((yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                        	(yyval.attr)->type=tint;
                	else if((yyvsp[(3) - (3)].attr)->type==tshort && ((yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort))
                        	(yyval.attr)->type=tshort;
                	else if((yyvsp[(3) - (3)].attr)->type==tbyte && (yyvsp[(1) - (3)].attr)->type==tbyte)
                        	(yyval.attr)->type=tbyte;
                	else if((yyvsp[(3) - (3)].attr)->type==tchar && (yyvsp[(1) - (3)].attr)->type==tchar)
                        	(yyval.attr)->type=tchar;
			else if((yyvsp[(1) - (3)].attr)->type==tboolean && (yyvsp[(3) - (3)].attr)->type==tboolean)
				(yyval.attr)->type=tboolean;
                	else
                	{
                        	printf("ERROR:Incorrect initialisation line %d\n",yylineno);
                        	(yyval.attr)->type=tnone;
                	}
		}
		else if(!((yyvsp[(1) - (3)].attr)->token==1 || (yyvsp[(3) - (3)].attr)->token==1 || (yyvsp[(1) - (3)].attr)->token==3 || (yyvsp[(3) - (3)].attr)->token==3))
		{
			(yyval.attr)->token=(yyvsp[(1) - (3)].attr)->token;
			(yyval.attr)->dimension=(yyvsp[(1) - (3)].attr)->dimension;
			if((yyvsp[(1) - (3)].attr)->dimension!=(yyvsp[(3) - (3)].attr)->dimension)
			{
				(yyval.attr)->type=tnone;
				printf("ERROR:array dimension mismatch at line %d\n",yylineno);
			}
			else if(strcmp((yyvsp[(1) - (3)].attr)->ref,(yyvsp[(3) - (3)].attr)->ref)!=0)
			{
				printf("ERROR:Incorrect initialisation at line %d\n",yylineno);
				(yyval.attr)->type=tnone;
			}
			else
				strcpy((yyval.attr)->ref,(yyvsp[(1) - (3)].attr)->ref);
		}
		else
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Incorrect initialisation at line %d\n",yylineno);
		}
	}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 1573 "parser.ypp"
    {	
		int i=0;
		bool found=false;
		vector<methodConstructor *> temp=listOfClasses[currenterpointer].listOfMethods;
		for(;i<temp.size();i++)
		{
			if(!strcmp(temp[i]->name,m->name))
			{
				if(temp[i]->param.size()==m->param.size())
				{
					int j;
					for(j=0;j<temp[i]->param.size();j++)
					{
						if(temp[i]->param[j]->token!=m->param[j]->token)
							break;
						else if(temp[i]->param[j]->dimension!=m->param[j]->dimension)
							break;
						else if(temp[i]->param[j]->token==1 || temp[i]->param[j]->token==3)
						{
							if(temp[i]->param[j]->type!=m->param[j]->type)
								break;
						}
						else if(strcmp(temp[i]->param[j]->ref,m->param[j]->ref))
							break;
					}
					if(j==temp[i]->param.size())
					{
						found=true;
						break;
					}
				}
			}
		}
		if(!found)
		{
			listOfClasses[currenterpointer].listOfMethods.push_back(m);printf("function %s installed\n",m->name);
			if(!strcmp(m->name,"main"))
				fprintf(fcg,"main:\n");
			else
				fprintf(fcg,"%s%d:\n",m->name,method_count++);
			fprintf(fcg,"subu $sp,$sp,352\n");//variable method length??
			fprintf(fcg,"sw $ra,40($sp)\n");
			fprintf(fcg,"sw $fp,36($sp)\n");
			fprintf(fcg,"addu $fp,$sp,300\n");
			fprintf(fcg,"s.s $f12,32($sp)\n");
			fprintf(fcg,"s.s $f13,28($sp)\n");
			fprintf(fcg,"s.s $f14,24($sp)\n");
			fprintf(fcg,"sw $a0,20($sp)\n");
			fprintf(fcg,"sw $a1,16($sp)\n");
			fprintf(fcg,"sw $a2,12($sp)\n");
			fprintf(fcg,"sw $a3,8($sp)\n\n");			
		}
		else
			printf("ERROR line %d:function  already installled\n",yylineno);
	}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 1628 "parser.ypp"
    {	
		removetable(currenter);
		if(returninfo->type!=tvoid && !returnFound)
			printf("ERROR:expected return statement\n");
		if(strcmp(m->name,"main"))
		{
			fprintf(fcg,"%s%dend:\n",m->name,method_count-1);
			fprintf(fcg,"lw $ra,40($sp)\n");
			fprintf(fcg,"lw $fp,36($sp)\n");
			fprintf(fcg,"l.s $f12,32($sp)\n");
			fprintf(fcg,"l.s $f13,28($sp)\n");
			fprintf(fcg,"l.s $f14,24($sp)\n");
			fprintf(fcg,"lw $a0,20($sp)\n");
			fprintf(fcg,"lw $a1,16($sp)\n");
			fprintf(fcg,"lw $a2,12($sp)\n");
			fprintf(fcg,"lw $a3,8($sp)\n");	
			fprintf(fcg,"addu $sp,$sp,352\n");
			fprintf(fcg,"jr $ra\n\n");
			num_var=3;
		}	
		else
		{
			fprintf(fcg,"\nmainend:\n");
			fprintf(fcg,"li $v0,10\n");
			fprintf(fcg,"syscall\n");
			num_var=3;
		}
		returnFound=false;
	}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 1660 "parser.ypp"
    {
		createtable(currenter);	
		m = (struct methodConstructor *)malloc(sizeof(methodConstructor));
		returninfo=(struct attribute *)malloc(sizeof(struct attribute));
		returninfo->type=tvoid;
		returninfo->modifier=listOfModifiers;
		strcpy(m->name,id);
		m->number=method_count;
                m->modifier=listOfModifiers;
		listOfModifiers.clear();
                m->type=tvoid;
		m->token=1;
		returninfo->token=1;
		returninfo->dimension=0;
		m->param=param;
		int i,nonfloat=0,fl=0;
		for(i=0;i<param.size();i++)
		{
			if(findentry(currenter,param[i]->value))	
				printf("ERROR:redefinition of variable %s at line %d\n",param[i]->value,yylineno);
			else
			{
				if(param[i]->token==1 || param[i]->token==3)
				{
					if((param[i]->type==tfloat || param[i]->type==tdouble) && param[i]->token==1)
						insertentry(currenter,param[i]->value,param[i]->modifier,param[i]->type,NULL,param[i]->dimension,105+fl++);
					else
						insertentry(currenter,param[i]->value,param[i]->modifier,param[i]->type,NULL,param[i]->dimension,100+nonfloat++);
				}
				else if(param[i]->token==2 || param[i]->token==4)
					insertentry(currenter,param[i]->value,param[i]->modifier,tnone,param[i]->ref,param[i]->dimension,100+nonfloat++);
			}
		}			
		param.clear();
	}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 1697 "parser.ypp"
    {	createtable(currenter);
		m = (struct methodConstructor *)malloc(sizeof(methodConstructor));
		returninfo=(struct attribute *)malloc(sizeof(struct attribute));
		returninfo->type=tvoid;
		returninfo->token=2;
		returninfo->dimension=0;
		strcpy(m->name,id);
		m->number=method_count;
                m->type=tvoid;
		m->token=1;
		m->modifier.push_back(mnative);
		m->param=param;
		int i,nonfloat=0,fl=0;
		for(i=0;i<param.size();i++)
		{
			if(findentry(currenter,param[i]->value))	
				printf("ERROR:redefinition of variable %s at line %d\n",id,yylineno); 
			else
			{
				printf("installing %s in the symbol table %p\n",param[i]->value,currenter);
				if(param[i]->token==1 || param[i]->token==3)
				{
					if((param[i]->type==tfloat || param[i]->type==tdouble) && param[i]->token==1)
						insertentry(currenter,param[i]->value,param[i]->modifier,param[i]->type,NULL,param[i]->dimension,105+fl++);
					else
						insertentry(currenter,param[i]->value,param[i]->modifier,param[i]->type,NULL,param[i]->dimension,100+nonfloat++);
				}
				else if(param[i]->token==2 || param[i]->token==4)
					insertentry(currenter,param[i]->value,param[i]->modifier,tnone,param[i]->ref,param[i]->dimension,100+i);
			}
		}			
		param.clear();
	}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 1732 "parser.ypp"
    {	createtable(currenter);
		m = (struct methodConstructor *)malloc(sizeof(methodConstructor));
		returninfo=(struct attribute *)malloc(sizeof(struct attribute));
		returninfo->modifier=listOfModifiers;
		strcpy(m->name,id);
		m->number=method_count;
                m->modifier=listOfModifiers;
		listOfModifiers.clear();
		returninfo->dimension=0;
                if((yyvsp[(2) - (3)].attr)->token==1 || (yyvsp[(2) - (3)].attr)->token==3)
		{
			returninfo->type=(yyvsp[(2) - (3)].attr)->type;
			returninfo->token=1;
                        m->type=(yyvsp[(2) - (3)].attr)->type;
			m->token=1;
		}
                else
		{
			strcpy(returninfo->ref,(yyvsp[(2) - (3)].attr)->ref);
                        strcpy(m->ref,(yyvsp[(2) - (3)].attr)->ref);
			m->token=2;
			returninfo->token=2;
		}
		m->param=param;
		int i,nonfl=0,fl=0;
		for(i=0;i<param.size();i++)
		{
			if(findentry(currenter,param[i]->value))	
				printf("ERROR:redefinition of variable %s at line %d\n",id,yylineno); 
			else
			{
				printf("installing %s in the symbol table %p\n",param[i]->value,currenter);
				if(param[i]->token==1 || param[i]->token==3)
				{
					if((param[i]->type==tfloat || param[i]->type==tdouble) && param[i]->token==1)
						insertentry(currenter,param[i]->value,param[i]->modifier,param[i]->type,NULL,param[i]->dimension,105+fl++);
					else
						insertentry(currenter,param[i]->value,param[i]->modifier,param[i]->type,NULL,param[i]->dimension,100+nonfl++);
				}
				else if(param[i]->token==2 || param[i]->token==4)
					insertentry(currenter,param[i]->value,param[i]->modifier,tnone,param[i]->ref,param[i]->dimension,100+nonfl++);
			}
		}			
		param.clear();
	}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1779 "parser.ypp"
    {	createtable(currenter);
		m = (struct methodConstructor *)malloc(sizeof(methodConstructor));
		returninfo=(struct attribute *)malloc(sizeof(struct attribute));
		strcpy(m->name,id);
		m->number=method_count;
		returninfo->dimension=0;
		m->modifier.push_back(mnative);
                if((yyvsp[(1) - (2)].attr)->token==1)
		{
			returninfo->type=(yyvsp[(1) - (2)].attr)->type;
			returninfo->token=1;
                        m->type=(yyvsp[(1) - (2)].attr)->type;
			m->token=1;
		}
                else
		{
			strcpy(returninfo->ref,(yyvsp[(1) - (2)].attr)->ref);
                        strcpy(m->ref,(yyvsp[(1) - (2)].attr)->ref);
			m->token=2;
			returninfo->token=2;
		}
		m->param=param;
		int i,nonfl=0,fl=0;
		for(i=0;i<param.size();i++)
		{
			if(findentry(currenter,param[i]->value))	
				printf("ERROR:redefinition of variable %s at line %d\n",id,yylineno); 
			else
			{
				printf("installing %s in the symbol table %p\n",param[i]->value,currenter);
				if(param[i]->token==1 || param[i]->token==3)
				{
					if((param[i]->type==tfloat || param[i]->type==tdouble) && param[i]->token==1)
						insertentry(currenter,param[i]->value,param[i]->modifier,param[i]->type,NULL,param[i]->dimension,105+fl++);
					else
						insertentry(currenter,param[i]->value,param[i]->modifier,param[i]->type,NULL,param[i]->dimension,100+nonfl++);
				}
				else if(param[i]->token==2 || param[i]->token==4)
					insertentry(currenter,param[i]->value,param[i]->modifier,tnone,param[i]->ref,param[i]->dimension,100+nonfl++);
			}
		}			
		param.clear();
	}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 1824 "parser.ypp"
    {strcpy(id,(yyvsp[(1) - (3)].str));}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1826 "parser.ypp"
    {strcpy(id,(yyvsp[(1) - (2)].str));}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1828 "parser.ypp"
    {printf("ERROR:Missing ( on line %d\n",yylineno);}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1830 "parser.ypp"
    {printf("ERROR:Missing ( on line %d\n",yylineno);}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1832 "parser.ypp"
    {printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1834 "parser.ypp"
    {printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1852 "parser.ypp"
    {
		struct attribute *temp=(struct attribute *)malloc(sizeof(struct attribute));
		temp->dimension=typeinfo->dimension+(yyvsp[(3) - (3)].attr)->dimension;
		temp->modifier.push_back(mfinal);
		strcpy(temp->value,id);
		if(typeinfo->token==1 || typeinfo->token==3)
		{
			temp->type=typeinfo->type;
			temp->token=temp->dimension>0?3:1;
		}
		else
		{
			strcpy(temp->ref,typeinfo->ref);
			temp->token=temp->dimension>0?4:2;
		}
		strcpy(temp->value,id);
		param.push_back(temp);
	}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1872 "parser.ypp"
    {
		struct attribute *temp=(struct attribute *)malloc(sizeof(struct attribute));
		temp->dimension=typeinfo->dimension+(yyvsp[(2) - (2)].attr)->dimension;
		temp->modifier.push_back(mpublic);
		strcpy(temp->value,id);
                if(typeinfo->token==1 || typeinfo->token==3)
		{
			temp->type=typeinfo->type;
			temp->token=temp->dimension>0?3:1;
		}
		else
		{
			strcpy(temp->ref,typeinfo->ref);
			temp->token=temp->dimension>0?4:2;
		}
		strcpy(temp->value,id);
                param.push_back(temp);
	}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1894 "parser.ypp"
    {
		struct attribute *temp=(struct attribute *)malloc(sizeof(struct attribute));
                temp->modifier.push_back(mfinal);
		temp->dimension=typeinfo->dimension+(yyvsp[(6) - (6)].attr)->dimension;
		strcpy(temp->value,id);
                if(typeinfo->token==1 || typeinfo->token==3)
		{
			temp->type=typeinfo->type;
			temp->token=temp->dimension>0?3:1;
		}
		else
		{
			strcpy(temp->ref,typeinfo->ref);
			temp->token=temp->dimension>0?4:2;
		}
		strcpy(temp->value,id);
                param.push_back(temp);
	}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1914 "parser.ypp"
    {
		struct attribute *temp=(struct attribute *)malloc(sizeof(struct attribute));
		temp->modifier.push_back(mpublic);
		temp->dimension=typeinfo->dimension+(yyvsp[(5) - (5)].attr)->dimension;
		strcpy(temp->value,id);
                if(typeinfo->token==1 || typeinfo->token==3)
		{
			temp->type=typeinfo->type;
			temp->token=temp->dimension>0?3:1;
		}
		else
		{
			strcpy(temp->ref,typeinfo->ref);
			temp->token=temp->dimension>0?4:2;
		}
		strcpy(temp->value,id);
                param.push_back(temp);
	}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1942 "parser.ypp"
    {
		removetable(currenter);
		int i=0;
		bool found=false;
		returninfo->modifier=listOfModifiers;
		listOfModifiers.clear();
		vector<methodConstructor *> temp=listOfClasses[currenterpointer].listOfMethods;
		for(;i<temp.size();i++)
		{
			if(!strcmp(temp[i]->name,m->name))
			{
				if(temp[i]->param.size()==m->param.size())
				{
					int j;
					for(j=0;j<temp[i]->param.size();j++)
					{
						if(temp[i]->param[j]->token!=m->param[j]->token)
							break;
						else if(temp[i]->param[j]->dimension!=m->param[j]->dimension)
							break;
						else if(temp[i]->param[j]->token==1 || temp[i]->param[j]->token==3)
						{
							if(temp[i]->param[j]->type!=m->param[j]->type)
								break;
						}
						else if(strcmp(temp[i]->param[j]->ref,m->param[j]->ref))
							break;
					}
					if(j==temp[i]->param.size())
					{
						found=true;
						break;
					}
				}
			}
		}
		if(!found)
		{
			listOfClasses[currenterpointer].listOfMethods.push_back(m);
			printf("constructor installed\n");
			fprintf(fcg,"%s%dend:\n",m->name,method_count-1);
			fprintf(fcg,"lw $ra,40($sp)\n");
			fprintf(fcg,"lw $fp,36($sp)\n");
			fprintf(fcg,"l.s $f12,32($sp)\n");
			fprintf(fcg,"l.s $f13,28($sp)\n");
			fprintf(fcg,"l.s $f14,24($sp)\n");
			fprintf(fcg,"lw $a0,20($sp)\n");
			fprintf(fcg,"lw $a1,16($sp)\n");
			fprintf(fcg,"lw $a2,12($sp)\n");
			fprintf(fcg,"lw $a3,8($sp)\n");	
			fprintf(fcg,"addu $sp,$sp,352\n");
			fprintf(fcg,"jr $ra\n\n");
			num_var=3;
		}
		else
			printf("ERROR line %d:constructor already installled\n",yylineno);
	}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 2001 "parser.ypp"
    {
		removetable(currenter);
		int i=0;
		returninfo->modifier.push_back(mnative);
		bool found=false;
		vector<methodConstructor *> temp=listOfClasses[currenterpointer].listOfMethods;
		for(;i<temp.size();i++)
		{
			if(!strcmp(temp[i]->name,m->name))
			{
				if(temp[i]->param.size()==m->param.size())
				{
					int j;
					for(j=0;j<temp[i]->param.size();j++)
					{
						if(temp[i]->param[j]->token!=m->param[j]->token)
							break;
						else if(temp[i]->param[j]->dimension!=m->param[j]->dimension)
							break;
						else if(temp[i]->param[j]->token==1 || temp[i]->param[j]->token==3)
						{
							if(temp[i]->param[j]->type!=m->param[j]->type)
								break;
						}
						else if(strcmp(temp[i]->param[j]->ref,m->param[j]->ref))
							break;
					}
					if(j==temp[i]->param.size())
					{
						found=true;
						break;
					}
				}
			}
		}
		if(!found)
		{
			listOfClasses[currenterpointer].listOfMethods.push_back(m);
			printf("constructor installed\n");
			fprintf(fcg,"%s%dend:\n",m->name,method_count-1);
			fprintf(fcg,"lw $ra,40($sp)\n");
			fprintf(fcg,"lw $fp,36($sp)\n");
			fprintf(fcg,"l.s $f12,32($sp)\n");
			fprintf(fcg,"l.s $f13,28($sp)\n");
			fprintf(fcg,"l.s $f14,24($sp)\n");
			fprintf(fcg,"lw $a0,20($sp)\n");
			fprintf(fcg,"lw $a1,16($sp)\n");
			fprintf(fcg,"lw $a2,12($sp)\n");
			fprintf(fcg,"lw $a3,8($sp)\n");	
			fprintf(fcg,"addu $sp,$sp,352\n");
			fprintf(fcg,"jr $ra\n\n");
			num_var=3;
		}
		else
			printf("ERROR line %d:constructor already installled\n",yylineno);
	}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 2058 "parser.ypp"
    {printf("ERROR:Error in constructor body,line %d\n",yylineno);}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 2062 "parser.ypp"
    {	createtable(currenter);
		m=(struct methodConstructor *)malloc(sizeof(methodConstructor));
		if(listOfModifiers.size()==0)
			m->modifier.push_back(mnative);
		else
			m->modifier=listOfModifiers;
		m->number=method_count;
		returninfo=(struct attribute *)malloc(sizeof(struct attribute));
		returninfo->type=tvoid;
		listOfModifiers.clear();
		ClassInterface *t=new ClassInterface;
		t=&listOfClasses[currenterpointer];
		while(t!=NULL)
		{
			if(!strcmp((yyvsp[(1) - (4)].str),t->name))
				break;
			else
				t=t->extends;
		}
		if(!t)
		{
			strcpy(m->name,"012");
			printf("ERROR:Incorrect constructor declaration at line %d\n",yylineno);
		}
		else
		{
			m->param=param;
			int i,nonfloat=0,fl=0;
			for(i=0;i<param.size();i++)
			{
				if(findentry(currenter,param[i]->value))	
					printf("ERROR:redefinition of variable %s at line %d\n",param[i]->value,yylineno);
				else
				{
					if(param[i]->token==1 || param[i]->token==3)
					{
						if((param[i]->type==tfloat || param[i]->type==tdouble) && param[i]->token==1)
							insertentry(currenter,param[i]->value,param[i]->modifier,param[i]->type,NULL,param[i]->dimension,105+fl++);
						else
							insertentry(currenter,param[i]->value,param[i]->modifier,param[i]->type,NULL,param[i]->dimension,100+nonfloat++);
					}
					else if(param[i]->token==2 || param[i]->token==4)
						insertentry(currenter,param[i]->value,param[i]->modifier,tnone,param[i]->ref,param[i]->dimension,100+nonfloat++);
				}
			}			
			strcpy(m->name,(yyvsp[(1) - (4)].str));
			fprintf(fcg,"%s%d:\n",m->name,method_count++);
			fprintf(fcg,"subu $sp,$sp,352\n");//variable method length??
			fprintf(fcg,"sw $ra,40($sp)\n");
			fprintf(fcg,"sw $fp,36($sp)\n");
			fprintf(fcg,"addu $fp,$sp,300\n");
			fprintf(fcg,"s.s $f12,32($sp)\n");
			fprintf(fcg,"s.s $f13,28($sp)\n");
			fprintf(fcg,"s.s $f14,24($sp)\n");
			fprintf(fcg,"sw $a0,20($sp)\n");
			fprintf(fcg,"sw $a1,16($sp)\n");
			fprintf(fcg,"sw $a2,12($sp)\n");
			fprintf(fcg,"sw $a3,8($sp)\n\n");			
		}
		param.clear();
	}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 2125 "parser.ypp"
    {	 createtable(currenter);
		 m=(struct methodConstructor *)malloc(sizeof(methodConstructor));
		 if(listOfModifiers.size()==0)
			m->modifier.push_back(mnative);
		 else
			m->modifier=listOfModifiers; 
		 m->number=method_count;
                 listOfModifiers.clear();
		 ClassInterface *t=new ClassInterface;
		 t=&listOfClasses[currenterpointer];
		 returninfo=(struct attribute *)malloc(sizeof(struct attribute));
		 returninfo->type=tvoid;
		 while(t!=NULL)
		 {
			if(!strcmp((yyvsp[(1) - (3)].str),t->name))
				break;
			else
				t=NULL;
		}
		if(!t)
		{
			strcpy(m->name,"012");
			printf("ERROR:Incorrect constructor declaration at line %d\n",yylineno);
		}
                else
		{
			strcpy(m->name,(yyvsp[(1) - (3)].str));
			fprintf(fcg,"%s%d:\n",m->name,method_count++);
			fprintf(fcg,"subu $sp,$sp,352\n");//variable method length??
			fprintf(fcg,"sw $ra,40($sp)\n");
			fprintf(fcg,"sw $fp,36($sp)\n");
			fprintf(fcg,"addu $fp,$sp,300\n");
			fprintf(fcg,"s.s $f12,32($sp)\n");
			fprintf(fcg,"s.s $f13,28($sp)\n");
			fprintf(fcg,"s.s $f14,24($sp)\n");
			fprintf(fcg,"sw $a0,20($sp)\n");
			fprintf(fcg,"sw $a1,16($sp)\n");
			fprintf(fcg,"sw $a2,12($sp)\n");
			fprintf(fcg,"sw $a3,8($sp)\n\n");
		}			
	}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 2167 "parser.ypp"
    {printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 2178 "parser.ypp"
    {
		struct ClassInterface *t=(struct ClassInterface *)malloc(sizeof(struct ClassInterface));
		struct methodConstructor *m1=new struct methodConstructor;
		t=&listOfClasses[currenterpointer];
		int p=currenterpointer;
		while(p>=0)
		{
			t=&listOfClasses[p];
			if(!strcmp(t->name,m->name))
				break;
			else
				p--;
		}
		bool found=false;
		int j;
		for(j=0;j<t->listOfMethods.size() && !found;j++)
		{
			if(strcmp(t->listOfMethods[j]->name,t->name)==0 && t->listOfMethods[j]->param.size()==param.size())
			{
				m1=t->listOfMethods[j];
				found=compare(t->listOfMethods[j]->param,param);	
			}
		}
		if(!found)
			printf("ERROR:Illegal constructor invocation at line %d\n",yylineno);
		else
		{
			int nonfloat=0,fl=12;
			for(j=0;j<param.size();j++)		//currently restrciting to only 4 parameters
			{
				char *val=Address(param[j]->contains);
				if(m1->param[j]->type==tfloat || m1->param[j]->type==tdouble)
				{
					if(param[j]->type!=tfloat && param[j]->type!=tdouble)
					{
						if(Ref(val)==constant)
							fprintf(fcg,"li $t0,%s\n",val);
						else if(Ref(val)==memory)
							fprintf(fcg,"lw $t0,%s\n",val);
						else
							fprintf(fcg,"move $t0,%s\n",val);
						fprintf(fcg,"mtc1 $t0,$f1\n");
						fprintf(fcg,"cvt.s.w $f1,$f1\n");
						fprintf(fcg,"mov.s $f%d,$f1\n",fl++);
					}
					else
					{
						if(Ref(val)==constant)
							fprintf(fcg,"li.s $f%d,%s\n",fl++,val);
						else if(Ref(val)==memory)
							fprintf(fcg,"l.s $f%d,%s\n",fl++,val);
						else
							fprintf(fcg,"mov.s $f%d,%s\n",fl++,val);
					}	
				}
				else
				{
					if(Ref(val)==constant)
						fprintf(fcg,"li $a%d,%s\n",nonfloat++,val);
					else if(Ref(val)==memory)
						fprintf(fcg,"lw $a%d,%s\n",nonfloat++,val);
					else
						fprintf(fcg,"move $a%d,%s\n",nonfloat++,val);
				}
			}
			fprintf(fcg,"\njal %s%d\n",m1->name,m1->number);
		}
		param.clear();
	}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 2249 "parser.ypp"
    {
		struct ClassInterface *t=(struct ClassInterface *)malloc(sizeof(struct ClassInterface));
		struct methodConstructor *m1=new struct methodConstructor;
		t=&listOfClasses[currenterpointer];
		int p=currenterpointer;
		while(p>=0)
		{
			t=&listOfClasses[p];
			if(!strcmp(t->name,m->name))
				break;
			else
				p--;
		}
		bool found=false;
		int j;
		for(int j=0;j<t->listOfMethods.size() && !found;j++)
		{
			if(strcmp(t->listOfMethods[j]->name,t->name)==0 && t->listOfMethods[j]->param.size()==0)
			{
				m1=t->listOfMethods[j];
				found=true;
			}
		}
		if(!found)
			printf("ERROR:Illegal constructor invocation at line %d\n",yylineno);
		else
			fprintf(fcg,"\njal %s%d\n",m1->name,m1->number);
	}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 2279 "parser.ypp"
    {
		struct ClassInterface *t=(struct ClassInterface *)malloc(sizeof(struct ClassInterface));
		struct methodConstructor *m1=new struct methodConstructor;
		t=&listOfClasses[currenterpointer];
		int p=currenterpointer;
		while(p>=0)
		{
			t=&listOfClasses[p];
			if(!strcmp(t->name,m->name))
				break;
			else
				p--;
		}
		if(t->extends==NULL)
			printf("ERROR:no super class found\n");
		t=t->extends;
		bool found=false;
		int j;
		if(t!=NULL)
		{
			for(j=0;j<t->listOfMethods.size() && !found;j++)
			{
				//printf("%d %d\n",param.size(),t->listOfMethods[j]->param.size());
				if(strcmp(t->listOfMethods[j]->name,t->name)==0 && t->listOfMethods[j]->param.size()==param.size())
				{
					m1=t->listOfMethods[j];
					found=compare(t->listOfMethods[j]->param,param);
				}
			}
		}
		if(!found)
			printf("ERROR:Illegal constructor invocation at line %d\n",yylineno);
		else
		{
			int nonfloat=0,fl=12;
			for(j=0;j<param.size();j++)		//currently restrciting to only 4 parameters
			{
				char *val=Address(param[j]->contains);
				if(m1->param[j]->type==tfloat || m1->param[j]->type==tdouble)
				{
					if(param[j]->type!=tfloat && param[j]->type!=tdouble)
					{
						if(Ref(val)==constant)
							fprintf(fcg,"li $t0,%s\n",val);
						else if(Ref(val)==memory)
							fprintf(fcg,"lw $t0,%s\n",val);
						else
							fprintf(fcg,"move $t0,%s\n",val);
						fprintf(fcg,"mtc1 $t0,$f1\n");
						fprintf(fcg,"cvt.s.w $f1,$f1\n");
						fprintf(fcg,"mov.s $f%d,$f1\n",fl++);
					}
					else
					{
						if(Ref(val)==constant)
							fprintf(fcg,"li.s $f%d,%s\n",fl++,val);
						else if(Ref(val)==memory)
							fprintf(fcg,"l.s $f%d,%s\n",fl++,val);
						else
							fprintf(fcg,"mov.s $f%d,%s\n",fl++,val);
						}	
				}
				else
				{
					if(Ref(val)==constant)
						fprintf(fcg,"li $a%d,%s\n",nonfloat++,val);
					else if(Ref(val)==memory)
						fprintf(fcg,"lw $a%d,%s\n",nonfloat++,val);
					else
						fprintf(fcg,"move $a%d,%s\n",nonfloat++,val);
				}
			}
			fprintf(fcg,"\njal %s%d\n",m1->name,m1->number);
		}
		param.clear();
	}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 2357 "parser.ypp"
    {
		struct ClassInterface *t=(struct ClassInterface *)malloc(sizeof(struct ClassInterface));
		struct methodConstructor *m1=new struct methodConstructor;
		t=&listOfClasses[currenterpointer];
		int p=currenterpointer;
		while(p>=0)
		{
			t=&listOfClasses[p];
			if(!strcmp(t->name,m->name))
				break;
			else
				p--;
		}
		if(t->extends==NULL)
			printf("ERROR:no super class found\n");
		t=t->extends;
		bool found=false;
		if(t!=NULL)
		{
			for(int j=0;j<t->listOfMethods.size() && !found;j++)
			{
				if(strcmp(t->listOfMethods[j]->name,t->name)==0 && t->listOfMethods[j]->param.size()==0)
				{
					m1=t->listOfMethods[j];
					found=true;
				}
			}
		}
		if(!found)
			printf("ERROR:Illegal constructor invocation at line %d\n",yylineno);
		else
			fprintf(fcg,"\njal %s%d\n",m1->name,m1->number);
	}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 2430 "parser.ypp"
    {printf("ERROR:Missing } on line %d\n",yylineno);}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 2432 "parser.ypp"
    {printf("ERROR:Missing } on line %d\n",yylineno);}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 2434 "parser.ypp"
    {printf("ERROR:Missing } on line %d\n",yylineno);}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 2436 "parser.ypp"
    {printf("ERROR:Missing } on line %d\n",yylineno);}
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 2438 "parser.ypp"
    {printf("ERROR:Missing } on line %d\n",yylineno);}
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 2440 "parser.ypp"
    {printf("ERROR:Missing } on line %d\n",yylineno);}
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 2442 "parser.ypp"
    {printf("ERROR:Missing } on line %d\n",yylineno);}
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 2444 "parser.ypp"
    {printf("ERROR:Missing } on line %d\n",yylineno);}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 2474 "parser.ypp"
    {
		 for(int i=0;i<listOfModifiers.size();i++) {
                 if(!(listOfModifiers[i]==mpublic||listOfModifiers[i]==mprivate||listOfModifiers[i]==mprotected||listOfModifiers[i]==mabstract||listOfModifiers[i]==mstatic||listOfModifiers[i]==mstrictfp ))
                                printf("ERROR:Incorrect modifier at line %d\n",yylineno);}
                 currenterpointer++;
                 createtable(currenter);
                 ClassInterface cl;
                 strcpy(cl.name,(yyvsp[(3) - (5)].str));
                 cl.table=(ST *)malloc(sizeof(ST));
                 cl.extends=(ClassInterface *)malloc(sizeof(ClassInterface));
		 cl.implements=NULL;
                 cl.table=currenter;
                 int i;
                 for(i=0;i<listOfClasses.size();i++)
                 {
                       if(strcmp(listOfClasses[i].name,(yyvsp[(5) - (5)].attr)->ref)==0)
                                        break;
                 }
                 if(i==listOfClasses.size())
		 {
			cl.extends=NULL;
                        printf("ERROR:Error in class declaration.No class/interface of name %s found\n",(yyvsp[(5) - (5)].attr)->ref);
		 }
                 else
                       *(cl.extends)=listOfClasses[i];
                 cl.modifiers=listOfModifiers;
                 listOfModifiers.clear();
                 
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{
				currenterpointer--;
				printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);
			}
	}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 2514 "parser.ypp"
    {currenter=NULL;}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 2517 "parser.ypp"
    {
		 currenterpointer++;
                 createtable(currenter);
                 ClassInterface cl;
                 strcpy(cl.name,(yyvsp[(2) - (4)].str));
                 cl.table=(ST *)malloc(sizeof(ST));
                 cl.table=currenter;
                 cl.extends=(ClassInterface *)malloc(sizeof(ClassInterface));
		 cl.implements=NULL;
                 int i;
                 for(i=0;i<listOfClasses.size();i++)
                 {
                       if(strcmp(listOfClasses[i].name,(yyvsp[(4) - (4)].attr)->ref)==0)
                                        break;
                 }
                 if(i==listOfClasses.size())
		 {
			cl.extends=NULL;
                        printf("ERROR:Error in class declaration.No class/interface of name %s found\n",(yyvsp[(4) - (4)].attr)->ref);
		 }
                 else
                                *(cl.extends)=listOfClasses[i];
                 cl.modifiers.push_back(mnative);
                 
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{
				currenterpointer--;
				printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);
			}
	}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 2553 "parser.ypp"
    {currenter=NULL;}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 2556 "parser.ypp"
    {
		for(int i=0;i<listOfModifiers.size();i++) {
                if(!(listOfModifiers[i]==mpublic||listOfModifiers[i]==mprivate||listOfModifiers[i]==mprotected||listOfModifiers[i]==mabstract||listOfModifiers[i]==mstatic||listOfModifiers[i]==mstrictfp ))
                                printf("ERROR:Incorrect modifier at line %d\n",yylineno);}
                 currenterpointer++;
                 createtable(currenter);
                 ClassInterface cl;
                 strcpy(cl.name,(yyvsp[(3) - (3)].str));
                 cl.table=(ST *)malloc(sizeof(ST));
                 cl.table=currenter;
                 cl.modifiers=listOfModifiers;
		 cl.extends=NULL;
		 cl.implements=NULL;
                 listOfModifiers.clear();
                 int i;
                for(i=0;i<listOfClasses.size();i++)
                {
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                }
		if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
		else
		{currenterpointer--;printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);}
	}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 2580 "parser.ypp"
    {currenter=NULL;}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 2583 "parser.ypp"
    {
                 currenterpointer++;
                 createtable(currenter);
                 ClassInterface cl;
                 strcpy(cl.name,(yyvsp[(2) - (2)].str));
                 cl.table=(ST *)malloc(sizeof(ST));
                 cl.table=currenter;
		 cl.implements=NULL;
		 cl.extends=NULL;
		 cl.modifiers.push_back(mnative);
                 int i;
                	for(i=0;i<listOfClasses.size();i++)
                	{
                                if(strcmp(listOfClasses[i].name,cl.name)==0)
                                        break;
                        }
			if(i==listOfClasses.size())
                        	listOfClasses.push_back(cl);
			else
			{currenterpointer--;printf("ERROR:Multiple definition of class %s on line %d\n",cl.name,yylineno);}
	}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 2603 "parser.ypp"
    {currenter=NULL;}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 2620 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Interface Field Declaration>>>>>>>,line %d\n",yylineno);}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 2622 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Interface Method Declaration>>>>>>>,line %d\n",yylineno);}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 2632 "parser.ypp"
    {
		m = (struct methodConstructor *)malloc(sizeof(methodConstructor));
		strcpy(m->name,id);
                m->modifier=listOfModifiers;
		listOfModifiers.clear();
                if((yyvsp[(2) - (3)].attr)->token==1)
                        m->type=(yyvsp[(2) - (3)].attr)->type;
                else
                        strcpy(m->ref,(yyvsp[(2) - (3)].attr)->ref);
		m->param=param;
		param.clear();
		listOfClasses[currenterpointer].listOfMethods.push_back(m);
	}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 2647 "parser.ypp"
    {
		m = (struct methodConstructor *)malloc(sizeof(methodConstructor));
		strcpy(m->name,id);
                m->modifier.push_back(mnative);
		listOfModifiers.clear();
                if((yyvsp[(1) - (2)].attr)->token==1)
                        m->type=(yyvsp[(1) - (2)].attr)->type;
                else
                        strcpy(m->ref,(yyvsp[(1) - (2)].attr)->ref);
		m->param=param;
		param.clear();
		listOfClasses[currenterpointer].listOfMethods.push_back(m);
	}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 2662 "parser.ypp"
    {
		m = (struct methodConstructor *)malloc(sizeof(methodConstructor));
		strcpy(m->name,id);
		m->modifier=listOfModifiers;
		listOfModifiers.clear();
		m->type=tvoid;
		m->param=param;
		param.clear();
		listOfClasses[currenterpointer].listOfMethods.push_back(m);
	}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 2674 "parser.ypp"
    {
		m = (struct methodConstructor *)malloc(sizeof(methodConstructor));
		strcpy(m->name,id);
		m->modifier.push_back(mnative);
		m->type=tvoid;
		m->param=param;
		param.clear();
		listOfClasses[currenterpointer].listOfMethods.push_back(m);
	}
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 2707 "parser.ypp"
    {if(!forSt) createtable(currenter);}
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 2707 "parser.ypp"
    {if(!forSt) removetable(currenter);}
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 2714 "parser.ypp"
    {
		fprintf(fcg,"%s:\n",(yyvsp[(1) - (2)].str));
	}
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 2719 "parser.ypp"
    {
		if((yyvsp[(3) - (4)].attr)->type!=tboolean)
			printf("ERROR:erroneous type used in if statement at line %d\n",yylineno);
		else
		{
			char *val=Address((yyvsp[(3) - (4)].attr)->contains);
			enum refType t=Ref(val);
			if(t==constant)
				fprintf(fcg,"\nli $t0,%s\n",val);
			else
				fprintf(fcg,"lw $t0,%s\n",val);
			labels.push(num_label++);
			fprintf(fcg,"beqz $t0,L%d\n",labels.top());
		}
	}
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 2735 "parser.ypp"
    {printf("ERROR:Missing ( on line %d\n",yylineno);}
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 2738 "parser.ypp"
    {
		//strcpy(oldswitch,newswitch);
		//strcpy(newswitch,$3->contains);
		switches.push((yyvsp[(3) - (4)].attr)->contains);
		labels.push(num_label++);
		break_allowed++;
		break_label.push(labels.top());
		labels.push(num_label++);
	}
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 2748 "parser.ypp"
    {
		//if($7->type!=tvoid && $3->type!=$7->type)
		//	printf("ERROR:Type mismatch in switch statement at line %d\n",yylineno);
		if(!labels.empty())
		{
			//printf("%d %d\n",labels.top(),break_label);
			while(!labels.empty() && labels.top()!=break_label.top())
			{
				//printf("%d %d\n",labels.top(),break_label);
				fprintf(fcg,"L%d:\n",labels.top());
				labels.pop();
			}
			if(!labels.empty())
			{
				fprintf(fcg,"L%d:\n",labels.top());
				labels.pop();
			}
		}
		//strcpy(newswitch,oldswitch);
		switches.pop();
		break_label.pop();
		break_allowed--;
	}
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 2772 "parser.ypp"
    {printf("ERROR:Missing ( on line %d\n",yylineno);}
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 2774 "parser.ypp"
    {break_allowed++;labels.push(num_label++);continue_label.push(labels.top());fprintf(fcg,"\nL%d:\n",labels.top());}
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 2775 "parser.ypp"
    {
		if((yyvsp[(4) - (5)].attr)->type!=tboolean)
			printf("ERROR:erroneous type used in while statement at line %d\n",yylineno);
		else
		{
			char *val=Address((yyvsp[(4) - (5)].attr)->contains);
			enum refType t=Ref(val);
			if(t==constant)
				fprintf(fcg,"li $t0,%s\n",val);
			else
				fprintf(fcg,"lw $t0,%s\n",val);
			labels.push(num_label++);
			fprintf(fcg,"beqz $t0,L%d\n",labels.top());
			break_label.push(labels.top());
		}
	}
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 2791 "parser.ypp"
    {
		if(!labels.empty())
		{
			int val=labels.top();
			labels.pop();
			if(!labels.empty())
			{
				fprintf(fcg,"b L%d\n",labels.top());
				fprintf(fcg,"L%d:\n\n",val);
				labels.pop();
			}
		}
		break_label.pop();
		continue_label.pop();
		break_allowed--;
	}
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 2808 "parser.ypp"
    {printf("ERROR:Missing ( on line %d\n",yylineno);}
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 2811 "parser.ypp"
    {
		break_allowed++;
		labels.push(num_label++);continue_label.push(labels.top());
		fprintf(fcg,"\nL%d:\n",labels.top());
		labels.push(num_label++);break_label.push(labels.top());
	}
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 2818 "parser.ypp"
    {
		if((yyvsp[(6) - (8)].attr)->type!=tboolean)
			printf("ERROR:erroneous type used in if statement at line %d\n",yylineno);
		else
		{
			char *val=Address((yyvsp[(6) - (8)].attr)->contains);
			enum refType t=Ref(val);
			if(t==constant)
				fprintf(fcg,"li $t0,%s\n",val);
			else
				fprintf(fcg,"lw $t0,%s\n",val);
			if(!labels.empty())
			{
				int loop=labels.top();
				labels.pop();
				if(!labels.empty())
				{
					fprintf(fcg,"bnez $t0,L%d\n",labels.top());
					fprintf(fcg,"L%d:\n\n",loop);
					labels.pop();
				}
			}
		}
		break_label.pop();
		continue_label.pop();
		break_allowed--;
	}
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 2846 "parser.ypp"
    {printf("ERROR:Missing ( on line %d\n",yylineno);}
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 2849 "parser.ypp"
    {	createtable(currenter);
		forSt++;
		break_allowed++;
		labels.push(num_label++);//start of statement
		labels.push(num_label++);//end of statement
		break_label.push(labels.top());
		labels.push(num_label++);//expression
		labels.push(num_label++);//update
		continue_label.push(labels.top());
	}
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 2860 "parser.ypp"
    {
		int val1=labels.top();
		labels.pop();
		int val2=labels.top();
		labels.pop();
		fprintf(fcg,"L%d:\n",labels.top());
		labels.pop();
		labels.push(val2);
		labels.push(val1);
	}
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 2870 "parser.ypp"
    {	removetable(currenter);
		forSt--;
		if(!labels.empty())
		{
			fprintf(fcg,"b L%d\n",labels.top());
			labels.pop();
			if(!labels.empty())
			{
				fprintf(fcg,"L%d:\n",labels.top());
				labels.pop();
			}
		}
	}
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 2884 "parser.ypp"
    {printf("ERROR:Missing ( on line %d\n",yylineno);}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 2888 "parser.ypp"
    {printf("ERROR:Missing ; on line %d\n",yylineno);}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 2891 "parser.ypp"
    {
		if(break_allowed)
			fprintf(fcg,"b L%d\n",break_label.top());
		else
			printf("ERROR:illegal use of break at line %d\n",yylineno);
	}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 2898 "parser.ypp"
    {printf("ERROR:Missing ; on line %d\n",yylineno);}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 2901 "parser.ypp"
    {
		if(break_allowed)
			fprintf(fcg,"b %s\n",(yyvsp[(2) - (3)].str));
		else
			printf("ERROR:illegal use of continue at line %d\n",yylineno);
	}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 2908 "parser.ypp"
    {printf("ERROR:Missing ; on line %d\n",yylineno);}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 2911 "parser.ypp"
    {
		if(break_allowed)
			fprintf(fcg,"b L%d\n",continue_label.top());
		else
			printf("ERROR:illegal use of continue at line %d\n",yylineno);
	}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 2918 "parser.ypp"
    {printf("ERROR:Missing ; on line %d\n",yylineno);}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 2921 "parser.ypp"
    {
		if((yyvsp[(2) - (3)].attr)->token!=returninfo->token)
			printf("ERROR:Invalid return expression at line %d\n",yylineno);
		else if((yyvsp[(2) - (3)].attr)->dimension!=returninfo->dimension)
			printf("ERROR:Invalid return expression at line %d\n",yylineno);
		else if((yyvsp[(2) - (3)].attr)->token==1 || (yyvsp[(2) - (3)].attr)->token==3)
		{
			if(returninfo->type==tdouble && ((yyvsp[(2) - (3)].attr)->type==tstring || (yyvsp[(2) - (3)].attr)->type==tnull || (yyvsp[(2) - (3)].attr)->type==tboolean || \
			(yyvsp[(2) - (3)].attr)->type==tnone || (yyvsp[(2) - (3)].attr)->type==tvoid))
                		printf("ERROR:Invalid return type on line %d\n",yylineno);
			else if(returninfo->type==tfloat && ((yyvsp[(2) - (3)].attr)->type==tdouble || (yyvsp[(2) - (3)].attr)->type==tstring || (yyvsp[(2) - (3)].attr)->type==tnull || (yyvsp[(2) - (3)].attr)->type==tboolean || \
				(yyvsp[(2) - (3)].attr)->type==tnone || (yyvsp[(2) - (3)].attr)->type==tvoid))
                		printf("ERROR:Invalid return type on line %d\n",yylineno);
			else if(returninfo->type==tlong && !((yyvsp[(2) - (3)].attr)->type==tlong || (yyvsp[(2) - (3)].attr)->type==tint || (yyvsp[(2) - (3)].attr)->type==tbyte || (yyvsp[(2) - (3)].attr)->type==tshort || (yyvsp[(2) - (3)].attr)->type==tchar))
              			 printf("ERROR:Invalid return type on line %d\n",yylineno);
                	else if(returninfo->type==tint && !((yyvsp[(2) - (3)].attr)->type==tint || (yyvsp[(2) - (3)].attr)->type==tbyte || (yyvsp[(2) - (3)].attr)->type==tshort || (yyvsp[(2) - (3)].attr)->type==tchar))
                		 printf("ERROR:Invalid return type on line %d\n",yylineno);
                	else if(returninfo->type==tshort && !((yyvsp[(2) - (3)].attr)->type==tbyte || (yyvsp[(2) - (3)].attr)->type==tshort || (yyvsp[(2) - (3)].attr)->type==tchar))
                		 printf("ERROR:Invalid return type on line %d\n",yylineno);
                	else if(returninfo->type==tbyte && !((yyvsp[(2) - (3)].attr)->type==tbyte || (yyvsp[(2) - (3)].attr)->type==tchar))
                		 printf("ERROR:Invalid return type on line %d\n",yylineno);
                	else if(returninfo->type==tchar && (yyvsp[(2) - (3)].attr)->type!=tchar)
                		 printf("ERROR:Invalid return type on line %d\n",yylineno);
			else if(returninfo->type==tvoid)
				printf("ERROR:return statement used inside a void at line %d\n",yylineno);
			else
			{
				returnFound=true;
				char *val=Address((yyvsp[(2) - (3)].attr)->contains);
				if(Ref(val)==constant)
				{
					if(returninfo->type==tdouble || returninfo->type==tdouble)
					{
						if((yyvsp[(2) - (3)].attr)->type==tdouble || (yyvsp[(2) - (3)].attr)->type==tfloat)
							fprintf(fcg,"li.s $f0,%s\n",val);
						else
						{
							fprintf(fcg,"li $t0,%s\n",val);
							fprintf(fcg,"mtc1 $t0,$f0\n");
							fprintf(fcg,"cvt.s.w $f0,$f0\n");
						}
					}
					else
						fprintf(fcg,"li $v0,%s\n",val);
				}
				else if(Ref(val)==memory)
				{
					if(returninfo->type==tdouble || returninfo->type==tdouble)
					{
						if((yyvsp[(2) - (3)].attr)->type==tdouble || (yyvsp[(2) - (3)].attr)->type==tfloat)
							fprintf(fcg,"l.s $f0,%s\n",val);
						else
						{
							fprintf(fcg,"lw $t0,%s\n",val);
							fprintf(fcg,"mtc1 $t0,$f0\n");
							fprintf(fcg,"cvt.s.w $f0,$f0\n");
						}
					}
					else if(returninfo->type!=tchar)
						fprintf(fcg,"lw $v0,%s\n",val);
					else
						fprintf(fcg,"lb $v0,%s\n",val);
				}
				else
				{
					if(returninfo->type==tdouble || returninfo->type==tdouble)
					{
						if((yyvsp[(2) - (3)].attr)->type==tdouble || (yyvsp[(2) - (3)].attr)->type==tfloat)
							fprintf(fcg,"mov.s $f0,%s\n",val);
						else
						{
							fprintf(fcg,"move $t0,%s\n",val);
							fprintf(fcg,"mtc1 $t0,$f0\n");
							fprintf(fcg,"cvt.s.w $f0,$f0\n");
						}
					}
					else
						fprintf(fcg,"move $v0,%s\n",val);
				}
				if(strcmp(m->name,"main"))
					fprintf(fcg,"b %s%dend\n",m->name,method_count-1);
				else
					fprintf(fcg,"b mainend\n");
			}
		}
		else if((yyvsp[(2) - (3)].attr)->token==2 || (yyvsp[(2) - (3)].attr)->token==4)
		{
			if(strcmp(returninfo->ref,(yyvsp[(2) - (3)].attr)->ref))
				printf("ERROR:Invalid return expression at line %d\n",yylineno);
			else
			{
				returnFound=true;
				char *val=Address((yyvsp[(2) - (3)].attr)->contains);
				if(Ref(val)==memory)
					fprintf(fcg,"lw $v0,%s\n",val);
				else
					fprintf(fcg,"move $v0,%s\n",val);
				if(strcmp(m->name,"main"))
					fprintf(fcg,"b %s%dend\n",m->name,method_count-1);
				else
					fprintf(fcg,"b mainend\n");
			}
		}
	}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 3027 "parser.ypp"
    {
		if(returninfo->type!=tvoid)
			printf("ERROR:Empty return statement in line %d\n",yylineno);
		else
		{
			if(strcmp(m->name,"main"))
				fprintf(fcg,"b %s%dend\n",m->name,method_count-1);
			else
				fprintf(fcg,"b mainend\n");
		}
	}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 3039 "parser.ypp"
    {printf("ERROR:Missing ; on line %d\n",yylineno);}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 3042 "parser.ypp"
    {fprintf(fcg,"\nL%d:\n",labels.top());labels.pop();}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 3045 "parser.ypp"
    {	
		if(!labels.empty())
		{
			int val=labels.top();
			labels.pop();
			labels.push(num_label++);
			fprintf(fcg,"b L%d\n",labels.top());
			fprintf(fcg,"\nL%d:\n",val);
		}
	}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 3054 "parser.ypp"
    {fprintf(fcg,"\nL%d:\n",labels.top());labels.pop();}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 3057 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tvoid;}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 3059 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 3061 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 3063 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 3065 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 3069 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 3072 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		//if(!(($1->type!=tvoid && $2->type==tvoid) || $1->type==$2->type))
		//{
		//	$$->type=tnone;
		//	printf("ERROR:Error in switch statement at line %d\n",yylineno);
		//}
		//else
			(yyval.attr)=(yyvsp[(1) - (2)].attr);
	}
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 3085 "parser.ypp"
    {
		if((yyvsp[(1) - (1)].attr)->type!=tvoid)
		{
			labels.push(num_label++);
			fprintf(fcg,"b L%d\n",labels.top());
			int val=labels.top();
			labels.pop();
			if(!labels.empty())
			{
				fprintf(fcg,"L%d:\n",labels.top());
				labels.pop();
			}
			labels.push(val);
		}
		else
		{
			if(!labels.empty())
			{
				fprintf(fcg,"L%d:\n",labels.top());
				labels.pop();
			}
		}
	}
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 3109 "parser.ypp"
    {	(yyval.attr)=(yyvsp[(1) - (3)].attr);
		if(!labels.empty())
		{
			if((yyvsp[(1) - (3)].attr)->type!=tvoid)
			{
				int val1=labels.top();
				labels.pop();
				labels.push(num_label++);
				fprintf(fcg,"b L%d\n",labels.top());
				fprintf(fcg,"L%d:\n",val1);
			}
		}
	}
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 3125 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 3128 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		if(!(((yyvsp[(1) - (2)].attr)->type!=tvoid && (yyvsp[(2) - (2)].attr)->type==tvoid) || (yyvsp[(1) - (2)].attr)->type==(yyvsp[(2) - (2)].attr)->type))
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Error in switch statement at line %d\n",yylineno);
		}
		else
			(yyval.attr)=(yyvsp[(1) - (2)].attr);
	}
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 3141 "parser.ypp"
    {	
		(yyval.attr)=(yyvsp[(2) - (3)].attr);
		if(!labels.empty())
		{
			char *val2=Address((yyvsp[(2) - (3)].attr)->contains);
			char *val1=Address(switches.top());
			if((yyvsp[(2) - (3)].attr)->type==tfloat || (yyvsp[(2) - (3)].attr)->type==tdouble)
			{
				if(Ref(val1)==constant)
					fprintf(fcg,"li.s $f0,%s\n",val1);
				else if(Ref(val1)==memory)
					fprintf(fcg,"l.s $f0,%s\n",val1);
				else
					fprintf(fcg,"mov.s $f0,%s\n",val1);
				if(Ref(val2)==constant)
					fprintf(fcg,"li.s $f1,%s\n",val2);
				else if(Ref(val2)==memory)
					fprintf(fcg,"l.s $f1,%s\n",val2);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val2);
				fprintf(fcg,"c.seq.s $f0,$f1\n");
				fprintf(fcg,"bc1t L%d\n",labels.top());
			}
			else if((yyvsp[(2) - (3)].attr)->type==tchar)
			{
				if(Ref(val1)==constant)
					fprintf(fcg,"li $t0,%s\n",val1);
				else if(Ref(val1)==memory)
					fprintf(fcg,"lb $t0,%s\n",val1);
				else
					fprintf(fcg,"move $t0,%s\n",val1);
				if(Ref(val2)==constant)
					fprintf(fcg,"li $t1,%s\n",val2);
				else if(Ref(val2)==memory)
					fprintf(fcg,"lb $t1,%s\n",val2);
				else
					fprintf(fcg,"move $t1,%s\n",val2);
				fprintf(fcg,"seq $t0,$t0,$t1\n");
				fprintf(fcg,"bnez $t0,L%d\n",labels.top());
			}
			else
			{
				if(Ref(val1)==constant)
					fprintf(fcg,"li $t0,%s\n",val1);
				else if(Ref(val1)==memory)
					fprintf(fcg,"lw $t0,%s\n",val1);
				else
					fprintf(fcg,"move $t0,%s\n",val1);
				if(Ref(val2)==constant)
					fprintf(fcg,"li $t1,%s\n",val2);
				else if(Ref(val2)==memory)
					fprintf(fcg,"lw $t1,%s\n",val2);
				else
					fprintf(fcg,"move $t1,%s\n",val2);
				fprintf(fcg,"seq $t0,$t0,$t1\n");
				fprintf(fcg,"bnez $t0,L%d\n",labels.top());
			}
		}
	}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 3202 "parser.ypp"
    {	
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->type=tvoid;
		fprintf(fcg,"b L%d\n",labels.top());
	}
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 3208 "parser.ypp"
    {printf("ERROR:Missing : on line %d\n",yylineno);}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 3212 "parser.ypp"
    {
		fprintf(fcg,"L%d:\n",labels.top());
		int val=labels.top();
		labels.pop();
		fprintf(fcg,"b L%d\n",labels.top());
		labels.pop();
		labels.push(val);
	}
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 3222 "parser.ypp"
    {
		fprintf(fcg,"L%d:\n",labels.top());
		int val=labels.top();
		labels.pop();
		fprintf(fcg,"b L%d\n",labels.top());
		labels.pop();
		labels.push(val);
	}
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 3231 "parser.ypp"
    {printf("ERROR:Missing ; on line %d\n",yylineno);}
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 3233 "parser.ypp"
    {fprintf(fcg,"L%d:\n",labels.top());}
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 3234 "parser.ypp"
    {
		int val=labels.top();
		labels.pop();
		fprintf(fcg,"b L%d\n",labels.top());
		labels.pop();
		labels.push(val);
	}
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 3242 "parser.ypp"
    {fprintf(fcg,"L%d:\n",labels.top());}
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 3243 "parser.ypp"
    {
		int val=labels.top();
		labels.pop();
		fprintf(fcg,"b L%d\n",labels.top());
		labels.pop();
		labels.push(val);
	}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 3252 "parser.ypp"
    {
		int val=labels.top();
		labels.pop();
		fprintf(fcg,"L%d:\n",labels.top());
		labels.push(val);
	}
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 3259 "parser.ypp"
    {
		if((yyvsp[(2) - (2)].attr)->type!=tboolean)
			printf("ERROR:Type mismatch in for statement at line %d\n",yylineno);
		char *val=Address((yyvsp[(2) - (2)].attr)->contains);
		if(Ref(val)==memory)
			fprintf(fcg,"lw $t0,%s\n",val);
		else if(Ref(val)==reg)
			fprintf(fcg,"move $t0,%s\n",val);
		else
			fprintf(fcg,"li $t0,%s\n",val);
		int val1=labels.top();
		labels.pop();
		int val2=labels.top();
		labels.pop();
		int val3=labels.top();
		labels.pop();
		int val4=labels.top();
		labels.pop();
		fprintf(fcg,"bnez $t0,L%d\n",val4);
		fprintf(fcg,"b L%d\n",val3);
		labels.push(val4);
		labels.push(val3);
		labels.push(val2);
		labels.push(val1);
	}
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 3286 "parser.ypp"
    {
		int val1=labels.top();
		labels.pop();
		int val2=labels.top();
		labels.pop();
		int val3=labels.top();
		labels.pop();
		int val4=labels.top();
		labels.pop();
		fprintf(fcg,"L%d:\n",val2);
		fprintf(fcg,"b L%d\n",val4);
		labels.push(val4);
		labels.push(val3);
		labels.push(val2);
		labels.push(val1);
	}
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 3318 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 3320 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 3323 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 3326 "parser.ypp"
    { 	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		strcpy((yyval.attr)->ref,listOfClasses[currenterpointer].name);
		(yyval.attr)->token=2;
		(yyval.attr)->dimension=0;
		strcpy((yyval.attr)->contains,"$s7");
		if(find(returninfo->modifier.begin(),returninfo->modifier.end(),mstatic)!=returninfo->modifier.end())
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:illegal usage of this at line %d\n",yylineno);
		}
	}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 3338 "parser.ypp"
    {(yyval.attr)=(yyvsp[(2) - (3)].attr);}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 3340 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 3342 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 3344 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 3346 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 3350 "parser.ypp"
    {
		struct ClassInterface *t=(struct ClassInterface *)malloc(sizeof(struct ClassInterface));
		bool found=false;
		struct methodConstructor *m=new struct methodConstructor;
		int p=listOfClasses.size()-1;
		while(!found && p>=0)
		{
			t=&listOfClasses[p--];
			if(strcmp(t->name,(yyvsp[(2) - (5)].attr)->ref))
				continue;
			for(int j=0;j<t->listOfMethods.size() && !found;j++)
			{
				//printf("%d %d\n",t->listOfMethods[j]->param.size(),param.size());
				if(strcmp(t->listOfMethods[j]->name,t->name)==0 && t->listOfMethods[j]->param.size()==param.size())
				{
					found=compare(t->listOfMethods[j]->param,param);
					m=t->listOfMethods[j];
					if(t!=&listOfClasses[currenterpointer])
					{
						if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mprivate)!=t->listOfMethods[j]->modifier.end())
							found=false;
					}
				}
			}
		}
		if(!found)
		{ 
			(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal constructor invocation at line %d\n",yylineno);
		}
		else
		{
			(yyval.attr)=(yyvsp[(2) - (5)].attr);
			char *temp=getNewTemp();
			strcpy((yyval.attr)->contains,temp);
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
			int i,nonstatic=1;
			t=&listOfClasses[p+1];
			ST *tab=t->table;
			while(tab!=NULL)
			{
				for(i=0;i<tab->entries.size();i++)
				{
					if(find(tab->entries[i].modifiers.begin(),tab->entries[i].modifiers.end(),mstatic)==tab->entries[i].modifiers.end())
						nonstatic++;
				}
				if(t->extends!=NULL)
				{
					tab=t->extends->table;
					t=t->extends;
				}
				else
					tab=NULL;
			}	
			fprintf(fcg,"li $a0,%d\n",4*nonstatic);
			fprintf(fcg,"li $v0,9\n");
			fprintf(fcg,"syscall\n");
			fprintf(fcg,"move $s7,$v0\n");
			int j,nonfloat=0,fl=12;
			for(j=0;j<param.size();j++)		//currently restrciting to only 4 parameters
			{
				char *val=Address(param[j]->contains);
				if((m->param[j]->type==tfloat || m->param[j]->type==tdouble) && m->param[j]->token==1)
				{
					if(param[j]->type!=tfloat && param[j]->type!=tdouble)
					{
						if(Ref(val)==constant)
							fprintf(fcg,"li $t0,%s\n",val);
						else if(Ref(val)==memory)
							fprintf(fcg,"lw $t0,%s\n",val);
						else
							fprintf(fcg,"move $t0,%s\n",val);
						fprintf(fcg,"mtc1 $t0,$f1\n");
						fprintf(fcg,"cvt.s.w $f1,$f1\n");
						fprintf(fcg,"mov.s $f%d,$f1\n",fl++);
					}
					else
					{
						if(Ref(val)==constant)
							fprintf(fcg,"li.s $f%d,%s\n",fl++,val);
						else if(Ref(val)==memory)
							fprintf(fcg,"l.s $f%d,%s\n",fl++,val);
						else
							fprintf(fcg,"mov.s $f%d,%s\n",fl++,val);
					}	
				}
				else
				{
					if(Ref(val)==constant)
						fprintf(fcg,"li $a%d,%s\n",nonfloat++,val);
					else if(Ref(val)==memory)
						fprintf(fcg,"lw $a%d,%s\n",nonfloat++,val);
					else
						fprintf(fcg,"move $a%d,%s\n",nonfloat++,val);
				}
			}
			fprintf(fcg,"sw $v0,%s\n",offToAddr(offset_temp[off]));
			fprintf(fcg,"\njal %s%d\n",m->name,m->number);
			//fprintf(fcg,"lw $s7,4($sp)\n");
		}
		param.clear();
	}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 3457 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		struct ClassInterface *t=(struct ClassInterface *)malloc(sizeof(struct ClassInterface));
		struct methodConstructor *m=new struct methodConstructor;
		bool found=false,alone=true;
		int p=listOfClasses.size()-1;
		while(!found && p>=0)
		{
			t=&listOfClasses[p--];
			if(strcmp(t->name,(yyvsp[(2) - (4)].attr)->ref))
			{
				alone=false;
				continue;
			}
			alone=true;
			for(int j=0;j<t->listOfMethods.size() && !found;j++)
			{
				if(strcmp(t->listOfMethods[j]->name,t->name)==0)
				{
					alone=false;
					if(t->listOfMethods[j]->param.size()==0)
					{
						m=t->listOfMethods[j];
						found=true;
						if(t!=&listOfClasses[currenterpointer])
						{
							if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mprivate)!=t->listOfMethods[j]->modifier.end())
								found=false;
						}
					}
				}
			}
			break;
		}
		if(alone)
			found=true;
		if(!found)
		{ 	
			(yyval.attr)->type=tnone;
			(yyval.attr)->token=1;
			printf("ERROR:Illegal constructor invocation at line %d\n",yylineno);
		}
		else
		{
			(yyval.attr)=(yyvsp[(2) - (4)].attr);
			char *temp=getNewTemp();
			strcpy((yyval.attr)->contains,temp);
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
			int i,nonstatic=1;
			t=&listOfClasses[p+1];
			ST *tab=t->table;
			while(tab!=NULL)
			{
				for(i=0;i<tab->entries.size();i++)
				{
					if(find(tab->entries[i].modifiers.begin(),tab->entries[i].modifiers.end(),mstatic)==tab->entries[i].modifiers.end())
						nonstatic++;
				}
				if(t->extends!=NULL)
				{
					tab=t->extends->table;
					t=t->extends;
				}
				else
					tab=NULL;
			}	
			fprintf(fcg,"li $a0,%d\n",4*nonstatic);
			fprintf(fcg,"li $v0,9\n");
			fprintf(fcg,"syscall\n");
			if(alone)
			{
				nonstatic=1;
				t=&listOfClasses[p+1];
				tab=t->table;
				while(tab!=NULL)
				{
					for(i=0;i<tab->entries.size();i++)
					{
						if(find(tab->entries[i].modifiers.begin(),tab->entries[i].modifiers.end(),mstatic)==tab->entries[i].modifiers.end())
						{
							if(tab->entries[i].btype==tfloat || tab->entries[i].btype==tdouble)
							{
								fprintf(fcg,"li.s $f0,0.0\n");						
								fprintf(fcg,"s.s $f0,%d($v0)\n",4*nonstatic);
							}
							else if(tab->entries[i].btype!=tchar)
							{
								fprintf(fcg,"li $t0,0\n");						
								fprintf(fcg,"sw $t0,%d($v0)\n",4*nonstatic);
							}
							else
							{
								fprintf(fcg,"li $t0,0\n");						
								fprintf(fcg,"sb $t0,%d($v0)\n",4*nonstatic);
							}
							nonstatic++;
						}
					}
					if(t->extends!=NULL)
					{
						tab=t->extends->table;
						t=t->extends;
					}
					else
						tab=NULL;
				}
				fprintf(fcg,"sw $v0,%s\n",offToAddr(offset_temp[off]));
			}
			else
			{
				fprintf(fcg,"sw $s7,4($sp)\n");
				fprintf(fcg,"move $s7,$v0\n");
				fprintf(fcg,"sw $v0,%s\n",offToAddr(offset_temp[off]));
				fprintf(fcg,"jal %s%d\n",m->name,m->number);
				fprintf(fcg,"lw $s7,4($sp)\n");
			}
		}		
	}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 3578 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 3580 "parser.ypp"
    { param.clear();(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 3584 "parser.ypp"
    {
		param.clear();
		struct attribute *at=(struct attribute *)malloc(sizeof(struct attribute));
		if((yyvsp[(1) - (1)].attr)->token==1 || (yyvsp[(1) - (1)].attr)->token==3)
			at->type=(yyvsp[(1) - (1)].attr)->type;
		else
			strcpy(at->ref,(yyvsp[(1) - (1)].attr)->ref);
		at->modifier=(yyvsp[(1) - (1)].attr)->modifier;
		at->token=(yyvsp[(1) - (1)].attr)->token;
		at->dimension=(yyvsp[(1) - (1)].attr)->dimension;
		strcpy(at->contains,(yyvsp[(1) - (1)].attr)->contains);
		param.push_back(at);
	}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 3599 "parser.ypp"
    {
		struct attribute *at=(struct attribute *)malloc(sizeof(struct attribute));
		if((yyvsp[(3) - (3)].attr)->token==1 || (yyvsp[(3) - (3)].attr)->token==3)
			at->type=(yyvsp[(3) - (3)].attr)->type;
		else
			strcpy(at->ref,(yyvsp[(3) - (3)].attr)->ref);
		at->modifier=(yyvsp[(3) - (3)].attr)->modifier;
		at->token=(yyvsp[(3) - (3)].attr)->token;
		at->dimension=(yyvsp[(3) - (3)].attr)->dimension;
		strcpy(at->contains,(yyvsp[(3) - (3)].attr)->contains);
		param.push_back(at);
	}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 3614 "parser.ypp"
    { 	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->type=(yyvsp[(2) - (4)].attr)->type;
		(yyval.attr)->dimension=(yyvsp[(3) - (4)].attr)->dimension+(yyvsp[(4) - (4)].attr)->dimension;
		(yyval.attr)->token=3;
	}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 3621 "parser.ypp"
    { 	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->type=(yyvsp[(2) - (3)].attr)->type;
		(yyval.attr)->dimension=(yyvsp[(3) - (3)].attr)->dimension;
		(yyval.attr)->token=3;
		char *val=Address((yyvsp[(3) - (3)].attr)->contains);
		
		char *temp=getNewTemp();

		int i;
		for(i=0;i<strlen(temp);i++)
			(yyval.attr)->contains[i]=temp[i];
		(yyval.attr)->contains[i]='\0';

		int off=(temp[2]-'0')*10+temp[3]-'0';
		offset_temp[off]=-num_var*4;
		num_var++;
		
		if(Ref(val)==memory)
			fprintf(fcg,"lw $t0,%s\n",val);
		else if(Ref(val)==reg)
			fprintf(fcg,"move $t0,%s\n",val);
		else
			fprintf(fcg,"li $t0,%s\n",val);
		fprintf(fcg,"add $t0,$t0,1\n");
		fprintf(fcg,"mul $t0,$t0,4\n");
		fprintf(fcg,"move $a0,$t0\n");
		fprintf(fcg,"li $v0,9\n");
		fprintf(fcg,"syscall\n");
		fprintf(fcg,"sw $v0,%s\n",Address(temp));
		jump_found=true;
	}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 3654 "parser.ypp"
    { 	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		strcpy((yyval.attr)->ref,(yyvsp[(2) - (4)].attr)->ref);
		(yyval.attr)->dimension=(yyvsp[(3) - (4)].attr)->dimension+(yyvsp[(4) - (4)].attr)->dimension;
		(yyval.attr)->token=4;
	}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 3661 "parser.ypp"
    { 	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		strcpy((yyval.attr)->ref,(yyvsp[(2) - (3)].attr)->ref);
		(yyval.attr)->dimension=(yyvsp[(3) - (3)].attr)->dimension;
		(yyval.attr)->token=4;

		char *temp=getNewTemp();
		strcpy((yyval.attr)->contains,temp);
		int off=(temp[2]-'0')*10+temp[3]-'0';
		offset_temp[off]=-num_var*4;
		num_var++;
		char *val=Address((yyvsp[(3) - (3)].attr)->contains);
		
		if(Ref(val)==memory)
			fprintf(fcg,"lw $t0,%s\n",val);
		else if(Ref(val)==reg)
			fprintf(fcg,"move $t0,%s\n",val);
		else
			fprintf(fcg,"li $t0,%s\n",val);
		fprintf(fcg,"addu $t0,$t0,1\n");
		fprintf(fcg,"mul $t0,$t0,%d\n",4);
		fprintf(fcg,"move $a0,$t0\n");
		fprintf(fcg,"li $v0,9\n");
		fprintf(fcg,"syscall\n");
		fprintf(fcg,"sw $v0,%s\n",Address(temp));
		jump_found=true;
	}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 3689 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->dimension=1;strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].attr)->contains);}
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 3691 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->dimension=(yyvsp[(1) - (2)].attr)->dimension+1;}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 3694 "parser.ypp"
    {(yyval.attr)=(yyvsp[(2) - (3)].attr);}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 3697 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->dimension=1;}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 3699 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->dimension=(yyvsp[(1) - (3)].attr)->dimension+1;}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 3703 "parser.ypp"
    { 	
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		struct ClassInterface *t2=(struct ClassInterface *)malloc(sizeof(struct ClassInterface));
		bool found=false,stat=false,off=0;
		char name[1024];
		ST *tab=currenter;
		STE *t1=(STE *)malloc(sizeof(STE));
		int loc=0;
		for(;loc<listOfClasses.size();loc++)
		{
			if(strcmp(listOfClasses[loc].name,(yyvsp[(1) - (3)].str))==0)
				break;
		}
		if(loc!=listOfClasses.size())
		{
			t1=findentry(listOfClasses[loc].table,(yyvsp[(3) - (3)].str));
			if(t1!=NULL)
			{
				for(loc=0;loc<t1->modifiers.size();loc++)
				{
					if(t1->modifiers[loc]==mstatic)
						break;
				}
				if(loc!=t1->modifiers.size())
				{
					stat=true;
					found=true;
					(yyval.attr)->dimension=t1->dimension;
					(yyval.attr)->token=(yyval.attr)->dimension>0?3:1;
					(yyval.attr)->type=t1->btype;	
					strcpy((yyval.attr)->contains,offToAddr(t1->offset));
				}
			}
		}
		else
		{
			while(tab!=NULL && !found)
			{
				t1=findentry(tab,(yyvsp[(1) - (3)].str));
				if(t1!=NULL)
					found=true;
				else
					tab=tab->prev;
			}
			if(!found)
				printf("ERROR:Illegal field access at line %d\n",yylineno);
			else
			{
				strcpy(name,t1->ref);
				int loc=0;
				for(;loc<listOfClasses.size();loc++)
				{
					if(strcmp(listOfClasses[loc].name,name)==0)
						break;
				}
				t2=&listOfClasses[loc];
				found=false;
				while(t2!=NULL && !found)
				{
					t1=findentry(t2->table,(yyvsp[(3) - (3)].str));
					if(!t1)
						t2=t2->extends;
					else
					{
						found=true;
						if(t2!=&listOfClasses[currenterpointer])
						{
							if(find(t1->modifiers.begin(),t1->modifiers.end(),mprivate)!=t1->modifiers.end())
							{t2=t2->extends;found=false;}	
						}
					}
				}
		        	if(!found)
					printf("ERROR:No variable of name %s found\n",(yyvsp[(3) - (3)].str));
				else
				{
					(yyval.attr)->dimension=t1->dimension;
					if(t1->btype==tnone)
					{
						(yyval.attr)->token=(yyval.attr)->dimension>0?4:2;
						strcpy((yyval.attr)->ref,t1->ref);
					}
					else
					{
						(yyval.attr)->token=(yyval.attr)->dimension>0?3:1;
						(yyval.attr)->type=t1->btype;
					}
					char *val=Address((yyvsp[(1) - (3)].str));
					fprintf(fcg,"lw $t0,%s\n",val);
					int nonstatic=1,i=0,total=1,barrier=0;
					found=false;
					t2=&listOfClasses[loc];
					tab=t2->table;
					while(tab!=NULL)
					{
						for(i=0;i<tab->entries.size();i++)
						{
							if(find(tab->entries[i].modifiers.begin(),tab->entries[i].modifiers.end(),mstatic)==tab->entries[i].modifiers.end())
								total++;
						}
						if(t2->extends!=NULL)
						{
							tab=t2->extends->table;
							t2=t2->extends;
						}
						else
							tab=NULL;
					}
					t2=&listOfClasses[loc];
					tab=t2->table;
					while(tab!=NULL && !found)
					{
						nonstatic=0;
						for(i=0;i<tab->entries.size();i++)
						{
							if(find(tab->entries[i].modifiers.begin(),tab->entries[i].modifiers.end(),mstatic)==tab->entries[i].modifiers.end())
							{
								if(!strcmp(tab->entries[i].lexeme,(yyvsp[(3) - (3)].str)))
								{
									found=true;
									break;
								}
								nonstatic++;
							}
						}
						barrier+=tab->entries.size();
						if(!found)
						{
							if(t2->extends!=NULL)
							{
								tab=t2->extends->table;
								t2=t2->extends;
							}
							else
								tab=NULL;
						}
					}
					if(!found)
						printf("ERROR:cannot access a static member from an object\n");
					else
					{
						fprintf(fcg,"addu $t0,$t0,%d\n",4*(nonstatic+total-barrier));
						fprintf(fcg,"move $t%d,$t0\n",next_loc_reg);
						fprintf(fcg,"\n");
						char temp[64];
						temp[0]='0';
						temp[1]='(';
						temp[2]='$';
						temp[3]='t';
						temp[4]='0'+next_loc_reg;
						temp[5]=')';
						temp[6]='\0';
						strcpy((yyval.attr)->contains,temp);
						next_loc_reg=(next_loc_reg+1)%10>=3?(next_loc_reg+1)%10:3;
					}
				}
			}
		}
	}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 3864 "parser.ypp"
    { 	
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		if((yyvsp[(1) - (3)].attr)->token!=2)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal field invocation at line %d\n",yylineno);
		}
		else
		{
			struct ClassInterface *t2=(struct ClassInterface *)malloc(sizeof(struct ClassInterface));
			int p=currenterpointer;
			while(p>=0)
			{	
				t2=&listOfClasses[p];
				if((yyvsp[(1) - (3)].attr)->ref!=NULL && !strcmp(t2->name,(yyvsp[(1) - (3)].attr)->ref))
					break;
				else
					p--;
			}
			bool found=false;
			STE *t1=NULL;
			found=false;
			while(t2!=NULL && !found)
			{
				t1=findentry(t2->table,(yyvsp[(3) - (3)].str));
				if(!t1)
					t2=t2->extends;
				else
				{
					found=true;
					if(t2!=&listOfClasses[currenterpointer])
					{
						if(find(t1->modifiers.begin(),t1->modifiers.end(),mprivate)!=t1->modifiers.end())
						{t2=t2->extends;found=false;}	
					}
				}
			}
			if(t1)
				found=true;
			if(!found)
			{
				(yyval.attr)->type=tnone;
				printf("ERROR:No variable of name %s found\n",(yyvsp[(3) - (3)].str));
			}
			else
			{
				(yyval.attr)->dimension=t1->dimension;
				if(t1->btype==tnone)
				{
					(yyval.attr)->token=(yyval.attr)->dimension>0?4:2;
					strcpy((yyval.attr)->ref,t1->ref);
				}
				else
				{
					(yyval.attr)->token=(yyval.attr)->dimension>0?3:1;
					(yyval.attr)->type=t1->btype;
				}
				char *val=Address((yyvsp[(1) - (3)].attr)->contains);
				if(Ref(val)==memory)
					fprintf(fcg,"lw $t0,%s\n",val);
				else
					fprintf(fcg,"move $t0,%s\n",val);
				found=false;
				int nonstatic=0,i=0,barrier=0,total=1;
				t2=&listOfClasses[p];
				ST *tab=t2->table;
				while(tab!=NULL)
				{
					for(i=0;i<tab->entries.size();i++)
					{
						if(find(tab->entries[i].modifiers.begin(),tab->entries[i].modifiers.end(),mstatic)==tab->entries[i].modifiers.end())
							total++;
					}
					if(t2->extends!=NULL)
					{
						tab=t2->extends->table;
						t2=t2->extends;
					}
						else
							tab=NULL;
				}
				t2=&listOfClasses[p];
				tab=t2->table;
				while(tab!=NULL && !found)
				{
					nonstatic=0;
					for(i=0;i<tab->entries.size();i++)
					{
						if(find(tab->entries[i].modifiers.begin(),tab->entries[i].modifiers.end(),mstatic)==tab->entries[i].modifiers.end())
						{
							if(!strcmp(tab->entries[i].lexeme,(yyvsp[(3) - (3)].str)))
							{
								found=true;
								break;
							}
							nonstatic++;
						}
					}
					barrier+=tab->entries.size();
					if(!found)
					{
						if(t2->extends!=NULL)
						{
							tab=t2->extends->table;
							t2=t2->extends;
						}
						else
							tab=NULL;
					}
				}
				if(!found)
					printf("ERROR:cannot access static member using an object\n");
				else
				{
						fprintf(fcg,"addu $t0,$t0,%d\n",4*(nonstatic+total-barrier));
						fprintf(fcg,"move $t%d,$t0\n",next_loc_reg);
						fprintf(fcg,"\n");
						char temp[64];
						temp[0]='0';
						temp[1]='(';
						temp[2]='$';
						temp[3]='t';
						temp[4]='0'+next_loc_reg;
						temp[5]=')';
						temp[6]='\0';
						strcpy((yyval.attr)->contains,temp);
						next_loc_reg=(next_loc_reg+1)%10>=3?(next_loc_reg+1)%10:3;
				}
			}
		}
	}
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 3997 "parser.ypp"
    { 	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		struct ClassInterface *t2=(struct ClassInterface *)malloc(sizeof(struct ClassInterface));	
		t2=listOfClasses[currenterpointer].extends;
		bool found=false;
		STE *t1;
		if(t2!=NULL)
		{
			t1=findentry(t2->table,(yyvsp[(3) - (3)].str));
			if(t1)
				found=true;
		}
		if(!found)
			printf("ERROR:No variable of name %s found\n",(yyvsp[(3) - (3)].str));
		else
		{
			(yyval.attr)->dimension=t1->dimension;
			if(t1->btype==tnone)
			{
				(yyval.attr)->token=(yyval.attr)->dimension>0?4:2;
				strcpy((yyval.attr)->ref,t1->ref);
			}
			else
			{
				(yyval.attr)->token=(yyval.attr)->dimension>0?3:1;
				(yyval.attr)->type=t1->btype;
			}
		}
	}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 4028 "parser.ypp"
    { 	
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tvoid;(yyval.attr)->token=1;(yyval.attr)->dimension=0;
		char *val=Address((yyvsp[(3) - (4)].attr)->contains);
		if(Ref(val)==constant)
		{
			if((yyvsp[(3) - (4)].attr)->token==1)
			{
				if((yyvsp[(3) - (4)].attr)->type==tdouble || (yyvsp[(3) - (4)].attr)->type==tfloat)
				{
					fprintf(fcg,"li.s $f12,%s\n",val);
					fprintf(fcg,"li $v0,2\n");
				}
				else if((yyvsp[(3) - (4)].attr)->type!=tchar)
				{
					fprintf(fcg,"li $a0,%s\n",val);
					fprintf(fcg,"li $v0,1\n");
				}
				else
				{
					fprintf(fcg,"li $a0,%s\n",val);
					fprintf(fcg,"li $v0,11\n");
				}
				fprintf(fcg,"syscall\n");
				fprintf(fcg,"la $a0,newline\n");
				fprintf(fcg,"li $v0,4\n");
				fprintf(fcg,"syscall\n");
			}
			else
			{
				fprintf(fcg,".data\n");
				fprintf(fcg,"__print%d:\t.asciiz \%s\n",num_print++,val);
				fprintf(fcg,".text\n");
				fprintf(fcg,"la $a0,__print%d\n",num_print-1);
				fprintf(fcg,"li $v0,4\n");
				fprintf(fcg,"syscall\n\n");
				fprintf(fcg,"la $a0,newline\n");
				fprintf(fcg,"li $v0,4\n");
				fprintf(fcg,"syscall\n");
				
			}	
		}
		else if(Ref(val)==memory)
		{
			if((yyvsp[(3) - (4)].attr)->type==tdouble || (yyvsp[(3) - (4)].attr)->type==tfloat)
			{
				fprintf(fcg,"l.s $f12,%s\n",val);
				fprintf(fcg,"li $v0,2\n");
			}
			else if((yyvsp[(3) - (4)].attr)->type!=tchar)
			{
				fprintf(fcg,"lw $a0,%s\n",val);
				fprintf(fcg,"li $v0,1\n");
			}
			else
			{
				fprintf(fcg,"lb $a0,%s\n",val);
				fprintf(fcg,"li $v0,11\n");
			}
			fprintf(fcg,"syscall\n");
			fprintf(fcg,"la $a0,newline\n");
			fprintf(fcg,"li $v0,4\n");
			fprintf(fcg,"syscall\n");
		}
		else
		{
			if((yyvsp[(3) - (4)].attr)->type==tdouble || (yyvsp[(3) - (4)].attr)->type==tfloat)
			{
				fprintf(fcg,"mov.s $f12,%s\n",val);
				fprintf(fcg,"li $v0,2\n");
			}
			else if((yyvsp[(3) - (4)].attr)->type!=tchar)
			{
				fprintf(fcg,"move $a0,%s\n",val);
				fprintf(fcg,"li $v0,1\n");
			}
			else
			{
				fprintf(fcg,"move $a0,%s\n",val);
				fprintf(fcg,"li $v0,11\n");
			}
			fprintf(fcg,"syscall\n");
			fprintf(fcg,"la $a0,newline\n");
			fprintf(fcg,"li $v0,4\n");
			fprintf(fcg,"syscall\n");
		}
	}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 4115 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 4117 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing ( on line %d\n",yylineno);}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 4120 "parser.ypp"
    { 
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->type=tvoid;(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		char *val=Address((yyvsp[(3) - (4)].attr)->contains);
		if(Ref(val)==constant)
		{
			if((yyvsp[(3) - (4)].attr)->token==1)
			{
				if((yyvsp[(3) - (4)].attr)->type==tdouble || (yyvsp[(3) - (4)].attr)->type==tfloat)
				{
					fprintf(fcg,"li.s $f12,%s\n",val);
					fprintf(fcg,"li $v0,2\n");
					fprintf(fcg,"syscall\n");
				}
				else if((yyvsp[(3) - (4)].attr)->type!=tchar)
				{
					fprintf(fcg,"li $a0,%s\n",val);
					fprintf(fcg,"li $v0,1\n");
					fprintf(fcg,"syscall\n");
				}
				else
				{
					fprintf(fcg,"li $a0,%s\n",val);
					fprintf(fcg,"li $v0,11\n");
					fprintf(fcg,"syscall\n");
				}
			}
			else
			{
				fprintf(fcg,".data\n");
				fprintf(fcg,"__print%d:\t.asciiz %s\n",num_print++,val);
				fprintf(fcg,".text\n");
				fprintf(fcg,"la $a0,__print%d\n",num_print-1);
				fprintf(fcg,"li $v0,4\n");
				fprintf(fcg,"syscall\n\n");
			}	
		}
		else if(Ref(val)==memory)
		{
			if((yyvsp[(3) - (4)].attr)->type==tdouble || (yyvsp[(3) - (4)].attr)->type==tfloat)
			{
				fprintf(fcg,"l.s $f12,%s\n",val);
				fprintf(fcg,"li $v0,2\n");
				fprintf(fcg,"syscall\n");
			}
			else if((yyvsp[(3) - (4)].attr)->type!=tchar)
			{
				fprintf(fcg,"lw $a0,%s\n",val);
				fprintf(fcg,"li $v0,1\n");
				fprintf(fcg,"syscall\n");
			}
			else
			{
				fprintf(fcg,"lb $a0,%s\n",val);
				fprintf(fcg,"li $v0,11\n");
				fprintf(fcg,"syscall\n");
			}
		}
		else
		{
			if((yyvsp[(3) - (4)].attr)->type==tdouble || (yyvsp[(3) - (4)].attr)->type==tfloat)
			{
				fprintf(fcg,"mov.s $f12,%s\n",val);
				fprintf(fcg,"li $v0,2\n");
				fprintf(fcg,"syscall\n");
			}
			else if((yyvsp[(3) - (4)].attr)->type!=tchar)
			{
				fprintf(fcg,"move $a0,%s\n",val);
				fprintf(fcg,"li $v0,1\n");
				fprintf(fcg,"syscall\n");
			}
			else
			{
				fprintf(fcg,"move $a0,%s\n",val);
				fprintf(fcg,"li $v0,11\n");
				fprintf(fcg,"syscall\n");
			}
		}
	}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 4202 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 4204 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing ( on line %d\n",yylineno);}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 4206 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tvoid;(yyval.attr)->token=1;(yyval.attr)->dimension=0;}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 4208 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 4211 "parser.ypp"
    { 	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->type=tvoid;(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		fprintf(fcg,"la $a0,newline\n");
		fprintf(fcg,"li $v0,4\n");
		fprintf(fcg,"syscall\n");
	}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 4219 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 4222 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		struct ClassInterface *t=&listOfClasses[currenterpointer];
		bool found=false;
		int j;
		enum Basic tp=tvoid;
		char typ[1024];
		int tk=1;
		struct methodConstructor *m;
		while(t!=NULL && !found)
		{
			for(j=0;j<t->listOfMethods.size() && !found;j++)
			{
				if(strcmp(t->listOfMethods[j]->name,(yyvsp[(1) - (4)].str))==0 && t->listOfMethods[j]->param.size()==param.size())
				{
					m=t->listOfMethods[j];
					if(t->listOfMethods[j]->token==1)
						tp=t->listOfMethods[j]->type;
					else
					{
						tk=0;
						strcpy(typ,t->listOfMethods[j]->ref);
					}
					(yyval.attr)->dimension=0;
					found=compare(t->listOfMethods[j]->param,param);
					if(find(returninfo->modifier.begin(),returninfo->modifier.end(),mstatic)!=returninfo->modifier.end())
					{
						if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mstatic)==t->listOfMethods[j]->modifier.end())
							found=false;
					}
					if(t!=&listOfClasses[currenterpointer])
					{
						if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mprivate)!=t->listOfMethods[j]->modifier.end())
							found=false;
					}						
				}
			}
			t=t->extends;	
		}
		if(!found)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal method invocation at line %d\n",yylineno);
		}
		else
		{
			if(tk)
			{
				(yyval.attr)->token=1;	
				(yyval.attr)->type=tp;
			}
			else
			{
				strcpy((yyval.attr)->ref,typ);
				(yyval.attr)->token=2;
			}
		
				int nonfloat=0,fl=12;
				for(j=0;j<param.size();j++)		//currently restrciting to only 4 parameters
				{
					char *val=Address(param[j]->contains);
					if((m->param[j]->type==tfloat || m->param[j]->type==tdouble) && m->param[j]->token==1)
					{
						if(param[j]->type!=tfloat && param[j]->type!=tdouble)
						{
							if(Ref(val)==constant)
								fprintf(fcg,"li $t0,%s\n",val);
							else if(Ref(val)==memory)
								fprintf(fcg,"lw $t0,%s\n",val);
							else
								fprintf(fcg,"move $t0,%s\n",val);
							fprintf(fcg,"mtc1 $t0,$f1\n");
							fprintf(fcg,"cvt.s.w $f1,$f1\n");
							fprintf(fcg,"mov.s $f%d,$f1\n",fl++);
						}
						else
						{
							if(Ref(val)==constant)
								fprintf(fcg,"li.s $f%d,%s\n",fl++,val);
							else if(Ref(val)==memory)
								fprintf(fcg,"l.s $f%d,%s\n",fl++,val);
							else
								fprintf(fcg,"mov.s $f%d,%s\n",fl++,val);
						}	
					}
					else
					{
						if(Ref(val)==constant)
							fprintf(fcg,"li $a%d,%s\n",nonfloat++,val);
						else if(Ref(val)==memory)
							fprintf(fcg,"lw $a%d,%s\n",nonfloat++,val);
						else
							fprintf(fcg,"move $a%d,%s\n",nonfloat++,val);
					}
				}
				fprintf(fcg,"\njal %s%d\n",m->name,m->number);
				char *temp=getNewTemp();
				int off=(temp[2]-'0')*10+temp[3]-'0';
				offset_temp[off]=-num_var*4;
				num_var++;
				if(tk)
				{
					if(tp!=tvoid &&(tp==tfloat || tp==tdouble))
						fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					else if(tp!=tvoid)
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
				}
				else
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
				strcpy((yyval.attr)->contains,temp);
		}
		param.clear();	
	}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 4337 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		struct ClassInterface *t=&listOfClasses[currenterpointer];
		bool found=false;
		int j;
		enum Basic tp=tvoid;
		char typ[1024];
		int tk=1;
		struct methodConstructor *m;
		while(t!=NULL && !found)
		{
			for(j=0;j<t->listOfMethods.size() && !found;j++)
			{
				if(strcmp(t->listOfMethods[j]->name,(yyvsp[(1) - (3)].str))==0 && t->listOfMethods[j]->param.size()==0)
				{		
					found=true;
					m=t->listOfMethods[j];		
					(yyval.attr)->dimension=0;
					if(t->listOfMethods[j]->token==1)
						tp=t->listOfMethods[j]->type;
					else
					{
						tk=0;
						strcpy(typ,t->listOfMethods[j]->ref);
					}
					if(find(returninfo->modifier.begin(),returninfo->modifier.end(),mstatic)!=returninfo->modifier.end())
					{
						if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mstatic)==t->listOfMethods[j]->modifier.end())
							found=false;
					}
					if(t!=&listOfClasses[currenterpointer])
					{
						if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mprivate)!=t->listOfMethods[j]->modifier.end())
							found=false;
					}
				}
			}
			t=t->extends;	
		}
		if(!found)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal method invocation at line %d\n",yylineno);
		}
		else
		{
			if(tk)
			{
				(yyval.attr)->token=1;	
				(yyval.attr)->type=tp;
			}
			else
			{
				strcpy((yyval.attr)->ref,typ);
				(yyval.attr)->token=2;
			}
				fprintf(fcg,"\njal %s%d\n",m->name,m->number);
				char *temp=getNewTemp();
				int off=(temp[2]-'0')*10+temp[3]-'0';
				offset_temp[off]=-num_var*4;
				num_var++;
				if(tk)
				{
					if(tp!=tvoid &&(tp==tfloat || tp==tdouble))
						fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					else if(tp!=tvoid)
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
				}
				else
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
				strcpy((yyval.attr)->contains,temp);
		}
			
	}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 4413 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		bool found=false,isStatic=false;
		char name[1024];
		struct ClassInterface *t=&listOfClasses[0];
		ST *tab=currenter;
		STE *t1=(STE *)malloc(sizeof(STE));
		int loc=0;
		for(;loc<listOfClasses.size();loc++)
		{
			if(strcmp(listOfClasses[loc].name,(yyvsp[(1) - (6)].str))==0)
				break;
		}
		if(loc!=listOfClasses.size())
		{
			found=true;
			t=&listOfClasses[loc];
			isStatic=true;
		}
		else
		{
			while(tab!=NULL && !found)
			{
				t1=findentry(tab,(yyvsp[(1) - (6)].str));
				if(t1!=NULL)
					found=true;
				else
					tab=tab->prev;
			}
			if(found)
			{
				int i=0;
				while(i<listOfClasses.size())
				{
					if(t1->ref!=NULL && strcmp(t->name,t1->ref))
						i++;
					else
						break;
					t=&listOfClasses[i];
				}
			}	
		}
		if(!found)
		{
			//printf("%d %d\n",found,isStatic);
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal method access at line %d\n",yylineno);
		}
		else
		{
			bool found=false;
			int j,tk=1;
			enum Basic tp=tvoid;
			char typ[1024];
			struct methodConstructor *m;
			while(t!=NULL && !found)
			{
				for(j=0;j<t->listOfMethods.size() && !found;j++)
				{
					if(strcmp(t->listOfMethods[j]->name,(yyvsp[(3) - (6)].str))==0 && t->listOfMethods[j]->param.size()==param.size())
					{
						m=t->listOfMethods[j];
						if(t->listOfMethods[j]->token==1)
							tp=t->listOfMethods[j]->type;
						else
						{
							tk=0;
							strcpy(typ,t->listOfMethods[j]->ref);
						}
						(yyval.attr)->dimension=0;
						found=compare(t->listOfMethods[j]->param,param);
						if(isStatic)
						{
							if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mstatic)==t->listOfMethods[j]->modifier.end())
								found=false;
						}
						if(t!=&listOfClasses[currenterpointer])
						{
							if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mprivate)!=t->listOfMethods[j]->modifier.end())
								found=false;
						}
					}
				}
				t=t->extends;	
			}
			if(!found)
			{
				(yyval.attr)->type=tnone;
				printf("ERROR:Illegal method invocation at line %d\n",yylineno);
			}
			else
			{
				if(tk)
				{
					(yyval.attr)->token=1;	
					(yyval.attr)->type=tp;
				}
				else	
				{	
					strcpy((yyval.attr)->ref,typ);
					(yyval.attr)->token=2;
				}
					//printf("%d\n",tp);
					int nonfloat=0,fl=12;
					for(j=0;j<param.size();j++)		//currently restrciting to only 4 parameters
					{
						char *val=Address(param[j]->contains);
						if((m->param[j]->type==tfloat || m->param[j]->type==tdouble) && m->param[j]->token==1)
						{
							if(param[j]->type!=tfloat && param[j]->type!=tdouble)
							{
								if(Ref(val)==constant)
									fprintf(fcg,"li $t0,%s\n",val);
								else if(Ref(val)==memory)
									fprintf(fcg,"lw $t0,%s\n",val);
								else
									fprintf(fcg,"move $t0,%s\n",val);
								fprintf(fcg,"mtc1 $t0,$f1\n");
								fprintf(fcg,"cvt.s.w $f1,$f1\n");
								fprintf(fcg,"mov.s $f%d,$f1\n",fl++);
							}
							else
							{
								if(Ref(val)==constant)
									fprintf(fcg,"li.s $f%d,%s\n",fl++,val);
								else if(Ref(val)==memory)
									fprintf(fcg,"l.s $f%d,%s\n",fl++,val);
								else	
									fprintf(fcg,"mov.s $f%d,%s\n",fl++,val);
							}	
						}
						else
						{
							if(Ref(val)==constant)
								fprintf(fcg,"li $a%d,%s\n",nonfloat++,val);
							else if(Ref(val)==memory)
								fprintf(fcg,"lw $a%d,%s\n",nonfloat++,val);
							else
								fprintf(fcg,"move $a%d,%s\n",nonfloat++,val);
						}
					}
					char *temp=getNewTemp();
					int off=(temp[2]-'0')*10+temp[3]-'0';
					offset_temp[off]=-num_var*4;
					num_var++;
					if(!isStatic)
					{
						fprintf(fcg,"sw $s7,%s\n",Address(temp));
						fprintf(fcg,"lw $s7,%s\n",Address((yyvsp[(1) - (6)].str)));
					}
					fprintf(fcg,"\njal %s%d\n",m->name,m->number);
					if(!isStatic)
						fprintf(fcg,"lw $s7,%s\n",Address(temp));
				if(tk)
				{
					if(tp!=tvoid &&(tp==tfloat || tp==tdouble))
						fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					else if(tp!=tvoid)
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
				}
				else
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
					strcpy((yyval.attr)->contains,temp);
			}	
		}
		param.clear();
	}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 4582 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		bool found=false,isStatic=false;
		char name[1024];
		ST *tab=currenter;
		ClassInterface *t;
		STE *t1;
		int loc=0;
		for(;loc<listOfClasses.size();loc++)
		{
			if(strcmp(listOfClasses[loc].name,(yyvsp[(1) - (5)].str))==0)
				break;
		}
		if(loc!=listOfClasses.size())
		{
			found=true;
			isStatic=true;
			t=&listOfClasses[loc];
		}
		else
		{
			while(tab!=NULL && !found)
			{
				t1=findentry(tab,(yyvsp[(1) - (5)].str));
				if(t1!=NULL)
					found=true;
				else
					tab=tab->prev;
			}
			if(found)
			{
				int i=0;
				t=&listOfClasses[i];
				while(i<listOfClasses.size())
				{
					if(t1->ref!=NULL && strcmp(t->name,t1->ref))
						i++;
					else
						break;
					t=&listOfClasses[i];
				}
			}	
		}
		if(!found)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal method access at line %d\n",yylineno);
		}
		else
		{
			bool found=false;
			int j,tk=1;
			enum Basic tp=tvoid;
			char typ[1024];
			struct methodConstructor *m;
			while(t!=NULL && !found)
			{
				for(j=0;j<t->listOfMethods.size() && !found;j++)
				{
					(yyval.attr)->dimension=0;
					if(strcmp(t->listOfMethods[j]->name,(yyvsp[(3) - (5)].str))==0 && t->listOfMethods[j]->param.size()==0)
					{
						m=t->listOfMethods[j];		
						found=true;
						if(t->listOfMethods[j]->token==1)
							tp=t->listOfMethods[j]->type;
						else
						{
							tk=0;
							strcpy(typ,t->listOfMethods[j]->ref);
						}
						if(isStatic)
						{
							if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mstatic)==t->listOfMethods[j]->modifier.end())
								found=false;
						}
						if(t!=&listOfClasses[currenterpointer])
						{
							if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mprivate)!=t->listOfMethods[j]->modifier.end())
								found=false;
						}
					}
				}
				t=t->extends;	
			}
			if(!found)
			{
				(yyval.attr)->type=tnone;
				printf("ERROR:Illegal method invocation at line %d\n",yylineno);
			}
			else
			{
				if(tk)
				{
					(yyval.attr)->token=1;	
					(yyval.attr)->type=tp;
				}
				else	
				{	
					strcpy((yyval.attr)->ref,typ);
					(yyval.attr)->token=2;
				}
				
				char *temp=getNewTemp();
				int off=(temp[2]-'0')*10+temp[3]-'0';
				offset_temp[off]=-num_var*4;
				num_var++;
				if(!isStatic)
				{
					fprintf(fcg,"sw $s7,%s\n",Address(temp));
					fprintf(fcg,"lw $s7,%s\n",Address((yyvsp[(1) - (5)].str)));
				}
				fprintf(fcg,"\njal %s%d\n",m->name,m->number);
				if(!isStatic)
					fprintf(fcg,"lw $s7,%s\n",Address(temp));
				if(tk)
				{
					if(tp!=tvoid &&(tp==tfloat || tp==tdouble))
						fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					else if(tp!=tvoid)
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
				}
				else
					fprintf(fcg,"sw $v0,%s\n",Address(temp));
				strcpy((yyval.attr)->contains,temp);
					
			}	
		}
	}
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 4713 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		if((yyvsp[(1) - (6)].attr)->token!=2)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal method invocation at line %d\n",yylineno);
		}
		else
		{
			struct ClassInterface *t;
			int p=currenterpointer;
			while(p>=0)
			{	
				t=&listOfClasses[p];
				if((yyvsp[(1) - (6)].attr)->ref!=NULL && !strcmp(t->name,(yyvsp[(1) - (6)].attr)->ref))
					break;
				else
					p--;
			}
			bool found=false;
			int j,tk=1;
			enum Basic tp=tvoid;
			char typ[1024];
			struct methodConstructor *m;
			while(t!=NULL && !found)
			{
				for(j=0;j<t->listOfMethods.size() && !found;j++)
				{
					if(strcmp(t->listOfMethods[j]->name,(yyvsp[(3) - (6)].str))==0 && t->listOfMethods[j]->param.size()==param.size())
					{
						m=t->listOfMethods[j];
						if(t->listOfMethods[j]->token==1)
							tp=t->listOfMethods[j]->type;
						else
						{
							tk=0;
							strcpy(typ,t->listOfMethods[j]->ref);
						}
						found=compare(t->listOfMethods[j]->param,param);
						if(t!=&listOfClasses[currenterpointer])
						{
							if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mprivate)!=t->listOfMethods[j]->modifier.end())
								found=false;
						}
					}
				}		
				t=t->extends;	
			}
			if(!found)
			{
				(yyval.attr)->type=tnone;
				printf("ERROR:Illegal method invocation at line %d\n",yylineno);
			}
			else
			{
				if(tk)
				{
					(yyval.attr)->token=1;	
					(yyval.attr)->type=tp;
					int nonfloat=0,fl=12;
					for(j=0;j<param.size();j++)		//currently restrciting to only 4 parameters
					{
						char *val=Address(param[j]->contains);
						if((m->param[j]->type==tfloat || m->param[j]->type==tdouble) && m->param[j]->token==1)
						{
							if(param[j]->type!=tfloat && param[j]->type!=tdouble)
							{
								if(Ref(val)==constant)
									fprintf(fcg,"li $t0,%s\n",val);
								else if(Ref(val)==memory)
									fprintf(fcg,"lw $t0,%s\n",val);
								else
									fprintf(fcg,"move $t0,%s\n",val);
								fprintf(fcg,"mtc1 $t0,$f1\n");
								fprintf(fcg,"cvt.s.w $f1,$f1\n");
								fprintf(fcg,"mov.s $f%d,$f1\n",fl++);
							}
							else
							{
								if(Ref(val)==constant)
									fprintf(fcg,"li.s $f%d,%s\n",fl++,val);
								else if(Ref(val)==memory)
									fprintf(fcg,"l.s $f%d,%s\n",fl++,val);
								else	
									fprintf(fcg,"mov.s $f%d,%s\n",fl++,val);
							}	
						}
						else
						{
							if(Ref(val)==constant)
								fprintf(fcg,"li $a%d,%s\n",nonfloat++,val);
							else if(Ref(val)==memory)
								fprintf(fcg,"lw $a%d,%s\n",nonfloat++,val);
							else
								fprintf(fcg,"move $a%d,%s\n",nonfloat++,val);
						}
					}
					char *temp=getNewTemp();
					int off=(temp[2]-'0')*10+temp[3]-'0';
					offset_temp[off]=-num_var*4;
					num_var++;
					fprintf(fcg,"sw $s7,%s\n",Address(temp));
					if(Ref(Address((yyvsp[(1) - (6)].attr)->contains))==memory)
						fprintf(fcg,"lw $s7,%s\n",Address((yyvsp[(1) - (6)].attr)->contains));
					else
						fprintf(fcg,"move $s7,%s\n",Address((yyvsp[(1) - (6)].attr)->contains));
					fprintf(fcg,"\njal %s%d\n",m->name,m->number);
					fprintf(fcg,"lw $s7,%s\n",Address(temp));
					if(tk)
					{
						if(tp!=tvoid &&(tp==tfloat || tp==tdouble))
							fprintf(fcg,"s.s $f0,%s\n",Address(temp));
						else if(tp!=tvoid)
							fprintf(fcg,"sw $v0,%s\n",Address(temp));
					}
					else
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
					strcpy((yyval.attr)->contains,temp);
				}
				else	
				{	
					strcpy((yyval.attr)->ref,typ);
					(yyval.attr)->token=2;
				}
			}
		}
		param.clear();	
	}
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 4842 "parser.ypp"
    {param.clear();printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 4845 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		if((yyvsp[(1) - (5)].attr)->token!=2)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal method access at line %d\n",yylineno);
		}
		else
		{
			struct ClassInterface *t;
			int p=currenterpointer;
			while(p>=0)
			{	
				t=&listOfClasses[p];
				if((yyvsp[(1) - (5)].attr)->ref!=NULL && !strcmp(t->name,(yyvsp[(1) - (5)].attr)->ref))
					break;
				else
					p--;
			}	
			bool found=false;
			int j,tk=1;
			enum Basic tp=tvoid;
			char typ[1024];
			struct methodConstructor *m;
			while(t!=NULL && !found)
			{
				for(j=0;j<t->listOfMethods.size() && !found;j++)
				{
					if(strcmp(t->listOfMethods[j]->name,(yyvsp[(3) - (5)].str))==0 && t->listOfMethods[j]->param.size()==0)
					{	
						m=t->listOfMethods[j];
						found=true;
						(yyval.attr)->dimension=0;
						if(t!=&listOfClasses[currenterpointer])
						{
							if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mprivate)!=t->listOfMethods[j]->modifier.end())
								found=false;
						}
						if(t->listOfMethods[j]->token==1)
							tp=t->listOfMethods[j]->type;
						else
							{tk=0;	strcpy(typ,t->listOfMethods[j]->ref);}	
					}
				}
				t=t->extends;	
			}
			if(!found)
			{
				(yyval.attr)->type=tnone;
				printf("ERROR:Illegal method invocation at line %d\n",yylineno);
			}
			else
			{
				if(tk)
				{
					(yyval.attr)->token=1;	
					(yyval.attr)->type=tp;
				}
				else	
				{	
					strcpy((yyval.attr)->ref,typ);
					(yyval.attr)->token=2;
				}
					char *temp=getNewTemp();
					int off=(temp[2]-'0')*10+temp[3]-'0';
					offset_temp[off]=-num_var*4;
					num_var++;
					fprintf(fcg,"sw $s7,%s\n",Address(temp));
					if(Ref(Address((yyvsp[(1) - (5)].attr)->contains))==memory)
						fprintf(fcg,"lw $s7,%s\n",Address((yyvsp[(1) - (5)].attr)->contains));
					else
						fprintf(fcg,"move $s7,%s\n",Address((yyvsp[(1) - (5)].attr)->contains));
					fprintf(fcg,"\njal %s%d\n",m->name,m->number);
					fprintf(fcg,"lw $s7,%s\n",Address(temp));
					if(tp!=tvoid &&(tp==tfloat || tp==tdouble))
						fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					else if(tp!=tvoid)
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
					strcpy((yyval.attr)->contains,temp);
					
					if(tk)
					{
						if(tp!=tvoid &&(tp==tfloat || tp==tdouble))
							fprintf(fcg,"s.s $f0,%s\n",Address(temp));
						else if(tp!=tvoid)
							fprintf(fcg,"sw $v0,%s\n",Address(temp));
					}
					else
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
			}
			
		}
	}
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 4939 "parser.ypp"
    {printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 4942 "parser.ypp"
    { 	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		struct ClassInterface *t=(struct ClassInterface *)malloc(sizeof(struct ClassInterface));
		t=listOfClasses[currenterpointer].extends;
		bool found=false;
		int j,tk=1;
		enum Basic tp=tvoid;
		char typ[1024];
		struct methodConstructor *m;
		while(t!=NULL && !found)
		{
			for(j=0;j<t->listOfMethods.size() && !found;j++)
			{
				if(strcmp(t->listOfMethods[j]->name,(yyvsp[(3) - (6)].str))==0 && t->listOfMethods[j]->param.size()==param.size())
				{
					m=t->listOfMethods[j];
					found=true;
					if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mprivate)!=t->listOfMethods[j]->modifier.end())
						found=false;
					if(t->listOfMethods[j]->token==1)
						tp=t->listOfMethods[j]->type;
					else
					{tk=0;	strcpy(typ,t->listOfMethods[j]->ref);}	
					(yyval.attr)->dimension=0;
					found=compare(t->listOfMethods[j]->param,param);
				}
			}
			t=t->extends;	
		}
		if(!found)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal method invocation at line %d\n",yylineno);
		}
		else
		{
			if(tk)
			{
				(yyval.attr)->token=1;	
				(yyval.attr)->type=tp;
			}
			else	
			{	
				strcpy((yyval.attr)->ref,typ);
				(yyval.attr)->token=2;
			}
				int nonfloat=0,fl=12;
				for(j=0;j<param.size();j++)		//currently restrciting to only 4 parameters
				{
						char *val=Address(param[j]->contains);
						if((m->param[j]->type==tfloat || m->param[j]->type==tdouble) && m->param[j]->token==1)
						{
							if(param[j]->type!=tfloat && param[j]->type!=tdouble)
							{
								if(Ref(val)==constant)
									fprintf(fcg,"li $t0,%s\n",val);
								else if(Ref(val)==memory)
									fprintf(fcg,"lw $t0,%s\n",val);
								else
									fprintf(fcg,"move $t0,%s\n",val);
								fprintf(fcg,"mtc1 $t0,$f1\n");
								fprintf(fcg,"cvt.s.w $f1,$f1\n");
								fprintf(fcg,"mov.s $f%d,$f1\n",fl++);
							}
							else
							{
								if(Ref(val)==constant)
									fprintf(fcg,"li.s $f%d,%s\n",fl++,val);
								else if(Ref(val)==memory)
									fprintf(fcg,"l.s $f%d,%s\n",fl++,val);
								else	
									fprintf(fcg,"mov.s $f%d,%s\n",fl++,val);
							}	
						}
						else
						{
							if(Ref(val)==constant)
								fprintf(fcg,"li $a%d,%s\n",nonfloat++,val);
							else if(Ref(val)==memory)
								fprintf(fcg,"lw $a%d,%s\n",nonfloat++,val);
							else
								fprintf(fcg,"move $a%d,%s\n",nonfloat++,val);
						}
				}
				fprintf(fcg,"\njal %s%d\n",m->name,m->number);
				char *temp=getNewTemp();
				int off=(temp[2]-'0')*10+temp[3]-'0';
				offset_temp[off]=-num_var*4;
				num_var++;
				strcpy((yyval.attr)->contains,temp);
				
					if(tk)
					{
						if(tp!=tvoid &&(tp==tfloat || tp==tdouble))
							fprintf(fcg,"s.s $f0,%s\n",Address(temp));
						else if(tp!=tvoid)
							fprintf(fcg,"sw $v0,%s\n",Address(temp));
					}
					else
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
		}
		param.clear();	
	}
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 5045 "parser.ypp"
    {param.clear();printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 5048 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		struct ClassInterface *t=listOfClasses[currenterpointer].extends;
		bool found=false;
		int j,tk=1;
		enum Basic tp=tvoid;
		char typ[1024];
		struct methodConstructor *m;
		while(t!=NULL && !found)
		{
			for(j=0;j<t->listOfMethods.size() && !found;j++)
			{
				if(strcmp(t->listOfMethods[j]->name,(yyvsp[(3) - (5)].str))==0 && t->listOfMethods[j]->param.size()==0)
				{	
					m=t->listOfMethods[j];
					found=true;
					if(find(t->listOfMethods[j]->modifier.begin(),t->listOfMethods[j]->modifier.end(),mprivate)!=t->listOfMethods[j]->modifier.end())
						found=false;
					if(t->listOfMethods[j]->token==1)
						tp=t->listOfMethods[j]->type;
					else
					{tk=0;	strcpy(typ,t->listOfMethods[j]->ref);}	
					(yyval.attr)->dimension=0;
				}
			}
			t=t->extends;	
		}
		if(!found)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal method invocation at line %d\n",yylineno);
		}
		else
		{
			if(tk)
			{
				(yyval.attr)->token=1;	
				(yyval.attr)->type=tp;
			}
			else	
			{	
				strcpy((yyval.attr)->ref,typ);
				(yyval.attr)->token=2;
			}
			
				fprintf(fcg,"\njal %s%d\n",m->name,m->number);
				char *temp=getNewTemp();
				int off=(temp[2]-'0')*10+temp[3]-'0';
				offset_temp[off]=-num_var*4;
				num_var++;
					if(tk)
					{
						if(tp!=tvoid &&(tp==tfloat || tp==tdouble))
							fprintf(fcg,"s.s $f0,%s\n",Address(temp));
						else if(tp!=tvoid)
							fprintf(fcg,"sw $v0,%s\n",Address(temp));
					}
					else
						fprintf(fcg,"sw $v0,%s\n",Address(temp));
				strcpy((yyval.attr)->contains,temp);
		}	
	}
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 5111 "parser.ypp"
    {printf("ERROR:Missing ) on line %d\n",yylineno);}
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 5115 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		bool found=false;
		char name[1024];
		ST *tab=currenter;
		STE *t1=(STE *)malloc(sizeof(STE));
		while(tab!=NULL && !found)
		{
			t1=findentry(tab,(yyvsp[(1) - (4)].attr)->ref);
			if(t1!=NULL)
				found=true;
			else
				tab=tab->prev;
		}
		if(!found)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Illegal array access at line %d\n",yylineno);
		}
		else
		{
			if(((yyvsp[(3) - (4)].attr)->type!=tint && (yyvsp[(3) - (4)].attr)->type!=tchar && (yyvsp[(3) - (4)].attr)->type!=tlong && (yyvsp[(3) - (4)].attr)->type!=tbyte && (yyvsp[(3) - (4)].attr)->type!=tshort) || t1->dimension==0)
			{
				(yyval.attr)->type=tnone;
				printf("ERROR:Wrong expression in array access at line %d\n",yylineno);
			}
			else
			{
				(yyval.attr)->dimension=t1->dimension-1;
				int nonstatic=1;
			       	if(t1->btype==tnone)
				{
					(yyval.attr)->token=t1->dimension>1?4:2;
					strcpy((yyval.attr)->ref,t1->ref);
					fprintf(fcg,"li $t0,%d\n",4*nonstatic);
				}
				else
				{
					(yyval.attr)->type=t1->btype;
					(yyval.attr)->token=t1->dimension>1?3:1;
					fprintf(fcg,"li $t0,4\n");
				}
				int start = t1->offset;
				char * val2 = Address((yyvsp[(3) - (4)].attr)->contains);
				enum refType type2 = Ref (val2);
				if (type2 == constant) 
					fprintf (fcg, "li $t1, %s\n", val2);
				else if (type2 == memory) 
					fprintf (fcg, "lw $t1, %s\n", val2);
				else 				
					fprintf (fcg, "move $t1, %s\n", val2);
				
				fprintf (fcg, "addi $t1, $t1, 1\n");
				
				fprintf (fcg, "mul $t0,$t0, $t1\n");
				if(Ref(Address((yyvsp[(1) - (4)].attr)->contains))==memory)
					fprintf (fcg, "lw $t1, %s\n",Address((yyvsp[(1) - (4)].attr)->contains));
				else
					fprintf (fcg, "move $t1, %s\n",Address((yyvsp[(1) - (4)].attr)->contains));
				fprintf (fcg, "add $t%d, $t0, $t1\n",next_loc_reg);
				fprintf (fcg, "\n");
				char temp[64];
					temp[0]='0';
					temp[1]='(';
					temp[2]='$';
					temp[3]='t';
					temp[4]='0'+next_loc_reg;
					temp[5]=')';
					temp[6]='\0';
					strcpy((yyval.attr)->contains,temp);
				next_loc_reg=(next_loc_reg+1)%10>=3?(next_loc_reg+1)%10:3;
			}
		}
	}
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 5191 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		if((yyvsp[(3) - (4)].attr)->type!=tint && (yyvsp[(3) - (4)].attr)->type!=tlong && (yyvsp[(3) - (4)].attr)->type!=tbyte && (yyvsp[(3) - (4)].attr)->type!=tshort)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Wrong expression in array access at line %d\n",yylineno);
		}
		else
		{
			if((yyvsp[(1) - (4)].attr)->dimension==0)
				printf("ERROR:Illegal array access at line %d\n",yylineno);
			else
			{
				if((yyvsp[(1) - (4)].attr)->token==1 || (yyvsp[(1) - (4)].attr)->token==3)
				{
					(yyval.attr)->token=(yyvsp[(1) - (4)].attr)->dimension>1?3:1;
					fprintf(fcg,"li $t0,%d\n",4);
					(yyval.attr)->type=(yyvsp[(1) - (4)].attr)->type;
				}
				else
				{
					(yyval.attr)->token=(yyvsp[(1) - (4)].attr)->dimension>1?4:2;
					fprintf(fcg,"li $t0,4\n");
					strcpy((yyval.attr)->ref,(yyvsp[(1) - (4)].attr)->ref);
				}
				char * val2 = Address((yyvsp[(3) - (4)].attr)->contains);
				enum refType type2 = Ref (val2);
				if (type2 == memory) 
					fprintf (fcg, "lw $t1, %s\n", val2);
				else if(type2==reg)				
					fprintf (fcg, "move $t1, %s\n", val2);
				else
					fprintf(fcg,"li $t1,%s\n",val2);
				fprintf (fcg, "addi $t1, $t1, 1\n");
				fprintf (fcg, "mul $t0,$t0, $t1\n");
				if(Ref(Address((yyvsp[(1) - (4)].attr)->contains))==memory)
					fprintf (fcg, "lw $t1, %s\n",Address((yyvsp[(1) - (4)].attr)->contains));
				else
					fprintf (fcg, "move $t1, %s\n",Address((yyvsp[(1) - (4)].attr)->contains));
				fprintf (fcg, "add $t%d, $t0, $t1\n",next_loc_reg);
				fprintf (fcg, "\n");
				char temp[64];
					temp[0]='0';
					temp[1]='(';
					temp[2]='$';
					temp[3]='t';
					temp[4]='0'+next_loc_reg;
					temp[5]=')';
					temp[6]='\0';
					strcpy((yyval.attr)->contains,temp);
				next_loc_reg=(next_loc_reg+1)%10>=3?(next_loc_reg+1)%10:3;
			}
		}
	}
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 5245 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing ] on line %d\n",yylineno);}
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 5247 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Missing ] on line %d\n",yylineno);}
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 5250 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 5253 "parser.ypp"
    {

		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		ST *temp=currenter;
		bool found=false;
		ClassInterface *t=&listOfClasses[currenterpointer];
		while(temp!=NULL)
		{
			if(!findentry(temp,(yyvsp[(1) - (1)].str)))
			{
				temp=temp->prev;
				if(temp==NULL)
				{
					if(t->extends!=NULL)
					{
						temp=t->extends->table;
						t=t->extends;
					}
				}
			}
			else
			{
				STE *entry=findentry(temp,(yyvsp[(1) - (1)].str));
				found=true;
				if(temp==t->table)
				{
					if(find(returninfo->modifier.begin(),returninfo->modifier.end(),mstatic)==returninfo->modifier.end())
					{
						//printf("here\n");
						if(find(entry->modifiers.begin(),entry->modifiers.end(),mstatic)==entry->modifiers.end())
						{
							fprintf(fcg,"move $t0,$s7\n");
							int nonstatic=1,i=0,barrier=0,total=1;
							t=&listOfClasses[currenterpointer];
							temp=t->table;
							found=false;
					while(temp!=NULL)
					{
						for(i=0;i<temp->entries.size();i++)
						{
							if(find(temp->entries[i].modifiers.begin(),temp->entries[i].modifiers.end(),mstatic)==temp->entries[i].modifiers.end())
								total++;
						}
						if(t->extends!=NULL)
						{
							temp=t->extends->table;
							t=t->extends;
						}
						else
							temp=NULL;
					}
							t=&listOfClasses[currenterpointer];
							temp=t->table;
					while(temp!=NULL && !found)
					{
						nonstatic=0;
						for(i=0;i<temp->entries.size();i++)
						{
							if(find(temp->entries[i].modifiers.begin(),temp->entries[i].modifiers.end(),mstatic)==temp->entries[i].modifiers.end())
							{
								if(!strcmp(temp->entries[i].lexeme,(yyvsp[(1) - (1)].str)))
								{
									found=true;
									break;
								}
								nonstatic++;
							}
						}
						barrier+=temp->entries.size();
						if(!found)
						{
							if(t->extends!=NULL)
							{
								temp=t->extends->table;
								t=t->extends;
							}
							else
								temp=NULL;
						}
					}
							fprintf(fcg,"addu $t0,$t0,%d\n",4*(nonstatic+total-barrier));
							fprintf(fcg,"move $t%d,$t0\n",next_loc_reg);
							fprintf(fcg,"\n");
							char temp[64];
							temp[0]='0';
							temp[1]='(';
							temp[2]='$';
							temp[3]='t';
							temp[4]='0'+next_loc_reg;
							temp[5]=')';
							temp[6]='\0';
							strcpy((yyval.attr)->contains,temp);
							next_loc_reg=(next_loc_reg+1)%10>=3?(next_loc_reg+1)%10:3;
						}
						else
							strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].str));
					}
					else
					{
						if(find(entry->modifiers.begin(),entry->modifiers.end(),mstatic)==entry->modifiers.end())
							printf("ERROR:call to a non static member from inside a static method\n");
						strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].str));
					}
				}
				else
					strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].str));
				if(entry->btype==tnone)
				{
					(yyval.attr)->token=entry->dimension>0?4:2;
					strcpy((yyval.attr)->ref,entry->ref);
				}
				else
				{
					(yyval.attr)->token=entry->dimension>0?3:1;
					(yyval.attr)->type=entry->btype;	
				}
				(yyval.attr)->dimension=entry->dimension;
				break;
			}
		}
		if(!found)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Identifier at line %d not found\n",yylineno);
		}
		/*$$=(struct attribute *)malloc(sizeof(struct attribute));
		ST *temp=currenter;
		bool found=false;
		int val=currenterpointer;
		ClassInterface *t=&listOfClasses[currenterpointer];
		while(temp!=NULL)
		{
			if(!findentry(temp,$1))
			{
				temp=temp->prev;
				if(temp==NULL)
				{
					if(t->extends!=NULL)
					{
						temp=t->extends->table;
						t=t->extends;
					}
				}
			}
			else
			{
				STE *entry=findentry(temp,$1);
				found=true;
				if(temp==t->table)
				{
					if(find(returninfo->modifier.begin(),returninfo->modifier.end(),mstatic)==returninfo->modifier.end())
					{
						if(find(entry->modifiers.begin(),entry->modifiers.end(),mstatic)==entry->modifiers.end())
						{
							fprintf(fcg,"move $t0,$s7\n");
							int nonstatic=1,count=1,total=1,barrier=0,i=0;
							t=&listOfClasses[currenterpointer];
							temp=t->table;
							found=false;
							
				while(temp!=NULL)
				{
						for(i=0;i<temp->entries.size();i++)
						{
							if(find(temp->entries[i].modifiers.begin(),temp->entries[i].modifiers.end(),mstatic)==temp->entries[i].modifiers.end())
								total++;
						}
						if(t->extends!=NULL)
						{
							temp=t->extends->table;
							t=t->extends;
						}
						else
							temp=NULL;
				}
							t=&listOfClasses[currenterpointer];
							temp=t->table;
				while(temp!=NULL && !found)
				{
						nonstatic=0;
						for(i=0;i<temp->entries.size();i++)
						{
							if(find(temp->entries[i].modifiers.begin(),temp->entries[i].modifiers.end(),mstatic)==temp->entries[i].modifiers.end())
							{
								if(!strcmp(temp->entries[i].lexeme,$1))
								{
									found=true;
									break;
								}
								nonstatic++;
							}
						}
						barrier+=temp->entries.size();
						if(!found)
						{
							if(t->extends!=NULL)
							{
								temp=t->extends->table;
								t=t->extends;
							}
							else
								temp=NULL;
						}
				}
							printf("%d\n",nonstatic+total-barrier);
							fprintf(fcg,"addu $t0,$t0,%d\n",4*(nonstatic+total-barrier));
							fprintf(fcg,"move $t%d,$t0\n",next_loc_reg);
							fprintf(fcg,"\n");
							char temp[64];
							temp[0]='0';
							temp[1]='(';
							temp[2]='$';
							temp[3]='t';
							temp[4]='0'+next_loc_reg;
							temp[5]=')';
							temp[6]='\0';
							strcpy($$->contains,temp);
							next_loc_reg=(next_loc_reg+1)%10>=3?(next_loc_reg+1)%10:3;
						}
						else
							strcpy($$->contains,$1);
					}
					else
					{
						if(find(entry->modifiers.begin(),entry->modifiers.end(),mstatic)==entry->modifiers.end())
							printf("ERROR:call to a non static member from inside a static method\n");
						strcpy($$->contains,$1);
					}
				}
				else
					strcpy($$->contains,$1);
				if(entry->btype==tnone)
				{
					$$->token=entry->dimension>0?4:2;
					strcpy($$->ref,entry->ref);
				}
				else
				{
					$$->token=entry->dimension>0?3:1;
					$$->type=entry->btype;	
				}
				$$->dimension=entry->dimension;
				break;
			}
		}
		if(!found)
		{
			$$->type=tnone;
			printf("ERROR:-----Identifier at line %d not found\n",yylineno);
		}*/
	}
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 5505 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 5509 "parser.ypp"
    {	
		(yyval.attr)=new struct attribute;
		(yyval.attr)->dimension=0;
		(yyval.attr)->token=1;
		char *temp=getNewTemp();
		int off=(temp[2]-'0')*10+temp[3]-'0';
		offset_temp[off]=-num_var*4;
		num_var++;
		strcpy((yyval.attr)->contains,temp);
		char *val=Address((yyvsp[(1) - (2)].attr)->contains);
		enum refType t=Ref(val);
		if((yyvsp[(1) - (2)].attr)->token!=1)
			printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
		else
		{
			if((yyvsp[(1) - (2)].attr)->type==tdouble && !((yyvsp[(1) - (2)].attr)->type==tnull || (yyvsp[(1) - (2)].attr)->type==tboolean || (yyvsp[(1) - (2)].attr)->type==tvoid || (yyvsp[(1) - (2)].attr)->type==tnone))
			{
				if(t==constant)
				{
					(yyval.attr)->type=tnone;
					printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
				}
				else if(t==memory)
				{
					fprintf(fcg,"l.s $f0,%s\n",val);
					fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					fprintf(fcg,"li.s $f1,1.0\n");
					fprintf(fcg,"%s.s $f0,$f0,$f1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"s.s $f0,%s\n",val);
					(yyval.attr)->type=tdouble;
				}
				else
				{
					fprintf(fcg,"mov.s $f0,%s\n",val);
					fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					fprintf(fcg,"li.s $f1,1.0\n");
					fprintf(fcg,"%s.s $f0,$f0,$f1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"mov.s %s,$f0\n",val);
					(yyval.attr)->type=tdouble;
				}
			}
			else if((yyvsp[(1) - (2)].attr)->type==tfloat && !((yyvsp[(1) - (2)].attr)->type==tdouble || (yyvsp[(1) - (2)].attr)->type==tnull || (yyvsp[(1) - (2)].attr)->type==tboolean || (yyvsp[(1) - (2)].attr)->type==tvoid || (yyvsp[(1) - (2)].attr)->type==tnone))
			{
				if(t==constant)
				{
					(yyval.attr)->type=tnone;
					printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
				}
				else if(t==memory)
				{
					fprintf(fcg,"l.s $f0,%s\n",val);
					fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					fprintf(fcg,"li.s $f1,1.0\n");
					fprintf(fcg,"%s.s $f0,$f0,$f1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"s.s $f0,%s\n",val);
					(yyval.attr)->type=tfloat;
				}
				else
				{
					fprintf(fcg,"mov.s $f0,%s\n",val);
					fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					fprintf(fcg,"li.s $f0,1\n");
					fprintf(fcg,"%s.s $f0,$f0,$f1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"mov.s %s,$f0\n",val);
					(yyval.attr)->type=tdouble;
				}
				
			}
			else if((yyvsp[(1) - (2)].attr)->type==tlong && !((yyvsp[(1) - (2)].attr)->type==tfloat || (yyvsp[(1) - (2)].attr)->type==tdouble || (yyvsp[(1) - (2)].attr)->type==tnull || (yyvsp[(1) - (2)].attr)->type==tboolean || (yyvsp[(1) - (2)].attr)->type==tvoid || (yyvsp[(1) - (2)].attr)->type==tnone))
			{
				if(t==constant)
				{
					(yyval.attr)->type=tnone;
					printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
				}
				else if(t==memory)
				{
					fprintf(fcg,"lw $t0,%s\n",val);
					fprintf(fcg,"sw $t0,%s\n",Address(temp));
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"sw $t0,%s\n",val);
					(yyval.attr)->type=tlong;
				}
				else
				{
					fprintf(fcg,"move $t0,%s\n",val);
					fprintf(fcg,"sw $t0,%s\n",Address(temp));
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"move %s,$t0\n",val);
					(yyval.attr)->type=tlong;
				}
				
			}
			else if((yyvsp[(1) - (2)].attr)->type==tint && ((yyvsp[(1) - (2)].attr)->type==tint || (yyvsp[(1) - (2)].attr)->type==tbyte || (yyvsp[(1) - (2)].attr)->type==tshort || (yyvsp[(1) - (2)].attr)->type==tchar))
			{
				if(t==constant)
				{
					(yyval.attr)->type=tnone;
					printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
				}
				else if(t==memory)
				{
					fprintf(fcg,"lw $t0,%s\n",val);
					fprintf(fcg,"sw $t0,%s\n",Address(temp));
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"sw $t0,%s\n",val);
					(yyval.attr)->type=tint;
				}
				else
				{
					fprintf(fcg,"move $t0,%s\n",val);
					fprintf(fcg,"sw $t0,%s\n",Address(temp));
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"move %s,$t0\n",val);
					(yyval.attr)->type=tint;
				}
			}
			else if((yyvsp[(1) - (2)].attr)->type==tshort && ((yyvsp[(1) - (2)].attr)->type==tbyte || (yyvsp[(1) - (2)].attr)->type==tshort))
			{
				if(t==constant)
				{
					(yyval.attr)->type=tnone;
					printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
				}
				else if(t==memory)
				{
					fprintf(fcg,"lw $t0,%s\n",val);
					fprintf(fcg,"sw $t0,%s\n",Address(temp));
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"sw $t0,%s\n",val);
					(yyval.attr)->type=tshort;
				}
				else
				{
					fprintf(fcg,"move $t0,%s\n",val);
					fprintf(fcg,"sw $t0,%s\n",Address(temp));
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"move %s,$t0\n",val);
					(yyval.attr)->type=tshort;
				}
			}
			else if((yyvsp[(1) - (2)].attr)->type==tbyte && (yyvsp[(1) - (2)].attr)->type==tbyte)
			{
				if(t==constant)
				{
					(yyval.attr)->type=tnone;
					printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
				}
				else if(t==memory)
				{
					fprintf(fcg,"lw $t0,%s\n",val);
					fprintf(fcg,"sw $t0,%s\n",Address(temp));
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"sw $t0,%s\n",val);
					(yyval.attr)->type=tbyte;
				}
				else
				{
					fprintf(fcg,"move $t0,%s\n",val);
					fprintf(fcg,"sw $t0,%s\n",Address(temp));
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"move %s,$t0\n",val);
					(yyval.attr)->type=tbyte;
				}
			}
			else if((yyvsp[(1) - (2)].attr)->type==tchar && (yyvsp[(1) - (2)].attr)->type==tchar)
			{
				if(t==constant)
				{
					(yyval.attr)->type=tnone;
					printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
				}
				else if(t==memory)
				{
					fprintf(fcg,"lb $t0,%s\n",val);
					fprintf(fcg,"sb $t0,%s\n",Address(temp));
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"sb $t0,%s\n",val);
					(yyval.attr)->type=tchar;
				}
				else
				{
					fprintf(fcg,"move $t0,%s\n",val);
					fprintf(fcg,"sb $t0,%s\n",Address(temp));
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(2) - (2)].str));
					fprintf(fcg,"move %s,$t0\n",val);
					(yyval.attr)->type=tchar;
				}
			}
			else
			{
				printf("ERROR:incorrect usage of postfix operator on line %d\n",yylineno);
				(yyval.attr)->type=tnone;
			}
		}			
	}
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 5707 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 5710 "parser.ypp"
    {
		(yyval.attr)=new struct attribute;
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		char *temp,*val=Address((yyvsp[(2) - (2)].attr)->contains);
		if(val[0]=='_' && val[1]=='T')
			temp=val;
		else
		{	
			temp=getNewTemp();
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
		}
		strcpy((yyval.attr)->contains,temp);
		enum refType t=Ref(val);
		if((yyvsp[(2) - (2)].attr)->token!=1)
			printf("ERROR:incorrect usage of unary operator on line %d\n",yylineno);
		else
		{
			if(!strcmp((yyvsp[(1) - (2)].str),"neg") || !strcmp((yyvsp[(1) - (2)].str),"not"))
			{
				if((yyvsp[(2) - (2)].attr)->type==tdouble || (yyvsp[(2) - (2)].attr)->type==tfloat) 
				{
					if(t==constant)
					{
						fprintf(fcg,"li.s $f0,%s\n",val);
						fprintf(fcg,"%s.s $f0,$f0\n",(yyvsp[(1) - (2)].str));
						fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					}
					else if(t==memory)
					{
						fprintf(fcg,"l.s $f0,%s\n",val);
						fprintf(fcg,"%s.s $f0,$f0\n",(yyvsp[(1) - (2)].str));
						fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					}
					else
					{
						fprintf(fcg,"mov.s $f0,%s\n",val);
						fprintf(fcg,"%s.s $f0,$f0\n",(yyvsp[(1) - (2)].str));
						fprintf(fcg,"mov.s %s,$f0\n",Address(temp));
					}
					(yyval.attr)->type=(yyvsp[(2) - (2)].attr)->type;
				}
				else if((yyvsp[(2) - (2)].attr)->type!=tboolean && (yyvsp[(2) - (2)].attr)->type!=tnone && (yyvsp[(2) - (2)].attr)->type!=tvoid)
				{
					if(t==constant)
					{
						fprintf(fcg,"li $t0,%s\n",val);
						fprintf(fcg,"%s $t0,$t0\n",(yyvsp[(1) - (2)].str));
						fprintf(fcg,"sw $t0,%s\n",Address(temp));
					}
					else if(t==memory)
					{
						fprintf(fcg,"lw $t0,%s\n",val);
						fprintf(fcg,"%s $t0,$t0\n",(yyvsp[(1) - (2)].str));
						fprintf(fcg,"sw $t0,%s\n",Address(temp));
					}
					else
					{
						fprintf(fcg,"move $t0,%s\n",val);
						fprintf(fcg,"%s $t0,$t0\n",(yyvsp[(1) - (2)].str));
						fprintf(fcg,"move %s,$t0\n",Address(temp));
					}
					(yyval.attr)->type=(yyvsp[(2) - (2)].attr)->type;
				}
				else
				{
					printf("ERROR:incorrect usage of unary operator on line %d\n",yylineno);
					(yyval.attr)->type=tnone;
				}
			}
			else if(!strcmp((yyvsp[(1) - (2)].str),"bnot"))
			{
				if((yyvsp[(2) - (2)].attr)->type==tboolean)
				{
					if(t==constant)
					{
						fprintf(fcg,"li $t0,%s\n",val);
						fprintf(fcg,"seq $t0,$t0,0\n");
						fprintf(fcg,"sw $t0,%s\n",Address(temp));
					}
					else if(t==memory)
					{
						fprintf(fcg,"lw $t0,%s\n",val);
						fprintf(fcg,"seq $t0,$t0,0\n");
						fprintf(fcg,"sw $t0,%s\n",Address(temp));
					}
					else
					{
						fprintf(fcg,"move $t0,%s\n",val);
						fprintf(fcg,"seq $t0,$t0,0\n");
						fprintf(fcg,"move %s,$t0\n",Address(temp));
					}
					(yyval.attr)->type=tboolean;
				}
				else
				{
					printf("ERROR:incorrect usage of not operator on line %d\n",yylineno);
					(yyval.attr)->type=tnone;
				}
			}
			else
			{
				if((yyvsp[(2) - (2)].attr)->type==tdouble || (yyvsp[(2) - (2)].attr)->type==tfloat) 
				{
					if(t==constant)
					{
						fprintf(fcg,"li.s $f0,%s\n",val);
						fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					}
					else if(t==memory)
					{
						fprintf(fcg,"l.s $f0,%s\n",val);
						fprintf(fcg,"s.s $f0,%s\n",Address(temp));
					}
					else
						fprintf(fcg,"mov.s %s,%s\n",Address(temp),val);
					(yyval.attr)->type=(yyvsp[(2) - (2)].attr)->type;
				}
				else if((yyvsp[(2) - (2)].attr)->type!=tboolean && (yyvsp[(2) - (2)].attr)->type!=tnone && (yyvsp[(2) - (2)].attr)->type!=tvoid && (yyvsp[(2) - (2)].attr)->type!=tnull)
				{
					if(t==constant)
					{
						fprintf(fcg,"li $t0,%s\n",val);
						fprintf(fcg,"sw $t0,%s\n",Address(temp));
					}
					else if(t==memory)
					{
						fprintf(fcg,"lw $t0,%s\n",val);
						fprintf(fcg,"sw $t0,%s\n",Address(temp));
					}
					else
						fprintf(fcg,"move %s,%s\n",Address(temp),val);
					(yyval.attr)->type=(yyvsp[(2) - (2)].attr)->type;
				}
				else
				{
					printf("ERROR:incorrect usage of unary operator on line %d\n",yylineno);
					(yyval.attr)->type=tnone;
				}
			}
				
		}
	}
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 5857 "parser.ypp"
    {
		(yyval.attr)=new struct attribute;
		(yyval.attr)=(yyvsp[(2) - (2)].attr);
		(yyval.attr)->type=(yyvsp[(1) - (2)].attr)->type;
	}
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 5863 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 5865 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Error in unary expression at line %d\n",yylineno);}
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 5869 "parser.ypp"
    {	
		(yyval.attr)=new struct attribute;
		(yyval.attr)->dimension=0;
		(yyval.attr)->token=1;
		strcpy((yyval.attr)->contains,(yyvsp[(2) - (2)].attr)->contains);
		char *val=Address((yyvsp[(2) - (2)].attr)->contains);
		enum refType t=Ref(val);
		if((yyvsp[(2) - (2)].attr)->token!=1)
			printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
		else
		{
			if((yyvsp[(2) - (2)].attr)->type==tdouble || (yyvsp[(2) - (2)].attr)->type==tfloat)
			{
				if(t==constant)
				{
					(yyval.attr)->type=tnone;
					printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
				}
				else if(t==memory)
				{
					fprintf(fcg,"l.s $f0,%s\n",val);
					fprintf(fcg,"li.s $f1,1.0\n");
					fprintf(fcg,"%s.s $f0,$f0,$f1\n",(yyvsp[(1) - (2)].str));
					fprintf(fcg,"s.s $f0,%s\n",val);
					(yyval.attr)->type=(yyvsp[(2) - (2)].attr)->type;
				}
				else
				{
					fprintf(fcg,"mov.s $f0,%s\n",val);
					fprintf(fcg,"li.s $f1,1.0\n");
					fprintf(fcg,"%s.s $f0,$f0,$f1\n",(yyvsp[(1) - (2)].str));
					fprintf(fcg,"mov.s %s,$f0\n",val);
					(yyval.attr)->type=(yyvsp[(2) - (2)].attr)->type;
				}
			}
			else if((yyvsp[(2) - (2)].attr)->type!=tboolean && (yyvsp[(2) - (2)].attr)->type!=tnone && (yyvsp[(2) - (2)].attr)->type!=tvoid && (yyvsp[(2) - (2)].attr)->type!=tnull)
			{
				if(t==constant)
				{
					(yyval.attr)->type=tnone;
					printf("ERROR:incorrect usage of postfix operator at line %d\n",yylineno);
				}
				else if(t==memory)
				{
					fprintf(fcg,"lw $t0,%s\n",val);
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(1) - (2)].str));
					fprintf(fcg,"sw $t0,%s\n",val);
					(yyval.attr)->type=(yyvsp[(2) - (2)].attr)->type;
				}
				else
				{
					fprintf(fcg,"move $t0,%s\n",val);
					fprintf(fcg,"%s $t0,$t0,1\n",(yyvsp[(1) - (2)].str));
					fprintf(fcg,"move %s,$t0\n",val);
					(yyval.attr)->type=(yyvsp[(2) - (2)].attr)->type;
				}
			}
			else
			{
				printf("ERROR:incorrect usage of postfix operator on line %d\n",yylineno);
				(yyval.attr)->type=tnone;
			}
		}			
	}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 5936 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;

		char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
		char *val2=Address((yyvsp[(3) - (3)].attr)->contains);
		char *temp;
		if((yyvsp[(1) - (3)].attr)->contains[0]=='_' && (yyvsp[(1) - (3)].attr)->contains[1]=='T')
			temp=val1;
		else if((yyvsp[(3) - (3)].attr)->contains[0]=='_' && (yyvsp[(3) - (3)].attr)->contains[1]=='T')
			temp=val2;
		else
		{	
			temp=getNewTemp();
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
		}
		strcpy((yyval.attr)->contains,temp);
		char *val3=Address(temp);
		enum refType t1=Ref(val1);
		enum refType t2=Ref(val2);
		//printf("%d %d\n",$1->type,$3->type);
		if((yyvsp[(1) - (3)].attr)->type==tdouble && (yyvsp[(3) - (3)].attr)->type!=tstring && (yyvsp[(3) - (3)].attr)->type!=tboolean && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tnone)
		{
			if(t1==constant)
				fprintf(fcg,"li.s $f0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"l.s $f0,%s\n",val1);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val1);
			if((yyvsp[(3) - (3)].attr)->type!=tdouble && (yyvsp[(3) - (3)].attr)->type!=tfloat)
			{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t2==constant)
					fprintf(fcg,"li.s $f1,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"l.s $f1,%s\n",val2);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val2);
			}
			if(!strcmp((yyvsp[(2) - (3)].str),"rem"))
				printf("ERROR:mod operator on floating point not supported\n");
			fprintf(fcg,"%s.s $f1,$f0,$f1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"s.s $f1,%s\n",val3);
			(yyval.attr)->type=tdouble;
		}
		else if((yyvsp[(1) - (3)].attr)->type==tfloat && (yyvsp[(3) - (3)].attr)->type!=tdouble \
		&& (yyvsp[(3) - (3)].attr)->type!=tstring && (yyvsp[(3) - (3)].attr)->type!=tboolean && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tnone)
		{
			if(t1==constant)
				fprintf(fcg,"li.s $f0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"l.s $f0,%s\n",val1);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val1);
			if((yyvsp[(3) - (3)].attr)->type!=tdouble && (yyvsp[(3) - (3)].attr)->type!=tfloat)
			{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t2==constant)
					fprintf(fcg,"li.s $f1,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"l.s $f1,%s\n",val2);
				else 
					fprintf(fcg,"mov.s $f1,%s\n",val2);
			}
			fprintf(fcg,"%s.s $f1,$f0,$f1\n",(yyvsp[(2) - (3)].str));
			if(!strcmp((yyvsp[(2) - (3)].str),"rem"))
				printf("ERROR:mod operator on floating point not supported\n");
			fprintf(fcg,"s.s $f1,%s\n",val3);
			(yyval.attr)->type=tfloat;			
		}
		else if((yyvsp[(1) - (3)].attr)->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tlong || (yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else 
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tlong;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tint && ((yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tint;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tshort && ((yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else 
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else 
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tshort;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tbyte && (yyvsp[(3) - (3)].attr)->type==tbyte )
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else 
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tbyte;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tchar && (yyvsp[(3) - (3)].attr)->type==tchar)
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			else 
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sb $t0,%s\n",val3);
                        (yyval.attr)->type=tchar;
		}	
		else if((yyvsp[(3) - (3)].attr)->type==tdouble && (yyvsp[(1) - (3)].attr)->type!=tstring && (yyvsp[(1) - (3)].attr)->type!=tboolean && (yyvsp[(1) - (3)].attr)->type!=tnull && (yyvsp[(1) - (3)].attr)->type!=tvoid && (yyvsp[(1) - (3)].attr)->type!=tnone)
		{
			if(t2==constant)
				fprintf(fcg,"li.s $f0,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"l.s $f0,%s\n",val2);
			else 
				fprintf(fcg,"mov.s $f0,%s\n",val2);
			if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
			{
				if(t1==constant)
					fprintf(fcg,"li $t0,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"lw $t0,%s\n",val1);
				else 
					fprintf(fcg,"move $t0,%s\n",val1);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t1==constant)
					fprintf(fcg,"li.s $f1,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"l.s $f1,%s\n",val1);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val1);
			}
			fprintf(fcg,"%s.s $f1,$f1,$f0\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"s.s $f1,%s\n",val3);
			(yyval.attr)->type=tdouble;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tfloat && (yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tstring && (yyvsp[(1) - (3)].attr)->type!=tboolean \
		&& (yyvsp[(1) - (3)].attr)->type!=tnull && (yyvsp[(1) - (3)].attr)->type!=tvoid && (yyvsp[(1) - (3)].attr)->type!=tnone) 
		{
			if(t2==constant)
				fprintf(fcg,"li.s $f0,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"l.s $f0,%s\n",val2);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val2);
			if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
			{
				if(t1==constant)
					fprintf(fcg,"li $t0,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"lw $t0,%s\n",val1);
				else
					fprintf(fcg,"move $t0,%s\n",val1);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t1==constant)
					fprintf(fcg,"li.s $f1,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"l.s $f1,%s\n",val1);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val1);
			}
			fprintf(fcg,"%s.s $f1,$f1,$f0\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"s.s $f1,%s\n",val3);
			(yyval.attr)->type=tfloat;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tlong && ((yyvsp[(1) - (3)].attr)->type==tlong || (yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tlong;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tint && ((yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tint;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tshort && ((yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tshort;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tbyte && (yyvsp[(1) - (3)].attr)->type==tbyte)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else 
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tbyte;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tchar && (yyvsp[(1) - (3)].attr)->type==tchar)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sb $t0,%s\n",val3);
                        (yyval.attr)->type=tchar;
		}
                else
                {
                        printf("ERROR:Incorrect usage of *,divide or mod on line %d\n",yylineno);
                        (yyval.attr)->type=tnone;
                }
	}
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 6280 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 6282 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Error in expression at line %d\n",yylineno);}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 6286 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
		char *val2=Address((yyvsp[(3) - (3)].attr)->contains);
		char *temp;
		if((yyvsp[(1) - (3)].attr)->contains[0]=='_' && (yyvsp[(1) - (3)].attr)->contains[1]=='T')
			temp=val1;
		else if((yyvsp[(3) - (3)].attr)->contains[0]=='_' && (yyvsp[(3) - (3)].attr)->contains[1]=='T')
			temp=val2;
		else
		{	
			temp=getNewTemp();
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
		}
		strcpy((yyval.attr)->contains,temp);
		char *val3=Address(temp);
		enum refType t1=Ref(val1);
		enum refType t2=Ref(val2);
	
		if((yyvsp[(1) - (3)].attr)->type==tdouble && (yyvsp[(3) - (3)].attr)->type!=tstring && (yyvsp[(3) - (3)].attr)->type!=tboolean && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tnone)
		{
			if(t1==constant)
				fprintf(fcg,"li.s $f0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"l.s $f0,%s\n",val1);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val1);
			if((yyvsp[(3) - (3)].attr)->type!=tdouble && (yyvsp[(3) - (3)].attr)->type!=tfloat)
			{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t2==constant)
					fprintf(fcg,"li.s $f1,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"l.s $f1,%s\n",val2);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val2);
			}
			fprintf(fcg,"%s.s $f1,$f0,$f1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"s.s $f1,%s\n",val3);
			(yyval.attr)->type=tdouble;
		}
		else if((yyvsp[(1) - (3)].attr)->type==tfloat && (yyvsp[(3) - (3)].attr)->type!=tdouble \
		&& (yyvsp[(3) - (3)].attr)->type!=tstring && (yyvsp[(3) - (3)].attr)->type!=tboolean && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tnone)
		{
			if(t1==constant)
				fprintf(fcg,"li.s $f0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"l.s $f0,%s\n",val1);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val1);
			if((yyvsp[(3) - (3)].attr)->type!=tdouble && (yyvsp[(3) - (3)].attr)->type!=tfloat)
			{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t2==constant)
					fprintf(fcg,"li.s $f1,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"l.s $f1,%s\n",val2);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val2);
			}
			fprintf(fcg,"%s.s $f1,$f0,$f1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"s.s $f1,%s\n",val3);
			(yyval.attr)->type=tfloat;			
		}
		else if((yyvsp[(1) - (3)].attr)->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tlong || (yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tlong;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tint && ((yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tint;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tshort && ((yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tshort;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tbyte && (yyvsp[(3) - (3)].attr)->type==tbyte )
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tbyte;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tchar && (yyvsp[(3) - (3)].attr)->type==tchar)
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sb $t0,%s\n",val3);
                        (yyval.attr)->type=tchar;
		}	
		else if((yyvsp[(3) - (3)].attr)->type==tdouble && (yyvsp[(1) - (3)].attr)->type!=tstring && (yyvsp[(1) - (3)].attr)->type!=tboolean && (yyvsp[(1) - (3)].attr)->type!=tnull && (yyvsp[(1) - (3)].attr)->type!=tvoid && (yyvsp[(1) - (3)].attr)->type!=tnone)
		{
			if(t2==constant)
				fprintf(fcg,"li.s $f0,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"l.s $f0,%s\n",val2);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val2);
			if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
			{
				if(t1==constant)
					fprintf(fcg,"li $t0,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"lw $t0,%s\n",val1);
				else
					fprintf(fcg,"move $t0,%s\n",val1);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t1==constant)
					fprintf(fcg,"li.s $f1,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"l.s $f1,%s\n",val1);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val1);
			}
			fprintf(fcg,"%s.s $f1,$f1,$f0\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"s.s $f1,%s\n",val3);
			(yyval.attr)->type=tdouble;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tfloat && (yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tstring && (yyvsp[(1) - (3)].attr)->type!=tboolean \
		&& (yyvsp[(1) - (3)].attr)->type!=tnull && (yyvsp[(1) - (3)].attr)->type!=tvoid && (yyvsp[(1) - (3)].attr)->type!=tnone) 
		{
			if(t2==constant)
				fprintf(fcg,"li.s $f0,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"l.s $f0,%s\n",val2);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val2);
			if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
			{
				if(t1==constant)
					fprintf(fcg,"li $t0,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"lw $t0,%s\n",val1);
				else
					fprintf(fcg,"move $t0,%s\n",val1);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t1==constant)
					fprintf(fcg,"li.s $f1,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"l.s $f1,%s\n",val1);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val1);
			}
			fprintf(fcg,"%s.s $f1,$f1,$f0\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"s.s $f1,%s\n",val3);
			(yyval.attr)->type=tfloat;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tlong && ((yyvsp[(1) - (3)].attr)->type==tlong || (yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tlong;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tint && ((yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tint;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tshort && ((yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tshort;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tbyte && (yyvsp[(1) - (3)].attr)->type==tbyte)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tbyte;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tchar && (yyvsp[(1) - (3)].attr)->type==tchar)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sb $t0,%s\n",val3);
                        (yyval.attr)->type=tchar;
		}
		else if((yyvsp[(1) - (3)].attr)->ref!=NULL && (yyvsp[(3) - (3)].attr)->ref!=NULL && !strcmp((yyvsp[(1) - (3)].attr)->ref,"String")  && !strcmp((yyvsp[(3) - (3)].attr)->ref,"String"))
		{
			(yyval.attr)->token=2;
			strcpy((yyval.attr)->ref,"String");			/*How to do string concatenation?*/
		}
                else
                {
                        printf("ERROR:Incorrect usage of +/- line %d\n",yylineno);
                        (yyval.attr)->type=tnone;
                }
	}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 6630 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 6632 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("Error in expression at line %d\n",yylineno);}
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 6636 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;

		
		char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
		char *val2=Address((yyvsp[(3) - (3)].attr)->contains);
		char *temp;
		if((yyvsp[(1) - (3)].attr)->contains[0]=='_' && (yyvsp[(1) - (3)].attr)->contains[1]=='T')
			temp=val1;
		else if((yyvsp[(3) - (3)].attr)->contains[0]=='_' && (yyvsp[(3) - (3)].attr)->contains[1]=='T')
			temp=val2;
		else
		{	
			temp=getNewTemp();
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
		}
		strcpy((yyval.attr)->contains,temp);
		char *val3=Address(temp);
		enum refType t1=Ref(val1);
		enum refType t2=Ref(val2);
	
		if((yyvsp[(1) - (3)].attr)->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tlong || (yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tlong;
		}				
                else if((yyvsp[(1) - (3)].attr)->type==tint && ((yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tint;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tshort && ((yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tshort;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tbyte && (yyvsp[(3) - (3)].attr)->type==tbyte)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tbyte;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tlong && ((yyvsp[(1) - (3)].attr)->type==tlong || (yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tlong;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tint && ((yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tint;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tshort && ((yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tshort;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tbyte && (yyvsp[(1) - (3)].attr)->type==tbyte )
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tbyte;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tchar && (yyvsp[(1) - (3)].attr)->type==tchar)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tchar;
		}
                else
                {
                        printf("ERROR:Incorrect usage of shift operator on line %d\n",yylineno);
                	(yyval.attr)->type=tnone;
		}
	}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 6829 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 6831 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("Error in expression at line %d\n",yylineno);}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 6835 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;

		
		char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
		char *val2=Address((yyvsp[(3) - (3)].attr)->contains);
		char *temp;
		if((yyvsp[(1) - (3)].attr)->contains[0]=='_' && (yyvsp[(1) - (3)].attr)->contains[1]=='T')
			temp=val1;
		else if((yyvsp[(3) - (3)].attr)->contains[0]=='_' && (yyvsp[(3) - (3)].attr)->contains[1]=='T')
			temp=val2;
		else
		{	
			temp=getNewTemp();
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
		}
		strcpy((yyval.attr)->contains,temp);
		char *val3=Address(temp);
		enum refType t1=Ref(val1);
		enum refType t2=Ref(val2);
	
		if((yyvsp[(1) - (3)].attr)->type==tdouble && (yyvsp[(3) - (3)].attr)->type!=tstring && (yyvsp[(3) - (3)].attr)->type!=tboolean && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tnone)
		{
			if(t1==constant)
				fprintf(fcg,"li.s $f0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"l.s $f0,%s\n",val1);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val1);
			if((yyvsp[(3) - (3)].attr)->type!=tdouble && (yyvsp[(3) - (3)].attr)->type!=tfloat)
			{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t2==constant)
					fprintf(fcg,"li.s $f1,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"l.s $f1,%s\n",val2);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val2);
			}
			char *t=(char *)malloc(10);
			strcpy(t,(yyvsp[(2) - (3)].str));
			t[0]='u';
			if(t[1]=='g')
			{
				t[1]='l';
				fprintf(fcg,"c.%s.s $f0,$f1\n",t);
				fprintf(fcg,"bc1f true%d\n",te++);
				fprintf(fcg,"li $t0,0\n");
				fprintf(fcg,"b done%d\n",te++);
				fprintf(fcg,"true%d:\n",te-2);
				fprintf(fcg,"li $t0,1\n");
				fprintf(fcg,"done%d:\n",te-1);
				fprintf(fcg,"sw $t0,%s\n",val3);
			}
			else
			{
				fprintf(fcg,"c.%s.s $f0,$f1\n",t);
				fprintf(fcg,"bc1t true%d\n",te++);
				fprintf(fcg,"li $t0,0\n");
				fprintf(fcg,"b done%d\n",te++);
				fprintf(fcg,"true%d:\n",te-2);
				fprintf(fcg,"li $t0,1\n");
				fprintf(fcg,"done%d:\n",te-1);
				fprintf(fcg,"sw $t0,%s\n",val3);
			}
			(yyval.attr)->type=tboolean;
		}
		else if((yyvsp[(1) - (3)].attr)->type==tfloat && (yyvsp[(3) - (3)].attr)->type!=tdouble \
		&& (yyvsp[(3) - (3)].attr)->type!=tstring && (yyvsp[(3) - (3)].attr)->type!=tboolean && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tnone)
		{
			if(t1==constant)
				fprintf(fcg,"li.s $f0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"l.s $f0,%s\n",val1);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val1);
			if((yyvsp[(3) - (3)].attr)->type!=tdouble && (yyvsp[(3) - (3)].attr)->type!=tfloat)
			{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t2==constant)
					fprintf(fcg,"li.s $f1,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"l.s $f1,%s\n",val2);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val2);
			}
			char *t=(char *)malloc(10);
			strcpy(t,(yyvsp[(2) - (3)].str));
			t[0]='u';
			if(t[1]=='g')
			{
				t[1]='l';
				fprintf(fcg,"c.%s.s $f0,$f1\n",t);
				fprintf(fcg,"bc1f true%d\n",te++);
				fprintf(fcg,"li $t0,0\n");
				fprintf(fcg,"b done%d\n",te++);
				fprintf(fcg,"true%d:\n",te-2);
				fprintf(fcg,"li $t0,1\n");
				fprintf(fcg,"done%d:\n",te-1);
				fprintf(fcg,"sw $t0,%s\n",val3);
			}
			else
			{
				fprintf(fcg,"c.%s.s $f0,$f1\n",t);
				fprintf(fcg,"bc1t true%d\n",te++);
				fprintf(fcg,"li $t0,0\n");
				fprintf(fcg,"b done%d\n",te++);
				fprintf(fcg,"true%d:\n",te-2);
				fprintf(fcg,"li $t0,1\n");
				fprintf(fcg,"done%d:\n",te-1);
				fprintf(fcg,"sw $t0,%s\n",val3);
			}
			(yyval.attr)->type=tboolean;			
		}
		else if((yyvsp[(1) - (3)].attr)->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tlong || (yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tint && ((yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tshort && ((yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tbyte && (yyvsp[(3) - (3)].attr)->type==tbyte )
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tchar && (yyvsp[(3) - (3)].attr)->type==tchar)
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}	
		else if((yyvsp[(3) - (3)].attr)->type==tdouble && (yyvsp[(1) - (3)].attr)->type!=tstring && (yyvsp[(1) - (3)].attr)->type!=tboolean && (yyvsp[(1) - (3)].attr)->type!=tnull && (yyvsp[(1) - (3)].attr)->type!=tvoid && (yyvsp[(1) - (3)].attr)->type!=tnone)
		{
			if(t2==constant)
				fprintf(fcg,"li.s $f0,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"l.s $f0,%s\n",val2);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val2);
			if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
			{
				if(t1==constant)
					fprintf(fcg,"li $t0,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"lw $t0,%s\n",val1);
				else
					fprintf(fcg,"move $t0,%s\n",val1);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t1==constant)
					fprintf(fcg,"li.s $f1,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"l.s $f1,%s\n",val1);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val1);
			}
			char *t=(char *)malloc(10);
			strcpy(t,(yyvsp[(2) - (3)].str));
			t[0]='u';
			if(t[1]=='g')
			{
				t[1]='l';
				fprintf(fcg,"c.%s.s $f0,$f1\n",t);
				fprintf(fcg,"bc1f true%d\n",te++);
				fprintf(fcg,"li $t0,0\n");
				fprintf(fcg,"b done%d\n",te++);
				fprintf(fcg,"true%d:\n",te-2);
				fprintf(fcg,"li $t0,1\n");
				fprintf(fcg,"done%d:\n",te-1);
				fprintf(fcg,"sw $t0,%s\n",val3);
			}
			else
			{
				fprintf(fcg,"c.%s.s $f0,$f1\n",t);
				fprintf(fcg,"bc1t true%d\n",te++);
				fprintf(fcg,"li $t0,0\n");
				fprintf(fcg,"b done%d\n",te++);
				fprintf(fcg,"true%d:\n",te-2);
				fprintf(fcg,"li $t0,1\n");
				fprintf(fcg,"done%d:\n",te-1);
				fprintf(fcg,"sw $t0,%s\n",val3);
			}
			(yyval.attr)->type=tboolean;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tfloat && (yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tstring && (yyvsp[(1) - (3)].attr)->type!=tboolean \
		&& (yyvsp[(1) - (3)].attr)->type!=tnull && (yyvsp[(1) - (3)].attr)->type!=tvoid && (yyvsp[(1) - (3)].attr)->type!=tnone) 
		{
			if(t2==constant)
				fprintf(fcg,"li.s $f0,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"l.s $f0,%s\n",val2);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val2);
			if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
			{
				if(t1==constant)
					fprintf(fcg,"li $t0,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"lw $t0,%s\n",val1);
				else
					fprintf(fcg,"move $t0,%s\n",val1);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t1==constant)
					fprintf(fcg,"li.s $f1,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"l.s $f1,%s\n",val1);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val1);
			}
			char *t=(char *)malloc(10);
			strcpy(t,(yyvsp[(2) - (3)].str));
			t[0]='u';
			if(t[1]=='g')
			{
				t[1]='l';
				fprintf(fcg,"c.%s.s $f0,$f1\n",t);
				fprintf(fcg,"bc1f true%d\n",te++);
				fprintf(fcg,"li $t0,0\n");
				fprintf(fcg,"b done%d\n",te++);
				fprintf(fcg,"true%d:\n",te-2);
				fprintf(fcg,"li $t0,1\n");
				fprintf(fcg,"done%d:\n",te-1);
				fprintf(fcg,"sw $t0,%s\n",val3);
			}
			else
			{
				fprintf(fcg,"c.%s.s $f0,$f1\n",t);
				fprintf(fcg,"bc1t true%d\n",te++);
				fprintf(fcg,"li $t0,0\n");
				fprintf(fcg,"b done%d\n",te++);
				fprintf(fcg,"true%d:\n",te-2);
				fprintf(fcg,"li $t0,1\n");
				fprintf(fcg,"done%d:\n",te-1);
				fprintf(fcg,"sw $t0,%s\n",val3);
			}
			(yyval.attr)->type=tboolean;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tlong && ((yyvsp[(1) - (3)].attr)->type==tlong || (yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tint && ((yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tshort && ((yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tbyte && (yyvsp[(1) - (3)].attr)->type==tbyte)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tchar && (yyvsp[(1) - (3)].attr)->type==tchar)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else
                {
                        printf("ERROR:Incorrect usage of relop on line %d\n",yylineno);
                        (yyval.attr)->type=tnone;
                }
		
	}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 7273 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 7275 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("Error in expression at line %d\n",yylineno);}
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 7279 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;

		
		char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
		char *val2=Address((yyvsp[(3) - (3)].attr)->contains);
		char *temp;
		if((yyvsp[(1) - (3)].attr)->contains[0]=='_' && (yyvsp[(1) - (3)].attr)->contains[1]=='T')
			temp=val1;
		else if((yyvsp[(3) - (3)].attr)->contains[0]=='_' && (yyvsp[(3) - (3)].attr)->contains[1]=='T')
			temp=val2;
		else
		{	
			temp=getNewTemp();
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
		}
		strcpy((yyval.attr)->contains,temp);
		char *val3=Address(temp);
		enum refType t1=Ref(val1);
		enum refType t2=Ref(val2);
	
		if((yyvsp[(1) - (3)].attr)->type==tdouble && (yyvsp[(3) - (3)].attr)->type!=tstring && (yyvsp[(3) - (3)].attr)->type!=tboolean && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tnone)
		{
			if(t1==constant)
				fprintf(fcg,"li.s $f0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"l.s $f0,%s\n",val1);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val1);
			if((yyvsp[(3) - (3)].attr)->type!=tdouble && (yyvsp[(3) - (3)].attr)->type!=tfloat)
			{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t2==constant)
					fprintf(fcg,"li.s $f1,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"l.s $f1,%s\n",val2);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val2);
			}
			fprintf(fcg,"c.seq.s $f0,$f1\n");
			if(!strcmp((yyvsp[(2) - (3)].str),"seq"))
				fprintf(fcg,"bc1t true%d\n",te++);
			else
				fprintf(fcg,"bc1f true%d\n",te++);
			fprintf(fcg,"li $t0,0\n");
			fprintf(fcg,"b done%d\n",te++);
			fprintf(fcg,"true%d:\n",te-2);
			fprintf(fcg,"li $t0,1\n");
			fprintf(fcg,"done%d:\n",te-1);
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tboolean;
		}
		else if((yyvsp[(1) - (3)].attr)->type==tfloat && (yyvsp[(3) - (3)].attr)->type!=tdouble \
		&& (yyvsp[(3) - (3)].attr)->type!=tstring && (yyvsp[(3) - (3)].attr)->type!=tboolean && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tnone)
		{
			if(t1==constant)
				fprintf(fcg,"li.s $f0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"l.s $f0,%s\n",val1);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val1);
			if((yyvsp[(3) - (3)].attr)->type!=tdouble && (yyvsp[(3) - (3)].attr)->type!=tfloat)
			{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t2==constant)
					fprintf(fcg,"li.s $f1,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"l.s $f1,%s\n",val2);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val2);
			}
			fprintf(fcg,"c.%s.s $f0,$f1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"bc1t true%d\n",te++);
			fprintf(fcg,"li $t0,0\n");
			fprintf(fcg,"b done%d\n",te++);
			fprintf(fcg,"true%d:\n",te-2);
			fprintf(fcg,"li $t0,1\n");
			fprintf(fcg,"done%d:\n",te-1);
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tboolean;			
		}
		else if((yyvsp[(1) - (3)].attr)->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tlong || (yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tint && ((yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tshort && ((yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tbyte && (yyvsp[(3) - (3)].attr)->type==tbyte )
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tchar && (yyvsp[(3) - (3)].attr)->type==tchar)
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}	
		else if((yyvsp[(3) - (3)].attr)->type==tdouble && (yyvsp[(1) - (3)].attr)->type!=tstring && (yyvsp[(1) - (3)].attr)->type!=tboolean && (yyvsp[(1) - (3)].attr)->type!=tnull && (yyvsp[(1) - (3)].attr)->type!=tvoid && (yyvsp[(1) - (3)].attr)->type!=tnone)
		{
			if(t2==constant)
				fprintf(fcg,"li.s $f0,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"l.s $f0,%s\n",val2);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val2);
			if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
			{
				if(t1==constant)
					fprintf(fcg,"li $t0,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"lw $t0,%s\n",val1);
				else
					fprintf(fcg,"move $t0,%s\n",val1);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t1==constant)
					fprintf(fcg,"li.s $f1,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"l.s $f1,%s\n",val1);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val1);
			}
			fprintf(fcg,"%s $f1,$f0,$f1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"s.s $f1,%s\n",val3);
			(yyval.attr)->type=tboolean;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tfloat && (yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tstring && (yyvsp[(1) - (3)].attr)->type!=tboolean \
		&& (yyvsp[(1) - (3)].attr)->type!=tnull && (yyvsp[(1) - (3)].attr)->type!=tvoid && (yyvsp[(1) - (3)].attr)->type!=tnone) 
		{
			if(t2==constant)
				fprintf(fcg,"li.s $f0,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"l.s $f0,%s\n",val2);
			else
				fprintf(fcg,"mov.s $f0,%s\n",val2);
			if((yyvsp[(1) - (3)].attr)->type!=tdouble && (yyvsp[(1) - (3)].attr)->type!=tfloat)
			{
				if(t1==constant)
					fprintf(fcg,"li $t0,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"lw $t0,%s\n",val1);
				else
					fprintf(fcg,"move $t0,%s\n",val1);
				fprintf(fcg,"mtc1 $t0,$f1\n");
				fprintf(fcg,"cvt.s.w $f1,$f1\n");
			}
			else
			{
				if(t1==constant)
					fprintf(fcg,"li.s $f1,%s\n",val1);
				else if(t1==memory)
					fprintf(fcg,"l.s $f1,%s\n",val1);
				else
					fprintf(fcg,"mov.s $f1,%s\n",val1);
			}
			fprintf(fcg,"%s $f1,$f0,$f1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"s.s $f1,%s\n",val3);
			(yyval.attr)->type=tboolean;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tlong && ((yyvsp[(1) - (3)].attr)->type==tlong || (yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"lw $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tint && ((yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tshort && ((yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tbyte && (yyvsp[(1) - (3)].attr)->type==tbyte)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tchar && (yyvsp[(1) - (3)].attr)->type==tchar)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"%s $t0,$t0,$t1\n",(yyvsp[(2) - (3)].str));
			fprintf(fcg,"sw $t0,%s\n",val3);
                        (yyval.attr)->type=tboolean;
		}
		else if((yyvsp[(1) - (3)].attr)->ref!=NULL && (yyvsp[(3) - (3)].attr)->ref!=NULL && !strcmp((yyvsp[(1) - (3)].attr)->ref,(yyvsp[(3) - (3)].attr)->ref))
		{
			strcpy((yyval.attr)->ref,(yyvsp[(1) - (3)].attr)->ref);
			(yyval.attr)->token=2;
		}
                else
                {
                        printf("ERROR:Incorrect usage of == on line %d\n",yylineno);
                        (yyval.attr)->type=tnone;
                }
		
	}
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 7641 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 7643 "parser.ypp"
    {(yyval.attr)->type=tnone;printf("ERROR:Error in expression at line %d\n",yylineno);}
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 7647 "parser.ypp"
    {	
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		
		char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
		char *val2=Address((yyvsp[(3) - (3)].attr)->contains);
		char *temp;
		if((yyvsp[(1) - (3)].attr)->contains[0]=='_' && (yyvsp[(1) - (3)].attr)->contains[1]=='T')
			temp=val1;
		else if((yyvsp[(3) - (3)].attr)->contains[0]=='_' && (yyvsp[(3) - (3)].attr)->contains[1]=='T')
			temp=val2;
		else
		{	
			temp=getNewTemp();
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
		}
		strcpy((yyval.attr)->contains,temp);
		char *val3=Address(temp);
		enum refType t1=Ref(val1);
		enum refType t2=Ref(val2);
		if((yyvsp[(1) - (3)].attr)->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tlong || (yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tlong;
		}				
                else if((yyvsp[(1) - (3)].attr)->type==tint && ((yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tint;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tshort && ((yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tshort;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tbyte && (yyvsp[(3) - (3)].attr)->type==tbyte)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tbyte;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tlong && ((yyvsp[(1) - (3)].attr)->type==tlong || (yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tlong;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tint && ((yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"lw $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tint;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tshort && ((yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tshort;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tbyte && (yyvsp[(1) - (3)].attr)->type==tbyte )
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tbyte;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tchar && (yyvsp[(1) - (3)].attr)->type==tchar)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tchar;
		}
                else
                {
                        printf("ERROR:Incorrect usage of & on line %d\n",yylineno);
			(yyval.attr)->type=tnone;
               	}
	}
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 7839 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 7841 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Error in expression at line %d\n",yylineno);}
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 7845 "parser.ypp"
    {	
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		
		char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
		char *val2=Address((yyvsp[(3) - (3)].attr)->contains);
		char *temp;
		if((yyvsp[(1) - (3)].attr)->contains[0]=='_' && (yyvsp[(1) - (3)].attr)->contains[1]=='T')
			temp=val1;
		else if((yyvsp[(3) - (3)].attr)->contains[0]=='_' && (yyvsp[(3) - (3)].attr)->contains[1]=='T')
			temp=val2;
		else
		{	
			temp=getNewTemp();
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
		}
		strcpy((yyval.attr)->contains,temp);
		char *val3=Address(temp);
		enum refType t1=Ref(val1);
		enum refType t2=Ref(val2);
		
		if((yyvsp[(1) - (3)].attr)->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tlong || (yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"xor $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tlong;
		}				
                else if((yyvsp[(1) - (3)].attr)->type==tint && ((yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"xor $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tint;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tshort && ((yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"xor $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tshort;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tbyte && (yyvsp[(3) - (3)].attr)->type==tbyte)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"xor $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tbyte;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tlong && ((yyvsp[(1) - (3)].attr)->type==tlong || (yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"xor $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tlong;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tint && ((yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"xor $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tint;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tshort && ((yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"xor $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tshort;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tbyte && (yyvsp[(1) - (3)].attr)->type==tbyte )
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"xor $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tbyte;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tchar && (yyvsp[(1) - (3)].attr)->type==tchar)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"xor $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tchar;
		}
                else
                {
                        printf("ERROR:Incorrect usage of ^ on line %d\n",yylineno);
                        (yyval.attr)->type=tnone;
                }
	}
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 8038 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 8040 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Error in expression at line %d\n",yylineno);}
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 8044 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		
		char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
		char *val2=Address((yyvsp[(3) - (3)].attr)->contains);
		char *temp;
		if((yyvsp[(1) - (3)].attr)->contains[0]=='_' && (yyvsp[(1) - (3)].attr)->contains[1]=='T')
			temp=val1;
		else if((yyvsp[(3) - (3)].attr)->contains[0]=='_' && (yyvsp[(3) - (3)].attr)->contains[1]=='T')
			temp=val2;
		else
		{	
			temp=getNewTemp();
			int off=(temp[2]-'0')*10+temp[3]-'0';
			offset_temp[off]=-num_var*4;
			num_var++;
		}
		strcpy((yyval.attr)->contains,temp);
		char *val3=Address(temp);
		enum refType t1=Ref(val1);
		enum refType t2=Ref(val2);
		
		if((yyvsp[(1) - (3)].attr)->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tlong || (yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"or $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tlong;
		}				
                else if((yyvsp[(1) - (3)].attr)->type==tint && ((yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"or $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tint;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tshort && ((yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"or $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tshort;
		}
                else if((yyvsp[(1) - (3)].attr)->type==tbyte && (yyvsp[(3) - (3)].attr)->type==tbyte)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"or $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tbyte;
		}
		else if((yyvsp[(3) - (3)].attr)->type==tlong && ((yyvsp[(1) - (3)].attr)->type==tlong || (yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"or $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tlong;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tint && ((yyvsp[(1) - (3)].attr)->type==tint || (yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort || (yyvsp[(1) - (3)].attr)->type==tchar))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"or $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tint;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tshort && ((yyvsp[(1) - (3)].attr)->type==tbyte || (yyvsp[(1) - (3)].attr)->type==tshort))
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"or $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tshort;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tbyte && (yyvsp[(1) - (3)].attr)->type==tbyte )
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"or $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tbyte;
		}
                else if((yyvsp[(3) - (3)].attr)->type==tchar && (yyvsp[(1) - (3)].attr)->type==tchar)
                {
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lb $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lb $t1,%s\n",val2);
			fprintf(fcg,"or $t0,$t0,$t1\n");
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tchar;
		}	
                else
                {
                        printf("ERROR:Incorrect usage of | on line %d\n",yylineno);
                        (yyval.attr)->type=tnone;
                }
	}
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 8235 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 8237 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Error in expression at line %d\n",yylineno);}
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 8241 "parser.ypp"
    {
		char *val1=Address((yyvsp[(1) - (2)].attr)->contains);
		enum refType t1=Ref(val1);
		if((yyvsp[(1) - (2)].attr)->type==tboolean)
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			labels.push(num_label++);
			fprintf(fcg,"beqz $t0,L%d\n",labels.top());
		}
		else
			printf("ERROR:incorrect usage of && operator at line %d\n",yylineno);
	}
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 8259 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		char *temp=getNewTemp();
		
		int i;
		for(i=0;i<strlen(temp);i++)
			(yyval.attr)->contains[i]=temp[i];
		(yyval.attr)->contains[i]='\0';

		int off=(temp[2]-'0')*10+temp[3]-'0';
		offset_temp[off]=-num_var*4;
		num_var++;
		char *val2=Address((yyvsp[(4) - (4)].attr)->contains);
		char *val3=Address(temp);
		enum refType t2=Ref(val2);
                if((yyvsp[(1) - (4)].attr)->type==tboolean && (yyvsp[(4) - (4)].attr)->type==tboolean)
                {
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"L%d:\n",labels.top());
			labels.pop();
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tboolean;
		}
                else
                {
                        printf("ERROR:Incorrect usage of && on line %d\n",yylineno);
                        (yyval.attr)->type=tnone;
                }
	}
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 8296 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 8298 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Error in expression at line %d\n",yylineno);}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 8302 "parser.ypp"
    {	
		char *val1=Address((yyvsp[(1) - (2)].attr)->contains);
		enum refType t1=Ref(val1);
		if((yyvsp[(1) - (2)].attr)->type==tboolean)
		{
			if(t1==constant)
				fprintf(fcg,"li $t0,%s\n",val1);
			else if(t1==memory)
				fprintf(fcg,"lw $t0,%s\n",val1);
			else
				fprintf(fcg,"move $t0,%s\n",val1);
			labels.push(num_label++);
			fprintf(fcg,"bnez $t0,L%d\n",labels.top());
		}
		else
			printf("ERROR:incorrect usage of || operator at line %d\n",yylineno);
	}
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 8320 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;

		char *temp=getNewTemp();

		int i;
		for(i=0;i<strlen(temp);i++)
			(yyval.attr)->contains[i]=temp[i];
		(yyval.attr)->contains[i]='\0';

		int off=(temp[2]-'0')*10+temp[3]-'0';
		offset_temp[off]=-num_var*4;
		num_var++;
		char *val2=Address((yyvsp[(4) - (4)].attr)->contains);
		char *val3=Address(temp);
		enum refType t2=Ref(val2);
                if((yyvsp[(1) - (4)].attr)->type==tboolean && (yyvsp[(4) - (4)].attr)->type==tboolean)
                {
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
			fprintf(fcg,"and $t0,$t0,$t1\n");
			fprintf(fcg,"L%d:\n",labels.top());
			labels.pop();
			fprintf(fcg,"sw $t0,%s\n",val3);
			(yyval.attr)->type=tboolean;
		}
                else
                {
                        printf("ERROR:Incorrect usage of && on line %d\n",yylineno);
                        (yyval.attr)->type=tnone;
                }
	}
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 8358 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 8360 "parser.ypp"
    {(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Error in expression at line %d\n",yylineno);}
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 8363 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 8366 "parser.ypp"
    {
		 char *val1=Address((yyvsp[(1) - (2)].attr)->contains);
		 enum refType t1=Ref(val1);
		 if(t1==constant)
			fprintf(fcg,"li $t0,%s\n",val1);
		else if(t1==memory)
			fprintf(fcg,"lw $t0,%s\n",val1);
		else
			fprintf(fcg,"move $t0,%s\n",val1);
		labels.push(num_label++);
		fprintf(fcg,"beqz $t0,L%d\n",labels.top());
	}
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 8379 "parser.ypp"
    {
		char *val2=Address((yyvsp[(4) - (4)].attr)->contains);
		enum refType t2=Ref(val2);
		if((yyvsp[(4) - (4)].attr)->type==tfloat || (yyvsp[(4) - (4)].attr)->type==tdouble)
		{
			if(t2==constant)
				fprintf(fcg,"li.s $f1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"l.s $f1,%s\n",val2);
			else
				fprintf(fcg,"mov.s $f1,%s\n",val2);
		}
		else
		{							
			if(t2==constant)
				fprintf(fcg,"li $t1,%s\n",val2);
			else if(t2==memory)
				fprintf(fcg,"lw $t1,%s\n",val2);
			else
				fprintf(fcg,"move $t1,%s\n",val2);
		}
		int val=labels.top();
		labels.pop();
		labels.push(num_label++);
		fprintf(fcg,"b L%d\n",labels.top());
		fprintf(fcg,"L%d:\n",val);
	}
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 8406 "parser.ypp"
    {	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		(yyval.attr)->token=1;
		(yyval.attr)->dimension=0;
		char *temp=getNewTemp();

		int i;
		for(i=0;i<strlen(temp);i++)
			(yyval.attr)->contains[i]=temp[i];
		(yyval.attr)->contains[i]='\0';

		int off=(temp[2]-'0')*10+temp[3]-'0';
		offset_temp[off]=-num_var*4;
		num_var++;
		char *val3=Address((yyvsp[(7) - (7)].attr)->contains);
		enum refType t3=Ref(val3);
		if((yyvsp[(1) - (7)].attr)->type==tboolean)
		{
			if((yyvsp[(4) - (7)].attr)->type!=tnone && (yyvsp[(7) - (7)].attr)->type!=tnone)
			{
				if(((yyvsp[(4) - (7)].attr)->type==tboolean && (yyvsp[(7) - (7)].attr)->type!=tboolean) || ((yyvsp[(7) - (7)].attr)->type==tboolean && (yyvsp[(4) - (7)].attr)->type!=tboolean))
				{
					(yyval.attr)->type=tnone;
					printf("ERROR:erroneous comparison at line %d\n",yylineno);
				}
				else
				{
					if((yyvsp[(7) - (7)].attr)->type==tfloat || (yyvsp[(7) - (7)].attr)->type==tdouble)
					{
						if(t3==constant)
							fprintf(fcg,"li.s $f2,%s\n",val3);
						else if(t3==memory)
							fprintf(fcg,"l.s $f2,%s\n",val3);
						else
							fprintf(fcg,"mov.s $f2,%s\n",val3);
					}
					else
					{							
						if(t3==constant)
							fprintf(fcg,"li $t2,%s\n",val3);
						else if(t3==memory)
							fprintf(fcg,"lw $t2,%s\n",val3);
						else
							fprintf(fcg,"move $t2,%s\n",val3);
					}
					if((yyvsp[(7) - (7)].attr)->type==tdouble || (yyvsp[(7) - (7)].attr)->type==tfloat)
						fprintf(fcg,"s.s $f2,%s\n",Address(temp));
					else
						fprintf(fcg,"sw $t2,%s\n",Address(temp));
					fprintf(fcg,"b L%d\n",num_label++);
					fprintf(fcg,"L%d:\n",labels.top());
					if((yyvsp[(4) - (7)].attr)->type==tdouble || (yyvsp[(4) - (7)].attr)->type==tfloat)
						fprintf(fcg,"s.s $f1,%s\n",Address(temp));
					else
						fprintf(fcg,"sw $t1,%s\n",Address(temp));
					labels.pop();
					fprintf(fcg,"L%d:\n",num_label-1);
					if((yyvsp[(4) - (7)].attr)->type==tdouble || (yyvsp[(7) - (7)].attr)->type==tdouble)
						(yyval.attr)->type=tdouble;
					else if((yyvsp[(4) - (7)].attr)->type==tfloat || (yyvsp[(7) - (7)].attr)->type==tfloat)
						(yyval.attr)->type=tfloat;
					else
						(yyval.attr)->type=(yyvsp[(7) - (7)].attr)->type;
				}
			}
			else
			{
				printf("ERROR:Type mismatch at line %d\n",yylineno);
				(yyval.attr)->type=tnone;
			}
		}
		else
			(yyval.attr)->type=tnone;
	}
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 8480 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Error in ternary expression on line %d\n",yylineno);}
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 8483 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 8485 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 409:

/* Line 1806 of yacc.c  */
#line 8489 "parser.ypp"
    {  
	   	(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
		char *val2=Address((yyvsp[(3) - (3)].attr)->contains);
		//printf("%s %s %d %d\n",val1,val2,$1->token,$3->token);
		enum refType t1=Ref(val1);
		enum refType t2=Ref(val2);
		jump_found=false;
	   	if(((yyvsp[(1) - (3)].attr)->token==1 && (yyvsp[(3) - (3)].attr)->token==1) || ((yyvsp[(1) - (3)].attr)->token==3 && (yyvsp[(3) - (3)].attr)->token==3))
	   	{
			if((yyvsp[(1) - (3)].attr)->type==tdouble && (yyvsp[(3) - (3)].attr)->type!=tstring && (yyvsp[(3) - (3)].attr)->type!=tnull && (yyvsp[(3) - (3)].attr)->type!=tnone && (yyvsp[(3) - (3)].attr)->type!=tvoid && (yyvsp[(3) - (3)].attr)->type!=tboolean)
			{
				if((yyvsp[(3) - (3)].attr)->token==1)
				{
					if((yyvsp[(3) - (3)].attr)->type==tdouble || (yyvsp[(3) - (3)].attr)->type==tfloat)
					{
						if(t2==constant)
							fprintf(fcg,"li.s $f0,%s\n",val2);
						else if(t2==memory)
							fprintf(fcg,"l.s $f0,%s\n",val2);
						else
							fprintf(fcg,"mov.s $f0,%s\n",val2);
					}
					else
					{
						if(t2==constant)
							fprintf(fcg,"li $t0,%s\n",val2);
						else if(t2==memory)
							fprintf(fcg,"lw $t0,%s\n",val2);
						else
							fprintf(fcg,"move $t0,%s\n",val2);
						fprintf(fcg,"mtc1 $t0,$f0\n");
						fprintf(fcg,"cvt.s.w $f0,$f0\n");
					}	
					if(!strcmp((yyvsp[(2) - (3)].str),"="))
					{
						(yyval.attr)=(yyvsp[(1) - (3)].attr);
						if(t1==memory)
							fprintf(fcg,"s.s $f0,%s\n",val1);
						else
							fprintf(fcg,"mov.s %s,$f0\n",val1);
					}
					else if(!strcmp((yyvsp[(2) - (3)].str),"add") || !strcmp((yyvsp[(2) - (3)].str),"sub") || !strcmp((yyvsp[(2) - (3)].str),"mul") || !strcmp((yyvsp[(2) - (3)].str),"div") || !strcmp((yyvsp[(2) - (3)].str),"rem"))
					{
						(yyval.attr)=(yyvsp[(1) - (3)].attr);
						if(t1==memory)
						{
							fprintf(fcg,"l.s $f1,%s\n",val1);
							fprintf(fcg,"%s.s $f1,$f1,$f0\n",(yyvsp[(2) - (3)].str));
							fprintf(fcg,"s.s $f1,%s\n",val1);
						}
						else
						{
							fprintf(fcg,"mov.s $f1,%s\n",val1);
							fprintf(fcg,"%s.s $f1,$f1,$f0\n",(yyvsp[(2) - (3)].str));
							fprintf(fcg,"mov.s %s,$f1\n",val1);
						}
					}
					else
					{
						(yyval.attr)=(yyvsp[(1) - (3)].attr);
						(yyval.attr)->type=tnone;
						printf("ERROR:incorrect assignment at line %d\n",yylineno);
					}
				}
				else
				{
					if(t2==constant)
						fprintf(fcg,"li $t0,%s\n",val2);
					else if(t2==memory)
						fprintf(fcg,"lw $t0,%s\n",val2);
					else
						fprintf(fcg,"move $t0,%s\n",val2);
					fprintf(fcg,"move %s,$t0\n",val1);
				}
			}
			else if((yyvsp[(1) - (3)].attr)->type==tfloat && !((yyvsp[(3) - (3)].attr)->type==tdouble || (yyvsp[(3) - (3)].attr)->type==tstring || (yyvsp[(3) - (3)].attr)->type==tnull || (yyvsp[(3) - (3)].attr)->type==tnone || (yyvsp[(3) - (3)].attr)->type==tvoid))
			{
				if((yyvsp[(3) - (3)].attr)->token==1)
				{
					if((yyvsp[(3) - (3)].attr)->type==tdouble || (yyvsp[(3) - (3)].attr)->type==tfloat)
					{
						if(t2==constant)
							fprintf(fcg,"li.s $f0,%s\n",val2);
						else if(t2==memory)
							fprintf(fcg,"l.s $f0,%s\n",val2);
						else
							fprintf(fcg,"mov.s $f0,%s\n",val2);
					}
					else
					{
						if(t2==constant)
							fprintf(fcg,"li $t0,%s\n",val2);
						else if(t2==memory)
							fprintf(fcg,"lw $t0,%s\n",val2);
						else
							fprintf(fcg,"move $t0,%s\n",val2);
						fprintf(fcg,"mtc1 $t0,$f0\n");
						fprintf(fcg,"cvt.s.w $f0,$f0\n");
					}	
					if(!strcmp((yyvsp[(2) - (3)].str),"="))
					{
						(yyval.attr)=(yyvsp[(1) - (3)].attr);
						if(t1==memory)
							fprintf(fcg,"s.s $f0,%s\n",val1);
						else
							fprintf(fcg,"mov.s %s,$f0\n",val1);
					}
					else if(!strcmp((yyvsp[(2) - (3)].str),"add") || !strcmp((yyvsp[(2) - (3)].str),"sub") || !strcmp((yyvsp[(2) - (3)].str),"mul") || !strcmp((yyvsp[(2) - (3)].str),"div") || !strcmp((yyvsp[(2) - (3)].str),"rem"))
					{
						(yyval.attr)=(yyvsp[(1) - (3)].attr);
						if(t1==memory)
						{
							fprintf(fcg,"l.s $f1,%s\n",val1);
							fprintf(fcg,"%s.s $f1,$f1,$f0\n",(yyvsp[(2) - (3)].str));
							fprintf(fcg,"s.s $f1,%s\n",val1);
						}
						else
						{
							fprintf(fcg,"mov.s $f1,%s\n",val1);
							fprintf(fcg,"%s.s $f1,$f1,$f0\n",(yyvsp[(2) - (3)].str));
							fprintf(fcg,"mov.s %s,$f1\n",val1);
						}
					}
					else
					{
						(yyval.attr)=(yyvsp[(1) - (3)].attr);
						(yyval.attr)->type=tnone;
						printf("ERROR:incorrect assignment at line %d\n",yylineno);
					}
				}
				else
				{
					if(t2==constant)
						fprintf(fcg,"li $t0,%s\n",val2);
					else if(t2==memory)
						fprintf(fcg,"lw $t0,%s\n",val2);
					else
						fprintf(fcg,"move $t0,%s\n",val2);
					fprintf(fcg,"move %s,$t0\n",val1);
				}
			}		
			else if((yyvsp[(1) - (3)].attr)->type==tlong && ((yyvsp[(3) - (3)].attr)->type==tlong || (yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
                        {
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				if(!strcmp((yyvsp[(2) - (3)].str),"="))
				{
					if(t1==memory)
						fprintf(fcg,"sw $t0,%s\n",val1);
					else
						fprintf(fcg,"move %s,$t0\n",val1);
				}
				else 
				{
					if(t1==memory)
					{
						fprintf(fcg,"lw $t1,%s\n",val1);
						fprintf(fcg,"%s $t1,$t1,$t0\n",(yyvsp[(2) - (3)].str));
						fprintf(fcg,"sw $t1,%s\n",val1);
					}
					else
					{
						fprintf(fcg,"move $t1,%s\n",val1);
						fprintf(fcg,"%s $t1,$t1,$t0\n",(yyvsp[(2) - (3)].str));
						fprintf(fcg,"move %s,$t1\n",val1);
					}
				}
				(yyval.attr)=(yyvsp[(1) - (3)].attr);
			}
			else if((yyvsp[(1) - (3)].attr)->type==tint && ((yyvsp[(3) - (3)].attr)->type==tint || (yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort || (yyvsp[(3) - (3)].attr)->type==tchar))
                       	{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				if(!strcmp((yyvsp[(2) - (3)].str),"="))
				{
					if(t1==memory)
						fprintf(fcg,"sw $t0,%s\n",val1);
					else
						fprintf(fcg,"move %s,$t0\n",val1);
				}
				else 
				{
					if(t1==memory)
					{
						fprintf(fcg,"lw $t1,%s\n",val1);
						fprintf(fcg,"%s $t1,$t1,$t0\n",(yyvsp[(2) - (3)].str));
						fprintf(fcg,"sw $t1,%s\n",val1);
					}
					else
					{
						fprintf(fcg,"move $t1,%s\n",val1);
						fprintf(fcg,"%s $t1,$t1,$t0\n",(yyvsp[(2) - (3)].str));
						fprintf(fcg,"move %s,$t1\n",val1);
					}
				}
				(yyval.attr)=(yyvsp[(1) - (3)].attr);
			}
                	else if((yyvsp[(1) - (3)].attr)->type==tshort && ((yyvsp[(3) - (3)].attr)->type==tbyte || (yyvsp[(3) - (3)].attr)->type==tshort))
                        {
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				if(!strcmp((yyvsp[(2) - (3)].str),"="))
				{
					if(t1==memory)
						fprintf(fcg,"sw $t0,%s\n",val1);
					else
						fprintf(fcg,"move %s,$t0\n",val1);
				}
				else 
				{
					if(t1==memory)
					{
						fprintf(fcg,"lw $t1,%s\n",val1);
						fprintf(fcg,"%s $t1,$t1,$t0\n",(yyvsp[(2) - (3)].str));
						fprintf(fcg,"sw $t1,%s\n",val1);
					}
					else
					{
						fprintf(fcg,"move $t1,%s\n",val1);
						fprintf(fcg,"%s $t1,$t1,$t0\n",(yyvsp[(2) - (3)].str));
						fprintf(fcg,"move %s,$t1\n",val1);
					}
				}
				(yyval.attr)=(yyvsp[(1) - (3)].attr);
			}
                	else if((yyvsp[(1) - (3)].attr)->type==tbyte && (yyvsp[(3) - (3)].attr)->type==tbyte)
                        {
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				if(!strcmp((yyvsp[(2) - (3)].str),"="))
				{
					if(t1==memory)
						fprintf(fcg,"sw $t0,%s\n",val1);
					else
						fprintf(fcg,"move %s,$t0\n",val1);
				}
				else 
				{
					if(t1==memory)
					{
						fprintf(fcg,"lw $t1,%s\n",val1);
						fprintf(fcg,"%s $t1,$t1,$t0\n",(yyvsp[(2) - (3)].str));
						fprintf(fcg,"sw $t1,%s\n",val1);
					}
					else
					{
						fprintf(fcg,"move $t1,%s\n",val1);
						fprintf(fcg,"%s $t1,$t1,$t0\n",(yyvsp[(2) - (3)].str));
						fprintf(fcg,"move %s,$t1\n",val1);
					}
				}
				(yyval.attr)=(yyvsp[(1) - (3)].attr);
			}
			else if((yyvsp[(1) - (3)].attr)->type==tchar && (yyvsp[(3) - (3)].attr)->type==tchar)
			{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				if(!strcmp((yyvsp[(2) - (3)].str),"="))
				{
					if(t1==memory)
						fprintf(fcg,"sw $t0,%s\n",val1);
					else
						fprintf(fcg,"move %s,$t0\n",val1);
				}
				else 
				{
					if(t1==memory)
					{
						fprintf(fcg,"lw $t1,%s\n",val1);
						fprintf(fcg,"%s $t1,$t1,$t0\n",(yyvsp[(2) - (3)].str));
						fprintf(fcg,"sw $t1,%s\n",val1);
					}
					else
					{
						fprintf(fcg,"move $t1,%s\n",val1);
						fprintf(fcg,"%s $t1,$t1,$t0\n",(yyvsp[(2) - (3)].str));
						fprintf(fcg,"move %s,$t1\n",val1);
					}
				}
				(yyval.attr)=(yyvsp[(1) - (3)].attr);
			}
			else if((yyvsp[(1) - (3)].attr)->type==tboolean && (yyvsp[(3) - (3)].attr)->type==tboolean)
			{
				if(t2==constant)
					fprintf(fcg,"li $t0,%s\n",val2);
				else if(t2==memory)
					fprintf(fcg,"lw $t0,%s\n",val2);
				else
					fprintf(fcg,"move $t0,%s\n",val2);
				if(!strcmp((yyvsp[(2) - (3)].str),"="))
				{
					(yyval.attr)=(yyvsp[(1) - (3)].attr);
					if(t1==memory)
						fprintf(fcg,"sw $t0,%s\n",val1);
					else
						fprintf(fcg,"move %s,$t0\n",val1);
				}
				else 
				{
					(yyval.attr)=(yyvsp[(1) - (3)].attr);
					(yyval.attr)->type=tnone;
					printf("ERROR:incorrect assignment on line %d\n",yylineno);
				}
			}
                	else
                	{
                        	printf("ERROR:Incorrect usage of = on line %d\n",yylineno);
                        	(yyval.attr)->type=tnone;
                	}
	   	}
	   	else if(((yyvsp[(1) - (3)].attr)->token==2 && (yyvsp[(3) - (3)].attr)->token==2) || ((yyvsp[(1) - (3)].attr)->token==4 && (yyvsp[(3) - (3)].attr)->token==4))
	   	{
			if((yyvsp[(1) - (3)].attr)->ref!=NULL && (yyvsp[(3) - (3)].attr)->ref!=NULL && strcmp((yyvsp[(1) - (3)].attr)->ref,(yyvsp[(3) - (3)].attr)->ref)==0)
			{
				(yyval.attr)=(yyvsp[(1) - (3)].attr);
				char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
				if((yyvsp[(1) - (3)].attr)->token==2)
				{
					if(Ref(Address((yyvsp[(3) - (3)].attr)->contains))==reg)
						fprintf(fcg,"move $t0,%s\n",Address((yyvsp[(3) - (3)].attr)->contains));
					else
						fprintf(fcg,"lw $t0,%s\n",Address((yyvsp[(3) - (3)].attr)->contains));
					if(Ref(val1)==memory)
						fprintf(fcg,"sw $t0,%s\n",val1);
					else
						fprintf(fcg,"move %s,$t0\n",val1);
				}
			}
			else if((yyvsp[(1) - (3)].attr)->ref!=NULL && (yyvsp[(3) - (3)].attr)->ref!=NULL)
			{
				int p1,p2;
				p1=p2=listOfClasses.size()-1;
				while(p1>=0)
				{
					if(!strcmp(listOfClasses[p1].name,(yyvsp[(1) - (3)].attr)->ref))
						break;
					else
						p1--;
				}
				while(p2>=0)
				{
					if(!strcmp(listOfClasses[p2].name,(yyvsp[(3) - (3)].attr)->ref))
						break;
					else
						p2--;
				}
				if(listOfClasses[p2].extends!=NULL && !strcmp(listOfClasses[p2].extends->name,listOfClasses[p1].name))
				{
					ST *temp=currenter;
					ClassInterface *t=&listOfClasses[currenterpointer];
					while(temp!=NULL)
					{
						if(!findentry(temp,(yyvsp[(1) - (3)].attr)->contains))
						{
							temp=temp->prev;
							if(temp==NULL)
							{
								if(t->extends!=NULL)
								{
									temp=t->extends->table;
									t=t->extends;
								}
							}
						}
						else
						{
							STE *entry=findentry(temp,(yyvsp[(1) - (3)].attr)->contains);
							strcpy(entry->ref,(yyvsp[(3) - (3)].attr)->ref);
							break;
						}
					}
					(yyval.attr)=(yyvsp[(3) - (3)].attr);
					char *val1=Address((yyvsp[(1) - (3)].attr)->contains);
					if((yyvsp[(1) - (3)].attr)->token==2)
					{
						if(Ref(Address((yyvsp[(3) - (3)].attr)->contains))==reg)
							fprintf(fcg,"move $t0,%s\n",Address((yyvsp[(3) - (3)].attr)->contains));
						else
							fprintf(fcg,"lw $t0,%s\n",Address((yyvsp[(3) - (3)].attr)->contains));
						if(Ref(val1)==memory)
							fprintf(fcg,"sw $t0,%s\n",val1);
						else
							fprintf(fcg,"move %s,$t0\n",val1);
					}
				}
				else
				{
					(yyval.attr)->token=1;
					(yyval.attr)->type=tnone;
				}
			}
			else
                	{
                        	printf("ERROR:Incorrect usage of = on line %d\n",yylineno);
                        	(yyval.attr)->type=tnone;
                	}
	    	}
	   	else
	   	{
                        printf("ERROR:Incorrect usage of = on line %d\n",yylineno);
                        (yyval.attr)->type=tnone;
           	}
	}
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 8914 "parser.ypp"
    { (yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));(yyval.attr)->type=tnone;printf("ERROR:Error in assignment expression on line %d\n",yylineno);}
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 8918 "parser.ypp"
    {
		(yyval.attr)=(struct attribute *)malloc(sizeof(struct attribute));
		ST *temp=currenter;
		bool found=false;
		ClassInterface *t=&listOfClasses[currenterpointer];
		while(temp!=NULL)
		{
			if(!findentry(temp,(yyvsp[(1) - (1)].str)))
			{
				temp=temp->prev;
				if(temp==NULL)
				{
					if(t->extends!=NULL)
					{
						temp=t->extends->table;
						t=t->extends;
					}
				}
			}
			else
			{
				STE *entry=findentry(temp,(yyvsp[(1) - (1)].str));
				found=true;
				if(temp==t->table)
				{
					if(find(returninfo->modifier.begin(),returninfo->modifier.end(),mstatic)==returninfo->modifier.end())
					{
						//printf("here\n");
						if(find(entry->modifiers.begin(),entry->modifiers.end(),mstatic)==entry->modifiers.end())
						{
							fprintf(fcg,"move $t0,$s7\n");
							int nonstatic=1,i=0,barrier=0,total=1;
							t=&listOfClasses[currenterpointer];
							temp=t->table;
							found=false;
					while(temp!=NULL)
					{
						for(i=0;i<temp->entries.size();i++)
						{
							if(find(temp->entries[i].modifiers.begin(),temp->entries[i].modifiers.end(),mstatic)==temp->entries[i].modifiers.end())
								total++;
						}
						if(t->extends!=NULL)
						{
							temp=t->extends->table;
							t=t->extends;
						}
						else
							temp=NULL;
					}
							t=&listOfClasses[currenterpointer];
							temp=t->table;
					while(temp!=NULL && !found)
					{
						nonstatic=0;
						for(i=0;i<temp->entries.size();i++)
						{
							if(find(temp->entries[i].modifiers.begin(),temp->entries[i].modifiers.end(),mstatic)==temp->entries[i].modifiers.end())
							{
								if(!strcmp(temp->entries[i].lexeme,(yyvsp[(1) - (1)].str)))
								{
									found=true;
									break;
								}
								nonstatic++;
							}
						}
						barrier+=temp->entries.size();
						if(!found)
						{
							if(t->extends!=NULL)
							{
								temp=t->extends->table;
								t=t->extends;
							}
							else
								temp=NULL;
						}
					}
							fprintf(fcg,"addu $t0,$t0,%d\n",4*(nonstatic+total-barrier));
							fprintf(fcg,"move $t%d,$t0\n",next_loc_reg);
							fprintf(fcg,"\n");
							char temp[64];
							temp[0]='0';
							temp[1]='(';
							temp[2]='$';
							temp[3]='t';
							temp[4]='0'+next_loc_reg;
							temp[5]=')';
							temp[6]='\0';
							strcpy((yyval.attr)->contains,temp);
							next_loc_reg=(next_loc_reg+1)%10>=3?(next_loc_reg+1)%10:3;
						}
						else
							strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].str));
					}
					else
					{
						if(find(entry->modifiers.begin(),entry->modifiers.end(),mstatic)==entry->modifiers.end())
							printf("ERROR:call to a non static member from inside a static method\n");
						strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].str));
					}
				}
				else
					strcpy((yyval.attr)->contains,(yyvsp[(1) - (1)].str));
				if(entry->btype==tnone)
				{
					(yyval.attr)->token=entry->dimension>0?4:2;
					strcpy((yyval.attr)->ref,entry->ref);
				}
				else
				{
					(yyval.attr)->token=entry->dimension>0?3:1;
					(yyval.attr)->type=entry->btype;	
				}
				(yyval.attr)->dimension=entry->dimension;
				break;
			}
		}
		if(!found)
		{
			(yyval.attr)->type=tnone;
			printf("ERROR:Identifier at line %d not found\n",yylineno);
		}
	}
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 9044 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 9046 "parser.ypp"
    {(yyval.attr)=(yyvsp[(1) - (1)].attr);}
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 9049 "parser.ypp"
    {strcpy((yyval.str),"add");}
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 9051 "parser.ypp"
    {strcpy((yyval.str),"sub");}
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 9055 "parser.ypp"
    {strcpy((yyval.str),"add");}
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 9057 "parser.ypp"
    {strcpy((yyval.str),"neg");}
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 9059 "parser.ypp"
    {strcpy((yyval.str),"bnot");}
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 9061 "parser.ypp"
    {strcpy((yyval.str),"not");}
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 9064 "parser.ypp"
    {(yyval.attr)=new struct attribute;(yyval.attr)->type=tint;strcpy((yyval.attr)->contains,"int");}
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 9066 "parser.ypp"
    {(yyval.attr)=new struct attribute;(yyval.attr)->type=tbyte;strcpy((yyval.attr)->contains,"byte");}
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 9068 "parser.ypp"
    {(yyval.attr)=new struct attribute;(yyval.attr)->type=tshort;strcpy((yyval.attr)->contains,"short");}
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 9070 "parser.ypp"
    {(yyval.attr)=new struct attribute;(yyval.attr)->type=tlong;strcpy((yyval.attr)->contains,"long");}
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 9072 "parser.ypp"
    {(yyval.attr)=new struct attribute;(yyval.attr)->type=tchar;strcpy((yyval.attr)->contains,"char");}
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 9074 "parser.ypp"
    {(yyval.attr)=new struct attribute;(yyval.attr)->type=tdouble;strcpy((yyval.attr)->contains,"double");}
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 9076 "parser.ypp"
    {(yyval.attr)=new struct attribute;(yyval.attr)->type=tfloat;strcpy((yyval.attr)->contains,"float");}
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 9079 "parser.ypp"
    {strcpy((yyval.str),"mul");}
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 9081 "parser.ypp"
    {strcpy((yyval.str),"div");}
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 9083 "parser.ypp"
    {strcpy((yyval.str),"rem");}
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 9086 "parser.ypp"
    {strcpy((yyval.str),"add");}
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 9088 "parser.ypp"
    {strcpy((yyval.str),"sub");}
    break;

  case 432:

/* Line 1806 of yacc.c  */
#line 9091 "parser.ypp"
    {strcpy((yyval.str),"sll");}
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 9093 "parser.ypp"
    {strcpy((yyval.str),"sra");}
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 9095 "parser.ypp"
    {strcpy((yyval.str),"srl");}
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 9098 "parser.ypp"
    {strcpy((yyval.str),"slt");}
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 9100 "parser.ypp"
    {strcpy((yyval.str),"sle");}
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 9102 "parser.ypp"
    {strcpy((yyval.str),"sgt");}
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 9104 "parser.ypp"
    {strcpy((yyval.str),"sge");}
    break;

  case 439:

/* Line 1806 of yacc.c  */
#line 9106 "parser.ypp"
    {}
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 9109 "parser.ypp"
    {strcpy((yyval.str),"seq");}
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 9111 "parser.ypp"
    {strcpy((yyval.str),"sne");}
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 9114 "parser.ypp"
    {strcpy((yyval.str),"=");}
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 9116 "parser.ypp"
    {strcpy((yyval.str),"add");}
    break;

  case 444:

/* Line 1806 of yacc.c  */
#line 9118 "parser.ypp"
    {strcpy((yyval.str),"sub");}
    break;

  case 445:

/* Line 1806 of yacc.c  */
#line 9120 "parser.ypp"
    {strcpy((yyval.str),"mul");}
    break;

  case 446:

/* Line 1806 of yacc.c  */
#line 9122 "parser.ypp"
    {strcpy((yyval.str),"div");}
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 9124 "parser.ypp"
    {strcpy((yyval.str),"rem");}
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 9126 "parser.ypp"
    {strcpy((yyval.str),"and");}
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 9128 "parser.ypp"
    {strcpy((yyval.str),"xor");}
    break;

  case 450:

/* Line 1806 of yacc.c  */
#line 9130 "parser.ypp"
    {strcpy((yyval.str),"or");}
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 9132 "parser.ypp"
    {strcpy((yyval.str),"sll");}
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 9134 "parser.ypp"
    {strcpy((yyval.str),"sra");}
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 9136 "parser.ypp"
    {strcpy((yyval.str),"srl");}
    break;



/* Line 1806 of yacc.c  */
#line 13184 "parser.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 9138 "parser.ypp"

void createtable(ST *parent)
{
	node = new ST;
	(node->entries).reserve(32*sizeof(STE));
	node->prev=parent;
	currenter=node;
}

void removetable(ST *tab)
{
	ST *temp=currenter;
	temp->entries.clear();
	currenter=tab->prev;
	//free(temp);
}

STE *findentry(ST *tab,char *lexeme)
{
	for(int i=0;i<tab->entries.size();i++)
	{
		if(!strcmp((tab->entries[i]).lexeme,lexeme))
			return &(tab->entries[i]);
	}
	return NULL;
}

void insertentry(ST *tab,char *lexeme,vector<int> m,enum Basic b,char *ref,int dimension,int offset)
{
	STE entry;
	entry.table=tab;
	entry.lexeme=(char *)malloc(256*sizeof(lexeme));
	strcpy(entry.lexeme,lexeme);
	entry.btype=b;
	if(ref!=NULL)
		strcpy(entry.ref,ref);
	entry.dimension=dimension;
	entry.modifiers=m;
	entry.offset=offset;
	tab->entries.push_back(entry);
}

bool compare(vector<struct attribute *>a,vector<struct attribute *>b)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]->token!=b[i]->token)
			return false;
		else if(a[i]->dimension!=b[i]->dimension)
			return false;
		else if(a[i]->dimension>0 && b[i]->dimension>0)
		{
			if(a[i]->token==3 && a[i]->type!=b[i]->type)
				return false;
			else if(a[i]->token==4 && strcmp(a[i]->ref,b[i]->ref))
				return false;
		}
		else if(a[i]->token==1)
		{
			if(a[i]->type==tdouble && (b[i]->type==tstring || b[i]->type==tnull || b[i]->type==tnone || b[i]->type==tvoid || b[i]->type==tboolean))
				return false;
			else if(a[i]->type==tfloat && (b[i]->type==tdouble || b[i]->type==tstring || b[i]->type==tnull || b[i]->type==tnone || b[i]->type==tvoid))
				return false;	
			else if(a[i]->type==tlong && !(b[i]->type==tlong || b[i]->type==tint || b[i]->type==tbyte || b[i]->type==tshort || b[i]->type==tchar))
                        	return false;
                	else if(a[i]->type==tint && !(b[i]->type==tint || b[i]->type==tbyte || b[i]->type==tshort || b[i]->type==tchar))
                        	return false;
                	else if(a[i]->type==tshort && !(b[i]->type==tbyte || b[i]->type==tshort))
                        	return false;
                	else if(a[i]->type==tbyte && !(b[i]->type==tbyte))
                        	return false;
			else if(a[i]->type==tchar && b[i]->type!=tchar)
				return false;
			else if(a[i]->type==tboolean && b[i]->type!=tboolean)
				return false;
		}
		else if(a[i]->token==2  && strcmp(a[i]->ref,b[i]->ref))
			return false;
       }
       return true;
}

enum Basic findType(char tmp[],int size)
{
	int i=0;
	long long int val=0;
	while(i<size)
	{
		val=val*10+(tmp[i]-'0');
		i++;
	}
	if(val<128)
		return tbyte;
	else if(val<32767)
		return tshort;
	else if(val<2147483647)
		return tint;
	else
		return tlong;
}

char *getNewTemp()
{
	char * temp = (char *)malloc (5);
	strcpy (temp, "_T00");
	temp [2] = num_temp / 10 + '0';
	temp [3] = num_temp % 10 + '0';
	num_temp++;
	return temp;
}

char *offToAddr(int offset)
{
	if(offset>=100)
	{
		if(offset==100)
			return "20($sp)";
		else if(offset==101)
			return "16($sp)";
		else if(offset==102)
			return "12($sp)";
		else if(offset==103)
			return "8($sp)";
		else if(offset==105)
			return "32($sp)";
		else if(offset==106)
			return "28($sp)";
		else
			return "24($sp)";
	}
	if(offset>=60)
	{
		char *temp=(char *)malloc(5);
		temp[0]='$';
		temp[1]='f';
		temp[2]='0'+(offset-60)/10;
		temp[3]='0'+(offset-60)%10;
		temp[4]='\0';
		return temp;
	}
	if(offset>=50)
	{
		char *temp=(char *)malloc(4);
		temp[0]='$';
		temp[1]='s';
		temp[2]='0'+offset%50;
		temp[3]='\0';
		return temp;
	}
	if(offset>-100)
	{
		char *temp=(char *)malloc(10);
		strcpy(temp,"---($fp)");
		offset=-offset;
		temp[1]=offset/10+'0';
		temp[2]=offset%10+'0';
		return temp;
	}
	else
	{
		char *temp=(char *)malloc(12);
		strcpy(temp,"----($fp)");
		offset=-offset;
		temp[1]=offset/100+'0';
		temp[2]=(offset%100)/10+'0';
		temp[3]=offset%10+'0';
		return temp;
	}
}

char *Address(char *var,int val)
{
	if(var[0]=='$')							//register address
		return var;
	if(var[0]=='-' || (var[0]>='0' && var[0]<='9') || var[0]=='\'')	//constant
		return var;
	else if(var[0]=='_' && var[1]=='T')				//temporary
	{
		int offset=(var[2]-'0')*10+var[3]-'0';
		return offToAddr(offset_temp[offset]);
	}
	else
	{	
		STE *st=NULL;
		ST *temp=currenter;
		while(temp!=NULL && st==NULL)
		{
			st=findentry(temp,var);
			temp=temp->prev;
		}
		if(st!=NULL)
			return offToAddr(st->offset);
		else
			return var;
	}
}
void optimise (char * filename) 
{
	FILE * in = fopen (filename, "r");
	FILE * out = fopen ("codeopt.asm", "w");
	int MAX_LINE_LEN = 50;
	char bufferprev [MAX_LINE_LEN];
	char buffernew [MAX_LINE_LEN];
	int line_number = 0;
	while (fgets (buffernew, MAX_LINE_LEN, in) != 0) 
	{
		if (line_number != 0) 
		{
			if (strcmp (bufferprev+1, buffernew+1)) 
				fprintf (out, "%s", buffernew);
		}
		else 
			fprintf (out, "%s", buffernew);
		line_number ++;
		strcpy (bufferprev, buffernew);
	}
	fclose (in);
	fclose (out);
	char command [50];
	sprintf (command, "mv codeopt.asm %s", filename);
	system (command);
}
	
extern FILE *yyin;
main(int argc,char *argv[])
{
	char * outfilename = (char *)malloc (100);
	strcpy (outfilename, "code.asm");
	fcg = fopen (outfilename, "w");
	do
	{
		yyparse();	
	}
	while(!feof(yyin));
	fclose(fcg);
	if(argc>1)
	{
		printf("code optimised\n");
		optimise(outfilename);
	}
}


