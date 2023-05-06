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
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_PROGRAM = 43,                   /* PROGRAM  */
  YYSYMBOL_STATEMENT = 44,                 /* STATEMENT  */
  YYSYMBOL_TYPE = 45,                      /* TYPE  */
  YYSYMBOL_DECLARATION_STT = 46,           /* DECLARATION_STT  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_DECLARATION_TAIL = 49,          /* DECLARATION_TAIL  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_52_5 = 52,                      /* $@5  */
  YYSYMBOL_SWITCH_STT = 53,                /* SWITCH_STT  */
  YYSYMBOL_CASES = 54,                     /* CASES  */
  YYSYMBOL_ERRONOUS_CASES = 55,            /* ERRONOUS_CASES  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_57_7 = 57,                      /* $@7  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 58,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_59_8 = 59,                      /* $@8  */
  YYSYMBOL_60_9 = 60,                      /* $@9  */
  YYSYMBOL_61_10 = 61,                     /* $@10  */
  YYSYMBOL_62_11 = 62,                     /* $@11  */
  YYSYMBOL_FUNC_CALL = 63,                 /* FUNC_CALL  */
  YYSYMBOL_USED_ARGS = 64,                 /* USED_ARGS  */
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
  YYSYMBOL_ENUM_ARGS = 80,                 /* ENUM_ARGS  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 81,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_IF_STT = 82,                    /* IF_STT  */
  YYSYMBOL_WHILE_STT = 83,                 /* WHILE_STT  */
  YYSYMBOL_DO_WHILE_STT = 84,              /* DO_WHILE_STT  */
  YYSYMBOL_FOR_STT = 85,                   /* FOR_STT  */
  YYSYMBOL_86_21 = 86,                     /* $@21  */
  YYSYMBOL_87_22 = 87,                     /* $@22  */
  YYSYMBOL_assignmentSTT = 88,             /* assignmentSTT  */
  YYSYMBOL_BLOCK = 89,                     /* BLOCK  */
  YYSYMBOL_90_23 = 90,                     /* $@23  */
  YYSYMBOL_91_24 = 91,                     /* $@24  */
  YYSYMBOL_EXPRESSION = 92,                /* EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 93,             /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 94,    /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 95                   /* RES_WORD  */
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
#define YYLAST   1076

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  292

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
       2,     2,     2,     2,     2,     2,     2,     2,    38,     2,
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
       0,    98,    98,    99,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   124,   125,
     126,   127,   131,   131,   132,   132,   133,   134,   135,   140,
     141,   142,   143,   144,   144,   145,   145,   146,   146,   148,
     156,   157,   162,   163,   164,   168,   168,   169,   169,   173,
     173,   174,   174,   175,   175,   176,   176,   187,   188,   192,
     193,   194,   195,   202,   203,   203,   204,   204,   205,   205,
     206,   206,   210,   210,   211,   212,   212,   213,   214,   214,
     215,   215,   216,   216,   220,   221,   222,   225,   228,   238,
     239,   242,   243,   246,   247,   255,   256,   257,   262,   267,
     272,   272,   272,   277,   282,   282,   282,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347
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
  "$accept", "PROGRAM", "STATEMENT", "TYPE", "DECLARATION_STT", "$@1",
  "$@2", "DECLARATION_TAIL", "$@3", "$@4", "$@5", "SWITCH_STT", "CASES",
  "ERRONOUS_CASES", "$@6", "$@7", "ERRONOUS_SWITCH_STT", "$@8", "$@9",
  "$@10", "$@11", "FUNC_CALL", "USED_ARGS", "FUNC_DECLARATION_STT", "$@12",
  "$@13", "$@14", "$@15", "ERRONOUS_FUNC_DECLARATION_STT", "$@16", "$@17",
  "$@18", "$@19", "$@20", "ARGS", "ERRONOUS_ARGS", "ARG_DECL",
  "ENUM_DECLARATION_STT", "ENUM_ARGS", "ENUM_DEFINED_ARGS", "IF_STT",
  "WHILE_STT", "DO_WHILE_STT", "FOR_STT", "$@21", "$@22", "assignmentSTT",
  "BLOCK", "$@23", "$@24", "EXPRESSION", "COMPARISONSTT",
  "ERRONOUS_COMPARISONSTT", "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-189)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-123)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -189,   199,  -189,   917,  -189,  -189,  -189,  -189,   -22,   518,
     -19,   535,  -189,  -189,  -189,    14,    23,    18,   553,  -189,
     376,  -189,  -189,   535,  -189,    -1,  -189,  -189,  -189,  -189,
    -189,    14,  -189,  -189,  -189,  -189,  -189,  -189,  -189,   943,
    -189,  -189,   215,   398,  -189,    53,   535,   535,   535,   535,
      63,  -189,  -189,    15,   410,   266,   535,   768,  -189,   790,
      76,    49,  -189,     4,    79,  1054,    59,   535,   414,  -189,
     856,  -189,    16,  -189,   535,   441,   457,  -189,   482,   500,
     535,   535,   570,   588,   605,   623,   535,    97,   535,    91,
    -189,  1054,  1054,  1043,  1043,  -189,  -189,    24,    98,   877,
      14,   347,    14,    50,    82,    84,    81,     7,  -189,   963,
     370,    96,   153,   307,  -189,    21,   116,    78,    21,    98,
     168,    79,   640,    97,   121,   658,    91,  -189,   150,  -189,
      97,    95,  1054,    79,  1054,    79,  1054,   124,  1043,   124,
    1043,    97,    97,   102,  -189,    98,   112,   -13,  -189,   115,
      99,   699,   151,   347,  -189,   535,     3,   137,   140,   139,
     152,   149,  -189,    62,  -189,   414,  -189,   414,  -189,   120,
     675,  -189,  -189,  -189,   157,  -189,     6,  -189,   154,    79,
      97,   121,    97,    98,    14,  -189,  -189,  -189,  -189,    98,
    -189,   162,    14,   347,   898,   535,   155,  -189,  -189,    62,
     172,    62,    62,   535,   535,   156,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,   983,  -189,
    -189,  -189,  -189,  -189,  1003,  -189,   227,   835,    98,    14,
    -189,  -189,  -189,  -189,   175,  -189,    14,  -189,  -189,  -189,
     176,  -189,   721,   174,  -189,   181,    62,   182,   186,  1023,
     812,  -189,  -189,  -189,  -189,   189,   191,   750,   192,  -189,
     200,    14,  -189,  -189,  -189,   159,  -189,   206,  -189,  -189,
     207,     8,  -189,  -189,  -189,  -189,  -189,  -189,  -189,    14,
     229,  -189,  -189,    14,  -189,    62,  -189,    62,    62,  -189,
    -189,  -189
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    18,    19,    20,    21,     0,     0,
       0,     0,   110,   111,   112,     0,     0,     0,     0,   108,
       0,   109,   104,     0,     2,     0,     4,    12,    41,   121,
       5,     0,    13,     8,     9,    11,    10,     6,    14,     0,
     120,   132,     0,     0,    15,     0,     0,     0,     0,     0,
       0,    16,    17,    75,     0,     0,     0,     0,   100,     0,
       0,     0,    49,     0,   141,   131,     0,     0,     0,     3,
       0,    24,    72,    63,     0,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   133,     0,   135,
      27,   137,   139,   142,   144,    26,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    58,     0,
       0,     0,    61,     0,   122,     0,    78,     0,     0,     0,
     118,   134,     0,   123,   136,     0,   124,   113,   115,   114,
     116,   117,   119,   138,   127,   140,   128,   143,   129,   145,
     130,   148,   146,     0,    70,     0,     0,     0,    86,    85,
       0,     0,    95,     0,    98,     0,    92,     0,     0,     0,
       0,     0,    55,     0,   103,     0,    57,     0,   105,     0,
       0,    32,    25,    28,     0,    68,     0,    23,     0,   149,
     126,   147,   125,     0,     0,    87,    88,    66,    77,     0,
      76,     0,     0,     0,     0,     0,     0,    89,    90,     0,
       0,     0,     0,     0,     0,     0,    43,    60,    59,   106,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,    39,     0,    37,     0,     0,
      82,    64,    74,    73,     0,    71,     0,    84,    97,    96,
       0,    99,    94,    92,    91,     0,     0,     0,     0,    45,
       0,    40,    30,    31,    29,     0,     0,     0,     0,    69,
       0,     0,    81,    67,   101,     0,    50,     0,    54,    56,
       0,     0,    34,    36,   158,    38,    79,    83,    65,     0,
       0,    93,    52,     0,    47,     0,   102,     0,     0,    42,
      46,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,   183,   -99,     5,  -189,  -189,  -189,   133,  -189,  -189,
    -189,  -189,  -188,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -103,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,   -94,  -189,  -189,  -189,    64,    -6,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,   -15,  -189,  -189,
      -8,  -189,  -189,     9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    24,   146,    26,   118,   115,   172,   255,   256,
     257,    27,   205,   206,   270,   288,    28,   105,   160,   161,
     202,    29,   111,    30,   261,   236,   229,   184,    31,   119,
      98,   174,   143,   260,   147,   148,   149,    32,   157,   158,
      33,    34,    35,    36,   101,   279,    37,    38,    69,   209,
      39,    40,    41,   225
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    57,   153,    59,   150,   106,    25,   230,   162,   284,
      65,   245,    53,   247,   248,    70,    73,   -22,   195,    62,
      71,    58,   169,   176,   187,   178,   188,     4,     5,     6,
       7,   -22,   -22,    72,    87,    89,   170,   171,    91,    92,
      93,    94,   107,   231,   196,   232,   163,    22,    99,    96,
     116,   185,    63,    22,   193,    97,   117,    61,   267,   109,
     112,   144,   207,   203,   208,   145,   120,   123,   126,    90,
     128,   130,   131,   132,   134,   136,   138,   140,   141,    95,
     142,     4,     5,     6,     7,   152,   103,   154,   104,   234,
     155,   204,    42,    43,   240,   237,   108,   289,   -44,   290,
     291,     4,     5,     6,     7,    76,    25,    74,    75,    76,
      75,    76,    78,    79,   180,   175,   156,   182,    25,   145,
     -53,    54,   159,   210,   211,   212,   213,   214,   215,   216,
     217,    12,   173,   166,   258,    43,   190,    42,    43,   145,
      13,   218,   183,   219,   220,   221,   186,   194,   222,   223,
      46,    47,    18,    19,    55,    21,   189,   112,    25,   112,
      23,   224,   227,    75,    76,    74,    75,    76,    79,   235,
      78,    79,    80,   197,   192,    81,   198,   239,   199,    82,
      83,    75,    76,    84,    85,    78,    79,   242,   201,   243,
     200,   233,   251,   280,   167,   249,   250,   228,    25,     2,
       3,   238,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   246,   262,   264,   259,   196,    54,   266,   268,    13,
      14,   263,   269,    15,    16,   272,    12,    17,   273,   276,
      86,    18,    19,    20,    21,    13,    14,   277,    22,    23,
      42,    43,   282,   253,   195,   283,   278,    18,    19,    55,
      21,   177,   113,    46,    47,    23,   285,    48,    49,   281,
     244,     0,     0,     0,   286,     0,   275,    66,   287,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,     0,  -107,  -107,
    -107,     0,  -107,  -107,  -107,  -107,     0,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,     0,     0,
       0,     0,  -107,  -107,  -107,     0,    68,  -107,     3,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
       0,    15,    16,     0,     0,    17,     0,     0,     0,    18,
      19,    20,    21,   168,     0,     0,    22,    23,     3,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
       0,    15,    16,     0,     0,    17,     0,    66,     0,    18,
      19,    20,    21,    42,    43,     0,    22,    23,  -107,  -107,
    -107,    67,  -107,  -107,  -107,  -107,    46,    47,  -107,    54,
      48,    49,  -107,  -107,     0,     0,  -107,  -107,     0,    12,
       0,   165,     0,    88,     0,   110,    68,     0,    13,    14,
       0,     0,     0,    42,    43,    12,     0,     0,     0,     0,
      18,    19,    55,    21,    13,    14,    46,    47,    23,     0,
      48,    49,   121,     0,     0,     0,    18,    19,    55,    21,
       0,   -62,    12,     0,    23,     0,   122,     0,   124,     0,
       0,    13,    14,     0,     0,     0,     0,     0,    12,     0,
       0,     0,   125,    18,    19,    55,    21,    13,    14,     0,
       0,    23,     0,    54,     0,     0,     0,     0,     0,    18,
      19,    55,    21,    12,     0,     0,     0,    23,     0,   127,
       0,    54,    13,    14,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,    18,    19,    55,    21,   129,    54,
      13,    14,    23,     0,     0,     0,     0,     0,     0,    12,
       0,     0,    18,    19,    55,    21,    54,     0,    13,    14,
      23,     0,     0,     0,     0,     0,    12,     0,     0,     0,
      18,    19,    55,    21,    64,    13,    14,     0,    56,     0,
       0,     0,     0,     0,    12,     0,     0,    18,    19,    55,
      21,   133,     0,    13,    14,    23,     0,     0,     0,     0,
       0,    12,     0,     0,     0,    18,    19,    55,    21,   135,
      13,    14,     0,    23,     0,     0,     0,     0,     0,    12,
       0,     0,    18,    19,    55,    21,   137,     0,    13,    14,
      23,     0,     0,     0,     0,     0,    12,     0,     0,     0,
      18,    19,    55,    21,   139,    13,    14,     0,    23,     0,
       0,     0,     0,     0,    12,     0,     0,    18,    19,    55,
      21,   179,     0,    13,    14,    23,     0,     0,     0,     0,
       0,    12,     0,     0,     0,    18,    19,    55,    21,   181,
      13,    14,     0,    23,     0,     0,     0,     0,     0,    12,
       0,     0,    18,    19,    55,    21,   226,     0,    13,    14,
      23,     0,     0,     0,     0,     0,    12,     0,     0,     0,
      18,    19,    55,    21,     0,    13,    14,     0,    23,     0,
     191,     0,     0,     0,     0,     0,     0,    18,    19,    55,
      21,  -122,  -122,  -122,     0,    23,  -122,  -122,  -122,     0,
       0,  -122,     0,     0,     0,  -122,  -122,     0,     0,  -122,
    -122,     0,     0,    74,    75,    76,     0,  -122,    78,    79,
      80,     0,     0,    81,     0,     0,     0,    82,    83,     0,
       0,    84,    85,   210,   211,   212,   213,   214,   215,   216,
     217,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,   274,     0,   219,   220,   221,     0,     0,   222,   223,
      74,    75,    76,     0,     0,    78,    79,    80,     0,     0,
      81,     0,     0,     0,    82,    83,     0,     0,    84,    85,
       0,     0,    74,    75,    76,     0,   100,    78,    79,    80,
       0,     0,    81,     0,     0,     0,    82,    83,     0,     0,
      84,    85,     0,     0,    74,    75,    76,     0,   102,    78,
      79,    80,     0,     0,    81,     0,     0,     0,    82,    83,
       0,     0,    84,    85,     0,     0,     0,    74,    75,    76,
     271,   254,    78,    79,    80,     0,     0,    81,     0,     0,
       0,    82,    83,     0,     0,    84,    85,     0,    74,    75,
      76,   -33,   -35,    78,    79,    80,     0,     0,    81,     0,
       0,     0,    82,    83,     0,     0,    84,    85,     0,    74,
      75,    76,     0,   114,    78,    79,    80,     0,     0,    81,
       0,     0,     0,    82,    83,     0,     0,    84,    85,     0,
      74,    75,    76,     0,   151,    78,    79,    80,     0,     0,
      81,     0,     0,     0,    82,    83,     0,     0,    84,    85,
      42,    43,     0,    44,     0,   241,     0,     0,    45,     0,
       0,     0,     0,    46,    47,     0,     0,    48,    49,     0,
       0,    50,     0,    51,    52,    74,    75,    76,     0,    77,
      78,    79,    80,     0,     0,    81,     0,     0,     0,    82,
      83,     0,     0,    84,    85,    74,    75,    76,     0,   164,
      78,    79,    80,     0,     0,    81,     0,     0,     0,    82,
      83,     0,     0,    84,    85,  -112,  -112,  -112,     0,  -112,
    -112,  -112,  -112,     0,     0,  -112,     0,     0,     0,  -112,
    -112,     0,     0,  -112,  -112,    74,    75,    76,     0,   252,
      78,    79,    80,     0,     0,    81,     0,     0,     0,    82,
      83,     0,     0,    84,    85,    74,    75,    76,     0,     0,
      78,    79,    80,     0,     0,    81,     0,     0,     0,    82,
      83,     0,     0,    84,    85,    74,    75,    76,     0,     0,
      78,    79,    80,     0,     0,    81,    74,    75,    76,    82,
      83,    78,    79,    80,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
      15,     9,   101,    11,    98,     1,     1,     1,     1,     1,
      18,   199,    34,   201,   202,    23,    31,     1,    15,     1,
      21,    40,     1,   117,    37,   119,    39,     3,     4,     5,
       6,    15,    16,    34,    42,    43,    15,    16,    46,    47,
      48,    49,    38,    37,    41,    39,    39,    39,    56,    34,
      34,   145,    34,    39,   153,    40,    40,    34,   246,    67,
      68,    37,   165,     1,   167,    41,    74,    75,    76,    16,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    16,
      88,     3,     4,     5,     6,   100,    10,   102,    39,   183,
      40,    29,    13,    14,   193,   189,    37,   285,    36,   287,
     288,     3,     4,     5,     6,    14,   101,    12,    13,    14,
      13,    14,    17,    18,   122,    37,    34,   125,   113,    41,
      39,     1,    38,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    16,    37,   228,    14,    37,    13,    14,    41,
      20,    21,    40,    23,    24,    25,    34,   155,    28,    29,
      26,    27,    32,    33,    34,    35,    41,   165,   153,   167,
      40,   169,   170,    13,    14,    12,    13,    14,    18,   184,
      17,    18,    19,    36,    23,    22,    36,   192,    39,    26,
      27,    13,    14,    30,    31,    17,    18,   195,    39,    34,
      38,    37,    36,    34,    41,   203,   204,    40,   193,     0,
       1,    39,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    39,    37,    37,   229,    41,     1,    36,    36,    20,
      21,   236,    36,    24,    25,    36,    11,    28,    37,    37,
      15,    32,    33,    34,    35,    20,    21,    37,    39,    40,
      13,    14,    36,    16,    15,    38,   261,    32,    33,    34,
      35,   118,    69,    26,    27,    40,   271,    30,    31,   265,
     196,    -1,    -1,    -1,   279,    -1,   257,     1,   283,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,
      -1,    24,    25,    -1,    -1,    28,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    39,    40,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,
      -1,    24,    25,    -1,    -1,    28,    -1,     1,    -1,    32,
      33,    34,    35,    13,    14,    -1,    39,    40,    12,    13,
      14,    15,    16,    17,    18,    19,    26,    27,    22,     1,
      30,    31,    26,    27,    -1,    -1,    30,    31,    -1,    11,
      -1,    41,    -1,    15,    -1,     1,    40,    -1,    20,    21,
      -1,    -1,    -1,    13,    14,    11,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    20,    21,    26,    27,    40,    -1,
      30,    31,     1,    -1,    -1,    -1,    32,    33,    34,    35,
      -1,    37,    11,    -1,    40,    -1,    15,    -1,     1,    -1,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    15,    32,    33,    34,    35,    20,    21,    -1,
      -1,    40,    -1,     1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    11,    -1,    -1,    -1,    40,    -1,    17,
      -1,     1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    32,    33,    34,    35,    18,     1,
      20,    21,    40,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    32,    33,    34,    35,     1,    -1,    20,    21,
      40,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      32,    33,    34,    35,     1,    20,    21,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    32,    33,    34,
      35,     1,    -1,    20,    21,    40,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    32,    33,    34,    35,     1,
      20,    21,    -1,    40,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    32,    33,    34,    35,     1,    -1,    20,    21,
      40,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      32,    33,    34,    35,     1,    20,    21,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    32,    33,    34,
      35,     1,    -1,    20,    21,    40,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    32,    33,    34,    35,     1,
      20,    21,    -1,    40,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    32,    33,    34,    35,     1,    -1,    20,    21,
      40,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      32,    33,    34,    35,    -1,    20,    21,    -1,    40,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    12,    13,    14,    -1,    40,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,
      31,    -1,    -1,    12,    13,    14,    -1,    38,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    23,    24,    25,    -1,    -1,    28,    29,
      12,    13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      -1,    -1,    12,    13,    14,    -1,    38,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    -1,    -1,    12,    13,    14,    -1,    38,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    -1,    -1,    -1,    12,    13,    14,
      38,    16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    12,    13,
      14,    36,    37,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,    12,
      13,    14,    -1,    37,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,
      12,    13,    14,    -1,    37,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      13,    14,    -1,    16,    -1,    37,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,
      -1,    34,    -1,    36,    37,    12,    13,    14,    -1,    16,
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
      17,    18,    19,    -1,    -1,    22,    12,    13,    14,    26,
      27,    17,    18,    19,    -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    20,    21,    24,    25,    28,    32,    33,
      34,    35,    39,    40,    44,    45,    46,    53,    58,    63,
      65,    70,    79,    82,    83,    84,    85,    88,    89,    92,
      93,    94,    13,    14,    16,    21,    26,    27,    30,    31,
      34,    36,    37,    34,     1,    34,    40,    92,    40,    92,
      89,    34,     1,    34,     1,    92,     1,    15,    40,    90,
      92,    21,    34,    89,    12,    13,    14,    16,    17,    18,
      19,    22,    26,    27,    30,    31,    15,    92,    15,    92,
      16,    92,    92,    92,    92,    16,    34,    40,    72,    92,
      38,    86,    38,    10,    39,    59,     1,    38,    37,    92,
       1,    64,    92,    43,    37,    48,    34,    40,    47,    71,
      92,     1,    15,    92,     1,    15,    92,    17,    92,    18,
      92,    92,    92,     1,    92,     1,    92,     1,    92,     1,
      92,    92,    92,    74,    37,    41,    45,    76,    77,    78,
      76,    37,    89,    44,    89,    40,    34,    80,    81,    38,
      60,    61,     1,    39,    16,    41,    37,    41,    36,     1,
      15,    16,    49,    16,    73,    37,    76,    49,    76,     1,
      92,     1,    92,    40,    69,    76,    34,    37,    39,    41,
      37,     1,    23,    44,    92,    15,    41,    36,    36,    39,
      38,    39,    62,     1,    29,    54,    55,    64,    64,    91,
       3,     4,     5,     6,     7,     8,     9,    10,    21,    23,
      24,    25,    28,    29,    92,    95,     1,    92,    40,    68,
       1,    37,    39,    37,    76,    89,    67,    76,    39,    89,
      44,    37,    92,    34,    80,    54,    39,    54,    54,    92,
      92,    36,    16,    16,    16,    50,    51,    52,    76,    89,
      75,    66,    37,    89,    37,    41,    36,    54,    36,    36,
      56,    38,    36,    37,    21,    95,    37,    37,    89,    87,
      34,    81,    36,    38,     1,    89,    89,    89,    57,    54,
      54,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    45,    45,
      45,    45,    47,    46,    48,    46,    46,    46,    46,    49,
      49,    49,    49,    50,    49,    51,    49,    52,    49,    49,
      53,    53,    54,    54,    54,    56,    55,    57,    55,    59,
      58,    60,    58,    61,    58,    62,    58,    63,    63,    64,
      64,    64,    64,    65,    66,    65,    67,    65,    68,    65,
      69,    65,    71,    70,    70,    72,    70,    70,    73,    70,
      74,    70,    75,    70,    76,    76,    76,    77,    78,    79,
      79,    80,    80,    81,    81,    82,    82,    82,    83,    84,
      86,    87,    85,    88,    90,    91,    89,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     0,     4,     0,     4,     3,     3,     4,     3,
       3,     3,     1,     0,     4,     0,     4,     0,     4,     2,
       6,     1,     5,     1,     0,     0,     6,     0,     6,     0,
       7,     0,     8,     0,     7,     0,     7,     4,     3,     3,
       3,     1,     0,     2,     0,     7,     0,     7,     0,     6,
       0,     6,     0,     5,     5,     0,     5,     5,     0,     7,
       0,     7,     0,     7,     3,     1,     1,     2,     2,     5,
       5,     3,     1,     5,     3,     4,     6,     6,     4,     6,
       0,     0,     9,     4,     0,     0,     5,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     4,     4,     3,     3,     3,
       3,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     4,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 98 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1568 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 104 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1574 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 107 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1580 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 108 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1586 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 109 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1592 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 110 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1598 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 111 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1604 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 112 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1610 "parser.tab.c"
    break;

  case 15: /* STATEMENT: error SEMICOLON  */
#line 114 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1616 "parser.tab.c"
    break;

  case 16: /* STATEMENT: error '}'  */
#line 115 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1622 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error ')'  */
#line 116 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1628 "parser.tab.c"
    break;

  case 18: /* TYPE: INT  */
#line 124 "parser.y"
                    { (yyval.str) = "int"; }
#line 1634 "parser.tab.c"
    break;

  case 19: /* TYPE: FLOAT  */
#line 125 "parser.y"
                        { (yyval.str) = "float"; }
#line 1640 "parser.tab.c"
    break;

  case 20: /* TYPE: BOOL  */
#line 126 "parser.y"
                        { (yyval.str) = "bool"; }
#line 1646 "parser.tab.c"
    break;

  case 21: /* TYPE: STRING  */
#line 127 "parser.y"
                         { (yyval.str) = "string"; }
#line 1652 "parser.tab.c"
    break;

  case 22: /* $@1: %empty  */
#line 131 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0); }
#line 1658 "parser.tab.c"
    break;

  case 23: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 131 "parser.y"
                                                                                            {printf("#[Parsed_Declaration]# ");}
#line 1664 "parser.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 132 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0);}
#line 1670 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 132 "parser.y"
                                                                                            {printf("#[Parsed_CONST_Declaration]# "); }
#line 1676 "parser.tab.c"
    break;

  case 26: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 133 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1682 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 134 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1688 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 135 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);}
#line 1694 "parser.tab.c"
    break;

  case 30: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 141 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1700 "parser.tab.c"
    break;

  case 31: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 142 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1706 "parser.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 144 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); yyclearin; yyclearin;}
#line 1712 "parser.tab.c"
    break;

  case 35: /* $@4: %empty  */
#line 145 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); yyclearin; yyclearin;}
#line 1718 "parser.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 146 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); yyclearin; yyclearin;}
#line 1724 "parser.tab.c"
    break;

  case 39: /* DECLARATION_TAIL: error RES_WORD  */
#line 148 "parser.y"
                                                                                           {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);}
#line 1730 "parser.tab.c"
    break;

  case 45: /* $@6: %empty  */
#line 168 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);}
#line 1736 "parser.tab.c"
    break;

  case 47: /* $@7: %empty  */
#line 169 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);}
#line 1742 "parser.tab.c"
    break;

  case 49: /* $@8: %empty  */
#line 173 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1748 "parser.tab.c"
    break;

  case 51: /* $@9: %empty  */
#line 174 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }
#line 1754 "parser.tab.c"
    break;

  case 53: /* $@10: %empty  */
#line 175 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1760 "parser.tab.c"
    break;

  case 55: /* $@11: %empty  */
#line 176 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1766 "parser.tab.c"
    break;

  case 57: /* FUNC_CALL: IDENTIFIER '(' USED_ARGS ')'  */
#line 187 "parser.y"
                                                        {printf("#[Parsed_Func_Call]# ");}
#line 1772 "parser.tab.c"
    break;

  case 58: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 188 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 1778 "parser.tab.c"
    break;

  case 60: /* USED_ARGS: error ',' USED_ARGS  */
#line 193 "parser.y"
                                                        {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 1784 "parser.tab.c"
    break;

  case 64: /* $@12: %empty  */
#line 203 "parser.y"
                                                 {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1790 "parser.tab.c"
    break;

  case 66: /* $@13: %empty  */
#line 204 "parser.y"
                                                 {st_insert("void", (yyvsp[-3].str),"func",0);}
#line 1796 "parser.tab.c"
    break;

  case 68: /* $@14: %empty  */
#line 205 "parser.y"
                                                 {st_insert((yyvsp[-3].str), (yyvsp[-2].str),"func",0);}
#line 1802 "parser.tab.c"
    break;

  case 70: /* $@15: %empty  */
#line 206 "parser.y"
                                                 {st_insert("void", (yyvsp[-2].str),"func",0);}
#line 1808 "parser.tab.c"
    break;

  case 72: /* $@16: %empty  */
#line 210 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1814 "parser.tab.c"
    break;

  case 73: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@16 ARGS ')'  */
#line 210 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1820 "parser.tab.c"
    break;

  case 74: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS '{'  */
#line 211 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1826 "parser.tab.c"
    break;

  case 75: /* $@17: %empty  */
#line 212 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1832 "parser.tab.c"
    break;

  case 76: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER $@17 ARGS ')'  */
#line 212 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1838 "parser.tab.c"
    break;

  case 77: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER '(' ARGS '{'  */
#line 213 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1844 "parser.tab.c"
    break;

  case 78: /* $@18: %empty  */
#line 214 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1850 "parser.tab.c"
    break;

  case 79: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER $@18 '(' ARGS ')'  */
#line 214 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1856 "parser.tab.c"
    break;

  case 80: /* $@19: %empty  */
#line 215 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1862 "parser.tab.c"
    break;

  case 81: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER IDENTIFIER $@19 '(' ARGS ')'  */
#line 215 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1868 "parser.tab.c"
    break;

  case 82: /* $@20: %empty  */
#line 216 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected token '%s' in argument list of function declaration at line %d\n\n", yylval, yylineno);}
#line 1874 "parser.tab.c"
    break;

  case 83: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS error $@20 ')'  */
#line 216 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1880 "parser.tab.c"
    break;

  case 87: /* ERRONOUS_ARGS: ',' ARGS  */
#line 225 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
#line 1886 "parser.tab.c"
    break;

  case 88: /* ARG_DECL: TYPE IDENTIFIER  */
#line 228 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1);}
#line 1892 "parser.tab.c"
    break;

  case 89: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_ARGS '}'  */
#line 238 "parser.y"
                                                            { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 1898 "parser.tab.c"
    break;

  case 90: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_DEFINED_ARGS '}'  */
#line 239 "parser.y"
                                                            { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 1904 "parser.tab.c"
    break;

  case 97: /* IF_STT: IF '(' EXPRESSION ')' error '{'  */
#line 257 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 1910 "parser.tab.c"
    break;

  case 100: /* $@21: %empty  */
#line 272 "parser.y"
                        {in_loop = 1;}
#line 1916 "parser.tab.c"
    break;

  case 101: /* $@22: %empty  */
#line 272 "parser.y"
                                                                        {in_loop = 0;}
#line 1922 "parser.tab.c"
    break;

  case 103: /* assignmentSTT: IDENTIFIER EQ EXPRESSION SEMICOLON  */
#line 277 "parser.y"
                                                            {printf("#[Parsed_Assignment]# ");}
#line 1928 "parser.tab.c"
    break;

  case 104: /* $@23: %empty  */
#line 282 "parser.y"
                    {scope_start();}
#line 1934 "parser.tab.c"
    break;

  case 105: /* $@24: %empty  */
#line 282 "parser.y"
                                                 {scope_end();}
#line 1940 "parser.tab.c"
    break;

  case 106: /* BLOCK: '{' $@23 PROGRAM '}' $@24  */
#line 282 "parser.y"
                                                                                    {printf("#[Parsed_Block]# ");}
#line 1946 "parser.tab.c"
    break;

  case 108: /* EXPRESSION: DIGIT  */
#line 289 "parser.y"
                        { symbolTable[st_index-1].intValue= (yyvsp[0].num) ;}
#line 1952 "parser.tab.c"
    break;

  case 109: /* EXPRESSION: FLOAT_DIGIT  */
#line 290 "parser.y"
                              { symbolTable[st_index-1].floatValue= (yyvsp[0].float_val) ;}
#line 1958 "parser.tab.c"
    break;

  case 110: /* EXPRESSION: BOOL_LITERAL  */
#line 291 "parser.y"
                                { symbolTable[st_index-1].boolValue= (yyvsp[0].bool_val) ;}
#line 1964 "parser.tab.c"
    break;

  case 111: /* EXPRESSION: STRING_LITERAL  */
#line 292 "parser.y"
                                  { symbolTable[st_index-1].strValue= (yyvsp[0].str) ;}
#line 1970 "parser.tab.c"
    break;

  case 133: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 323 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 1976 "parser.tab.c"
    break;

  case 134: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 324 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 1982 "parser.tab.c"
    break;

  case 135: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 325 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 1988 "parser.tab.c"
    break;

  case 136: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 326 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 1994 "parser.tab.c"
    break;

  case 137: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 327 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 2000 "parser.tab.c"
    break;

  case 138: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 328 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 2006 "parser.tab.c"
    break;

  case 139: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 329 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 2012 "parser.tab.c"
    break;

  case 140: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 330 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 2018 "parser.tab.c"
    break;

  case 141: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 331 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 2024 "parser.tab.c"
    break;

  case 142: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 332 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 2030 "parser.tab.c"
    break;

  case 143: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 333 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 2036 "parser.tab.c"
    break;

  case 144: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 334 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 2042 "parser.tab.c"
    break;

  case 145: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 335 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 2048 "parser.tab.c"
    break;

  case 146: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 336 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 2054 "parser.tab.c"
    break;

  case 147: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 337 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 2060 "parser.tab.c"
    break;

  case 148: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 338 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 2066 "parser.tab.c"
    break;

  case 149: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 339 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 2072 "parser.tab.c"
    break;


#line 2076 "parser.tab.c"

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

#line 358 "parser.y"




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
