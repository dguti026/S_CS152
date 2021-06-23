%{
    int currPos = 1, currLine = 1;
    int numIntergers = 0;
    int numOperators = 0;
    int numParens = 0;
    int numEquals = 0;
%}

    

DIGIT [0-9]
ALPHA [a-zA-Z]
ID ({ALPHA})(({ALPHA}|{DIGIT})*.[_]*({ALPHA}|{DIGIT})+)*
E_ID_1 [0-9_][a-zA-Z0-9_]*
E_ID_2 [a-zA-Z][a-zA-Z0-9_]*[_]
COMMENT ##.*

%% 



"+"  {printf("PLUS\n"); currPos += yyleng; numOperators++;}
"-"  {printf("MINUS\n"); currPos += yyleng; numOperators++;}
"*"  {printf("MULT\n"); currPos += yyleng;  numOperators++;}
"/"  {printf("DIV\n"); currPos += yyleng;  numOperators++;}
"("  {printf("L_PAREN\n"); currPos += yyleng; numParens++;}
")"  {printf("R_PAREN\n"); currPos += yyleng; numParens++;}
"="  {printf("EQUAL\n"); currPos += yyleng; numEquals++;}
"_"  {printf("UNDER_SCORE\n"); currPos += yyleng; numOperators++;}
"%"  {printf("MOD\n"); currPos += yyleng; numOperators++;}



"=="    {printf("EQ\n"); currPos += yyleng; numOperators++;}
"<>"    {printf("NEQ\n"); currPos += yyleng; numOperators++;}
"<"     {printf("LT\n"); currPos += yyleng; numOperators++;}
">"     {printf("GT\n"); currPos += yyleng; numOperators++;}
"<="    {printf("LTE\n"); currPos += yyleng; numOperators++;}
">="    {printf("GTE\n"); currPos += yyleng; numOperators++;}


";"     {printf("SEMICOLON\n"); currPos += yyleng; numOperators++;}
":"     {printf("COLON\n"); currPos += yyleng; numOperators++;}
","     {printf("COMMA\n"); currPos += yyleng; numOperators++;}
"["     {printf("L_SQUARE_BRACKET\n"); currPos += yyleng; numOperators++;}
"]"     {printf("R_SQUARE_BRACKET\n"); currPos += yyleng; numOperators++;}
":="    {printf("ASSIGN\n"); currPos += yyleng; numOperators++;}



"function"      {printf("FUNCTION\n");     currPos += yyleng; numOperators++;}
"beginparams"   {printf("BEGIN_PARAMS\n"); currPos += yyleng; numOperators++;}
"endparams"     {printf("END_PARAMS\n");   currPos += yyleng; numOperators++;}
"beginlocals"   {printf("BEGIN_LOCALS\n"); currPos += yyleng; numOperators++;}
endlocals       {printf("END_LOCALS\n");   currPos += yyleng; numOperators++;}
beginbody       {printf("BEGIN_BODY\n");   currPos += yyleng; numOperators++;}
endbody         {printf("END_BODY\n");     currPos += yyleng; numOperators++;}
integer         {printf("INTEGER\n");      currPos += yyleng; numOperators++;}
array           {printf("ARRAY\n");        currPos += yyleng; numOperators++;}
enum	        {printf("ENUM\n");         currPos += yyleng; numOperators++;}
of              {printf("OF\n");           currPos += yyleng; numOperators++;}
if              {printf("IF\n");           currPos += yyleng; numOperators++;}
then            {printf("THEN\n");         currPos += yyleng; numOperators++;}
endif           {printf("ENDIF\n");        currPos += yyleng; numOperators++;}
else            {printf("ELSE\n");         currPos += yyleng; numOperators++;}
while           {printf("WHILE\n");        currPos += yyleng; numOperators++;}
do              {printf("DO\n");           currPos += yyleng; numOperators++;}
beginloop       {printf("BEGIN_LOOP\n");   currPos += yyleng; numOperators++;}
endloop         {printf("END_LOOP\n");     currPos += yyleng; numOperators++;}
continue        {printf("CONTINUE\n");     currPos += yyleng; numOperators++;}
read            {printf("READ\n");         currPos += yyleng; numOperators++;}
write           {printf("WRITE\n");        currPos += yyleng; numOperators++;}
and             {printf("AND\n");          currPos += yyleng; numOperators++;}
or	            {printf("OR\n");           currPos += yyleng; numOperators++;}
not	            {printf("NOT\n");          currPos += yyleng; numOperators++;}
true	        {printf("TRUE\n");         currPos += yyleng; numOperators++;}
false	        {printf("FALSE\n");        currPos += yyleng; numOperators++;}
return          {printf("RETURN\n");       currPos += yyleng; numOperators++;}



(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?{DIGIT}+)?) {printf("NUMBER %s\n", yytext); currPos += yyleng; numIntergers++;}
{ID} {printf("ID %s\n",yytext); currPos += yyleng;}

{E_ID_1} {printf("Error at line %d, column %d: unrecognized symbol \"%s\" Identifier starts with a digit \n", currLine, currPos, yytext); exit(0);}
{E_ID_2} {printf("Error at line %d, column %d: unrecognized symbol \"%s\"Identifier ends with an underscore \n", currLine, currPos, yytext); exit(0);}
{COMMENT} {currLine++; currPos = 1;}


[ \t]+ { /* ignore spaces */ currPos += yyleng;}
"\n"   {currLine++; currPos = 1;}

.      {printf("Error at line %d, column %d: ubrecognized symbol \"%s\"\n", currLine, currPos,yytext); exit(0);}

%%

int main(int argc, char **argv)
{
    if(argc >= 2){
        yyin = fopen(argv[1], "r");
        if(yyin == NULL){
            yyin = stdin;
        }
    }
    else{
        yyin = stdin;
    }
    yylex();
    printf("# Intergers: %d\n", numIntergers);
    printf("# Operators: %d\n", numOperators);
    printf("# Parenheses: %d\n", numParens);
    printf("# Equal Signs: %d\n", numEquals);
}
