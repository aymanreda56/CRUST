%{
    #include <string.h>
    void yyerror(char *);
    int yylex(void);
    struct Symbol{
        string ID;
        int type;
        int intValue;
        bool boolValue;
        string stringValue;
    };
    struct Symbol symbolTableIntegers[300]; //maximum of 300 different variables

    void updateVar()
%}


%token INTEGER_IMM_VAL VAR_NAME BOOL_TRUE_IMM_VAL BOOL_FALSE_IMM_VAL CONSTANT_VAR STRING_DEC CHAR_DEC FLOAT_DEC BOOL_DEC INTEGER_DEC ASSIGN_OP MUL
%token SUB ADD SEMICOLON
%left '+' '-'
%left '*' '/'


%%
program:
        program statement SEMICOLON '\n'        {printf("Program parsed")};
        | /* NULL */
        ;

statement:
        assignmentSTT                           {printf("assignment!");}
        | addSTT                                {printf("addition");}
        ;
/*
        | subSTT
        | mulSTT
        | divSTT
        | expression                      { printf("%d\n", $1); }
        | VAR_NAME ASSIGN_OP expression       { sym[$1] = $3; }
        ;
*/
assignmentSTT:
        VAR_NAME ASSIGN_OP statement            {$$ = $3}//{printf("assignment!");}
        ;

addSTT:
        expression ADD expression     {$$ = $1 + $3;}
        ;

expression:
        INTEGER_IMM_VAL                 {$$ = $1;}
        | VAR_NAME                      { for (int i =0; i< symbolTableIntegers.size(); i++){
                                                if($1 == symbolTableIntegers[i].ID){
                                                        switch(symbolTableIntegers[i].type){
                                                                case(1):
                                                                $$ = symbolTableIntegers[i].intValue; break;
                                                                case(2):
                                                                $$ = symbolTableIntegers[i].boolValue; break;
                                                                case(3):
                                                                $$ = symbolTableIntegers[i].stringValue; break;
                                                        }
                                                }
                                         }
                                        }
        | statement                     {$$ = $1;}
        ;
/*
        | expression ADD expression     { $$ = $1 + $3; }
        | expression SUB expression     { $$ = $1 - $3; }
        | expression MUL expression     { $$ = $1 * $3; }
        ;
*/

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