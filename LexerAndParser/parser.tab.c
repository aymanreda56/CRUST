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
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* ':'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
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
  YYSYMBOL_COMPARISONSTT = 109,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 110,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 111                  /* RES_WORD  */
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
#define YYLAST   1197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  194
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  354

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
      40,    37,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    36,     2,     2,     2,     2,
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
       0,    99,    99,   100,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   125,   126,
     127,   128,   132,   132,   133,   133,   134,   135,   136,   141,
     142,   143,   144,   145,   145,   146,   146,   147,   147,   149,
     157,   158,   163,   164,   165,   169,   169,   170,   170,   174,
     174,   175,   175,   176,   176,   177,   177,   192,   193,   193,
     194,   194,   195,   195,   196,   196,   200,   200,   201,   202,
     202,   203,   204,   204,   205,   205,   206,   206,   210,   211,
     212,   215,   218,   228,   229,   231,   231,   233,   234,   237,
     238,   241,   242,   244,   251,   252,   253,   254,   254,   255,
     255,   256,   263,   264,   268,   268,   269,   269,   270,   276,
     277,   280,   280,   281,   281,   282,   282,   283,   283,   284,
     291,   291,   291,   292,   296,   296,   297,   297,   303,   308,
     308,   308,   315,   316,   320,   321,   322,   323,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   387,   387,   387,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,   387
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
  "IDENTIFIER", "FLOAT_DIGIT", "'}'", "')'", "':'", "'{'", "'('", "','",
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
  "$@33", "$@34", "FUNC_CALL", "USED_ARGS", "EXPRESSION", "COMPARISONSTT",
  "ERRONOUS_COMPARISONSTT", "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-241)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-144)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -241,   214,  -241,  1044,  -241,  -241,  -241,  -241,   -12,    27,
       9,   531,  -241,  -241,  -241,    12,     0,    94,   556,  -241,
     128,  -241,  -241,   572,  -241,     8,  -241,  -241,  -241,  -241,
       2,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,  1070,  -241,  -241,   230,   422,  -241,    15,
     572,   572,   572,   572,    75,  -241,  -241,   -10,   287,   327,
    -241,   823,   406,    46,   439,   845,    62,    13,    78,   143,
    -241,    18,   219,   725,   101,   572,   447,  -241,   911,  -241,
      56,  -241,   572,   474,   490,  -241,   168,   515,   572,   572,
     597,   613,   638,   654,   572,   223,   572,   134,  -241,   725,
     725,  1170,  1170,  -241,  -241,   120,   108,     2,    31,     2,
     406,   406,   406,  -241,    35,     2,   142,   124,  -241,    63,
     133,    -8,    96,   135,  -241,  -241,   140,   152,    65,  -241,
    1090,   766,   156,   744,   271,  -241,    11,   179,   129,    11,
     108,   193,   219,   679,   223,   183,   695,   134,  -241,     7,
    -241,   223,   276,   725,   219,   725,   219,   725,   149,  1170,
     149,  1170,   223,   223,   164,  -241,   108,   175,    68,  -241,
     171,   189,  -241,   180,   205,  -241,   406,   406,   406,     2,
     204,  -241,  -241,   212,   245,   216,  -241,   572,   572,   221,
     572,   224,   231,   233,  -241,   220,   222,   227,  -241,    72,
    -241,   447,  -241,   447,  -241,   368,   720,  -241,  -241,  -241,
     243,  -241,   114,  -241,   234,   219,   223,   183,   223,   108,
       2,  -241,  -241,  -241,  -241,   108,  -241,  -241,   117,   236,
     406,   406,  -241,  -241,   572,   246,   572,   572,  1037,   932,
    -241,   764,   244,  -241,  -241,  -241,    72,   248,    72,    72,
     572,   572,   261,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  1110,  -241,  -241,  -241,  -241,
    -241,  1130,  -241,   790,   890,   108,     2,  -241,  -241,  -241,
    -241,   272,  -241,     2,  -241,   279,  -241,  -241,   275,   282,
     953,   572,   974,   995,  -241,  -241,   274,   284,    72,   285,
     286,  1150,   867,  -241,  -241,  -241,  -241,   288,   290,   805,
     301,  -241,   305,     2,  -241,  -241,  -241,     2,  -241,  -241,
    -241,  1016,  -241,  -241,   308,  -241,  -241,   311,  -241,  -241,
     321,   126,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
       2,     2,  -241,  -241,     2,  -241,    72,  -241,  -241,    72,
      72,  -241,  -241,  -241
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    18,    19,    20,    21,     0,     0,
       0,     0,   141,   142,   143,     0,     0,     0,     0,   139,
       0,   140,   129,     0,     2,     0,     4,    12,    41,     5,
       0,    13,    84,     8,     9,   103,    11,   110,    10,   123,
       6,    14,   152,     0,   151,   163,     0,     0,    15,     0,
       0,     0,     0,     0,     0,    16,    17,    69,     0,     0,
      99,    97,     0,   120,     0,   106,   111,     0,     0,     0,
      49,     0,   172,   162,     0,     0,     0,     3,     0,    24,
      66,    57,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,   166,    27,   168,
     170,   173,   175,    26,    74,     0,     0,     0,     0,     0,
       0,     0,     0,   104,     0,     0,     0,     0,   115,     0,
       0,    88,     0,     0,    85,    86,     0,    51,     0,   133,
       0,     0,     0,   136,     0,   153,     0,    72,     0,     0,
       0,   149,   165,     0,   154,   167,     0,   155,   144,   146,
     145,   147,   148,   150,   169,   158,   171,   159,   174,   160,
     176,   161,   179,   177,     0,    64,     0,     0,     0,    80,
      79,     0,   100,     0,    94,    98,     0,     0,     0,     0,
       0,   102,   107,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,     0,    55,     0,
     128,     0,   132,     0,   130,     0,     0,    32,    25,    28,
       0,    62,     0,    23,     0,   180,   157,   178,   156,     0,
       0,    81,    82,    60,    71,     0,    70,   101,     0,     0,
       0,     0,   105,   108,     0,     0,     0,     0,     0,     0,
      91,    90,    88,    87,    93,    83,     0,     0,     0,     0,
       0,     0,     0,    43,   135,   134,   131,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,    39,     0,    37,     0,     0,    76,    58,    68,
      67,     0,    65,     0,    78,     0,    96,   124,     0,     0,
       0,     0,     0,     0,   119,   109,     0,     0,     0,     0,
       0,    45,     0,    40,    30,    31,    29,     0,     0,     0,
       0,    63,     0,     0,    75,    61,    95,     0,   126,   121,
     112,     0,   116,   114,     0,    89,    50,     0,    54,    56,
       0,     0,    34,    36,   189,    38,    73,    77,    59,   125,
       0,     0,   118,    52,     0,    47,     0,   127,   122,     0,
       0,    42,    46,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -241,   283,   -57,   -88,  -241,  -241,  -241,   241,  -241,  -241,
    -241,  -241,  -240,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -103,  -241,  -241,  -241,    64,   170,    66,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
     -15,  -241,  -241,  -241,   -11,    -7,  -241,  -241,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    24,    25,    26,   139,   136,   208,   307,   308,
     309,    27,   252,   253,   330,   350,    28,   126,   196,   197,
     249,    29,   313,   283,   276,   220,    30,   140,   106,   210,
     164,   312,   168,   169,   170,    31,   123,   124,   125,    32,
      33,   109,   107,    34,    35,   179,   115,    36,    37,   116,
     237,   185,   117,    38,   112,   341,    39,   317,   340,    40,
      41,    77,   256,    42,   132,    43,    44,    45,   272
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    68,    61,   171,    65,   110,   297,   190,   299,   300,
      62,    73,   205,    66,   118,    81,    78,   167,   167,   127,
      83,    84,    57,   119,   104,    87,   206,   207,    58,    79,
     105,    98,   173,   191,    69,   212,   180,   214,    12,    95,
      97,    22,    80,    99,   100,   101,   102,    13,    14,    63,
     167,    22,   167,   176,   177,   178,   128,   -22,   327,    18,
      19,    59,    21,   221,   186,    60,   198,    23,   130,   133,
      22,   -22,   -22,   250,    22,   141,   144,   147,   167,   149,
     151,   152,   153,   155,   157,   159,   161,   162,   111,   163,
     137,   103,   172,   174,   175,    70,   138,   192,  -117,   181,
     182,   251,   187,   188,   199,   223,   351,   224,   -44,   352,
     353,     4,     5,     6,     7,   277,   281,   120,   285,   229,
     230,   231,   284,     4,     5,     6,     7,   345,    71,    74,
     121,   167,     4,     5,     6,     7,   216,   167,   129,   218,
    -138,  -138,  -138,    75,  -138,  -138,  -138,  -138,    84,   166,
    -138,   278,   183,   279,  -138,  -138,    22,   165,  -138,  -138,
     184,   166,    46,    47,   232,    22,   211,   121,    76,    58,
     166,   194,   310,   288,   289,    50,    51,   121,   195,    12,
     238,   239,   122,   241,   189,   148,   193,   167,    13,    14,
     254,   -53,   255,   202,   133,   209,   133,    47,   271,   274,
      18,    19,    59,    21,   219,   282,    83,    84,    23,   222,
      86,    87,   225,   286,     2,     3,   227,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   226,   290,   228,   292,
     293,    58,    46,    47,    13,    14,    83,    84,    15,    16,
     233,    12,    17,   301,   302,    94,    18,    19,    20,    21,
      13,    14,   234,    22,    23,   235,   236,   240,   242,   246,
     247,   311,    18,    19,    59,    21,   248,   244,   315,   245,
      23,   280,     3,   287,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   275,   321,   191,   291,   298,    82,    83,
      84,    13,    14,    86,    87,    15,    16,   303,   338,    17,
      46,    47,   339,    18,    19,    20,    21,   204,   324,   314,
      22,    23,   318,    50,    51,   316,   346,    52,    53,   319,
     326,   328,   329,   190,   332,   347,   348,   333,    74,   349,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   336,  -138,
    -138,  -138,   337,  -138,  -138,  -138,  -138,   343,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   344,
     134,   243,   325,  -138,  -138,  -138,  -138,    76,  -138,    58,
     335,   257,   258,   259,   260,   261,   262,   263,   264,    12,
     213,     0,     0,     0,     0,     0,     0,     0,    13,   265,
       0,   266,   267,   268,     0,     0,   269,   270,     0,     0,
      18,    19,    59,    21,     0,     0,     0,     3,    23,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,    58,     0,     0,    13,    14,     0,     0,
      15,    16,     0,    12,    17,     0,     0,    96,    18,    19,
      20,    21,    13,    14,     0,    22,    23,     0,   131,     0,
       0,     0,    46,    47,    18,    19,    59,    21,    12,     0,
       0,     0,    23,     0,     0,    50,    51,    13,    14,    52,
      53,     0,     0,     0,     0,   142,     0,   113,     0,    18,
      19,    59,    21,     0,  -137,    12,     0,    23,     0,   143,
       0,   145,     0,     0,    13,    14,     0,     0,     0,     0,
       0,    12,     0,     0,     0,   146,    18,    19,    59,    21,
      13,    14,     0,     0,    23,     0,    58,     0,     0,     0,
       0,     0,    18,    19,    59,    21,    12,     0,     0,     0,
      23,     0,    64,   150,     0,    13,    14,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,    18,    19,    59,
      21,    13,    14,     0,     0,    23,     0,    72,     0,     0,
       0,     0,     0,    18,    19,    59,    21,    12,     0,     0,
       0,    23,     0,    58,     0,     0,    13,    14,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,    18,    19,
      59,    21,    13,    14,     0,     0,    23,     0,   154,     0,
       0,     0,     0,     0,    18,    19,    59,    21,    12,     0,
       0,     0,    23,     0,   156,     0,     0,    13,    14,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,    18,
      19,    59,    21,    13,    14,     0,     0,    23,     0,   158,
       0,     0,     0,     0,     0,    18,    19,    59,    21,    12,
       0,     0,     0,    23,     0,   160,     0,     0,    13,    14,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
      18,    19,    59,    21,    13,    14,     0,     0,    23,     0,
     215,     0,     0,     0,     0,     0,    18,    19,    59,    21,
      12,     0,     0,     0,    23,     0,   217,     0,     0,    13,
      14,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,    18,    19,    59,    21,    13,    14,     0,     0,    23,
       0,   273,     0,     0,     0,     0,     0,    18,    19,    59,
      21,    12,     0,     0,     0,    23,     0,    82,    83,    84,
      13,    14,    86,    87,    88,     0,     0,    89,     0,     0,
       0,     0,    18,    19,    59,    21,    82,    83,    84,     0,
      23,    86,    87,    88,     0,     0,    89,     0,     0,     0,
      90,    91,     0,     0,    92,    93,    82,    83,    84,    46,
      47,    86,    87,    88,     0,   203,    89,     0,     0,     0,
      90,    91,    50,    51,    92,    93,    52,    53,     0,     0,
       0,     0,     0,    46,    47,   296,   305,   201,   257,   258,
     259,   260,   261,   262,   263,   264,    50,    51,     0,     0,
      52,    53,     0,     0,     0,     0,   334,     0,   266,   267,
     268,     0,     0,   269,   270,    82,    83,    84,     0,     0,
      86,    87,    88,     0,     0,    89,     0,     0,     0,    90,
      91,     0,     0,    92,    93,     0,     0,    82,    83,    84,
       0,   108,    86,    87,    88,     0,     0,    89,     0,     0,
       0,    90,    91,     0,     0,    92,    93,     0,     0,    82,
      83,    84,     0,   114,    86,    87,    88,     0,     0,    89,
       0,     0,     0,    90,    91,     0,     0,    92,    93,     0,
       0,     0,    82,    83,    84,   331,   306,    86,    87,    88,
       0,     0,    89,     0,     0,     0,    90,    91,     0,     0,
      92,    93,     0,    82,    83,    84,   -33,   -35,    86,    87,
      88,     0,     0,    89,     0,     0,     0,    90,    91,     0,
       0,    92,    93,     0,    82,    83,    84,     0,   135,    86,
      87,    88,     0,     0,    89,     0,     0,     0,    90,    91,
       0,     0,    92,    93,     0,    82,    83,    84,     0,   295,
      86,    87,    88,     0,     0,    89,     0,     0,     0,    90,
      91,     0,     0,    92,    93,     0,    82,    83,    84,     0,
     320,    86,    87,    88,     0,     0,    89,     0,     0,     0,
      90,    91,     0,     0,    92,    93,     0,    82,    83,    84,
       0,   322,    86,    87,    88,     0,     0,    89,     0,     0,
       0,    90,    91,     0,     0,    92,    93,     0,    82,    83,
      84,     0,   323,    86,    87,    88,     0,     0,    89,     0,
       0,     0,    90,    91,     0,     0,    92,    93,     0,    82,
      83,    84,     0,   342,    86,    87,    88,    46,    47,    89,
      48,     0,     0,    90,    91,    49,     0,    92,    93,     0,
      50,    51,     0,   294,    52,    53,     0,     0,    54,     0,
      55,    56,    82,    83,    84,     0,    85,    86,    87,    88,
       0,     0,    89,     0,     0,     0,    90,    91,     0,     0,
      92,    93,    82,    83,    84,     0,   200,    86,    87,    88,
       0,     0,    89,     0,     0,     0,    90,    91,     0,     0,
      92,    93,  -143,  -143,  -143,     0,  -143,  -143,  -143,  -143,
       0,     0,  -143,     0,     0,     0,  -143,  -143,     0,     0,
    -143,  -143,    82,    83,    84,     0,   304,    86,    87,    88,
       0,     0,    89,     0,     0,     0,    90,    91,     0,     0,
      92,    93,    82,    83,    84,     0,     0,    86,    87,    88,
       0,     0,    89,     0,     0,     0,    90,    91,     0,     0,
      92,    93,    82,    83,    84,     0,     0,    86,    87,    88,
       0,     0,    89,     0,     0,     0,    90,    91
};

static const yytype_int16 yycheck[] =
{
      15,     1,     9,   106,    11,    62,   246,    15,   248,   249,
       1,    18,     1,     1,     1,    30,    23,   105,   106,     1,
      13,    14,    34,    10,    34,    18,    15,    16,     1,    21,
      40,    16,     1,    41,    34,   138,     1,   140,    11,    46,
      47,    39,    34,    50,    51,    52,    53,    20,    21,    40,
     138,    39,   140,   110,   111,   112,    38,     1,   298,    32,
      33,    34,    35,   166,     1,    38,     1,    40,    75,    76,
      39,    15,    16,     1,    39,    82,    83,    84,   166,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    42,    96,
      34,    16,   107,   108,   109,     1,    40,     1,    36,   114,
     115,    29,    39,    40,    39,    37,   346,    39,    36,   349,
     350,     3,     4,     5,     6,     1,   219,    39,     1,   176,
     177,   178,   225,     3,     4,     5,     6,     1,    34,     1,
      34,   219,     3,     4,     5,     6,   143,   225,    37,   146,
      12,    13,    14,    15,    16,    17,    18,    19,    14,    41,
      22,    37,    10,    39,    26,    27,    39,    37,    30,    31,
      36,    41,    13,    14,   179,    39,    37,    34,    40,     1,
      41,    36,   275,   230,   231,    26,    27,    34,    38,    11,
     187,   188,    39,   190,   120,    17,   122,   275,    20,    21,
     201,    39,   203,    37,   201,    16,   203,    14,   205,   206,
      32,    33,    34,    35,    40,   220,    13,    14,    40,    34,
      17,    18,    41,   228,     0,     1,    36,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    37,   234,    23,   236,
     237,     1,    13,    14,    20,    21,    13,    14,    24,    25,
      36,    11,    28,   250,   251,    15,    32,    33,    34,    35,
      20,    21,    40,    39,    40,    10,    40,    36,    34,    39,
      38,   276,    32,    33,    34,    35,    39,    36,   283,    36,
      40,    37,     1,    37,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    40,   291,    41,    40,    39,    12,    13,
      14,    20,    21,    17,    18,    24,    25,    36,   313,    28,
      13,    14,   317,    32,    33,    34,    35,    36,    34,    37,
      39,    40,    37,    26,    27,    36,   331,    30,    31,    37,
      36,    36,    36,    15,    36,   340,   341,    37,     1,   344,
       3,     4,     5,     6,     7,     8,     9,    10,    37,    12,
      13,    14,    37,    16,    17,    18,    19,    36,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    38,
      77,   191,   296,    36,    37,    38,    39,    40,    41,     1,
     309,     3,     4,     5,     6,     7,     8,     9,    10,    11,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      -1,    23,    24,    25,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,     1,    40,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    20,    21,    -1,    -1,
      24,    25,    -1,    11,    28,    -1,    -1,    15,    32,    33,
      34,    35,    20,    21,    -1,    39,    40,    -1,     1,    -1,
      -1,    -1,    13,    14,    32,    33,    34,    35,    11,    -1,
      -1,    -1,    40,    -1,    -1,    26,    27,    20,    21,    30,
      31,    -1,    -1,    -1,    -1,     1,    -1,    38,    -1,    32,
      33,    34,    35,    -1,    37,    11,    -1,    40,    -1,    15,
      -1,     1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    15,    32,    33,    34,    35,
      20,    21,    -1,    -1,    40,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    11,    -1,    -1,    -1,
      40,    -1,     1,    18,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    20,    21,    -1,    -1,    40,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    11,    -1,    -1,
      -1,    40,    -1,     1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    20,    21,    -1,    -1,    40,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    11,    -1,
      -1,    -1,    40,    -1,     1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    20,    21,    -1,    -1,    40,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    11,
      -1,    -1,    -1,    40,    -1,     1,    -1,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    20,    21,    -1,    -1,    40,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      11,    -1,    -1,    -1,    40,    -1,     1,    -1,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    20,    21,    -1,    -1,    40,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    11,    -1,    -1,    -1,    40,    -1,    12,    13,    14,
      20,    21,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    12,    13,    14,    -1,
      40,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    12,    13,    14,    13,
      14,    17,    18,    19,    -1,    41,    22,    -1,    -1,    -1,
      26,    27,    26,    27,    30,    31,    30,    31,    -1,    -1,
      -1,    -1,    -1,    13,    14,    41,    16,    41,     3,     4,
       5,     6,     7,     8,     9,    10,    26,    27,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    21,    -1,    23,    24,
      25,    -1,    -1,    28,    29,    12,    13,    14,    -1,    -1,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    -1,    -1,    12,    13,    14,
      -1,    38,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,    12,
      13,    14,    -1,    38,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,
      -1,    -1,    12,    13,    14,    38,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    -1,    12,    13,    14,    36,    37,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    -1,    12,    13,    14,    -1,    37,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    -1,    12,    13,    14,    -1,    37,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    -1,    12,    13,    14,    -1,
      37,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    -1,    12,    13,    14,
      -1,    37,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    12,    13,
      14,    -1,    37,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,    12,
      13,    14,    -1,    37,    17,    18,    19,    13,    14,    22,
      16,    -1,    -1,    26,    27,    21,    -1,    30,    31,    -1,
      26,    27,    -1,    36,    30,    31,    -1,    -1,    34,    -1,
      36,    37,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    12,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    12,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    20,    21,    24,    25,    28,    32,    33,
      34,    35,    39,    40,    45,    46,    47,    54,    59,    64,
      69,    78,    82,    83,    86,    87,    90,    91,    96,    99,
     102,   103,   106,   108,   109,   110,    13,    14,    16,    21,
      26,    27,    30,    31,    34,    36,    37,    34,     1,    34,
      38,   108,     1,    40,     1,   108,     1,   103,     1,    34,
       1,    34,     1,   108,     1,    15,    40,   104,   108,    21,
      34,   103,    12,    13,    14,    16,    17,    18,    19,    22,
      26,    27,    30,    31,    15,   108,    15,   108,    16,   108,
     108,   108,   108,    16,    34,    40,    71,    85,    38,    84,
      45,    42,    97,    38,    38,    89,    92,    95,     1,    10,
      39,    34,    39,    79,    80,    81,    60,     1,    38,    37,
     108,     1,   107,   108,    44,    37,    49,    34,    40,    48,
      70,   108,     1,    15,   108,     1,    15,   108,    17,   108,
      18,   108,   108,   108,     1,   108,     1,   108,     1,   108,
       1,   108,   108,   108,    73,    37,    41,    46,    75,    76,
      77,    75,   103,     1,   103,   103,    45,    45,    45,    88,
       1,   103,   103,    10,    36,    94,     1,    39,    40,    79,
      15,    41,     1,    79,    36,    38,    61,    62,     1,    39,
      16,    41,    37,    41,    36,     1,    15,    16,    50,    16,
      72,    37,    75,    50,    75,     1,   108,     1,   108,    40,
      68,    75,    34,    37,    39,    41,    37,    36,    23,    45,
      45,    45,   103,    36,    40,    10,    40,    93,   108,   108,
      36,   108,    34,    80,    36,    36,    39,    38,    39,    63,
       1,    29,    55,    56,   107,   107,   105,     3,     4,     5,
       6,     7,     8,     9,    10,    21,    23,    24,    25,    28,
      29,   108,   111,     1,   108,    40,    67,     1,    37,    39,
      37,    75,   103,    66,    75,     1,   103,    37,    45,    45,
     108,    40,   108,   108,    36,    37,    41,    55,    39,    55,
      55,   108,   108,    36,    16,    16,    16,    51,    52,    53,
      75,   103,    74,    65,    37,   103,    36,   100,    37,    37,
      37,   108,    37,    37,    34,    81,    36,    55,    36,    36,
      57,    38,    36,    37,    21,   111,    37,    37,   103,   103,
     101,    98,    37,    36,    38,     1,   103,   103,   103,   103,
      58,    55,    55,    55
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
      97,    98,    96,    96,   100,    99,   101,    99,   102,   104,
     105,   103,   106,   106,   107,   107,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111
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
       0,     0,     9,     1,     0,     8,     0,     9,     4,     0,
       0,     5,     4,     3,     3,     3,     1,     0,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     4,     4,     3,     3,
       3,     3,     2,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     4,     4,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 99 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1640 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 105 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1646 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 108 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1652 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 109 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1658 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 110 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1664 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 111 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1670 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 112 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1676 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 113 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1682 "parser.tab.c"
    break;

  case 15: /* STATEMENT: error SEMICOLON  */
#line 115 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1688 "parser.tab.c"
    break;

  case 16: /* STATEMENT: error '}'  */
#line 116 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1694 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error ')'  */
#line 117 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1700 "parser.tab.c"
    break;

  case 18: /* TYPE: INT  */
#line 125 "parser.y"
                    { (yyval.str) = "int"; }
#line 1706 "parser.tab.c"
    break;

  case 19: /* TYPE: FLOAT  */
#line 126 "parser.y"
                        { (yyval.str) = "float"; }
#line 1712 "parser.tab.c"
    break;

  case 20: /* TYPE: BOOL  */
#line 127 "parser.y"
                        { (yyval.str) = "bool"; }
#line 1718 "parser.tab.c"
    break;

  case 21: /* TYPE: STRING  */
#line 128 "parser.y"
                         { (yyval.str) = "string"; }
#line 1724 "parser.tab.c"
    break;

  case 22: /* $@1: %empty  */
#line 132 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0); }
#line 1730 "parser.tab.c"
    break;

  case 23: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 132 "parser.y"
                                                                                            {printf("#[Parsed_Declaration]# ");}
#line 1736 "parser.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 133 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0);}
#line 1742 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 133 "parser.y"
                                                                                            {printf("#[Parsed_CONST_Declaration]# "); }
#line 1748 "parser.tab.c"
    break;

  case 26: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 134 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1754 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 135 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1760 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 136 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);}
#line 1766 "parser.tab.c"
    break;

  case 30: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 142 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1772 "parser.tab.c"
    break;

  case 31: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 143 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1778 "parser.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 145 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1784 "parser.tab.c"
    break;

  case 35: /* $@4: %empty  */
#line 146 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1790 "parser.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 147 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1796 "parser.tab.c"
    break;

  case 39: /* DECLARATION_TAIL: error RES_WORD  */
#line 149 "parser.y"
                                                                                           {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);}
#line 1802 "parser.tab.c"
    break;

  case 45: /* $@6: %empty  */
#line 169 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);}
#line 1808 "parser.tab.c"
    break;

  case 47: /* $@7: %empty  */
#line 170 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);}
#line 1814 "parser.tab.c"
    break;

  case 49: /* $@8: %empty  */
#line 174 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1820 "parser.tab.c"
    break;

  case 51: /* $@9: %empty  */
#line 175 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }
#line 1826 "parser.tab.c"
    break;

  case 53: /* $@10: %empty  */
#line 176 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1832 "parser.tab.c"
    break;

  case 55: /* $@11: %empty  */
#line 177 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1838 "parser.tab.c"
    break;

  case 58: /* $@12: %empty  */
#line 193 "parser.y"
                                                 {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1844 "parser.tab.c"
    break;

  case 60: /* $@13: %empty  */
#line 194 "parser.y"
                                                 {st_insert("void", (yyvsp[-3].str),"func",0);}
#line 1850 "parser.tab.c"
    break;

  case 62: /* $@14: %empty  */
#line 195 "parser.y"
                                                 {st_insert((yyvsp[-3].str), (yyvsp[-2].str),"func",0);}
#line 1856 "parser.tab.c"
    break;

  case 64: /* $@15: %empty  */
#line 196 "parser.y"
                                                 {st_insert("void", (yyvsp[-2].str),"func",0);}
#line 1862 "parser.tab.c"
    break;

  case 66: /* $@16: %empty  */
#line 200 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1868 "parser.tab.c"
    break;

  case 67: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@16 ARGS ')'  */
#line 200 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1874 "parser.tab.c"
    break;

  case 68: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS '{'  */
#line 201 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1880 "parser.tab.c"
    break;

  case 69: /* $@17: %empty  */
#line 202 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1886 "parser.tab.c"
    break;

  case 70: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER $@17 ARGS ')'  */
#line 202 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1892 "parser.tab.c"
    break;

  case 71: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER '(' ARGS '{'  */
#line 203 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1898 "parser.tab.c"
    break;

  case 72: /* $@18: %empty  */
#line 204 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1904 "parser.tab.c"
    break;

  case 73: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER $@18 '(' ARGS ')'  */
#line 204 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1910 "parser.tab.c"
    break;

  case 74: /* $@19: %empty  */
#line 205 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1916 "parser.tab.c"
    break;

  case 75: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER IDENTIFIER $@19 '(' ARGS ')'  */
#line 205 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1922 "parser.tab.c"
    break;

  case 76: /* $@20: %empty  */
#line 206 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected token '%s' in argument list of function declaration at line %d\n\n", yylval, yylineno);}
#line 1928 "parser.tab.c"
    break;

  case 77: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS error $@20 ')'  */
#line 206 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1934 "parser.tab.c"
    break;

  case 81: /* ERRONOUS_ARGS: ',' ARGS  */
#line 215 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
#line 1940 "parser.tab.c"
    break;

  case 82: /* ARG_DECL: TYPE IDENTIFIER  */
#line 218 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1);}
#line 1946 "parser.tab.c"
    break;

  case 83: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_HELPER '}'  */
#line 228 "parser.y"
                                                              { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 1952 "parser.tab.c"
    break;

  case 91: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 241 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);}
#line 1958 "parser.tab.c"
    break;

  case 92: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 242 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);}
#line 1964 "parser.tab.c"
    break;

  case 93: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 244 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 1970 "parser.tab.c"
    break;

  case 95: /* IF_STT: IF EXPRESSION ':' BLOCK ELSE error '}'  */
#line 252 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);}
#line 1976 "parser.tab.c"
    break;

  case 97: /* $@21: %empty  */
#line 254 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 1982 "parser.tab.c"
    break;

  case 99: /* $@22: %empty  */
#line 255 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);}
#line 1988 "parser.tab.c"
    break;

  case 101: /* IF_STT: IF EXPRESSION ':' error '}'  */
#line 256 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);}
#line 1994 "parser.tab.c"
    break;

  case 104: /* $@23: %empty  */
#line 268 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the WHILE loop at line %d\n\n", yylineno);}
#line 2000 "parser.tab.c"
    break;

  case 106: /* $@24: %empty  */
#line 269 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the WHILE loop at line %d\n\n", yylineno);}
#line 2006 "parser.tab.c"
    break;

  case 108: /* ERRONOUS_WHILE_STT: WHILE EXPRESSION ':' error '}'  */
#line 270 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the WHILE loop at line %d\n\n", yylineno);}
#line 2012 "parser.tab.c"
    break;

  case 111: /* $@25: %empty  */
#line 280 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing DO-Block for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2018 "parser.tab.c"
    break;

  case 113: /* $@26: %empty  */
#line 281 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening parenthesis '(' for the DO-WHILE loop at line %d\n\n", yylineno);}
#line 2024 "parser.tab.c"
    break;

  case 115: /* $@27: %empty  */
#line 282 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing WHILE DO-WHILE loop at line %d\n\n", yylineno);}
#line 2030 "parser.tab.c"
    break;

  case 117: /* $@28: %empty  */
#line 283 "parser.y"
                                                    {printf("\n\n=====ERROR====\n Missing opening curly braces '{' for the DO-Block for DO-WHILE loop at line %d\n\n", yylineno);}
#line 2036 "parser.tab.c"
    break;

  case 119: /* ERRONOUS_DO_WHILE: DO BLOCK WHILE '{' EXPRESSION '}'  */
#line 284 "parser.y"
                                                    {printf("\n\n=====ERROR====\n DO-WHILE loop accepts braces () not curly braces {} at line %d\n\n", yylineno);}
#line 2042 "parser.tab.c"
    break;

  case 120: /* $@29: %empty  */
#line 291 "parser.y"
                        {in_loop = 1;}
#line 2048 "parser.tab.c"
    break;

  case 121: /* $@30: %empty  */
#line 291 "parser.y"
                                                                        {in_loop = 0;}
#line 2054 "parser.tab.c"
    break;

  case 124: /* $@31: %empty  */
#line 296 "parser.y"
                                                                       {printf("\n\n=====ERROR====\n Missing opening braces '(' in the FOR loop at line %d\n\n", yylineno);}
#line 2060 "parser.tab.c"
    break;

  case 126: /* $@32: %empty  */
#line 297 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n unexpected semicolon in the FOR loop at line %d\n\n", yylineno);}
#line 2066 "parser.tab.c"
    break;

  case 128: /* assignmentSTT: IDENTIFIER EQ EXPRESSION SEMICOLON  */
#line 303 "parser.y"
                                                            {printf("#[Parsed_Assignment]# ");}
#line 2072 "parser.tab.c"
    break;

  case 129: /* $@33: %empty  */
#line 308 "parser.y"
                    {scope_start();}
#line 2078 "parser.tab.c"
    break;

  case 130: /* $@34: %empty  */
#line 308 "parser.y"
                                                 {scope_end();}
#line 2084 "parser.tab.c"
    break;

  case 131: /* BLOCK: '{' $@33 PROGRAM '}' $@34  */
#line 308 "parser.y"
                                                                                    {printf("#[Parsed_Block]# ");}
#line 2090 "parser.tab.c"
    break;

  case 132: /* FUNC_CALL: IDENTIFIER '(' USED_ARGS ')'  */
#line 315 "parser.y"
                                                        {printf("#[Parsed_Func_Call]# ");}
#line 2096 "parser.tab.c"
    break;

  case 133: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 316 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 2102 "parser.tab.c"
    break;

  case 135: /* USED_ARGS: error ',' USED_ARGS  */
#line 321 "parser.y"
                                                        {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 2108 "parser.tab.c"
    break;

  case 139: /* EXPRESSION: DIGIT  */
#line 329 "parser.y"
                        { symbolTable[st_index-1].intValue= (yyvsp[0].num) ;}
#line 2114 "parser.tab.c"
    break;

  case 140: /* EXPRESSION: FLOAT_DIGIT  */
#line 330 "parser.y"
                              { symbolTable[st_index-1].floatValue= (yyvsp[0].float_val) ;}
#line 2120 "parser.tab.c"
    break;

  case 141: /* EXPRESSION: BOOL_LITERAL  */
#line 331 "parser.y"
                                { symbolTable[st_index-1].boolValue= (yyvsp[0].bool_val) ;}
#line 2126 "parser.tab.c"
    break;

  case 142: /* EXPRESSION: STRING_LITERAL  */
#line 332 "parser.y"
                                  { symbolTable[st_index-1].strValue= (yyvsp[0].str) ;}
#line 2132 "parser.tab.c"
    break;

  case 164: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 363 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 2138 "parser.tab.c"
    break;

  case 165: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 364 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 2144 "parser.tab.c"
    break;

  case 166: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 365 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 2150 "parser.tab.c"
    break;

  case 167: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 366 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 2156 "parser.tab.c"
    break;

  case 168: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 367 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 2162 "parser.tab.c"
    break;

  case 169: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 368 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 2168 "parser.tab.c"
    break;

  case 170: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 369 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 2174 "parser.tab.c"
    break;

  case 171: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 370 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 2180 "parser.tab.c"
    break;

  case 172: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 371 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 2186 "parser.tab.c"
    break;

  case 173: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 372 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 2192 "parser.tab.c"
    break;

  case 174: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 373 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 2198 "parser.tab.c"
    break;

  case 175: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 374 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 2204 "parser.tab.c"
    break;

  case 176: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 375 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 2210 "parser.tab.c"
    break;

  case 177: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 376 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 2216 "parser.tab.c"
    break;

  case 178: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 377 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 2222 "parser.tab.c"
    break;

  case 179: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 378 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 2228 "parser.tab.c"
    break;

  case 180: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 379 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 2234 "parser.tab.c"
    break;


#line 2238 "parser.tab.c"

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

#line 398 "parser.y"




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
