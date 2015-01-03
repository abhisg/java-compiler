---Abhijit Sharang(10007)---
Group 17

To generate the executable,run the Makefile
The executable is "parser"

To test any program in the samples folder pipe it to the executable as:
./parser <samples "filename.java"

Features of the parser:

(1) Type Checking:- All grammar symbols have been assigned a type.Static type checking has been done for:
	-Expressions
	-Method Invocations
	-Object Creation
	-Loops
	-Class Member access
	-Return types of the functions
	-Access control to the members
    Besides,it has been ensured that only static members can be accessed from static functions

(2) Scoping and Symbol Table:- Proper scoping rules have been implemented.Each scope has a symbol table with a pointer to the symbol table of the scope in which it is embedded.Classes and interfaces have pointers to the classes which they are inheriting or implementing.This hierarchy has been used to resolve calls to global members and inherited members

(3) Function overlaoding:function overloading has been resolved on the basis of the method signatures

(4) Casting:- Implicit and explicit type casting have been implemented in the expressions on the basis of the rules defined in the java manual.Implicit casting is done on the fly by promoting the lower type to higher type in the arithmetic expressions.Only basic types can be cast(Both explicit and implicit)  

(4) Error Handling:- Whenever there is type error appropriate error messages have been printed.
(a) Error in type expressions
(b) Error when the identifier is not found in the symbol table
(c) Error when the method access is illegal
(d) Error when non-boolean is used where boolean type is required
(e) Error when non-numeric is used when numeric type is required
(f) Error when access control is wrongly defined
(g) Error when a variable/method/constructor is defined multiple times
(h) Error when the type of the return expression does not match with the return type of the function
(i) Error when a non-integer is used in the array access
(j) Error when a non-static member is accessed from inside a static method
(k) Syntax errors

(5) Disambiguating the overloaded operators:- The disambiguation of the overloaded operators such as real+int, float*long, double%int is taken care of while performing various arthematic operators.

(6)Test Cases:- There are 18 test programs present in the folder "samples".Their coressponding compilation dumps are present in the folder "outputs"

(7)Intermediate representation:The intermediate representation is in the form of the abstract syntax tree which can be accessed by traversing the path defined by the symbol table.It has not been explicitly constructed since the next phase involves the development of the bytecode which itself is an intermediate representation
