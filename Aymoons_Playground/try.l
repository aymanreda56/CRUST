%{
#include "try.tab.h" /* The tokens */
#include <stdbool.h>
void* yyerror(char*);
%}

%%
[0-9]+                  {yylval = atoi(yytext);
                        return INTEGER_IMM_VAL;}                        /*integer immediate values*/

(true|false)            {yylval = (yytext == "true")?true:false;
                        return BOOL_IMM_VAL;}                           /*boolean immediate values*/

\B[A-Z]+\B              {yylval = *yytext;
                        return CONSTANT_VAR;}                           /*constants are defined totally in uppercase*/



\+                      {return ADD;}                                   /*add operation*/
-                       {return SUB;}
\*                      {return MUL;}
=                       {return ASSIGN_OP;}
int                     {return INTEGER_DEC;}       /*declaration of integer*/
bool                    {return BOOL_DEC;}
(float|double)          {return FLOAT_DEC;}
char                    {return CHAR_DEC;}
string                  {return STRING_DEC;}

                        
[a-zA-Z]+[a-zA-Z_0-9]   {yylval = *yytext;
                        return VAR_NAME;}                               /*variable name*/

[ \t]                                                                   /*whitespaces and tabs are muda muda*/
.                       {yyerror("Unknown character");}                                                /*for any erronous matches*/
%%


int yywrap(void) {
    return 1;
}


