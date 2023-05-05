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
  YYSYMBOL_SWITCH_STT = 50,                /* SWITCH_STT  */
  YYSYMBOL_CASES = 51,                     /* CASES  */
  YYSYMBOL_ERRONOUS_CASES = 52,            /* ERRONOUS_CASES  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 55,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_56_5 = 56,                      /* $@5  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_59_8 = 59,                      /* $@8  */
  YYSYMBOL_FUNC_CALL = 60,                 /* FUNC_CALL  */
  YYSYMBOL_USED_ARGS = 61,                 /* USED_ARGS  */
  YYSYMBOL_FUNC_DECLARATION_STT = 62,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_65_11 = 65,                     /* $@11  */
  YYSYMBOL_66_12 = 66,                     /* $@12  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 67, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_68_13 = 68,                     /* $@13  */
  YYSYMBOL_69_14 = 69,                     /* $@14  */
  YYSYMBOL_70_15 = 70,                     /* $@15  */
  YYSYMBOL_71_16 = 71,                     /* $@16  */
  YYSYMBOL_72_17 = 72,                     /* $@17  */
  YYSYMBOL_ARGS = 73,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 74,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 75,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 76,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_ARGS = 77,                 /* ENUM_ARGS  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 78,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_IF_STT = 79,                    /* IF_STT  */
  YYSYMBOL_WHILE_STT = 80,                 /* WHILE_STT  */
  YYSYMBOL_DO_WHILE_STT = 81,              /* DO_WHILE_STT  */
  YYSYMBOL_FOR_STT = 82,                   /* FOR_STT  */
  YYSYMBOL_83_18 = 83,                     /* $@18  */
  YYSYMBOL_84_19 = 84,                     /* $@19  */
  YYSYMBOL_assignmentSTT = 85,             /* assignmentSTT  */
  YYSYMBOL_BLOCK = 86,                     /* BLOCK  */
  YYSYMBOL_87_20 = 87,                     /* $@20  */
  YYSYMBOL_88_21 = 88,                     /* $@21  */
  YYSYMBOL_EXPRESSION = 89,                /* EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 90,             /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 91     /* ERRONOUS_COMPARISONSTT  */
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
#define YYLAST   967

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

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
     109,   110,   111,   112,   113,   114,   115,   116,   125,   126,
     127,   128,   132,   132,   133,   133,   134,   135,   140,   141,
     142,   143,   151,   152,   157,   158,   159,   163,   163,   164,
     164,   168,   168,   169,   169,   170,   170,   171,   171,   182,
     183,   187,   188,   189,   190,   197,   198,   198,   199,   199,
     200,   200,   201,   201,   205,   205,   206,   207,   207,   208,
     209,   209,   210,   210,   211,   211,   215,   216,   217,   220,
     223,   233,   234,   237,   238,   241,   242,   250,   251,   252,
     257,   262,   267,   267,   267,   272,   277,   277,   277,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334
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
  "$@2", "DECLARATION_TAIL", "SWITCH_STT", "CASES", "ERRONOUS_CASES",
  "$@3", "$@4", "ERRONOUS_SWITCH_STT", "$@5", "$@6", "$@7", "$@8",
  "FUNC_CALL", "USED_ARGS", "FUNC_DECLARATION_STT", "$@9", "$@10", "$@11",
  "$@12", "ERRONOUS_FUNC_DECLARATION_STT", "$@13", "$@14", "$@15", "$@16",
  "$@17", "ARGS", "ERRONOUS_ARGS", "ARG_DECL", "ENUM_DECLARATION_STT",
  "ENUM_ARGS", "ENUM_DEFINED_ARGS", "IF_STT", "WHILE_STT", "DO_WHILE_STT",
  "FOR_STT", "$@18", "$@19", "assignmentSTT", "BLOCK", "$@20", "$@21",
  "EXPRESSION", "COMPARISONSTT", "ERRONOUS_COMPARISONSTT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-169)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-115)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -169,   145,  -169,   808,  -169,  -169,  -169,  -169,   -21,   438,
     -16,   455,  -169,  -169,  -169,    15,    -3,    27,   473,  -169,
     312,  -169,  -169,   455,  -169,    31,  -169,  -169,  -169,  -169,
    -169,    15,  -169,  -169,  -169,  -169,  -169,  -169,  -169,   834,
    -169,  -169,    68,   104,  -169,    42,   455,   455,   455,   455,
      47,  -169,  -169,    50,   229,   195,   455,   681,  -169,   703,
      71,    43,  -169,     4,    96,   945,    67,   455,   334,  -169,
     747,  -169,    10,  -169,   455,   361,   377,  -169,   402,   420,
     455,   455,   490,   508,   525,   543,   455,   107,   455,    93,
    -169,   945,   945,   934,   934,  -169,  -169,    14,   187,   768,
      15,   283,    15,    73,    88,    94,    84,     7,  -169,   854,
     189,   103,   641,   243,  -169,    21,  -169,   123,    21,   187,
     117,    96,   560,   107,   119,   578,    93,  -169,   169,  -169,
     107,   284,   945,    96,   945,    96,   945,    85,   934,    85,
     934,   107,   107,   101,  -169,   187,   108,   -25,  -169,   102,
     126,   619,   144,   283,  -169,   455,    12,   135,   136,   142,
     137,   149,  -169,    28,  -169,   334,  -169,   334,  -169,   455,
     595,  -169,  -169,   134,  -169,     6,  -169,   152,    96,   107,
     119,   107,   187,    15,  -169,  -169,  -169,  -169,   187,  -169,
     160,    15,   283,   789,   455,   166,  -169,  -169,    28,   162,
      28,    28,   455,   455,   168,  -169,  -169,  -169,  -169,   874,
     333,   894,   187,    15,  -169,  -169,  -169,  -169,   173,  -169,
      15,  -169,  -169,  -169,   181,  -169,   661,   165,  -169,   188,
      28,   193,   198,   914,   725,  -169,  -169,  -169,  -169,   186,
    -169,   201,    15,  -169,  -169,  -169,   205,  -169,   204,  -169,
    -169,   219,     8,  -169,  -169,  -169,    15,   246,  -169,  -169,
      15,  -169,    28,  -169,    28,    28,  -169,  -169,  -169
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    18,    19,    20,    21,     0,     0,
       0,     0,   102,   103,   104,     0,     0,     0,     0,   100,
       0,   101,    96,     0,     2,     0,     4,    12,    33,   113,
       5,     0,    13,     8,     9,    11,    10,     6,    14,     0,
     112,   124,     0,     0,    15,     0,     0,     0,     0,     0,
       0,    16,    17,    67,     0,     0,     0,     0,    92,     0,
       0,     0,    41,     0,   133,   123,     0,     0,     0,     3,
       0,    24,    64,    55,     0,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,   127,
      27,   129,   131,   134,   136,    26,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,    50,     0,
       0,     0,    53,     0,   114,     0,    70,     0,     0,     0,
     110,   126,     0,   115,   128,     0,   116,   105,   107,   106,
     108,   109,   111,   130,   119,   132,   120,   135,   121,   137,
     122,   140,   138,     0,    62,     0,     0,     0,    78,    77,
       0,     0,    87,     0,    90,     0,    84,     0,     0,     0,
       0,     0,    47,     0,    95,     0,    49,     0,    97,     0,
       0,    31,    25,     0,    60,     0,    23,     0,   141,   118,
     139,   117,     0,     0,    79,    80,    58,    69,     0,    68,
       0,     0,     0,     0,     0,     0,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    35,    52,    51,    98,     0,
       0,     0,     0,     0,    74,    56,    66,    65,     0,    63,
       0,    76,    89,    88,     0,    91,    86,    84,    83,     0,
       0,     0,     0,    37,     0,    32,    29,    30,    28,     0,
      61,     0,     0,    73,    59,    93,     0,    42,     0,    46,
      48,     0,     0,    71,    75,    57,     0,     0,    85,    44,
       0,    39,     0,    94,     0,     0,    34,    38,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,   196,   -97,     5,  -169,  -169,  -169,   140,  -169,  -168,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,   -74,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,   -96,  -169,  -169,  -169,    74,    16,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,   -15,  -169,  -169,    -8,  -169,  -169
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    24,   146,    26,   118,   115,   172,    27,   204,
     205,   251,   265,    28,   105,   160,   161,   201,    29,   111,
      30,   242,   220,   213,   183,    31,   119,    98,   173,   143,
     241,   147,   148,   149,    32,   157,   158,    33,    34,    35,
      36,   101,   256,    37,    38,    69,   208,    39,    40,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    57,   150,    59,   153,   106,    25,   214,   162,   261,
      65,   -22,   186,    53,   187,    70,    73,     4,     5,     6,
       7,   175,   169,   177,    58,   -22,   -22,   194,    62,   202,
     229,    61,   231,   232,    87,    89,   170,   171,    91,    92,
      93,    94,   107,   215,   116,   216,   163,    22,    99,   184,
     117,   144,    71,   195,    22,   145,   192,   203,    90,   109,
     112,    63,   248,    95,   -36,    72,   120,   123,   126,    54,
     128,   130,   131,   132,   134,   136,   138,   140,   141,    12,
     142,   103,   104,    86,    96,   152,   218,   154,    13,    14,
      97,   206,   221,   207,   266,   224,   267,   268,    42,    43,
      18,    19,    55,    21,   108,    54,    25,    76,    23,    42,
      43,    46,    47,   155,   179,    12,   239,   181,    25,    88,
      75,    76,   156,   -45,    13,    14,     4,     5,     6,     7,
      75,    76,   159,    43,    78,    79,    18,    19,    55,    21,
     166,   182,   185,   188,    23,     2,     3,   193,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   112,    25,   112,
     174,   209,   211,   189,   145,    13,    14,   191,   219,    15,
      16,   196,   197,    17,   212,   199,   223,    18,    19,    20,
      21,   198,    75,    76,    22,    23,   226,    79,   200,   217,
       4,     5,     6,     7,   233,   234,    66,    25,   240,   222,
     227,   230,    42,    43,   235,   244,   195,   -99,   -99,   -99,
     243,   -99,   -99,   -99,   -99,    46,    47,   -99,   245,    48,
      49,   -99,   -99,   253,   247,   -99,   -99,   255,   145,   249,
     165,   -99,   -99,   -99,   250,    68,   -99,   262,   254,   257,
     259,   263,    42,    43,     3,   264,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    46,    47,   260,   176,    48,
      49,   194,   258,    13,    14,   113,     0,    15,    16,   228,
       0,    17,     0,     0,     0,    18,    19,    20,    21,   168,
       0,     0,    22,    23,     3,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    74,    75,    76,     0,
       0,    78,    79,    13,    14,     0,     0,    15,    16,     0,
       0,    17,     0,    66,     0,    18,    19,    20,    21,     0,
       0,     0,    22,    23,   -99,   -99,   -99,    67,   -99,   -99,
     -99,   -99,     0,     0,   -99,   110,     0,     0,   -99,   -99,
       0,     0,   -99,   -99,     0,    12,    42,    43,     0,   237,
       0,     0,    68,     0,    13,    14,     0,     0,     0,    46,
      47,     0,   121,    48,    49,     0,    18,    19,    55,    21,
       0,   -54,    12,     0,    23,     0,   122,     0,   124,     0,
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
      21,   178,     0,    13,    14,    23,     0,     0,     0,     0,
       0,    12,     0,     0,     0,    18,    19,    55,    21,   180,
      13,    14,     0,    23,     0,     0,     0,     0,     0,    12,
       0,     0,    18,    19,    55,    21,   210,     0,    13,    14,
      23,     0,     0,     0,     0,     0,    12,     0,     0,     0,
      18,    19,    55,    21,     0,    13,    14,     0,    23,     0,
     190,     0,     0,     0,     0,     0,     0,    18,    19,    55,
      21,  -114,  -114,  -114,     0,    23,  -114,  -114,  -114,     0,
       0,  -114,     0,     0,     0,  -114,  -114,     0,     0,  -114,
    -114,     0,     0,    74,    75,    76,     0,  -114,    78,    79,
      80,     0,     0,    81,     0,     0,     0,    82,    83,     0,
       0,    84,    85,    74,    75,    76,     0,     0,    78,    79,
      80,     0,   167,    81,     0,     0,     0,    82,    83,     0,
       0,    84,    85,    74,    75,    76,     0,     0,    78,    79,
      80,     0,   246,    81,     0,     0,     0,    82,    83,     0,
       0,    84,    85,     0,     0,    74,    75,    76,     0,   100,
      78,    79,    80,     0,     0,    81,     0,     0,     0,    82,
      83,     0,     0,    84,    85,     0,     0,    74,    75,    76,
       0,   102,    78,    79,    80,     0,     0,    81,     0,     0,
       0,    82,    83,     0,     0,    84,    85,     0,     0,    74,
      75,    76,     0,   252,    78,    79,    80,     0,     0,    81,
       0,     0,     0,    82,    83,     0,     0,    84,    85,     0,
      74,    75,    76,     0,   114,    78,    79,    80,     0,     0,
      81,     0,     0,     0,    82,    83,     0,     0,    84,    85,
       0,    74,    75,    76,     0,   151,    78,    79,    80,     0,
       0,    81,     0,     0,     0,    82,    83,     0,     0,    84,
      85,    42,    43,     0,    44,     0,   225,     0,     0,    45,
       0,     0,     0,     0,    46,    47,     0,     0,    48,    49,
       0,     0,    50,     0,    51,    52,    74,    75,    76,     0,
      77,    78,    79,    80,     0,     0,    81,     0,     0,     0,
      82,    83,     0,     0,    84,    85,    74,    75,    76,     0,
     164,    78,    79,    80,     0,     0,    81,     0,     0,     0,
      82,    83,     0,     0,    84,    85,    74,    75,    76,     0,
     236,    78,    79,    80,     0,     0,    81,     0,     0,     0,
      82,    83,     0,     0,    84,    85,    74,    75,    76,     0,
     238,    78,    79,    80,     0,     0,    81,     0,     0,     0,
      82,    83,     0,     0,    84,    85,    74,    75,    76,     0,
       0,    78,    79,    80,     0,     0,    81,     0,     0,     0,
      82,    83,     0,     0,    84,    85,    74,    75,    76,     0,
       0,    78,    79,    80,     0,     0,    81,    74,    75,    76,
      82,    83,    78,    79,    80,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
      15,     9,    98,    11,   101,     1,     1,     1,     1,     1,
      18,     1,    37,    34,    39,    23,    31,     3,     4,     5,
       6,   117,     1,   119,    40,    15,    16,    15,     1,     1,
     198,    34,   200,   201,    42,    43,    15,    16,    46,    47,
      48,    49,    38,    37,    34,    39,    39,    39,    56,   145,
      40,    37,    21,    41,    39,    41,   153,    29,    16,    67,
      68,    34,   230,    16,    36,    34,    74,    75,    76,     1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    11,
      88,    10,    39,    15,    34,   100,   182,   102,    20,    21,
      40,   165,   188,   167,   262,   192,   264,   265,    13,    14,
      32,    33,    34,    35,    37,     1,   101,    14,    40,    13,
      14,    26,    27,    40,   122,    11,   212,   125,   113,    15,
      13,    14,    34,    39,    20,    21,     3,     4,     5,     6,
      13,    14,    38,    14,    17,    18,    32,    33,    34,    35,
      37,    40,    34,    41,    40,     0,     1,   155,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   165,   153,   167,
      37,   169,   170,    37,    41,    20,    21,    23,   183,    24,
      25,    36,    36,    28,    40,    38,   191,    32,    33,    34,
      35,    39,    13,    14,    39,    40,   194,    18,    39,    37,
       3,     4,     5,     6,   202,   203,     1,   192,   213,    39,
      34,    39,    13,    14,    36,   220,    41,    12,    13,    14,
      37,    16,    17,    18,    19,    26,    27,    22,    37,    30,
      31,    26,    27,    37,    36,    30,    31,   242,    41,    36,
      41,    36,    37,    38,    36,    40,    41,   252,    37,    34,
      36,   256,    13,    14,     1,   260,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    26,    27,    38,   118,    30,
      31,    15,   246,    20,    21,    69,    -1,    24,    25,   195,
      -1,    28,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    39,    40,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    12,    13,    14,    -1,
      -1,    17,    18,    20,    21,    -1,    -1,    24,    25,    -1,
      -1,    28,    -1,     1,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,     1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    -1,    11,    13,    14,    -1,    16,
      -1,    -1,    40,    -1,    20,    21,    -1,    -1,    -1,    26,
      27,    -1,     1,    30,    31,    -1,    32,    33,    34,    35,
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
      -1,    30,    31,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    41,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    41,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    -1,    -1,    12,    13,    14,    -1,    38,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    -1,    -1,    12,    13,    14,
      -1,    38,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,    12,
      13,    14,    -1,    38,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,
      12,    13,    14,    -1,    37,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      -1,    12,    13,    14,    -1,    37,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,
      31,    13,    14,    -1,    16,    -1,    37,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      -1,    -1,    34,    -1,    36,    37,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    12,    13,    14,    -1,
      -1,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    12,    13,    14,    -1,
      -1,    17,    18,    19,    -1,    -1,    22,    12,    13,    14,
      26,    27,    17,    18,    19,    -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    20,    21,    24,    25,    28,    32,    33,
      34,    35,    39,    40,    44,    45,    46,    50,    55,    60,
      62,    67,    76,    79,    80,    81,    82,    85,    86,    89,
      90,    91,    13,    14,    16,    21,    26,    27,    30,    31,
      34,    36,    37,    34,     1,    34,    40,    89,    40,    89,
      86,    34,     1,    34,     1,    89,     1,    15,    40,    87,
      89,    21,    34,    86,    12,    13,    14,    16,    17,    18,
      19,    22,    26,    27,    30,    31,    15,    89,    15,    89,
      16,    89,    89,    89,    89,    16,    34,    40,    69,    89,
      38,    83,    38,    10,    39,    56,     1,    38,    37,    89,
       1,    61,    89,    43,    37,    48,    34,    40,    47,    68,
      89,     1,    15,    89,     1,    15,    89,    17,    89,    18,
      89,    89,    89,     1,    89,     1,    89,     1,    89,     1,
      89,    89,    89,    71,    37,    41,    45,    73,    74,    75,
      73,    37,    86,    44,    86,    40,    34,    77,    78,    38,
      57,    58,     1,    39,    16,    41,    37,    41,    36,     1,
      15,    16,    49,    70,    37,    73,    49,    73,     1,    89,
       1,    89,    40,    66,    73,    34,    37,    39,    41,    37,
       1,    23,    44,    89,    15,    41,    36,    36,    39,    38,
      39,    59,     1,    29,    51,    52,    61,    61,    88,    89,
       1,    89,    40,    65,     1,    37,    39,    37,    73,    86,
      64,    73,    39,    86,    44,    37,    89,    34,    77,    51,
      39,    51,    51,    89,    89,    36,    16,    16,    16,    73,
      86,    72,    63,    37,    86,    37,    41,    36,    51,    36,
      36,    53,    38,    37,    37,    86,    84,    34,    78,    36,
      38,     1,    86,    86,    86,    54,    51,    51,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    45,    45,
      45,    45,    47,    46,    48,    46,    46,    46,    49,    49,
      49,    49,    50,    50,    51,    51,    51,    53,    52,    54,
      52,    56,    55,    57,    55,    58,    55,    59,    55,    60,
      60,    61,    61,    61,    61,    62,    63,    62,    64,    62,
      65,    62,    66,    62,    68,    67,    67,    69,    67,    67,
      70,    67,    71,    67,    72,    67,    73,    73,    73,    74,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    79,
      80,    81,    83,    84,    82,    85,    87,    88,    86,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     0,     4,     0,     4,     3,     3,     3,     3,
       3,     1,     6,     1,     5,     1,     0,     0,     6,     0,
       6,     0,     7,     0,     8,     0,     7,     0,     7,     4,
       3,     3,     3,     1,     0,     2,     0,     7,     0,     7,
       0,     6,     0,     6,     0,     5,     5,     0,     5,     5,
       0,     7,     0,     7,     0,     7,     3,     1,     1,     2,
       2,     5,     5,     3,     1,     5,     3,     4,     6,     6,
       4,     6,     0,     0,     9,     4,     0,     0,     5,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     4,     4,     3,
       3,     3,     3,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     4,     4,
       4,     4
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
#line 1524 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 104 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1530 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 107 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1536 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 108 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1542 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 109 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1548 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 110 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1554 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 111 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1560 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 112 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1566 "parser.tab.c"
    break;

  case 15: /* STATEMENT: error SEMICOLON  */
#line 114 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1572 "parser.tab.c"
    break;

  case 16: /* STATEMENT: error '}'  */
#line 115 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1578 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error ')'  */
#line 116 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1584 "parser.tab.c"
    break;

  case 18: /* TYPE: INT  */
#line 125 "parser.y"
                    { (yyval.str) = "int"; }
#line 1590 "parser.tab.c"
    break;

  case 19: /* TYPE: FLOAT  */
#line 126 "parser.y"
                        { (yyval.str) = "float"; }
#line 1596 "parser.tab.c"
    break;

  case 20: /* TYPE: BOOL  */
#line 127 "parser.y"
                        { (yyval.str) = "bool"; }
#line 1602 "parser.tab.c"
    break;

  case 21: /* TYPE: STRING  */
#line 128 "parser.y"
                         { (yyval.str) = "string"; }
#line 1608 "parser.tab.c"
    break;

  case 22: /* $@1: %empty  */
#line 132 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0); }
#line 1614 "parser.tab.c"
    break;

  case 23: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 132 "parser.y"
                                                                                            {printf("#[Parsed_Declaration]# ");}
#line 1620 "parser.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 133 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0);}
#line 1626 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 133 "parser.y"
                                                                                            {printf("#[Parsed_CONST_Declaration]# "); }
#line 1632 "parser.tab.c"
    break;

  case 26: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 134 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1638 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 135 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1644 "parser.tab.c"
    break;

  case 29: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 141 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1650 "parser.tab.c"
    break;

  case 30: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 142 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1656 "parser.tab.c"
    break;

  case 37: /* $@3: %empty  */
#line 163 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);}
#line 1662 "parser.tab.c"
    break;

  case 39: /* $@4: %empty  */
#line 164 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);}
#line 1668 "parser.tab.c"
    break;

  case 41: /* $@5: %empty  */
#line 168 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1674 "parser.tab.c"
    break;

  case 43: /* $@6: %empty  */
#line 169 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }
#line 1680 "parser.tab.c"
    break;

  case 45: /* $@7: %empty  */
#line 170 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1686 "parser.tab.c"
    break;

  case 47: /* $@8: %empty  */
#line 171 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1692 "parser.tab.c"
    break;

  case 49: /* FUNC_CALL: IDENTIFIER '(' USED_ARGS ')'  */
#line 182 "parser.y"
                                                        {printf("#[Parsed_Func_Call]# ");}
#line 1698 "parser.tab.c"
    break;

  case 50: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 183 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 1704 "parser.tab.c"
    break;

  case 52: /* USED_ARGS: error ',' USED_ARGS  */
#line 188 "parser.y"
                                                        {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 1710 "parser.tab.c"
    break;

  case 56: /* $@9: %empty  */
#line 198 "parser.y"
                                                 {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1716 "parser.tab.c"
    break;

  case 58: /* $@10: %empty  */
#line 199 "parser.y"
                                                 {st_insert("void", (yyvsp[-3].str),"func",0);}
#line 1722 "parser.tab.c"
    break;

  case 60: /* $@11: %empty  */
#line 200 "parser.y"
                                                 {st_insert((yyvsp[-3].str), (yyvsp[-2].str),"func",0);}
#line 1728 "parser.tab.c"
    break;

  case 62: /* $@12: %empty  */
#line 201 "parser.y"
                                                 {st_insert("void", (yyvsp[-2].str),"func",0);}
#line 1734 "parser.tab.c"
    break;

  case 64: /* $@13: %empty  */
#line 205 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1740 "parser.tab.c"
    break;

  case 65: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@13 ARGS ')'  */
#line 205 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1746 "parser.tab.c"
    break;

  case 66: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS '{'  */
#line 206 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1752 "parser.tab.c"
    break;

  case 67: /* $@14: %empty  */
#line 207 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1758 "parser.tab.c"
    break;

  case 68: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER $@14 ARGS ')'  */
#line 207 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1764 "parser.tab.c"
    break;

  case 69: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER '(' ARGS '{'  */
#line 208 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1770 "parser.tab.c"
    break;

  case 70: /* $@15: %empty  */
#line 209 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1776 "parser.tab.c"
    break;

  case 71: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER $@15 '(' ARGS ')'  */
#line 209 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1782 "parser.tab.c"
    break;

  case 72: /* $@16: %empty  */
#line 210 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1788 "parser.tab.c"
    break;

  case 73: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER IDENTIFIER $@16 '(' ARGS ')'  */
#line 210 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1794 "parser.tab.c"
    break;

  case 74: /* $@17: %empty  */
#line 211 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected token '%s' in argument list of function declaration at line %d\n\n", yylval, yylineno);}
#line 1800 "parser.tab.c"
    break;

  case 75: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS error $@17 ')'  */
#line 211 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1806 "parser.tab.c"
    break;

  case 79: /* ERRONOUS_ARGS: ',' ARGS  */
#line 220 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
#line 1812 "parser.tab.c"
    break;

  case 80: /* ARG_DECL: TYPE IDENTIFIER  */
#line 223 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1);}
#line 1818 "parser.tab.c"
    break;

  case 81: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_ARGS '}'  */
#line 233 "parser.y"
                                                            { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 1824 "parser.tab.c"
    break;

  case 82: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_DEFINED_ARGS '}'  */
#line 234 "parser.y"
                                                            { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 1830 "parser.tab.c"
    break;

  case 89: /* IF_STT: IF '(' EXPRESSION ')' error '{'  */
#line 252 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 1836 "parser.tab.c"
    break;

  case 92: /* $@18: %empty  */
#line 267 "parser.y"
                        {in_loop = 1;}
#line 1842 "parser.tab.c"
    break;

  case 93: /* $@19: %empty  */
#line 267 "parser.y"
                                                                        {in_loop = 0;}
#line 1848 "parser.tab.c"
    break;

  case 95: /* assignmentSTT: IDENTIFIER EQ EXPRESSION SEMICOLON  */
#line 272 "parser.y"
                                                            {printf("#[Parsed_Assignment]# ");}
#line 1854 "parser.tab.c"
    break;

  case 96: /* $@20: %empty  */
#line 277 "parser.y"
                    {scope_start();}
#line 1860 "parser.tab.c"
    break;

  case 97: /* $@21: %empty  */
#line 277 "parser.y"
                                                 {scope_end();}
#line 1866 "parser.tab.c"
    break;

  case 98: /* BLOCK: '{' $@20 PROGRAM '}' $@21  */
#line 277 "parser.y"
                                                                                    {printf("#[Parsed_Block]# ");}
#line 1872 "parser.tab.c"
    break;

  case 100: /* EXPRESSION: DIGIT  */
#line 284 "parser.y"
                        { symbolTable[st_index-1].intValue= (yyvsp[0].num) ;}
#line 1878 "parser.tab.c"
    break;

  case 101: /* EXPRESSION: FLOAT_DIGIT  */
#line 285 "parser.y"
                              { symbolTable[st_index-1].floatValue= (yyvsp[0].float_val) ;}
#line 1884 "parser.tab.c"
    break;

  case 102: /* EXPRESSION: BOOL_LITERAL  */
#line 286 "parser.y"
                                { symbolTable[st_index-1].boolValue= (yyvsp[0].bool_val) ;}
#line 1890 "parser.tab.c"
    break;

  case 103: /* EXPRESSION: STRING_LITERAL  */
#line 287 "parser.y"
                                  { symbolTable[st_index-1].strValue= (yyvsp[0].str) ;}
#line 1896 "parser.tab.c"
    break;

  case 125: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 318 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 1902 "parser.tab.c"
    break;

  case 126: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 319 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 1908 "parser.tab.c"
    break;

  case 127: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 320 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 1914 "parser.tab.c"
    break;

  case 128: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 321 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 1920 "parser.tab.c"
    break;

  case 129: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 322 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 1926 "parser.tab.c"
    break;

  case 130: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 323 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 1932 "parser.tab.c"
    break;

  case 131: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 324 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 1938 "parser.tab.c"
    break;

  case 132: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 325 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 1944 "parser.tab.c"
    break;

  case 133: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 326 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 1950 "parser.tab.c"
    break;

  case 134: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 327 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 1956 "parser.tab.c"
    break;

  case 135: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 328 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 1962 "parser.tab.c"
    break;

  case 136: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 329 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 1968 "parser.tab.c"
    break;

  case 137: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 330 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 1974 "parser.tab.c"
    break;

  case 138: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 331 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 1980 "parser.tab.c"
    break;

  case 139: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 332 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 1986 "parser.tab.c"
    break;

  case 140: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 333 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 1992 "parser.tab.c"
    break;

  case 141: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 334 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 1998 "parser.tab.c"
    break;


#line 2002 "parser.tab.c"

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

#line 345 "parser.y"




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
