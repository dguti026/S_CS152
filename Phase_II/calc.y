%{
    extern FILE **yyin;
%}

%union{
    double dval
    int ival

}
%error-verbose
%token <dval> NUMBER
%type  <dval> EXP
%token L_PAREN, R_PAREN, EQUAL
%left  PLUS,MINUS
%left  MULT,DIV
%start input
%%
input:
    | input line
    ;
line:
    EXP;
EXP:
    NUMBER {$$ = $1;}
        | EXP PLUS  EXP {$$ = $1 + $3;}
        | EXP MINUS EXP {$$ = $1 - $3;}
        | EXP MULT  EXP {$$ = $1 * $3;}
        | EXP DIV   EXP {$$ = $1 / $3; if $3 == 0 yyerror("dividsion by zero");}
        | L_PAREN EXP R_PAREN {$$ = $2;}
        | MINUS EXP     {$$ = -$2}
        



