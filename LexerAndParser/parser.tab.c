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
    // #include "../SymbolTable/SymbolTableEntry.h"
    #include "parser.tab.h"
    void yyerror(char* );
    int yylex();
    void yyerror();
    extern FILE *yyin;
    extern FILE *yyout;

    // extern enum yytokentype ;
    //---------------------- data types -----------------
    // typedef enum {int, float , bool,} Type;
    //--------------------- Symbol Table -----------------
    struct Entry {
        char* name , value;
        char* scope;
        // struct Type dataType;
        char* type; // var, func, class
        char* dataType; // int, float, bool, string
        int delcareLine;
    };
    //SymbolTableEntry* symbolTable = new SymbolTableEntry()
    // const int maxSize=500;
    struct Entry symbolTable[500];
    int st_index=0;
    //-- symbol table functions:  st_functionName()
    void st_insert(char* data_type, char* name, int is_const);
    void st_print();

    // BOOL st_isExist();



#line 108 "parser.tab.c"

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
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_BOOL_LITERAL = 10,              /* BOOL_LITERAL  */
  YYSYMBOL_DIV = 11,                       /* DIV  */
  YYSYMBOL_GT = 12,                        /* GT  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_SEMICOLON = 15,                 /* SEMICOLON  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_SUB = 17,                       /* SUB  */
  YYSYMBOL_MUL = 18,                       /* MUL  */
  YYSYMBOL_STRING_LITERAL = 19,            /* STRING_LITERAL  */
  YYSYMBOL_CONSTANT = 20,                  /* CONSTANT  */
  YYSYMBOL_POW = 21,                       /* POW  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_ENUM = 24,                      /* ENUM  */
  YYSYMBOL_EQUALITY = 25,                  /* EQUALITY  */
  YYSYMBOL_NEG_EQUALITY = 26,              /* NEG_EQUALITY  */
  YYSYMBOL_SWITCH = 27,                    /* SWITCH  */
  YYSYMBOL_CASE = 28,                      /* CASE  */
  YYSYMBOL_LOGIC_AND = 29,                 /* LOGIC_AND  */
  YYSYMBOL_LOGIC_OR = 30,                  /* LOGIC_OR  */
  YYSYMBOL_LOGIC_NOT = 31,                 /* LOGIC_NOT  */
  YYSYMBOL_DIGIT = 32,                     /* DIGIT  */
  YYSYMBOL_IDENTIFIER = 33,                /* IDENTIFIER  */
  YYSYMBOL_34_ = 34,                       /* ':'  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_PROGRAM = 41,                   /* PROGRAM  */
  YYSYMBOL_STATEMENT = 42,                 /* STATEMENT  */
  YYSYMBOL_TYPE = 43,                      /* TYPE  */
  YYSYMBOL_DECLARATION_STT = 44,           /* DECLARATION_STT  */
  YYSYMBOL_DECLARATION_TAIL = 45,          /* DECLARATION_TAIL  */
  YYSYMBOL_SWITCH_STT = 46,                /* SWITCH_STT  */
  YYSYMBOL_CASES = 47,                     /* CASES  */
  YYSYMBOL_FUNC_CALL = 48,                 /* FUNC_CALL  */
  YYSYMBOL_USED_ARGS = 49,                 /* USED_ARGS  */
  YYSYMBOL_FUNC_DECLARATION_STT = 50,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_ARGS = 51,                      /* ARGS  */
  YYSYMBOL_ARG_DECL = 52,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 53,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_ARGS = 54,                 /* ENUM_ARGS  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 55,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_IF_STT = 56,                    /* IF_STT  */
  YYSYMBOL_WHILE_STT = 57,                 /* WHILE_STT  */
  YYSYMBOL_DO_WHILE_STT = 58,              /* DO_WHILE_STT  */
  YYSYMBOL_FOR_STT = 59,                   /* FOR_STT  */
  YYSYMBOL_assignmentSTT = 60,             /* assignmentSTT  */
  YYSYMBOL_BLOCK = 61,                     /* BLOCK  */
  YYSYMBOL_EXPRESSION = 62,                /* EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 63              /* COMPARISONSTT  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   437

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      37,    38,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    66,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    88,    89,    90,    91,    95,
      96,   100,   101,   105,   108,   109,   113,   116,   117,   118,
     122,   126,   127,   128,   132,   136,   137,   140,   141,   144,
     145,   149,   150,   154,   158,   162,   166,   170,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   192,   193,   194,   195,   196,   197,   198,
     199,   200
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
  "STRING", "IF", "FOR", "WHILE", "BOOL_LITERAL", "DIV", "GT", "LT", "EQ",
  "SEMICOLON", "PLUS", "SUB", "MUL", "STRING_LITERAL", "CONSTANT", "POW",
  "ELSE", "DO", "ENUM", "EQUALITY", "NEG_EQUALITY", "SWITCH", "CASE",
  "LOGIC_AND", "LOGIC_OR", "LOGIC_NOT", "DIGIT", "IDENTIFIER", "':'",
  "'{'", "'}'", "'('", "')'", "','", "$accept", "PROGRAM", "STATEMENT",
  "TYPE", "DECLARATION_STT", "DECLARATION_TAIL", "SWITCH_STT", "CASES",
  "FUNC_CALL", "USED_ARGS", "FUNC_DECLARATION_STT", "ARGS", "ARG_DECL",
  "ENUM_DECLARATION_STT", "ENUM_ARGS", "ENUM_DEFINED_ARGS", "IF_STT",
  "WHILE_STT", "DO_WHILE_STT", "FOR_STT", "assignmentSTT", "BLOCK",
  "EXPRESSION", "COMPARISONSTT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -74,   121,   -74,   -74,   -74,   -74,   -74,   258,   -36,   258,
     -74,   -74,   -74,   -29,   -26,     1,   258,   -74,    -6,   -74,
     258,   -74,    -8,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   345,   -74,     0,   285,   191,   305,
      32,     8,    11,   416,   258,   258,   156,   218,    34,    -1,
     258,    74,    82,   -74,     7,   255,   258,   258,   258,   258,
     258,   258,   -29,   191,   -29,    18,    31,    33,   365,    41,
       3,   -74,   -74,   258,    68,   164,    72,   130,   258,    54,
     258,    78,   -74,    57,   -74,    54,   122,   416,   416,   416,
     405,   405,    73,   191,   -74,   258,    -9,    64,    67,    80,
     -74,   -74,   258,   385,   -74,    77,   -35,   -74,   -74,    54,
      54,   -29,    79,   241,   258,    85,   -74,   -74,   258,    86,
     -74,   -74,   -29,   164,   -74,   -29,   -74,    60,    93,   -74,
     325,   -74,   -74,   -74,   -74,   103,   -29,   123,   -74,    80,
     -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,    15,    16,    17,    18,     0,     0,     0,
      50,    51,    52,     0,     0,     0,     0,    49,    48,     3,
       0,     2,     0,     4,    12,    61,     5,    13,     8,     9,
      11,    10,     6,    14,     0,    60,    48,     0,     0,     0,
       0,     0,     0,    71,     0,    29,     0,     0,    22,    22,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    47,    62,     0,     0,    33,     0,    58,     0,    63,
       0,    64,    53,    55,    54,    56,    57,    59,    67,    68,
      69,    70,    41,     0,    43,     0,    38,     0,     0,    25,
      46,    26,    29,    21,    20,     0,     0,    32,    19,    66,
      65,     0,     0,     0,     0,     0,    35,    36,     0,     0,
      27,    34,     0,     0,    42,     0,    44,    40,    38,    37,
       0,    23,    30,    31,    45,     0,     0,     0,    39,    25,
      24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   131,   -28,   -73,   -74,   100,   -74,    12,   -74,    53,
     -74,   -74,    48,   -74,    42,    37,   -74,   -74,   -74,   -74,
     -74,   -13,     2,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    21,    22,    23,    74,    24,   119,    25,    69,
      26,   106,   107,    27,    97,    98,    28,    29,    30,    31,
      32,    33,    34,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    38,   105,   122,   123,   114,    19,    41,    44,    37,
      63,    39,    48,    73,    50,    51,    52,    10,    43,    54,
      55,    56,    47,    82,    57,    49,    11,    12,    58,    59,
     115,    45,    60,    61,    42,    93,    75,    45,    16,    17,
      36,    65,   102,    66,    20,    67,    68,    70,    73,    92,
     105,    94,    77,    79,    81,    95,    83,    85,    86,    87,
      88,    89,    90,    91,    96,   112,    51,    52,    99,    51,
      52,    50,    51,    52,    55,   103,    54,    55,    56,   101,
     109,    57,   110,   104,    10,    58,    59,   108,    78,    60,
      61,    52,    10,    11,    12,   111,    80,   113,   124,   135,
     116,    11,    12,   117,    70,    16,    17,    36,   118,   132,
     121,    20,   134,    16,    17,    36,   127,   125,   128,    20,
     130,     2,   131,   139,     3,     4,     5,     6,     7,     8,
       9,    10,   115,    50,    51,    52,   137,   114,    54,    55,
      11,    12,    51,    52,    13,    14,    54,    55,    15,    76,
      46,   140,    16,    17,    18,   120,    19,   129,    20,     3,
       4,     5,     6,     7,     8,     9,    10,     3,     4,     5,
       6,   133,   138,     0,     0,    11,    12,     0,     0,    13,
      14,     0,     0,    15,     0,     0,     0,    16,    17,    18,
       0,    19,    71,    20,     3,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,     0,     0,    13,    14,     0,     0,    15,     0,
       0,     0,    16,    17,    18,     0,    19,     0,    20,    50,
      51,    52,     0,     0,    54,    55,    56,     0,     0,    57,
       0,     0,     0,    58,    59,     0,     0,    60,    61,     0,
       0,     0,    50,    51,    52,     0,    72,    54,    55,    56,
       0,     0,    57,     0,     0,    10,    58,    59,    10,     0,
      60,    61,    84,     0,    11,    12,     0,    11,    12,   126,
       0,     0,     0,     0,     0,     0,    16,    17,    36,    16,
      17,    36,    20,     0,     0,    20,    50,    51,    52,     0,
       0,    54,    55,    56,     0,     0,    57,     0,     0,     0,
      58,    59,     0,     0,    60,    61,    50,    51,    52,    62,
       0,    54,    55,    56,     0,     0,    57,     0,     0,     0,
      58,    59,     0,     0,    60,    61,    50,    51,    52,    64,
       0,    54,    55,    56,     0,     0,    57,     0,     0,     0,
      58,    59,     0,     0,    60,    61,    50,    51,    52,   136,
      53,    54,    55,    56,     0,     0,    57,     0,     0,     0,
      58,    59,     0,     0,    60,    61,    50,    51,    52,     0,
     100,    54,    55,    56,     0,     0,    57,     0,     0,     0,
      58,    59,     0,     0,    60,    61,    50,    51,    52,     0,
       0,    54,    55,    56,     0,     0,    57,     0,     0,     0,
      58,    59,     0,     0,    60,    61,    50,    51,    52,     0,
       0,    54,    55,    56,     0,     0,    57,    50,    51,    52,
      58,    59,    54,    55,    56,     0,     0,    57
};

static const yytype_int16 yycheck[] =
{
      13,    37,    75,    38,    39,    14,    35,    33,    14,     7,
      38,     9,    20,    14,    11,    12,    13,    10,    16,    16,
      17,    18,    20,    16,    21,    33,    19,    20,    25,    26,
      39,    37,    29,    30,    33,    63,    37,    37,    31,    32,
      33,     9,    39,    35,    37,    34,    44,    45,    14,    62,
     123,    64,    50,    51,    52,    37,    54,    55,    56,    57,
      58,    59,    60,    61,    33,    93,    12,    13,    35,    12,
      13,    11,    12,    13,    17,    73,    16,    17,    18,    38,
      78,    21,    80,    15,    10,    25,    26,    15,    14,    29,
      30,    13,    10,    19,    20,    22,    14,    95,   111,    39,
      36,    19,    20,    36,   102,    31,    32,    33,    28,   122,
      33,    37,   125,    31,    32,    33,   114,    38,    33,    37,
     118,     0,    36,   136,     3,     4,     5,     6,     7,     8,
       9,    10,    39,    11,    12,    13,    33,    14,    16,    17,
      19,    20,    12,    13,    23,    24,    16,    17,    27,    49,
      19,   139,    31,    32,    33,   102,    35,   115,    37,     3,
       4,     5,     6,     7,     8,     9,    10,     3,     4,     5,
       6,   123,   135,    -1,    -1,    19,    20,    -1,    -1,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,
      -1,    35,    36,    37,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    33,    -1,    35,    -1,    37,    11,
      12,    13,    -1,    -1,    16,    17,    18,    -1,    -1,    21,
      -1,    -1,    -1,    25,    26,    -1,    -1,    29,    30,    -1,
      -1,    -1,    11,    12,    13,    -1,    38,    16,    17,    18,
      -1,    -1,    21,    -1,    -1,    10,    25,    26,    10,    -1,
      29,    30,    17,    -1,    19,    20,    -1,    19,    20,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    31,
      32,    33,    37,    -1,    -1,    37,    11,    12,    13,    -1,
      -1,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    -1,    29,    30,    11,    12,    13,    34,
      -1,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    -1,    29,    30,    11,    12,    13,    34,
      -1,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    -1,    29,    30,    11,    12,    13,    34,
      15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    -1,    29,    30,    11,    12,    13,    -1,
      15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    -1,    29,    30,    11,    12,    13,    -1,
      -1,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    -1,    29,    30,    11,    12,    13,    -1,
      -1,    16,    17,    18,    -1,    -1,    21,    11,    12,    13,
      25,    26,    16,    17,    18,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    19,    20,    23,    24,    27,    31,    32,    33,    35,
      37,    42,    43,    44,    46,    48,    50,    53,    56,    57,
      58,    59,    60,    61,    62,    63,    33,    62,    37,    62,
      61,    33,    33,    62,    14,    37,    41,    62,    20,    33,
      11,    12,    13,    15,    16,    17,    18,    21,    25,    26,
      29,    30,    34,    42,    34,     9,    35,    34,    62,    49,
      62,    36,    38,    14,    45,    37,    45,    62,    14,    62,
      14,    62,    16,    62,    17,    62,    62,    62,    62,    62,
      62,    62,    61,    42,    61,    37,    33,    54,    55,    35,
      15,    38,    39,    62,    15,    43,    51,    52,    15,    62,
      62,    22,    42,    62,    14,    39,    36,    36,    28,    47,
      49,    33,    38,    39,    61,    38,    38,    62,    33,    54,
      62,    36,    61,    52,    61,    39,    34,    33,    55,    61,
      47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    43,    43,    43,    43,    44,
      44,    45,    45,    46,    47,    47,    48,    49,    49,    49,
      50,    51,    51,    51,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    58,    59,    60,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     2,     0,     6,     5,     0,     4,     3,     1,     0,
       6,     3,     1,     0,     2,     5,     5,     3,     1,     5,
       3,     4,     6,     4,     6,     7,     4,     3,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     4,     4,     3,     3,     3,
       3,     2
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
#line 65 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1309 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 71 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1315 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 74 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1321 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 75 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1327 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 76 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1333 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 77 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1339 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 78 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1345 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 79 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1351 "parser.tab.c"
    break;

  case 15: /* TYPE: INT  */
#line 88 "parser.y"
                    { (yyval.str) = "int"; }
#line 1357 "parser.tab.c"
    break;

  case 16: /* TYPE: FLOAT  */
#line 89 "parser.y"
                        { (yyval.str) = "float"; }
#line 1363 "parser.tab.c"
    break;

  case 17: /* TYPE: BOOL  */
#line 90 "parser.y"
                        { (yyval.str) = "bool"; }
#line 1369 "parser.tab.c"
    break;

  case 18: /* TYPE: STRING  */
#line 91 "parser.y"
                         { (yyval.str) = "string"; }
#line 1375 "parser.tab.c"
    break;

  case 19: /* DECLARATION_STT: TYPE IDENTIFIER DECLARATION_TAIL SEMICOLON  */
#line 95 "parser.y"
                                                                     {printf("#[Parsed_Declaration]# "); st_insert((yyvsp[-3].str), (yyvsp[-2].str),0);}
#line 1381 "parser.tab.c"
    break;

  case 20: /* DECLARATION_STT: TYPE CONSTANT DECLARATION_TAIL SEMICOLON  */
#line 96 "parser.y"
                                                                     {printf("#[Parsed_CONST_Declaration]# "); st_insert((yyvsp[-3].str), (yyvsp[-2].str),1); }
#line 1387 "parser.tab.c"
    break;

  case 26: /* FUNC_CALL: IDENTIFIER '(' USED_ARGS ')'  */
#line 113 "parser.y"
                                                        {printf("#[Parsed_Func_Call]# ");}
#line 1393 "parser.tab.c"
    break;

  case 46: /* assignmentSTT: IDENTIFIER EQ EXPRESSION SEMICOLON  */
#line 166 "parser.y"
                                                            {printf("#[Parsed_Assignment]# ");}
#line 1399 "parser.tab.c"
    break;

  case 47: /* BLOCK: '{' PROGRAM '}'  */
#line 170 "parser.y"
                                                           {printf("#[Parsed_Block]# ");}
#line 1405 "parser.tab.c"
    break;


#line 1409 "parser.tab.c"

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

#line 202 "parser.y"



void yyerror(char* s)
{
    fprintf(stderr, "%s\n", s);
};
int yywrap()
{
    return 1;
}
void st_insert(char* data_type, char* name, int is_const){
    //create new entry
    struct Entry newEntry ;
    newEntry.name = "test";
    newEntry.dataType = data_type;
    symbolTable[st_index] = newEntry;
    st_index++;
    // print with new line

    printf(data_type);
    printf(name);
   
}
void st_print() {
    // write symbol table to file
    FILE *fp = fopen("/symbol_table.txt", "w");
    if(fp == NULL) {
        printf("can't open symbol_table.txt file!\n");
        exit(1);
    }
    // fprintf(fp, "\nName\tData Type\tScope\tType\tLine\n");
    fprintf(fp, "\nData Type\n");

    for(int i=0; i<st_index; i++) {
        struct Entry *entry = &symbolTable[i];
        fprintf(fp, "%s\n", entry->dataType);
        // fprintf(fp, "%4s\t%9s\t%5d\t%4c\t%4d\t%3d\t%10d\n", entry->name, entry->dataType, entry->token_scope, entry->type, entry->declareLine); 
    }
}

int main(int argc, char *argv[])
{ 
    yyin = fopen(argv[1], "r");
    yyparse();
    st_print();
    return 0;
}
