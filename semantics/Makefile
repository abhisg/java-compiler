all:parser.tab.cpp lex.yy.o
	g++ -g -o parser parser.tab.cpp lex.yy.o -ll

#symboltable.o:symboltable.cpp
#	gcc -c symboltable.cpp

#parser.o:parser.cpp
#	g++ -c parser.cpp

parser.tab.cpp:parser.ypp
	bison -d -v parser.ypp

lex.yy.o:lex.yy.c
	gcc -c lex.yy.c

lex.yy.c:lexer.l
	lex lexer.l

clean:
	rm lex.yy.c parser.tab.* parser.output *.o
	rm parser
