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
    char switcher[50];
//==================================================================================================================================================


#line 206 "parser.tab.c"

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
  YYSYMBOL_CASES = 60,                     /* CASES  */
  YYSYMBOL_61_7 = 61,                      /* $@7  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 64,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_66_11 = 66,                     /* $@11  */
  YYSYMBOL_67_12 = 67,                     /* $@12  */
  YYSYMBOL_68_13 = 68,                     /* $@13  */
  YYSYMBOL_FUNC_DECLARATION_STT = 69,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_70_14 = 70,                     /* $@14  */
  YYSYMBOL_71_15 = 71,                     /* $@15  */
  YYSYMBOL_72_16 = 72,                     /* $@16  */
  YYSYMBOL_73_17 = 73,                     /* $@17  */
  YYSYMBOL_74_18 = 74,                     /* $@18  */
  YYSYMBOL_75_19 = 75,                     /* $@19  */
  YYSYMBOL_76_20 = 76,                     /* $@20  */
  YYSYMBOL_77_21 = 77,                     /* $@21  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 78, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_79_22 = 79,                     /* $@22  */
  YYSYMBOL_ARGS = 80,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 81,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 82,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 83,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_84_23 = 84,                     /* $@23  */
  YYSYMBOL_ENUM_HELPER = 85,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 86,                 /* ENUM_ARGS  */
  YYSYMBOL_87_24 = 87,                     /* $@24  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 88,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_89_25 = 89,                     /* $@25  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 90, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_CALL_STT = 91,             /* ENUM_CALL_STT  */
  YYSYMBOL_IF_STT_HELPER = 92,             /* IF_STT_HELPER  */
  YYSYMBOL_93_26 = 93,                     /* $@26  */
  YYSYMBOL_IF_STT_HELPER1 = 94,            /* IF_STT_HELPER1  */
  YYSYMBOL_IF_STT = 95,                    /* IF_STT  */
  YYSYMBOL_96_27 = 96,                     /* $@27  */
  YYSYMBOL_97_28 = 97,                     /* $@28  */
  YYSYMBOL_WHILE_STT = 98,                 /* WHILE_STT  */
  YYSYMBOL_99_29 = 99,                     /* $@29  */
  YYSYMBOL_100_30 = 100,                   /* $@30  */
  YYSYMBOL_DO_WHILE_STT = 101,             /* DO_WHILE_STT  */
  YYSYMBOL_ERRONOUS_DO_WHILE = 102,        /* ERRONOUS_DO_WHILE  */
  YYSYMBOL_103_31 = 103,                   /* $@31  */
  YYSYMBOL_104_32 = 104,                   /* $@32  */
  YYSYMBOL_105_33 = 105,                   /* $@33  */
  YYSYMBOL_106_34 = 106,                   /* $@34  */
  YYSYMBOL_FOR_STT = 107,                  /* FOR_STT  */
  YYSYMBOL_108_35 = 108,                   /* $@35  */
  YYSYMBOL_109_36 = 109,                   /* $@36  */
  YYSYMBOL_110_37 = 110,                   /* $@37  */
  YYSYMBOL_111_38 = 111,                   /* $@38  */
  YYSYMBOL_ERRONOUS_FOR_LOOP = 112,        /* ERRONOUS_FOR_LOOP  */
  YYSYMBOL_113_39 = 113,                   /* $@39  */
  YYSYMBOL_114_40 = 114,                   /* $@40  */
  YYSYMBOL_helperAssignmentRule = 115,     /* helperAssignmentRule  */
  YYSYMBOL_assignmentSTT = 116,            /* assignmentSTT  */
  YYSYMBOL_117_41 = 117,                   /* $@41  */
  YYSYMBOL_BLOCK = 118,                    /* BLOCK  */
  YYSYMBOL_119_42 = 119,                   /* $@42  */
  YYSYMBOL_FUNC_CALL = 120,                /* FUNC_CALL  */
  YYSYMBOL_121_43 = 121,                   /* $@43  */
  YYSYMBOL_122_44 = 122,                   /* $@44  */
  YYSYMBOL_123_45 = 123,                   /* $@45  */
  YYSYMBOL_USED_ARGS = 124,                /* USED_ARGS  */
  YYSYMBOL_125_46 = 125,                   /* $@46  */
  YYSYMBOL_EXPRESSION = 126,               /* EXPRESSION  */
  YYSYMBOL_127_47 = 127,                   /* $@47  */
  YYSYMBOL_128_48 = 128,                   /* $@48  */
  YYSYMBOL_129_49 = 129,                   /* $@49  */
  YYSYMBOL_130_50 = 130,                   /* $@50  */
  YYSYMBOL_ERRONOUS_EXPRESSION = 131,      /* ERRONOUS_EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 132,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 133,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 134                  /* RES_WORD  */
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
#define YYLAST   1133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  377

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
       0,   184,   184,   185,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     212,   213,   214,   215,   219,   219,   220,   220,   221,   222,
     223,   228,   229,   230,   231,   232,   232,   233,   233,   234,
     234,   241,   242,   242,   244,   247,   248,   253,   253,   253,
     253,   254,   256,   265,   265,   266,   266,   267,   267,   268,
     268,   269,   281,   282,   282,   282,   283,   283,   283,   284,
     284,   284,   285,   285,   285,   290,   290,   300,   301,   302,
     305,   308,   315,   315,   316,   318,   318,   321,   321,   322,
     328,   328,   329,   330,   331,   332,   333,   337,   338,   340,
     343,   344,   348,   348,   351,   355,   356,   357,   358,   358,
     359,   359,   360,   369,   369,   369,   378,   379,   382,   382,
     383,   383,   384,   384,   385,   385,   386,   393,   393,   393,
     393,   393,   394,   398,   398,   399,   399,   406,   410,   411,
     412,   412,   417,   417,   425,   425,   425,   425,   426,   430,
     430,   431,   432,   433,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   448,   450,   450,   451,   451,   454,
     454,   455,   456,   457,   458,   467,   469,   470,   471,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   515,   515,   515,   515,
     515,   515,   515,   515,   515,   515,   515,   515,   515,   515
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
  "RETURN_STT", "$@6", "helperSWITCH", "SWITCH_STT", "CASES", "$@7", "$@8",
  "$@9", "ERRONOUS_SWITCH_STT", "$@10", "$@11", "$@12", "$@13",
  "FUNC_DECLARATION_STT", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19",
  "$@20", "$@21", "ERRONOUS_FUNC_DECLARATION_STT", "$@22", "ARGS",
  "ERRONOUS_ARGS", "ARG_DECL", "ENUM_DECLARATION_STT", "$@23",
  "ENUM_HELPER", "ENUM_ARGS", "$@24", "ENUM_DEFINED_ARGS", "$@25",
  "ERRONOUS_ENUM_DECLARATION_STT", "ENUM_CALL_STT", "IF_STT_HELPER",
  "$@26", "IF_STT_HELPER1", "IF_STT", "$@27", "$@28", "WHILE_STT", "$@29",
  "$@30", "DO_WHILE_STT", "ERRONOUS_DO_WHILE", "$@31", "$@32", "$@33",
  "$@34", "FOR_STT", "$@35", "$@36", "$@37", "$@38", "ERRONOUS_FOR_LOOP",
  "$@39", "$@40", "helperAssignmentRule", "assignmentSTT", "$@41", "BLOCK",
  "$@42", "FUNC_CALL", "$@43", "$@44", "$@45", "USED_ARGS", "$@46",
  "EXPRESSION", "$@47", "$@48", "$@49", "$@50", "ERRONOUS_EXPRESSION",
  "COMPARISONSTT", "ERRONOUS_COMPARISONSTT", "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-262)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-155)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -262,   197,  -262,   670,  -262,  -262,  -262,  -262,   -26,   -20,
      13,  -262,  -262,   484,  -262,  -262,    25,    76,    -1,    85,
     495,  -262,   388,  -262,  -262,   484,  -262,    68,  -262,    54,
     -11,  -262,  -262,  -262,    43,  -262,  -262,  -262,    49,  -262,
    -262,  -262,  -262,  -262,  -262,    98,  -262,  -262,  -262,   944,
    -262,  -262,  -262,   484,   144,   407,  -262,   484,   484,    79,
     484,   484,   484,   484,   484,   101,  -262,  -262,    42,  -262,
     484,   357,    48,   484,  1076,   248,   163,    81,    28,    90,
      -4,   484,  -262,    16,    14,   125,    83,  -262,    63,    82,
    -262,   752,  -262,    38,  -262,    95,  -262,     5,  -262,    29,
     108,    43,  -262,   966,  -262,   418,   446,  -262,   129,   131,
    -262,  -262,   522,   533,   560,   571,    84,   484,    84,   484,
     146,   138,   175,  -262,   125,   125,   125,   284,   284,  -262,
     118,    43,  1032,   357,   357,   357,  1032,    83,   157,   134,
    -262,    18,   132,    -8,    86,   135,  -262,  -262,  1032,   149,
     147,    35,  -262,   484,   155,  -262,  -262,   314,  -262,   110,
     154,   152,   110,    19,    43,   484,  -262,  -262,   160,  -262,
      75,  -262,  -262,   484,    14,   598,    84,   179,   609,   146,
    -262,   484,  -262,   484,   484,  1111,   125,  1111,   125,  1098,
     284,  1098,   284,    84,    84,    19,   156,  -262,   357,   357,
    -262,   169,   171,   204,   174,  -262,   484,   484,   180,    71,
     177,   185,   132,  -262,   187,   188,   190,  -262,  -262,   988,
     210,   457,  -262,   484,   636,  -262,  -262,  -262,    19,   196,
    -262,    19,   194,   200,  -262,   198,  -262,  1032,  -262,   203,
    -262,    84,    14,    84,   179,    84,   138,   175,   125,   207,
    -262,   208,   357,   357,    43,   484,   195,   484,   484,   920,
     776,  -262,   201,  -262,  -262,   211,  -262,   227,  -262,   229,
     -11,   236,   -11,   -11,  -262,  -262,   647,  -262,   800,  1010,
    1054,   699,   242,  -262,  -262,  -262,  -262,    19,   243,  -262,
    -262,    43,  -262,   252,  -262,  -262,   824,   484,   848,   872,
    -262,  -262,  -262,   240,   254,  -262,  -262,   255,   -11,   256,
     261,   457,   264,   266,  -262,  -262,  -262,   272,   274,   737,
    -262,    43,  -262,    43,    43,  -262,    43,  -262,   357,  -262,
     896,  -262,  -262,   280,  -262,   287,  -262,  -262,  -262,  -262,
     457,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,    43,  -262,
    -262,  -262,  -262,    43,   289,  -262,   312,  -262,  -262,  -262,
    -262,   -11,  -262,  -262,  -262,    43,  -262
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    20,    21,    22,    23,     0,   102,
       0,   113,   157,     0,   158,   159,     0,     0,    42,     0,
       0,   155,     0,   156,   142,     0,     2,     0,     4,     0,
      52,    12,    46,     5,     0,    13,    84,    14,   108,     8,
       9,    11,   117,    10,   132,     0,     6,    15,   172,     0,
     174,   171,   188,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,     0,   110,
       0,     0,   127,     0,     0,     0,   160,   118,     0,     0,
       0,     0,    53,     0,   197,   187,   140,   137,     0,     0,
       3,     0,    26,    75,    16,     0,    47,     0,    62,     0,
     105,     0,   138,     0,   167,     0,     0,     7,   163,     0,
     165,   169,     0,     0,     0,     0,   177,     0,   189,     0,
     191,   175,   176,    29,   178,   193,   195,   198,   200,    28,
      66,     0,   103,     0,     0,     0,   114,     0,     0,     0,
     122,     0,     0,    87,     0,     0,    85,    86,    43,     0,
      55,     0,   148,     0,     0,   101,   145,     0,   173,     0,
       0,    63,     0,     0,     0,     0,    61,    45,     0,   104,
       0,   109,   139,     0,   190,     0,   179,   192,     0,   180,
     161,     0,   162,     0,     0,   194,   183,   196,   184,   199,
     185,   201,   186,   204,   202,     0,     0,   111,     0,     0,
     128,     0,     0,     0,     0,   120,     0,     0,     0,     0,
       0,     0,     0,    98,     0,     0,     0,    59,    44,     0,
       0,     0,   143,     0,     0,    34,    27,    30,     0,     0,
      25,     0,     0,     0,    79,    78,    51,    48,   112,     0,
     106,   168,   205,   182,   203,   181,   164,   166,   170,     0,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,    96,    95,    90,    94,     0,    99,     0,
      52,     0,    52,    52,   141,   100,     0,   146,   149,     0,
       0,    39,     0,    70,    80,    81,    76,     0,     0,   107,
      67,     0,   133,     0,   129,   115,     0,     0,     0,     0,
     126,   116,    93,     0,    87,    88,    83,     0,    52,     0,
       0,     0,     0,     0,    32,    33,    31,     0,     0,     0,
      64,     0,    77,     0,     0,    74,     0,   135,     0,   119,
       0,   123,   121,     0,    54,     0,    58,    60,   151,   147,
       0,    36,    38,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,    40,     0,    71,
      49,    68,   134,     0,     0,   125,     0,    91,    56,   150,
      65,    52,   136,   130,    50,     0,   131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -262,   241,   -69,  -160,  -262,  -262,  -262,   168,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -261,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -191,  -262,  -262,  -262,  -262,
    -137,    66,  -262,     3,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,   -16,  -262,  -262,  -262,  -262,  -262,  -252,
    -262,   -12,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    26,    27,    28,   162,   159,   226,   317,   318,
     319,    29,    81,    30,    31,    97,   165,   288,   371,    32,
     149,   215,   216,   273,    33,   228,   358,   195,   324,   229,
     321,   196,   291,    34,   163,   233,   234,   235,    35,   212,
     145,   146,   210,   147,   303,    36,    37,    38,    70,   100,
      39,   101,   131,    40,    73,   201,    41,    42,   138,   258,
     204,   139,    43,   135,   253,   328,   375,    44,   326,   363,
      45,    46,   153,    47,    90,    48,    89,   221,   312,   277,
     313,    49,   181,   183,   173,   184,    50,    51,    52,   357
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    76,   133,   232,   249,   208,   166,   209,    85,   307,
      68,   309,   310,    91,    71,   -41,    95,   150,    98,   205,
      96,    69,     4,     5,     6,     7,    77,    54,    55,   140,
     168,   -89,   143,   103,   144,   232,   217,   282,   141,   -24,
     284,   116,   118,   120,   167,   121,   122,   335,   124,   125,
     126,   127,   128,   -24,   -24,    72,   206,   151,   132,   338,
     207,   136,   231,    24,   198,   199,   200,    24,   232,   148,
      94,   232,   262,   218,   160,   269,   239,    79,   154,   155,
     161,    24,   263,   169,   130,   171,    82,   211,   369,    92,
      99,   264,   134,   176,   179,   123,   322,   105,   106,    74,
     186,   188,   190,   192,    93,   193,   265,   194,   266,    12,
     374,   223,    80,    24,   102,   197,    13,   129,    14,    15,
    -124,    83,   -82,   152,   156,   224,   225,   232,   142,   251,
     252,   170,    20,    21,    75,    23,   164,   104,   105,   106,
      25,   219,   108,   109,   110,    74,   180,   111,   236,   182,
     104,   105,   106,   237,   240,    12,   109,   110,   -72,   117,
     106,   241,    13,   243,    14,    15,   245,   202,   143,   246,
     227,   247,   248,   203,   213,   104,   105,   106,    20,    21,
      75,    23,   110,   293,   294,   -57,    25,   104,   105,   106,
     214,   220,   -69,    55,   259,   260,   250,     2,     3,   238,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   278,
     254,   279,   281,   255,   256,    13,   257,    14,    15,   261,
     267,    16,    17,    18,   268,   270,   275,    19,   272,   271,
     285,    20,    21,    22,    23,    24,   283,   297,   295,    25,
     286,   287,   289,   296,   302,   298,   299,   290,   292,   137,
     -92,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,   364,
    -154,  -154,  -154,   304,  -154,  -154,  -154,  -154,   306,  -154,
    -154,  -154,  -154,  -154,   308,   325,  -154,  -154,  -154,  -154,
    -154,  -154,   320,   333,   323,   330,  -154,  -154,  -154,  -154,
    -144,  -154,   327,   -89,   334,   336,   104,   105,   106,   278,
     337,   108,   109,   110,   339,   359,   111,   360,   361,   340,
     362,   341,   112,   113,   342,     3,   366,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   368,   209,   278,   373,
     230,   157,    13,   305,    14,    15,   367,     0,    16,    17,
      18,     0,   370,     0,    19,     0,     0,   372,    20,    21,
      22,    23,    24,   222,     0,     0,    25,     0,     3,   376,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,    13,     0,    14,    15,     0,
       0,    16,    17,    18,     0,     0,     0,    19,     0,    86,
       0,    20,    21,    22,    23,    24,     0,     0,     0,    25,
    -154,  -154,  -154,    87,  -154,  -154,  -154,  -154,    74,     0,
    -154,     0,     0,     0,     0,     0,  -154,  -154,    12,   174,
    -154,  -154,   119,     0,    88,    13,     0,    14,    15,    12,
    -144,     0,     0,   175,     0,     0,    13,     0,    14,    15,
       0,    20,    21,    75,    23,     0,     0,   177,     0,    25,
       0,     0,    20,    21,    75,    23,     0,    12,   276,     0,
      25,   178,     0,     0,    13,     0,    14,    15,    12,     0,
       0,     0,     0,     0,     0,    13,     0,    14,    15,     0,
      20,    21,    75,    23,     0,    74,     0,     0,    25,     0,
       0,    20,    21,    75,    23,    12,    84,  -153,     0,    25,
       0,     0,    13,     0,    14,    15,    12,     0,     0,     0,
       0,     0,     0,    13,     0,    14,    15,     0,    20,    21,
      75,    23,     0,   185,     0,     0,    25,     0,     0,    20,
      21,    75,    23,    12,   187,     0,     0,    25,     0,     0,
      13,     0,    14,    15,    12,     0,     0,     0,     0,     0,
       0,    13,     0,    14,    15,     0,    20,    21,    75,    23,
       0,   189,     0,     0,    25,     0,     0,    20,    21,    75,
      23,    12,   191,     0,     0,    25,     0,     0,    13,     0,
      14,    15,    12,     0,     0,     0,     0,     0,     0,    13,
       0,    14,    15,     0,    20,    21,    75,    23,     0,   242,
       0,     0,    25,     0,     0,    20,    21,    75,    23,    12,
     244,     0,     0,    25,     0,     0,    13,     0,    14,    15,
      12,     0,     0,     0,     0,     0,     0,    13,     0,    14,
      15,     0,    20,    21,    75,    23,     0,   280,     0,     0,
      25,     0,     0,    20,    21,    75,    23,    12,     0,     0,
       0,    25,     0,     0,    13,     0,    14,    15,     0,    53,
      54,    55,     0,     0,    57,     0,    58,     0,     0,    60,
      20,    21,    75,    23,     0,    61,    62,     0,    25,    63,
      64,     0,    53,    54,    55,     0,    56,    57,     0,    58,
     311,    59,    60,     0,     0,     0,     0,     0,    61,    62,
       0,     0,    63,    64,     0,     0,    65,     0,     0,    66,
      67,   104,   105,   106,     0,   316,   108,   109,   110,     0,
       0,   111,     0,     0,     0,     0,     0,   112,   113,     0,
       0,   114,   115,     0,     0,     0,     0,     0,   -35,   -37,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   351,     0,
     352,   353,   354,     0,   104,   105,   106,   355,   356,   108,
     109,   110,     0,     0,   111,     0,     0,     0,     0,     0,
     112,   113,     0,     0,   114,   115,     0,     0,   104,   105,
     106,     0,   158,   108,   109,   110,     0,     0,   111,     0,
       0,     0,     0,     0,   112,   113,     0,     0,   114,   115,
       0,     0,   104,   105,   106,     0,   301,   108,   109,   110,
       0,     0,   111,     0,     0,     0,     0,     0,   112,   113,
       0,     0,   114,   115,     0,     0,   104,   105,   106,     0,
    -152,   108,   109,   110,     0,     0,   111,     0,     0,     0,
       0,     0,   112,   113,     0,     0,   114,   115,     0,     0,
     104,   105,   106,     0,   329,   108,   109,   110,     0,     0,
     111,     0,     0,     0,     0,     0,   112,   113,     0,     0,
     114,   115,     0,     0,   104,   105,   106,     0,   331,   108,
     109,   110,     0,     0,   111,     0,     0,     0,     0,     0,
     112,   113,     0,     0,   114,   115,     0,     0,   104,   105,
     106,     0,   332,   108,   109,   110,     0,     0,   111,     0,
       0,     0,     0,     0,   112,   113,     0,     0,   114,   115,
       0,     0,   104,   105,   106,     0,   365,   108,   109,   110,
       0,     0,   111,     0,     0,     0,     0,     0,   112,   113,
       0,     0,   114,   115,     0,     0,   104,   105,   106,   300,
     107,   108,   109,   110,     0,     0,   111,     0,     0,     0,
       0,     0,   112,   113,     0,     0,   114,   115,   104,   105,
     106,     0,   172,   108,   109,   110,     0,     0,   111,     0,
       0,     0,     0,     0,   112,   113,     0,     0,   114,   115,
     104,   105,   106,     0,   274,   108,   109,   110,     0,     0,
     111,     0,     0,     0,     0,     0,   112,   113,     0,     0,
     114,   115,   104,   105,   106,     0,   314,   108,   109,   110,
       0,     0,   111,     0,     0,     0,     0,     0,   112,   113,
       0,     0,   114,   115,   104,   105,   106,     0,     0,   108,
     109,   110,     0,     0,   111,     0,     0,     0,     0,     0,
     112,   113,     0,     0,   114,   115,    53,    54,    55,     0,
     315,    57,     0,    58,     0,     0,    60,     0,     0,     0,
       0,     0,    61,    62,     0,     0,    63,    64,    53,    54,
      55,     0,     0,    57,     0,    58,     0,     0,    60,     0,
       0,     0,     0,     0,    61,    62,     0,     0,    63,    64,
      53,    54,    55,     0,     0,    57,     0,    58,     0,     0,
      60,     0,     0,    53,    54,    55,    61,    62,    57,     0,
      58,     0,     0,    60
};

static const yytype_int16 yycheck[] =
{
      16,    13,    71,   163,   195,   142,     1,    15,    20,   270,
      36,   272,   273,    25,     1,    16,    27,     1,    34,     1,
      31,    41,     3,     4,     5,     6,     1,    13,    14,     1,
       1,    39,    36,    45,    38,   195,     1,   228,    10,     1,
     231,    53,    54,    55,    39,    57,    58,   308,    60,    61,
      62,    63,    64,    15,    16,    42,    38,    41,    70,   311,
      42,    73,    43,    38,   133,   134,   135,    38,   228,    81,
      16,   231,     1,    38,    36,   212,     1,     1,    15,    16,
      42,    38,    11,    99,    42,   101,     1,     1,   340,    21,
      41,    20,    44,   105,   106,    16,   287,    13,    14,     1,
     112,   113,   114,   115,    36,   117,    35,   119,    37,    11,
     371,     1,    36,    38,    16,   131,    18,    16,    20,    21,
      39,    36,    36,    40,    42,    15,    16,   287,    38,   198,
     199,    23,    34,    35,    36,    37,    41,    12,    13,    14,
      42,   153,    17,    18,    19,     1,    17,    22,   164,    18,
      12,    13,    14,   165,   170,    11,    18,    19,    40,    15,
      14,   173,    18,   175,    20,    21,   178,    10,    36,   181,
      16,   183,   184,    39,    39,    12,    13,    14,    34,    35,
      36,    37,    19,   252,   253,    38,    42,    12,    13,    14,
      41,    36,    40,    14,   206,   207,    40,     0,     1,    39,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   221,
      41,   223,   224,    42,    10,    18,    42,    20,    21,    39,
      43,    24,    25,    26,    39,    38,    16,    30,    38,    41,
      36,    34,    35,    36,    37,    38,    40,    42,   254,    42,
      40,    43,    39,   255,    43,   257,   258,    40,    40,     1,
      39,     3,     4,     5,     6,     7,     8,     9,    10,   328,
      12,    13,    14,    36,    16,    17,    18,    19,    39,    21,
      22,    23,    24,    25,    38,   291,    28,    29,    30,    31,
      32,    33,    40,    43,    41,   297,    38,    39,    40,    41,
      42,    43,    40,    39,    39,    39,    12,    13,    14,   311,
      39,    17,    18,    19,    40,   321,    22,   323,   324,    43,
     326,    39,    28,    29,    40,     1,    36,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    39,    15,   340,    40,
     162,    90,    18,   267,    20,    21,   333,    -1,    24,    25,
      26,    -1,   358,    -1,    30,    -1,    -1,   363,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,     1,   375,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,
      -1,    24,    25,    26,    -1,    -1,    -1,    30,    -1,     1,
      -1,    34,    35,    36,    37,    38,    -1,    -1,    -1,    42,
      12,    13,    14,    15,    16,    17,    18,    19,     1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    11,     1,
      32,    33,    15,    -1,    36,    18,    -1,    20,    21,    11,
      42,    -1,    -1,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,    34,    35,    36,    37,    -1,    -1,     1,    -1,    42,
      -1,    -1,    34,    35,    36,    37,    -1,    11,     1,    -1,
      42,    15,    -1,    -1,    18,    -1,    20,    21,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,
      34,    35,    36,    37,    -1,     1,    -1,    -1,    42,    -1,
      -1,    34,    35,    36,    37,    11,     1,    40,    -1,    42,
      -1,    -1,    18,    -1,    20,    21,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    20,    21,    -1,    34,    35,
      36,    37,    -1,     1,    -1,    -1,    42,    -1,    -1,    34,
      35,    36,    37,    11,     1,    -1,    -1,    42,    -1,    -1,
      18,    -1,    20,    21,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    20,    21,    -1,    34,    35,    36,    37,
      -1,     1,    -1,    -1,    42,    -1,    -1,    34,    35,    36,
      37,    11,     1,    -1,    -1,    42,    -1,    -1,    18,    -1,
      20,    21,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    20,    21,    -1,    34,    35,    36,    37,    -1,     1,
      -1,    -1,    42,    -1,    -1,    34,    35,    36,    37,    11,
       1,    -1,    -1,    42,    -1,    -1,    18,    -1,    20,    21,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,
      21,    -1,    34,    35,    36,    37,    -1,     1,    -1,    -1,
      42,    -1,    -1,    34,    35,    36,    37,    11,    -1,    -1,
      -1,    42,    -1,    -1,    18,    -1,    20,    21,    -1,    12,
      13,    14,    -1,    -1,    17,    -1,    19,    -1,    -1,    22,
      34,    35,    36,    37,    -1,    28,    29,    -1,    42,    32,
      33,    -1,    12,    13,    14,    -1,    16,    17,    -1,    19,
      43,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,    -1,    -1,    36,    -1,    -1,    39,
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
      -1,    -1,    32,    33,    -1,    -1,    12,    13,    14,    39,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    12,    13,
      14,    -1,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      12,    13,    14,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    33,    12,    13,    14,    -1,    -1,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    33,    12,    13,    14,    -1,
      16,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    12,    13,
      14,    -1,    -1,    17,    -1,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      12,    13,    14,    -1,    -1,    17,    -1,    19,    -1,    -1,
      22,    -1,    -1,    12,    13,    14,    28,    29,    17,    -1,
      19,    -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    18,    20,    21,    24,    25,    26,    30,
      34,    35,    36,    37,    38,    42,    47,    48,    49,    56,
      58,    59,    64,    69,    78,    83,    90,    91,    92,    95,
      98,   101,   102,   107,   112,   115,   116,   118,   120,   126,
     131,   132,   133,    12,    13,    14,    16,    17,    19,    21,
      22,    28,    29,    32,    33,    36,    39,    40,    36,    41,
      93,     1,    42,    99,     1,    36,   126,     1,   118,     1,
      36,    57,     1,    36,     1,   126,     1,    15,    36,   121,
     119,   126,    21,    36,    16,    27,    31,    60,   118,    41,
      94,    96,    16,   126,    12,    13,    14,    16,    17,    18,
      19,    22,    28,    29,    32,    33,   126,    15,   126,    15,
     126,   126,   126,    16,   126,   126,   126,   126,   126,    16,
      42,    97,   126,    47,    44,   108,   126,     1,   103,   106,
       1,    10,    38,    36,    38,    85,    86,    88,   126,    65,
       1,    41,    40,   117,    15,    16,    42,    46,    40,    51,
      36,    42,    50,    79,    41,    61,     1,    39,     1,   118,
      23,   118,    16,   129,     1,    15,   126,     1,    15,   126,
      17,   127,    18,   128,   130,     1,   126,     1,   126,     1,
     126,     1,   126,   126,   126,    72,    76,   118,    47,    47,
      47,   100,    10,    39,   105,     1,    38,    42,    85,    15,
      87,     1,    84,    39,    41,    66,    67,     1,    38,   126,
      36,   122,    39,     1,    15,    16,    52,    16,    70,    74,
      52,    43,    48,    80,    81,    82,   118,   126,    39,     1,
     118,   126,     1,   126,     1,   126,   126,   126,   126,    80,
      40,    47,    47,   109,    41,    42,    10,    42,   104,   126,
     126,    39,     1,    11,    20,    35,    37,    43,    39,    85,
      38,    41,    38,    68,    16,    16,     1,   124,   126,   126,
       1,   126,    80,    40,    80,    36,    40,    43,    62,    39,
      40,    77,    40,    47,    47,   118,   126,    42,   126,   126,
      39,    40,    43,    89,    36,    86,    39,    60,    38,    60,
      60,    43,   123,   125,    16,    16,    16,    53,    54,    55,
      40,    75,    80,    41,    73,   118,   113,    40,   110,    40,
     126,    40,    40,    43,    39,    60,    39,    39,   124,    40,
      43,    39,    40,     3,     4,     5,     6,     7,     8,     9,
      10,    21,    23,    24,    25,    30,    31,   134,    71,   118,
     118,   118,   118,   114,    47,    40,    36,    88,    39,   124,
     118,    63,   118,    40,    60,   111,   118
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    48,    48,    50,    49,    51,    49,    49,    49,
      49,    52,    52,    52,    52,    53,    52,    54,    52,    55,
      52,    56,    57,    56,    58,    59,    59,    61,    62,    63,
      60,    60,    60,    65,    64,    66,    64,    67,    64,    68,
      64,    64,    69,    70,    71,    69,    72,    73,    69,    74,
      75,    69,    76,    77,    69,    79,    78,    80,    80,    80,
      81,    82,    84,    83,    83,    85,    85,    87,    86,    86,
      89,    88,    88,    88,    88,    88,    88,    90,    90,    90,
      91,    91,    93,    92,    94,    95,    95,    95,    96,    95,
      97,    95,    95,    99,   100,    98,   101,   101,   103,   102,
     104,   102,   105,   102,   106,   102,   102,   108,   109,   110,
     111,   107,   107,   113,   112,   114,   112,   115,   116,   116,
     117,   116,   119,   118,   121,   122,   123,   120,   120,   125,
     124,   124,   124,   124,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   127,   126,   128,   126,   129,   126,   130,
     126,   126,   126,   126,   126,   131,   131,   131,   131,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     0,     4,     0,     4,     3,     3,
       4,     3,     3,     3,     1,     0,     4,     0,     4,     0,
       4,     1,     0,     3,     4,     3,     1,     0,     0,     0,
       8,     3,     0,     0,     7,     0,     8,     0,     7,     0,
       7,     3,     2,     0,     0,     8,     0,     0,     8,     0,
       0,     7,     0,     0,     7,     0,     5,     3,     1,     1,
       2,     2,     0,     6,     1,     1,     1,     0,     4,     1,
       0,     6,     3,     4,     3,     3,     3,     5,     4,     5,
       5,     3,     0,     3,     2,     2,     4,     5,     0,     3,
       0,     4,     4,     0,     0,     6,     6,     1,     0,     7,
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
#line 184 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1753 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 190 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1759 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 193 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1765 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 194 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1771 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 195 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1777 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 196 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1783 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 197 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1789 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 198 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1795 "parser.tab.c"
    break;

  case 14: /* STATEMENT: ENUM_CALL_STT  */
#line 199 "parser.y"
                                                            {printf("#[Parsed_Enum_USAGE]# ");}
#line 1801 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error SEMICOLON  */
#line 202 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1807 "parser.tab.c"
    break;

  case 18: /* STATEMENT: error '}'  */
#line 203 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1813 "parser.tab.c"
    break;

  case 19: /* STATEMENT: error ')'  */
#line 204 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1819 "parser.tab.c"
    break;

  case 20: /* TYPE: INT  */
#line 212 "parser.y"
                            { (yyval.str) = "int";   }
#line 1825 "parser.tab.c"
    break;

  case 21: /* TYPE: FLOAT  */
#line 213 "parser.y"
                            { (yyval.str) = "float"; }
#line 1831 "parser.tab.c"
    break;

  case 22: /* TYPE: BOOL  */
#line 214 "parser.y"
                            { (yyval.str) = "bool";  }
#line 1837 "parser.tab.c"
    break;

  case 23: /* TYPE: STRING  */
#line 215 "parser.y"
                            { (yyval.str) = "string";}
#line 1843 "parser.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 219 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0);   assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1849 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 219 "parser.y"
                                                                                                                                                         {printf("#[Parsed_Declaration]# "); }
#line 1855 "parser.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 220 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0); assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1861 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 220 "parser.y"
                                                                                                                                                         {printf("#[Parsed_CONST_Declaration]# "); }
#line 1867 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 221 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1873 "parser.tab.c"
    break;

  case 29: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 222 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1879 "parser.tab.c"
    break;

  case 30: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 223 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);}
#line 1885 "parser.tab.c"
    break;

  case 31: /* DECLARATION_TAIL: EQ EXPRESSION SEMICOLON  */
#line 228 "parser.y"
                                                                                            {StAssPush(strdup(IdentifierHolder)); StAssPrint("OVER", 1); StAssPrint("STORE", 1); StAssPrint("DROP", 1);}
#line 1891 "parser.tab.c"
    break;

  case 32: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 229 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1897 "parser.tab.c"
    break;

  case 33: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 230 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1903 "parser.tab.c"
    break;

  case 35: /* $@3: %empty  */
#line 232 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1909 "parser.tab.c"
    break;

  case 37: /* $@4: %empty  */
#line 233 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1915 "parser.tab.c"
    break;

  case 39: /* $@5: %empty  */
#line 234 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1921 "parser.tab.c"
    break;

  case 41: /* RETURN_STT: RETURN  */
#line 241 "parser.y"
                                                {int dum = 0;StAssPrint("POP\tPC",1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1927 "parser.tab.c"
    break;

  case 42: /* $@6: %empty  */
#line 242 "parser.y"
                         {assign_index =func_index;}
#line 1933 "parser.tab.c"
    break;

  case 43: /* RETURN_STT: RETURN $@6 EXPRESSION  */
#line 242 "parser.y"
                                                                            { return_exist = 1; StAssPrint("OVER",1);int dum = 0;StAssPrint("POP\tPC",1);StAssPrint("DNEXT", 1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1939 "parser.tab.c"
    break;

  case 44: /* helperSWITCH: SWITCH IDENTIFIER ':' '{'  */
#line 244 "parser.y"
                                          {strcpy(switcher, (yyvsp[-2].str));}
#line 1945 "parser.tab.c"
    break;

  case 45: /* SWITCH_STT: helperSWITCH CASES '}'  */
#line 247 "parser.y"
                                        {StAssPrintLBL(0,1);}
#line 1951 "parser.tab.c"
    break;

  case 47: /* $@7: %empty  */
#line 253 "parser.y"
                     {StAssPush(switcher);}
#line 1957 "parser.tab.c"
    break;

  case 48: /* $@8: %empty  */
#line 253 "parser.y"
                                                       {StAssPrint("EQ", 1); StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 1963 "parser.tab.c"
    break;

  case 49: /* $@9: %empty  */
#line 253 "parser.y"
                                                                                                                                   {StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 1969 "parser.tab.c"
    break;

  case 51: /* CASES: DEFAULT ':' BLOCK  */
#line 254 "parser.y"
                                    {StAssJmp("JMP", "END",&SMLabel_End, 0,0); }
#line 1975 "parser.tab.c"
    break;

  case 53: /* $@10: %empty  */
#line 265 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1981 "parser.tab.c"
    break;

  case 55: /* $@11: %empty  */
#line 266 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }
#line 1987 "parser.tab.c"
    break;

  case 57: /* $@12: %empty  */
#line 267 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1993 "parser.tab.c"
    break;

  case 59: /* $@13: %empty  */
#line 268 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1999 "parser.tab.c"
    break;

  case 61: /* ERRONOUS_SWITCH_STT: helperSWITCH CASES error  */
#line 269 "parser.y"
                                           {printf("\n\n=====ERROR====\n unclosed '}' for switch statement at line %d\n\n", yylineno);}
#line 2005 "parser.tab.c"
    break;

  case 63: /* $@14: %empty  */
#line 282 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2011 "parser.tab.c"
    break;

  case 64: /* $@15: %empty  */
#line 282 "parser.y"
                                                                                                                    {func_index = st_insert((yyvsp[-5].str), (yyvsp[-4].str),"func",0); popArgs();}
#line 2017 "parser.tab.c"
    break;

  case 66: /* $@16: %empty  */
#line 283 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2023 "parser.tab.c"
    break;

  case 67: /* $@17: %empty  */
#line 283 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-4].str),"func",0); popArgs();}
#line 2029 "parser.tab.c"
    break;

  case 69: /* $@18: %empty  */
#line 284 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2035 "parser.tab.c"
    break;

  case 70: /* $@19: %empty  */
#line 284 "parser.y"
                                                                                                                    {func_index=st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2041 "parser.tab.c"
    break;

  case 72: /* $@20: %empty  */
#line 285 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2047 "parser.tab.c"
    break;

  case 73: /* $@21: %empty  */
#line 285 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-3].str),"func",0);}
#line 2053 "parser.tab.c"
    break;

  case 75: /* $@22: %empty  */
#line 290 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 2059 "parser.tab.c"
    break;

  case 76: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@22 ARGS ')'  */
#line 290 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2065 "parser.tab.c"
    break;

  case 80: /* ERRONOUS_ARGS: ',' ARGS  */
#line 305 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
#line 2071 "parser.tab.c"
    break;

  case 81: /* ARG_DECL: TYPE IDENTIFIER  */
#line 308 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1); char* buf=(yyvsp[0].str); argumentList[argPointer]=buf;argPointer++;}
#line 2077 "parser.tab.c"
    break;

  case 82: /* $@23: %empty  */
#line 315 "parser.y"
                                      { is_enum =1;}
#line 2083 "parser.tab.c"
    break;

  case 83: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' $@23 ENUM_HELPER '}'  */
#line 315 "parser.y"
                                                                              { st_insert("enum" , (yyvsp[-4].str), "var" , 0); is_enum=0; enumCNT=1;}
#line 2089 "parser.tab.c"
    break;

  case 87: /* $@24: %empty  */
#line 321 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++;  st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int(  enum_arg_count-1,st_index-1); }
#line 2095 "parser.tab.c"
    break;

  case 89: /* ENUM_ARGS: IDENTIFIER  */
#line 322 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++; st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int( enum_arg_count-1,st_index-1);  }
#line 2101 "parser.tab.c"
    break;

  case 90: /* $@25: %empty  */
#line 328 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++ ; st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2107 "parser.tab.c"
    break;

  case 92: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ DIGIT  */
#line 329 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++;  st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2113 "parser.tab.c"
    break;

  case 93: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ error ','  */
#line 330 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2119 "parser.tab.c"
    break;

  case 94: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ FLOAT_DIGIT  */
#line 331 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2125 "parser.tab.c"
    break;

  case 95: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ STRING_LITERAL  */
#line 332 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2131 "parser.tab.c"
    break;

  case 96: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ BOOL_LITERAL  */
#line 333 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2137 "parser.tab.c"
    break;

  case 97: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 337 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);}
#line 2143 "parser.tab.c"
    break;

  case 98: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 338 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);}
#line 2149 "parser.tab.c"
    break;

  case 99: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 340 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2155 "parser.tab.c"
    break;

  case 100: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER EQ IDENTIFIER SEMICOLON  */
#line 343 "parser.y"
                                                               { StAssPush((yyvsp[-3].str));StAssPush((yyvsp[-1].str));StAssPrint("STORE",1); st_insert((yyvsp[-4].str) , (yyvsp[-3].str), "var_enum" , 0); assign_enum(st_index-1, (yyvsp[-4].str),(yyvsp[-1].str)); int i= lookup((yyvsp[-4].str)); symbolTable[i].isUsed=1; }
#line 2161 "parser.tab.c"
    break;

  case 101: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER SEMICOLON  */
#line 344 "parser.y"
                                                   { st_insert((yyvsp[-2].str) , (yyvsp[-1].str), "var_enum" , 0); int i= lookup((yyvsp[-2].str)); symbolTable[i].isUsed=1;}
#line 2167 "parser.tab.c"
    break;

  case 102: /* $@26: %empty  */
#line 348 "parser.y"
                   {printIF();}
#line 2173 "parser.tab.c"
    break;

  case 103: /* IF_STT_HELPER: IF $@26 EXPRESSION  */
#line 348 "parser.y"
                                           {StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2179 "parser.tab.c"
    break;

  case 104: /* IF_STT_HELPER1: ':' BLOCK  */
#line 351 "parser.y"
                                                            {controlTerminator(0);  StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2185 "parser.tab.c"
    break;

  case 105: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1  */
#line 355 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2191 "parser.tab.c"
    break;

  case 106: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE BLOCK  */
#line 356 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2197 "parser.tab.c"
    break;

  case 107: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE error '}'  */
#line 357 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);}
#line 2203 "parser.tab.c"
    break;

  case 108: /* $@27: %empty  */
#line 358 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 2209 "parser.tab.c"
    break;

  case 110: /* $@28: %empty  */
#line 359 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);}
#line 2215 "parser.tab.c"
    break;

  case 112: /* IF_STT: IF_STT_HELPER ':' error '}'  */
#line 360 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);}
#line 2221 "parser.tab.c"
    break;

  case 113: /* $@29: %empty  */
#line 369 "parser.y"
                      {printWHILE(); StAssPrintLBL(1, 0);}
#line 2227 "parser.tab.c"
    break;

  case 114: /* $@30: %empty  */
#line 369 "parser.y"
                                                                      {StAssJmp("JNZ", "END",&SMLabel_End, 0,0);}
#line 2233 "parser.tab.c"
    break;

  case 115: /* WHILE_STT: WHILE $@29 EXPRESSION $@30 ':' BLOCK  */
#line 369 "parser.y"
                                                                                                                            {StAssJmp("JMP", "LBL",&SMLabel_Else, 1,0); StAssPrintLBL(0, 1);}
#line 2239 "parser.tab.c"
    break;

  case 118: /* $@31: %empty  */
#line 382 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2245 "parser.tab.c"
    break;

  case 120: /* $@32: %empty  */
#line 383 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2251 "parser.tab.c"
    break;

  case 122: /* $@33: %empty  */
#line 384 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);}
#line 2257 "parser.tab.c"
    break;

  case 124: /* $@34: %empty  */
#line 385 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);}
#line 2263 "parser.tab.c"
    break;

  case 126: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 386 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);}
#line 2269 "parser.tab.c"
    break;

  case 127: /* $@35: %empty  */
#line 393 "parser.y"
                        {in_loop = 1;}
#line 2275 "parser.tab.c"
    break;

  case 128: /* $@36: %empty  */
#line 393 "parser.y"
                                                 {StAssForHeader();}
#line 2281 "parser.tab.c"
    break;

  case 129: /* $@37: %empty  */
#line 393 "parser.y"
                                                                               {StAssForMiddle();}
#line 2287 "parser.tab.c"
    break;

  case 130: /* $@38: %empty  */
#line 393 "parser.y"
                                                                                                                {StAssPrintLBL(1,1); in_loop = 0;}
#line 2293 "parser.tab.c"
    break;

  case 131: /* FOR_STT: FOR '(' $@35 STATEMENT $@36 STATEMENT $@37 STATEMENT ')' $@38 BLOCK  */
#line 393 "parser.y"
                                                                                                                                                          {StAssJmp("JMP", "Label", &ForHeaderLabel,1,0); StAssPrintLBL(0,1);}
#line 2299 "parser.tab.c"
    break;

  case 133: /* $@39: %empty  */
#line 398 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);}
#line 2305 "parser.tab.c"
    break;

  case 135: /* $@40: %empty  */
#line 399 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);}
#line 2311 "parser.tab.c"
    break;

  case 137: /* helperAssignmentRule: IDENTIFIER EQ  */
#line 406 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); StAssPush((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str));}
#line 2317 "parser.tab.c"
    break;

  case 138: /* assignmentSTT: helperAssignmentRule SEMICOLON  */
#line 410 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);}
#line 2323 "parser.tab.c"
    break;

  case 139: /* assignmentSTT: helperAssignmentRule EXPRESSION SEMICOLON  */
#line 411 "parser.y"
                                                                 {StAssPrint("STORE", 1); CodeGenAss();printf("#[Parsed_Assignment]# ");}
#line 2329 "parser.tab.c"
    break;

  case 140: /* $@41: %empty  */
#line 412 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str)); StAssPush((yyvsp[-1].str));}
#line 2335 "parser.tab.c"
    break;

  case 141: /* assignmentSTT: IDENTIFIER error $@41 EXPRESSION SEMICOLON  */
#line 412 "parser.y"
                                                                                                                                                                                                 {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);}
#line 2341 "parser.tab.c"
    break;

  case 142: /* $@42: %empty  */
#line 417 "parser.y"
                    {scope_start();}
#line 2347 "parser.tab.c"
    break;

  case 143: /* BLOCK: '{' $@42 PROGRAM '}'  */
#line 417 "parser.y"
                                                                              {scope_end(); printf("#[Parsed_Block]# ");}
#line 2353 "parser.tab.c"
    break;

  case 144: /* $@43: %empty  */
#line 425 "parser.y"
                           {called_func_index = lookup((yyvsp[0].str)); check_type(called_func_index); StAssPush("PC");}
#line 2359 "parser.tab.c"
    break;

  case 145: /* $@44: %empty  */
#line 425 "parser.y"
                                                                                                                 { is_param =1;}
#line 2365 "parser.tab.c"
    break;

  case 146: /* $@45: %empty  */
#line 425 "parser.y"
                                                                                                                                            { is_param =0; arg_count_check(called_func_index); arg_count=0; int dum=0; StAssJmp("JMP", (yyvsp[-4].str),&dum, 0,0);}
#line 2371 "parser.tab.c"
    break;

  case 147: /* FUNC_CALL: IDENTIFIER $@43 '(' $@44 USED_ARGS $@45 ')'  */
#line 425 "parser.y"
                                                                                                                                                                                                                                                             { printf("#[Parsed_Func_Call]# ");}
#line 2377 "parser.tab.c"
    break;

  case 148: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 426 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 2383 "parser.tab.c"
    break;

  case 149: /* $@46: %empty  */
#line 430 "parser.y"
                           { arg_count++; }
#line 2389 "parser.tab.c"
    break;

  case 151: /* USED_ARGS: error ',' USED_ARGS  */
#line 431 "parser.y"
                                                            {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 2395 "parser.tab.c"
    break;

  case 152: /* USED_ARGS: EXPRESSION  */
#line 432 "parser.y"
                             {arg_count++ ;}
#line 2401 "parser.tab.c"
    break;

  case 154: /* EXPRESSION: IDENTIFIER  */
#line 439 "parser.y"
                                                { int i = lookup((yyvsp[0].str)); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2407 "parser.tab.c"
    break;

  case 155: /* EXPRESSION: DIGIT  */
#line 440 "parser.y"
                                                { assign_int((yyvsp[0].num), assign_index) ; char numtostring[40]; itoa((yyvsp[0].num), numtostring, 10); pushVStack(numtostring); char dum[10]="$"; StAssPush(strcat(dum,numtostring));}
#line 2413 "parser.tab.c"
    break;

  case 156: /* EXPRESSION: FLOAT_DIGIT  */
#line 441 "parser.y"
                                                { assign_float((yyvsp[0].float_val), assign_index); char floattostring[40]; gcvt((yyvsp[0].float_val), 6, floattostring); pushVStack(floattostring); char dum[10]="$"; StAssPush(strcat(dum,floattostring));}
#line 2419 "parser.tab.c"
    break;

  case 157: /* EXPRESSION: BOOL_LITERAL  */
#line 442 "parser.y"
                                                { assign_bool((yyvsp[0].bool_val), assign_index); if((yyvsp[0].bool_val)==true){pushVStack("true");StAssPush("$true");}else{pushVStack("false");StAssPush("$false");} }
#line 2425 "parser.tab.c"
    break;

  case 158: /* EXPRESSION: STRING_LITERAL  */
#line 443 "parser.y"
                                                { assign_str((yyvsp[0].str), assign_index); pushVStack((yyvsp[0].str));char buf[50]; strcpy(buf, "$");strcat(buf, (yyvsp[0].str)); StAssPush(buf);}
#line 2431 "parser.tab.c"
    break;

  case 159: /* EXPRESSION: CONSTANT  */
#line 444 "parser.y"
                                                { int i = lookup((yyvsp[0].str)); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2437 "parser.tab.c"
    break;

  case 160: /* EXPRESSION: SUB EXPRESSION  */
#line 445 "parser.y"
                                                {StAssPrint("neg", 1);}
#line 2443 "parser.tab.c"
    break;

  case 161: /* EXPRESSION: EXPRESSION PLUS PLUS  */
#line 446 "parser.y"
                                                { pushVStack("+"); pushVStack("1"); CodeGenOp("ADD"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("ADD", 1); StAssPrint("STORE", 1);}
#line 2449 "parser.tab.c"
    break;

  case 162: /* EXPRESSION: EXPRESSION SUB SUB  */
#line 447 "parser.y"
                                                { pushVStack("-"); pushVStack("1"); CodeGenOp("SUB"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("SUB", 1); StAssPrint("STORE", 1);}
#line 2455 "parser.tab.c"
    break;

  case 163: /* $@47: %empty  */
#line 448 "parser.y"
                                                { pushVStack("+");}
#line 2461 "parser.tab.c"
    break;

  case 164: /* EXPRESSION: EXPRESSION PLUS $@47 EXPRESSION  */
#line 448 "parser.y"
                                                                                 {CodeGenOp("ADD"); StAssPrint("ADD", 1);}
#line 2467 "parser.tab.c"
    break;

  case 165: /* $@48: %empty  */
#line 450 "parser.y"
                                                { pushVStack("*");}
#line 2473 "parser.tab.c"
    break;

  case 166: /* EXPRESSION: EXPRESSION MUL $@48 EXPRESSION  */
#line 450 "parser.y"
                                                                                 {CodeGenOp("MUL"); StAssPrint("MUL", 1);}
#line 2479 "parser.tab.c"
    break;

  case 167: /* $@49: %empty  */
#line 451 "parser.y"
                                                { pushVStack("/");}
#line 2485 "parser.tab.c"
    break;

  case 168: /* EXPRESSION: EXPRESSION DIV $@49 EXPRESSION  */
#line 451 "parser.y"
                                                                                 {CodeGenOp("DIV"); StAssPrint("DIV", 1);}
#line 2491 "parser.tab.c"
    break;

  case 169: /* $@50: %empty  */
#line 454 "parser.y"
                                                {pushVStack("^");}
#line 2497 "parser.tab.c"
    break;

  case 170: /* EXPRESSION: EXPRESSION POW $@50 EXPRESSION  */
#line 454 "parser.y"
                                                                               {CodeGenOp("POW");}
#line 2503 "parser.tab.c"
    break;

  case 174: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 458 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);}
#line 2509 "parser.tab.c"
    break;

  case 179: /* COMPARISONSTT: EXPRESSION GT EXPRESSION  */
#line 478 "parser.y"
                                                        {pushVStack(">"); CodeGenLogical(); StAssPrint("GT", 1);}
#line 2515 "parser.tab.c"
    break;

  case 180: /* COMPARISONSTT: EXPRESSION LT EXPRESSION  */
#line 479 "parser.y"
                                                        {pushVStack("<"); CodeGenLogical(); StAssPrint("LT", 1);}
#line 2521 "parser.tab.c"
    break;

  case 181: /* COMPARISONSTT: EXPRESSION LT EQ EXPRESSION  */
#line 480 "parser.y"
                                                        {pushVStack("<="); CodeGenLogical(); StAssPrint("LE", 1);}
#line 2527 "parser.tab.c"
    break;

  case 182: /* COMPARISONSTT: EXPRESSION GT EQ EXPRESSION  */
#line 481 "parser.y"
                                                        {pushVStack(">="); CodeGenLogical(); StAssPrint("GE", 1);}
#line 2533 "parser.tab.c"
    break;

  case 183: /* COMPARISONSTT: EXPRESSION EQUALITY EXPRESSION  */
#line 482 "parser.y"
                                                        {pushVStack("="); CodeGenLogical(); StAssPrint("EQ", 1);}
#line 2539 "parser.tab.c"
    break;

  case 184: /* COMPARISONSTT: EXPRESSION NEG_EQUALITY EXPRESSION  */
#line 483 "parser.y"
                                                        {pushVStack("!="); CodeGenLogical(); StAssPrint("NE", 1);}
#line 2545 "parser.tab.c"
    break;

  case 185: /* COMPARISONSTT: EXPRESSION LOGIC_AND EXPRESSION  */
#line 484 "parser.y"
                                                        {pushVStack("and"); CodeGenLogical(); StAssPrint("AND", 1);}
#line 2551 "parser.tab.c"
    break;

  case 186: /* COMPARISONSTT: EXPRESSION LOGIC_OR EXPRESSION  */
#line 485 "parser.y"
                                                        {pushVStack("or"); CodeGenLogical(); StAssPrint("OR", 1);}
#line 2557 "parser.tab.c"
    break;

  case 187: /* COMPARISONSTT: LOGIC_NOT EXPRESSION  */
#line 486 "parser.y"
                                                        {StAssPrint("neg", 1);}
#line 2563 "parser.tab.c"
    break;

  case 189: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 491 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 2569 "parser.tab.c"
    break;

  case 190: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 492 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 2575 "parser.tab.c"
    break;

  case 191: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 493 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 2581 "parser.tab.c"
    break;

  case 192: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 494 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 2587 "parser.tab.c"
    break;

  case 193: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 495 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 2593 "parser.tab.c"
    break;

  case 194: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 496 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 2599 "parser.tab.c"
    break;

  case 195: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 497 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 2605 "parser.tab.c"
    break;

  case 196: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 498 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 2611 "parser.tab.c"
    break;

  case 197: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 499 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 2617 "parser.tab.c"
    break;

  case 198: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 500 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 2623 "parser.tab.c"
    break;

  case 199: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 501 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 2629 "parser.tab.c"
    break;

  case 200: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 502 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 2635 "parser.tab.c"
    break;

  case 201: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 503 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 2641 "parser.tab.c"
    break;

  case 202: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 504 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 2647 "parser.tab.c"
    break;

  case 203: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 505 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 2653 "parser.tab.c"
    break;

  case 204: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 506 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 2659 "parser.tab.c"
    break;

  case 205: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 507 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 2665 "parser.tab.c"
    break;


#line 2669 "parser.tab.c"

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

#line 526 "parser.y"




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
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == block_number){
            printf("\n===================== %d %s\n", scope_index, symbolTable[i].name);
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
    assign_index = -1;
}
void assign_float( float f, int i) {
    if (i == -1) {return;}
     if ( symbolTable[i].dataType != "float" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned float !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
     return ;}
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "float"){symbolTable[i].floatValue= f ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned float value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
   if(is_changed == 1) {st_log();}
   assign_index = -1;
}
void assign_str( char* s , int i) {
    if (i == -1) {return;}
    if ( symbolTable[i].dataType != "string" && symbolTable[i].type == "func" )
    {printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: Function %s return type is %s but assigned string !!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );
     return ;} 
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "string"){symbolTable[i].strValue= s ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned string value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
    if(is_changed == 1) {st_log();}
    assign_index = -1;
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
    assign_index = -1;
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
                        assign_index = -1;
                        return;
                    }
                }
                printf("\n !!!!!!!!!!!! Error at line %d: %s not exist as key for %s enum  !!!!!!!!!!!\n", line_number, key ,enum_name );
                assign_index = -1;
                return;
            }
        }
    }
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned enum value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
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
    if (strcmp(symbolTable[func_index].type, "func") == 0 && return_exist == 0 && strcmp(symbolTable[func_index].dataType, "void") != 0)
    {printf("\n !!!!!!!!!!!! Error at line %d: Missing return statement in Function %s !!!!!!!!!!!\n", line_number, symbolTable[func_index].name);}
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
