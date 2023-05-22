/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include "parser.tab.h"
    void yyerror(char* );
    int yylex();
    void yyerror();
    extern int yylineno;
    extern FILE *yyin;
    extern FILE *yyout;
    extern int line_number;
    extern int yy_flex_debug;
    // TODO make data type of enum int and store its enum name  (try it with switc case)
    //TODO  add float and int error DONE
    //TODO if you have 2 x in diffrent scopes and both are in valid scopes take the closet (DONE)
    //TODO unused variables (DONE)
    //TODO type mismatch lel < > w kda
    //TODO division by zero
    //TODO check err.txt err2.txt err3.txt
    ///TODOS
    // ''' 1- symbol table: 
    // store enum value , check el type bta3o w kda 
    // 2- error handling:
    //   type checking (DONE) ,const value change, undeclared variables (DONE), used before assign (DONE)
    //, scope checking (DONE), function call checking (DONE),
    //  function return type checking+ feh return wla la2 aslan ,function
    //   argument type checking (count), function argument count checking (count), function argument order checking '''
    //--------------------- Symbol Table -----------------
    struct enumEntry{
        char* keys[100];
        int values [100];
    };
    struct Entry {
        int id,intValue,scope;
        char* name , value;
        float floatValue;
        bool boolValue;
        char* strValue; 

        struct enumEntry enumValue;
        char* type; // var,const, func, enum_arg, var_enum
        char* dataType; // int, float, bool, string (for func: return type)
        // list of arguments stored as IDs of them symbol table
        int argList[100];
        int argEnum[100]; // store indexes of the enum args in the symbol table
        int argCount;
        int declareLine;
        int isConst, isArg, isUsed, isInit, outOfScope;
    };
    struct Entry symbolTable[500]; //TODO: need to be dynamic?
    int st_index=0;
    int in_loop=0;
    int assign_index=-1;
    int func_index=-1; // to check return type of the function
    int is_param=0;
    int arg_count=0;
    int called_func_index=0;
    int is_enum=0;
    char* enum_keys[100];
    int enum_values [100];
    int enum_arg_count=0;
    int is_changed=1; // default is 1,
    int return_exist=0;
    //-- symbol table functions:  st_functionName()
    int st_insert(char* data_type, char* name, char* type, int is_arg);
    void st_print();
    void st_log();
    void clear_logs();
    int is_exist(char* name);
    int lookup(char* name, int is_assignment);
    //--- handle scope
    int scope_index=0;
    int block_number=0;
    int scope_stack[500]; // stack of scopes (for nested scopes to store block number)
    void scope_start();
    void scope_end();
    //--- handle errors
    void check_type( int i);
    void unused_print() ;
    void assign_int( int d , int i);
    void assign_str( char* s , int i);
    // void assign_bool( bool b , int i);
    // void assign_float( float f , int i);
    void assign_enum (int i, char* enum_name, char* key);
    void arg_count_check( int i);



//____________________________________________________________ CODE GEN ____________________________________________________________________
    #include <fcntl.h>             //for creating file
    #include <errno.h>             //for checking for file
    int codeGen = 1;
    char* VirtualStack [1000];
    int VirtualSP = -1;
    int tempNumber = 0;
    int labelNumber = 0;
    int endlabelNumber=0;
    char temp_label[50] = "L";
    char temp_endlabel[50] = "END";
    char* popVStack();
    char temp_var[50] = "t";
    void pushVStack(char* s);
    void CodeGenAss();
    void CodeGenOp(char* operator);
    void printIF();
    void printLLVM(char* s);
    char* makeLabel();
    char* makeEndLabel();
    void printWHILE();
    void controlTerminator(int isWhile);
    void CodeGenLogical();
    void StAssPush(char* s);
    void StAssPrint(char* s, int ind);
    int SMLabel = 0;
    int SMLabel_Else = 0;
    int SMLabel_End = 0;
    void StAssJmp(char* jmp, char* jmpName,int* num, int inc, int noNum);
    void StAssPrintLBL(int isLBL, int inc);
    void StAssForHeader();
    void StAssForMiddle();
    int ForHeaderLabel = 0;
    int ForHelperLabel = 0;
    char IdentifierHolder[10];
    char* argumentList[20];
    int argPointer = 0;
    void popArgs();
    int enumCNT = 1;
    void prepend(char* s, const char* t)    {size_t len = strlen(t);memmove(s + len, s, strlen(s) + 1);memcpy(s, t, len);}
    char switcher[50];
    void pErr(int num);
    void sErr();
    //int* linenoPTR = &yylineno;
//==================================================================================================================================================


#line 209 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_BOOL = 5,                       /* BOOL  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_BOOL_LITERAL = 11,              /* BOOL_LITERAL  */
  YYSYMBOL_DIV = 12,                       /* DIV  */
  YYSYMBOL_GT = 13,                        /* GT  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_SEMICOLON = 16,                 /* SEMICOLON  */
  YYSYMBOL_PLUS = 17,                      /* PLUS  */
  YYSYMBOL_SUB = 18,                       /* SUB  */
  YYSYMBOL_MUL = 19,                       /* MUL  */
  YYSYMBOL_STRING_LITERAL = 20,            /* STRING_LITERAL  */
  YYSYMBOL_CONSTANT = 21,                  /* CONSTANT  */
  YYSYMBOL_POW = 22,                       /* POW  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_ENUM = 25,                      /* ENUM  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_DEFAULT = 27,                   /* DEFAULT  */
  YYSYMBOL_EQUALITY = 28,                  /* EQUALITY  */
  YYSYMBOL_NEG_EQUALITY = 29,              /* NEG_EQUALITY  */
  YYSYMBOL_SWITCH = 30,                    /* SWITCH  */
  YYSYMBOL_CASE = 31,                      /* CASE  */
  YYSYMBOL_LOGIC_AND = 32,                 /* LOGIC_AND  */
  YYSYMBOL_LOGIC_OR = 33,                  /* LOGIC_OR  */
  YYSYMBOL_LOGIC_NOT = 34,                 /* LOGIC_NOT  */
  YYSYMBOL_DIGIT = 35,                     /* DIGIT  */
  YYSYMBOL_IDENTIFIER = 36,                /* IDENTIFIER  */
  YYSYMBOL_FLOAT_DIGIT = 37,               /* FLOAT_DIGIT  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ':'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_PROGRAM = 46,                   /* PROGRAM  */
  YYSYMBOL_STATEMENT = 47,                 /* STATEMENT  */
  YYSYMBOL_TYPE = 48,                      /* TYPE  */
  YYSYMBOL_DECLARATION_STT = 49,           /* DECLARATION_STT  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_DECLARATION_TAIL = 52,          /* DECLARATION_TAIL  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_RETURN_STT = 56,                /* RETURN_STT  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_helperSWITCH = 58,              /* helperSWITCH  */
  YYSYMBOL_SWITCH_STT = 59,                /* SWITCH_STT  */
  YYSYMBOL_DEFAULTCASE = 60,               /* DEFAULTCASE  */
  YYSYMBOL_CASES = 61,                     /* CASES  */
  YYSYMBOL_62_7 = 62,                      /* $@7  */
  YYSYMBOL_63_8 = 63,                      /* $@8  */
  YYSYMBOL_64_9 = 64,                      /* $@9  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 66,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_67_11 = 67,                     /* $@11  */
  YYSYMBOL_68_12 = 68,                     /* $@12  */
  YYSYMBOL_69_13 = 69,                     /* $@13  */
  YYSYMBOL_70_14 = 70,                     /* $@14  */
  YYSYMBOL_FUNC_DECLARATION_STT = 71,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_72_15 = 72,                     /* $@15  */
  YYSYMBOL_73_16 = 73,                     /* $@16  */
  YYSYMBOL_74_17 = 74,                     /* $@17  */
  YYSYMBOL_75_18 = 75,                     /* $@18  */
  YYSYMBOL_76_19 = 76,                     /* $@19  */
  YYSYMBOL_77_20 = 77,                     /* $@20  */
  YYSYMBOL_78_21 = 78,                     /* $@21  */
  YYSYMBOL_79_22 = 79,                     /* $@22  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 80, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_81_23 = 81,                     /* $@23  */
  YYSYMBOL_ARGS = 82,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 83,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 84,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 85,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_86_24 = 86,                     /* $@24  */
  YYSYMBOL_ENUM_HELPER = 87,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 88,                 /* ENUM_ARGS  */
  YYSYMBOL_89_25 = 89,                     /* $@25  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 90,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_91_26 = 91,                     /* $@26  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 92, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_CALL_STT = 93,             /* ENUM_CALL_STT  */
  YYSYMBOL_IF_STT_HELPER = 94,             /* IF_STT_HELPER  */
  YYSYMBOL_95_27 = 95,                     /* $@27  */
  YYSYMBOL_IF_STT_HELPER1 = 96,            /* IF_STT_HELPER1  */
  YYSYMBOL_IF_STT = 97,                    /* IF_STT  */
  YYSYMBOL_98_28 = 98,                     /* $@28  */
  YYSYMBOL_99_29 = 99,                     /* $@29  */
  YYSYMBOL_WHILE_STT = 100,                /* WHILE_STT  */
  YYSYMBOL_101_30 = 101,                   /* $@30  */
  YYSYMBOL_102_31 = 102,                   /* $@31  */
  YYSYMBOL_DO_WHILE_STT = 103,             /* DO_WHILE_STT  */
  YYSYMBOL_ERRONOUS_DO_WHILE = 104,        /* ERRONOUS_DO_WHILE  */
  YYSYMBOL_105_32 = 105,                   /* $@32  */
  YYSYMBOL_106_33 = 106,                   /* $@33  */
  YYSYMBOL_107_34 = 107,                   /* $@34  */
  YYSYMBOL_108_35 = 108,                   /* $@35  */
  YYSYMBOL_FOR_STT = 109,                  /* FOR_STT  */
  YYSYMBOL_110_36 = 110,                   /* $@36  */
  YYSYMBOL_111_37 = 111,                   /* $@37  */
  YYSYMBOL_112_38 = 112,                   /* $@38  */
  YYSYMBOL_113_39 = 113,                   /* $@39  */
  YYSYMBOL_ERRONOUS_FOR_LOOP = 114,        /* ERRONOUS_FOR_LOOP  */
  YYSYMBOL_115_40 = 115,                   /* $@40  */
  YYSYMBOL_116_41 = 116,                   /* $@41  */
  YYSYMBOL_helperAssignmentRule = 117,     /* helperAssignmentRule  */
  YYSYMBOL_assignmentSTT = 118,            /* assignmentSTT  */
  YYSYMBOL_119_42 = 119,                   /* $@42  */
  YYSYMBOL_BLOCK = 120,                    /* BLOCK  */
  YYSYMBOL_121_43 = 121,                   /* $@43  */
  YYSYMBOL_FUNC_CALL = 122,                /* FUNC_CALL  */
  YYSYMBOL_123_44 = 123,                   /* $@44  */
  YYSYMBOL_124_45 = 124,                   /* $@45  */
  YYSYMBOL_125_46 = 125,                   /* $@46  */
  YYSYMBOL_USED_ARGS = 126,                /* USED_ARGS  */
  YYSYMBOL_127_47 = 127,                   /* $@47  */
  YYSYMBOL_EXPRESSION = 128,               /* EXPRESSION  */
  YYSYMBOL_129_48 = 129,                   /* $@48  */
  YYSYMBOL_130_49 = 130,                   /* $@49  */
  YYSYMBOL_131_50 = 131,                   /* $@50  */
  YYSYMBOL_132_51 = 132,                   /* $@51  */
  YYSYMBOL_ERRONOUS_EXPRESSION = 133,      /* ERRONOUS_EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 134,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 135,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 136                  /* RES_WORD  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  225
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  388

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    40,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    44,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   187,   187,   188,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     215,   216,   217,   218,   222,   222,   223,   223,   224,   225,
     226,   231,   232,   233,   234,   235,   235,   236,   236,   237,
     237,   244,   245,   245,   247,   250,   251,   255,   256,   259,
     259,   259,   259,   260,   260,   261,   262,   264,   273,   273,
     274,   274,   275,   275,   276,   276,   277,   289,   290,   290,
     290,   291,   291,   291,   292,   292,   292,   293,   293,   293,
     298,   298,   308,   309,   310,   313,   316,   323,   323,   324,
     326,   326,   329,   329,   330,   336,   336,   337,   338,   339,
     340,   341,   345,   346,   348,   349,   353,   354,   358,   358,
     361,   365,   366,   367,   368,   368,   369,   369,   370,   379,
     379,   379,   388,   389,   392,   392,   393,   393,   394,   394,
     395,   395,   396,   403,   403,   403,   403,   403,   404,   408,
     408,   409,   409,   416,   420,   421,   422,   422,   427,   427,
     435,   435,   435,   435,   436,   440,   440,   441,   442,   443,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     458,   460,   460,   461,   461,   464,   464,   465,   466,   467,
     468,   477,   479,   480,   481,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   525,   525,   525,   525,   525,   525,   525,   525,
     525,   525,   525,   525,   525,   525
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "BOOL",
  "STRING", "VOID", "IF", "FOR", "WHILE", "BOOL_LITERAL", "DIV", "GT",
  "LT", "EQ", "SEMICOLON", "PLUS", "SUB", "MUL", "STRING_LITERAL",
  "CONSTANT", "POW", "ELSE", "DO", "ENUM", "RETURN", "DEFAULT", "EQUALITY",
  "NEG_EQUALITY", "SWITCH", "CASE", "LOGIC_AND", "LOGIC_OR", "LOGIC_NOT",
  "DIGIT", "IDENTIFIER", "FLOAT_DIGIT", "'{'", "'}'", "')'", "':'", "'('",
  "','", "';'", "$accept", "PROGRAM", "STATEMENT", "TYPE",
  "DECLARATION_STT", "$@1", "$@2", "DECLARATION_TAIL", "$@3", "$@4", "$@5",
  "RETURN_STT", "$@6", "helperSWITCH", "SWITCH_STT", "DEFAULTCASE",
  "CASES", "$@7", "$@8", "$@9", "$@10", "ERRONOUS_SWITCH_STT", "$@11",
  "$@12", "$@13", "$@14", "FUNC_DECLARATION_STT", "$@15", "$@16", "$@17",
  "$@18", "$@19", "$@20", "$@21", "$@22", "ERRONOUS_FUNC_DECLARATION_STT",
  "$@23", "ARGS", "ERRONOUS_ARGS", "ARG_DECL", "ENUM_DECLARATION_STT",
  "$@24", "ENUM_HELPER", "ENUM_ARGS", "$@25", "ENUM_DEFINED_ARGS", "$@26",
  "ERRONOUS_ENUM_DECLARATION_STT", "ENUM_CALL_STT", "IF_STT_HELPER",
  "$@27", "IF_STT_HELPER1", "IF_STT", "$@28", "$@29", "WHILE_STT", "$@30",
  "$@31", "DO_WHILE_STT", "ERRONOUS_DO_WHILE", "$@32", "$@33", "$@34",
  "$@35", "FOR_STT", "$@36", "$@37", "$@38", "$@39", "ERRONOUS_FOR_LOOP",
  "$@40", "$@41", "helperAssignmentRule", "assignmentSTT", "$@42", "BLOCK",
  "$@43", "FUNC_CALL", "$@44", "$@45", "$@46", "USED_ARGS", "$@47",
  "EXPRESSION", "$@48", "$@49", "$@50", "$@51", "ERRONOUS_EXPRESSION",
  "COMPARISONSTT", "ERRONOUS_COMPARISONSTT", "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-272)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-161)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -272,   201,  -272,   670,  -272,  -272,  -272,  -272,   -19,    32,
      13,  -272,  -272,   507,  -272,  -272,    33,    38,    16,    77,
     518,  -272,   109,  -272,  -272,   507,  -272,    -9,  -272,    71,
      62,  -272,  -272,  -272,    52,  -272,  -272,  -272,    51,  -272,
    -272,  -272,  -272,  -272,  -272,   128,  -272,  -272,  -272,   966,
    -272,  -272,  -272,   507,   292,   430,  -272,   507,   507,   114,
     507,   507,   507,   507,   507,   116,  -272,  -272,    56,  -272,
     507,   402,    92,   507,  1098,   359,   141,   101,    14,   123,
      61,   507,  -272,     3,    12,  1133,   107,  -272,   104,   110,
    -272,   752,  -272,    21,  -272,    47,  -272,    78,    15,  -272,
      39,   146,    52,  -272,   988,  -272,   441,   469,  -272,   150,
     154,  -272,  -272,   545,   556,   583,   594,   144,   507,   144,
     507,   159,   228,   184,  -272,  1133,  1133,  1133,   166,   166,
    -272,   135,    52,  1054,   402,   402,   402,  1054,   107,   171,
     143,  -272,    22,   151,   148,    -4,    82,   153,  -272,  -272,
    1054,   152,   165,    58,  -272,   507,   177,  -272,  -272,   253,
    -272,     5,   173,   174,     5,    25,    52,  -272,   507,  -272,
     185,  -272,  -272,   181,  -272,    69,  -272,  -272,   507,    12,
     621,   144,   209,   632,   159,  -272,   507,  -272,   507,   507,
    1144,  1133,  1144,  1133,  1120,   166,  1120,   166,   144,   144,
      25,   188,  -272,   402,   402,  -272,   183,   187,   220,   191,
    -272,   507,   507,   195,   151,    80,   205,   210,   151,  -272,
     206,   214,   213,  -272,  -272,  1010,   249,   480,  -272,   507,
     659,  -272,  -272,  -272,    25,   226,  -272,    25,   231,   229,
    -272,   225,  -272,  1054,   507,  -272,   233,  -272,   144,    12,
     144,   209,   144,   228,   184,  1133,   235,  -272,   236,   402,
     402,    52,   507,   238,   507,   507,   920,   776,  -272,   243,
     242,  -272,  -272,   247,  -272,   260,  -272,   258,    62,   261,
      62,    62,  -272,  -272,   318,  -272,   800,  1032,  1076,   699,
     262,  -272,  -272,  -272,  -272,    25,   257,   943,  -272,  -272,
      52,  -272,   264,  -272,  -272,   824,   507,   848,   872,  -272,
    -272,  -272,  -272,   263,   266,  -272,  -272,   269,    62,   272,
     275,   480,   276,   277,  -272,  -272,  -272,   279,   282,   737,
    -272,    52,  -272,    52,  -272,    52,  -272,    52,  -272,   402,
    -272,   896,  -272,  -272,   265,  -272,   284,  -272,  -272,  -272,
    -272,   480,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,    52,
    -272,  -272,  -272,  -272,    52,   285,  -272,   309,  -272,  -272,
    -272,  -272,    62,  -272,  -272,  -272,    52,  -272
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    20,    21,    22,    23,     0,   108,
       0,   119,   163,     0,   164,   165,     0,     0,    42,     0,
       0,   161,     0,   162,   148,     0,     2,     0,     4,     0,
      57,    12,    46,     5,     0,    13,    89,    14,   114,     8,
       9,    11,   123,    10,   138,     0,     6,    15,   178,     0,
     180,   177,   194,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,     0,   116,
       0,     0,   133,     0,     0,     0,   166,   124,     0,     0,
       0,     0,    58,     0,   203,   193,   146,   143,     0,     0,
       3,     0,    26,    80,    16,     0,    49,    56,     0,    67,
       0,   111,     0,   144,     0,   173,     0,     0,     7,   169,
       0,   171,   175,     0,     0,     0,     0,   183,     0,   195,
       0,   197,   181,   182,    29,   184,   199,   201,   204,   206,
      28,    71,     0,   109,     0,     0,     0,   120,     0,     0,
       0,   128,     0,     0,     0,    92,     0,     0,    90,    91,
      43,     0,    60,     0,   154,     0,     0,   107,   151,     0,
     179,     0,     0,    68,     0,     0,     0,    48,     0,    55,
       0,    66,    45,     0,   110,     0,   115,   145,     0,   196,
       0,   185,   198,     0,   186,   167,     0,   168,     0,     0,
     200,   189,   202,   190,   205,   191,   207,   192,   210,   208,
       0,     0,   117,     0,     0,   134,     0,     0,     0,     0,
     126,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,    64,    44,     0,     0,     0,   149,     0,
       0,    34,    27,    30,     0,     0,    25,     0,     0,     0,
      84,    83,    47,    50,     0,   118,     0,   112,   174,   211,
     188,   209,   187,   170,   172,   176,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
       0,   101,   100,    95,    99,     0,   104,     0,    57,     0,
      57,    57,   147,   106,     0,   152,   155,     0,     0,    39,
       0,    75,    85,    86,    81,     0,     0,     0,   113,    72,
       0,   139,     0,   135,   121,     0,     0,     0,     0,   132,
     122,   105,    98,     0,    92,    93,    88,     0,    57,     0,
       0,     0,     0,     0,    32,    33,    31,     0,     0,     0,
      69,     0,    82,     0,    54,     0,    79,     0,   141,     0,
     125,     0,   129,   127,     0,    59,     0,    63,    65,   157,
     153,     0,    36,    38,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,    40,     0,
      76,    51,    73,   140,     0,     0,   131,     0,    96,    61,
     156,    70,    57,   142,   136,    52,     0,   137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -272,   246,   -69,  -162,  -272,  -272,  -272,   136,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,   241,  -271,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -181,  -272,  -272,
    -272,  -272,  -138,    66,  -272,   -11,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,   -16,  -272,  -272,  -272,  -272,
    -272,  -239,  -272,   -12,  -272,  -272,  -272,  -272,  -272,  -272,
    -272,  -272
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    26,    27,    28,   164,   161,   232,   327,   328,
     329,    29,    81,    30,    31,    97,    98,   168,   296,   382,
     170,    32,   151,   221,   222,   281,    33,   234,   369,   200,
     335,   235,   331,   201,   300,    34,   165,   239,   240,   241,
      35,   218,   147,   148,   216,   149,   313,    36,    37,    38,
      70,   101,    39,   102,   132,    40,    73,   206,    41,    42,
     139,   265,   209,   140,    43,   136,   260,   339,   386,    44,
     337,   374,    45,    46,   155,    47,    90,    48,    89,   227,
     322,   285,   323,    49,   186,   188,   178,   189,    50,    51,
      52,   368
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    76,   134,   238,   152,   213,   229,   317,    85,   319,
     320,   215,    92,    91,    71,   141,   171,    68,    99,   256,
     230,   231,   -24,   210,   142,    54,    55,    93,     4,     5,
       6,     7,   -41,   104,    77,   -94,   -24,   -24,   238,    79,
     173,   117,   119,   121,   153,   122,   123,   346,   125,   126,
     127,   128,   129,   290,   172,    72,   292,   162,   133,   223,
     211,   137,   144,   163,   212,   203,   204,   205,   237,   150,
     246,    24,   238,    69,    80,   238,   269,    24,    82,   167,
     277,   270,   349,   217,   174,    24,   176,    94,   166,    95,
      24,   271,   100,    96,   181,   184,   224,   145,   131,   146,
     272,   191,   193,   195,   197,    95,   198,    24,   199,   -53,
      86,   385,   380,    83,   332,   273,   202,   274,   -87,   156,
     157,  -160,  -160,  -160,    87,  -160,  -160,  -160,  -160,    74,
     124,  -160,   130,   238,   258,   259,   135,  -160,  -160,    12,
    -130,  -160,  -160,   225,   103,    88,    13,   154,    14,    15,
     242,  -150,   158,   105,   106,   107,   243,   106,   107,   247,
     111,   143,    20,    21,    75,    23,   248,   185,   250,   175,
      25,   252,   187,   107,   253,   -77,   254,   255,   105,   106,
     107,   207,   208,   109,   110,   111,   214,   145,   112,   233,
     302,   303,   219,   220,   113,   114,   105,   106,   107,   266,
     267,     2,     3,   -62,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   226,   -74,   286,   244,   287,   289,    13,
     245,    14,    15,    55,   261,    16,    17,    18,   257,   262,
     263,    19,   297,   264,   268,    20,    21,    22,    23,    24,
     105,   106,   107,    25,   278,   304,   110,   111,   275,   276,
     305,   280,   307,   308,     3,   279,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   283,   291,   293,   295,   294,
     375,    13,   298,    14,    15,   299,   301,    16,    17,    18,
     306,   334,   311,    19,   336,   312,   -97,    20,    21,    22,
      23,    24,   228,    74,   341,    25,   314,   316,   333,   318,
     236,   377,   330,    12,   338,   -94,   344,   118,   345,   286,
      13,   347,    14,    15,   348,   370,   350,   371,   352,   372,
     351,   373,   353,   379,   215,   384,    20,    21,    75,    23,
      53,    54,    55,   378,    25,    57,   159,    58,   169,   286,
      60,   315,     0,     0,     0,     0,    61,    62,     0,     0,
      63,    64,     0,   381,     0,     0,     0,     0,   383,     0,
     138,   321,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
     387,  -160,  -160,  -160,     0,  -160,  -160,  -160,  -160,     0,
    -160,  -160,  -160,  -160,  -160,     0,     0,  -160,  -160,  -160,
    -160,  -160,  -160,     0,     0,     0,     0,  -160,  -160,  -160,
    -160,  -150,  -160,     3,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
      13,     0,    14,    15,     0,     0,    16,    17,    18,     0,
       0,    74,    19,     0,     0,     0,    20,    21,    22,    23,
      24,    12,   179,     0,    25,   120,     0,     0,    13,     0,
      14,    15,    12,     0,     0,     0,   180,     0,     0,    13,
       0,    14,    15,     0,    20,    21,    75,    23,     0,     0,
     182,     0,    25,     0,     0,    20,    21,    75,    23,     0,
      12,   284,     0,    25,   183,     0,     0,    13,     0,    14,
      15,    12,     0,     0,     0,     0,     0,     0,    13,     0,
      14,    15,     0,    20,    21,    75,    23,     0,    74,     0,
       0,    25,     0,     0,    20,    21,    75,    23,    12,    84,
    -159,     0,    25,     0,     0,    13,     0,    14,    15,    12,
       0,     0,     0,     0,     0,     0,    13,     0,    14,    15,
       0,    20,    21,    75,    23,     0,   190,     0,     0,    25,
       0,     0,    20,    21,    75,    23,    12,   192,     0,     0,
      25,     0,     0,    13,     0,    14,    15,    12,     0,     0,
       0,     0,     0,     0,    13,     0,    14,    15,     0,    20,
      21,    75,    23,     0,   194,     0,     0,    25,     0,     0,
      20,    21,    75,    23,    12,   196,     0,     0,    25,     0,
       0,    13,     0,    14,    15,    12,     0,     0,     0,     0,
       0,     0,    13,     0,    14,    15,     0,    20,    21,    75,
      23,     0,   249,     0,     0,    25,     0,     0,    20,    21,
      75,    23,    12,   251,     0,     0,    25,     0,     0,    13,
       0,    14,    15,    12,     0,     0,     0,     0,     0,     0,
      13,     0,    14,    15,     0,    20,    21,    75,    23,     0,
     288,     0,     0,    25,     0,     0,    20,    21,    75,    23,
      12,     0,     0,     0,    25,     0,     0,    13,     0,    14,
      15,     0,    53,    54,    55,     0,    56,    57,     0,    58,
       0,    59,    60,    20,    21,    75,    23,     0,    61,    62,
       0,    25,    63,    64,     0,     0,    65,     0,     0,    66,
      67,   105,   106,   107,     0,   326,   109,   110,   111,     0,
       0,   112,     0,     0,     0,     0,     0,   113,   114,     0,
       0,   115,   116,     0,     0,     0,     0,     0,   -35,   -37,
     354,   355,   356,   357,   358,   359,   360,   361,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   362,     0,
     363,   364,   365,     0,   105,   106,   107,   366,   367,   109,
     110,   111,     0,     0,   112,     0,     0,     0,     0,     0,
     113,   114,     0,     0,   115,   116,     0,     0,   105,   106,
     107,     0,   160,   109,   110,   111,     0,     0,   112,     0,
       0,     0,     0,     0,   113,   114,     0,     0,   115,   116,
       0,     0,   105,   106,   107,     0,   310,   109,   110,   111,
       0,     0,   112,     0,     0,     0,     0,     0,   113,   114,
       0,     0,   115,   116,     0,     0,   105,   106,   107,     0,
    -158,   109,   110,   111,     0,     0,   112,     0,     0,     0,
       0,     0,   113,   114,     0,     0,   115,   116,     0,     0,
     105,   106,   107,     0,   340,   109,   110,   111,     0,     0,
     112,     0,     0,     0,     0,     0,   113,   114,     0,     0,
     115,   116,     0,     0,   105,   106,   107,     0,   342,   109,
     110,   111,     0,     0,   112,     0,     0,     0,     0,     0,
     113,   114,     0,     0,   115,   116,     0,     0,   105,   106,
     107,     0,   343,   109,   110,   111,     0,     0,   112,     0,
       0,     0,     0,     0,   113,   114,     0,     0,   115,   116,
       0,     0,   105,   106,   107,     0,   376,   109,   110,   111,
       0,     0,   112,     0,     0,     0,     0,     0,   113,   114,
       0,     0,   115,   116,     0,   105,   106,   107,     0,   309,
     109,   110,   111,     0,     0,   112,     0,     0,     0,     0,
       0,   113,   114,     0,     0,   115,   116,     0,   105,   106,
     107,    24,   108,   109,   110,   111,     0,     0,   112,     0,
       0,     0,     0,     0,   113,   114,     0,     0,   115,   116,
     105,   106,   107,     0,   177,   109,   110,   111,     0,     0,
     112,     0,     0,     0,     0,     0,   113,   114,     0,     0,
     115,   116,   105,   106,   107,     0,   282,   109,   110,   111,
       0,     0,   112,     0,     0,     0,     0,     0,   113,   114,
       0,     0,   115,   116,   105,   106,   107,     0,   324,   109,
     110,   111,     0,     0,   112,     0,     0,     0,     0,     0,
     113,   114,     0,     0,   115,   116,   105,   106,   107,     0,
       0,   109,   110,   111,     0,     0,   112,     0,     0,     0,
       0,     0,   113,   114,     0,     0,   115,   116,    53,    54,
      55,     0,   325,    57,     0,    58,     0,     0,    60,     0,
       0,     0,     0,     0,    61,    62,     0,     0,    63,    64,
      53,    54,    55,     0,     0,    57,     0,    58,     0,     0,
      60,     0,     0,     0,     0,     0,    61,    62,     0,     0,
      63,    64,    53,    54,    55,     0,     0,    57,     0,    58,
       0,     0,    60,     0,     0,   105,   106,   107,    61,    62,
     109,   110,   111,     0,     0,   112,    53,    54,    55,     0,
       0,    57,     0,    58,     0,     0,    60
};

static const yytype_int16 yycheck[] =
{
      16,    13,    71,   165,     1,   143,     1,   278,    20,   280,
     281,    15,    21,    25,     1,     1,     1,    36,    34,   200,
      15,    16,     1,     1,    10,    13,    14,    36,     3,     4,
       5,     6,    16,    45,     1,    39,    15,    16,   200,     1,
       1,    53,    54,    55,    41,    57,    58,   318,    60,    61,
      62,    63,    64,   234,    39,    42,   237,    36,    70,     1,
      38,    73,     1,    42,    42,   134,   135,   136,    43,    81,
       1,    38,   234,    41,    36,   237,   214,    38,     1,    95,
     218,     1,   321,     1,   100,    38,   102,    16,    41,    27,
      38,    11,    41,    31,   106,   107,    38,    36,    42,    38,
      20,   113,   114,   115,   116,    27,   118,    38,   120,    31,
       1,   382,   351,    36,   295,    35,   132,    37,    36,    15,
      16,    12,    13,    14,    15,    16,    17,    18,    19,     1,
      16,    22,    16,   295,   203,   204,    44,    28,    29,    11,
      39,    32,    33,   155,    16,    36,    18,    40,    20,    21,
     166,    42,    42,    12,    13,    14,   168,    13,    14,   175,
      19,    38,    34,    35,    36,    37,   178,    17,   180,    23,
      42,   183,    18,    14,   186,    40,   188,   189,    12,    13,
      14,    10,    39,    17,    18,    19,    38,    36,    22,    16,
     259,   260,    39,    41,    28,    29,    12,    13,    14,   211,
     212,     0,     1,    38,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    36,    40,   227,    31,   229,   230,    18,
      39,    20,    21,    14,    41,    24,    25,    26,    40,    42,
      10,    30,   244,    42,    39,    34,    35,    36,    37,    38,
      12,    13,    14,    42,    38,   261,    18,    19,    43,    39,
     262,    38,   264,   265,     1,    41,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    16,    40,    36,    43,    40,
     339,    18,    39,    20,    21,    40,    40,    24,    25,    26,
      42,   297,    39,    30,   300,    43,    39,    34,    35,    36,
      37,    38,    39,     1,   306,    42,    36,    39,    41,    38,
     164,    36,    40,    11,    40,    39,    43,    15,    39,   321,
      18,    39,    20,    21,    39,   331,    40,   333,    39,   335,
      43,   337,    40,    39,    15,    40,    34,    35,    36,    37,
      12,    13,    14,   344,    42,    17,    90,    19,    97,   351,
      22,   275,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    -1,   369,    -1,    -1,    -1,    -1,   374,    -1,
       1,    43,     3,     4,     5,     6,     7,     8,     9,    10,
     386,    12,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    24,    25,    26,    -1,
      -1,     1,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    11,     1,    -1,    42,    15,    -1,    -1,    18,    -1,
      20,    21,    11,    -1,    -1,    -1,    15,    -1,    -1,    18,
      -1,    20,    21,    -1,    34,    35,    36,    37,    -1,    -1,
       1,    -1,    42,    -1,    -1,    34,    35,    36,    37,    -1,
      11,     1,    -1,    42,    15,    -1,    -1,    18,    -1,    20,
      21,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      20,    21,    -1,    34,    35,    36,    37,    -1,     1,    -1,
      -1,    42,    -1,    -1,    34,    35,    36,    37,    11,     1,
      40,    -1,    42,    -1,    -1,    18,    -1,    20,    21,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,
      -1,    34,    35,    36,    37,    -1,     1,    -1,    -1,    42,
      -1,    -1,    34,    35,    36,    37,    11,     1,    -1,    -1,
      42,    -1,    -1,    18,    -1,    20,    21,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    34,
      35,    36,    37,    -1,     1,    -1,    -1,    42,    -1,    -1,
      34,    35,    36,    37,    11,     1,    -1,    -1,    42,    -1,
      -1,    18,    -1,    20,    21,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    20,    21,    -1,    34,    35,    36,
      37,    -1,     1,    -1,    -1,    42,    -1,    -1,    34,    35,
      36,    37,    11,     1,    -1,    -1,    42,    -1,    -1,    18,
      -1,    20,    21,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,    -1,    34,    35,    36,    37,    -1,
       1,    -1,    -1,    42,    -1,    -1,    34,    35,    36,    37,
      11,    -1,    -1,    -1,    42,    -1,    -1,    18,    -1,    20,
      21,    -1,    12,    13,    14,    -1,    16,    17,    -1,    19,
      -1,    21,    22,    34,    35,    36,    37,    -1,    28,    29,
      -1,    42,    32,    33,    -1,    -1,    36,    -1,    -1,    39,
      40,    12,    13,    14,    -1,    16,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      23,    24,    25,    -1,    12,    13,    14,    30,    31,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    33,    -1,    -1,    12,    13,
      14,    -1,    40,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      -1,    -1,    12,    13,    14,    -1,    40,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,    -1,    -1,    12,    13,    14,    -1,
      40,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    -1,    -1,
      12,    13,    14,    -1,    40,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    -1,    -1,    12,    13,    14,    -1,    40,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    33,    -1,    -1,    12,    13,
      14,    -1,    40,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      -1,    -1,    12,    13,    14,    -1,    40,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,    -1,    12,    13,    14,    -1,    39,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    33,    -1,    12,    13,
      14,    38,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      12,    13,    14,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    33,    12,    13,    14,    -1,
      -1,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    12,    13,
      14,    -1,    16,    17,    -1,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      12,    13,    14,    -1,    -1,    17,    -1,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    12,    13,    14,    -1,    -1,    17,    -1,    19,
      -1,    -1,    22,    -1,    -1,    12,    13,    14,    28,    29,
      17,    18,    19,    -1,    -1,    22,    12,    13,    14,    -1,
      -1,    17,    -1,    19,    -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    18,    20,    21,    24,    25,    26,    30,
      34,    35,    36,    37,    38,    42,    47,    48,    49,    56,
      58,    59,    66,    71,    80,    85,    92,    93,    94,    97,
     100,   103,   104,   109,   114,   117,   118,   120,   122,   128,
     133,   134,   135,    12,    13,    14,    16,    17,    19,    21,
      22,    28,    29,    32,    33,    36,    39,    40,    36,    41,
      95,     1,    42,   101,     1,    36,   128,     1,   120,     1,
      36,    57,     1,    36,     1,   128,     1,    15,    36,   123,
     121,   128,    21,    36,    16,    27,    31,    60,    61,   120,
      41,    96,    98,    16,   128,    12,    13,    14,    16,    17,
      18,    19,    22,    28,    29,    32,    33,   128,    15,   128,
      15,   128,   128,   128,    16,   128,   128,   128,   128,   128,
      16,    42,    99,   128,    47,    44,   110,   128,     1,   105,
     108,     1,    10,    38,     1,    36,    38,    87,    88,    90,
     128,    67,     1,    41,    40,   119,    15,    16,    42,    46,
      40,    51,    36,    42,    50,    81,    41,   120,    62,    60,
      65,     1,    39,     1,   120,    23,   120,    16,   131,     1,
      15,   128,     1,    15,   128,    17,   129,    18,   130,   132,
       1,   128,     1,   128,     1,   128,     1,   128,   128,   128,
      74,    78,   120,    47,    47,    47,   102,    10,    39,   107,
       1,    38,    42,    87,    38,    15,    89,     1,    86,    39,
      41,    68,    69,     1,    38,   128,    36,   124,    39,     1,
      15,    16,    52,    16,    72,    76,    52,    43,    48,    82,
      83,    84,   120,   128,    31,    39,     1,   120,   128,     1,
     128,     1,   128,   128,   128,   128,    82,    40,    47,    47,
     111,    41,    42,    10,    42,   106,   128,   128,    39,    87,
       1,    11,    20,    35,    37,    43,    39,    87,    38,    41,
      38,    70,    16,    16,     1,   126,   128,   128,     1,   128,
      82,    40,    82,    36,    40,    43,    63,   128,    39,    40,
      79,    40,    47,    47,   120,   128,    42,   128,   128,    39,
      40,    39,    43,    91,    36,    88,    39,    61,    38,    61,
      61,    43,   125,   127,    16,    16,    16,    53,    54,    55,
      40,    77,    82,    41,   120,    75,   120,   115,    40,   112,
      40,   128,    40,    40,    43,    39,    61,    39,    39,   126,
      40,    43,    39,    40,     3,     4,     5,     6,     7,     8,
       9,    10,    21,    23,    24,    25,    30,    31,   136,    73,
     120,   120,   120,   120,   116,    47,    40,    36,    90,    39,
     126,   120,    64,   120,    40,    61,   113,   120
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    48,    48,    50,    49,    51,    49,    49,    49,
      49,    52,    52,    52,    52,    53,    52,    54,    52,    55,
      52,    56,    57,    56,    58,    59,    59,    60,    60,    62,
      63,    64,    61,    65,    61,    61,    61,    61,    67,    66,
      68,    66,    69,    66,    70,    66,    66,    71,    72,    73,
      71,    74,    75,    71,    76,    77,    71,    78,    79,    71,
      81,    80,    82,    82,    82,    83,    84,    86,    85,    85,
      87,    87,    89,    88,    88,    91,    90,    90,    90,    90,
      90,    90,    92,    92,    92,    92,    93,    93,    95,    94,
      96,    97,    97,    97,    98,    97,    99,    97,    97,   101,
     102,   100,   103,   103,   105,   104,   106,   104,   107,   104,
     108,   104,   104,   110,   111,   112,   113,   109,   109,   115,
     114,   116,   114,   117,   118,   118,   119,   118,   121,   120,
     123,   124,   125,   122,   122,   127,   126,   126,   126,   126,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   129,
     128,   130,   128,   131,   128,   132,   128,   128,   128,   128,
     128,   133,   133,   133,   133,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     0,     4,     0,     4,     3,     3,
       4,     3,     3,     3,     1,     0,     4,     0,     4,     0,
       4,     1,     0,     3,     4,     3,     1,     3,     2,     0,
       0,     0,     8,     0,     5,     2,     1,     0,     0,     7,
       0,     8,     0,     7,     0,     7,     3,     2,     0,     0,
       8,     0,     0,     8,     0,     0,     7,     0,     0,     7,
       0,     5,     3,     1,     1,     2,     2,     0,     6,     1,
       1,     1,     0,     4,     1,     0,     6,     3,     4,     3,
       3,     3,     5,     4,     5,     6,     5,     3,     0,     3,
       2,     2,     4,     5,     0,     3,     0,     4,     4,     0,
       0,     6,     6,     1,     0,     7,     0,     7,     0,     7,
       0,     8,     6,     0,     0,     0,     0,    11,     1,     0,
       8,     0,     9,     2,     2,     3,     0,     5,     0,     4,
       0,     0,     0,     7,     3,     0,     4,     3,     1,     0,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     0,
       4,     0,     4,     0,     4,     0,     4,     1,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     4,     4,     3,
       3,     3,     3,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* PROGRAM: PROGRAM STATEMENT  */
#line 187 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1772 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 193 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1778 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 196 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1784 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 197 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1790 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 198 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1796 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 199 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1802 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 200 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1808 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 201 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1814 "parser.tab.c"
    break;

  case 14: /* STATEMENT: ENUM_CALL_STT  */
#line 202 "parser.y"
                                                            {printf("#[Parsed_Enum_USAGE]# ");}
#line 1820 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error SEMICOLON  */
#line 205 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1826 "parser.tab.c"
    break;

  case 18: /* STATEMENT: error '}'  */
#line 206 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1832 "parser.tab.c"
    break;

  case 19: /* STATEMENT: error ')'  */
#line 207 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1838 "parser.tab.c"
    break;

  case 20: /* TYPE: INT  */
#line 215 "parser.y"
                            { (yyval.str) = "int";   }
#line 1844 "parser.tab.c"
    break;

  case 21: /* TYPE: FLOAT  */
#line 216 "parser.y"
                            { (yyval.str) = "float"; }
#line 1850 "parser.tab.c"
    break;

  case 22: /* TYPE: BOOL  */
#line 217 "parser.y"
                            { (yyval.str) = "bool";  }
#line 1856 "parser.tab.c"
    break;

  case 23: /* TYPE: STRING  */
#line 218 "parser.y"
                            { (yyval.str) = "string";}
#line 1862 "parser.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 222 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0);   assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1868 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 222 "parser.y"
                                                                                                                                                         {printf("#[Parsed_Declaration]# "); }
#line 1874 "parser.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 223 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0); assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1880 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 223 "parser.y"
                                                                                                                                                         {printf("#[Parsed_CONST_Declaration]# "); }
#line 1886 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 224 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);pErr(yylineno);}
#line 1892 "parser.tab.c"
    break;

  case 29: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 225 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);pErr(yylineno);}
#line 1898 "parser.tab.c"
    break;

  case 30: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 226 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);pErr(yylineno);}
#line 1904 "parser.tab.c"
    break;

  case 31: /* DECLARATION_TAIL: EQ EXPRESSION SEMICOLON  */
#line 231 "parser.y"
                                                                                            {StAssPush(strdup(IdentifierHolder)); StAssPrint("OVER", 1); StAssPrint("STORE", 1); StAssPrint("DROP", 1);}
#line 1910 "parser.tab.c"
    break;

  case 32: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 232 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 1916 "parser.tab.c"
    break;

  case 33: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 233 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);pErr(yylineno);}
#line 1922 "parser.tab.c"
    break;

  case 35: /* $@3: %empty  */
#line 235 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1928 "parser.tab.c"
    break;

  case 37: /* $@4: %empty  */
#line 236 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1934 "parser.tab.c"
    break;

  case 39: /* $@5: %empty  */
#line 237 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1940 "parser.tab.c"
    break;

  case 41: /* RETURN_STT: RETURN  */
#line 244 "parser.y"
                                                {int dum = 0;StAssPrint("POP\tPC",1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1946 "parser.tab.c"
    break;

  case 42: /* $@6: %empty  */
#line 245 "parser.y"
                         {assign_index =func_index;}
#line 1952 "parser.tab.c"
    break;

  case 43: /* RETURN_STT: RETURN $@6 EXPRESSION  */
#line 245 "parser.y"
                                                                            { return_exist = 1; StAssPrint("OVER",1);int dum = 0;StAssPrint("POP\tPC",1);StAssPrint("DNEXT", 1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1958 "parser.tab.c"
    break;

  case 44: /* helperSWITCH: SWITCH IDENTIFIER ':' '{'  */
#line 247 "parser.y"
                                          {strcpy(switcher, (yyvsp[-2].str));}
#line 1964 "parser.tab.c"
    break;

  case 45: /* SWITCH_STT: helperSWITCH CASES '}'  */
#line 250 "parser.y"
                                        {StAssPrintLBL(0,1);}
#line 1970 "parser.tab.c"
    break;

  case 47: /* DEFAULTCASE: DEFAULT ':' BLOCK  */
#line 255 "parser.y"
                                  {StAssJmp("JMP", "END",&SMLabel_End, 0,0); }
#line 1976 "parser.tab.c"
    break;

  case 48: /* DEFAULTCASE: DEFAULT BLOCK  */
#line 256 "parser.y"
                                {printf("\n\n=====ERROR====\n missing colon ':' at DEFAULT CASE of switch, error at line %d\n\n", yylineno); pErr(yylineno);}
#line 1982 "parser.tab.c"
    break;

  case 49: /* $@7: %empty  */
#line 259 "parser.y"
                     {StAssPush(switcher);}
#line 1988 "parser.tab.c"
    break;

  case 50: /* $@8: %empty  */
#line 259 "parser.y"
                                                       {StAssPrint("EQ", 1); StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 1994 "parser.tab.c"
    break;

  case 51: /* $@9: %empty  */
#line 259 "parser.y"
                                                                                                                                   {StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2000 "parser.tab.c"
    break;

  case 53: /* $@10: %empty  */
#line 260 "parser.y"
                              {printf("\n\n=====ERROR====\n DEFAULT CASE must be written at the end of the switch statement, error at line %d\n\n", yylineno); pErr(yylineno);}
#line 2006 "parser.tab.c"
    break;

  case 55: /* CASES: DEFAULTCASE DEFAULTCASE  */
#line 261 "parser.y"
                                                                {printf("\n\n=====ERROR====\n only 1 DEFAULT CASE is allowed in the switch statement error, at line %d\n\n", yylineno); pErr(yylineno);}
#line 2012 "parser.tab.c"
    break;

  case 58: /* $@11: %empty  */
#line 273 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2018 "parser.tab.c"
    break;

  case 60: /* $@12: %empty  */
#line 274 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); pErr(yylineno);}
#line 2024 "parser.tab.c"
    break;

  case 62: /* $@13: %empty  */
#line 275 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);pErr(yylineno);}
#line 2030 "parser.tab.c"
    break;

  case 64: /* $@14: %empty  */
#line 276 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2036 "parser.tab.c"
    break;

  case 66: /* ERRONOUS_SWITCH_STT: helperSWITCH CASES error  */
#line 277 "parser.y"
                                           {printf("\n\n=====ERROR====\n unclosed '}' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2042 "parser.tab.c"
    break;

  case 68: /* $@15: %empty  */
#line 290 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2048 "parser.tab.c"
    break;

  case 69: /* $@16: %empty  */
#line 290 "parser.y"
                                                                                                                    {func_index = st_insert((yyvsp[-5].str), (yyvsp[-4].str),"func",0); popArgs();}
#line 2054 "parser.tab.c"
    break;

  case 71: /* $@17: %empty  */
#line 291 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2060 "parser.tab.c"
    break;

  case 72: /* $@18: %empty  */
#line 291 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-4].str),"func",0); popArgs();}
#line 2066 "parser.tab.c"
    break;

  case 74: /* $@19: %empty  */
#line 292 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2072 "parser.tab.c"
    break;

  case 75: /* $@20: %empty  */
#line 292 "parser.y"
                                                                                                                    {func_index=st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2078 "parser.tab.c"
    break;

  case 77: /* $@21: %empty  */
#line 293 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2084 "parser.tab.c"
    break;

  case 78: /* $@22: %empty  */
#line 293 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-3].str),"func",0);}
#line 2090 "parser.tab.c"
    break;

  case 80: /* $@23: %empty  */
#line 298 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));pErr(yylineno);}
#line 2096 "parser.tab.c"
    break;

  case 81: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@23 ARGS ')'  */
#line 298 "parser.y"
                                                                                                                                                                                                                   {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2102 "parser.tab.c"
    break;

  case 85: /* ERRONOUS_ARGS: ',' ARGS  */
#line 313 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);pErr(yylineno);}
#line 2108 "parser.tab.c"
    break;

  case 86: /* ARG_DECL: TYPE IDENTIFIER  */
#line 316 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1); char* buf=(yyvsp[0].str); argumentList[argPointer]=buf;argPointer++;}
#line 2114 "parser.tab.c"
    break;

  case 87: /* $@24: %empty  */
#line 323 "parser.y"
                                      { is_enum =1;}
#line 2120 "parser.tab.c"
    break;

  case 88: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' $@24 ENUM_HELPER '}'  */
#line 323 "parser.y"
                                                                              { st_insert("enum" , (yyvsp[-4].str), "var" , 0); is_enum=0; enumCNT=1;}
#line 2126 "parser.tab.c"
    break;

  case 92: /* $@25: %empty  */
#line 329 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++;  st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int(  enum_arg_count-1,st_index-1); }
#line 2132 "parser.tab.c"
    break;

  case 94: /* ENUM_ARGS: IDENTIFIER  */
#line 330 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++; st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int( enum_arg_count-1,st_index-1);  }
#line 2138 "parser.tab.c"
    break;

  case 95: /* $@26: %empty  */
#line 336 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++ ; st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2144 "parser.tab.c"
    break;

  case 97: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ DIGIT  */
#line 337 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++;  st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2150 "parser.tab.c"
    break;

  case 98: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ error ','  */
#line 338 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2156 "parser.tab.c"
    break;

  case 99: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ FLOAT_DIGIT  */
#line 339 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2162 "parser.tab.c"
    break;

  case 100: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ STRING_LITERAL  */
#line 340 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2168 "parser.tab.c"
    break;

  case 101: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ BOOL_LITERAL  */
#line 341 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2174 "parser.tab.c"
    break;

  case 102: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 345 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2180 "parser.tab.c"
    break;

  case 103: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 346 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2186 "parser.tab.c"
    break;

  case 104: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 348 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2192 "parser.tab.c"
    break;

  case 105: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER error '{' ENUM_HELPER '}'  */
#line 349 "parser.y"
                                                            {printf("\n\n=====ERROR====\n UnExpected IDENTIFIER in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2198 "parser.tab.c"
    break;

  case 106: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER EQ IDENTIFIER SEMICOLON  */
#line 353 "parser.y"
                                                               { StAssPush((yyvsp[-3].str));StAssPush((yyvsp[-1].str));StAssPrint("STORE",1); st_insert((yyvsp[-4].str) , (yyvsp[-3].str), "var_enum" , 0); assign_enum(st_index-1, (yyvsp[-4].str),(yyvsp[-1].str)); int i= lookup((yyvsp[-4].str), 0); symbolTable[i].isUsed=1; }
#line 2204 "parser.tab.c"
    break;

  case 107: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER SEMICOLON  */
#line 354 "parser.y"
                                                   { st_insert((yyvsp[-2].str) , (yyvsp[-1].str), "var_enum" , 0); int i= lookup((yyvsp[-2].str),0); symbolTable[i].isUsed=1;}
#line 2210 "parser.tab.c"
    break;

  case 108: /* $@27: %empty  */
#line 358 "parser.y"
                   {printIF();}
#line 2216 "parser.tab.c"
    break;

  case 109: /* IF_STT_HELPER: IF $@27 EXPRESSION  */
#line 358 "parser.y"
                                           {StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2222 "parser.tab.c"
    break;

  case 110: /* IF_STT_HELPER1: ':' BLOCK  */
#line 361 "parser.y"
                                                            {controlTerminator(0);  StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2228 "parser.tab.c"
    break;

  case 111: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1  */
#line 365 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2234 "parser.tab.c"
    break;

  case 112: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE BLOCK  */
#line 366 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2240 "parser.tab.c"
    break;

  case 113: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE error '}'  */
#line 367 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2246 "parser.tab.c"
    break;

  case 114: /* $@28: %empty  */
#line 368 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2252 "parser.tab.c"
    break;

  case 116: /* $@29: %empty  */
#line 369 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2258 "parser.tab.c"
    break;

  case 118: /* IF_STT: IF_STT_HELPER ':' error '}'  */
#line 370 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2264 "parser.tab.c"
    break;

  case 119: /* $@30: %empty  */
#line 379 "parser.y"
                      {printWHILE(); StAssPrintLBL(1, 0);}
#line 2270 "parser.tab.c"
    break;

  case 120: /* $@31: %empty  */
#line 379 "parser.y"
                                                                      {StAssJmp("JNZ", "END",&SMLabel_End, 0,0);}
#line 2276 "parser.tab.c"
    break;

  case 121: /* WHILE_STT: WHILE $@30 EXPRESSION $@31 ':' BLOCK  */
#line 379 "parser.y"
                                                                                                                            {StAssJmp("JMP", "LBL",&SMLabel_Else, 1,0); StAssPrintLBL(0, 1);}
#line 2282 "parser.tab.c"
    break;

  case 124: /* $@32: %empty  */
#line 392 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2288 "parser.tab.c"
    break;

  case 126: /* $@33: %empty  */
#line 393 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2294 "parser.tab.c"
    break;

  case 128: /* $@34: %empty  */
#line 394 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2300 "parser.tab.c"
    break;

  case 130: /* $@35: %empty  */
#line 395 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2306 "parser.tab.c"
    break;

  case 132: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 396 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);pErr(yylineno);}
#line 2312 "parser.tab.c"
    break;

  case 133: /* $@36: %empty  */
#line 403 "parser.y"
                        {in_loop = 1;}
#line 2318 "parser.tab.c"
    break;

  case 134: /* $@37: %empty  */
#line 403 "parser.y"
                                                 {StAssForHeader();}
#line 2324 "parser.tab.c"
    break;

  case 135: /* $@38: %empty  */
#line 403 "parser.y"
                                                                               {StAssForMiddle();}
#line 2330 "parser.tab.c"
    break;

  case 136: /* $@39: %empty  */
#line 403 "parser.y"
                                                                                                                {StAssPrintLBL(1,1); in_loop = 0;}
#line 2336 "parser.tab.c"
    break;

  case 137: /* FOR_STT: FOR '(' $@36 STATEMENT $@37 STATEMENT $@38 STATEMENT ')' $@39 BLOCK  */
#line 403 "parser.y"
                                                                                                                                                          {StAssJmp("JMP", "Label", &ForHeaderLabel,1,0); StAssPrintLBL(0,1);}
#line 2342 "parser.tab.c"
    break;

  case 139: /* $@40: %empty  */
#line 408 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2348 "parser.tab.c"
    break;

  case 141: /* $@41: %empty  */
#line 409 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2354 "parser.tab.c"
    break;

  case 143: /* helperAssignmentRule: IDENTIFIER EQ  */
#line 416 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); StAssPush((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str),1);}
#line 2360 "parser.tab.c"
    break;

  case 144: /* assignmentSTT: helperAssignmentRule SEMICOLON  */
#line 420 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2366 "parser.tab.c"
    break;

  case 145: /* assignmentSTT: helperAssignmentRule EXPRESSION SEMICOLON  */
#line 421 "parser.y"
                                                                 {StAssPrint("STORE", 1); CodeGenAss();printf("#[Parsed_Assignment]# ");}
#line 2372 "parser.tab.c"
    break;

  case 146: /* $@42: %empty  */
#line 422 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str),1); StAssPush((yyvsp[-1].str));}
#line 2378 "parser.tab.c"
    break;

  case 147: /* assignmentSTT: IDENTIFIER error $@42 EXPRESSION SEMICOLON  */
#line 422 "parser.y"
                                                                                                                                                        {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2384 "parser.tab.c"
    break;

  case 148: /* $@43: %empty  */
#line 427 "parser.y"
                    {scope_start();}
#line 2390 "parser.tab.c"
    break;

  case 149: /* BLOCK: '{' $@43 PROGRAM '}'  */
#line 427 "parser.y"
                                                                              {scope_end(); printf("#[Parsed_Block]# ");}
#line 2396 "parser.tab.c"
    break;

  case 150: /* $@44: %empty  */
#line 435 "parser.y"
                           {called_func_index = lookup((yyvsp[0].str),0); check_type(called_func_index); StAssPush("PC");}
#line 2402 "parser.tab.c"
    break;

  case 151: /* $@45: %empty  */
#line 435 "parser.y"
                                                                                                                   { is_param =1;}
#line 2408 "parser.tab.c"
    break;

  case 152: /* $@46: %empty  */
#line 435 "parser.y"
                                                                                                                                              { is_param =0; arg_count_check(called_func_index); arg_count=0; int dum=0; StAssJmp("JMP", (yyvsp[-4].str),&dum, 0,0);}
#line 2414 "parser.tab.c"
    break;

  case 153: /* FUNC_CALL: IDENTIFIER $@44 '(' $@45 USED_ARGS $@46 ')'  */
#line 435 "parser.y"
                                                                                                                                                                                                                                                               { printf("#[Parsed_Func_Call]# ");}
#line 2420 "parser.tab.c"
    break;

  case 154: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 436 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);pErr(yylineno);}
#line 2426 "parser.tab.c"
    break;

  case 155: /* $@47: %empty  */
#line 440 "parser.y"
                           { arg_count++; }
#line 2432 "parser.tab.c"
    break;

  case 157: /* USED_ARGS: error ',' USED_ARGS  */
#line 441 "parser.y"
                                                            {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2438 "parser.tab.c"
    break;

  case 158: /* USED_ARGS: EXPRESSION  */
#line 442 "parser.y"
                             {arg_count++ ;}
#line 2444 "parser.tab.c"
    break;

  case 160: /* EXPRESSION: IDENTIFIER  */
#line 449 "parser.y"
                                                { int i = lookup((yyvsp[0].str),0); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2450 "parser.tab.c"
    break;

  case 161: /* EXPRESSION: DIGIT  */
#line 450 "parser.y"
                                                { assign_int((yyvsp[0].num), assign_index) ; char numtostring[40]; itoa((yyvsp[0].num), numtostring, 10); pushVStack(numtostring); char dum[10]="$"; StAssPush(strcat(dum,numtostring));}
#line 2456 "parser.tab.c"
    break;

  case 162: /* EXPRESSION: FLOAT_DIGIT  */
#line 451 "parser.y"
                                                { assign_int((yyvsp[0].float_val), assign_index); char floattostring[40]; gcvt((yyvsp[0].float_val), 6, floattostring); pushVStack(floattostring); char dum[10]="$"; StAssPush(strcat(dum,floattostring));}
#line 2462 "parser.tab.c"
    break;

  case 163: /* EXPRESSION: BOOL_LITERAL  */
#line 452 "parser.y"
                                                { assign_int((yyvsp[0].bool_val), assign_index); if((yyvsp[0].bool_val)==true){pushVStack("true");StAssPush("$true");}else{pushVStack("false");StAssPush("$false");} }
#line 2468 "parser.tab.c"
    break;

  case 164: /* EXPRESSION: STRING_LITERAL  */
#line 453 "parser.y"
                                                { assign_str((yyvsp[0].str), assign_index); pushVStack((yyvsp[0].str));char buf[50]; strcpy(buf, "$");strcat(buf, (yyvsp[0].str)); StAssPush(buf);}
#line 2474 "parser.tab.c"
    break;

  case 165: /* EXPRESSION: CONSTANT  */
#line 454 "parser.y"
                                                { int i = lookup((yyvsp[0].str),0); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2480 "parser.tab.c"
    break;

  case 166: /* EXPRESSION: SUB EXPRESSION  */
#line 455 "parser.y"
                                                {StAssPrint("neg", 1);}
#line 2486 "parser.tab.c"
    break;

  case 167: /* EXPRESSION: EXPRESSION PLUS PLUS  */
#line 456 "parser.y"
                                                { pushVStack("+"); pushVStack("1"); CodeGenOp("ADD"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("ADD", 1); StAssPrint("STORE", 1);}
#line 2492 "parser.tab.c"
    break;

  case 168: /* EXPRESSION: EXPRESSION SUB SUB  */
#line 457 "parser.y"
                                                { pushVStack("-"); pushVStack("1"); CodeGenOp("SUB"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("SUB", 1); StAssPrint("STORE", 1);}
#line 2498 "parser.tab.c"
    break;

  case 169: /* $@48: %empty  */
#line 458 "parser.y"
                                                { pushVStack("+");}
#line 2504 "parser.tab.c"
    break;

  case 170: /* EXPRESSION: EXPRESSION PLUS $@48 EXPRESSION  */
#line 458 "parser.y"
                                                                                 {CodeGenOp("ADD"); StAssPrint("ADD", 1);}
#line 2510 "parser.tab.c"
    break;

  case 171: /* $@49: %empty  */
#line 460 "parser.y"
                                                { pushVStack("*");}
#line 2516 "parser.tab.c"
    break;

  case 172: /* EXPRESSION: EXPRESSION MUL $@49 EXPRESSION  */
#line 460 "parser.y"
                                                                                 {CodeGenOp("MUL"); StAssPrint("MUL", 1);}
#line 2522 "parser.tab.c"
    break;

  case 173: /* $@50: %empty  */
#line 461 "parser.y"
                                                { pushVStack("/");}
#line 2528 "parser.tab.c"
    break;

  case 174: /* EXPRESSION: EXPRESSION DIV $@50 EXPRESSION  */
#line 461 "parser.y"
                                                                                 {CodeGenOp("DIV"); StAssPrint("DIV", 1);}
#line 2534 "parser.tab.c"
    break;

  case 175: /* $@51: %empty  */
#line 464 "parser.y"
                                                {pushVStack("^");}
#line 2540 "parser.tab.c"
    break;

  case 176: /* EXPRESSION: EXPRESSION POW $@51 EXPRESSION  */
#line 464 "parser.y"
                                                                               {CodeGenOp("POW");}
#line 2546 "parser.tab.c"
    break;

  case 180: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 468 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);pErr(yylineno);}
#line 2552 "parser.tab.c"
    break;

  case 185: /* COMPARISONSTT: EXPRESSION GT EXPRESSION  */
#line 488 "parser.y"
                                                        {pushVStack(">"); CodeGenLogical(); StAssPrint("GT", 1);}
#line 2558 "parser.tab.c"
    break;

  case 186: /* COMPARISONSTT: EXPRESSION LT EXPRESSION  */
#line 489 "parser.y"
                                                        {pushVStack("<"); CodeGenLogical(); StAssPrint("LT", 1);}
#line 2564 "parser.tab.c"
    break;

  case 187: /* COMPARISONSTT: EXPRESSION LT EQ EXPRESSION  */
#line 490 "parser.y"
                                                        {pushVStack("<="); CodeGenLogical(); StAssPrint("LE", 1);}
#line 2570 "parser.tab.c"
    break;

  case 188: /* COMPARISONSTT: EXPRESSION GT EQ EXPRESSION  */
#line 491 "parser.y"
                                                        {pushVStack(">="); CodeGenLogical(); StAssPrint("GE", 1);}
#line 2576 "parser.tab.c"
    break;

  case 189: /* COMPARISONSTT: EXPRESSION EQUALITY EXPRESSION  */
#line 492 "parser.y"
                                                        {pushVStack("="); CodeGenLogical(); StAssPrint("EQ", 1);}
#line 2582 "parser.tab.c"
    break;

  case 190: /* COMPARISONSTT: EXPRESSION NEG_EQUALITY EXPRESSION  */
#line 493 "parser.y"
                                                        {pushVStack("!="); CodeGenLogical(); StAssPrint("NE", 1);}
#line 2588 "parser.tab.c"
    break;

  case 191: /* COMPARISONSTT: EXPRESSION LOGIC_AND EXPRESSION  */
#line 494 "parser.y"
                                                        {pushVStack("and"); CodeGenLogical(); StAssPrint("AND", 1);}
#line 2594 "parser.tab.c"
    break;

  case 192: /* COMPARISONSTT: EXPRESSION LOGIC_OR EXPRESSION  */
#line 495 "parser.y"
                                                        {pushVStack("or"); CodeGenLogical(); StAssPrint("OR", 1);}
#line 2600 "parser.tab.c"
    break;

  case 193: /* COMPARISONSTT: LOGIC_NOT EXPRESSION  */
#line 496 "parser.y"
                                                        {StAssPrint("neg", 1);}
#line 2606 "parser.tab.c"
    break;

  case 195: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 501 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2612 "parser.tab.c"
    break;

  case 196: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 502 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2618 "parser.tab.c"
    break;

  case 197: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 503 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2624 "parser.tab.c"
    break;

  case 198: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 504 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2630 "parser.tab.c"
    break;

  case 199: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 505 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2636 "parser.tab.c"
    break;

  case 200: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 506 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2642 "parser.tab.c"
    break;

  case 201: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 507 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2648 "parser.tab.c"
    break;

  case 202: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 508 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2654 "parser.tab.c"
    break;

  case 203: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 509 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2660 "parser.tab.c"
    break;

  case 204: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 510 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2666 "parser.tab.c"
    break;

  case 205: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 511 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2672 "parser.tab.c"
    break;

  case 206: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 512 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2678 "parser.tab.c"
    break;

  case 207: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 513 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2684 "parser.tab.c"
    break;

  case 208: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 514 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2690 "parser.tab.c"
    break;

  case 209: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 515 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2696 "parser.tab.c"
    break;

  case 210: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 516 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2702 "parser.tab.c"
    break;

  case 211: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 517 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2708 "parser.tab.c"
    break;


#line 2712 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 536 "parser.y"




//------------------------------------------ FUNCTIONS ---------------------------------------------
void yyerror(char *s) { 
 fprintf(stderr, "line %d: %s\n", yylineno, s); 
} 
int yywrap()
{
    return 1;
}
//--------------------------------------------------- SYMBOL TABLE---------------------------------------------
int is_exist(char* name){
    for (int i = 0; i < st_index; i++){
        //TODO SCOPE CHECK
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == block_number && symbolTable[i].outOfScope == 0){
            return symbolTable[i].declareLine;
        }
    }
    return -1;
}
int lookup(char* name, int is_assignment) {
    // 
    // This method returns -1 if the symbol does not exist in the symbol table. 
    // If the symbol exists, it returns its index in the table.
    // loop on the table from down to up to take the variable from the closest scope as closet one will
    // be with higher index in the table

     if ( is_enum == 1) { return -1;} 
     if ( symbolTable[assign_index].type == "var_enum")
     {  
        assign_enum (assign_index, symbolTable[assign_index].dataType, name);
        return -1;
    }     
    for (int i = st_index-1 ; i >= 0; i--){
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].outOfScope == 0 ){
           
            if (symbolTable[i].isInit == 0 && strcmp(symbolTable[i].type, "var") == 0 && symbolTable[i].isArg == 0 ) 
            {   
            // if ( i != assign_index)// 3shan lw kan el var 3la el LHS s3tha 3ady ex: int x=9; int z; z =x;
            if (is_assignment == 0)
            {
                printf("\n !!!!!!!!!!!! Error at line %d: %s used before initialized !!!!!!!!!!!\n", line_number, name); sErr();}
            }
            symbolTable[i].isUsed=1;
            return i;
        }
    }
    printf("\n !!!!!!!!!!!! Error at line %d: %s undeclared identifier in this scope !!!!!!!!!!!\n", line_number, name);
    sErr();
    return -1;
}
//-------------------------------------- INSERT IN SYMBOL TABLE  ----------------------------------I
int st_insert(char* data_type, char* name, char* type ,int is_arg ) {

    //------ create new entry
    struct Entry newEntry ;
    //----- check if name is already in symbol table
    int L=is_exist(name) ;
    if (L != -1){
        printf("\n !!!!!!!!!!!! Error at line %d: %s is already declared in this scope at line %d !!!!!!!!!!!\n",line_number, name, L); 
        sErr();
        is_changed=0;
        return -1;
        }
    //------ set new entry values
    newEntry.name = name;
    newEntry.dataType = data_type;
    newEntry.declareLine = line_number;
    newEntry.type = type;
    newEntry.id = st_index;
    newEntry.isArg = is_arg;
    newEntry.outOfScope = 0;
    newEntry.isInit = 0;// assume all uninitialized untill assign
    newEntry.isUsed = 0; // assume all unused untill used
    //----- set scope (if it's an argument, scope is the next scope)
    if (is_arg == 1 || in_loop == 1){ newEntry.scope = block_number+1;}
    else {newEntry.scope = scope_stack[scope_index];}
    //------ if it's a function, set argCount and argList
    if ( strcmp(type, "func") == 0){
        int j =0;        
        for(int i=0; i<st_index; i++) {
            if ( symbolTable[i].isArg  && symbolTable[i].scope == (block_number +1)){
                newEntry.argList[j] = symbolTable[i].id;
                j++;
            }
            }
            newEntry.argCount = j;
    }
    //------ insert new entry to symbol table
    symbolTable[st_index] = newEntry;
      // 
    if (strcmp( data_type, "enum") == 0 )
    {
        symbolTable[st_index].isInit=1;
        // // create enum entry 
        struct enumEntry newEnumEntry ;
        // initialize enum keys and values
         for (int i = 0; i < 100; i++)
        {
            newEnumEntry.keys[i]  = "";
            newEnumEntry.values[i]  = 0;
        }
        // fill enum keys and values
        for (int i = 0; i < enum_arg_count; i++)
        {
            newEnumEntry.keys[i] = enum_keys[i];
            newEnumEntry.values[i] = enum_values[i];
        }
        symbolTable[st_index].enumValue = newEnumEntry;
        enum_arg_count=0;
        // clear enum keys and values
        for (int i = 0; i < 100; i++)
        {
            enum_keys[i] = "";
            enum_values[i] = 0;
        }
    }
    st_index++; // increment symbol table index
    st_log(); // log symbol table
    return st_index-1;
}
//----------------------------------------------- PRINT SYMBOL TABLE ----------------------------------------------------
void st_log() {
    //----- write symbol table to file
    FILE *log_fp= fopen("symbol_table_logs.log", "a");
    //----- check if file is opened
    if(log_fp == NULL) {
        printf("can't open symbol_table_logs.log file!\n");
        exit(1);
    }
    //----- write symbol table header
    fprintf(log_fp, "ID, Line, Scope, Name, Type, DataType, isInit, Value, Args\n");
    //----- write symbol table entries
    for(int i=0; i< st_index; i++) {
        struct Entry *entry = &symbolTable[i];
        fprintf(log_fp, "%d, %d, %d, %s, %s, %s, %d, ", entry->id, entry->declareLine, entry->scope, entry->name,entry->type, entry->dataType,entry->isInit);
        //---- store value of entry
        if (entry->isInit == 1) {
        if (strcmp(entry->dataType,"int")==0 || strcmp(entry->type,"var_enum")==0) {fprintf(log_fp, "%d, ", entry->intValue);}
        else if (strcmp(entry->dataType,"float")==0) {fprintf(log_fp, "%f, ", entry->floatValue);}
        else if (strcmp(entry->dataType,"bool")==0) {fprintf(log_fp,"%s, ", entry->boolValue ? "true" : "false");}
        else if (strcmp(entry->dataType,"string")==0) {fprintf(log_fp, "%s, ", entry->strValue);}
        }
        else {fprintf(log_fp, "-, ");}
        //---- print arguments of functions
        if (strcmp(entry->type, "func") == 0)
        {
            for (int j = 0; j < entry->argCount; j++)
            {
            fprintf(log_fp, "%d,", entry->argList[j]);
            }
        }
        else {fprintf(log_fp, "-");}
       
        fprintf(log_fp, "\n");

    }
    fprintf(log_fp, "=============\n");
    fclose(log_fp);
}
void clear_logs()
{
   FILE *fp= fopen("symbol_table_logs.log", "w");
   fclose(fp);
}
void st_print() {
    //----- write symbol table to file
    FILE *fp = fopen("symbol_table.txt", "w");
    //----- check if file is opened
    if(fp == NULL) {
        printf("can't open symbol_table.txt file!\n");
        exit(1);
    }
    //----- write symbol table header
    fprintf(fp, "ID\t|Name\t|Type\t|DataType\t|Line\t|Scope\tisInit\t|Value\t\t|Args\n");
    fprintf(fp, "-------------------------------------------------------------------------------------------\n");
    //----- write symbol table entries
    for(int i=0; i< st_index; i++) {
        struct Entry *entry = &symbolTable[i];
        fprintf(fp, "%d\t|%s\t|%s\t|%s\t\t|%d\t|%d\t|%d\t|", entry->id, entry->name,entry->type, entry->dataType, entry->declareLine, entry->scope,entry->isInit);
        //---- store value of entry
        if (entry->isInit == 1) {
        if (strcmp(entry->dataType,"int")==0 || strcmp(entry->type,"var_enum")==0) {fprintf(fp, "%d\t\t|", entry->intValue);}
        else if (strcmp(entry->dataType,"float")==0) {fp, fprintf(fp, "%f\t\t|", entry->floatValue);}
        else if (strcmp(entry->dataType,"bool")==0) {fprintf(fp,"%s\t\t|", entry->boolValue ? "true" : "false");}
        else if (strcmp(entry->dataType,"string")==0) {fprintf(fp, "%s\t\t|", entry->strValue);}
        }
        else {fprintf(fp, "-\t\t|");}
        //---- print arguments of functions
        if (strcmp(entry->type, "func") == 0)
        {
            for (int j = 0; j < entry->argCount; j++)
            {
            fprintf(fp, "%d,", entry->argList[j]);
            }
        }
        else {fprintf(fp, "-");}
       
        fprintf(fp, "\n");
    }
    fclose(fp);
}
//---------------------------------- HANDLE TYPE MISMATCH ERRORS ------------------------------------------------------------------

// for declaration statments take the st_index -1 3shan lesa m3molo insert but for assignment 3ady take assign_index coming from lookup function
void assign_int (int d , int i) {
    if (i == -1) {return;}
    if ( symbolTable[i].dataType == "string" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned int !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
    sErr();
     return; }
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType != "string" ) {symbolTable[i].intValue= d ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned wrong value!!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
    sErr();}
    if(is_changed == 1) {st_log();} // 
    assign_index = -1;
}
// void assign_float( float f, int i) {
//     if (i == -1) {return;}
//      if ( symbolTable[i].dataType != "float" && symbolTable[i].type == "func" )
//     {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned float !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
//      return ;}
//     symbolTable[i].isInit= 1 ;
//     if (symbolTable[i].dataType == "float"){symbolTable[i].floatValue= f ;}
//     else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned float value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
//    if(is_changed == 1) {st_log();}
//    assign_index = -1;
// }
void assign_str( char* s , int i) {
    if (i == -1) {return;}
    if ( symbolTable[i].dataType != "string" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned string !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
     sErr();
     return ;} 
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "string"){symbolTable[i].strValue= s ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned string value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );
    sErr();}
    if(is_changed == 1) {st_log();}
    assign_index = -1;
}
// void assign_bool( bool b , int i) {
//     if (i == -1) {return;}
//     if ( symbolTable[i].dataType != "bool" && symbolTable[i].type == "func" )
//     {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned boolean !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
//      return ;} 
//     symbolTable[i].isInit= 1 ;
//     if (symbolTable[i].dataType == "bool"){symbolTable[i].boolValue= b ;}
//     else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned bool value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
//     if(is_changed == 1) {st_log();}
//     assign_index = -1;
// }

void assign_enum (int i, char* enum_name, char* key) {
    if (i == -1) {return;}
    if (symbolTable[i].type == "var_enum") {
        for (int k=0; k < st_index; k++) { // loop on symbol table to find the enum declaration
            if (strcmp(symbolTable[k].name, enum_name) == 0) { // if found the enum declaration
                for (int j = 0; j < 100; j++) { // loop on enum keys to find the enum value
                    if (strcmp(symbolTable[k].enumValue.keys[j], key) == 0) {
                        symbolTable[i].intValue = symbolTable[k].enumValue.values[j];
                        symbolTable[i].isInit= 1 ; // set isInit to 1
                        st_log();
                        assign_index = -1;
                        return;
                    }
                }
                printf("\n !!!!!!!!!!!! Error at line %d: %s not exist as key for %s enum  !!!!!!!!!!!\n", line_number, key ,enum_name );
                sErr();
                assign_index = -1;
                return;
            }
        }
    }
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned enum value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );
    sErr();}
    assign_index = -1;
}
// void check_param_type (int i) {

// }
void check_type( int i) {
    // this functio check type matching between 2 identifiers before assign the value
    if ( is_param == 1) 
    { assign_index = arg_count;}
     if ( i == -1 || assign_index == -1) 
    { return;}
    if (symbolTable[i].dataType != symbolTable[assign_index].dataType && (symbolTable[assign_index].dataType == "string" ||  symbolTable[i].dataType == "string"))
    {   /// at calling a function
        if (strcmp(symbolTable[i].type,"func")== 0){ printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s return %s value  !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType ); sErr();}
        else if (strcmp(symbolTable[assign_index].type,"func")== 0){ printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s return %s value  !!!!!!!!!!!\n", line_number,symbolTable[i].name,symbolTable[i].dataType, symbolTable[assign_index].name,symbolTable[assign_index].dataType ); sErr();}
        else if (is_param == 1)
        {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Incorrect argument type %s is %s variable but %s %s !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType ); sErr();}
        else {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s %s !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType );sErr();}
    }
    else
    {
        symbolTable[assign_index].isInit=1;
        // assign value to the variable
        if ( strcmp(symbolTable[i].dataType,"int") ==0) {symbolTable[assign_index].intValue= symbolTable[i].intValue ;}
        else if (symbolTable[i].dataType == "float"){symbolTable[assign_index].floatValue= symbolTable[i].floatValue ;}
        else if ( strcmp(symbolTable[i].dataType, "string")==0){symbolTable[assign_index].strValue= symbolTable[i].strValue ;}
        else if (symbolTable[i].dataType == "bool"){symbolTable[assign_index].boolValue= symbolTable[i].boolValue ;}
    }
}
//--------------------------------------------------- HANDLE SCOPE ---------------------------------------------------

void scope_start(){
    //----- increment block number and scope index
    block_number++;
    scope_index++;
    scope_stack[scope_index] = block_number;
}
void scope_end(){
    if (func_index != -1 && strcmp(symbolTable[func_index].type, "func") == 0 && return_exist == 0 && strcmp(symbolTable[func_index].dataType, "void") != 0)
    {printf("\n !!!!!!!!!!!! Error at line %d: Missing return statement in Function %s !!!!!!!!!!!\n", line_number, symbolTable[func_index].name); sErr();}
    //----- make all symbols in this scope out of scope
    for (int i = 0; i < st_index; i++){
        if (symbolTable[i].scope == scope_stack[scope_index]){
            symbolTable[i].outOfScope = 1;
        }
    }
    scope_index--; // decrement scope index   
}
void unused_print() {
    for(int i=0; i< st_index; i++) {
        if ( symbolTable[i].isUsed == 0 && strcmp( symbolTable[i].type, "enum_arg") != 0) {
        if (strcmp(symbolTable[i].type,"func") == 0){printf("\n !!!!!!!!!!!! Function %s Declared at line %d but never called !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); sErr();}
        else if ( symbolTable[i].isArg == 1){printf("\n !!!!!!!!!!!! Unused Argument %s Declared in Function at line %d !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); sErr();}
        else {printf("\n !!!!!!!!!!!! Unused Identifier %s Declared at line %d !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); sErr();}
        }
    }
}
void arg_count_check( int i) {
    if ( arg_count > symbolTable[i].argCount )
    {printf("\n !!!!!!!!!!!! Error at line %d : too many arguments for function call expected %d got %d !!!!!!!!!!!\n", line_number, symbolTable[i].argCount, arg_count); sErr();}
    else if ( arg_count < symbolTable[i].argCount )
    {printf("\n !!!!!!!!!!!! Error at line %d : too few arguments for function call expected %d got %d !!!!!!!!!!!\n", line_number, symbolTable[i].argCount, arg_count); sErr(); }
}


/*
                                                                                |\/\  ,.
                                                                                /   `' |,-,
                                                                            /         /_
                                                                            _/            /
                                                                            (.-,--.       /
                                                                            /o/  o \     /
                                                                            \_\    /   _/
                                                                            (__`--'    _)
                                                                            /         |
                                                                            (_____,'    \  BART :)
                                                                            \_       _\
                                                                                `._..-'
*/
// ____________________________________________________________________________ CODE GEN _______________________________________________________________________

void pushVStack(char* var)
{   
    VirtualSP++;
    VirtualStack[VirtualSP] = strdup(var);
    /*printf("\nPUSHED %s\n", var);
    for (int i = VirtualSP ; i >=0; i--)
    {
        printf("\nDEBUG: %s", VirtualStack[i]);
    }*/
};

char* popVStack ()
{
    char* returner =  VirtualStack[VirtualSP];
    VirtualSP--;
    //printf("\nPOPED %s\n", returner);
    return returner;
};


char* newTemp()
{
    char* tempVar;
    strcpy(tempVar, "t");
    char numtostring[10];
    itoa(tempNumber, numtostring, 10);
    strcat(tempVar, numtostring);
    tempNumber++;
    return tempVar;
};



void StAssPush(char* s)
{
//////////////////////////////////////////////////////////// STACK ASSEMBLY///////////////////////////////////////////////
    FILE *assfile = fopen("stackassembly.txt", "a");
    if(assfile == NULL) {
        printf("can't open stackassembly.txt file!\n");
        exit(1);
    }
    fprintf(assfile, "\tPUSH \t %s\n", s);
    fclose (assfile);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void StAssPrint(char* s, int ind)
{
//////////////////////////////////////////////////////////// STACK ASSEMBLY///////////////////////////////////////////////
    FILE *assfile = fopen("stackassembly.txt", "a");
    if(assfile == NULL) {
        printf("can't open stackassembly.txt file!\n");
        exit(1);
    }
    if(ind){fprintf(assfile, "\t%s\n", s);}
    else{fprintf(assfile, "%s\n", s);}
    fclose (assfile);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};

void StAssJmp(char* jmp, char* jmpName, int* num, int inc, int noNum)
{
    FILE *assfile = fopen("stackassembly.txt", "a");
    if(assfile == NULL) {
        printf("can't open stackassembly.txt file!\n");
        exit(1);
    }
    if(noNum == 1)
    {
        fprintf(assfile, "\t%s \t %s\n", jmp, jmpName);
    }
    else{fprintf(assfile, "\t%s \t %s%d\n", jmp, jmpName,*num);}
    
    fclose (assfile);
    if(inc == 1){*num = *num + 1;}
};

void StAssPrintLBL(int isLBL, int inc)
{
    char buf[10];
    char numtostring[10];
    if(isLBL){
        strcpy(buf , "LBL");
        
        if(inc)
        {
            itoa(SMLabel_Else++, numtostring, 10);
        }
        else
        {
            itoa(SMLabel_Else, numtostring, 10);
        }

        } else {
        strcpy(buf, "END");
        if(inc)
        {
            itoa(SMLabel_End++, numtostring, 10);
        }
        else
        {
            itoa(SMLabel_End, numtostring, 10);
        }
    }
    strcat(buf, numtostring);strcat(buf, ":"); StAssPrint(buf,0);
};


void StAssForHeader()
{
    StAssPush("dum");
    StAssPush("$0");
    StAssPrint("STORE", 1);
    char buf[10];
    char numtostring[10];
    itoa(ForHeaderLabel, numtostring, 10);
    strcpy(buf, "Label");
    strcat(buf, numtostring);
    strcat(buf, ":");
    StAssPrint(buf, 0);
    StAssPush("dum");
    StAssPush("$1");
    StAssPrint("EQ", 1);
    StAssJmp("JZ", "HELPER", &ForHelperLabel, 0,0);

};

void StAssForMiddle()
{
    StAssJmp("JNZ", "END", &SMLabel_End, 0,0);
    StAssPush("dum");
    StAssPush("$1");
    StAssPrint("STORE", 1);
    StAssJmp("JMP", "LBL", &SMLabel_Else, 0,0);
    char buf[10];
    char numtostring[10];
    itoa(ForHelperLabel, numtostring, 10);
    strcpy(buf, "HELPER");
    strcat(buf, numtostring);
    strcat(buf, ":");
    StAssPrint(buf, 0);
    ForHelperLabel++;
};


void pErr(int lineNUMM)
{
    FILE *assfile = fopen("ParsingErrors.txt", "a");
    char buf [50];
    itoa(lineNUMM, buf,10);

    fprintf(assfile, "%s ", buf);
    
    fclose (assfile);
};



void sErr()
{
    printf("\n\n\n\n\n %d \n\n\n\n\n\n\n", line_number);
    FILE *semfile = fopen("SemanticErrors.txt", "a");
     if(semfile == NULL) {
        printf("can't open SemanticErrors.txt file!\n");
        exit(1);
    }

    fprintf(semfile, "%d ", line_number);
    
    fclose (semfile);
};

void popArgs()
{
    argPointer--;
    for (int i = argPointer; i>= 0;i--)
    {
        char buf[20];
        strcpy(buf, "POP\t");
        strcat(buf, argumentList[i]);
        StAssPrint(buf,1);
        argPointer--;
    }
    argPointer = 0;
};

void CodeGenAss()
{
    if(codeGen){
    //printf("DEBUG %s", VirtualStack[VirtualSP]);
    FILE *llfile = fopen("LLVM.txt", "a");
    if(llfile == NULL) {
        printf("can't open LLVM.txt file!\n");
        exit(1);
    }
    char* value = popVStack();
    char* carrier = popVStack();
    fprintf(llfile, "%s = %s\n", carrier, value);
    fclose (llfile);
    //printf("DEBUG %s", VirtualStack[VirtualSP]);

    }
};

void CodeGenOp(char* operator)
{
    if(codeGen){
    char* second_operand = popVStack();
    char* operation = popVStack();
    char* first_operand = popVStack();
    char dumstr[10];
    itoa(tempNumber, dumstr, 10);
    strcat(temp_var, dumstr);
    tempNumber++;
    pushVStack(temp_var);
    FILE *llvfile = fopen("LLVM.txt", "a");
    if(llvfile == NULL) {
        printf("can't open LLVM.txt file!\n");
        exit(1);
    }
    fprintf(llvfile, "%s = %s %s %s\n", temp_var, first_operand, operation, second_operand);
    fclose (llvfile);
    temp_var[strlen(temp_var)-1] = '\0';
    
    }
};

char* makeLabel()
{
    char dumstr[10];
    itoa(labelNumber, dumstr, 10);
    strcat(temp_label, dumstr);
    return temp_label;
};

void resetTempLabel()
{
    temp_label[strlen(temp_label)-1] = '\0';
    labelNumber++;
};

char* makeEndLabel()
{
    char dumstr[10];
    itoa(endlabelNumber, dumstr, 10);
    strcat(temp_endlabel, dumstr);
    return temp_endlabel;
};

void CodeGenLogical()
{
    if(codeGen)
    {
        char* equality_OP = popVStack();
        char* second_operand = popVStack();
        char* first_operand = popVStack();
        makeEndLabel();
        makeLabel();
        FILE *llvfile = fopen("LLVM.txt", "a");
        if(llvfile == NULL) {printf("can't open LLVM.txt file!\n");exit(1);}
        fprintf(llvfile, "%s %s %s goto %s\ngoto %s\n%s : \n", first_operand, equality_OP, second_operand, temp_label, temp_endlabel, temp_label); fclose (llvfile);
    }
    resetTempLabel();
};

void printIF(){
    if(codeGen){
    FILE *llvfile = fopen("LLVM.txt", "a");
    if(llvfile == NULL) {printf("can't open LLVM.txt file!\n");exit(1);}
    fprintf(llvfile, "IF "); fclose (llvfile);   }
};

void printLLVM(char* s)
{
    if(codeGen){
        FILE *llvfile = fopen("LLVM.txt", "a");
        if(llvfile == NULL) {printf("can't open LLVM.txt file!\n");exit(1);}
        fprintf(llvfile, s); fclose (llvfile);
    }
};

void printWHILE()
{
    if(codeGen)
    {
        printLLVM(makeLabel());
        resetTempLabel();
        printLLVM(":\n");
        printIF();
    }
};

void controlTerminator(int isWhile)
{
    if(codeGen)
    {
        if(isWhile)
        {
            labelNumber-=2;
            printLLVM("goto ");
            printLLVM(makeLabel());
            labelNumber+=2;
            printLLVM("\n");
            resetTempLabel();
        }

        printLLVM(strdup(temp_endlabel));
        printLLVM(":\n");
        temp_endlabel[strlen(temp_endlabel)-1] = '\0';
        endlabelNumber++;
    }
};
//==============================================================================================================================================================





//------------------------------------------- MAIN -------------------------------
int main(int argc, char *argv[])
{ 
    clear_logs();
    yy_flex_debug = 1;
    int ret = remove("LLVM.txt");
    int ret2 = remove("stackassembly.txt");
    int ret3 = remove("ParsingErrors.txt");
    int ret4 = remove("SemanticErrors.txt");
    if(ret != 0 && ret2 !=0 && ret3 !=0 && ret4 != 0){
        printf("\nCreating Intermediate Code File ...\n");
        printf("Creating Stack Machine Assembly File ...\n");
    }
    yyin = fopen(argv[1], "r");
    yyparse();
    st_print();
    unused_print();
    return 0;
}
