%{
    
    #include <iostream>
    #include <stdio.h>
    #include <map>
    #include <vector>
    #include "semanticAnalyzer.cpp"
    using std::vector;
    using std::string;
    using std::cout;
    using std::endl;

    int yylex(void);
    int yyparse(void);
    void yyerror(const char *);

    semanticAnalyzer * semantico = new semanticAnalyzer();

    bool isSubclassOf = false;

    string operadorAtual;
    string classeAtual;
    string precedente;
    string coercao;
    string numCoercao = "";

    vector<string> sintaticErrors;
    string sintClass = "";

    std::string propriedadeAtual;

    extern char *yytext;
    extern int yylineno; 

%}

%union {
	double num;
	int ind;
}

%token SOME ALL VALUE MIN MAX EXACTLY THAT NOT OR AND ONLY INVERSE CLASS PROPRIETY INSTANCY SSYMBOL DTYPE CARDINALIDADE 
%token RCLASS RSUBCLASS REQUIVALENT RINDIVIDUALS RDISJOINT '[' ']' '(' ')' ',' '{' '}'

%%

classe: classeDefinida classe 
    | classePrimitiva classe    
    | classeComum classe        
    | operprecedente classe  
    | error classe              
    |
    ;

rclass: RCLASS CLASS { classeAtual = yytext; semantico->precAux.clear(); semantico->onlys.clear(); sintClass = ""; }
    ;

classeComum: classeComumProbs   { sintClass += "Classe Comum -> " + classeAtual + "\n"; }
    ;

classeComumProbs: rclass disjoint individuals 
    | rclass disjoint
    | rclass individuals
    | rclass
    ;

classePrimitiva: classePrimitivaProbs   { sintClass += "Classe Primitiva -> " + classeAtual + "\n";  }
    ;

classePrimitivaProbs: rclass subclass disjoint individuals 
    | rclass subclass disjoint
    | rclass subclass individuals
    | rclass subclass
    ;

classeDefinida: classeDefinidaProbs { sintClass += "Classe Definida -> " + classeAtual + "\n"; } 
    ;

classeDefinidaProbs: rclass equivalent disjoint individuals 
    | rclass equivalent disjoint
    | rclass equivalent individuals
    | rclass equivalent
    | rclass equivalent subclass disjoint individuals
    | rclass equivalent subclass disjoint
    | rclass equivalent subclass individuals
    | rclass equivalent subclass
    ;

operprecedente: operprecedenteProbs   { sintClass += "Classe Desconhecida -> " + classeAtual + "\n"; semantico->onlyCheck(operadorAtual, yylineno); }
    ;

operprecedenteProbs: rclass subclass equivalent
    | rclass subclass equivalent disjoint individuals
    | rclass subclass equivalent individuals disjoint
    | rclass subclass equivalent individuals
    | rclass subclass equivalent disjoint
    | rclass subclass individuals disjoint
    | rclass equivalent individuals disjoint
    | rclass individuals equivalent subclass disjoint
    | rclass disjoint equivalent subclass individuals
    | rclass individuals equivalent subclass
    | rclass disjoint equivalent subclass
    | rclass individuals subclass
    | rclass individuals equivalent
    | rclass disjoint subclass
    | rclass disjoint equivalent
    ;

equivalent: requivalent CLASS equivProbs
    | requivalent instancies  { sintClass += "Classe enumerada, "; }
    ;

subclass: rsubclass CLASS
    | rsubclass seqProp
    | rsubclass CLASS connect seqProp
    | rsubclass CLASS ',' seqProp
    ;         

individuals: rindividuals instancies
    ;

disjoint: rdisjoint seqClasses
    ;    

requivalent: REQUIVALENT    { operadorAtual = yytext; isSubclassOf = false; }
    ;

rsubclass: RSUBCLASS        { operadorAtual = yytext; isSubclassOf = true; }
    ;        

rindividuals: RINDIVIDUALS  { operadorAtual = yytext; }
    ;    

rdisjoint: RDISJOINT        { operadorAtual = yytext; }
    ;                            

equivProbs: ',' seqProp
    | connect seqProp
    | connect multClasses { sintClass += "Classe coberta, "; }
    | '(' equivProbs ')'
    ;

seqClasses: CLASS
    | CLASS ',' seqClasses
    | '(' seqClasses ')' 
    ;

instancies: INSTANCY
    | INSTANCY ',' instancies
    | '{' instancies '}'
    ;    

connect: OR
    | AND
    ;

seqProp: prop      
    | prop connect seqProp         
    | prop ',' seqProp
    | INVERSE prop
    | INVERSE prop connect seqProp
    | INVERSE prop ',' seqProp
    ;

prop: propName some 
    | propName only        { sintClass += "Axioma de fechamento, "; semantico->onlyCheck(propriedadeAtual, yylineno); }
    | propName value
    | propName qntd
    | propName exactly
    | propName all
    | '(' seqProp ')'
    ;

propName: PROPRIETY         { propriedadeAtual = yytext;}
    ;

only: ONLY auxOnlyClass                    
    | ONLY '(' onlyMultClasses ')'
    ;

onlyMultClasses: auxOnlyClass
    | auxOnlyClass connect onlyMultClasses 
    ;

auxOnlyClass: CLASS             { if(isSubclassOf) semantico->onlys.push_back(yytext); }
    ;

multClasses: className  
    | className connect multClasses 
    ;

className: CLASS            { precedente = yytext; coercao = yytext; }
    ;

some: SOME CLASS       { }
    | SOME '(' multClasses ')' {  semantico->precAux.push_back(precedente); precedente = ""; }
    | SOME dtype especificardtype {  }
    | SOME prop             { sintClass += "Descrição aninhada, "; }
    //| error                 { std::cout << "Esperava CLASS, DTYPE, PROPRIETY\n"; }
    ;

especificardtype: '[' SSYMBOL num ']'   { semantico->coercionChecker(coercao, numCoercao, yylineno); }
    |
    ;

qntd: MIN num dtype   { semantico->coercionChecker(coercao, numCoercao, yylineno); }
    | MAX num dtype   { semantico->coercionChecker(coercao, numCoercao, yylineno); }
    | MIN num className   { semantico->coercionChecker(coercao, numCoercao, yylineno); }
    | MAX num className   { semantico->coercionChecker(coercao, numCoercao, yylineno); }
    ;

num: CARDINALIDADE      { numCoercao = yytext; }
    ;

dtype: DTYPE            { coercao = yytext; }
    ;

value: VALUE CLASS      
    | VALUE INSTANCY    
    | VALUE dtype especificardtype
    ;

exactly: EXACTLY num className      { semantico->coercionChecker(coercao, numCoercao, yylineno); }
    | EXACTLY '{' instancies '}'
    ;

all: ALL CLASS 
    | ALL '(' multClasses ')'
    ;

%%

/* definido pelo analisador léxico */
extern FILE * yyin;  
int main(int argc, char ** argv)
{

    /* se foi passado um nome de arquivo */
	if (argc > 1)
	{
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file)
		{
			cout << "Arquivo " << argv[1] << " não encontrado!\n";
			exit(1);
		}

		/* entrada ajustada para ler do arquivo */
		yyin = file;
	}

	yyparse();

    cout << "Arquivo lido: " << argv[1] << endl;

            cout << "-------------------------------------------------------------------------------" << std::endl;
            cout << "\t\t\t\t ERROS SEMÂNTICOS" << std::endl;
            cout << "-------------------------------------------------------------------------------" << std::endl;
            for(string e : semantico->semanticErrors){
                cout << "ERRO SEMÂNTICO: " << e;
            }  
            if(semantico->semanticErrors.size() == 0){
                cout << "Nenhum erro semântico encontrado. Verifique os sintáticos.\n";
            }

            cout << "-------------------------------------------------------------------------------" << std::endl;
            cout << "\t\t\t\t ERROS SINTÁTICOS" << std::endl;
            cout << "-------------------------------------------------------------------------------" << std::endl;
            for(string e: sintaticErrors){
                cout << e;
            }
            if(sintaticErrors.size() == 0){
                cout << "Nenhum erro sintático encontrado.\n";
            }
}

void yyerror(const char * s)
{
	/* variáveis definidas no analisador léxico */   
	extern char * yytext;   


    string aux = "";

    aux += "ERRO SINTÁTICO: símbolo \"" + std::string(yytext) + "\" (linha " + std::to_string(yylineno) + " do arquivo)\n";
    aux += "NA PROPRIEDADE: \"" + operadorAtual + "\" DA CLASSE " + classeAtual + "\n";

    sintaticErrors.push_back(aux);
    aux = "";
}