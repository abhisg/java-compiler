%{
#include<stdio.h>
#include<string.h>
extern int yylineno;
int error_count = 0;
#define DEBUG_MODE 0
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
%}
%error-verbose
%token ERROR
%token PRINTL
%token PRINT

%token STRING
%token CHARACTERS
%token BOOL
%token NULLER
%token IDENTIFIER
%token HEX_INT
%token BIN_INT
%token OCT_INT
%token INTEGER
%token FLOATING
%token HEX_FLOAT

%token ABSTRACT
%token ASSERT
%token BOOLEAN
%token BREAK
%token BYTE
%token CASE
%token CATCH
%token CHAR
%token CLASS
%token CONST
%token CONTINUE
%token DEFAULT
%token DO
%token DOUBLE
%token ELSE
%token ENUM
%token EXTENDS
%token FINAL
%token FINALLY
%token FLOAT
%token FOR
%token IF
%token GOTO
%token IMPLEMENTS
%token IMPORT
%token INSTANCEOF
%token INT
%token INTERFACE
%token LONG
%token NATIVE
%token NEW
%token PACKAGE
%token PRIVATE
%token PROTECTED
%token PUBLIC
%token RETURN
%token SHORT
%token STATIC
%token STRICTFP
%token SUPER
%token SWITCH
%token SYNCHRONIZED
%token THIS
%token THROW
%token THROWS
%token TRANSIENT
%token TRY
%token VOID
%token VOLATILE
%token WHILE

%token LRBRACE
%token RRBRACE
%token LCBRACE
%token RCBRACE
%token LSBRACE
%token RSBRACE
%token COMMA
%token SEMICOLON
%token DOT
%token COLON

%token TERNARY
%token INCREMENT
%token DECREMENT
%token UNOT
%token NEQ
%token NOT
%token COMPARE
%token EQUAL
%token MULTEQUAL
%token PLUSEQUAL
%token DIVEQUAL
%token MINUSEQUAL
%token MODEQUAL
%token DIV
%token MULT
%token MOD
%token PLUS
%token MINUS
%token LEFTSHIFTEQUAL
%token RIGHTSHIFTEQUAL
%token URIGHTSHIFTEQUAL
%token LEFTSHIFT
%token RIGHTSHIFT
%token URIGHTSHIFT
%token LEQ
%token LT
%token GT
%token GEQ
%token ANDEQUAL
%token BAND
%token OREQUAL
%token BOR
%token AND
%token OR
%token XOR
%token XOREQUAL
%token CAST


%right INCREMENT DECREMENT
%right PREINCREMENT PREDECREMENT UPLUS UMINUS NOT UNOT CAST
%left  MULT DIV MOD
%left  PLUS MINUS
%left  LEFTSHIFT RIGHTSHIFT URIGHTSHIFT
%left  LT LEQ GT GEQ INSTANCEOF
%left  COMPARE NEQ
%left  BAND
%left  XOR
%left  BOR
%left  AND
%left  OR
%right EQUAL PLUSEQUAL MINUSEQUAL MULTEQUAL DIVEQUAL MODEQUAL ANDEQUAL XOREQUAL OREQUAL LEFTSHIFTEQUAL RIGHTSHIFTEQUAL URIGHTSHIFTEQUAL 


%%

Goal:	CompilationUnit	
;

Identifier:
	IDENTIFIER
;

Literal:
	IntegerLiteral	
	|	
	FloatingPointLiteral
	|
	BOOL				
	|
	CHARACTERS			
	|
	STRING		
	|
	NULLER
	|
	ERROR			{printf("Erraneous literal at line %d\n",yylineno);}		
;

IntegerLiteral:
	INTEGER
	|
	HEX_INT
	|
	BIN_INT
	|
	OCT_INT
;

FloatingPointLiteral:
	HEX_FLOAT
	|
	FLOATING
;

Type:
	Primitive
	|
	Reference		
;
Primitive:
	Numeric
	|
	BOOLEAN
;
Numeric:
	Integral
	|
	FloatingPointType
;
Integral:
	BYTE
	|
	SHORT
	|
	INT
	|
	LONG
	|
	CHAR
;
FloatingPointType:
	FLOAT
	|
	DOUBLE
;
Reference:
	ClassOrInterfaceType
	|
	ArrayType
;

ClassOrInterfaceType:
	TypeName
	|
	TypeName TypeArguments
;
TypeName:
	SimpleName
	|
	TypeName DOT SimpleName
	|
	TypeName DOT error SEMICOLON  {printf("erraneous name used on line %d\n",yylineno);}	
;
SimpleName:		
	Identifier	
;
ArrayType:
	Type LSBRACE RSBRACE
	|
	Type LSBRACE error SEMICOLON {printf("error!!missing ] on %d\n",yylineno);}
;

TypeArguments:
	LT TypeArgumentList GT
;

TypeArgumentList:
	TypeArgument
	|
	TypeArgumentList COMMA TypeArgument
;

TypeArgument:
	Reference
	|
	WildCard
;

WildCard:
	TERNARY 
	|
	TERNARY Bounds
;

Bounds:
	EXTENDS Reference
	|
	SUPER Reference
;





CompilationUnit:
	PackageDeclaration ImportDeclarations TypeDeclarations {if(DEBUG_MODE) printf("<<<<<<<<Pacakge,import and class/interface present>>>>>>>>>>\n");}
	|
	PackageDeclaration TypeDeclarations			{if(DEBUG_MODE) printf("<<<<<<<<<<<Package and Class/Interface>>>>>>>>>\n");}
	|
	ImportDeclarations TypeDeclarations			{if(DEBUG_MODE) printf("<<<<<<<<<<<<<<<<<<<Import and Class/Interface>>>>>>>>>>>>>\n");}
	|
	TypeDeclarations					{if(DEBUG_MODE) printf("<<<<<<<<Only class/interface>>>>>>>>>>>>\n");}
	|
;

PackageDeclaration:
	PACKAGE TypeName SEMICOLON
	|
	PACKAGE error SEMICOLON					
;

ImportDeclarations:
	ImportDeclaration					{if(DEBUG_MODE) printf("<<<<<<<<<Single Import Statement>>>>>>>>>>>\n");}
	|
	ImportDeclarations ImportDeclaration			{if(DEBUG_MODE) printf("<<<<<<<<Multiple Import Statements>>>>>>>>>\n");}
;

ImportDeclaration:
	IMPORT TypeName SEMICOLON
	|
	IMPORT TypeName DOT MULT SEMICOLON	       
	|
	IMPORT STATIC TypeName DOT Identifier SEMICOLON
	|
	IMPORT STATIC TypeName DOT MULT SEMICOLON
	|
	IMPORT error SEMICOLON					
;

TypeDeclarations:
	TypeDeclaration						{if(DEBUG_MODE) printf("<<<<<<<<<Single  Class/Interface Declaration>>>>>>>>>>>\n");}
	|
	TypeDeclarations TypeDeclaration			{if(DEBUG_MODE) printf("<<<<<<<<Multiple Class/Interface Declarations>>>>>>>>>\n");}
;	

TypeDeclaration:
	ClassDeclaration					
	|
	InterfaceDeclaration
;

ClassDeclaration:
	NormalClassDeclaration		{if(DEBUG_MODE) printf("<<<<<<<<<<<Normal Class Declaration>>>>>>>>>>>>>>>>>>>>>>>\n");}
	|
	EnumDeclaration			{if(DEBUG_MODE) printf("<<<<<<<<<<<Enum Declaration>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");}
;

NormalClassDeclaration:
	Modifiers CLASS Identifier TypeParameters EXTENDS ClassOrInterfaceType Interfaces ClassBody
	|
	CLASS Identifier TypeParameters EXTENDS ClassOrInterfaceType Interfaces ClassBody
	|
	Modifiers CLASS Identifier EXTENDS ClassOrInterfaceType Interfaces ClassBody
	|
	Modifiers CLASS Identifier TypeParameters Interfaces ClassBody
	|
	Modifiers CLASS Identifier TypeParameters EXTENDS ClassOrInterfaceType ClassBody
	|
	CLASS Identifier EXTENDS ClassOrInterfaceType Interfaces ClassBody
	|
	CLASS Identifier TypeParameters Interfaces ClassBody
	|
	CLASS Identifier TypeParameters EXTENDS ClassOrInterfaceType ClassBody
	|
	Modifiers CLASS Identifier Interfaces ClassBody
	|
	Modifiers CLASS Identifier EXTENDS ClassOrInterfaceType ClassBody
	|
	Modifiers CLASS Identifier TypeParameters ClassBody
	|
	CLASS Identifier Interfaces ClassBody
	|
	CLASS Identifier TypeParameters ClassBody
	|
	CLASS Identifier EXTENDS ClassOrInterfaceType ClassBody
	|
	Modifiers CLASS Identifier ClassBody                    
	|
	CLASS Identifier ClassBody
	|
	Modifiers CLASS error ClassBody
	|
	CLASS error ClassBody
;

Modifiers:
	Modifiers Modifier
	|
	Modifier
;
Modifier:			
	PUBLIC
	|
	PRIVATE
	|
	PROTECTED
	|
	ABSTRACT
	|
	STATIC
	|
	FINAL
	|
	NATIVE
	|
	SYNCHRONIZED
	|
	TRANSIENT
	|
	VOLATILE
	|
	STRICTFP
;

TypeParameters:
	LT TypeParameterList GT
	|
	LT error GT
;

TypeParameterList:
	TypeParameterList COMMA TypeParameter
	|
	TypeParameter
;

TypeParameter:
	Identifier TypeBound
	|
	Identifier
;

TypeBound:
	EXTENDS ClassOrInterfaceType
;

Interfaces:
	IMPLEMENTS InterfaceTypeList
;

InterfaceTypeList:
	ClassOrInterfaceType
	|
	InterfaceTypeList COMMA ClassOrInterfaceType
;

ClassBody:
	LCBRACE RCBRACE
	|
	LCBRACE ClassBodyDeclarations RCBRACE				{if(DEBUG_MODE)	printf("<<<<<<<Class Declarations>>>>>>\n");}
;

ClassBodyDeclarations:
	ClassBodyDeclaration
	|
	ClassBodyDeclarations ClassBodyDeclaration
;

ClassBodyDeclaration:
	ClassMemberDeclaration			
	|
	Block
	|
	STATIC Block				{if(DEBUG_MODE) printf("<<<<<Static Block inside class>>>>>>>\n");}
	|
	ConstructorDeclaration			{if(DEBUG_MODE)	printf("<<<<Constuctor Declaration inside class>>>>>\n");}
;

ClassMemberDeclaration:
	FieldDeclaration				{if(DEBUG_MODE) printf("<<<<<<Field Declaration>>>>>>>>>>>\n");}
	|
	MethodDeclaration				{if(DEBUG_MODE) printf("<<<<<<Method Declaration>>>>>>>>>>>\n");}
	|
	ClassDeclaration				{if(DEBUG_MODE) printf("<<<<<<Class Declaration within Class>>>>>>>>>>>\n");}
	|
	InterfaceDeclaration				{if(DEBUG_MODE) printf("<<<<<<Interface Declaration within Class>>>>>>>>>>>\n");}
	|
	SEMICOLON
;

FieldDeclaration:
	Modifiers Type VariableDeclarators SEMICOLON
	|
	Type VariableDeclarators SEMICOLON
	|
	Modifiers error SEMICOLON			{printf("Error!!!missing identifiers at line %d\n",yylineno);}
	|
	Type error SEMICOLON				{printf("Error!!!missing identifiers at line %d\n",yylineno);}
;

VariableDeclarators:
	VariableDeclarator
	|
	VariableDeclarators COMMA VariableDeclarator
;

VariableDeclarator:
	VariableDeclaratorID
	|
	VariableDeclaratorID EQUAL VariableInitialiser
	|
	VariableDeclaratorID EQUAL error SEMICOLON	{printf("Error!!!missing expression after = at line %d\n",yylineno);}
;

VariableDeclaratorID:
	Identifier
	|
	VariableDeclaratorID LSBRACE RSBRACE
	|
	VariableDeclaratorID LSBRACE error SEMICOLON	{printf("Error!!!missing ] at line %d\n",yylineno);}
;

VariableInitialiser:
	Expression
	|
	ArrayInitialiser
;

ArrayInitialiser:
	LCBRACE RCBRACE
	|
	LCBRACE VariableInitialisers COMMA RCBRACE
	|
	LCBRACE COMMA RCBRACE
	|
	LCBRACE VariableInitialisers RCBRACE
	|
	LCBRACE error RCBRACE
	|
	LCBRACE VariableInitialisers error SEMICOLON	{printf("Missing } on line %d\n",yylineno);}
;
VariableInitialisers:
	VariableInitialiser
	|
	VariableInitialisers COMMA VariableInitialiser
;

MethodDeclaration:
	MethodHeader MethodBody
;
MethodHeader:
	Modifiers TypeParameters VOID MethodDeclarator Throws
	|
	TypeParameters VOID MethodDeclarator Throws
	|
	Modifiers VOID MethodDeclarator Throws
	|
	Modifiers TypeParameters VOID MethodDeclarator
	|
	VOID MethodDeclarator Throws
	|
	Modifiers VOID MethodDeclarator
	|
	TypeParameters VOID MethodDeclarator
	|
	VOID MethodDeclarator
	|
	Modifiers TypeParameters Type MethodDeclarator Throws
	|
	TypeParameters Type MethodDeclarator Throws
	|
	Modifiers Type MethodDeclarator Throws
	|
	Modifiers TypeParameters Type MethodDeclarator
	|
	Type MethodDeclarator Throws
	|
	Modifiers Type MethodDeclarator
	|
	TypeParameters Type MethodDeclarator
	|
	Type MethodDeclarator
;
MethodDeclarator:
	Identifier LRBRACE FormalParameterList RRBRACE
	|
	Identifier LRBRACE RRBRACE
	|
	Identifier LRBRACE FormalParameterList error SEMICOLON 	{printf("Missing ) on line %d\n",yylineno);}
;
FormalParameterList:
	LastFormalParameter
	|
	FormalParameters COMMA LastFormalParameter
;

FormalParameters:
	FormalParameter
	|
	FormalParameters COMMA FormalParameter
	|
	FormalParameters COMMA error
;

FormalParameter:
	FINAL Type VariableDeclaratorID
	|
	Type VariableDeclaratorID
;

LastFormalParameter:
	FINAL Type DOT DOT DOT VariableDeclaratorID
	|
	Type DOT DOT DOT VariableDeclaratorID
	|
	FormalParameter
;
Throws:
	THROWS ExceptionTypeList
;
ExceptionTypeList:
	TypeName
	|
	ExceptionTypeList COMMA TypeName
;
MethodBody:
	Block
	|
	SEMICOLON
;
ConstructorDeclaration:
	Modifiers ConstructorDeclarator Throws ConstructorBody
	|
	ConstructorDeclarator Throws ConstructorBody
	|
	Modifiers ConstructorDeclarator ConstructorBody
	|
	ConstructorDeclarator ConstructorBody
;
ConstructorDeclarator:
	TypeParameters SimpleName LRBRACE FormalParameterList RRBRACE
	|
	SimpleName LRBRACE FormalParameterList RRBRACE
	|
	TypeParameters SimpleName LRBRACE RRBRACE
	|
	SimpleName LRBRACE RRBRACE
	|
	TypeParameters SimpleName LRBRACE error SEMICOLON	{printf("Missing ) on line %d\n",yylineno);}
	|
	SimpleName LRBRACE error SEMICOLON			{printf("Missing ) on line %d\n",yylineno);}
;
ConstructorBody:
	LCBRACE ExplicitConstructorInvocation BlockStatements RCBRACE
	|
	Block
	|
	LCBRACE ExplicitConstructorInvocation RCBRACE
;
ExplicitConstructorInvocation:
	NonWildTypeArguments THIS LRBRACE ArgumentList RRBRACE SEMICOLON
	|
	THIS LRBRACE ArgumentList RRBRACE SEMICOLON
	|
	NonWildTypeArguments THIS LRBRACE RRBRACE SEMICOLON
	|
	THIS LRBRACE RRBRACE SEMICOLON
	|
	NonWildTypeArguments SUPER LRBRACE ArgumentList RRBRACE SEMICOLON
	|
	SUPER LRBRACE ArgumentList RRBRACE SEMICOLON
	|
	NonWildTypeArguments SUPER LRBRACE RRBRACE SEMICOLON
	|
	SUPER LRBRACE RRBRACE SEMICOLON
	|
	Primary DOT NonWildTypeArguments SUPER LRBRACE ArgumentList RRBRACE SEMICOLON
	|
	Primary DOT SUPER LRBRACE ArgumentList RRBRACE SEMICOLON
	|
	Primary DOT NonWildTypeArguments SUPER LRBRACE RRBRACE SEMICOLON
	|
	Primary DOT SUPER LRBRACE RRBRACE SEMICOLON
	|
	NonWildTypeArguments THIS LRBRACE ArgumentList error SEMICOLON	
        |
        THIS LRBRACE ArgumentList error SEMICOLON
        |
        NonWildTypeArguments THIS LRBRACE error SEMICOLON
        |
        THIS LRBRACE error SEMICOLON
        |
        NonWildTypeArguments SUPER LRBRACE ArgumentList error SEMICOLON
        |
        SUPER LRBRACE ArgumentList error SEMICOLON
        |
        NonWildTypeArguments SUPER LRBRACE error SEMICOLON
        |
        SUPER LRBRACE error SEMICOLON
        |
        Primary DOT NonWildTypeArguments SUPER LRBRACE ArgumentList error SEMICOLON
        |
        Primary DOT SUPER LRBRACE ArgumentList error SEMICOLON
        |
        Primary DOT NonWildTypeArguments SUPER LRBRACE error SEMICOLON
        |
        Primary DOT SUPER LRBRACE error SEMICOLON

;
NonWildTypeArguments:
	LT ReferenceList GT
	|
	LT error GT
	|
	LT ReferenceList error		{printf("Missing > on line %d\n",yylineno);}
;
ReferenceList:
	Reference
	|
	ReferenceList COMMA Reference
;
EnumDeclaration:
	Modifiers ENUM Identifier Interfaces EnumBody
	|
	ENUM Identifier Interfaces EnumBody
	|
	Modifiers ENUM Identifier EnumBody
	|
	ENUM Identifier EnumBody
	|
	ENUM error EnumBody
	|
	Modifiers ENUM error EnumBody
;
EnumBody:
	LCBRACE EnumConstants COMMA EnumBodyDeclarations RCBRACE
	|
	LCBRACE EnumConstants EnumBodyDeclarations RCBRACE
	|
	LCBRACE COMMA EnumBodyDeclarations RCBRACE
	|
	LCBRACE EnumConstants COMMA RCBRACE
	|
	LCBRACE EnumBodyDeclarations RCBRACE
	|
	LCBRACE EnumConstants RCBRACE
	|
	LCBRACE COMMA RCBRACE
	|
	LCBRACE RCBRACE
	|
	LCBRACE EnumConstants COMMA EnumBodyDeclarations error SEMICOLON
        |
        LCBRACE EnumConstants EnumBodyDeclarations error SEMICOLON
        |
        LCBRACE COMMA EnumBodyDeclarations error SEMICOLON
        |
        LCBRACE EnumConstants COMMA error SEMICOLON
        |
        LCBRACE EnumBodyDeclarations error SEMICOLON
        |
        LCBRACE EnumConstants error SEMICOLON
        |
        LCBRACE COMMA error SEMICOLON
        |
        LCBRACE error SEMICOLON
;
EnumConstants:
	EnumConstant
	|
	EnumConstants COMMA EnumConstant
;
EnumConstant:
	Identifier Arguments ClassBody
	|
	Identifier ClassBody
	|
	Identifier Arguments
	|
	Identifier
;
EnumBodyDeclarations:
	SEMICOLON ClassBodyDeclarations
	|
	SEMICOLON
;
Arguments:
	LRBRACE ArgumentList RRBRACE
	|
	LRBRACE RRBRACE
;
InterfaceDeclaration:
	Modifiers INTERFACE Identifier TypeParameters EXTENDS InterfaceTypeList InterfaceBody
	|
	INTERFACE Identifier TypeParameters EXTENDS InterfaceTypeList InterfaceBody
	|
	Modifiers INTERFACE Identifier EXTENDS InterfaceTypeList InterfaceBody
	|
	Modifiers INTERFACE Identifier TypeParameters InterfaceBody
	|
	INTERFACE Identifier EXTENDS InterfaceTypeList InterfaceBody
	|
	INTERFACE Identifier TypeParameters InterfaceBody
	|
	Modifiers INTERFACE Identifier InterfaceBody
	|
	INTERFACE Identifier InterfaceBody
	|
	Modifiers INTERFACE error InterfaceBody
	|
	INTERFACE error InterfaceBody
;
InterfaceBody:
	LCBRACE InterfaceMemberDeclarations RCBRACE
	|
	LCBRACE RCBRACE  
;
InterfaceMemberDeclarations:
	InterfaceMemberDeclaration
	|
	InterfaceMemberDeclarations InterfaceMemberDeclaration
;
InterfaceMemberDeclaration:
	FieldDeclaration				{if(DEBUG_MODE) printf("<<<<<<<<<<Interface Field Declaration>>>>>>>\n");}
	|
	AbstractMethodDeclaration			{if(DEBUG_MODE) printf("<<<<<<<<<<Abstract Declaration>>>>>>>\n");}
	|
	ClassDeclaration   				{if(DEBUG_MODE) printf("<<<<<<<<<<Interface Class Declaration>>>>>>>\n");}
	|
	InterfaceDeclaration				{if(DEBUG_MODE) printf("<<<<<<<<<<Interface Interface Declaration>>>>>>>\n");}
	|	
	SEMICOLON
;
AbstractMethodDeclaration:
	Modifiers TypeParameters Type MethodDeclarator Throws
	|
	TypeParameters Type MethodDeclarator Throws
	|
	Modifiers Type MethodDeclarator Throws
	|
	Modifiers TypeParameters Type MethodDeclarator
	|
	Type MethodDeclarator Throws
	|
	Modifiers Type MethodDeclarator
	|
	TypeParameters Type MethodDeclarator
	|
	Type MethodDeclarator
	|
	Modifiers TypeParameters VOID MethodDeclarator Throws
	|
	TypeParameters VOID MethodDeclarator Throws
	|
	Modifiers VOID MethodDeclarator Throws
	|
	Modifiers TypeParameters VOID MethodDeclarator
	|
	VOID MethodDeclarator Throws
	|
	Modifiers VOID MethodDeclarator
	|
	TypeParameters VOID MethodDeclarator
	|
	VOID MethodDeclarator
;

Block:
	LCBRACE RCBRACE
	|
        LCBRACE BlockStatements RCBRACE
;

BlockStatements:
      BlockStatement
      |
      BlockStatements BlockStatement
;

BlockStatement:

        FieldDeclaration
        |
        ClassDeclaration
	|
	Statement
;
Statement:
	Block
	|
	SEMICOLON
	|
	Expression SEMICOLON						{if(DEBUG_MODE) printf("<<<<<<Ordinary Statement>>>>>>>>>\n");}
	|
	Identifier COLON Statement					{if(DEBUG_MODE)	printf("<<<<Labeled Statement>>>>>\n");}
	|
	IF LRBRACE Expression RRBRACE Statement				{if(DEBUG_MODE) printf("<<<<<SINGLE IF>>>>>>>>\n");}
	|
	IF LRBRACE Expression RRBRACE Statement ELSE Statement		{if(DEBUG_MODE) printf("<<<<<<IF ELSE>>>>>>>>>\n");}
	|
	IF error SEMICOLON						{printf("Missing ( on line %d\n",yylineno);}
	|
	IF LRBRACE Expression error Statement				{printf("Missing ) on linr %d\n",yylineno);}
	|
	ASSERT Expression SEMICOLON					 {if(DEBUG_MODE) printf("<<<<<<Assert Statement>>>>>>>>>\n");}
	|
	ASSERT Expression COLON Expression SEMICOLON			 {if(DEBUG_MODE) printf("<<<<<<Labeled Assert Statement>>>>>>>>>\n");}
	|
	ASSERT Expression error SEMICOLON				{printf("Error in assertion at line %d\n",yylineno);}
	|
	SWITCH LRBRACE Expression RRBRACE LCBRACE SwitchBlockStatementGroups RCBRACE	 {if(DEBUG_MODE) printf("<<<<<<Switch Statement>>>>>>>>>\n");}
	|
	SWITCH error SEMICOLON						{printf("Missing ( on line %d\n",yylineno);}
	|
	SWITCH LRBRACE Expression error SEMICOLON			{printf("Missing ) on line %d\n",yylineno);}
	|
	SWITCH LRBRACE Expression RRBRACE error SEMICOLON		{printf("Missing { on line %d\n",yylineno);}
	|
	SWITCH LRBRACE Expression RRBRACE LCBRACE SwitchBlockStatementGroups error SEMICOLON	{printf("Missing } on line %d\n",yylineno);}
	|
	WHILE LRBRACE Expression RRBRACE Statement			 {if(DEBUG_MODE) printf("<<<<<<While Statement>>>>>>>>>\n");}
	|
	WHILE error SEMICOLON						{printf("Missing ( on line %d\n",yylineno);}
	|
	WHILE LRBRACE Expression error SEMICOLON			{printf("Missing ) on line %d\n",yylineno);}
	|
	DO Statement WHILE LRBRACE Expression RRBRACE SEMICOLON		 {if(DEBUG_MODE) printf("<<<<<<Do While Statement>>>>>>>>>\n");}
	|
	DO Statement WHILE error SEMICOLON				{printf("Missing ( on line %d\n",yylineno);}
	|
	DO Statement WHILE LRBRACE Expression error SEMICOLON		{printf("Missing ) on line %d\n",yylineno);}
	|
	FOR LRBRACE ForControl RRBRACE Statement			 {if(DEBUG_MODE) printf("<<<<<<For Statement>>>>>>>>>\n");}
	|
	FOR error SEMICOLON						{printf("Missing ( on line %d\n",yylineno);}
	|
	FOR LRBRACE ForControl error Statement				{printf("Missing ) on line %d\n",yylineno);}
	|
	BREAK Identifier SEMICOLON
	|
	BREAK Identifier error SEMICOLON				{printf("Missing ; on line %d\n",yylineno);}
	|
	BREAK SEMICOLON
	|
	BREAK error SEMICOLON						{printf("Missing ; on line %d\n",yylineno);}
	|
	CONTINUE Identifier SEMICOLON
	|
	CONTINUE Identifier error SEMICOLON				{printf("Missing ; on line %d\n",yylineno);}
	|
	CONTINUE SEMICOLON
	|
	CONTINUE error SEMICOLON					{printf("Missing ; on line %d\n",yylineno);}
	|
	RETURN Expression SEMICOLON
	|
	RETURN SEMICOLON
	|
	RETURN error RCBRACE						{printf("Missing ; on line %d\n",yylineno);}
	|
	THROW Expression SEMICOLON
	|
	THROW Expression error SEMICOLON				{printf("Missing ; on line %d\n",yylineno);}
	|
	SYNCHRONIZED LRBRACE Expression RRBRACE Block
	|
	TRY Block Catches
	|
	TRY Block Finally 
	|
	TRY Block Catches Finally
	|
	TRY ResourceSpecification Block Catches Finally
	|
	TRY ResourceSpecification Block Catches
	|
	TRY ResourceSpecification Block Finally
	|
	TRY ResourceSpecification
;
Catches:
	CatchClause
	|
	Catches CatchClause
;
CatchClause:
	CATCH LRBRACE FINAL CatchType RRBRACE Block
	|
	CATCH LRBRACE CatchType RRBRACE Block
	|
	CATCH LRBRACE FINAL CatchType error Block
	|
	CATCH LRBRACE CatchType error Block
;
CatchType:
	ClassOrInterfaceType
	|
	ClassOrInterfaceType CatchType
;
Finally:
	FINALLY Block
;
ResourceSpecification:

        LRBRACE Resources RRBRACE
        |
        LRBRACE Resources SEMICOLON RRBRACE
	|
	LRBRACE Resources error SEMICOLON
;

Resources:

        Resource
        |
        Resources SEMICOLON Resource
;

Resource:

        Reference VariableDeclaratorID EQUAL Expression
        |
        FINAL Reference VariableDeclaratorID EQUAL Expression
;


SwitchBlockStatementGroups:

        SwitchBlockStatementGroup
        |
        SwitchBlockStatementGroups SwitchBlockStatementGroup
;

SwitchBlockStatementGroup:

        SwitchLabels BlockStatements
;

SwitchLabels:

        SwitchLabel
        |
        SwitchLabels SwitchLabel
;

SwitchLabel:

        CASE Expression COLON
	|
        DEFAULT COLON
	|
	CASE Expression error SEMICOLON	{printf("Missing : on line %d\n",yylineno);}
;
ForControl:
	ForVarControl
	|
	ForInit SEMICOLON SEMICOLON
	|
	ForInit SEMICOLON Expression SEMICOLON
	|
	ForInit SEMICOLON Expression error SEMICOLON {printf("Missing ; on line %d\n",yylineno);}
	|
	ForInit SEMICOLON Expression SEMICOLON ForUpdate
	|
	ForInit SEMICOLON SEMICOLON ForUpdate
;
ForVarControl:
	Modifiers Type VariableDeclaratorID ForVarControlRest
	|
	Type VariableDeclaratorID ForVarControlRest
	|
	Type VariableDeclaratorID error
;
ForVarControlRest:
	ForVariableDeclaratorsRest SEMICOLON Expression SEMICOLON ForUpdate
	|
	ForVariableDeclaratorsRest SEMICOLON Expression SEMICOLON 
	|
	ForVariableDeclaratorsRest SEMICOLON SEMICOLON ForUpdate
	|
	ForVariableDeclaratorsRest SEMICOLON SEMICOLON
	|
	COLON Expression
;
ForVariableDeclaratorsRest:
	EQUAL VariableInitialiser VariableDeclarators
	|
	EQUAL VariableInitialiser
	|
	VariableDeclarators
	|
;
ForInit:
	StatementExpressionList
;

ForUpdate:

        StatementExpressionList
;

StatementExpressionList:

        Expression
        |
        StatementExpressionList COMMA Expression
;
Primary:
	PrimaryNoNewArray
	|
	ArrayCreationExpression
;
PrimaryNoNewArray:
	Literal
	|
	THIS
	|
	LRBRACE Expression RRBRACE
	|
	ClassInstanceCreationExpression
	|
	FieldAccess
	|
	MethodInvocation
	|
	ArrayAccess
;
ClassInstanceCreationExpression:
	NEW TypeArguments TypeName TypeArgumentsOrDiamond LRBRACE ArgumentList RRBRACE ClassBody
	|
	NEW TypeName TypeArgumentsOrDiamond LRBRACE ArgumentList RRBRACE ClassBody
	|
	NEW TypeArguments TypeName  LRBRACE ArgumentList RRBRACE ClassBody
	|
	NEW TypeArguments TypeName TypeArgumentsOrDiamond LRBRACE  RRBRACE ClassBody
	|
	NEW TypeArguments TypeName TypeArgumentsOrDiamond LRBRACE ArgumentList RRBRACE 
	|
	NEW TypeName  LRBRACE ArgumentList RRBRACE ClassBody
	|
	NEW TypeName TypeArgumentsOrDiamond LRBRACE  RRBRACE ClassBody
	|
	NEW TypeName TypeArgumentsOrDiamond LRBRACE ArgumentList RRBRACE 
	|
	NEW TypeArguments TypeName  LRBRACE  RRBRACE ClassBody
	|
	NEW TypeArguments TypeName LRBRACE ArgumentList RRBRACE
	|
	NEW TypeArguments TypeName TypeArgumentsOrDiamond LRBRACE  RRBRACE 
	|
	NEW TypeArguments TypeName LRBRACE RRBRACE
	|
	NEW TypeName TypeArgumentsOrDiamond LRBRACE RRBRACE
	|
	NEW TypeName LRBRACE ArgumentList RRBRACE
	|
	NEW TypeName LRBRACE RRBRACE ClassBody
	|
	NEW  TypeName LRBRACE  RRBRACE 
	|
	NEW TypeArguments TypeName TypeArgumentsOrDiamond LRBRACE ArgumentList error ClassBody	{printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeName TypeArgumentsOrDiamond LRBRACE ArgumentList error ClassBody    {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeArguments TypeName  LRBRACE ArgumentList error ClassBody            {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeArguments TypeName TypeArgumentsOrDiamond LRBRACE error ClassBody   {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeArguments TypeName TypeArgumentsOrDiamond LRBRACE ArgumentList error SEMICOLON {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeName  LRBRACE ArgumentList error ClassBody {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeName TypeArgumentsOrDiamond LRBRACE error ClassBody {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeName TypeArgumentsOrDiamond LRBRACE ArgumentList error SEMICOLON {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeArguments TypeName  LRBRACE  error ClassBody   {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeArguments TypeName LRBRACE ArgumentList error SEMICOLON {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeArguments TypeName TypeArgumentsOrDiamond LRBRACE error SEMICOLON {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeArguments TypeName LRBRACE error SEMICOLON {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeName TypeArgumentsOrDiamond LRBRACE error SEMICOLON {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeName LRBRACE ArgumentList error SEMICOLON {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW TypeName LRBRACE error ClassBody {printf("Missing ) on line %d\n",yylineno);}
        |
        NEW  TypeName LRBRACE  error SEMICOLON {printf("Missing ) on line %d\n",yylineno);}
;
TypeArgumentsOrDiamond:
	TypeArguments
	|
	LT GT
;
ArgumentList:
	Expression
	|
	ArgumentList COMMA Expression
;
ArrayCreationExpression:
	NEW Primitive DimExprs Dims
	|
	NEW Primitive DimExprs
	|
	NEW ClassOrInterfaceType DimExprs Dims
	|
	NEW ClassOrInterfaceType DimExprs
	|
	NEW Primitive Dims ArrayInitialiser
	|
	NEW ClassOrInterfaceType Dims ArrayInitialiser
;
DimExprs:
	DimExpr
	|
	DimExprs DimExpr
;
DimExpr:
	LSBRACE Expression RSBRACE
;
Dims:
	LSBRACE RSBRACE
	|
	Dims LSBRACE RSBRACE
;
FieldAccess:
	Primary DOT Identifier
	|
	SUPER DOT Identifier
;
MethodInvocation:
	PRINTL LRBRACE Expression RRBRACE
	|
	PRINTL LRBRACE Expression error SEMICOLON	{printf("Missing ) on line %d\n",yylineno);}
	|
	PRINT LRBRACE Expression RRBRACE
	|
	PRINT LRBRACE Expression error SEMICOLON	{printf("Missing ) on line %d\n",yylineno);}
	|
	PRINT LRBRACE RRBRACE
	|
	PRINT LRBRACE error SEMICOLON			{printf("Missing ) on line %d\n",yylineno);}
	|
	PRINTL LRBRACE RRBRACE
	|
	PRINTL LRBRACE error SEMICOLON			{printf("Missing ) on line %d\n",yylineno);}
	|
	TypeName LRBRACE ArgumentList RRBRACE
	|
	TypeName LRBRACE RRBRACE
	|
	Primary DOT NonWildTypeArguments Identifier LRBRACE ArgumentList RRBRACE
	|
	Primary DOT NonWildTypeArguments Identifier LRBRACE ArgumentList error SEMICOLON {printf("Missing ) on line %d\n",yylineno);}
	|
	Primary DOT  Identifier LRBRACE ArgumentList RRBRACE
	|
	Primary DOT Identifier LRBRACE ArgumentList error SEMICOLON   {printf("Missing ) on line %d\n",yylineno);}
	|
	Primary DOT NonWildTypeArguments Identifier LRBRACE RRBRACE
	|
	Primary DOT NonWildTypeArguments Identifier LRBRACE error SEMICOLON	{printf("Missing ) on line %d\n",yylineno);}
	|
	Primary DOT Identifier LRBRACE RRBRACE
	|
	Primary DOT Identifier LRBRACE error SEMICOLON		{printf("Missing ) on line %d\n",yylineno);}
	|
	SUPER DOT  NonWildTypeArguments Identifier LRBRACE ArgumentList RRBRACE
	|
	SUPER DOT NonWildTypeArguments Identifier LRBRACE ArgumentList error SEMICOLON	{printf("Missing ) on line %d\n",yylineno);}
	|
	SUPER DOT NonWildTypeArguments Identifier LRBRACE RRBRACE
	|
	SUPER DOT NonWildTypeArguments Identifier LRBRACE error SEMICOLON	{printf("Missing ) on line %d\n",yylineno);}
	|
	SUPER DOT Identifier LRBRACE ArgumentList RRBRACE
	|
	SUPER DOT Identifier LRBRACE ArgumentList error SEMICOLON		{printf("Missing ) on line %d\n",yylineno);}
	|
	SUPER DOT Identifier LRBRACE RRBRACE
	|
	SUPER DOT Identifier LRBRACE error SEMICOLON			{printf("Missing ) on line %d\n",yylineno);}
	|
	TypeName DOT SUPER DOT  IDENTIFIER LRBRACE ArgumentList RRBRACE
	|
	TypeName DOT SUPER DOT NonWildTypeArguments IDENTIFIER LRBRACE RRBRACE
	|
	TypeName DOT SUPER DOT IDENTIFIER LRBRACE RRBRACE
	|
	TypeName DOT SUPER DOT NonWildTypeArguments IDENTIFIER LRBRACE ArgumentList RRBRACE
	|
	TypeName DOT NonWildTypeArguments Identifier LRBRACE ArgumentList RRBRACE
	|
	TypeName DOT NonWildTypeArguments Identifier LRBRACE RRBRACE
;
ArrayAccess:
	TypeName LSBRACE Expression RSBRACE
	|
	PrimaryNoNewArray LSBRACE Expression RSBRACE
	|
	PrimaryNoNewArray LSBRACE Expression error SEMICOLON	{printf("Error!!!Missing ] on line %d\n",yylineno);}
	|
	TypeName LSBRACE Expression error SEMICOLON		{printf("Error!!!Missing ] on line %d\n",yylineno);}
;
OpExpression:
	Primary				{if(DEBUG_MODE) printf("<<<<<<<<<<<Primary Expression>>>>>>>>>\n");}
	|
	TypeName			{if(DEBUG_MODE) printf("<<<<<<<<<<Ordinary Name>>>>>>>>>\n");}
	|
	PostFixOp			{if(DEBUG_MODE) printf("<<<<<<<<<<<Postfix>>>>>>>>>>>\n");}
;
PostFixOp:
	OpExpression UnaryRtoL
;
UnaryExpression:
	OpExpression			
	|
	UnaryLtoR UnaryExpression	{if(DEBUG_MODE) printf("<<<<<<<<<<<<<Unary Expression>>>>>>>>>>>\n");}
	|
	UnaryLtoR error SEMICOLON	{printf("Error in unary expression at line %d\n",yylineno);}
;
NonAsExpression:
	UnaryExpression		
	|
	NonAsExpression NonAssignmentOperator UnaryExpression	{if(DEBUG_MODE) printf("<<<<<<<<<<Non Assignment Expression>>>>>>>>>>>>>>\n");}
	|
	NonAsExpression NonAssignmentOperator error SEMICOLON	{printf("Error in expression at line %d\n",yylineno);}
;
TernaryExpression:
	NonAsExpression	
	|
	NonAsExpression TERNARY Expression COLON TernaryExpression {if(DEBUG_MODE) printf("<<<<<<<<<<<<Ternary Expression>>>>>>>>>>>\n");}
	|
	NonAsExpression TERNARY error SEMICOLON {printf("Error in ternary expression on line %d\n",yylineno);}
; 
Expression:
	TernaryExpression			
	|
	LeftHandSide AssignmentOperator Expression	{if(DEBUG_MODE) printf("<<<<<<<<<<<<Assignment found>>>>>>>\n");}
	|
	LeftHandSide AssignmentOperator error SEMICOLON	{printf("Error in assignment expression on line %d\n",yylineno);}
;
LeftHandSide:
	TypeName		
	|
	FieldAccess
	|
	ArrayAccess
;
UnaryRtoL:
	INCREMENT
	|
	DECREMENT
;

UnaryLtoR:
	INCREMENT %prec PREINCREMENT
	|
	DECREMENT %prec PREDECREMENT
	|
	PLUS      %prec UPLUS
	|
	MINUS     %prec UMINUS
	|
	NOT
	|
	UNOT
	|
	CAST
;
NonAssignmentOperator:
	ArithmeticOperator
	|
	RelOperator
	|
	LogicalOperator
;
ArithmeticOperator:
	MULT
	|
	DIV
	|
	MOD
	|
	PLUS
	|
	MINUS
;
RelOperator:
	LEFTSHIFT
	|
	RIGHTSHIFT
	|
	URIGHTSHIFT
	|
	LT
	|
	LEQ
	|
	GT
	|
	GEQ
	|
	INSTANCEOF
;
LogicalOperator:
	COMPARE
	|
	NEQ
	|
	BAND
	|
	XOR
	|
	BOR
	|
	AND
	|
	OR
;
AssignmentOperator:
	EQUAL
	|
	PLUSEQUAL
	|
	MINUSEQUAL
	|
	MULTEQUAL
	|
	DIVEQUAL
	|
	MODEQUAL
	|
	ANDEQUAL
	|
	XOREQUAL
	|
	OREQUAL
	|
	LEFTSHIFTEQUAL
	|
	RIGHTSHIFTEQUAL
	|
	URIGHTSHIFTEQUAL
;	
%%
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

