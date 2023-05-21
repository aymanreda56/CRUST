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
    struct Entry {
        int id,intValue,scope;
        char* name , value;
        float floatValue;
        bool boolValue;
        char* strValue; 
        char* type; // var,const, func
        char* dataType; // int, float, bool, string (for func: return type)
        // list of arguments stored as IDs of them symbol table
        int argList[100];
        int argCount;
        int declareLine;
        int isConst, isArg, isUsed, isInit, outOfScope;
    };
    struct Entry symbolTable[500]; //TODO: need to be dynamic?
    int st_index=0;
    int in_loop=0;
    int assign_index=-1;
    int is_param=0;
    int arg_count=0;
    int called_func_index=0;
    //-- symbol table functions:  st_functionName()
    void st_insert(char* data_type, char* name, char* type, int is_arg);
    void st_print();
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
    void arg_count_check( int i);



//_____________________________ CODE GEN _________________________
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
//================================================================


#line 187 "parser.tab.c"

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
  YYSYMBOL_ENUM_CALL_STT = 56,             /* ENUM_CALL_STT  */
  YYSYMBOL_SWITCH_STT = 57,                /* SWITCH_STT  */
  YYSYMBOL_CASES = 58,                     /* CASES  */
  YYSYMBOL_ERRONOUS_CASES = 59,            /* ERRONOUS_CASES  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_61_7 = 61,                      /* $@7  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 62,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_63_8 = 63,                      /* $@8  */
  YYSYMBOL_64_9 = 64,                      /* $@9  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_66_11 = 66,                     /* $@11  */
  YYSYMBOL_FUNC_DECLARATION_STT = 67,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_68_12 = 68,                     /* $@12  */
  YYSYMBOL_69_13 = 69,                     /* $@13  */
  YYSYMBOL_70_14 = 70,                     /* $@14  */
  YYSYMBOL_71_15 = 71,                     /* $@15  */
  YYSYMBOL_72_16 = 72,                     /* $@16  */
  YYSYMBOL_73_17 = 73,                     /* $@17  */
  YYSYMBOL_74_18 = 74,                     /* $@18  */
  YYSYMBOL_75_19 = 75,                     /* $@19  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 76, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_77_20 = 77,                     /* $@20  */
  YYSYMBOL_ARGS = 78,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 79,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 80,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 81,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_HELPER = 82,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 83,                 /* ENUM_ARGS  */
  YYSYMBOL_84_21 = 84,                     /* $@21  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 85,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_86_22 = 86,                     /* $@22  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 87, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_IF_STT_HELPER = 88,             /* IF_STT_HELPER  */
  YYSYMBOL_89_23 = 89,                     /* $@23  */
  YYSYMBOL_IF_STT_HELPER1 = 90,            /* IF_STT_HELPER1  */
  YYSYMBOL_IF_STT = 91,                    /* IF_STT  */
  YYSYMBOL_92_24 = 92,                     /* $@24  */
  YYSYMBOL_93_25 = 93,                     /* $@25  */
  YYSYMBOL_WHILE_STT = 94,                 /* WHILE_STT  */
  YYSYMBOL_95_26 = 95,                     /* $@26  */
  YYSYMBOL_96_27 = 96,                     /* $@27  */
  YYSYMBOL_DO_WHILE_STT = 97,              /* DO_WHILE_STT  */
  YYSYMBOL_ERRONOUS_DO_WHILE = 98,         /* ERRONOUS_DO_WHILE  */
  YYSYMBOL_99_28 = 99,                     /* $@28  */
  YYSYMBOL_100_29 = 100,                   /* $@29  */
  YYSYMBOL_101_30 = 101,                   /* $@30  */
  YYSYMBOL_102_31 = 102,                   /* $@31  */
  YYSYMBOL_FOR_STT = 103,                  /* FOR_STT  */
  YYSYMBOL_104_32 = 104,                   /* $@32  */
  YYSYMBOL_105_33 = 105,                   /* $@33  */
  YYSYMBOL_106_34 = 106,                   /* $@34  */
  YYSYMBOL_107_35 = 107,                   /* $@35  */
  YYSYMBOL_ERRONOUS_FOR_LOOP = 108,        /* ERRONOUS_FOR_LOOP  */
  YYSYMBOL_109_36 = 109,                   /* $@36  */
  YYSYMBOL_110_37 = 110,                   /* $@37  */
  YYSYMBOL_helperAssignmentRule = 111,     /* helperAssignmentRule  */
  YYSYMBOL_assignmentSTT = 112,            /* assignmentSTT  */
  YYSYMBOL_113_38 = 113,                   /* $@38  */
  YYSYMBOL_BLOCK = 114,                    /* BLOCK  */
  YYSYMBOL_115_39 = 115,                   /* $@39  */
  YYSYMBOL_116_40 = 116,                   /* $@40  */
  YYSYMBOL_FUNC_CALL = 117,                /* FUNC_CALL  */
  YYSYMBOL_118_41 = 118,                   /* $@41  */
  YYSYMBOL_119_42 = 119,                   /* $@42  */
  YYSYMBOL_120_43 = 120,                   /* $@43  */
  YYSYMBOL_USED_ARGS = 121,                /* USED_ARGS  */
  YYSYMBOL_122_44 = 122,                   /* $@44  */
  YYSYMBOL_EXPRESSION = 123,               /* EXPRESSION  */
  YYSYMBOL_124_45 = 124,                   /* $@45  */
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
#define YYLAST   1092

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  378

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
       0,   165,   165,   166,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     193,   194,   195,   196,   200,   200,   201,   201,   202,   203,
     204,   209,   210,   211,   212,   213,   213,   214,   214,   215,
     215,   222,   223,   228,   229,   234,   235,   240,   241,   242,
     246,   246,   247,   247,   251,   251,   252,   252,   253,   253,
     254,   254,   267,   268,   268,   268,   269,   269,   269,   270,
     270,   270,   271,   271,   271,   276,   276,   286,   287,   288,
     291,   294,   304,   305,   307,   307,   309,   309,   310,   313,
     313,   314,   315,   316,   317,   318,   321,   322,   324,   329,
     329,   332,   336,   337,   338,   339,   339,   340,   340,   341,
     350,   350,   350,   359,   360,   363,   363,   364,   364,   365,
     365,   366,   366,   367,   374,   374,   374,   374,   374,   375,
     379,   379,   380,   380,   387,   391,   392,   393,   393,   398,
     398,   398,   406,   406,   406,   406,   407,   411,   411,   412,
     413,   414,   420,   421,   422,   423,   424,   425,   427,   428,
     429,   429,   430,   430,   431,   431,   432,   432,   435,   435,
     436,   437,   438,   439,   448,   450,   451,   452,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496
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
  "RETURN_STT", "ENUM_CALL_STT", "SWITCH_STT", "CASES", "ERRONOUS_CASES",
  "$@6", "$@7", "ERRONOUS_SWITCH_STT", "$@8", "$@9", "$@10", "$@11",
  "FUNC_DECLARATION_STT", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "$@19", "ERRONOUS_FUNC_DECLARATION_STT", "$@20", "ARGS",
  "ERRONOUS_ARGS", "ARG_DECL", "ENUM_DECLARATION_STT", "ENUM_HELPER",
  "ENUM_ARGS", "$@21", "ENUM_DEFINED_ARGS", "$@22",
  "ERRONOUS_ENUM_DECLARATION_STT", "IF_STT_HELPER", "$@23",
  "IF_STT_HELPER1", "IF_STT", "$@24", "$@25", "WHILE_STT", "$@26", "$@27",
  "DO_WHILE_STT", "ERRONOUS_DO_WHILE", "$@28", "$@29", "$@30", "$@31",
  "FOR_STT", "$@32", "$@33", "$@34", "$@35", "ERRONOUS_FOR_LOOP", "$@36",
  "$@37", "helperAssignmentRule", "assignmentSTT", "$@38", "BLOCK", "$@39",
  "$@40", "FUNC_CALL", "$@41", "$@42", "$@43", "USED_ARGS", "$@44",
  "EXPRESSION", "$@45", "$@46", "$@47", "$@48", "$@49",
  "ERRONOUS_EXPRESSION", "COMPARISONSTT", "ERRONOUS_COMPARISONSTT",
  "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-249)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-153)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -249,   184,  -249,   636,  -249,  -249,  -249,  -249,    37,    -8,
       8,  -249,  -249,  -249,  -249,    26,    15,    55,    52,   105,
    -249,   267,  -249,  -249,   465,  -249,    63,  -249,    65,  -249,
    -249,  -249,  -249,    64,  -249,  -249,    69,  -249,  -249,  -249,
    -249,  -249,  -249,   295,  -249,  -249,  -249,   899,  -249,  -249,
    -249,   465,   134,   299,  -249,   465,   465,    89,   465,   465,
     465,   465,   465,    91,  -249,  -249,    81,  -249,   465,   399,
      74,   465,    95,     7,    82,   -31,  1025,   357,   983,  -249,
      22,    98,   333,   103,  -249,   115,   102,  -249,   715,  -249,
      67,  -249,  -249,    32,   124,    64,  -249,   920,  -249,   426,
     437,  -249,   135,   133,  -249,  -249,   483,   501,   512,   529,
     123,   465,   123,   465,   143,   403,    12,  -249,   333,   333,
     333,  1046,  1046,  -249,   122,    64,   983,   399,   399,   399,
     983,   153,   138,  -249,    14,   127,    -3,    99,   139,  -249,
    -249,   103,   132,   141,    33,  -249,   465,   144,  -249,  -249,
     237,  -249,   113,   164,   142,   113,    16,   148,  -249,    76,
    -249,  -249,   465,    98,   540,   123,   187,   557,   143,  -249,
     465,  -249,   465,   465,   465,  1070,   333,  1070,   333,  1058,
    1046,  1058,  1046,   123,   123,    16,   159,  -249,   399,   399,
    -249,   162,   166,   193,   170,  -249,   465,   465,   174,   195,
     172,   178,   185,  -249,   189,   182,   190,  -249,    35,   941,
     208,   454,  -249,   465,   568,  -249,  -249,  -249,    16,   196,
    -249,    16,   199,   197,  -249,   209,  -249,   201,  -249,   123,
      98,   123,   187,   123,   403,   152,    12,   333,   198,  -249,
     213,   399,   399,    64,   465,   212,   465,   465,   876,   738,
    -249,   214,  -249,  -249,   217,  -249,   224,  -249,  -249,    35,
     223,    35,    35,   465,   465,   226,  -249,  -249,  -249,   593,
    -249,   761,  -249,   962,  1004,   664,   228,  -249,  -249,  -249,
    -249,    16,  -249,  -249,    64,  -249,   238,  -249,  -249,   784,
     465,   807,   830,  -249,  -249,  -249,   245,   227,  -249,   250,
      35,   252,   253,   983,   614,  -249,   454,   254,   255,  -249,
    -249,  -249,   266,   268,   701,  -249,    64,  -249,    64,  -249,
      64,  -249,   399,  -249,   853,  -249,  -249,   274,  -249,   275,
    -249,  -249,   272,    78,  -249,  -249,   454,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,    64,  -249,  -249,  -249,    64,   278,
    -249,   306,  -249,  -249,    64,  -249,    35,  -249,  -249,  -249,
    -249,    35,    35,  -249,    64,  -249,  -249,  -249
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    20,    21,    22,    23,     0,    99,
       0,   110,   155,   156,   157,     0,     0,     0,     0,     0,
     153,     0,   154,   139,     0,     2,     0,     4,     0,    14,
      12,    46,     5,     0,    13,    83,   105,     8,     9,    11,
     114,    10,   129,     0,     6,    15,   171,     0,   173,   170,
     187,     0,     0,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,     0,   107,     0,     0,
     124,     0,   115,     0,     0,     0,     0,     0,    42,    54,
       0,   196,   186,   137,   134,     0,     0,     3,     0,    26,
      75,    16,    62,     0,   102,     0,   135,     0,   166,     0,
       0,     7,   160,   162,   164,   168,     0,     0,     0,     0,
     176,     0,   188,     0,   190,   174,   175,    29,   177,   192,
     194,   197,   199,    28,    66,     0,   100,     0,     0,     0,
     111,     0,     0,   119,     0,     0,    86,     0,     0,    84,
      85,     0,     0,    56,     0,   146,     0,     0,    44,   143,
       0,   172,     0,     0,    63,     0,     0,     0,   101,     0,
     106,   136,     0,   189,     0,   178,   191,     0,   179,   158,
       0,   159,     0,     0,     0,   193,   182,   195,   183,   198,
     184,   200,   185,   203,   201,     0,     0,   108,     0,     0,
     125,     0,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,    60,     0,     0,
       0,     0,   140,     0,     0,    34,    27,    30,     0,     0,
      25,     0,     0,     0,    79,    78,   109,     0,   103,   167,
     204,   181,   202,   180,   161,   163,   165,   169,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,    95,    94,    89,    93,     0,    98,    82,     0,
       0,     0,     0,     0,     0,     0,    48,   138,    43,     0,
     144,   147,   141,     0,     0,    39,     0,    70,    80,    81,
      76,     0,   104,    67,     0,   130,     0,   126,   112,     0,
       0,     0,     0,   123,   113,    92,     0,    86,    87,     0,
       0,     0,     0,    50,     0,    45,     0,     0,     0,    32,
      33,    31,     0,     0,     0,    64,     0,    77,     0,    74,
       0,   132,     0,   116,     0,   120,   118,     0,    55,     0,
      59,    61,     0,     0,   149,   145,     0,    36,    38,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    40,     0,    71,    68,   131,     0,     0,
     122,     0,    90,    57,     0,    52,     0,   148,    65,   133,
     127,     0,     0,    47,     0,    51,    53,   128
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -249,   236,   -68,  -154,  -249,  -249,  -249,   169,  -249,  -249,
    -249,  -249,  -249,  -249,  -248,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -178,  -249,  -249,  -249,  -107,    70,
    -249,    -2,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
     -15,  -249,  -249,  -249,  -249,  -249,  -249,  -232,  -249,   -14,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    25,    26,    27,   155,   152,   216,   312,   313,
     314,    28,    29,    30,   265,   266,   332,   372,    31,   142,
     205,   206,   262,    32,   218,   354,   185,   318,   219,   316,
     186,   284,    33,   156,   223,   224,   225,    34,   138,   139,
     200,   140,   296,    35,    36,    68,    94,    37,    95,   125,
      38,    71,   191,    39,    40,   131,   247,   194,   132,    41,
     129,   242,   322,   374,    42,   320,   358,    43,    44,   146,
      45,    87,   272,    46,    86,   211,   307,   270,   308,    47,
     170,   172,   173,   162,   174,    48,    49,    50,   353
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,   127,   222,    78,   136,    82,   137,   238,   133,    69,
      88,   299,   199,   301,   302,   195,    74,   134,    92,     4,
       5,     6,     7,   143,    98,    99,   100,    72,   198,    97,
     202,   222,    67,   157,   207,   -88,   263,   110,   112,   114,
     276,   115,   116,   278,   118,   119,   120,   121,   122,    70,
      75,   196,   329,    79,   126,   197,    76,   130,   221,   188,
     189,   190,   144,    23,   222,   264,    12,   222,   -24,    23,
     208,   -41,    66,   -49,   334,    13,    14,   227,   158,   365,
     160,    91,   -24,   -24,    89,   165,   168,    80,    19,    20,
      77,    22,   176,   178,   180,   182,    24,   183,    90,   184,
     201,    23,   153,   317,   367,   117,    81,   123,   154,    93,
     187,    52,    53,    23,   213,    23,    12,   128,   373,   135,
     240,   241,   124,   375,   376,    13,    14,   222,   214,   215,
     147,   148,   209,  -121,   136,    76,    99,   100,    19,    20,
      77,    22,   145,   149,   228,    12,    24,   159,   229,   111,
     231,   171,   169,   233,    13,    14,   234,   100,   235,   236,
     237,   -72,   136,   192,    98,    99,   100,    19,    20,    77,
      22,   104,   204,   286,   287,    24,   193,   203,   -58,   210,
     217,   -69,   248,   249,     2,     3,   226,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   251,   271,   239,   273,
     275,    53,   243,   245,    13,    14,   252,   244,    15,    16,
      17,   246,   250,    18,   256,   253,   257,    19,    20,    21,
      22,    23,   260,   258,   268,    24,   259,   261,   288,   254,
     289,   255,   291,   292,   279,   277,   280,   283,     3,   282,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   303,
     304,   281,   285,   290,   359,   -91,   295,    13,    14,   297,
     300,    15,    16,    17,   305,   -88,    18,   315,    83,   319,
      19,    20,    21,    22,    23,   212,   324,   321,    24,  -152,
    -152,  -152,    84,  -152,  -152,  -152,  -152,   327,   328,  -152,
     330,   331,   271,   335,  -152,  -152,    76,   336,  -152,  -152,
      76,   355,    85,   356,   337,   357,    12,   338,  -142,   361,
      12,    96,   364,   363,   113,    13,    14,   370,   366,    13,
      14,   199,   271,   150,   220,   362,   298,     0,    19,    20,
      77,    22,    19,    20,    77,    22,    24,     0,     0,   368,
      24,     0,     0,   369,     0,    98,    99,   100,     0,   371,
     102,   103,   104,     0,     0,   105,     0,     0,   141,   377,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,     0,  -152,
    -152,  -152,     0,  -152,  -152,  -152,  -152,     0,  -152,  -152,
    -152,  -152,  -152,     0,  -152,  -152,  -152,  -152,  -152,  -152,
       0,     0,     0,     0,  -152,  -152,  -152,  -152,  -142,  -152,
       3,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,    98,    99,   100,     0,    13,
      14,   103,   104,    15,    16,    17,     0,   163,    18,     0,
       0,     0,    19,    20,    21,    22,    23,    12,   166,     0,
      24,   164,     0,     0,     0,     0,    13,    14,    12,     0,
       0,     0,   167,     0,     0,   269,     0,    13,    14,    19,
      20,    77,    22,     0,     0,    12,    76,    24,     0,     0,
      19,    20,    77,    22,    13,    14,    12,     0,    24,     0,
       0,     0,     0,     0,   175,    13,    14,    19,    20,    77,
      22,     0,     0,  -151,    12,    24,     0,     0,    19,    20,
      77,    22,   177,    13,    14,     0,    24,     0,     0,     0,
       0,     0,    12,   179,     0,     0,    19,    20,    77,    22,
       0,    13,    14,    12,    24,     0,     0,     0,     0,     0,
     181,     0,    13,    14,    19,    20,    77,    22,     0,     0,
      12,   230,    24,     0,     0,    19,    20,    77,    22,    13,
      14,    12,     0,    24,     0,     0,     0,     0,   232,     0,
      13,    14,    19,    20,    77,    22,     0,     0,    12,   274,
      24,     0,     0,    19,    20,    77,    22,    13,    14,    12,
       0,    24,     0,     0,     0,     0,     0,     0,    13,    14,
      19,    20,    77,    22,     0,     0,     0,     0,    24,     0,
       0,    19,    20,    77,    22,    51,    52,    53,     0,    24,
      55,     0,    56,     0,     0,    58,     0,     0,     0,     0,
      59,    60,     0,     0,    61,    62,    98,    99,   100,     0,
       0,   102,   103,   104,     0,   306,   105,     0,     0,     0,
       0,   106,   107,     0,     0,   108,   109,     0,    51,    52,
      53,     0,    54,    55,   333,    56,     0,    57,    58,     0,
       0,     0,     0,    59,    60,     0,     0,    61,    62,     0,
       0,    63,     0,     0,    64,    65,    98,    99,   100,     0,
     311,   102,   103,   104,     0,     0,   105,     0,     0,     0,
       0,   106,   107,     0,     0,   108,   109,     0,     0,     0,
       0,     0,   -35,   -37,   339,   340,   341,   342,   343,   344,
     345,   346,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   347,     0,   348,   349,   350,    98,    99,   100,
     351,   352,   102,   103,   104,     0,     0,   105,     0,     0,
       0,     0,   106,   107,     0,     0,   108,   109,     0,     0,
      98,    99,   100,     0,   151,   102,   103,   104,     0,     0,
     105,     0,     0,     0,     0,   106,   107,     0,     0,   108,
     109,     0,     0,    98,    99,   100,     0,   294,   102,   103,
     104,     0,     0,   105,     0,     0,     0,     0,   106,   107,
       0,     0,   108,   109,     0,     0,    98,    99,   100,     0,
    -150,   102,   103,   104,     0,     0,   105,     0,     0,     0,
       0,   106,   107,     0,     0,   108,   109,     0,     0,    98,
      99,   100,     0,   323,   102,   103,   104,     0,     0,   105,
       0,     0,     0,     0,   106,   107,     0,     0,   108,   109,
       0,     0,    98,    99,   100,     0,   325,   102,   103,   104,
       0,     0,   105,     0,     0,     0,     0,   106,   107,     0,
       0,   108,   109,     0,     0,    98,    99,   100,     0,   326,
     102,   103,   104,     0,     0,   105,     0,     0,     0,     0,
     106,   107,     0,     0,   108,   109,     0,     0,    98,    99,
     100,     0,   360,   102,   103,   104,     0,     0,   105,     0,
       0,     0,     0,   106,   107,     0,     0,   108,   109,     0,
       0,    98,    99,   100,   293,   101,   102,   103,   104,     0,
       0,   105,     0,     0,     0,     0,   106,   107,     0,     0,
     108,   109,    98,    99,   100,     0,   161,   102,   103,   104,
       0,     0,   105,     0,     0,     0,     0,   106,   107,     0,
       0,   108,   109,    98,    99,   100,     0,   267,   102,   103,
     104,     0,     0,   105,     0,     0,     0,     0,   106,   107,
       0,     0,   108,   109,    98,    99,   100,     0,   309,   102,
     103,   104,     0,     0,   105,     0,     0,     0,     0,   106,
     107,     0,     0,   108,   109,    98,    99,   100,     0,     0,
     102,   103,   104,     0,     0,   105,     0,     0,     0,     0,
     106,   107,     0,     0,   108,   109,    51,    52,    53,     0,
     310,    55,     0,    56,     0,     0,    58,     0,     0,     0,
       0,    59,    60,     0,     0,    61,    62,    51,    52,    53,
       0,     0,    55,     0,    56,     0,     0,    58,     0,     0,
       0,     0,    59,    60,     0,     0,    61,    62,    98,    99,
     100,     0,     0,   102,   103,   104,     0,     0,   105,     0,
      51,    52,    53,   106,   107,    55,     0,    56,     0,     0,
      58,     0,    51,    52,    53,    59,    60,    55,     0,    56,
       0,     0,    58
};

static const yytype_int16 yycheck[] =
{
      15,    69,   156,    17,    35,    19,    37,   185,     1,     1,
      24,   259,    15,   261,   262,     1,     1,    10,    33,     3,
       4,     5,     6,     1,    12,    13,    14,     1,   135,    43,
     137,   185,    40,     1,     1,    38,     1,    51,    52,    53,
     218,    55,    56,   221,    58,    59,    60,    61,    62,    41,
      35,    37,   300,     1,    68,    41,     1,    71,    42,   127,
     128,   129,    40,    37,   218,    30,    11,   221,     1,    37,
      37,    16,    35,    38,   306,    20,    21,     1,    93,     1,
      95,    16,    15,    16,    21,    99,   100,    35,    33,    34,
      35,    36,   106,   107,   108,   109,    41,   111,    35,   113,
       1,    37,    35,   281,   336,    16,     1,    16,    41,    40,
     125,    13,    14,    37,     1,    37,    11,    43,   366,    37,
     188,   189,    41,   371,   372,    20,    21,   281,    15,    16,
      15,    16,   146,    38,    35,     1,    13,    14,    33,    34,
      35,    36,    39,    41,   159,    11,    41,    23,   162,    15,
     164,    18,    17,   167,    20,    21,   170,    14,   172,   173,
     174,    39,    35,    10,    12,    13,    14,    33,    34,    35,
      36,    19,    40,   241,   242,    41,    38,    38,    37,    35,
      16,    39,   196,   197,     0,     1,    38,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     1,   211,    39,   213,
     214,    14,    40,    10,    20,    21,    11,    41,    24,    25,
      26,    41,    38,    29,    42,    20,    38,    33,    34,    35,
      36,    37,    40,    38,    16,    41,    37,    37,   243,    34,
     244,    36,   246,   247,    35,    39,    39,    39,     1,    38,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   263,
     264,    42,    39,    41,   322,    38,    42,    20,    21,    35,
      37,    24,    25,    26,    38,    38,    29,    39,     1,   284,
      33,    34,    35,    36,    37,    38,   290,    39,    41,    12,
      13,    14,    15,    16,    17,    18,    19,    42,    38,    22,
      38,    38,   306,    39,    27,    28,     1,    42,    31,    32,
       1,   316,    35,   318,    38,   320,    11,    39,    41,    35,
      11,    16,    40,    38,    15,    20,    21,    39,   333,    20,
      21,    15,   336,    87,   155,   327,   256,    -1,    33,    34,
      35,    36,    33,    34,    35,    36,    41,    -1,    -1,   354,
      41,    -1,    -1,   358,    -1,    12,    13,    14,    -1,   364,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,     1,   374,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    20,
      21,    18,    19,    24,    25,    26,    -1,     1,    29,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    11,     1,    -1,
      41,    15,    -1,    -1,    -1,    -1,    20,    21,    11,    -1,
      -1,    -1,    15,    -1,    -1,     1,    -1,    20,    21,    33,
      34,    35,    36,    -1,    -1,    11,     1,    41,    -1,    -1,
      33,    34,    35,    36,    20,    21,    11,    -1,    41,    -1,
      -1,    -1,    -1,    -1,     1,    20,    21,    33,    34,    35,
      36,    -1,    -1,    39,    11,    41,    -1,    -1,    33,    34,
      35,    36,     1,    20,    21,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    11,     1,    -1,    -1,    33,    34,    35,    36,
      -1,    20,    21,    11,    41,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    20,    21,    33,    34,    35,    36,    -1,    -1,
      11,     1,    41,    -1,    -1,    33,    34,    35,    36,    20,
      21,    11,    -1,    41,    -1,    -1,    -1,    -1,     1,    -1,
      20,    21,    33,    34,    35,    36,    -1,    -1,    11,     1,
      41,    -1,    -1,    33,    34,    35,    36,    20,    21,    11,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    33,    34,    35,    36,    12,    13,    14,    -1,    41,
      17,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    31,    32,    12,    13,    14,    -1,
      -1,    17,    18,    19,    -1,    42,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    31,    32,    -1,    12,    13,
      14,    -1,    16,    17,    40,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    32,    -1,
      -1,    35,    -1,    -1,    38,    39,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    39,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    23,    24,    25,    12,    13,    14,
      29,    30,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
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
      -1,    -1,    12,    13,    14,    -1,    39,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    32,    -1,    -1,    12,    13,    14,    -1,    39,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    31,    32,    -1,    -1,    12,    13,
      14,    -1,    39,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    32,    -1,
      -1,    12,    13,    14,    38,    16,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,
      31,    32,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    32,    12,    13,    14,    -1,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    31,    32,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    31,    32,    12,    13,    14,    -1,    -1,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    31,    32,    12,    13,    14,    -1,
      16,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    31,    32,    12,    13,    14,
      -1,    -1,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    31,    32,    12,    13,
      14,    -1,    -1,    17,    18,    19,    -1,    -1,    22,    -1,
      12,    13,    14,    27,    28,    17,    -1,    19,    -1,    -1,
      22,    -1,    12,    13,    14,    27,    28,    17,    -1,    19,
      -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    20,    21,    24,    25,    26,    29,    33,
      34,    35,    36,    37,    41,    46,    47,    48,    55,    56,
      57,    62,    67,    76,    81,    87,    88,    91,    94,    97,
      98,   103,   108,   111,   112,   114,   117,   123,   129,   130,
     131,    12,    13,    14,    16,    17,    19,    21,    22,    27,
      28,    31,    32,    35,    38,    39,    35,    40,    89,     1,
      41,    95,     1,   114,     1,    35,     1,    35,   123,     1,
      35,     1,   123,     1,    15,    35,   118,   115,   123,    21,
      35,    16,   114,    40,    90,    92,    16,   123,    12,    13,
      14,    16,    17,    18,    19,    22,    27,    28,    31,    32,
     123,    15,   123,    15,   123,   123,   123,    16,   123,   123,
     123,   123,   123,    16,    41,    93,   123,    46,    43,   104,
     123,    99,   102,     1,    10,    37,    35,    37,    82,    83,
      85,     1,    63,     1,    40,    39,   113,    15,    16,    41,
      45,    39,    50,    35,    41,    49,    77,     1,   114,    23,
     114,    16,   127,     1,    15,   123,     1,    15,   123,    17,
     124,    18,   125,   126,   128,     1,   123,     1,   123,     1,
     123,     1,   123,   123,   123,    70,    74,   114,    46,    46,
      46,    96,    10,    38,   101,     1,    37,    41,    82,    15,
      84,     1,    82,    38,    40,    64,    65,     1,    37,   123,
      35,   119,    38,     1,    15,    16,    51,    16,    68,    72,
      51,    42,    47,    78,    79,    80,    38,     1,   114,   123,
       1,   123,     1,   123,   123,   123,   123,   123,    78,    39,
      46,    46,   105,    40,    41,    10,    41,   100,   123,   123,
      38,     1,    11,    20,    34,    36,    42,    38,    38,    37,
      40,    37,    66,     1,    30,    58,    59,    16,    16,     1,
     121,   123,   116,   123,     1,   123,    78,    39,    78,    35,
      39,    42,    38,    39,    75,    39,    46,    46,   114,   123,
      41,   123,   123,    38,    39,    42,    86,    35,    83,    58,
      37,    58,    58,   123,   123,    38,    42,   120,   122,    16,
      16,    16,    52,    53,    54,    39,    73,    78,    71,   114,
     109,    39,   106,    39,   123,    39,    39,    42,    38,    58,
      38,    38,    60,    40,   121,    39,    42,    38,    39,     3,
       4,     5,     6,     7,     8,     9,    10,    21,    23,    24,
      25,    29,    30,   132,    69,   114,   114,   114,   110,    46,
      39,    35,    85,    38,    40,     1,   114,   121,   114,   114,
      39,   114,    61,    58,   107,    58,    58,   114
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    49,    48,    50,    48,    48,    48,
      48,    51,    51,    51,    51,    52,    51,    53,    51,    54,
      51,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      60,    59,    61,    59,    63,    62,    64,    62,    65,    62,
      66,    62,    67,    68,    69,    67,    70,    71,    67,    72,
      73,    67,    74,    75,    67,    77,    76,    78,    78,    78,
      79,    80,    81,    81,    82,    82,    84,    83,    83,    86,
      85,    85,    85,    85,    85,    85,    87,    87,    87,    89,
      88,    90,    91,    91,    91,    92,    91,    93,    91,    91,
      95,    96,    94,    97,    97,    99,    98,   100,    98,   101,
      98,   102,    98,    98,   104,   105,   106,   107,   103,   103,
     109,   108,   110,   108,   111,   112,   112,   113,   112,   115,
     116,   114,   118,   119,   120,   117,   117,   122,   121,   121,
     121,   121,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   123,   125,   123,   126,   123,   127,   123,   128,   123,
     123,   123,   123,   123,   129,   129,   129,   129,   130,   130,
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
       4,     1,     2,     5,     3,     6,     1,     5,     1,     0,
       0,     6,     0,     6,     0,     7,     0,     8,     0,     7,
       0,     7,     2,     0,     0,     8,     0,     0,     8,     0,
       0,     7,     0,     0,     7,     0,     5,     3,     1,     1,
       2,     2,     5,     1,     1,     1,     0,     4,     1,     0,
       6,     3,     4,     3,     3,     3,     5,     4,     5,     0,
       3,     2,     2,     4,     5,     0,     3,     0,     4,     4,
       0,     0,     6,     6,     1,     0,     7,     0,     7,     0,
       7,     0,     8,     6,     0,     0,     0,     0,    11,     1,
       0,     8,     0,     9,     2,     2,     3,     0,     5,     0,
       0,     5,     0,     0,     0,     7,     3,     0,     4,     3,
       1,     0,     1,     1,     1,     1,     1,     1,     3,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
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
#line 165 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1725 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 171 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1731 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 174 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1737 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 175 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1743 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 176 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1749 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 177 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1755 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 178 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1761 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 179 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1767 "parser.tab.c"
    break;

  case 14: /* STATEMENT: ENUM_CALL_STT  */
#line 180 "parser.y"
                                                            {printf("#[Parsed_Enum_USAGE]# ");}
#line 1773 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error SEMICOLON  */
#line 183 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1779 "parser.tab.c"
    break;

  case 18: /* STATEMENT: error '}'  */
#line 184 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1785 "parser.tab.c"
    break;

  case 19: /* STATEMENT: error ')'  */
#line 185 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1791 "parser.tab.c"
    break;

  case 20: /* TYPE: INT  */
#line 193 "parser.y"
                    { (yyval.str) = "int"; }
#line 1797 "parser.tab.c"
    break;

  case 21: /* TYPE: FLOAT  */
#line 194 "parser.y"
                        { (yyval.str) = "float"; }
#line 1803 "parser.tab.c"
    break;

  case 22: /* TYPE: BOOL  */
#line 195 "parser.y"
                        { (yyval.str) = "bool"; }
#line 1809 "parser.tab.c"
    break;

  case 23: /* TYPE: STRING  */
#line 196 "parser.y"
                         { (yyval.str) = "string"; }
#line 1815 "parser.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 200 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0); assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1821 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 200 "parser.y"
                                                                                                                                                   {printf("#[Parsed_Declaration]# "); }
#line 1827 "parser.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 201 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0);  assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1833 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 201 "parser.y"
                                                                                                                                                     {printf("#[Parsed_CONST_Declaration]# "); }
#line 1839 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 202 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1845 "parser.tab.c"
    break;

  case 29: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 203 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1851 "parser.tab.c"
    break;

  case 30: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 204 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);}
#line 1857 "parser.tab.c"
    break;

  case 31: /* DECLARATION_TAIL: EQ EXPRESSION SEMICOLON  */
#line 209 "parser.y"
                                         {StAssPush(strdup(IdentifierHolder)); StAssPrint("OVER", 1); StAssPrint("STORE", 1); StAssPrint("DROP", 1);}
#line 1863 "parser.tab.c"
    break;

  case 32: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 210 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1869 "parser.tab.c"
    break;

  case 33: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 211 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1875 "parser.tab.c"
    break;

  case 35: /* $@3: %empty  */
#line 213 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1881 "parser.tab.c"
    break;

  case 37: /* $@4: %empty  */
#line 214 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1887 "parser.tab.c"
    break;

  case 39: /* $@5: %empty  */
#line 215 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1893 "parser.tab.c"
    break;

  case 41: /* RETURN_STT: RETURN  */
#line 222 "parser.y"
                                                {int dum = 0;StAssPrint("POP\tPC",1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1899 "parser.tab.c"
    break;

  case 42: /* RETURN_STT: RETURN EXPRESSION  */
#line 223 "parser.y"
                                                {StAssPrint("OVER",1);int dum = 0;StAssPrint("POP\tPC",1);StAssPrint("DNEXT", 1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1905 "parser.tab.c"
    break;

  case 43: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER EQ IDENTIFIER SEMICOLON  */
#line 228 "parser.y"
                                                              {StAssPush((yyvsp[-3].str));StAssPush((yyvsp[-1].str));StAssPrint("STORE",1);}
#line 1911 "parser.tab.c"
    break;

  case 50: /* $@6: %empty  */
#line 246 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);}
#line 1917 "parser.tab.c"
    break;

  case 52: /* $@7: %empty  */
#line 247 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);}
#line 1923 "parser.tab.c"
    break;

  case 54: /* $@8: %empty  */
#line 251 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1929 "parser.tab.c"
    break;

  case 56: /* $@9: %empty  */
#line 252 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }
#line 1935 "parser.tab.c"
    break;

  case 58: /* $@10: %empty  */
#line 253 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1941 "parser.tab.c"
    break;

  case 60: /* $@11: %empty  */
#line 254 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1947 "parser.tab.c"
    break;

  case 63: /* $@12: %empty  */
#line 268 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 1953 "parser.tab.c"
    break;

  case 64: /* $@13: %empty  */
#line 268 "parser.y"
                                                                                                                    {st_insert((yyvsp[-5].str), (yyvsp[-4].str),"func",0); popArgs();}
#line 1959 "parser.tab.c"
    break;

  case 66: /* $@14: %empty  */
#line 269 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 1965 "parser.tab.c"
    break;

  case 67: /* $@15: %empty  */
#line 269 "parser.y"
                                                                                                                   {st_insert("void", (yyvsp[-4].str),"func",0); popArgs();}
#line 1971 "parser.tab.c"
    break;

  case 69: /* $@16: %empty  */
#line 270 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 1977 "parser.tab.c"
    break;

  case 70: /* $@17: %empty  */
#line 270 "parser.y"
                                                                                                                   {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1983 "parser.tab.c"
    break;

  case 72: /* $@18: %empty  */
#line 271 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 1989 "parser.tab.c"
    break;

  case 73: /* $@19: %empty  */
#line 271 "parser.y"
                                                                                                                   {st_insert("void", (yyvsp[-3].str),"func",0);}
#line 1995 "parser.tab.c"
    break;

  case 75: /* $@20: %empty  */
#line 276 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 2001 "parser.tab.c"
    break;

  case 76: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@20 ARGS ')'  */
#line 276 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2007 "parser.tab.c"
    break;

  case 80: /* ERRONOUS_ARGS: ',' ARGS  */
#line 291 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
#line 2013 "parser.tab.c"
    break;

  case 81: /* ARG_DECL: TYPE IDENTIFIER  */
#line 294 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1); char* buf=(yyvsp[0].str); argumentList[argPointer]=buf;argPointer++;}
#line 2019 "parser.tab.c"
    break;

  case 82: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_HELPER '}'  */
#line 304 "parser.y"
                                                              { st_insert("enum" , (yyvsp[-3].str), "var" , 0); enumCNT=1;}
#line 2025 "parser.tab.c"
    break;

  case 86: /* $@21: %empty  */
#line 309 "parser.y"
                           {StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);}
#line 2031 "parser.tab.c"
    break;

  case 88: /* ENUM_ARGS: IDENTIFIER  */
#line 310 "parser.y"
                             {StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10);prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);}
#line 2037 "parser.tab.c"
    break;

  case 89: /* $@22: %empty  */
#line 313 "parser.y"
                                    {StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1);}
#line 2043 "parser.tab.c"
    break;

  case 91: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ DIGIT  */
#line 314 "parser.y"
                                     {StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1);}
#line 2049 "parser.tab.c"
    break;

  case 92: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ error ','  */
#line 315 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2055 "parser.tab.c"
    break;

  case 93: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ FLOAT_DIGIT  */
#line 316 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2061 "parser.tab.c"
    break;

  case 94: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ STRING_LITERAL  */
#line 317 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2067 "parser.tab.c"
    break;

  case 95: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ BOOL_LITERAL  */
#line 318 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2073 "parser.tab.c"
    break;

  case 96: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 321 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);}
#line 2079 "parser.tab.c"
    break;

  case 97: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 322 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);}
#line 2085 "parser.tab.c"
    break;

  case 98: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 324 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2091 "parser.tab.c"
    break;

  case 99: /* $@23: %empty  */
#line 329 "parser.y"
                   {printIF();}
#line 2097 "parser.tab.c"
    break;

  case 100: /* IF_STT_HELPER: IF $@23 EXPRESSION  */
#line 329 "parser.y"
                                          {StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2103 "parser.tab.c"
    break;

  case 101: /* IF_STT_HELPER1: ':' BLOCK  */
#line 332 "parser.y"
                          {controlTerminator(0);  StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2109 "parser.tab.c"
    break;

  case 102: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1  */
#line 336 "parser.y"
                                             {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2115 "parser.tab.c"
    break;

  case 103: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE BLOCK  */
#line 337 "parser.y"
                                                          {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2121 "parser.tab.c"
    break;

  case 104: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE error '}'  */
#line 338 "parser.y"
                                                                   {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);}
#line 2127 "parser.tab.c"
    break;

  case 105: /* $@24: %empty  */
#line 339 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 2133 "parser.tab.c"
    break;

  case 106: /* IF_STT: IF_STT_HELPER $@24 BLOCK  */
#line 339 "parser.y"
                                                                                                                                                                      {char*dummy; strcpy(dummy, makeEndLabel()); printLLVM(dummy); printLLVM(":\n");}
#line 2139 "parser.tab.c"
    break;

  case 107: /* $@25: %empty  */
#line 340 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);}
#line 2145 "parser.tab.c"
    break;

  case 108: /* IF_STT: IF ':' $@25 BLOCK  */
#line 340 "parser.y"
                                                                                                                                                                      {char*dummy; strcpy(dummy, makeEndLabel()); printLLVM(dummy); printLLVM(":\n");}
#line 2151 "parser.tab.c"
    break;

  case 109: /* IF_STT: IF_STT_HELPER ':' error '}'  */
#line 341 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);}
#line 2157 "parser.tab.c"
    break;

  case 110: /* $@26: %empty  */
#line 350 "parser.y"
                      {printWHILE(); StAssPrintLBL(1, 0);}
#line 2163 "parser.tab.c"
    break;

  case 111: /* $@27: %empty  */
#line 350 "parser.y"
                                                                      {StAssJmp("JNZ", "END",&SMLabel_End, 0,0);}
#line 2169 "parser.tab.c"
    break;

  case 112: /* WHILE_STT: WHILE $@26 EXPRESSION $@27 ':' BLOCK  */
#line 350 "parser.y"
                                                                                                                            {StAssJmp("JMP", "LBL",&SMLabel_Else, 1,0); StAssPrintLBL(0, 1);}
#line 2175 "parser.tab.c"
    break;

  case 115: /* $@28: %empty  */
#line 363 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2181 "parser.tab.c"
    break;

  case 117: /* $@29: %empty  */
#line 364 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2187 "parser.tab.c"
    break;

  case 119: /* $@30: %empty  */
#line 365 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);}
#line 2193 "parser.tab.c"
    break;

  case 121: /* $@31: %empty  */
#line 366 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);}
#line 2199 "parser.tab.c"
    break;

  case 123: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 367 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);}
#line 2205 "parser.tab.c"
    break;

  case 124: /* $@32: %empty  */
#line 374 "parser.y"
                        {in_loop = 1;}
#line 2211 "parser.tab.c"
    break;

  case 125: /* $@33: %empty  */
#line 374 "parser.y"
                                                 {StAssForHeader();}
#line 2217 "parser.tab.c"
    break;

  case 126: /* $@34: %empty  */
#line 374 "parser.y"
                                                                               {StAssForMiddle();}
#line 2223 "parser.tab.c"
    break;

  case 127: /* $@35: %empty  */
#line 374 "parser.y"
                                                                                                                {StAssPrintLBL(1,1); in_loop = 0;}
#line 2229 "parser.tab.c"
    break;

  case 128: /* FOR_STT: FOR '(' $@32 STATEMENT $@33 STATEMENT $@34 STATEMENT ')' $@35 BLOCK  */
#line 374 "parser.y"
                                                                                                                                                          {StAssJmp("JMP", "Label", &ForHeaderLabel,1,0); StAssPrintLBL(0,1);}
#line 2235 "parser.tab.c"
    break;

  case 130: /* $@36: %empty  */
#line 379 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);}
#line 2241 "parser.tab.c"
    break;

  case 132: /* $@37: %empty  */
#line 380 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);}
#line 2247 "parser.tab.c"
    break;

  case 134: /* helperAssignmentRule: IDENTIFIER EQ  */
#line 387 "parser.y"
                                {pushVStack((yyvsp[-1].str)); StAssPush((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str));}
#line 2253 "parser.tab.c"
    break;

  case 135: /* assignmentSTT: helperAssignmentRule SEMICOLON  */
#line 391 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);}
#line 2259 "parser.tab.c"
    break;

  case 136: /* assignmentSTT: helperAssignmentRule EXPRESSION SEMICOLON  */
#line 392 "parser.y"
                                                                     {StAssPrint("STORE", 1); CodeGenAss();printf("#[Parsed_Assignment]# ");}
#line 2265 "parser.tab.c"
    break;

  case 137: /* $@38: %empty  */
#line 393 "parser.y"
                                   {pushVStack((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str)); StAssPush((yyvsp[-1].str));}
#line 2271 "parser.tab.c"
    break;

  case 138: /* assignmentSTT: IDENTIFIER error $@38 EXPRESSION SEMICOLON  */
#line 393 "parser.y"
                                                                                                                        {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);}
#line 2277 "parser.tab.c"
    break;

  case 139: /* $@39: %empty  */
#line 398 "parser.y"
                    {scope_start();}
#line 2283 "parser.tab.c"
    break;

  case 140: /* $@40: %empty  */
#line 398 "parser.y"
                                                 {scope_end();}
#line 2289 "parser.tab.c"
    break;

  case 141: /* BLOCK: '{' $@39 PROGRAM '}' $@40  */
#line 398 "parser.y"
                                                                                    {printf("#[Parsed_Block]# ");}
#line 2295 "parser.tab.c"
    break;

  case 142: /* $@41: %empty  */
#line 406 "parser.y"
                           {called_func_index = lookup((yyvsp[0].str)); check_type(called_func_index); StAssPush("PC");}
#line 2301 "parser.tab.c"
    break;

  case 143: /* $@42: %empty  */
#line 406 "parser.y"
                                                                                                                 { is_param =1;}
#line 2307 "parser.tab.c"
    break;

  case 144: /* $@43: %empty  */
#line 406 "parser.y"
                                                                                                                                            { is_param =0; arg_count_check(called_func_index); arg_count=0; int dum=0; StAssJmp("JMP", (yyvsp[-4].str),&dum, 0,0);}
#line 2313 "parser.tab.c"
    break;

  case 145: /* FUNC_CALL: IDENTIFIER $@41 '(' $@42 USED_ARGS $@43 ')'  */
#line 406 "parser.y"
                                                                                                                                                                                                                                                             { printf("#[Parsed_Func_Call]# ");}
#line 2319 "parser.tab.c"
    break;

  case 146: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 407 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 2325 "parser.tab.c"
    break;

  case 147: /* $@44: %empty  */
#line 411 "parser.y"
                           { arg_count++; }
#line 2331 "parser.tab.c"
    break;

  case 149: /* USED_ARGS: error ',' USED_ARGS  */
#line 412 "parser.y"
                                                        {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 2337 "parser.tab.c"
    break;

  case 150: /* USED_ARGS: EXPRESSION  */
#line 413 "parser.y"
                             {arg_count++ ;}
#line 2343 "parser.tab.c"
    break;

  case 152: /* EXPRESSION: IDENTIFIER  */
#line 420 "parser.y"
                            { int i = lookup((yyvsp[0].str)); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2349 "parser.tab.c"
    break;

  case 153: /* EXPRESSION: DIGIT  */
#line 421 "parser.y"
                        { assign_int((yyvsp[0].num), assign_index) ; char numtostring[40]; itoa((yyvsp[0].num), numtostring, 10); pushVStack(numtostring); char dum[10]="$"; StAssPush(strcat(dum,numtostring));}
#line 2355 "parser.tab.c"
    break;

  case 154: /* EXPRESSION: FLOAT_DIGIT  */
#line 422 "parser.y"
                              { assign_float((yyvsp[0].float_val), assign_index); char floattostring[40]; gcvt((yyvsp[0].float_val), 6, floattostring); pushVStack(floattostring); char dum[10]="$"; StAssPush(strcat(dum,floattostring));}
#line 2361 "parser.tab.c"
    break;

  case 155: /* EXPRESSION: BOOL_LITERAL  */
#line 423 "parser.y"
                                { assign_bool((yyvsp[0].bool_val), assign_index); if((yyvsp[0].bool_val)==true){pushVStack("true");StAssPush("$true");}else{pushVStack("false");StAssPush("$false");} }
#line 2367 "parser.tab.c"
    break;

  case 156: /* EXPRESSION: STRING_LITERAL  */
#line 424 "parser.y"
                                  {  assign_str((yyvsp[0].str), assign_index); pushVStack((yyvsp[0].str));StAssPush(strcat("$",strdup((yyvsp[0].str))));}
#line 2373 "parser.tab.c"
    break;

  case 157: /* EXPRESSION: CONSTANT  */
#line 425 "parser.y"
                           { int i = lookup((yyvsp[0].str)); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2379 "parser.tab.c"
    break;

  case 158: /* EXPRESSION: EXPRESSION PLUS PLUS  */
#line 427 "parser.y"
                                       {pushVStack("+"); pushVStack("1"); CodeGenOp("ADD"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("ADD", 1); StAssPrint("STORE", 1);}
#line 2385 "parser.tab.c"
    break;

  case 159: /* EXPRESSION: EXPRESSION SUB SUB  */
#line 428 "parser.y"
                                       {pushVStack("-"); pushVStack("1"); CodeGenOp("SUB"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("SUB", 1); StAssPrint("STORE", 1);}
#line 2391 "parser.tab.c"
    break;

  case 160: /* $@45: %empty  */
#line 429 "parser.y"
                                  {pushVStack("+");}
#line 2397 "parser.tab.c"
    break;

  case 161: /* EXPRESSION: EXPRESSION PLUS $@45 EXPRESSION  */
#line 429 "parser.y"
                                                                 {CodeGenOp("ADD"); StAssPrint("ADD", 1);}
#line 2403 "parser.tab.c"
    break;

  case 162: /* $@46: %empty  */
#line 430 "parser.y"
                                  {pushVStack("-");}
#line 2409 "parser.tab.c"
    break;

  case 163: /* EXPRESSION: EXPRESSION SUB $@46 EXPRESSION  */
#line 430 "parser.y"
                                                                 {CodeGenOp("SUB"); StAssPrint("SUB", 1);}
#line 2415 "parser.tab.c"
    break;

  case 164: /* $@47: %empty  */
#line 431 "parser.y"
                                  {pushVStack("*");}
#line 2421 "parser.tab.c"
    break;

  case 165: /* EXPRESSION: EXPRESSION MUL $@47 EXPRESSION  */
#line 431 "parser.y"
                                                                 {CodeGenOp("MUL"); StAssPrint("MUL", 1);}
#line 2427 "parser.tab.c"
    break;

  case 166: /* $@48: %empty  */
#line 432 "parser.y"
                                  {pushVStack("/");}
#line 2433 "parser.tab.c"
    break;

  case 167: /* EXPRESSION: EXPRESSION DIV $@48 EXPRESSION  */
#line 432 "parser.y"
                                                                 {CodeGenOp("DIV"); StAssPrint("DIV", 1);}
#line 2439 "parser.tab.c"
    break;

  case 168: /* $@49: %empty  */
#line 435 "parser.y"
                                  {pushVStack("^");}
#line 2445 "parser.tab.c"
    break;

  case 169: /* EXPRESSION: EXPRESSION POW $@49 EXPRESSION  */
#line 435 "parser.y"
                                                                 {CodeGenOp("POW");}
#line 2451 "parser.tab.c"
    break;

  case 171: /* EXPRESSION: FUNC_CALL  */
#line 437 "parser.y"
                            {}
#line 2457 "parser.tab.c"
    break;

  case 173: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 439 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);}
#line 2463 "parser.tab.c"
    break;

  case 178: /* COMPARISONSTT: EXPRESSION GT EXPRESSION  */
#line 459 "parser.y"
                                                        {pushVStack(">"); CodeGenLogical(); StAssPrint("GT", 1);}
#line 2469 "parser.tab.c"
    break;

  case 179: /* COMPARISONSTT: EXPRESSION LT EXPRESSION  */
#line 460 "parser.y"
                                                        {pushVStack("<"); CodeGenLogical(); StAssPrint("LT", 1);}
#line 2475 "parser.tab.c"
    break;

  case 180: /* COMPARISONSTT: EXPRESSION LT EQ EXPRESSION  */
#line 461 "parser.y"
                                                        {pushVStack("<="); CodeGenLogical(); StAssPrint("LE", 1);}
#line 2481 "parser.tab.c"
    break;

  case 181: /* COMPARISONSTT: EXPRESSION GT EQ EXPRESSION  */
#line 462 "parser.y"
                                                        {pushVStack(">="); CodeGenLogical(); StAssPrint("GE", 1);}
#line 2487 "parser.tab.c"
    break;

  case 182: /* COMPARISONSTT: EXPRESSION EQUALITY EXPRESSION  */
#line 463 "parser.y"
                                                        {pushVStack("="); CodeGenLogical(); StAssPrint("EQ", 1);}
#line 2493 "parser.tab.c"
    break;

  case 183: /* COMPARISONSTT: EXPRESSION NEG_EQUALITY EXPRESSION  */
#line 464 "parser.y"
                                                        {pushVStack("!="); CodeGenLogical(); StAssPrint("NE", 1);}
#line 2499 "parser.tab.c"
    break;

  case 184: /* COMPARISONSTT: EXPRESSION LOGIC_AND EXPRESSION  */
#line 465 "parser.y"
                                                        {pushVStack("and"); CodeGenLogical(); StAssPrint("AND", 1);}
#line 2505 "parser.tab.c"
    break;

  case 185: /* COMPARISONSTT: EXPRESSION LOGIC_OR EXPRESSION  */
#line 466 "parser.y"
                                                        {pushVStack("or"); CodeGenLogical(); StAssPrint("OR", 1);}
#line 2511 "parser.tab.c"
    break;

  case 188: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 472 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 2517 "parser.tab.c"
    break;

  case 189: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 473 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 2523 "parser.tab.c"
    break;

  case 190: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 474 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 2529 "parser.tab.c"
    break;

  case 191: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 475 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 2535 "parser.tab.c"
    break;

  case 192: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 476 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 2541 "parser.tab.c"
    break;

  case 193: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 477 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 2547 "parser.tab.c"
    break;

  case 194: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 478 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 2553 "parser.tab.c"
    break;

  case 195: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 479 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 2559 "parser.tab.c"
    break;

  case 196: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 480 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 2565 "parser.tab.c"
    break;

  case 197: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 481 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 2571 "parser.tab.c"
    break;

  case 198: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 482 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 2577 "parser.tab.c"
    break;

  case 199: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 483 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 2583 "parser.tab.c"
    break;

  case 200: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 484 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 2589 "parser.tab.c"
    break;

  case 201: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 485 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 2595 "parser.tab.c"
    break;

  case 202: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 486 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 2601 "parser.tab.c"
    break;

  case 203: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 487 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 2607 "parser.tab.c"
    break;

  case 204: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 488 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 2613 "parser.tab.c"
    break;


#line 2617 "parser.tab.c"

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

#line 507 "parser.y"




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
void st_insert(char* data_type, char* name, char* type ,int is_arg ) {

    //------ create new entry
    struct Entry newEntry ;
    //----- check if name is already in symbol table
    int L=is_exist(name) ;
    if (L != -1){
        printf("\n !!!!!!!!!!!! Error at line %d: %s is already declared in this scope at line %d !!!!!!!!!!!\n",line_number, name, L); }
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
    st_index++; // increment symbol table index
}
//---------------------------------- HANDLE TYPE MISMATCH ERRORS ------------------------------------------------------------------

// for declaration statments take the st_index -1 3shan lesa m3molo insert but for assignment 3ady take assign_index coming from lookup function
void assign_int (int d , int i) {
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "int") {symbolTable[i].intValue= d ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned int value!!!!!!!!!!!\n", line_number, symbolTable[i].name, symbolTable[i].dataType );}
}
void assign_float( float f, int i) {
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "float"){symbolTable[i].floatValue= f ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned float value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
}
void assign_str( char* s , int i) {
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "string"){symbolTable[i].strValue= s ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned string value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
}
void assign_bool( bool b , int i) {
    symbolTable[i].isInit= 1 ;
    if (symbolTable[i].dataType == "bool"){symbolTable[i].boolValue= b ;}
    else { printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s %s variable assigned bool value !!!!!!!!!!!\n", line_number, symbolTable[i].name,symbolTable[i].dataType );}
}
// void check_param_type (int i) {

// }
void check_type( int i) {
    // this functio check type matching between 2 identifiers before assign the value
    if ( is_param == 1) { 
        assign_index = arg_count;
        printf("\nparammmmmmmmmmmmmmm %s\n", symbolTable[i].name);
        printf("\nparammmmmmmmmmmmmmm %d\n", arg_count);        
        }


    if (i != -1 && symbolTable[i].dataType != symbolTable[assign_index].dataType)
    {
        if (strcmp(symbolTable[i].type,"func")== 0){ printf("\n !!!!!!!!!!!! Type Mismatch Error at line %d: %s is %s variable  but %s return %s value  !!!!!!!!!!!\n", line_number,symbolTable[assign_index].name,symbolTable[assign_index].dataType, symbolTable[i].name,symbolTable[i].dataType );}
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
//----------------------------------------------- PRINT SYMBOL TABLE ----------------------------------------------------
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
        if (strcmp(entry->dataType,"int")==0) {fprintf(fp, "%d\t\t|", entry->intValue);}
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
        if ( symbolTable[i].isUsed == 0) {
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
