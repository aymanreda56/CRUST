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
    ///TODOS
    // ''' 1- symbol table: 
    // store enum value 
    // 2- error handling:
    //   type checking ,const value change, scope checking, function call checking,
    //  function return type checking + feh return wla la2 aslan , function argument checking, function
    //   argument type checking, function argument count checking, function argument order checking '''
    //--------------------- Symbol Table -----------------
    struct Entry {
        int id,intValue,scope;
        char* name , value;
        float floatValue;
        bool boolValue;
        char* strValue; 
        // struct Type dataType;
        char* type; // var,const, func
        char* dataType; // int, float, bool, string (for func: return type)
        // list of arguments stored as IDs of them symbol table
        int argList[100];
        int argCount;
        int declareLine;
        int isConst, isArg, isUsed, isInit;
    };
    struct Entry symbolTable[500];
    int st_index=0;
    int in_loop=0;
    //-- symbol table functions:  st_functionName()
    void st_insert(char* data_type, char* name, char* type, int is_arg);
    void st_print();
    int is_exist(char* name);
    //--- handle scope
    int scope_index=0;
    int block_number=0;
    int scope_stack[500]; // stack of scopes (for nested scopes to store block number)
    void scope_start();
    void scope_end();


#line 123 "parser.tab.c"

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
  YYSYMBOL_BLOCK = 103,                    /* BLOCK  */
  YYSYMBOL_104_33 = 104,                   /* $@33  */
  YYSYMBOL_105_34 = 105,                   /* $@34  */
  YYSYMBOL_FUNC_CALL = 106,                /* FUNC_CALL  */
  YYSYMBOL_USED_ARGS = 107,                /* USED_ARGS  */
  YYSYMBOL_EXPRESSION = 108,               /* EXPRESSION  */
  YYSYMBOL_ERRONOUS_EXPRESSION = 109,      /* ERRONOUS_EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 110,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 111,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 112                  /* RES_WORD  */
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
#define YYLAST   1356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  202
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  369

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
       0,   101,   101,   102,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   127,   128,
     129,   130,   134,   134,   135,   135,   136,   137,   138,   143,
     144,   145,   146,   147,   147,   148,   148,   149,   149,   151,
     159,   160,   165,   166,   167,   171,   171,   172,   172,   176,
     176,   177,   177,   178,   178,   179,   179,   194,   195,   195,
     196,   196,   197,   197,   198,   198,   202,   202,   203,   204,
     204,   205,   206,   206,   207,   207,   208,   208,   212,   213,
     214,   217,   220,   230,   231,   233,   233,   235,   236,   239,
     240,   243,   244,   246,   253,   254,   255,   256,   256,   257,
     257,   258,   265,   266,   270,   270,   271,   271,   272,   278,
     279,   282,   282,   283,   283,   284,   284,   285,   285,   286,
     293,   293,   293,   294,   298,   298,   299,   299,   305,   306,
     307,   312,   312,   312,   320,   321,   325,   326,   327,   328,
     334,   335,   336,   337,   338,   339,   340,   341,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   360,   361,   362,
     363,   364,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408
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
  "$@30", "ERRONOUS_FOR_LOOP", "$@31", "$@32", "assignmentSTT", "BLOCK",
  "$@33", "$@34", "FUNC_CALL", "USED_ARGS", "EXPRESSION",
  "ERRONOUS_EXPRESSION", "COMPARISONSTT", "ERRONOUS_COMPARISONSTT",
  "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-252)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-146)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -252,   136,  -252,   928,  -252,  -252,  -252,  -252,   -14,   246,
      21,   594,  -252,  -252,  -252,    18,    75,   120,   611,  -252,
     412,  -252,  -252,   629,  -252,     5,  -252,  -252,  -252,  -252,
     -11,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  1163,  -252,  -252,  -252,   629,   434,   450,
    -252,   629,   629,   629,    63,   629,   629,   629,   629,   629,
      77,  -252,  -252,    68,  1283,   342,  -252,   835,   383,    81,
     858,   881,    -3,    17,    42,    86,  -252,    16,   103,   204,
     166,   475,   491,  -252,  1009,  -252,    13,  -252,   629,   517,
     533,  -252,   558,   576,   629,   629,   646,   664,   681,   699,
     175,   629,   145,   629,    93,   189,   145,   257,  -252,   204,
     204,   204,   310,   310,  -252,  -252,    94,     2,    95,   -11,
      29,   -11,   383,   383,   383,  -252,    36,   -11,   124,   101,
    -252,    20,   114,    62,   150,   115,  -252,  -252,   123,   129,
      65,  -252,  1183,  -252,  1203,   775,   141,   795,   228,  -252,
       8,   174,   125,     8,     2,   175,   103,   716,   145,   168,
     734,    93,  -252,   189,  -252,   145,   257,   204,  1334,   204,
    1334,   204,  1323,   310,  1323,   310,   145,   145,   151,  -252,
       2,   162,   137,  -252,   171,   177,  -252,   182,   201,  -252,
     383,   383,   383,   -11,   188,  -252,  -252,   187,   220,   200,
    -252,   629,   629,   206,   629,   207,   209,   213,  -252,   215,
     216,   218,  -252,    34,  -252,  -252,   491,  -252,   491,  -252,
     286,   751,  -252,  -252,  -252,   232,  -252,    32,  -252,   235,
     103,   145,   168,   145,     2,   -11,  -252,  -252,  -252,  -252,
       2,  -252,  -252,    79,   239,   383,   383,  -252,  -252,   629,
     242,   629,   629,  1141,  1031,  -252,   815,   243,  -252,  -252,
    -252,    34,   252,    34,    34,   629,   629,   261,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    1223,  -252,  -252,  -252,  -252,  -252,  1243,  -252,  1263,   955,
       2,   -11,  -252,  -252,  -252,  -252,   262,  -252,   -11,  -252,
     264,  -252,  -252,   265,   266,  1053,   629,  1075,  1097,  -252,
    -252,   268,   271,    34,   275,   279,  1303,   904,  -252,  -252,
    -252,  -252,   288,   267,   991,   292,  -252,   295,   -11,  -252,
    -252,  -252,   -11,  -252,  -252,  -252,  1119,  -252,  -252,   319,
    -252,  -252,   298,  -252,  -252,   299,    83,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,   -11,   -11,  -252,  -252,   -11,
    -252,    34,  -252,  -252,    34,    34,  -252,  -252,  -252
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    18,    19,    20,    21,     0,     0,
       0,     0,   143,   144,   145,     0,     0,     0,     0,   141,
       0,   142,   131,     0,     2,     0,     4,    12,    41,     5,
       0,    13,    84,     8,     9,   103,    11,   110,    10,   123,
       6,    14,   154,     0,   156,   153,   171,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    69,     0,     0,    99,    97,     0,   120,
       0,   106,   111,     0,     0,     0,    49,     0,   180,   170,
       0,     0,     0,     3,     0,    24,    66,    57,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
     160,     0,   172,     0,   174,   157,   158,   159,    27,   161,
     176,   178,   181,   183,    26,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,     0,     0,
     115,     0,     0,    88,     0,     0,    85,    86,     0,    51,
       0,   135,     0,   130,     0,     0,     0,   138,     0,   155,
       0,    72,     0,     0,     0,   151,   173,     0,   162,   175,
       0,   163,   146,   148,   147,   149,   150,   152,   177,   166,
     179,   167,   182,   168,   184,   169,   187,   185,     0,    64,
       0,     0,     0,    80,    79,     0,   100,     0,    94,    98,
       0,     0,     0,     0,     0,   102,   107,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,     0,    55,     0,   129,   128,     0,   134,     0,   132,
       0,     0,    32,    25,    28,     0,    62,     0,    23,     0,
     188,   165,   186,   164,     0,     0,    81,    82,    71,    60,
       0,    70,   101,     0,     0,     0,     0,   105,   108,     0,
       0,     0,     0,     0,     0,    91,    90,    88,    87,    93,
      83,     0,     0,     0,     0,     0,     0,     0,    43,   137,
     136,   133,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,     0,    39,     0,    37,
       0,     0,    76,    68,    58,    67,     0,    65,     0,    78,
       0,    96,   124,     0,     0,     0,     0,     0,     0,   119,
     109,     0,     0,     0,     0,     0,    45,     0,    40,    30,
      31,    29,     0,     0,     0,     0,    63,     0,     0,    75,
      61,    95,     0,   126,   121,   112,     0,   116,   114,     0,
      89,    50,     0,    54,    56,     0,     0,    34,    36,   197,
      38,    73,    77,    59,   125,     0,     0,   118,    52,     0,
      47,     0,   127,   122,     0,     0,    42,    46,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -252,   256,   -65,   -85,  -252,  -252,  -252,   221,  -252,  -252,
    -252,  -252,  -251,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -116,  -252,  -252,  -252,    51,   148,    31,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
     -15,  -252,  -252,  -252,    -8,    -7,  -252,  -252,  -252,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    24,    25,    26,   153,   150,   223,   322,   323,
     324,    27,   267,   268,   345,   365,    28,   138,   210,   211,
     264,    29,   328,   298,   291,   235,    30,   154,   117,   225,
     178,   327,   182,   183,   184,    31,   135,   136,   137,    32,
      33,   121,   119,    34,    35,   193,   127,    36,    37,   128,
     252,   199,   129,    38,   124,   356,    39,   332,   355,    40,
      41,    83,   271,    42,   146,    43,    44,    45,    46,   287
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,   185,    67,   122,    71,     4,     5,     6,     7,   220,
     312,    79,   314,   315,   -22,    87,    84,   139,   130,    72,
      63,   200,    68,   221,   222,    22,    85,   131,   -22,   -22,
     187,   181,   181,   292,  -117,   265,   227,   194,   229,    86,
     100,   102,   104,   180,   105,   106,   107,   151,   109,   110,
     111,   112,   113,   152,    22,   140,   201,   190,   191,   192,
     202,    69,   342,   266,   236,    22,   212,   181,   293,   181,
     294,   -44,    22,   142,   144,   147,    74,   204,   132,   108,
     300,   155,   158,   161,   360,   163,   165,   166,   167,   169,
     171,   173,   175,   114,   176,   181,   177,     4,     5,     6,
       7,   213,   115,   205,   186,   188,   189,    90,   116,    75,
     366,   195,   196,   367,   368,    22,    48,    49,   296,    22,
     133,    76,   134,   123,   299,   244,   245,   246,     4,     5,
       6,     7,   179,   141,   197,   180,     2,     3,   198,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   133,   181,
     231,   206,   208,   233,    77,   181,    13,    14,    89,    90,
      15,    16,   209,   226,    17,   -53,   180,    64,    18,    19,
      20,    21,    22,   238,   325,   239,    23,    12,   247,   217,
     303,   304,    49,   203,   133,   207,    13,    14,    89,    90,
     224,   234,    92,    93,   253,   254,   237,   256,    18,    19,
      65,    21,    89,    90,   141,   181,    23,    93,   269,   147,
     270,   147,   240,   286,   289,   241,    88,    89,    90,   242,
     297,    92,    93,    94,   243,   248,    95,   249,   301,     3,
     250,     4,     5,     6,     7,     8,     9,    10,    11,    12,
     251,   257,   305,   255,   307,   308,   259,    64,    13,    14,
     260,   261,    15,    16,   263,   262,    17,    12,   316,   317,
      18,    19,    20,    21,    22,   219,    13,    14,    23,    88,
      89,    90,   290,   295,    92,    93,   326,   302,    18,    19,
      65,    21,   306,   330,   205,    66,    23,    64,   313,   272,
     273,   274,   275,   276,   277,   278,   279,    12,   318,   336,
     329,   331,   339,   333,   334,   348,    13,   280,   341,   281,
     282,   283,   343,   353,   284,   285,   344,   354,    18,    19,
      65,    21,    88,    89,    90,   347,    23,    92,    93,    94,
     351,   361,    95,   352,   204,   358,    96,    97,   359,   148,
     362,   363,   340,   118,   364,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,   258,  -140,  -140,  -140,   350,  -140,  -140,
    -140,  -140,     0,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,   228,     0,     0,     0,  -140,  -140,
    -140,  -140,    82,  -140,     3,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     0,     0,    15,    16,     0,
       0,    17,     0,    80,     0,    18,    19,    20,    21,    22,
       0,     0,     0,    23,  -140,  -140,  -140,    81,  -140,  -140,
    -140,  -140,     0,     0,  -140,    64,     0,     0,  -140,  -140,
       0,     0,  -140,  -140,     0,    12,     0,     0,     0,   101,
       0,    64,    82,     0,    13,    14,     0,     0,     0,     0,
       0,    12,     0,     0,     0,   103,    18,    19,    65,    21,
      13,    14,     0,     0,    23,     0,    64,     0,     0,     0,
       0,     0,    18,    19,    65,    21,    12,     0,     0,     0,
      23,   143,   145,     0,     0,    13,    14,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,    18,    19,    65,
      21,    13,    14,     0,     0,    23,     0,     0,   156,     0,
       0,     0,     0,    18,    19,    65,    21,     0,    12,  -139,
       0,    23,   157,     0,   159,     0,     0,    13,    14,     0,
       0,     0,     0,     0,    12,     0,     0,     0,   160,    18,
      19,    65,    21,    13,    14,     0,     0,    23,     0,    64,
       0,     0,     0,     0,     0,    18,    19,    65,    21,    12,
       0,     0,     0,    23,     0,   162,     0,    64,    13,    14,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
      18,    19,    65,    21,   164,    70,    13,    14,    23,     0,
       0,     0,     0,     0,     0,    12,     0,     0,    18,    19,
      65,    21,    78,     0,    13,    14,    23,     0,     0,     0,
       0,     0,    12,     0,     0,     0,    18,    19,    65,    21,
      64,    13,    14,     0,    23,     0,     0,     0,     0,     0,
      12,     0,     0,    18,    19,    65,    21,   168,     0,    13,
      14,    23,     0,     0,     0,     0,     0,    12,     0,     0,
       0,    18,    19,    65,    21,   170,    13,    14,     0,    23,
       0,     0,     0,     0,     0,    12,     0,     0,    18,    19,
      65,    21,   172,     0,    13,    14,    23,     0,     0,     0,
       0,     0,    12,     0,     0,     0,    18,    19,    65,    21,
     174,    13,    14,     0,    23,     0,     0,     0,     0,     0,
      12,     0,     0,    18,    19,    65,    21,   230,     0,    13,
      14,    23,     0,     0,     0,     0,     0,    12,     0,     0,
       0,    18,    19,    65,    21,   232,    13,    14,     0,    23,
       0,     0,     0,     0,     0,    12,     0,     0,    18,    19,
      65,    21,   288,     0,    13,    14,    23,     0,     0,     0,
       0,     0,    12,     0,     0,     0,    18,    19,    65,    21,
       0,    13,    14,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    65,    21,    47,    48,    49,
       0,    23,    51,    52,    53,     0,     0,    55,     0,     0,
       0,    56,    57,     0,     0,    58,    59,    88,    89,    90,
       0,     0,    92,    93,    94,     0,   216,    95,     0,     0,
       0,    96,    97,     0,     0,    98,    99,    88,    89,    90,
       0,     0,    92,    93,    94,     0,   218,    95,     0,     0,
       0,    96,    97,     0,     0,    98,    99,    88,    89,    90,
       0,     0,    92,    93,    94,     0,   311,    95,     0,     0,
       0,    96,    97,     0,     0,    98,    99,     0,     0,     0,
      47,    48,    49,     0,   120,    51,    52,    53,     0,     0,
      55,     0,     0,     0,    56,    57,     0,     0,    58,    59,
       0,     0,     0,    88,    89,    90,     0,   125,    92,    93,
      94,     0,     0,    95,     0,     0,     0,    96,    97,     0,
       0,    98,    99,     0,     0,     0,    88,    89,    90,     0,
     126,    92,    93,    94,     0,     0,    95,     0,     0,     0,
      96,    97,     0,     0,    98,    99,     0,     0,     0,     0,
      47,    48,    49,   346,    50,    51,    52,    53,     0,    54,
      55,     0,     0,     0,    56,    57,     0,     0,    58,    59,
       0,     0,    60,     0,     0,    61,    62,    88,    89,    90,
       0,   321,    92,    93,    94,     0,     0,    95,     0,     0,
       0,    96,    97,     0,     0,    98,    99,     0,     0,     0,
       0,     0,   -33,   -35,   272,   273,   274,   275,   276,   277,
     278,   279,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   349,     0,   281,   282,   283,     0,     0,   284,
     285,    88,    89,    90,     0,     0,    92,    93,    94,     0,
       0,    95,     0,     0,     0,    96,    97,     0,     0,    98,
      99,     0,     0,    88,    89,    90,     0,   149,    92,    93,
      94,     0,     0,    95,     0,     0,     0,    96,    97,     0,
       0,    98,    99,     0,     0,    88,    89,    90,     0,   310,
      92,    93,    94,     0,     0,    95,     0,     0,     0,    96,
      97,     0,     0,    98,    99,     0,     0,    88,    89,    90,
       0,   335,    92,    93,    94,     0,     0,    95,     0,     0,
       0,    96,    97,     0,     0,    98,    99,     0,     0,    88,
      89,    90,     0,   337,    92,    93,    94,     0,     0,    95,
       0,     0,     0,    96,    97,     0,     0,    98,    99,     0,
       0,    88,    89,    90,     0,   338,    92,    93,    94,     0,
       0,    95,     0,     0,     0,    96,    97,     0,     0,    98,
      99,     0,     0,    88,    89,    90,     0,   357,    92,    93,
      94,     0,     0,    95,     0,     0,     0,    96,    97,     0,
       0,    98,    99,     0,     0,    88,    89,    90,   309,    91,
      92,    93,    94,     0,     0,    95,     0,     0,     0,    96,
      97,     0,     0,    98,    99,    88,    89,    90,     0,   214,
      92,    93,    94,     0,     0,    95,     0,     0,     0,    96,
      97,     0,     0,    98,    99,    88,    89,    90,     0,   215,
      92,    93,    94,     0,     0,    95,     0,     0,     0,    96,
      97,     0,     0,    98,    99,  -145,  -145,  -145,     0,  -145,
    -145,  -145,  -145,     0,     0,  -145,     0,     0,     0,  -145,
    -145,     0,     0,  -145,  -145,    88,    89,    90,     0,   319,
      92,    93,    94,     0,     0,    95,     0,     0,     0,    96,
      97,     0,     0,    98,    99,    47,    48,    49,     0,   320,
      51,    52,    53,     0,     0,    55,     0,     0,     0,    56,
      57,     0,     0,    58,    59,    47,    48,    49,     0,     0,
      51,    52,    53,     0,     0,    55,     0,     0,     0,    56,
      57,     0,     0,    58,    59,    88,    89,    90,     0,     0,
      92,    93,    94,     0,     0,    95,     0,     0,     0,    96,
      97,     0,     0,    98,    99,    47,    48,    49,     0,     0,
      51,    52,    53,     0,     0,    55,    47,    48,    49,    56,
      57,    51,    52,    53,     0,     0,    55
};

static const yytype_int16 yycheck[] =
{
      15,   117,     9,    68,    11,     3,     4,     5,     6,     1,
     261,    18,   263,   264,     1,    30,    23,     1,     1,     1,
      34,     1,     1,    15,    16,    36,    21,    10,    15,    16,
       1,   116,   117,     1,    37,     1,   152,     1,   154,    34,
      47,    48,    49,    41,    51,    52,    53,    34,    55,    56,
      57,    58,    59,    40,    36,    39,    36,   122,   123,   124,
      40,    40,   313,    29,   180,    36,     1,   152,    36,   154,
      38,    37,    36,    80,    81,    82,     1,    15,    36,    16,
       1,    88,    89,    90,     1,    92,    93,    94,    95,    96,
      97,    98,    99,    16,   101,   180,   103,     3,     4,     5,
       6,    36,    34,    41,   119,   120,   121,    14,    40,    34,
     361,   126,   127,   364,   365,    36,    13,    14,   234,    36,
      34,     1,    36,    42,   240,   190,   191,   192,     3,     4,
       5,     6,    38,    38,    10,    41,     0,     1,    37,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    34,   234,
     157,     1,    37,   160,    34,   240,    20,    21,    13,    14,
      24,    25,    39,    38,    28,    36,    41,     1,    32,    33,
      34,    35,    36,    36,   290,    38,    40,    11,   193,    38,
     245,   246,    14,   132,    34,   134,    20,    21,    13,    14,
      16,    40,    17,    18,   201,   202,    34,   204,    32,    33,
      34,    35,    13,    14,    38,   290,    40,    18,   216,   216,
     218,   218,    41,   220,   221,    38,    12,    13,    14,    37,
     235,    17,    18,    19,    23,    37,    22,    40,   243,     1,
      10,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      40,    34,   249,    37,   251,   252,    37,     1,    20,    21,
      37,    36,    24,    25,    36,    39,    28,    11,   265,   266,
      32,    33,    34,    35,    36,    37,    20,    21,    40,    12,
      13,    14,    40,    38,    17,    18,   291,    38,    32,    33,
      34,    35,    40,   298,    41,    39,    40,     1,    36,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    37,   306,
      38,    37,    34,    38,    38,    38,    20,    21,    37,    23,
      24,    25,    37,   328,    28,    29,    37,   332,    32,    33,
      34,    35,    12,    13,    14,    37,    40,    17,    18,    19,
      38,   346,    22,    38,    15,    37,    26,    27,    39,    83,
     355,   356,   311,     1,   359,     3,     4,     5,     6,     7,
       8,     9,    10,   205,    12,    13,    14,   324,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   153,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    -1,    -1,    24,    25,    -1,
      -1,    28,    -1,     1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,     1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    -1,    11,    -1,    -1,    -1,    15,
      -1,     1,    40,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    15,    32,    33,    34,    35,
      20,    21,    -1,    -1,    40,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    11,    -1,    -1,    -1,
      40,    16,     1,    -1,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    20,    21,    -1,    -1,    40,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    -1,    11,    38,
      -1,    40,    15,    -1,     1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    15,    32,
      33,    34,    35,    20,    21,    -1,    -1,    40,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    11,
      -1,    -1,    -1,    40,    -1,    17,    -1,     1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      32,    33,    34,    35,    18,     1,    20,    21,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    32,    33,
      34,    35,     1,    -1,    20,    21,    40,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    32,    33,    34,    35,
       1,    20,    21,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    32,    33,    34,    35,     1,    -1,    20,
      21,    40,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    32,    33,    34,    35,     1,    20,    21,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    32,    33,
      34,    35,     1,    -1,    20,    21,    40,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    32,    33,    34,    35,
       1,    20,    21,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    32,    33,    34,    35,     1,    -1,    20,
      21,    40,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    32,    33,    34,    35,     1,    20,    21,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    32,    33,
      34,    35,     1,    -1,    20,    21,    40,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    32,    33,    34,    35,
      -1,    20,    21,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    12,    13,    14,
      -1,    40,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    12,    13,    14,
      -1,    -1,    17,    18,    19,    -1,    41,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    12,    13,    14,
      -1,    -1,    17,    18,    19,    -1,    41,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    12,    13,    14,
      -1,    -1,    17,    18,    19,    -1,    41,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,
      12,    13,    14,    -1,    39,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      -1,    -1,    -1,    12,    13,    14,    -1,    39,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    -1,    -1,    -1,    12,    13,    14,    -1,
      39,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      12,    13,    14,    39,    16,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      -1,    -1,    34,    -1,    -1,    37,    38,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    23,    24,    25,    -1,    -1,    28,
      29,    12,    13,    14,    -1,    -1,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,
      31,    -1,    -1,    12,    13,    14,    -1,    38,    17,    18,
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
      -1,    30,    31,    -1,    -1,    12,    13,    14,    37,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    12,    13,    14,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    12,    13,    14,    -1,    -1,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    12,    13,    14,    -1,    -1,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    12,    13,    14,    -1,    -1,
      17,    18,    19,    -1,    -1,    22,    12,    13,    14,    26,
      27,    17,    18,    19,    -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    20,    21,    24,    25,    28,    32,    33,
      34,    35,    36,    40,    45,    46,    47,    54,    59,    64,
      69,    78,    82,    83,    86,    87,    90,    91,    96,    99,
     102,   103,   106,   108,   109,   110,   111,    12,    13,    14,
      16,    17,    18,    19,    21,    22,    26,    27,    30,    31,
      34,    37,    38,    34,     1,    34,    39,   108,     1,    40,
       1,   108,     1,   103,     1,    34,     1,    34,     1,   108,
       1,    15,    40,   104,   108,    21,    34,   103,    12,    13,
      14,    16,    17,    18,    19,    22,    26,    27,    30,    31,
     108,    15,   108,    15,   108,   108,   108,   108,    16,   108,
     108,   108,   108,   108,    16,    34,    40,    71,     1,    85,
      39,    84,    45,    42,    97,    39,    39,    89,    92,    95,
       1,    10,    36,    34,    36,    79,    80,    81,    60,     1,
      39,    38,   108,    16,   108,     1,   107,   108,    44,    38,
      49,    34,    40,    48,    70,   108,     1,    15,   108,     1,
      15,   108,    17,   108,    18,   108,   108,   108,     1,   108,
       1,   108,     1,   108,     1,   108,   108,   108,    73,    38,
      41,    46,    75,    76,    77,    75,   103,     1,   103,   103,
      45,    45,    45,    88,     1,   103,   103,    10,    37,    94,
       1,    36,    40,    79,    15,    41,     1,    79,    37,    39,
      61,    62,     1,    36,    16,    16,    41,    38,    41,    37,
       1,    15,    16,    50,    16,    72,    38,    75,    50,    75,
       1,   108,     1,   108,    40,    68,    75,    34,    36,    38,
      41,    38,    37,    23,    45,    45,    45,   103,    37,    40,
      10,    40,    93,   108,   108,    37,   108,    34,    80,    37,
      37,    36,    39,    36,    63,     1,    29,    55,    56,   107,
     107,   105,     3,     4,     5,     6,     7,     8,     9,    10,
      21,    23,    24,    25,    28,    29,   108,   112,     1,   108,
      40,    67,     1,    36,    38,    38,    75,   103,    66,    75,
       1,   103,    38,    45,    45,   108,    40,   108,   108,    37,
      38,    41,    55,    36,    55,    55,   108,   108,    37,    16,
      16,    16,    51,    52,    53,    75,   103,    74,    65,    38,
     103,    37,   100,    38,    38,    38,   108,    38,    38,    34,
      81,    37,    55,    37,    37,    57,    39,    37,    38,    21,
     112,    38,    38,   103,   103,   101,    98,    38,    37,    39,
       1,   103,   103,   103,   103,    58,    55,    55,    55
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
      97,    98,    96,    96,   100,    99,   101,    99,   102,   102,
     102,   104,   105,   103,   106,   106,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   109,
     109,   109,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112
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
       0,     0,     9,     1,     0,     8,     0,     9,     4,     4,
       3,     0,     0,     5,     4,     3,     3,     3,     1,     0,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
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
#line 101 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1680 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 107 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1686 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 110 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1692 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 111 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1698 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 112 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1704 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 113 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1710 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 114 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1716 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 115 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1722 "parser.tab.c"
    break;

  case 15: /* STATEMENT: error SEMICOLON  */
#line 117 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1728 "parser.tab.c"
    break;

  case 16: /* STATEMENT: error '}'  */
#line 118 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1734 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error ')'  */
#line 119 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1740 "parser.tab.c"
    break;

  case 18: /* TYPE: INT  */
#line 127 "parser.y"
                    { (yyval.str) = "int"; }
#line 1746 "parser.tab.c"
    break;

  case 19: /* TYPE: FLOAT  */
#line 128 "parser.y"
                        { (yyval.str) = "float"; }
#line 1752 "parser.tab.c"
    break;

  case 20: /* TYPE: BOOL  */
#line 129 "parser.y"
                        { (yyval.str) = "bool"; }
#line 1758 "parser.tab.c"
    break;

  case 21: /* TYPE: STRING  */
#line 130 "parser.y"
                         { (yyval.str) = "string"; }
#line 1764 "parser.tab.c"
    break;

  case 22: /* $@1: %empty  */
#line 134 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0); }
#line 1770 "parser.tab.c"
    break;

  case 23: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 134 "parser.y"
                                                                                            {printf("#[Parsed_Declaration]# ");}
#line 1776 "parser.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 135 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0);}
#line 1782 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 135 "parser.y"
                                                                                            {printf("#[Parsed_CONST_Declaration]# "); }
#line 1788 "parser.tab.c"
    break;

  case 26: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 136 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1794 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 137 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1800 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 138 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);}
#line 1806 "parser.tab.c"
    break;

  case 30: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 144 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1812 "parser.tab.c"
    break;

  case 31: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 145 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1818 "parser.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 147 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1824 "parser.tab.c"
    break;

  case 35: /* $@4: %empty  */
#line 148 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1830 "parser.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 149 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1836 "parser.tab.c"
    break;

  case 39: /* DECLARATION_TAIL: error RES_WORD  */
#line 151 "parser.y"
                                                                                           {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);}
#line 1842 "parser.tab.c"
    break;

  case 45: /* $@6: %empty  */
#line 171 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);}
#line 1848 "parser.tab.c"
    break;

  case 47: /* $@7: %empty  */
#line 172 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);}
#line 1854 "parser.tab.c"
    break;

  case 49: /* $@8: %empty  */
#line 176 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1860 "parser.tab.c"
    break;

  case 51: /* $@9: %empty  */
#line 177 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }
#line 1866 "parser.tab.c"
    break;

  case 53: /* $@10: %empty  */
#line 178 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1872 "parser.tab.c"
    break;

  case 55: /* $@11: %empty  */
#line 179 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1878 "parser.tab.c"
    break;

  case 58: /* $@12: %empty  */
#line 195 "parser.y"
                                                 {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1884 "parser.tab.c"
    break;

  case 60: /* $@13: %empty  */
#line 196 "parser.y"
                                                 {st_insert("void", (yyvsp[-3].str),"func",0);}
#line 1890 "parser.tab.c"
    break;

  case 62: /* $@14: %empty  */
#line 197 "parser.y"
                                                 {st_insert((yyvsp[-3].str), (yyvsp[-2].str),"func",0);}
#line 1896 "parser.tab.c"
    break;

  case 64: /* $@15: %empty  */
#line 198 "parser.y"
                                                 {st_insert("void", (yyvsp[-2].str),"func",0);}
#line 1902 "parser.tab.c"
    break;

  case 66: /* $@16: %empty  */
#line 202 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1908 "parser.tab.c"
    break;

  case 67: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@16 ARGS ')'  */
#line 202 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1914 "parser.tab.c"
    break;

  case 68: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS '{'  */
#line 203 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1920 "parser.tab.c"
    break;

  case 69: /* $@17: %empty  */
#line 204 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1926 "parser.tab.c"
    break;

  case 70: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER $@17 ARGS ')'  */
#line 204 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1932 "parser.tab.c"
    break;

  case 71: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER '(' ARGS '{'  */
#line 205 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1938 "parser.tab.c"
    break;

  case 72: /* $@18: %empty  */
#line 206 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1944 "parser.tab.c"
    break;

  case 73: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER $@18 '(' ARGS ')'  */
#line 206 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1950 "parser.tab.c"
    break;

  case 74: /* $@19: %empty  */
#line 207 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1956 "parser.tab.c"
    break;

  case 75: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER IDENTIFIER $@19 '(' ARGS ')'  */
#line 207 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1962 "parser.tab.c"
    break;

  case 76: /* $@20: %empty  */
#line 208 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected token '%s' in argument list of function declaration at line %d\n\n", yylval, yylineno);}
#line 1968 "parser.tab.c"
    break;

  case 77: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS error $@20 ')'  */
#line 208 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1974 "parser.tab.c"
    break;

  case 81: /* ERRONOUS_ARGS: ',' ARGS  */
#line 217 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
#line 1980 "parser.tab.c"
    break;

  case 82: /* ARG_DECL: TYPE IDENTIFIER  */
#line 220 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1);}
#line 1986 "parser.tab.c"
    break;

  case 83: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_HELPER '}'  */
#line 230 "parser.y"
                                                              { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 1992 "parser.tab.c"
    break;

  case 91: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 243 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);}
#line 1998 "parser.tab.c"
    break;

  case 92: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 244 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);}
#line 2004 "parser.tab.c"
    break;

  case 93: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 246 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 2010 "parser.tab.c"
    break;

  case 95: /* IF_STT: IF EXPRESSION ':' BLOCK ELSE error '}'  */
#line 254 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);}
#line 2016 "parser.tab.c"
    break;

  case 97: /* $@21: %empty  */
#line 256 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 2022 "parser.tab.c"
    break;

  case 99: /* $@22: %empty  */
#line 257 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);}
#line 2028 "parser.tab.c"
    break;

  case 101: /* IF_STT: IF EXPRESSION ':' error '}'  */
#line 258 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);}
#line 2034 "parser.tab.c"
    break;

  case 104: /* $@23: %empty  */
#line 270 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the WHILE loop at line %d\n\n", yylineno);}
#line 2040 "parser.tab.c"
    break;

  case 106: /* $@24: %empty  */
#line 271 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the WHILE loop at line %d\n\n", yylineno);}
#line 2046 "parser.tab.c"
    break;

  case 108: /* ERRONOUS_WHILE_STT: WHILE EXPRESSION ':' error '}'  */
#line 272 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the WHILE loop at line %d\n\n", yylineno);}
#line 2052 "parser.tab.c"
    break;

  case 111: /* $@25: %empty  */
#line 282 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2058 "parser.tab.c"
    break;

  case 113: /* $@26: %empty  */
#line 283 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2064 "parser.tab.c"
    break;

  case 115: /* $@27: %empty  */
#line 284 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);}
#line 2070 "parser.tab.c"
    break;

  case 117: /* $@28: %empty  */
#line 285 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);}
#line 2076 "parser.tab.c"
    break;

  case 119: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 286 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);}
#line 2082 "parser.tab.c"
    break;

  case 120: /* $@29: %empty  */
#line 293 "parser.y"
                        {in_loop = 1;}
#line 2088 "parser.tab.c"
    break;

  case 121: /* $@30: %empty  */
#line 293 "parser.y"
                                                                        {in_loop = 0;}
#line 2094 "parser.tab.c"
    break;

  case 124: /* $@31: %empty  */
#line 298 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);}
#line 2100 "parser.tab.c"
    break;

  case 126: /* $@32: %empty  */
#line 299 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);}
#line 2106 "parser.tab.c"
    break;

  case 128: /* assignmentSTT: IDENTIFIER EQ EXPRESSION SEMICOLON  */
#line 305 "parser.y"
                                                            {printf("#[Parsed_Assignment]# ");}
#line 2112 "parser.tab.c"
    break;

  case 129: /* assignmentSTT: IDENTIFIER error EXPRESSION SEMICOLON  */
#line 306 "parser.y"
                                                            {printf("\n\n=====ERROR====\n expected '=' in assignment statement at line %d\n\n", yylineno);}
#line 2118 "parser.tab.c"
    break;

  case 130: /* assignmentSTT: IDENTIFIER EQ SEMICOLON  */
#line 307 "parser.y"
                                                            {printf("\n\n=====ERROR====\n expected expression in assignment statement at line %d\n\n", yylineno);}
#line 2124 "parser.tab.c"
    break;

  case 131: /* $@33: %empty  */
#line 312 "parser.y"
                    {scope_start();}
#line 2130 "parser.tab.c"
    break;

  case 132: /* $@34: %empty  */
#line 312 "parser.y"
                                                 {scope_end();}
#line 2136 "parser.tab.c"
    break;

  case 133: /* BLOCK: '{' $@33 PROGRAM '}' $@34  */
#line 312 "parser.y"
                                                                                    {printf("#[Parsed_Block]# ");}
#line 2142 "parser.tab.c"
    break;

  case 134: /* FUNC_CALL: IDENTIFIER '(' USED_ARGS ')'  */
#line 320 "parser.y"
                                                        {printf("#[Parsed_Func_Call]# ");}
#line 2148 "parser.tab.c"
    break;

  case 135: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 321 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 2154 "parser.tab.c"
    break;

  case 137: /* USED_ARGS: error ',' USED_ARGS  */
#line 326 "parser.y"
                                                        {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 2160 "parser.tab.c"
    break;

  case 141: /* EXPRESSION: DIGIT  */
#line 335 "parser.y"
                        { symbolTable[st_index-1].intValue= (yyvsp[0].num) ;}
#line 2166 "parser.tab.c"
    break;

  case 142: /* EXPRESSION: FLOAT_DIGIT  */
#line 336 "parser.y"
                              { symbolTable[st_index-1].floatValue= (yyvsp[0].float_val) ;}
#line 2172 "parser.tab.c"
    break;

  case 143: /* EXPRESSION: BOOL_LITERAL  */
#line 337 "parser.y"
                                { symbolTable[st_index-1].boolValue= (yyvsp[0].bool_val) ;}
#line 2178 "parser.tab.c"
    break;

  case 144: /* EXPRESSION: STRING_LITERAL  */
#line 338 "parser.y"
                                  { symbolTable[st_index-1].strValue= (yyvsp[0].str) ;}
#line 2184 "parser.tab.c"
    break;

  case 156: /* EXPRESSION: ERRONOUS_EXPRESSION  */
#line 351 "parser.y"
                                                {printf("\n\n=====ERROR====\n Expression error at line %d\n\n", yylineno);}
#line 2190 "parser.tab.c"
    break;

  case 172: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 384 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 2196 "parser.tab.c"
    break;

  case 173: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 385 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 2202 "parser.tab.c"
    break;

  case 174: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 386 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 2208 "parser.tab.c"
    break;

  case 175: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 387 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 2214 "parser.tab.c"
    break;

  case 176: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 388 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 2220 "parser.tab.c"
    break;

  case 177: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 389 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 2226 "parser.tab.c"
    break;

  case 178: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 390 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 2232 "parser.tab.c"
    break;

  case 179: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 391 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 2238 "parser.tab.c"
    break;

  case 180: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 392 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 2244 "parser.tab.c"
    break;

  case 181: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 393 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 2250 "parser.tab.c"
    break;

  case 182: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 394 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 2256 "parser.tab.c"
    break;

  case 183: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 395 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 2262 "parser.tab.c"
    break;

  case 184: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 396 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 2268 "parser.tab.c"
    break;

  case 185: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 397 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 2274 "parser.tab.c"
    break;

  case 186: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 398 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 2280 "parser.tab.c"
    break;

  case 187: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 399 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 2286 "parser.tab.c"
    break;

  case 188: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 400 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 2292 "parser.tab.c"
    break;


#line 2296 "parser.tab.c"

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

#line 419 "parser.y"




//------------------------------------------ FUNCTIONS ---------------------------------------------
void yyerror(char *s) { 
 fprintf(stderr, "line %d: %s\n", yylineno, s); 
} 
int yywrap()
{
    return 1;
}
//------------------------------------------ SYMBOL TABLE---------------------------------------------
int is_exist(char* name){
    for (int i = 0; i < st_index; i++){
        if (strcmp(symbolTable[i].name, name) == 0 && symbolTable[i].scope == scope_index){
            return 1;
        }
    }
    return 0;
}
//-------------------------------------- INSERT IN SYMBOL TABLE  ----------------------------------I
void st_insert(char* data_type, char* name, char* type ,int is_arg ) {
    printf("##############################################");
    //------ create new entry
    struct Entry newEntry ;
    //----- check if name is already in symbol table
    if (is_exist(name) == 1){
        printf("\n !!!!!!!!!!!! Error: %s is already declared in this scope !!!!!!!!!!!\n", name);
        exit(1);
    }
    //------ set new entry values
    newEntry.name = name;
    newEntry.dataType = data_type;
    newEntry.declareLine = line_number;
    newEntry.type = type;
    newEntry.id = st_index;
    newEntry.isArg = is_arg;
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
//---------------------------------- PRINT SYMBOL TABLE ----------------------------------------------------
void st_print() {
    //----- write symbol table to file
    FILE *fp = fopen("symbol_table.txt", "w");
    //----- check if file is opened
    if(fp == NULL) {
        printf("can't open symbol_table.txt file!\n");
        exit(1);
    }
    //----- write symbol table header
    fprintf(fp, "ID\t|Name\t\t|Type\t|DataType\t|Line\t|Scope\t|Value\t\t|Args\n");
    fprintf(fp, "-------------------------------------------------------------------------------------------\n");
    //----- write symbol table entries
    for(int i=0; i< st_index; i++) {
        struct Entry *entry = &symbolTable[i];
        fprintf(fp, "%d\t|%s\t|%s\t|%s\t\t|%d\t|%d\t|", entry->id, entry->name,entry->type, entry->dataType, entry->declareLine, entry->scope);
        //---- store value of entry
        if (strcmp(entry->dataType,"int")==0) {fprintf(fp, "%d\t\t|", entry->intValue);}
        else if (strcmp(entry->dataType,"float")==0) {fp, fprintf(fp, "%f\t\t|", entry->floatValue);}
        else if (strcmp(entry->dataType,"bool")==0) {fprintf(fp,"%s\t\t|", entry->boolValue ? "true" : "false");}
        else if (strcmp(entry->dataType,"string")==0) {fprintf(fp, "%s\t\t|", entry->strValue);}
        else {fprintf(fp, "-|");}
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
//------------------------------------------- HANDLE SCOPE -----------------------------------------
void scope_start(){
    //----- increment block number and scope index
    block_number++;
    scope_index++;
    scope_stack[scope_index] = block_number;
}
void scope_end(){
    scope_index--; // decrement scope index
}
//------------------------------------------- MAIN -------------------------------
int main(int argc, char *argv[])
{ 
    yyin = fopen(argv[1], "r");
    yyparse();
    st_print();
    return 0;
}
