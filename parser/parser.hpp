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

extern YYSTYPE yylval;


