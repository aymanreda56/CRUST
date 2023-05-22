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
    extern int yy_flex_debug;
    // TODO make data type of enum int and store its enum name  (try it with switc case)
    //TODO  add float and int error DONE
    //TODO if you have 2 x in diffrent scopes and both are in valid scopes take the closet (DONE)
    //TODO unused variables (DONE)
    //TODO type mismatch lel < > w kda
    //TODO division by zero
    //TODO check err.txt err2.txt err3.txt
    ///TODOS
    // ''' 1- symbol table: 
    // store enum value , check el type bta3o w kda 
    // 2- error handling:
    //   type checking (DONE) ,const value change, undeclared variables (DONE), used before assign (DONE)
    //, scope checking (DONE), function call checking (DONE),
    //  function return type checking+ feh return wla la2 aslan ,function
    //   argument type checking (count), function argument count checking (count), function argument order checking '''
    //--------------------- Symbol Table -----------------
    struct enumEntry{
        char* keys[100];
        int values [100];
    };
    struct Entry {
        int id,intValue,scope;
        char* name , value;
        float floatValue;
        bool boolValue;
        char* strValue; 

        struct enumEntry enumValue;
        char* type; // var,const, func, enum_arg, var_enum
        char* dataType; // int, float, bool, string (for func: return type)
        // list of arguments stored as IDs of them symbol table
        int argList[100];
        int argEnum[100]; // store indexes of the enum args in the symbol table
        int argCount;
        int declareLine;
        int isConst, isArg, isUsed, isInit, outOfScope;
    };
    struct Entry symbolTable[500]; //TODO: need to be dynamic?
    int st_index=0;
    int in_loop=0;
    int assign_index=-1;
    int func_index=-1; // to check return type of the function
    int is_param=0;
    int arg_count=0;
    int called_func_index=0;
    int is_enum=0;
    char* enum_keys[100];
    int enum_values [100];
    int enum_arg_count=0;
    int is_changed=1; // default is 1,
    int return_exist=0;
    //-- symbol table functions:  st_functionName()
    int st_insert(char* data_type, char* name, char* type, int is_arg);
    void st_print();
    void st_log();
    void clear_logs();
    int is_exist(char* name);
    int lookup(char* name, int is_assignment);
    //--- handle scope
    int scope_index=0;
    int block_number=0;
    int scope_stack[500]; // stack of scopes (for nested scopes to store block number)
    void scope_start();
    void scope_end();
    //--- handle errors
    void check_type( int i);
    void unused_print() ;
    void assign_int( int d , int i);
    void assign_str( char* s , int i);
    // void assign_bool( bool b , int i);
    // void assign_float( float f , int i);
    void assign_enum (int i, char* enum_name, char* key);
    void arg_count_check( int i);



//____________________________________________________________ CODE GEN ____________________________________________________________________
    #include <fcntl.h>             //for creating file
    #include <errno.h>             //for checking for file
    int codeGen = 1;
    char* VirtualStack [1000];
    int VirtualSP = -1;
    int tempNumber = 0;
    int labelNumber = 0;
    int endlabelNumber=0;
    char temp_label[50] = "L";
    char temp_endlabel[50] = "END";
    char* popVStack();
    char temp_var[50] = "t";
    void pushVStack(char* s);
    void CodeGenAss();
    void CodeGenOp(char* operator);
    void printIF();
    void printLLVM(char* s);
    char* makeLabel();
    char* makeEndLabel();
    void printWHILE();
    void controlTerminator(int isWhile);
    void CodeGenLogical();
    void StAssPush(char* s);
    void StAssPrint(char* s, int ind);
    int SMLabel = 0;
    int SMLabel_Else = 0;
    int SMLabel_End = 0;
    void StAssJmp(char* jmp, char* jmpName,int* num, int inc, int noNum);
    void StAssPrintLBL(int isLBL, int inc);
    void StAssForHeader();
    void StAssForMiddle();
    int ForHeaderLabel = 0;
    int ForHelperLabel = 0;
    char IdentifierHolder[10];
    char* argumentList[20];
    int argPointer = 0;
    void popArgs();
    int enumCNT = 1;
    void prepend(char* s, const char* t)    {size_t len = strlen(t);memmove(s + len, s, strlen(s) + 1);memcpy(s, t, len);}
    char switcher[50];
    void pErr(int num);
    void sErr(int num);
    //int* linenoPTR = &yylineno;
//==================================================================================================================================================

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

%token INT FLOAT BOOL STRING VOID IF FOR WHILE BOOL_LITERAL DIV GT LT EQ SEMICOLON PLUS SUB MUL STRING_LITERAL CONSTANT POW ELSE DO ENUM RETURN DEFAULT
%token EQUALITY NEG_EQUALITY
%token SWITCH CASE
%token LOGIC_AND LOGIC_OR LOGIC_NOT
%token DIGIT IDENTIFIER FLOAT_DIGIT
%left LOGIC_AND LOGIC_OR
%left EQUALITY NEG_EQUALITY
%right LOGIC_NOT
%right POW
%left PLUS
%left SUB
%left MUL
%left DIV
%right EQ
%right GT
%right LT
%left '{'
%left '}'


%type <str> INT FLOAT BOOL STRING VOID CONSTANT IDENTIFIER TYPE STRING_LITERAL ENUM PLUS
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
                | ENUM_CALL_STT                             {printf("#[Parsed_Enum_USAGE]# ");}
                | BLOCK
                | RETURN_STT SEMICOLON
                | error SEMICOLON                           {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}//Error handler using ; as a delimiter
                | error '}'                                 {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}//Error handler using ; as a delimiter
                | error ')'                                 {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}//Error handler using ; as a delimiter
                ;

/*
| MATCHED_IF_STT                            {printf("#[Parsed_Matched_If_STT]# ");}
*/

TYPE:
                INT         { $$ = "int";   }
                | FLOAT     { $$ = "float"; }
                | BOOL      { $$ = "bool";  }
                | STRING    { $$ = "string";}
                ;

DECLARATION_STT:                                                            
                TYPE    IDENTIFIER  {st_insert($1, $2,"var",0);   assign_index= st_index-1; strcpy(IdentifierHolder, $2);}   DECLARATION_TAIL            {printf("#[Parsed_Declaration]# "); }
                | TYPE  CONSTANT    {st_insert($1, $2,"const",0); assign_index= st_index-1; strcpy(IdentifierHolder, $2);}   DECLARATION_TAIL            {printf("#[Parsed_CONST_Declaration]# "); }
                | error IDENTIFIER    SEMICOLON                                             {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);pErr(yylineno);}//Error handler
                | error CONSTANT      SEMICOLON                                             {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);pErr(yylineno);}//Error handler
                | TYPE  IDENTIFIER    IDENTIFIER SEMICOLON                                  {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",$3, yylineno);pErr(yylineno);}
                ;


DECLARATION_TAIL:
                EQ EXPRESSION  SEMICOLON                                                    {StAssPush(strdup(IdentifierHolder)); StAssPrint("OVER", 1); StAssPrint("STORE", 1); StAssPrint("DROP", 1);}
                | error EXPRESSION   SEMICOLON                                              {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);pErr(yylineno);}//Error handler
                | EQ error SEMICOLON                                                        {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);pErr(yylineno);}//Error handler
                | SEMICOLON 
                | EQ EXPRESSION                                                       {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);} '}'
                | EQ EXPRESSION                                                       {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);} ')'
                | EQ EXPRESSION                                                       {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);} RES_WORD
                //|                                                                     {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);pErr(yylineno);} '}'
                //| error RES_WORD                                                           {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);pErr(yylineno);} 
                ;


RETURN_STT:
                RETURN                          {int dum = 0;StAssPrint("POP\tPC",1);StAssJmp("JMP", "PC", &dum,0,1);}
                | RETURN {assign_index =func_index;} EXPRESSION             { return_exist = 1; StAssPrint("OVER",1);int dum = 0;StAssPrint("POP\tPC",1);StAssPrint("DNEXT", 1);StAssJmp("JMP", "PC", &dum,0,1);}
                ;
helperSWITCH:   SWITCH IDENTIFIER ':' '{' {strcpy(switcher, $2);}
                ;
SWITCH_STT:
                helperSWITCH CASES  '}' {StAssPrintLBL(0,1);}
                | ERRONOUS_SWITCH_STT
                //todo, handle unclose parenthesis for switch stt
                ;
DEFAULTCASE:
                DEFAULT ':' BLOCK {StAssJmp("JMP", "END",&SMLabel_End, 0,0); }
                | DEFAULT BLOCK {printf("\n\n=====ERROR====\n missing colon ':' at DEFAULT CASE of switch, error at line %d\n\n", yylineno); pErr(yylineno);}
                ;
CASES:
                CASE {StAssPush(switcher);} EXPRESSION {StAssPrint("EQ", 1); StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);} ':' BLOCK {StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);} CASES
                | DEFAULTCASE {printf("\n\n=====ERROR====\n DEFAULT CASE must be written at the end of the switch statement, error at line %d\n\n", yylineno); pErr(yylineno);} CASE EXPRESSION BLOCK             
                | DEFAULTCASE DEFAULTCASE                       {printf("\n\n=====ERROR====\n only 1 DEFAULT CASE is allowed in the switch statement error, at line %d\n\n", yylineno); pErr(yylineno);}
                | DEFAULTCASE
                //| ERRONOUS_CASES
                |
                ;
/* AYMAAN 7awel tesala7 DE
ERRONOUS_CASES:
                error EXPRESSION                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);pErr(yylineno);} ':' BLOCK CASES     
                | CASE EXPRESSION ':' error      {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);pErr(yylineno);} CASES         
                ;
*/
ERRONOUS_SWITCH_STT:
                SWITCH error                    {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);pErr(yylineno);}                            ':' '{' CASES '}'      
                | SWITCH IDENTIFIER error       {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); pErr(yylineno);}             ':'  '{' CASES '}'  
                | SWITCH IDENTIFIER error       {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);pErr(yylineno);} '{' CASES '}'
                | SWITCH IDENTIFIER ':' error   {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}                                   CASES '}'   
                | helperSWITCH CASES error {printf("\n\n=====ERROR====\n unclosed '}' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}    
                ;









FUNC_DECLARATION_STT:
                ERRONOUS_FUNC_DECLARATION_STT                                       BLOCK
                | TYPE IDENTIFIER '(' {char dum[10]; strcpy(dum,$2);strcat(dum,":");StAssPrint(dum, 0);} ARGS ')'   {func_index = st_insert($1, $2,"func",0); popArgs();}      BLOCK                                   
                | VOID IDENTIFIER '(' {char dum[10]; strcpy(dum,$2);strcat(dum,":");StAssPrint(dum, 0);}ARGS ')'    {func_index=st_insert("void", $2,"func",0); popArgs();}  BLOCK 
                | TYPE IDENTIFIER '(' {char dum[10]; strcpy(dum,$2);strcat(dum,":");StAssPrint(dum, 0);}')'         {func_index=st_insert($1, $2,"func",0);}                 BLOCK                                   
                | VOID IDENTIFIER '(' {char dum[10]; strcpy(dum,$2);strcat(dum,":");StAssPrint(dum, 0);}')'         {func_index=st_insert("void", $2,"func",0);}             BLOCK 
                ;

// AYMOOON  UNCOMMENT THOSE ERROR HANDLERS AND IGNORE THE RED/RED CONFLICTS, they impose zero harm whatsoever.
ERRONOUS_FUNC_DECLARATION_STT:
                TYPE IDENTIFIER                     {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, $2);pErr(yylineno);}                    ARGS ')'       {st_insert($1, $2,"func",0);} 
                //| TYPE IDENTIFIER '(' ARGS  '{'     {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, $2); yyclearin;pErr(yylineno);                          st_insert($1, $2,"func",0);} 
                //| VOID IDENTIFIER                   {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, $2);pErr(yylineno);}                    ARGS ')'       {st_insert($1, $2,"func",0);} 
                //| VOID IDENTIFIER '(' ARGS  '{'     {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, $2); yyclearin; pErr(yylineno);                         st_insert($1, $2,"func",0);} 
                //| TYPE IDENTIFIER IDENTIFIER        {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;pErr(yylineno);}  '(' ARGS ')'   {st_insert($1, $2,"func",0);}      
                //| VOID IDENTIFIER IDENTIFIER        {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;pErr(yylineno);}  '(' ARGS ')'   {st_insert($1, $2,"func",0);}      
                //| TYPE IDENTIFIER '(' ARGS error    {printf("\n\n=====ERROR====\n unexpected token '%s' in argument list of function declaration at line %d\n\n", yylval, yylineno);pErr(yylineno);}')'            {st_insert($1, $2,"func",0);}      
                ;

ARGS:
                ARG_DECL ',' ARGS
                | ARG_DECL
                | ERRONOUS_ARGS
                ;
ERRONOUS_ARGS:
                ',' ARGS                   {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);pErr(yylineno);}
                ;
ARG_DECL:
                TYPE IDENTIFIER                             {st_insert($1, $2,"var",1); char* buf=$2; argumentList[argPointer]=buf;argPointer++;}
                //| error IDENTIFIER              {printf("\n\n=====ERROR====\n erronous argument declaration in function declaration at line %d\n\n", yylineno);pErr(yylineno);}
                ;



ENUM_DECLARATION_STT:
                ENUM IDENTIFIER  '{'  { is_enum =1;} ENUM_HELPER '}'          { st_insert("enum" , $2, "var" , 0); is_enum=0; enumCNT=1;}
                | ERRONOUS_ENUM_DECLARATION_STT
                ;
ENUM_HELPER     : ENUM_ARGS | ENUM_DEFINED_ARGS;
ENUM_ARGS:

                IDENTIFIER    { StAssPush($1);char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = $1; enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++;  st_insert("int" , $1, "enum_arg" , 0); assign_int(  enum_arg_count-1,st_index-1); } ',' ENUM_ARGS  
                | IDENTIFIER  { StAssPush($1);char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = $1; enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++; st_insert("int" , $1, "enum_arg" , 0); assign_int( enum_arg_count-1,st_index-1);  }

                ;
            
ENUM_DEFINED_ARGS:

                IDENTIFIER EQ DIGIT     { StAssPush($1);char buf[10]; itoa($3,buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = $1; enum_values[enum_arg_count] = $3; enum_arg_count++ ; st_insert("int" , $1, "enum_arg" , 0); assign_int(  $3,st_index-1); } ',' ENUM_DEFINED_ARGS 
                | IDENTIFIER EQ DIGIT   { StAssPush($1);char buf[10]; itoa($3,buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = $1; enum_values[enum_arg_count] = $3; enum_arg_count++;  st_insert("int" , $1, "enum_arg" , 0); assign_int(  $3,st_index-1); }
                | IDENTIFIER EQ error ','                   {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
                | IDENTIFIER EQ FLOAT_DIGIT                 {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
                | IDENTIFIER EQ STRING_LITERAL              {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
                | IDENTIFIER EQ BOOL_LITERAL                {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
                ;

ERRONOUS_ENUM_DECLARATION_STT:
                ENUM error '{' ENUM_HELPER '}'              {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
                | ENUM IDENTIFIER ENUM_HELPER '}'           {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
                //TODO unclosed parenthesis
                | ENUM IDENTIFIER '{' error '}'             {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
                | ENUM IDENTIFIER error '{' ENUM_HELPER '}' {printf("\n\n=====ERROR====\n UnExpected IDENTIFIER in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
                ;

ENUM_CALL_STT:
                IDENTIFIER  IDENTIFIER EQ IDENTIFIER SEMICOLON { StAssPush($2);StAssPush($4);StAssPrint("STORE",1); st_insert($1 , $2, "var_enum" , 0); assign_enum(st_index-1, $1,$4); int i= lookup($1, 0); symbolTable[i].isUsed=1; }
                | IDENTIFIER IDENTIFIER SEMICOLON  { st_insert($1 , $2, "var_enum" , 0); int i= lookup($1,0); symbolTable[i].isUsed=1;}
                ;

IF_STT_HELPER:
                IF {printIF();} EXPRESSION {StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
                ;
IF_STT_HELPER1:
                ':' BLOCK                                   {controlTerminator(0);  StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
                ;

IF_STT:
                IF_STT_HELPER IF_STT_HELPER1                  {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
                | IF_STT_HELPER IF_STT_HELPER1 ELSE BLOCK     {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
                | IF_STT_HELPER IF_STT_HELPER1 ELSE error '}' {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);pErr(yylineno);}
                | IF_STT_HELPER                               {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}        BLOCK//{char*dummy; strcpy(dummy, makeEndLabel()); printLLVM(dummy); printLLVM(":\n");}
                | IF       ':'                                {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);pErr(yylineno);} BLOCK//{char*dummy; strcpy(dummy, makeEndLabel()); printLLVM(dummy); printLLVM(":\n");}
                | IF_STT_HELPER ':' error '}'                 {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
                
                //TODO handle opened parenthesis but not closed
                ;



// AYMON : ana masa7t el Error handling bta3 elWhile Loop 3shan fadelly taka we aksar elLaptop da fo2 dma8 elli katabo Bayzoooon >:(((
WHILE_STT:
                WHILE {printWHILE(); StAssPrintLBL(1, 0);} EXPRESSION {StAssJmp("JNZ", "END",&SMLabel_End, 0,0);} ':' BLOCK {StAssJmp("JMP", "LBL",&SMLabel_Else, 1,0); StAssPrintLBL(0, 1);}
                //| WHILE {printWHILE();} error ':'                    {printf("\n\n=====ERROR====\n Missing expression for the WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}  BLOCK {controlTerminator(1);}
                //| WHILE {printWHILE();} EXPRESSION                   {printf("\n\n=====ERROR====\n Missing ':' for the WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}         BLOCK {controlTerminator(1);}
                //| WHILE {printWHILE();} EXPRESSION ':' error '}'     {printf("\n\n=====ERROR====\n Missing '{' for the WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
                //TODO handle unclosed curly braces 
                ;


DO_WHILE_STT:
                DO BLOCK WHILE '(' EXPRESSION ')'
                | ERRONOUS_DO_WHILE
                ;
ERRONOUS_DO_WHILE:
                DO   error                          {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}                              WHILE '(' EXPRESSION ')'
                | DO BLOCK WHILE error              {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}               EXPRESSION ')'
                | DO BLOCK error                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}                                         '(' EXPRESSION ')'
                | DO error                          {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);} '}' WHILE '(' EXPRESSION ')'
                | DO BLOCK WHILE '{' EXPRESSION '}' {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);pErr(yylineno);}
                //| DO BLOCK {printf("\n\n=====ERROR====\n Missing While loop for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);}
                //TODO handle missing while statement, user only wrote the Do statement (we might agree that it is acceptable)
                ;


FOR_STT:
                FOR '(' {in_loop = 1;} STATEMENT {StAssForHeader();} STATEMENT {StAssForMiddle();} STATEMENT ')'{StAssPrintLBL(1,1); in_loop = 0;} BLOCK  {StAssJmp("JMP", "Label", &ForHeaderLabel,1,0); StAssPrintLBL(0,1);}
                | ERRONOUS_FOR_LOOP
                ;
ERRONOUS_FOR_LOOP:
                //FOR '(' STATEMENT ')'  {printf("\n\n=====ERROR====\n Missing a third statement inside the FOR loop at line %d\n\n", yylineno);}  BLOCK
                FOR error STATEMENT STATEMENT STATEMENT ')'            {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}  BLOCK
                | FOR '(' ';' STATEMENT STATEMENT STATEMENT ')'        {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}        BLOCK
                //TODO 7agat keteeer, ana ma5noooo2   >:(
                ;

//TODO hl m7taga a7ot call lel lookup t7t? i think yes bs kda kda da error so no need to store assign index 
//AYMON : SOLVED the conflicts
helperAssignmentRule:
                IDENTIFIER  EQ                                   {pushVStack($1); StAssPush($1); assign_index = lookup($1,1);}
                ;

assignmentSTT:
                helperAssignmentRule SEMICOLON                   {printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
                | helperAssignmentRule EXPRESSION SEMICOLON      {StAssPrint("STORE", 1); CodeGenAss();printf("#[Parsed_Assignment]# ");}
                | IDENTIFIER  error                              {pushVStack($1); assign_index = lookup($1,1); StAssPush($1);} EXPRESSION SEMICOLON     {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
                ;


BLOCK:
                '{' {scope_start();} PROGRAM '}'                              {scope_end(); printf("#[Parsed_Block]# ");}
                //| '{' PROGRAM error                                         {printf("\n=====ERROR====\n Missing closing parenthesis '{' at line %d\n", yylineno);}//Error handler
                //TODO handle opened curly braces but not closed
                ;



FUNC_CALL:
                IDENTIFIER {called_func_index = lookup($1,0); check_type(called_func_index); StAssPush("PC");} '(' { is_param =1;}  USED_ARGS { is_param =0; arg_count_check(called_func_index); arg_count=0; int dum=0; StAssJmp("JMP", $1,&dum, 0,0);}   ')' { printf("#[Parsed_Func_Call]# ");}
                | IDENTIFIER error ')'                  {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);pErr(yylineno);}//Error handler
                //| IDENTIFIER '(' USED_ARGS error        {printf("\n=====ERROR====\n unclosed function parenthesis 'case' at line %d\n", yylineno);}//Error handler
                ;
USED_ARGS:      
                EXPRESSION { arg_count++; }  ',' USED_ARGS 
                | error ',' USED_ARGS                       {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);pErr(yylineno);}//Error handler
                | EXPRESSION {arg_count++ ;}
                |
                ;


EXPRESSION:
                
                IDENTIFIER                      { int i = lookup($1,0); check_type(i); pushVStack($1); StAssPush($1);}
                | DIGIT                         { assign_int($1, assign_index) ; char numtostring[40]; itoa($1, numtostring, 10); pushVStack(numtostring); char dum[10]="$"; StAssPush(strcat(dum,numtostring));}
                | FLOAT_DIGIT                   { assign_int($1, assign_index); char floattostring[40]; gcvt($1, 6, floattostring); pushVStack(floattostring); char dum[10]="$"; StAssPush(strcat(dum,floattostring));}
                | BOOL_LITERAL                  { assign_int($1, assign_index); if($1==true){pushVStack("true");StAssPush("$true");}else{pushVStack("false");StAssPush("$false");} }
                | STRING_LITERAL                { assign_str($1, assign_index); pushVStack($1);char buf[50]; strcpy(buf, "$");strcat(buf, $1); StAssPush(buf);}
                | CONSTANT                      { int i = lookup($1,0); check_type(i); pushVStack($1); StAssPush($1);}
                | SUB EXPRESSION                {StAssPrint("neg", 1);}
                | EXPRESSION PLUS PLUS          { pushVStack("+"); pushVStack("1"); CodeGenOp("ADD"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("ADD", 1); StAssPrint("STORE", 1);}
                | EXPRESSION SUB SUB            { pushVStack("-"); pushVStack("1"); CodeGenOp("SUB"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("SUB", 1); StAssPrint("STORE", 1);}
                | EXPRESSION PLUS               { pushVStack("+");}  EXPRESSION  {CodeGenOp("ADD"); StAssPrint("ADD", 1);}
                //| EXPRESSION SUB                { pushVStack("-");}  EXPRESSION  {CodeGenOp("SUB"); StAssPrint("SUB", 1);}
                | EXPRESSION MUL                { pushVStack("*");}  EXPRESSION  {CodeGenOp("MUL"); StAssPrint("MUL", 1);}
                | EXPRESSION DIV                { pushVStack("/");}  EXPRESSION  {CodeGenOp("DIV"); StAssPrint("DIV", 1);}

// TODO : IMPLEMENT THE POWER STATEMENT IN STACK MACHINE CODE (maybe as a macro?)
                | EXPRESSION POW                {pushVStack("^");} EXPRESSION  {CodeGenOp("POW");}
                | COMPARISONSTT
                | FUNC_CALL                                
                | '(' EXPRESSION ')'
                | ERRONOUS_EXPRESSION           {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);pErr(yylineno);}
                ;

ERRONOUS_EXPRESSION:
                //EXPRESSION PLUS error
                //| EXPRESSION SUB
                //| EXPRESSION MUL
                //| EXPRESSION DIV
                //| EXPRESSION POW
                error PLUS EXPRESSION           
                //| error SUB EXPRESSION          
                | error MUL EXPRESSION          
                | error DIV EXPRESSION          
                | error POW EXPRESSION          
                ;




COMPARISONSTT:
                EXPRESSION GT EXPRESSION                {pushVStack(">"); CodeGenLogical(); StAssPrint("GT", 1);}
                | EXPRESSION LT EXPRESSION              {pushVStack("<"); CodeGenLogical(); StAssPrint("LT", 1);}
                | EXPRESSION LT EQ EXPRESSION           {pushVStack("<="); CodeGenLogical(); StAssPrint("LE", 1);}
                | EXPRESSION GT EQ EXPRESSION           {pushVStack(">="); CodeGenLogical(); StAssPrint("GE", 1);}
                | EXPRESSION EQUALITY EXPRESSION        {pushVStack("="); CodeGenLogical(); StAssPrint("EQ", 1);}
                | EXPRESSION NEG_EQUALITY EXPRESSION    {pushVStack("!="); CodeGenLogical(); StAssPrint("NE", 1);}
                | EXPRESSION LOGIC_AND EXPRESSION       {pushVStack("and"); CodeGenLogical(); StAssPrint("AND", 1);}
                | EXPRESSION LOGIC_OR EXPRESSION        {pushVStack("or"); CodeGenLogical(); StAssPrint("OR", 1);}
                | LOGIC_NOT EXPRESSION                  {StAssPrint("neg", 1);}
                | ERRONOUS_COMPARISONSTT
                ;

ERRONOUS_COMPARISONSTT:
                error GT EXPRESSION                                 {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);pErr(yylineno);}
                | EXPRESSION GT error   %prec GT                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);pErr(yylineno);}
                | error LT EXPRESSION                               {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);pErr(yylineno);}
                | EXPRESSION LT error   %prec LT                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);pErr(yylineno);}
                | error EQUALITY EXPRESSION                         {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);pErr(yylineno);}
                | EXPRESSION EQUALITY error   %prec EQUALITY        {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);pErr(yylineno);}
                | error NEG_EQUALITY EXPRESSION                     {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);pErr(yylineno);}
                | EXPRESSION NEG_EQUALITY error   %prec NEG_EQUALITY{printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);pErr(yylineno);}
                | LOGIC_NOT error   %prec EQ                        {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);pErr(yylineno);}
                | error LOGIC_AND EXPRESSION                        {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
                | EXPRESSION LOGIC_AND error   %prec LOGIC_AND      {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
                | error LOGIC_OR EXPRESSION                         {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
                | EXPRESSION LOGIC_OR error   %prec LOGIC_OR        {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
                | error LT EQ EXPRESSION                            {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
                | EXPRESSION LT EQ error   %prec LT                 {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
                | error GT EQ EXPRESSION                            {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
                | EXPRESSION GT EQ error   %prec GT                 {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
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
//--------------------------------------------------- SYMBOL TABLE---------------------------------------------
int is_exist(char* name){
    for (int i = 0; i < st_index; i++){
        //TODO SCOPE CHECK
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == block_number && symbolTable[i].outOfScope == 0){
            return symbolTable[i].declareLine;
        }
    }
    return -1;
}
int lookup(char* name, int is_assignment) {
    // 
    // This method returns -1 if the symbol does not exist in the symbol table. 
    // If the symbol exists, it returns its index in the table.
    // loop on the table from down to up to take the variable from the closest scope as closet one will
    // be with higher index in the table

     if ( is_enum == 1) { return -1;} 
     if ( symbolTable[assign_index].type == "var_enum")
     {  
        assign_enum (assign_index, symbolTable[assign_index].dataType, name);
        return -1;
    }     
    for (int i = st_index-1 ; i >= 0; i--){
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].outOfScope == 0 ){
           
            if (symbolTable[i].isInit == 0 && strcmp(symbolTable[i].type, "var") == 0 && symbolTable[i].isArg == 0 ) 
            {   
            // if ( i != assign_index)// 3shan lw kan el var 3la el LHS s3tha 3ady ex: int x=9; int z; z =x;
            if (is_assignment == 0)
            {
                printf("\n !!!!!!!!!!!! Error at line %d: %s used before initialized !!!!!!!!!!!\n", line_number, name); sErr(line_number);}
            }
            symbolTable[i].isUsed=1;
            return i;
        }
    }
    printf("\n !!!!!!!!!!!! Error at line %d: %s undeclared identifier in this scope !!!!!!!!!!!\n", line_number, name);
    sErr(line_number);
    return -1;
}
//-------------------------------------- INSERT IN SYMBOL TABLE  ----------------------------------I
int st_insert(char* data_type, char* name, char* type ,int is_arg ) {

    //------ create new entry
    struct Entry newEntry ;
    //----- check if name is already in symbol table
    int L=is_exist(name) ;
    if (L != -1){
        printf("\n !!!!!!!!!!!! Error at line %d: %s is already declared in this scope at line %d !!!!!!!!!!!\n",line_number, name, L); 
        sErr(line_number);
        is_changed=0;
        return -1;
        }
    //------ set new entry values
    newEntry.name = name;
    newEntry.dataType = data_type;
    newEntry.declareLine = line_number;
    newEntry.type = type;
    newEntry.id = st_index;
    newEntry.isArg = is_arg;
    newEntry.outOfScope = 0;
    newEntry.isInit = 0;// assume all uninitialized untill assign
    newEntry.isUsed = 0; // assume all unused untill used
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
      // 
    if (strcmp( data_type, "enum") == 0 )
    {
        symbolTable[st_index].isInit=1;
        // // create enum entry 
        struct enumEntry newEnumEntry ;
        // initialize enum keys and values
         for (int i = 0; i < 100; i++)
        {
            newEnumEntry.keys[i]  = "";
            newEnumEntry.values[i]  = 0;
        }
        // fill enum keys and values
        for (int i = 0; i < enum_arg_count; i++)
        {
            newEnumEntry.keys[i] = enum_keys[i];
            newEnumEntry.values[i] = enum_values[i];
        }
        symbolTable[st_index].enumValue = newEnumEntry;
        enum_arg_count=0;
        // clear enum keys and values
        for (int i = 0; i < 100; i++)
        {
            enum_keys[i] = "";
            enum_values[i] = 0;
        }
    }
    st_index++; // increment symbol table index
    st_log(); // log symbol table
    return st_index-1;
}
//----------------------------------------------- PRINT SYMBOL TABLE ----------------------------------------------------
void st_log() {
    //----- write symbol table to file
    FILE *log_fp= fopen("symbol_table_logs.log", "a");
    //----- check if file is opened
    if(log_fp == NULL) {
        printf("can't open symbol_table_logs.log file!\n");
        exit(1);
    }
    //----- write symbol table header
    fprintf(log_fp, "ID, Line, Scope, Name, Type, DataType, isInit, Value, Args\n");
    //----- write symbol table entries
    for(int i=0; i< st_index; i++) {
        struct Entry *entry = &symbolTable[i];
        fprintf(log_fp, "%d, %d, %d, %s, %s, %s, %d, ", entry->id, entry->declareLine, entry->scope, entry->name,entry->type, entry->dataType,entry->isInit);
        //---- store value of entry
        if (entry->isInit == 1) {
        if (strcmp(entry->dataType,"int")==0 || strcmp(entry->type,"var_enum")==0) {fprintf(log_fp, "%d, ", entry->intValue);}
        else if (strcmp(entry->dataType,"float")==0) {fprintf(log_fp, "%f, ", entry->floatValue);}
        else if (strcmp(entry->dataType,"bool")==0) {fprintf(log_fp,"%s, ", entry->boolValue ? "true" : "false");}
        else if (strcmp(entry->dataType,"string")==0) {fprintf(log_fp, "%s, ", entry->strValue);}
        }
        else {fprintf(log_fp, "-, ");}
        //---- print arguments of functions
        if (strcmp(entry->type, "func") == 0)
        {
            for (int j = 0; j < entry->argCount; j++)
            {
            fprintf(log_fp, "%d,", entry->argList[j]);
            }
        }
        else {fprintf(log_fp, "-");}
       
        fprintf(log_fp, "\n");

    }
    fprintf(log_fp, "=============\n");
    fclose(log_fp);
}
void clear_logs()
{
   FILE *fp= fopen("symbol_table_logs.log", "w");
   fclose(fp);
}
void st_print() {
    //----- write symbol table to file
    FILE *fp = fopen("symbol_table.txt", "w");
    //----- check if file is opened
    if(fp == NULL) {
        printf("can't open symbol_table.txt file!\n");
        exit(1);
    }
    //----- write symbol table header
    fprintf(fp, "ID\t|Name\t|Type\t|DataType\t|Line\t|Scope\tisInit\t|Value\t\t|Args\n");
    fprintf(fp, "-------------------------------------------------------------------------------------------\n");
    //----- write symbol table entries
    for(int i=0; i< st_index; i++) {
        struct Entry *entry = &symbolTable[i];
        fprintf(fp, "%d\t|%s\t|%s\t|%s\t\t|%d\t|%d\t|%d\t|", entry->id, entry->name,entry->type, entry->dataType, entry->declareLine, entry->scope,entry->isInit);
        //---- store value of entry
        if (entry->isInit == 1) {
        if (strcmp(entry->dataType,"int")==0 || strcmp(entry->type,"var_enum")==0) {fprintf(fp, "%d\t\t|", entry->intValue);}
        else if (strcmp(entry->dataType,"float")==0) {fp, fprintf(fp, "%f\t\t|", entry->floatValue);}
        else if (strcmp(entry->dataType,"bool")==0) {fprintf(fp,"%s\t\t|", entry->boolValue ? "true" : "false");}
        else if (strcmp(entry->dataType,"string")==0) {fprintf(fp, "%s\t\t|", entry->strValue);}
        }
        else {fprintf(fp, "-\t\t|");}
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
//---------------------------------- HANDLE TYPE MISMATCH ERRORS ------------------------------------------------------------------

// for declaration statments take the st_index -1 3shan lesa m3molo insert but for assignment 3ady take assign_index coming from lookup function
void assign_int (int d , int i) {
    if (i == -1) {return;}
    if ( symbolTable[i].dataType == "string" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned int !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
    sErr(line_number);
     return; }
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType != "string" ) {symbolTable[i].intValue= d ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned wrong value!!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
    sErr(line_number);}
    if(is_changed == 1) {st_log();} // 
    assign_index = -1;
}
// void assign_float( float f, int i) {
//     if (i == -1) {return;}
//      if ( symbolTable[i].dataType != "float" && symbolTable[i].type == "func" )
//     {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned float !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
//      return ;}
//     symbolTable[i].isInit= 1 ;
//     if (symbolTable[i].dataType == "float"){symbolTable[i].floatValue= f ;}
//     else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned float value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
//    if(is_changed == 1) {st_log();}
//    assign_index = -1;
// }
void assign_str( char* s , int i) {
    if (i == -1) {return;}
    if ( symbolTable[i].dataType != "string" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned string !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
     sErr();
     return ;} 
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "string"){symbolTable[i].strValue= s ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned string value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );
    sErr();}
    if(is_changed == 1) {st_log();}
    assign_index = -1;
}
// void assign_bool( bool b , int i) {
//     if (i == -1) {return;}
//     if ( symbolTable[i].dataType != "bool" && symbolTable[i].type == "func" )
//     {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned boolean !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
//      return ;} 
//     symbolTable[i].isInit= 1 ;
//     if (symbolTable[i].dataType == "bool"){symbolTable[i].boolValue= b ;}
//     else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned bool value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
//     if(is_changed == 1) {st_log();}
//     assign_index = -1;
// }

void assign_enum (int i, char* enum_name, char* key) {
    if (i == -1) {return;}
    if (symbolTable[i].type == "var_enum") {
        for (int k=0; k < st_index; k++) { // loop on symbol table to find the enum declaration
            if (strcmp(symbolTable[k].name, enum_name) == 0) { // if found the enum declaration
                for (int j = 0; j < 100; j++) { // loop on enum keys to find the enum value
                    if (strcmp(symbolTable[k].enumValue.keys[j], key) == 0) {
                        symbolTable[i].intValue = symbolTable[k].enumValue.values[j];
                        symbolTable[i].isInit= 1 ; // set isInit to 1
                        st_log();
                        assign_index = -1;
                        return;
                    }
                }
                printf("\n !!!!!!!!!!!! Error at line %d: %s not exist as key for %s enum  !!!!!!!!!!!\n", line_number, key ,enum_name );
                sErr(line_number);
                assign_index = -1;
                return;
            }
        }
    }
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned enum value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );
    sErr(line_number);}
    assign_index = -1;
}
// void check_param_type (int i) {

// }
void check_type( int i) {
    // this functio check type matching between 2 identifiers before assign the value
    if ( is_param == 1) 
    { assign_index = arg_count;}
     if ( i == -1 || assign_index == -1) 
    { return;}
    if (symbolTable[i].dataType != symbolTable[assign_index].dataType && (symbolTable[assign_index].dataType == "string" ||  symbolTable[i].dataType == "string"))
    {   /// at calling a function
        if (strcmp(symbolTable[i].type,"func")== 0){ printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s return %s value  !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType ); sErr(line_number);}
        else if (strcmp(symbolTable[assign_index].type,"func")== 0){ printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s return %s value  !!!!!!!!!!!\n", line_number,symbolTable[i].name,symbolTable[i].dataType, symbolTable[assign_index].name,symbolTable[assign_index].dataType ); sErr(line_number);}
        else if (is_param == 1)
        {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Incorrect argument type %s is %s variable but %s %s !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType ); sErr(line_number);}
        else {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s %s !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType );sErr(line_number);}
    }
    else
    {
        symbolTable[assign_index].isInit=1;
        // assign value to the variable
        if ( strcmp(symbolTable[i].dataType,"int") ==0) {symbolTable[assign_index].intValue= symbolTable[i].intValue ;}
        else if (symbolTable[i].dataType == "float"){symbolTable[assign_index].floatValue= symbolTable[i].floatValue ;}
        else if ( strcmp(symbolTable[i].dataType, "string")==0){symbolTable[assign_index].strValue= symbolTable[i].strValue ;}
        else if (symbolTable[i].dataType == "bool"){symbolTable[assign_index].boolValue= symbolTable[i].boolValue ;}
    }
}
//--------------------------------------------------- HANDLE SCOPE ---------------------------------------------------

void scope_start(){
    //----- increment block number and scope index
    block_number++;
    scope_index++;
    scope_stack[scope_index] = block_number;
}
void scope_end(){
    if (func_index != -1 && strcmp(symbolTable[func_index].type, "func") == 0 && return_exist == 0 && strcmp(symbolTable[func_index].dataType, "void") != 0)
    {printf("\n !!!!!!!!!!!! Error at line %d: Missing return statement in Function %s !!!!!!!!!!!\n", line_number, symbolTable[func_index].name); sErr(line_number);}
    //----- make all symbols in this scope out of scope
    for (int i = 0; i < st_index; i++){
        if (symbolTable[i].scope == scope_stack[scope_index]){
            symbolTable[i].outOfScope = 1;
        }
    }
    scope_index--; // decrement scope index   
}
void unused_print() {
    for(int i=0; i< st_index; i++) {
        if ( symbolTable[i].isUsed == 0 && strcmp( symbolTable[i].type, "enum_arg") != 0) {
        if (strcmp(symbolTable[i].type,"func") == 0){printf("\n !!!!!!!!!!!! Function %s Declared at line %d but never called !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); sErr(symbolTable[i].declareLine);}
        else if ( symbolTable[i].isArg == 1){printf("\n !!!!!!!!!!!! Unused Argument %s Declared in Function at line %d !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); sErr(symbolTable[i].declareLine);}
        else {printf("\n !!!!!!!!!!!! Unused Identifier %s Declared at line %d !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); sErr(symbolTable[i].declareLine);}
        }
    }
}
void arg_count_check( int i) {
    if ( arg_count > symbolTable[i].argCount )
    {printf("\n !!!!!!!!!!!! Error at line %d : too many arguments for function call expected %d got %d !!!!!!!!!!!\n", line_number, symbolTable[i].argCount, arg_count); sErr(line_number);}
    else if ( arg_count < symbolTable[i].argCount )
    {printf("\n !!!!!!!!!!!! Error at line %d : too few arguments for function call expected %d got %d !!!!!!!!!!!\n", line_number, symbolTable[i].argCount, arg_count); sErr(line_number); }
}


/*
                                                                                |\/\  ,.
                                                                                /   `' |,-,
                                                                            /         /_
                                                                            _/            /
                                                                            (.-,--.       /
                                                                            /o/  o \     /
                                                                            \_\    /   _/
                                                                            (__`--'    _)
                                                                            /         |
                                                                            (_____,'    \  BART :)
                                                                            \_       _\
                                                                                `._..-'
*/
// ____________________________________________________________________________ CODE GEN _______________________________________________________________________

void pushVStack(char* var)
{   
    VirtualSP++;
    VirtualStack[VirtualSP] = strdup(var);
    /*printf("\nPUSHED %s\n", var);
    for (int i = VirtualSP ; i >=0; i--)
    {
        printf("\nDEBUG: %s", VirtualStack[i]);
    }*/
};

char* popVStack ()
{
    char* returner =  VirtualStack[VirtualSP];
    VirtualSP--;
    //printf("\nPOPED %s\n", returner);
    return returner;
};


char* newTemp()
{
    char* tempVar;
    strcpy(tempVar, "t");
    char numtostring[10];
    itoa(tempNumber, numtostring, 10);
    strcat(tempVar, numtostring);
    tempNumber++;
    return tempVar;
};



void StAssPush(char* s)
{
//////////////////////////////////////////////////////////// STACK ASSEMBLY///////////////////////////////////////////////
    FILE *assfile = fopen("stackassembly.txt", "a");
    if(assfile == NULL) {
        printf("can't open stackassembly.txt file!\n");
        exit(1);
    }
    fprintf(assfile, "\tPUSH \t %s\n", s);
    fclose (assfile);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void StAssPrint(char* s, int ind)
{
//////////////////////////////////////////////////////////// STACK ASSEMBLY///////////////////////////////////////////////
    FILE *assfile = fopen("stackassembly.txt", "a");
    if(assfile == NULL) {
        printf("can't open stackassembly.txt file!\n");
        exit(1);
    }
    if(ind){fprintf(assfile, "\t%s\n", s);}
    else{fprintf(assfile, "%s\n", s);}
    fclose (assfile);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};

void StAssJmp(char* jmp, char* jmpName, int* num, int inc, int noNum)
{
    FILE *assfile = fopen("stackassembly.txt", "a");
    if(assfile == NULL) {
        printf("can't open stackassembly.txt file!\n");
        exit(1);
    }
    if(noNum == 1)
    {
        fprintf(assfile, "\t%s \t %s\n", jmp, jmpName);
    }
    else{fprintf(assfile, "\t%s \t %s%d\n", jmp, jmpName,*num);}
    
    fclose (assfile);
    if(inc == 1){*num = *num + 1;}
};

void StAssPrintLBL(int isLBL, int inc)
{
    char buf[10];
    char numtostring[10];
    if(isLBL){
        strcpy(buf , "LBL");
        
        if(inc)
        {
            itoa(SMLabel_Else++, numtostring, 10);
        }
        else
        {
            itoa(SMLabel_Else, numtostring, 10);
        }

        } else {
        strcpy(buf, "END");
        if(inc)
        {
            itoa(SMLabel_End++, numtostring, 10);
        }
        else
        {
            itoa(SMLabel_End, numtostring, 10);
        }
    }
    strcat(buf, numtostring);strcat(buf, ":"); StAssPrint(buf,0);
};


void StAssForHeader()
{
    StAssPush("dum");
    StAssPush("$0");
    StAssPrint("STORE", 1);
    char buf[10];
    char numtostring[10];
    itoa(ForHeaderLabel, numtostring, 10);
    strcpy(buf, "Label");
    strcat(buf, numtostring);
    strcat(buf, ":");
    StAssPrint(buf, 0);
    StAssPush("dum");
    StAssPush("$1");
    StAssPrint("EQ", 1);
    StAssJmp("JZ", "HELPER", &ForHelperLabel, 0,0);

};

void StAssForMiddle()
{
    StAssJmp("JNZ", "END", &SMLabel_End, 0,0);
    StAssPush("dum");
    StAssPush("$1");
    StAssPrint("STORE", 1);
    StAssJmp("JMP", "LBL", &SMLabel_Else, 0,0);
    char buf[10];
    char numtostring[10];
    itoa(ForHelperLabel, numtostring, 10);
    strcpy(buf, "HELPER");
    strcat(buf, numtostring);
    strcat(buf, ":");
    StAssPrint(buf, 0);
    ForHelperLabel++;
};


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prependFile(char* filename, char* text) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(fsize + 1);
    fread(buffer, 1, fsize, file);
    fclose(file);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fprintf(file, "%s", text);
    fwrite(buffer, 1, fsize, file);
    fclose(file);

    free(buffer);
}


void printDataSegment()
{
    char* DS;
    strcpy(DS, "");
    for (int i = 0 ; i < st_index ; i++)
    {
        strcat(DS, "VAR\t");
        strcat(DS, symbolTable[i].name);
        strcat(DS, "\n");
    }
    prependFile("stackassembly.txt", DS);
}

void pErr(int lineNUMM)
{
    FILE *assfile = fopen("ParsingErrors.txt", "a");
    char buf [50];
    itoa(lineNUMM, buf,10);

    fprintf(assfile, "%s ", buf);
    
    fclose (assfile);
};



void sErr(int num)
{
    // printf("\n\n\n\n\n %d \n\n\n\n\n\n\n", num);
    FILE *semfile = fopen("SemanticErrors.txt", "a");
     if(semfile == NULL) {
        printf("can't open SemanticErrors.txt file!\n");
        exit(1);
    }

    fprintf(semfile, "%d ", num);
    
    fclose (semfile);
};

void popArgs()
{
    argPointer--;
    for (int i = argPointer; i>= 0;i--)
    {
        char buf[20];
        strcpy(buf, "POP\t");
        strcat(buf, argumentList[i]);
        StAssPrint(buf,1);
        argPointer--;
    }
    argPointer = 0;
};

void CodeGenAss()
{
    if(codeGen){
    //printf("DEBUG %s", VirtualStack[VirtualSP]);
    FILE *llfile = fopen("LLVM.txt", "a");
    if(llfile == NULL) {
        printf("can't open LLVM.txt file!\n");
        exit(1);
    }
    char* value = popVStack();
    char* carrier = popVStack();
    fprintf(llfile, "%s = %s\n", carrier, value);
    fclose (llfile);
    //printf("DEBUG %s", VirtualStack[VirtualSP]);

    }
};

void CodeGenOp(char* operator)
{
    if(codeGen){
    char* second_operand = popVStack();
    char* operation = popVStack();
    char* first_operand = popVStack();
    char dumstr[10];
    itoa(tempNumber, dumstr, 10);
    strcat(temp_var, dumstr);
    tempNumber++;
    pushVStack(temp_var);
    FILE *llvfile = fopen("LLVM.txt", "a");
    if(llvfile == NULL) {
        printf("can't open LLVM.txt file!\n");
        exit(1);
    }
    fprintf(llvfile, "%s = %s %s %s\n", temp_var, first_operand, operation, second_operand);
    fclose (llvfile);
    temp_var[strlen(temp_var)-1] = '\0';
    
    }
};

char* makeLabel()
{
    char dumstr[10];
    itoa(labelNumber, dumstr, 10);
    strcat(temp_label, dumstr);
    return temp_label;
};

void resetTempLabel()
{
    temp_label[strlen(temp_label)-1] = '\0';
    labelNumber++;
};

char* makeEndLabel()
{
    char dumstr[10];
    itoa(endlabelNumber, dumstr, 10);
    strcat(temp_endlabel, dumstr);
    return temp_endlabel;
};

void CodeGenLogical()
{
    if(codeGen)
    {
        char* equality_OP = popVStack();
        char* second_operand = popVStack();
        char* first_operand = popVStack();
        makeEndLabel();
        makeLabel();
        FILE *llvfile = fopen("LLVM.txt", "a");
        if(llvfile == NULL) {printf("can't open LLVM.txt file!\n");exit(1);}
        fprintf(llvfile, "%s %s %s goto %s\ngoto %s\n%s : \n", first_operand, equality_OP, second_operand, temp_label, temp_endlabel, temp_label); fclose (llvfile);
    }
    resetTempLabel();
};

void printIF(){
    if(codeGen){
    FILE *llvfile = fopen("LLVM.txt", "a");
    if(llvfile == NULL) {printf("can't open LLVM.txt file!\n");exit(1);}
    fprintf(llvfile, "IF "); fclose (llvfile);   }
};

void printLLVM(char* s)
{
    if(codeGen){
        FILE *llvfile = fopen("LLVM.txt", "a");
        if(llvfile == NULL) {printf("can't open LLVM.txt file!\n");exit(1);}
        fprintf(llvfile, s); fclose (llvfile);
    }
};

void printWHILE()
{
    if(codeGen)
    {
        printLLVM(makeLabel());
        resetTempLabel();
        printLLVM(":\n");
        printIF();
    }
};

void controlTerminator(int isWhile)
{
    if(codeGen)
    {
        if(isWhile)
        {
            labelNumber-=2;
            printLLVM("goto ");
            printLLVM(makeLabel());
            labelNumber+=2;
            printLLVM("\n");
            resetTempLabel();
        }

        printLLVM(strdup(temp_endlabel));
        printLLVM(":\n");
        temp_endlabel[strlen(temp_endlabel)-1] = '\0';
        endlabelNumber++;
    }
};
//==============================================================================================================================================================





//------------------------------------------- MAIN -------------------------------
int main(int argc, char *argv[])
{ 
    clear_logs();
    yy_flex_debug = 1;
    int ret = remove("LLVM.txt");
    int ret2 = remove("stackassembly.txt");
    int ret3 = remove("ParsingErrors.txt");
    int ret4 = remove("SemanticErrors.txt");
    if(ret != 0 && ret2 !=0 && ret3 !=0 && ret4 != 0){
        printf("\nCreating Intermediate Code File ...\n");
        printf("Creating Stack Machine Assembly File ...\n");
    }
    yyin = fopen(argv[1], "r");
    yyparse();
    st_print();
    unused_print();
    return 0;
}