%{
    #include "y.tab.h"
    int yyerror(char* msg);
    int currPos = 1;
    int currLine = 1;
%}

    

DIGIT [0-9]
ALPHA [a-zA-Z]
IDENT ({ALPHA})(({ALPHA}|{DIGIT})*([_]*({ALPHA}|{DIGIT})+))*
E_ID_1 [0-9_][a-zA-Z0-9_]*
E_ID_2 [a-zA-Z][a-zA-Z0-9_]*[_]
COMMENT ##.*

%% 


"function"          {currPos += yyleng; return FUNCTION;}
"beginparams"       {currPos += yyleng; return BEGIN_PARAMS;}
"endparams"         {currPos += yyleng; return END_PARAMS;}
"beginlocals"       {currPos += yyleng; return BEGIN_LOCALS;}
"endlocals"         {currPos += yyleng; return END_LOCALS;}
"beginbody"         {currPos += yyleng; return BEGIN_BODY;}
"endbody"           {currPos += yyleng; return END_BODY;}
"integer"           {currPos += yyleng; return INTEGER;}
"array"             {currPos += yyleng; return ARRAY;}
"of"                {currPos += yyleng; return OF;}
"if"                {currPos += yyleng; return IF;}
"then"              {currPos += yyleng; return THEN;}
"endif"             {currPos += yyleng; return ENDIF;}
"else"              {currPos += yyleng; return ELSE;}
"while"             {currPos += yyleng; return WHILE;}
"do"                {currPos += yyleng; return DO;}
"beginloop"         {currPos += yyleng; return BEGINLOOP;}
"endloop"           {currPos += yyleng; return ENDLOOP;}
"continue"          {currPos += yyleng; return CONTINUE;}
"read"              {currPos += yyleng; return READ;}
"write"             {currPos += yyleng; return WRITE;}
"and"               {currPos += yyleng; return AND;}
"or"	            {currPos += yyleng; return OR;}
"not"	            {currPos += yyleng; return NOT;}
"true"	            {currPos += yyleng; return TRUE;}
"false"	            {currPos += yyleng; return FALSE;}
"return"            {currPos += yyleng; return RETURN;}

"+"  {currPos += yyleng; return PLUS;}
"-"  {currPos += yyleng; return MINUS;}
"*"  {currPos += yyleng;  return MULT;}
"/"  {currPos += yyleng;  return DIV;}
"("  {currPos += yyleng; return L_PAREN;}
")"  {currPos += yyleng; return R_PAREN;}

"_"  {currPos += yyleng; return MINUS;}
"%"  {currPos += yyleng; return MOD;}




"=="    {currPos += yyleng; return EQ;}
"<>"    {currPos += yyleng; return NEQ;}
"<"     {currPos += yyleng; return LT;}
">"     {currPos += yyleng; return GT;}
"<="    {currPos += yyleng; return LTE;}
">="    {currPos += yyleng; return GTE;}


";"     {currPos += yyleng; return SEMICOLON;}
":"     {currPos += yyleng; return COLON;}
","     {currPos += yyleng; return COMMA;}
"["     {currPos += yyleng; return L_SQUARE_BRACKET;}
"]"     {currPos += yyleng; return R_SQUARE_BRACKET;}
":="    {currPos += yyleng; return ASSIGN;}


(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?{DIGIT}+)?) {yylval.num_val = atoi(yytext);currPos += yyleng; return NUMBER;  }
{IDENT} {yylval.id_val = yytext; return IDENT; currPos += yyleng;}

{E_ID_1} {printf("Error at line %d, column %d: unrecognized symbol \"%s\" Identifier starts with a digit \n", currLine, currPos, yytext); exit(0);}
{E_ID_2} {printf("Error at line %d, column %d: unrecognized symbol \"%s\"Identifier ends with an underscore \n", currLine, currPos, yytext); exit(0);}
{COMMENT} {currLine++; currPos = 1;}


[ \t]+ { /* ignore spaces */ currPos += yyleng;}
"\n"   {currLine++; currPos = 1;}

.      {printf("Error at line %d, column %d: ubrecognized symbol \"%s\"\n", currLine, currPos,yytext); exit(0);}

%%
