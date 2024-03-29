%{
    
    #include <iostream>
    #include <stdio.h>
    #include <cstring>
    using std::cout;

    int yylex(void);
    int yyparse(void);
    void yyerror(const char *);

    extern int yylineno;    
	extern char * yytext;   

%}

%token SOME ALL VALUE MIN MAX EXACTLY THAT NOT OR AND ONLY INVERSE CLASS PROPRIEDADES INSTANCY 
%token RELOP DADOS NUM RESERVADO SUBCLASSOF EQUIVALENTTO INDIVIDUALS DISJOINTCLASS 
%token '[' ']' '(' ')' ',' '{' '}'

%%

classe: classeBody classe              
    | 
    ;

classeBody: classReservada equivalent disjIndiv     
    | classReservada subclass disjIndiv     
    | classReservada disjIndiv        
    | classReservada equivalent subclass disjIndiv 
    ;

classReservada: RESERVADO CLASS 
    ;

disjIndiv: disjoint individuals
    ;

classes: CLASS
    | CLASS orAnd classes 
    ;

/*EquivalentTo*/
equivalent: EQUIVALENTTO CLASS equivalentPro
    | EQUIVALENTTO instancyExpressions  
    ;
    equivalentPro: virgula props
    | orAnd props
    | orAnd classes 
    | '(' equivalentPro ')'
    ;

/*SubClass*/
subclass: SUBCLASSOF CLASS
    | SUBCLASSOF props
    | SUBCLASSOF CLASS orAnd props
    | SUBCLASSOF CLASS virgula props
    ;        

/*Individuals*/
individuals: INDIVIDUALS instancyExpressions
    | 
    ;
individuals: INDIVIDUALS  
    ;   

/*Disjoint Classes*/
disjoint: disjoint seqClasses
    |
    ;           
disjoint: DISJOINTCLASS        
    ;                            
seqClasses: CLASS
    | CLASS virgula seqClasses
    | '(' seqClasses ')' 
    ;
    
/*instancies*/
instancyExpressions: INSTANCY
    | INSTANCY virgula instancyExpressions
    | '{' instancyExpressions '}'
    ;    

/*propriedades*/
props: propriedade
    | propriedade orAnd props         
    | propriedade virgula props
    | INVERSE propriedade
    | INVERSE propriedade orAnd props
    | INVERSE propriedade virgula props
    ;
propriedade: PROPRIEDADES some
    | PROPRIEDADES only        
    | PROPRIEDADES value
    | PROPRIEDADES quantity
    | PROPRIEDADES all
    | '(' props ')'
    ;

only: ONLY CLASS                
    | ONLY '(' classes ')'
    ;

some: SOME CLASS
    | SOME '(' classes ')'
    | SOME DADOS dados
    | SOME propriedade                          
    ;

orAnd: OR
    | AND
    ;

dados: '[' RELOP NUM ']'
    |
    ;

quantity: MIN NUM DADOS
    | MAX NUM DADOS
    | EXACTLY NUM DADOS
    | MIN NUM CLASS
    | MAX NUM CLASS
    | EXACTLY NUM CLASS
    ;

value: VALUE CLASS
    | VALUE INSTANCY
    | VALUE DADOS dados
    ;

all: ALL 
    ;

virgula: ','
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
    
}

void yyerror(const char * s)
{
	/* mensagem de erro exibe o símbolo que causou erro e o número da linha */
    cout << "ERRO SINTÁTICO: símbolo \"" << yytext << "\" (linha " << yylineno << " do arquivo)\n";

}