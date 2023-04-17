%{
    #include <stdio.h>
    void yyerror(char *);
    int yylex(void);

    int sym[26];
%}


%token INTEGER_IMM_VAL VAR_NAME BOOL_IMM_VAL CONSTANT_VAR STRING_DEC CHAR_DEC FLOAT_DEC BOOL_DEC INTEGER_DEC ASSIGN_OP MUL
%token SUB ADD
%left '+' '-'
%left '*' '/'


%%
program:
        program statement '\n'
        | /* NULL */
        ;

statement:
        expression                      { printf("%d\n", $1); }
        | VAR_NAME '=' expression       { sym[$1] = $3; }
        ;

expression:
        INTEGER_IMM_VAL
        | VAR_NAME                      { $$ = sym[$1]; }
        | expression '+' expression     { $$ = $1 + $3; }
        | expression '-' expression     { $$ = $1 - $3; }
        | expression '*' expression     { $$ = $1 * $3; }
        ;

%%



void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}


int main(void) {
  //yylex();
  yyparse();
  //printf("%d\t%d\t%d\t%d\n", nchar, nword, nline);
  return 0;
}