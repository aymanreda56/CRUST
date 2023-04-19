%{
#include "try.tab.h" /* The tokens */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
void* yyerror(char*);
%}

%%
'+'                       {return ADD;}                                   /*add operation*/
'-'                       {return SUB;}
'*'                       {return MUL;}
'='                       {return ASSIGN_OP;}
"int"                     {return INTEGER_DEC;}       /*declaration of integer*/
"bool"                    {return BOOL_DEC;}
"float"                   {return FLOAT_DEC;}
"double"                  {return FLOAT_DEC;}
"char"                    {return CHAR_DEC;}
"string"                  {return STRING_DEC;}

"true"                    {yylval = true;
                           return BOOL_TRUE_IMM_VAL;}                           /*boolean immediate values*/

"false"                   {yylval = false;
                           return BOOL_FALSE_IMM_VAL;}

[0-9]+                    {yylval = atoi(yytext);
                           return INTEGER_IMM_VAL;}                        /*integer immediate values*/

\s[A-Z]+\s                {yylval = *yytext;
                           return CONSTANT_VAR;}                           /*constants are defined totally in uppercase*/

';'                       {return SEMICOLON;}    

[a-zA-Z]+[a-zA-Z_0-9]*    {yylval = *yytext;
                           return VAR_NAME;}                               /*variable name*/

[ \t]                                                                   /*whitespaces and tabs are muda muda*/
.                       {yyerror("Unknown character");}                                                /*for any erronous matches*/
%%


int yywrap(void) {
    return 1;
}