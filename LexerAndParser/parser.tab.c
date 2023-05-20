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
    char* VirtualStack [1000];
    int VirtualSP = -1;
    int tempNumber = 0;
    char* popVStack();
    void pushVStack(char* s);
    void CodeGenAss();
    void CodeGenOp();
//================================================================


#line 156 "parser.tab.c"

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
  YYSYMBOL_SWITCH_STT = 54,                /* SWITCH_STT  */
  YYSYMBOL_CASES = 55,                     /* CASES  */
  YYSYMBOL_ERRONOUS_CASES = 56,            /* ERRONOUS_CASES  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 59,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_60_8 = 60,                      /* $@8  */
  YYSYMBOL_61_9 = 61,                      /* $@9  */
  YYSYMBOL_62_10 = 62,                     /* $@10  */
  YYSYMBOL_63_11 = 63,                     /* $@11  */
  YYSYMBOL_FUNC_DECLARATION_STT = 64,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_65_12 = 65,                     /* $@12  */
  YYSYMBOL_66_13 = 66,                     /* $@13  */
  YYSYMBOL_67_14 = 67,                     /* $@14  */
  YYSYMBOL_68_15 = 68,                     /* $@15  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 69, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_70_16 = 70,                     /* $@16  */
  YYSYMBOL_71_17 = 71,                     /* $@17  */
  YYSYMBOL_72_18 = 72,                     /* $@18  */
  YYSYMBOL_73_19 = 73,                     /* $@19  */
  YYSYMBOL_74_20 = 74,                     /* $@20  */
  YYSYMBOL_ARGS = 75,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 76,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 77,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 78,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_HELPER = 79,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 80,                 /* ENUM_ARGS  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 81,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 82, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_IF_STT = 83,                    /* IF_STT  */
  YYSYMBOL_84_21 = 84,                     /* $@21  */
  YYSYMBOL_85_22 = 85,                     /* $@22  */
  YYSYMBOL_WHILE_STT = 86,                 /* WHILE_STT  */
  YYSYMBOL_ERRONOUS_WHILE_STT = 87,        /* ERRONOUS_WHILE_STT  */
  YYSYMBOL_88_23 = 88,                     /* $@23  */
  YYSYMBOL_89_24 = 89,                     /* $@24  */
  YYSYMBOL_DO_WHILE_STT = 90,              /* DO_WHILE_STT  */
  YYSYMBOL_ERRONOUS_DO_WHILE = 91,         /* ERRONOUS_DO_WHILE  */
  YYSYMBOL_92_25 = 92,                     /* $@25  */
  YYSYMBOL_93_26 = 93,                     /* $@26  */
  YYSYMBOL_94_27 = 94,                     /* $@27  */
  YYSYMBOL_95_28 = 95,                     /* $@28  */
  YYSYMBOL_FOR_STT = 96,                   /* FOR_STT  */
  YYSYMBOL_97_29 = 97,                     /* $@29  */
  YYSYMBOL_98_30 = 98,                     /* $@30  */
  YYSYMBOL_ERRONOUS_FOR_LOOP = 99,         /* ERRONOUS_FOR_LOOP  */
  YYSYMBOL_100_31 = 100,                   /* $@31  */
  YYSYMBOL_101_32 = 101,                   /* $@32  */
  YYSYMBOL_assignmentSTT = 102,            /* assignmentSTT  */
  YYSYMBOL_103_33 = 103,                   /* $@33  */
  YYSYMBOL_104_34 = 104,                   /* $@34  */
  YYSYMBOL_105_35 = 105,                   /* $@35  */
  YYSYMBOL_106_36 = 106,                   /* $@36  */
  YYSYMBOL_107_37 = 107,                   /* $@37  */
  YYSYMBOL_BLOCK = 108,                    /* BLOCK  */
  YYSYMBOL_109_38 = 109,                   /* $@38  */
  YYSYMBOL_110_39 = 110,                   /* $@39  */
  YYSYMBOL_FUNC_CALL = 111,                /* FUNC_CALL  */
  YYSYMBOL_112_40 = 112,                   /* $@40  */
  YYSYMBOL_113_41 = 113,                   /* $@41  */
  YYSYMBOL_114_42 = 114,                   /* $@42  */
  YYSYMBOL_USED_ARGS = 115,                /* USED_ARGS  */
  YYSYMBOL_116_43 = 116,                   /* $@43  */
  YYSYMBOL_EXPRESSION = 117,               /* EXPRESSION  */
  YYSYMBOL_118_44 = 118,                   /* $@44  */
  YYSYMBOL_ERRONOUS_EXPRESSION = 119,      /* ERRONOUS_EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 120,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 121,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 122                  /* RES_WORD  */
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
#define YYLAST   1295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  380

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
       0,   134,   134,   135,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   160,   161,
     162,   163,   167,   167,   168,   168,   169,   170,   171,   176,
     177,   178,   179,   180,   180,   181,   181,   182,   182,   184,
     192,   193,   198,   199,   200,   204,   204,   205,   205,   209,
     209,   210,   210,   211,   211,   212,   212,   227,   228,   228,
     229,   229,   230,   230,   231,   231,   235,   235,   236,   237,
     237,   238,   239,   239,   240,   240,   241,   241,   245,   246,
     247,   250,   253,   263,   264,   266,   266,   268,   269,   272,
     273,   276,   277,   279,   286,   287,   288,   289,   289,   290,
     290,   291,   298,   299,   303,   303,   304,   304,   305,   311,
     312,   315,   315,   316,   316,   317,   317,   318,   318,   319,
     326,   326,   326,   327,   331,   331,   332,   332,   338,   338,
     338,   338,   339,   339,   340,   340,   345,   345,   345,   353,
     353,   353,   353,   354,   358,   358,   359,   360,   361,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   392,   393,   394,
     395,   396,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440
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
  "$@1", "$@2", "DECLARATION_TAIL", "$@3", "$@4", "$@5", "SWITCH_STT",
  "CASES", "ERRONOUS_CASES", "$@6", "$@7", "ERRONOUS_SWITCH_STT", "$@8",
  "$@9", "$@10", "$@11", "FUNC_DECLARATION_STT", "$@12", "$@13", "$@14",
  "$@15", "ERRONOUS_FUNC_DECLARATION_STT", "$@16", "$@17", "$@18", "$@19",
  "$@20", "ARGS", "ERRONOUS_ARGS", "ARG_DECL", "ENUM_DECLARATION_STT",
  "ENUM_HELPER", "ENUM_ARGS", "ENUM_DEFINED_ARGS",
  "ERRONOUS_ENUM_DECLARATION_STT", "IF_STT", "$@21", "$@22", "WHILE_STT",
  "ERRONOUS_WHILE_STT", "$@23", "$@24", "DO_WHILE_STT",
  "ERRONOUS_DO_WHILE", "$@25", "$@26", "$@27", "$@28", "FOR_STT", "$@29",
  "$@30", "ERRONOUS_FOR_LOOP", "$@31", "$@32", "assignmentSTT", "$@33",
  "$@34", "$@35", "$@36", "$@37", "BLOCK", "$@38", "$@39", "FUNC_CALL",
  "$@40", "$@41", "$@42", "USED_ARGS", "$@43", "EXPRESSION", "$@44",
  "ERRONOUS_EXPRESSION", "COMPARISONSTT", "ERRONOUS_COMPARISONSTT",
  "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-254)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-155)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -254,   228,  -254,   860,  -254,  -254,  -254,  -254,   -26,    99,
      13,   514,  -254,  -254,  -254,    27,   113,   139,   539,  -254,
     145,  -254,  -254,   555,  -254,   132,  -254,  -254,  -254,  -254,
     -23,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  1117,  -254,  -254,  -254,   555,   167,   254,
    -254,   555,   555,   555,     8,   555,   555,   555,   555,   555,
      15,  -254,  -254,   -11,  1217,   352,  -254,   767,   431,    30,
     790,   813,    50,    24,    92,    41,  -254,     4,   156,   203,
     106,   135,   153,   166,   125,  -254,   941,  -254,   101,  -254,
     555,   457,   473,  -254,   175,    46,   555,   555,   580,   596,
     621,   637,   253,   555,   177,   555,   170,   190,   177,   233,
    -254,   203,   203,   203,  1257,  1257,  -254,  -254,    33,    14,
     -23,    67,   -23,   431,   431,   431,  -254,    75,   -23,   187,
     161,  -254,    29,   171,    -9,   155,   173,  -254,  -254,   174,
     178,    94,  -254,  -254,   555,   202,  -254,   393,  -254,    11,
     207,   276,    11,    14,   253,   156,   662,   177,   210,   678,
     170,  -254,   555,  -254,   177,   233,   203,   278,   203,   278,
     203,  1268,  1257,  1268,  1257,   177,   177,   186,  -254,    14,
     196,    61,  -254,   199,   204,  -254,   217,   236,  -254,   431,
     431,   431,   -23,   235,  -254,  -254,   237,   263,   243,  -254,
     555,   555,   239,   555,   250,   256,   261,  -254,   267,   260,
     277,  -254,    72,   555,  1137,  -254,   498,  -254,   301,   703,
    -254,  -254,  -254,   280,  -254,   107,  -254,   289,   156,   177,
     210,   177,   190,    14,   -23,  -254,  -254,  -254,  -254,    14,
    -254,  -254,   147,   290,   431,   431,  -254,  -254,   555,   291,
     555,   555,  1095,   963,  -254,   727,   275,  -254,  -254,  -254,
      72,   282,    72,    72,   555,   555,   295,  -254,  1237,  -254,
     747,  -254,   985,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  1157,  -254,  -254,  -254,  -254,  -254,  1177,  -254,
    1197,   887,    14,   -23,  -254,  -254,  -254,  -254,   300,  -254,
     -23,  -254,   302,  -254,  -254,   304,   305,  1007,   555,  1029,
    1051,  -254,  -254,   306,   307,    72,   308,   309,  1237,   836,
    -254,   331,   498,   310,   311,  -254,  -254,  -254,   326,   329,
     923,   334,  -254,   346,   -23,  -254,  -254,  -254,   -23,  -254,
    -254,  -254,  1073,  -254,  -254,   370,  -254,  -254,   349,  -254,
    -254,   348,   150,  -254,  -254,  -254,   498,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,   -23,   -23,  -254,  -254,   -23,
    -254,    72,  -254,  -254,  -254,    72,    72,  -254,  -254,  -254
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    18,    19,    20,    21,     0,     0,
       0,     0,   152,   153,   154,     0,     0,     0,     0,   150,
       0,   151,   136,     0,     2,     0,     4,    12,    41,     5,
       0,    13,    84,     8,     9,   103,    11,   110,    10,   123,
       6,    14,   164,     0,   166,   163,   181,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    69,     0,     0,    99,    97,     0,   120,
       0,   106,   111,     0,     0,     0,    49,     0,   190,   180,
       0,     0,     0,     0,     0,     3,     0,    24,    66,    57,
       0,     0,     0,     7,   157,     0,     0,     0,     0,     0,
       0,     0,   170,     0,   182,     0,   184,   167,   168,   169,
      27,   171,   186,   188,   191,   193,    26,    74,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,     0,
       0,   115,     0,     0,    88,     0,     0,    85,    86,     0,
      51,     0,   143,   129,     0,     0,   140,     0,   165,     0,
      72,     0,     0,     0,   161,   183,     0,   172,   185,     0,
     173,   155,     0,   156,   159,   160,   162,   187,   176,   189,
     177,   192,   178,   194,   179,   197,   195,     0,    64,     0,
       0,     0,    80,    79,     0,   100,     0,    94,    98,     0,
       0,     0,     0,     0,   102,   107,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,    92,     0,     0,
       0,    55,     0,     0,     0,   135,     0,   137,     0,     0,
      32,    25,    28,     0,    62,     0,    23,     0,   198,   175,
     196,   174,   158,     0,     0,    81,    82,    71,    60,     0,
      70,   101,     0,     0,     0,     0,   105,   108,     0,     0,
       0,     0,     0,     0,    91,    90,    88,    87,    93,    83,
       0,     0,     0,     0,     0,     0,     0,    43,   130,   133,
       0,   141,   144,   138,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,    39,
       0,    37,     0,     0,    76,    68,    58,    67,     0,    65,
       0,    78,     0,    96,   124,     0,     0,     0,     0,     0,
       0,   119,   109,     0,     0,     0,     0,     0,    45,     0,
      40,     0,     0,     0,     0,    30,    31,    29,     0,     0,
       0,     0,    63,     0,     0,    75,    61,    95,     0,   126,
     121,   112,     0,   116,   114,     0,    89,    50,     0,    54,
      56,     0,     0,   131,   146,   142,     0,    34,    36,   207,
      38,    73,    77,    59,   125,     0,     0,   118,    52,     0,
      47,     0,   145,   127,   122,     0,     0,    42,    46,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -254,   320,   -65,   -97,  -254,  -254,  -254,   255,  -254,  -254,
    -254,  -254,  -253,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -118,  -254,  -254,  -254,    -6,   191,    93,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,   -15,  -254,  -254,  -254,  -254,
    -254,  -254,  -252,  -254,    -7,  -254,  -254,  -254,  -254,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    24,    25,    26,   152,   149,   221,   328,   329,
     330,    27,   266,   267,   351,   376,    28,   139,   209,   210,
     263,    29,   334,   300,   293,   234,    30,   153,   119,   223,
     177,   333,   181,   182,   183,    31,   136,   137,   138,    32,
      33,   122,   120,    34,    35,   192,   128,    36,    37,   129,
     251,   198,   130,    38,   125,   366,    39,   338,   365,    40,
      81,   213,   321,    82,    83,    41,    85,   273,    42,    84,
     216,   323,   271,   324,    43,   162,    44,    45,    46,   289
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,   184,    67,   123,    71,   140,   203,   314,    63,   316,
     317,    79,   218,    22,    68,    89,    86,     4,     5,     6,
       7,   180,   180,   117,   110,   131,   219,   220,    72,   118,
     199,   116,   204,   225,   132,   227,     4,     5,     6,     7,
     102,   104,   106,   141,   107,   108,   109,    64,   111,   112,
     113,   114,   115,    69,   180,   179,   180,    12,   189,   190,
     191,   235,   348,    22,   163,   200,    13,    14,   186,   201,
     354,   178,   124,   264,   179,   134,   193,   135,    18,    19,
      65,    21,   180,   154,   157,   160,    23,  -117,   164,   165,
     166,   168,   170,   172,   174,   211,   175,   237,   176,   238,
      64,   265,   -22,    22,   372,   185,   187,   188,   294,   -44,
      12,    22,   194,   195,    74,   298,   -22,   -22,   377,    13,
      14,   301,   378,   379,   243,   244,   245,   202,   133,   206,
     212,    18,    19,    65,    21,   150,   180,   214,    66,    23,
      76,   151,   180,   295,   142,   296,    80,    75,   302,   229,
     143,   370,   231,    87,   144,   232,   205,  -149,  -149,  -149,
    -128,  -149,  -149,  -149,  -149,   146,    88,  -149,    64,    48,
      49,  -149,  -149,    77,   331,  -149,  -149,   246,    12,   305,
     306,   145,   103,    22,    92,  -139,    22,    13,    14,   134,
      91,    92,   161,   252,   253,   180,   255,   196,   197,    18,
      19,    65,    21,    91,    92,   134,   268,    23,    95,   272,
     207,   288,   291,   208,   -53,    90,    91,    92,   215,   299,
      94,    95,    96,   222,    49,    97,   233,   303,     2,     3,
     236,     4,     5,     6,     7,     8,     9,    10,    11,    12,
     239,   307,   240,   309,   310,    90,    91,    92,    13,    14,
      94,    95,    15,    16,   241,    64,    17,   318,   319,   242,
      18,    19,    20,    21,    22,    12,    91,    92,    23,   105,
      94,    95,   247,   249,    13,    14,   254,   248,   332,     4,
       5,     6,     7,   250,   256,   336,    18,    19,    65,    21,
      47,    48,    49,   258,    23,    51,    52,    53,   259,   261,
      55,   342,    64,   260,   274,   275,   276,   277,   278,   279,
     280,   281,    12,   262,   224,   272,   204,   179,   315,   363,
     292,    13,   282,   364,   283,   284,   285,   297,   304,   286,
     287,   308,   320,    18,    19,    65,    21,   371,   335,   337,
     345,    23,   339,   340,   347,   349,   350,   353,   355,   272,
     373,   374,   356,    80,   375,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,   357,  -149,  -149,  -149,   358,  -149,  -149,
    -149,  -149,   361,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,   362,   203,   368,   369,  -149,  -149,
    -149,  -149,  -139,  -149,     3,   257,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   147,   346,   226,   360,     0,
       0,     0,     0,    13,    14,     0,     0,    15,    16,     0,
       0,    17,     0,     0,     0,    18,    19,    20,    21,    22,
     217,     0,     3,    23,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,    15,    16,     0,   155,    17,
       0,     0,     0,    18,    19,    20,    21,    22,    12,     0,
       0,    23,   156,     0,   158,     0,     0,    13,    14,     0,
       0,     0,     0,     0,    12,     0,     0,     0,   159,    18,
      19,    65,    21,    13,    14,     0,     0,    23,     0,   270,
       0,     0,     0,     0,     0,    18,    19,    65,    21,    12,
       0,     0,     0,    23,     0,    70,     0,     0,    13,    14,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
      18,    19,    65,    21,    13,    14,  -148,     0,    23,     0,
      78,     0,     0,     0,     0,     0,    18,    19,    65,    21,
      12,     0,     0,     0,    23,     0,    64,     0,     0,    13,
      14,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,    18,    19,    65,    21,    13,    14,     0,     0,    23,
       0,   167,     0,     0,     0,     0,     0,    18,    19,    65,
      21,    12,     0,     0,     0,    23,     0,   169,     0,     0,
      13,    14,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,    18,    19,    65,    21,    13,    14,     0,     0,
      23,     0,   171,     0,     0,     0,     0,     0,    18,    19,
      65,    21,    12,     0,     0,     0,    23,     0,   173,     0,
       0,    13,    14,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,    18,    19,    65,    21,    13,    14,     0,
       0,    23,     0,   228,     0,     0,     0,     0,     0,    18,
      19,    65,    21,    12,     0,     0,     0,    23,     0,   230,
       0,     0,    13,    14,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,    18,    19,    65,    21,    13,    14,
       0,     0,    23,     0,   290,     0,     0,     0,     0,     0,
      18,    19,    65,    21,    12,     0,     0,     0,    23,     0,
       0,     0,     0,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    65,    21,    90,
      91,    92,     0,    23,    94,    95,    96,     0,     0,    97,
       0,     0,     0,    98,    99,     0,     0,   100,   101,    47,
      48,    49,     0,     0,    51,    52,    53,     0,   313,    55,
       0,     0,     0,    56,    57,     0,     0,    58,    59,    90,
      91,    92,     0,     0,    94,    95,    96,     0,   322,    97,
       0,     0,     0,    98,    99,     0,     0,   100,   101,     0,
       0,     0,    47,    48,    49,     0,   121,    51,    52,    53,
       0,     0,    55,     0,     0,     0,    56,    57,     0,     0,
      58,    59,     0,     0,     0,    90,    91,    92,     0,   126,
      94,    95,    96,     0,     0,    97,     0,     0,     0,    98,
      99,     0,     0,   100,   101,     0,     0,     0,    90,    91,
      92,     0,   127,    94,    95,    96,     0,     0,    97,     0,
       0,     0,    98,    99,     0,     0,   100,   101,     0,     0,
       0,     0,    47,    48,    49,   352,    50,    51,    52,    53,
       0,    54,    55,     0,     0,     0,    56,    57,     0,     0,
      58,    59,     0,     0,    60,     0,     0,    61,    62,    90,
      91,    92,     0,   327,    94,    95,    96,     0,     0,    97,
       0,     0,     0,    98,    99,     0,     0,   100,   101,     0,
       0,     0,     0,     0,   -33,   -35,   274,   275,   276,   277,
     278,   279,   280,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,     0,   283,   284,   285,     0,
       0,   286,   287,    90,    91,    92,     0,     0,    94,    95,
      96,     0,     0,    97,     0,     0,     0,    98,    99,     0,
       0,   100,   101,     0,     0,    90,    91,    92,     0,   148,
      94,    95,    96,     0,     0,    97,     0,     0,     0,    98,
      99,     0,     0,   100,   101,     0,     0,    90,    91,    92,
       0,   312,    94,    95,    96,     0,     0,    97,     0,     0,
       0,    98,    99,     0,     0,   100,   101,     0,     0,    90,
      91,    92,     0,  -147,    94,    95,    96,     0,     0,    97,
       0,     0,     0,    98,    99,     0,     0,   100,   101,     0,
       0,    90,    91,    92,     0,   341,    94,    95,    96,     0,
       0,    97,     0,     0,     0,    98,    99,     0,     0,   100,
     101,     0,     0,    90,    91,    92,     0,   343,    94,    95,
      96,     0,     0,    97,     0,     0,     0,    98,    99,     0,
       0,   100,   101,     0,     0,    90,    91,    92,     0,   344,
      94,    95,    96,     0,     0,    97,     0,     0,     0,    98,
      99,     0,     0,   100,   101,     0,     0,    90,    91,    92,
       0,   367,    94,    95,    96,     0,     0,    97,     0,     0,
       0,    98,    99,     0,     0,   100,   101,     0,     0,    90,
      91,    92,   311,    93,    94,    95,    96,     0,     0,    97,
       0,     0,     0,    98,    99,     0,     0,   100,   101,    90,
      91,    92,     0,   269,    94,    95,    96,     0,     0,    97,
       0,     0,     0,    98,    99,     0,     0,   100,   101,  -154,
    -154,  -154,     0,  -154,  -154,  -154,  -154,     0,     0,  -154,
       0,     0,     0,  -154,  -154,     0,     0,  -154,  -154,    90,
      91,    92,     0,   325,    94,    95,    96,     0,     0,    97,
       0,     0,     0,    98,    99,     0,     0,   100,   101,    47,
      48,    49,     0,   326,    51,    52,    53,     0,     0,    55,
       0,     0,     0,    56,    57,     0,     0,    58,    59,    47,
      48,    49,     0,     0,    51,    52,    53,     0,     0,    55,
       0,     0,     0,    56,    57,     0,     0,    58,    59,    90,
      91,    92,     0,     0,    94,    95,    96,     0,     0,    97,
       0,     0,     0,    98,    99,     0,     0,   100,   101,    90,
      91,    92,     0,     0,    94,    95,    96,     0,     0,    97,
      47,    48,    49,    98,    99,    51,    52,    53,     0,     0,
      55,     0,     0,     0,    56,    57
};

static const yytype_int16 yycheck[] =
{
      15,   119,     9,    68,    11,     1,    15,   260,    34,   262,
     263,    18,     1,    36,     1,    30,    23,     3,     4,     5,
       6,   118,   119,    34,    16,     1,    15,    16,     1,    40,
       1,    16,    41,   151,    10,   153,     3,     4,     5,     6,
      47,    48,    49,    39,    51,    52,    53,     1,    55,    56,
      57,    58,    59,    40,   151,    41,   153,    11,   123,   124,
     125,   179,   315,    36,    18,    36,    20,    21,     1,    40,
     322,    38,    42,     1,    41,    34,     1,    36,    32,    33,
      34,    35,   179,    90,    91,    92,    40,    37,    95,    96,
      97,    98,    99,   100,   101,     1,   103,    36,   105,    38,
       1,    29,     1,    36,   356,   120,   121,   122,     1,    37,
      11,    36,   127,   128,     1,   233,    15,    16,   371,    20,
      21,   239,   375,   376,   189,   190,   191,   133,    36,   135,
      36,    32,    33,    34,    35,    34,   233,   144,    39,    40,
       1,    40,   239,    36,    38,    38,     1,    34,     1,   156,
      15,     1,   159,    21,     1,   162,     1,    12,    13,    14,
      15,    16,    17,    18,    19,    40,    34,    22,     1,    13,
      14,    26,    27,    34,   292,    30,    31,   192,    11,   244,
     245,    15,    15,    36,    14,    40,    36,    20,    21,    34,
      13,    14,    17,   200,   201,   292,   203,    10,    37,    32,
      33,    34,    35,    13,    14,    34,   213,    40,    18,   216,
      37,   218,   219,    39,    36,    12,    13,    14,    16,   234,
      17,    18,    19,    16,    14,    22,    40,   242,     0,     1,
      34,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      41,   248,    38,   250,   251,    12,    13,    14,    20,    21,
      17,    18,    24,    25,    37,     1,    28,   264,   265,    23,
      32,    33,    34,    35,    36,    11,    13,    14,    40,    15,
      17,    18,    37,    10,    20,    21,    37,    40,   293,     3,
       4,     5,     6,    40,    34,   300,    32,    33,    34,    35,
      12,    13,    14,    37,    40,    17,    18,    19,    37,    39,
      22,   308,     1,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    36,    38,   322,    41,    41,    36,   334,
      40,    20,    21,   338,    23,    24,    25,    38,    38,    28,
      29,    40,    37,    32,    33,    34,    35,   352,    38,    37,
      34,    40,    38,    38,    37,    37,    37,    16,    38,   356,
     365,   366,    41,     1,   369,     3,     4,     5,     6,     7,
       8,     9,    10,    37,    12,    13,    14,    38,    16,    17,
      18,    19,    38,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    38,    15,    37,    39,    36,    37,
      38,    39,    40,    41,     1,   204,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    85,   313,   152,   330,    -1,
      -1,    -1,    -1,    20,    21,    -1,    -1,    24,    25,    -1,
      -1,    28,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    -1,     1,    40,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    -1,    -1,    24,    25,    -1,     1,    28,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    11,    -1,
      -1,    40,    15,    -1,     1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    15,    32,
      33,    34,    35,    20,    21,    -1,    -1,    40,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    11,
      -1,    -1,    -1,    40,    -1,     1,    -1,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    20,    21,    38,    -1,    40,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      11,    -1,    -1,    -1,    40,    -1,     1,    -1,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    20,    21,    -1,    -1,    40,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    11,    -1,    -1,    -1,    40,    -1,     1,    -1,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    20,    21,    -1,    -1,
      40,    -1,     1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    11,    -1,    -1,    -1,    40,    -1,     1,    -1,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    20,    21,    -1,
      -1,    40,    -1,     1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    11,    -1,    -1,    -1,    40,    -1,     1,
      -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    20,    21,
      -1,    -1,    40,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    11,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    12,
      13,    14,    -1,    40,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    12,
      13,    14,    -1,    -1,    17,    18,    19,    -1,    41,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    12,
      13,    14,    -1,    -1,    17,    18,    19,    -1,    41,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,
      -1,    -1,    12,    13,    14,    -1,    39,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    -1,    -1,    -1,    12,    13,    14,    -1,    39,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    -1,    -1,    -1,    12,    13,
      14,    -1,    39,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    12,    13,    14,    39,    16,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    -1,    -1,    34,    -1,    -1,    37,    38,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    23,    24,    25,    -1,
      -1,    28,    29,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    -1,    -1,    12,    13,    14,    -1,    38,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    -1,    -1,    12,    13,    14,
      -1,    38,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,    12,
      13,    14,    -1,    38,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,
      -1,    12,    13,    14,    -1,    38,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,
      31,    -1,    -1,    12,    13,    14,    -1,    38,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    -1,    -1,    12,    13,    14,    -1,    38,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    -1,    -1,    12,    13,    14,
      -1,    38,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,    12,
      13,    14,    37,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    12,
      13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    12,
      13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    12,
      13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,    22,
      12,    13,    14,    26,    27,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    20,    21,    24,    25,    28,    32,    33,
      34,    35,    36,    40,    45,    46,    47,    54,    59,    64,
      69,    78,    82,    83,    86,    87,    90,    91,    96,    99,
     102,   108,   111,   117,   119,   120,   121,    12,    13,    14,
      16,    17,    18,    19,    21,    22,    26,    27,    30,    31,
      34,    37,    38,    34,     1,    34,    39,   117,     1,    40,
       1,   117,     1,   108,     1,    34,     1,    34,     1,   117,
       1,   103,   106,   107,   112,   109,   117,    21,    34,   108,
      12,    13,    14,    16,    17,    18,    19,    22,    26,    27,
      30,    31,   117,    15,   117,    15,   117,   117,   117,   117,
      16,   117,   117,   117,   117,   117,    16,    34,    40,    71,
      85,    39,    84,    45,    42,    97,    39,    39,    89,    92,
      95,     1,    10,    36,    34,    36,    79,    80,    81,    60,
       1,    39,    38,    15,     1,    15,    40,    44,    38,    49,
      34,    40,    48,    70,   117,     1,    15,   117,     1,    15,
     117,    17,   118,    18,   117,   117,   117,     1,   117,     1,
     117,     1,   117,     1,   117,   117,   117,    73,    38,    41,
      46,    75,    76,    77,    75,   108,     1,   108,   108,    45,
      45,    45,    88,     1,   108,   108,    10,    37,    94,     1,
      36,    40,    79,    15,    41,     1,    79,    37,    39,    61,
      62,     1,    36,   104,   117,    16,   113,    37,     1,    15,
      16,    50,    16,    72,    38,    75,    50,    75,     1,   117,
       1,   117,   117,    40,    68,    75,    34,    36,    38,    41,
      38,    37,    23,    45,    45,    45,   108,    37,    40,    10,
      40,    93,   117,   117,    37,   117,    34,    80,    37,    37,
      36,    39,    36,    63,     1,    29,    55,    56,   117,    16,
       1,   115,   117,   110,     3,     4,     5,     6,     7,     8,
       9,    10,    21,    23,    24,    25,    28,    29,   117,   122,
       1,   117,    40,    67,     1,    36,    38,    38,    75,   108,
      66,    75,     1,   108,    38,    45,    45,   117,    40,   117,
     117,    37,    38,    41,    55,    36,    55,    55,   117,   117,
      37,   105,    41,   114,   116,    16,    16,    16,    51,    52,
      53,    75,   108,    74,    65,    38,   108,    37,   100,    38,
      38,    38,   117,    38,    38,    34,    81,    37,    55,    37,
      37,    57,    39,    16,   115,    38,    41,    37,    38,    21,
     122,    38,    38,   108,   108,   101,    98,    38,    37,    39,
       1,   108,   115,   108,   108,   108,    58,    55,    55,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
      46,    46,    48,    47,    49,    47,    47,    47,    47,    50,
      50,    50,    50,    51,    50,    52,    50,    53,    50,    50,
      54,    54,    55,    55,    55,    57,    56,    58,    56,    60,
      59,    61,    59,    62,    59,    63,    59,    64,    65,    64,
      66,    64,    67,    64,    68,    64,    70,    69,    69,    71,
      69,    69,    72,    69,    73,    69,    74,    69,    75,    75,
      75,    76,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    82,    83,    83,    83,    84,    83,    85,
      83,    83,    86,    86,    88,    87,    89,    87,    87,    90,
      90,    92,    91,    93,    91,    94,    91,    95,    91,    91,
      97,    98,    96,    96,   100,    99,   101,    99,   103,   104,
     105,   102,   106,   102,   107,   102,   109,   110,   108,   112,
     113,   114,   111,   111,   116,   115,   115,   115,   115,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   119,   119,   119,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     0,     4,     0,     4,     3,     3,     4,     3,
       3,     3,     1,     0,     4,     0,     4,     0,     4,     2,
       6,     1,     5,     1,     0,     0,     6,     0,     6,     0,
       7,     0,     8,     0,     7,     0,     7,     2,     0,     7,
       0,     7,     0,     6,     0,     6,     0,     5,     5,     0,
       5,     5,     0,     7,     0,     7,     0,     7,     3,     1,
       1,     2,     2,     5,     1,     1,     1,     3,     1,     5,
       3,     5,     4,     5,     4,     7,     6,     0,     4,     0,
       4,     5,     4,     1,     0,     5,     0,     4,     5,     6,
       1,     0,     7,     0,     7,     0,     7,     0,     8,     6,
       0,     0,     9,     1,     0,     8,     0,     9,     0,     0,
       0,     7,     0,     5,     0,     4,     0,     0,     5,     0,
       0,     0,     7,     3,     0,     4,     3,     1,     0,     1,
       1,     1,     1,     1,     1,     3,     3,     0,     4,     3,
       3,     3,     3,     1,     1,     3,     1,     3,     3,     3,
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
#line 134 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1720 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 140 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1726 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 143 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1732 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 144 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1738 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 145 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1744 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 146 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1750 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 147 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1756 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 148 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1762 "parser.tab.c"
    break;

  case 15: /* STATEMENT: error SEMICOLON  */
#line 150 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1768 "parser.tab.c"
    break;

  case 16: /* STATEMENT: error '}'  */
#line 151 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1774 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error ')'  */
#line 152 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1780 "parser.tab.c"
    break;

  case 18: /* TYPE: INT  */
#line 160 "parser.y"
                    { (yyval.str) = "int"; }
#line 1786 "parser.tab.c"
    break;

  case 19: /* TYPE: FLOAT  */
#line 161 "parser.y"
                        { (yyval.str) = "float"; }
#line 1792 "parser.tab.c"
    break;

  case 20: /* TYPE: BOOL  */
#line 162 "parser.y"
                        { (yyval.str) = "bool"; }
#line 1798 "parser.tab.c"
    break;

  case 21: /* TYPE: STRING  */
#line 163 "parser.y"
                         { (yyval.str) = "string"; }
#line 1804 "parser.tab.c"
    break;

  case 22: /* $@1: %empty  */
#line 167 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0); assign_index= st_index-1; }
#line 1810 "parser.tab.c"
    break;

  case 23: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 167 "parser.y"
                                                                                                                      {printf("#[Parsed_Declaration]# "); }
#line 1816 "parser.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 168 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0);  assign_index= st_index-1;}
#line 1822 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 168 "parser.y"
                                                                                                                       {printf("#[Parsed_CONST_Declaration]# "); }
#line 1828 "parser.tab.c"
    break;

  case 26: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 169 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1834 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 170 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1840 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 171 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);}
#line 1846 "parser.tab.c"
    break;

  case 30: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 177 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1852 "parser.tab.c"
    break;

  case 31: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 178 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1858 "parser.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 180 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1864 "parser.tab.c"
    break;

  case 35: /* $@4: %empty  */
#line 181 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1870 "parser.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 182 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1876 "parser.tab.c"
    break;

  case 39: /* DECLARATION_TAIL: error RES_WORD  */
#line 184 "parser.y"
                                                                                           {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);}
#line 1882 "parser.tab.c"
    break;

  case 45: /* $@6: %empty  */
#line 204 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);}
#line 1888 "parser.tab.c"
    break;

  case 47: /* $@7: %empty  */
#line 205 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);}
#line 1894 "parser.tab.c"
    break;

  case 49: /* $@8: %empty  */
#line 209 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1900 "parser.tab.c"
    break;

  case 51: /* $@9: %empty  */
#line 210 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }
#line 1906 "parser.tab.c"
    break;

  case 53: /* $@10: %empty  */
#line 211 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1912 "parser.tab.c"
    break;

  case 55: /* $@11: %empty  */
#line 212 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1918 "parser.tab.c"
    break;

  case 58: /* $@12: %empty  */
#line 228 "parser.y"
                                                 {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1924 "parser.tab.c"
    break;

  case 60: /* $@13: %empty  */
#line 229 "parser.y"
                                                 {st_insert("void", (yyvsp[-3].str),"func",0);}
#line 1930 "parser.tab.c"
    break;

  case 62: /* $@14: %empty  */
#line 230 "parser.y"
                                                 {st_insert((yyvsp[-3].str), (yyvsp[-2].str),"func",0);}
#line 1936 "parser.tab.c"
    break;

  case 64: /* $@15: %empty  */
#line 231 "parser.y"
                                                 {st_insert("void", (yyvsp[-2].str),"func",0);}
#line 1942 "parser.tab.c"
    break;

  case 66: /* $@16: %empty  */
#line 235 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1948 "parser.tab.c"
    break;

  case 67: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@16 ARGS ')'  */
#line 235 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1954 "parser.tab.c"
    break;

  case 68: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS '{'  */
#line 236 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1960 "parser.tab.c"
    break;

  case 69: /* $@17: %empty  */
#line 237 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1966 "parser.tab.c"
    break;

  case 70: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER $@17 ARGS ')'  */
#line 237 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1972 "parser.tab.c"
    break;

  case 71: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER '(' ARGS '{'  */
#line 238 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1978 "parser.tab.c"
    break;

  case 72: /* $@18: %empty  */
#line 239 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1984 "parser.tab.c"
    break;

  case 73: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER $@18 '(' ARGS ')'  */
#line 239 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1990 "parser.tab.c"
    break;

  case 74: /* $@19: %empty  */
#line 240 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1996 "parser.tab.c"
    break;

  case 75: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER IDENTIFIER $@19 '(' ARGS ')'  */
#line 240 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 2002 "parser.tab.c"
    break;

  case 76: /* $@20: %empty  */
#line 241 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected token '%s' in argument list of function declaration at line %d\n\n", yylval, yylineno);}
#line 2008 "parser.tab.c"
    break;

  case 77: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS error $@20 ')'  */
#line 241 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 2014 "parser.tab.c"
    break;

  case 81: /* ERRONOUS_ARGS: ',' ARGS  */
#line 250 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
#line 2020 "parser.tab.c"
    break;

  case 82: /* ARG_DECL: TYPE IDENTIFIER  */
#line 253 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1);}
#line 2026 "parser.tab.c"
    break;

  case 83: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_HELPER '}'  */
#line 263 "parser.y"
                                                              { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 2032 "parser.tab.c"
    break;

  case 91: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 276 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);}
#line 2038 "parser.tab.c"
    break;

  case 92: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 277 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);}
#line 2044 "parser.tab.c"
    break;

  case 93: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 279 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2050 "parser.tab.c"
    break;

  case 95: /* IF_STT: IF EXPRESSION ':' BLOCK ELSE error '}'  */
#line 287 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);}
#line 2056 "parser.tab.c"
    break;

  case 97: /* $@21: %empty  */
#line 289 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 2062 "parser.tab.c"
    break;

  case 99: /* $@22: %empty  */
#line 290 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);}
#line 2068 "parser.tab.c"
    break;

  case 101: /* IF_STT: IF EXPRESSION ':' error '}'  */
#line 291 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);}
#line 2074 "parser.tab.c"
    break;

  case 104: /* $@23: %empty  */
#line 303 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the WHILE loop at line %d\n\n", yylineno);}
#line 2080 "parser.tab.c"
    break;

  case 106: /* $@24: %empty  */
#line 304 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the WHILE loop at line %d\n\n", yylineno);}
#line 2086 "parser.tab.c"
    break;

  case 108: /* ERRONOUS_WHILE_STT: WHILE EXPRESSION ':' error '}'  */
#line 305 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the WHILE loop at line %d\n\n", yylineno);}
#line 2092 "parser.tab.c"
    break;

  case 111: /* $@25: %empty  */
#line 315 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2098 "parser.tab.c"
    break;

  case 113: /* $@26: %empty  */
#line 316 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2104 "parser.tab.c"
    break;

  case 115: /* $@27: %empty  */
#line 317 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);}
#line 2110 "parser.tab.c"
    break;

  case 117: /* $@28: %empty  */
#line 318 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);}
#line 2116 "parser.tab.c"
    break;

  case 119: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 319 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);}
#line 2122 "parser.tab.c"
    break;

  case 120: /* $@29: %empty  */
#line 326 "parser.y"
                        {in_loop = 1;}
#line 2128 "parser.tab.c"
    break;

  case 121: /* $@30: %empty  */
#line 326 "parser.y"
                                                                        {in_loop = 0;}
#line 2134 "parser.tab.c"
    break;

  case 124: /* $@31: %empty  */
#line 331 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);}
#line 2140 "parser.tab.c"
    break;

  case 126: /* $@32: %empty  */
#line 332 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);}
#line 2146 "parser.tab.c"
    break;

  case 128: /* $@33: %empty  */
#line 338 "parser.y"
                           {pushVStack((yyvsp[0].str));}
#line 2152 "parser.tab.c"
    break;

  case 129: /* $@34: %empty  */
#line 338 "parser.y"
                                                { assign_index =lookup((yyvsp[-2].str));}
#line 2158 "parser.tab.c"
    break;

  case 130: /* $@35: %empty  */
#line 338 "parser.y"
                                                                                        {CodeGenAss();}
#line 2164 "parser.tab.c"
    break;

  case 131: /* assignmentSTT: IDENTIFIER $@33 EQ $@34 EXPRESSION $@35 SEMICOLON  */
#line 338 "parser.y"
                                                                                                                           {printf("#[Parsed_Assignment]# ");}
#line 2170 "parser.tab.c"
    break;

  case 132: /* $@36: %empty  */
#line 339 "parser.y"
                             { lookup((yyvsp[0].str));}
#line 2176 "parser.tab.c"
    break;

  case 133: /* assignmentSTT: IDENTIFIER $@36 error EXPRESSION SEMICOLON  */
#line 339 "parser.y"
                                                                           {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);}
#line 2182 "parser.tab.c"
    break;

  case 134: /* $@37: %empty  */
#line 340 "parser.y"
                             { lookup((yyvsp[0].str));}
#line 2188 "parser.tab.c"
    break;

  case 135: /* assignmentSTT: IDENTIFIER $@37 EQ SEMICOLON  */
#line 340 "parser.y"
                                                                           {printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);}
#line 2194 "parser.tab.c"
    break;

  case 136: /* $@38: %empty  */
#line 345 "parser.y"
                    {scope_start();}
#line 2200 "parser.tab.c"
    break;

  case 137: /* $@39: %empty  */
#line 345 "parser.y"
                                                 {scope_end();}
#line 2206 "parser.tab.c"
    break;

  case 138: /* BLOCK: '{' $@38 PROGRAM '}' $@39  */
#line 345 "parser.y"
                                                                                    {printf("#[Parsed_Block]# ");}
#line 2212 "parser.tab.c"
    break;

  case 139: /* $@40: %empty  */
#line 353 "parser.y"
                           {called_func_index = lookup((yyvsp[0].str)); check_type(called_func_index); }
#line 2218 "parser.tab.c"
    break;

  case 140: /* $@41: %empty  */
#line 353 "parser.y"
                                                                                                 { is_param =1;}
#line 2224 "parser.tab.c"
    break;

  case 141: /* $@42: %empty  */
#line 353 "parser.y"
                                                                                                                            { is_param =0; arg_count_check(called_func_index); arg_count=0;}
#line 2230 "parser.tab.c"
    break;

  case 142: /* FUNC_CALL: IDENTIFIER $@40 '(' $@41 USED_ARGS $@42 ')'  */
#line 353 "parser.y"
                                                                                                                                                                                                   { printf("#[Parsed_Func_Call]# ");}
#line 2236 "parser.tab.c"
    break;

  case 143: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 354 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 2242 "parser.tab.c"
    break;

  case 144: /* $@43: %empty  */
#line 358 "parser.y"
                           { arg_count++; }
#line 2248 "parser.tab.c"
    break;

  case 146: /* USED_ARGS: error ',' USED_ARGS  */
#line 359 "parser.y"
                                                        {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 2254 "parser.tab.c"
    break;

  case 147: /* USED_ARGS: EXPRESSION  */
#line 360 "parser.y"
                             {arg_count++ ;}
#line 2260 "parser.tab.c"
    break;

  case 149: /* EXPRESSION: IDENTIFIER  */
#line 367 "parser.y"
                            { int i = lookup((yyvsp[0].str)); check_type(i); pushVStack((yyvsp[0].str));}
#line 2266 "parser.tab.c"
    break;

  case 150: /* EXPRESSION: DIGIT  */
#line 368 "parser.y"
                        { assign_int((yyvsp[0].num), assign_index) ; char numtostring[40]; itoa((yyvsp[0].num), numtostring, 10); pushVStack(numtostring);}
#line 2272 "parser.tab.c"
    break;

  case 151: /* EXPRESSION: FLOAT_DIGIT  */
#line 369 "parser.y"
                              { assign_float((yyvsp[0].float_val), assign_index); char floattostring[40]; gcvt((yyvsp[0].float_val), 6, floattostring); pushVStack(floattostring);}
#line 2278 "parser.tab.c"
    break;

  case 152: /* EXPRESSION: BOOL_LITERAL  */
#line 370 "parser.y"
                                { assign_bool((yyvsp[0].bool_val), assign_index); if((yyvsp[0].bool_val)==true){pushVStack("true");}else{pushVStack("false");}}
#line 2284 "parser.tab.c"
    break;

  case 153: /* EXPRESSION: STRING_LITERAL  */
#line 371 "parser.y"
                                  {  assign_str((yyvsp[0].str), assign_index); pushVStack((yyvsp[0].str));}
#line 2290 "parser.tab.c"
    break;

  case 154: /* EXPRESSION: CONSTANT  */
#line 372 "parser.y"
                           { int i = lookup((yyvsp[0].str)); check_type(i); pushVStack((yyvsp[0].str));}
#line 2296 "parser.tab.c"
    break;

  case 157: /* $@44: %empty  */
#line 375 "parser.y"
                                  {pushVStack("+");}
#line 2302 "parser.tab.c"
    break;

  case 158: /* EXPRESSION: EXPRESSION PLUS $@44 EXPRESSION  */
#line 375 "parser.y"
                                                                 {CodeGenOp();}
#line 2308 "parser.tab.c"
    break;

  case 164: /* EXPRESSION: FUNC_CALL  */
#line 381 "parser.y"
                            {}
#line 2314 "parser.tab.c"
    break;

  case 166: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 383 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);}
#line 2320 "parser.tab.c"
    break;

  case 182: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 416 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 2326 "parser.tab.c"
    break;

  case 183: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 417 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 2332 "parser.tab.c"
    break;

  case 184: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 418 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 2338 "parser.tab.c"
    break;

  case 185: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 419 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 2344 "parser.tab.c"
    break;

  case 186: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 420 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 2350 "parser.tab.c"
    break;

  case 187: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 421 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 2356 "parser.tab.c"
    break;

  case 188: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 422 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 2362 "parser.tab.c"
    break;

  case 189: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 423 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 2368 "parser.tab.c"
    break;

  case 190: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 424 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 2374 "parser.tab.c"
    break;

  case 191: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 425 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 2380 "parser.tab.c"
    break;

  case 192: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 426 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 2386 "parser.tab.c"
    break;

  case 193: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 427 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 2392 "parser.tab.c"
    break;

  case 194: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 428 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 2398 "parser.tab.c"
    break;

  case 195: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 429 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 2404 "parser.tab.c"
    break;

  case 196: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 430 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 2410 "parser.tab.c"
    break;

  case 197: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 431 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 2416 "parser.tab.c"
    break;

  case 198: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 432 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 2422 "parser.tab.c"
    break;


#line 2426 "parser.tab.c"

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

#line 451 "parser.y"




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
    VirtualStack[VirtualSP] = var;
};

char* popVStack ()
{
    //printf("DEBUG %s", VirtualStack[VirtualSP]);
    //char* returner = VirtualStack[VirtualSP];
    //char* returner = VirtualStack[VirtualSP--];
    //strcpy(returner, VirtualStack[VirtualSP--]);
    //VirtualSP--;
    char* returner =  VirtualStack[VirtualSP];
    VirtualSP--;
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
    //printf("DEBUG %s", VirtualStack[VirtualSP]);
    FILE *fp = fopen("LLVM.txt", "a");
    
    if(fp == NULL) {
        printf("can't open LLVM.txt file!\n");
        exit(1);
    }

    //char* value = popVStack();
    //char* carrier = popVStack();
    char* value = popVStack();
    char* carrier = popVStack();
    //strcpy(value, popVStack());
    //strcpy(carrier, popVStack());
    fprintf(fp, "%s = %s\n", carrier, value);
    fclose (fp);

    //printf("DEBUG %s", VirtualStack[VirtualSP]);
};

void CodeGenOp()
{


    

    char* second_operand = popVStack();
    char* operation = popVStack();
    char* first_operand = popVStack();
    
    
    char* temp_var;
    //strcpy(temp_var, newTemp());
    strcpy(temp_var, "t");
    char numtostring[10];
    itoa(tempNumber, numtostring, 10);
    strcat(temp_var, numtostring);
    
    tempNumber++;

    

    FILE *fp = fopen("LLVM.txt", "a");
    if(fp == NULL) {
        printf("can't open LLVM.txt file!\n");
        exit(1);
    }
    
    fprintf(fp, "%s = %s %s %s\n", temp_var, first_operand, operation, second_operand);
    fclose (fp);

    pushVStack(temp_var);

};
//==============================================================================================================================================================





//------------------------------------------- MAIN -------------------------------
int main(int argc, char *argv[])
{ 
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
