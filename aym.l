%{
    #include <stdio.h>
    #include "aym.tab.h"
    void yyerror();
%}

%%
"int"       {printf("int "); return INT;}
"if"        {return IF;}
"for"       {return FOR;}
"while"     {return WHILE;}
"true"      {return BOOL_LITERAL;}
"false"     {return BOOL_LITERAL;}
'/'         {return DIV;}
[ \t]+      {}//{return SPC;}
">"         {return GT;}
"<"         {return LT;}
"="         {printf("equal ");return EQ;}
':'         {return COLON;}
';'         {printf("semicolon"); return SEMICOLON;}
'+'         {return PLUS;}
'-'         {return SUB;}
'*'         {return MUL;}


[^a-zA-Z_]([a-zA-Z_][a-zA-Z0-9_]*)[^a-zA-Z0-9_]  {printf("identifier "); return IDENTIFIER;}
[^a-zA-Z_0-9]([0-9]+)[^a-zA-Z0-9_]                  {printf("digit "); return DIGIT;}
.                       {printf("unknown error");}
%%


int yywrap()
{
    return 1;
}

int main()
{
    yyparse();
    return 0;
}