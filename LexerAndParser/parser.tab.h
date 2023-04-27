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
    IF = 262,                      /* IF  */
    FOR = 263,                     /* FOR  */
    WHILE = 264,                   /* WHILE  */
    BOOL_LITERAL = 265,            /* BOOL_LITERAL  */
    DIV = 266,                     /* DIV  */
    GT = 267,                      /* GT  */
    LT = 268,                      /* LT  */
    EQ = 269,                      /* EQ  */
    SEMICOLON = 270,               /* SEMICOLON  */
    PLUS = 271,                    /* PLUS  */
    SUB = 272,                     /* SUB  */
    MUL = 273,                     /* MUL  */
    STRING_LITERAL = 274,          /* STRING_LITERAL  */
    CONSTANT = 275,                /* CONSTANT  */
    POW = 276,                     /* POW  */
    ELSE = 277,                    /* ELSE  */
    DO = 278,                      /* DO  */
    ENUM = 279,                    /* ENUM  */
    EQUALITY = 280,                /* EQUALITY  */
    NEG_EQUALITY = 281,            /* NEG_EQUALITY  */
    SWITCH = 282,                  /* SWITCH  */
    CASE = 283,                    /* CASE  */
    LOGIC_AND = 284,               /* LOGIC_AND  */
    LOGIC_OR = 285,                /* LOGIC_OR  */
    LOGIC_NOT = 286,               /* LOGIC_NOT  */
    DIGIT = 287,                   /* DIGIT  */
    IDENTIFIER = 288               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
