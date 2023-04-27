%{
    #include <stdlib.h>
    #include <stdio.h>
    void yyerror(char* );
    int yylex();
%}


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

%%
PROGRAM:                                                    
                PROGRAM STATEMENT                      
                |
                ;

STATEMENT:
                DECLARATION_STT
                | FUNC_DECLARATION_STT                      {printf("#[Parsed_Func_Declaration]# ");}
                | assignmentSTT
                | EXPRESSION SEMICOLON
                | FUNC_CALL                                 {printf("#[Parsed_Func_Call]# ");}
                | IF_STT                                    {printf("#[Parsed_If_STT]# ");}
                | WHILE_STT                                 {printf("#[Parsed_While_LOOP]# ");}
                | FOR_STT                                   {printf("#[Parsed_For_LOOP]# ");}
                | DO_WHILE_STT                              {printf("#[Parsed_DO_WHILE_LOOP]# ");}
                | SWITCH_STT                                {printf("#[Parsed_SWITCH_STT]# ");}
                | ENUM_DECLARATION_STT                      {printf("#[Parsed_Enum_Declaration]# ");}
                ;

/*
| MATCHED_IF_STT                            {printf("#[Parsed_Matched_If_STT]# ");}
*/

TYPE:
                INT
                | FLOAT
                | BOOL
                | STRING
                ;

DECLARATION_STT:                                                            
                TYPE IDENTIFIER DECLARATION_TAIL SEMICOLON           {printf("#[Parsed_Declaration]# ");}
                | TYPE CONSTANT DECLARATION_TAIL SEMICOLON           {printf("#[Parsed_CONST_Declaration]# ");}
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
                IDENTIFIER '(' USED_ARGS ')' SEMICOLON
                ;
USED_ARGS:
                EXPRESSION ',' USED_ARGS
                | EXPRESSION
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