%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    // include bool type
    #include <stdbool.h>
    // #include "../SymbolTable/SymbolTableEntry.h"
    #include "parser.tab.h"
    void yyerror(char* );
    int yylex();
    void yyerror();
    extern FILE *yyin;
    extern FILE *yyout;
    extern int line_number;
    //TODOS: store value , handle scope , test and check 
    // extern enum yytokentype ;
    //---------------------- data types -----------------
    // typedef enum {int, float , bool,} Type;
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
 char* str; /* symbol table index */ 
 float float_val;
 bool bool_val;
}

%code requires
{
#include<stdbool.h>
}

%token INT FLOAT BOOL STRING IF FOR WHILE BOOL_LITERAL DIV GT LT EQ SEMICOLON PLUS SUB MUL STRING_LITERAL CONSTANT POW ELSE DO ENUM
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


%type <str> INT FLOAT BOOL STRING CONSTANT IDENTIFIER TYPE STRING_LITERAL
%type <float_val> FLOAT_DIGIT
%type <num> DIGIT
%type <bool_val> BOOL_LITERAL
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
                TYPE IDENTIFIER {st_insert($1, $2,"var",0); printf("\n=>>>>> inserted");}   DECLARATION_TAIL SEMICOLON           {printf("#[Parsed_Declaration]# ");}
                | TYPE CONSTANT {st_insert($1, $2,"const",0);} DECLARATION_TAIL SEMICOLON   {printf("#[Parsed_CONST_Declaration]# "); }
                ;

DECLARATION_TAIL:
                EQ EXPRESSION
                |
                ;

SWITCH_STT:
                SWITCH IDENTIFIER ':' '{' CASES '}'
                ;
CASES:
                CASE EXPRESSION ':' BLOCK CASES
                |
                ;

FUNC_CALL:
                IDENTIFIER '(' USED_ARGS ')'            {printf("#[Parsed_Func_Call]# ");}
                ;
USED_ARGS:
                EXPRESSION ',' USED_ARGS
                | EXPRESSION
                |
                ;

FUNC_DECLARATION_STT:
                TYPE IDENTIFIER '(' ARGS ')' {st_insert($1, $2,"func",0);} BLOCK 
                ;

ARGS:
                ARGS ',' ARG_DECL
                | ARG_DECL
                |
                ;

ARG_DECL:
                TYPE IDENTIFIER {st_insert($1, $2,"var",1);}
                ;

ENUM_DECLARATION_STT:
                ENUM IDENTIFIER '{' ENUM_ARGS '}'
                | ENUM IDENTIFIER '{' ENUM_DEFINED_ARGS '}'
                ;
ENUM_ARGS:
                IDENTIFIER ',' ENUM_ARGS
                | IDENTIFIER
                ;
ENUM_DEFINED_ARGS:
                IDENTIFIER EQ EXPRESSION ',' ENUM_DEFINED_ARGS
                | IDENTIFIER EQ EXPRESSION
                ;

IF_STT:
                IF EXPRESSION ':' BLOCK
                | IF EXPRESSION ':' BLOCK ELSE BLOCK
                ;

WHILE_STT:
                WHILE EXPRESSION ':' BLOCK
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
                ;

EXPRESSION:
                IDENTIFIER
                | DIGIT {  symbolTable[st_index-1].intValue= $1 ;}
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
                ;
%%
//------------------------------------------ FUNCTIONS ---------------------------------------------
void yyerror(char* s)
{
    fprintf(stderr, "%s\n", s);
};
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
        printf("=======================================FUNC \n");
        printf("block number: %d\n", block_number);
        printf("name: %s\n", name);
        // print bool value
        
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
    fprintf(fp, "ID\t|Name\t|Type\t|DataType\t|Line\t|Scope\t|Value\t\t|Args\n");
    fprintf(fp, "----------------------------------------------------------\n");
    //----- write symbol table entries
    for(int i=0; i< st_index; i++) {
        struct Entry *entry = &symbolTable[i];
        fprintf(fp, "%d\t|%s\t|%s\t|%s\t\t|%d\t|%d\t|", entry->id, entry->name,entry->type, entry->dataType, entry->declareLine, entry->scope);
        //---- store value of entry
        if (strcmp(entry->dataType,"int")==0) {fprintf(fp, "%d\t\t|", entry->intValue);}
        else if (strcmp(entry->dataType,"float")==0) {fprintf(fp, "%s\t\t|", entry->floatValue);}
        else if (strcmp(entry->dataType,"bool")==0) {fprintf(fp, "%d\t\t|", entry->boolValue);}
        else if (strcmp(entry->dataType,"string")==0) {fprintf(fp, "%s\t\t|", entry->strValue);}
        else {fprintf(fp, "-");}
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
    //  TODO: store name of scope instead of number
    block_number++;
    scope_index++;
    // int  scope_index_temp= block_number;
    scope_stack[scope_index] = block_number;
    // printf("\n scope start \n");
}
void scope_end(){
    // scope_stack[scope_index] = -1; // end of scope
    scope_index--;
    // block_number--;
}
//------------------------------------------- MAIN -------------------------------
int main(int argc, char *argv[])
{ 
    yyin = fopen(argv[1], "r");
    yyparse();
    st_print();
    return 0;
}