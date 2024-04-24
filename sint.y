%{
    
    #include <iostream>
    #include <stdio.h>
    #include <cstring>
    using std::cout;

    int cont = 0, contPar = 0, contColc = 0, contChav = 0;
    int contCommumClasses = 0;
    int contClassesDefinidas = 0;
    int contClassesPrimitivas = 0;
    int 
    bool classeError, equivalentError, subclassError, disjointError, individualsError, onlyError,someError, integerError,floatError,dataError

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

classeBody: classReservada equivalent disjIndiv    { std::cout << "Classe Definida"<< std::endl;} 
    | classReservada subclass disjIndiv     { std::cout << "Classe Primitiva"<< std::endl;} 
    | classReservada disjIndiv        { std::cout << "Classe Comum"<< std::endl;} 
    | classReservada equivalent subclass disjIndiv { std::cout << "Classe Indefinida"<< std::endl;} 
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
    | EQUIVALENTTO instancyExpressions  { std::cout << "Classe Enumerada"<< std::endl;} 
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