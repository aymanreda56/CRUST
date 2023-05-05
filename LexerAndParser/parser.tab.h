/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 61 "parser.y"

#include<stdbool.h>

#line 53 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    BOOL = 260,                    /* BOOL  */
    STRING = 261,                  /* STRING  */
    VOID = 262,                    /* VOID  */
    IF = 263,                      /* IF  */
    FOR = 264,                     /* FOR  */
    WHILE = 265,                   /* WHILE  */
    BOOL_LITERAL = 266,            /* BOOL_LITERAL  */
    DIV = 267,                     /* DIV  */
    GT = 268,                      /* GT  */
    LT = 269,                      /* LT  */
    EQ = 270,                      /* EQ  */
    SEMICOLON = 271,               /* SEMICOLON  */
    PLUS = 272,                    /* PLUS  */
    SUB = 273,                     /* SUB  */
    MUL = 274,                     /* MUL  */
    STRING_LITERAL = 275,          /* STRING_LITERAL  */
    CONSTANT = 276,                /* CONSTANT  */
    POW = 277,                     /* POW  */
    ELSE = 278,                    /* ELSE  */
    DO = 279,                      /* DO  */
    ENUM = 280,                    /* ENUM  */
    EQUALITY = 281,                /* EQUALITY  */
    NEG_EQUALITY = 282,            /* NEG_EQUALITY  */
    SWITCH = 283,                  /* SWITCH  */
    CASE = 284,                    /* CASE  */
    LOGIC_AND = 285,               /* LOGIC_AND  */
    LOGIC_OR = 286,                /* LOGIC_OR  */
    LOGIC_NOT = 287,               /* LOGIC_NOT  */
    DIGIT = 288,                   /* DIGIT  */
    IDENTIFIER = 289,              /* IDENTIFIER  */
    FLOAT_DIGIT = 290              /* FLOAT_DIGIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "parser.y"
 
 int num; /* integer value */ 
 char* str; 
 float float_val;
 bool bool_val;

#line 112 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
