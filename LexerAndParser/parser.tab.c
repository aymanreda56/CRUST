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
  YYSYMBOL_TYPE = 49,                      /* TYPE  */
  YYSYMBOL_DECLARATION_STT = 50,           /* DECLARATION_STT  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_DECLARATION_TAIL = 53,          /* DECLARATION_TAIL  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_55_4 = 55,                      /* $@4  */
  YYSYMBOL_56_5 = 56,                      /* $@5  */
  YYSYMBOL_RETURN_STT = 57,                /* RETURN_STT  */
  YYSYMBOL_58_6 = 58,                      /* $@6  */
  YYSYMBOL_helperSWITCH = 59,              /* helperSWITCH  */
  YYSYMBOL_SWITCH_STT = 60,                /* SWITCH_STT  */
  YYSYMBOL_DEFAULTCASE = 61,               /* DEFAULTCASE  */
  YYSYMBOL_CASES = 62,                     /* CASES  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_64_8 = 64,                      /* $@8  */
  YYSYMBOL_65_9 = 65,                      /* $@9  */
  YYSYMBOL_66_10 = 66,                     /* $@10  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 67,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_68_11 = 68,                     /* $@11  */
  YYSYMBOL_69_12 = 69,                     /* $@12  */
  YYSYMBOL_70_13 = 70,                     /* $@13  */
  YYSYMBOL_71_14 = 71,                     /* $@14  */
  YYSYMBOL_FUNC_DECLARATION_STT = 72,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_73_15 = 73,                     /* $@15  */
  YYSYMBOL_74_16 = 74,                     /* $@16  */
  YYSYMBOL_75_17 = 75,                     /* $@17  */
  YYSYMBOL_76_18 = 76,                     /* $@18  */
  YYSYMBOL_77_19 = 77,                     /* $@19  */
  YYSYMBOL_78_20 = 78,                     /* $@20  */
  YYSYMBOL_79_21 = 79,                     /* $@21  */
  YYSYMBOL_80_22 = 80,                     /* $@22  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 81, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_82_23 = 82,                     /* $@23  */
  YYSYMBOL_ARGS = 83,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 84,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 85,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 86,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_87_24 = 87,                     /* $@24  */
  YYSYMBOL_ENUM_HELPER = 88,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 89,                 /* ENUM_ARGS  */
  YYSYMBOL_90_25 = 90,                     /* $@25  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 91,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_92_26 = 92,                     /* $@26  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 93, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_CALL_STT = 94,             /* ENUM_CALL_STT  */
  YYSYMBOL_IF_STT_HELPER = 95,             /* IF_STT_HELPER  */
  YYSYMBOL_96_27 = 96,                     /* $@27  */
  YYSYMBOL_IF_STT_HELPER1 = 97,            /* IF_STT_HELPER1  */
  YYSYMBOL_IF_STT = 98,                    /* IF_STT  */
  YYSYMBOL_99_28 = 99,                     /* $@28  */
  YYSYMBOL_100_29 = 100,                   /* $@29  */
  YYSYMBOL_WHILE_STT = 101,                /* WHILE_STT  */
  YYSYMBOL_102_30 = 102,                   /* $@30  */
  YYSYMBOL_103_31 = 103,                   /* $@31  */
  YYSYMBOL_DO_WHILE_STT = 104,             /* DO_WHILE_STT  */
  YYSYMBOL_ERRONOUS_DO_WHILE = 105,        /* ERRONOUS_DO_WHILE  */
  YYSYMBOL_106_32 = 106,                   /* $@32  */
  YYSYMBOL_107_33 = 107,                   /* $@33  */
  YYSYMBOL_108_34 = 108,                   /* $@34  */
  YYSYMBOL_109_35 = 109,                   /* $@35  */
  YYSYMBOL_FOR_STT = 110,                  /* FOR_STT  */
  YYSYMBOL_111_36 = 111,                   /* $@36  */
  YYSYMBOL_112_37 = 112,                   /* $@37  */
  YYSYMBOL_113_38 = 113,                   /* $@38  */
  YYSYMBOL_114_39 = 114,                   /* $@39  */
  YYSYMBOL_ERRONOUS_FOR_LOOP = 115,        /* ERRONOUS_FOR_LOOP  */
  YYSYMBOL_116_40 = 116,                   /* $@40  */
  YYSYMBOL_117_41 = 117,                   /* $@41  */
  YYSYMBOL_helperAssignmentRule = 118,     /* helperAssignmentRule  */
  YYSYMBOL_assignmentSTT = 119,            /* assignmentSTT  */
  YYSYMBOL_120_42 = 120,                   /* $@42  */
  YYSYMBOL_BLOCK = 121,                    /* BLOCK  */
  YYSYMBOL_122_43 = 122,                   /* $@43  */
  YYSYMBOL_FUNC_CALL = 123,                /* FUNC_CALL  */
  YYSYMBOL_124_44 = 124,                   /* $@44  */
  YYSYMBOL_125_45 = 125,                   /* $@45  */
  YYSYMBOL_126_46 = 126,                   /* $@46  */
  YYSYMBOL_USED_ARGS = 127,                /* USED_ARGS  */
  YYSYMBOL_128_47 = 128,                   /* $@47  */
  YYSYMBOL_EXPRESSION = 129,               /* EXPRESSION  */
  YYSYMBOL_130_48 = 130,                   /* $@48  */
  YYSYMBOL_131_49 = 131,                   /* $@49  */
  YYSYMBOL_132_50 = 132,                   /* $@50  */
  YYSYMBOL_133_51 = 133,                   /* $@51  */
  YYSYMBOL_ERRONOUS_EXPRESSION = 134,      /* ERRONOUS_EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 135,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 136,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 137                  /* RES_WORD  */
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
#define YYLAST   1189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  390

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
     212,   220,   221,   222,   223,   227,   227,   228,   228,   229,
     230,   231,   236,   237,   238,   239,   240,   240,   241,   241,
     242,   242,   249,   250,   250,   252,   255,   256,   260,   261,
     264,   264,   264,   264,   265,   265,   266,   267,   269,   278,
     278,   279,   279,   280,   280,   281,   281,   282,   294,   295,
     295,   295,   296,   296,   296,   297,   297,   297,   298,   298,
     298,   303,   303,   313,   314,   315,   318,   321,   328,   328,
     329,   331,   331,   334,   334,   335,   341,   341,   342,   343,
     344,   345,   346,   350,   351,   353,   354,   358,   359,   363,
     363,   366,   370,   371,   372,   373,   373,   374,   374,   375,
     384,   384,   384,   393,   394,   397,   397,   398,   398,   399,
     399,   400,   400,   401,   408,   408,   408,   408,   408,   409,
     413,   413,   414,   414,   421,   425,   426,   427,   427,   432,
     432,   440,   440,   440,   440,   441,   445,   445,   446,   447,
     448,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   463,   465,   465,   466,   466,   469,   469,   470,   471,
     472,   473,   482,   484,   485,   486,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   530,   530,   530,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530
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
  "':'", "'('", "','", "';'", "$accept", "PROGRAM", "STATEMENT", "TYPE",
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

#define YYPACT_NINF (-313)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-162)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -313,   205,  -313,   676,  -313,  -313,  -313,  -313,   -22,   -25,
       5,  -313,  -313,   485,  -313,  -313,    32,    75,     7,    66,
      83,   496,  -313,   110,  -313,  -313,   485,  -313,   -11,  -313,
      97,     0,  -313,  -313,  -313,   -18,  -313,  -313,  -313,    77,
    -313,  -313,  -313,  -313,  -313,  -313,   309,  -313,  -313,  -313,
     984,  -313,  -313,  -313,   485,   145,   313,  -313,   485,   485,
     101,   485,   485,   485,   485,   485,   118,  -313,  -313,    98,
    -313,   485,   405,   106,   485,  1122,   361,    88,   102,     3,
     120,    24,   485,  -313,  -313,    23,   117,   181,   123,  -313,
      76,   126,  -313,   761,  -313,    21,  -313,    51,  -313,   130,
      15,  -313,    34,   144,   -18,  -313,  1007,  -313,   417,   446,
    -313,   154,   156,  -313,  -313,   524,   535,   563,   574,   124,
     485,   124,   485,   158,   136,   172,  -313,   181,   181,   181,
    1145,  1145,  -313,   134,   -18,  1076,   405,   405,   405,  1076,
     123,   167,   147,  -313,    17,   152,   151,    59,    84,   157,
    -313,  -313,  1076,   162,   168,    38,  -313,   485,   159,  -313,
    -313,   269,  -313,    79,   202,   180,    79,    25,   -18,  -313,
     485,  -313,   190,  -313,  -313,   184,  -313,    39,  -313,  -313,
     485,   117,   602,   124,   213,   613,   158,  -313,   485,  -313,
     485,   485,   244,   181,   244,   181,  1159,  1145,  1159,  1145,
     124,   124,    25,   187,  -313,   405,   405,  -313,   193,   189,
     227,   195,  -313,   485,   485,   199,   152,    78,   201,   206,
     152,  -313,   210,   208,   212,  -313,  -313,  1030,   237,   457,
    -313,   485,   641,  -313,  -313,  -313,    25,   218,  -313,    25,
     223,   221,  -313,   220,  -313,  1076,   485,  -313,   225,  -313,
     124,   117,   124,   213,   124,   136,   172,   181,   226,  -313,
     228,   405,   405,   -18,   485,   238,   485,   485,   936,   786,
    -313,   242,   224,  -313,  -313,   245,  -313,   247,  -313,   248,
       0,   252,     0,     0,  -313,  -313,   652,  -313,   811,  1053,
    1099,   706,   251,  -313,  -313,  -313,  -313,    25,   256,   960,
    -313,  -313,   -18,  -313,   258,  -313,  -313,   836,   485,   861,
     886,  -313,  -313,  -313,  -313,   257,   262,  -313,  -313,   263,
       0,   273,   275,   457,   277,   272,  -313,  -313,  -313,   282,
     285,   745,  -313,   -18,  -313,   -18,  -313,   -18,  -313,   -18,
    -313,   405,  -313,   911,  -313,  -313,   295,  -313,   296,  -313,
    -313,  -313,  -313,   457,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,   -18,  -313,  -313,  -313,  -313,   -18,   294,  -313,   322,
    -313,  -313,  -313,  -313,     0,  -313,  -313,  -313,   -18,  -313
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    21,    22,    23,    24,     0,   109,
       0,   120,   164,     0,   165,   166,     0,     0,    43,     0,
       0,     0,   162,     0,   163,   149,     0,     2,     0,     4,
       0,    58,    12,    47,     5,     0,    13,    90,    14,   115,
       8,     9,    11,   124,    10,   139,     0,     6,    15,   179,
       0,   181,   178,   195,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
     117,     0,     0,   134,     0,     0,     0,   167,   125,     0,
       0,     0,     0,    16,    59,     0,   204,   194,   147,   144,
       0,     0,     3,     0,    27,    81,    17,     0,    50,    57,
       0,    68,     0,   112,     0,   145,     0,   174,     0,     0,
       7,   170,     0,   172,   176,     0,     0,     0,     0,   184,
       0,   196,     0,   198,   182,   183,    30,   185,   200,   202,
     205,   207,    29,    72,     0,   110,     0,     0,     0,   121,
       0,     0,     0,   129,     0,     0,     0,    93,     0,     0,
      91,    92,    44,     0,    61,     0,   155,     0,     0,   108,
     152,     0,   180,     0,     0,    69,     0,     0,     0,    49,
       0,    56,     0,    67,    46,     0,   111,     0,   116,   146,
       0,   197,     0,   186,   199,     0,   187,   168,     0,   169,
       0,     0,   201,   190,   203,   191,   206,   192,   208,   193,
     211,   209,     0,     0,   118,     0,     0,   135,     0,     0,
       0,     0,   127,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,     0,    65,    45,     0,     0,     0,
     150,     0,     0,    35,    28,    31,     0,     0,    26,     0,
       0,     0,    85,    84,    48,    51,     0,   119,     0,   113,
     175,   212,   189,   210,   188,   171,   173,   177,     0,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,   102,   101,    96,   100,     0,   105,     0,
      58,     0,    58,    58,   148,   107,     0,   153,   156,     0,
       0,    40,     0,    76,    86,    87,    82,     0,     0,     0,
     114,    73,     0,   140,     0,   136,   122,     0,     0,     0,
       0,   133,   123,   106,    99,     0,    93,    94,    89,     0,
      58,     0,     0,     0,     0,     0,    33,    34,    32,     0,
       0,     0,    70,     0,    83,     0,    55,     0,    80,     0,
     142,     0,   126,     0,   130,   128,     0,    60,     0,    64,
      66,   158,   154,     0,    37,    39,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
      41,     0,    77,    52,    74,   141,     0,     0,   132,     0,
      97,    62,   157,    71,    58,   143,   137,    53,     0,   138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -313,   246,   -70,  -164,  -313,  -313,  -313,   173,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,   241,  -275,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -182,  -313,  -313,
    -313,  -313,  -133,    65,  -313,    -3,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,   -16,  -313,  -313,  -313,  -313,
    -313,  -312,  -313,   -12,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,    28,    29,   166,   163,   234,   329,   330,
     331,    30,    82,    31,    32,    99,   100,   170,   298,   384,
     172,    33,   153,   223,   224,   283,    34,   236,   371,   202,
     337,   237,   333,   203,   302,    35,   167,   241,   242,   243,
      36,   220,   149,   150,   218,   151,   315,    37,    38,    39,
      71,   103,    40,   104,   134,    41,    74,   208,    42,    43,
     141,   267,   211,   142,    44,   138,   262,   341,   388,    45,
     339,   376,    46,    47,   157,    48,    92,    49,    91,   229,
     324,   287,   325,    50,   188,   190,   180,   191,    51,    52,
      53,   370
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    77,   136,   240,   143,   319,    72,   321,   322,    87,
      94,   351,   215,   144,    93,    69,   173,    70,   212,   101,
     258,    25,   -25,   -42,   154,   146,    95,    97,     4,     5,
       6,     7,    98,    78,   106,   175,   -25,   -25,   240,   225,
     248,   382,   119,   121,   123,   348,   124,   125,    73,   127,
     128,   129,   130,   131,   292,   174,   213,   294,   164,   135,
     214,   147,   139,   148,   165,   155,   205,   206,   207,   239,
     152,    25,   240,    25,   217,   240,    80,   226,    25,   272,
     231,   169,    83,   271,    84,   219,   176,   279,   178,   273,
      25,   158,   159,   168,   232,   233,   183,   186,   274,   -95,
     107,   108,   109,   193,   195,   197,   199,   113,   200,   387,
     201,    88,    81,    96,   275,   334,   276,   126,   204,   102,
      85,   -88,  -161,  -161,  -161,    89,  -161,  -161,  -161,  -161,
      55,    56,  -161,   240,   132,   260,   261,   108,   109,  -161,
    -161,   133,  -131,  -161,  -161,   227,    75,    90,   107,   108,
     109,   137,   244,  -151,   112,   113,    12,    97,   245,   145,
     120,   249,   -54,    13,   156,    14,    15,   177,   250,   160,
     252,   187,   109,   254,   189,   -78,   255,   209,   256,   257,
      21,    22,    76,    24,   107,   108,   109,   210,    26,   147,
     216,   304,   305,   107,   108,   109,   228,   221,   111,   112,
     113,   268,   269,   114,   222,     2,     3,   -63,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   288,   235,   289,
     291,   -75,   246,    13,   247,    14,    15,    56,   259,    16,
      17,    18,   264,    19,   299,   263,    20,   265,   266,   270,
      21,    22,    23,    24,    25,   277,   278,   306,    26,   280,
     281,   282,   307,   285,   309,   310,    54,    55,    56,   293,
     295,    58,   296,    59,   297,   300,    61,   301,   314,   303,
       3,   377,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   308,   313,   336,   316,   -98,   338,    13,   318,    14,
      15,   320,   332,    16,    17,    18,   343,    19,   335,   340,
      20,   346,   -95,   347,    21,    22,    23,    24,    25,   230,
      75,   288,    26,   349,    75,   350,   353,   372,   352,   373,
      12,   374,   354,   375,    12,   105,   355,    13,   122,    14,
      15,    13,   379,    14,    15,   386,   381,   217,   161,   238,
     171,   288,   317,   380,    21,    22,    76,    24,    21,    22,
      76,    24,    26,     0,     0,   383,    26,     0,     0,     0,
     385,     0,   140,     0,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,   389,  -161,  -161,  -161,     0,  -161,  -161,  -161,
    -161,     0,  -161,  -161,  -161,  -161,  -161,     0,     0,     0,
    -161,  -161,  -161,  -161,  -161,  -161,     0,     0,     0,     0,
    -161,  -161,  -161,  -161,  -151,  -161,     3,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,   181,     0,
       0,     0,     0,    13,     0,    14,    15,     0,    12,    16,
      17,    18,   182,    19,     0,    13,    20,    14,    15,     0,
      21,    22,    23,    24,    25,     0,     0,   184,    26,     0,
       0,     0,    21,    22,    76,    24,     0,    12,   286,     0,
      26,   185,     0,     0,    13,     0,    14,    15,    12,     0,
       0,     0,     0,     0,     0,    13,     0,    14,    15,     0,
       0,    21,    22,    76,    24,     0,    75,     0,     0,    26,
       0,     0,    21,    22,    76,    24,    12,    86,  -160,     0,
      26,     0,     0,    13,     0,    14,    15,    12,     0,     0,
       0,     0,     0,     0,    13,     0,    14,    15,     0,     0,
      21,    22,    76,    24,     0,   192,     0,     0,    26,     0,
       0,    21,    22,    76,    24,    12,   194,     0,     0,    26,
       0,     0,    13,     0,    14,    15,    12,     0,     0,     0,
       0,     0,     0,    13,     0,    14,    15,     0,     0,    21,
      22,    76,    24,     0,   196,     0,     0,    26,     0,     0,
      21,    22,    76,    24,    12,   198,     0,     0,    26,     0,
       0,    13,     0,    14,    15,    12,     0,     0,     0,     0,
       0,     0,    13,     0,    14,    15,     0,     0,    21,    22,
      76,    24,     0,   251,     0,     0,    26,     0,     0,    21,
      22,    76,    24,    12,   253,     0,     0,    26,     0,     0,
      13,     0,    14,    15,    12,     0,     0,     0,     0,     0,
       0,    13,     0,    14,    15,     0,     0,    21,    22,    76,
      24,     0,   290,     0,     0,    26,     0,     0,    21,    22,
      76,    24,    12,     0,     0,     0,    26,     0,     0,    13,
       0,    14,    15,     0,    54,    55,    56,     0,     0,    58,
       0,    59,     0,     0,    61,     0,    21,    22,    76,    24,
       0,    62,    63,     0,    26,    64,    65,     0,    54,    55,
      56,     0,    57,    58,     0,    59,   323,    60,    61,     0,
       0,     0,     0,     0,     0,    62,    63,     0,     0,    64,
      65,     0,     0,    66,     0,     0,    67,    68,   107,   108,
     109,     0,   328,   111,   112,   113,     0,     0,   114,     0,
       0,     0,     0,     0,     0,   115,   116,     0,     0,   117,
     118,     0,     0,     0,     0,     0,   -36,   -38,   356,   357,
     358,   359,   360,   361,   362,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   364,     0,   365,   366,
     367,     0,     0,   107,   108,   109,   368,   369,   111,   112,
     113,     0,     0,   114,     0,     0,     0,     0,     0,     0,
     115,   116,     0,     0,   117,   118,     0,     0,   107,   108,
     109,     0,   162,   111,   112,   113,     0,     0,   114,     0,
       0,     0,     0,     0,     0,   115,   116,     0,     0,   117,
     118,     0,     0,   107,   108,   109,     0,   312,   111,   112,
     113,     0,     0,   114,     0,     0,     0,     0,     0,     0,
     115,   116,     0,     0,   117,   118,     0,     0,   107,   108,
     109,     0,  -159,   111,   112,   113,     0,     0,   114,     0,
       0,     0,     0,     0,     0,   115,   116,     0,     0,   117,
     118,     0,     0,   107,   108,   109,     0,   342,   111,   112,
     113,     0,     0,   114,     0,     0,     0,     0,     0,     0,
     115,   116,     0,     0,   117,   118,     0,     0,   107,   108,
     109,     0,   344,   111,   112,   113,     0,     0,   114,     0,
       0,     0,     0,     0,     0,   115,   116,     0,     0,   117,
     118,     0,     0,   107,   108,   109,     0,   345,   111,   112,
     113,     0,     0,   114,     0,     0,     0,     0,     0,     0,
     115,   116,     0,     0,   117,   118,     0,     0,   107,   108,
     109,     0,   378,   111,   112,   113,     0,     0,   114,     0,
       0,     0,     0,     0,     0,   115,   116,     0,     0,   117,
     118,     0,   107,   108,   109,     0,   311,   111,   112,   113,
       0,     0,   114,     0,     0,     0,     0,     0,     0,   115,
     116,     0,     0,   117,   118,     0,   107,   108,   109,    25,
     110,   111,   112,   113,     0,     0,   114,     0,     0,     0,
       0,     0,     0,   115,   116,     0,     0,   117,   118,   107,
     108,   109,     0,   179,   111,   112,   113,     0,     0,   114,
       0,     0,     0,     0,     0,     0,   115,   116,     0,     0,
     117,   118,   107,   108,   109,     0,   284,   111,   112,   113,
       0,     0,   114,     0,     0,     0,     0,     0,     0,   115,
     116,     0,     0,   117,   118,   107,   108,   109,     0,   326,
     111,   112,   113,     0,     0,   114,     0,     0,     0,     0,
       0,     0,   115,   116,     0,     0,   117,   118,   107,   108,
     109,     0,     0,   111,   112,   113,     0,     0,   114,     0,
       0,     0,     0,     0,     0,   115,   116,     0,     0,   117,
     118,    54,    55,    56,     0,   327,    58,     0,    59,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,    63,
       0,     0,    64,    65,    54,    55,    56,     0,     0,    58,
       0,    59,     0,     0,    61,     0,     0,     0,     0,     0,
       0,    62,    63,     0,     0,    64,    65,   107,   108,   109,
       0,     0,   111,   112,   113,     0,     0,   114,     0,     0,
       0,    54,    55,    56,   115,   116,    58,     0,    59,     0,
       0,    61,     0,     0,     0,     0,     0,     0,    62,    63
};

static const yytype_int16 yycheck[] =
{
      16,    13,    72,   167,     1,   280,     1,   282,   283,    21,
      21,   323,   145,    10,    26,    37,     1,    42,     1,    35,
     202,    39,     1,    16,     1,     1,    37,    27,     3,     4,
       5,     6,    32,     1,    46,     1,    15,    16,   202,     1,
       1,   353,    54,    55,    56,   320,    58,    59,    43,    61,
      62,    63,    64,    65,   236,    40,    39,   239,    37,    71,
      43,    37,    74,    39,    43,    42,   136,   137,   138,    44,
      82,    39,   236,    39,    15,   239,     1,    39,    39,     1,
       1,    97,    16,   216,     1,     1,   102,   220,   104,    11,
      39,    15,    16,    42,    15,    16,   108,   109,    20,    40,
      12,    13,    14,   115,   116,   117,   118,    19,   120,   384,
     122,     1,    37,    16,    36,   297,    38,    16,   134,    42,
      37,    37,    12,    13,    14,    15,    16,    17,    18,    19,
      13,    14,    22,   297,    16,   205,   206,    13,    14,    29,
      30,    43,    40,    33,    34,   157,     1,    37,    12,    13,
      14,    45,   168,    43,    18,    19,    11,    27,   170,    39,
      15,   177,    32,    18,    41,    20,    21,    23,   180,    43,
     182,    17,    14,   185,    18,    41,   188,    10,   190,   191,
      35,    36,    37,    38,    12,    13,    14,    40,    43,    37,
      39,   261,   262,    12,    13,    14,    37,    40,    17,    18,
      19,   213,   214,    22,    42,     0,     1,    39,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   229,    16,   231,
     232,    41,    32,    18,    40,    20,    21,    14,    41,    24,
      25,    26,    43,    28,   246,    42,    31,    10,    43,    40,
      35,    36,    37,    38,    39,    44,    40,   263,    43,    39,
      42,    39,   264,    16,   266,   267,    12,    13,    14,    41,
      37,    17,    41,    19,    44,    40,    22,    41,    44,    41,
       1,   341,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    43,    40,   299,    37,    40,   302,    18,    40,    20,
      21,    39,    41,    24,    25,    26,   308,    28,    42,    41,
      31,    44,    40,    40,    35,    36,    37,    38,    39,    40,
       1,   323,    43,    40,     1,    40,    44,   333,    41,   335,
      11,   337,    40,   339,    11,    16,    41,    18,    15,    20,
      21,    18,    37,    20,    21,    41,    40,    15,    92,   166,
      99,   353,   277,   346,    35,    36,    37,    38,    35,    36,
      37,    38,    43,    -1,    -1,   371,    43,    -1,    -1,    -1,
     376,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,   388,    12,    13,    14,    -1,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,     1,    -1,
      -1,    -1,    -1,    18,    -1,    20,    21,    -1,    11,    24,
      25,    26,    15,    28,    -1,    18,    31,    20,    21,    -1,
      35,    36,    37,    38,    39,    -1,    -1,     1,    43,    -1,
      -1,    -1,    35,    36,    37,    38,    -1,    11,     1,    -1,
      43,    15,    -1,    -1,    18,    -1,    20,    21,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,
      -1,    35,    36,    37,    38,    -1,     1,    -1,    -1,    43,
      -1,    -1,    35,    36,    37,    38,    11,     1,    41,    -1,
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
      37,    38,    -1,     1,    -1,    -1,    43,    -1,    -1,    35,
      36,    37,    38,    11,     1,    -1,    -1,    43,    -1,    -1,
      18,    -1,    20,    21,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    20,    21,    -1,    -1,    35,    36,    37,
      38,    -1,     1,    -1,    -1,    43,    -1,    -1,    35,    36,
      37,    38,    11,    -1,    -1,    -1,    43,    -1,    -1,    18,
      -1,    20,    21,    -1,    12,    13,    14,    -1,    -1,    17,
      -1,    19,    -1,    -1,    22,    -1,    35,    36,    37,    38,
      -1,    29,    30,    -1,    43,    33,    34,    -1,    12,    13,
      14,    -1,    16,    17,    -1,    19,    44,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    -1,    -1,    37,    -1,    -1,    40,    41,    12,    13,
      14,    -1,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    23,    24,
      25,    -1,    -1,    12,    13,    14,    31,    32,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    33,    34,    -1,    -1,    12,    13,
      14,    -1,    41,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    -1,    -1,    12,    13,    14,    -1,    41,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    33,    34,    -1,    -1,    12,    13,
      14,    -1,    41,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    -1,    -1,    12,    13,    14,    -1,    41,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    33,    34,    -1,    -1,    12,    13,
      14,    -1,    41,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    -1,    -1,    12,    13,    14,    -1,    41,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    33,    34,    -1,    -1,    12,    13,
      14,    -1,    41,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    -1,    12,    13,    14,    -1,    40,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    -1,    12,    13,    14,    39,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      33,    34,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    33,    34,    12,    13,
      14,    -1,    -1,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    12,    13,    14,    -1,    16,    17,    -1,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    33,    34,    12,    13,    14,    -1,    -1,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    33,    34,    12,    13,    14,
      -1,    -1,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    12,    13,    14,    29,    30,    17,    -1,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    18,    20,    21,    24,    25,    26,    28,
      31,    35,    36,    37,    38,    39,    43,    48,    49,    50,
      57,    59,    60,    67,    72,    81,    86,    93,    94,    95,
      98,   101,   104,   105,   110,   115,   118,   119,   121,   123,
     129,   134,   135,   136,    12,    13,    14,    16,    17,    19,
      21,    22,    29,    30,    33,    34,    37,    40,    41,    37,
      42,    96,     1,    43,   102,     1,    37,   129,     1,   121,
       1,    37,    58,    16,     1,    37,     1,   129,     1,    15,
      37,   124,   122,   129,    21,    37,    16,    27,    32,    61,
      62,   121,    42,    97,    99,    16,   129,    12,    13,    14,
      16,    17,    18,    19,    22,    29,    30,    33,    34,   129,
      15,   129,    15,   129,   129,   129,    16,   129,   129,   129,
     129,   129,    16,    43,   100,   129,    48,    45,   111,   129,
       1,   106,   109,     1,    10,    39,     1,    37,    39,    88,
      89,    91,   129,    68,     1,    42,    41,   120,    15,    16,
      43,    47,    41,    52,    37,    43,    51,    82,    42,   121,
      63,    61,    66,     1,    40,     1,   121,    23,   121,    16,
     132,     1,    15,   129,     1,    15,   129,    17,   130,    18,
     131,   133,     1,   129,     1,   129,     1,   129,     1,   129,
     129,   129,    75,    79,   121,    48,    48,    48,   103,    10,
      40,   108,     1,    39,    43,    88,    39,    15,    90,     1,
      87,    40,    42,    69,    70,     1,    39,   129,    37,   125,
      40,     1,    15,    16,    53,    16,    73,    77,    53,    44,
      49,    83,    84,    85,   121,   129,    32,    40,     1,   121,
     129,     1,   129,     1,   129,   129,   129,   129,    83,    41,
      48,    48,   112,    42,    43,    10,    43,   107,   129,   129,
      40,    88,     1,    11,    20,    36,    38,    44,    40,    88,
      39,    42,    39,    71,    16,    16,     1,   127,   129,   129,
       1,   129,    83,    41,    83,    37,    41,    44,    64,   129,
      40,    41,    80,    41,    48,    48,   121,   129,    43,   129,
     129,    40,    41,    40,    44,    92,    37,    89,    40,    62,
      39,    62,    62,    44,   126,   128,    16,    16,    16,    54,
      55,    56,    41,    78,    83,    42,   121,    76,   121,   116,
      41,   113,    41,   129,    41,    41,    44,    40,    62,    40,
      40,   127,    41,    44,    40,    41,     3,     4,     5,     6,
       7,     8,     9,    10,    21,    23,    24,    25,    31,    32,
     137,    74,   121,   121,   121,   121,   117,    48,    41,    37,
      91,    40,   127,   121,    65,   121,    41,    62,   114,   121
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    49,    49,    51,    50,    52,    50,    50,
      50,    50,    53,    53,    53,    53,    54,    53,    55,    53,
      56,    53,    57,    58,    57,    59,    60,    60,    61,    61,
      63,    64,    65,    62,    66,    62,    62,    62,    62,    68,
      67,    69,    67,    70,    67,    71,    67,    67,    72,    73,
      74,    72,    75,    76,    72,    77,    78,    72,    79,    80,
      72,    82,    81,    83,    83,    83,    84,    85,    87,    86,
      86,    88,    88,    90,    89,    89,    92,    91,    91,    91,
      91,    91,    91,    93,    93,    93,    93,    94,    94,    96,
      95,    97,    98,    98,    98,    99,    98,   100,    98,    98,
     102,   103,   101,   104,   104,   106,   105,   107,   105,   108,
     105,   109,   105,   105,   111,   112,   113,   114,   110,   110,
     116,   115,   117,   115,   118,   119,   119,   120,   119,   122,
     121,   124,   125,   126,   123,   123,   128,   127,   127,   127,
     127,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   129,   131,   129,   132,   129,   133,   129,   129,   129,
     129,   129,   134,   134,   134,   134,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     0,     4,     0,     4,     3,
       3,     4,     3,     3,     3,     1,     0,     4,     0,     4,
       0,     4,     1,     0,     3,     4,     3,     1,     3,     2,
       0,     0,     0,     8,     0,     5,     2,     1,     0,     0,
       7,     0,     8,     0,     7,     0,     7,     3,     2,     0,
       0,     8,     0,     0,     8,     0,     0,     7,     0,     0,
       7,     0,     5,     3,     1,     1,     2,     2,     0,     6,
       1,     1,     1,     0,     4,     1,     0,     6,     3,     4,
       3,     3,     3,     5,     4,     5,     6,     5,     3,     0,
       3,     2,     2,     4,     5,     0,     3,     0,     4,     4,
       0,     0,     6,     6,     1,     0,     7,     0,     7,     0,
       7,     0,     8,     6,     0,     0,     0,     0,    11,     1,
       0,     8,     0,     9,     2,     2,     3,     0,     5,     0,
       4,     0,     0,     0,     7,     3,     0,     4,     3,     1,
       0,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     1,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     4,     4,
       3,     3,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 1781 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 197 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1787 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 200 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1793 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 201 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1799 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 202 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1805 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 203 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1811 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 204 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1817 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 205 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1823 "parser.tab.c"
    break;

  case 14: /* STATEMENT: ENUM_CALL_STT  */
#line 206 "parser.y"
                                                            {printf("#[Parsed_Enum_USAGE]# ");}
#line 1829 "parser.tab.c"
    break;

  case 16: /* STATEMENT: BREAK SEMICOLON  */
#line 208 "parser.y"
                                                            {StAssJmp("JMP", "END", &SMLabel_End, 0, 0);}
#line 1835 "parser.tab.c"
    break;

  case 18: /* STATEMENT: error SEMICOLON  */
#line 210 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1841 "parser.tab.c"
    break;

  case 19: /* STATEMENT: error '}'  */
#line 211 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1847 "parser.tab.c"
    break;

  case 20: /* STATEMENT: error ')'  */
#line 212 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1853 "parser.tab.c"
    break;

  case 21: /* TYPE: INT  */
#line 220 "parser.y"
                            { (yyval.str) = "int";   }
#line 1859 "parser.tab.c"
    break;

  case 22: /* TYPE: FLOAT  */
#line 221 "parser.y"
                            { (yyval.str) = "float"; }
#line 1865 "parser.tab.c"
    break;

  case 23: /* TYPE: BOOL  */
#line 222 "parser.y"
                            { (yyval.str) = "bool";  }
#line 1871 "parser.tab.c"
    break;

  case 24: /* TYPE: STRING  */
#line 223 "parser.y"
                            { (yyval.str) = "string";}
#line 1877 "parser.tab.c"
    break;

  case 25: /* $@1: %empty  */
#line 227 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0);   assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1883 "parser.tab.c"
    break;

  case 26: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 227 "parser.y"
                                                                                                                                                         {printf("#[Parsed_Declaration]# "); }
#line 1889 "parser.tab.c"
    break;

  case 27: /* $@2: %empty  */
#line 228 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0); assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1895 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 228 "parser.y"
                                                                                                                                                         {printf("#[Parsed_CONST_Declaration]# "); }
#line 1901 "parser.tab.c"
    break;

  case 29: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 229 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);pErr(yylineno);}
#line 1907 "parser.tab.c"
    break;

  case 30: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 230 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);pErr(yylineno);}
#line 1913 "parser.tab.c"
    break;

  case 31: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 231 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);pErr(yylineno);}
#line 1919 "parser.tab.c"
    break;

  case 32: /* DECLARATION_TAIL: EQ EXPRESSION SEMICOLON  */
#line 236 "parser.y"
                                                                                            {StAssPush(strdup(IdentifierHolder)); StAssPrint("OVER", 1); StAssPrint("STORE", 1); StAssPrint("DROP", 1);}
#line 1925 "parser.tab.c"
    break;

  case 33: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 237 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 1931 "parser.tab.c"
    break;

  case 34: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 238 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);pErr(yylineno);}
#line 1937 "parser.tab.c"
    break;

  case 36: /* $@3: %empty  */
#line 240 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1943 "parser.tab.c"
    break;

  case 38: /* $@4: %empty  */
#line 241 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1949 "parser.tab.c"
    break;

  case 40: /* $@5: %empty  */
#line 242 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1955 "parser.tab.c"
    break;

  case 42: /* RETURN_STT: RETURN  */
#line 249 "parser.y"
                                                {int dum = 0;StAssPrint("POP\tPC",1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1961 "parser.tab.c"
    break;

  case 43: /* $@6: %empty  */
#line 250 "parser.y"
                         {assign_index =func_index;}
#line 1967 "parser.tab.c"
    break;

  case 44: /* RETURN_STT: RETURN $@6 EXPRESSION  */
#line 250 "parser.y"
                                                                            { return_exist = 1; StAssPrint("OVER",1);int dum = 0;StAssPrint("POP\tPC",1);StAssPrint("DNEXT", 1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 1973 "parser.tab.c"
    break;

  case 45: /* helperSWITCH: SWITCH IDENTIFIER ':' '{'  */
#line 252 "parser.y"
                                          {strcpy(switcher, (yyvsp[-2].str));}
#line 1979 "parser.tab.c"
    break;

  case 46: /* SWITCH_STT: helperSWITCH CASES '}'  */
#line 255 "parser.y"
                                        {StAssPrintLBL(0,1);}
#line 1985 "parser.tab.c"
    break;

  case 48: /* DEFAULTCASE: DEFAULT ':' BLOCK  */
#line 260 "parser.y"
                                  {StAssJmp("JMP", "END",&SMLabel_End, 0,0); }
#line 1991 "parser.tab.c"
    break;

  case 49: /* DEFAULTCASE: DEFAULT BLOCK  */
#line 261 "parser.y"
                                {printf("\n\n=====ERROR====\n missing colon ':' at DEFAULT CASE of switch, error at line %d\n\n", yylineno); pErr(yylineno);}
#line 1997 "parser.tab.c"
    break;

  case 50: /* $@7: %empty  */
#line 264 "parser.y"
                     {StAssPush(switcher);}
#line 2003 "parser.tab.c"
    break;

  case 51: /* $@8: %empty  */
#line 264 "parser.y"
                                                       {StAssPrint("EQ", 1); StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2009 "parser.tab.c"
    break;

  case 52: /* $@9: %empty  */
#line 264 "parser.y"
                                                                                                                                   {StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2015 "parser.tab.c"
    break;

  case 54: /* $@10: %empty  */
#line 265 "parser.y"
                              {printf("\n\n=====ERROR====\n DEFAULT CASE must be written at the end of the switch statement, error at line %d\n\n", yylineno); pErr(yylineno);}
#line 2021 "parser.tab.c"
    break;

  case 56: /* CASES: DEFAULTCASE DEFAULTCASE  */
#line 266 "parser.y"
                                                                {printf("\n\n=====ERROR====\n only 1 DEFAULT CASE is allowed in the switch statement error, at line %d\n\n", yylineno); pErr(yylineno);}
#line 2027 "parser.tab.c"
    break;

  case 59: /* $@11: %empty  */
#line 278 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2033 "parser.tab.c"
    break;

  case 61: /* $@12: %empty  */
#line 279 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); pErr(yylineno);}
#line 2039 "parser.tab.c"
    break;

  case 63: /* $@13: %empty  */
#line 280 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);pErr(yylineno);}
#line 2045 "parser.tab.c"
    break;

  case 65: /* $@14: %empty  */
#line 281 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2051 "parser.tab.c"
    break;

  case 67: /* ERRONOUS_SWITCH_STT: helperSWITCH CASES error  */
#line 282 "parser.y"
                                           {printf("\n\n=====ERROR====\n unclosed '}' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2057 "parser.tab.c"
    break;

  case 69: /* $@15: %empty  */
#line 295 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2063 "parser.tab.c"
    break;

  case 70: /* $@16: %empty  */
#line 295 "parser.y"
                                                                                                                    {func_index = st_insert((yyvsp[-5].str), (yyvsp[-4].str),"func",0); popArgs();}
#line 2069 "parser.tab.c"
    break;

  case 72: /* $@17: %empty  */
#line 296 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2075 "parser.tab.c"
    break;

  case 73: /* $@18: %empty  */
#line 296 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-4].str),"func",0); popArgs();}
#line 2081 "parser.tab.c"
    break;

  case 75: /* $@19: %empty  */
#line 297 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2087 "parser.tab.c"
    break;

  case 76: /* $@20: %empty  */
#line 297 "parser.y"
                                                                                                                    {func_index=st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2093 "parser.tab.c"
    break;

  case 78: /* $@21: %empty  */
#line 298 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2099 "parser.tab.c"
    break;

  case 79: /* $@22: %empty  */
#line 298 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-3].str),"func",0);}
#line 2105 "parser.tab.c"
    break;

  case 81: /* $@23: %empty  */
#line 303 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));pErr(yylineno);}
#line 2111 "parser.tab.c"
    break;

  case 82: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@23 ARGS ')'  */
#line 303 "parser.y"
                                                                                                                                                                                                                   {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2117 "parser.tab.c"
    break;

  case 86: /* ERRONOUS_ARGS: ',' ARGS  */
#line 318 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);pErr(yylineno);}
#line 2123 "parser.tab.c"
    break;

  case 87: /* ARG_DECL: TYPE IDENTIFIER  */
#line 321 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1); char* buf=(yyvsp[0].str); argumentList[argPointer]=buf;argPointer++;}
#line 2129 "parser.tab.c"
    break;

  case 88: /* $@24: %empty  */
#line 328 "parser.y"
                                      { is_enum =1;}
#line 2135 "parser.tab.c"
    break;

  case 89: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' $@24 ENUM_HELPER '}'  */
#line 328 "parser.y"
                                                                              { st_insert("enum" , (yyvsp[-4].str), "var" , 0); is_enum=0; enumCNT=1;}
#line 2141 "parser.tab.c"
    break;

  case 93: /* $@25: %empty  */
#line 334 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++;  st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int(  enum_arg_count-1,st_index-1); }
#line 2147 "parser.tab.c"
    break;

  case 95: /* ENUM_ARGS: IDENTIFIER  */
#line 335 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++; st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int( enum_arg_count-1,st_index-1);  }
#line 2153 "parser.tab.c"
    break;

  case 96: /* $@26: %empty  */
#line 341 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++ ; st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2159 "parser.tab.c"
    break;

  case 98: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ DIGIT  */
#line 342 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++;  st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2165 "parser.tab.c"
    break;

  case 99: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ error ','  */
#line 343 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2171 "parser.tab.c"
    break;

  case 100: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ FLOAT_DIGIT  */
#line 344 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2177 "parser.tab.c"
    break;

  case 101: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ STRING_LITERAL  */
#line 345 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2183 "parser.tab.c"
    break;

  case 102: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ BOOL_LITERAL  */
#line 346 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2189 "parser.tab.c"
    break;

  case 103: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 350 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2195 "parser.tab.c"
    break;

  case 104: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 351 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2201 "parser.tab.c"
    break;

  case 105: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 353 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2207 "parser.tab.c"
    break;

  case 106: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER error '{' ENUM_HELPER '}'  */
#line 354 "parser.y"
                                                            {printf("\n\n=====ERROR====\n UnExpected IDENTIFIER in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2213 "parser.tab.c"
    break;

  case 107: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER EQ IDENTIFIER SEMICOLON  */
#line 358 "parser.y"
                                                               { StAssPush((yyvsp[-3].str));StAssPush((yyvsp[-1].str));StAssPrint("STORE",1); st_insert((yyvsp[-4].str) , (yyvsp[-3].str), "var_enum" , 0); assign_enum(st_index-1, (yyvsp[-4].str),(yyvsp[-1].str)); int i= lookup((yyvsp[-4].str), 0); symbolTable[i].isUsed=1; }
#line 2219 "parser.tab.c"
    break;

  case 108: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER SEMICOLON  */
#line 359 "parser.y"
                                                   { st_insert((yyvsp[-2].str) , (yyvsp[-1].str), "var_enum" , 0); int i= lookup((yyvsp[-2].str),0); symbolTable[i].isUsed=1;}
#line 2225 "parser.tab.c"
    break;

  case 109: /* $@27: %empty  */
#line 363 "parser.y"
                   {printIF();}
#line 2231 "parser.tab.c"
    break;

  case 110: /* IF_STT_HELPER: IF $@27 EXPRESSION  */
#line 363 "parser.y"
                                           {StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2237 "parser.tab.c"
    break;

  case 111: /* IF_STT_HELPER1: ':' BLOCK  */
#line 366 "parser.y"
                                                            {controlTerminator(0);  StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2243 "parser.tab.c"
    break;

  case 112: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1  */
#line 370 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2249 "parser.tab.c"
    break;

  case 113: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE BLOCK  */
#line 371 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2255 "parser.tab.c"
    break;

  case 114: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE error '}'  */
#line 372 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2261 "parser.tab.c"
    break;

  case 115: /* $@28: %empty  */
#line 373 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2267 "parser.tab.c"
    break;

  case 117: /* $@29: %empty  */
#line 374 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2273 "parser.tab.c"
    break;

  case 119: /* IF_STT: IF_STT_HELPER ':' error '}'  */
#line 375 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2279 "parser.tab.c"
    break;

  case 120: /* $@30: %empty  */
#line 384 "parser.y"
                      {printWHILE(); StAssPrintLBL(1, 0);}
#line 2285 "parser.tab.c"
    break;

  case 121: /* $@31: %empty  */
#line 384 "parser.y"
                                                                      {StAssJmp("JNZ", "END",&SMLabel_End, 0,0);}
#line 2291 "parser.tab.c"
    break;

  case 122: /* WHILE_STT: WHILE $@30 EXPRESSION $@31 ':' BLOCK  */
#line 384 "parser.y"
                                                                                                                            {StAssJmp("JMP", "LBL",&SMLabel_Else, 1,0); StAssPrintLBL(0, 1);}
#line 2297 "parser.tab.c"
    break;

  case 125: /* $@32: %empty  */
#line 397 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2303 "parser.tab.c"
    break;

  case 127: /* $@33: %empty  */
#line 398 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2309 "parser.tab.c"
    break;

  case 129: /* $@34: %empty  */
#line 399 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2315 "parser.tab.c"
    break;

  case 131: /* $@35: %empty  */
#line 400 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2321 "parser.tab.c"
    break;

  case 133: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 401 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);pErr(yylineno);}
#line 2327 "parser.tab.c"
    break;

  case 134: /* $@36: %empty  */
#line 408 "parser.y"
                        {in_loop = 1;}
#line 2333 "parser.tab.c"
    break;

  case 135: /* $@37: %empty  */
#line 408 "parser.y"
                                                 {StAssForHeader();}
#line 2339 "parser.tab.c"
    break;

  case 136: /* $@38: %empty  */
#line 408 "parser.y"
                                                                               {StAssForMiddle();}
#line 2345 "parser.tab.c"
    break;

  case 137: /* $@39: %empty  */
#line 408 "parser.y"
                                                                                                                {StAssPrintLBL(1,1); in_loop = 0;}
#line 2351 "parser.tab.c"
    break;

  case 138: /* FOR_STT: FOR '(' $@36 STATEMENT $@37 STATEMENT $@38 STATEMENT ')' $@39 BLOCK  */
#line 408 "parser.y"
                                                                                                                                                          {StAssJmp("JMP", "Label", &ForHeaderLabel,1,0); StAssPrintLBL(0,1);}
#line 2357 "parser.tab.c"
    break;

  case 140: /* $@40: %empty  */
#line 413 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2363 "parser.tab.c"
    break;

  case 142: /* $@41: %empty  */
#line 414 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2369 "parser.tab.c"
    break;

  case 144: /* helperAssignmentRule: IDENTIFIER EQ  */
#line 421 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); StAssPush((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str),1);}
#line 2375 "parser.tab.c"
    break;

  case 145: /* assignmentSTT: helperAssignmentRule SEMICOLON  */
#line 425 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2381 "parser.tab.c"
    break;

  case 146: /* assignmentSTT: helperAssignmentRule EXPRESSION SEMICOLON  */
#line 426 "parser.y"
                                                                 {StAssPrint("STORE", 1); CodeGenAss();printf("#[Parsed_Assignment]# ");}
#line 2387 "parser.tab.c"
    break;

  case 147: /* $@42: %empty  */
#line 427 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str),1); StAssPush((yyvsp[-1].str));}
#line 2393 "parser.tab.c"
    break;

  case 148: /* assignmentSTT: IDENTIFIER error $@42 EXPRESSION SEMICOLON  */
#line 427 "parser.y"
                                                                                                                                                        {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2399 "parser.tab.c"
    break;

  case 149: /* $@43: %empty  */
#line 432 "parser.y"
                    {scope_start();}
#line 2405 "parser.tab.c"
    break;

  case 150: /* BLOCK: '{' $@43 PROGRAM '}'  */
#line 432 "parser.y"
                                                                              {scope_end(); printf("#[Parsed_Block]# ");}
#line 2411 "parser.tab.c"
    break;

  case 151: /* $@44: %empty  */
#line 440 "parser.y"
                           {called_func_index = lookup((yyvsp[0].str),0); check_type(called_func_index); StAssPush("PC");}
#line 2417 "parser.tab.c"
    break;

  case 152: /* $@45: %empty  */
#line 440 "parser.y"
                                                                                                                   { is_param =1;}
#line 2423 "parser.tab.c"
    break;

  case 153: /* $@46: %empty  */
#line 440 "parser.y"
                                                                                                                                              { is_param =0; arg_count_check(called_func_index); arg_count=0; int dum=0; StAssJmp("JMP", (yyvsp[-4].str),&dum, 0,0);}
#line 2429 "parser.tab.c"
    break;

  case 154: /* FUNC_CALL: IDENTIFIER $@44 '(' $@45 USED_ARGS $@46 ')'  */
#line 440 "parser.y"
                                                                                                                                                                                                                                                               { printf("#[Parsed_Func_Call]# ");}
#line 2435 "parser.tab.c"
    break;

  case 155: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 441 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);pErr(yylineno);}
#line 2441 "parser.tab.c"
    break;

  case 156: /* $@47: %empty  */
#line 445 "parser.y"
                           { arg_count++; }
#line 2447 "parser.tab.c"
    break;

  case 158: /* USED_ARGS: error ',' USED_ARGS  */
#line 446 "parser.y"
                                                            {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2453 "parser.tab.c"
    break;

  case 159: /* USED_ARGS: EXPRESSION  */
#line 447 "parser.y"
                             {arg_count++ ;}
#line 2459 "parser.tab.c"
    break;

  case 161: /* EXPRESSION: IDENTIFIER  */
#line 454 "parser.y"
                                                { int i = lookup((yyvsp[0].str),0); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2465 "parser.tab.c"
    break;

  case 162: /* EXPRESSION: DIGIT  */
#line 455 "parser.y"
                                                { assign_int((yyvsp[0].num), assign_index) ; char numtostring[40]; itoa((yyvsp[0].num), numtostring, 10); pushVStack(numtostring); char dum[10]="$"; StAssPush(strcat(dum,numtostring));}
#line 2471 "parser.tab.c"
    break;

  case 163: /* EXPRESSION: FLOAT_DIGIT  */
#line 456 "parser.y"
                                                { assign_int((yyvsp[0].float_val), assign_index); char floattostring[40]; gcvt((yyvsp[0].float_val), 6, floattostring); pushVStack(floattostring); char dum[10]="$"; StAssPush(strcat(dum,floattostring));}
#line 2477 "parser.tab.c"
    break;

  case 164: /* EXPRESSION: BOOL_LITERAL  */
#line 457 "parser.y"
                                                { assign_int((yyvsp[0].bool_val), assign_index); if((yyvsp[0].bool_val)==true){pushVStack("true");StAssPush("$true");}else{pushVStack("false");StAssPush("$false");} }
#line 2483 "parser.tab.c"
    break;

  case 165: /* EXPRESSION: STRING_LITERAL  */
#line 458 "parser.y"
                                                { assign_str((yyvsp[0].str), assign_index); pushVStack((yyvsp[0].str));char buf[50]; strcpy(buf, "$");strcat(buf, (yyvsp[0].str)); StAssPush(buf);}
#line 2489 "parser.tab.c"
    break;

  case 166: /* EXPRESSION: CONSTANT  */
#line 459 "parser.y"
                                                { int i = lookup((yyvsp[0].str),0); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2495 "parser.tab.c"
    break;

  case 167: /* EXPRESSION: SUB EXPRESSION  */
#line 460 "parser.y"
                                                {StAssPrint("neg", 1);}
#line 2501 "parser.tab.c"
    break;

  case 168: /* EXPRESSION: EXPRESSION PLUS PLUS  */
#line 461 "parser.y"
                                                { pushVStack("+"); pushVStack("1"); CodeGenOp("ADD"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("ADD", 1); StAssPrint("STORE", 1);}
#line 2507 "parser.tab.c"
    break;

  case 169: /* EXPRESSION: EXPRESSION SUB SUB  */
#line 462 "parser.y"
                                                { pushVStack("-"); pushVStack("1"); CodeGenOp("SUB"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("SUB", 1); StAssPrint("STORE", 1);}
#line 2513 "parser.tab.c"
    break;

  case 170: /* $@48: %empty  */
#line 463 "parser.y"
                                                { pushVStack("+");}
#line 2519 "parser.tab.c"
    break;

  case 171: /* EXPRESSION: EXPRESSION PLUS $@48 EXPRESSION  */
#line 463 "parser.y"
                                                                                 {CodeGenOp("ADD"); StAssPrint("ADD", 1);}
#line 2525 "parser.tab.c"
    break;

  case 172: /* $@49: %empty  */
#line 465 "parser.y"
                                                { pushVStack("*");}
#line 2531 "parser.tab.c"
    break;

  case 173: /* EXPRESSION: EXPRESSION MUL $@49 EXPRESSION  */
#line 465 "parser.y"
                                                                                 {CodeGenOp("MUL"); StAssPrint("MUL", 1);}
#line 2537 "parser.tab.c"
    break;

  case 174: /* $@50: %empty  */
#line 466 "parser.y"
                                                { pushVStack("/");}
#line 2543 "parser.tab.c"
    break;

  case 175: /* EXPRESSION: EXPRESSION DIV $@50 EXPRESSION  */
#line 466 "parser.y"
                                                                                 {CodeGenOp("DIV"); StAssPrint("DIV", 1);}
#line 2549 "parser.tab.c"
    break;

  case 176: /* $@51: %empty  */
#line 469 "parser.y"
                                                {pushVStack("^");}
#line 2555 "parser.tab.c"
    break;

  case 177: /* EXPRESSION: EXPRESSION POW $@51 EXPRESSION  */
#line 469 "parser.y"
                                                                               {CodeGenOp("POW");}
#line 2561 "parser.tab.c"
    break;

  case 181: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 473 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);pErr(yylineno);}
#line 2567 "parser.tab.c"
    break;

  case 186: /* COMPARISONSTT: EXPRESSION GT EXPRESSION  */
#line 493 "parser.y"
                                                        {pushVStack(">"); CodeGenLogical(); StAssPrint("GT", 1);}
#line 2573 "parser.tab.c"
    break;

  case 187: /* COMPARISONSTT: EXPRESSION LT EXPRESSION  */
#line 494 "parser.y"
                                                        {pushVStack("<"); CodeGenLogical(); StAssPrint("LT", 1);}
#line 2579 "parser.tab.c"
    break;

  case 188: /* COMPARISONSTT: EXPRESSION LT EQ EXPRESSION  */
#line 495 "parser.y"
                                                        {pushVStack("<="); CodeGenLogical(); StAssPrint("LE", 1);}
#line 2585 "parser.tab.c"
    break;

  case 189: /* COMPARISONSTT: EXPRESSION GT EQ EXPRESSION  */
#line 496 "parser.y"
                                                        {pushVStack(">="); CodeGenLogical(); StAssPrint("GE", 1);}
#line 2591 "parser.tab.c"
    break;

  case 190: /* COMPARISONSTT: EXPRESSION EQUALITY EXPRESSION  */
#line 497 "parser.y"
                                                        {pushVStack("="); CodeGenLogical(); StAssPrint("EQ", 1);}
#line 2597 "parser.tab.c"
    break;

  case 191: /* COMPARISONSTT: EXPRESSION NEG_EQUALITY EXPRESSION  */
#line 498 "parser.y"
                                                        {pushVStack("!="); CodeGenLogical(); StAssPrint("NE", 1);}
#line 2603 "parser.tab.c"
    break;

  case 192: /* COMPARISONSTT: EXPRESSION LOGIC_AND EXPRESSION  */
#line 499 "parser.y"
                                                        {pushVStack("and"); CodeGenLogical(); StAssPrint("AND", 1);}
#line 2609 "parser.tab.c"
    break;

  case 193: /* COMPARISONSTT: EXPRESSION LOGIC_OR EXPRESSION  */
#line 500 "parser.y"
                                                        {pushVStack("or"); CodeGenLogical(); StAssPrint("OR", 1);}
#line 2615 "parser.tab.c"
    break;

  case 194: /* COMPARISONSTT: LOGIC_NOT EXPRESSION  */
#line 501 "parser.y"
                                                        {StAssPrint("neg", 1);}
#line 2621 "parser.tab.c"
    break;

  case 196: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 506 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2627 "parser.tab.c"
    break;

  case 197: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 507 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2633 "parser.tab.c"
    break;

  case 198: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 508 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2639 "parser.tab.c"
    break;

  case 199: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 509 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2645 "parser.tab.c"
    break;

  case 200: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 510 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2651 "parser.tab.c"
    break;

  case 201: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 511 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2657 "parser.tab.c"
    break;

  case 202: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 512 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2663 "parser.tab.c"
    break;

  case 203: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 513 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2669 "parser.tab.c"
    break;

  case 204: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 514 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2675 "parser.tab.c"
    break;

  case 205: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 515 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2681 "parser.tab.c"
    break;

  case 206: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 516 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2687 "parser.tab.c"
    break;

  case 207: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 517 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2693 "parser.tab.c"
    break;

  case 208: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 518 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2699 "parser.tab.c"
    break;

  case 209: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 519 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2705 "parser.tab.c"
    break;

  case 210: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 520 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2711 "parser.tab.c"
    break;

  case 211: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 521 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2717 "parser.tab.c"
    break;

  case 212: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 522 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2723 "parser.tab.c"
    break;


#line 2727 "parser.tab.c"

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

#line 541 "parser.y"




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
