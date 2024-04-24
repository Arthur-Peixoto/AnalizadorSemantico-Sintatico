%{
#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

#include "sint.tab.h"

using std::cout;
using std::cin;
using std::string;
//enum {SOME = 1, ALL, VALUE, MIN, MAX, EXACTLY, THAT, NOT, AND, OR, ONLY, RWORD, CLASS, PROPRIETY, INSTANCY, SSYMBOL, DTYPE, CARDINALIDADE};

%}

%option yylineno
%option noyywrap

maiusc [A-Z]
minusc [a-z]
digito [0-9]

%%
[ \t\n]+                                            ; 
[+-]?(({digito}+)|({digito}*\.{digito}+)([eE][-+]?{digito}+)?)      return CARDINALIDADE;
(some)|(SOME)                                                       return SOME;
(all)|(ALL)                                                         return ALL;
(value)|(VALUE)                                                     return VALUE;
(min)|(MIN)                                                         return MIN;
(max)|(MAX)                                                         return MAX;
(exactly)|(EXACTLY)                                                 return EXACTLY;
(that)|(THAT)                                                       return THAT;
(not)|(NOT)                                                         return NOT;
(and)|(AND)                                                         return AND;
(or)|(OR)                                                           return OR;
(only)|(ONLY)                                                       return ONLY;
(inverse)|(INVERSE)                                                 return INVERSE;
(Class:)|(class:)|(CLASS:)                                          return RCLASS;
(SubClassOf:)|(subclassof:)|(SUBCLASSOF:)                           return RSUBCLASS;
(EquivalentTo:)|(equivalentto:)|(EQUIVALENTTO:)                     return REQUIVALENT;
(Individuals:)|(individuals:)|(INDIVIDUALS:)                        return RINDIVIDUALS;
(DisjointClasses:)|(disjointclasses:)|(DISJOINTCLASSES:)            return RDISJOINT;
(DisjointWith:)|(disjointwith:)|(DISJOINTWITH:)                     return RDISJOINT;
({maiusc})({minusc}+)(_?({maiusc})({minusc}*))*                     return CLASS;
((has)(({maiusc})({minusc}+))+)|((is)({maiusc})({minusc}+)(Of))     return PROPRIETY;
(({minusc}+)(({maiusc})({minusc})*)*)                               return PROPRIETY;
({maiusc})({minusc}+)(_?({maiusc})({minusc}+))*({digito}*)          return INSTANCY;
"["                                                                 return '[';
"]"                                                                 return ']';
"{"                                                                 return '{';
"}"                                                                 return '}';
"("                                                                 return '(';
")"                                                                 return ')';
">"                                                                 return SSYMBOL;
"<"                                                                 return SSYMBOL;
"="                                                                 return SSYMBOL;
"<="                                                                return SSYMBOL;
">="                                                                return SSYMBOL;
","                                                                 return ',';
(({minusc}+):" "?({minusc}+))                                       return DTYPE;


%%