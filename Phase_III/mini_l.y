%{
    #define YY_NO_INPUT
    #include <stdio.h>
    #include <stdlib.h>
    #include <map>
    #include <string.h>
    #include <set>
    /*Phase_3*/
    int tempCount = 0;
    int labelCount = 0;
    extern char* yytext;
    extern int currPos;
    bool mainFunc = false;
    std::set<std::string> funcs;
    std::map<std::string, std::string> varTemp;
    std::map<std::string, int> arrSize;
    std::set<std::string> reserved {"FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS",  
        "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER", "ARRAY", "OF" , "IF", "THEN",
        "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", 
        "TRUE", "FALSE", "SEMICOLON", "COLON" ,"RETURN", "COMMA", "FALSE", "SEMICOLON", "COLON", "RETURN", "COMMA",
        "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "MULT", "DIV", "MOD","PLUS" "MINUS", "LT", "LTE" 
        "GT", "GTE" , "EQ", "NEQ", " NOT", "AND", "OR ","ASSIGN", "Function", "Declarations", "Declaration", "Vars", "Var", "Expressions", "Expression", "Ident", "Idents", "Bool_exp",
         "Relation_and_expr", "Relation_expr_inv", "Relation_expr", "Comp", "Multiplicative_expr", "Term", "Statements", "Statement"
        };
    std::string new_label();
    std::string new_temp();
    /*Pahse_2*/
    void yyerror(const char* msg);
    int yylex();
//     extern int currLine;
//     extern FILE* yyin;
%}
%union{
    int num_val;
    char* id_val;
    struct S{
            char* code;
    } statement;
    struct E{
            char* place;
            char* code;
            bool arr;
    } expression;
}
%error-verbose
%start prog_start
%token <id_val> IDENT
%token <num_val> NUMBER
%type <expression> Function Declartions Declartion FuncIdent Vars Var Expression Expressions Ident Idents
%type <expression> Bool_exp Relation_and_expr Relation_expr_inv Relation_expr Comp Mutiplicative_expr Term
%type <statement>  Statement Statements
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
prog_start: %empty
        {
                if(!mainFunc){
                     printf("No main function declared!\n");
                }
        }
        | Function prog_start
        { 
        }
  
      ;

Function:   FUNCTION FuncIdent SEMICOLON BEGIN_PARAMS Declartions END_PARAMS BEGIN_LOCALS Declartions END_LOCALS BEGIN_BODY Statements END_BODY
            {
                    std::string temp = "func ";
                    temp.append($2.place);
                    temp.append("\n");
                    std::string s = $2.place;
                    if(s == "main"){
                        mainFunc = true;
                    }
                    temp.append($5.code);
                    std::string decs = $5.code;
                    int decNum = 0;
                    while(decs.find(".") != std::string::npos){
                        int pos = decs.find(".");
                        decs.replace(pos,1,"=");
                        std::string part = ", $" + std::to_string(decNum) + "\n";
                        decNum ++;
                        decs.replace(decs.find("\n",pos), 1, part);
                    }
                    temp.append(decs);
                    temp.append($8.code);
                    std::string statements = $11.code;
                    if(statements.find("continue") != std::string::npos){
                            printf("ERROR: Continue outside loop in function %s\n", $2.place);

                    }
                    temp.append(statements);
                    temp.append("endfunc\n\n");
                    printf(temp.c_str());
            }

    ;
Declartions:   Declartion SEMICOLON Declartions
             {
                     std::string temp;
                     temp.append($1.code);
                     temp.append($3.code);
                     $$.code = strdup(temp.c_str());
                     $$.place = strdup("");
             }
    |         %empty
            {       $$.code = strdup("");
                    $$.place = strdup("");
                    
            } 
    ;
/*changed identifiers to Idents*/
Declartion: Idents COLON INTEGER
            {
                    int left = 0;
                    int right = 0;
                    std::string parse($1.place);
                    std::string temp;
                    bool ex = false;
                    while(!ex){
                        right = parse.find("|",left);
                        temp.append(". ");
                        if(right == std::string::npos){
                                std::string ident = parse.substr(left, right);
                                if(reserved.find(ident) != reserved.end()){
                                        printf("Identifier %s's name is a reserved word. \n",ident.c_str());
                                }
                                if(funcs.find(ident) != funcs.end() || varTemp.find(ident) != varTemp.end()){
                                        printf("Identifier %s is previously declared. \n", ident.c_str());
                                }
                                else{
                                        varTemp[ident] = ident;
                                        arrSize[ident] = 1;
                                }
                                temp.append(ident);
                                ex = true;
                        }
                        else{
                                std::string ident = parse.substr(left,right-left);
                                if(reserved.find(ident) != reserved.end()){
                                        printf("Identifier %s's name is a reserved word. \n", ident.c_str());
                                }
                                if(funcs.find(ident) != funcs.end() || varTemp.find(ident) != varTemp.end()){
                                        printf("Identifier %s is previously declared. \n", ident.c_str());
                                }
                                else{
                                        varTemp[ident] = ident;
                                        arrSize[ident] = 1;
                                }
                                temp.append(ident);
                                left = right + 1;
                        }
                        temp.append("\n");
                    }
                    $$.code = strdup(temp.c_str());
                    $$.place  = strdup("");
            }
/*changed identifiers to Idents*/
    |       Idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
            {
                    size_t left = 0;
                    size_t right = 0;
                    std::string parse($1.place);
                    std::string temp;
                    bool ex = false;
                    while(!ex){
                            right = parse.find("|",left);
                            temp.append(".[] ");
                            if(right == std::string::npos){
                                    std::string ident = parse.substr(left, right);
                                    if(reserved.find(ident) != reserved.end()){
                                        printf("Identifier %s's name is a reserved word. \n", ident.c_str());
                                    }
                                    if(funcs.find(ident) != funcs.end() || varTemp.find(ident) != varTemp.end()){
                                        printf("Identifier %s is previously declared. \n", ident.c_str());
                                    }
                                    else{
                                        if($5 <= 0){
                                        printf("Declaring array ident %s of size <= 0. \n", ident.c_str()); 
                                        }
                                        varTemp[ident] = ident;
                                        varTemp[ident] = $5;
                                    }
                                    temp.append(ident);
                                    ex = true;
                            }
                            else{
                                    std::string ident = parse.substr(left,right-left);
                                    if(reserved.find(ident) != reserved.end()){
                                        printf("Identifier %s's name is a reserved word. \n", ident.c_str());
                                    }
                                    if(funcs.find(ident) != funcs.end() || varTemp.find(ident) != varTemp.end()){
                                        printf("Identifier %s is previously declared. \n", ident.c_str());
                                    }
                                    else{
                                        if($5 <= 0){
                                        printf("Declaring array ident %s of size <= 0. \n", ident.c_str()); 
                                        }
                                        varTemp[ident] = ident;
                                        varTemp[ident] = $5;
                                    }
                                    temp.append(ident);
                                    left = right + 1;
                            }
                            temp.append(", ");
                            temp.append(std::to_string($5));
                            temp.append("\n");
                    }
                    $$.code = strdup(temp.c_str());
                    $$.place = strdup("");
            }
    ;

Statements: Statement SEMICOLON Statements
            {
                    std::string temp;
                    temp.append($1.code);
                    temp.append($3.code);
                    $$.code = strdup(temp.c_str());
            }
     |           Statement SEMICOLON
            {
                    $$.code = strdup($1.code);
            }
    ;
Statement:  Var ASSIGN Expression
            {
                    std::string temp;
                    temp.append($1.code);
                    temp.append($3.code);
                    std::string middle = $3.place;
                    if($1.arr && $3.arr){
                            temp += "[]= ";
                    }
                    else if($1.arr){
                            temp += "[]= ";
                    }
                    else if($3.arr){
                            temp += "=[] ";
                    }
                    else{
                            temp += "= ";   
                    }
                    temp.append($1.place);
                    temp.append(", ");
                    temp.append(middle);
                    temp += "\n";
                    $$.code = strdup(temp.c_str());

            }
    |       IF Bool_exp THEN Statements ENDIF
            {
                    std::string begin_if = new_label();
                    std::string after = new_label();
                    std::string temp;
                    temp.append($2.code);
                    temp = temp + "?:= " + begin_if+ ", " + $2.place + "\n";
                    temp = temp + ":= " + after + "\n";
                    temp = temp + ": " + begin_if + "\n";
                    // declaring a label
                    temp.append($4.code);
                    temp = temp + ": " + after + "\n ";
                    $$.code = strdup(temp.c_str());

            }
    |       IF Bool_exp THEN Statements ELSE Statements ENDIF
            {
                    std::string begin_if = new_label();
                    std::string after = new_label();
                    std::string temp;
                    temp.append($2.code);
                    temp = temp + "?:= " + begin_if + ", " + $2.place + "\n";
                    temp.append($6.code);
                    temp = temp + ":= " + after + "\n";
                    temp = temp + ": " + begin_if + "\n";
                    temp.append($4.code);
                    temp = temp + ": " + after + "\n";
                    $$.code = strdup(temp.c_str());

            }
    |       WHILE Bool_exp BEGINLOOP Statements ENDLOOP
            {
                    std::string begin = new_label();
                    std::string first = new_label();
                    std::string after = new_label();
                    std::string temp;
                    std::string code = $4.code;
                    size_t pos = code.find("continue");
                    while(pos != std::string::npos){
                            code.replace(pos,8,":= " +begin);
                            pos = code.find("continue");
                    }
                    temp.append(": ");
                    temp += begin + "\n";
                    temp.append($2.code);
                    temp += "?:=" + first + ", ";
                    temp.append($2.place);
                    temp.append("\n");
                    temp += ":= " + after + "\n";
                    temp += ": " + first + "\n";
                    temp.append($4.code);
                    temp += ":= " + begin + "\n";
                    temp += ": " + after + "\n";
                    $$.code = strdup(temp.c_str());
            }
    |       DO BEGINLOOP Statements ENDLOOP WHILE Bool_exp
            {
                    std::string begin = new_label();
                    std::string after = new_label();
                    std::string temp;
                    std::string code = $3.code;
                    size_t pos = code.find("continue");
                    while(pos != std::string::npos){
                        code.replace(pos,8,":= " + after);
                        pos = code.find("continue");
                    }
                    temp.append(": ");
                    temp += begin +"\n";
                    temp.append($3.code);
                    temp += ": " + after + "\n";
                    temp.append($6.code);
                    temp += "?:= " + begin + ",";
                    temp.append($6.place);
                    temp.append("\n");
                    $$.code = strdup(temp.c_str());


            }
    |       READ Vars
            {
                    std::string temp;
                    temp.append($2.code);
                    size_t pos = temp.find("|", 0);
                    while(pos != std::string::npos){
                            temp.replace(pos, 1, "<");
                            pos = temp.find("|",pos);
                    }
                    $$.code = strdup(temp.c_str());
            }
    |       WRITE Vars
            {
                    std::string temp;
                    temp.append($2.code);
                    size_t pos = temp.find("|",0);
                    while(pos != std::string::npos){
                            temp.replace(pos,1,">");
                            pos = temp.find("|", pos);
                    }
                    $$.code = strdup(temp.c_str());

            }
    |       CONTINUE 
            {
                    $$.code = strdup("continue");
            }
    |       RETURN Expression
            {
                    std::string temp;
                    temp.append($2.code);
                    temp.append($2.place);
                    temp.append("\n");
                    $$.code = strdup(temp.c_str());
            }
    ;
Bool_exp:           Relation_and_expr
                    {
                            $$.code =strdup($1.code);
                            $$.place = strdup($1.place);
                    }
        |           Relation_and_expr OR Bool_exp
                    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append($1.code);
                            temp.append($3.code);
                            temp += ". "+ dst + "\n";
                            temp += "|| " + dst + ",";
                            temp.append($1.place);
                            temp += ",";
                            temp.append($3.place);
                            temp += "\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                    }
    ;
Relation_and_expr:  Relation_expr_inv
                    {
                            $$.code =strdup($1.code);
                            $$.place = strdup($1.place);
                    }
        |           Relation_expr_inv AND Relation_and_expr
                    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append($1.code);
                            temp.append($3.code);
                            temp += ". "+ dst + "\n";
                            temp += "&& " + dst + ",";
                            temp.append($1.place);
                            temp += ",";
                            temp.append($3.place);
                            temp += "\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                    }
        
        ;
Relation_expr_inv: NOT Relation_expr_inv
                   {
                           std::string temp;
                           std::string dst = new_temp();
                           temp.append($2.code);
                           temp += ". " + dst + "\n";
                           temp == "! " + dst + ",";
                           temp.append($2.place);
                           temp.append("\n");
                           $$.code = strdup(temp.c_str());
                           $$.place = strdup($2.place);
                   }
        |           Relation_expr{
                           $$.code = strdup($1.code);
                           $$.place = strdup($1.place);

        }


Relation_expr:      Expression Comp Expression
                    {
                            std::string dst = new_temp();
                            std::string temp;
                            temp.append($1.code);
                            temp.append($3.code);
                            temp = temp + ". " + dst + "\n" + $2.place + dst + ", " + $1.place + ", " + $3.place + "\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                    }
        |           TRUE
                    {
                            std::string temp;
                            temp.append("1");
                            $$.code = strdup("");
                            $$.place = strdup(temp.c_str());
                    }
        |           FALSE
                    {
                            std::string temp;
                            temp.append("0");
                            $$.code = strdup("");
                            $$.place = strdup(temp.c_str());
                    }
        |           L_PAREN  Bool_exp R_PAREN
                    {
                            $$.code = strdup($2.code);
                            $$.place = strdup($2.place);
                    }
/*
        |           NOT expression comp expression
                    {printf("relation_expr -> NOT expression comp expression\n");}
        |           NOT TRUE
                    {printf("relation_expr -> NOT TRUE\n");}
        |           NOT FALSE
                    {printf("relation_expr -> NOT FALSE\n");}
        |           NOT L_PAREN  bool_exp R_PAREN
                    {printf("relation_expr -> NOT L_PAREN  bool_exp R_PAREN\n");}
*/
        ;
Comp:               EQ
                    {
                            $$.code = strdup("");
                            $$.place = strdup("==");
                    }
        |           NEQ
                    {
                            $$.code = strdup("");
                            $$.place = strdup("!=");
                    }
        |           LT
                    {
                            $$.code = strdup("");
                            $$.place = strdup("<");
                    }
        |           GT
                    {
                            $$.code = strdup("");
                            $$.place = strdup(">");
                    }
        |           LTE
                    {
                            $$.code = strdup("");
                            $$.place = strdup(">=");
                    }
        |           GTE
                    {
                            $$.code = strdup("");
                            $$.place = strdup("<=");
                    }
        ;
Expression:         Mutiplicative_expr
                    {
                            $$.code = strdup($1.code);
                            $$.place = strdup($1.place);
                    }
        |           Mutiplicative_expr PLUS Expression
                    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append($1.code);
                            temp.append($3.code);
                            temp += ". "+ dst + "\n";
                            temp += "+ " + dst + ",";
                            temp.append($1.place);
                            temp += ",";
                            temp.append($3.place);
                            temp += "\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                    }
        |           Mutiplicative_expr MINUS Expression
                    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append($1.code);
                            temp.append($3.code);
                            temp += ". "+ dst + "\n";
                            temp += "- " + dst + ",";
                            temp.append($1.place);
                            temp += ",";
                            temp.append($3.place);
                            temp += "\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                    }
        ;
Expressions:        Expression COMMA Expressions
                    {
                            std::string temp;
                            temp.append($1.code);
                            temp.append("param ");
                            temp.append($1.place);
                            temp.append("\n");
                            temp.append($3.code);
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup("");
                    }
        |           Expression
                    {
                            std::string temp;
                            temp.append($1.code);
                            temp.append("param ");
                            temp.append($1.place);
                            temp.append("\n");
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup("");
                    }
        ;
Mutiplicative_expr: Term
                    {
                            $$.code = strdup($1.code);
                            $$.place = strdup($1.place);
                    }
        |           Term MULT Mutiplicative_expr
                    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append($1.code);
                            temp.append($3.code);
                            temp.append(".");
                            temp.append(dst);
                            temp.append("\n");
                            temp += "* " + dst + ", ";
                            temp.append($1.place);
                            temp += ",";
                            temp.append($3.place);
                            temp += "\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());

                    }
        |           Term DIV Mutiplicative_expr
                    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append($1.code);
                            temp.append($3.code);
                            temp.append(".");
                            temp.append(dst);
                            temp.append("\n");
                            temp += "/ " + dst + ", ";
                            temp.append($1.place);
                            temp += ",";
                            temp.append($3.place);
                            temp += "\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                    }
        |           Term MOD Mutiplicative_expr
                    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append($1.code);
                            temp.append($3.code);
                            temp.append(".");
                            temp.append(dst);
                            temp.append("\n");
                            temp += "%" + dst + ", ";
                            temp.append($1.place);
                            temp += ",";
                            temp.append($3.place);
                            temp += "\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                    }
        ;
Term:               Var 
                    {
                            std::string dst = new_temp();
                            std::string temp;
                            if($1.arr){
                                    temp.append($1.code);
                                    temp.append(". ");
                                    temp.append(dst);
                                    temp.append("\n");
                                    temp += "=[] " + dst + ", ";
                                    temp.append($1.place);
                                    temp.append("\n");
                            }
                            else{
                                    temp.append(". ");
                                    temp.append(dst);
                                    temp.append("\n");
                                    temp = temp + "= " + dst + ", ";
                                    temp.append($1.place);
                                    temp.append("\n");
                                    temp.append($1.code);
                            }
                            if(varTemp.find($1.place) != varTemp.end()){
                                    varTemp[$1.place] = dst;
                            }
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                    }
        |           NUMBER
                    {
                            std::string dst = new_temp();
                            std::string temp;
                            temp.append(". ");
                            temp.append(dst);
                            temp.append("\n");
                            temp = temp + "= " + dst + "," + std::to_string($1) + "\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                            
                    }
        |           L_PAREN Expression R_PAREN
                    {
                            $$.code = strdup($2.code);
                            $$.place = strdup($2.place);
                    }
        |           Ident L_PAREN Expressions R_PAREN
                    {
                            std::string temp;
                            std::string func = $1.place;
                            if(funcs.find(func) == funcs.end()){
                                    printf("Calling undeclared function %s. \n", func.c_str());
                            }
                            std::string dst = new_temp();
                            temp.append($3.code);
                            temp += ". " + dst + "\ncall ";
                            temp.append($1.place);
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                    }
        
        |           MINUS Var
                    {
                            std::string dst = new_temp();
                            std::string temp;
                            if($2.arr){
                                    temp.append($2.code);
                                    temp.append(". ");
                                    temp.append(dst);
                                    temp.append("\n");
                                    temp += "=[] " + dst + ", ";
                                    temp.append($2.place);
                                    temp.append("\n");
                            }
                            else{
                                    temp.append(". ");
                                    temp.append(dst);
                                    temp.append("\n");
                                    temp = temp + "= " + dst + ", ";
                                    temp.append($2.place);
                                    temp.append("\n");
                                    temp.append($2.code);
                            }
                            if(varTemp.find($2.place) != varTemp.end()){
                                    varTemp[$2.place] = dst;
                            }
                            temp += "* " + dst + ", " + dst + ", -1\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());
                    }
        |           MINUS NUMBER
                    {
                            std::string dst = new_temp();
                            std::string temp;
                            temp.append(". ");
                            temp.append(dst);
                            temp.append("\n");
                            temp = temp + "= " + dst + ", -" + std::to_string($2) + "\n";
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup(dst.c_str());

                    }
        |           MINUS L_PAREN Expression R_PAREN
                    {
                            std::string temp;
                            temp.append($3.code);
                            temp.append("* ");
                            temp.append($3.place);
                            temp.append(", ");
                            temp.append(", -1\n");
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup($3.place);
                    }
        ;
/*Added FuncIdent */
FuncIdent:      IDENT
                {
                        if(funcs.find($1) != funcs.end()){
                                printf("function name %s already declared.\n",$1);
                        }
                        else{
                                funcs.insert($1);
                        }
                        $$.place = strdup($1);
                        $$.code = strdup("");
                }
        ;
/*changed ident to Ident*/
Ident:              IDENT
                    {
                            $$.place = strdup($1);
                            $$.code = strdup("");
                    }
        ;
/*added Idents */
Idents:             Ident
                    {
                            $$.place = strdup($1.place);
                            $$.code = strdup("");
                    }
        |           Ident COMMA Idents
                    {
                            std::string temp;
                            temp.append($1.place);
                            temp.append("|");
                            temp.append($3.place);
                            $$.place = strdup(temp.c_str());
                            $$.code = strdup("");
                    }
        ;
Vars:               Var COMMA Vars
                    {
                            std::string temp;
                            temp.append($1.code);
                            if($1.arr){
                                    temp.append(".[]| ");
                            }
                            else{
                                    temp.append(".| ");
                            }
                            temp.append($1.place);
                            temp.append("\n");
                            temp.append($3.code);
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup("");
                    }
        |           Var
                    {
                            std::string temp;
                            temp.append($1.code);
                            if($1.arr){
                                    temp.append(".[]| ");
                            }
                            else{
                                    temp.append(".|");
                            }
                            temp.append($1.place);
                            temp.append("\n");
                            $$.code = strdup(temp.c_str());
                            $$.place = strdup("");
                    }
        ;
//changed identifiers to Idents
Var:                Ident
                     {
                             std::string temp;
                             std::string ident = $1.place;
                             if(funcs.find(ident) == funcs.end() && varTemp.find(ident) == varTemp.end()){
                                     printf("Identifier %s is not declared. \n", ident.c_str());
                             }
                             else if(arrSize[ident] > 1){
                                     printf("Did not provide index for array Identifier %s\n", ident.c_str());
                             }
                             $$.code = strdup("");
                             $$.place = strdup(ident.c_str());
                             $$.arr = false;
                     }
//changed identifiers to Idents
        |            Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET
                     {
                             std::string temp;
                             std::string ident = $1.place;
                             if( funcs.find(ident) == funcs.end() && varTemp.find(ident) == varTemp.end()){
                                     printf("Identifier %s is not declared. \n", ident.c_str());

                             }
                             else if(arrSize[ident] > 1){
                                     printf("Did not provide index for array Identifier %s\n", ident.c_str());
                             }
                             temp.append($1.place);
                             temp.append(", ");
                             temp.append($3.place);
                             $$.code = strdup($3.code);
                             $$.place = strdup(temp.c_str());
                             $$.arr = true;
                     }
        
%%

void yyerror(const char *msg){
        extern int yylineno;
        extern char* yytext;
        printf("%s on line %d at char %d at symbol \"%s\"\n",msg, yylineno,currPos,yytext);
        exit(1);
}
std::string new_temp(){
    std::string t = 't' + std::to_string(tempCount);
    tempCount++;
    return t;
}
std::string new_label(){
    std::string l = "L" + std::to_string(labelCount);
    labelCount++;
    return l;
}