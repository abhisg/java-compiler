all:parser.cpp lex.yy.o
	g++ lex.yy.o parser.cpp -o parser

parser.cpp:parser.ypp
	bison -d -v parser.ypp -o parser.cpp

lex.yy.o:lex.yy.c
	gcc -c lex.yy.c

lex.yy.c:lexer.l
	lex lexer.l

clean:
	rm lex.yy.*
	rm parser parser.output parser.hpp parser.cpp
