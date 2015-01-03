%{
#include<stdio.h>
#include<string.h>
//#include "y.tab.h"

#define DEBUG_MODE 1
#define LEXEME_LENGTH 4096
#define TABLE_LENGTH 4096

#define KEYWORD	0
#define IDENT 1
#define LITERAL 2

char lexeme[LEXEME_LENGTH];
int line=1,col=1;
int lexeme_count=0,error_count=0;

struct table
{
	char *lexeme;
	int token;
	int line;
}symbol_table[TABLE_LENGTH],error_dump[TABLE_LENGTH];

int find(char *);
void insert(char *,int);
void insert_error(char *);

%}

SINGLE_LINE_COMMENT	"//".*
MULTI_LINE_COMMENT	"/*"([^*]|[\r\n]|([\*]+([^*/]|[\r\n])))*[\*]+"/"

DEC_DIGITS		[0-9]
HEX_DIGITS		[0-9a-fA-F]
INTEGERS		0|[1-9]([_]*{DEC_DIGITS})*[lL]?
HEX_NUMBERS		"0"[Xx]{HEX_DIGITS}([_]*{HEX_DIGITS})*[lL]?
OCTAL_NUMBERS		"0"([_]*[0-7])*[lL]?
BINARY_NUMBERS		"0"[bB][01]([_]*[01])*[lL]?
EXPONENTS		[eE][+\-]?{DEC_DIGITS}([_]*{DEC_DIGITS})*
HEX_EXPONENTS		[pP][+\-]?{DEC_DIGITS}([_]*{DEC_DIGITS})*

FLOATS			({DEC_DIGITS}([_]*{DEC_DIGITS})*((({EXPONENTS}?[dDFf])|({EXPONENTS}[dDFf]?))|([\.]({DEC_DIGITS}([_]*{DEC_DIGITS})*)?{EXPONENTS}?[dDfF]?)))|([\.]{DEC_DIGITS}([_]*{DEC_DIGITS})*{EXPONENTS}?[dDfF]?)

HEX_FLOATS		"0"[xX](({HEX_DIGITS}([_]*{HEX_DIGITS})*[\.]?({HEX_DIGITS}([_]*{HEX_DIGITS})*)?)|([\.]{HEX_DIGITS}([_]*{HEX_DIGITS})*)){HEX_EXPONENTS}[dDfF]?

IDENTIFIERS		[a-zA-Z_$][a-zA-Z0-9_$]*
HEX_CHARS		"\\"[u]+{HEX_DIGITS}{4,4}
OCTAL_CHARS		"\\"([0-7]{1,2}|([0-3][0-7]{1,2}))
ESCAPE			"\\'"|"\\\\"|"\\b"|"\\t"|"\\n"|"\\f"|"\\r"|"\\\""
CHARACTERS		"'"({HEX_CHARS}|{OCTAL_CHARS}|{ESCAPE}|[^'\n\\])"'"
STRINGS			"\""({ESCAPE}|{HEX_CHARS}|{OCTAL_CHARS}|[^\"\n\\])*"\""
CAST                    "("[ \t]*(int|byte|short|long|double|float)[ \t]*")"
BOOL			true|false
NULL			null			

WHITESPACE		"\t"|" "|"\f"
PRINTL			System.out.println
PRINT			System.out.print

%%

[\n\r] 			{	line++;col=1;if(DEBUG_MODE) printf("\n-----Lexical analyser on line %d------\n\n",line);
			}
{WHITESPACE}    		col+=strlen(yytext);

{SINGLE_LINE_COMMENT}   {	if(DEBUG_MODE)  printf("comment %s on line %d\n",yytext,line);col=1;
			}
{MULTI_LINE_COMMENT}    {	if(DEBUG_MODE) printf("multi line comment %s\n",yytext);
				strcpy(lexeme,yytext);
				int i;
                                for(i=0;i<strlen(lexeme);i++)
                                {
                                        if(lexeme[i]=='\n' || lexeme[i]=='\r') line++;
                                }col=1;
                        }
{PRINTL}		{	if(DEBUG_MODE)	printf("print statement %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return PRINTL;
			}
{PRINT}			{	if(DEBUG_MODE)	printf("print statement %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return PRINT;
			}
{STRINGS}		{	if(DEBUG_MODE)	printf("string %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return STRING;
			}
{CHARACTERS}		{	if(DEBUG_MODE)	printf("character %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return CHARACTERS;
			}
{CAST}			{	if(DEBUG_MODE)	printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return CAST;
			}
"abstract"		{	if(DEBUG_MODE)	printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return ABSTRACT;
			}
"assert"		{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return ASSERT;
			}
"boolean"		{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return BOOLEAN;
			}
"break"			{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return BREAK;
			}
"byte"			{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return BYTE;
			}
"case"			{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);	return CASE;
			}	
"catch"			{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return CATCH;
			}
"char"			{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return CHAR;
			}
"class"			{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return CLASS;
			}
"continue"		{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return CONTINUE;
			}
"default"		{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return DEFAULT;
			}
"do"			{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return DO;
			}
"double"		{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return DOUBLE;
			}
"else"			{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme))	insert(lexeme,KEYWORD);return ELSE;
			}
"enum"			{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return ENUM;
			}
"extends"               {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return EXTENDS;
                        }
"finally"               {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return FINALLY;
                        }
"final"                 {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return FINAL;
                        }
"float"                 {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return FLOAT;
                        }
"for"                   {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return FOR;
                        }
"if"                    {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return IF;
                        }
"implements"            {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return IMPLEMENTS;
                        }
"import"                {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return IMPORT;
                        }
"instanceof"            {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return INSTANCEOF;
                        }
"int"                   {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return INT;
                        }
"interface"             {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);	
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return INTERFACE;
                        }
"long"                  {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return LONG;
                        }
"native"                {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return NATIVE;
                        }
"new"                   {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return NEW;
                        }
"package"               {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return PACAKGE;
			}
"private"               {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return PRIVATE;
                        }
"protected"             {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
         			strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return PROTECTED;
                        }
"public"                {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return PUBLIC;
                        }
"return"                {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return RETURN;
                        }
"short"                 {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return SHORT;
                        }
"static"                {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return ENUM;
                        }
"strictfp"              {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return STRICTFP;
                        }
"super"                 {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return SUPER;
                        }
"switch"                {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return SWITCH;
                        }
"synchronized"          {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return SYNCHRONIZED;
                        }
"this"      		{	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return THIS;
                        }
"throws"                {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return THROWS;
                        }
"throw"                 {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return THROW;
                        }
"transient"             {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return TRANSIENT;
                        }
"try"                   {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return TRY;
                        }
"void"                  {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return VOID;
                        }
"volatile"              {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return VOLATILE;
                        }
"while"                 {	if(DEBUG_MODE)  printf("keyword %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return WHILE;
                        }
"goto"			{	if(DEBUG_MODE)  printf("reserved word %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return GOTO;
			}
"const"			{	if(DEBUG_MODE)  printf("reserved word %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
                                strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,KEYWORD);return CONST;
			}
{BOOL}			{	if(DEBUG_MODE)  printf("literal %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,LITERAL);return BOOL;
			}
{NULL}			{	if(DEBUG_MODE)  printf("literal %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme)) insert(lexeme,LITERAL);return  NULL;
			}
{IDENTIFIERS}		{	if(DEBUG_MODE)  printf("identifier %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				strcpy(lexeme,yytext);if(!find(lexeme))	insert(lexeme,IDENT);return IDENTIFIER;
			}
"("			{	if(DEBUG_MODE)  printf("separator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return LRBRACE}
")"			{	if(DEBUG_MODE)  printf("separator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return RRBRACE;
			}
"{"			{	if(DEBUG_MODE)  printf("separator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return LCBRACE;
			} 
"}"			{	if(DEBUG_MODE)  printf("separator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return RCBRACE;
			}
"["			{	if(DEBUG_MODE)  printf("separator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return LSBRACE;
			}
"]"			{	if(DEBUG_MODE)  printf("separator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return RSBRACE;
			}
","			{	if(DEBUG_MODE)  printf("separator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return COMMA;
			}
";"			{	if(DEBUG_MODE)  printf("separator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return SEMICOLON;
			}
"."			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return DOT;
			}
":"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return COLON;
			}
"?"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return TERNARY;
			}
"++"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return INCREMENT;
			}
"--"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return DECREMENT;
			}    
"~"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return UNOT;
			}
"!="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return NEQ;
			}
"!"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return NOT;
			}
"=="			{       if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return COMP;
			}
"="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return EQUAL;
			}
"*="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return MULTEQUAL;
			}
"/="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return DIVEQUAL;
			}
"+="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return PLUSEQUAL;
			}
"-="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return MINUSEQUAL;
			}
"%="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return MODEQUAL;
			}				
"*"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return MULT;
			}
"/"			{       if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return DIV;
			}
"%"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return MOD;
			}
"+"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return PLUS;
			}
"-"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return MINUS;
			}
"<<="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return LEFTSHIFTEQUAL;
			}
">>>="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return URIGHTSHIFTEQUAL;
			}
">>="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return RIGHTSHIFTEQUAL;
			}
"<<"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return LEFTSHIFT;
			}
">>>"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return URIGHTSHIFT;
			}
">>"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return RIGHTSHIFT;
			}
"<="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return LEQ;
			}
"<"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return LT;
			}
">="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return GEQ;
			}
">"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return GT;
			}
"&&"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return AND;
			}
"&="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return ANDEQUAL;
			}
"&"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return BAND;
			}
"|="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return OREQUAL;
			}
"||"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return OR;
			}
"|"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return BOR;
			}
"^="			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return XOREQUAL;
			}
"^"			{	if(DEBUG_MODE)  printf("operator %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return XOR;
			}
{HEX_NUMBERS}		{	if(DEBUG_MODE)  printf("hexadecimal number %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				return HEX_INT;
			}
{BINARY_NUMBERS}	{	if(DEBUG_MODE)  printf("binary number %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				return BIN_INT;
			}
{INTEGERS}		{	if(DEBUG_MODE)  printf("number %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return INTEGER;
			}
{OCTAL_NUMBERS}		{	if(DEBUG_MODE)  printf("octal number %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				return OCT_INT;
			}
{HEX_FLOATS}		{	if(DEBUG_MODE)  printf("hexadecimal float %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				return HEX_FLOAT;
			}
{FLOATS}		{	if(DEBUG_MODE)  printf("float %s on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);return FLOATING;
                        }
.			{	if(DEBUG_MODE)	printf("%s is erraneous on line %d,column %d\n",yytext,line,col);col+=strlen(yytext);
				insert_error(yytext);return ERROR;
			}
%%

int find(char *lexeme)
{
	int i,flag=0;
	for(i=0;i<lexeme_count;i++)
	{
		if(strcmp(symbol_table[i].lexeme,lexeme)==0)
			return 1;
	}
	return 0;
}

void insert(char *lexeme,int type)
{
	symbol_table[lexeme_count].lexeme=(char *)malloc(strlen(lexeme)+1);
	strcpy(symbol_table[lexeme_count].lexeme,lexeme);
	symbol_table[lexeme_count].token=type;
	symbol_table[lexeme_count++].line=line;
}

void insert_error(char *error)
{
	error_dump[error_count].lexeme=(char *)malloc(strlen(error)+1);
        strcpy(error_dump[error_count].lexeme,error);
        error_dump[error_count].token=-1;
        error_dump[error_count++].line=line;
}
int main()
{
	yylex();
	printf("\n-----Printing the contents of the symbol table-----\n\n");
	int i;
	for(i=0;i<lexeme_count;i++)
		printf("lexeme %s of type %d was found at line %d\n",symbol_table[i].lexeme,symbol_table[i].token,symbol_table[i].line);
	printf("\n-----Printing the contents of the error dump-------\n\n");
	for(i=0;i<error_count;i++)
		printf("Error %s was found at line %d\n",error_dump[i].lexeme,error_dump[i].line);	
	return 0;
}
