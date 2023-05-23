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
  YYSYMBOL_NEWLINE = 29,                   /* NEWLINE  */
  YYSYMBOL_EQUALITY = 30,                  /* EQUALITY  */
  YYSYMBOL_NEG_EQUALITY = 31,              /* NEG_EQUALITY  */
  YYSYMBOL_SWITCH = 32,                    /* SWITCH  */
  YYSYMBOL_CASE = 33,                      /* CASE  */
  YYSYMBOL_LOGIC_AND = 34,                 /* LOGIC_AND  */
  YYSYMBOL_LOGIC_OR = 35,                  /* LOGIC_OR  */
  YYSYMBOL_LOGIC_NOT = 36,                 /* LOGIC_NOT  */
  YYSYMBOL_DIGIT = 37,                     /* DIGIT  */
  YYSYMBOL_IDENTIFIER = 38,                /* IDENTIFIER  */
  YYSYMBOL_FLOAT_DIGIT = 39,               /* FLOAT_DIGIT  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_PROGRAM = 48,                   /* PROGRAM  */
  YYSYMBOL_STATEMENT = 49,                 /* STATEMENT  */
  YYSYMBOL_SEMICOLON_MISS = 50,            /* SEMICOLON_MISS  */
  YYSYMBOL_TYPE = 51,                      /* TYPE  */
  YYSYMBOL_DECLARATION_STT = 52,           /* DECLARATION_STT  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_DECLARATION_TAIL = 55,          /* DECLARATION_TAIL  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_RETURN_STT = 59,                /* RETURN_STT  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_helperSWITCH = 61,              /* helperSWITCH  */
  YYSYMBOL_SWITCH_STT = 62,                /* SWITCH_STT  */
  YYSYMBOL_DEFAULTCASE = 63,               /* DEFAULTCASE  */
  YYSYMBOL_CASES = 64,                     /* CASES  */
  YYSYMBOL_65_7 = 65,                      /* $@7  */
  YYSYMBOL_66_8 = 66,                      /* $@8  */
  YYSYMBOL_67_9 = 67,                      /* $@9  */
  YYSYMBOL_68_10 = 68,                     /* $@10  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 69,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_70_11 = 70,                     /* $@11  */
  YYSYMBOL_71_12 = 71,                     /* $@12  */
  YYSYMBOL_72_13 = 72,                     /* $@13  */
  YYSYMBOL_73_14 = 73,                     /* $@14  */
  YYSYMBOL_FUNC_DECLARATION_STT = 74,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_75_15 = 75,                     /* $@15  */
  YYSYMBOL_76_16 = 76,                     /* $@16  */
  YYSYMBOL_77_17 = 77,                     /* $@17  */
  YYSYMBOL_78_18 = 78,                     /* $@18  */
  YYSYMBOL_79_19 = 79,                     /* $@19  */
  YYSYMBOL_80_20 = 80,                     /* $@20  */
  YYSYMBOL_81_21 = 81,                     /* $@21  */
  YYSYMBOL_82_22 = 82,                     /* $@22  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 83, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_84_23 = 84,                     /* $@23  */
  YYSYMBOL_ARGS = 85,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 86,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 87,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 88,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_89_24 = 89,                     /* $@24  */
  YYSYMBOL_ENUM_HELPER = 90,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 91,                 /* ENUM_ARGS  */
  YYSYMBOL_92_25 = 92,                     /* $@25  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 93,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_94_26 = 94,                     /* $@26  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 95, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_CALL_STT = 96,             /* ENUM_CALL_STT  */
  YYSYMBOL_IF_STT_HELPER = 97,             /* IF_STT_HELPER  */
  YYSYMBOL_98_27 = 98,                     /* $@27  */
  YYSYMBOL_IF_STT_HELPER1 = 99,            /* IF_STT_HELPER1  */
  YYSYMBOL_IF_STT = 100,                   /* IF_STT  */
  YYSYMBOL_101_28 = 101,                   /* $@28  */
  YYSYMBOL_102_29 = 102,                   /* $@29  */
  YYSYMBOL_WHILE_STT = 103,                /* WHILE_STT  */
  YYSYMBOL_104_30 = 104,                   /* $@30  */
  YYSYMBOL_105_31 = 105,                   /* $@31  */
  YYSYMBOL_WHILEMISS_COLON = 106,          /* WHILEMISS_COLON  */
  YYSYMBOL_DO_WHILE_STT = 107,             /* DO_WHILE_STT  */
  YYSYMBOL_ERRONOUS_DO_WHILE = 108,        /* ERRONOUS_DO_WHILE  */
  YYSYMBOL_109_32 = 109,                   /* $@32  */
  YYSYMBOL_110_33 = 110,                   /* $@33  */
  YYSYMBOL_111_34 = 111,                   /* $@34  */
  YYSYMBOL_112_35 = 112,                   /* $@35  */
  YYSYMBOL_FOR_STT = 113,                  /* FOR_STT  */
  YYSYMBOL_114_36 = 114,                   /* $@36  */
  YYSYMBOL_115_37 = 115,                   /* $@37  */
  YYSYMBOL_116_38 = 116,                   /* $@38  */
  YYSYMBOL_117_39 = 117,                   /* $@39  */
  YYSYMBOL_ERRONOUS_FOR_LOOP = 118,        /* ERRONOUS_FOR_LOOP  */
  YYSYMBOL_119_40 = 119,                   /* $@40  */
  YYSYMBOL_120_41 = 120,                   /* $@41  */
  YYSYMBOL_helperAssignmentRule = 121,     /* helperAssignmentRule  */
  YYSYMBOL_assignmentSTT = 122,            /* assignmentSTT  */
  YYSYMBOL_123_42 = 123,                   /* $@42  */
  YYSYMBOL_BLOCK = 124,                    /* BLOCK  */
  YYSYMBOL_125_43 = 125,                   /* $@43  */
  YYSYMBOL_FUNC_CALL = 126,                /* FUNC_CALL  */
  YYSYMBOL_127_44 = 127,                   /* $@44  */
  YYSYMBOL_128_45 = 128,                   /* $@45  */
  YYSYMBOL_129_46 = 129,                   /* $@46  */
  YYSYMBOL_USED_ARGS = 130,                /* USED_ARGS  */
  YYSYMBOL_131_47 = 131,                   /* $@47  */
  YYSYMBOL_EXPRESSION = 132,               /* EXPRESSION  */
  YYSYMBOL_133_48 = 133,                   /* $@48  */
  YYSYMBOL_134_49 = 134,                   /* $@49  */
  YYSYMBOL_135_50 = 135,                   /* $@50  */
  YYSYMBOL_136_51 = 136,                   /* $@51  */
  YYSYMBOL_ERRONOUS_EXPRESSION = 137,      /* ERRONOUS_EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 138,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 139,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 140                  /* RES_WORD  */
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
#define YYLAST   1198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  230
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  394

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      44,    42,     2,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   191,   191,   192,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   216,   217,   227,   228,   229,   230,   234,   234,   235,
     235,   236,   237,   238,   243,   244,   245,   246,   247,   247,
     248,   248,   249,   249,   256,   257,   257,   259,   262,   263,
     267,   268,   271,   271,   271,   271,   272,   272,   273,   274,
     276,   285,   285,   286,   286,   287,   287,   288,   288,   289,
     301,   302,   302,   302,   303,   303,   303,   304,   304,   304,
     305,   305,   305,   310,   310,   320,   321,   322,   325,   328,
     335,   335,   336,   338,   338,   341,   341,   342,   348,   348,
     349,   350,   351,   352,   353,   357,   358,   360,   361,   365,
     366,   370,   370,   373,   377,   378,   379,   380,   380,   381,
     381,   382,   391,   391,   391,   398,   399,   404,   405,   408,
     408,   409,   409,   410,   410,   411,   411,   412,   419,   419,
     419,   419,   419,   420,   424,   424,   425,   425,   432,   436,
     437,   438,   438,   443,   443,   451,   451,   451,   451,   452,
     458,   458,   459,   460,   461,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   476,   478,   478,   479,   479,
     482,   482,   483,   484,   485,   486,   495,   497,   498,   499,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543
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
  "NEWLINE", "EQUALITY", "NEG_EQUALITY", "SWITCH", "CASE", "LOGIC_AND",
  "LOGIC_OR", "LOGIC_NOT", "DIGIT", "IDENTIFIER", "FLOAT_DIGIT", "'{'",
  "'}'", "')'", "':'", "'('", "','", "';'", "$accept", "PROGRAM",
  "STATEMENT", "SEMICOLON_MISS", "TYPE", "DECLARATION_STT", "$@1", "$@2",
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

#define YYPACT_NINF (-321)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-166)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -321,   206,  -321,   699,  -321,  -321,  -321,  -321,    -7,    -4,
      12,  -321,  -321,   504,  -321,  -321,    23,    59,    -6,    93,
      76,   533,  -321,   116,  -321,  -321,   504,  -321,    -5,  -321,
      93,    60,  -321,  -321,  -321,    44,  -321,  -321,  -321,    49,
    -321,  -321,  -321,  -321,  -321,  -321,   259,  -321,  -321,  -321,
    1019,  -321,  -321,  -321,   504,   148,   273,  -321,   504,   504,
      93,   504,   504,   504,   504,   504,    93,  -321,  -321,    50,
    -321,   504,   452,    57,   504,  1163,   365,   189,    70,    81,
      87,    28,   504,   107,  -321,  -321,  -321,     2,    -2,   177,
     114,  -321,   129,   113,  -321,   787,  -321,    20,  -321,   100,
    -321,    69,     7,  -321,    29,   135,    44,  -321,  1043,  -321,
     313,   482,  -321,   145,   147,  -321,  -321,   544,   555,   584,
     595,   139,   504,   139,   504,   153,   688,   112,  -321,   177,
     177,   177,   235,   235,  -321,   128,    44,  1115,   452,   452,
     452,  1115,   114,   162,   133,  -321,    21,   137,   138,    74,
      80,   136,  -321,  -321,  1115,  -321,   140,   160,    39,  -321,
     504,   142,  -321,  -321,   410,  -321,    85,    93,   146,    85,
      22,    44,  -321,   504,  -321,   185,  -321,  -321,   152,  -321,
      73,  -321,  -321,   504,    -2,   606,   139,   205,   635,   153,
    -321,   504,  -321,   504,   504,   250,   177,   250,   177,   324,
     235,   324,   235,   139,   139,    22,   179,  -321,   452,   452,
    -321,   182,   184,   219,   191,  -321,   504,   504,   192,   137,
      84,   194,   195,   137,  -321,   200,   198,   215,  -321,  -321,
    1067,   245,   493,  -321,   504,   646,  -321,  -321,  -321,    22,
     226,  -321,    22,   233,   231,  -321,   236,  -321,  1115,   504,
    -321,   241,  -321,   139,    -2,   139,   205,   139,   688,   112,
     177,   234,  -321,   243,   452,   452,  -321,    44,   504,   239,
     504,   504,   969,   813,  -321,   248,   247,  -321,  -321,   258,
    -321,   263,  -321,   261,    60,   246,    60,    60,  -321,  -321,
     674,  -321,   839,  1091,  1139,   730,   262,  -321,  -321,  -321,
    -321,    22,   264,   994,  -321,  -321,    44,  -321,   266,  -321,
    -321,   865,   504,   891,   917,  -321,  -321,  -321,  -321,   260,
     265,  -321,  -321,   272,    60,   275,   277,   493,   278,   274,
    -321,  -321,  -321,   281,   284,   770,  -321,    44,  -321,    44,
    -321,    44,  -321,    44,  -321,   452,  -321,   943,  -321,  -321,
     291,  -321,   289,  -321,  -321,  -321,  -321,   493,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,    44,  -321,  -321,  -321,  -321,
      44,   290,  -321,   320,  -321,  -321,  -321,  -321,    60,  -321,
    -321,  -321,    44,  -321
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    23,    24,    25,    26,     0,   111,
       0,   122,   168,     0,   169,   170,     0,     0,    45,     0,
       0,     0,   166,     0,   167,   153,     0,     2,     0,     4,
       0,    60,    13,    49,     5,     0,    14,    92,    15,   117,
       9,    10,    12,   128,    11,   143,     0,     6,    16,   183,
       0,   185,   182,   199,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
     119,     0,     0,   138,     0,     0,     0,   171,   129,     0,
       0,     0,     0,     0,    22,    17,    61,     0,   208,   198,
     151,   148,     0,     0,     3,     0,    29,    83,     7,     0,
      52,    59,     0,    70,     0,   114,     0,   149,     0,   178,
       0,     0,     8,   174,     0,   176,   180,     0,     0,     0,
       0,   188,     0,   200,     0,   202,   186,   187,    32,   189,
     204,   206,   209,   211,    31,    74,     0,   112,     0,     0,
       0,   123,     0,     0,     0,   133,     0,     0,     0,    95,
       0,     0,    93,    94,    46,    21,     0,    63,     0,   159,
       0,     0,   110,   156,     0,   184,     0,     0,    71,     0,
       0,     0,    51,     0,    58,     0,    69,    48,     0,   113,
       0,   118,   150,     0,   201,     0,   190,   203,     0,   191,
     172,     0,   173,     0,     0,   205,   194,   207,   195,   210,
     196,   212,   197,   215,   213,     0,     0,   120,     0,     0,
     139,   126,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,     0,    67,    47,
       0,     0,     0,   154,     0,     0,    37,    30,    33,     0,
       0,    28,     0,     0,     0,    87,    86,    50,    53,     0,
     121,     0,   115,   179,   216,   193,   214,   192,   175,   177,
     181,     0,    81,     0,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,   104,   103,    98,
     102,     0,   107,     0,    60,     0,    60,    60,   152,   109,
       0,   157,   160,     0,     0,    42,     0,    78,    88,    89,
      84,     0,     0,     0,   116,    75,     0,   144,     0,   140,
     124,     0,     0,     0,     0,   137,   127,   108,   101,     0,
      95,    96,    91,     0,    60,     0,     0,     0,     0,     0,
      35,    36,    34,     0,     0,     0,    72,     0,    85,     0,
      57,     0,    82,     0,   146,     0,   130,     0,   134,   132,
       0,    62,     0,    66,    68,   162,   158,     0,    39,    41,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,    43,     0,    79,    54,    76,   145,
       0,     0,   136,     0,    99,    64,   161,    73,    60,   147,
     141,    55,     0,   142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -321,   253,   -67,   -28,  -164,  -321,  -321,  -321,   170,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,   252,  -269,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -185,  -321,
    -321,  -321,  -321,  -143,    61,  -321,   -10,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,   -16,  -321,  -321,
    -321,  -321,  -321,  -320,  -321,   -12,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,    85,    28,    29,   169,   166,   237,   333,
     334,   335,    30,    82,    31,    32,   101,   102,   173,   302,
     388,   175,    33,   156,   226,   227,   287,    34,   239,   375,
     205,   341,   240,   337,   206,   306,    35,   170,   244,   245,
     246,    36,   223,   151,   152,   221,   153,   319,    37,    38,
      39,    71,   105,    40,   106,   136,    41,    74,   211,   267,
      42,    43,   143,   271,   214,   144,    44,   140,   265,   345,
     392,    45,   343,   380,    46,    47,   160,    48,    94,    49,
      93,   232,   328,   291,   329,    50,   191,   193,   183,   194,
      51,    52,    53,   374
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    77,    98,   157,   218,   138,   243,   355,   176,    89,
     -44,    55,    56,    72,    95,   323,    96,   325,   326,   103,
     261,   -27,   215,   -44,    78,     4,     5,     6,     7,   148,
     178,    69,   128,    97,   108,   -27,   -27,   386,   134,    70,
     228,   243,   121,   123,   125,   158,   126,   127,   177,   129,
     130,   131,   132,   133,   296,   352,    73,   298,   167,   137,
      80,   216,   141,    25,   168,   217,   149,   242,   150,    25,
     154,   208,   209,   210,   251,   243,   275,    86,   243,   229,
     283,   222,   145,   172,    25,   276,   234,    99,   179,   220,
     181,   146,   104,   100,   135,   277,    99,    81,   186,   189,
     235,   236,   -56,   139,   278,   196,   198,   200,   202,    83,
     203,  -135,   204,    25,    87,   -97,   338,    90,   -90,   391,
     207,   279,    84,   280,   109,   110,   111,   147,  -165,  -165,
    -165,    91,  -165,  -165,  -165,  -165,   155,   243,  -165,   238,
      25,   263,   264,   171,   161,   162,  -165,  -165,   230,    75,
    -165,  -165,   110,   111,    92,   247,   159,   163,   180,    12,
    -155,   248,   190,   122,   252,   192,    13,   111,    14,    15,
     -80,   253,   212,   255,   213,   149,   257,   224,   219,   258,
     231,   259,   260,   225,    21,    22,    76,    24,   -77,   109,
     110,   111,    26,   250,   113,   114,   115,   308,   309,   116,
     -65,   109,   110,   111,   272,   273,     2,     3,   115,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   249,    56,
     292,   262,   293,   295,    13,   266,    14,    15,   268,   269,
      16,    17,    18,   274,    19,   270,   282,   303,    20,   281,
     284,   285,    21,    22,    23,    24,    25,   109,   110,   111,
      26,   310,   113,   114,   115,   286,   311,   116,   313,   314,
      75,   289,    54,    55,    56,   117,   118,    58,   297,    59,
      12,   299,    61,   300,    75,   107,   305,    13,   381,    14,
      15,   301,   304,   312,    12,   307,   324,   340,   124,   317,
     342,    13,   318,    14,    15,    21,    22,    76,    24,  -100,
     347,   320,   322,    26,   336,   350,   -97,   339,   344,    21,
      22,    76,    24,   351,   184,   292,   353,    26,   354,   357,
     356,   376,   358,   377,    12,   378,   359,   379,   185,   383,
     385,    13,   390,    14,    15,   220,    54,    55,    56,   241,
     384,    58,   321,    59,     0,   292,    61,   164,     0,    21,
      22,    76,    24,   174,    62,    63,     0,    26,     0,   387,
       0,     0,     0,     0,   389,     0,   142,     0,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,   393,  -165,  -165,  -165,
       0,  -165,  -165,  -165,  -165,     0,  -165,  -165,  -165,  -165,
    -165,     0,     0,     0,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,     0,     0,     0,     0,  -165,  -165,  -165,  -165,  -155,
    -165,     3,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,     0,     0,    13,     0,
      14,    15,     0,     0,    16,    17,    18,     0,    19,     0,
       0,     0,    20,     0,     0,     0,    21,    22,    23,    24,
      25,   233,     0,     3,    26,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
      13,     0,    14,    15,     0,     0,    16,    17,    18,     0,
      19,     0,     0,   187,    20,     0,     0,     0,    21,    22,
      23,    24,    25,    12,   290,     0,    26,   188,     0,     0,
      13,     0,    14,    15,    12,    75,     0,     0,     0,     0,
       0,    13,     0,    14,    15,    12,     0,     0,    21,    22,
      76,    24,    13,     0,    14,    15,    26,     0,     0,    21,
      22,    76,    24,     0,    88,  -164,     0,    26,     0,     0,
      21,    22,    76,    24,    12,   195,     0,     0,    26,     0,
       0,    13,     0,    14,    15,    12,   197,     0,     0,     0,
       0,     0,    13,     0,    14,    15,    12,     0,     0,    21,
      22,    76,    24,    13,     0,    14,    15,    26,     0,     0,
      21,    22,    76,    24,     0,   199,     0,     0,    26,     0,
       0,    21,    22,    76,    24,    12,   201,     0,     0,    26,
       0,     0,    13,     0,    14,    15,    12,   254,     0,     0,
       0,     0,     0,    13,     0,    14,    15,    12,     0,     0,
      21,    22,    76,    24,    13,     0,    14,    15,    26,     0,
       0,    21,    22,    76,    24,     0,   256,     0,     0,    26,
       0,     0,    21,    22,    76,    24,    12,   294,     0,     0,
      26,     0,     0,    13,     0,    14,    15,    12,     0,     0,
       0,     0,     0,     0,    13,     0,    14,    15,     0,     0,
       0,    21,    22,    76,    24,     0,     0,     0,     0,    26,
       0,     0,    21,    22,    76,    24,    54,    55,    56,     0,
      26,    58,     0,    59,     0,     0,    61,     0,     0,     0,
     109,   110,   111,     0,    62,    63,   114,   115,    64,    65,
       0,    54,    55,    56,     0,    57,    58,     0,    59,   327,
      60,    61,     0,     0,     0,     0,     0,     0,     0,    62,
      63,     0,     0,    64,    65,     0,     0,    66,     0,     0,
      67,    68,   109,   110,   111,     0,   332,   113,   114,   115,
       0,     0,   116,     0,     0,     0,     0,     0,     0,     0,
     117,   118,     0,     0,   119,   120,     0,     0,     0,     0,
       0,   -38,   -40,   360,   361,   362,   363,   364,   365,   366,
     367,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   368,     0,   369,   370,   371,     0,     0,     0,   109,
     110,   111,   372,   373,   113,   114,   115,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,   117,   118,     0,
       0,   119,   120,     0,     0,   109,   110,   111,     0,   165,
     113,   114,   115,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,   117,   118,     0,     0,   119,   120,     0,
       0,   109,   110,   111,     0,   316,   113,   114,   115,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,   117,
     118,     0,     0,   119,   120,     0,     0,   109,   110,   111,
       0,  -163,   113,   114,   115,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,   117,   118,     0,     0,   119,
     120,     0,     0,   109,   110,   111,     0,   346,   113,   114,
     115,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,   117,   118,     0,     0,   119,   120,     0,     0,   109,
     110,   111,     0,   348,   113,   114,   115,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,   117,   118,     0,
       0,   119,   120,     0,     0,   109,   110,   111,     0,   349,
     113,   114,   115,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,   117,   118,     0,     0,   119,   120,     0,
       0,   109,   110,   111,     0,   382,   113,   114,   115,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,   117,
     118,     0,     0,   119,   120,     0,   109,   110,   111,     0,
     315,   113,   114,   115,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,   117,   118,     0,     0,   119,   120,
       0,   109,   110,   111,    25,   112,   113,   114,   115,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,   117,
     118,     0,     0,   119,   120,   109,   110,   111,     0,   182,
     113,   114,   115,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,   117,   118,     0,     0,   119,   120,   109,
     110,   111,     0,   288,   113,   114,   115,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,   117,   118,     0,
       0,   119,   120,   109,   110,   111,     0,   330,   113,   114,
     115,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,   117,   118,     0,     0,   119,   120,   109,   110,   111,
       0,     0,   113,   114,   115,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,   117,   118,     0,     0,   119,
     120,    54,    55,    56,     0,   331,    58,     0,    59,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,    62,
      63,     0,     0,    64,    65,    54,    55,    56,     0,     0,
      58,     0,    59,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     0,    62,    63,     0,     0,    64,    65
};

static const yytype_int16 yycheck[] =
{
      16,    13,    30,     1,   147,    72,   170,   327,     1,    21,
      16,    13,    14,     1,    26,   284,    21,   286,   287,    35,
     205,     1,     1,    29,     1,     3,     4,     5,     6,     1,
       1,    38,    60,    38,    46,    15,    16,   357,    66,    43,
       1,   205,    54,    55,    56,    43,    58,    59,    41,    61,
      62,    63,    64,    65,   239,   324,    44,   242,    38,    71,
       1,    40,    74,    40,    44,    44,    38,    45,    40,    40,
      82,   138,   139,   140,     1,   239,   219,     1,   242,    40,
     223,     1,     1,    99,    40,     1,     1,    27,   104,    15,
     106,    10,    43,    33,    44,    11,    27,    38,   110,   111,
      15,    16,    33,    46,    20,   117,   118,   119,   120,    16,
     122,    41,   124,    40,    38,    41,   301,     1,    38,   388,
     136,    37,    29,    39,    12,    13,    14,    40,    12,    13,
      14,    15,    16,    17,    18,    19,    29,   301,    22,   167,
      40,   208,   209,    43,    15,    16,    30,    31,   160,     1,
      34,    35,    13,    14,    38,   171,    42,    44,    23,    11,
      44,   173,    17,    15,   180,    18,    18,    14,    20,    21,
      42,   183,    10,   185,    41,    38,   188,    41,    40,   191,
      38,   193,   194,    43,    36,    37,    38,    39,    42,    12,
      13,    14,    44,    41,    17,    18,    19,   264,   265,    22,
      40,    12,    13,    14,   216,   217,     0,     1,    19,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    33,    14,
     232,    42,   234,   235,    18,    43,    20,    21,    44,    10,
      24,    25,    26,    41,    28,    44,    41,   249,    32,    45,
      40,    43,    36,    37,    38,    39,    40,    12,    13,    14,
      44,   267,    17,    18,    19,    40,   268,    22,   270,   271,
       1,    16,    12,    13,    14,    30,    31,    17,    42,    19,
      11,    38,    22,    42,     1,    16,    42,    18,   345,    20,
      21,    45,    41,    44,    11,    42,    40,   303,    15,    41,
     306,    18,    45,    20,    21,    36,    37,    38,    39,    41,
     312,    38,    41,    44,    42,    45,    41,    43,    42,    36,
      37,    38,    39,    41,     1,   327,    41,    44,    41,    45,
      42,   337,    41,   339,    11,   341,    42,   343,    15,    38,
      41,    18,    42,    20,    21,    15,    12,    13,    14,   169,
     350,    17,   281,    19,    -1,   357,    22,    94,    -1,    36,
      37,    38,    39,   101,    30,    31,    -1,    44,    -1,   375,
      -1,    -1,    -1,    -1,   380,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,   392,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      20,    21,    -1,    -1,    24,    25,    26,    -1,    28,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    -1,     1,    44,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    24,    25,    26,    -1,
      28,    -1,    -1,     1,    32,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    11,     1,    -1,    44,    15,    -1,    -1,
      18,    -1,    20,    21,    11,     1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    20,    21,    11,    -1,    -1,    36,    37,
      38,    39,    18,    -1,    20,    21,    44,    -1,    -1,    36,
      37,    38,    39,    -1,     1,    42,    -1,    44,    -1,    -1,
      36,    37,    38,    39,    11,     1,    -1,    -1,    44,    -1,
      -1,    18,    -1,    20,    21,    11,     1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    20,    21,    11,    -1,    -1,    36,
      37,    38,    39,    18,    -1,    20,    21,    44,    -1,    -1,
      36,    37,    38,    39,    -1,     1,    -1,    -1,    44,    -1,
      -1,    36,    37,    38,    39,    11,     1,    -1,    -1,    44,
      -1,    -1,    18,    -1,    20,    21,    11,     1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    20,    21,    11,    -1,    -1,
      36,    37,    38,    39,    18,    -1,    20,    21,    44,    -1,
      -1,    36,    37,    38,    39,    -1,     1,    -1,    -1,    44,
      -1,    -1,    36,    37,    38,    39,    11,     1,    -1,    -1,
      44,    -1,    -1,    18,    -1,    20,    21,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    36,    37,    38,    39,    12,    13,    14,    -1,
      44,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,
      12,    13,    14,    -1,    30,    31,    18,    19,    34,    35,
      -1,    12,    13,    14,    -1,    16,    17,    -1,    19,    45,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    34,    35,    -1,    -1,    38,    -1,    -1,
      41,    42,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    41,    42,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    23,    24,    25,    -1,    -1,    -1,    12,
      13,    14,    32,    33,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    34,    35,    -1,    -1,    12,    13,    14,    -1,    42,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,    -1,
      -1,    12,    13,    14,    -1,    42,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    34,    35,    -1,    -1,    12,    13,    14,
      -1,    42,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,
      35,    -1,    -1,    12,    13,    14,    -1,    42,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    12,
      13,    14,    -1,    42,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    34,    35,    -1,    -1,    12,    13,    14,    -1,    42,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,    -1,
      -1,    12,    13,    14,    -1,    42,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    34,    35,    -1,    12,    13,    14,    -1,
      41,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,
      -1,    12,    13,    14,    40,    16,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    34,    35,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    34,    35,    12,    13,    14,    -1,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    34,    35,    12,    13,    14,
      -1,    -1,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,
      35,    12,    13,    14,    -1,    16,    17,    -1,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    34,    35,    12,    13,    14,    -1,    -1,
      17,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    18,    20,    21,    24,    25,    26,    28,
      32,    36,    37,    38,    39,    40,    44,    49,    51,    52,
      59,    61,    62,    69,    74,    83,    88,    95,    96,    97,
     100,   103,   107,   108,   113,   118,   121,   122,   124,   126,
     132,   137,   138,   139,    12,    13,    14,    16,    17,    19,
      21,    22,    30,    31,    34,    35,    38,    41,    42,    38,
      43,    98,     1,    44,   104,     1,    38,   132,     1,   124,
       1,    38,    60,    16,    29,    50,     1,    38,     1,   132,
       1,    15,    38,   127,   125,   132,    21,    38,    50,    27,
      33,    63,    64,   124,    43,    99,   101,    16,   132,    12,
      13,    14,    16,    17,    18,    19,    22,    30,    31,    34,
      35,   132,    15,   132,    15,   132,   132,   132,    50,   132,
     132,   132,   132,   132,    50,    44,   102,   132,    49,    46,
     114,   132,     1,   109,   112,     1,    10,    40,     1,    38,
      40,    90,    91,    93,   132,    29,    70,     1,    43,    42,
     123,    15,    16,    44,    48,    42,    54,    38,    44,    53,
      84,    43,   124,    65,    63,    68,     1,    41,     1,   124,
      23,   124,    16,   135,     1,    15,   132,     1,    15,   132,
      17,   133,    18,   134,   136,     1,   132,     1,   132,     1,
     132,     1,   132,   132,   132,    77,    81,   124,    49,    49,
      49,   105,    10,    41,   111,     1,    40,    44,    90,    40,
      15,    92,     1,    89,    41,    43,    71,    72,     1,    40,
     132,    38,   128,    41,     1,    15,    16,    55,    50,    75,
      79,    55,    45,    51,    85,    86,    87,   124,   132,    33,
      41,     1,   124,   132,     1,   132,     1,   132,   132,   132,
     132,    85,    42,    49,    49,   115,    43,   106,    44,    10,
      44,   110,   132,   132,    41,    90,     1,    11,    20,    37,
      39,    45,    41,    90,    40,    43,    40,    73,    16,    16,
       1,   130,   132,   132,     1,   132,    85,    42,    85,    38,
      42,    45,    66,   132,    41,    42,    82,    42,    49,    49,
     124,   132,    44,   132,   132,    41,    42,    41,    45,    94,
      38,    91,    41,    64,    40,    64,    64,    45,   129,   131,
      16,    16,    16,    56,    57,    58,    42,    80,    85,    43,
     124,    78,   124,   119,    42,   116,    42,   132,    42,    42,
      45,    41,    64,    41,    41,   130,    42,    45,    41,    42,
       3,     4,     5,     6,     7,     8,     9,    10,    21,    23,
      24,    25,    32,    33,   140,    76,   124,   124,   124,   124,
     120,    49,    42,    38,    93,    41,   130,   124,    67,   124,
      42,    64,   117,   124
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    51,    51,    53,    52,    54,
      52,    52,    52,    52,    55,    55,    55,    55,    56,    55,
      57,    55,    58,    55,    59,    60,    59,    61,    62,    62,
      63,    63,    65,    66,    67,    64,    68,    64,    64,    64,
      64,    70,    69,    71,    69,    72,    69,    73,    69,    69,
      74,    75,    76,    74,    77,    78,    74,    79,    80,    74,
      81,    82,    74,    84,    83,    85,    85,    85,    86,    87,
      89,    88,    88,    90,    90,    92,    91,    91,    94,    93,
      93,    93,    93,    93,    93,    95,    95,    95,    95,    96,
      96,    98,    97,    99,   100,   100,   100,   101,   100,   102,
     100,   100,   104,   105,   103,   106,   106,   107,   107,   109,
     108,   110,   108,   111,   108,   112,   108,   108,   114,   115,
     116,   117,   113,   113,   119,   118,   120,   118,   121,   122,
     122,   123,   122,   125,   124,   127,   128,   129,   126,   126,
     131,   130,   130,   130,   130,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   132,   134,   132,   135,   132,
     136,   132,   132,   132,   132,   132,   137,   137,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     3,     3,     4,     3,     3,     3,     1,     0,     4,
       0,     4,     0,     4,     1,     0,     3,     4,     3,     1,
       3,     2,     0,     0,     0,     8,     0,     5,     2,     1,
       0,     0,     7,     0,     8,     0,     7,     0,     7,     3,
       2,     0,     0,     8,     0,     0,     8,     0,     0,     7,
       0,     0,     7,     0,     5,     3,     1,     1,     2,     2,
       0,     6,     1,     1,     1,     0,     4,     1,     0,     6,
       3,     4,     3,     3,     3,     5,     4,     5,     6,     5,
       3,     0,     3,     2,     2,     4,     5,     0,     3,     0,
       4,     4,     0,     0,     6,     1,     0,     6,     1,     0,
       7,     0,     7,     0,     7,     0,     8,     6,     0,     0,
       0,     0,    11,     1,     0,     8,     0,     9,     2,     2,
       3,     0,     5,     0,     4,     0,     0,     0,     7,     3,
       0,     4,     3,     1,     0,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     0,     4,     0,     4,     0,     4,
       0,     4,     1,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     4,     4,     3,     3,     3,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     4,     4,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 1794 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 197 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1800 "parser.tab.c"
    break;

  case 9: /* STATEMENT: IF_STT  */
#line 201 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1806 "parser.tab.c"
    break;

  case 10: /* STATEMENT: WHILE_STT  */
#line 202 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1812 "parser.tab.c"
    break;

  case 11: /* STATEMENT: FOR_STT  */
#line 203 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1818 "parser.tab.c"
    break;

  case 12: /* STATEMENT: DO_WHILE_STT  */
#line 204 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1824 "parser.tab.c"
    break;

  case 13: /* STATEMENT: SWITCH_STT  */
#line 205 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1830 "parser.tab.c"
    break;

  case 14: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 206 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1836 "parser.tab.c"
    break;

  case 15: /* STATEMENT: ENUM_CALL_STT  */
#line 207 "parser.y"
                                                            {printf("#[Parsed_Enum_USAGE]# ");}
#line 1842 "parser.tab.c"
    break;

  case 17: /* STATEMENT: BREAK SEMICOLON_MISS  */
#line 209 "parser.y"
                                                            {StAssJmp("JMP", "END", &SMLabel_End, 0, 0);}
#line 1848 "parser.tab.c"
    break;

  case 18: /* STATEMENT: error SEMICOLON  */
#line 210 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1854 "parser.tab.c"
    break;

  case 19: /* STATEMENT: error '}'  */
#line 211 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1860 "parser.tab.c"
    break;

  case 20: /* STATEMENT: error ')'  */
#line 212 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1866 "parser.tab.c"
    break;

  case 22: /* SEMICOLON_MISS: NEWLINE  */
#line 217 "parser.y"
                                {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);pErr(yylineno);}
#line 1872 "parser.tab.c"
    break;

  case 23: /* TYPE: INT  */
#line 227 "parser.y"
                            { (yyval.str) = "int";   }
#line 1878 "parser.tab.c"
    break;

  case 24: /* TYPE: FLOAT  */
#line 228 "parser.y"
                            { (yyval.str) = "float"; }
#line 1884 "parser.tab.c"
    break;

  case 25: /* TYPE: BOOL  */
#line 229 "parser.y"
                            { (yyval.str) = "bool";  }
#line 1890 "parser.tab.c"
    break;

  case 26: /* TYPE: STRING  */
#line 230 "parser.y"
                            { (yyval.str) = "string";}
#line 1896 "parser.tab.c"
    break;

  case 27: /* $@1: %empty  */
#line 234 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0);   assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1902 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 234 "parser.y"
                                                                                                                                                         { assign_index =-1; printf("#[Parsed_Declaration]# "); }
#line 1908 "parser.tab.c"
    break;

  case 29: /* $@2: %empty  */
#line 235 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0); assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1914 "parser.tab.c"
    break;

  case 30: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 235 "parser.y"
                                                                                                                                                         {assign_index =-1; printf("#[Parsed_CONST_Declaration]# "); }
#line 1920 "parser.tab.c"
    break;

  case 31: /* DECLARATION_STT: error IDENTIFIER SEMICOLON_MISS  */
#line 236 "parser.y"
                                                                                                 {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);pErr(yylineno);}
#line 1926 "parser.tab.c"
    break;

  case 32: /* DECLARATION_STT: error CONSTANT SEMICOLON_MISS  */
#line 237 "parser.y"
                                                                                                 {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);pErr(yylineno);}
#line 1932 "parser.tab.c"
    break;

  case 33: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON_MISS  */
#line 238 "parser.y"
                                                                                                 {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);pErr(yylineno);}
#line 1938 "parser.tab.c"
    break;

  case 34: /* DECLARATION_TAIL: EQ EXPRESSION SEMICOLON  */
#line 243 "parser.y"
                                                                                            {StAssPush(strdup(IdentifierHolder)); StAssPrint("OVER", 1); StAssPrint("STORE", 1); StAssPrint("DROP", 1);}
#line 1944 "parser.tab.c"
    break;

  case 35: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 244 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 1950 "parser.tab.c"
    break;

  case 36: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 245 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);pErr(yylineno);}
#line 1956 "parser.tab.c"
    break;

  case 38: /* $@3: %empty  */
#line 247 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1962 "parser.tab.c"
    break;

  case 40: /* $@4: %empty  */
#line 248 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1968 "parser.tab.c"
    break;

  case 42: /* $@5: %empty  */
#line 249 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1974 "parser.tab.c"
    break;

  case 44: /* RETURN_STT: RETURN  */
#line 256 "parser.y"
                                                {int dum = 0;StAssPrint("POP\tPC",1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1980 "parser.tab.c"
    break;

  case 45: /* $@6: %empty  */
#line 257 "parser.y"
                         {assign_index =func_index;}
#line 1986 "parser.tab.c"
    break;

  case 46: /* RETURN_STT: RETURN $@6 EXPRESSION  */
#line 257 "parser.y"
                                                                            { return_exist = 1; StAssPrint("OVER",1);int dum = 0;StAssPrint("POP\tPC",1);StAssPrint("DNEXT", 1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1992 "parser.tab.c"
    break;

  case 47: /* helperSWITCH: SWITCH IDENTIFIER ':' '{'  */
#line 259 "parser.y"
                                          {strcpy(switcher, (yyvsp[-2].str));}
#line 1998 "parser.tab.c"
    break;

  case 48: /* SWITCH_STT: helperSWITCH CASES '}'  */
#line 262 "parser.y"
                                        {StAssPrintLBL(0,1);}
#line 2004 "parser.tab.c"
    break;

  case 50: /* DEFAULTCASE: DEFAULT ':' BLOCK  */
#line 267 "parser.y"
                                  {StAssJmp("JMP", "END",&SMLabel_End, 0,0); }
#line 2010 "parser.tab.c"
    break;

  case 51: /* DEFAULTCASE: DEFAULT BLOCK  */
#line 268 "parser.y"
                                {printf("\n\n=====ERROR====\n missing colon ':' at DEFAULT CASE of switch, error at line %d\n\n", yylineno); pErr(yylineno);}
#line 2016 "parser.tab.c"
    break;

  case 52: /* $@7: %empty  */
#line 271 "parser.y"
                     {StAssPush(switcher);}
#line 2022 "parser.tab.c"
    break;

  case 53: /* $@8: %empty  */
#line 271 "parser.y"
                                                       {StAssPrint("EQ", 1); StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2028 "parser.tab.c"
    break;

  case 54: /* $@9: %empty  */
#line 271 "parser.y"
                                                                                                                                   {StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2034 "parser.tab.c"
    break;

  case 56: /* $@10: %empty  */
#line 272 "parser.y"
                              {printf("\n\n=====ERROR====\n DEFAULT CASE must be written at the end of the switch statement, error at line %d\n\n", yylineno); pErr(yylineno);}
#line 2040 "parser.tab.c"
    break;

  case 58: /* CASES: DEFAULTCASE DEFAULTCASE  */
#line 273 "parser.y"
                                                                {printf("\n\n=====ERROR====\n only 1 DEFAULT CASE is allowed in the switch statement error, at line %d\n\n", yylineno); pErr(yylineno);}
#line 2046 "parser.tab.c"
    break;

  case 61: /* $@11: %empty  */
#line 285 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2052 "parser.tab.c"
    break;

  case 63: /* $@12: %empty  */
#line 286 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); pErr(yylineno);}
#line 2058 "parser.tab.c"
    break;

  case 65: /* $@13: %empty  */
#line 287 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);pErr(yylineno);}
#line 2064 "parser.tab.c"
    break;

  case 67: /* $@14: %empty  */
#line 288 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2070 "parser.tab.c"
    break;

  case 69: /* ERRONOUS_SWITCH_STT: helperSWITCH CASES error  */
#line 289 "parser.y"
                                           {printf("\n\n=====ERROR====\n unclosed '}' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2076 "parser.tab.c"
    break;

  case 71: /* $@15: %empty  */
#line 302 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2082 "parser.tab.c"
    break;

  case 72: /* $@16: %empty  */
#line 302 "parser.y"
                                                                                                                    {func_index = st_insert((yyvsp[-5].str), (yyvsp[-4].str),"func",0); popArgs();}
#line 2088 "parser.tab.c"
    break;

  case 74: /* $@17: %empty  */
#line 303 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2094 "parser.tab.c"
    break;

  case 75: /* $@18: %empty  */
#line 303 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-4].str),"func",0); popArgs();}
#line 2100 "parser.tab.c"
    break;

  case 77: /* $@19: %empty  */
#line 304 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2106 "parser.tab.c"
    break;

  case 78: /* $@20: %empty  */
#line 304 "parser.y"
                                                                                                                    {func_index=st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2112 "parser.tab.c"
    break;

  case 80: /* $@21: %empty  */
#line 305 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2118 "parser.tab.c"
    break;

  case 81: /* $@22: %empty  */
#line 305 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-3].str),"func",0);}
#line 2124 "parser.tab.c"
    break;

  case 83: /* $@23: %empty  */
#line 310 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));pErr(yylineno);}
#line 2130 "parser.tab.c"
    break;

  case 84: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@23 ARGS ')'  */
#line 310 "parser.y"
                                                                                                                                                                                                                   {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2136 "parser.tab.c"
    break;

  case 88: /* ERRONOUS_ARGS: ',' ARGS  */
#line 325 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);pErr(yylineno);}
#line 2142 "parser.tab.c"
    break;

  case 89: /* ARG_DECL: TYPE IDENTIFIER  */
#line 328 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1); char* buf=(yyvsp[0].str); argumentList[argPointer]=buf;argPointer++;}
#line 2148 "parser.tab.c"
    break;

  case 90: /* $@24: %empty  */
#line 335 "parser.y"
                                      { is_enum =1;}
#line 2154 "parser.tab.c"
    break;

  case 91: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' $@24 ENUM_HELPER '}'  */
#line 335 "parser.y"
                                                                              { st_insert("enum" , (yyvsp[-4].str), "var" , 0); is_enum=0; enumCNT=1;}
#line 2160 "parser.tab.c"
    break;

  case 95: /* $@25: %empty  */
#line 341 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++;  st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int(  enum_arg_count-1,st_index-1); }
#line 2166 "parser.tab.c"
    break;

  case 97: /* ENUM_ARGS: IDENTIFIER  */
#line 342 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++; st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int( enum_arg_count-1,st_index-1);  }
#line 2172 "parser.tab.c"
    break;

  case 98: /* $@26: %empty  */
#line 348 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++ ; st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2178 "parser.tab.c"
    break;

  case 100: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ DIGIT  */
#line 349 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++;  st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2184 "parser.tab.c"
    break;

  case 101: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ error ','  */
#line 350 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2190 "parser.tab.c"
    break;

  case 102: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ FLOAT_DIGIT  */
#line 351 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2196 "parser.tab.c"
    break;

  case 103: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ STRING_LITERAL  */
#line 352 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2202 "parser.tab.c"
    break;

  case 104: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ BOOL_LITERAL  */
#line 353 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2208 "parser.tab.c"
    break;

  case 105: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 357 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2214 "parser.tab.c"
    break;

  case 106: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 358 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2220 "parser.tab.c"
    break;

  case 107: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 360 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2226 "parser.tab.c"
    break;

  case 108: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER error '{' ENUM_HELPER '}'  */
#line 361 "parser.y"
                                                            {printf("\n\n=====ERROR====\n UnExpected IDENTIFIER in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2232 "parser.tab.c"
    break;

  case 109: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER EQ IDENTIFIER SEMICOLON  */
#line 365 "parser.y"
                                                               { StAssPush((yyvsp[-3].str));StAssPush((yyvsp[-1].str));StAssPrint("STORE",1); st_insert((yyvsp[-4].str) , (yyvsp[-3].str), "var_enum" , 0); assign_enum(st_index-1, (yyvsp[-4].str),(yyvsp[-1].str)); int i= lookup((yyvsp[-4].str), 0); symbolTable[i].isUsed=1; }
#line 2238 "parser.tab.c"
    break;

  case 110: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER SEMICOLON  */
#line 366 "parser.y"
                                                   { st_insert((yyvsp[-2].str) , (yyvsp[-1].str), "var_enum" , 0); int i= lookup((yyvsp[-2].str),0); symbolTable[i].isUsed=1;}
#line 2244 "parser.tab.c"
    break;

  case 111: /* $@27: %empty  */
#line 370 "parser.y"
                   {printIF();}
#line 2250 "parser.tab.c"
    break;

  case 112: /* IF_STT_HELPER: IF $@27 EXPRESSION  */
#line 370 "parser.y"
                                           {StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2256 "parser.tab.c"
    break;

  case 113: /* IF_STT_HELPER1: ':' BLOCK  */
#line 373 "parser.y"
                                                            {controlTerminator(0);  StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2262 "parser.tab.c"
    break;

  case 114: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1  */
#line 377 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2268 "parser.tab.c"
    break;

  case 115: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE BLOCK  */
#line 378 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2274 "parser.tab.c"
    break;

  case 116: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE error '}'  */
#line 379 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2280 "parser.tab.c"
    break;

  case 117: /* $@28: %empty  */
#line 380 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2286 "parser.tab.c"
    break;

  case 119: /* $@29: %empty  */
#line 381 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2292 "parser.tab.c"
    break;

  case 121: /* IF_STT: IF_STT_HELPER ':' error '}'  */
#line 382 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2298 "parser.tab.c"
    break;

  case 122: /* $@30: %empty  */
#line 391 "parser.y"
                      {printWHILE(); StAssPrintLBL(1, 0);}
#line 2304 "parser.tab.c"
    break;

  case 123: /* $@31: %empty  */
#line 391 "parser.y"
                                                                      {StAssJmp("JNZ", "END",&SMLabel_End, 0,0);}
#line 2310 "parser.tab.c"
    break;

  case 124: /* WHILE_STT: WHILE $@30 EXPRESSION $@31 WHILEMISS_COLON BLOCK  */
#line 391 "parser.y"
                                                                                                                                        {StAssJmp("JMP", "LBL",&SMLabel_Else, 1,0); StAssPrintLBL(0, 1);}
#line 2316 "parser.tab.c"
    break;

  case 126: /* WHILEMISS_COLON: %empty  */
#line 399 "parser.y"
                  {printf("\n\n=====ERROR====\n Missing ':' for the WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2322 "parser.tab.c"
    break;

  case 129: /* $@32: %empty  */
#line 408 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2328 "parser.tab.c"
    break;

  case 131: /* $@33: %empty  */
#line 409 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2334 "parser.tab.c"
    break;

  case 133: /* $@34: %empty  */
#line 410 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2340 "parser.tab.c"
    break;

  case 135: /* $@35: %empty  */
#line 411 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2346 "parser.tab.c"
    break;

  case 137: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 412 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);pErr(yylineno);}
#line 2352 "parser.tab.c"
    break;

  case 138: /* $@36: %empty  */
#line 419 "parser.y"
                        {in_loop = 1;}
#line 2358 "parser.tab.c"
    break;

  case 139: /* $@37: %empty  */
#line 419 "parser.y"
                                                 {StAssForHeader();}
#line 2364 "parser.tab.c"
    break;

  case 140: /* $@38: %empty  */
#line 419 "parser.y"
                                                                               {StAssForMiddle();}
#line 2370 "parser.tab.c"
    break;

  case 141: /* $@39: %empty  */
#line 419 "parser.y"
                                                                                                                {StAssPrintLBL(1,1); in_loop = 0;}
#line 2376 "parser.tab.c"
    break;

  case 142: /* FOR_STT: FOR '(' $@36 STATEMENT $@37 STATEMENT $@38 STATEMENT ')' $@39 BLOCK  */
#line 419 "parser.y"
                                                                                                                                                          {StAssJmp("JMP", "Label", &ForHeaderLabel,1,0); StAssPrintLBL(0,1);}
#line 2382 "parser.tab.c"
    break;

  case 144: /* $@40: %empty  */
#line 424 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2388 "parser.tab.c"
    break;

  case 146: /* $@41: %empty  */
#line 425 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2394 "parser.tab.c"
    break;

  case 148: /* helperAssignmentRule: IDENTIFIER EQ  */
#line 432 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); StAssPush((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str),1);}
#line 2400 "parser.tab.c"
    break;

  case 149: /* assignmentSTT: helperAssignmentRule SEMICOLON  */
#line 436 "parser.y"
                                                                 {assign_index=-1; printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2406 "parser.tab.c"
    break;

  case 150: /* assignmentSTT: helperAssignmentRule EXPRESSION SEMICOLON  */
#line 437 "parser.y"
                                                                 {assign_index =-1; StAssPrint("STORE", 1); CodeGenAss();printf("#[Parsed_Assignment]# ");}
#line 2412 "parser.tab.c"
    break;

  case 151: /* $@42: %empty  */
#line 438 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str),1); StAssPush((yyvsp[-1].str));}
#line 2418 "parser.tab.c"
    break;

  case 152: /* assignmentSTT: IDENTIFIER error $@42 EXPRESSION SEMICOLON  */
#line 438 "parser.y"
                                                                                                                                                        {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2424 "parser.tab.c"
    break;

  case 153: /* $@43: %empty  */
#line 443 "parser.y"
                    {scope_start();}
#line 2430 "parser.tab.c"
    break;

  case 154: /* BLOCK: '{' $@43 PROGRAM '}'  */
#line 443 "parser.y"
                                                                              {scope_end(); printf("#[Parsed_Block]# ");}
#line 2436 "parser.tab.c"
    break;

  case 155: /* $@44: %empty  */
#line 451 "parser.y"
                           {called_func_index = lookup((yyvsp[0].str),0); check_type(called_func_index); StAssPush("PC");}
#line 2442 "parser.tab.c"
    break;

  case 156: /* $@45: %empty  */
#line 451 "parser.y"
                                                                                                                   { is_param =1;}
#line 2448 "parser.tab.c"
    break;

  case 157: /* $@46: %empty  */
#line 451 "parser.y"
                                                                                                                                              { is_param =0; arg_count_check(called_func_index); arg_count=0; int dum=0; StAssJmp("JMP", (yyvsp[-4].str),&dum, 0,0);}
#line 2454 "parser.tab.c"
    break;

  case 158: /* FUNC_CALL: IDENTIFIER $@44 '(' $@45 USED_ARGS $@46 ')'  */
#line 451 "parser.y"
                                                                                                                                                                                                                                                               { printf("#[Parsed_Func_Call]# ");}
#line 2460 "parser.tab.c"
    break;

  case 159: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 452 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);pErr(yylineno);}
#line 2466 "parser.tab.c"
    break;

  case 160: /* $@47: %empty  */
#line 458 "parser.y"
                           { arg_count++; }
#line 2472 "parser.tab.c"
    break;

  case 162: /* USED_ARGS: error ',' USED_ARGS  */
#line 459 "parser.y"
                                                            {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2478 "parser.tab.c"
    break;

  case 163: /* USED_ARGS: EXPRESSION  */
#line 460 "parser.y"
                             {arg_count++ ;}
#line 2484 "parser.tab.c"
    break;

  case 165: /* EXPRESSION: IDENTIFIER  */
#line 467 "parser.y"
                                                { int i = lookup((yyvsp[0].str),0); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2490 "parser.tab.c"
    break;

  case 166: /* EXPRESSION: DIGIT  */
#line 468 "parser.y"
                                                { assign_int((yyvsp[0].num), assign_index) ; char numtostring[40]; itoa((yyvsp[0].num), numtostring, 10); pushVStack(numtostring); char dum[10]="$"; StAssPush(strcat(dum,numtostring));}
#line 2496 "parser.tab.c"
    break;

  case 167: /* EXPRESSION: FLOAT_DIGIT  */
#line 469 "parser.y"
                                                { assign_int((yyvsp[0].float_val), assign_index); char floattostring[40]; gcvt((yyvsp[0].float_val), 6, floattostring); pushVStack(floattostring); char dum[10]="$"; StAssPush(strcat(dum,floattostring));}
#line 2502 "parser.tab.c"
    break;

  case 168: /* EXPRESSION: BOOL_LITERAL  */
#line 470 "parser.y"
                                                { assign_int((yyvsp[0].bool_val), assign_index); if((yyvsp[0].bool_val)==true){pushVStack("true");StAssPush("$true");}else{pushVStack("false");StAssPush("$false");} }
#line 2508 "parser.tab.c"
    break;

  case 169: /* EXPRESSION: STRING_LITERAL  */
#line 471 "parser.y"
                                                { assign_str((yyvsp[0].str), assign_index); pushVStack((yyvsp[0].str));char buf[50]; strcpy(buf, "$");strcat(buf, (yyvsp[0].str)); StAssPush(buf);}
#line 2514 "parser.tab.c"
    break;

  case 170: /* EXPRESSION: CONSTANT  */
#line 472 "parser.y"
                                                { int i = lookup((yyvsp[0].str),0); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2520 "parser.tab.c"
    break;

  case 171: /* EXPRESSION: SUB EXPRESSION  */
#line 473 "parser.y"
                                                {StAssPrint("neg", 1);}
#line 2526 "parser.tab.c"
    break;

  case 172: /* EXPRESSION: EXPRESSION PLUS PLUS  */
#line 474 "parser.y"
                                                { pushVStack("+"); pushVStack("1"); CodeGenOp("ADD"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("ADD", 1); StAssPrint("STORE", 1);}
#line 2532 "parser.tab.c"
    break;

  case 173: /* EXPRESSION: EXPRESSION SUB SUB  */
#line 475 "parser.y"
                                                { pushVStack("-"); pushVStack("1"); CodeGenOp("SUB"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("SUB", 1); StAssPrint("STORE", 1);}
#line 2538 "parser.tab.c"
    break;

  case 174: /* $@48: %empty  */
#line 476 "parser.y"
                                                { pushVStack("+");}
#line 2544 "parser.tab.c"
    break;

  case 175: /* EXPRESSION: EXPRESSION PLUS $@48 EXPRESSION  */
#line 476 "parser.y"
                                                                                 {CodeGenOp("ADD"); StAssPrint("ADD", 1);}
#line 2550 "parser.tab.c"
    break;

  case 176: /* $@49: %empty  */
#line 478 "parser.y"
                                                { pushVStack("*");}
#line 2556 "parser.tab.c"
    break;

  case 177: /* EXPRESSION: EXPRESSION MUL $@49 EXPRESSION  */
#line 478 "parser.y"
                                                                                 {CodeGenOp("MUL"); StAssPrint("MUL", 1);}
#line 2562 "parser.tab.c"
    break;

  case 178: /* $@50: %empty  */
#line 479 "parser.y"
                                                { pushVStack("/");}
#line 2568 "parser.tab.c"
    break;

  case 179: /* EXPRESSION: EXPRESSION DIV $@50 EXPRESSION  */
#line 479 "parser.y"
                                                                                 {CodeGenOp("DIV"); StAssPrint("DIV", 1);}
#line 2574 "parser.tab.c"
    break;

  case 180: /* $@51: %empty  */
#line 482 "parser.y"
                                                {pushVStack("^");}
#line 2580 "parser.tab.c"
    break;

  case 181: /* EXPRESSION: EXPRESSION POW $@51 EXPRESSION  */
#line 482 "parser.y"
                                                                               {CodeGenOp("POW");}
#line 2586 "parser.tab.c"
    break;

  case 185: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 486 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);pErr(yylineno);}
#line 2592 "parser.tab.c"
    break;

  case 190: /* COMPARISONSTT: EXPRESSION GT EXPRESSION  */
#line 506 "parser.y"
                                                        {pushVStack(">"); CodeGenLogical(); StAssPrint("GT", 1);}
#line 2598 "parser.tab.c"
    break;

  case 191: /* COMPARISONSTT: EXPRESSION LT EXPRESSION  */
#line 507 "parser.y"
                                                        {pushVStack("<"); CodeGenLogical(); StAssPrint("LT", 1);}
#line 2604 "parser.tab.c"
    break;

  case 192: /* COMPARISONSTT: EXPRESSION LT EQ EXPRESSION  */
#line 508 "parser.y"
                                                        {pushVStack("<="); CodeGenLogical(); StAssPrint("LE", 1);}
#line 2610 "parser.tab.c"
    break;

  case 193: /* COMPARISONSTT: EXPRESSION GT EQ EXPRESSION  */
#line 509 "parser.y"
                                                        {pushVStack(">="); CodeGenLogical(); StAssPrint("GE", 1);}
#line 2616 "parser.tab.c"
    break;

  case 194: /* COMPARISONSTT: EXPRESSION EQUALITY EXPRESSION  */
#line 510 "parser.y"
                                                        {pushVStack("="); CodeGenLogical(); StAssPrint("EQ", 1);}
#line 2622 "parser.tab.c"
    break;

  case 195: /* COMPARISONSTT: EXPRESSION NEG_EQUALITY EXPRESSION  */
#line 511 "parser.y"
                                                        {pushVStack("!="); CodeGenLogical(); StAssPrint("NE", 1);}
#line 2628 "parser.tab.c"
    break;

  case 196: /* COMPARISONSTT: EXPRESSION LOGIC_AND EXPRESSION  */
#line 512 "parser.y"
                                                        {pushVStack("and"); CodeGenLogical(); StAssPrint("AND", 1);}
#line 2634 "parser.tab.c"
    break;

  case 197: /* COMPARISONSTT: EXPRESSION LOGIC_OR EXPRESSION  */
#line 513 "parser.y"
                                                        {pushVStack("or"); CodeGenLogical(); StAssPrint("OR", 1);}
#line 2640 "parser.tab.c"
    break;

  case 198: /* COMPARISONSTT: LOGIC_NOT EXPRESSION  */
#line 514 "parser.y"
                                                        {StAssPrint("neg", 1);}
#line 2646 "parser.tab.c"
    break;

  case 200: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 519 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2652 "parser.tab.c"
    break;

  case 201: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 520 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2658 "parser.tab.c"
    break;

  case 202: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 521 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2664 "parser.tab.c"
    break;

  case 203: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 522 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2670 "parser.tab.c"
    break;

  case 204: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 523 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2676 "parser.tab.c"
    break;

  case 205: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 524 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2682 "parser.tab.c"
    break;

  case 206: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 525 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2688 "parser.tab.c"
    break;

  case 207: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 526 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2694 "parser.tab.c"
    break;

  case 208: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 527 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2700 "parser.tab.c"
    break;

  case 209: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 528 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2706 "parser.tab.c"
    break;

  case 210: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 529 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2712 "parser.tab.c"
    break;

  case 211: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 530 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2718 "parser.tab.c"
    break;

  case 212: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 531 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2724 "parser.tab.c"
    break;

  case 213: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 532 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2730 "parser.tab.c"
    break;

  case 214: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 533 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2736 "parser.tab.c"
    break;

  case 215: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 534 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2742 "parser.tab.c"
    break;

  case 216: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 535 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2748 "parser.tab.c"
    break;


#line 2752 "parser.tab.c"

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

#line 554 "parser.y"




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
    //  assign_index=-1;//TODO
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
