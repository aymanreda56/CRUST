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
    void sErr(int num);
    void prependFile(char* filename, char* text);
    void printDataSegment();
    //int* linenoPTR = &yylineno;
//==================================================================================================================================================


#line 213 "parser.tab.c"

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
  YYSYMBOL_BREAK = 28,                     /* BREAK  */
  YYSYMBOL_EQUALITY = 29,                  /* EQUALITY  */
  YYSYMBOL_NEG_EQUALITY = 30,              /* NEG_EQUALITY  */
  YYSYMBOL_SWITCH = 31,                    /* SWITCH  */
  YYSYMBOL_CASE = 32,                      /* CASE  */
  YYSYMBOL_LOGIC_AND = 33,                 /* LOGIC_AND  */
  YYSYMBOL_LOGIC_OR = 34,                  /* LOGIC_OR  */
  YYSYMBOL_LOGIC_NOT = 35,                 /* LOGIC_NOT  */
  YYSYMBOL_DIGIT = 36,                     /* DIGIT  */
  YYSYMBOL_IDENTIFIER = 37,                /* IDENTIFIER  */
  YYSYMBOL_FLOAT_DIGIT = 38,               /* FLOAT_DIGIT  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ':'  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_PROGRAM = 47,                   /* PROGRAM  */
  YYSYMBOL_STATEMENT = 48,                 /* STATEMENT  */
  YYSYMBOL_SEMICOLON_MISS = 49,            /* SEMICOLON_MISS  */
  YYSYMBOL_TYPE = 50,                      /* TYPE  */
  YYSYMBOL_DECLARATION_STT = 51,           /* DECLARATION_STT  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_DECLARATION_TAIL = 54,          /* DECLARATION_TAIL  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_57_5 = 57,                      /* $@5  */
  YYSYMBOL_RETURN_STT = 58,                /* RETURN_STT  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_helperSWITCH = 60,              /* helperSWITCH  */
  YYSYMBOL_SWITCH_STT = 61,                /* SWITCH_STT  */
  YYSYMBOL_DEFAULTCASE = 62,               /* DEFAULTCASE  */
  YYSYMBOL_CASES = 63,                     /* CASES  */
  YYSYMBOL_64_7 = 64,                      /* $@7  */
  YYSYMBOL_65_8 = 65,                      /* $@8  */
  YYSYMBOL_66_9 = 66,                      /* $@9  */
  YYSYMBOL_67_10 = 67,                     /* $@10  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 68,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_69_11 = 69,                     /* $@11  */
  YYSYMBOL_70_12 = 70,                     /* $@12  */
  YYSYMBOL_71_13 = 71,                     /* $@13  */
  YYSYMBOL_72_14 = 72,                     /* $@14  */
  YYSYMBOL_FUNC_DECLARATION_STT = 73,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_74_15 = 74,                     /* $@15  */
  YYSYMBOL_75_16 = 75,                     /* $@16  */
  YYSYMBOL_76_17 = 76,                     /* $@17  */
  YYSYMBOL_77_18 = 77,                     /* $@18  */
  YYSYMBOL_78_19 = 78,                     /* $@19  */
  YYSYMBOL_79_20 = 79,                     /* $@20  */
  YYSYMBOL_80_21 = 80,                     /* $@21  */
  YYSYMBOL_81_22 = 81,                     /* $@22  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 82, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_83_23 = 83,                     /* $@23  */
  YYSYMBOL_ARGS = 84,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 85,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 86,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 87,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_88_24 = 88,                     /* $@24  */
  YYSYMBOL_ENUM_HELPER = 89,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 90,                 /* ENUM_ARGS  */
  YYSYMBOL_91_25 = 91,                     /* $@25  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 92,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_93_26 = 93,                     /* $@26  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 94, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_CALL_STT = 95,             /* ENUM_CALL_STT  */
  YYSYMBOL_IF_STT_HELPER = 96,             /* IF_STT_HELPER  */
  YYSYMBOL_97_27 = 97,                     /* $@27  */
  YYSYMBOL_IF_STT_HELPER1 = 98,            /* IF_STT_HELPER1  */
  YYSYMBOL_IF_STT = 99,                    /* IF_STT  */
  YYSYMBOL_100_28 = 100,                   /* $@28  */
  YYSYMBOL_101_29 = 101,                   /* $@29  */
  YYSYMBOL_WHILE_STT = 102,                /* WHILE_STT  */
  YYSYMBOL_103_30 = 103,                   /* $@30  */
  YYSYMBOL_104_31 = 104,                   /* $@31  */
  YYSYMBOL_WHILEMISS_COLON = 105,          /* WHILEMISS_COLON  */
  YYSYMBOL_DO_WHILE_STT = 106,             /* DO_WHILE_STT  */
  YYSYMBOL_ERRONOUS_DO_WHILE = 107,        /* ERRONOUS_DO_WHILE  */
  YYSYMBOL_108_32 = 108,                   /* $@32  */
  YYSYMBOL_109_33 = 109,                   /* $@33  */
  YYSYMBOL_110_34 = 110,                   /* $@34  */
  YYSYMBOL_111_35 = 111,                   /* $@35  */
  YYSYMBOL_FOR_STT = 112,                  /* FOR_STT  */
  YYSYMBOL_113_36 = 113,                   /* $@36  */
  YYSYMBOL_114_37 = 114,                   /* $@37  */
  YYSYMBOL_115_38 = 115,                   /* $@38  */
  YYSYMBOL_116_39 = 116,                   /* $@39  */
  YYSYMBOL_ERRONOUS_FOR_LOOP = 117,        /* ERRONOUS_FOR_LOOP  */
  YYSYMBOL_118_40 = 118,                   /* $@40  */
  YYSYMBOL_119_41 = 119,                   /* $@41  */
  YYSYMBOL_helperAssignmentRule = 120,     /* helperAssignmentRule  */
  YYSYMBOL_assignmentSTT = 121,            /* assignmentSTT  */
  YYSYMBOL_122_42 = 122,                   /* $@42  */
  YYSYMBOL_BLOCK = 123,                    /* BLOCK  */
  YYSYMBOL_124_43 = 124,                   /* $@43  */
  YYSYMBOL_FUNC_CALL = 125,                /* FUNC_CALL  */
  YYSYMBOL_126_44 = 126,                   /* $@44  */
  YYSYMBOL_127_45 = 127,                   /* $@45  */
  YYSYMBOL_128_46 = 128,                   /* $@46  */
  YYSYMBOL_USED_ARGS = 129,                /* USED_ARGS  */
  YYSYMBOL_130_47 = 130,                   /* $@47  */
  YYSYMBOL_EXPRESSION = 131,               /* EXPRESSION  */
  YYSYMBOL_132_48 = 132,                   /* $@48  */
  YYSYMBOL_133_49 = 133,                   /* $@49  */
  YYSYMBOL_134_50 = 134,                   /* $@50  */
  YYSYMBOL_135_51 = 135,                   /* $@51  */
  YYSYMBOL_ERRONOUS_EXPRESSION = 136,      /* ERRONOUS_EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 137,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 138,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 139                  /* RES_WORD  */
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
#define YYLAST   1201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  229
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  392

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      43,    41,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   191,   191,   192,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   216,   226,   227,   228,   229,   233,   233,   234,   234,
     235,   236,   237,   242,   243,   244,   245,   246,   246,   247,
     247,   248,   248,   255,   256,   256,   258,   261,   262,   266,
     267,   270,   270,   270,   270,   271,   271,   272,   273,   275,
     284,   284,   285,   285,   286,   286,   287,   287,   288,   300,
     301,   301,   301,   302,   302,   302,   303,   303,   303,   304,
     304,   304,   309,   309,   319,   320,   321,   324,   327,   334,
     334,   335,   337,   337,   340,   340,   341,   347,   347,   348,
     349,   350,   351,   352,   356,   357,   359,   360,   364,   365,
     369,   369,   372,   376,   377,   378,   379,   379,   380,   380,
     381,   390,   390,   390,   397,   398,   403,   404,   407,   407,
     408,   408,   409,   409,   410,   410,   411,   418,   418,   418,
     418,   418,   419,   423,   423,   424,   424,   431,   435,   436,
     437,   437,   442,   442,   450,   450,   450,   450,   451,   456,
     456,   457,   458,   459,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   474,   476,   476,   477,   477,   480,
     480,   481,   482,   483,   484,   493,   495,   496,   497,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541
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
  "CONSTANT", "POW", "ELSE", "DO", "ENUM", "RETURN", "DEFAULT", "BREAK",
  "EQUALITY", "NEG_EQUALITY", "SWITCH", "CASE", "LOGIC_AND", "LOGIC_OR",
  "LOGIC_NOT", "DIGIT", "IDENTIFIER", "FLOAT_DIGIT", "'{'", "'}'", "')'",
  "':'", "'('", "','", "';'", "$accept", "PROGRAM", "STATEMENT",
  "SEMICOLON_MISS", "TYPE", "DECLARATION_STT", "$@1", "$@2",
  "DECLARATION_TAIL", "$@3", "$@4", "$@5", "RETURN_STT", "$@6",
  "helperSWITCH", "SWITCH_STT", "DEFAULTCASE", "CASES", "$@7", "$@8",
  "$@9", "$@10", "ERRONOUS_SWITCH_STT", "$@11", "$@12", "$@13", "$@14",
  "FUNC_DECLARATION_STT", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
  "$@21", "$@22", "ERRONOUS_FUNC_DECLARATION_STT", "$@23", "ARGS",
  "ERRONOUS_ARGS", "ARG_DECL", "ENUM_DECLARATION_STT", "$@24",
  "ENUM_HELPER", "ENUM_ARGS", "$@25", "ENUM_DEFINED_ARGS", "$@26",
  "ERRONOUS_ENUM_DECLARATION_STT", "ENUM_CALL_STT", "IF_STT_HELPER",
  "$@27", "IF_STT_HELPER1", "IF_STT", "$@28", "$@29", "WHILE_STT", "$@30",
  "$@31", "WHILEMISS_COLON", "DO_WHILE_STT", "ERRONOUS_DO_WHILE", "$@32",
  "$@33", "$@34", "$@35", "FOR_STT", "$@36", "$@37", "$@38", "$@39",
  "ERRONOUS_FOR_LOOP", "$@40", "$@41", "helperAssignmentRule",
  "assignmentSTT", "$@42", "BLOCK", "$@43", "FUNC_CALL", "$@44", "$@45",
  "$@46", "USED_ARGS", "$@47", "EXPRESSION", "$@48", "$@49", "$@50",
  "$@51", "ERRONOUS_EXPRESSION", "COMPARISONSTT", "ERRONOUS_COMPARISONSTT",
  "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-275)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-165)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -275,   205,  -275,   705,  -275,  -275,  -275,  -275,   -24,    41,
      11,  -275,  -275,   498,  -275,  -275,    16,    23,    14,    94,
      34,   526,  -275,   315,  -275,  -275,   498,  -275,    -6,  -275,
      94,    -7,  -275,  -275,  -275,    46,  -275,  -275,  -275,    84,
    -275,  -275,  -275,  -275,  -275,  -275,   107,  -275,  -275,  -275,
    1013,  -275,  -275,  -275,   498,   146,   419,  -275,   498,   498,
      94,   498,   498,   498,   498,   498,    94,  -275,  -275,    79,
    -275,   498,   407,    86,   498,  1128,   363,   327,    92,    17,
      95,    62,   498,  -275,  -275,  -275,    15,    78,   182,    98,
    -275,   105,    97,  -275,   790,  -275,    21,  -275,   -13,  -275,
      52,     5,  -275,    27,   112,    46,  -275,  1036,  -275,   448,
     459,  -275,   124,   130,  -275,  -275,   537,   565,   576,   604,
     116,   498,   116,   498,   140,   246,    82,  -275,   182,   182,
     182,  1151,  1151,  -275,   114,    46,   233,   407,   407,   407,
     233,    98,   148,   120,  -275,    22,   119,   126,    -8,    80,
     123,  -275,  -275,   233,   128,   129,    39,  -275,   498,   135,
    -275,  -275,   271,  -275,    87,    94,   132,    87,    69,    46,
    -275,   498,  -275,   143,  -275,  -275,   136,  -275,    76,  -275,
    -275,   498,    78,   615,   116,   164,   643,   140,  -275,   498,
    -275,   498,   498,  1179,   182,  1179,   182,  1165,  1151,  1165,
    1151,   116,   116,    69,   144,  -275,   407,   407,  -275,   145,
     147,   176,   154,  -275,   498,   498,   151,   119,   113,   163,
     158,   119,  -275,   149,   175,   180,  -275,  -275,  1059,   206,
     487,  -275,   498,   654,  -275,  -275,  -275,    69,   183,  -275,
      69,   190,   187,  -275,   188,  -275,   233,   498,  -275,   194,
    -275,   116,    78,   116,   164,   116,   246,    82,   182,   196,
    -275,   197,   407,   407,  -275,    46,   498,   210,   498,   498,
     965,   815,  -275,   199,   217,  -275,  -275,   228,  -275,   232,
    -275,   230,    -7,   244,    -7,    -7,  -275,  -275,   681,  -275,
     840,  1082,  1105,   735,   243,  -275,  -275,  -275,  -275,    69,
     229,   989,  -275,  -275,    46,  -275,   245,  -275,  -275,   865,
     498,   890,   915,  -275,  -275,  -275,  -275,   249,   247,  -275,
    -275,   250,    -7,   254,   260,   487,   262,   257,  -275,  -275,
    -275,   264,   274,   774,  -275,    46,  -275,    46,  -275,    46,
    -275,    46,  -275,   407,  -275,   940,  -275,  -275,   268,  -275,
     272,  -275,  -275,  -275,  -275,   487,  -275,  -275,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,
    -275,  -275,  -275,    46,  -275,  -275,  -275,  -275,    46,   276,
    -275,   303,  -275,  -275,  -275,  -275,    -7,  -275,  -275,  -275,
      46,  -275
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    22,    23,    24,    25,     0,   110,
       0,   121,   167,     0,   168,   169,     0,     0,    44,     0,
       0,     0,   165,     0,   166,   152,     0,     2,     0,     4,
       0,    59,    13,    48,     5,     0,    14,    91,    15,   116,
       9,    10,    12,   127,    11,   142,     0,     6,    16,   182,
       0,   184,   181,   198,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
     118,     0,     0,   137,     0,     0,     0,   170,   128,     0,
       0,     0,     0,    21,    17,    60,     0,   207,   197,   150,
     147,     0,     0,     3,     0,    28,    82,     7,     0,    51,
      58,     0,    69,     0,   113,     0,   148,     0,   177,     0,
       0,     8,   173,     0,   175,   179,     0,     0,     0,     0,
     187,     0,   199,     0,   201,   185,   186,    31,   188,   203,
     205,   208,   210,    30,    73,     0,   111,     0,     0,     0,
     122,     0,     0,     0,   132,     0,     0,     0,    94,     0,
       0,    92,    93,    45,     0,    62,     0,   158,     0,     0,
     109,   155,     0,   183,     0,     0,    70,     0,     0,     0,
      50,     0,    57,     0,    68,    47,     0,   112,     0,   117,
     149,     0,   200,     0,   189,   202,     0,   190,   171,     0,
     172,     0,     0,   204,   193,   206,   194,   209,   195,   211,
     196,   214,   212,     0,     0,   119,     0,     0,   138,   125,
       0,     0,     0,   130,     0,     0,     0,     0,     0,     0,
       0,     0,   105,     0,     0,     0,    66,    46,     0,     0,
       0,   153,     0,     0,    36,    29,    32,     0,     0,    27,
       0,     0,     0,    86,    85,    49,    52,     0,   120,     0,
     114,   178,   215,   192,   213,   191,   174,   176,   180,     0,
      80,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,   104,     0,     0,   103,   102,    97,   101,     0,
     106,     0,    59,     0,    59,    59,   151,   108,     0,   156,
     159,     0,     0,    41,     0,    77,    87,    88,    83,     0,
       0,     0,   115,    74,     0,   143,     0,   139,   123,     0,
       0,     0,     0,   136,   126,   107,   100,     0,    94,    95,
      90,     0,    59,     0,     0,     0,     0,     0,    34,    35,
      33,     0,     0,     0,    71,     0,    84,     0,    56,     0,
      81,     0,   145,     0,   129,     0,   133,   131,     0,    61,
       0,    65,    67,   161,   157,     0,    38,    40,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,    42,     0,    78,    53,    75,   144,     0,     0,
     135,     0,    98,    63,   160,    72,    59,   146,   140,    54,
       0,   141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -275,   227,   -70,   -27,  -147,  -275,  -275,  -275,   155,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,   224,  -274,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -199,  -275,
    -275,  -275,  -275,  -141,    47,  -275,   -10,  -275,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,   -16,  -275,  -275,
    -275,  -275,  -275,  -239,  -275,   -12,  -275,  -275,  -275,  -275,
    -275,  -275,  -275,  -275
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,    84,    28,    29,   167,   164,   235,   331,
     332,   333,    30,    82,    31,    32,   100,   101,   171,   300,
     386,   173,    33,   154,   224,   225,   285,    34,   237,   373,
     203,   339,   238,   335,   204,   304,    35,   168,   242,   243,
     244,    36,   221,   150,   151,   219,   152,   317,    37,    38,
      39,    71,   104,    40,   105,   135,    41,    74,   209,   265,
      42,    43,   142,   269,   212,   143,    44,   139,   263,   343,
     390,    45,   341,   378,    46,    47,   158,    48,    93,    49,
      92,   230,   326,   289,   327,    50,   189,   191,   181,   192,
      51,    52,    53,   372
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    77,   137,    97,   259,   216,   174,   218,   321,    88,
     323,   324,    72,    69,    94,    95,   155,    78,   144,   102,
      98,   241,   -26,   213,    80,    99,    25,   145,   176,   169,
     -43,    96,   -96,   127,   107,    85,   -26,   -26,   294,   133,
     226,   296,   120,   122,   124,   175,   125,   126,   350,   128,
     129,   130,   131,   132,    73,    25,   241,   156,   165,   136,
      81,   214,   140,   147,   166,   215,    25,   206,   207,   208,
     153,    86,     4,     5,     6,     7,   273,   249,   227,    98,
     281,   220,   170,    70,   -55,    25,   353,   177,   232,   179,
     241,    55,    56,   241,   108,   109,   110,   184,   187,   148,
     336,   149,   233,   234,   194,   196,   198,   200,    75,   201,
      83,   202,   389,   240,   274,    25,   384,   -89,    12,   205,
     159,   160,   134,   106,   275,    13,   103,    14,    15,   109,
     110,   138,  -134,   276,   146,   178,   261,   262,   236,   157,
     161,   188,    21,    22,    76,    24,   228,    75,   190,   277,
      26,   278,   241,   245,   110,   -79,   148,    12,   210,   246,
     211,   121,   250,   222,    13,   217,    14,    15,   -64,   251,
     223,   253,   229,   -76,   255,   247,   248,   256,    56,   257,
     258,    21,    22,    76,    24,   260,   267,   264,   282,    26,
     266,   272,   306,   307,   108,   109,   110,   268,   280,   112,
     113,   114,   270,   271,   115,     2,     3,   279,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   283,   290,   284,
     291,   293,   287,    13,   295,    14,    15,   297,   298,    16,
      17,    18,   299,    19,   302,   301,    20,   303,   305,   315,
      21,    22,    23,    24,    25,   108,   109,   110,    26,   308,
     112,   113,   114,   310,   309,   115,   311,   312,   108,   109,
     110,   316,   116,   117,   113,   114,   118,   119,   -99,   318,
     320,   337,     3,   379,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   322,   334,   338,   342,   -96,   340,    13,
     349,    14,    15,   348,   351,    16,    17,    18,   345,    19,
     352,   355,    20,   354,   356,   381,    21,    22,    23,    24,
      25,   231,   383,   290,    26,   357,    89,   388,   218,   374,
     162,   375,   239,   376,   172,   377,   319,  -164,  -164,  -164,
      90,  -164,  -164,  -164,  -164,     0,     0,  -164,   382,   108,
     109,   110,     0,   290,  -164,  -164,   114,     0,  -164,  -164,
       0,     0,    91,     0,     0,     0,     0,   385,  -154,     0,
       0,     0,   387,     0,   141,     0,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,   391,  -164,  -164,  -164,     0,  -164,
    -164,  -164,  -164,     0,  -164,  -164,  -164,  -164,  -164,     0,
       0,     0,  -164,  -164,  -164,  -164,  -164,  -164,     0,     0,
       0,     0,  -164,  -164,  -164,  -164,  -154,  -164,     3,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      75,     0,     0,     0,     0,    13,     0,    14,    15,     0,
      12,    16,    17,    18,   123,    19,     0,    13,    20,    14,
      15,     0,    21,    22,    23,    24,    25,     0,     0,   182,
      26,     0,     0,     0,    21,    22,    76,    24,     0,    12,
     185,     0,    26,   183,     0,     0,    13,     0,    14,    15,
      12,     0,     0,     0,   186,     0,     0,    13,     0,    14,
      15,     0,     0,    21,    22,    76,    24,     0,   288,     0,
       0,    26,     0,     0,    21,    22,    76,    24,    12,    75,
       0,     0,    26,     0,     0,    13,     0,    14,    15,    12,
       0,     0,     0,     0,     0,     0,    13,     0,    14,    15,
       0,     0,    21,    22,    76,    24,     0,    87,  -163,     0,
      26,     0,     0,    21,    22,    76,    24,    12,   193,     0,
       0,    26,     0,     0,    13,     0,    14,    15,    12,     0,
       0,     0,     0,     0,     0,    13,     0,    14,    15,     0,
       0,    21,    22,    76,    24,     0,   195,     0,     0,    26,
       0,     0,    21,    22,    76,    24,    12,   197,     0,     0,
      26,     0,     0,    13,     0,    14,    15,    12,     0,     0,
       0,     0,     0,     0,    13,     0,    14,    15,     0,     0,
      21,    22,    76,    24,     0,   199,     0,     0,    26,     0,
       0,    21,    22,    76,    24,    12,   252,     0,     0,    26,
       0,     0,    13,     0,    14,    15,    12,     0,     0,     0,
       0,     0,     0,    13,     0,    14,    15,     0,     0,    21,
      22,    76,    24,     0,   254,     0,     0,    26,     0,     0,
      21,    22,    76,    24,    12,   292,     0,     0,    26,     0,
       0,    13,     0,    14,    15,    12,     0,     0,     0,     0,
       0,     0,    13,     0,    14,    15,     0,     0,    21,    22,
      76,    24,     0,     0,     0,     0,    26,     0,     0,    21,
      22,    76,    24,    54,    55,    56,     0,    26,    58,     0,
      59,     0,     0,    61,     0,     0,     0,     0,     0,     0,
      62,    63,     0,     0,    64,    65,     0,    54,    55,    56,
       0,    57,    58,     0,    59,   325,    60,    61,     0,     0,
       0,     0,     0,     0,    62,    63,     0,     0,    64,    65,
       0,     0,    66,     0,     0,    67,    68,   108,   109,   110,
       0,   330,   112,   113,   114,     0,     0,   115,     0,     0,
       0,     0,     0,     0,   116,   117,     0,     0,   118,   119,
       0,     0,     0,     0,     0,   -37,   -39,   358,   359,   360,
     361,   362,   363,   364,   365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   366,     0,   367,   368,   369,
       0,     0,   108,   109,   110,   370,   371,   112,   113,   114,
       0,     0,   115,     0,     0,     0,     0,     0,     0,   116,
     117,     0,     0,   118,   119,     0,     0,   108,   109,   110,
       0,   163,   112,   113,   114,     0,     0,   115,     0,     0,
       0,     0,     0,     0,   116,   117,     0,     0,   118,   119,
       0,     0,   108,   109,   110,     0,   314,   112,   113,   114,
       0,     0,   115,     0,     0,     0,     0,     0,     0,   116,
     117,     0,     0,   118,   119,     0,     0,   108,   109,   110,
       0,  -162,   112,   113,   114,     0,     0,   115,     0,     0,
       0,     0,     0,     0,   116,   117,     0,     0,   118,   119,
       0,     0,   108,   109,   110,     0,   344,   112,   113,   114,
       0,     0,   115,     0,     0,     0,     0,     0,     0,   116,
     117,     0,     0,   118,   119,     0,     0,   108,   109,   110,
       0,   346,   112,   113,   114,     0,     0,   115,     0,     0,
       0,     0,     0,     0,   116,   117,     0,     0,   118,   119,
       0,     0,   108,   109,   110,     0,   347,   112,   113,   114,
       0,     0,   115,     0,     0,     0,     0,     0,     0,   116,
     117,     0,     0,   118,   119,     0,     0,   108,   109,   110,
       0,   380,   112,   113,   114,     0,     0,   115,     0,     0,
       0,     0,     0,     0,   116,   117,     0,     0,   118,   119,
       0,   108,   109,   110,     0,   313,   112,   113,   114,     0,
       0,   115,     0,     0,     0,     0,     0,     0,   116,   117,
       0,     0,   118,   119,     0,   108,   109,   110,    25,   111,
     112,   113,   114,     0,     0,   115,     0,     0,     0,     0,
       0,     0,   116,   117,     0,     0,   118,   119,   108,   109,
     110,     0,   180,   112,   113,   114,     0,     0,   115,     0,
       0,     0,     0,     0,     0,   116,   117,     0,     0,   118,
     119,   108,   109,   110,     0,   286,   112,   113,   114,     0,
       0,   115,     0,     0,     0,     0,     0,     0,   116,   117,
       0,     0,   118,   119,   108,   109,   110,     0,   328,   112,
     113,   114,     0,     0,   115,     0,     0,     0,     0,     0,
       0,   116,   117,     0,     0,   118,   119,    54,    55,    56,
       0,   329,    58,     0,    59,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    62,    63,     0,     0,    64,    65,
      54,    55,    56,     0,     0,    58,     0,    59,     0,     0,
      61,     0,     0,     0,     0,     0,     0,    62,    63,     0,
       0,    64,    65,   108,   109,   110,     0,     0,   112,   113,
     114,     0,     0,   115,     0,     0,     0,    54,    55,    56,
     116,   117,    58,     0,    59,     0,     0,    61,     0,     0,
       0,    54,    55,    56,    62,    63,    58,     0,    59,     0,
       0,    61
};

static const yytype_int16 yycheck[] =
{
      16,    13,    72,    30,   203,   146,     1,    15,   282,    21,
     284,   285,     1,    37,    26,    21,     1,     1,     1,    35,
      27,   168,     1,     1,     1,    32,    39,    10,     1,    42,
      16,    37,    40,    60,    46,     1,    15,    16,   237,    66,
       1,   240,    54,    55,    56,    40,    58,    59,   322,    61,
      62,    63,    64,    65,    43,    39,   203,    42,    37,    71,
      37,    39,    74,     1,    43,    43,    39,   137,   138,   139,
      82,    37,     3,     4,     5,     6,   217,     1,    39,    27,
     221,     1,    98,    42,    32,    39,   325,   103,     1,   105,
     237,    13,    14,   240,    12,    13,    14,   109,   110,    37,
     299,    39,    15,    16,   116,   117,   118,   119,     1,   121,
      16,   123,   386,    44,     1,    39,   355,    37,    11,   135,
      15,    16,    43,    16,    11,    18,    42,    20,    21,    13,
      14,    45,    40,    20,    39,    23,   206,   207,   165,    41,
      43,    17,    35,    36,    37,    38,   158,     1,    18,    36,
      43,    38,   299,   169,    14,    41,    37,    11,    10,   171,
      40,    15,   178,    40,    18,    39,    20,    21,    39,   181,
      42,   183,    37,    41,   186,    32,    40,   189,    14,   191,
     192,    35,    36,    37,    38,    41,    10,    42,    39,    43,
      43,    40,   262,   263,    12,    13,    14,    43,    40,    17,
      18,    19,   214,   215,    22,     0,     1,    44,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    42,   230,    39,
     232,   233,    16,    18,    41,    20,    21,    37,    41,    24,
      25,    26,    44,    28,    40,   247,    31,    41,    41,    40,
      35,    36,    37,    38,    39,    12,    13,    14,    43,   265,
      17,    18,    19,    43,   266,    22,   268,   269,    12,    13,
      14,    44,    29,    30,    18,    19,    33,    34,    40,    37,
      40,    42,     1,   343,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    39,    41,   301,    41,    40,   304,    18,
      40,    20,    21,    44,    40,    24,    25,    26,   310,    28,
      40,    44,    31,    41,    40,    37,    35,    36,    37,    38,
      39,    40,    40,   325,    43,    41,     1,    41,    15,   335,
      93,   337,   167,   339,   100,   341,   279,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,   348,    12,
      13,    14,    -1,   355,    29,    30,    19,    -1,    33,    34,
      -1,    -1,    37,    -1,    -1,    -1,    -1,   373,    43,    -1,
      -1,    -1,   378,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,   390,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
       1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,
      11,    24,    25,    26,    15,    28,    -1,    18,    31,    20,
      21,    -1,    35,    36,    37,    38,    39,    -1,    -1,     1,
      43,    -1,    -1,    -1,    35,    36,    37,    38,    -1,    11,
       1,    -1,    43,    15,    -1,    -1,    18,    -1,    20,    21,
      11,    -1,    -1,    -1,    15,    -1,    -1,    18,    -1,    20,
      21,    -1,    -1,    35,    36,    37,    38,    -1,     1,    -1,
      -1,    43,    -1,    -1,    35,    36,    37,    38,    11,     1,
      -1,    -1,    43,    -1,    -1,    18,    -1,    20,    21,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    35,    36,    37,    38,    -1,     1,    41,    -1,
      43,    -1,    -1,    35,    36,    37,    38,    11,     1,    -1,
      -1,    43,    -1,    -1,    18,    -1,    20,    21,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,
      -1,    35,    36,    37,    38,    -1,     1,    -1,    -1,    43,
      -1,    -1,    35,    36,    37,    38,    11,     1,    -1,    -1,
      43,    -1,    -1,    18,    -1,    20,    21,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      35,    36,    37,    38,    -1,     1,    -1,    -1,    43,    -1,
      -1,    35,    36,    37,    38,    11,     1,    -1,    -1,    43,
      -1,    -1,    18,    -1,    20,    21,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,    35,
      36,    37,    38,    -1,     1,    -1,    -1,    43,    -1,    -1,
      35,    36,    37,    38,    11,     1,    -1,    -1,    43,    -1,
      -1,    18,    -1,    20,    21,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    35,
      36,    37,    38,    12,    13,    14,    -1,    43,    17,    -1,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    33,    34,    -1,    12,    13,    14,
      -1,    16,    17,    -1,    19,    44,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      -1,    -1,    37,    -1,    -1,    40,    41,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    23,    24,    25,
      -1,    -1,    12,    13,    14,    31,    32,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    -1,    -1,    12,    13,    14,
      -1,    41,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      -1,    -1,    12,    13,    14,    -1,    41,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    -1,    -1,    12,    13,    14,
      -1,    41,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      -1,    -1,    12,    13,    14,    -1,    41,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    -1,    -1,    12,    13,    14,
      -1,    41,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      -1,    -1,    12,    13,    14,    -1,    41,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    -1,    -1,    12,    13,    14,
      -1,    41,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      -1,    12,    13,    14,    -1,    40,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    33,    34,    -1,    12,    13,    14,    39,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    33,    34,    12,    13,
      14,    -1,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    12,    13,    14,    -1,    16,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    33,    34,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    33,    34,    12,    13,    14,
      -1,    16,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      12,    13,    14,    -1,    -1,    17,    -1,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    33,    34,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    12,    13,    14,
      29,    30,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,
      -1,    12,    13,    14,    29,    30,    17,    -1,    19,    -1,
      -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    18,    20,    21,    24,    25,    26,    28,
      31,    35,    36,    37,    38,    39,    43,    48,    50,    51,
      58,    60,    61,    68,    73,    82,    87,    94,    95,    96,
      99,   102,   106,   107,   112,   117,   120,   121,   123,   125,
     131,   136,   137,   138,    12,    13,    14,    16,    17,    19,
      21,    22,    29,    30,    33,    34,    37,    40,    41,    37,
      42,    97,     1,    43,   103,     1,    37,   131,     1,   123,
       1,    37,    59,    16,    49,     1,    37,     1,   131,     1,
      15,    37,   126,   124,   131,    21,    37,    49,    27,    32,
      62,    63,   123,    42,    98,   100,    16,   131,    12,    13,
      14,    16,    17,    18,    19,    22,    29,    30,    33,    34,
     131,    15,   131,    15,   131,   131,   131,    49,   131,   131,
     131,   131,   131,    49,    43,   101,   131,    48,    45,   113,
     131,     1,   108,   111,     1,    10,    39,     1,    37,    39,
      89,    90,    92,   131,    69,     1,    42,    41,   122,    15,
      16,    43,    47,    41,    53,    37,    43,    52,    83,    42,
     123,    64,    62,    67,     1,    40,     1,   123,    23,   123,
      16,   134,     1,    15,   131,     1,    15,   131,    17,   132,
      18,   133,   135,     1,   131,     1,   131,     1,   131,     1,
     131,   131,   131,    76,    80,   123,    48,    48,    48,   104,
      10,    40,   110,     1,    39,    43,    89,    39,    15,    91,
       1,    88,    40,    42,    70,    71,     1,    39,   131,    37,
     127,    40,     1,    15,    16,    54,    49,    74,    78,    54,
      44,    50,    84,    85,    86,   123,   131,    32,    40,     1,
     123,   131,     1,   131,     1,   131,   131,   131,   131,    84,
      41,    48,    48,   114,    42,   105,    43,    10,    43,   109,
     131,   131,    40,    89,     1,    11,    20,    36,    38,    44,
      40,    89,    39,    42,    39,    72,    16,    16,     1,   129,
     131,   131,     1,   131,    84,    41,    84,    37,    41,    44,
      65,   131,    40,    41,    81,    41,    48,    48,   123,   131,
      43,   131,   131,    40,    41,    40,    44,    93,    37,    90,
      40,    63,    39,    63,    63,    44,   128,   130,    16,    16,
      16,    55,    56,    57,    41,    79,    84,    42,   123,    77,
     123,   118,    41,   115,    41,   131,    41,    41,    44,    40,
      63,    40,    40,   129,    41,    44,    40,    41,     3,     4,
       5,     6,     7,     8,     9,    10,    21,    23,    24,    25,
      31,    32,   139,    75,   123,   123,   123,   123,   119,    48,
      41,    37,    92,    40,   129,   123,    66,   123,    41,    63,
     116,   123
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    50,    50,    50,    50,    52,    51,    53,    51,
      51,    51,    51,    54,    54,    54,    54,    55,    54,    56,
      54,    57,    54,    58,    59,    58,    60,    61,    61,    62,
      62,    64,    65,    66,    63,    67,    63,    63,    63,    63,
      69,    68,    70,    68,    71,    68,    72,    68,    68,    73,
      74,    75,    73,    76,    77,    73,    78,    79,    73,    80,
      81,    73,    83,    82,    84,    84,    84,    85,    86,    88,
      87,    87,    89,    89,    91,    90,    90,    93,    92,    92,
      92,    92,    92,    92,    94,    94,    94,    94,    95,    95,
      97,    96,    98,    99,    99,    99,   100,    99,   101,    99,
      99,   103,   104,   102,   105,   105,   106,   106,   108,   107,
     109,   107,   110,   107,   111,   107,   107,   113,   114,   115,
     116,   112,   112,   118,   117,   119,   117,   120,   121,   121,
     122,   121,   124,   123,   126,   127,   128,   125,   125,   130,
     129,   129,   129,   129,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   132,   131,   133,   131,   134,   131,   135,
     131,   131,   131,   131,   131,   136,   136,   136,   136,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       3,     3,     4,     3,     3,     3,     1,     0,     4,     0,
       4,     0,     4,     1,     0,     3,     4,     3,     1,     3,
       2,     0,     0,     0,     8,     0,     5,     2,     1,     0,
       0,     7,     0,     8,     0,     7,     0,     7,     3,     2,
       0,     0,     8,     0,     0,     8,     0,     0,     7,     0,
       0,     7,     0,     5,     3,     1,     1,     2,     2,     0,
       6,     1,     1,     1,     0,     4,     1,     0,     6,     3,
       4,     3,     3,     3,     5,     4,     5,     6,     5,     3,
       0,     3,     2,     2,     4,     5,     0,     3,     0,     4,
       4,     0,     0,     6,     1,     0,     6,     1,     0,     7,
       0,     7,     0,     7,     0,     8,     6,     0,     0,     0,
       0,    11,     1,     0,     8,     0,     9,     2,     2,     3,
       0,     5,     0,     4,     0,     0,     0,     7,     3,     0,
       4,     3,     1,     0,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     0,     4,     0,     4,     0,     4,     0,
       4,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     4,     4,     3,     3,     3,     3,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 191 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1792 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 197 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1798 "parser.tab.c"
    break;

  case 9: /* STATEMENT: IF_STT  */
#line 201 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1804 "parser.tab.c"
    break;

  case 10: /* STATEMENT: WHILE_STT  */
#line 202 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1810 "parser.tab.c"
    break;

  case 11: /* STATEMENT: FOR_STT  */
#line 203 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1816 "parser.tab.c"
    break;

  case 12: /* STATEMENT: DO_WHILE_STT  */
#line 204 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1822 "parser.tab.c"
    break;

  case 13: /* STATEMENT: SWITCH_STT  */
#line 205 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1828 "parser.tab.c"
    break;

  case 14: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 206 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1834 "parser.tab.c"
    break;

  case 15: /* STATEMENT: ENUM_CALL_STT  */
#line 207 "parser.y"
                                                            {printf("#[Parsed_Enum_USAGE]# ");}
#line 1840 "parser.tab.c"
    break;

  case 17: /* STATEMENT: BREAK SEMICOLON_MISS  */
#line 209 "parser.y"
                                                            {StAssJmp("JMP", "END", &SMLabel_End, 0, 0);}
#line 1846 "parser.tab.c"
    break;

  case 18: /* STATEMENT: error SEMICOLON  */
#line 210 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1852 "parser.tab.c"
    break;

  case 19: /* STATEMENT: error '}'  */
#line 211 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1858 "parser.tab.c"
    break;

  case 20: /* STATEMENT: error ')'  */
#line 212 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1864 "parser.tab.c"
    break;

  case 22: /* TYPE: INT  */
#line 226 "parser.y"
                            { (yyval.str) = "int";   }
#line 1870 "parser.tab.c"
    break;

  case 23: /* TYPE: FLOAT  */
#line 227 "parser.y"
                            { (yyval.str) = "float"; }
#line 1876 "parser.tab.c"
    break;

  case 24: /* TYPE: BOOL  */
#line 228 "parser.y"
                            { (yyval.str) = "bool";  }
#line 1882 "parser.tab.c"
    break;

  case 25: /* TYPE: STRING  */
#line 229 "parser.y"
                            { (yyval.str) = "string";}
#line 1888 "parser.tab.c"
    break;

  case 26: /* $@1: %empty  */
#line 233 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0);   assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1894 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 233 "parser.y"
                                                                                                                                                         {printf("#[Parsed_Declaration]# "); }
#line 1900 "parser.tab.c"
    break;

  case 28: /* $@2: %empty  */
#line 234 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0); assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1906 "parser.tab.c"
    break;

  case 29: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 234 "parser.y"
                                                                                                                                                         {printf("#[Parsed_CONST_Declaration]# "); }
#line 1912 "parser.tab.c"
    break;

  case 30: /* DECLARATION_STT: error IDENTIFIER SEMICOLON_MISS  */
#line 235 "parser.y"
                                                                                                 {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);pErr(yylineno);}
#line 1918 "parser.tab.c"
    break;

  case 31: /* DECLARATION_STT: error CONSTANT SEMICOLON_MISS  */
#line 236 "parser.y"
                                                                                                 {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);pErr(yylineno);}
#line 1924 "parser.tab.c"
    break;

  case 32: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON_MISS  */
#line 237 "parser.y"
                                                                                                 {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);pErr(yylineno);}
#line 1930 "parser.tab.c"
    break;

  case 33: /* DECLARATION_TAIL: EQ EXPRESSION SEMICOLON  */
#line 242 "parser.y"
                                                                                            {StAssPush(strdup(IdentifierHolder)); StAssPrint("OVER", 1); StAssPrint("STORE", 1); StAssPrint("DROP", 1);}
#line 1936 "parser.tab.c"
    break;

  case 34: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 243 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 1942 "parser.tab.c"
    break;

  case 35: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 244 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);pErr(yylineno);}
#line 1948 "parser.tab.c"
    break;

  case 37: /* $@3: %empty  */
#line 246 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1954 "parser.tab.c"
    break;

  case 39: /* $@4: %empty  */
#line 247 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1960 "parser.tab.c"
    break;

  case 41: /* $@5: %empty  */
#line 248 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1966 "parser.tab.c"
    break;

  case 43: /* RETURN_STT: RETURN  */
#line 255 "parser.y"
                                                {int dum = 0;StAssPrint("POP\tPC",1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1972 "parser.tab.c"
    break;

  case 44: /* $@6: %empty  */
#line 256 "parser.y"
                         {assign_index =func_index;}
#line 1978 "parser.tab.c"
    break;

  case 45: /* RETURN_STT: RETURN $@6 EXPRESSION  */
#line 256 "parser.y"
                                                                            { return_exist = 1; StAssPrint("OVER",1);int dum = 0;StAssPrint("POP\tPC",1);StAssPrint("DNEXT", 1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1984 "parser.tab.c"
    break;

  case 46: /* helperSWITCH: SWITCH IDENTIFIER ':' '{'  */
#line 258 "parser.y"
                                          {strcpy(switcher, (yyvsp[-2].str));}
#line 1990 "parser.tab.c"
    break;

  case 47: /* SWITCH_STT: helperSWITCH CASES '}'  */
#line 261 "parser.y"
                                        {StAssPrintLBL(0,1);}
#line 1996 "parser.tab.c"
    break;

  case 49: /* DEFAULTCASE: DEFAULT ':' BLOCK  */
#line 266 "parser.y"
                                  {StAssJmp("JMP", "END",&SMLabel_End, 0,0); }
#line 2002 "parser.tab.c"
    break;

  case 50: /* DEFAULTCASE: DEFAULT BLOCK  */
#line 267 "parser.y"
                                {printf("\n\n=====ERROR====\n missing colon ':' at DEFAULT CASE of switch, error at line %d\n\n", yylineno); pErr(yylineno);}
#line 2008 "parser.tab.c"
    break;

  case 51: /* $@7: %empty  */
#line 270 "parser.y"
                     {StAssPush(switcher);}
#line 2014 "parser.tab.c"
    break;

  case 52: /* $@8: %empty  */
#line 270 "parser.y"
                                                       {StAssPrint("EQ", 1); StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2020 "parser.tab.c"
    break;

  case 53: /* $@9: %empty  */
#line 270 "parser.y"
                                                                                                                                   {StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2026 "parser.tab.c"
    break;

  case 55: /* $@10: %empty  */
#line 271 "parser.y"
                              {printf("\n\n=====ERROR====\n DEFAULT CASE must be written at the end of the switch statement, error at line %d\n\n", yylineno); pErr(yylineno);}
#line 2032 "parser.tab.c"
    break;

  case 57: /* CASES: DEFAULTCASE DEFAULTCASE  */
#line 272 "parser.y"
                                                                {printf("\n\n=====ERROR====\n only 1 DEFAULT CASE is allowed in the switch statement error, at line %d\n\n", yylineno); pErr(yylineno);}
#line 2038 "parser.tab.c"
    break;

  case 60: /* $@11: %empty  */
#line 284 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2044 "parser.tab.c"
    break;

  case 62: /* $@12: %empty  */
#line 285 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); pErr(yylineno);}
#line 2050 "parser.tab.c"
    break;

  case 64: /* $@13: %empty  */
#line 286 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);pErr(yylineno);}
#line 2056 "parser.tab.c"
    break;

  case 66: /* $@14: %empty  */
#line 287 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2062 "parser.tab.c"
    break;

  case 68: /* ERRONOUS_SWITCH_STT: helperSWITCH CASES error  */
#line 288 "parser.y"
                                           {printf("\n\n=====ERROR====\n unclosed '}' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2068 "parser.tab.c"
    break;

  case 70: /* $@15: %empty  */
#line 301 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2074 "parser.tab.c"
    break;

  case 71: /* $@16: %empty  */
#line 301 "parser.y"
                                                                                                                    {func_index = st_insert((yyvsp[-5].str), (yyvsp[-4].str),"func",0); popArgs();}
#line 2080 "parser.tab.c"
    break;

  case 73: /* $@17: %empty  */
#line 302 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2086 "parser.tab.c"
    break;

  case 74: /* $@18: %empty  */
#line 302 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-4].str),"func",0); popArgs();}
#line 2092 "parser.tab.c"
    break;

  case 76: /* $@19: %empty  */
#line 303 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2098 "parser.tab.c"
    break;

  case 77: /* $@20: %empty  */
#line 303 "parser.y"
                                                                                                                    {func_index=st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2104 "parser.tab.c"
    break;

  case 79: /* $@21: %empty  */
#line 304 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2110 "parser.tab.c"
    break;

  case 80: /* $@22: %empty  */
#line 304 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-3].str),"func",0);}
#line 2116 "parser.tab.c"
    break;

  case 82: /* $@23: %empty  */
#line 309 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));pErr(yylineno);}
#line 2122 "parser.tab.c"
    break;

  case 83: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@23 ARGS ')'  */
#line 309 "parser.y"
                                                                                                                                                                                                                   {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2128 "parser.tab.c"
    break;

  case 87: /* ERRONOUS_ARGS: ',' ARGS  */
#line 324 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);pErr(yylineno);}
#line 2134 "parser.tab.c"
    break;

  case 88: /* ARG_DECL: TYPE IDENTIFIER  */
#line 327 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1); char* buf=(yyvsp[0].str); argumentList[argPointer]=buf;argPointer++;}
#line 2140 "parser.tab.c"
    break;

  case 89: /* $@24: %empty  */
#line 334 "parser.y"
                                      { is_enum =1;}
#line 2146 "parser.tab.c"
    break;

  case 90: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' $@24 ENUM_HELPER '}'  */
#line 334 "parser.y"
                                                                              { st_insert("enum" , (yyvsp[-4].str), "var" , 0); is_enum=0; enumCNT=1;}
#line 2152 "parser.tab.c"
    break;

  case 94: /* $@25: %empty  */
#line 340 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++;  st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int(  enum_arg_count-1,st_index-1); }
#line 2158 "parser.tab.c"
    break;

  case 96: /* ENUM_ARGS: IDENTIFIER  */
#line 341 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++; st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int( enum_arg_count-1,st_index-1);  }
#line 2164 "parser.tab.c"
    break;

  case 97: /* $@26: %empty  */
#line 347 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++ ; st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2170 "parser.tab.c"
    break;

  case 99: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ DIGIT  */
#line 348 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++;  st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2176 "parser.tab.c"
    break;

  case 100: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ error ','  */
#line 349 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2182 "parser.tab.c"
    break;

  case 101: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ FLOAT_DIGIT  */
#line 350 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2188 "parser.tab.c"
    break;

  case 102: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ STRING_LITERAL  */
#line 351 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2194 "parser.tab.c"
    break;

  case 103: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ BOOL_LITERAL  */
#line 352 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2200 "parser.tab.c"
    break;

  case 104: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 356 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2206 "parser.tab.c"
    break;

  case 105: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 357 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2212 "parser.tab.c"
    break;

  case 106: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 359 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2218 "parser.tab.c"
    break;

  case 107: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER error '{' ENUM_HELPER '}'  */
#line 360 "parser.y"
                                                            {printf("\n\n=====ERROR====\n UnExpected IDENTIFIER in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2224 "parser.tab.c"
    break;

  case 108: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER EQ IDENTIFIER SEMICOLON  */
#line 364 "parser.y"
                                                               { StAssPush((yyvsp[-3].str));StAssPush((yyvsp[-1].str));StAssPrint("STORE",1); st_insert((yyvsp[-4].str) , (yyvsp[-3].str), "var_enum" , 0); assign_enum(st_index-1, (yyvsp[-4].str),(yyvsp[-1].str)); int i= lookup((yyvsp[-4].str), 0); symbolTable[i].isUsed=1; }
#line 2230 "parser.tab.c"
    break;

  case 109: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER SEMICOLON  */
#line 365 "parser.y"
                                                   { st_insert((yyvsp[-2].str) , (yyvsp[-1].str), "var_enum" , 0); int i= lookup((yyvsp[-2].str),0); symbolTable[i].isUsed=1;}
#line 2236 "parser.tab.c"
    break;

  case 110: /* $@27: %empty  */
#line 369 "parser.y"
                   {printIF();}
#line 2242 "parser.tab.c"
    break;

  case 111: /* IF_STT_HELPER: IF $@27 EXPRESSION  */
#line 369 "parser.y"
                                           {StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2248 "parser.tab.c"
    break;

  case 112: /* IF_STT_HELPER1: ':' BLOCK  */
#line 372 "parser.y"
                                                            {controlTerminator(0);  StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2254 "parser.tab.c"
    break;

  case 113: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1  */
#line 376 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2260 "parser.tab.c"
    break;

  case 114: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE BLOCK  */
#line 377 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2266 "parser.tab.c"
    break;

  case 115: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE error '}'  */
#line 378 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2272 "parser.tab.c"
    break;

  case 116: /* $@28: %empty  */
#line 379 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2278 "parser.tab.c"
    break;

  case 118: /* $@29: %empty  */
#line 380 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2284 "parser.tab.c"
    break;

  case 120: /* IF_STT: IF_STT_HELPER ':' error '}'  */
#line 381 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2290 "parser.tab.c"
    break;

  case 121: /* $@30: %empty  */
#line 390 "parser.y"
                      {printWHILE(); StAssPrintLBL(1, 0);}
#line 2296 "parser.tab.c"
    break;

  case 122: /* $@31: %empty  */
#line 390 "parser.y"
                                                                      {StAssJmp("JNZ", "END",&SMLabel_End, 0,0);}
#line 2302 "parser.tab.c"
    break;

  case 123: /* WHILE_STT: WHILE $@30 EXPRESSION $@31 WHILEMISS_COLON BLOCK  */
#line 390 "parser.y"
                                                                                                                                        {StAssJmp("JMP", "LBL",&SMLabel_Else, 1,0); StAssPrintLBL(0, 1);}
#line 2308 "parser.tab.c"
    break;

  case 125: /* WHILEMISS_COLON: %empty  */
#line 398 "parser.y"
                  {printf("\n\n=====ERROR====\n Missing ':' for the WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2314 "parser.tab.c"
    break;

  case 128: /* $@32: %empty  */
#line 407 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2320 "parser.tab.c"
    break;

  case 130: /* $@33: %empty  */
#line 408 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2326 "parser.tab.c"
    break;

  case 132: /* $@34: %empty  */
#line 409 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2332 "parser.tab.c"
    break;

  case 134: /* $@35: %empty  */
#line 410 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2338 "parser.tab.c"
    break;

  case 136: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 411 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);pErr(yylineno);}
#line 2344 "parser.tab.c"
    break;

  case 137: /* $@36: %empty  */
#line 418 "parser.y"
                        {in_loop = 1;}
#line 2350 "parser.tab.c"
    break;

  case 138: /* $@37: %empty  */
#line 418 "parser.y"
                                                 {StAssForHeader();}
#line 2356 "parser.tab.c"
    break;

  case 139: /* $@38: %empty  */
#line 418 "parser.y"
                                                                               {StAssForMiddle();}
#line 2362 "parser.tab.c"
    break;

  case 140: /* $@39: %empty  */
#line 418 "parser.y"
                                                                                                                {StAssPrintLBL(1,1); in_loop = 0;}
#line 2368 "parser.tab.c"
    break;

  case 141: /* FOR_STT: FOR '(' $@36 STATEMENT $@37 STATEMENT $@38 STATEMENT ')' $@39 BLOCK  */
#line 418 "parser.y"
                                                                                                                                                          {StAssJmp("JMP", "Label", &ForHeaderLabel,1,0); StAssPrintLBL(0,1);}
#line 2374 "parser.tab.c"
    break;

  case 143: /* $@40: %empty  */
#line 423 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2380 "parser.tab.c"
    break;

  case 145: /* $@41: %empty  */
#line 424 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2386 "parser.tab.c"
    break;

  case 147: /* helperAssignmentRule: IDENTIFIER EQ  */
#line 431 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); StAssPush((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str),1);}
#line 2392 "parser.tab.c"
    break;

  case 148: /* assignmentSTT: helperAssignmentRule SEMICOLON  */
#line 435 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2398 "parser.tab.c"
    break;

  case 149: /* assignmentSTT: helperAssignmentRule EXPRESSION SEMICOLON  */
#line 436 "parser.y"
                                                                 {StAssPrint("STORE", 1); CodeGenAss();printf("#[Parsed_Assignment]# ");}
#line 2404 "parser.tab.c"
    break;

  case 150: /* $@42: %empty  */
#line 437 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str),1); StAssPush((yyvsp[-1].str));}
#line 2410 "parser.tab.c"
    break;

  case 151: /* assignmentSTT: IDENTIFIER error $@42 EXPRESSION SEMICOLON  */
#line 437 "parser.y"
                                                                                                                                                        {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2416 "parser.tab.c"
    break;

  case 152: /* $@43: %empty  */
#line 442 "parser.y"
                    {scope_start();}
#line 2422 "parser.tab.c"
    break;

  case 153: /* BLOCK: '{' $@43 PROGRAM '}'  */
#line 442 "parser.y"
                                                                              {scope_end(); printf("#[Parsed_Block]# ");}
#line 2428 "parser.tab.c"
    break;

  case 154: /* $@44: %empty  */
#line 450 "parser.y"
                           {called_func_index = lookup((yyvsp[0].str),0); check_type(called_func_index); StAssPush("PC");}
#line 2434 "parser.tab.c"
    break;

  case 155: /* $@45: %empty  */
#line 450 "parser.y"
                                                                                                                   { is_param =1;}
#line 2440 "parser.tab.c"
    break;

  case 156: /* $@46: %empty  */
#line 450 "parser.y"
                                                                                                                                              { is_param =0; arg_count_check(called_func_index); arg_count=0; int dum=0; StAssJmp("JMP", (yyvsp[-4].str),&dum, 0,0);}
#line 2446 "parser.tab.c"
    break;

  case 157: /* FUNC_CALL: IDENTIFIER $@44 '(' $@45 USED_ARGS $@46 ')'  */
#line 450 "parser.y"
                                                                                                                                                                                                                                                               { printf("#[Parsed_Func_Call]# ");}
#line 2452 "parser.tab.c"
    break;

  case 158: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 451 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);pErr(yylineno);}
#line 2458 "parser.tab.c"
    break;

  case 159: /* $@47: %empty  */
#line 456 "parser.y"
                           { arg_count++; }
#line 2464 "parser.tab.c"
    break;

  case 161: /* USED_ARGS: error ',' USED_ARGS  */
#line 457 "parser.y"
                                                            {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2470 "parser.tab.c"
    break;

  case 162: /* USED_ARGS: EXPRESSION  */
#line 458 "parser.y"
                             {arg_count++ ;}
#line 2476 "parser.tab.c"
    break;

  case 164: /* EXPRESSION: IDENTIFIER  */
#line 465 "parser.y"
                                                { int i = lookup((yyvsp[0].str),0); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2482 "parser.tab.c"
    break;

  case 165: /* EXPRESSION: DIGIT  */
#line 466 "parser.y"
                                                { assign_int((yyvsp[0].num), assign_index) ; char numtostring[40]; itoa((yyvsp[0].num), numtostring, 10); pushVStack(numtostring); char dum[10]="$"; StAssPush(strcat(dum,numtostring));}
#line 2488 "parser.tab.c"
    break;

  case 166: /* EXPRESSION: FLOAT_DIGIT  */
#line 467 "parser.y"
                                                { assign_int((yyvsp[0].float_val), assign_index); char floattostring[40]; gcvt((yyvsp[0].float_val), 6, floattostring); pushVStack(floattostring); char dum[10]="$"; StAssPush(strcat(dum,floattostring));}
#line 2494 "parser.tab.c"
    break;

  case 167: /* EXPRESSION: BOOL_LITERAL  */
#line 468 "parser.y"
                                                { assign_int((yyvsp[0].bool_val), assign_index); if((yyvsp[0].bool_val)==true){pushVStack("true");StAssPush("$true");}else{pushVStack("false");StAssPush("$false");} }
#line 2500 "parser.tab.c"
    break;

  case 168: /* EXPRESSION: STRING_LITERAL  */
#line 469 "parser.y"
                                                { assign_str((yyvsp[0].str), assign_index); pushVStack((yyvsp[0].str));char buf[50]; strcpy(buf, "$");strcat(buf, (yyvsp[0].str)); StAssPush(buf);}
#line 2506 "parser.tab.c"
    break;

  case 169: /* EXPRESSION: CONSTANT  */
#line 470 "parser.y"
                                                { int i = lookup((yyvsp[0].str),0); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2512 "parser.tab.c"
    break;

  case 170: /* EXPRESSION: SUB EXPRESSION  */
#line 471 "parser.y"
                                                {StAssPrint("neg", 1);}
#line 2518 "parser.tab.c"
    break;

  case 171: /* EXPRESSION: EXPRESSION PLUS PLUS  */
#line 472 "parser.y"
                                                { pushVStack("+"); pushVStack("1"); CodeGenOp("ADD"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("ADD", 1); StAssPrint("STORE", 1);}
#line 2524 "parser.tab.c"
    break;

  case 172: /* EXPRESSION: EXPRESSION SUB SUB  */
#line 473 "parser.y"
                                                { pushVStack("-"); pushVStack("1"); CodeGenOp("SUB"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("SUB", 1); StAssPrint("STORE", 1);}
#line 2530 "parser.tab.c"
    break;

  case 173: /* $@48: %empty  */
#line 474 "parser.y"
                                                { pushVStack("+");}
#line 2536 "parser.tab.c"
    break;

  case 174: /* EXPRESSION: EXPRESSION PLUS $@48 EXPRESSION  */
#line 474 "parser.y"
                                                                                 {CodeGenOp("ADD"); StAssPrint("ADD", 1);}
#line 2542 "parser.tab.c"
    break;

  case 175: /* $@49: %empty  */
#line 476 "parser.y"
                                                { pushVStack("*");}
#line 2548 "parser.tab.c"
    break;

  case 176: /* EXPRESSION: EXPRESSION MUL $@49 EXPRESSION  */
#line 476 "parser.y"
                                                                                 {CodeGenOp("MUL"); StAssPrint("MUL", 1);}
#line 2554 "parser.tab.c"
    break;

  case 177: /* $@50: %empty  */
#line 477 "parser.y"
                                                { pushVStack("/");}
#line 2560 "parser.tab.c"
    break;

  case 178: /* EXPRESSION: EXPRESSION DIV $@50 EXPRESSION  */
#line 477 "parser.y"
                                                                                 {CodeGenOp("DIV"); StAssPrint("DIV", 1);}
#line 2566 "parser.tab.c"
    break;

  case 179: /* $@51: %empty  */
#line 480 "parser.y"
                                                {pushVStack("^");}
#line 2572 "parser.tab.c"
    break;

  case 180: /* EXPRESSION: EXPRESSION POW $@51 EXPRESSION  */
#line 480 "parser.y"
                                                                               {CodeGenOp("POW");}
#line 2578 "parser.tab.c"
    break;

  case 184: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 484 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);pErr(yylineno);}
#line 2584 "parser.tab.c"
    break;

  case 189: /* COMPARISONSTT: EXPRESSION GT EXPRESSION  */
#line 504 "parser.y"
                                                        {pushVStack(">"); CodeGenLogical(); StAssPrint("GT", 1);}
#line 2590 "parser.tab.c"
    break;

  case 190: /* COMPARISONSTT: EXPRESSION LT EXPRESSION  */
#line 505 "parser.y"
                                                        {pushVStack("<"); CodeGenLogical(); StAssPrint("LT", 1);}
#line 2596 "parser.tab.c"
    break;

  case 191: /* COMPARISONSTT: EXPRESSION LT EQ EXPRESSION  */
#line 506 "parser.y"
                                                        {pushVStack("<="); CodeGenLogical(); StAssPrint("LE", 1);}
#line 2602 "parser.tab.c"
    break;

  case 192: /* COMPARISONSTT: EXPRESSION GT EQ EXPRESSION  */
#line 507 "parser.y"
                                                        {pushVStack(">="); CodeGenLogical(); StAssPrint("GE", 1);}
#line 2608 "parser.tab.c"
    break;

  case 193: /* COMPARISONSTT: EXPRESSION EQUALITY EXPRESSION  */
#line 508 "parser.y"
                                                        {pushVStack("="); CodeGenLogical(); StAssPrint("EQ", 1);}
#line 2614 "parser.tab.c"
    break;

  case 194: /* COMPARISONSTT: EXPRESSION NEG_EQUALITY EXPRESSION  */
#line 509 "parser.y"
                                                        {pushVStack("!="); CodeGenLogical(); StAssPrint("NE", 1);}
#line 2620 "parser.tab.c"
    break;

  case 195: /* COMPARISONSTT: EXPRESSION LOGIC_AND EXPRESSION  */
#line 510 "parser.y"
                                                        {pushVStack("and"); CodeGenLogical(); StAssPrint("AND", 1);}
#line 2626 "parser.tab.c"
    break;

  case 196: /* COMPARISONSTT: EXPRESSION LOGIC_OR EXPRESSION  */
#line 511 "parser.y"
                                                        {pushVStack("or"); CodeGenLogical(); StAssPrint("OR", 1);}
#line 2632 "parser.tab.c"
    break;

  case 197: /* COMPARISONSTT: LOGIC_NOT EXPRESSION  */
#line 512 "parser.y"
                                                        {StAssPrint("neg", 1);}
#line 2638 "parser.tab.c"
    break;

  case 199: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 517 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2644 "parser.tab.c"
    break;

  case 200: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 518 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2650 "parser.tab.c"
    break;

  case 201: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 519 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2656 "parser.tab.c"
    break;

  case 202: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 520 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2662 "parser.tab.c"
    break;

  case 203: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 521 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2668 "parser.tab.c"
    break;

  case 204: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 522 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2674 "parser.tab.c"
    break;

  case 205: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 523 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2680 "parser.tab.c"
    break;

  case 206: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 524 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2686 "parser.tab.c"
    break;

  case 207: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 525 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2692 "parser.tab.c"
    break;

  case 208: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 526 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2698 "parser.tab.c"
    break;

  case 209: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 527 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2704 "parser.tab.c"
    break;

  case 210: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 528 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2710 "parser.tab.c"
    break;

  case 211: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 529 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2716 "parser.tab.c"
    break;

  case 212: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 530 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2722 "parser.tab.c"
    break;

  case 213: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 531 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2728 "parser.tab.c"
    break;

  case 214: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 532 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2734 "parser.tab.c"
    break;

  case 215: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 533 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2740 "parser.tab.c"
    break;


#line 2744 "parser.tab.c"

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

#line 552 "parser.y"




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
                printf("\n !!!!!!!!!!!! Error at line %d: %s used before initialized !!!!!!!!!!!\n", line_number, name); sErr(line_number);
            }
            }
             if (is_assignment == 0) {symbolTable[i].isUsed=1;}
            return i;
        }
    }
    printf("\n !!!!!!!!!!!! Error at line %d: %s undeclared identifier in this scope !!!!!!!!!!!\n", line_number, name);
    // assign_index=-1;TODO
    sErr(line_number);
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
        sErr(line_number);
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
    // printf("\n\n hhhhhhhhhhhhhhhhhhhhhhhhhhh %d %d %s \n\n", d, i , symbolTable[i].name);
    if (i == -1) {return;}
    if ( symbolTable[i].dataType == "string" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned int !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
    sErr(line_number);
     return; }
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType != "string" && symbolTable[i].outOfScope == 0 ) {symbolTable[i].intValue= d ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned wrong value!!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
    sErr(line_number);}
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
     sErr(line_number);
     return ;} 
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "string"){symbolTable[i].strValue= s ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned string value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );
    sErr(line_number);}
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
                sErr(line_number);
                assign_index = -1;
                return;
            }
        }
    }
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned enum value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );
    sErr(line_number);}
    assign_index = -1;
}
// void check_param_type (int i) {

// }
void check_type( int i) {
    // this functio check type matching between 2 identifiers before assign the value
    // if ( is_param == 1) TODO
    // { assign_index = arg_count;}
     if ( i == -1 || assign_index == -1) 
    { return;}
    if (symbolTable[i].dataType != symbolTable[assign_index].dataType && (symbolTable[assign_index].dataType == "string" ||  symbolTable[i].dataType == "string"))
    {   /// at calling a function
        if (strcmp(symbolTable[i].type,"func")== 0){ printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s return %s value  !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType ); sErr(line_number);}
        else if (strcmp(symbolTable[assign_index].type,"func")== 0){ printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s return %s value  !!!!!!!!!!!\n", line_number,symbolTable[i].name,symbolTable[i].dataType, symbolTable[assign_index].name,symbolTable[assign_index].dataType ); sErr(line_number);}
        else if (is_param == 1)
        {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Incorrect argument type %s is %s variable but %s %s !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType ); sErr(line_number);}
        else {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s %s !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType );sErr(line_number);}
    }
    else if (strcmp(symbolTable[assign_index].type,"func") != 0)
    {
        symbolTable[assign_index].isInit=1;
        // assign value to the variable
        if ( strcmp(symbolTable[i].dataType,"int") ==0 || strcmp(symbolTable[i].type,"var_enum") ==0  ) {
            symbolTable[assign_index].intValue= symbolTable[i].intValue ;}
        else if (symbolTable[i].dataType == "float"){symbolTable[assign_index].floatValue= symbolTable[i].floatValue ;}
        else if ( strcmp(symbolTable[i].dataType, "string")==0){symbolTable[assign_index].strValue= symbolTable[i].strValue ;}
        else if (symbolTable[i].dataType == "bool"){symbolTable[assign_index].boolValue= symbolTable[i].boolValue ;}
        st_log();
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
    {printf("\n !!!!!!!!!!!! Error at line %d: Missing return statement in Function %s !!!!!!!!!!!\n", line_number, symbolTable[func_index].name); sErr(line_number);}
    assign_index=-1;
    func_index =-1;
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
        if (strcmp(symbolTable[i].type,"func") == 0){printf("\n !!!!!!!!!!!! Function %s Declared at line %d but never called !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); sErr(symbolTable[i].declareLine);}
        else if ( symbolTable[i].isArg == 1){printf("\n !!!!!!!!!!!! Unused Argument %s Declared in Function at line %d !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); sErr(symbolTable[i].declareLine);}
        else {printf("\n !!!!!!!!!!!! Unused Identifier %s Declared at line %d !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); sErr(symbolTable[i].declareLine);}
        }
    }
}
void arg_count_check( int i) {
    if ( arg_count > symbolTable[i].argCount )
    {printf("\n !!!!!!!!!!!! Error at line %d : too many arguments for function call expected %d got %d !!!!!!!!!!!\n", line_number, symbolTable[i].argCount, arg_count); sErr(line_number);}
    else if ( arg_count < symbolTable[i].argCount )
    {printf("\n !!!!!!!!!!!! Error at line %d : too few arguments for function call expected %d got %d !!!!!!!!!!!\n", line_number, symbolTable[i].argCount, arg_count); sErr(line_number); }
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



void prependFile(char* filename, char* text) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(fsize + 1);
    fread(buffer, 1, fsize, file);
    fclose(file);
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(file, "%s", text);
    fwrite(buffer, 1, fsize, file);
    fclose(file);
    free(buffer);
}


void printDataSegment()
{
    char DS[5000];
    strcpy(DS, "");
    for (int i = 0 ; i < st_index-1 ; i++)
    {
        if((strcmp(symbolTable[i].type, "func") != 0) && (strcmp(symbolTable[i].dataType , "int")==0 || strcmp(symbolTable[i].dataType , "float")==0 || strcmp(symbolTable[i].dataType ,"bool")==0 || strcmp(symbolTable[i].dataType , "string")==0))
        {
            strcat(DS, "VAR\t");
            char buff [500];
            strcpy(buff, symbolTable[i].name);
            strcat(DS, buff);
            strcat(DS, "\n");
        }
    }
    strcat(DS, "\n\n");
    char* filename = "stackassembly.txt";
    prependFile(filename, DS);
};

void pErr(int lineNUMM)
{
    FILE *assfile = fopen("ParsingErrors.txt", "a");
    char buf [50];
    itoa(lineNUMM, buf,10);
    fprintf(assfile, "%s ", buf);
    fclose (assfile);
};



void sErr(int num)
{
    FILE *semfile = fopen("SemanticErrors.txt", "a");
     if(semfile == NULL) {
        printf("can't open SemanticErrors.txt file!\n");
        exit(1);
    }

    fprintf(semfile, "%d ", num);
    
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
    printDataSegment();

    return 0;
}
