%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include "parser.tab.h"
    void yyerror(char* );
    int yylex();
    void yyerror();
    extern int yylineno;
    extern FILE *yyin;
    extern FILE *yyout;
    extern int line_number;
    ///TODOS
    // ''' 1- symbol table: 
    // store enum value 
    // 2- error handling:
    //   type checking ,const value change, scope checking, function call checking,
    //  function return type checking + feh return wla la2 aslan , function argument checking, function
    //   argument type checking, function argument count checking, function argument order checking '''
    //--------------------- Symbol Table -----------------
    struct Entry {
        int id,intValue,scope;
        char* name , value;
        float floatValue;
        bool boolValue;
        char* strValue; 
        // struct Type dataType;
        char* type; // var,const, func
        char* dataType; // int, float, bool, string (for func: return type)
        // list of arguments stored as IDs of them symbol table
        int argList[100];
        int argCount;
        int declareLine;
        int isConst, isArg, isUsed, isInit;
    };
    struct Entry symbolTable[500];
    int st_index=0;
    int in_loop=0;
    //-- symbol table functions:  st_functionName()
    void st_insert(char* data_type, char* name, char* type, int is_arg);
    void st_print();
    int is_exist(char* name);
    //--- handle scope
    int scope_index=0;
    int block_number=0;
    int scope_stack[500]; // stack of scopes (for nested scopes to store block number)
    void scope_start();
    void scope_end();

%}

%union { 
 int num; /* integer value */ 
 char* str; 
 float float_val;
 bool bool_val;
}

%code requires
{
#include<stdbool.h>
}

%token INT FLOAT BOOL STRING VOID IF FOR WHILE BOOL_LITERAL DIV GT LT EQ SEMICOLON PLUS SUB MUL STRING_LITERAL CONSTANT POW ELSE DO ENUM
%token EQUALITY NEG_EQUALITY
%token SWITCH CASE
%token LOGIC_AND LOGIC_OR LOGIC_NOT
%token DIGIT IDENTIFIER FLOAT_DIGIT
%left LOGIC_AND LOGIC_OR
%left EQUALITY NEG_EQUALITY
%right LOGIC_NOT
%right POW
%left MUL
%left DIV
%left PLUS
%left SUB
%right EQ
%right GT
%right LT

%type <str> INT FLOAT BOOL STRING VOID CONSTANT IDENTIFIER TYPE STRING_LITERAL ENUM
%type <float_val> FLOAT_DIGIT
%type <num> DIGIT
%type <bool_val> BOOL_LITERAL


//leave those as they are please, their absence wont hurt your memory as long as you restart your laptop once every while.
//they are just handlers for the memory leak problem of bison, and I still don't know how to make them work
//%destructor { } <str>
//%destructor { free ($$); } <*>
//%destructor { free ($$); printf ("%d", @$.first_line); } INT FLOAT BOOL STRING VOID IF FOR WHILE BOOL_LITERAL DIV GT LT EQ SEMICOLON PLUS SUB MUL STRING_LITERAL CONSTANT POW ELSE DO ENUM EQUALITY NEG_EQUALITY SWITCH CASE LOGIC_AND LOGIC_OR LOGIC_NOT DIGIT IDENTIFIER FLOAT_DIGIT
//%destructor { printf ("Discarding tagless symbol.\n"); } <>


%%
PROGRAM:                                                    
                PROGRAM STATEMENT                           {printf("\n ----> Parsing Succesful :D <---- \n");}        
                |
                ;

STATEMENT:
                DECLARATION_STT
                | FUNC_DECLARATION_STT                      {printf("#[Parsed_Func_Declaration]# ");}
                | assignmentSTT
                | EXPRESSION SEMICOLON
                | IF_STT                                    {printf("#[Parsed_If_STT]# ");}
                | WHILE_STT                                 {printf("#[Parsed_While_LOOP]# ");}
                | FOR_STT                                   {printf("#[Parsed_For_LOOP]# ");}
                | DO_WHILE_STT                              {printf("#[Parsed_DO_WHILE_LOOP]# ");}
                | SWITCH_STT                                {printf("#[Parsed_SWITCH_STT]# ");}
                | ENUM_DECLARATION_STT                      {printf("#[Parsed_Enum_Declaration]# ");}
                | BLOCK
                | error SEMICOLON                           {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}//Error handler using ; as a delimiter
                | error '}'                                 {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}//Error handler using ; as a delimiter
                | error ')'                                 {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}//Error handler using ; as a delimiter
                ;

/*
| MATCHED_IF_STT                            {printf("#[Parsed_Matched_If_STT]# ");}
*/

TYPE:
                INT { $$ = "int"; }
                | FLOAT { $$ = "float"; }
                | BOOL  { $$ = "bool"; }
                | STRING { $$ = "string"; }
                ;

DECLARATION_STT:                                                            
                TYPE IDENTIFIER {st_insert($1, $2,"var",0); }   DECLARATION_TAIL            {printf("#[Parsed_Declaration]# ");}
                | TYPE CONSTANT {st_insert($1, $2,"const",0);}  DECLARATION_TAIL            {printf("#[Parsed_CONST_Declaration]# "); }
                | error IDENTIFIER    SEMICOLON                                             {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}//Error handler
                | error CONSTANT      SEMICOLON                                             {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}//Error handler
                | TYPE IDENTIFIER IDENTIFIER SEMICOLON                                      {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",$3, yylineno);}
                ;


DECLARATION_TAIL:
                EQ EXPRESSION   SEMICOLON
                | error EXPRESSION   SEMICOLON                                              {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}//Error handler
                | EQ error SEMICOLON                                                        {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}//Error handler
                | SEMICOLON
                | EQ EXPRESSION                                                       {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); } '}'
                | EQ EXPRESSION                                                       {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); } ')'
                | EQ EXPRESSION                                                       {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); } RES_WORD
                //|                                                                     {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);} '}'
                | error RES_WORD                                                           {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);} 
                ;





SWITCH_STT:
                SWITCH IDENTIFIER ':' '{' CASES '}'
                | ERRONOUS_SWITCH_STT
                //todo, handle unclose parenthesis for switch stt
                ;

CASES:
                CASE EXPRESSION ':' BLOCK CASES
                | ERRONOUS_CASES
                |
                ;

ERRONOUS_CASES:
                error EXPRESSION                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);} ':' BLOCK CASES     
                | CASE EXPRESSION ':' error      {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);} CASES         
                ;

ERRONOUS_SWITCH_STT:
                SWITCH error                    {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}                            ':' '{' CASES '}'      
                | SWITCH IDENTIFIER error       {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }               ':'  '{' CASES '}'  
                | SWITCH IDENTIFIER error       {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);} '{' CASES '}'
                | SWITCH IDENTIFIER ':' error   {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}                                   CASES '}'   
                //| SWITCH IDENTIFIER ':' '{' CASES error {printf("\n\n=====ERROR====\n unclosed '}' for switch statement at line %d\n\n", yylineno);}    
                ;











FUNC_DECLARATION_STT:
                ERRONOUS_FUNC_DECLARATION_STT                                       BLOCK
                | TYPE IDENTIFIER '(' ARGS ')'   {st_insert($1, $2,"func",0);}      BLOCK                                   
                | VOID IDENTIFIER '(' ARGS ')'   {st_insert("void", $2,"func",0);}  BLOCK 
                | TYPE IDENTIFIER '(' ')'        {st_insert($1, $2,"func",0);}      BLOCK                                   
                | VOID IDENTIFIER '(' ')'        {st_insert("void", $2,"func",0);}  BLOCK 
                ;

ERRONOUS_FUNC_DECLARATION_STT:
                TYPE IDENTIFIER                     {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, $2);}                    ARGS ')'       {st_insert($1, $2,"func",0);} 
                | TYPE IDENTIFIER '(' ARGS  '{'     {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, $2); yyclearin;                          st_insert($1, $2,"func",0);} 
                | VOID IDENTIFIER                   {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, $2);}                    ARGS ')'       {st_insert($1, $2,"func",0);} 
                | VOID IDENTIFIER '(' ARGS  '{'     {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, $2); yyclearin;                          st_insert($1, $2,"func",0);} 
                | TYPE IDENTIFIER IDENTIFIER        {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}  '(' ARGS ')'   {st_insert($1, $2,"func",0);}      
                | VOID IDENTIFIER IDENTIFIER        {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}  '(' ARGS ')'   {st_insert($1, $2,"func",0);}      
                | TYPE IDENTIFIER '(' ARGS error    {printf("\n\n=====ERROR====\n unexpected token '%s' in argument list of function declaration at line %d\n\n", yylval, yylineno);}')'            {st_insert($1, $2,"func",0);}      
                ;

ARGS:
                ARG_DECL ',' ARGS
                | ARG_DECL
                | ERRONOUS_ARGS
                ;
ERRONOUS_ARGS:
                ',' ARGS                   {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
                ;
ARG_DECL:
                TYPE IDENTIFIER                             {st_insert($1, $2,"var",1);}
                //| error IDENTIFIER              {printf("\n\n=====ERROR====\n erronous argument declaration in function declaration at line %d\n\n", yylineno);}
                ;






ENUM_DECLARATION_STT:
                ENUM IDENTIFIER  '{' ENUM_HELPER '}'          { st_insert("enum" , $2, "var" , 0); }
                | ERRONOUS_ENUM_DECLARATION_STT
                ;
ENUM_HELPER     : ENUM_ARGS | ENUM_DEFINED_ARGS;
ENUM_ARGS:
                IDENTIFIER ',' ENUM_ARGS
                | IDENTIFIER
                ;
ENUM_DEFINED_ARGS:
                IDENTIFIER EQ EXPRESSION ',' ENUM_DEFINED_ARGS
                | IDENTIFIER EQ EXPRESSION
                ;
ERRONOUS_ENUM_DECLARATION_STT:
                ENUM error '{' ENUM_HELPER '}'              {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);}
                | ENUM IDENTIFIER ENUM_HELPER '}'           {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);}
                //TODO unclosed parenthesis
                | ENUM IDENTIFIER '{' error '}'             {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);}
                ;




IF_STT:
                IF EXPRESSION ':' BLOCK
                | IF EXPRESSION ':' BLOCK ELSE error '}'      {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);}
                | IF EXPRESSION ':' BLOCK ELSE BLOCK
                | IF EXPRESSION                               {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}        BLOCK
                | IF       ':'                                {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);} BLOCK
                | IF EXPRESSION ':' error '}'                 {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);}
                
                //TODO handle opened parenthesis but not closed
                ;


WHILE_STT:
                WHILE EXPRESSION ':' BLOCK
                | ERRONOUS_WHILE_STT  
                ;

ERRONOUS_WHILE_STT:
                WHILE error ':'                               {printf("\n\n=====ERROR====\n Missing expression for the WHILE loop at line %d\n\n", yylineno);}  BLOCK
                | WHILE EXPRESSION                            {printf("\n\n=====ERROR====\n Missing ':' for the WHILE loop at line %d\n\n", yylineno);}         BLOCK
                | WHILE EXPRESSION ':' error '}'                 {printf("\n\n=====ERROR====\n Missing '{' for the WHILE loop at line %d\n\n", yylineno);}
                ;


DO_WHILE_STT:
                DO BLOCK WHILE '(' EXPRESSION ')'
                ;


FOR_STT:
                FOR '(' {in_loop = 1;} STATEMENT STATEMENT STATEMENT ')'{in_loop = 0;} BLOCK 
                ;


assignmentSTT:
                IDENTIFIER EQ EXPRESSION SEMICOLON          {printf("#[Parsed_Assignment]# ");}
                ;


BLOCK:
                '{' {scope_start();} PROGRAM '}' {scope_end();}                     {printf("#[Parsed_Block]# ");}
                //| '{' PROGRAM error                                         {printf("\n=====ERROR====\n Missing closing parenthesis '{' at line %d\n", yylineno);}//Error handler
                ;



FUNC_CALL:
                IDENTIFIER '(' USED_ARGS ')'            {printf("#[Parsed_Func_Call]# ");}
                | IDENTIFIER error ')'                  {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}//Error handler
                //| IDENTIFIER '(' USED_ARGS error        {printf("\n=====ERROR====\n unclosed function parenthesis 'case' at line %d\n", yylineno);}//Error handler
                ;
USED_ARGS:
                EXPRESSION ',' USED_ARGS
                | error ',' USED_ARGS                   {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}//Error handler
                | EXPRESSION
                |
                ;


EXPRESSION:
                IDENTIFIER
                | DIGIT { symbolTable[st_index-1].intValue= $1 ;}
                | FLOAT_DIGIT { symbolTable[st_index-1].floatValue= $1 ;}
                | BOOL_LITERAL  { symbolTable[st_index-1].boolValue= $1 ;}
                | STRING_LITERAL  { symbolTable[st_index-1].strValue= $1 ;}
                | CONSTANT
                | EXPRESSION PLUS PLUS
                | EXPRESSION SUB SUB
                | EXPRESSION PLUS EXPRESSION
                | EXPRESSION SUB EXPRESSION
                | EXPRESSION MUL EXPRESSION
                | EXPRESSION DIV EXPRESSION
                | EXPRESSION POW EXPRESSION
                | COMPARISONSTT
                | FUNC_CALL                                 
                | '(' EXPRESSION ')'
                ;




COMPARISONSTT:
                EXPRESSION GT EXPRESSION
                | EXPRESSION LT EXPRESSION
                | EXPRESSION LT EQ EXPRESSION
                | EXPRESSION GT EQ EXPRESSION
                | EXPRESSION EQUALITY EXPRESSION
                | EXPRESSION NEG_EQUALITY EXPRESSION
                | EXPRESSION LOGIC_AND EXPRESSION
                | EXPRESSION LOGIC_OR EXPRESSION
                | LOGIC_NOT EXPRESSION
                | ERRONOUS_COMPARISONSTT
                ;

ERRONOUS_COMPARISONSTT:
                error GT EXPRESSION                                 {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
                | EXPRESSION GT error   %prec GT                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
                | error LT EXPRESSION                               {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
                | EXPRESSION LT error   %prec LT                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
                | error EQUALITY EXPRESSION                         {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
                | EXPRESSION EQUALITY error   %prec EQUALITY        {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
                | error NEG_EQUALITY EXPRESSION                     {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
                | EXPRESSION NEG_EQUALITY error   %prec NEG_EQUALITY{printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
                | LOGIC_NOT error   %prec EQ                        {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
                | error LOGIC_AND EXPRESSION                        {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
                | EXPRESSION LOGIC_AND error   %prec LOGIC_AND      {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
                | error LOGIC_OR EXPRESSION                         {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
                | EXPRESSION LOGIC_OR error   %prec LOGIC_OR        {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
                | error LT EQ EXPRESSION                            {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
                | EXPRESSION LT EQ error   %prec LT                 {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
                | error GT EQ EXPRESSION                            {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
                | EXPRESSION GT EQ error   %prec GT                 {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
                //| EXPRESSION error EXPRESSION   %prec GT          {printf("\n\n=====ERROR====\n Missing or invalid operator at line %d\n\n", yylineno);}
                ;
                



RES_WORD:
                INT | FLOAT| BOOL| STRING| VOID| IF| FOR| WHILE|  CONSTANT | ELSE | DO| ENUM| SWITCH| CASE;






//IDENTIFIER : error {printf("\n=====ERROR====\n MISSING identifier at line %d\n", yylineno);} | IDENTIFIER;
//INT: error {printf("\n=====ERROR====\n MISSING identifier TYPE at line %d\n", yylineno);} | INT1;
//FOR: error {printf("\n=====ERROR====\n MISSING for at line %d\n", yylineno);} | FOR1;

%%



//------------------------------------------ FUNCTIONS ---------------------------------------------
void yyerror(char *s) { 
 fprintf(stderr, "line %d: %s\n", yylineno, s); 
} 
int yywrap()
{
    return 1;
}
//------------------------------------------ SYMBOL TABLE---------------------------------------------
int is_exist(char* name){
    for (int i = 0; i < st_index; i++){
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope_index){
            return 1;
        }
    }
    return 0;
}
//-------------------------------------- INSERT IN SYMBOL TABLE  ----------------------------------I
void st_insert(char* data_type, char* name, char* type ,int is_arg ) {
    printf("##############################################");
    //------ create new entry
    struct Entry newEntry ;
    //----- check if name is already in symbol table
    if (is_exist(name) == 1){
        printf("\n !!!!!!!!!!!! Error: %s is already declared in this scope !!!!!!!!!!!\n", name);
        exit(1);
    }
    //------ set new entry values
    newEntry.name = name;
    newEntry.dataType = data_type;
    newEntry.declareLine = line_number;
    newEntry.type = type;
    newEntry.id = st_index;
    newEntry.isArg = is_arg;
    //----- set scope (if it's an argument, scope is the next scope)
    if (is_arg == 1 || in_loop == 1){ newEntry.scope = block_number+1;}
    else {newEntry.scope = scope_stack[scope_index];}
    //------ if it's a function, set argCount and argList
    if ( strcmp(type, "func") == 0){
        int j =0;        
        for(int i=0; i<st_index; i++) {
            if ( symbolTable[i].isArg  && symbolTable[i].scope == (block_number +1)){
                newEntry.argList[j] = symbolTable[i].id;
                j++;
            }
            }
            newEntry.argCount = j;
    }
    //------ insert new entry to symbol table
    symbolTable[st_index] = newEntry;
    st_index++; // increment symbol table index
}
//---------------------------------- PRINT SYMBOL TABLE ----------------------------------------------------
void st_print() {
    //----- write symbol table to file
    FILE *fp = fopen("symbol_table.txt", "w");
    //----- check if file is opened
    if(fp == NULL) {
        printf("can't open symbol_table.txt file!\n");
        exit(1);
    }
    //----- write symbol table header
    fprintf(fp, "ID\t|Name\t\t|Type\t|DataType\t|Line\t|Scope\t|Value\t\t|Args\n");
    fprintf(fp, "-------------------------------------------------------------------------------------------\n");
    //----- write symbol table entries
    for(int i=0; i< st_index; i++) {
        struct Entry *entry = &symbolTable[i];
        fprintf(fp, "%d\t|%s\t|%s\t|%s\t\t|%d\t|%d\t|", entry->id, entry->name,entry->type, entry->dataType, entry->declareLine, entry->scope);
        //---- store value of entry
        if (strcmp(entry->dataType,"int")==0) {fprintf(fp, "%d\t\t|", entry->intValue);}
        else if (strcmp(entry->dataType,"float")==0) {fp, fprintf(fp, "%f\t\t|", entry->floatValue);}
        else if (strcmp(entry->dataType,"bool")==0) {fprintf(fp,"%s\t\t|", entry->boolValue ? "true" : "false");}
        else if (strcmp(entry->dataType,"string")==0) {fprintf(fp, "%s\t\t|", entry->strValue);}
        else {fprintf(fp, "-|");}
        //---- print arguments of functions
        if (strcmp(entry->type, "func") == 0)
        {
            for (int j = 0; j < entry->argCount; j++)
            {
            fprintf(fp, "%d,", entry->argList[j]);
            }
        }
        else {fprintf(fp, "-");}
       
        fprintf(fp, "\n");
    }
    fclose(fp);
}
//------------------------------------------- HANDLE SCOPE -----------------------------------------
void scope_start(){
    //----- increment block number and scope index
    block_number++;
    scope_index++;
    scope_stack[scope_index] = block_number;
}
void scope_end(){
    scope_index--; // decrement scope index
}
//------------------------------------------- MAIN -------------------------------
int main(int argc, char *argv[])
{ 
    yyin = fopen(argv[1], "r");
    yyparse();
    st_print();
    return 0;
}