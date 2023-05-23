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
  YYSYMBOL_MODULO = 30,                    /* MODULO  */
  YYSYMBOL_DEC = 31,                       /* DEC  */
  YYSYMBOL_INC = 32,                       /* INC  */
  YYSYMBOL_EQUALITY = 33,                  /* EQUALITY  */
  YYSYMBOL_NEG_EQUALITY = 34,              /* NEG_EQUALITY  */
  YYSYMBOL_SWITCH = 35,                    /* SWITCH  */
  YYSYMBOL_CASE = 36,                      /* CASE  */
  YYSYMBOL_LOGIC_AND = 37,                 /* LOGIC_AND  */
  YYSYMBOL_LOGIC_OR = 38,                  /* LOGIC_OR  */
  YYSYMBOL_LOGIC_NOT = 39,                 /* LOGIC_NOT  */
  YYSYMBOL_DIGIT = 40,                     /* DIGIT  */
  YYSYMBOL_IDENTIFIER = 41,                /* IDENTIFIER  */
  YYSYMBOL_FLOAT_DIGIT = 42,               /* FLOAT_DIGIT  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* ':'  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_PROGRAM = 51,                   /* PROGRAM  */
  YYSYMBOL_STATEMENT = 52,                 /* STATEMENT  */
  YYSYMBOL_SEMICOLON_MISS = 53,            /* SEMICOLON_MISS  */
  YYSYMBOL_TYPE = 54,                      /* TYPE  */
  YYSYMBOL_DECLARATION_STT = 55,           /* DECLARATION_STT  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_DECLARATION_TAIL = 58,          /* DECLARATION_TAIL  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_RETURN_STT = 62,                /* RETURN_STT  */
  YYSYMBOL_63_6 = 63,                      /* $@6  */
  YYSYMBOL_helperSWITCH = 64,              /* helperSWITCH  */
  YYSYMBOL_SWITCH_STT = 65,                /* SWITCH_STT  */
  YYSYMBOL_DEFAULTCASE = 66,               /* DEFAULTCASE  */
  YYSYMBOL_CASES = 67,                     /* CASES  */
  YYSYMBOL_68_7 = 68,                      /* $@7  */
  YYSYMBOL_69_8 = 69,                      /* $@8  */
  YYSYMBOL_70_9 = 70,                      /* $@9  */
  YYSYMBOL_71_10 = 71,                     /* $@10  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 72,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_73_11 = 73,                     /* $@11  */
  YYSYMBOL_74_12 = 74,                     /* $@12  */
  YYSYMBOL_75_13 = 75,                     /* $@13  */
  YYSYMBOL_76_14 = 76,                     /* $@14  */
  YYSYMBOL_FUNC_DECLARATION_STT = 77,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_78_15 = 78,                     /* $@15  */
  YYSYMBOL_79_16 = 79,                     /* $@16  */
  YYSYMBOL_80_17 = 80,                     /* $@17  */
  YYSYMBOL_81_18 = 81,                     /* $@18  */
  YYSYMBOL_82_19 = 82,                     /* $@19  */
  YYSYMBOL_83_20 = 83,                     /* $@20  */
  YYSYMBOL_84_21 = 84,                     /* $@21  */
  YYSYMBOL_85_22 = 85,                     /* $@22  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 86, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_87_23 = 87,                     /* $@23  */
  YYSYMBOL_ARGS = 88,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 89,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 90,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 91,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_92_24 = 92,                     /* $@24  */
  YYSYMBOL_ENUM_HELPER = 93,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 94,                 /* ENUM_ARGS  */
  YYSYMBOL_95_25 = 95,                     /* $@25  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 96,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_97_26 = 97,                     /* $@26  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 98, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_CALL_STT = 99,             /* ENUM_CALL_STT  */
  YYSYMBOL_IF_STT_HELPER = 100,            /* IF_STT_HELPER  */
  YYSYMBOL_101_27 = 101,                   /* $@27  */
  YYSYMBOL_IF_STT_HELPER1 = 102,           /* IF_STT_HELPER1  */
  YYSYMBOL_IF_STT = 103,                   /* IF_STT  */
  YYSYMBOL_104_28 = 104,                   /* $@28  */
  YYSYMBOL_105_29 = 105,                   /* $@29  */
  YYSYMBOL_WHILE_STT = 106,                /* WHILE_STT  */
  YYSYMBOL_107_30 = 107,                   /* $@30  */
  YYSYMBOL_108_31 = 108,                   /* $@31  */
  YYSYMBOL_WHILEMISS_COLON = 109,          /* WHILEMISS_COLON  */
  YYSYMBOL_DO_WHILE_STT = 110,             /* DO_WHILE_STT  */
  YYSYMBOL_ERRONOUS_DO_WHILE = 111,        /* ERRONOUS_DO_WHILE  */
  YYSYMBOL_112_32 = 112,                   /* $@32  */
  YYSYMBOL_113_33 = 113,                   /* $@33  */
  YYSYMBOL_114_34 = 114,                   /* $@34  */
  YYSYMBOL_115_35 = 115,                   /* $@35  */
  YYSYMBOL_FOR_STT = 116,                  /* FOR_STT  */
  YYSYMBOL_117_36 = 117,                   /* $@36  */
  YYSYMBOL_118_37 = 118,                   /* $@37  */
  YYSYMBOL_119_38 = 119,                   /* $@38  */
  YYSYMBOL_120_39 = 120,                   /* $@39  */
  YYSYMBOL_ERRONOUS_FOR_LOOP = 121,        /* ERRONOUS_FOR_LOOP  */
  YYSYMBOL_122_40 = 122,                   /* $@40  */
  YYSYMBOL_123_41 = 123,                   /* $@41  */
  YYSYMBOL_helperAssignmentRule = 124,     /* helperAssignmentRule  */
  YYSYMBOL_assignmentSTT = 125,            /* assignmentSTT  */
  YYSYMBOL_126_42 = 126,                   /* $@42  */
  YYSYMBOL_BLOCK = 127,                    /* BLOCK  */
  YYSYMBOL_128_43 = 128,                   /* $@43  */
  YYSYMBOL_FUNC_CALL = 129,                /* FUNC_CALL  */
  YYSYMBOL_130_44 = 130,                   /* $@44  */
  YYSYMBOL_131_45 = 131,                   /* $@45  */
  YYSYMBOL_132_46 = 132,                   /* $@46  */
  YYSYMBOL_USED_ARGS = 133,                /* USED_ARGS  */
  YYSYMBOL_134_47 = 134,                   /* $@47  */
  YYSYMBOL_EXPRESSION = 135,               /* EXPRESSION  */
  YYSYMBOL_136_48 = 136,                   /* $@48  */
  YYSYMBOL_137_49 = 137,                   /* $@49  */
  YYSYMBOL_138_50 = 138,                   /* $@50  */
  YYSYMBOL_139_51 = 139,                   /* $@51  */
  YYSYMBOL_140_52 = 140,                   /* $@52  */
  YYSYMBOL_141_53 = 141,                   /* $@53  */
  YYSYMBOL_ERRONOUS_EXPRESSION = 142,      /* ERRONOUS_EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 143,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 144,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 145                  /* RES_WORD  */
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
#define YYLAST   1270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  235
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  402

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      47,    45,     2,     2,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    49,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
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
     381,   382,   393,   393,   393,   400,   401,   406,   407,   410,
     410,   411,   411,   412,   412,   413,   413,   414,   421,   421,
     421,   421,   421,   422,   426,   426,   427,   427,   434,   435,
     439,   440,   441,   441,   446,   446,   454,   454,   454,   454,
     455,   461,   461,   462,   463,   464,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   479,   480,   480,   481,
     481,   483,   483,   484,   484,   487,   487,   488,   489,   490,
     491,   500,   502,   503,   504,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548
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
  "NEWLINE", "MODULO", "DEC", "INC", "EQUALITY", "NEG_EQUALITY", "SWITCH",
  "CASE", "LOGIC_AND", "LOGIC_OR", "LOGIC_NOT", "DIGIT", "IDENTIFIER",
  "FLOAT_DIGIT", "'{'", "'}'", "')'", "':'", "'('", "','", "';'",
  "$accept", "PROGRAM", "STATEMENT", "SEMICOLON_MISS", "TYPE",
  "DECLARATION_STT", "$@1", "$@2", "DECLARATION_TAIL", "$@3", "$@4", "$@5",
  "RETURN_STT", "$@6", "helperSWITCH", "SWITCH_STT", "DEFAULTCASE",
  "CASES", "$@7", "$@8", "$@9", "$@10", "ERRONOUS_SWITCH_STT", "$@11",
  "$@12", "$@13", "$@14", "FUNC_DECLARATION_STT", "$@15", "$@16", "$@17",
  "$@18", "$@19", "$@20", "$@21", "$@22", "ERRONOUS_FUNC_DECLARATION_STT",
  "$@23", "ARGS", "ERRONOUS_ARGS", "ARG_DECL", "ENUM_DECLARATION_STT",
  "$@24", "ENUM_HELPER", "ENUM_ARGS", "$@25", "ENUM_DEFINED_ARGS", "$@26",
  "ERRONOUS_ENUM_DECLARATION_STT", "ENUM_CALL_STT", "IF_STT_HELPER",
  "$@27", "IF_STT_HELPER1", "IF_STT", "$@28", "$@29", "WHILE_STT", "$@30",
  "$@31", "WHILEMISS_COLON", "DO_WHILE_STT", "ERRONOUS_DO_WHILE", "$@32",
  "$@33", "$@34", "$@35", "FOR_STT", "$@36", "$@37", "$@38", "$@39",
  "ERRONOUS_FOR_LOOP", "$@40", "$@41", "helperAssignmentRule",
  "assignmentSTT", "$@42", "BLOCK", "$@43", "FUNC_CALL", "$@44", "$@45",
  "$@46", "USED_ARGS", "$@47", "EXPRESSION", "$@48", "$@49", "$@50",
  "$@51", "$@52", "$@53", "ERRONOUS_EXPRESSION", "COMPARISONSTT",
  "ERRONOUS_COMPARISONSTT", "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-288)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-167)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -288,   213,  -288,   705,  -288,  -288,  -288,  -288,   -37,    -9,
      14,  -288,  -288,   515,  -288,    15,    11,    37,    -3,    65,
      39,   540,  -288,   117,  -288,  -288,   515,  -288,    -5,  -288,
      65,    69,  -288,  -288,  -288,    46,  -288,  -288,  -288,    45,
    -288,  -288,  -288,  -288,  -288,  -288,   229,  -288,  -288,  -288,
    1027,  -288,  -288,  -288,   515,   264,   279,  -288,   515,   515,
      65,   515,   515,   515,   515,   515,    65,  -288,  -288,    56,
    -288,   515,   466,    59,   515,  1189,  -288,   373,   185,  -288,
     102,    96,   109,    26,   515,   127,  -288,  -288,  -288,    10,
     107,  1238,   112,  -288,   122,   118,  -288,   739,  -288,    16,
    -288,    61,  -288,    87,    24,  -288,    27,   136,    46,  -288,
    1054,  -288,   321,   478,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,   552,   565,   577,   602,   128,   515,   128,   515,
     159,   149,   114,  -288,  1238,  1238,  1238,  1202,  1202,  -288,
     129,    46,  1162,   466,   466,   466,  1162,   112,   169,   138,
    -288,    17,   147,   146,    72,    47,   150,  -288,  -288,  1081,
    -288,   144,   157,    28,  -288,   515,   152,  -288,  -288,   421,
    -288,    83,    65,   156,    83,    18,    46,  -288,   515,  -288,
     171,  -288,  -288,   161,  -288,    34,  -288,  -288,   515,   107,
     614,   128,   194,   627,   159,   515,   515,   515,   515,   515,
     274,  1238,   274,  1238,  1225,  1202,  1225,  1202,   128,   128,
      18,   166,  -288,   466,   466,  -288,   179,   165,   205,   180,
    -288,   515,   515,   188,   147,    82,   187,   192,   147,  -288,
    -288,   199,   198,   203,  -288,  -288,  1108,   235,   503,  -288,
     515,   639,  -288,  -288,  -288,    18,   212,  -288,    18,   217,
     216,  -288,   214,  -288,  1162,   515,  -288,   219,  -288,   128,
     107,   128,   194,   128,   149,   185,   114,  1238,   149,   227,
    -288,   228,   466,   466,  -288,    46,   515,   230,   515,   515,
     971,   768,  -288,   234,   226,  -288,  -288,   237,  -288,   248,
    -288,   257,    69,   249,    69,    69,  -288,  -288,   158,  -288,
     797,  1135,   332,   671,   262,  -288,  -288,  -288,  -288,    18,
     256,   999,  -288,  -288,    46,  -288,   265,  -288,  -288,   826,
     515,   855,   884,  -288,  -288,  -288,  -288,   261,   268,  -288,
    -288,   269,    69,   270,   271,   503,   272,   276,  -288,  -288,
    -288,   281,   282,   956,  -288,    46,  -288,    46,  -288,    46,
    -288,    46,  -288,   466,  -288,   913,  -288,  -288,   275,  -288,
     284,  -288,  -288,  -288,  -288,   503,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,    46,  -288,  -288,  -288,  -288,    46,   285,
    -288,   319,  -288,  -288,  -288,  -288,    69,  -288,  -288,  -288,
      46,  -288
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    23,    24,    25,    26,     0,   111,
       0,   122,   169,     0,   170,   171,     0,     0,    45,     0,
       0,     0,   167,     0,   168,   154,     0,     2,     0,     4,
       0,    60,    13,    49,     5,     0,    14,    92,    15,   117,
       9,    10,    12,   128,    11,   143,     0,     6,    16,   188,
       0,   190,   187,   204,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
     119,     0,     0,   138,     0,     0,   171,     0,   172,   149,
     129,     0,     0,     0,     0,     0,    22,    17,    61,     0,
     213,   203,   152,   148,     0,     0,     3,     0,    29,    83,
       7,     0,    52,    59,     0,    70,     0,   114,     0,   150,
       0,   183,     0,     0,     8,   175,   179,   181,   185,   177,
     174,   173,     0,     0,     0,     0,   193,     0,   205,     0,
     207,   191,   192,    32,   194,   209,   211,   214,   216,    31,
      74,     0,   112,     0,     0,     0,   123,     0,     0,     0,
     133,     0,     0,     0,    95,     0,     0,    93,    94,     0,
      21,     0,    63,     0,   160,     0,     0,   110,   157,     0,
     189,     0,     0,    71,     0,     0,     0,    51,     0,    58,
       0,    69,    48,     0,   113,     0,   118,   151,     0,   206,
       0,   195,   208,     0,   196,     0,     0,     0,     0,     0,
     210,   199,   212,   200,   215,   201,   217,   202,   220,   218,
       0,     0,   120,     0,     0,   139,   126,     0,     0,     0,
     131,     0,     0,     0,     0,     0,     0,     0,     0,   106,
      46,     0,     0,     0,    67,    47,     0,     0,     0,   155,
       0,     0,    37,    30,    33,     0,     0,    28,     0,     0,
       0,    87,    86,    50,    53,     0,   121,     0,   115,   184,
     221,   198,   219,   197,   176,   180,   182,   186,   178,     0,
      81,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,   105,     0,     0,   104,   103,    98,   102,     0,
     107,     0,    60,     0,    60,    60,   153,   109,     0,   158,
     161,     0,     0,    42,     0,    78,    88,    89,    84,     0,
       0,     0,   116,    75,     0,   144,     0,   140,   124,     0,
       0,     0,     0,   137,   127,   108,   101,     0,    95,    96,
      91,     0,    60,     0,     0,     0,     0,     0,    35,    36,
      34,     0,     0,     0,    72,     0,    85,     0,    57,     0,
      82,     0,   146,     0,   130,     0,   134,   132,     0,    62,
       0,    66,    68,   163,   159,     0,    39,    41,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    43,     0,    79,    54,    76,   145,     0,     0,
     136,     0,    99,    64,   162,    73,    60,   147,   141,    55,
       0,   142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -288,   241,   -70,   -27,  -169,  -288,  -288,  -288,   164,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,   240,  -287,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -190,  -288,
    -288,  -288,  -288,  -142,    51,  -288,   -11,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,   -16,  -288,  -288,
    -288,  -288,  -288,  -270,  -288,   -12,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    27,    87,    28,    29,   174,   171,   243,   341,
     342,   343,    30,    84,    31,    32,   103,   104,   178,   310,
     396,   180,    33,   161,   232,   233,   295,    34,   245,   383,
     210,   349,   246,   345,   211,   314,    35,   175,   250,   251,
     252,    36,   228,   156,   157,   226,   158,   327,    37,    38,
      39,    71,   107,    40,   108,   141,    41,    74,   216,   275,
      42,    43,   148,   279,   219,   149,    44,   145,   273,   353,
     400,    45,   351,   388,    46,    47,   165,    48,    96,    49,
      95,   238,   336,   299,   337,    50,   195,   199,   196,   197,
     188,   198,    51,    52,    53,   382
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    78,   143,   100,    69,   331,   249,   333,   334,    91,
     223,   162,    80,   -44,    97,    72,    98,   -27,   220,   105,
     269,     4,     5,     6,     7,   181,   -44,   153,   183,   234,
      79,   -27,   -27,   133,   110,   257,    99,    70,    82,   139,
      88,   249,   126,   128,   130,   360,   131,   132,   227,   134,
     135,   136,   137,   138,    25,   304,   163,   172,   306,   142,
     221,    73,   146,   173,   222,   363,   248,   154,   182,   155,
      25,   235,   159,   213,   214,   215,   249,    25,    83,   249,
      89,    85,   283,   284,   240,   177,   291,   225,   -90,    25,
     184,   106,   186,   285,    86,   394,   101,   150,   241,   242,
     191,   194,   286,   140,    25,   102,   151,   176,   144,   399,
     201,   203,   205,   207,   101,   208,   -97,   209,    92,   346,
      55,    56,   287,   -56,   288,   212,   111,   112,   113,  -166,
    -166,  -166,    93,  -166,  -166,  -166,  -166,   166,   167,  -166,
     249,   112,   113,   271,   272,   244,  -135,  -166,  -166,  -166,
    -166,  -166,   152,   236,  -166,  -166,   160,   164,    94,   185,
     253,   111,   112,   113,  -156,   168,   254,   116,   117,   258,
      54,    55,    56,   113,   -80,    58,   259,    59,   261,   217,
      61,   263,   218,   264,   265,   266,   267,   268,   154,   224,
     231,    62,    63,   237,   229,    64,    65,   111,   112,   113,
     -65,   -77,   316,   317,   117,   256,   335,   255,    56,   280,
     281,   270,   276,     2,     3,   277,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   274,   300,   278,   301,   303,
      75,    13,   282,    14,    15,   289,   290,    16,    17,    18,
      12,    19,   292,   311,   293,   109,   294,    13,    20,    14,
      76,   297,    21,    22,    23,    24,    25,   305,   307,   318,
      26,   308,   309,   312,   319,    75,   321,   322,    21,    22,
      77,    24,   313,   315,   326,    12,    26,   320,   325,   127,
      75,  -100,    13,   389,    14,    76,    54,    55,    56,   328,
      12,    58,   332,    59,   129,   348,    61,    13,   350,    14,
      76,   330,   347,    21,    22,    77,    24,   344,   355,   358,
     352,    26,   -97,   359,   361,   362,   391,   364,    21,    22,
      77,    24,   189,   300,   365,   366,    26,   367,   393,   384,
     398,   385,    12,   386,   225,   387,   190,   169,   247,    13,
     329,    14,    76,   179,    54,    55,    56,   392,   339,    58,
       0,    59,     0,   300,    61,     0,     0,     0,     0,     0,
      21,    22,    77,    24,     0,    62,    63,   395,    26,    64,
      65,     0,   397,     0,   147,     0,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,   401,  -166,  -166,  -166,     0,  -166,
    -166,  -166,  -166,     0,  -166,  -166,  -166,  -166,  -166,     0,
       0,     0,     0,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,     0,     0,     0,     0,  -166,  -166,  -166,  -166,
    -156,  -166,     3,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,    13,
       0,    14,    15,     0,     0,    16,    17,    18,     0,    19,
       0,     0,     0,     0,     0,     0,    20,     0,     0,     0,
      21,    22,    23,    24,    25,   239,     0,     3,    26,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,   192,
       0,     0,     0,     0,    13,     0,    14,    15,     0,    12,
      16,    17,    18,   193,    19,     0,    13,     0,    14,    76,
       0,    20,     0,     0,   298,    21,    22,    23,    24,    25,
       0,     0,     0,    26,    12,     0,    75,    21,    22,    77,
      24,    13,     0,    14,    76,    26,    12,     0,     0,     0,
       0,     0,     0,    13,     0,    14,    76,     0,     0,     0,
       0,    90,    21,    22,    77,    24,     0,     0,  -165,     0,
      26,    12,     0,   200,    21,    22,    77,    24,    13,     0,
      14,    76,    26,    12,     0,     0,   202,     0,     0,     0,
      13,     0,    14,    76,     0,     0,    12,     0,   204,    21,
      22,    77,    24,    13,     0,    14,    76,    26,    12,     0,
       0,    21,    22,    77,    24,    13,     0,    14,    76,    26,
       0,     0,     0,   206,    21,    22,    77,    24,     0,     0,
       0,     0,    26,    12,     0,   260,    21,    22,    77,    24,
      13,     0,    14,    76,    26,    12,     0,     0,   262,     0,
       0,     0,    13,     0,    14,    76,     0,     0,    12,     0,
     302,    21,    22,    77,    24,    13,     0,    14,    76,    26,
      12,     0,     0,    21,    22,    77,    24,    13,     0,    14,
      76,    26,     0,     0,     0,     0,    21,    22,    77,    24,
       0,     0,     0,     0,    26,     0,     0,     0,    21,    22,
      77,    24,     0,   111,   112,   113,    26,   340,   115,   116,
     117,     0,     0,   118,     0,     0,     0,     0,     0,     0,
       0,   119,   120,   121,   122,   123,     0,     0,   124,   125,
       0,     0,     0,     0,     0,   -38,   -40,    54,    55,    56,
       0,    57,    58,     0,    59,     0,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
       0,     0,    64,    65,     0,     0,    66,     0,     0,    67,
      68,   111,   112,   113,     0,     0,   115,   116,   117,     0,
       0,   118,     0,     0,     0,     0,     0,     0,     0,   119,
     120,   121,   122,   123,     0,     0,   124,   125,     0,     0,
     111,   112,   113,     0,   170,   115,   116,   117,     0,     0,
     118,     0,     0,     0,     0,     0,     0,     0,   119,   120,
     121,   122,   123,     0,     0,   124,   125,     0,     0,   111,
     112,   113,     0,   324,   115,   116,   117,     0,     0,   118,
       0,     0,     0,     0,     0,     0,     0,   119,   120,   121,
     122,   123,     0,     0,   124,   125,     0,     0,   111,   112,
     113,     0,  -164,   115,   116,   117,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,   119,   120,   121,   122,
     123,     0,     0,   124,   125,     0,     0,   111,   112,   113,
       0,   354,   115,   116,   117,     0,     0,   118,     0,     0,
       0,     0,     0,     0,     0,   119,   120,   121,   122,   123,
       0,     0,   124,   125,     0,     0,   111,   112,   113,     0,
     356,   115,   116,   117,     0,     0,   118,     0,     0,     0,
       0,     0,     0,     0,   119,   120,   121,   122,   123,     0,
       0,   124,   125,     0,     0,   111,   112,   113,     0,   357,
     115,   116,   117,     0,     0,   118,     0,     0,     0,     0,
       0,     0,     0,   119,   120,   121,   122,   123,     0,     0,
     124,   125,     0,     0,     0,     0,     0,     0,   390,   368,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   376,     0,   377,
     378,   379,     0,   111,   112,   113,     0,     0,   115,   116,
     117,   380,   381,   118,     0,     0,     0,     0,     0,     0,
       0,   119,   120,   121,   122,   123,     0,     0,   124,   125,
       0,   111,   112,   113,     0,   323,   115,   116,   117,     0,
       0,   118,     0,     0,     0,     0,     0,     0,     0,   119,
     120,   121,   122,   123,     0,     0,   124,   125,     0,   111,
     112,   113,    25,   114,   115,   116,   117,     0,     0,   118,
       0,     0,     0,     0,     0,     0,     0,   119,   120,   121,
     122,   123,     0,     0,   124,   125,   111,   112,   113,     0,
     187,   115,   116,   117,     0,     0,   118,     0,     0,     0,
       0,     0,     0,     0,   119,   120,   121,   122,   123,     0,
       0,   124,   125,   111,   112,   113,     0,   230,   115,   116,
     117,     0,     0,   118,     0,     0,     0,     0,     0,     0,
       0,   119,   120,   121,   122,   123,     0,     0,   124,   125,
     111,   112,   113,     0,   296,   115,   116,   117,     0,     0,
     118,     0,     0,     0,     0,     0,     0,     0,   119,   120,
     121,   122,   123,     0,     0,   124,   125,   111,   112,   113,
       0,   338,   115,   116,   117,     0,     0,   118,     0,     0,
       0,     0,     0,     0,     0,   119,   120,   121,   122,   123,
       0,     0,   124,   125,   111,   112,   113,     0,     0,   115,
     116,   117,     0,     0,   118,     0,     0,     0,     0,     0,
       0,     0,   119,   120,   121,   122,   123,     0,     0,   124,
     125,    54,    55,    56,     0,     0,    58,     0,    59,     0,
       0,    61,     0,     0,   111,   112,   113,     0,     0,   115,
     116,   117,    62,    63,   118,     0,    64,    65,     0,     0,
       0,     0,   119,   120,   121,   122,   123,    54,    55,    56,
       0,     0,    58,     0,    59,     0,     0,    61,     0,     0,
     111,   112,   113,     0,     0,   115,   116,   117,    62,    63,
     118,     0,     0,     0,     0,     0,     0,     0,   119,   120,
     121
};

static const yytype_int16 yycheck[] =
{
      16,    13,    72,    30,    41,   292,   175,   294,   295,    21,
     152,     1,     1,    16,    26,     1,    21,     1,     1,    35,
     210,     3,     4,     5,     6,     1,    29,     1,     1,     1,
      15,    15,    16,    60,    46,     1,    41,    46,     1,    66,
       1,   210,    54,    55,    56,   332,    58,    59,     1,    61,
      62,    63,    64,    65,    43,   245,    46,    41,   248,    71,
      43,    47,    74,    47,    47,   335,    48,    41,    44,    43,
      43,    43,    84,   143,   144,   145,   245,    43,    41,   248,
      41,    16,   224,     1,     1,   101,   228,    15,    41,    43,
     106,    46,   108,    11,    29,   365,    27,     1,    15,    16,
     112,   113,    20,    47,    43,    36,    10,    46,    49,   396,
     122,   123,   124,   125,    27,   127,    44,   129,     1,   309,
      13,    14,    40,    36,    42,   141,    12,    13,    14,    12,
      13,    14,    15,    16,    17,    18,    19,    15,    16,    22,
     309,    13,    14,   213,   214,   172,    44,    30,    31,    32,
      33,    34,    43,   165,    37,    38,    29,    45,    41,    23,
     176,    12,    13,    14,    47,    47,   178,    18,    19,   185,
      12,    13,    14,    14,    45,    17,   188,    19,   190,    10,
      22,   193,    44,   195,   196,   197,   198,   199,    41,    43,
      46,    33,    34,    41,    44,    37,    38,    12,    13,    14,
      43,    45,   272,   273,    19,    44,    48,    36,    14,   221,
     222,    45,    47,     0,     1,    10,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    46,   238,    47,   240,   241,
       1,    18,    44,    20,    21,    48,    44,    24,    25,    26,
      11,    28,    43,   255,    46,    16,    43,    18,    35,    20,
      21,    16,    39,    40,    41,    42,    43,    45,    41,   275,
      47,    45,    48,    44,   276,     1,   278,   279,    39,    40,
      41,    42,    45,    45,    48,    11,    47,    47,    44,    15,
       1,    44,    18,   353,    20,    21,    12,    13,    14,    41,
      11,    17,    43,    19,    15,   311,    22,    18,   314,    20,
      21,    44,    46,    39,    40,    41,    42,    45,   320,    48,
      45,    47,    44,    44,    44,    44,    41,    45,    39,    40,
      41,    42,     1,   335,    48,    44,    47,    45,    44,   345,
      45,   347,    11,   349,    15,   351,    15,    96,   174,    18,
     289,    20,    21,   103,    12,    13,    14,   358,    16,    17,
      -1,    19,    -1,   365,    22,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    -1,    33,    34,   383,    47,    37,
      38,    -1,   388,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,   400,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    20,    21,    -1,    -1,    24,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,     1,    47,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,     1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    11,
      24,    25,    26,    15,    28,    -1,    18,    -1,    20,    21,
      -1,    35,    -1,    -1,     1,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    47,    11,    -1,     1,    39,    40,    41,
      42,    18,    -1,    20,    21,    47,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,
      -1,     1,    39,    40,    41,    42,    -1,    -1,    45,    -1,
      47,    11,    -1,     1,    39,    40,    41,    42,    18,    -1,
      20,    21,    47,    11,    -1,    -1,     1,    -1,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    11,    -1,     1,    39,
      40,    41,    42,    18,    -1,    20,    21,    47,    11,    -1,
      -1,    39,    40,    41,    42,    18,    -1,    20,    21,    47,
      -1,    -1,    -1,     1,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    47,    11,    -1,     1,    39,    40,    41,    42,
      18,    -1,    20,    21,    47,    11,    -1,    -1,     1,    -1,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    11,    -1,
       1,    39,    40,    41,    42,    18,    -1,    20,    21,    47,
      11,    -1,    -1,    39,    40,    41,    42,    18,    -1,    20,
      21,    47,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    39,    40,
      41,    42,    -1,    12,    13,    14,    47,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    12,    13,    14,
      -1,    16,    17,    -1,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    37,    38,    -1,    -1,    41,    -1,    -1,    44,
      45,    12,    13,    14,    -1,    -1,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    -1,    -1,    37,    38,    -1,    -1,
      12,    13,    14,    -1,    45,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    -1,    -1,    37,    38,    -1,    -1,    12,
      13,    14,    -1,    45,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    12,    13,
      14,    -1,    45,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    -1,    -1,    37,    38,    -1,    -1,    12,    13,    14,
      -1,    45,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      -1,    -1,    37,    38,    -1,    -1,    12,    13,    14,    -1,
      45,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    -1,
      -1,    37,    38,    -1,    -1,    12,    13,    14,    -1,    45,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    23,
      24,    25,    -1,    12,    13,    14,    -1,    -1,    17,    18,
      19,    35,    36,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    -1,    -1,    37,    38,
      -1,    12,    13,    14,    -1,    44,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    -1,    -1,    37,    38,    -1,    12,
      13,    14,    43,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    -1,    -1,    37,    38,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    -1,
      -1,    37,    38,    12,    13,    14,    -1,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    -1,    -1,    37,    38,
      12,    13,    14,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    -1,    -1,    37,    38,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      -1,    -1,    37,    38,    12,    13,    14,    -1,    -1,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    -1,    -1,    37,
      38,    12,    13,    14,    -1,    -1,    17,    -1,    19,    -1,
      -1,    22,    -1,    -1,    12,    13,    14,    -1,    -1,    17,
      18,    19,    33,    34,    22,    -1,    37,    38,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    12,    13,    14,
      -1,    -1,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,
      12,    13,    14,    -1,    -1,    17,    18,    19,    33,    34,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    18,    20,    21,    24,    25,    26,    28,
      35,    39,    40,    41,    42,    43,    47,    52,    54,    55,
      62,    64,    65,    72,    77,    86,    91,    98,    99,   100,
     103,   106,   110,   111,   116,   121,   124,   125,   127,   129,
     135,   142,   143,   144,    12,    13,    14,    16,    17,    19,
      21,    22,    33,    34,    37,    38,    41,    44,    45,    41,
      46,   101,     1,    47,   107,     1,    21,    41,   135,    15,
       1,   127,     1,    41,    63,    16,    29,    53,     1,    41,
       1,   135,     1,    15,    41,   130,   128,   135,    21,    41,
      53,    27,    36,    66,    67,   127,    46,   102,   104,    16,
     135,    12,    13,    14,    16,    17,    18,    19,    22,    30,
      31,    32,    33,    34,    37,    38,   135,    15,   135,    15,
     135,   135,   135,    53,   135,   135,   135,   135,   135,    53,
      47,   105,   135,    52,    49,   117,   135,     1,   112,   115,
       1,    10,    43,     1,    41,    43,    93,    94,    96,   135,
      29,    73,     1,    46,    45,   126,    15,    16,    47,    51,
      45,    57,    41,    47,    56,    87,    46,   127,    68,    66,
      71,     1,    44,     1,   127,    23,   127,    16,   140,     1,
      15,   135,     1,    15,   135,   136,   138,   139,   141,   137,
       1,   135,     1,   135,     1,   135,     1,   135,   135,   135,
      80,    84,   127,    52,    52,    52,   108,    10,    44,   114,
       1,    43,    47,    93,    43,    15,    95,     1,    92,    44,
      16,    46,    74,    75,     1,    43,   135,    41,   131,    44,
       1,    15,    16,    58,    53,    78,    82,    58,    48,    54,
      88,    89,    90,   127,   135,    36,    44,     1,   127,   135,
       1,   135,     1,   135,   135,   135,   135,   135,   135,    88,
      45,    52,    52,   118,    46,   109,    47,    10,    47,   113,
     135,   135,    44,    93,     1,    11,    20,    40,    42,    48,
      44,    93,    43,    46,    43,    76,    16,    16,     1,   133,
     135,   135,     1,   135,    88,    45,    88,    41,    45,    48,
      69,   135,    44,    45,    85,    45,    52,    52,   127,   135,
      47,   135,   135,    44,    45,    44,    48,    97,    41,    94,
      44,    67,    43,    67,    67,    48,   132,   134,    16,    16,
      16,    59,    60,    61,    45,    83,    88,    46,   127,    81,
     127,   122,    45,   119,    45,   135,    45,    45,    48,    44,
      67,    44,    44,   133,    45,    48,    44,    45,     3,     4,
       5,     6,     7,     8,     9,    10,    21,    23,    24,    25,
      35,    36,   145,    79,   127,   127,   127,   127,   123,    52,
      45,    41,    96,    44,   133,   127,    70,   127,    45,    67,
     120,   127
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    53,    53,    54,    54,    54,    54,    56,    55,    57,
      55,    55,    55,    55,    58,    58,    58,    58,    59,    58,
      60,    58,    61,    58,    62,    63,    62,    64,    65,    65,
      66,    66,    68,    69,    70,    67,    71,    67,    67,    67,
      67,    73,    72,    74,    72,    75,    72,    76,    72,    72,
      77,    78,    79,    77,    80,    81,    77,    82,    83,    77,
      84,    85,    77,    87,    86,    88,    88,    88,    89,    90,
      92,    91,    91,    93,    93,    95,    94,    94,    97,    96,
      96,    96,    96,    96,    96,    98,    98,    98,    98,    99,
      99,   101,   100,   102,   103,   103,   103,   104,   103,   105,
     103,   103,   107,   108,   106,   109,   109,   110,   110,   112,
     111,   113,   111,   114,   111,   115,   111,   111,   117,   118,
     119,   120,   116,   116,   122,   121,   123,   121,   124,   124,
     125,   125,   126,   125,   128,   127,   130,   131,   132,   129,
     129,   134,   133,   133,   133,   133,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   136,   135,   137,   135,   138,
     135,   139,   135,   140,   135,   141,   135,   135,   135,   135,
     135,   142,   142,   142,   142,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     3,     3,     4,     3,     3,     3,     1,     0,     4,
       0,     4,     0,     4,     1,     0,     4,     4,     3,     1,
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
       2,     3,     0,     5,     0,     4,     0,     0,     0,     7,
       3,     0,     4,     3,     1,     0,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     0,     4,     0,     4,     0,
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
#line 191 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1818 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 197 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1824 "parser.tab.c"
    break;

  case 9: /* STATEMENT: IF_STT  */
#line 201 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1830 "parser.tab.c"
    break;

  case 10: /* STATEMENT: WHILE_STT  */
#line 202 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1836 "parser.tab.c"
    break;

  case 11: /* STATEMENT: FOR_STT  */
#line 203 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1842 "parser.tab.c"
    break;

  case 12: /* STATEMENT: DO_WHILE_STT  */
#line 204 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1848 "parser.tab.c"
    break;

  case 13: /* STATEMENT: SWITCH_STT  */
#line 205 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1854 "parser.tab.c"
    break;

  case 14: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 206 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1860 "parser.tab.c"
    break;

  case 15: /* STATEMENT: ENUM_CALL_STT  */
#line 207 "parser.y"
                                                            {printf("#[Parsed_Enum_USAGE]# ");}
#line 1866 "parser.tab.c"
    break;

  case 17: /* STATEMENT: BREAK SEMICOLON_MISS  */
#line 209 "parser.y"
                                                            {StAssJmp("JMP", "END", &SMLabel_End, 0, 0);}
#line 1872 "parser.tab.c"
    break;

  case 18: /* STATEMENT: error SEMICOLON  */
#line 210 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1878 "parser.tab.c"
    break;

  case 19: /* STATEMENT: error '}'  */
#line 211 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1884 "parser.tab.c"
    break;

  case 20: /* STATEMENT: error ')'  */
#line 212 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);pErr(yylineno);}
#line 1890 "parser.tab.c"
    break;

  case 22: /* SEMICOLON_MISS: NEWLINE  */
#line 217 "parser.y"
                                {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);pErr(yylineno);}
#line 1896 "parser.tab.c"
    break;

  case 23: /* TYPE: INT  */
#line 227 "parser.y"
                            { (yyval.str) = "int";   }
#line 1902 "parser.tab.c"
    break;

  case 24: /* TYPE: FLOAT  */
#line 228 "parser.y"
                            { (yyval.str) = "float"; }
#line 1908 "parser.tab.c"
    break;

  case 25: /* TYPE: BOOL  */
#line 229 "parser.y"
                            { (yyval.str) = "bool";  }
#line 1914 "parser.tab.c"
    break;

  case 26: /* TYPE: STRING  */
#line 230 "parser.y"
                            { (yyval.str) = "string";}
#line 1920 "parser.tab.c"
    break;

  case 27: /* $@1: %empty  */
#line 234 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0);   assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1926 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 234 "parser.y"
                                                                                                                                                         { assign_index =-1; printf("#[Parsed_Declaration]# "); }
#line 1932 "parser.tab.c"
    break;

  case 29: /* $@2: %empty  */
#line 235 "parser.y"
                                    {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0); assign_index= st_index-1; strcpy(IdentifierHolder, (yyvsp[0].str));}
#line 1938 "parser.tab.c"
    break;

  case 30: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 235 "parser.y"
                                                                                                                                                         {assign_index =-1; printf("#[Parsed_CONST_Declaration]# "); }
#line 1944 "parser.tab.c"
    break;

  case 31: /* DECLARATION_STT: error IDENTIFIER SEMICOLON_MISS  */
#line 236 "parser.y"
                                                                                                 {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);pErr(yylineno);}
#line 1950 "parser.tab.c"
    break;

  case 32: /* DECLARATION_STT: error CONSTANT SEMICOLON_MISS  */
#line 237 "parser.y"
                                                                                                 {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);pErr(yylineno);}
#line 1956 "parser.tab.c"
    break;

  case 33: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON_MISS  */
#line 238 "parser.y"
                                                                                                 {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);pErr(yylineno);}
#line 1962 "parser.tab.c"
    break;

  case 34: /* DECLARATION_TAIL: EQ EXPRESSION SEMICOLON  */
#line 243 "parser.y"
                                                                                            {StAssPush(strdup(IdentifierHolder)); StAssPrint("OVER", 1); StAssPrint("STORE", 1); StAssPrint("DROP", 1);}
#line 1968 "parser.tab.c"
    break;

  case 35: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 244 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 1974 "parser.tab.c"
    break;

  case 36: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 245 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);pErr(yylineno);}
#line 1980 "parser.tab.c"
    break;

  case 38: /* $@3: %empty  */
#line 247 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1986 "parser.tab.c"
    break;

  case 40: /* $@4: %empty  */
#line 248 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1992 "parser.tab.c"
    break;

  case 42: /* $@5: %empty  */
#line 249 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); pErr(yylineno);}
#line 1998 "parser.tab.c"
    break;

  case 44: /* RETURN_STT: RETURN  */
#line 256 "parser.y"
                                        {int dum = 0;StAssPrint("POP\tPC",1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 2004 "parser.tab.c"
    break;

  case 45: /* $@6: %empty  */
#line 257 "parser.y"
                         {assign_index =func_index;}
#line 2010 "parser.tab.c"
    break;

  case 46: /* RETURN_STT: RETURN $@6 EXPRESSION SEMICOLON  */
#line 257 "parser.y"
                                                                                     { return_exist = 1; StAssPrint("OVER",1);int dum = 0;StAssPrint("POP\tPC",1);StAssPrint("DNEXT", 1);StAssJmp("JMP", "PC", &dum,0,1);}
#line 2016 "parser.tab.c"
    break;

  case 47: /* helperSWITCH: SWITCH IDENTIFIER ':' '{'  */
#line 259 "parser.y"
                                          {strcpy(switcher, (yyvsp[-2].str));}
#line 2022 "parser.tab.c"
    break;

  case 48: /* SWITCH_STT: helperSWITCH CASES '}'  */
#line 262 "parser.y"
                                        {StAssPrintLBL(0,1);}
#line 2028 "parser.tab.c"
    break;

  case 50: /* DEFAULTCASE: DEFAULT ':' BLOCK  */
#line 267 "parser.y"
                                  {StAssJmp("JMP", "END",&SMLabel_End, 0,0); }
#line 2034 "parser.tab.c"
    break;

  case 51: /* DEFAULTCASE: DEFAULT BLOCK  */
#line 268 "parser.y"
                                {printf("\n\n=====ERROR====\n missing colon ':' at DEFAULT CASE of switch, error at line %d\n\n", yylineno); pErr(yylineno);}
#line 2040 "parser.tab.c"
    break;

  case 52: /* $@7: %empty  */
#line 271 "parser.y"
                     {StAssPush(switcher);}
#line 2046 "parser.tab.c"
    break;

  case 53: /* $@8: %empty  */
#line 271 "parser.y"
                                                       {StAssPrint("EQ", 1); StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2052 "parser.tab.c"
    break;

  case 54: /* $@9: %empty  */
#line 271 "parser.y"
                                                                                                                                   {StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2058 "parser.tab.c"
    break;

  case 56: /* $@10: %empty  */
#line 272 "parser.y"
                              {printf("\n\n=====ERROR====\n DEFAULT CASE must be written at the end of the switch statement, error at line %d\n\n", yylineno); pErr(yylineno);}
#line 2064 "parser.tab.c"
    break;

  case 58: /* CASES: DEFAULTCASE DEFAULTCASE  */
#line 273 "parser.y"
                                                                {printf("\n\n=====ERROR====\n only 1 DEFAULT CASE is allowed in the switch statement error, at line %d\n\n", yylineno); pErr(yylineno);}
#line 2070 "parser.tab.c"
    break;

  case 61: /* $@11: %empty  */
#line 285 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2076 "parser.tab.c"
    break;

  case 63: /* $@12: %empty  */
#line 286 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); pErr(yylineno);}
#line 2082 "parser.tab.c"
    break;

  case 65: /* $@13: %empty  */
#line 287 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);pErr(yylineno);}
#line 2088 "parser.tab.c"
    break;

  case 67: /* $@14: %empty  */
#line 288 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2094 "parser.tab.c"
    break;

  case 69: /* ERRONOUS_SWITCH_STT: helperSWITCH CASES error  */
#line 289 "parser.y"
                                           {printf("\n\n=====ERROR====\n unclosed '}' for switch statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2100 "parser.tab.c"
    break;

  case 71: /* $@15: %empty  */
#line 302 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2106 "parser.tab.c"
    break;

  case 72: /* $@16: %empty  */
#line 302 "parser.y"
                                                                                                                    {func_index = st_insert((yyvsp[-5].str), (yyvsp[-4].str),"func",0); popArgs();}
#line 2112 "parser.tab.c"
    break;

  case 74: /* $@17: %empty  */
#line 303 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2118 "parser.tab.c"
    break;

  case 75: /* $@18: %empty  */
#line 303 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-4].str),"func",0); popArgs();}
#line 2124 "parser.tab.c"
    break;

  case 77: /* $@19: %empty  */
#line 304 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2130 "parser.tab.c"
    break;

  case 78: /* $@20: %empty  */
#line 304 "parser.y"
                                                                                                                    {func_index=st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2136 "parser.tab.c"
    break;

  case 80: /* $@21: %empty  */
#line 305 "parser.y"
                                      {char dum[10]; strcpy(dum,(yyvsp[-1].str));strcat(dum,":");StAssPrint(dum, 0);}
#line 2142 "parser.tab.c"
    break;

  case 81: /* $@22: %empty  */
#line 305 "parser.y"
                                                                                                                    {func_index=st_insert("void", (yyvsp[-3].str),"func",0);}
#line 2148 "parser.tab.c"
    break;

  case 83: /* $@23: %empty  */
#line 310 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));pErr(yylineno);}
#line 2154 "parser.tab.c"
    break;

  case 84: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@23 ARGS ')'  */
#line 310 "parser.y"
                                                                                                                                                                                                                   {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 2160 "parser.tab.c"
    break;

  case 88: /* ERRONOUS_ARGS: ',' ARGS  */
#line 325 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);pErr(yylineno);}
#line 2166 "parser.tab.c"
    break;

  case 89: /* ARG_DECL: TYPE IDENTIFIER  */
#line 328 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1); char* buf=(yyvsp[0].str); argumentList[argPointer]=buf;argPointer++;}
#line 2172 "parser.tab.c"
    break;

  case 90: /* $@24: %empty  */
#line 335 "parser.y"
                                      { is_enum =1;}
#line 2178 "parser.tab.c"
    break;

  case 91: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' $@24 ENUM_HELPER '}'  */
#line 335 "parser.y"
                                                                              { st_insert("enum" , (yyvsp[-4].str), "var" , 0); is_enum=0; enumCNT=1;}
#line 2184 "parser.tab.c"
    break;

  case 95: /* $@25: %empty  */
#line 341 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++;  st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int(  enum_arg_count-1,st_index-1); }
#line 2190 "parser.tab.c"
    break;

  case 97: /* ENUM_ARGS: IDENTIFIER  */
#line 342 "parser.y"
                              { StAssPush((yyvsp[0].str));char buf[10]; itoa(enumCNT++,buf,10); prepend(buf, "$"); StAssPush(buf);StAssPrint("STORE",1);enum_keys[enum_arg_count] = (yyvsp[0].str); enum_values[enum_arg_count] = enum_arg_count; enum_arg_count++; st_insert("int" , (yyvsp[0].str), "enum_arg" , 0); assign_int( enum_arg_count-1,st_index-1);  }
#line 2196 "parser.tab.c"
    break;

  case 98: /* $@26: %empty  */
#line 348 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++ ; st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2202 "parser.tab.c"
    break;

  case 100: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ DIGIT  */
#line 349 "parser.y"
                                        { StAssPush((yyvsp[-2].str));char buf[10]; itoa((yyvsp[0].num),buf,10);prepend(buf, "$");StAssPush(buf);StAssPrint("STORE",1); enum_keys[enum_arg_count] = (yyvsp[-2].str); enum_values[enum_arg_count] = (yyvsp[0].num); enum_arg_count++;  st_insert("int" , (yyvsp[-2].str), "enum_arg" , 0); assign_int(  (yyvsp[0].num),st_index-1); }
#line 2208 "parser.tab.c"
    break;

  case 101: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ error ','  */
#line 350 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2214 "parser.tab.c"
    break;

  case 102: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ FLOAT_DIGIT  */
#line 351 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2220 "parser.tab.c"
    break;

  case 103: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ STRING_LITERAL  */
#line 352 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2226 "parser.tab.c"
    break;

  case 104: /* ENUM_DEFINED_ARGS: IDENTIFIER EQ BOOL_LITERAL  */
#line 353 "parser.y"
                                                            {printf("\n\n=====ERROR====\n WRONG arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2232 "parser.tab.c"
    break;

  case 105: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 357 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2238 "parser.tab.c"
    break;

  case 106: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 358 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2244 "parser.tab.c"
    break;

  case 107: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 360 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2250 "parser.tab.c"
    break;

  case 108: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER error '{' ENUM_HELPER '}'  */
#line 361 "parser.y"
                                                            {printf("\n\n=====ERROR====\n UnExpected IDENTIFIER in the ENUM statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2256 "parser.tab.c"
    break;

  case 109: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER EQ IDENTIFIER SEMICOLON  */
#line 365 "parser.y"
                                                               { StAssPush((yyvsp[-3].str));StAssPush((yyvsp[-1].str));StAssPrint("STORE",1); st_insert((yyvsp[-4].str) , (yyvsp[-3].str), "var_enum" , 0); assign_enum(st_index-1, (yyvsp[-4].str),(yyvsp[-1].str)); int i= lookup((yyvsp[-4].str), 0); symbolTable[i].isUsed=1; }
#line 2262 "parser.tab.c"
    break;

  case 110: /* ENUM_CALL_STT: IDENTIFIER IDENTIFIER SEMICOLON  */
#line 366 "parser.y"
                                                   { st_insert((yyvsp[-2].str) , (yyvsp[-1].str), "var_enum" , 0); int i= lookup((yyvsp[-2].str),0); symbolTable[i].isUsed=1;}
#line 2268 "parser.tab.c"
    break;

  case 111: /* $@27: %empty  */
#line 370 "parser.y"
                   {printIF();}
#line 2274 "parser.tab.c"
    break;

  case 112: /* IF_STT_HELPER: IF $@27 EXPRESSION  */
#line 370 "parser.y"
                                           {StAssJmp("JNZ", "LBL",&SMLabel_Else, 0,0);}
#line 2280 "parser.tab.c"
    break;

  case 113: /* IF_STT_HELPER1: ':' BLOCK  */
#line 373 "parser.y"
                                                            {controlTerminator(0);  StAssJmp("JMP", "END",&SMLabel_End, 0,0); StAssPrintLBL(1, 1);}
#line 2286 "parser.tab.c"
    break;

  case 114: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1  */
#line 377 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2292 "parser.tab.c"
    break;

  case 115: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE BLOCK  */
#line 378 "parser.y"
                                                              {StAssJmp("JMP", "END",&SMLabel_End, 1,0); StAssPrintLBL(0, 1);}
#line 2298 "parser.tab.c"
    break;

  case 116: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE error '}'  */
#line 379 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2304 "parser.tab.c"
    break;

  case 117: /* $@28: %empty  */
#line 380 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2310 "parser.tab.c"
    break;

  case 119: /* $@29: %empty  */
#line 381 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2316 "parser.tab.c"
    break;

  case 121: /* IF_STT: IF_STT_HELPER ':' error '}'  */
#line 382 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2322 "parser.tab.c"
    break;

  case 122: /* $@30: %empty  */
#line 393 "parser.y"
                      {printWHILE(); StAssPrintLBL(1, 0);}
#line 2328 "parser.tab.c"
    break;

  case 123: /* $@31: %empty  */
#line 393 "parser.y"
                                                                      {StAssJmp("JNZ", "END",&SMLabel_End, 0,0);}
#line 2334 "parser.tab.c"
    break;

  case 124: /* WHILE_STT: WHILE $@30 EXPRESSION $@31 WHILEMISS_COLON BLOCK  */
#line 393 "parser.y"
                                                                                                                                        {StAssJmp("JMP", "LBL",&SMLabel_Else, 1,0); StAssPrintLBL(0, 1);}
#line 2340 "parser.tab.c"
    break;

  case 126: /* WHILEMISS_COLON: %empty  */
#line 401 "parser.y"
                  {printf("\n\n=====ERROR====\n Missing ':' for the WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2346 "parser.tab.c"
    break;

  case 129: /* $@32: %empty  */
#line 410 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2352 "parser.tab.c"
    break;

  case 131: /* $@33: %empty  */
#line 411 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2358 "parser.tab.c"
    break;

  case 133: /* $@34: %empty  */
#line 412 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2364 "parser.tab.c"
    break;

  case 135: /* $@35: %empty  */
#line 413 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2370 "parser.tab.c"
    break;

  case 137: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 414 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);pErr(yylineno);}
#line 2376 "parser.tab.c"
    break;

  case 138: /* $@36: %empty  */
#line 421 "parser.y"
                        {in_loop = 1;}
#line 2382 "parser.tab.c"
    break;

  case 139: /* $@37: %empty  */
#line 421 "parser.y"
                                                 {StAssForHeader();}
#line 2388 "parser.tab.c"
    break;

  case 140: /* $@38: %empty  */
#line 421 "parser.y"
                                                                               {StAssForMiddle();}
#line 2394 "parser.tab.c"
    break;

  case 141: /* $@39: %empty  */
#line 421 "parser.y"
                                                                                                                {StAssPrintLBL(1,1); in_loop = 0;}
#line 2400 "parser.tab.c"
    break;

  case 142: /* FOR_STT: FOR '(' $@36 STATEMENT $@37 STATEMENT $@38 STATEMENT ')' $@39 BLOCK  */
#line 421 "parser.y"
                                                                                                                                                          {StAssJmp("JMP", "Label", &ForHeaderLabel,1,0); StAssPrintLBL(0,1);}
#line 2406 "parser.tab.c"
    break;

  case 144: /* $@40: %empty  */
#line 426 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2412 "parser.tab.c"
    break;

  case 146: /* $@41: %empty  */
#line 427 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);pErr(yylineno);}
#line 2418 "parser.tab.c"
    break;

  case 148: /* helperAssignmentRule: IDENTIFIER EQ  */
#line 434 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); StAssPush((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str),1);}
#line 2424 "parser.tab.c"
    break;

  case 149: /* helperAssignmentRule: CONSTANT EQ  */
#line 435 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n CONSTANTS must not be reassigned %d\n\n", yylineno);pErr(yylineno);}
#line 2430 "parser.tab.c"
    break;

  case 150: /* assignmentSTT: helperAssignmentRule SEMICOLON  */
#line 439 "parser.y"
                                                                 {assign_index=-1; printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2436 "parser.tab.c"
    break;

  case 151: /* assignmentSTT: helperAssignmentRule EXPRESSION SEMICOLON  */
#line 440 "parser.y"
                                                                 {assign_index =-1; StAssPrint("STORE", 1); CodeGenAss();printf("#[Parsed_Assignment]# ");}
#line 2442 "parser.tab.c"
    break;

  case 152: /* $@42: %empty  */
#line 441 "parser.y"
                                                                 {pushVStack((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str),1); StAssPush((yyvsp[-1].str));}
#line 2448 "parser.tab.c"
    break;

  case 153: /* assignmentSTT: IDENTIFIER error $@42 EXPRESSION SEMICOLON  */
#line 441 "parser.y"
                                                                                                                                                        {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);pErr(yylineno);}
#line 2454 "parser.tab.c"
    break;

  case 154: /* $@43: %empty  */
#line 446 "parser.y"
                    {scope_start();}
#line 2460 "parser.tab.c"
    break;

  case 155: /* BLOCK: '{' $@43 PROGRAM '}'  */
#line 446 "parser.y"
                                                                              {scope_end(); printf("#[Parsed_Block]# ");}
#line 2466 "parser.tab.c"
    break;

  case 156: /* $@44: %empty  */
#line 454 "parser.y"
                           {called_func_index = lookup((yyvsp[0].str),0); check_type(called_func_index); StAssPush("PC");}
#line 2472 "parser.tab.c"
    break;

  case 157: /* $@45: %empty  */
#line 454 "parser.y"
                                                                                                                   { is_param =1;}
#line 2478 "parser.tab.c"
    break;

  case 158: /* $@46: %empty  */
#line 454 "parser.y"
                                                                                                                                              { is_param =0; arg_count_check(called_func_index); arg_count=0; int dum=0; StAssJmp("JMP", (yyvsp[-4].str),&dum, 0,0);}
#line 2484 "parser.tab.c"
    break;

  case 159: /* FUNC_CALL: IDENTIFIER $@44 '(' $@45 USED_ARGS $@46 ')'  */
#line 454 "parser.y"
                                                                                                                                                                                                                                                               { printf("#[Parsed_Func_Call]# ");}
#line 2490 "parser.tab.c"
    break;

  case 160: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 455 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);pErr(yylineno);}
#line 2496 "parser.tab.c"
    break;

  case 161: /* $@47: %empty  */
#line 461 "parser.y"
                           { arg_count++; }
#line 2502 "parser.tab.c"
    break;

  case 163: /* USED_ARGS: error ',' USED_ARGS  */
#line 462 "parser.y"
                                                            {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2508 "parser.tab.c"
    break;

  case 164: /* USED_ARGS: EXPRESSION  */
#line 463 "parser.y"
                             {arg_count++ ;}
#line 2514 "parser.tab.c"
    break;

  case 166: /* EXPRESSION: IDENTIFIER  */
#line 470 "parser.y"
                                                { int i = lookup((yyvsp[0].str),0); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2520 "parser.tab.c"
    break;

  case 167: /* EXPRESSION: DIGIT  */
#line 471 "parser.y"
                                                { assign_int((yyvsp[0].num), assign_index) ; char numtostring[40]; itoa((yyvsp[0].num), numtostring, 10); pushVStack(numtostring); char dum[10]="$"; StAssPush(strcat(dum,numtostring));}
#line 2526 "parser.tab.c"
    break;

  case 168: /* EXPRESSION: FLOAT_DIGIT  */
#line 472 "parser.y"
                                                { assign_int((yyvsp[0].float_val), assign_index); char floattostring[40]; gcvt((yyvsp[0].float_val), 6, floattostring); pushVStack(floattostring); char dum[10]="$"; StAssPush(strcat(dum,floattostring));}
#line 2532 "parser.tab.c"
    break;

  case 169: /* EXPRESSION: BOOL_LITERAL  */
#line 473 "parser.y"
                                                { assign_int((yyvsp[0].bool_val), assign_index); if((yyvsp[0].bool_val)==true){pushVStack("true");StAssPush("$true");}else{pushVStack("false");StAssPush("$false");} }
#line 2538 "parser.tab.c"
    break;

  case 170: /* EXPRESSION: STRING_LITERAL  */
#line 474 "parser.y"
                                                { assign_str((yyvsp[0].str), assign_index); pushVStack((yyvsp[0].str));char buf[50]; strcpy(buf, "$");strcat(buf, (yyvsp[0].str)); StAssPush(buf);}
#line 2544 "parser.tab.c"
    break;

  case 171: /* EXPRESSION: CONSTANT  */
#line 475 "parser.y"
                                                { int i = lookup((yyvsp[0].str),0); check_type(i); pushVStack((yyvsp[0].str)); StAssPush((yyvsp[0].str));}
#line 2550 "parser.tab.c"
    break;

  case 172: /* EXPRESSION: SUB EXPRESSION  */
#line 476 "parser.y"
                                                {StAssPrint("neg", 1);}
#line 2556 "parser.tab.c"
    break;

  case 173: /* EXPRESSION: EXPRESSION INC  */
#line 477 "parser.y"
                                                { pushVStack("+"); pushVStack("1"); CodeGenOp("ADD"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("ADD", 1); StAssPrint("STORE", 1);}
#line 2562 "parser.tab.c"
    break;

  case 174: /* EXPRESSION: EXPRESSION DEC  */
#line 478 "parser.y"
                                                { pushVStack("-"); pushVStack("1"); CodeGenOp("SUB"); StAssPrint("DUP",1); StAssPush("$1"); StAssPrint("SUB", 1); StAssPrint("STORE", 1);}
#line 2568 "parser.tab.c"
    break;

  case 175: /* $@48: %empty  */
#line 479 "parser.y"
                                                { pushVStack("+");}
#line 2574 "parser.tab.c"
    break;

  case 176: /* EXPRESSION: EXPRESSION PLUS $@48 EXPRESSION  */
#line 479 "parser.y"
                                                                                 {CodeGenOp("ADD"); StAssPrint("ADD", 1);}
#line 2580 "parser.tab.c"
    break;

  case 177: /* $@49: %empty  */
#line 480 "parser.y"
                                                { pushVStack("m");}
#line 2586 "parser.tab.c"
    break;

  case 178: /* EXPRESSION: EXPRESSION MODULO $@49 EXPRESSION  */
#line 480 "parser.y"
                                                                                 {CodeGenOp("MOD"); StAssPrint("MOD", 1);}
#line 2592 "parser.tab.c"
    break;

  case 179: /* $@50: %empty  */
#line 481 "parser.y"
                                                { pushVStack("-");}
#line 2598 "parser.tab.c"
    break;

  case 180: /* EXPRESSION: EXPRESSION SUB $@50 EXPRESSION  */
#line 481 "parser.y"
                                                                                 {CodeGenOp("SUB"); StAssPrint("SUB", 1);}
#line 2604 "parser.tab.c"
    break;

  case 181: /* $@51: %empty  */
#line 483 "parser.y"
                                                { pushVStack("*");}
#line 2610 "parser.tab.c"
    break;

  case 182: /* EXPRESSION: EXPRESSION MUL $@51 EXPRESSION  */
#line 483 "parser.y"
                                                                                 {CodeGenOp("MUL"); StAssPrint("MUL", 1);}
#line 2616 "parser.tab.c"
    break;

  case 183: /* $@52: %empty  */
#line 484 "parser.y"
                                                { pushVStack("/");}
#line 2622 "parser.tab.c"
    break;

  case 184: /* EXPRESSION: EXPRESSION DIV $@52 EXPRESSION  */
#line 484 "parser.y"
                                                                                 {CodeGenOp("DIV"); StAssPrint("DIV", 1);}
#line 2628 "parser.tab.c"
    break;

  case 185: /* $@53: %empty  */
#line 487 "parser.y"
                                                {pushVStack("^");}
#line 2634 "parser.tab.c"
    break;

  case 186: /* EXPRESSION: EXPRESSION POW $@53 EXPRESSION  */
#line 487 "parser.y"
                                                                               {CodeGenOp("POW");}
#line 2640 "parser.tab.c"
    break;

  case 190: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 491 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);pErr(yylineno);}
#line 2646 "parser.tab.c"
    break;

  case 195: /* COMPARISONSTT: EXPRESSION GT EXPRESSION  */
#line 511 "parser.y"
                                                        {pushVStack(">"); CodeGenLogical(); StAssPrint("GT", 1);}
#line 2652 "parser.tab.c"
    break;

  case 196: /* COMPARISONSTT: EXPRESSION LT EXPRESSION  */
#line 512 "parser.y"
                                                        {pushVStack("<"); CodeGenLogical(); StAssPrint("LT", 1);}
#line 2658 "parser.tab.c"
    break;

  case 197: /* COMPARISONSTT: EXPRESSION LT EQ EXPRESSION  */
#line 513 "parser.y"
                                                        {pushVStack("<="); CodeGenLogical(); StAssPrint("LE", 1);}
#line 2664 "parser.tab.c"
    break;

  case 198: /* COMPARISONSTT: EXPRESSION GT EQ EXPRESSION  */
#line 514 "parser.y"
                                                        {pushVStack(">="); CodeGenLogical(); StAssPrint("GE", 1);}
#line 2670 "parser.tab.c"
    break;

  case 199: /* COMPARISONSTT: EXPRESSION EQUALITY EXPRESSION  */
#line 515 "parser.y"
                                                        {pushVStack("="); CodeGenLogical(); StAssPrint("EQ", 1);}
#line 2676 "parser.tab.c"
    break;

  case 200: /* COMPARISONSTT: EXPRESSION NEG_EQUALITY EXPRESSION  */
#line 516 "parser.y"
                                                        {pushVStack("!="); CodeGenLogical(); StAssPrint("NE", 1);}
#line 2682 "parser.tab.c"
    break;

  case 201: /* COMPARISONSTT: EXPRESSION LOGIC_AND EXPRESSION  */
#line 517 "parser.y"
                                                        {pushVStack("and"); CodeGenLogical(); StAssPrint("AND", 1);}
#line 2688 "parser.tab.c"
    break;

  case 202: /* COMPARISONSTT: EXPRESSION LOGIC_OR EXPRESSION  */
#line 518 "parser.y"
                                                        {pushVStack("or"); CodeGenLogical(); StAssPrint("OR", 1);}
#line 2694 "parser.tab.c"
    break;

  case 203: /* COMPARISONSTT: LOGIC_NOT EXPRESSION  */
#line 519 "parser.y"
                                                        {StAssPrint("neg", 1);}
#line 2700 "parser.tab.c"
    break;

  case 205: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 524 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2706 "parser.tab.c"
    break;

  case 206: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 525 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2712 "parser.tab.c"
    break;

  case 207: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 526 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2718 "parser.tab.c"
    break;

  case 208: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 527 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2724 "parser.tab.c"
    break;

  case 209: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 528 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2730 "parser.tab.c"
    break;

  case 210: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 529 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2736 "parser.tab.c"
    break;

  case 211: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 530 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2742 "parser.tab.c"
    break;

  case 212: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 531 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2748 "parser.tab.c"
    break;

  case 213: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 532 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);pErr(yylineno);}
#line 2754 "parser.tab.c"
    break;

  case 214: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 533 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2760 "parser.tab.c"
    break;

  case 215: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 534 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2766 "parser.tab.c"
    break;

  case 216: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 535 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2772 "parser.tab.c"
    break;

  case 217: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 536 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2778 "parser.tab.c"
    break;

  case 218: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 537 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2784 "parser.tab.c"
    break;

  case 219: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 538 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2790 "parser.tab.c"
    break;

  case 220: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 539 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2796 "parser.tab.c"
    break;

  case 221: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 540 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);pErr(yylineno);}
#line 2802 "parser.tab.c"
    break;


#line 2806 "parser.tab.c"

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

#line 559 "parser.y"




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
    assign_index=-1;
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
