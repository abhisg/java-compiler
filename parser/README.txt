For generating the executable,the following software have been used:
	lex 2.5.35
	bison (GNU Bison) 2.5
	gcc version 4.6.3 (Ubuntu/Linaro 4.6.3-1ubuntu5) 
	GNU Make 3.81
	
Run the Makefile to generate the executable named 'parser'.To test the parser on any input JAVA file,run
	$./parser <Filename>.java
	
Important files:
	lexer.l:for tokenising
	parser.ypp:for parse generation
	Folder 'samples' with healthy codes
	Erroneous.java-----|
	small.java---------|codes with error
	test4.java---------|
 
Description:
We have implemented the LALR grammar for Java as specified at http://docs.oracle.com/javase/specs/jls/se7/html/index.html.Bison has been used for generating the parse.Appropriate messages have been printed at salient syntax points.The debug mode can be turned off by setting DEBUG_MODE to 0 in the file parser.ypp.The output dump for various java files in the folder samples is present in the .txt files.

Error Recovery:
In case the statement is erroneous, it shows that an error has been found. Most common type of errors have been handled(;missing,)missing extra } etc.).The strategy of error handling is to find the grammar expression which is nearest to resultant terminal statement,identify the possible locations of error ,and skip upto semi-colon when the error is found.The function yyerror() is called,which pinpoints the exact error.
	However ,in some cases,entire block is skipped if error is found.

