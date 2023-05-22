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
    //-- symbol table functions:  st_functionName()
    int st_insert(char* data_type, char* name, char* type, int is_arg);
    void st_print();
    void st_log();
    void clear_logs();
    int is_exist(char* name);
    int lookup(char* name);
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
    void assign_bool( bool b , int i);
    void assign_float( float f , int i);
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
//==================================================================================================================================================


#line 204 "parser.tab.c"

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
  YYSYMBOL_EQUALITY = 27,                  /* EQUALITY  */
  YYSYMBOL_NEG_EQUALITY = 28,              /* NEG_EQUALITY  */
  YYSYMBOL_SWITCH = 29,                    /* SWITCH  */
  YYSYMBOL_CASE = 30,                      /* CASE  */
  YYSYMBOL_LOGIC_AND = 31,                 /* LOGIC_AND  */
  YYSYMBOL_LOGIC_OR = 32,                  /* LOGIC_OR  */
  YYSYMBOL_LOGIC_NOT = 33,                 /* LOGIC_NOT  */
  YYSYMBOL_DIGIT = 34,                     /* DIGIT  */
  YYSYMBOL_IDENTIFIER = 35,                /* IDENTIFIER  */
  YYSYMBOL_FLOAT_DIGIT = 36,               /* FLOAT_DIGIT  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* ':'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_PROGRAM = 45,                   /* PROGRAM  */
  YYSYMBOL_STATEMENT = 46,                 /* STATEMENT  */
  YYSYMBOL_TYPE = 47,                      /* TYPE  */
  YYSYMBOL_DECLARATION_STT = 48,           /* DECLARATION_STT  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_DECLARATION_TAIL = 51,          /* DECLARATION_TAIL  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_53_4 = 53,                      /* $@4  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_RETURN_STT = 55,                /* RETURN_STT  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_SWITCH_STT = 57,                /* SWITCH_STT  */
  YYSYMBOL_CASES = 58,                     /* CASES  */
  YYSYMBOL_ERRONOUS_CASES = 59,            /* ERRONOUS_CASES  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 62,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_65_11 = 65,                     /* $@11  */
  YYSYMBOL_66_12 = 66,                     /* $@12  */
  YYSYMBOL_FUNC_DECLARATION_STT = 67,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_68_13 = 68,                     /* $@13  */
  YYSYMBOL_69_14 = 69,                     /* $@14  */
  YYSYMBOL_70_15 = 70,                     /* $@15  */
  YYSYMBOL_71_16 = 71,                     /* $@16  */
  YYSYMBOL_72_17 = 72,                     /* $@17  */
  YYSYMBOL_73_18 = 73,                     /* $@18  */
  YYSYMBOL_74_19 = 74,                     /* $@19  */
  YYSYMBOL_75_20 = 75,                     /* $@20  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 76, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_77_21 = 77,                     /* $@21  */
  YYSYMBOL_ARGS = 78,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 79,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 80,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 81,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_82_22 = 82,                     /* $@22  */
  YYSYMBOL_ENUM_HELPER = 83,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 84,                 /* ENUM_ARGS  */
  YYSYMBOL_85_23 = 85,                     /* $@23  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 86,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_87_24 = 87,                     /* $@24  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 88, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_CALL_STT = 89,             /* ENUM_CALL_STT  */
  YYSYMBOL_IF_STT_HELPER = 90,             /* IF_STT_HELPER  */
  YYSYMBOL_91_25 = 91,                     /* $@25  */
  YYSYMBOL_IF_STT_HELPER1 = 92,            /* IF_STT_HELPER1  */
  YYSYMBOL_IF_STT = 93,                    /* IF_STT  */
  YYSYMBOL_94_26 = 94,                     /* $@26  */
  YYSYMBOL_95_27 = 95,                     /* $@27  */
  YYSYMBOL_WHILE_STT = 96,                 /* WHILE_STT  */
  YYSYMBOL_97_28 = 97,                     /* $@28  */
  YYSYMBOL_98_29 = 98,                     /* $@29  */
  YYSYMBOL_DO_WHILE_STT = 99,              /* DO_WHILE_STT  */
  YYSYMBOL_ERRONOUS_DO_WHILE = 100,        /* ERRONOUS_DO_WHILE  */
  YYSYMBOL_101_30 = 101,                   /* $@30  */
  YYSYMBOL_102_31 = 102,                   /* $@31  */
  YYSYMBOL_103_32 = 103,                   /* $@32  */
  YYSYMBOL_104_33 = 104,                   /* $@33  */
  YYSYMBOL_FOR_STT = 105,                  /* FOR_STT  */
  YYSYMBOL_106_34 = 106,                   /* $@34  */
  YYSYMBOL_107_35 = 107,                   /* $@35  */
  YYSYMBOL_108_36 = 108,                   /* $@36  */
  YYSYMBOL_109_37 = 109,                   /* $@37  */
  YYSYMBOL_ERRONOUS_FOR_LOOP = 110,        /* ERRONOUS_FOR_LOOP  */
  YYSYMBOL_111_38 = 111,                   /* $@38  */
  YYSYMBOL_112_39 = 112,                   /* $@39  */
  YYSYMBOL_helperAssignmentRule = 113,     /* helperAssignmentRule  */
  YYSYMBOL_assignmentSTT = 114,            /* assignmentSTT  */
  YYSYMBOL_115_40 = 115,                   /* $@40  */
  YYSYMBOL_BLOCK = 116,                    /* BLOCK  */
  YYSYMBOL_117_41 = 117,                   /* $@41  */
  YYSYMBOL_FUNC_CALL = 118,                /* FUNC_CALL  */
  YYSYMBOL_119_42 = 119,                   /* $@42  */
  YYSYMBOL_120_43 = 120,                   /* $@43  */
  YYSYMBOL_121_44 = 121,                   /* $@44  */
  YYSYMBOL_USED_ARGS = 122,                /* USED_ARGS  */
  YYSYMBOL_123_45 = 123,                   /* $@45  */
  YYSYMBOL_EXPRESSION = 124,               /* EXPRESSION  */
  YYSYMBOL_125_46 = 125,                   /* $@46  */
  YYSYMBOL_126_47 = 126,                   /* $@47  */
  YYSYMBOL_127_48 = 127,                   /* $@48  */
  YYSYMBOL_128_49 = 128,                   /* $@49  */
  YYSYMBOL_ERRONOUS_EXPRESSION = 129,      /* ERRONOUS_EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 130,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 131,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 132                  /* RES_WORD  */
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
#define YYLAST   1138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  379

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      41,    39,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   182,   182,   183,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     210,   211,   212,   213,   217,   217,   218,   218,   219,   220,
     221,   226,   227,   228,   229,   230,   230,   231,   231,   232,
     232,   239,   240,   240,   244,   245,   250,   251,   252,   256,
     256,   257,   257,   261,   261,   262,   262,   263,   263,   264,
     264,   277,   278,   278,   278,   279,   279,   279,   280,   280,
     280,   281,   281,   281,   286,   286,   296,   297,   298,   301,
     304,   311,   311,   312,   314,   314,   317,   317,   318,   324,
     324,   325,   326,   327,   328,   329,   333,   334,   336,   339,
     340,   344,   344,   347,   351,   352,   353,   354,   354,   355,
     355,   356,   365,   365,   365,   374,   375,   378,   378,   379,
     379,   380,   380,   381,   381,   382,   389,   389,   389,   389,
     389,   390,   394,   394,   395,   395,   402,   406,   407,   408,
     408,   413,   413,   421,   421,   421,   421,   422,   426,   426,
     427,   428,   429,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   444,   446,   446,   447,   447,   450,   450,
     451,   452,   453,   454,   463,   465,   466,   467,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511
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
  "CONSTANT", "POW", "ELSE", "DO", "ENUM", "RETURN", "EQUALITY",
  "NEG_EQUALITY", "SWITCH", "CASE", "LOGIC_AND", "LOGIC_OR", "LOGIC_NOT",
  "DIGIT", "IDENTIFIER", "FLOAT_DIGIT", "'{'", "'}'", "')'", "':'", "'('",
  "','", "';'", "$accept", "PROGRAM", "STATEMENT", "TYPE",
  "DECLARATION_STT", "$@1", "$@2", "DECLARATION_TAIL", "$@3", "$@4", "$@5",
  "RETURN_STT", "$@6", "SWITCH_STT", "CASES", "ERRONOUS_CASES", "$@7",
  "$@8", "ERRONOUS_SWITCH_STT", "$@9", "$@10", "$@11", "$@12",
  "FUNC_DECLARATION_STT", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18",
  "$@19", "$@20", "ERRONOUS_FUNC_DECLARATION_STT", "$@21", "ARGS",
  "ERRONOUS_ARGS", "ARG_DECL", "ENUM_DECLARATION_STT", "$@22",
  "ENUM_HELPER", "ENUM_ARGS", "$@23", "ENUM_DEFINED_ARGS", "$@24",
  "ERRONOUS_ENUM_DECLARATION_STT", "ENUM_CALL_STT", "IF_STT_HELPER",
  "$@25", "IF_STT_HELPER1", "IF_STT", "$@26", "$@27", "WHILE_STT", "$@28",
  "$@29", "DO_WHILE_STT", "ERRONOUS_DO_WHILE", "$@30", "$@31", "$@32",
  "$@33", "FOR_STT", "$@34", "$@35", "$@36", "$@37", "ERRONOUS_FOR_LOOP",
  "$@38", "$@39", "helperAssignmentRule", "assignmentSTT", "$@40", "BLOCK",
  "$@41", "FUNC_CALL", "$@42", "$@43", "$@44", "USED_ARGS", "$@45",
  "EXPRESSION", "$@46", "$@47", "$@48", "$@49", "ERRONOUS_EXPRESSION",
  "COMPARISONSTT", "ERRONOUS_COMPARISONSTT", "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-226)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-154)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -226,   188,  -226,   717,  -226,  -226,  -226,  -226,   -23,   -25,
      13,  -226,  -226,   149,  -226,  -226,    21,    73,    57,    81,
     512,  -226,   295,  -226,  -226,   149,  -226,   -10,  -226,    64,
    -226,  -226,  -226,    41,  -226,  -226,  -226,    45,  -226,  -226,
    -226,  -226,  -226,  -226,    94,  -226,  -226,  -226,   980,  -226,
    -226,  -226,   149,   426,   437,  -226,   149,   149,    75,   149,
     149,   149,   149,   149,    90,  -226,  -226,    68,  -226,   149,
     399,    76,   149,  1106,   357,   319,    86,     8,    83,   -30,
     149,  -226,    29,    10,   159,    74,  -226,    71,    85,  -226,
     796,  -226,    18,  -226,  -226,    35,   109,    41,  -226,  1001,
    -226,   464,   475,  -226,   116,   118,  -226,  -226,   538,   549,
     575,   586,    80,   149,    80,   149,   124,   267,   131,  -226,
     159,   159,   159,   270,   270,  -226,    95,    41,  1064,   399,
     399,   399,  1064,    74,   129,   103,  -226,    15,   114,    62,
      82,   113,  -226,  -226,  1064,   112,   122,    38,  -226,   149,
     127,  -226,  -226,   236,  -226,     5,   141,   126,     5,    23,
     128,  -226,    65,  -226,  -226,   149,    10,   612,    80,   154,
     623,   124,  -226,   149,  -226,   149,   149,   659,   159,   659,
     159,   328,   270,   328,   270,    80,    80,    23,   140,  -226,
     399,   399,  -226,   160,   139,   192,   164,  -226,   149,   149,
     169,   120,   168,   173,   114,  -226,   178,   176,   181,  -226,
      54,  1022,   203,   501,  -226,   149,   649,  -226,  -226,  -226,
      23,   187,  -226,    23,   185,   191,  -226,   189,  -226,   194,
    -226,    80,    10,    80,   154,    80,   267,   131,   159,   195,
    -226,   199,   399,   399,    41,   149,   186,   149,   149,   957,
     819,  -226,   206,  -226,  -226,   211,  -226,   215,  -226,   213,
      54,   221,    54,    54,   149,   149,   225,  -226,  -226,  -226,
     674,  -226,   842,  1043,  1085,   745,   220,  -226,  -226,  -226,
    -226,    23,  -226,  -226,    41,  -226,   227,  -226,  -226,   865,
     149,   888,   911,  -226,  -226,  -226,   222,   229,  -226,  -226,
     237,    54,   238,   252,  1064,   695,  -226,   501,   254,   249,
    -226,  -226,  -226,   256,   260,   782,  -226,    41,  -226,    41,
    -226,    41,  -226,   399,  -226,   934,  -226,  -226,   265,  -226,
     264,  -226,  -226,   266,    70,  -226,  -226,   501,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,    41,  -226,  -226,  -226,    41,
     276,  -226,   289,  -226,  -226,    41,  -226,    54,  -226,  -226,
    -226,  -226,    54,    54,  -226,    41,  -226,  -226,  -226
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    20,    21,    22,    23,     0,   101,
       0,   112,   156,     0,   157,   158,     0,     0,    42,     0,
       0,   154,     0,   155,   141,     0,     2,     0,     4,     0,
      12,    45,     5,     0,    13,    83,    14,   107,     8,     9,
      11,   116,    10,   131,     0,     6,    15,   171,     0,   173,
     170,   187,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,   109,     0,
       0,   126,     0,     0,     0,   159,   117,     0,     0,     0,
       0,    53,     0,   196,   186,   139,   136,     0,     0,     3,
       0,    26,    74,    16,    61,     0,   104,     0,   137,     0,
     166,     0,     0,     7,   162,     0,   164,   168,     0,     0,
       0,     0,   176,     0,   188,     0,   190,   174,   175,    29,
     177,   192,   194,   197,   199,    28,    65,     0,   102,     0,
       0,     0,   113,     0,     0,     0,   121,     0,     0,    86,
       0,     0,    84,    85,    43,     0,    55,     0,   147,     0,
       0,   100,   144,     0,   172,     0,     0,    62,     0,     0,
       0,   103,     0,   108,   138,     0,   189,     0,   178,   191,
       0,   179,   160,     0,   161,     0,     0,   193,   182,   195,
     183,   198,   184,   200,   185,   203,   201,     0,     0,   110,
       0,     0,   127,     0,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,    59,
       0,     0,     0,     0,   142,     0,     0,    34,    27,    30,
       0,     0,    25,     0,     0,     0,    78,    77,   111,     0,
     105,   167,   204,   181,   202,   180,   163,   165,   169,     0,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,    95,    94,    89,    93,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,    47,   140,    99,
       0,   145,   148,     0,     0,    39,     0,    69,    79,    80,
      75,     0,   106,    66,     0,   132,     0,   128,   114,     0,
       0,     0,     0,   125,   115,    92,     0,    86,    87,    82,
       0,     0,     0,     0,    49,     0,    44,     0,     0,     0,
      32,    33,    31,     0,     0,     0,    63,     0,    76,     0,
      73,     0,   134,     0,   118,     0,   122,   120,     0,    54,
       0,    58,    60,     0,     0,   150,   146,     0,    36,    38,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    40,     0,    70,    67,   133,     0,
       0,   124,     0,    90,    56,     0,    51,     0,   149,    64,
     135,   129,     0,     0,    46,     0,    50,    52,   130
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -226,   230,   -68,  -156,  -226,  -226,  -226,   158,  -226,  -226,
    -226,  -226,  -226,  -226,  -225,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -177,  -226,  -226,  -226,  -226,  -134,
      63,  -226,    -7,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,   -16,  -226,  -226,  -226,  -226,  -226,  -219,  -226,
     -12,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    26,    27,    28,   158,   155,   218,   313,   314,
     315,    29,    80,    30,   266,   267,   333,   373,    31,   145,
     207,   208,   263,    32,   220,   355,   187,   319,   221,   317,
     188,   284,    33,   159,   225,   226,   227,    34,   204,   141,
     142,   202,   143,   296,    35,    36,    37,    69,    96,    38,
      97,   127,    39,    72,   193,    40,    41,   134,   248,   196,
     135,    42,   131,   243,   323,   375,    43,   321,   359,    44,
      45,   149,    46,    89,    47,    88,   213,   308,   271,   309,
      48,   173,   175,   165,   176,    49,    50,    51,   354
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    75,   129,   224,   200,   139,   215,   140,    84,   136,
     239,    91,    67,    90,    70,    68,   197,    94,   137,   -24,
     216,   217,    76,    53,    54,    92,     4,     5,     6,     7,
     146,   224,    99,   -24,   -24,   300,   160,   302,   303,   209,
     112,   114,   116,   276,   117,   118,   278,   120,   121,   122,
     123,   124,   198,   156,    71,   264,   199,   128,    24,   157,
     132,   190,   191,   192,   224,   223,   229,   224,   144,   147,
     259,   366,    24,   -41,    78,   210,   330,   201,    24,   161,
      93,   163,    81,   203,   265,    95,   150,   151,   335,   168,
     171,   119,   -48,   101,   102,    73,   178,   180,   182,   184,
     -88,   185,    24,   186,   318,    12,   125,    24,    79,   126,
      98,   189,    13,   148,    14,    15,    82,   -81,   368,   130,
     138,   252,   241,   242,  -123,   224,   152,    20,    21,    74,
      23,   253,   162,   172,   -71,    25,   174,   211,   102,   194,
     254,   195,   374,   100,   101,   102,   230,   376,   377,   139,
      73,   205,   206,   231,   255,   233,   256,   219,   235,   -57,
      12,   236,   212,   237,   238,   -68,   228,    13,    54,    14,
      15,   100,   101,   102,   286,   287,   104,   105,   106,   240,
     245,   107,    20,    21,    74,    23,   249,   250,     2,     3,
      25,     4,     5,     6,     7,     8,     9,    10,    11,    12,
     244,   272,   246,   273,   275,   247,    13,   251,    14,    15,
     257,   258,    16,    17,    18,   260,   261,    19,   262,   269,
     279,    20,    21,    22,    23,    24,   277,   290,   288,    25,
     280,   281,   282,   289,   283,   291,   292,     3,   285,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   295,   -91,
     297,   299,   304,   305,    13,   360,    14,    15,   301,   316,
      16,    17,    18,   306,   328,    19,   322,   -88,   320,    20,
      21,    22,    23,    24,   214,   329,   331,    25,   325,   100,
     101,   102,   100,   101,   102,   105,   106,   104,   105,   106,
     332,   337,   107,   336,   338,   272,    85,   108,   109,   339,
     362,   356,   364,   357,   201,   358,   365,  -153,  -153,  -153,
      86,  -153,  -153,  -153,  -153,   371,   222,  -153,   367,   153,
     298,   363,  -153,  -153,     0,   272,  -153,  -153,     0,     0,
      87,   100,   101,   102,     0,     0,  -143,     0,   106,   369,
      52,    53,    54,   370,     0,    56,     0,    57,     0,   372,
      59,     0,     0,     0,     0,    60,    61,     0,   133,   378,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,     0,  -153,
    -153,  -153,     0,  -153,  -153,  -153,  -153,     0,  -153,  -153,
    -153,  -153,  -153,     0,  -153,  -153,  -153,  -153,  -153,  -153,
       0,     0,     0,     0,  -153,  -153,  -153,  -153,  -143,  -153,
       3,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,    13,     0,    14,
      15,     0,     0,    16,    17,    18,     0,    73,    19,     0,
       0,     0,    20,    21,    22,    23,    24,    12,    73,     0,
      25,   113,     0,     0,    13,     0,    14,    15,    12,     0,
       0,     0,   115,     0,     0,    13,     0,    14,    15,    20,
      21,    74,    23,     0,     0,   166,     0,    25,     0,     0,
      20,    21,    74,    23,     0,    12,   169,     0,    25,   167,
       0,     0,    13,     0,    14,    15,    12,     0,     0,     0,
     170,     0,     0,    13,     0,    14,    15,    20,    21,    74,
      23,     0,   270,     0,     0,    25,     0,     0,    20,    21,
      74,    23,    12,    83,     0,     0,    25,     0,     0,    13,
       0,    14,    15,    12,     0,     0,     0,     0,     0,     0,
      13,     0,    14,    15,    20,    21,    74,    23,     0,   177,
    -152,     0,    25,     0,     0,    20,    21,    74,    23,    12,
     179,     0,     0,    25,     0,     0,    13,     0,    14,    15,
      12,     0,     0,     0,     0,     0,     0,    13,     0,    14,
      15,    20,    21,    74,    23,     0,   181,     0,     0,    25,
       0,     0,    20,    21,    74,    23,    12,   183,     0,     0,
      25,     0,     0,    13,     0,    14,    15,    12,     0,     0,
       0,     0,     0,     0,    13,     0,    14,    15,    20,    21,
      74,    23,     0,   232,     0,     0,    25,     0,     0,    20,
      21,    74,    23,    12,   234,     0,     0,    25,     0,     0,
      13,     0,    14,    15,    12,     0,     0,     0,     0,     0,
       0,    13,     0,    14,    15,    20,    21,    74,    23,     0,
     274,     0,     0,    25,     0,     0,    20,    21,    74,    23,
      12,     0,     0,     0,    25,     0,     0,    13,     0,    14,
      15,    52,    53,    54,     0,     0,    56,     0,    57,     0,
       0,    59,    20,    21,    74,    23,    52,    53,    54,     0,
      25,    56,     0,    57,     0,     0,    59,     0,     0,     0,
       0,    60,    61,     0,     0,    62,    63,   100,   101,   102,
       0,     0,   104,   105,   106,     0,   307,   107,     0,     0,
       0,     0,   108,   109,     0,     0,   110,   111,     0,    52,
      53,    54,     0,    55,    56,   334,    57,     0,    58,    59,
       0,     0,     0,     0,    60,    61,     0,     0,    62,    63,
       0,     0,    64,     0,     0,    65,    66,   100,   101,   102,
       0,   312,   104,   105,   106,     0,     0,   107,     0,     0,
       0,     0,   108,   109,     0,     0,   110,   111,     0,     0,
       0,     0,     0,   -35,   -37,   340,   341,   342,   343,   344,
     345,   346,   347,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   348,     0,   349,   350,   351,   100,   101,
     102,   352,   353,   104,   105,   106,     0,     0,   107,     0,
       0,     0,     0,   108,   109,     0,     0,   110,   111,     0,
       0,   100,   101,   102,     0,   154,   104,   105,   106,     0,
       0,   107,     0,     0,     0,     0,   108,   109,     0,     0,
     110,   111,     0,     0,   100,   101,   102,     0,   294,   104,
     105,   106,     0,     0,   107,     0,     0,     0,     0,   108,
     109,     0,     0,   110,   111,     0,     0,   100,   101,   102,
       0,  -151,   104,   105,   106,     0,     0,   107,     0,     0,
       0,     0,   108,   109,     0,     0,   110,   111,     0,     0,
     100,   101,   102,     0,   324,   104,   105,   106,     0,     0,
     107,     0,     0,     0,     0,   108,   109,     0,     0,   110,
     111,     0,     0,   100,   101,   102,     0,   326,   104,   105,
     106,     0,     0,   107,     0,     0,     0,     0,   108,   109,
       0,     0,   110,   111,     0,     0,   100,   101,   102,     0,
     327,   104,   105,   106,     0,     0,   107,     0,     0,     0,
       0,   108,   109,     0,     0,   110,   111,     0,     0,   100,
     101,   102,     0,   361,   104,   105,   106,     0,     0,   107,
       0,     0,     0,     0,   108,   109,     0,     0,   110,   111,
       0,     0,   100,   101,   102,   293,   103,   104,   105,   106,
       0,     0,   107,     0,     0,     0,     0,   108,   109,     0,
       0,   110,   111,   100,   101,   102,     0,   164,   104,   105,
     106,     0,     0,   107,     0,     0,     0,     0,   108,   109,
       0,     0,   110,   111,   100,   101,   102,     0,   268,   104,
     105,   106,     0,     0,   107,     0,     0,     0,     0,   108,
     109,     0,     0,   110,   111,   100,   101,   102,     0,   310,
     104,   105,   106,     0,     0,   107,     0,     0,     0,     0,
     108,   109,     0,     0,   110,   111,   100,   101,   102,     0,
       0,   104,   105,   106,     0,     0,   107,     0,     0,     0,
       0,   108,   109,     0,     0,   110,   111,    52,    53,    54,
       0,   311,    56,     0,    57,     0,     0,    59,     0,     0,
       0,     0,    60,    61,     0,     0,    62,    63,    52,    53,
      54,     0,     0,    56,     0,    57,     0,     0,    59,     0,
       0,     0,     0,    60,    61,     0,     0,    62,    63
};

static const yytype_int16 yycheck[] =
{
      16,    13,    70,   159,   138,    35,     1,    37,    20,     1,
     187,    21,    35,    25,     1,    40,     1,    33,    10,     1,
      15,    16,     1,    13,    14,    35,     3,     4,     5,     6,
       1,   187,    44,    15,    16,   260,     1,   262,   263,     1,
      52,    53,    54,   220,    56,    57,   223,    59,    60,    61,
      62,    63,    37,    35,    41,     1,    41,    69,    37,    41,
      72,   129,   130,   131,   220,    42,     1,   223,    80,    40,
     204,     1,    37,    16,     1,    37,   301,    15,    37,    95,
      16,    97,     1,     1,    30,    40,    15,    16,   307,   101,
     102,    16,    38,    13,    14,     1,   108,   109,   110,   111,
      38,   113,    37,   115,   281,    11,    16,    37,    35,    41,
      16,   127,    18,    39,    20,    21,    35,    35,   337,    43,
      37,     1,   190,   191,    38,   281,    41,    33,    34,    35,
      36,    11,    23,    17,    39,    41,    18,   149,    14,    10,
      20,    38,   367,    12,    13,    14,   162,   372,   373,    35,
       1,    38,    40,   165,    34,   167,    36,    16,   170,    37,
      11,   173,    35,   175,   176,    39,    38,    18,    14,    20,
      21,    12,    13,    14,   242,   243,    17,    18,    19,    39,
      41,    22,    33,    34,    35,    36,   198,   199,     0,     1,
      41,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      40,   213,    10,   215,   216,    41,    18,    38,    20,    21,
      42,    38,    24,    25,    26,    37,    40,    29,    37,    16,
      35,    33,    34,    35,    36,    37,    39,    41,   244,    41,
      39,    42,    38,   245,    39,   247,   248,     1,    39,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    42,    38,
      35,    38,   264,   265,    18,   323,    20,    21,    37,    39,
      24,    25,    26,    38,    42,    29,    39,    38,   284,    33,
      34,    35,    36,    37,    38,    38,    38,    41,   290,    12,
      13,    14,    12,    13,    14,    18,    19,    17,    18,    19,
      38,    42,    22,    39,    38,   307,     1,    27,    28,    39,
      35,   317,    38,   319,    15,   321,    40,    12,    13,    14,
      15,    16,    17,    18,    19,    39,   158,    22,   334,    89,
     257,   328,    27,    28,    -1,   337,    31,    32,    -1,    -1,
      35,    12,    13,    14,    -1,    -1,    41,    -1,    19,   355,
      12,    13,    14,   359,    -1,    17,    -1,    19,    -1,   365,
      22,    -1,    -1,    -1,    -1,    27,    28,    -1,     1,   375,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,
      21,    -1,    -1,    24,    25,    26,    -1,     1,    29,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    11,     1,    -1,
      41,    15,    -1,    -1,    18,    -1,    20,    21,    11,    -1,
      -1,    -1,    15,    -1,    -1,    18,    -1,    20,    21,    33,
      34,    35,    36,    -1,    -1,     1,    -1,    41,    -1,    -1,
      33,    34,    35,    36,    -1,    11,     1,    -1,    41,    15,
      -1,    -1,    18,    -1,    20,    21,    11,    -1,    -1,    -1,
      15,    -1,    -1,    18,    -1,    20,    21,    33,    34,    35,
      36,    -1,     1,    -1,    -1,    41,    -1,    -1,    33,    34,
      35,    36,    11,     1,    -1,    -1,    41,    -1,    -1,    18,
      -1,    20,    21,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,    33,    34,    35,    36,    -1,     1,
      39,    -1,    41,    -1,    -1,    33,    34,    35,    36,    11,
       1,    -1,    -1,    41,    -1,    -1,    18,    -1,    20,    21,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,
      21,    33,    34,    35,    36,    -1,     1,    -1,    -1,    41,
      -1,    -1,    33,    34,    35,    36,    11,     1,    -1,    -1,
      41,    -1,    -1,    18,    -1,    20,    21,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    33,    34,
      35,    36,    -1,     1,    -1,    -1,    41,    -1,    -1,    33,
      34,    35,    36,    11,     1,    -1,    -1,    41,    -1,    -1,
      18,    -1,    20,    21,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    20,    21,    33,    34,    35,    36,    -1,
       1,    -1,    -1,    41,    -1,    -1,    33,    34,    35,    36,
      11,    -1,    -1,    -1,    41,    -1,    -1,    18,    -1,    20,
      21,    12,    13,    14,    -1,    -1,    17,    -1,    19,    -1,
      -1,    22,    33,    34,    35,    36,    12,    13,    14,    -1,
      41,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    31,    32,    12,    13,    14,
      -1,    -1,    17,    18,    19,    -1,    42,    22,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    31,    32,    -1,    12,
      13,    14,    -1,    16,    17,    40,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,    32,
      -1,    -1,    35,    -1,    -1,    38,    39,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    38,    39,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    23,    24,    25,    12,    13,
      14,    29,    30,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    32,    -1,
      -1,    12,    13,    14,    -1,    39,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,
      31,    32,    -1,    -1,    12,    13,    14,    -1,    39,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    31,    32,    -1,    -1,    12,    13,    14,
      -1,    39,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    31,    32,    -1,    -1,
      12,    13,    14,    -1,    39,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      32,    -1,    -1,    12,    13,    14,    -1,    39,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    31,    32,    -1,    -1,    12,    13,    14,    -1,
      39,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    31,    32,    -1,    -1,    12,
      13,    14,    -1,    39,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,    32,
      -1,    -1,    12,    13,    14,    38,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    32,    12,    13,    14,    -1,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    31,    32,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    31,    32,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    31,    32,    12,    13,    14,    -1,
      -1,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    31,    32,    12,    13,    14,
      -1,    16,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    31,    32,    12,    13,
      14,    -1,    -1,    17,    -1,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    18,    20,    21,    24,    25,    26,    29,
      33,    34,    35,    36,    37,    41,    46,    47,    48,    55,
      57,    62,    67,    76,    81,    88,    89,    90,    93,    96,
      99,   100,   105,   110,   113,   114,   116,   118,   124,   129,
     130,   131,    12,    13,    14,    16,    17,    19,    21,    22,
      27,    28,    31,    32,    35,    38,    39,    35,    40,    91,
       1,    41,    97,     1,    35,   124,     1,   116,     1,    35,
      56,     1,    35,     1,   124,     1,    15,    35,   119,   117,
     124,    21,    35,    16,   116,    40,    92,    94,    16,   124,
      12,    13,    14,    16,    17,    18,    19,    22,    27,    28,
      31,    32,   124,    15,   124,    15,   124,   124,   124,    16,
     124,   124,   124,   124,   124,    16,    41,    95,   124,    46,
      43,   106,   124,     1,   101,   104,     1,    10,    37,    35,
      37,    83,    84,    86,   124,    63,     1,    40,    39,   115,
      15,    16,    41,    45,    39,    50,    35,    41,    49,    77,
       1,   116,    23,   116,    16,   127,     1,    15,   124,     1,
      15,   124,    17,   125,    18,   126,   128,     1,   124,     1,
     124,     1,   124,     1,   124,   124,   124,    70,    74,   116,
      46,    46,    46,    98,    10,    38,   103,     1,    37,    41,
      83,    15,    85,     1,    82,    38,    40,    64,    65,     1,
      37,   124,    35,   120,    38,     1,    15,    16,    51,    16,
      68,    72,    51,    42,    47,    78,    79,    80,    38,     1,
     116,   124,     1,   124,     1,   124,   124,   124,   124,    78,
      39,    46,    46,   107,    40,    41,    10,    41,   102,   124,
     124,    38,     1,    11,    20,    34,    36,    42,    38,    83,
      37,    40,    37,    66,     1,    30,    58,    59,    16,    16,
       1,   122,   124,   124,     1,   124,    78,    39,    78,    35,
      39,    42,    38,    39,    75,    39,    46,    46,   116,   124,
      41,   124,   124,    38,    39,    42,    87,    35,    84,    38,
      58,    37,    58,    58,   124,   124,    38,    42,   121,   123,
      16,    16,    16,    52,    53,    54,    39,    73,    78,    71,
     116,   111,    39,   108,    39,   124,    39,    39,    42,    38,
      58,    38,    38,    60,    40,   122,    39,    42,    38,    39,
       3,     4,     5,     6,     7,     8,     9,    10,    21,    23,
      24,    25,    29,    30,   132,    69,   116,   116,   116,   112,
      46,    39,    35,    86,    38,    40,     1,   116,   122,   116,
     116,    39,   116,    61,    58,   109,    58,    58,   116
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    49,    48,    50,    48,    48,    48,
      48,    51,    51,    51,    51,    52,    51,    53,    51,    54,
      51,    55,    56,    55,    57,    57,    58,    58,    58,    60,
      59,    61,    59,    63,    62,    64,    62,    65,    62,    66,
      62,    67,    68,    69,    67,    70,    71,    67,    72,    73,
      67,    74,    75,    67,    77,    76,    78,    78,    78,    79,
      80,    82,    81,    81,    83,    83,    85,    84,    84,    87,
      86,    86,    86,    86,    86,    86,    88,    88,    88,    89,
      89,    91,    90,    92,    93,    93,    93,    94,    93,    95,
      93,    93,    97,    98,    96,    99,    99,   101,   100,   102,
     100,   103,   100,   104,   100,   100,   106,   107,   108,   109,
     105,   105,   111,   110,   112,   110,   113,   114,   114,   115,
     114,   117,   116,   119,   120,   121,   118,   118,   123,   122,
     122,   122,   122,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   124,   126,   124,   127,   124,   128,   124,
     124,   124,   124,   124,   129,   129,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     0,     4,     0,     4,     3,     3,
       4,     3,     3,     3,     1,     0,     4,     0,     4,     0,
       4,     1,     0,     3,     6,     1,     5,     1,     0,     0,
       6,     0,     6,     0,     7,     0,     8,     0,     7,     0,
       7,     2,     0,     0,     8,     0,     0,     8,     0,     0,
       7,     0,     0,     7,     0,     5,     3,     1,     1,     2,
       2,     0,     6,     1,     1,     1,     0,     4,     1,     0,
       6,     3,     4,     3,     3,     3,     5,     4,     5,     5,
       3,     0,     3,     2,     2,     4,     5,     0,     3,     0,
       4,     4,     0,     0,     6,     6,     1,     0,     7,     0,
       7,     0,     7,     0,     8,     6,     0,     0,     0,     0,
      11,     1,     0,     8,     0,     9,     2,     2,     3,     0,
       5,     0,     4,     0,     0,     0,     7,     3,     0,     4,
       3,     1,     0,     1,     1,     1,     1,     1,     1,     2,
       3,     3,     0,     4,     0,     4,     0,     4,     0,     4,
       1,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       4,     4,     3,     3,     3,     3,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 182 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1749 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 188 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1755 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 191 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1761 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 192 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1767 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 193 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1773 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 194 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1779 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 195 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1785 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 196 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1791 "parser.tab.c"
    break;

  case 14: /* STATEMENT: ENUM_CALL_STT  */
#line 197 "parser.y"
                                                            {printf("#[Parsed_Enum_USAGE]# ");}
#line 1797 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error SEMICOLON  */
#line 200 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1803 "parser.tab.c"
    break;

  case 18: /* STATEMENT: error '}'  */
#line 201 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1809 "parser.tab.c"
    break;

  case 19: /* STATEMENT: error ')'  */
#line 202 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1815 "parser.tab.c"
    break;

  case 20: /* TYPE: INT  */
#line 210 "parser.y"
                            { (yyval.str) = "int";   }
#line 1821 "parser.tab.c"
    break;

  case 21: /* TYPE: FLOAT  */
#line 211 "parser.y"
                            { (yyval.str) = "float"; }
#line 1827 "parser.tab.c"
    break;

  case 22: /* TYPE: BOOL  */
#line 212 "parser.y"
                            { (yyval.str) = "bool";  }
#line 1833 "parser.tab.c"
    break;

  case 23: /* TYPE: STRING  */
#line 213 "parser.y"
                            { (yyval.str) = "string";}
#line 1839 "parser.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 217 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0);   assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1845 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 217 "parser.y"
                                                                                                                                                         {printf("#[Parsed_Declaration]# "); }
#line 1851 "parser.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 218 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0); assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1857 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 218 "parser.y"
                                                                                                                                                         {printf("#[Parsed_CONST_Declaration]# "); }
#line 1863 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 219 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1869 "parser.tab.c"
    break;

  case 29: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 220 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1875 "parser.tab.c"
    break;

  case 30: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 221 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);}
#line 1881 "parser.tab.c"
    break;

  case 31: /* DECLARATION_TAIL: EQ EXPRESSION SEMICOLON  */
#line 226 "parser.y"
                                                                                            {StAssPush(strdup(IdentifierHolder)); StAssPrint("OVER", 1); StAssPrint("STORE", 1); StAssPrint("DROP", 1);}
#line 1887 "parser.tab.c"
    break;

  case 32: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 227 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1893 "parser.tab.c"
    break;

  case 33: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 228 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1899 "parser.tab.c"
    break;

  case 35: /* $@3: %empty  */
#line 230 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1905 "parser.tab.c"
    break;

  case 37: /* $@4: %empty  */
#line 231 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1911 "parser.tab.c"
    break;

  case 39: /* $@5: %empty  */
#line 232 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1917 "parser.tab.c"
    break;

  case 41: /* RETURN_STT: RETURN  */
#line 239 "parser.y"
                                                {int dum = 0;StAssPrint("POP\tPC",1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1923 "parser.tab.c"
    break;

  case 42: /* $@6: %empty  */
#line 240 "parser.y"
                         {assign_index =func_index;}
#line 1929 "parser.tab.c"
    break;

  case 43: /* RETURN_STT: RETURN $@6 EXPRESSION  */
#line 240 "parser.y"
                                                                            { StAssPrint("OVER",1);int dum = 0;StAssPrint("POP\tPC",1);StAssPrint("DNEXT", 1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1935 "parser.tab.c"
    break;

  case 49: /* $@7: %empty  */
#line 256 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);}
#line 1941 "parser.tab.c"
    break;

  case 51: /* $@8: %empty  */
#line 257 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);}
#line 1947 "parser.tab.c"
    break;

  case 53: /* $@9: %empty  */
#line 261 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1953 "parser.tab.c"
    break;

  case 55: /* $@10: %empty  */
#line 262 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }
#line 1959 "parser.tab.c"
    break;

  case 57: /* $@11: %empty  */
#line 263 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1965 "parser.tab.c"
    break;

  case 59: /* $@12: %empty  */
#line 264 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1971 "parser.tab.c"
    break;

  case 62: /* $@13: %empty  */
#line 278 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 1977 "parser.tab.c"
    break;

  case 63: /* $@14: %empty  */
#line 278 "parser.y"
                                                                                                                    {func_index = st_insert((yyvsp[-5].str), (yyvsp[-4].str),"func",0); popArgs();}
#line 1983 "parser.tab.c"
    break;

  case 65: /* $@15: %empty  */
#line 279 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 1989 "parser.tab.c"
    break;

  case 66: /* $@16: %empty  */
#line 279 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-4].str),"func",0); popArgs();}
#line 1995 "parser.tab.c"
    break;

  case 68: /* $@17: %empty  */
#line 280 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2001 "parser.tab.c"
    break;

  case 69: /* $@18: %empty  */
#line 280 "parser.y"
                                                                                                                    {func_index=st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2007 "parser.tab.c"
    break;

  case 71: /* $@19: %empty  */
#line 281 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2013 "parser.tab.c"
    break;

  case 72: /* $@20: %empty  */
#line 281 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-3].str),"func",0);}
#line 2019 "parser.tab.c"
    break;

  case 74: /* $@21: %empty  */
#line 286 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 2025 "parser.tab.c"
    break;

  case 75: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@21 ARGS ')'  */
#line 286 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2031 "parser.tab.c"
    break;

  case 79: /* ERRONOUS_ARGS: ',' ARGS  */
#line 301 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
#line 2037 "parser.tab.c"
    break;

  case 80: /* ARG_DECL: TYPE IDENTIFIER  */
#line 304 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1); char* buf=(yyvsp[0].str); argumentList[argPointer]=buf;argPointer++;}
#line 2043 "parser.tab.c"
    break;

  case 81: /* $@22: %empty  */
#line 311 "parser.y"
                                      { is_enum =1;}
#line 2049 "parser.tab.c"
    break;

  case 82: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' $@22 ENUM_HELPER '}'  */
#line 311 "parser.y"
                                                                              { st_insert("enum" , (yyvsp[-4].str), "var" , 0); is_enum=0;}
#line 2055 "parser.tab.c"
    break;

  case 86: /* $@23: %empty  */
#line 317 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++;  st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int(  enum_arg_count-1,st_index-1); }
#line 2061 "parser.tab.c"
    break;

  case 88: /* ENUM_ARGS: IDENTIFIER  */
#line 318 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++; st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int( enum_arg_count-1,st_index-1);  }
#line 2067 "parser.tab.c"
    break;

  case 89: /* $@24: %empty  */
#line 324 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++ ; st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2073 "parser.tab.c"
    break;

  case 91: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ DIGIT  */
#line 325 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++;  st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2079 "parser.tab.c"
    break;

  case 92: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ error ','  */
#line 326 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2085 "parser.tab.c"
    break;

  case 93: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ FLOAT_DIGIT  */
#line 327 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2091 "parser.tab.c"
    break;

  case 94: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ STRING_LITERAL  */
#line 328 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2097 "parser.tab.c"
    break;

  case 95: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ BOOL_LITERAL  */
#line 329 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2103 "parser.tab.c"
    break;

  case 96: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 333 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);}
#line 2109 "parser.tab.c"
    break;

  case 97: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 334 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);}
#line 2115 "parser.tab.c"
    break;

  case 98: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 336 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2121 "parser.tab.c"
    break;

  case 99: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER EQ IDENTIFIER SEMICOLON  */
#line 339 "parser.y"
                                                               { StAssPush((yyvsp[-3].str));StAssPush((yyvsp[-1].str));StAssPrint("STORE",1); st_insert((yyvsp[-4].str) , (yyvsp[-3].str), "var_enum" , 0); assign_enum(st_index-1, (yyvsp[-4].str),(yyvsp[-1].str)); int i= lookup((yyvsp[-4].str)); symbolTable[i].isUsed=1; }
#line 2127 "parser.tab.c"
    break;

  case 100: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER SEMICOLON  */
#line 340 "parser.y"
                                                   { st_insert((yyvsp[-2].str) , (yyvsp[-1].str), "var_enum" , 0); int i= lookup((yyvsp[-2].str)); symbolTable[i].isUsed=1;}
#line 2133 "parser.tab.c"
    break;

  case 101: /* $@25: %empty  */
#line 344 "parser.y"
                   {printIF();}
#line 2139 "parser.tab.c"
    break;

  case 102: /* IF_STT_HELPER: IF $@25 EXPRESSION  */
#line 344 "parser.y"
                                           {StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2145 "parser.tab.c"
    break;

  case 103: /* IF_STT_HELPER1: ':' BLOCK  */
#line 347 "parser.y"
                                                            {controlTerminator(0);  StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2151 "parser.tab.c"
    break;

  case 104: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1  */
#line 351 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2157 "parser.tab.c"
    break;

  case 105: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE BLOCK  */
#line 352 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2163 "parser.tab.c"
    break;

  case 106: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE error '}'  */
#line 353 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);}
#line 2169 "parser.tab.c"
    break;

  case 107: /* $@26: %empty  */
#line 354 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 2175 "parser.tab.c"
    break;

  case 108: /* IF_STT: IF_STT_HELPER $@26 BLOCK  */
#line 354 "parser.y"
                                                                                                                                                                      {char*dummy; strcpy(dummy, makeEndLabel()); printLLVM(dummy); printLLVM(":\n");}
#line 2181 "parser.tab.c"
    break;

  case 109: /* $@27: %empty  */
#line 355 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);}
#line 2187 "parser.tab.c"
    break;

  case 110: /* IF_STT: IF ':' $@27 BLOCK  */
#line 355 "parser.y"
                                                                                                                                                                      {char*dummy; strcpy(dummy, makeEndLabel()); printLLVM(dummy); printLLVM(":\n");}
#line 2193 "parser.tab.c"
    break;

  case 111: /* IF_STT: IF_STT_HELPER ':' error '}'  */
#line 356 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);}
#line 2199 "parser.tab.c"
    break;

  case 112: /* $@28: %empty  */
#line 365 "parser.y"
                      {printWHILE(); StAssPrintLBL(1, 0);}
#line 2205 "parser.tab.c"
    break;

  case 113: /* $@29: %empty  */
#line 365 "parser.y"
                                                                      {StAssJmp("JNZ", "END",&SMLabel_End, 0,0);}
#line 2211 "parser.tab.c"
    break;

  case 114: /* WHILE_STT: WHILE $@28 EXPRESSION $@29 ':' BLOCK  */
#line 365 "parser.y"
                                                                                                                            {StAssJmp("JMP", "LBL",&SMLabel_Else, 1,0); StAssPrintLBL(0, 1);}
#line 2217 "parser.tab.c"
    break;

  case 117: /* $@30: %empty  */
#line 378 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2223 "parser.tab.c"
    break;

  case 119: /* $@31: %empty  */
#line 379 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2229 "parser.tab.c"
    break;

  case 121: /* $@32: %empty  */
#line 380 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);}
#line 2235 "parser.tab.c"
    break;

  case 123: /* $@33: %empty  */
#line 381 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);}
#line 2241 "parser.tab.c"
    break;

  case 125: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 382 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);}
#line 2247 "parser.tab.c"
    break;

  case 126: /* $@34: %empty  */
#line 389 "parser.y"
                        {in_loop = 1;}
#line 2253 "parser.tab.c"
    break;

  case 127: /* $@35: %empty  */
#line 389 "parser.y"
                                                 {StAssForHeader();}
#line 2259 "parser.tab.c"
    break;

  case 128: /* $@36: %empty  */
#line 389 "parser.y"
                                                                               {StAssForMiddle();}
#line 2265 "parser.tab.c"
    break;

  case 129: /* $@37: %empty  */
#line 389 "parser.y"
                                                                                                                {StAssPrintLBL(1,1); in_loop = 0;}
#line 2271 "parser.tab.c"
    break;

  case 130: /* FOR_STT: FOR '(' $@34 STATEMENT $@35 STATEMENT $@36 STATEMENT ')' $@37 BLOCK  */
#line 389 "parser.y"
                                                                                                                                                          {StAssJmp("JMP", "Label", &ForHeaderLabel,1,0); StAssPrintLBL(0,1);}
#line 2277 "parser.tab.c"
    break;

  case 132: /* $@38: %empty  */
#line 394 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);}
#line 2283 "parser.tab.c"
    break;

  case 134: /* $@39: %empty  */
#line 395 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);}
#line 2289 "parser.tab.c"
    break;

  case 136: /* helperAssignmentRule: IDENTIFIER EQ  */
#line 402 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); StAssPush((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str));}
#line 2295 "parser.tab.c"
    break;

  case 137: /* assignmentSTT: helperAssignmentRule SEMICOLON  */
#line 406 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);}
#line 2301 "parser.tab.c"
    break;

  case 138: /* assignmentSTT: helperAssignmentRule EXPRESSION SEMICOLON  */
#line 407 "parser.y"
                                                                 {StAssPrint("STORE", 1); CodeGenAss();printf("#[Parsed_Assignment]# ");}
#line 2307 "parser.tab.c"
    break;

  case 139: /* $@40: %empty  */
#line 408 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str)); StAssPush((yyvsp[-1].str));}
#line 2313 "parser.tab.c"
    break;

  case 140: /* assignmentSTT: IDENTIFIER error $@40 EXPRESSION SEMICOLON  */
#line 408 "parser.y"
                                                                                                                                                                                                 {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);}
#line 2319 "parser.tab.c"
    break;

  case 141: /* $@41: %empty  */
#line 413 "parser.y"
                    {scope_start();}
#line 2325 "parser.tab.c"
    break;

  case 142: /* BLOCK: '{' $@41 PROGRAM '}'  */
#line 413 "parser.y"
                                                                              {scope_end(); printf("#[Parsed_Block]# ");}
#line 2331 "parser.tab.c"
    break;

  case 143: /* $@42: %empty  */
#line 421 "parser.y"
                           {called_func_index = lookup((yyvsp[0].str)); check_type(called_func_index); StAssPush("PC");}
#line 2337 "parser.tab.c"
    break;

  case 144: /* $@43: %empty  */
#line 421 "parser.y"
                                                                                                                 { is_param =1;}
#line 2343 "parser.tab.c"
    break;

  case 145: /* $@44: %empty  */
#line 421 "parser.y"
                                                                                                                                            { is_param =0; arg_count_check(called_func_index); arg_count=0; int dum=0; StAssJmp("JMP", (yyvsp[-4].str),&dum, 0,0);}
#line 2349 "parser.tab.c"
    break;

  case 146: /* FUNC_CALL: IDENTIFIER $@42 '(' $@43 USED_ARGS $@44 ')'  */
#line 421 "parser.y"
                                                                                                                                                                                                                                                             { printf("#[Parsed_Func_Call]# ");}
#line 2355 "parser.tab.c"
    break;

  case 147: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 422 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 2361 "parser.tab.c"
    break;

  case 148: /* $@45: %empty  */
#line 426 "parser.y"
                           { arg_count++; }
#line 2367 "parser.tab.c"
    break;

  case 150: /* USED_ARGS: error ',' USED_ARGS  */
#line 427 "parser.y"
                                                            {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 2373 "parser.tab.c"
    break;

  case 151: /* USED_ARGS: EXPRESSION  */
#line 428 "parser.y"
                             {arg_count++ ;}
#line 2379 "parser.tab.c"
    break;

  case 153: /* EXPRESSION: IDENTIFIER  */
#line 435 "parser.y"
                                                { int i = lookup((yyvsp[0].str)); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2385 "parser.tab.c"
    break;

  case 154: /* EXPRESSION: DIGIT  */
#line 436 "parser.y"
                                                { assign_int((yyvsp[0].num), assign_index) ; char numtostring[40]; itoa((yyvsp[0].num), numtostring, 10); pushVStack(numtostring); char dum[10]="$"; StAssPush(strcat(dum,numtostring));}
#line 2391 "parser.tab.c"
    break;

  case 155: /* EXPRESSION: FLOAT_DIGIT  */
#line 437 "parser.y"
                                                { assign_float((yyvsp[0].float_val), assign_index); char floattostring[40]; gcvt((yyvsp[0].float_val), 6, floattostring); pushVStack(floattostring); char dum[10]="$"; StAssPush(strcat(dum,floattostring));}
#line 2397 "parser.tab.c"
    break;

  case 156: /* EXPRESSION: BOOL_LITERAL  */
#line 438 "parser.y"
                                                { assign_bool((yyvsp[0].bool_val), assign_index); if((yyvsp[0].bool_val)==true){pushVStack("true");StAssPush("$true");}else{pushVStack("false");StAssPush("$false");} }
#line 2403 "parser.tab.c"
    break;

  case 157: /* EXPRESSION: STRING_LITERAL  */
#line 439 "parser.y"
                                                { assign_str((yyvsp[0].str), assign_index); pushVStack((yyvsp[0].str));char* buf; strcpy(buf, "$");strcat(buf, (yyvsp[0].str)); StAssPush(buf);}
#line 2409 "parser.tab.c"
    break;

  case 158: /* EXPRESSION: CONSTANT  */
#line 440 "parser.y"
                                                { int i = lookup((yyvsp[0].str)); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2415 "parser.tab.c"
    break;

  case 159: /* EXPRESSION: SUB EXPRESSION  */
#line 441 "parser.y"
                                                {StAssPush("$-1"); StAssPrint("MUL");}
#line 2421 "parser.tab.c"
    break;

  case 160: /* EXPRESSION: EXPRESSION PLUS PLUS  */
#line 442 "parser.y"
                                                { pushVStack("+"); pushVStack("1"); CodeGenOp("ADD"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("ADD", 1); StAssPrint("STORE", 1);}
#line 2427 "parser.tab.c"
    break;

  case 161: /* EXPRESSION: EXPRESSION SUB SUB  */
#line 443 "parser.y"
                                                { pushVStack("-"); pushVStack("1"); CodeGenOp("SUB"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("SUB", 1); StAssPrint("STORE", 1);}
#line 2433 "parser.tab.c"
    break;

  case 162: /* $@46: %empty  */
#line 444 "parser.y"
                                                { pushVStack("+");}
#line 2439 "parser.tab.c"
    break;

  case 163: /* EXPRESSION: EXPRESSION PLUS $@46 EXPRESSION  */
#line 444 "parser.y"
                                                                                 {CodeGenOp("ADD"); StAssPrint("ADD", 1);}
#line 2445 "parser.tab.c"
    break;

  case 164: /* $@47: %empty  */
#line 446 "parser.y"
                                                { pushVStack("*");}
#line 2451 "parser.tab.c"
    break;

  case 165: /* EXPRESSION: EXPRESSION MUL $@47 EXPRESSION  */
#line 446 "parser.y"
                                                                                 {CodeGenOp("MUL"); StAssPrint("MUL", 1);}
#line 2457 "parser.tab.c"
    break;

  case 166: /* $@48: %empty  */
#line 447 "parser.y"
                                                { pushVStack("/");}
#line 2463 "parser.tab.c"
    break;

  case 167: /* EXPRESSION: EXPRESSION DIV $@48 EXPRESSION  */
#line 447 "parser.y"
                                                                                 {CodeGenOp("DIV"); StAssPrint("DIV", 1);}
#line 2469 "parser.tab.c"
    break;

  case 168: /* $@49: %empty  */
#line 450 "parser.y"
                                                {pushVStack("^");}
#line 2475 "parser.tab.c"
    break;

  case 169: /* EXPRESSION: EXPRESSION POW $@49 EXPRESSION  */
#line 450 "parser.y"
                                                                               {CodeGenOp("POW");}
#line 2481 "parser.tab.c"
    break;

  case 173: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 454 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);}
#line 2487 "parser.tab.c"
    break;

  case 178: /* COMPARISONSTT: EXPRESSION GT EXPRESSION  */
#line 474 "parser.y"
                                                        {pushVStack(">"); CodeGenLogical(); StAssPrint("GT", 1);}
#line 2493 "parser.tab.c"
    break;

  case 179: /* COMPARISONSTT: EXPRESSION LT EXPRESSION  */
#line 475 "parser.y"
                                                        {pushVStack("<"); CodeGenLogical(); StAssPrint("LT", 1);}
#line 2499 "parser.tab.c"
    break;

  case 180: /* COMPARISONSTT: EXPRESSION LT EQ EXPRESSION  */
#line 476 "parser.y"
                                                        {pushVStack("<="); CodeGenLogical(); StAssPrint("LE", 1);}
#line 2505 "parser.tab.c"
    break;

  case 181: /* COMPARISONSTT: EXPRESSION GT EQ EXPRESSION  */
#line 477 "parser.y"
                                                        {pushVStack(">="); CodeGenLogical(); StAssPrint("GE", 1);}
#line 2511 "parser.tab.c"
    break;

  case 182: /* COMPARISONSTT: EXPRESSION EQUALITY EXPRESSION  */
#line 478 "parser.y"
                                                        {pushVStack("="); CodeGenLogical(); StAssPrint("EQ", 1);}
#line 2517 "parser.tab.c"
    break;

  case 183: /* COMPARISONSTT: EXPRESSION NEG_EQUALITY EXPRESSION  */
#line 479 "parser.y"
                                                        {pushVStack("!="); CodeGenLogical(); StAssPrint("NE", 1);}
#line 2523 "parser.tab.c"
    break;

  case 184: /* COMPARISONSTT: EXPRESSION LOGIC_AND EXPRESSION  */
#line 480 "parser.y"
                                                        {pushVStack("and"); CodeGenLogical(); StAssPrint("AND", 1);}
#line 2529 "parser.tab.c"
    break;

  case 185: /* COMPARISONSTT: EXPRESSION LOGIC_OR EXPRESSION  */
#line 481 "parser.y"
                                                        {pushVStack("or"); CodeGenLogical(); StAssPrint("OR", 1);}
#line 2535 "parser.tab.c"
    break;

  case 188: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 487 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 2541 "parser.tab.c"
    break;

  case 189: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 488 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 2547 "parser.tab.c"
    break;

  case 190: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 489 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 2553 "parser.tab.c"
    break;

  case 191: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 490 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 2559 "parser.tab.c"
    break;

  case 192: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 491 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 2565 "parser.tab.c"
    break;

  case 193: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 492 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 2571 "parser.tab.c"
    break;

  case 194: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 493 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 2577 "parser.tab.c"
    break;

  case 195: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 494 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 2583 "parser.tab.c"
    break;

  case 196: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 495 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 2589 "parser.tab.c"
    break;

  case 197: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 496 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 2595 "parser.tab.c"
    break;

  case 198: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 497 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 2601 "parser.tab.c"
    break;

  case 199: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 498 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 2607 "parser.tab.c"
    break;

  case 200: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 499 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 2613 "parser.tab.c"
    break;

  case 201: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 500 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 2619 "parser.tab.c"
    break;

  case 202: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 501 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 2625 "parser.tab.c"
    break;

  case 203: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 502 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 2631 "parser.tab.c"
    break;

  case 204: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 503 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 2637 "parser.tab.c"
    break;


#line 2641 "parser.tab.c"

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

#line 522 "parser.y"




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
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope_index){
            return symbolTable[i].declareLine;
        }
    }
    return -1;
}
int lookup(char* name) {
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
            if ( i != assign_index)// 3shan lw kan el var 3la el LHS s3tha 3ady ex: int x=9; int z; z =x;
            {
                printf("\n !!!!!!!!!!!! Error at line %d: %s used before initialized !!!!!!!!!!!\n", line_number, name);}
            }
            symbolTable[i].isUsed=1;
            return i;
        }
    }
    printf("\n !!!!!!!!!!!! Error at line %d: %s undeclared identifier in this scope !!!!!!!!!!!\n", line_number, name);
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
    if ( symbolTable[i].dataType != "int" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned int !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
     return ;}
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "int" ) {symbolTable[i].intValue= d ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned int value!!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );}
    if(is_changed == 1) {st_log();} // 
}
void assign_float( float f, int i) {
     if ( symbolTable[i].dataType != "float" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned float !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
     return ;}
    if (i == -1) {return;}
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "float"){symbolTable[i].floatValue= f ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned float value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
   if(is_changed == 1) {st_log();}
}
void assign_str( char* s , int i) {
    if ( symbolTable[i].dataType != "string" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned string !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
     return ;} 
    if (i == -1) {return;}
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "string"){symbolTable[i].strValue= s ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned string value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
    if(is_changed == 1) {st_log();}
}
void assign_bool( bool b , int i) {
    if (i == -1) {return;}
    if ( symbolTable[i].dataType != "bool" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned boolean !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
     return ;} 
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "bool"){symbolTable[i].boolValue= b ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned bool value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
    if(is_changed == 1) {st_log();}
}

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
                        return;
                    }
                }
                printf("\n !!!!!!!!!!!! Error at line %d: %s not exist as key for %s enum  !!!!!!!!!!!\n", line_number, key ,enum_name );
                return;
            }
        }
    }
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned enum value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
}
// void check_param_type (int i) {

// }
void check_type( int i) {
    // this functio check type matching between 2 identifiers before assign the value
    if ( is_param == 1) 
    { assign_index = arg_count;}
     if ( i == -1) 
    { return;}
    if (i != -1 && symbolTable[i].dataType != symbolTable[assign_index].dataType)
    {   /// at calling a function
        if (strcmp(symbolTable[i].type,"func")== 0){ printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s return %s value  !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType );}
        else if (strcmp(symbolTable[assign_index].type,"func")== 0){ printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s return %s value  !!!!!!!!!!!\n", line_number,symbolTable[i].name,symbolTable[i].dataType, symbolTable[assign_index].name,symbolTable[assign_index].dataType );}
        else if (is_param == 1)
        {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Incorrect argument type %s is %s variable but %s %s !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType );}
        else {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s %s !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType );}
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
        if (strcmp(symbolTable[i].type,"func") == 0){printf("\n !!!!!!!!!!!! Function %s Declared at line %d but never called !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); }
        else if ( symbolTable[i].isArg == 1){printf("\n !!!!!!!!!!!! Unused Argument %s Declared in Function at line %d !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); }
        else {printf("\n !!!!!!!!!!!! Unused Identifier %s Declared at line %d !!!!!!!!!!!\n",symbolTable[i].name, symbolTable[i].declareLine); }
        }
    }
}
void arg_count_check( int i) {
    if ( arg_count > symbolTable[i].argCount )
    {printf("\n !!!!!!!!!!!! Error at line %d : too many arguments for function call expected %d got %d !!!!!!!!!!!\n", line_number, symbolTable[i].argCount, arg_count); }
    else if ( arg_count < symbolTable[i].argCount )
    {printf("\n !!!!!!!!!!!! Error at line %d : too few arguments for function call expected %d got %d !!!!!!!!!!!\n", line_number, symbolTable[i].argCount, arg_count); }
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
    if(noNum)
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

    if(ret != 0 && ret2 !=0){
        printf("\nCreating Intermediate Code File ...\n");
        printf("Creating Stack Machine Assembly File ...\n");
    }
    yyin = fopen(argv[1], "r");
    yyparse();
    st_print();
    unused_print();
    return 0;
}
