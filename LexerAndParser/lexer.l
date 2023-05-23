%{
    #include "parser.tab.h"
    int line_number = 1;
    int nchar;
    int nword;
%}
%option yylineno

%%
#[\s\t]*.*[\s\t]*#                  {}//discard comments
"int"                           {printf("INT:%s | ", yytext);            nword++; nchar+=yyleng;                                return INT;}
"return"                        {printf("RETURN:%s | ", yytext);         nword++; nchar+=yyleng;                                return RETURN;}
"void"                          {printf("VOID:%s | ", yytext);           nword++; nchar+=yyleng;                                return VOID;}
"break"                         {printf("BREAK:%s | ", yytext);          nword++; nchar+=yyleng;                                return BREAK;}
"float"                         {printf("FLOAT:%s | ", yytext);          nword++; nchar+=yyleng;                                return FLOAT;}
"double"                        {printf("FLOAT:%s | ", yytext);          nword++; nchar+=yyleng;                                return FLOAT;}
"bool"                          {printf("BOOL:%s | ", yytext);           nword++; nchar+=yyleng;                                return BOOL;}
"default"                       {printf("DEFAULT:%s | ", yytext);        nword++; nchar+=yyleng;                                return DEFAULT;}
"string"                        {printf("STRING:%s | ", yytext);         nword++; nchar+=yyleng;                                return STRING;}
"enum"                          {printf("ENUM:%s | ", yytext);           nword++; nchar+=yyleng;                                return ENUM;}
"switch"                        {printf("SWITCH:%s | ", yytext);         nword++; nchar+=yyleng;                                return SWITCH;}
"case"                          {printf("CASE:%s | ", yytext);           nword++; nchar+=yyleng;                                return CASE;}
"if"                            {printf("IF:%s | ", yytext);             nword++; nchar+=yyleng;                                return IF;}
"else"                          {printf("ELSE:%s | ", yytext);           nword++; nchar+=yyleng;                                return ELSE;}
"for"                           {printf("FOR:%s | ", yytext);            nword++; nchar+=yyleng;                                return FOR;}
"while"                         {printf("WHILE:%s | ", yytext);          nword++; nchar+=yyleng;                                return WHILE;}
"do"                            {printf("DO:%s | ", yytext);             nword++; nchar+=yyleng;                                return DO;}
"true"                          {printf("BOOL_LITERAL:%s | ", yytext);   nword++; nchar+=yyleng;  yylval.bool_val = true;       return BOOL_LITERAL;}
"false"                         {printf("BOOL_LITERAL:%s | ", yytext);   nword++; nchar+=yyleng;  yylval.bool_val = false;      return BOOL_LITERAL;}     
"and"                           {printf("LOGIC_AND:%s | ", yytext);      nword++; nchar+=yyleng;                                return LOGIC_AND;}
"or"                            {printf("LOGIC_OR:%s | ", yytext);       nword++; nchar+=yyleng;                                return LOGIC_OR;}
"!"                             {printf("LOGIC_NOT:%s | ", yytext);      nword++; nchar+=yyleng;                                return LOGIC_NOT;}

"=="                            {printf("EQUALITY:%s | ", yytext);       nword++; nchar+=yyleng;                                return EQUALITY;}
"!="                            {printf("NEG_EQUALITY:%s | ", yytext);   nword++; nchar+=yyleng;                                return NEG_EQUALITY;}

">"                             {printf("GT:%s | ", yytext);             nword++; nchar+=yyleng;                                return GT;}
"<"                             {printf("LT:%s | ", yytext);             nword++; nchar+=yyleng;                                return LT;}
"="                             {printf("EQ:%s | ", yytext);             nword++; nchar+=yyleng;                                return EQ;}         
";"                             {printf("SEMICOLON:%s | ", yytext);      nword++; nchar+=yyleng;                                return SEMICOLON;}
"+"                             {printf("PLUS:%s | ", yytext);           nword++; nchar+=yyleng;  yylval.str = strdup(yytext);                              return PLUS;}
"-"                             {printf("SUB:%s | ", yytext);            nword++; nchar+=yyleng;                                return SUB;}
"*"                             {printf("MUL:%s | ", yytext);            nword++; nchar+=yyleng;                                return MUL;}
"/"                             {printf("DIV:%s | ", yytext);            nword++; nchar+=yyleng;                                return DIV;}
"^"                             {printf("POW: %s | ", yytext);           nword++; nchar+=yyleng;                                return POW;}
[)}{(:,]                         {printf("special_TOKEN:%s | ", yytext) ;nword++; nchar+=yyleng;                                return *yytext;}
[A-Z]+                          {printf("CONSTANT:%s | ", yytext);   yylval.str = strdup(yytext);     nword++; nchar+=yyleng;     return CONSTANT;}
[a-zA-Z_][a-zA-Z0-9_]*          {printf("IDENTIFIER:%s | ", yytext);   yylval.str = strdup(yytext);   nword++; nchar+=yyleng;   return IDENTIFIER;}
\"[a-zA-Z0-9_]+\"               {printf("STRING_LITERAL:%s | ", yytext); yylval.str = strdup(yytext); nword++; nchar+=yyleng; return STRING_LITERAL;}

[0-9]+                          {printf("DIGIT:%s | ", yytext);  nword++; nchar+=yyleng;  yylval.num = atoi(yytext);     return DIGIT;}
[0-9]+\.[0-9]+                  {printf("FLOAT_DIGIT:%s | ", yytext);  nword++; nchar+=yyleng;  yylval.float_val= atof(yytext);   return FLOAT_DIGIT;}

[ \t]+                           //ignore
\n                              {nchar++;line_number++;}
.                               {printf("UNK: %s | ", yytext);     nchar++;    return *yytext;}


%%

