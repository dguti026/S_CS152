%{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(const char* msg);
//     extern int currLine;
//     extern int currPos;
    extern FILE* yyin;
%}
%union{
    int num_val;
    char* id_val;
}
%error-verbose
%start prog_start
%token <id_val> IDENT
%token <num_val> NUMBER
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS 
END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN
ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE 
TRUE FALSE SEMICOLON COLON RETURN COMMA
%left L_PAREN R_PAREN
%left L_SQUARE_BRACKET R_SQUARE_BRACKET
%left MULT DIV MOD  
%left PLUS MINUS 
%left LT LTE GT GTE EQ NEQ
%right NOT
%left AND
%left OR 
%right ASSIGN

%%
prog_start: functions { printf("prog_start -> functions\n"); }
        ;
functions:  /*empty*/ {printf("functions -> epsilon\n");}
    |       function functions 
            {printf(" functions -> function functions \n");}
    ;
function:   FUNCTION ident SEMICOLON BEGIN_PARAMS declartions END_PARAMS BEGIN_LOCALS declartions END_LOCALS BEGIN_BODY statements END_BODY
            {printf("function ->  FUNCTION ident SEMICOLON BEGIN_PARAMS declartions END_PARAMS BEGIN_LOCALS declartions END_LOCALS BEGIN_BODY statements END_BODY\n");}
    ;
declartions: /*empty*/ 
            {printf("declartions -> epsilon\n");} 
    |        declartion SEMICOLON declartions
             {printf("declartions -> declartion SEMICOLON declartions\n");}
    ;
declartion: identifiers COLON INTEGER
            {printf("declartion -> identifiers COLON INTEGER\n" );}
    |       identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
            {printf("declartion -> identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
    ;
identifiers: ident
            {printf("identifiers -> ident\n");}
    |        ident COMMA identifiers
            {printf("identifiers -> ident COMMA identifiers");}
    ;
statements:
    |       statement SEMICOLON statements
            {printf("statements -> statement SEMICOLON statements\n");}

            
    ;
statement:  var ASSIGN expression
            {printf("statement -> var ASSIGN expression\n");}
    |       IF bool_exp THEN statements ENDIF
            {printf("statement -> IF bool_exp THEN statements ENDIF\n");}
    |       IF bool_exp THEN statements ELSE statements ENDIF
            {printf("statement -> IF bool_exp THEN statements ELSE statements ENDIF\n");}
    |       WHILE bool_exp BEGINLOOP statements ENDLOOP
            {printf("statement -> WHILE bool_exp BEGINLOOP statements ENDLOOP\n");}
    |       DO BEGINLOOP statements ENDLOOP WHILE bool_exp
            {printf("statement -> DO BEGINLOOP statements ENDLOOP WHILE bool_exp\n");}
    |       READ vars
            {printf("statement -> READ vars\n");}
    |       WRITE vars
            {printf("statement -> WRITE vars\n");}
    |       CONTINUE 
            {printf("statement -> CONTINUE\n");}
    |       RETURN expression
            {printf("statement -> RETURN expression\n");}
    ;
bool_exp:           relation_and_expr
                    {printf("bool_exp -> relation_and_expr\n");}
        |           relation_and_expr OR bool_exp
                    {printf("bool_exp -> relation_and_expr OR relation_and_expr\n");}
    ;
relation_and_expr:  relation_expr
                    {printf("relation_and_expr -> relation_expr \n");}
        |           relation_expr AND relation_and_expr
                    {printf("relation_and_expr -> relation_expr AND relation_expr \n");}
        
        ;
relation_expr:      expression comp expression
                    {printf("relation_expr -> expression comp expression\n");}
        |           TRUE
                    {printf("relmaation_expr -> TRUE\n");}
        |           FALSE
                    {printf("relation_expr -> FALSE\n");}
        |           L_PAREN  bool_exp R_PAREN
                    {printf("relation_expr -> L_PAREN  bool_exp R_PAREN\n");}

        |           NOT expression comp expression
                    {printf("relation_expr -> NOT expression comp expression\n");}
        |           NOT TRUE
                    {printf("relation_expr -> NOT TRUE\n");}
        |           NOT FALSE
                    {printf("relation_expr -> NOT FALSE\n");}
        |           NOT L_PAREN  bool_exp R_PAREN
                    {printf("relation_expr -> NOT L_PAREN  bool_exp R_PAREN\n");}
        ;
comp:               EQ
                    {printf("comp -> EQ\n");}
        |           NEQ
                    {printf("comp -> NEQ\n");}
        |           LT
                    {printf("comp -> LT\n");}
        |           GT
                    {printf("comp -> GT\n");}
        |           LTE
                    {printf("comp -> LTE\n");}
        |           GTE
                    {printf("comp -> GTE\n");}
        ;
expression:         mutiplicative_expr
                    {printf("expression -> mutiplicative_expr\n");}
        |           mutiplicative_expr PLUS expression
                    {printf("expression -> mutiplicative_expr PLUS mutiplicative_expr\n");}
        |           mutiplicative_expr MINUS expression
                    {printf("expression -> mutiplicative_expr MINUS mutiplicative_expr\n");}
        ;
expressions:        expression COMMA expressions
                    {printf("expressions -> expression COMMA expressions\n");}
        |           /*empty*/
                    {printf("expressions -> empty\n");}
        |           expression
                    {printf("expressions -> expression\n");}
        ;
mutiplicative_expr: term
                    {printf("mutiplicative_expr -> term\n");}
        |           term MULT term
                    {printf("mutiplicative_expr -> term MULT term\n");}
        |           term DIV term
                    {printf("mutiplicative_expr -> term DIV term\n");}
        |           term MOD term
                    {printf("mutiplicative_expr -> term MOD term\n");}
        ;
term:               var 
                    {printf("term -> var\n");}
        |           NUMBER
                    {printf("term ->NUMBER\n");}
        |           L_PAREN expression R_PAREN
                    {printf("term -> L_PAREN expression R_PAREN\n");}
        |           ident L_PAREN expressions R_PAREN
                    {printf("term -> identifiers L_PAREN expressions R_PAREN\n");}
        
        |           MINUS var
                    {printf("neg_term-> UNARY_MINUS var\n");}
        |           MINUS NUMBER
                    {printf("neg_term -> UNARY_MINUS NUMBER\n");}
        |           MINUS L_PAREN expression R_PAREN
                    {printf("neg_term -> UNARY_MINUS L_PAREN expression R_PAREN\n");}
        ;
ident:              IDENT
                    {printf("ident -> IDENT %s\n", $1);}
        ;
vars:               var COMMA vars
                    {printf("vars -> var COMMA vars\n");}
        |           var
                    {printf("vars->var\n");}
        ;
var:                 ident
                     {printf("var-> ident\n");}
        |            ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET
                     {printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
        
%%
int main(int argc, char **argv){
        if(argc > 1){
                yyin = fopen(argv[1], "r");
                if(yyin == NULL){
                        printf("syntax: %s filename", argv[0]);
                        exit(1);
                }
        }
        yyparse();
        return 0;
}
void yyerror(const char *msg){
        printf("Error: %s\n", msg);
}