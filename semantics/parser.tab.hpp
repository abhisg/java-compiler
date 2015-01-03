/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
#line 158 "parser.ypp"

	struct attribute *attr;
	char str[1024];



/* Line 2068 of yacc.c  */
#line 180 "parser.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


