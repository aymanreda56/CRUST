%{
    #include "aym2.tab.h"
    void yyerror();
%}

%%
"int"                           {printf("INT:%s | ", yytext);           return INT;}
"float"                         {printf("FLOAT:%s | ", yytext);         return FLOAT;}
"double"                        {printf("FLOAT:%s | ", yytext);         return FLOAT;}
"bool"                          {printf("BOOL:%s | ", yytext);          return BOOL;}
"string"                        {printf("STRING:%s | ", yytext);        return STRING;}
"enum"                          {printf("ENUM:%s | ", yytext);          return ENUM;}
"switch"                        {printf("SWITCH:%s | ", yytext);        return SWITCH;}
"case"                          {printf("CASE:%s | ", yytext);          return CASE;}
"if"                            {printf("IF:%s | ", yytext);            return IF;}
"else"                          {printf("ELSE:%s | ", yytext);          return ELSE;}
"for"                           {printf("FOR:%s | ", yytext);           return FOR;}
"while"                         {printf("WHILE:%s | ", yytext);         return WHILE;}
"do"                            {printf("DO:%s | ", yytext);            return DO;}
"true"                          {printf("BOOL_LITERAL:%s | ", yytext);  return BOOL_LITERAL;}
"false"                         {printf("BOOL_LITERAL:%s | ", yytext);  return BOOL_LITERAL;}     
"and"                           {printf("LOGIC_AND:%s | ", yytext);     return LOGIC_AND;}
"or"                            {printf("LOGIC_OR:%s | ", yytext);      return LOGIC_OR;}
"!"                             {printf("LOGIC_NOT:%s | ", yytext);     return LOGIC_NOT;}

">"                             {printf("GT:%s | ", yytext);            return GT;}
"<"                             {printf("LT:%s | ", yytext);            return LT;}
"="                             {printf("EQ:%s | ", yytext);            return EQ;}         
";"                             {printf("SEMICOLON:%s | ", yytext);     return SEMICOLON;}
"+"                             {printf("PLUS:%s | ", yytext);          return PLUS;}
"-"                             {printf("SUB:%s | ", yytext);           return SUB;}
"*"                             {printf("MUL:%s | ", yytext);           return MUL;}
"/"                             {printf("DIV:%s | ", yytext);           return DIV;}
"^"                             {printf("POW: %s | ", yytext);          return POW;}
[)}{(:]                         {printf("special_TOKEN:%s | ", yytext); return *yytext;}
[A-Z]+                          {printf("CONSTANT:%s | ", yytext);      return CONSTANT;}
[a-zA-Z_][a-zA-Z0-9_]*          {printf("IDENTIFIER:%s | ", yytext);    return IDENTIFIER;}
\"[a-zA-Z0-9_]+\"               {printf("STRING_LITERAL:%s | ", yytext);return STRING_LITERAL;}

[0-9]+                          {printf("DIGIT:%s | ", yytext);         return DIGIT;}
[ \t]                           //ignore
 
.                               {printf("UNK: %s | ", yytext);          return *yytext;}
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