------------------INTRODUCTION----------------------------------------------------------------------------------------------------------
This lexical analyser tokenises java identifiers,keywords,literals,operators and separators as defined in the Java language specification as defined at http://docs.oracle.com/javase/specs/jls/se7/html/jls-3.html.The salient features are described below:

1.Keywords
50 keywords are defined.

2.Reserved words
goto and const are defined.

3.Identifiers
As per the specification.

4.Escape sequences
 Unicode and octal escape sequences are supported.

5.Comments
  All three kinds of comments are supported.

5.Literals
  All strings,numbers,floating points and characters are defined as per specification.Boolean and null literals are supported.Integers may be decimal,binary,hexadecimal or octal.Underscores may be used between digits as separators.Floating points may be decimal or hexadecimal.

6.Operators and separators
  Defined as per specification.There are 36 symbols used as operators.
---------------------------------------------------------------------------------------------------------------------------

---------------------------------------Running the code--------------------------------------------------------------------

Run the Makefile to obtain a binary called tokeniser.Feed the sample Java program to this binary.
--------------------------------------------------------------------------------------------------------------------------------

--------------------------------------Output of the code---------------------------------------------------------------------------------
The code displays the tokens obtained from the program at their relevant column numbers and line numbers.Lexical errors are also displayed.There is a global symbol table which holds the keywords and identifiers seen in the program.There is an array error_dump which holds the symbols which are lexical errors and the positions of their occurences.The output can be suppressed by setting the variable DEBUG_MODE to 0.

An example of the output dump is present in the file example_out.txt which has been obtained by feeding the program example.java to the lexical analyser.Another output dump test_out.txt has been obtained by the lexical analysis of test.java

