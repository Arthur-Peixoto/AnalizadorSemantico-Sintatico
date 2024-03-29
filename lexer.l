%{
#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

#include "sint.tab.h"

using std::cout;
using std::cin;
using std::string;
//enum {SOME = 1, ALL, VALUE, MIN, MAX, EXACTLY, THAT, NOT, AND, OR, ONLY, RWORD, CLASS, PROPRIEDADES, INSTANCY, RELOP, DTYPE, NUM};

%}

%option yylineno
%option noyywrap

maiusc [A-Z]
minusc [a-z]
digito [0-9]

%%
[ \t\n]+                                            ; 
[+-]?(({digito}+)|({digito}*\.{digito}+)([eE][-+]?{digito}+)?)      return NUM;
(({minusc}+):" "?({minusc}+))                                       return DADOS;
"some"                                                              return SOME;
"all"                                                               return ALL;
"value"                                                             return VALUE;
"min"                                                               return MIN;
"max"                                                               return MAX;
"exactly"                                                           return EXACTLY;
"that"                                                              return THAT;
"not"                                                               return NOT;
"and"                                                               return AND;
"or"                                                                return OR;
"only"                                                              return ONLY;
"inverse"                                                           return INVERSE;
({maiusc})({minusc}+)(_?({maiusc})({minusc}*))*                     return CLASS;
((has)(({maiusc})({minusc}+))+)|((is)({maiusc})({minusc}+)(Of))     return PROPRIEDADES;
(({minusc}+)(({maiusc})({minusc})*)*)                               return PROPRIEDADES;
({maiusc})({minusc}+)(_?({maiusc})({minusc}+))*({digito}*)          return INSTANCY;
">"                                                                 return RELOP;
"<"                                                                 return RELOP;
"="                                                                 return RELOP;
"<="                                                                return RELOP;
">="                                                                return RELOP;
"["                                                                 return '[';
"]"                                                                 return ']';
"{"                                                                 return '{';
"}"                                                                 return '}';
"("                                                                 return '(';
")"                                                                 return ')';
","                                                                 return ',';

"Class:"                                                            return RESERVADO;
"SubClassOf:"                                                       return SUBCLASSOF;
"EquivalentTo:"                                                     return EQUIVALENTTO;
"Individuals:"                                                      return INDIVIDUALS;
"DisjointClasses:"|"DisjointWith"                                   return DISJOINTCLASS;


%%