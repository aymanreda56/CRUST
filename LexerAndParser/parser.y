%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    // #include "../SymbolTable/SymbolTableEntry.h"
    #include "parser.tab.h"
    void yyerror(char* );
    int yylex();
    void yyerror();
    extern FILE *yyin;
    extern FILE *yyout;

    // extern enum yytokentype ;
    //---------------------- data types -----------------
    // typedef enum {int, float , bool,} Type;
    //--------------------- Symbol Table -----------------
    struct Entry {
        char* name , value;
        char* scope;
        // struct Type dataType;
        char* type; // var, func, class
        char* dataType; // int, float, bool, string
        int delcareLine;
    };
    //SymbolTableEntry* symbolTable = new SymbolTableEntry()
    // const int maxSize=500;
    struct Entry symbolTable[500];
    int st_index=0;
    //-- symbol table functions:  st_functionName()
    void st_insert(char* data_type, char* name, int is_const);
    void st_print();

    // BOOL st_isExist();


%}

%union { 
 int num; /* integer value */ 
 char* str; /* symbol table index */ 
}

%token INT FLOAT BOOL STRING IF FOR WHILE BOOL_LITERAL DIV GT LT EQ SEMICOLON PLUS SUB MUL STRING_LITERAL CONSTANT POW ELSE DO ENUM
%token EQUALITY NEG_EQUALITY
%token SWITCH CASE
%token LOGIC_AND LOGIC_OR LOGIC_NOT
%token DIGIT IDENTIFIER
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


%type <str> INT FLOAT BOOL STRING CONSTANT IDENTIFIER TYPE

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
                TYPE IDENTIFIER DECLARATION_TAIL SEMICOLON           {printf("#[Parsed_Declaration]# "); st_insert($1, $2,0);}
                | TYPE CONSTANT DECLARATION_TAIL SEMICOLON           {printf("#[Parsed_CONST_Declaration]# "); st_insert($1, $2,1); }
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
                TYPE IDENTIFIER '(' ARGS ')' BLOCK
                ;

ARGS:
                ARGS ',' ARG_DECL
                | ARG_DECL
                |
                ;

ARG_DECL:
                TYPE IDENTIFIER
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
                FOR '(' STATEMENT STATEMENT STATEMENT ')' BLOCK
                ;

assignmentSTT:
                IDENTIFIER EQ EXPRESSION SEMICOLON          {printf("#[Parsed_Assignment]# ");}
                ;

BLOCK:
                '{' PROGRAM '}'                            {printf("#[Parsed_Block]# ");}
                ;

EXPRESSION:
                IDENTIFIER
                | DIGIT
                | BOOL_LITERAL
                | STRING_LITERAL
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


void yyerror(char* s)
{
    fprintf(stderr, "%s\n", s);
};
int yywrap()
{
    return 1;
}
void st_insert(char* data_type, char* name, int is_const){
    //create new entry
    struct Entry newEntry ;
    newEntry.name = "test";
    newEntry.dataType = data_type;
    symbolTable[st_index] = newEntry;
    st_index++;
    // print with new line

    printf(data_type);
    printf(name);
   
}
void st_print() {
    // write symbol table to file
    FILE *fp = fopen("/symbol_table.txt", "w");
    if(fp == NULL) {
        printf("can't open symbol_table.txt file!\n");
        exit(1);
    }
    // fprintf(fp, "\nName\tData Type\tScope\tType\tLine\n");
    fprintf(fp, "\nData Type\n");

    for(int i=0; i<st_index; i++) {
        struct Entry *entry = &symbolTable[i];
        fprintf(fp, "%s\n", entry->dataType);
        // fprintf(fp, "%4s\t%9s\t%5d\t%4c\t%4d\t%3d\t%10d\n", entry->name, entry->dataType, entry->token_scope, entry->type, entry->declareLine); 
    }
}

int main(int argc, char *argv[])
{ 
    yyin = fopen(argv[1], "r");
    yyparse();
    st_print();
    return 0;
}