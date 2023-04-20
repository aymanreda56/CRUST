

/*
%token INT IDENTIFIER EQ PLUS SEMICOLON DIGIT MUL DIV BOOL_LITERAL
%token IF GT COLON SPC WHILE FOR SUB
*/

%{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(char* );
    int yylex();
%}


%token INT IF FOR WHILE BOOL_LITERAL DIV SPC GT LT EQ COLON SEMICOLON PLUS SUB MUL DIGIT IDENTIFIER
%left MUL
%left DIV
%left PLUS
%left SUB
%right GT

%%
PROGRAM:
                PROGRAM STATEMENT           {printf("Parsed a Program !");}
                |
                ;

STATEMENT:
                PRIMARY_STATEMENT
                | SECONDARY_STATEMENT
                ;

PRIMARY_STATEMENT:                                  /*Statements ending with a semicolon*/
                DECLARATION_STT
                | assignmentSTT
                ;

                       

SECONDARY_STATEMENT:         /*Statements ending with a closed curly braces, like loops*/
                IF_STT
                | FUNC_DECLARATION_STT
                | WHILE_STT
                | FOR_STT
                ;

FUNC_DECLARATION_STT:
                INT IDENTIFIER '(' ARGS ')' COLON BLOCK
                ;

ARGS:
                DECLARATION_STT
                | ARGS ',' DECLARATION_STT
                ;

DECLARATION_STT:                                                            {printf("parsed Declaration");}
                INT IDENTIFIER DECLARATION_TAIL SEMICOLON   
                ;
DECLARATION_TAIL:
                EQ EXPRESSION
                |
                ;
assignmentSTT:
                IDENTIFIER EQ EXPRESSION SEMICOLON
                ;


IF_STT:
                IF SPC EXPRESSION COLON BLOCK
                ;

WHILE_STT:
                WHILE SPC EXPRESSION COLON BLOCK
                ;

FOR_STT:
                FOR '(' PRIMARY_STATEMENT PRIMARY_STATEMENT PRIMARY_STATEMENT ')' BLOCK
                ;
/*
THREE_STATEMENTS:
                THREE_STATEMENTS THREE_STATEMENTS THREE_STATEMENTS
                | PRIMARY_STATEMENT
                |
                ;
*/
BLOCK:
                '{' PROGRAM '}'
                ;

EXPRESSION:
                IDENTIFIER
                | DIGIT
                | BOOL_LITERAL
                | EXPRESSION PLUS EXPRESSION
                | EXPRESSION SUB EXPRESSION
                | EXPRESSION MUL EXPRESSION
                | EXPRESSION DIV EXPRESSION
                | EXPRESSION GT EXPRESSION
                | '(' EXPRESSION ')'
                ;

%%

void yyerror(char* s)
{
    fprintf(stderr, "%s\n", s);
};