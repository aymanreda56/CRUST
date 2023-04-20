%{
    #include <stdlib.h>
    #include <stdio.h>
    void yyerror(char* );
    int yylex();
%}


%token INT FLOAT BOOL STRING IF FOR WHILE BOOL_LITERAL DIV GT LT EQ SEMICOLON PLUS SUB MUL STRING_LITERAL CONSTANT
%token DIGIT IDENTIFIER
%left MUL
%left DIV
%left PLUS
%left SUB
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
                ;

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

FUNC_CALL:
                IDENTIFIER '(' EXPRESSION ')' SEMICOLON
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

IF_STT:
                IF EXPRESSION ':' BLOCK
                ;


WHILE_STT:
                WHILE EXPRESSION ':' BLOCK
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
                | EXPRESSION PLUS EXPRESSION
                | EXPRESSION SUB EXPRESSION
                | EXPRESSION MUL EXPRESSION
                | EXPRESSION DIV EXPRESSION
                | COMPARISONSTT
                | '(' EXPRESSION ')'
                ;

COMPARISONSTT:
                EXPRESSION GT EXPRESSION
                | EXPRESSION LT EXPRESSION
                ;
%%


void yyerror(char* s)
{
    fprintf(stderr, "%s\n", s);
};