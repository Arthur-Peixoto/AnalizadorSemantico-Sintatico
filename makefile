
# Compiladores
CC=g++
LEX=flex++
BISON=bison

# Dependências
all: sample

sample: sint.tab.o lex.o lex.yy.o
	$(CC) main.cpp lex.o lex.yy.o sint.tab.o -o sample

bison: sint.y
	$(BISON) sint.y -H 

sint.tab.o: bison
	$(CC) sint.tab.c -c -std=c++17 

lex.o: lex.cpp lex.h 
	$(CC) -c -std=c++17 lex.cpp

lex.yy.o: lex.yy.cc 
	$(CC) -c -std=c++17 lex.yy.cc

lex.yy.cc: lexer.l
	$(LEX) lexer.l

clean:
	rm sample lex.yy.cc lex.yy.o lex.o sample.o 
