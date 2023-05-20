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
    int codeGen = 0;
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
    void CodeGenOp();
    void printIF();
    void printLLVM(char* s);
    char* makeLabel();
    char* makeEndLabel();
    void printWHILE();
    void controlTerminator(int isWhile);
    void CodeGenLogical();
//================================================================


#line 170 "parser.tab.c"

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
  YYSYMBOL_EQUALITY = 26,                  /* EQUALITY  */
  YYSYMBOL_NEG_EQUALITY = 27,              /* NEG_EQUALITY  */
  YYSYMBOL_SWITCH = 28,                    /* SWITCH  */
  YYSYMBOL_CASE = 29,                      /* CASE  */
  YYSYMBOL_LOGIC_AND = 30,                 /* LOGIC_AND  */
  YYSYMBOL_LOGIC_OR = 31,                  /* LOGIC_OR  */
  YYSYMBOL_LOGIC_NOT = 32,                 /* LOGIC_NOT  */
  YYSYMBOL_DIGIT = 33,                     /* DIGIT  */
  YYSYMBOL_IDENTIFIER = 34,                /* IDENTIFIER  */
  YYSYMBOL_FLOAT_DIGIT = 35,               /* FLOAT_DIGIT  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* ':'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_PROGRAM = 44,                   /* PROGRAM  */
  YYSYMBOL_STATEMENT = 45,                 /* STATEMENT  */
  YYSYMBOL_TYPE = 46,                      /* TYPE  */
  YYSYMBOL_DECLARATION_STT = 47,           /* DECLARATION_STT  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_DECLARATION_TAIL = 50,          /* DECLARATION_TAIL  */
  YYSYMBOL_51_3 = 51,                      /* $@3  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_ENUM_CALL_STT = 54,             /* ENUM_CALL_STT  */
  YYSYMBOL_SWITCH_STT = 55,                /* SWITCH_STT  */
  YYSYMBOL_CASES = 56,                     /* CASES  */
  YYSYMBOL_ERRONOUS_CASES = 57,            /* ERRONOUS_CASES  */
  YYSYMBOL_58_6 = 58,                      /* $@6  */
  YYSYMBOL_59_7 = 59,                      /* $@7  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 60,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_62_9 = 62,                      /* $@9  */
  YYSYMBOL_63_10 = 63,                     /* $@10  */
  YYSYMBOL_64_11 = 64,                     /* $@11  */
  YYSYMBOL_FUNC_DECLARATION_STT = 65,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_66_12 = 66,                     /* $@12  */
  YYSYMBOL_67_13 = 67,                     /* $@13  */
  YYSYMBOL_68_14 = 68,                     /* $@14  */
  YYSYMBOL_69_15 = 69,                     /* $@15  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 70, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_71_16 = 71,                     /* $@16  */
  YYSYMBOL_72_17 = 72,                     /* $@17  */
  YYSYMBOL_73_18 = 73,                     /* $@18  */
  YYSYMBOL_74_19 = 74,                     /* $@19  */
  YYSYMBOL_75_20 = 75,                     /* $@20  */
  YYSYMBOL_ARGS = 76,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 77,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 78,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 79,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_HELPER = 80,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 81,                 /* ENUM_ARGS  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 82,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 83, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_IF_STT_HELPER = 84,             /* IF_STT_HELPER  */
  YYSYMBOL_85_21 = 85,                     /* $@21  */
  YYSYMBOL_IF_STT_HELPER1 = 86,            /* IF_STT_HELPER1  */
  YYSYMBOL_IF_STT = 87,                    /* IF_STT  */
  YYSYMBOL_88_22 = 88,                     /* $@22  */
  YYSYMBOL_89_23 = 89,                     /* $@23  */
  YYSYMBOL_WHILE_STT = 90,                 /* WHILE_STT  */
  YYSYMBOL_91_24 = 91,                     /* $@24  */
  YYSYMBOL_DO_WHILE_STT = 92,              /* DO_WHILE_STT  */
  YYSYMBOL_ERRONOUS_DO_WHILE = 93,         /* ERRONOUS_DO_WHILE  */
  YYSYMBOL_94_25 = 94,                     /* $@25  */
  YYSYMBOL_95_26 = 95,                     /* $@26  */
  YYSYMBOL_96_27 = 96,                     /* $@27  */
  YYSYMBOL_97_28 = 97,                     /* $@28  */
  YYSYMBOL_FOR_STT = 98,                   /* FOR_STT  */
  YYSYMBOL_99_29 = 99,                     /* $@29  */
  YYSYMBOL_100_30 = 100,                   /* $@30  */
  YYSYMBOL_ERRONOUS_FOR_LOOP = 101,        /* ERRONOUS_FOR_LOOP  */
  YYSYMBOL_102_31 = 102,                   /* $@31  */
  YYSYMBOL_103_32 = 103,                   /* $@32  */
  YYSYMBOL_helperAssignmentRule = 104,     /* helperAssignmentRule  */
  YYSYMBOL_assignmentSTT = 105,            /* assignmentSTT  */
  YYSYMBOL_106_33 = 106,                   /* $@33  */
  YYSYMBOL_BLOCK = 107,                    /* BLOCK  */
  YYSYMBOL_108_34 = 108,                   /* $@34  */
  YYSYMBOL_109_35 = 109,                   /* $@35  */
  YYSYMBOL_FUNC_CALL = 110,                /* FUNC_CALL  */
  YYSYMBOL_111_36 = 111,                   /* $@36  */
  YYSYMBOL_112_37 = 112,                   /* $@37  */
  YYSYMBOL_113_38 = 113,                   /* $@38  */
  YYSYMBOL_USED_ARGS = 114,                /* USED_ARGS  */
  YYSYMBOL_115_39 = 115,                   /* $@39  */
  YYSYMBOL_EXPRESSION = 116,               /* EXPRESSION  */
  YYSYMBOL_117_40 = 117,                   /* $@40  */
  YYSYMBOL_118_41 = 118,                   /* $@41  */
  YYSYMBOL_119_42 = 119,                   /* $@42  */
  YYSYMBOL_120_43 = 120,                   /* $@43  */
  YYSYMBOL_121_44 = 121,                   /* $@44  */
  YYSYMBOL_ERRONOUS_EXPRESSION = 122,      /* ERRONOUS_EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 123,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 124,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 125                  /* RES_WORD  */
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
#define YYLAST   1165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  377

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      40,    38,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   149,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   175,
     176,   177,   178,   182,   182,   183,   183,   184,   185,   186,
     191,   192,   193,   194,   195,   195,   196,   196,   197,   197,
     204,   205,   210,   211,   216,   217,   218,   222,   222,   223,
     223,   227,   227,   228,   228,   229,   229,   230,   230,   245,
     246,   246,   247,   247,   248,   248,   249,   249,   253,   253,
     254,   255,   255,   256,   257,   257,   258,   258,   259,   259,
     263,   264,   265,   268,   271,   281,   282,   284,   284,   286,
     287,   290,   291,   294,   295,   297,   302,   302,   305,   309,
     310,   311,   312,   312,   313,   313,   314,   323,   323,   332,
     333,   336,   336,   337,   337,   338,   338,   339,   339,   340,
     347,   347,   347,   348,   352,   352,   353,   353,   360,   364,
     365,   366,   366,   371,   371,   371,   379,   379,   379,   379,
     380,   384,   384,   385,   386,   387,   393,   394,   395,   396,
     397,   398,   400,   401,   402,   402,   403,   403,   404,   404,
     405,   405,   406,   406,   407,   408,   409,   410,   419,   421,
     422,   423,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   467,
     467,   467,   467,   467,   467,   467,   467,   467,   467,   467,
     467,   467,   467
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
  "CONSTANT", "POW", "ELSE", "DO", "ENUM", "EQUALITY", "NEG_EQUALITY",
  "SWITCH", "CASE", "LOGIC_AND", "LOGIC_OR", "LOGIC_NOT", "DIGIT",
  "IDENTIFIER", "FLOAT_DIGIT", "'{'", "'}'", "')'", "':'", "'('", "','",
  "';'", "$accept", "PROGRAM", "STATEMENT", "TYPE", "DECLARATION_STT",
  "$@1", "$@2", "DECLARATION_TAIL", "$@3", "$@4", "$@5", "ENUM_CALL_STT",
  "SWITCH_STT", "CASES", "ERRONOUS_CASES", "$@6", "$@7",
  "ERRONOUS_SWITCH_STT", "$@8", "$@9", "$@10", "$@11",
  "FUNC_DECLARATION_STT", "$@12", "$@13", "$@14", "$@15",
  "ERRONOUS_FUNC_DECLARATION_STT", "$@16", "$@17", "$@18", "$@19", "$@20",
  "ARGS", "ERRONOUS_ARGS", "ARG_DECL", "ENUM_DECLARATION_STT",
  "ENUM_HELPER", "ENUM_ARGS", "ENUM_DEFINED_ARGS",
  "ERRONOUS_ENUM_DECLARATION_STT", "IF_STT_HELPER", "$@21",
  "IF_STT_HELPER1", "IF_STT", "$@22", "$@23", "WHILE_STT", "$@24",
  "DO_WHILE_STT", "ERRONOUS_DO_WHILE", "$@25", "$@26", "$@27", "$@28",
  "FOR_STT", "$@29", "$@30", "ERRONOUS_FOR_LOOP", "$@31", "$@32",
  "helperAssignmentRule", "assignmentSTT", "$@33", "BLOCK", "$@34", "$@35",
  "FUNC_CALL", "$@36", "$@37", "$@38", "USED_ARGS", "$@39", "EXPRESSION",
  "$@40", "$@41", "$@42", "$@43", "$@44", "ERRONOUS_EXPRESSION",
  "COMPARISONSTT", "ERRONOUS_COMPARISONSTT", "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-306)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-147)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -306,   207,  -306,   735,  -306,  -306,  -306,  -306,   -30,    20,
      16,  -306,  -306,  -306,  -306,    24,    27,    92,   463,  -306,
     151,  -306,  -306,   479,  -306,   -12,  -306,  -306,  -306,  -306,
    -306,    26,  -306,  -306,    36,  -306,  -306,  -306,  -306,  -306,
    -306,    90,  -306,  -306,  -306,   992,  -306,  -306,  -306,   479,
     380,   396,  -306,   479,   479,    93,   479,   479,   479,   479,
     479,    96,  -306,  -306,   106,  -306,   479,   292,    57,   479,
      99,    88,    80,   -13,  -306,    14,   107,   349,   632,   101,
    -306,   146,   110,  -306,  1112,   816,  -306,    11,  -306,    28,
     121,    26,  -306,  1012,  -306,   422,   438,  -306,   139,   153,
    -306,  -306,   504,   520,   545,   561,   161,   479,   161,   479,
     165,   390,   208,  -306,   632,   632,   632,   317,   317,  -306,
    -306,    66,   265,    26,  1072,   292,   292,   292,   691,   177,
     156,  -306,    18,   163,   -10,   104,   162,  -306,  -306,   166,
     170,    67,   101,  -306,   479,   185,  -306,  -306,   252,  -306,
     113,   174,   154,   113,   265,   186,  -306,    79,  -306,  -306,
     479,   107,   586,   161,   210,   602,   165,  -306,   479,  -306,
     479,   479,   479,  1143,   632,  1143,   632,  1132,   317,  1132,
     317,   161,   161,   189,  -306,   265,   192,   111,  -306,   197,
     195,  -306,   292,   292,   292,    26,   204,   220,   205,  -306,
     479,   479,   209,   479,   214,   212,   215,  -306,   218,   225,
     229,  -306,     1,  1032,   251,    62,  -306,   479,   627,  -306,
    -306,  -306,   235,  -306,    19,  -306,   241,  -306,   244,  -306,
     161,   107,   161,   210,   161,   390,   190,   208,   632,   265,
      26,  -306,  -306,  -306,  -306,   265,  -306,   245,   292,   292,
    -306,   479,   242,   479,   479,   970,   838,  -306,   651,   249,
    -306,  -306,  -306,     1,   258,     1,     1,   479,   479,   267,
    -306,  -306,  -306,   671,  -306,   860,  -306,  1052,  1092,   762,
     265,    26,  -306,  -306,  -306,  -306,  -306,   269,  -306,    26,
    -306,  -306,   271,   272,   882,   479,   904,   926,  -306,  -306,
     277,   278,     1,   281,   282,  1072,   714,  -306,    62,   276,
     280,  -306,  -306,  -306,   296,   299,   798,   300,  -306,   302,
      26,  -306,  -306,    26,  -306,  -306,  -306,   948,  -306,  -306,
     326,  -306,  -306,   305,  -306,  -306,   306,    83,  -306,  -306,
      62,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,    26,    26,  -306,  -306,    26,  -306,     1,  -306,
    -306,  -306,     1,     1,  -306,  -306,  -306
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    19,    20,    21,    22,     0,    96,
       0,   107,   149,   150,   151,     0,     0,     0,     0,   147,
       0,   148,   133,     0,     2,     0,     4,    14,    12,    43,
       5,     0,    13,    86,   102,     8,     9,    11,   110,    10,
     123,     0,     6,    15,   165,     0,   167,   164,   181,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    71,   104,     0,     0,   120,     0,
     111,     0,     0,     0,    51,     0,   190,     0,   180,   131,
     128,     0,     0,     3,     0,     0,    25,    68,    59,     0,
      99,     0,   129,     0,   160,     0,     0,     7,   154,   156,
     158,   162,     0,     0,     0,     0,   170,     0,   182,     0,
     184,   168,   169,    28,   171,   186,   188,   191,   193,    27,
      76,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,   115,     0,     0,    90,     0,     0,    87,    88,     0,
      53,     0,     0,   140,     0,     0,    41,   137,     0,   166,
       0,    74,     0,     0,     0,     0,    98,     0,   103,   130,
       0,   183,     0,   172,   185,     0,   173,   152,     0,   153,
       0,     0,     0,   187,   176,   189,   177,   192,   178,   194,
     179,   197,   195,     0,    66,     0,     0,     0,    82,    81,
       0,   105,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,    94,     0,     0,
       0,    57,     0,     0,     0,     0,   134,     0,     0,    33,
      26,    29,     0,    64,     0,    24,     0,   106,     0,   100,
     161,   198,   175,   196,   174,   155,   157,   159,   163,     0,
       0,    83,    84,    73,    62,     0,    72,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,    93,    92,    90,
      89,    95,    85,     0,     0,     0,     0,     0,     0,     0,
      45,   132,    40,     0,   138,   141,   135,     0,     0,    38,
       0,     0,    78,    70,    60,    69,   101,     0,    67,     0,
      80,   124,     0,     0,     0,     0,     0,     0,   119,   109,
       0,     0,     0,     0,     0,    47,     0,    42,     0,     0,
       0,    31,    32,    30,     0,     0,     0,     0,    65,     0,
       0,    77,    63,     0,   126,   121,   112,     0,   116,   114,
       0,    91,    52,     0,    56,    58,     0,     0,   143,   139,
       0,    35,    37,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    39,    75,    79,
      61,   125,     0,     0,   118,    54,     0,    49,     0,   142,
     127,   122,     0,     0,    44,    48,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -306,   263,   -60,  -108,  -306,  -306,  -306,   196,  -306,  -306,
    -306,  -306,  -306,  -255,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -104,  -306,  -306,  -306,    61,   160,    60,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,   -15,  -306,  -306,  -306,  -306,  -306,
    -306,  -305,  -306,   -17,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    24,    25,    26,   153,   150,   220,   314,   315,
     316,    27,    28,   269,   270,   336,   373,    29,   139,   209,
     210,   266,    30,   320,   289,   281,   240,    31,   154,   122,
     222,   183,   319,   187,   188,   189,    32,   136,   137,   138,
      33,    34,    66,    90,    35,    91,   123,    36,    69,    37,
      38,   129,   254,   198,   130,    39,   127,   363,    40,   323,
     362,    41,    42,   144,    43,    83,   276,    44,    82,   215,
     309,   274,   310,    45,   168,   170,   171,   160,   172,    46,
      47,    48,   357
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,    78,   267,   338,    64,   203,    85,   125,   301,    86,
     303,   304,   -23,   186,   186,   140,    88,    67,   190,   199,
     282,   134,    87,   135,    93,    70,   -23,   -23,    72,   155,
     268,   204,   106,   108,   110,   369,   111,   112,   -46,   114,
     115,   116,   117,   118,   186,   151,   186,   333,   224,   124,
     226,   152,   128,   141,   200,   283,    68,   284,   201,    65,
      22,    73,    22,   273,    22,   192,   193,   194,   211,     4,
       5,     6,     7,    12,   156,    89,   158,   186,   163,   166,
     228,   241,    13,    14,   367,   174,   176,   178,   180,   131,
     181,    84,   182,    74,    18,    19,    77,    21,   132,   126,
    -145,    12,    23,   212,   184,   205,    92,   185,   191,   113,
      13,    14,   119,   374,   217,    22,   133,   375,   376,    22,
      50,    51,    18,    19,    77,    21,    75,   213,   218,   219,
      23,   186,   247,   248,   249,   287,  -117,   186,   134,   143,
     120,   290,   229,   230,   157,   232,   121,   243,   234,   244,
     147,   235,    79,   236,   237,   238,   167,     4,     5,     6,
       7,   145,   146,  -146,  -146,  -146,    80,  -146,  -146,  -146,
    -146,   169,   186,  -146,    95,    96,   317,  -146,  -146,    96,
     250,  -146,  -146,   255,   256,    81,   258,   196,   292,   293,
     221,  -136,   223,   197,   202,   185,   206,   134,   275,   207,
     277,   279,    94,    95,    96,   208,   -55,     2,     3,   100,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   214,
      94,    95,    96,   227,    51,   288,   242,    13,    14,   239,
     252,    15,    16,   246,   294,    17,   296,   297,   245,    18,
      19,    20,    21,    22,   251,   253,   257,    23,   259,   261,
     305,   306,   262,     3,   263,     4,     5,     6,     7,     8,
       9,    10,    11,    12,   264,   265,   318,   272,     4,     5,
       6,     7,    13,    14,   322,   280,    15,    16,   327,   285,
      17,   286,   295,   291,    18,    19,    20,    21,    22,   216,
     204,   275,    23,     3,   302,     4,     5,     6,     7,     8,
       9,    10,    11,    12,   307,   360,   185,   321,   361,   324,
     325,   330,    13,    14,   339,   332,    15,    16,   334,   335,
      17,   340,   368,   275,    18,    19,    20,    21,    22,    94,
      95,    96,    23,   341,    98,    99,   100,   342,   358,   101,
     359,   203,   365,   102,   103,   366,   148,   370,   371,   225,
     142,   372,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
     331,  -146,  -146,  -146,   260,  -146,  -146,  -146,  -146,     0,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,    84,     0,     0,     0,  -146,  -146,  -146,  -146,  -136,
    -146,    12,     0,     0,     0,   107,     0,    84,     0,     0,
      13,    14,    94,    95,    96,     0,     0,    12,    99,   100,
       0,   109,    18,    19,    77,    21,    13,    14,     0,     0,
      23,     0,     0,   161,     0,     0,     0,     0,    18,    19,
      77,    21,     0,    12,     0,     0,    23,   162,     0,   164,
       0,     0,    13,    14,     0,     0,     0,     0,     0,    12,
       0,     0,     0,   165,    18,    19,    77,    21,    13,    14,
       0,     0,    23,     0,    76,     0,     0,     0,     0,     0,
      18,    19,    77,    21,    12,     0,     0,     0,    23,     0,
      84,     0,     0,    13,    14,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,    18,    19,    77,    21,    13,
      14,     0,     0,    23,     0,   173,     0,     0,     0,     0,
       0,    18,    19,    77,    21,    12,     0,     0,     0,    23,
       0,   175,     0,     0,    13,    14,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,    18,    19,    77,    21,
      13,    14,     0,     0,    23,     0,   177,     0,     0,     0,
       0,     0,    18,    19,    77,    21,    12,     0,     0,     0,
      23,     0,   179,     0,     0,    13,    14,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,    18,    19,    77,
      21,    13,    14,     0,     0,    23,     0,   231,     0,     0,
       0,     0,     0,    18,    19,    77,    21,    12,     0,     0,
       0,    23,     0,   233,     0,     0,    13,    14,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,    18,    19,
      77,    21,    13,    14,     0,     0,    23,     0,   278,     0,
       0,     0,     0,     0,    18,    19,    77,    21,    12,     0,
       0,     0,    23,     0,    94,    95,    96,    13,    14,    98,
      99,   100,     0,     0,   101,     0,     0,     0,     0,    18,
      19,    77,    21,    94,    95,    96,     0,    23,    98,    99,
     100,     0,     0,   101,     0,     0,     0,   102,   103,     0,
       0,   104,   105,    49,    50,    51,     0,     0,    53,     0,
      54,     0,   300,    56,     0,     0,     0,    57,    58,     0,
       0,    59,    60,    94,    95,    96,     0,     0,    98,    99,
     100,     0,   308,   101,     0,     0,     0,   102,   103,     0,
       0,   104,   105,     0,     0,     0,    94,    95,    96,     0,
     195,    98,    99,   100,     0,     0,   101,     0,     0,     0,
     102,   103,     0,     0,   104,   105,     0,    49,    50,    51,
       0,    52,    53,   337,    54,     0,    55,    56,     0,     0,
       0,    57,    58,     0,     0,    59,    60,     0,     0,    61,
       0,     0,    62,    63,    94,    95,    96,     0,   313,    98,
      99,   100,     0,     0,   101,     0,     0,     0,   102,   103,
       0,     0,   104,   105,     0,     0,     0,     0,     0,   -34,
     -36,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   351,
       0,   352,   353,   354,     0,     0,   355,   356,    94,    95,
      96,     0,     0,    98,    99,   100,     0,     0,   101,     0,
       0,     0,   102,   103,     0,     0,   104,   105,     0,     0,
      94,    95,    96,     0,   149,    98,    99,   100,     0,     0,
     101,     0,     0,     0,   102,   103,     0,     0,   104,   105,
       0,     0,    94,    95,    96,     0,   299,    98,    99,   100,
       0,     0,   101,     0,     0,     0,   102,   103,     0,     0,
     104,   105,     0,     0,    94,    95,    96,     0,  -144,    98,
      99,   100,     0,     0,   101,     0,     0,     0,   102,   103,
       0,     0,   104,   105,     0,     0,    94,    95,    96,     0,
     326,    98,    99,   100,     0,     0,   101,     0,     0,     0,
     102,   103,     0,     0,   104,   105,     0,     0,    94,    95,
      96,     0,   328,    98,    99,   100,     0,     0,   101,     0,
       0,     0,   102,   103,     0,     0,   104,   105,     0,     0,
      94,    95,    96,     0,   329,    98,    99,   100,     0,     0,
     101,     0,     0,     0,   102,   103,     0,     0,   104,   105,
       0,     0,    94,    95,    96,     0,   364,    98,    99,   100,
       0,     0,   101,     0,     0,     0,   102,   103,     0,     0,
     104,   105,     0,     0,    94,    95,    96,   298,    97,    98,
      99,   100,     0,     0,   101,     0,     0,     0,   102,   103,
       0,     0,   104,   105,    94,    95,    96,     0,   159,    98,
      99,   100,     0,     0,   101,     0,     0,     0,   102,   103,
       0,     0,   104,   105,    94,    95,    96,     0,   271,    98,
      99,   100,     0,     0,   101,     0,     0,     0,   102,   103,
       0,     0,   104,   105,    94,    95,    96,     0,   311,    98,
      99,   100,     0,     0,   101,     0,     0,     0,   102,   103,
       0,     0,   104,   105,    94,    95,    96,     0,     0,    98,
      99,   100,     0,     0,   101,     0,     0,     0,   102,   103,
       0,     0,   104,   105,    49,    50,    51,     0,   312,    53,
       0,    54,     0,     0,    56,     0,     0,     0,    57,    58,
       0,     0,    59,    60,    49,    50,    51,     0,     0,    53,
       0,    54,     0,     0,    56,     0,     0,     0,    57,    58,
       0,     0,    59,    60,    49,    50,    51,     0,     0,    53,
       0,    54,     0,     0,    56,    49,    50,    51,    57,    58,
      53,     0,    54,     0,     0,    56
};

static const yytype_int16 yycheck[] =
{
      15,    18,     1,   308,    34,    15,    23,    67,   263,    21,
     265,   266,     1,   121,   122,     1,    31,     1,   122,     1,
       1,    34,    34,    36,    41,     1,    15,    16,     1,     1,
      29,    41,    49,    50,    51,   340,    53,    54,    37,    56,
      57,    58,    59,    60,   152,    34,   154,   302,   152,    66,
     154,    40,    69,    39,    36,    36,    40,    38,    40,    39,
      36,    34,    36,     1,    36,   125,   126,   127,     1,     3,
       4,     5,     6,    11,    89,    39,    91,   185,    95,    96,
       1,   185,    20,    21,     1,   102,   103,   104,   105,     1,
     107,     1,   109,     1,    32,    33,    34,    35,    10,    42,
      38,    11,    40,    36,    38,     1,    16,    41,   123,    16,
      20,    21,    16,   368,     1,    36,    36,   372,   373,    36,
      13,    14,    32,    33,    34,    35,    34,   144,    15,    16,
      40,   239,   192,   193,   194,   239,    37,   245,    34,    38,
      34,   245,   157,   160,    23,   162,    40,    36,   165,    38,
      40,   168,     1,   170,   171,   172,    17,     3,     4,     5,
       6,    15,    16,    12,    13,    14,    15,    16,    17,    18,
      19,    18,   280,    22,    13,    14,   280,    26,    27,    14,
     195,    30,    31,   200,   201,    34,   203,    10,   248,   249,
      16,    40,    38,    37,   133,    41,   135,    34,   215,    37,
     217,   218,    12,    13,    14,    39,    36,     0,     1,    19,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    34,
      12,    13,    14,    37,    14,   240,    34,    20,    21,    40,
      10,    24,    25,    38,   251,    28,   253,   254,    41,    32,
      33,    34,    35,    36,    40,    40,    37,    40,    34,    37,
     267,   268,    37,     1,    36,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    39,    36,   281,    16,     3,     4,
       5,     6,    20,    21,   289,    40,    24,    25,   295,    38,
      28,    37,    40,    38,    32,    33,    34,    35,    36,    37,
      41,   308,    40,     1,    36,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    37,   320,    41,    38,   323,    38,
      38,    34,    20,    21,    38,    37,    24,    25,    37,    37,
      28,    41,   337,   340,    32,    33,    34,    35,    36,    12,
      13,    14,    40,    37,    17,    18,    19,    38,    38,    22,
      38,    15,    37,    26,    27,    39,    83,   362,   363,   153,
       1,   366,     3,     4,     5,     6,     7,     8,     9,    10,
     300,    12,    13,    14,   204,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    11,    -1,    -1,    -1,    15,    -1,     1,    -1,    -1,
      20,    21,    12,    13,    14,    -1,    -1,    11,    18,    19,
      -1,    15,    32,    33,    34,    35,    20,    21,    -1,    -1,
      40,    -1,    -1,     1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    -1,    11,    -1,    -1,    40,    15,    -1,     1,
      -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    15,    32,    33,    34,    35,    20,    21,
      -1,    -1,    40,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    11,    -1,    -1,    -1,    40,    -1,
       1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    20,
      21,    -1,    -1,    40,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    11,    -1,    -1,    -1,    40,
      -1,     1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      20,    21,    -1,    -1,    40,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    11,    -1,    -1,    -1,
      40,    -1,     1,    -1,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    20,    21,    -1,    -1,    40,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    11,    -1,    -1,
      -1,    40,    -1,     1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    20,    21,    -1,    -1,    40,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    11,    -1,
      -1,    -1,    40,    -1,    12,    13,    14,    20,    21,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    12,    13,    14,    -1,    40,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    12,    13,    14,    -1,    -1,    17,    -1,
      19,    -1,    41,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    41,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    -1,    -1,    -1,    12,    13,    14,    -1,
      39,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    -1,    12,    13,    14,
      -1,    16,    17,    39,    19,    -1,    21,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,    34,
      -1,    -1,    37,    38,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    23,    24,    25,    -1,    -1,    28,    29,    12,    13,
      14,    -1,    -1,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,
      12,    13,    14,    -1,    38,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      -1,    -1,    12,    13,    14,    -1,    38,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    -1,    -1,    12,    13,    14,    -1,    38,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    -1,    -1,    12,    13,    14,    -1,
      38,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    -1,    -1,    12,    13,
      14,    -1,    38,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,
      12,    13,    14,    -1,    38,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      -1,    -1,    12,    13,    14,    -1,    38,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    -1,    -1,    12,    13,    14,    37,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    12,    13,    14,    -1,    -1,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    12,    13,    14,    -1,    16,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    12,    13,    14,    -1,    -1,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    12,    13,    14,    -1,    -1,    17,
      -1,    19,    -1,    -1,    22,    12,    13,    14,    26,    27,
      17,    -1,    19,    -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    20,    21,    24,    25,    28,    32,    33,
      34,    35,    36,    40,    45,    46,    47,    54,    55,    60,
      65,    70,    79,    83,    84,    87,    90,    92,    93,    98,
     101,   104,   105,   107,   110,   116,   122,   123,   124,    12,
      13,    14,    16,    17,    19,    21,    22,    26,    27,    30,
      31,    34,    37,    38,    34,    39,    85,     1,    40,    91,
       1,   107,     1,    34,     1,    34,     1,    34,   116,     1,
      15,    34,   111,   108,     1,   116,    21,    34,   107,    39,
      86,    88,    16,   116,    12,    13,    14,    16,    17,    18,
      19,    22,    26,    27,    30,    31,   116,    15,   116,    15,
     116,   116,   116,    16,   116,   116,   116,   116,   116,    16,
      34,    40,    72,    89,   116,    45,    42,    99,   116,    94,
      97,     1,    10,    36,    34,    36,    80,    81,    82,    61,
       1,    39,     1,    38,   106,    15,    16,    40,    44,    38,
      49,    34,    40,    48,    71,     1,   107,    23,   107,    16,
     120,     1,    15,   116,     1,    15,   116,    17,   117,    18,
     118,   119,   121,     1,   116,     1,   116,     1,   116,     1,
     116,   116,   116,    74,    38,    41,    46,    76,    77,    78,
      76,   107,    45,    45,    45,    39,    10,    37,    96,     1,
      36,    40,    80,    15,    41,     1,    80,    37,    39,    62,
      63,     1,    36,   116,    34,   112,    37,     1,    15,    16,
      50,    16,    73,    38,    76,    50,    76,    37,     1,   107,
     116,     1,   116,     1,   116,   116,   116,   116,   116,    40,
      69,    76,    34,    36,    38,    41,    38,    45,    45,    45,
     107,    40,    10,    40,    95,   116,   116,    37,   116,    34,
      81,    37,    37,    36,    39,    36,    64,     1,    29,    56,
      57,    16,    16,     1,   114,   116,   109,   116,     1,   116,
      40,    68,     1,    36,    38,    38,    37,    76,   107,    67,
      76,    38,    45,    45,   116,    40,   116,   116,    37,    38,
      41,    56,    36,    56,    56,   116,   116,    37,    41,   113,
     115,    16,    16,    16,    51,    52,    53,    76,   107,    75,
      66,    38,   107,   102,    38,    38,    38,   116,    38,    38,
      34,    82,    37,    56,    37,    37,    58,    39,   114,    38,
      41,    37,    38,     3,     4,     5,     6,     7,     8,     9,
      10,    21,    23,    24,    25,    28,    29,   125,    38,    38,
     107,   107,   103,   100,    38,    37,    39,     1,   107,   114,
     107,   107,   107,    59,    56,    56,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      46,    46,    46,    48,    47,    49,    47,    47,    47,    47,
      50,    50,    50,    50,    51,    50,    52,    50,    53,    50,
      54,    54,    55,    55,    56,    56,    56,    58,    57,    59,
      57,    61,    60,    62,    60,    63,    60,    64,    60,    65,
      66,    65,    67,    65,    68,    65,    69,    65,    71,    70,
      70,    72,    70,    70,    73,    70,    74,    70,    75,    70,
      76,    76,    76,    77,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    85,    84,    86,    87,
      87,    87,    88,    87,    89,    87,    87,    91,    90,    92,
      92,    94,    93,    95,    93,    96,    93,    97,    93,    93,
      99,   100,    98,    98,   102,   101,   103,   101,   104,   105,
     105,   106,   105,   108,   109,   107,   111,   112,   113,   110,
     110,   115,   114,   114,   114,   114,   116,   116,   116,   116,
     116,   116,   116,   116,   117,   116,   118,   116,   119,   116,
     120,   116,   121,   116,   116,   116,   116,   116,   122,   122,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     0,     4,     0,     4,     3,     3,     4,
       3,     3,     3,     1,     0,     4,     0,     4,     0,     4,
       5,     3,     6,     1,     5,     1,     0,     0,     6,     0,
       6,     0,     7,     0,     8,     0,     7,     0,     7,     2,
       0,     7,     0,     7,     0,     6,     0,     6,     0,     5,
       5,     0,     5,     5,     0,     7,     0,     7,     0,     7,
       3,     1,     1,     2,     2,     5,     1,     1,     1,     3,
       1,     5,     3,     5,     4,     5,     0,     3,     2,     2,
       4,     5,     0,     3,     0,     4,     4,     0,     5,     6,
       1,     0,     7,     0,     7,     0,     7,     0,     8,     6,
       0,     0,     9,     1,     0,     8,     0,     9,     2,     2,
       3,     0,     5,     0,     0,     5,     0,     0,     0,     7,
       3,     0,     4,     3,     1,     0,     1,     1,     1,     1,
       1,     1,     3,     3,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     1,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     4,     4,     3,     3,     3,     3,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     4,     4,     4,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 148 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1714 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 154 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1720 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 157 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1726 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 158 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1732 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 159 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1738 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 160 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1744 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 161 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1750 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 162 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1756 "parser.tab.c"
    break;

  case 14: /* STATEMENT: ENUM_CALL_STT  */
#line 163 "parser.y"
                                                            {printf("#[Parsed_Enum_USAGE]# ");}
#line 1762 "parser.tab.c"
    break;

  case 16: /* STATEMENT: error SEMICOLON  */
#line 165 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1768 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error '}'  */
#line 166 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1774 "parser.tab.c"
    break;

  case 18: /* STATEMENT: error ')'  */
#line 167 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1780 "parser.tab.c"
    break;

  case 19: /* TYPE: INT  */
#line 175 "parser.y"
                    { (yyval.str) = "int"; }
#line 1786 "parser.tab.c"
    break;

  case 20: /* TYPE: FLOAT  */
#line 176 "parser.y"
                        { (yyval.str) = "float"; }
#line 1792 "parser.tab.c"
    break;

  case 21: /* TYPE: BOOL  */
#line 177 "parser.y"
                        { (yyval.str) = "bool"; }
#line 1798 "parser.tab.c"
    break;

  case 22: /* TYPE: STRING  */
#line 178 "parser.y"
                         { (yyval.str) = "string"; }
#line 1804 "parser.tab.c"
    break;

  case 23: /* $@1: %empty  */
#line 182 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0); assign_index= st_index-1; }
#line 1810 "parser.tab.c"
    break;

  case 24: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 182 "parser.y"
                                                                                                                      {printf("#[Parsed_Declaration]# "); }
#line 1816 "parser.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 183 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0);  assign_index= st_index-1;}
#line 1822 "parser.tab.c"
    break;

  case 26: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 183 "parser.y"
                                                                                                                       {printf("#[Parsed_CONST_Declaration]# "); }
#line 1828 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 184 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1834 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 185 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1840 "parser.tab.c"
    break;

  case 29: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 186 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);}
#line 1846 "parser.tab.c"
    break;

  case 31: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 192 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1852 "parser.tab.c"
    break;

  case 32: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 193 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1858 "parser.tab.c"
    break;

  case 34: /* $@3: %empty  */
#line 195 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1864 "parser.tab.c"
    break;

  case 36: /* $@4: %empty  */
#line 196 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1870 "parser.tab.c"
    break;

  case 38: /* $@5: %empty  */
#line 197 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1876 "parser.tab.c"
    break;

  case 47: /* $@6: %empty  */
#line 222 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);}
#line 1882 "parser.tab.c"
    break;

  case 49: /* $@7: %empty  */
#line 223 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);}
#line 1888 "parser.tab.c"
    break;

  case 51: /* $@8: %empty  */
#line 227 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1894 "parser.tab.c"
    break;

  case 53: /* $@9: %empty  */
#line 228 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }
#line 1900 "parser.tab.c"
    break;

  case 55: /* $@10: %empty  */
#line 229 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1906 "parser.tab.c"
    break;

  case 57: /* $@11: %empty  */
#line 230 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1912 "parser.tab.c"
    break;

  case 60: /* $@12: %empty  */
#line 246 "parser.y"
                                                 {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1918 "parser.tab.c"
    break;

  case 62: /* $@13: %empty  */
#line 247 "parser.y"
                                                 {st_insert("void", (yyvsp[-3].str),"func",0);}
#line 1924 "parser.tab.c"
    break;

  case 64: /* $@14: %empty  */
#line 248 "parser.y"
                                                 {st_insert((yyvsp[-3].str), (yyvsp[-2].str),"func",0);}
#line 1930 "parser.tab.c"
    break;

  case 66: /* $@15: %empty  */
#line 249 "parser.y"
                                                 {st_insert("void", (yyvsp[-2].str),"func",0);}
#line 1936 "parser.tab.c"
    break;

  case 68: /* $@16: %empty  */
#line 253 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1942 "parser.tab.c"
    break;

  case 69: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@16 ARGS ')'  */
#line 253 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1948 "parser.tab.c"
    break;

  case 70: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS '{'  */
#line 254 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1954 "parser.tab.c"
    break;

  case 71: /* $@17: %empty  */
#line 255 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1960 "parser.tab.c"
    break;

  case 72: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER $@17 ARGS ')'  */
#line 255 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1966 "parser.tab.c"
    break;

  case 73: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER '(' ARGS '{'  */
#line 256 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1972 "parser.tab.c"
    break;

  case 74: /* $@18: %empty  */
#line 257 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1978 "parser.tab.c"
    break;

  case 75: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER $@18 '(' ARGS ')'  */
#line 257 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1984 "parser.tab.c"
    break;

  case 76: /* $@19: %empty  */
#line 258 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1990 "parser.tab.c"
    break;

  case 77: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER IDENTIFIER $@19 '(' ARGS ')'  */
#line 258 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1996 "parser.tab.c"
    break;

  case 78: /* $@20: %empty  */
#line 259 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected token '%s' in argument list of function declaration at line %d\n\n", yylval, yylineno);}
#line 2002 "parser.tab.c"
    break;

  case 79: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS error $@20 ')'  */
#line 259 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 2008 "parser.tab.c"
    break;

  case 83: /* ERRONOUS_ARGS: ',' ARGS  */
#line 268 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
#line 2014 "parser.tab.c"
    break;

  case 84: /* ARG_DECL: TYPE IDENTIFIER  */
#line 271 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1);}
#line 2020 "parser.tab.c"
    break;

  case 85: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_HELPER '}'  */
#line 281 "parser.y"
                                                              { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 2026 "parser.tab.c"
    break;

  case 93: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 294 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);}
#line 2032 "parser.tab.c"
    break;

  case 94: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 295 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);}
#line 2038 "parser.tab.c"
    break;

  case 95: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 297 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2044 "parser.tab.c"
    break;

  case 96: /* $@21: %empty  */
#line 302 "parser.y"
                   {printIF();}
#line 2050 "parser.tab.c"
    break;

  case 98: /* IF_STT_HELPER1: ':' BLOCK  */
#line 305 "parser.y"
                          {controlTerminator(0);}
#line 2056 "parser.tab.c"
    break;

  case 101: /* IF_STT: IF_STT_HELPER IF_STT_HELPER1 ELSE error '}'  */
#line 311 "parser.y"
                                                                   {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);}
#line 2062 "parser.tab.c"
    break;

  case 102: /* $@22: %empty  */
#line 312 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 2068 "parser.tab.c"
    break;

  case 103: /* IF_STT: IF_STT_HELPER $@22 BLOCK  */
#line 312 "parser.y"
                                                                                                                                                                      {char*dummy; strcpy(dummy, makeEndLabel()); printLLVM(dummy); printLLVM(":\n");}
#line 2074 "parser.tab.c"
    break;

  case 104: /* $@23: %empty  */
#line 313 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);}
#line 2080 "parser.tab.c"
    break;

  case 105: /* IF_STT: IF ':' $@23 BLOCK  */
#line 313 "parser.y"
                                                                                                                                                                      {char*dummy; strcpy(dummy, makeEndLabel()); printLLVM(dummy); printLLVM(":\n");}
#line 2086 "parser.tab.c"
    break;

  case 106: /* IF_STT: IF_STT_HELPER ':' error '}'  */
#line 314 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);}
#line 2092 "parser.tab.c"
    break;

  case 107: /* $@24: %empty  */
#line 323 "parser.y"
                      {printWHILE();}
#line 2098 "parser.tab.c"
    break;

  case 108: /* WHILE_STT: WHILE $@24 EXPRESSION ':' BLOCK  */
#line 323 "parser.y"
                                                           {controlTerminator(1);}
#line 2104 "parser.tab.c"
    break;

  case 111: /* $@25: %empty  */
#line 336 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2110 "parser.tab.c"
    break;

  case 113: /* $@26: %empty  */
#line 337 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2116 "parser.tab.c"
    break;

  case 115: /* $@27: %empty  */
#line 338 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);}
#line 2122 "parser.tab.c"
    break;

  case 117: /* $@28: %empty  */
#line 339 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);}
#line 2128 "parser.tab.c"
    break;

  case 119: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 340 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);}
#line 2134 "parser.tab.c"
    break;

  case 120: /* $@29: %empty  */
#line 347 "parser.y"
                        {in_loop = 1;}
#line 2140 "parser.tab.c"
    break;

  case 121: /* $@30: %empty  */
#line 347 "parser.y"
                                                                        {in_loop = 0;}
#line 2146 "parser.tab.c"
    break;

  case 124: /* $@31: %empty  */
#line 352 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);}
#line 2152 "parser.tab.c"
    break;

  case 126: /* $@32: %empty  */
#line 353 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);}
#line 2158 "parser.tab.c"
    break;

  case 128: /* helperAssignmentRule: IDENTIFIER EQ  */
#line 360 "parser.y"
                                {pushVStack((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str));}
#line 2164 "parser.tab.c"
    break;

  case 129: /* assignmentSTT: helperAssignmentRule SEMICOLON  */
#line 364 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);}
#line 2170 "parser.tab.c"
    break;

  case 130: /* assignmentSTT: helperAssignmentRule EXPRESSION SEMICOLON  */
#line 365 "parser.y"
                                                                     {CodeGenAss();printf("#[Parsed_Assignment]# ");}
#line 2176 "parser.tab.c"
    break;

  case 131: /* $@33: %empty  */
#line 366 "parser.y"
                                   {pushVStack((yyvsp[-1].str)); assign_index = lookup((yyvsp[-1].str));}
#line 2182 "parser.tab.c"
    break;

  case 132: /* assignmentSTT: IDENTIFIER error $@33 EXPRESSION SEMICOLON  */
#line 366 "parser.y"
                                                                                                         {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);}
#line 2188 "parser.tab.c"
    break;

  case 133: /* $@34: %empty  */
#line 371 "parser.y"
                    {scope_start();}
#line 2194 "parser.tab.c"
    break;

  case 134: /* $@35: %empty  */
#line 371 "parser.y"
                                                 {scope_end();}
#line 2200 "parser.tab.c"
    break;

  case 135: /* BLOCK: '{' $@34 PROGRAM '}' $@35  */
#line 371 "parser.y"
                                                                                    {printf("#[Parsed_Block]# ");}
#line 2206 "parser.tab.c"
    break;

  case 136: /* $@36: %empty  */
#line 379 "parser.y"
                           {called_func_index = lookup((yyvsp[0].str)); check_type(called_func_index); }
#line 2212 "parser.tab.c"
    break;

  case 137: /* $@37: %empty  */
#line 379 "parser.y"
                                                                                                 { is_param =1;}
#line 2218 "parser.tab.c"
    break;

  case 138: /* $@38: %empty  */
#line 379 "parser.y"
                                                                                                                            { is_param =0; arg_count_check(called_func_index); arg_count=0;}
#line 2224 "parser.tab.c"
    break;

  case 139: /* FUNC_CALL: IDENTIFIER $@36 '(' $@37 USED_ARGS $@38 ')'  */
#line 379 "parser.y"
                                                                                                                                                                                                   { printf("#[Parsed_Func_Call]# ");}
#line 2230 "parser.tab.c"
    break;

  case 140: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 380 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 2236 "parser.tab.c"
    break;

  case 141: /* $@39: %empty  */
#line 384 "parser.y"
                           { arg_count++; }
#line 2242 "parser.tab.c"
    break;

  case 143: /* USED_ARGS: error ',' USED_ARGS  */
#line 385 "parser.y"
                                                        {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 2248 "parser.tab.c"
    break;

  case 144: /* USED_ARGS: EXPRESSION  */
#line 386 "parser.y"
                             {arg_count++ ;}
#line 2254 "parser.tab.c"
    break;

  case 146: /* EXPRESSION: IDENTIFIER  */
#line 393 "parser.y"
                            { int i = lookup((yyvsp[0].str)); check_type(i); pushVStack((yyvsp[0].str));}
#line 2260 "parser.tab.c"
    break;

  case 147: /* EXPRESSION: DIGIT  */
#line 394 "parser.y"
                        { assign_int((yyvsp[0].num), assign_index) ; char numtostring[40]; itoa((yyvsp[0].num), numtostring, 10); pushVStack(numtostring);}
#line 2266 "parser.tab.c"
    break;

  case 148: /* EXPRESSION: FLOAT_DIGIT  */
#line 395 "parser.y"
                              { assign_float((yyvsp[0].float_val), assign_index); char floattostring[40]; gcvt((yyvsp[0].float_val), 6, floattostring); pushVStack(floattostring);}
#line 2272 "parser.tab.c"
    break;

  case 149: /* EXPRESSION: BOOL_LITERAL  */
#line 396 "parser.y"
                                { assign_bool((yyvsp[0].bool_val), assign_index); if((yyvsp[0].bool_val)==true){pushVStack("true");}else{pushVStack("false");}}
#line 2278 "parser.tab.c"
    break;

  case 150: /* EXPRESSION: STRING_LITERAL  */
#line 397 "parser.y"
                                  {  assign_str((yyvsp[0].str), assign_index); pushVStack((yyvsp[0].str));}
#line 2284 "parser.tab.c"
    break;

  case 151: /* EXPRESSION: CONSTANT  */
#line 398 "parser.y"
                           { int i = lookup((yyvsp[0].str)); check_type(i); pushVStack((yyvsp[0].str));}
#line 2290 "parser.tab.c"
    break;

  case 152: /* EXPRESSION: EXPRESSION PLUS PLUS  */
#line 400 "parser.y"
                                       {pushVStack("+"); pushVStack("1"); CodeGenOp();}
#line 2296 "parser.tab.c"
    break;

  case 153: /* EXPRESSION: EXPRESSION SUB SUB  */
#line 401 "parser.y"
                                       {pushVStack("-"); pushVStack("1"); CodeGenOp();}
#line 2302 "parser.tab.c"
    break;

  case 154: /* $@40: %empty  */
#line 402 "parser.y"
                                  {pushVStack("+");}
#line 2308 "parser.tab.c"
    break;

  case 155: /* EXPRESSION: EXPRESSION PLUS $@40 EXPRESSION  */
#line 402 "parser.y"
                                                                 {CodeGenOp();}
#line 2314 "parser.tab.c"
    break;

  case 156: /* $@41: %empty  */
#line 403 "parser.y"
                                  {pushVStack("-");}
#line 2320 "parser.tab.c"
    break;

  case 157: /* EXPRESSION: EXPRESSION SUB $@41 EXPRESSION  */
#line 403 "parser.y"
                                                                 {CodeGenOp();}
#line 2326 "parser.tab.c"
    break;

  case 158: /* $@42: %empty  */
#line 404 "parser.y"
                                  {pushVStack("*");}
#line 2332 "parser.tab.c"
    break;

  case 159: /* EXPRESSION: EXPRESSION MUL $@42 EXPRESSION  */
#line 404 "parser.y"
                                                                 {CodeGenOp();}
#line 2338 "parser.tab.c"
    break;

  case 160: /* $@43: %empty  */
#line 405 "parser.y"
                                  {pushVStack("/");}
#line 2344 "parser.tab.c"
    break;

  case 161: /* EXPRESSION: EXPRESSION DIV $@43 EXPRESSION  */
#line 405 "parser.y"
                                                                 {CodeGenOp();}
#line 2350 "parser.tab.c"
    break;

  case 162: /* $@44: %empty  */
#line 406 "parser.y"
                                  {pushVStack("^");}
#line 2356 "parser.tab.c"
    break;

  case 163: /* EXPRESSION: EXPRESSION POW $@44 EXPRESSION  */
#line 406 "parser.y"
                                                                 {CodeGenOp();}
#line 2362 "parser.tab.c"
    break;

  case 165: /* EXPRESSION: FUNC_CALL  */
#line 408 "parser.y"
                            {}
#line 2368 "parser.tab.c"
    break;

  case 167: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 410 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);}
#line 2374 "parser.tab.c"
    break;

  case 172: /* COMPARISONSTT: EXPRESSION GT EXPRESSION  */
#line 430 "parser.y"
                                                        {pushVStack(">"); CodeGenLogical();}
#line 2380 "parser.tab.c"
    break;

  case 173: /* COMPARISONSTT: EXPRESSION LT EXPRESSION  */
#line 431 "parser.y"
                                                        {pushVStack("<"); CodeGenLogical();}
#line 2386 "parser.tab.c"
    break;

  case 174: /* COMPARISONSTT: EXPRESSION LT EQ EXPRESSION  */
#line 432 "parser.y"
                                                        {pushVStack("<="); CodeGenLogical();}
#line 2392 "parser.tab.c"
    break;

  case 175: /* COMPARISONSTT: EXPRESSION GT EQ EXPRESSION  */
#line 433 "parser.y"
                                                        {pushVStack(">="); CodeGenLogical();}
#line 2398 "parser.tab.c"
    break;

  case 176: /* COMPARISONSTT: EXPRESSION EQUALITY EXPRESSION  */
#line 434 "parser.y"
                                                        {pushVStack("="); CodeGenLogical();}
#line 2404 "parser.tab.c"
    break;

  case 177: /* COMPARISONSTT: EXPRESSION NEG_EQUALITY EXPRESSION  */
#line 435 "parser.y"
                                                        {pushVStack("!="); CodeGenLogical();}
#line 2410 "parser.tab.c"
    break;

  case 178: /* COMPARISONSTT: EXPRESSION LOGIC_AND EXPRESSION  */
#line 436 "parser.y"
                                                        {pushVStack("and"); CodeGenLogical();}
#line 2416 "parser.tab.c"
    break;

  case 179: /* COMPARISONSTT: EXPRESSION LOGIC_OR EXPRESSION  */
#line 437 "parser.y"
                                                        {pushVStack("or"); CodeGenLogical();}
#line 2422 "parser.tab.c"
    break;

  case 182: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 443 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 2428 "parser.tab.c"
    break;

  case 183: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 444 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 2434 "parser.tab.c"
    break;

  case 184: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 445 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 2440 "parser.tab.c"
    break;

  case 185: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 446 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 2446 "parser.tab.c"
    break;

  case 186: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 447 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 2452 "parser.tab.c"
    break;

  case 187: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 448 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 2458 "parser.tab.c"
    break;

  case 188: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 449 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 2464 "parser.tab.c"
    break;

  case 189: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 450 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 2470 "parser.tab.c"
    break;

  case 190: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 451 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 2476 "parser.tab.c"
    break;

  case 191: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 452 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 2482 "parser.tab.c"
    break;

  case 192: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 453 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 2488 "parser.tab.c"
    break;

  case 193: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 454 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 2494 "parser.tab.c"
    break;

  case 194: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 455 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 2500 "parser.tab.c"
    break;

  case 195: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 456 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 2506 "parser.tab.c"
    break;

  case 196: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 457 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 2512 "parser.tab.c"
    break;

  case 197: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 458 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 2518 "parser.tab.c"
    break;

  case 198: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 459 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 2524 "parser.tab.c"
    break;


#line 2528 "parser.tab.c"

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

#line 478 "parser.y"




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

void CodeGenOp()
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

    if(ret != 0){
        printf("\nCreating Intermediate Code File ...\n");
    }
    yyin = fopen(argv[1], "r");
    yyparse();
    st_print();
    unused_print();
    return 0;
}
