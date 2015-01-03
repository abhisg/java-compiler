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
#line 1 "parser.ypp"

#include<stdio.h>
#include<string.h>
extern int yylineno;
int error_count = 0;
#define DEBUG_MODE 1
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
#line 93 "parser.cpp"

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
     FLOATING = 270,
     HEX_FLOAT = 271,
     ABSTRACT = 272,
     ASSERT = 273,
     BOOLEAN = 274,
     BREAK = 275,
     BYTE = 276,
     CASE = 277,
     CATCH = 278,
     CHAR = 279,
     CLASS = 280,
     CONST = 281,
     CONTINUE = 282,
     DEFAULT = 283,
     DO = 284,
     DOUBLE = 285,
     ELSE = 286,
     ENUM = 287,
     EXTENDS = 288,
     FINAL = 289,
     FINALLY = 290,
     FLOAT = 291,
     FOR = 292,
     IF = 293,
     GOTO = 294,
     IMPLEMENTS = 295,
     IMPORT = 296,
     INSTANCEOF = 297,
     INT = 298,
     INTERFACE = 299,
     LONG = 300,
     NATIVE = 301,
     NEW = 302,
     PACKAGE = 303,
     PRIVATE = 304,
     PROTECTED = 305,
     PUBLIC = 306,
     RETURN = 307,
     SHORT = 308,
     STATIC = 309,
     STRICTFP = 310,
     SUPER = 311,
     SWITCH = 312,
     SYNCHRONIZED = 313,
     THIS = 314,
     THROW = 315,
     THROWS = 316,
     TRANSIENT = 317,
     TRY = 318,
     VOID = 319,
     VOLATILE = 320,
     WHILE = 321,
     LRBRACE = 322,
     RRBRACE = 323,
     LCBRACE = 324,
     RCBRACE = 325,
     LSBRACE = 326,
     RSBRACE = 327,
     COMMA = 328,
     SEMICOLON = 329,
     DOT = 330,
     COLON = 331,
     TERNARY = 332,
     INCREMENT = 333,
     DECREMENT = 334,
     UNOT = 335,
     NEQ = 336,
     NOT = 337,
     COMPARE = 338,
     EQUAL = 339,
     MULTEQUAL = 340,
     PLUSEQUAL = 341,
     DIVEQUAL = 342,
     MINUSEQUAL = 343,
     MODEQUAL = 344,
     DIV = 345,
     MULT = 346,
     MOD = 347,
     PLUS = 348,
     MINUS = 349,
     LEFTSHIFTEQUAL = 350,
     RIGHTSHIFTEQUAL = 351,
     URIGHTSHIFTEQUAL = 352,
     LEFTSHIFT = 353,
     RIGHTSHIFT = 354,
     URIGHTSHIFT = 355,
     LEQ = 356,
     LT = 357,
     GT = 358,
     GEQ = 359,
     ANDEQUAL = 360,
     BAND = 361,
     OREQUAL = 362,
     BOR = 363,
     AND = 364,
     OR = 365,
     XOR = 366,
     XOREQUAL = 367,
     CAST = 368,
     UMINUS = 369,
     UPLUS = 370,
     PREDECREMENT = 371,
     PREINCREMENT = 372
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 252 "parser.cpp"

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5716

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  136
/* YYNRULES -- Number of rules.  */
#define YYNRULES  619
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   372

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
     115,   116,   117
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    49,    51,    53,    55,    57,
      59,    61,    63,    65,    68,    70,    74,    79,    81,    85,
      89,    93,    98,   103,   108,   112,   114,   118,   120,   122,
     124,   127,   130,   133,   137,   140,   143,   145,   146,   150,
     154,   156,   159,   163,   169,   176,   183,   187,   192,   194,
     197,   199,   201,   203,   205,   214,   222,   230,   237,   245,
     252,   258,   265,   271,   278,   284,   289,   294,   300,   305,
     309,   314,   318,   321,   323,   325,   327,   329,   331,   333,
     335,   337,   339,   341,   343,   345,   349,   353,   357,   359,
     362,   364,   367,   370,   372,   376,   379,   383,   387,   389,
     392,   394,   396,   399,   401,   403,   405,   407,   409,   411,
     416,   420,   424,   428,   430,   434,   436,   440,   445,   449,
     454,   456,   458,   460,   463,   468,   472,   476,   480,   485,
     487,   491,   494,   500,   505,   510,   515,   519,   523,   527,
     530,   536,   541,   546,   551,   555,   559,   563,   566,   571,
     575,   580,   584,   589,   595,   597,   601,   603,   607,   611,
     615,   618,   625,   631,   633,   636,   638,   642,   644,   646,
     651,   655,   659,   662,   665,   671,   676,   681,   685,   691,
     696,   701,   703,   707,   714,   720,   726,   731,   738,   744,
     750,   755,   764,   772,   780,   787,   794,   800,   806,   811,
     818,   824,   830,   835,   844,   852,   860,   867,   871,   875,
     879,   881,   885,   891,   896,   901,   905,   909,   914,   920,
     925,   930,   935,   939,   943,   947,   950,   957,   963,   969,
     975,   980,   985,   990,   994,   996,  1000,  1004,  1007,  1010,
    1012,  1015,  1017,  1021,  1024,  1028,  1036,  1043,  1050,  1056,
    1062,  1067,  1072,  1076,  1081,  1085,  1089,  1092,  1094,  1097,
    1099,  1101,  1103,  1105,  1107,  1113,  1118,  1123,  1128,  1132,
    1136,  1140,  1143,  1149,  1154,  1159,  1164,  1168,  1172,  1176,
    1179,  1182,  1186,  1190,  1192,  1195,  1197,  1199,  1201,  1203,
    1205,  1208,  1212,  1218,  1226,  1230,  1236,  1240,  1246,  1251,
    1259,  1263,  1269,  1276,  1285,  1291,  1295,  1301,  1309,  1315,
    1323,  1329,  1333,  1339,  1343,  1348,  1351,  1355,  1359,  1364,
    1367,  1371,  1375,  1378,  1382,  1386,  1391,  1397,  1403,  1407,
    1411,  1416,  1422,  1427,  1432,  1435,  1439,  1441,  1443,  1445,
    1447,  1449,  1451,  1454,  1461,  1467,  1474,  1480,  1482,  1485,
    1488,  1492,  1497,  1502,  1504,  1508,  1513,  1519,  1521,  1524,
    1527,  1529,  1532,  1536,  1539,  1544,  1546,  1550,  1555,  1561,
    1567,  1572,  1577,  1581,  1585,  1591,  1596,  1601,  1605,  1608,
    1612,  1615,  1617,  1618,  1620,  1621,  1623,  1625,  1629,  1631,
    1633,  1635,  1637,  1641,  1643,  1645,  1647,  1649,  1658,  1666,
    1674,  1682,  1690,  1697,  1704,  1711,  1718,  1725,  1732,  1738,
    1744,  1750,  1756,  1761,  1772,  1782,  1792,  1802,  1812,  1821,
    1830,  1839,  1848,  1857,  1866,  1874,  1882,  1890,  1898,  1905,
    1914,  1922,  1930,  1938,  1947,  1954,  1961,  1969,  1976,  1984,
    1992,  1999,  2006,  2013,  2019,  2025,  2036,  2046,  2056,  2066,
    2077,  2086,  2095,  2105,  2114,  2124,  2134,  2143,  2152,  2161,
    2169,  2177,  2179,  2182,  2184,  2188,  2193,  2197,  2202,  2206,
    2211,  2216,  2218,  2221,  2225,  2228,  2232,  2236,  2240,  2245,
    2251,  2255,  2260,  2266,  2270,  2274,  2279,  2283,  2288,  2293,
    2297,  2305,  2314,  2321,  2329,  2336,  2344,  2350,  2357,  2365,
    2374,  2381,  2389,  2396,  2404,  2410,  2417,  2426,  2435,  2443,
    2453,  2461,  2468,  2473,  2478,  2484,  2490,  2492,  2494,  2496,
    2499,  2501,  2504,  2506,  2510,  2513,  2516,  2520,  2522,  2527,
    2531,  2533,  2538,  2542,  2544,  2549,  2553,  2555,  2560,  2564,
    2566,  2571,  2575,  2577,  2582,  2586,  2588,  2593,  2597,  2599,
    2604,  2608,  2610,  2615,  2619,  2621,  2626,  2628,  2634,  2639,
    2641,  2643,  2647,  2652,  2654,  2656,  2658,  2660,  2662,  2664,
    2666,  2668,  2670,  2672,  2674,  2676,  2678,  2680,  2682,  2684,
    2686,  2688,  2690,  2692,  2694,  2696,  2698,  2700,  2702,  2704,
    2706,  2708,  2710,  2712,  2714,  2716,  2718,  2720,  2722,  2724
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     119,     0,    -1,   139,    -1,    10,    -1,   122,    -1,   123,
      -1,     8,    -1,     7,    -1,     6,    -1,     9,    -1,     3,
      -1,    14,    -1,    11,    -1,    12,    -1,    13,    -1,    16,
      -1,    15,    -1,   125,    -1,   129,    -1,   126,    -1,    19,
      -1,   127,    -1,   128,    -1,    21,    -1,    53,    -1,    43,
      -1,    45,    -1,    24,    -1,    36,    -1,    30,    -1,   130,
      -1,   133,    -1,   131,    -1,   131,   134,    -1,   132,    -1,
     131,    75,   132,    -1,   131,    75,     1,    74,    -1,   120,
      -1,   125,    71,    72,    -1,   131,    71,    72,    -1,   133,
      71,    72,    -1,   125,    71,     1,    74,    -1,   131,    71,
       1,    74,    -1,   133,    71,     1,    74,    -1,   102,   135,
     103,    -1,   136,    -1,   135,    73,   136,    -1,   129,    -1,
     137,    -1,    77,    -1,    77,   138,    -1,    33,   129,    -1,
      56,   129,    -1,   140,   141,   143,    -1,   140,   143,    -1,
     141,   143,    -1,   143,    -1,    -1,    48,   131,    74,    -1,
      48,     1,    74,    -1,   142,    -1,   141,   142,    -1,    41,
     131,    74,    -1,    41,   131,    75,    91,    74,    -1,    41,
      54,   131,    75,   120,    74,    -1,    41,    54,   131,    75,
      91,    74,    -1,    41,     1,    74,    -1,    41,    54,     1,
      74,    -1,   144,    -1,   143,   144,    -1,   145,    -1,   188,
      -1,   146,    -1,   182,    -1,   147,    25,   120,   149,    33,
     130,   153,   155,    -1,    25,   120,   149,    33,   130,   153,
     155,    -1,   147,    25,   120,    33,   130,   153,   155,    -1,
     147,    25,   120,   149,   153,   155,    -1,   147,    25,   120,
     149,    33,   130,   155,    -1,    25,   120,    33,   130,   153,
     155,    -1,    25,   120,   149,   153,   155,    -1,    25,   120,
     149,    33,   130,   155,    -1,   147,    25,   120,   153,   155,
      -1,   147,    25,   120,    33,   130,   155,    -1,   147,    25,
     120,   149,   155,    -1,    25,   120,   153,   155,    -1,    25,
     120,   149,   155,    -1,    25,   120,    33,   130,   155,    -1,
     147,    25,   120,   155,    -1,    25,   120,   155,    -1,   147,
      25,     1,   155,    -1,    25,     1,   155,    -1,   147,   148,
      -1,   148,    -1,    51,    -1,    49,    -1,    50,    -1,    17,
      -1,    54,    -1,    34,    -1,    46,    -1,    58,    -1,    62,
      -1,    65,    -1,    55,    -1,   102,   150,   103,    -1,   102,
       1,   103,    -1,   150,    73,   151,    -1,   151,    -1,   120,
     152,    -1,   120,    -1,    33,   130,    -1,    40,   154,    -1,
     130,    -1,   154,    73,   130,    -1,    69,    70,    -1,    69,
     156,    70,    -1,    69,     1,    70,    -1,   157,    -1,   156,
     157,    -1,   158,    -1,   193,    -1,    54,   193,    -1,   176,
      -1,   159,    -1,   166,    -1,   145,    -1,   188,    -1,    74,
      -1,   147,   124,   160,    74,    -1,   124,   160,    74,    -1,
     147,     1,    74,    -1,   124,     1,    74,    -1,   161,    -1,
     160,    73,   161,    -1,   162,    -1,   162,    84,   163,    -1,
     162,    84,     1,    74,    -1,   162,    71,    72,    -1,   162,
      71,     1,    74,    -1,   120,    -1,   243,    -1,   164,    -1,
      69,    70,    -1,    69,   165,    73,    70,    -1,    69,    73,
      70,    -1,    69,   165,    70,    -1,    69,     1,    70,    -1,
      69,   165,     1,    74,    -1,   163,    -1,   165,    73,   163,
      -1,   167,   175,    -1,   147,   149,    64,   168,   173,    -1,
     149,    64,   168,   173,    -1,   147,    64,   168,   173,    -1,
     147,   149,    64,   168,    -1,    64,   168,   173,    -1,   147,
      64,   168,    -1,   149,    64,   168,    -1,    64,   168,    -1,
     147,   149,   124,   168,   173,    -1,   149,   124,   168,   173,
      -1,   147,   124,   168,   173,    -1,   147,   149,   124,   168,
      -1,   124,   168,   173,    -1,   147,   124,   168,    -1,   149,
     124,   168,    -1,   124,   168,    -1,   120,    67,   169,    68,
      -1,   120,    67,    68,    -1,   120,     1,   169,    68,    -1,
     120,     1,    68,    -1,   120,    67,     1,    74,    -1,   120,
      67,   169,     1,    74,    -1,   172,    -1,   170,    73,   172,
      -1,   171,    -1,   170,    73,   171,    -1,   170,    73,     1,
      -1,    34,   124,   162,    -1,   124,   162,    -1,    34,   124,
      75,    75,    75,   162,    -1,   124,    75,    75,    75,   162,
      -1,   171,    -1,    61,   174,    -1,   131,    -1,   174,    73,
     131,    -1,   193,    -1,    74,    -1,   147,   177,   173,   178,
      -1,   177,   173,   178,    -1,   147,   177,   178,    -1,   177,
     178,    -1,   177,     1,    -1,   149,   132,    67,   169,    68,
      -1,   132,    67,   169,    68,    -1,   149,   132,    67,    68,
      -1,   132,    67,    68,    -1,   149,   132,    67,     1,    74,
      -1,   132,    67,     1,    74,    -1,    69,   179,   194,    70,
      -1,   193,    -1,    69,   179,    70,    -1,   180,    59,    67,
     220,    68,    74,    -1,    59,    67,   220,    68,    74,    -1,
     180,    59,    67,    68,    74,    -1,    59,    67,    68,    74,
      -1,   180,    56,    67,   220,    68,    74,    -1,    56,    67,
     220,    68,    74,    -1,   180,    56,    67,    68,    74,    -1,
      56,    67,    68,    74,    -1,   216,    75,   180,    56,    67,
     220,    68,    74,    -1,   216,    75,    56,    67,   220,    68,
      74,    -1,   216,    75,   180,    56,    67,    68,    74,    -1,
     216,    75,    56,    67,    68,    74,    -1,   180,    59,    67,
     220,     1,    74,    -1,    59,    67,   220,     1,    74,    -1,
     180,    59,    67,     1,    74,    -1,    59,    67,     1,    74,
      -1,   180,    56,    67,   220,     1,    74,    -1,    56,    67,
     220,     1,    74,    -1,   180,    56,    67,     1,    74,    -1,
      56,    67,     1,    74,    -1,   216,    75,   180,    56,    67,
     220,     1,    74,    -1,   216,    75,    56,    67,   220,     1,
      74,    -1,   216,    75,   180,    56,    67,     1,    74,    -1,
     216,    75,    56,    67,     1,    74,    -1,   102,   181,   103,
      -1,   102,     1,   103,    -1,   102,   181,     1,    -1,   129,
      -1,   181,    73,   129,    -1,   147,    32,   120,   153,   183,
      -1,    32,   120,   153,   183,    -1,   147,    32,   120,   183,
      -1,    32,   120,   183,    -1,    32,     1,   183,    -1,   147,
      32,     1,   183,    -1,    69,   184,    73,   186,    70,    -1,
      69,   184,   186,    70,    -1,    69,    73,   186,    70,    -1,
      69,   184,    73,    70,    -1,    69,   186,    70,    -1,    69,
     184,    70,    -1,    69,    73,    70,    -1,    69,    70,    -1,
      69,   184,    73,   186,     1,    74,    -1,    69,   184,   186,
       1,    74,    -1,    69,    73,   186,     1,    74,    -1,    69,
     184,    73,     1,    74,    -1,    69,   186,     1,    74,    -1,
      69,   184,     1,    74,    -1,    69,    73,     1,    74,    -1,
      69,     1,    74,    -1,   185,    -1,   184,    73,   185,    -1,
     120,   187,   155,    -1,   120,   155,    -1,   120,   187,    -1,
     120,    -1,    74,   156,    -1,    74,    -1,    67,   220,    68,
      -1,    67,    68,    -1,    67,     1,    68,    -1,   147,    44,
     120,   149,    33,   154,   189,    -1,    44,   120,   149,    33,
     154,   189,    -1,   147,    44,   120,    33,   154,   189,    -1,
     147,    44,   120,   149,   189,    -1,    44,   120,    33,   154,
     189,    -1,    44,   120,   149,   189,    -1,   147,    44,   120,
     189,    -1,    44,   120,   189,    -1,   147,    44,     1,   189,
      -1,    44,     1,   189,    -1,    69,   190,    70,    -1,    69,
      70,    -1,   191,    -1,   190,   191,    -1,   159,    -1,   192,
      -1,   145,    -1,   188,    -1,    74,    -1,   147,   149,   124,
     168,   173,    -1,   149,   124,   168,   173,    -1,   147,   124,
     168,   173,    -1,   147,   149,   124,   168,    -1,   124,   168,
     173,    -1,   147,   124,   168,    -1,   149,   124,   168,    -1,
     124,   168,    -1,   147,   149,    64,   168,   173,    -1,   149,
      64,   168,   173,    -1,   147,    64,   168,   173,    -1,   147,
     149,    64,   168,    -1,    64,   168,   173,    -1,   147,    64,
     168,    -1,   149,    64,   168,    -1,    64,   168,    -1,    69,
      70,    -1,    69,   194,    70,    -1,    69,     1,    70,    -1,
     195,    -1,   194,   195,    -1,   159,    -1,   145,    -1,   196,
      -1,   193,    -1,    74,    -1,   197,    74,    -1,   120,    76,
     196,    -1,    38,    67,   243,    68,   196,    -1,    38,    67,
     243,    68,   196,    31,   196,    -1,    38,     1,    74,    -1,
      38,    67,   243,     1,   196,    -1,    18,   243,    74,    -1,
      18,   243,    76,   243,    74,    -1,    18,   243,     1,    74,
      -1,    57,    67,   243,    68,    69,   205,    70,    -1,    57,
       1,    74,    -1,    57,    67,   243,     1,    74,    -1,    57,
      67,   243,    68,     1,    74,    -1,    57,    67,   243,    68,
      69,   205,     1,    74,    -1,    66,    67,   243,    68,   196,
      -1,    66,     1,    74,    -1,    66,    67,   243,     1,    74,
      -1,    29,   196,    66,    67,   243,    68,    74,    -1,    29,
     196,    66,     1,    74,    -1,    29,   196,    66,    67,   243,
       1,    74,    -1,    37,    67,   209,    68,   196,    -1,    37,
       1,    74,    -1,    37,    67,   209,     1,   196,    -1,    20,
     120,    74,    -1,    20,   120,     1,    74,    -1,    20,    74,
      -1,    20,     1,    74,    -1,    27,   120,    74,    -1,    27,
     120,     1,    74,    -1,    27,    74,    -1,    27,     1,    74,
      -1,    52,   243,    74,    -1,    52,    74,    -1,    52,     1,
      70,    -1,    60,   243,    74,    -1,    60,   243,     1,    74,
      -1,    58,    67,   243,    68,   193,    -1,    58,    67,   243,
       1,   193,    -1,    63,   193,   198,    -1,    63,   193,   201,
      -1,    63,   193,   198,   201,    -1,    63,   202,   193,   198,
     201,    -1,    63,   202,   193,   198,    -1,    63,   202,   193,
     201,    -1,    63,   202,    -1,    63,     1,    74,    -1,   244,
      -1,   231,    -1,   229,    -1,   226,    -1,   218,    -1,   199,
      -1,   198,   199,    -1,    23,    67,    34,   200,    68,   193,
      -1,    23,    67,   200,    68,   193,    -1,    23,    67,    34,
     200,     1,   193,    -1,    23,    67,   200,     1,   193,    -1,
     130,    -1,   130,   200,    -1,    35,   193,    -1,    67,   203,
      68,    -1,    67,   203,    74,    68,    -1,    67,   203,     1,
      74,    -1,   204,    -1,   203,    74,   204,    -1,   129,   162,
      84,   243,    -1,    34,   129,   162,    84,   243,    -1,   206,
      -1,   205,   206,    -1,   207,   194,    -1,   208,    -1,   207,
     208,    -1,    22,   243,    76,    -1,    28,    76,    -1,    22,
     243,     1,    74,    -1,   210,    -1,   213,    74,    74,    -1,
     213,    74,   243,    74,    -1,   213,    74,   243,     1,    74,
      -1,   213,    74,   243,    74,   214,    -1,   213,    74,    74,
     214,    -1,   147,   124,   162,   211,    -1,   124,   162,   211,
      -1,   124,   162,     1,    -1,   212,    74,   243,    74,   214,
      -1,   212,    74,   243,    74,    -1,   212,    74,    74,   214,
      -1,   212,    74,    74,    -1,    76,   243,    -1,    84,   163,
     160,    -1,    84,   163,    -1,   160,    -1,    -1,   215,    -1,
      -1,   215,    -1,   197,    -1,   215,    73,   197,    -1,   217,
      -1,   221,    -1,   121,    -1,    59,    -1,    67,   243,    68,
      -1,   218,    -1,   225,    -1,   226,    -1,   227,    -1,    47,
     134,   131,   219,    67,   220,    68,   155,    -1,    47,   131,
     219,    67,   220,    68,   155,    -1,    47,   134,   131,    67,
     220,    68,   155,    -1,    47,   134,   131,   219,    67,    68,
     155,    -1,    47,   134,   131,   219,    67,   220,    68,    -1,
      47,   131,    67,   220,    68,   155,    -1,    47,   131,   219,
      67,    68,   155,    -1,    47,   131,   219,    67,   220,    68,
      -1,    47,   134,   131,    67,    68,   155,    -1,    47,   134,
     131,    67,   220,    68,    -1,    47,   134,   131,   219,    67,
      68,    -1,    47,   134,   131,    67,    68,    -1,    47,   131,
     219,    67,    68,    -1,    47,   131,    67,   220,    68,    -1,
      47,   131,    67,    68,   155,    -1,    47,   131,    67,    68,
      -1,   216,    75,    47,   134,   131,   219,    67,   220,    68,
     155,    -1,   216,    75,    47,   131,   219,    67,   220,    68,
     155,    -1,   216,    75,    47,   134,   131,    67,   220,    68,
     155,    -1,   216,    75,    47,   134,   131,   219,    67,    68,
     155,    -1,   216,    75,    47,   134,   131,   219,    67,   220,
      68,    -1,   216,    75,    47,   131,    67,   220,    68,   155,
      -1,   216,    75,    47,   131,   219,    67,    68,   155,    -1,
     216,    75,    47,   131,   219,    67,   220,    68,    -1,   216,
      75,    47,   134,   131,    67,    68,   155,    -1,   216,    75,
      47,   134,   131,    67,   220,    68,    -1,   216,    75,    47,
     134,   131,   219,    67,    68,    -1,   216,    75,    47,   134,
     131,    67,    68,    -1,   216,    75,    47,   131,   219,    67,
      68,    -1,   216,    75,    47,   131,    67,   220,    68,    -1,
     216,    75,    47,   131,    67,    68,   155,    -1,   216,    75,
      47,   131,    67,    68,    -1,    47,   134,   131,   219,    67,
     220,     1,   155,    -1,    47,   131,   219,    67,   220,     1,
     155,    -1,    47,   134,   131,    67,   220,     1,   155,    -1,
      47,   134,   131,   219,    67,     1,   155,    -1,    47,   134,
     131,   219,    67,   220,     1,    74,    -1,    47,   131,    67,
     220,     1,   155,    -1,    47,   131,   219,    67,     1,   155,
      -1,    47,   131,   219,    67,   220,     1,    74,    -1,    47,
     134,   131,    67,     1,   155,    -1,    47,   134,   131,    67,
     220,     1,    74,    -1,    47,   134,   131,   219,    67,     1,
      74,    -1,    47,   134,   131,    67,     1,    74,    -1,    47,
     131,   219,    67,     1,    74,    -1,    47,   131,    67,   220,
       1,    74,    -1,    47,   131,    67,     1,   155,    -1,    47,
     131,    67,     1,    74,    -1,   216,    75,    47,   134,   131,
     219,    67,   220,     1,   155,    -1,   216,    75,    47,   131,
     219,    67,   220,     1,   155,    -1,   216,    75,    47,   134,
     131,    67,   220,     1,   155,    -1,   216,    75,    47,   134,
     131,   219,    67,     1,   155,    -1,   216,    75,    47,   134,
     131,   219,    67,   220,     1,    74,    -1,   216,    75,    47,
     131,    67,   220,     1,   155,    -1,   216,    75,    47,   131,
     219,    67,     1,   155,    -1,   216,    75,    47,   131,   219,
      67,   220,     1,    74,    -1,   216,    75,    47,   134,   131,
      67,     1,   155,    -1,   216,    75,    47,   134,   131,    67,
     220,     1,    74,    -1,   216,    75,    47,   134,   131,   219,
      67,     1,    74,    -1,   216,    75,    47,   134,   131,    67,
       1,    74,    -1,   216,    75,    47,   131,   219,    67,     1,
      74,    -1,   216,    75,    47,   131,    67,   220,     1,    74,
      -1,   216,    75,    47,   131,    67,     1,   155,    -1,   216,
      75,    47,   131,    67,     1,    74,    -1,   134,    -1,   102,
     103,    -1,   243,    -1,   220,    73,   243,    -1,    47,   125,
     222,   224,    -1,    47,   125,   222,    -1,    47,   130,   222,
     224,    -1,    47,   130,   222,    -1,    47,   125,   224,   164,
      -1,    47,   130,   224,   164,    -1,   223,    -1,   222,   223,
      -1,    71,   243,    72,    -1,    71,    72,    -1,   224,    71,
      72,    -1,   216,    75,   120,    -1,    56,    75,   120,    -1,
       4,    67,   243,    68,    -1,     4,    67,   243,     1,    74,
      -1,     4,     1,    74,    -1,     5,    67,   243,    68,    -1,
       5,    67,   243,     1,    74,    -1,     5,     1,    74,    -1,
       5,    67,    68,    -1,     5,    67,     1,    74,    -1,     4,
      67,    68,    -1,     4,    67,     1,    74,    -1,   131,    67,
     220,    68,    -1,   131,    67,    68,    -1,   216,    75,   180,
     120,    67,   220,    68,    -1,   216,    75,   180,   120,    67,
     220,     1,    74,    -1,   216,    75,   120,    67,   220,    68,
      -1,   216,    75,   120,    67,   220,     1,    74,    -1,   216,
      75,   180,   120,    67,    68,    -1,   216,    75,   180,   120,
      67,     1,    74,    -1,   216,    75,   120,    67,    68,    -1,
     216,    75,   120,    67,     1,    74,    -1,    56,    75,   180,
     120,    67,   220,    68,    -1,    56,    75,   180,   120,    67,
     220,     1,    74,    -1,    56,    75,   180,   120,    67,    68,
      -1,    56,    75,   180,   120,    67,     1,    74,    -1,    56,
      75,   120,    67,   220,    68,    -1,    56,    75,   120,    67,
     220,     1,    74,    -1,    56,    75,   120,    67,    68,    -1,
      56,    75,   120,    67,     1,    74,    -1,   131,    75,    56,
      75,    10,    67,   220,    68,    -1,   131,    75,    56,    75,
     180,    10,    67,    68,    -1,   131,    75,    56,    75,    10,
      67,    68,    -1,   131,    75,    56,    75,   180,    10,    67,
     220,    68,    -1,   131,    75,   180,   120,    67,   220,    68,
      -1,   131,    75,   180,   120,    67,    68,    -1,   131,    71,
     243,    72,    -1,   217,    71,   243,    72,    -1,   217,    71,
     243,     1,    74,    -1,   131,    71,   243,     1,    74,    -1,
     216,    -1,   131,    -1,   229,    -1,   228,   246,    -1,   228,
      -1,   247,   230,    -1,   231,    -1,   247,     1,    74,    -1,
      78,   230,    -1,    79,   230,    -1,   232,   248,   230,    -1,
     230,    -1,   232,   248,     1,    74,    -1,   233,   249,   232,
      -1,   232,    -1,   233,   249,     1,    74,    -1,   234,   250,
     233,    -1,   233,    -1,   234,   250,     1,    74,    -1,   235,
     251,   234,    -1,   234,    -1,   235,   251,     1,    74,    -1,
     236,   252,   235,    -1,   235,    -1,   236,   252,     1,    74,
      -1,   237,   106,   236,    -1,   236,    -1,   237,   106,     1,
      74,    -1,   238,   111,   237,    -1,   237,    -1,   238,   111,
       1,    74,    -1,   239,   108,   238,    -1,   238,    -1,   239,
     108,     1,    74,    -1,   240,   109,   239,    -1,   239,    -1,
     240,   109,     1,    74,    -1,   241,   110,   240,    -1,   240,
      -1,   241,   110,     1,    74,    -1,   241,    -1,   241,    77,
     243,    76,   242,    -1,   241,    77,     1,    74,    -1,   242,
      -1,   244,    -1,   245,   253,   243,    -1,   245,   253,     1,
      74,    -1,   131,    -1,   225,    -1,   227,    -1,    78,    -1,
      79,    -1,    93,    -1,    94,    -1,    82,    -1,    80,    -1,
     113,    -1,    91,    -1,    90,    -1,    92,    -1,    93,    -1,
      94,    -1,    98,    -1,    99,    -1,   100,    -1,   102,    -1,
     101,    -1,   103,    -1,   104,    -1,    42,    -1,    83,    -1,
      81,    -1,    84,    -1,    86,    -1,    88,    -1,    85,    -1,
      87,    -1,    89,    -1,   105,    -1,   112,    -1,   107,    -1,
      95,    -1,    96,    -1,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   154,   154,   158,   162,   164,   166,   168,   170,   172,
     174,   178,   180,   182,   184,   188,   190,   194,   196,   199,
     201,   204,   206,   209,   211,   213,   215,   217,   220,   222,
     225,   227,   231,   233,   236,   238,   240,   243,   246,   248,
     250,   252,   254,   256,   261,   265,   267,   271,   273,   277,
     279,   283,   285,   293,   295,   297,   299,   300,   304,   306,
     310,   312,   316,   318,   320,   322,   324,   326,   330,   332,
     336,   338,   342,   344,   348,   350,   352,   354,   356,   358,
     360,   362,   364,   366,   368,   370,   372,   374,   376,   378,
     380,   382,   386,   388,   391,   393,   395,   397,   399,   401,
     403,   405,   407,   409,   411,   415,   417,   421,   423,   427,
     429,   433,   437,   441,   443,   447,   449,   451,   455,   457,
     461,   463,   465,   467,   471,   473,   475,   477,   479,   483,
     485,   487,   489,   493,   495,   499,   501,   503,   507,   509,
     511,   515,   517,   521,   523,   525,   527,   529,   531,   534,
     536,   540,   543,   545,   547,   549,   551,   553,   555,   557,
     559,   561,   563,   565,   567,   569,   571,   573,   576,   578,
     580,   582,   584,   586,   589,   591,   595,   597,   599,   603,
     605,   609,   611,   613,   616,   619,   621,   624,   626,   629,
     631,   633,   635,   637,   640,   642,   644,   646,   648,   650,
     653,   655,   657,   660,   662,   664,   666,   668,   670,   672,
     674,   676,   678,   680,   682,   684,   686,   688,   690,   692,
     694,   696,   698,   700,   702,   704,   706,   710,   712,   714,
     717,   719,   722,   724,   726,   728,   730,   732,   735,   737,
     739,   741,   743,   745,   747,   749,   751,   753,   755,   757,
     759,   761,   763,   765,   768,   770,   773,   775,   777,   779,
     782,   784,   787,   789,   791,   794,   796,   798,   800,   802,
     804,   806,   808,   810,   812,   815,   817,   820,   822,   825,
     827,   829,   831,   833,   836,   838,   840,   842,   844,   846,
     848,   850,   852,   854,   856,   858,   860,   862,   864,   866,
     870,   872,   874,   878,   880,   885,   887,   889,   892,   894,
     896,   898,   900,   902,   904,   906,   908,   910,   912,   914,
     916,   918,   920,   922,   924,   926,   928,   930,   932,   934,
     936,   938,   940,   942,   944,   946,   948,   950,   952,   954,
     956,   958,   960,   962,   964,   966,   968,   970,   972,   974,
     976,   978,   980,   982,   984,   986,   989,   991,   993,   995,
     997,  1000,  1002,  1005,  1007,  1009,  1011,  1014,  1016,  1019,
    1023,  1025,  1027,  1032,  1034,  1039,  1041,  1047,  1049,  1054,
    1059,  1061,  1066,  1068,  1070,  1073,  1075,  1077,  1079,  1081,
    1083,  1086,  1088,  1090,  1093,  1095,  1097,  1099,  1101,  1104,
    1106,  1108,  1109,  1112,  1113,  1118,  1123,  1125,  1128,  1130,
    1133,  1135,  1137,  1139,  1141,  1143,  1145,  1148,  1150,  1152,
    1154,  1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,  1172,
    1174,  1176,  1178,  1180,  1182,  1184,  1186,  1188,  1190,  1192,
    1194,  1196,  1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,
    1214,  1216,  1218,  1220,  1222,  1224,  1226,  1228,  1230,  1232,
    1234,  1236,  1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,
    1254,  1256,  1258,  1260,  1262,  1264,  1266,  1268,  1270,  1272,
    1274,  1277,  1279,  1282,  1284,  1287,  1289,  1291,  1293,  1295,
    1297,  1300,  1302,  1305,  1308,  1310,  1313,  1315,  1318,  1320,
    1322,  1324,  1326,  1328,  1330,  1332,  1334,  1336,  1338,  1340,
    1342,  1344,  1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,
    1362,  1364,  1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,
    1382,  1384,  1387,  1389,  1391,  1393,  1396,  1398,  1400,  1403,
    1406,  1408,  1410,  1412,  1415,  1417,  1420,  1422,  1424,  1427,
    1429,  1431,  1434,  1436,  1438,  1441,  1443,  1445,  1448,  1450,
    1452,  1455,  1457,  1459,  1462,  1464,  1466,  1469,  1471,  1473,
    1476,  1478,  1480,  1483,  1485,  1487,  1490,  1492,  1494,  1497,
    1499,  1502,  1504,  1507,  1509,  1511,  1514,  1516,  1520,  1522,
    1524,  1526,  1528,  1531,  1533,  1535,  1538,  1540,  1543,  1545,
    1547,  1550,  1552,  1554,  1556,  1558,  1561,  1563,  1566,  1568,
    1570,  1572,  1574,  1576,  1578,  1580,  1582,  1584,  1586,  1588
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "PRINTL", "PRINT", "STRING",
  "CHARACTERS", "BOOL", "NULLER", "IDENTIFIER", "HEX_INT", "BIN_INT",
  "OCT_INT", "INTEGER", "FLOATING", "HEX_FLOAT", "ABSTRACT", "ASSERT",
  "BOOLEAN", "BREAK", "BYTE", "CASE", "CATCH", "CHAR", "CLASS", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTENDS",
  "FINAL", "FINALLY", "FLOAT", "FOR", "IF", "GOTO", "IMPLEMENTS", "IMPORT",
  "INSTANCEOF", "INT", "INTERFACE", "LONG", "NATIVE", "NEW", "PACKAGE",
  "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", "SHORT", "STATIC",
  "STRICTFP", "SUPER", "SWITCH", "SYNCHRONIZED", "THIS", "THROW", "THROWS",
  "TRANSIENT", "TRY", "VOID", "VOLATILE", "WHILE", "LRBRACE", "RRBRACE",
  "LCBRACE", "RCBRACE", "LSBRACE", "RSBRACE", "COMMA", "SEMICOLON", "DOT",
  "COLON", "TERNARY", "INCREMENT", "DECREMENT", "UNOT", "NEQ", "NOT",
  "COMPARE", "EQUAL", "MULTEQUAL", "PLUSEQUAL", "DIVEQUAL", "MINUSEQUAL",
  "MODEQUAL", "DIV", "MULT", "MOD", "PLUS", "MINUS", "LEFTSHIFTEQUAL",
  "RIGHTSHIFTEQUAL", "URIGHTSHIFTEQUAL", "LEFTSHIFT", "RIGHTSHIFT",
  "URIGHTSHIFT", "LEQ", "LT", "GT", "GEQ", "ANDEQUAL", "BAND", "OREQUAL",
  "BOR", "AND", "OR", "XOR", "XOREQUAL", "CAST", "UMINUS", "UPLUS",
  "PREDECREMENT", "PREINCREMENT", "$accept", "Goal", "Identifier",
  "Literal", "IntegerLiteral", "FloatingPointLiteral", "Type", "Primitive",
  "Numeric", "Integral", "FloatingPointType", "Reference",
  "ClassOrInterfaceType", "TypeName", "SimpleName", "ArrayType",
  "TypeArguments", "TypeArgumentList", "TypeArgument", "WildCard",
  "Bounds", "CompilationUnit", "PackageDeclaration", "ImportDeclarations",
  "ImportDeclaration", "TypeDeclarations", "TypeDeclaration",
  "ClassDeclaration", "NormalClassDeclaration", "Modifiers", "Modifier",
  "TypeParameters", "TypeParameterList", "TypeParameter", "TypeBound",
  "Interfaces", "InterfaceTypeList", "ClassBody", "ClassBodyDeclarations",
  "ClassBodyDeclaration", "ClassMemberDeclaration", "FieldDeclaration",
  "VariableDeclarators", "VariableDeclarator", "VariableDeclaratorID",
  "VariableInitialiser", "ArrayInitialiser", "VariableInitialisers",
  "MethodDeclaration", "MethodHeader", "MethodDeclarator",
  "FormalParameterList", "FormalParameters", "FormalParameter",
  "LastFormalParameter", "Throws", "ExceptionTypeList", "MethodBody",
  "ConstructorDeclaration", "ConstructorDeclarator", "ConstructorBody",
  "ExplicitConstructorInvocation", "NonWildTypeArguments", "ReferenceList",
  "EnumDeclaration", "EnumBody", "EnumConstants", "EnumConstant",
  "EnumBodyDeclarations", "Arguments", "InterfaceDeclaration",
  "InterfaceBody", "InterfaceMemberDeclarations",
  "InterfaceMemberDeclaration", "AbstractMethodDeclaration", "Block",
  "BlockStatements", "BlockStatement", "Statement", "StatementExpression",
  "Catches", "CatchClause", "CatchType", "Finally",
  "ResourceSpecification", "Resources", "Resource",
  "SwitchBlockStatementGroups", "SwitchBlockStatementGroup",
  "SwitchLabels", "SwitchLabel", "ForControl", "ForVarControl",
  "ForVarControlRest", "ForVariableDeclaratorsRest", "ForInit",
  "ForUpdate", "StatementExpressionList", "Primary", "PrimaryNoNewArray",
  "ClassInstanceCreationExpression", "TypeArgumentsOrDiamond",
  "ArgumentList", "ArrayCreationExpression", "DimExprs", "DimExpr", "Dims",
  "FieldAccess", "MethodInvocation", "ArrayAccess", "OpExpression",
  "PostFixOp", "UnaryExpression", "PreFixOp", "MultExpression",
  "AddExpression", "ShiftExpression", "RelExpression", "CompExpression",
  "BitAndExpression", "XORExpression", "BORExpression", "ANDExpression",
  "ORExpression", "TernaryExpression", "Expression", "Assignment",
  "LeftHandSide", "UnaryRtoL", "UnaryLtoR", "MultOperator", "AddOperator",
  "ShiftOperator", "RelOperator", "CompOperator", "AssignmentOperator", 0
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
     365,   366,   367,   368,   369,   370,   371,   372
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   118,   119,   120,   121,   121,   121,   121,   121,   121,
     121,   122,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   127,   127,   127,   128,   128,
     129,   129,   130,   130,   131,   131,   131,   132,   133,   133,
     133,   133,   133,   133,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   139,   139,   139,   140,   140,
     141,   141,   142,   142,   142,   142,   142,   142,   143,   143,
     144,   144,   145,   145,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   147,   147,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   149,   149,   150,   150,   151,
     151,   152,   153,   154,   154,   155,   155,   155,   156,   156,
     157,   157,   157,   157,   158,   158,   158,   158,   158,   159,
     159,   159,   159,   160,   160,   161,   161,   161,   162,   162,
     162,   163,   163,   164,   164,   164,   164,   164,   164,   165,
     165,   166,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   168,   168,
     168,   168,   168,   168,   169,   169,   170,   170,   170,   171,
     171,   172,   172,   172,   173,   174,   174,   175,   175,   176,
     176,   176,   176,   176,   177,   177,   177,   177,   177,   177,
     178,   178,   178,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   180,   180,   180,
     181,   181,   182,   182,   182,   182,   182,   182,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   185,   185,   185,   185,
     186,   186,   187,   187,   187,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   189,   189,   190,   190,   191,
     191,   191,   191,   191,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     193,   193,   193,   194,   194,   195,   195,   195,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   197,   197,   197,   197,
     197,   198,   198,   199,   199,   199,   199,   200,   200,   201,
     202,   202,   202,   203,   203,   204,   204,   205,   205,   206,
     207,   207,   208,   208,   208,   209,   209,   209,   209,   209,
     209,   210,   210,   210,   211,   211,   211,   211,   211,   212,
     212,   212,   212,   213,   213,   214,   215,   215,   216,   216,
     217,   217,   217,   217,   217,   217,   217,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   219,   219,   220,   220,   221,   221,   221,   221,   221,
     221,   222,   222,   223,   224,   224,   225,   225,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   227,   227,   227,   227,   228,   228,   228,   229,
     230,   230,   230,   230,   231,   231,   232,   232,   232,   233,
     233,   233,   234,   234,   234,   235,   235,   235,   236,   236,
     236,   237,   237,   237,   238,   238,   238,   239,   239,   239,
     240,   240,   240,   241,   241,   241,   242,   242,   242,   243,
     243,   244,   244,   245,   245,   245,   246,   246,   247,   247,
     247,   247,   247,   248,   248,   248,   249,   249,   250,   250,
     250,   251,   251,   251,   251,   251,   252,   252,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     4,     1,     3,     3,
       3,     4,     4,     4,     3,     1,     3,     1,     1,     1,
       2,     2,     2,     3,     2,     2,     1,     0,     3,     3,
       1,     2,     3,     5,     6,     6,     3,     4,     1,     2,
       1,     1,     1,     1,     8,     7,     7,     6,     7,     6,
       5,     6,     5,     6,     5,     4,     4,     5,     4,     3,
       4,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     2,
       1,     2,     2,     1,     3,     2,     3,     3,     1,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     4,
       3,     3,     3,     1,     3,     1,     3,     4,     3,     4,
       1,     1,     1,     2,     4,     3,     3,     3,     4,     1,
       3,     2,     5,     4,     4,     4,     3,     3,     3,     2,
       5,     4,     4,     4,     3,     3,     3,     2,     4,     3,
       4,     3,     4,     5,     1,     3,     1,     3,     3,     3,
       2,     6,     5,     1,     2,     1,     3,     1,     1,     4,
       3,     3,     2,     2,     5,     4,     4,     3,     5,     4,
       4,     1,     3,     6,     5,     5,     4,     6,     5,     5,
       4,     8,     7,     7,     6,     6,     5,     5,     4,     6,
       5,     5,     4,     8,     7,     7,     6,     3,     3,     3,
       1,     3,     5,     4,     4,     3,     3,     4,     5,     4,
       4,     4,     3,     3,     3,     2,     6,     5,     5,     5,
       4,     4,     4,     3,     1,     3,     3,     2,     2,     1,
       2,     1,     3,     2,     3,     7,     6,     6,     5,     5,
       4,     4,     3,     4,     3,     3,     2,     1,     2,     1,
       1,     1,     1,     1,     5,     4,     4,     4,     3,     3,
       3,     2,     5,     4,     4,     4,     3,     3,     3,     2,
       2,     3,     3,     1,     2,     1,     1,     1,     1,     1,
       2,     3,     5,     7,     3,     5,     3,     5,     4,     7,
       3,     5,     6,     8,     5,     3,     5,     7,     5,     7,
       5,     3,     5,     3,     4,     2,     3,     3,     4,     2,
       3,     3,     2,     3,     3,     4,     5,     5,     3,     3,
       4,     5,     4,     4,     2,     3,     1,     1,     1,     1,
       1,     1,     2,     6,     5,     6,     5,     1,     2,     2,
       3,     4,     4,     1,     3,     4,     5,     1,     2,     2,
       1,     2,     3,     2,     4,     1,     3,     4,     5,     5,
       4,     4,     3,     3,     5,     4,     4,     3,     2,     3,
       2,     1,     0,     1,     0,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     8,     7,     7,
       7,     7,     6,     6,     6,     6,     6,     6,     5,     5,
       5,     5,     4,    10,     9,     9,     9,     9,     8,     8,
       8,     8,     8,     8,     7,     7,     7,     7,     6,     8,
       7,     7,     7,     8,     6,     6,     7,     6,     7,     7,
       6,     6,     6,     5,     5,    10,     9,     9,     9,    10,
       8,     8,     9,     8,     9,     9,     8,     8,     8,     7,
       7,     1,     2,     1,     3,     4,     3,     4,     3,     4,
       4,     1,     2,     3,     2,     3,     3,     3,     4,     5,
       3,     4,     5,     3,     3,     4,     3,     4,     4,     3,
       7,     8,     6,     7,     6,     7,     5,     6,     7,     8,
       6,     7,     6,     7,     5,     6,     8,     8,     7,     9,
       7,     6,     4,     4,     5,     5,     1,     1,     1,     2,
       1,     2,     1,     3,     2,     2,     3,     1,     4,     3,
       1,     4,     3,     1,     4,     3,     1,     4,     3,     1,
       4,     3,     1,     4,     3,     1,     4,     3,     1,     4,
       3,     1,     4,     3,     1,     4,     1,     5,     4,     1,
       1,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
      57,    97,     0,     0,    99,     0,     0,   100,     0,    95,
      96,    94,    98,   104,   101,   102,   103,     0,     2,     0,
       0,    60,    56,    68,    70,    72,     0,    93,    73,    71,
       0,     3,     0,     0,     0,     0,     0,    37,     0,    34,
       0,     0,     0,     0,     1,     0,    54,    61,    55,    69,
       0,     0,     0,    92,     0,    91,     0,     0,     0,     0,
       0,    89,     0,   236,     0,   235,    66,     0,     0,    62,
       0,     0,   274,     0,     0,   272,    59,    58,     0,    53,
       0,     0,     0,     0,     0,     0,     0,    20,    23,    27,
      29,    28,    25,    26,    24,    98,     0,     0,   115,   128,
       0,    17,    19,    21,    22,    18,    30,    32,    34,    31,
     126,     0,     0,     0,   118,   120,   124,   125,     0,   123,
       0,   127,   121,     0,    32,   113,   112,     0,   110,     0,
     108,     0,     0,    86,    85,     0,   245,     0,   261,   259,
       0,   254,     0,   233,    67,     0,     0,     0,    35,     0,
     276,   283,     0,   281,     0,     0,   279,   282,     0,   277,
     280,     0,     0,   270,    90,     0,     0,     0,    88,   237,
       0,   234,   273,     0,     0,   271,   117,   122,     0,   159,
       0,    10,     0,     0,     8,     7,     6,     9,    12,    13,
      14,    11,    16,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   411,     0,     0,     0,     0,
     300,   309,     0,     0,    37,   410,     4,     5,     0,   583,
     306,     0,   305,   308,     0,   303,   307,     0,   536,   408,
     360,   409,   414,   359,   416,     0,   358,   357,   356,     0,
       0,     0,     0,   133,   135,   167,     0,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
     116,   119,   188,   151,   187,   193,     0,     0,     0,   192,
     201,     0,    87,     0,   106,     0,   109,     0,   105,     0,
      80,   253,     0,   244,     0,   260,     0,   257,   258,     0,
     243,     0,     0,     0,   242,     0,    37,    36,    63,   299,
     291,     0,     0,     0,     0,     0,   275,   278,   269,     0,
       0,     0,     0,    84,    82,   232,     0,     0,   268,     0,
       0,   156,   302,     0,     0,     0,     0,   591,   590,   588,
     589,   592,   537,   413,   415,   540,   538,   547,   542,   550,
     553,   556,   559,   562,   565,   568,   571,   574,   576,   579,
       0,   580,     0,     0,   335,     0,     0,   339,     0,     0,
       0,     0,   404,     0,     0,     0,     0,    32,     0,     0,
     342,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     354,     0,     0,     0,   537,   414,   416,   544,   545,     0,
     140,     0,     0,     0,     0,   301,   304,   310,     0,     0,
     586,   587,   539,   608,   611,   609,   612,   610,   613,   617,
     618,   619,   614,   616,   615,     0,   132,     0,   130,     0,
       0,   164,     0,    38,     0,    39,    49,     0,    47,     0,
      45,    48,     0,     0,   197,     0,     0,     0,   183,   174,
       0,    40,   131,   157,     0,   165,     0,     0,     0,   191,
     158,   166,     0,   185,   184,     0,   411,     0,     0,     0,
     536,   190,    79,   114,   111,   107,     0,    81,   252,     0,
     240,     0,   263,     0,   483,   256,   251,     0,   241,   255,
       0,     0,   239,   250,    65,    64,   296,   288,   297,   289,
       0,     0,   298,   290,   266,     0,    83,     0,    77,   267,
       0,   171,     0,     0,   169,     0,   500,     0,   506,     0,
     503,     0,   504,     0,     0,   594,   593,   595,     0,   596,
     597,     0,   598,   599,   600,     0,   605,   602,   601,   603,
     604,     0,   607,   606,     0,     0,     0,     0,     0,     0,
       0,     0,   316,     0,     0,   541,   336,     0,   333,   340,
       0,   337,     0,   331,     0,     0,   406,     0,   385,     0,
     403,   314,     0,     0,   486,   491,     0,   488,     0,     0,
       0,    33,     0,     0,   343,   341,   497,     0,   320,     0,
       0,     0,   344,   355,     0,     0,     0,   373,     0,     0,
     348,   361,   349,     0,   325,     0,   412,   311,   509,     0,
       0,     0,     0,     0,   496,     0,     0,     0,   581,   134,
       0,   138,     0,     0,   136,   142,   141,    41,    42,     0,
       0,    50,     0,    44,   199,     0,     0,   180,   195,     0,
      43,   154,   129,   162,   155,   163,   189,   153,   161,     0,
     196,     0,     0,     0,     0,     0,   230,     0,   202,     0,
       0,     0,     0,    75,   248,   264,   262,     0,   249,     0,
     238,   247,   294,   286,   295,   287,   293,   285,    76,     0,
      78,   265,   170,   172,     0,   168,   507,     0,   498,   505,
       0,   501,     0,   546,     0,   549,     0,   552,     0,   555,
       0,   558,     0,   561,     0,   564,     0,   567,     0,   570,
       0,     0,     0,   573,   318,     0,   543,   334,   338,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   494,
       0,   492,   485,     0,   489,   487,   490,     0,   432,     0,
     482,     0,     0,   481,     0,     0,     0,     0,     0,     0,
       0,   345,     0,     0,     0,   370,     0,     0,   369,   362,
     350,   352,   353,     0,     0,   508,     0,   532,     0,     0,
       0,     0,     0,     0,     0,   533,   582,   139,   137,     0,
     143,     0,   149,     0,    51,    52,    46,     0,   179,     0,
     178,   183,   175,   152,   160,   198,   194,   186,     0,     0,
       0,     0,     0,     0,   228,   229,     0,   227,   200,     0,
       0,     0,     0,   484,   246,   292,   284,    74,   173,   499,
     502,   548,   551,   554,   557,   560,   563,   566,   569,   572,
     578,     0,   575,   317,   328,     0,   393,     0,     0,   401,
     392,     0,   402,   332,   330,   386,     0,   407,   315,   312,
     493,   495,   464,   463,   431,     0,   430,     0,   429,     0,
       0,   428,     0,     0,     0,   524,     0,     0,   321,     0,
       0,   347,   346,     0,     0,   372,   371,   374,     0,   367,
       0,   351,   326,   324,   535,     0,     0,     0,     0,     0,
       0,     0,   516,     0,     0,   534,   147,   145,     0,   146,
       0,     0,     0,   222,   210,     0,     0,   218,   206,     0,
       0,   231,     0,     0,     0,     0,     0,     0,     0,     0,
     577,     0,     0,   398,   400,     0,   391,   390,   405,     0,
     387,     0,   462,   454,   422,   461,   455,   423,     0,   424,
     460,   457,   425,     0,   426,     0,   427,     0,   525,     0,
     522,     0,   520,     0,   322,     0,     0,     0,   377,     0,
     380,     0,   375,     0,   368,     0,     0,     0,     0,   531,
       0,     0,   448,     0,     0,     0,     0,   517,     0,   512,
       0,   514,     0,   148,   144,   150,     0,   182,   220,   208,
     216,   204,   221,   209,     0,     0,   217,   205,     0,     0,
       0,     0,     0,     0,   329,   327,   399,   397,     0,   388,
     389,   313,   456,   450,   418,   458,   451,   419,   459,   452,
     420,     0,   421,   523,   521,     0,   518,     0,   383,     0,
     319,   378,   379,   381,   376,     0,     0,   366,   364,   528,
       0,     0,   530,   480,   479,   447,     0,   446,     0,   445,
       0,     0,   444,     0,     0,   513,   515,     0,   510,   181,
     219,   207,   215,   203,   226,   214,     0,     0,     0,     0,
       0,   396,   395,   453,   449,   417,   519,     0,   382,   323,
     365,   363,   526,   527,     0,   478,   470,   438,   477,   471,
     439,     0,   440,   476,   473,   441,     0,   442,     0,   443,
       0,   511,   224,   212,   225,   213,     0,     0,   394,   384,
     529,   472,   466,   434,   474,   467,   435,   475,   468,   436,
       0,   437,   223,   211,   469,   465,   433
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    37,   215,   216,   217,   218,   101,   102,   103,
     104,   105,   106,   332,    39,   109,   249,   429,   430,   431,
     621,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   112,   129,   130,   276,    60,   126,    55,   113,   114,
     115,   222,   242,   243,   244,   614,   615,   773,   117,   118,
     179,   436,   437,   438,   439,   268,   454,   263,   119,   120,
     269,   458,   459,   647,    28,    63,   140,   141,   142,   288,
      29,    72,   158,   159,   160,   223,   224,   225,   226,   227,
     590,   591,   870,   592,   380,   586,   587,   947,   948,   949,
     950,   557,   558,   830,   831,   559,   917,   918,   228,   229,
     333,   572,   473,   231,   564,   565,   566,   232,   334,   234,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   474,   351,   239,   402,   352,
     518,   521,   525,   531,   534,   415
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -882
static const yytype_int16 yypact[] =
{
    5549,  -882,   611,   655,  -882,   553,   661,  -882,   671,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,    86,  -882,  5584,
    5584,  -882,  1658,  -882,  -882,  -882,  5619,  -882,  -882,  -882,
      32,  -882,   232,    77,   379,   114,   675,  -882,   472,  -882,
     176,   382,   121,   715,  -882,  5584,  1658,  -882,  1658,  -882,
     678,   683,   701,  -882,  4378,  -882,   285,   285,   704,    20,
      32,  -882,   230,  -882,    77,  -882,  -882,   300,   451,  -882,
      84,  4603,  -882,   285,    26,  -882,  -882,  -882,   712,  1658,
      32,   475,    77,   379,   176,   425,   487,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,   495,   285,  4798,  -882,  -882,
     741,   593,  -882,  -882,  -882,  -882,  -882,   557,   519,   722,
    -882,  4440,  4249,  4542,  -882,  -882,  -882,  -882,   693,  -882,
     481,  -882,  -882,   499,   231,  -882,   529,   624,   602,   464,
    -882,   285,    32,  -882,  -882,   737,  -882,   164,  4664,   631,
     152,  -882,   280,  -882,  -882,   126,   746,   750,  -882,   285,
    -882,  -882,   741,  -882,  4500,  5500,  -882,  -882,  4724,  -882,
    -882,   581,   285,  -882,  -882,   285,   564,    32,  -882,  -882,
      77,  -882,  -882,   285,   378,  -882,  -882,  -882,   408,   742,
     771,  -882,   437,   445,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  4204,   139,   172,  5337,   515,   518,
    1094,  1617,   777,   522,   811,  -882,  4204,    81,   527,  4204,
    -882,  -882,  4204,  4204,   767,  -882,  -882,  -882,   741,   412,
    -882,  5416,  -882,  -882,  4952,  -882,  -882,   782,   807,   834,
     637,  -882,   689,   679,  1398,   674,   756,  -882,  -882,  1681,
     833,   247,   817,  -882,   530,   742,    41,   163,  1339,  -882,
    1190,   196,   842,   285,   285,  5516,   588,   285,   285,   850,
    -882,  -882,  -882,  -882,  -882,  -882,   285,  4315,   853,  -882,
    -882,    32,  -882,   285,  -882,   285,  -882,   285,  -882,   499,
    -882,  -882,   849,  -882,   281,  4664,  1728,  -882,    32,   851,
    -882,    89,   346,   852,  -882,   854,   857,  -882,  -882,   742,
     742,   285,   285,  5541,   285,   285,  -882,  -882,  -882,   581,
     499,   285,    32,  -882,  -882,  -882,   581,   285,  -882,  1378,
    1321,  -882,  -882,   858,  1745,   859,  1856,  -882,  -882,  -882,
    -882,  -882,  5604,  -882,  -882,   674,  -882,  -882,  -882,   691,
     816,   787,   542,   276,   828,   824,   829,   831,   503,  -882,
      46,  -882,  2983,   867,  -882,    97,   868,  -882,   169,   811,
     877,   871,  5260,   872,  4204,   878,   878,   491,   285,   881,
    -882,   874,    36,   880,  4204,  4204,   184,   885,  3235,   583,
     495,   886,  4204,   890,   607,  -882,  -882,  -882,  -882,  5337,
    -882,  3760,  1873,   116,   285,  -882,  -882,  -882,    40,  4204,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  3077,  -882,   285,  -882,   274,
    1967,  -882,   887,  -882,   888,  -882,    37,   593,  -882,   537,
    -882,  -882,   889,  3346,  -882,   500,   896,   892,   893,  -882,
     894,  -882,  -882,   742,   838,   742,   285,   285,   853,  -882,
     742,   742,  5389,   897,   898,   672,   902,  3124,  5029,   638,
     900,  -882,  -882,  -882,  -882,  -882,    32,  -882,  -882,   903,
    -882,   906,  -882,   695,  -882,  -882,  -882,   904,  -882,  -882,
     384,   907,  -882,  -882,  -882,  -882,  -882,  -882,   742,   742,
     285,   285,   742,   742,  -882,    32,  -882,   499,  -882,  -882,
     581,  -882,   908,   909,  -882,   146,  -882,   910,  -882,   314,
    -882,   912,  -882,   323,  4204,  -882,  -882,  -882,  3094,  -882,
    -882,  3188,  -882,  -882,  -882,  3205,  -882,  -882,  -882,  -882,
    -882,  3299,  -882,  -882,  3316,  3410,  3427,  3521,  3538,  3632,
    3649,   913,  -882,  4204,   915,  -882,  -882,   917,  -882,  -882,
     922,  -882,   531,  -882,   285,  5458,  -882,   391,  -882,   925,
     927,  -882,   405,  3854,   878,  -882,   752,   878,   752,  1984,
     656,   935,   936,   528,  -882,  -882,   941,   285,  -882,   480,
     484,   938,  -882,  -882,  3346,   285,   131,  -882,   946,   495,
     583,  -882,  -882,   583,  -882,   485,  -882,  -882,  -882,   729,
     292,   939,   285,    67,   949,   285,   331,   943,  -882,  -882,
     944,  -882,   945,  1592,  -882,  -882,  -882,  -882,  -882,  3346,
    3346,  -882,  1339,  -882,  -882,   524,   947,   950,  -882,  2014,
    -882,  -882,  -882,  -882,   742,   742,  -882,  -882,  -882,   951,
    -882,   952,   285,  2078,  2095,   920,  -882,    64,  -882,  5106,
     957,   962,    28,  -882,  -882,  -882,  -882,  4204,  -882,   969,
    -882,  -882,  -882,  -882,   742,   742,  -882,  -882,  -882,    32,
    -882,  -882,  -882,  -882,   972,  -882,  -882,   974,  -882,  -882,
     977,  -882,   979,  -882,   984,   691,   985,   816,   986,   787,
     988,   542,   990,   276,   991,   828,   993,   824,   994,   829,
     995,   955,   996,   831,  -882,   997,  -882,  -882,  -882,   998,
    4204,   218,   285,  5337,  5337,  3871,  1464,  5337,  5337,  -882,
     964,  -882,  1002,  1004,  -882,  1002,  -882,   735,    32,   211,
    -882,  2189,  2206,  -882,  1007,  2300,  1010,  1008,   124,   495,
     495,  -882,   285,   552,  1009,  -882,  1517,   320,  -882,  -882,
    -882,   583,  -882,  1012,  5337,  -882,  1013,  -882,    78,  1014,
     549,   285,  2317,  1017,  1015,  -882,  -882,  -882,  -882,  1018,
    -882,  1022,  -882,   243,  -882,  -882,  -882,  1021,   950,  1026,
    -882,  1030,  -882,  -882,  -882,  -882,  -882,   897,  1032,  1033,
     275,  1036,  1037,   287,  -882,  -882,  3346,  -882,  -882,  2411,
    2428,  1045,   523,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  4204,  -882,  -882,  -882,   494,  -882,  4204,  3965,  1041,
    -882,  1048,    21,  -882,  -882,  1464,   188,  -882,  -882,  1092,
    -882,  -882,  -882,  -882,  -882,   736,    32,   738,    32,   290,
     748,    32,   325,  2522,  1051,  -882,   326,  2539,  -882,  1052,
     727,  -882,  -882,   576,  4204,  -882,  -882,  -882,   285,   285,
     501,  -882,  -882,  -882,  -882,  1060,  1118,  3982,  2633,  1064,
     559,  1058,  -882,   344,  2650,  -882,  -882,  -882,  1059,  -882,
    3743,  1061,   285,  -882,  -882,  1067,  1068,  -882,  -882,  1069,
    1070,  -882,  1071,  1072,   352,  1074,  1075,   369,  2744,  1083,
    -882,  1078,  1079,  -882,   285,  4076,  -882,  -882,   927,  1081,
    1464,  5337,  -882,  -882,  -882,  -882,  -882,  -882,   758,    32,
    -882,  -882,  -882,   762,    32,   768,    32,   388,  -882,  1085,
    -882,  1086,  -882,   389,  -882,  4204,  1062,   249,  -882,  4875,
    -882,  4204,  -882,   506,  -882,   495,   495,  4093,  1095,  -882,
     776,   781,    32,   420,  2761,  2855,  1096,  -882,  1087,  -882,
    1091,  -882,   430,  -882,  -882,  -882,   285,   950,  -882,  -882,
    -882,  -882,  -882,  -882,  1098,  1101,  -882,  -882,  1104,  1105,
    1106,  1108,   438,  2872,  -882,  -882,  1041,  1464,  1111,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,   789,    32,  -882,  -882,  1115,  -882,    33,  -882,  1116,
    -882,  -882,  5183,  -882,  -882,   495,   495,  -882,  -882,  -882,
     791,  4187,  -882,  -882,  -882,  -882,   793,    32,   799,    32,
     449,   800,    32,   467,  2966,  -882,  -882,  1119,  -882,   950,
    -882,  -882,  -882,  -882,  -882,  -882,  1120,  1121,  1123,  1124,
     468,  -882,  1464,  -882,  -882,  -882,  -882,  1125,  -882,  -882,
    -882,  -882,  -882,  -882,   792,  -882,  -882,  -882,  -882,  -882,
    -882,   802,    32,  -882,  -882,  -882,   803,    32,   806,    32,
     470,  -882,  -882,  -882,  -882,  -882,  1127,  1128,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
     810,    32,  -882,  -882,  -882,  -882,  -882
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -882,  -882,     6,  -882,  -882,  -882,   418,  -187,  -882,  -882,
    -882,  -247,   -21,   633,   332,  -882,  -189,  -882,   544,  -882,
    -882,  -882,  -882,  1173,   187,   410,   574,   -30,  -882,   -34,
       0,   355,  -882,   928,  -882,    -5,   -50,   -32,  1066,   -98,
    -882,    91,  -251,   790,  -425,  -592,   327,  -882,  -882,  -882,
     740,  -246,  -882,   577,   579,   884,  -882,  -882,  -882,  1099,
    -250,  -882,  -353,  -882,  -882,    -2,  -882,   921,  -107,  -882,
     103,    92,  -882,  1055,  -882,     1,  -444,  -222,  -193,  -355,
     622,  -565,    45,  -524,  -882,  -882,   473,  -882,   271,  -882,
     272,  -882,  -882,   390,  -882,  -882,  -881,   865,   961,  -882,
      18,  -568,   533,  -882,   863,   202,  -344,  -196,   112,  -169,
     321,   381,  -141,   403,   711,   709,   706,   705,   716,   708,
     703,   718,   707,  -882,   433,   899,   532,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -586
static const yytype_int16 yytable[] =
{
      61,   428,   396,   444,   360,   734,   449,   556,    32,    34,
     627,   368,    41,   365,   649,   261,   385,   385,   461,   577,
     111,   772,   568,   161,   110,   749,    53,   133,   134,    64,
     284,    31,    65,   292,  1067,   123,   125,   154,    31,  1000,
     602,   153,   422,   386,   386,   605,    31,   541,   164,   168,
      31,   444,   125,   131,   132,   122,    81,    83,    85,   162,
      57,   427,   143,   221,   128,   795,   750,   220,   139,   752,
     619,   387,   388,   502,   505,   603,   167,    31,   170,   111,
     169,   171,   377,   110,   801,   146,    44,   603,   875,    54,
     477,   272,   419,   620,    31,    71,   177,   827,   547,    31,
     280,    54,   178,   214,   111,   828,   241,   287,   110,  1068,
     279,    53,   309,   423,   122,   230,  1061,   146,   271,   264,
     542,   270,   543,   316,   154,   859,    31,   146,   153,   711,
     457,   585,   744,    75,   313,   314,    31,   796,   457,   122,
     353,   125,   457,   444,   310,   116,    62,   674,   378,    31,
      97,   296,   125,   289,    53,   178,   385,   121,   241,   478,
     743,   312,   156,   138,   424,   282,   163,   797,   315,   248,
     550,   548,   601,   356,   157,   147,   172,   175,   571,   366,
     457,  1098,    31,   386,   480,   581,   749,   261,    66,   919,
     221,   427,   879,   860,   220,    76,   597,   440,   636,   745,
     778,   355,   358,   214,   116,   746,   641,    47,   379,   233,
     646,   545,   845,   354,   675,   230,   121,   295,   457,   826,
     722,    53,   290,   725,   390,   291,   138,   871,    31,   116,
     214,   135,    47,   221,   283,   425,   914,   220,   138,   462,
      31,   121,   230,   551,   888,    71,   357,   467,   319,   156,
    1019,   111,   463,   308,   464,   110,   475,   270,   582,   178,
     241,   157,   920,   178,   178,    56,   318,   500,   441,   270,
     427,   945,    57,   214,   466,   610,   895,   946,   496,   846,
     498,   293,   469,   128,   657,   230,   122,   832,   899,   419,
     497,   928,  -402,   756,   827,    31,   125,   139,   975,   802,
     136,    54,   828,   137,   138,   495,    78,   178,   241,   233,
     178,   178,   966,   889,   320,   677,   890,   863,  -140,  1020,
    -140,  -140,   385,   428,   680,   385,   933,   939,   555,   385,
      31,  -140,   764,   248,    58,   385,   233,   742,   385,   385,
     385,   385,   385,   896,   385,   968,   611,   481,   657,   386,
     294,   470,   386,   984,   868,   900,   386,   532,   929,   533,
     657,   837,   386,   657,   757,   386,   386,   386,   386,   386,
     988,   386,   774,   775,   144,   428,   116,   683,   576,   233,
     230,   593,   678,   427,   733,   659,   108,    59,   121,  1011,
    1015,   681,   713,   934,   940,   214,    74,   427,   657,   657,
     390,   494,   148,   765,   604,   876,   717,   230,   499,   319,
     148,   317,   969,   -32,   761,    73,   482,   657,   235,    57,
     985,  1036,   -32,   390,   221,   657,   155,   396,   220,    46,
      48,  1047,   427,   427,   653,   427,   166,   989,   323,  1056,
     174,   390,   657,   108,   259,   108,   325,    71,    62,   270,
    1081,    71,   178,   178,   660,    79,  1012,  1016,   173,   714,
     829,   657,   657,   668,   214,   670,   255,   977,  1086,  1096,
     108,  1110,   100,   718,   233,   320,   230,   148,   236,   391,
     556,   737,   265,   392,    58,   739,   753,   393,  1037,   152,
    -537,  -537,   669,   657,    71,   911,   178,   178,  1048,   585,
     237,   233,   955,   657,   324,  1022,  1057,  1025,   165,   303,
      31,   657,   326,   155,   248,    57,   361,  1082,   235,   363,
     833,   834,   657,   373,   838,   839,   145,    58,   381,   254,
     258,   100,   709,    31,    31,  1087,  1097,   277,  1111,    57,
     657,   657,   266,   657,    54,   235,    69,    70,   738,   901,
     267,  1049,   740,   754,    35,    53,   100,   176,   569,   427,
     390,   873,   912,    31,    97,   556,    78,   278,    54,   956,
     233,   733,   302,   305,  1026,   626,   152,    58,   236,   909,
     539,   829,   362,   736,   526,   364,   250,   259,   235,   374,
     748,   390,   671,   570,   382,   732,    49,   311,   710,   777,
     237,   419,   273,    78,    57,   236,   588,    36,   759,   427,
     622,   763,    30,   540,   420,   221,   878,   108,   589,   220,
      49,    31,    49,   419,    78,   385,   965,   237,   247,   238,
     570,   390,    78,    54,    78,   275,   864,   807,    38,   394,
     623,    43,   556,   527,   528,   529,   530,   419,   236,   266,
      71,   570,   386,    49,   273,   214,    33,   267,   604,   248,
     951,   570,    40,   996,   246,    31,    31,   230,   435,    68,
     237,    31,    42,   447,   391,    87,    67,    88,   514,    80,
      89,    31,   393,   235,    82,    31,    90,   107,    31,   124,
     124,   733,    91,    31,   650,   843,   844,   651,   286,    92,
      54,    93,    84,   100,   107,   127,   124,   556,  -413,    94,
     235,    31,  -413,   146,    31,  -413,  -413,   390,   390,   214,
     214,   491,    31,   214,   214,   148,   869,   274,  1001,   238,
     219,   230,   230,   426,   230,   230,   230,   435,   435,   643,
     861,   862,   240,   236,   107,   107,   107,   372,   390,   945,
    -415,    31,   400,   401,  -415,   946,   238,  -415,  -415,   730,
     214,   233,    97,   656,   124,   237,   721,   262,   657,   721,
     236,   107,   230,  -584,  -584,  -584,  -584,  -584,  -584,   235,
     554,   515,   516,   517,  -584,  -584,  -584,   107,   107,    77,
      78,   107,   237,   251,  -584,   124,  -584,   755,   124,   238,
     396,  -584,   657,   266,    54,    54,   124,    54,   763,   842,
     922,   281,   925,   923,   924,   926,   927,    54,   931,   932,
     297,   613,   930,   723,   298,   233,   233,    54,   233,   233,
     233,    54,  1002,   367,  -538,  -538,  1005,    54,   390,   236,
     245,   322,  1008,   389,  1032,   384,   384,   869,   869,   657,
      54,   625,   372,   230,   107,  1033,   397,   219,    54,  1072,
    1100,   237,    54,  1063,   657,   657,   233,  1075,    54,    54,
     435,    54,    54,  1078,  1083,    54,  1101,  1104,   375,    54,
    1107,   107,   398,   107,  1114,   522,   523,   524,   107,   299,
     417,   418,   300,   724,   238,   726,  1003,  1004,   390,   453,
     219,  1006,  1007,  1009,  1010,   399,   124,   416,   124,   519,
     520,   417,   632,   953,   954,   221,   442,   452,   107,   220,
     390,   238,   267,   468,   599,   476,   483,   214,   484,  1034,
    1035,   485,   506,   510,   535,   536,   107,   537,   230,   230,
     538,   546,   549,   552,   124,   553,   561,   233,   575,   563,
     124,   574,   107,   107,   578,   214,  1027,  1028,   596,   583,
     594,   617,   618,   624,   628,   629,  -176,   230,   630,   644,
     235,   642,    78,   712,   655,   652,   672,   654,   658,  1064,
    1065,   661,   390,   673,   676,   384,   679,   704,   221,   706,
     238,   707,   220,   443,   445,   219,   708,   450,   451,   715,
     716,   573,  -481,   731,  1076,  1077,  1079,  1080,   735,  1084,
    1085,   107,   741,   747,   758,   230,   762,   766,   767,   768,
     786,   419,   779,   794,   799,   785,  1070,  1071,   214,   800,
     236,   821,   233,   233,   235,   235,   840,   235,   235,   235,
     230,   488,   489,   804,   492,   493,   808,   435,   809,  1102,
    1103,   810,   237,   811,  1105,  1106,  1108,  1109,   812,   813,
     814,   233,   815,   321,   816,   817,   107,   818,   819,   820,
     822,   823,   824,   723,   853,   235,   841,   857,  1115,  1116,
     230,   877,   858,   865,   884,   107,   872,   874,   886,   885,
     107,   219,   887,   350,   236,   236,   891,   236,   236,   236,
     371,   892,   729,  -177,    31,   376,   893,   894,   383,   233,
     897,   898,   908,    87,   417,    88,   237,   237,    89,   237,
     237,   237,   915,   921,    90,   938,   944,   957,   958,   421,
      91,   964,   967,   973,   233,   236,   976,    92,  1018,    93,
     448,   978,   979,   980,   981,   982,   983,    94,   986,   987,
     993,   384,   994,   995,   384,   999,   235,   237,   384,  1013,
    1014,  1045,  1031,  1044,   384,  1046,   776,   384,   384,   384,
     384,   384,  1050,   384,   233,  1051,   790,   793,  1052,  1053,
    1054,   238,  1055,   486,   487,  1062,   634,   635,   107,  1066,
    1069,   432,    45,  1091,  1092,  1093,   248,  1094,  1095,  1099,
      31,  1112,  1113,   107,   285,   465,   781,   609,   782,    87,
     256,    88,   479,   307,    89,   751,   236,   107,  1021,   867,
      90,  1023,   916,   509,   433,   513,    91,   560,   460,   567,
     664,   665,   685,    92,   687,    93,   760,   689,   237,   691,
     697,   235,   235,    94,   695,   238,   238,   703,   238,   238,
     238,   693,   107,   107,   910,   107,   699,     0,   434,     0,
       0,     0,   107,   562,   849,   852,     0,     0,   856,     0,
     235,     0,     0,   579,   580,   787,     0,     0,     0,     0,
       0,   595,   219,     0,     0,     0,   238,     0,     0,     0,
       0,   600,     0,     0,     0,   883,     0,     0,   606,     0,
       0,   236,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   608,     0,     0,     0,   235,   616,
       0,     0,   503,   237,   237,     0,     0,   631,     0,   633,
     236,    31,   904,   907,   637,   638,     0,     0,     0,     0,
      87,     0,    88,   235,     0,    89,     0,     0,     0,    31,
       0,    90,   237,     0,     0,   433,     0,    91,    87,     0,
      88,     0,     0,    89,    92,     0,    93,   238,     0,    90,
       0,     0,   662,   663,    94,    91,   666,   667,   236,   107,
     124,     0,    92,   235,    93,     0,   937,     0,    31,   504,
     943,     0,    94,     0,   880,     0,     0,    87,     0,    88,
     237,     0,    89,   236,     0,     0,     0,     0,    90,     0,
     960,   963,   433,   600,    91,     0,   426,   972,     0,     0,
       0,    92,     0,    93,     0,   237,     0,     0,     0,   107,
       0,    94,     0,     0,     0,     0,     0,     0,   701,     0,
       0,   992,   705,   236,     0,     0,   501,     0,     0,     0,
       0,     0,   238,   238,   384,     0,     0,     0,     0,     0,
       0,     0,   720,     0,     0,   237,     0,   181,   182,   183,
     184,   185,   186,   187,    31,   188,   189,   190,   191,   192,
     193,   238,  -585,  -585,  -585,  -585,  -585,  -585,     0,     0,
    1030,     0,     0,  -585,  -585,  -585,     0,  1040,  1043,     0,
       0,   124,   124,  -585,     0,  -585,     0,     0,     0,     0,
    -585,   200,   616,     0,     0,     0,     0,     0,   783,   784,
     202,     0,     0,   205,     0,     0,  1060,    31,     0,   238,
       0,   209,     0,     0,     0,     0,    87,     0,    88,     0,
       0,    89,   212,   213,     0,     0,     0,    90,   805,   806,
       0,   584,     0,    91,   238,     0,   803,     0,     0,     0,
      92,     0,    93,     0,  1074,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,     0,  1090,     0,     0,
       0,     0,   219,     0,     0,   866,     0,     0,     0,     0,
       0,     0,     0,   769,   238,   181,   182,   183,   184,   185,
     186,   187,    31,   188,   189,   190,   191,   192,   193,   825,
       0,     0,     0,     0,   836,     0,     0,     0,   369,     0,
     181,   182,   183,   184,   185,   186,   187,    31,   188,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,   200,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   205,     0,     0,     0,   219,     0,     0,     0,   209,
       0,   613,   770,     0,   200,   771,     0,     0,     0,     0,
     212,   213,   327,   202,   328,     1,   205,     0,     0,     0,
       0,     0,     0,     2,   209,   329,   330,     0,     0,     0,
       3,   370,     4,     0,     0,   212,   213,   327,     0,   328,
       0,     0,     6,     0,     7,   331,     0,     9,    10,    11,
     329,   330,    12,    13,     0,     0,    14,     0,     0,     0,
      15,     0,     0,    16,     0,     0,   913,   616,     0,   471,
     331,   181,   182,   183,   184,   185,   186,   187,    31,   188,
     189,   190,   191,   192,   193,     0,   507,     0,   181,   182,
     183,   184,   185,   186,   187,    31,   188,   189,   190,   191,
     192,   193,     0,   952,     0,   403,   404,   405,   406,   407,
     408,     0,     0,     0,     0,   200,   409,   410,   411,     0,
       0,     0,     0,     0,   202,     0,   412,   205,   413,   616,
       0,     0,   200,   414,     0,   209,   472,     0,     0,     0,
       0,   202,     0,     0,   205,     0,   212,   213,   327,     0,
     328,     0,   209,   508,   998,     0,     0,     0,     0,     0,
       0,   329,   330,   212,   213,   327,     0,   328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   329,   330,
       0,   331,     0,     0,  1017,     0,     0,     0,     0,     0,
    1024,     0,     0,     0,     0,     0,     0,   511,   331,   181,
     182,   183,   184,   185,   186,   187,    31,   188,   189,   190,
     191,   192,   193,     0,   424,     0,   181,   182,   183,   184,
     185,   186,   187,    31,   188,   189,   190,   191,   192,   193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,   202,     0,     0,   205,     0,     0,     0,     0,
     200,     0,     0,   209,   512,     0,     0,     0,     0,   202,
       0,     0,   205,     0,   212,   213,   327,     0,   328,     0,
     209,     0,     0,     0,     0,   425,     0,     0,     0,   329,
     330,   212,   213,   327,     0,   328,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   329,   330,   612,   331,
     181,   182,   183,   184,   185,   186,   187,    31,   188,   189,
     190,   191,   192,   193,     0,   727,   331,   181,   182,   183,
     184,   185,   186,   187,    31,   188,   189,   190,   191,   192,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,   780,     0,     0,     0,     0,
       0,     0,     0,   202,    31,     0,   205,     0,     0,     0,
       0,   200,     0,    87,   209,    88,   613,     0,    89,     0,
     202,     0,     0,   205,    90,   212,   213,   327,   433,   328,
      91,   209,   728,     0,     0,     0,     0,    92,     0,    93,
     329,   330,   212,   213,   327,     0,   328,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   329,   330,   788,
     331,   181,   182,   183,   184,   185,   186,   187,    31,   188,
     189,   190,   191,   192,   193,     0,   791,   331,   181,   182,
     183,   184,   185,   186,   187,    31,   188,   189,   190,   191,
     192,   193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,     0,     0,     0,     0,
       0,     0,     0,     0,   202,     0,     0,   205,     0,     0,
       0,     0,   200,     0,     0,   209,   789,     0,     0,     0,
       0,   202,     0,     0,   205,     0,   212,   213,   327,     0,
     328,     0,   209,   792,     0,     0,     0,     0,     0,     0,
       0,   329,   330,   212,   213,   327,     0,   328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   329,   330,
     847,   331,   181,   182,   183,   184,   185,   186,   187,    31,
     188,   189,   190,   191,   192,   193,     0,   850,   331,   181,
     182,   183,   184,   185,   186,   187,    31,   188,   189,   190,
     191,   192,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,   202,     0,     0,   205,     0,
       0,     0,     0,   200,     0,     0,   209,   848,     0,     0,
       0,     0,   202,     0,     0,   205,     0,   212,   213,   327,
       0,   328,     0,   209,   851,     0,     0,     0,     0,     0,
       0,     0,   329,   330,   212,   213,   327,     0,   328,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   329,
     330,   854,   331,   181,   182,   183,   184,   185,   186,   187,
      31,   188,   189,   190,   191,   192,   193,     0,   881,   331,
     181,   182,   183,   184,   185,   186,   187,    31,   188,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,     0,
       0,     0,     0,     0,     0,     0,   202,     0,     0,   205,
       0,     0,     0,     0,   200,     0,     0,   209,   855,     0,
       0,     0,     0,   202,     0,     0,   205,     0,   212,   213,
     327,     0,   328,     0,   209,   882,     0,     0,     0,     0,
       0,     0,     0,   329,   330,   212,   213,   327,     0,   328,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     329,   330,   902,   331,   181,   182,   183,   184,   185,   186,
     187,    31,   188,   189,   190,   191,   192,   193,     0,   905,
     331,   181,   182,   183,   184,   185,   186,   187,    31,   188,
     189,   190,   191,   192,   193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,     0,
     205,     0,     0,     0,     0,   200,     0,     0,   209,   903,
       0,     0,     0,     0,   202,     0,     0,   205,     0,   212,
     213,   327,     0,   328,     0,   209,   906,     0,     0,     0,
       0,     0,     0,     0,   329,   330,   212,   213,   327,     0,
     328,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   329,   330,   935,   331,   181,   182,   183,   184,   185,
     186,   187,    31,   188,   189,   190,   191,   192,   193,     0,
     941,   331,   181,   182,   183,   184,   185,   186,   187,    31,
     188,   189,   190,   191,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   205,     0,     0,     0,     0,   200,     0,     0,   209,
     936,     0,     0,     0,     0,   202,     0,     0,   205,     0,
     212,   213,   327,     0,   328,     0,   209,   942,     0,     0,
       0,     0,     0,     0,     0,   329,   330,   212,   213,   327,
       0,   328,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   329,   330,   961,   331,   181,   182,   183,   184,
     185,   186,   187,    31,   188,   189,   190,   191,   192,   193,
       0,   970,   331,   181,   182,   183,   184,   185,   186,   187,
      31,   188,   189,   190,   191,   192,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,     0,     0,     0,     0,     0,     0,     0,   202,
       0,     0,   205,     0,     0,     0,     0,   200,     0,     0,
     209,   962,     0,     0,     0,     0,   202,     0,     0,   205,
       0,   212,   213,   327,     0,   328,     0,   209,   971,     0,
       0,     0,     0,     0,     0,     0,   329,   330,   212,   213,
     327,     0,   328,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   329,   330,   990,   331,   181,   182,   183,
     184,   185,   186,   187,    31,   188,   189,   190,   191,   192,
     193,     0,  1038,   331,   181,   182,   183,   184,   185,   186,
     187,    31,   188,   189,   190,   191,   192,   193,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,     0,     0,     0,     0,     0,     0,     0,     0,
     202,     0,     0,   205,     0,     0,     0,     0,   200,     0,
       0,   209,   991,     0,     0,     0,     0,   202,     0,     0,
     205,     0,   212,   213,   327,     0,   328,     0,   209,  1039,
       0,     0,     0,     0,     0,     0,     0,   329,   330,   212,
     213,   327,     0,   328,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   329,   330,  1041,   331,   181,   182,
     183,   184,   185,   186,   187,    31,   188,   189,   190,   191,
     192,   193,     0,  1058,   331,   181,   182,   183,   184,   185,
     186,   187,    31,   188,   189,   190,   191,   192,   193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,     0,     0,     0,     0,     0,     0,     0,
       0,   202,     0,     0,   205,     0,     0,     0,     0,   200,
       0,     0,   209,  1042,     0,     0,     0,     0,   202,     0,
       0,   205,     0,   212,   213,   327,     0,   328,     0,   209,
    1059,     0,     0,     0,     0,     0,     0,     0,   329,   330,
     212,   213,   327,     0,   328,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   329,   330,  1088,   331,   181,
     182,   183,   184,   185,   186,   187,    31,   188,   189,   190,
     191,   192,   193,     0,   544,   331,   181,   182,   183,   184,
     185,   186,   187,    31,   188,   189,   190,   191,   192,   193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,   202,     0,     0,   205,     0,     0,     0,     0,
     200,     0,     0,   209,  1089,     0,     0,     0,     0,   202,
       0,     0,   205,     0,   212,   213,   327,     0,   328,     0,
     209,     0,     0,     0,     0,     0,     0,     0,     0,   329,
     330,   212,   213,   327,     0,   328,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   329,   330,   607,   331,
     181,   182,   183,   184,   185,   186,   187,    31,   188,   189,
     190,   191,   192,   193,     0,   682,   331,   181,   182,   183,
     184,   185,   186,   187,    31,   188,   189,   190,   191,   192,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,   645,     0,     0,     0,     0,
       0,     0,     0,   202,    31,     0,   205,     0,     0,     0,
       0,   200,     0,    87,   209,    88,     0,     0,    89,     0,
     202,     0,     0,   205,    90,   212,   213,   327,     0,   328,
      91,   209,     0,     0,     0,     0,     0,    92,     0,    93,
     329,   330,   212,   213,   327,     0,   328,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   329,   330,   684,
     331,   181,   182,   183,   184,   185,   186,   187,    31,   188,
     189,   190,   191,   192,   193,     0,   686,   331,   181,   182,
     183,   184,   185,   186,   187,    31,   188,   189,   190,   191,
     192,   193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,     0,     0,     0,     0,
       0,     0,     0,     0,   202,    31,     0,   205,     0,     0,
       0,     0,   200,     0,    87,   209,    88,     0,     0,    89,
       0,   202,     0,     0,   205,    90,   212,   213,   327,   584,
     328,    91,   209,     0,     0,     0,     0,     0,    92,     0,
      93,   329,   330,   212,   213,   327,     0,   328,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   329,   330,
     688,   331,   181,   182,   183,   184,   185,   186,   187,    31,
     188,   189,   190,   191,   192,   193,     0,   690,   331,   181,
     182,   183,   184,   185,   186,   187,    31,   188,   189,   190,
     191,   192,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,   202,    31,     0,   205,     0,
       0,     0,     0,   200,     0,    87,   209,    88,     0,     0,
      89,     0,   202,     0,     0,   205,    90,   212,   213,   327,
       0,   328,    91,   209,     0,     0,     0,     0,     0,    92,
       0,    93,   329,   330,   212,   213,   327,     0,   328,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   329,
     330,   692,   331,   181,   182,   183,   184,   185,   186,   187,
      31,   188,   189,   190,   191,   192,   193,     0,   694,   331,
     181,   182,   183,   184,   185,   186,   187,    31,   188,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,     0,
       0,     0,     0,     0,     0,     0,   202,     0,     0,   205,
       0,     0,     0,     0,   200,     0,     0,   209,     0,     0,
       0,     0,     0,   202,     0,     0,   205,     0,   212,   213,
     327,     0,   328,     0,   209,     0,     0,     0,     0,     0,
       0,     0,     0,   329,   330,   212,   213,   327,     0,   328,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     329,   330,   696,   331,   181,   182,   183,   184,   185,   186,
     187,    31,   188,   189,   190,   191,   192,   193,     0,   698,
     331,   181,   182,   183,   184,   185,   186,   187,    31,   188,
     189,   190,   191,   192,   193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,     0,
     205,     0,     0,     0,     0,   200,     0,     0,   209,     0,
       0,     0,     0,     0,   202,     0,     0,   205,     0,   212,
     213,   327,     0,   328,     0,   209,     0,     0,     0,     0,
       0,     0,     0,     0,   329,   330,   212,   213,   327,     0,
     328,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   329,   330,   700,   331,   181,   182,   183,   184,   185,
     186,   187,    31,   188,   189,   190,   191,   192,   193,     0,
     702,   331,   181,   182,   183,   184,   185,   186,   187,    31,
     188,   189,   190,   191,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,   205,     0,     0,     0,     0,   200,     0,     0,   209,
       0,     0,     0,     0,     0,   202,     0,     0,   205,     0,
     212,   213,   327,     0,   328,     0,   209,     0,     0,     0,
       0,     0,     0,     0,     0,   329,   330,   212,   213,   327,
       0,   328,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   329,   330,     0,   331,   181,   182,   183,   184,
     185,   186,   187,    31,   188,   189,   190,   191,   192,   193,
       0,     0,   331,   181,   182,   183,   184,   185,   186,   187,
      31,   188,   189,   190,   191,   192,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,     0,     0,     0,     0,     0,     0,     0,   202,
       0,     0,   205,     0,     0,     0,     0,   200,     0,     0,
     209,     0,   613,   974,     0,     0,   202,     0,     0,   205,
       0,   212,   213,   327,     0,   328,     0,   209,   598,     0,
       0,     0,     0,     0,     0,     0,   329,   330,   212,   213,
     327,     0,   328,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   329,   330,     0,   331,   181,   182,   183,
     184,   185,   186,   187,    31,   188,   189,   190,   191,   192,
     193,     0,     0,   331,   181,   182,   183,   184,   185,   186,
     187,    31,   188,   189,   190,   191,   192,   193,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,     0,     0,     0,     0,     0,     0,     0,     0,
     202,     0,     0,   205,     0,     0,     0,     0,   200,     0,
       0,   209,     0,     0,     0,     0,   719,   202,     0,     0,
     205,     0,   212,   213,   327,     0,   328,     0,   209,     0,
       0,     0,     0,     0,     0,   835,     0,   329,   330,   212,
     213,   327,     0,   328,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   329,   330,     0,   331,   181,   182,
     183,   184,   185,   186,   187,    31,   188,   189,   190,   191,
     192,   193,     0,     0,   331,   181,   182,   183,   184,   185,
     186,   187,    31,   188,   189,   190,   191,   192,   193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,     0,     0,     0,     0,     0,     0,     0,
       0,   202,     0,     0,   205,     0,     0,     0,     0,   200,
       0,     0,   209,     0,   613,     0,     0,     0,   202,     0,
       0,   205,     0,   212,   213,   327,     0,   328,     0,   209,
     959,     0,     0,     0,     0,     0,     0,     0,   329,   330,
     212,   213,   327,     0,   328,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   329,   330,     0,   331,   181,
     182,   183,   184,   185,   186,   187,    31,   188,   189,   190,
     191,   192,   193,     0,     0,   331,   181,   182,   183,   184,
     185,   186,   187,    31,   188,   189,   190,   191,   192,   193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,   202,     0,     0,   205,     0,     0,     0,     0,
     200,     0,     0,   209,     0,     0,     0,     0,     0,   202,
     997,     0,   205,     0,   212,   213,   327,     0,   328,     0,
     209,  1029,     0,     0,     0,     0,     0,     0,     0,   329,
     330,   212,   213,   327,     0,   328,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   329,   330,     0,   331,
     181,   182,   183,   184,   185,   186,   187,    31,   188,   189,
     190,   191,   192,   193,     0,     0,   331,   181,   182,   183,
     184,   185,   186,   187,    31,   188,   189,   190,   191,   192,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   200,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,   205,     0,     0,     0,
       0,   200,     0,     0,   209,  1073,     0,     0,     0,    31,
     202,     0,     0,   205,     0,   212,   213,   327,    87,   328,
      88,   209,     0,    89,     0,     0,     0,     0,     0,    90,
     329,   330,   212,   213,   327,    91,   328,     0,     0,     0,
       0,     0,    92,     0,    93,     0,     0,   329,   330,     0,
     331,     0,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,     0,     0,   180,   331,   181,   182,
     183,   184,   185,   186,   187,    31,   188,   189,   190,   191,
     192,   193,     1,   194,    87,   195,    88,     0,     0,    89,
       2,     0,   196,     0,   197,    90,     0,     3,     0,     4,
       0,    91,   198,   199,     0,     0,     0,     0,    92,     0,
      93,     7,   200,     0,     9,    10,    11,   201,    94,    12,
      13,   455,   203,   204,   456,   206,     0,    15,   207,    86,
      16,   208,   209,     0,    97,   210,     0,     0,    31,   211,
       0,     0,     0,   212,   213,     1,     0,    87,     0,    88,
       0,     0,    89,     2,     0,     0,     0,     0,    90,     0,
       3,     0,     4,     0,    91,     0,     0,   457,     0,     0,
       0,    92,     6,    93,     7,     0,     0,     9,    10,    11,
       0,    94,    95,    13,     0,     0,    14,     0,     0,     0,
      15,   252,    96,    16,     0,     0,     0,    97,    98,     0,
      31,     0,    99,     0,     0,     0,     0,     1,     0,    87,
       0,    88,     0,     0,    89,    50,     0,     0,     0,     0,
      90,     0,    51,     0,     4,     0,    91,     0,     0,     0,
      58,     0,     0,    92,    52,    93,     7,     0,     0,     9,
      10,    11,     0,    94,    12,    13,     0,     0,    14,     0,
       0,   252,    15,     0,   253,    16,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     1,     0,    87,
       0,    88,     0,     0,    89,    50,     0,     0,     0,     0,
      90,     0,    51,     0,     4,     0,    91,     0,     0,     0,
       0,     0,    58,    92,    52,    93,     7,     0,     0,     9,
      10,    11,    31,    94,    12,    13,     0,     0,    14,     1,
       0,    87,    15,    88,   301,    16,    89,     2,     0,     0,
       0,     0,    90,     0,     3,     0,     4,     0,    91,     0,
       0,     0,     0,     0,     0,    92,     6,    93,     7,     0,
       0,     9,    10,    11,     0,    94,    95,    13,     0,     0,
      14,     0,    58,     0,    15,     0,    96,    16,     0,     0,
       0,    97,   260,    31,     0,     0,    99,     0,     0,     0,
       1,     0,    87,     0,    88,     0,     0,    89,     2,     0,
       0,     0,     0,    90,     0,     3,     0,     4,     0,    91,
       0,     0,     0,     0,    58,     0,    92,     6,    93,     7,
       0,     0,     9,    10,    11,     0,    94,    12,    13,     0,
       0,    14,     0,     0,     0,    15,     0,   149,    16,     0,
       0,     0,     0,   150,    31,     0,     0,   151,     0,     0,
       0,     1,     0,    87,     0,    88,     0,     0,    89,     2,
       0,     0,     0,     0,    90,     0,     3,     0,     4,     0,
      91,     0,     0,     0,     0,    58,     0,    92,     6,    93,
       7,     0,     0,     9,    10,    11,     0,    94,    95,    13,
       0,     0,    14,     0,     0,     0,    15,     0,    96,    16,
       0,     0,     0,    97,    31,     0,     0,     0,    99,     0,
       0,     1,     0,    87,     0,    88,     0,     0,    89,     2,
       0,     0,     0,     0,    90,     0,     3,     0,     4,     0,
      91,     0,     0,     0,     0,     0,    58,    92,     6,    93,
       7,     0,     0,     9,    10,    11,     0,    94,    12,    13,
       0,     0,    14,     0,     0,     0,    15,     0,   149,    16,
       0,     0,     0,     0,   306,     0,     0,     0,   151,   180,
       0,   181,   182,   183,   184,   185,   186,   187,    31,   188,
     189,   190,   191,   192,   193,     1,   194,    87,   195,    88,
       0,     0,    89,     2,     0,   196,    58,   197,    90,     0,
       3,     0,     4,     0,    91,   198,   199,     0,     0,     0,
       0,    92,     0,    93,     7,   200,     0,     9,    10,    11,
     201,    94,    12,    13,   202,   203,   204,   205,   206,     0,
      15,   207,     0,    16,   208,   209,     0,    97,   210,     0,
       0,     0,   211,     0,     0,     0,   212,   213,   181,   182,
     183,   184,   185,   186,   187,    31,   188,   189,   190,   191,
     192,   193,     1,   194,    87,   195,    88,   945,     0,    89,
       2,     0,   196,   946,   197,    90,     0,     3,     0,     4,
       0,    91,   198,   199,     0,     0,     0,     0,    92,     0,
      93,     7,   200,     0,     9,    10,    11,   201,    94,    12,
      13,   202,   203,   204,   205,   206,     0,    15,   207,     0,
      16,   208,   209,     0,    97,     0,     0,     0,     0,   211,
       0,     0,     0,   212,   213,   181,   182,   183,   184,   185,
     186,   187,    31,   188,   189,   190,   191,   192,   193,     1,
     194,    87,   195,    88,     0,     0,    89,     2,     0,   196,
       0,   197,    90,     0,     3,     0,     4,     0,    91,   198,
     199,     0,     0,     0,     0,    92,     0,    93,     7,   200,
       0,     9,    10,    11,   201,    94,    12,    13,   202,   203,
     204,   205,   206,     0,    15,   207,     0,    16,   208,   209,
       0,    97,   395,     0,     0,     0,   211,     0,     0,     0,
     212,   213,   181,   182,   183,   184,   185,   186,   187,    31,
     188,   189,   190,   191,   192,   193,     1,   194,    87,   195,
      88,     0,     0,    89,     2,     0,   196,     0,   197,    90,
       0,     3,     0,     4,     0,    91,   198,   199,     0,     0,
       0,     0,    92,     0,    93,     7,   200,     0,     9,    10,
      11,   201,    94,    12,    13,   202,   203,   204,   205,   206,
       0,    15,   207,     0,    16,   208,   209,     0,    97,   648,
       0,     0,     0,   211,     0,     0,     0,   212,   213,   181,
     182,   183,   184,   185,   186,   187,    31,   188,   189,   190,
     191,   192,   193,     1,   194,    87,   195,    88,     0,     0,
      89,     2,     0,   196,     0,   197,    90,     0,     3,     0,
       4,     0,    91,   198,   199,     0,     0,     0,     0,    92,
       0,    93,     7,   200,     0,     9,    10,    11,   201,    94,
      12,    13,   202,   203,   204,   205,   206,     0,    15,   207,
       0,    16,   208,   209,     0,    97,   798,     0,     0,     0,
     211,     0,     0,     0,   212,   213,   181,   182,   183,   184,
     185,   186,   187,    31,   188,   189,   190,   191,   192,   193,
       1,   194,    87,   195,    88,     0,     0,    89,     2,     0,
     196,     0,   197,    90,     0,     3,     0,     4,     0,    91,
     198,   199,     0,     0,     0,     0,    92,     0,    93,     7,
     200,     0,     9,    10,    11,   201,    94,    12,    13,   202,
     203,   204,   205,   206,     0,    15,   207,     0,    16,   208,
     209,     0,    97,     0,     0,     0,     0,   211,     0,     0,
       0,   212,   213,   181,   182,   183,   184,   185,   186,   187,
      31,   188,   189,   190,   191,   192,   193,     1,     0,    87,
       0,    88,     0,     0,    89,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     4,     0,    91,     0,     0,     0,
       0,     0,     0,    92,     0,    93,     7,   200,     0,     9,
      10,    11,     0,    94,    12,    13,   202,     0,    14,   205,
       0,     0,    15,     0,     0,    16,     0,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   212,   213,
     181,   182,   183,   184,   185,   186,   187,    31,   188,   189,
     190,   191,   192,   193,     0,   194,     0,   195,     0,     0,
       0,     0,     0,     0,   196,     0,   197,     0,     0,     0,
       0,     0,     0,     0,   198,   199,     0,     0,     0,     0,
       0,     0,     0,     0,   200,     0,     0,     0,     0,   201,
     639,     0,     0,   202,   203,   359,   205,   206,     0,    31,
     207,     0,     0,   208,   209,     0,    97,     0,    87,     0,
      88,   211,     0,    89,     0,   212,   213,   252,     0,    90,
       0,     0,     0,   433,     0,    91,    31,     0,     0,     0,
       0,     0,    92,     1,    93,    87,     0,    88,     0,     0,
      89,    50,    94,     0,     0,     0,    90,     0,    51,     0,
       4,     0,    91,     0,     0,     0,     0,   640,     0,    92,
       0,    93,     7,     0,     0,     9,    10,    11,    31,    94,
      12,    13,     0,     0,    14,     1,     0,    87,    15,    88,
       0,    16,    89,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     4,     0,    91,     0,     0,     0,     0,     0,
       0,    92,     0,    93,     7,     0,     0,     9,    10,    11,
      31,    94,    12,    13,     0,     0,    14,     0,     0,    87,
      15,    88,     0,    16,    89,     0,    31,     0,     0,     0,
      90,     0,     0,     0,     0,    87,    91,    88,     0,     0,
      89,     0,     0,    92,     0,    93,    90,     0,     0,     0,
       0,    31,    91,    94,     0,     0,     0,     0,     0,    92,
      87,    93,    88,     0,   304,    89,     1,     0,     0,    94,
       0,    90,     0,     0,     2,     0,     0,    91,     0,     0,
     446,     3,     0,     4,    92,     0,    93,     0,     0,     0,
       5,     0,     0,     6,    94,     7,     0,     8,     9,    10,
      11,     1,     0,    12,    13,   490,     0,    14,     0,     2,
       0,    15,     0,     0,    16,     0,     3,     0,     4,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     6,     0,
       7,     0,     0,     9,    10,    11,     1,     0,    12,    13,
       0,     0,    14,     0,    50,     0,    15,     0,     0,    16,
       0,    51,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     7,     0,     0,     9,    10,
      11,   391,     0,    12,    13,   514,     0,    14,     0,   393,
       0,    15,     0,     0,    16,     0,     0,     0,  -583,  -583,
    -583,  -583,  -583,  -583,     0,     0,     0,     0,     0,  -583,
    -583,  -583,     0,     0,     0,     0,     0,     0,     0,  -583,
       0,  -583,     0,     0,     0,     0,  -583
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-882))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      32,   248,   224,   254,   197,   573,   256,   362,     2,     3,
     435,   200,     6,   200,   458,   113,   212,   213,   268,   372,
      54,   613,   366,    73,    54,   590,    26,    59,    60,    34,
     137,    10,    34,   140,     1,    56,    57,    71,    10,   920,
     393,    71,     1,   212,   213,   398,    10,     1,    80,    81,
      10,   302,    73,    33,    59,    54,    50,    51,    52,    33,
      40,   248,    64,    97,    58,     1,   590,    97,    62,   593,
      33,   212,   213,   319,   320,    47,    81,    10,    83,   113,
      82,    83,     1,   113,    56,     1,     0,    47,    10,    69,
       1,   123,    71,    56,    10,    69,    95,    76,     1,    10,
     132,    69,    96,    97,   138,    84,   100,   139,   138,    76,
     131,   111,   162,    72,   113,    97,   997,     1,   123,   118,
      74,   120,    76,   173,   158,     1,    10,     1,   158,   554,
     102,   378,     1,    41,   166,   167,    10,    73,   102,   138,
       1,   162,   102,   394,   165,    54,    69,     1,    67,    10,
      69,   145,   173,     1,   154,   149,   352,    54,   152,    70,
     585,   166,    71,    74,     1,     1,    74,   103,   170,   102,
       1,    74,    56,     1,    71,    91,    84,    85,   367,   200,
     102,  1062,    10,   352,   291,     1,   751,   285,    74,     1,
     224,   378,   760,    69,   224,    74,   389,     1,   448,    68,
     625,   195,   196,   197,   113,    74,   452,    20,   207,    97,
     457,   352,     1,    74,    68,   197,   113,    91,   102,     1,
     564,   221,    70,   567,   218,    73,    74,   751,    10,   138,
     224,     1,    45,   267,    70,    72,   828,   267,    74,   271,
      10,   138,   224,    74,     1,    69,    74,   279,     1,   158,
       1,   285,   273,   161,   275,   285,   288,   256,    74,   253,
     254,   158,    74,   257,   258,    33,   174,   317,    72,   268,
     457,    22,    40,   267,   279,     1,     1,    28,   310,    68,
     312,     1,     1,   277,    73,   267,   285,   712,     1,    71,
     311,     1,    74,     1,    76,    10,   317,   291,   890,   652,
      70,    69,    84,    73,    74,   310,    75,   301,   302,   197,
     304,   305,   880,    70,    67,     1,    73,   742,    71,    70,
      73,    74,   518,   570,     1,   521,     1,     1,   362,   525,
      10,    84,     1,   102,   102,   531,   224,   584,   534,   535,
     536,   537,   538,    68,   540,     1,    72,     1,    73,   518,
      70,    70,   521,     1,    34,    68,   525,    81,    68,    83,
      73,   716,   531,    73,    72,   534,   535,   536,   537,   538,
       1,   540,   619,   620,    74,   622,   285,   518,   372,   267,
     362,   380,    68,   570,   573,     1,    54,    32,   285,     1,
       1,    68,     1,    68,    68,   389,    41,   584,    73,    73,
     394,   309,    70,    72,   398,   758,     1,   389,   316,     1,
      78,    33,    68,     1,   603,    33,    70,    73,    97,    40,
      68,     1,    10,   417,   458,    73,    71,   649,   458,    19,
      20,     1,   619,   620,   466,   622,    81,    68,     1,     1,
      85,   435,    73,   111,   112,   113,     1,    69,    69,   448,
       1,    69,   446,   447,    70,    45,    68,    68,    33,    68,
     711,    73,    73,   495,   458,   497,   111,   892,     1,     1,
     138,     1,    54,    68,   362,    67,   458,   145,    97,    67,
     835,     1,     1,    71,   102,     1,     1,    75,    68,    71,
      78,    79,   497,    73,    69,     1,   490,   491,    68,   746,
      97,   389,     1,    73,    67,   949,    68,     1,    33,   154,
      10,    73,    67,   158,   102,    40,     1,    68,   197,     1,
     713,   714,    73,     1,   717,   718,    75,   102,     1,   111,
     112,   113,     1,    10,    10,    68,    68,    73,    68,    40,
      73,    73,    61,    73,    69,   224,    74,    75,    68,   796,
      69,   976,    68,    68,     1,   555,   138,    70,    67,   746,
     554,   754,    68,    10,    69,   920,    75,   103,    69,    68,
     458,   760,   154,   155,    68,    75,   158,   102,   197,    56,
      77,   832,    67,   577,    42,    67,    67,   255,   267,    67,
     589,   585,   500,   102,    67,    67,    22,    33,    67,    75,
     197,    71,    73,    75,    40,   224,    23,    54,   602,   796,
      73,   605,     1,   110,    84,   649,    67,   285,    35,   649,
      46,    10,    48,    71,    75,   821,    67,   224,    71,    97,
     102,   625,    75,    69,    75,    33,    84,   669,     5,   221,
     103,     8,   997,   101,   102,   103,   104,    71,   267,    61,
      69,   102,   821,    79,    73,   649,     1,    69,   652,   102,
      84,   102,     1,   914,    71,    10,    10,   649,   250,    36,
     267,    10,     1,   255,    67,    19,     1,    21,    71,     1,
      24,    10,    75,   362,     1,    10,    30,    54,    10,    56,
      57,   880,    36,    10,    56,   727,   728,    59,    67,    43,
      69,    45,     1,   285,    71,     1,    73,  1062,    71,    53,
     389,    10,    75,     1,    10,    78,    79,   711,   712,   713,
     714,   303,    10,   717,   718,   393,   747,   103,   921,   197,
      97,   713,   714,    77,   716,   717,   718,   319,   320,    67,
     739,   740,     1,   362,   111,   112,   113,    75,   742,    22,
      71,    10,    78,    79,    75,    28,   224,    78,    79,   103,
     754,   649,    69,    68,   131,   362,   564,    74,    73,   567,
     389,   138,   754,    84,    85,    86,    87,    88,    89,   458,
     362,    90,    91,    92,    95,    96,    97,   154,   155,    74,
      75,   158,   389,    71,   105,   162,   107,    68,   165,   267,
    1022,   112,    73,    61,    69,    69,   173,    69,   802,    74,
      74,    74,    74,   845,   846,   847,   848,    69,   850,   851,
      74,    69,    74,    71,    74,   713,   714,    69,   716,   717,
     718,    69,    74,   200,    78,    79,    74,    69,   832,   458,
     100,    70,    74,    76,    68,   212,   213,   868,   869,    73,
      69,   433,    75,   835,   221,    74,    74,   224,    69,    68,
      68,   458,    69,    74,    73,    73,   754,    74,    69,    69,
     452,    69,    69,    74,    74,    69,    74,    74,    67,    69,
      74,   248,    75,   250,    74,    98,    99,   100,   255,   149,
      73,    74,   152,   566,   362,   568,   928,   929,   892,   266,
     267,   933,   934,   935,   936,    71,   273,    74,   275,    93,
      94,    73,    74,   868,   869,   949,    74,    67,   285,   949,
     914,   389,    69,    74,   391,    74,    74,   921,    74,   961,
     962,    74,    74,    74,   106,   111,   303,   108,   920,   921,
     109,    74,    74,    66,   311,    74,    74,   835,    74,    71,
     317,    70,   319,   320,    74,   949,   955,   956,    68,    74,
      74,    74,    74,    74,    68,    73,    73,   949,    74,    67,
     649,    73,    75,   555,    68,    75,    68,    74,    74,  1011,
    1012,    74,   976,    74,    74,   352,    74,    74,  1022,    74,
     458,    74,  1022,   253,   254,   362,    74,   257,   258,    74,
      73,   368,    67,    67,  1036,  1037,  1038,  1039,    67,  1041,
    1042,   378,    74,    67,    75,   997,    67,    74,    74,    74,
      68,    71,    75,   103,    67,    74,  1025,  1026,  1022,    67,
     649,    76,   920,   921,   713,   714,    72,   716,   717,   718,
    1022,   301,   302,    74,   304,   305,    74,   629,    74,  1081,
    1082,    74,   649,    74,  1086,  1087,  1088,  1089,    74,    74,
      74,   949,    74,   179,    74,    74,   433,    74,    74,    74,
      74,    74,    74,    71,    67,   754,    72,    67,  1110,  1111,
    1062,    67,    74,    74,    67,   452,    74,    74,    70,    74,
     457,   458,    70,   194,   713,   714,    75,   716,   717,   718,
     201,    75,   569,    73,    10,   206,    74,    74,   209,   997,
      74,    74,    67,    19,    73,    21,   713,   714,    24,   716,
     717,   718,    74,    31,    30,    74,    74,    67,    10,   245,
      36,    67,    74,    74,  1022,   754,    75,    43,    76,    45,
     256,    74,    74,    74,    74,    74,    74,    53,    74,    74,
      67,   518,    74,    74,   521,    74,   835,   754,   525,    74,
      74,    74,    67,    67,   531,    74,   622,   534,   535,   536,
     537,   538,    74,   540,  1062,    74,   643,   644,    74,    74,
      74,   649,    74,   299,   300,    74,   446,   447,   555,    74,
      74,     1,    19,    74,    74,    74,   102,    74,    74,    74,
      10,    74,    74,   570,   138,   277,   629,   417,   629,    19,
     111,    21,   291,   158,    24,   593,   835,   584,   947,   746,
      30,   949,   832,   324,    34,   326,    36,   362,   267,   366,
     490,   491,   521,    43,   525,    45,   603,   531,   835,   534,
     537,   920,   921,    53,   536,   713,   714,   540,   716,   717,
     718,   535,   619,   620,   821,   622,   538,    -1,    68,    -1,
      -1,    -1,   629,   364,   731,   732,    -1,    -1,   735,    -1,
     949,    -1,    -1,   374,   375,   642,    -1,    -1,    -1,    -1,
      -1,   382,   649,    -1,    -1,    -1,   754,    -1,    -1,    -1,
      -1,   392,    -1,    -1,    -1,   762,    -1,    -1,   399,    -1,
      -1,   920,   921,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   415,    -1,    -1,    -1,   997,   420,
      -1,    -1,     1,   920,   921,    -1,    -1,   443,    -1,   445,
     949,    10,   799,   800,   450,   451,    -1,    -1,    -1,    -1,
      19,    -1,    21,  1022,    -1,    24,    -1,    -1,    -1,    10,
      -1,    30,   949,    -1,    -1,    34,    -1,    36,    19,    -1,
      21,    -1,    -1,    24,    43,    -1,    45,   835,    -1,    30,
      -1,    -1,   488,   489,    53,    36,   492,   493,   997,   746,
     747,    -1,    43,  1062,    45,    -1,   853,    -1,    10,    68,
     857,    -1,    53,    -1,   761,    -1,    -1,    19,    -1,    21,
     997,    -1,    24,  1022,    -1,    -1,    -1,    -1,    30,    -1,
     877,   878,    34,   514,    36,    -1,    77,   884,    -1,    -1,
      -1,    43,    -1,    45,    -1,  1022,    -1,    -1,    -1,   796,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,   539,    -1,
      -1,   908,   543,  1062,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,   920,   921,   821,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   563,    -1,    -1,  1062,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   949,    84,    85,    86,    87,    88,    89,    -1,    -1,
     957,    -1,    -1,    95,    96,    97,    -1,   964,   965,    -1,
      -1,   868,   869,   105,    -1,   107,    -1,    -1,    -1,    -1,
     112,    47,   613,    -1,    -1,    -1,    -1,    -1,   634,   635,
      56,    -1,    -1,    59,    -1,    -1,   993,    10,    -1,   997,
      -1,    67,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,
      -1,    24,    78,    79,    -1,    -1,    -1,    30,   664,   665,
      -1,    34,    -1,    36,  1022,    -1,   657,    -1,    -1,    -1,
      43,    -1,    45,    -1,  1031,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,  1044,    -1,    -1,
      -1,    -1,   949,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,  1062,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   710,
      -1,    -1,    -1,    -1,   715,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    -1,    -1,  1022,    -1,    -1,    -1,    67,
      -1,    69,    70,    -1,    47,    73,    -1,    -1,    -1,    -1,
      78,    79,    80,    56,    82,    17,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    67,    93,    94,    -1,    -1,    -1,
      32,    74,    34,    -1,    -1,    78,    79,    80,    -1,    82,
      -1,    -1,    44,    -1,    46,   113,    -1,    49,    50,    51,
      93,    94,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,
      62,    -1,    -1,    65,    -1,    -1,   827,   828,    -1,     1,
     113,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,   864,    -1,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    47,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    56,    -1,   105,    59,   107,   890,
      -1,    -1,    47,   112,    -1,    67,    68,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    78,    79,    80,    -1,
      82,    -1,    67,    68,   915,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    78,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,   113,    -1,    -1,   945,    -1,    -1,    -1,    -1,    -1,
     951,    -1,    -1,    -1,    -1,    -1,    -1,     1,   113,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    78,    79,    80,    -1,    82,    -1,
      67,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    93,
      94,    78,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,     1,   113,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,     1,   113,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    10,    -1,    59,    -1,    -1,    -1,
      -1,    47,    -1,    19,    67,    21,    69,    -1,    24,    -1,
      56,    -1,    -1,    59,    30,    78,    79,    80,    34,    82,
      36,    67,    68,    -1,    -1,    -1,    -1,    43,    -1,    45,
      93,    94,    78,    79,    80,    -1,    82,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,     1,
     113,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,     1,   113,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    78,    79,    80,    -1,
      82,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    78,    79,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
       1,   113,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,     1,   113,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    59,    -1,    78,    79,    80,
      -1,    82,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    78,    79,    80,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,     1,   113,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,     1,   113,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    78,    79,
      80,    -1,    82,    -1,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    78,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,     1,   113,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,     1,
     113,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    47,    -1,    -1,    67,    68,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    78,
      79,    80,    -1,    82,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    78,    79,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,     1,   113,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
       1,   113,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    47,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      78,    79,    80,    -1,    82,    -1,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    78,    79,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,     1,   113,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,     1,   113,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,
      -1,    78,    79,    80,    -1,    82,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    78,    79,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,     1,   113,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,     1,   113,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    59,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    78,    79,    80,    -1,    82,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    78,
      79,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,     1,   113,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,     1,   113,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    78,    79,    80,    -1,    82,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      78,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,     1,   113,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,     1,   113,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    78,    79,    80,    -1,    82,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    78,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,     1,   113,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,     1,   113,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    10,    -1,    59,    -1,    -1,    -1,
      -1,    47,    -1,    19,    67,    21,    -1,    -1,    24,    -1,
      56,    -1,    -1,    59,    30,    78,    79,    80,    -1,    82,
      36,    67,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,
      93,    94,    78,    79,    80,    -1,    82,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,     1,
     113,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,     1,   113,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    10,    -1,    59,    -1,    -1,
      -1,    -1,    47,    -1,    19,    67,    21,    -1,    -1,    24,
      -1,    56,    -1,    -1,    59,    30,    78,    79,    80,    34,
      82,    36,    67,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    93,    94,    78,    79,    80,    -1,    82,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
       1,   113,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,     1,   113,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    10,    -1,    59,    -1,
      -1,    -1,    -1,    47,    -1,    19,    67,    21,    -1,    -1,
      24,    -1,    56,    -1,    -1,    59,    30,    78,    79,    80,
      -1,    82,    36,    67,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    45,    93,    94,    78,    79,    80,    -1,    82,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,     1,   113,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,     1,   113,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    78,    79,
      80,    -1,    82,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    78,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,     1,   113,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,     1,
     113,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    47,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    78,
      79,    80,    -1,    82,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    78,    79,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,     1,   113,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
       1,   113,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    47,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      78,    79,    80,    -1,    82,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    78,    79,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,   113,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,   113,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      67,    -1,    69,    70,    -1,    -1,    56,    -1,    -1,    59,
      -1,    78,    79,    80,    -1,    82,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    78,    79,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,   113,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,   113,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    59,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    72,    56,    -1,    -1,
      59,    -1,    78,    79,    80,    -1,    82,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    93,    94,    78,
      79,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,   113,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,   113,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    67,    -1,    69,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    78,    79,    80,    -1,    82,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      78,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    -1,   113,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,   113,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    56,
      74,    -1,    59,    -1,    78,    79,    80,    -1,    82,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    78,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,   113,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,   113,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    67,    68,    -1,    -1,    -1,    10,
      56,    -1,    -1,    59,    -1,    78,    79,    80,    19,    82,
      21,    67,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      93,    94,    78,    79,    80,    36,    82,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    45,    -1,    -1,    93,    94,    -1,
     113,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,     1,   113,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    24,
      25,    -1,    27,    -1,    29,    30,    -1,    32,    -1,    34,
      -1,    36,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,     1,
      65,    66,    67,    -1,    69,    70,    -1,    -1,    10,    74,
      -1,    -1,    -1,    78,    79,    17,    -1,    19,    -1,    21,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      32,    -1,    34,    -1,    36,    -1,    -1,   102,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    51,
      -1,    53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,
      62,     1,    64,    65,    -1,    -1,    -1,    69,    70,    -1,
      10,    -1,    74,    -1,    -1,    -1,    -1,    17,    -1,    19,
      -1,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    32,    -1,    34,    -1,    36,    -1,    -1,    -1,
     102,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    51,    -1,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,     1,    62,    -1,    64,    65,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      -1,    21,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    32,    -1,    34,    -1,    36,    -1,    -1,    -1,
      -1,    -1,   102,    43,    44,    45,    46,    -1,    -1,    49,
      50,    51,    10,    53,    54,    55,    -1,    -1,    58,    17,
      -1,    19,    62,    21,    64,    65,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    32,    -1,    34,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    51,    -1,    53,    54,    55,    -1,    -1,
      58,    -1,   102,    -1,    62,    -1,    64,    65,    -1,    -1,
      -1,    69,    70,    10,    -1,    -1,    74,    -1,    -1,    -1,
      17,    -1,    19,    -1,    21,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    30,    -1,    32,    -1,    34,    -1,    36,
      -1,    -1,    -1,    -1,   102,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    51,    -1,    53,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,    62,    -1,    64,    65,    -1,
      -1,    -1,    -1,    70,    10,    -1,    -1,    74,    -1,    -1,
      -1,    17,    -1,    19,    -1,    21,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    34,    -1,
      36,    -1,    -1,    -1,    -1,   102,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    51,    -1,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    62,    -1,    64,    65,
      -1,    -1,    -1,    69,    10,    -1,    -1,    -1,    74,    -1,
      -1,    17,    -1,    19,    -1,    21,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    34,    -1,
      36,    -1,    -1,    -1,    -1,    -1,   102,    43,    44,    45,
      46,    -1,    -1,    49,    50,    51,    -1,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    62,    -1,    64,    65,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    24,    25,    -1,    27,   102,    29,    30,    -1,
      32,    -1,    34,    -1,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    -1,    65,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    78,    79,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    -1,    27,    28,    29,    30,    -1,    32,    -1,    34,
      -1,    36,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    -1,
      65,    66,    67,    -1,    69,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    79,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    24,    25,    -1,    27,
      -1,    29,    30,    -1,    32,    -1,    34,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      78,    79,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    24,    25,    -1,    27,    -1,    29,    30,
      -1,    32,    -1,    34,    -1,    36,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    -1,    65,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    79,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      24,    25,    -1,    27,    -1,    29,    30,    -1,    32,    -1,
      34,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,    43,
      -1,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      -1,    65,    66,    67,    -1,    69,    70,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    79,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    -1,
      27,    -1,    29,    30,    -1,    32,    -1,    34,    -1,    36,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    -1,    65,    66,
      67,    -1,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    79,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      -1,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    -1,    49,
      50,    51,    -1,    53,    54,    55,    56,    -1,    58,    59,
      -1,    -1,    62,    -1,    -1,    65,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
       1,    -1,    -1,    56,    57,    58,    59,    60,    -1,    10,
      63,    -1,    -1,    66,    67,    -1,    69,    -1,    19,    -1,
      21,    74,    -1,    24,    -1,    78,    79,     1,    -1,    30,
      -1,    -1,    -1,    34,    -1,    36,    10,    -1,    -1,    -1,
      -1,    -1,    43,    17,    45,    19,    -1,    21,    -1,    -1,
      24,    25,    53,    -1,    -1,    -1,    30,    -1,    32,    -1,
      34,    -1,    36,    -1,    -1,    -1,    -1,    68,    -1,    43,
      -1,    45,    46,    -1,    -1,    49,    50,    51,    10,    53,
      54,    55,    -1,    -1,    58,    17,    -1,    19,    62,    21,
      -1,    65,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    45,    46,    -1,    -1,    49,    50,    51,
      10,    53,    54,    55,    -1,    -1,    58,    -1,    -1,    19,
      62,    21,    -1,    65,    24,    -1,    10,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    19,    36,    21,    -1,    -1,
      24,    -1,    -1,    43,    -1,    45,    30,    -1,    -1,    -1,
      -1,    10,    36,    53,    -1,    -1,    -1,    -1,    -1,    43,
      19,    45,    21,    -1,    64,    24,    17,    -1,    -1,    53,
      -1,    30,    -1,    -1,    25,    -1,    -1,    36,    -1,    -1,
      64,    32,    -1,    34,    43,    -1,    45,    -1,    -1,    -1,
      41,    -1,    -1,    44,    53,    46,    -1,    48,    49,    50,
      51,    17,    -1,    54,    55,    64,    -1,    58,    -1,    25,
      -1,    62,    -1,    -1,    65,    -1,    32,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      46,    -1,    -1,    49,    50,    51,    17,    -1,    54,    55,
      -1,    -1,    58,    -1,    25,    -1,    62,    -1,    -1,    65,
      -1,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    46,    -1,    -1,    49,    50,
      51,    67,    -1,    54,    55,    71,    -1,    58,    -1,    75,
      -1,    62,    -1,    -1,    65,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,   112
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    25,    32,    34,    41,    44,    46,    48,    49,
      50,    51,    54,    55,    58,    62,    65,   119,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   182,   188,
       1,    10,   120,     1,   120,     1,    54,   120,   131,   132,
       1,   120,     1,   131,     0,   141,   143,   142,   143,   144,
      25,    32,    44,   148,    69,   155,    33,    40,   102,   149,
     153,   155,    69,   183,   153,   183,    74,     1,   131,    74,
      75,    69,   189,    33,   149,   189,    74,    74,    75,   143,
       1,   120,     1,   120,     1,   120,     1,    19,    21,    24,
      30,    36,    43,    45,    53,    54,    64,    69,    70,    74,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     145,   147,   149,   156,   157,   158,   159,   166,   167,   176,
     177,   188,   193,   130,   131,   130,   154,     1,   120,   150,
     151,    33,   153,   155,   155,     1,    70,    73,    74,   120,
     184,   185,   186,   183,    74,    75,     1,    91,   132,    64,
      70,    74,   124,   145,   147,   149,   159,   188,   190,   191,
     192,   154,    33,   189,   155,    33,   149,   153,   155,   183,
     153,   183,   189,    33,   149,   189,    70,   193,   120,   168,
       1,     3,     4,     5,     6,     7,     8,     9,    11,    12,
      13,    14,    15,    16,    18,    20,    27,    29,    37,    38,
      47,    52,    56,    57,    58,    59,    60,    63,    66,    67,
      70,    74,    78,    79,   120,   121,   122,   123,   124,   131,
     145,   147,   159,   193,   194,   195,   196,   197,   216,   217,
     218,   221,   225,   226,   227,   228,   229,   231,   244,   245,
       1,   120,   160,   161,   162,   168,    71,    71,   102,   134,
      67,    71,     1,    64,   124,   149,   177,    64,   124,   132,
      70,   157,    74,   175,   193,     1,    61,    69,   173,   178,
     193,   153,   155,    73,   103,    33,   152,    73,   103,   130,
     155,    74,     1,    70,   186,   156,    67,   155,   187,     1,
      70,    73,   186,     1,    70,    91,   120,    74,    74,   168,
     168,    64,   124,   149,    64,   124,    70,   191,   189,   154,
     130,    33,   153,   155,   155,   183,   154,    33,   189,     1,
      67,   173,    70,     1,    67,     1,    67,    80,    82,    93,
      94,   113,   131,   218,   226,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   247,     1,    74,   120,     1,    74,   120,    58,
     196,     1,    67,     1,    67,   125,   130,   131,   134,     1,
      74,   243,    75,     1,    67,    67,   243,     1,    67,   193,
     202,     1,    67,   243,   131,   225,   227,   230,   230,    76,
     120,    67,    71,    75,   124,    70,   195,    74,    75,    71,
      78,    79,   246,    84,    85,    86,    87,    88,    89,    95,
      96,    97,   105,   107,   112,   253,    74,    73,    74,    71,
      84,   173,     1,    72,     1,    72,    77,   125,   129,   135,
     136,   137,     1,    34,    68,   124,   169,   170,   171,   172,
       1,    72,    74,   168,   160,   168,    64,   124,   173,   178,
     168,   168,    67,   131,   174,    56,    59,   102,   179,   180,
     216,   178,   155,   130,   130,   151,   153,   155,    74,     1,
      70,     1,    68,   220,   243,   155,    74,     1,    70,   185,
     186,     1,    70,    74,    74,    74,   173,   173,   168,   168,
      64,   124,   168,   168,   189,   153,   155,   130,   155,   189,
     154,    68,   169,     1,    68,   169,    74,     1,    68,   243,
      74,     1,    68,   243,    71,    90,    91,    92,   248,    93,
      94,   249,    98,    99,   100,   250,    42,   101,   102,   103,
     104,   251,    81,    83,   252,   106,   111,   108,   109,    77,
     110,     1,    74,    76,     1,   230,    74,     1,    74,    74,
       1,    74,    66,    74,   124,   147,   197,   209,   210,   213,
     215,    74,   243,    71,   222,   223,   224,   222,   224,    67,
     102,   134,   219,   131,    70,    74,   120,   180,    74,   243,
     243,     1,    74,    74,    34,   129,   203,   204,    23,    35,
     198,   199,   201,   193,    74,   243,    68,   196,    68,   220,
     243,    56,   180,    47,   120,   180,   243,     1,   243,   161,
       1,    72,     1,    69,   163,   164,   243,    74,    74,    33,
      56,   138,    73,   103,    74,   124,    75,   162,    68,    73,
      74,   173,    74,   173,   168,   168,   178,   173,   173,     1,
      68,   169,    73,    67,    67,     1,   129,   181,    70,   194,
      56,    59,    75,   155,    74,    68,    68,    73,    74,     1,
      70,    74,   173,   173,   168,   168,   173,   173,   155,   153,
     155,   189,    68,    74,     1,    68,    74,     1,    68,    74,
       1,    68,     1,   230,     1,   232,     1,   233,     1,   234,
       1,   235,     1,   236,     1,   237,     1,   238,     1,   239,
       1,   243,     1,   240,    74,   243,    74,    74,    74,     1,
      67,   162,   124,     1,    68,    74,    73,     1,    68,    72,
     243,   223,   224,    71,   164,   224,   164,     1,    68,   220,
     103,    67,    67,   134,   219,    67,   120,     1,    68,     1,
      68,    74,   129,   162,     1,    68,    74,    67,   193,   199,
     201,   198,   201,     1,    68,    68,     1,    72,    75,   120,
     131,   134,    67,   120,     1,    72,    74,    74,    74,     1,
      70,    73,   163,   165,   129,   129,   136,    75,   162,    75,
       1,   171,   172,   173,   173,    74,    68,   131,     1,    68,
     220,     1,    68,   220,   103,     1,    73,   103,    70,    67,
      67,    56,   180,   243,    74,   173,   173,   155,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    76,    74,    74,    74,   243,     1,    76,    84,   160,
     211,   212,   162,   196,   196,    74,   243,   197,   196,   196,
      72,    72,    74,   155,   155,     1,    68,     1,    68,   220,
       1,    68,   220,    67,     1,    68,   220,    67,    74,     1,
      69,   193,   193,   162,    84,    74,    68,   204,    34,   130,
     200,   201,    74,   196,    74,    10,   180,    67,    67,   219,
     131,     1,    68,   220,    67,    74,    70,    70,     1,    70,
      73,    75,    75,    74,    74,     1,    68,    74,    74,     1,
      68,   129,     1,    68,   220,     1,    68,   220,    67,    56,
     242,     1,    68,   243,   163,    74,   211,   214,   215,     1,
      74,    31,    74,   155,   155,    74,   155,   155,     1,    68,
      74,   155,   155,     1,    68,     1,    68,   220,    74,     1,
      68,     1,    68,   220,    74,    22,    28,   205,   206,   207,
     208,    84,   243,   200,   200,     1,    68,    67,    10,    68,
     220,     1,    68,   220,    67,    67,   219,    74,     1,    68,
       1,    68,   220,    74,    70,   163,    75,   162,    74,    74,
      74,    74,    74,    74,     1,    68,    74,    74,     1,    68,
       1,    68,   220,    67,    74,    74,   160,    74,   243,    74,
     214,   196,    74,   155,   155,    74,   155,   155,    74,   155,
     155,     1,    68,    74,    74,     1,    68,   243,    76,     1,
      70,   206,   194,   208,   243,     1,    68,   193,   193,    68,
     220,    67,    68,    74,   155,   155,     1,    68,     1,    68,
     220,     1,    68,   220,    67,    74,    74,     1,    68,   162,
      74,    74,    74,    74,    74,    74,     1,    68,     1,    68,
     220,   214,    74,    74,   155,   155,    74,     1,    76,    74,
     193,   193,    68,    68,   220,    74,   155,   155,    74,   155,
     155,     1,    68,    74,   155,   155,     1,    68,     1,    68,
     220,    74,    74,    74,    74,    74,     1,    68,   214,    74,
      68,    74,   155,   155,    74,   155,   155,    74,   155,   155,
       1,    68,    74,    74,    74,   155,   155
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
        case 10:

/* Line 1806 of yacc.c  */
#line 174 "parser.ypp"
    {printf("Erraneous literal at line %d\n",yylineno);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 240 "parser.ypp"
    {printf("erraneous name used on line %d\n",yylineno);}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 252 "parser.ypp"
    {printf("error!!missing ] on %d\n",yylineno);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 254 "parser.ypp"
    {printf("error!!missing ] on %d\n",yylineno);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 256 "parser.ypp"
    {printf("error!!missing ] on %d\n",yylineno);}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 293 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<Package,import and class/interface present>>>>>>>>>>\n");}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 295 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<<Package and Class/Interface>>>>>>>>>\n");}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 297 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<<<<<<<<<<Import and Class/Interface>>>>>>>>>>>>>\n");}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 299 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<Only class/interface>>>>>>>>>>>>\n");}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 310 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<Single Import Statement>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 312 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<Multiple Import Statements>>>>>>>>>\n");}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 330 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<Single  Class/Interface Declaration>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 332 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<Multiple Class/Interface Declarations>>>>>>>>>\n");}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 342 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<<Normal Class Declaration>>>>>>>>>>>>>>>>>>>>>>>\n");}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 344 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<<Enum Declaration>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 449 "parser.ypp"
    {if(DEBUG_MODE)	printf("<<<<<<<Class Declarations>>>>>>\n");}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 465 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<Static Block inside class>>>>>>>\n");}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 467 "parser.ypp"
    {if(DEBUG_MODE)	printf("<<<<Constuctor Declaration inside class>>>>>\n");}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 471 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<Field Declaration>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 473 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<Method Declaration>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 475 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<Class Declaration within Class>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 477 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<Interface Declaration within Class>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 487 "parser.ypp"
    {printf("Error!!!missing identifiers at line %d\n",yylineno);}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 489 "parser.ypp"
    {printf("Error!!!missing identifiers at line %d\n",yylineno);}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 503 "parser.ypp"
    {printf("Error!!!missing expression after = at line %d\n",yylineno);}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 509 "parser.ypp"
    {printf("Error!!!missing ] at line %d\n",yylineno);}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 531 "parser.ypp"
    {printf("Missing } on line %d\n",yylineno);}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 580 "parser.ypp"
    {printf("Missing ( on line %d\n",yylineno);}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 582 "parser.ypp"
    {printf("Missing ( on line %d\n",yylineno);}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 584 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 586 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 637 "parser.ypp"
    {printf("Error in constructor body,line %d\n",yylineno);}
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 648 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 650 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 714 "parser.ypp"
    {printf("Missing > on line %d\n",yylineno);}
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 751 "parser.ypp"
    {printf("Missing } on line %d\n",yylineno);}
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 753 "parser.ypp"
    {printf("Missing } on line %d\n",yylineno);}
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 755 "parser.ypp"
    {printf("Missing } on line %d\n",yylineno);}
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 757 "parser.ypp"
    {printf("Missing } on line %d\n",yylineno);}
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 759 "parser.ypp"
    {printf("Missing } on line %d\n",yylineno);}
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 761 "parser.ypp"
    {printf("Missing } on line %d\n",yylineno);}
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 763 "parser.ypp"
    {printf("Missing } on line %d\n",yylineno);}
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 765 "parser.ypp"
    {printf("Missing } on line %d\n",yylineno);}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 825 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Interface Field Declaration>>>>>>>,line %d\n",yylineno);}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 827 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Interface Method Declaration>>>>>>>,line %d\n",yylineno);}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 829 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Interface Class Declaration>>>>>>>,line %d\n",yylineno);}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 831 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Interface Interface Declaration>>>>>>>,line %d\n",yylineno);}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 898 "parser.ypp"
    {if(DEBUG_MODE)	printf("<<<<Labeled Statement>>>>>,line %d\n",yylineno);}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 900 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<SINGLE IF>>>>>>>>,line %d\n",yylineno);}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 902 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<IF ELSE>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 904 "parser.ypp"
    {printf("Missing ( on line %d\n",yylineno);}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 906 "parser.ypp"
    {printf("Missing ) on linr %d\n",yylineno);}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 908 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<Assert Statement>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 910 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<Labeled Assert Statement>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 912 "parser.ypp"
    {printf("Error in assertion at line %d\n",yylineno);}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 914 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<Switch Statement>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 916 "parser.ypp"
    {printf("Missing ( on line %d\n",yylineno);}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 918 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 920 "parser.ypp"
    {printf("Missing { on line %d\n",yylineno);}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 922 "parser.ypp"
    {printf("Missing } on line %d\n",yylineno);}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 924 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<While Statement>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 926 "parser.ypp"
    {printf("Missing ( on line %d\n",yylineno);}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 928 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 930 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<Do While Statement>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 932 "parser.ypp"
    {printf("Missing ( on line %d\n",yylineno);}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 934 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 936 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<For Statement>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 938 "parser.ypp"
    {printf("Missing ( on line %d\n",yylineno);}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 940 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 944 "parser.ypp"
    {printf("Missing ; on line %d\n",yylineno);}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 948 "parser.ypp"
    {printf("Missing ; on line %d\n",yylineno);}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 952 "parser.ypp"
    {printf("Missing ; on line %d\n",yylineno);}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 956 "parser.ypp"
    {printf("Missing ; on line %d\n",yylineno);}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 962 "parser.ypp"
    {printf("Missing ; on line %d\n",yylineno);}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 966 "parser.ypp"
    {printf("Missing ; on line %d\n",yylineno);}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 970 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 1009 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 1011 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 1070 "parser.ypp"
    {printf("Missing : on line %d\n",yylineno);}
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 1079 "parser.ypp"
    {printf("Missing ; on line %d\n",yylineno);}
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 1133 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<Literal>>>>>>,line %d\n",yylineno);}
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 1135 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<this keyword>>>>,line %d\n",yylineno);}
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 1137 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<block>>>>>>,line %d\n",yylineno);}
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 1139 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<class instance creation,line %d>>>>\n",yylineno);}
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 1141 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<Field Access>>>>,line %d\n",yylineno);}
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 1143 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<Method Invocation>>>>,line %d\n",yylineno);}
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 1145 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<Array Access>>>>,line %d\n",yylineno);}
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 1212 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 450:

/* Line 1806 of yacc.c  */
#line 1214 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 451:

/* Line 1806 of yacc.c  */
#line 1216 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 452:

/* Line 1806 of yacc.c  */
#line 1218 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 453:

/* Line 1806 of yacc.c  */
#line 1220 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 454:

/* Line 1806 of yacc.c  */
#line 1222 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 455:

/* Line 1806 of yacc.c  */
#line 1224 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 456:

/* Line 1806 of yacc.c  */
#line 1226 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 457:

/* Line 1806 of yacc.c  */
#line 1228 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 458:

/* Line 1806 of yacc.c  */
#line 1230 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 459:

/* Line 1806 of yacc.c  */
#line 1232 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 460:

/* Line 1806 of yacc.c  */
#line 1234 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 461:

/* Line 1806 of yacc.c  */
#line 1236 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 462:

/* Line 1806 of yacc.c  */
#line 1238 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 463:

/* Line 1806 of yacc.c  */
#line 1240 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 464:

/* Line 1806 of yacc.c  */
#line 1242 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 465:

/* Line 1806 of yacc.c  */
#line 1244 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 466:

/* Line 1806 of yacc.c  */
#line 1246 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 467:

/* Line 1806 of yacc.c  */
#line 1248 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 468:

/* Line 1806 of yacc.c  */
#line 1250 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 469:

/* Line 1806 of yacc.c  */
#line 1252 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 470:

/* Line 1806 of yacc.c  */
#line 1254 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 471:

/* Line 1806 of yacc.c  */
#line 1256 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 472:

/* Line 1806 of yacc.c  */
#line 1258 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 473:

/* Line 1806 of yacc.c  */
#line 1260 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 474:

/* Line 1806 of yacc.c  */
#line 1262 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 475:

/* Line 1806 of yacc.c  */
#line 1264 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 476:

/* Line 1806 of yacc.c  */
#line 1266 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 1268 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 1270 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 1272 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 1274 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 1320 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 1322 "parser.ypp"
    {printf("Missing ( on line %d\n",yylineno);}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 1326 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 1328 "parser.ypp"
    {printf("Missing ( on line %d\n",yylineno);}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 1332 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 1336 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 1344 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 1348 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 1352 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 1356 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 1360 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 1364 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 1368 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 1372 "parser.ypp"
    {printf("Missing ) on line %d\n",yylineno);}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 1391 "parser.ypp"
    {printf("Missing ] on line %d\n",yylineno);}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 1393 "parser.ypp"
    {printf("Missing ] on line %d\n",yylineno);}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 1398 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Ordinary Name>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 1400 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<<Postfix>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 1408 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<<<<Unary Expression>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 1412 "parser.ypp"
    {printf("Error in unary expression at line %d\n",yylineno);}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 1420 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Multiplicative Expression>>>>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 1424 "parser.ypp"
    {printf("Error in expression at line %d\n",yylineno);}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 1427 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<+,- Expression>>>>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 1431 "parser.ypp"
    {printf("Error in expression at line %d\n",yylineno);}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 1434 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Shift Expression>>>>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 1438 "parser.ypp"
    {printf("Error in expression at line %d\n",yylineno);}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 1441 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Relational Expression>>>>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 1445 "parser.ypp"
    {printf("Error in expression at line %d\n",yylineno);}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 1448 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Comparison Expression>>>>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 1452 "parser.ypp"
    {printf("Error in expression at line %d\n",yylineno);}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 1455 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Bitwise AND Expression>>>>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 1459 "parser.ypp"
    {printf("Error in expression at line %d\n",yylineno);}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 1462 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<XOR Expression>>>>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 1466 "parser.ypp"
    {printf("Error in expression at line %d\n",yylineno);}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 1469 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<Bitwise OR Expression>>>>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 1473 "parser.ypp"
    {printf("Error in expression at line %d\n",yylineno);}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 1476 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<AND Expression>>>>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 1480 "parser.ypp"
    {printf("Error in expression at line %d\n",yylineno);}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 1483 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<OR Expression>>>>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 1487 "parser.ypp"
    {printf("Error in expression at line %d\n",yylineno);}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 1492 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<<<Ternary Expression>>>>>>>>>>>,line %d\n",yylineno);}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 1494 "parser.ypp"
    {printf("Error in ternary expression on line %d\n",yylineno);}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 1502 "parser.ypp"
    {if(DEBUG_MODE) printf("<<<<<<<<<<<<Assignment expression>>>>>>>,line %d\n",yylineno);}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 1504 "parser.ypp"
    {printf("Error in assignment expression on line %d\n",yylineno);}
    break;



/* Line 1806 of yacc.c  */
#line 4695 "parser.cpp"
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
#line 1590 "parser.ypp"

extern FILE *yyin;
main()
{
	do
	{
		yyparse();	
	}
	while(!feof(yyin));
	if(error_count)
		printf("%d errors found\n",error_count);
	else
		printf("Compiled successfully\n");
}


