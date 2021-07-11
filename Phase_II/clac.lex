%{
    #include "y.tab.h"
    int currPos = 1, currLine = 1;
    int numIntergers = 0;
    int numOperators = 0;
    int numParens = 0;
    int numEquals = 0;
%}

DIGIT [0-9]

%%

"+"  {currPos += yyleng; return  PLUS;}
"-"  {currPos += yyleng; return  MINUS}
"*"  {currPos += yyleng; return  MULT}
"/"  {currPos += yyleng; return  DIV}
"("  {currPos += yyleng; return  L_PAREN}
")"  {currPos += yyleng; return  R_PAREN}
"="  {currPos += yyleng; retunrn EQUAL}

(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?{DIGIT}+)?) {printf("NUMBER %s\n", yytext); currPos += yyleng; numIntergers++;}


[ \t]+ { /* ignore spaces */ currPos += yyleng;}
"\n"   {currLine++; currPos = 1;}

.      {printf("Error at line %d, column %d: ubrecognized symbol \"%s\"\n", currLine, currPos,yytext); exit(0);}

%%
