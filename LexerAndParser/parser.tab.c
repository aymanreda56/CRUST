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
  YYSYMBOL_FUNC_DECLARATION_STT = 63,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_64_12 = 64,                     /* $@12  */
  YYSYMBOL_65_13 = 65,                     /* $@13  */
  YYSYMBOL_66_14 = 66,                     /* $@14  */
  YYSYMBOL_67_15 = 67,                     /* $@15  */
  YYSYMBOL_ERRONOUS_FUNC_DECLARATION_STT = 68, /* ERRONOUS_FUNC_DECLARATION_STT  */
  YYSYMBOL_69_16 = 69,                     /* $@16  */
  YYSYMBOL_70_17 = 70,                     /* $@17  */
  YYSYMBOL_71_18 = 71,                     /* $@18  */
  YYSYMBOL_72_19 = 72,                     /* $@19  */
  YYSYMBOL_73_20 = 73,                     /* $@20  */
  YYSYMBOL_ARGS = 74,                      /* ARGS  */
  YYSYMBOL_ERRONOUS_ARGS = 75,             /* ERRONOUS_ARGS  */
  YYSYMBOL_ARG_DECL = 76,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 77,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_HELPER = 78,               /* ENUM_HELPER  */
  YYSYMBOL_ENUM_ARGS = 79,                 /* ENUM_ARGS  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 80,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_ERRONOUS_ENUM_DECLARATION_STT = 81, /* ERRONOUS_ENUM_DECLARATION_STT  */
  YYSYMBOL_IF_STT = 82,                    /* IF_STT  */
  YYSYMBOL_83_21 = 83,                     /* $@21  */
  YYSYMBOL_84_22 = 84,                     /* $@22  */
  YYSYMBOL_WHILE_STT = 85,                 /* WHILE_STT  */
  YYSYMBOL_ERRONOUS_WHILE_STT = 86,        /* ERRONOUS_WHILE_STT  */
  YYSYMBOL_87_23 = 87,                     /* $@23  */
  YYSYMBOL_88_24 = 88,                     /* $@24  */
  YYSYMBOL_DO_WHILE_STT = 89,              /* DO_WHILE_STT  */
  YYSYMBOL_FOR_STT = 90,                   /* FOR_STT  */
  YYSYMBOL_91_25 = 91,                     /* $@25  */
  YYSYMBOL_92_26 = 92,                     /* $@26  */
  YYSYMBOL_assignmentSTT = 93,             /* assignmentSTT  */
  YYSYMBOL_BLOCK = 94,                     /* BLOCK  */
  YYSYMBOL_95_27 = 95,                     /* $@27  */
  YYSYMBOL_96_28 = 96,                     /* $@28  */
  YYSYMBOL_FUNC_CALL = 97,                 /* FUNC_CALL  */
  YYSYMBOL_USED_ARGS = 98,                 /* USED_ARGS  */
  YYSYMBOL_EXPRESSION = 99,                /* EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 100,            /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 101,   /* ERRONOUS_COMPARISONSTT  */
  YYSYMBOL_RES_WORD = 102                  /* RES_WORD  */
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
#define YYLAST   1042

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  314

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
     173,   174,   174,   175,   175,   176,   176,   191,   192,   192,
     193,   193,   194,   194,   195,   195,   199,   199,   200,   201,
     201,   202,   203,   203,   204,   204,   205,   205,   209,   210,
     211,   214,   217,   227,   228,   230,   230,   232,   233,   236,
     237,   240,   241,   243,   250,   251,   252,   253,   253,   254,
     254,   255,   262,   263,   267,   267,   268,   268,   269,   274,
     279,   279,   279,   284,   289,   289,   289,   296,   297,   301,
     302,   303,   304,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368
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
  "$@10", "$@11", "FUNC_DECLARATION_STT", "$@12", "$@13", "$@14", "$@15",
  "ERRONOUS_FUNC_DECLARATION_STT", "$@16", "$@17", "$@18", "$@19", "$@20",
  "ARGS", "ERRONOUS_ARGS", "ARG_DECL", "ENUM_DECLARATION_STT",
  "ENUM_HELPER", "ENUM_ARGS", "ENUM_DEFINED_ARGS",
  "ERRONOUS_ENUM_DECLARATION_STT", "IF_STT", "$@21", "$@22", "WHILE_STT",
  "ERRONOUS_WHILE_STT", "$@23", "$@24", "DO_WHILE_STT", "FOR_STT", "$@25",
  "$@26", "assignmentSTT", "BLOCK", "$@27", "$@28", "FUNC_CALL",
  "USED_ARGS", "EXPRESSION", "COMPARISONSTT", "ERRONOUS_COMPARISONSTT",
  "RES_WORD", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-207)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-129)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -207,   115,  -207,   914,  -207,  -207,  -207,  -207,   -16,    13,
     -14,   538,  -207,  -207,  -207,    45,    21,    57,   555,  -207,
     396,  -207,  -207,   573,  -207,    71,  -207,  -207,  -207,  -207,
      45,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,   940,  -207,  -207,   141,   418,  -207,    70,   573,   573,
     573,   573,    84,  -207,  -207,    34,   353,   288,  -207,   786,
    -207,   390,   808,    97,    75,    18,  -207,     2,    98,  1020,
      72,   573,   434,  -207,   874,  -207,    20,  -207,   573,   461,
     477,  -207,   502,   520,   573,   573,   590,   608,   625,   643,
     573,   124,   573,   114,  -207,  1020,  1020,   186,   186,  -207,
    -207,   154,    92,    45,    11,    45,   367,  -207,    24,    45,
     104,   111,    -2,    65,   110,  -207,  -207,   128,   130,    30,
    -207,   960,   246,   133,   719,   222,  -207,   116,   156,   181,
     116,    92,   235,    98,   660,   124,   163,   678,   114,  -207,
     150,  -207,   124,   223,  1020,    98,  1020,    98,  1020,   188,
     186,   188,   186,   124,   124,   139,  -207,    92,   158,   -30,
    -207,   147,   153,  -207,   173,   193,  -207,   367,    45,   183,
    -207,  -207,   573,   198,   573,   190,   203,   208,  -207,   212,
     225,   228,  -207,   105,  -207,   434,  -207,   434,  -207,   329,
     695,  -207,  -207,  -207,   241,  -207,    22,  -207,   238,    98,
     124,   163,   124,    92,    45,  -207,  -207,  -207,  -207,    92,
    -207,  -207,    31,   367,  -207,  -207,   895,  -207,   739,   243,
    -207,  -207,  -207,   105,   247,   105,   105,   573,   573,   249,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,   980,  -207,  -207,  -207,  -207,  -207,  1000,  -207,
     180,   853,    92,    45,  -207,  -207,  -207,  -207,   262,  -207,
      45,  -207,   267,  -207,   271,  -207,   286,   285,   105,   287,
     295,   252,   830,  -207,  -207,  -207,  -207,   305,   306,   768,
     307,  -207,   308,    45,  -207,  -207,  -207,  -207,   327,  -207,
    -207,   310,  -207,  -207,   284,    48,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,    45,  -207,    45,  -207,   105,  -207,   105,
     105,  -207,  -207,  -207
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,    18,    19,    20,    21,     0,     0,
       0,     0,   126,   127,   128,     0,     0,     0,     0,   124,
       0,   125,   114,     0,     2,     0,     4,    12,    41,     5,
       0,    13,    84,     8,     9,   103,    11,    10,     6,    14,
     137,     0,   136,   148,     0,     0,    15,     0,     0,     0,
       0,     0,     0,    16,    17,    69,     0,     0,    99,    97,
     110,     0,   106,     0,     0,     0,    49,     0,   157,   147,
       0,     0,     0,     3,     0,    24,    66,    57,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   149,     0,   151,    27,   153,   155,   158,   160,    26,
      74,     0,     0,     0,     0,     0,     0,   104,     0,     0,
       0,     0,    88,     0,     0,    85,    86,     0,    51,     0,
     118,     0,     0,     0,   121,     0,   138,     0,    72,     0,
       0,     0,   134,   150,     0,   139,   152,     0,   140,   129,
     131,   130,   132,   133,   135,   154,   143,   156,   144,   159,
     145,   161,   146,   164,   162,     0,    64,     0,     0,     0,
      80,    79,     0,   100,     0,    94,    98,     0,     0,     0,
     102,   107,     0,     0,     0,     0,     0,     0,    92,     0,
       0,     0,    55,     0,   113,     0,   117,     0,   115,     0,
       0,    32,    25,    28,     0,    62,     0,    23,     0,   165,
     142,   163,   141,     0,     0,    81,    82,    60,    71,     0,
      70,   101,     0,     0,   105,   108,     0,    91,    90,    88,
      87,    93,    83,     0,     0,     0,     0,     0,     0,     0,
      43,   120,   119,   116,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,    39,
       0,    37,     0,     0,    76,    58,    68,    67,     0,    65,
       0,    78,     0,    96,     0,   109,     0,     0,     0,     0,
       0,    45,     0,    40,    30,    31,    29,     0,     0,     0,
       0,    63,     0,     0,    75,    61,    95,   111,     0,    89,
      50,     0,    54,    56,     0,     0,    34,    36,   174,    38,
      73,    77,    59,     0,    52,     0,    47,     0,   112,     0,
       0,    42,    46,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,   274,  -100,     4,  -207,  -207,  -207,   218,  -207,  -207,
    -207,  -207,  -206,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -101,  -207,  -207,  -207,  -103,   176,    89,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,   -15,  -207,  -207,  -207,  -158,    -7,  -207,  -207,
      77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    24,   158,    26,   130,   127,   192,   277,   278,
     279,    27,   229,   230,   294,   310,    28,   117,   180,   181,
     226,    29,   283,   260,   253,   204,    30,   131,   102,   194,
     155,   282,   159,   160,   161,    31,   114,   115,   116,    32,
      33,   105,   103,    34,    35,   168,   109,    36,    37,   106,
     303,    38,    39,    73,   233,    40,   123,    41,    42,    43,
     249
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,   162,    59,   118,    62,    25,   167,   207,   173,   208,
     177,    69,   164,   174,    56,    77,    74,   267,    55,   269,
     270,   -22,    64,   254,    12,   169,    60,   231,   196,   232,
     198,   182,   262,    13,    14,   -22,   -22,    91,    93,   175,
     119,    95,    96,    97,    98,    18,    19,    57,    21,   306,
      22,    58,   112,    23,   128,    65,   205,   113,    66,   255,
     129,   256,   291,    22,   121,   124,   176,   213,   100,   183,
      22,   132,   135,   138,   101,   140,   142,   143,   144,   146,
     148,   150,   152,   153,    22,   154,    94,    22,   163,   165,
     166,    67,    75,   170,   171,     4,     5,     6,     7,   112,
      99,   311,   258,   312,   313,    76,   227,   110,   261,   120,
      25,    44,    45,   264,   111,     2,     3,   189,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   200,    80,    25,
     202,   190,   191,   157,   228,    13,    14,    79,    80,    15,
      16,   -44,    56,    17,   172,   112,   178,    18,    19,    20,
      21,   280,    12,   214,    22,    23,    90,     4,     5,     6,
       7,    13,    14,    79,    80,   216,   179,   218,    83,   -53,
     186,    25,   193,    18,    19,    57,    21,    45,   124,   203,
     124,    23,   248,   251,     4,     5,     6,     7,   209,   259,
     210,   156,   206,    44,    45,   157,   275,   263,    78,    79,
      80,    44,    45,    82,    83,    84,    48,    49,    85,   211,
      50,    51,    86,    87,    48,    49,   212,    25,   195,   215,
     271,   272,   157,     3,   219,     4,     5,     6,     7,     8,
       9,    10,    11,    12,   217,    78,    79,    80,   281,   221,
      82,    83,    13,    14,   222,   285,    15,    16,    79,    80,
      17,   223,    82,    83,    18,    19,    20,    21,   188,    44,
      45,    22,    23,   224,    78,    79,    80,   225,   302,    82,
      83,    84,    48,    49,    85,   257,    50,    51,    86,    87,
     307,   252,    88,    89,   175,   273,   268,   185,   308,    70,
     309,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   284,
    -123,  -123,  -123,   286,  -123,  -123,  -123,  -123,   287,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
     288,   290,   305,   292,  -123,  -123,  -123,  -123,    72,  -123,
      56,   293,   234,   235,   236,   237,   238,   239,   240,   241,
      12,   296,   174,   297,   300,   301,   304,   125,   197,    13,
     242,   220,   243,   244,   245,   289,   299,   246,   247,     0,
       0,    18,    19,    57,    21,     0,    44,    45,     3,    23,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    48,
      49,     0,     0,    50,    51,     0,     0,    13,    14,     0,
       0,    15,    16,     0,     0,    17,     0,    70,     0,    18,
      19,    20,    21,    44,    45,     0,    22,    23,  -123,  -123,
    -123,    71,  -123,  -123,  -123,  -123,    48,    49,  -123,    56,
      50,    51,  -123,  -123,     0,     0,  -123,  -123,   107,    12,
       0,     0,     0,    92,     0,   122,    72,     0,    13,    14,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
      18,    19,    57,    21,    13,    14,     0,     0,    23,     0,
       0,     0,   133,     0,     0,     0,    18,    19,    57,    21,
       0,  -122,    12,     0,    23,     0,   134,     0,   136,     0,
       0,    13,    14,     0,     0,     0,     0,     0,    12,     0,
       0,     0,   137,    18,    19,    57,    21,    13,    14,     0,
       0,    23,     0,    56,     0,     0,     0,     0,     0,    18,
      19,    57,    21,    12,     0,     0,     0,    23,     0,   139,
       0,    56,    13,    14,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,    18,    19,    57,    21,   141,    61,
      13,    14,    23,     0,     0,     0,     0,     0,     0,    12,
       0,     0,    18,    19,    57,    21,    68,     0,    13,    14,
      23,     0,     0,     0,     0,     0,    12,     0,     0,     0,
      18,    19,    57,    21,    56,    13,    14,     0,    23,     0,
       0,     0,     0,     0,    12,     0,     0,    18,    19,    57,
      21,   145,     0,    13,    14,    23,     0,     0,     0,     0,
       0,    12,     0,     0,     0,    18,    19,    57,    21,   147,
      13,    14,     0,    23,     0,     0,     0,     0,     0,    12,
       0,     0,    18,    19,    57,    21,   149,     0,    13,    14,
      23,     0,     0,     0,     0,     0,    12,     0,     0,     0,
      18,    19,    57,    21,   151,    13,    14,     0,    23,     0,
       0,     0,     0,     0,    12,     0,     0,    18,    19,    57,
      21,   199,     0,    13,    14,    23,     0,     0,     0,     0,
       0,    12,     0,     0,     0,    18,    19,    57,    21,   201,
      13,    14,     0,    23,     0,     0,     0,     0,     0,    12,
       0,     0,    18,    19,    57,    21,   250,     0,    13,    14,
      23,     0,     0,     0,     0,     0,    12,     0,     0,     0,
      18,    19,    57,    21,     0,    13,    14,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    57,
      21,    78,    79,    80,     0,    23,    82,    83,    84,     0,
       0,    85,     0,     0,     0,    86,    87,     0,     0,    88,
      89,    78,    79,    80,     0,     0,    82,    83,    84,     0,
     187,    85,     0,     0,     0,    86,    87,     0,     0,    88,
      89,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,   298,
       0,   243,   244,   245,     0,     0,   246,   247,    78,    79,
      80,     0,     0,    82,    83,    84,     0,     0,    85,     0,
       0,     0,    86,    87,     0,     0,    88,    89,     0,     0,
      78,    79,    80,     0,   104,    82,    83,    84,     0,     0,
      85,     0,     0,     0,    86,    87,     0,     0,    88,    89,
       0,     0,    78,    79,    80,     0,   108,    82,    83,    84,
       0,     0,    85,     0,     0,     0,    86,    87,     0,     0,
      88,    89,     0,     0,     0,    78,    79,    80,   295,   276,
      82,    83,    84,     0,     0,    85,     0,     0,     0,    86,
      87,     0,     0,    88,    89,     0,    78,    79,    80,   -33,
     -35,    82,    83,    84,     0,     0,    85,     0,     0,     0,
      86,    87,     0,     0,    88,    89,     0,    78,    79,    80,
       0,   126,    82,    83,    84,     0,     0,    85,     0,     0,
       0,    86,    87,     0,     0,    88,    89,    44,    45,     0,
      46,     0,   265,     0,     0,    47,     0,     0,     0,     0,
      48,    49,     0,     0,    50,    51,     0,     0,    52,     0,
      53,    54,    78,    79,    80,     0,    81,    82,    83,    84,
       0,     0,    85,     0,     0,     0,    86,    87,     0,     0,
      88,    89,    78,    79,    80,     0,   184,    82,    83,    84,
       0,     0,    85,     0,     0,     0,    86,    87,     0,     0,
      88,    89,  -128,  -128,  -128,     0,  -128,  -128,  -128,  -128,
       0,     0,  -128,     0,     0,     0,  -128,  -128,     0,     0,
    -128,  -128,    78,    79,    80,     0,   274,    82,    83,    84,
       0,     0,    85,     0,     0,     0,    86,    87,     0,     0,
      88,    89,    78,    79,    80,     0,     0,    82,    83,    84,
       0,     0,    85
};

static const yytype_int16 yycheck[] =
{
      15,   102,     9,     1,    11,     1,   106,    37,   111,    39,
     113,    18,     1,    15,     1,    30,    23,   223,    34,   225,
     226,     1,     1,     1,    11,     1,    40,   185,   129,   187,
     131,     1,     1,    20,    21,    15,    16,    44,    45,    41,
      38,    48,    49,    50,    51,    32,    33,    34,    35,     1,
      39,    38,    34,    40,    34,    34,   157,    39,     1,    37,
      40,    39,   268,    39,    71,    72,     1,   167,    34,    39,
      39,    78,    79,    80,    40,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    39,    92,    16,    39,   103,   104,
     105,    34,    21,   108,   109,     3,     4,     5,     6,    34,
      16,   307,   203,   309,   310,    34,     1,    10,   209,    37,
     106,    13,    14,   213,    39,     0,     1,     1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   134,    14,   125,
     137,    15,    16,    41,    29,    20,    21,    13,    14,    24,
      25,    36,     1,    28,    40,    34,    36,    32,    33,    34,
      35,   252,    11,   168,    39,    40,    15,     3,     4,     5,
       6,    20,    21,    13,    14,   172,    38,   174,    18,    39,
      37,   167,    16,    32,    33,    34,    35,    14,   185,    40,
     187,    40,   189,   190,     3,     4,     5,     6,    41,   204,
      37,    37,    34,    13,    14,    41,    16,   212,    12,    13,
      14,    13,    14,    17,    18,    19,    26,    27,    22,    36,
      30,    31,    26,    27,    26,    27,    23,   213,    37,    36,
     227,   228,    41,     1,    34,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    36,    12,    13,    14,   253,    36,
      17,    18,    20,    21,    36,   260,    24,    25,    13,    14,
      28,    39,    17,    18,    32,    33,    34,    35,    36,    13,
      14,    39,    40,    38,    12,    13,    14,    39,   283,    17,
      18,    19,    26,    27,    22,    37,    30,    31,    26,    27,
     295,    40,    30,    31,    41,    36,    39,    41,   303,     1,
     305,     3,     4,     5,     6,     7,     8,     9,    10,    37,
      12,    13,    14,    36,    16,    17,    18,    19,    37,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      34,    36,    38,    36,    36,    37,    38,    39,    40,    41,
       1,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    36,    15,    37,    37,    37,    36,    73,   130,    20,
      21,   175,    23,    24,    25,   266,   279,    28,    29,    -1,
      -1,    32,    33,    34,    35,    -1,    13,    14,     1,    40,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    26,
      27,    -1,    -1,    30,    31,    -1,    -1,    20,    21,    -1,
      -1,    24,    25,    -1,    -1,    28,    -1,     1,    -1,    32,
      33,    34,    35,    13,    14,    -1,    39,    40,    12,    13,
      14,    15,    16,    17,    18,    19,    26,    27,    22,     1,
      30,    31,    26,    27,    -1,    -1,    30,    31,    38,    11,
      -1,    -1,    -1,    15,    -1,     1,    40,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    20,    21,    -1,    -1,    40,    -1,
      -1,    -1,     1,    -1,    -1,    -1,    32,    33,    34,    35,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    12,    13,    14,    -1,    40,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,
      31,    12,    13,    14,    -1,    -1,    17,    18,    19,    -1,
      41,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,
      31,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    23,    24,    25,    -1,    -1,    28,    29,    12,    13,
      14,    -1,    -1,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,    -1,
      12,    13,    14,    -1,    38,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      -1,    -1,    12,    13,    14,    -1,    38,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    -1,    -1,    -1,    12,    13,    14,    38,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    -1,    12,    13,    14,    36,
      37,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    -1,    12,    13,    14,
      -1,    37,    17,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    13,    14,    -1,
      16,    -1,    37,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,
      36,    37,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    12,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    20,    21,    24,    25,    28,    32,    33,
      34,    35,    39,    40,    44,    45,    46,    53,    58,    63,
      68,    77,    81,    82,    85,    86,    89,    90,    93,    94,
      97,    99,   100,   101,    13,    14,    16,    21,    26,    27,
      30,    31,    34,    36,    37,    34,     1,    34,    38,    99,
      40,     1,    99,    94,     1,    34,     1,    34,     1,    99,
       1,    15,    40,    95,    99,    21,    34,    94,    12,    13,
      14,    16,    17,    18,    19,    22,    26,    27,    30,    31,
      15,    99,    15,    99,    16,    99,    99,    99,    99,    16,
      34,    40,    70,    84,    38,    83,    91,    38,    38,    88,
      10,    39,    34,    39,    78,    79,    80,    59,     1,    38,
      37,    99,     1,    98,    99,    43,    37,    48,    34,    40,
      47,    69,    99,     1,    15,    99,     1,    15,    99,    17,
      99,    18,    99,    99,    99,     1,    99,     1,    99,     1,
      99,     1,    99,    99,    99,    72,    37,    41,    45,    74,
      75,    76,    74,    94,     1,    94,    94,    44,    87,     1,
      94,    94,    40,    78,    15,    41,     1,    78,    36,    38,
      60,    61,     1,    39,    16,    41,    37,    41,    36,     1,
      15,    16,    49,    16,    71,    37,    74,    49,    74,     1,
      99,     1,    99,    40,    67,    74,    34,    37,    39,    41,
      37,    36,    23,    44,    94,    36,    99,    36,    99,    34,
      79,    36,    36,    39,    38,    39,    62,     1,    29,    54,
      55,    98,    98,    96,     3,     4,     5,     6,     7,     8,
       9,    10,    21,    23,    24,    25,    28,    29,    99,   102,
       1,    99,    40,    66,     1,    37,    39,    37,    74,    94,
      65,    74,     1,    94,    44,    37,    41,    54,    39,    54,
      54,    99,    99,    36,    16,    16,    16,    50,    51,    52,
      74,    94,    73,    64,    37,    94,    36,    37,    34,    80,
      36,    54,    36,    36,    56,    38,    36,    37,    21,   102,
      37,    37,    94,    92,    36,    38,     1,    94,    94,    94,
      57,    54,    54,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    45,    45,
      45,    45,    47,    46,    48,    46,    46,    46,    46,    49,
      49,    49,    49,    50,    49,    51,    49,    52,    49,    49,
      53,    53,    54,    54,    54,    56,    55,    57,    55,    59,
      58,    60,    58,    61,    58,    62,    58,    63,    64,    63,
      65,    63,    66,    63,    67,    63,    69,    68,    68,    70,
      68,    68,    71,    68,    72,    68,    73,    68,    74,    74,
      74,    75,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    81,    82,    82,    82,    83,    82,    84,
      82,    82,    85,    85,    87,    86,    88,    86,    86,    89,
      91,    92,    90,    93,    95,    96,    94,    97,    97,    98,
      98,    98,    98,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102
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
       0,     0,     9,     4,     0,     0,     5,     4,     3,     3,
       3,     1,     0,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     4,     4,     3,     3,     3,     3,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 1582 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 104 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1588 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 107 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1594 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 108 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1600 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 109 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1606 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 110 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1612 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 111 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1618 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 112 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1624 "parser.tab.c"
    break;

  case 15: /* STATEMENT: error SEMICOLON  */
#line 114 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1630 "parser.tab.c"
    break;

  case 16: /* STATEMENT: error '}'  */
#line 115 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1636 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error ')'  */
#line 116 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1642 "parser.tab.c"
    break;

  case 18: /* TYPE: INT  */
#line 124 "parser.y"
                    { (yyval.str) = "int"; }
#line 1648 "parser.tab.c"
    break;

  case 19: /* TYPE: FLOAT  */
#line 125 "parser.y"
                        { (yyval.str) = "float"; }
#line 1654 "parser.tab.c"
    break;

  case 20: /* TYPE: BOOL  */
#line 126 "parser.y"
                        { (yyval.str) = "bool"; }
#line 1660 "parser.tab.c"
    break;

  case 21: /* TYPE: STRING  */
#line 127 "parser.y"
                         { (yyval.str) = "string"; }
#line 1666 "parser.tab.c"
    break;

  case 22: /* $@1: %empty  */
#line 131 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0); }
#line 1672 "parser.tab.c"
    break;

  case 23: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 131 "parser.y"
                                                                                            {printf("#[Parsed_Declaration]# ");}
#line 1678 "parser.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 132 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0);}
#line 1684 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 132 "parser.y"
                                                                                            {printf("#[Parsed_CONST_Declaration]# "); }
#line 1690 "parser.tab.c"
    break;

  case 26: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 133 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1696 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 134 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1702 "parser.tab.c"
    break;

  case 28: /* DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER SEMICOLON  */
#line 135 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected identifier %s at line %d\n\n",(yyvsp[-1].str), yylineno);}
#line 1708 "parser.tab.c"
    break;

  case 30: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 141 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1714 "parser.tab.c"
    break;

  case 31: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 142 "parser.y"
                                                                                            {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1720 "parser.tab.c"
    break;

  case 33: /* $@3: %empty  */
#line 144 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1726 "parser.tab.c"
    break;

  case 35: /* $@4: %empty  */
#line 145 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1732 "parser.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 146 "parser.y"
                                                                                      {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno); }
#line 1738 "parser.tab.c"
    break;

  case 39: /* DECLARATION_TAIL: error RES_WORD  */
#line 148 "parser.y"
                                                                                           {printf("\n\n=====ERROR====\n Missing semicolon ';' at line %d\n\n", yylineno);}
#line 1744 "parser.tab.c"
    break;

  case 45: /* $@6: %empty  */
#line 168 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);}
#line 1750 "parser.tab.c"
    break;

  case 47: /* $@7: %empty  */
#line 169 "parser.y"
                                                 {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);}
#line 1756 "parser.tab.c"
    break;

  case 49: /* $@8: %empty  */
#line 173 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1762 "parser.tab.c"
    break;

  case 51: /* $@9: %empty  */
#line 174 "parser.y"
                                                {printf("\n\n=====ERROR====\n unexpected identifier '%s' at switch statement at line %d\n\n",yylval, yylineno); }
#line 1768 "parser.tab.c"
    break;

  case 53: /* $@10: %empty  */
#line 175 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1774 "parser.tab.c"
    break;

  case 55: /* $@11: %empty  */
#line 176 "parser.y"
                                                {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1780 "parser.tab.c"
    break;

  case 58: /* $@12: %empty  */
#line 192 "parser.y"
                                                 {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1786 "parser.tab.c"
    break;

  case 60: /* $@13: %empty  */
#line 193 "parser.y"
                                                 {st_insert("void", (yyvsp[-3].str),"func",0);}
#line 1792 "parser.tab.c"
    break;

  case 62: /* $@14: %empty  */
#line 194 "parser.y"
                                                 {st_insert((yyvsp[-3].str), (yyvsp[-2].str),"func",0);}
#line 1798 "parser.tab.c"
    break;

  case 64: /* $@15: %empty  */
#line 195 "parser.y"
                                                 {st_insert("void", (yyvsp[-2].str),"func",0);}
#line 1804 "parser.tab.c"
    break;

  case 66: /* $@16: %empty  */
#line 199 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1810 "parser.tab.c"
    break;

  case 67: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER $@16 ARGS ')'  */
#line 199 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1816 "parser.tab.c"
    break;

  case 68: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS '{'  */
#line 200 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1822 "parser.tab.c"
    break;

  case 69: /* $@17: %empty  */
#line 201 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[0].str));}
#line 1828 "parser.tab.c"
    break;

  case 70: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER $@17 ARGS ')'  */
#line 201 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1834 "parser.tab.c"
    break;

  case 71: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER '(' ARGS '{'  */
#line 202 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unclosed function parenthesis at line %d for function %s\n\n", yylineno, (yyvsp[-3].str)); yyclearin;                          st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1840 "parser.tab.c"
    break;

  case 72: /* $@18: %empty  */
#line 203 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1846 "parser.tab.c"
    break;

  case 73: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER IDENTIFIER $@18 '(' ARGS ')'  */
#line 203 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1852 "parser.tab.c"
    break;

  case 74: /* $@19: %empty  */
#line 204 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected identifier '%s' at function declaration at line %d\n\n",yylval, yylineno); yyclearin;}
#line 1858 "parser.tab.c"
    break;

  case 75: /* ERRONOUS_FUNC_DECLARATION_STT: VOID IDENTIFIER IDENTIFIER $@19 '(' ARGS ')'  */
#line 204 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1864 "parser.tab.c"
    break;

  case 76: /* $@20: %empty  */
#line 205 "parser.y"
                                                    {printf("\n\n=====ERROR====\n unexpected token '%s' in argument list of function declaration at line %d\n\n", yylval, yylineno);}
#line 1870 "parser.tab.c"
    break;

  case 77: /* ERRONOUS_FUNC_DECLARATION_STT: TYPE IDENTIFIER '(' ARGS error $@20 ')'  */
#line 205 "parser.y"
                                                                                                                                                                                                    {st_insert((yyvsp[-6].str), (yyvsp[-5].str),"func",0);}
#line 1876 "parser.tab.c"
    break;

  case 81: /* ERRONOUS_ARGS: ',' ARGS  */
#line 214 "parser.y"
                                           {printf("\n\n=====ERROR====\n unexpected ',' in argument list of function declaration at line %d\n\n", yylineno);}
#line 1882 "parser.tab.c"
    break;

  case 82: /* ARG_DECL: TYPE IDENTIFIER  */
#line 217 "parser.y"
                                                            {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1);}
#line 1888 "parser.tab.c"
    break;

  case 83: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_HELPER '}'  */
#line 227 "parser.y"
                                                              { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 1894 "parser.tab.c"
    break;

  case 91: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM error '{' ENUM_HELPER '}'  */
#line 240 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing identifier for ENUM statement at line %d\n\n", yylineno);}
#line 1900 "parser.tab.c"
    break;

  case 92: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER ENUM_HELPER '}'  */
#line 241 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing opening curly braces for ENUM statement at line %d\n\n", yylineno);}
#line 1906 "parser.tab.c"
    break;

  case 93: /* ERRONOUS_ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' error '}'  */
#line 243 "parser.y"
                                                            {printf("\n\n=====ERROR====\n missing arguments in the ENUM statement at line %d\n\n", yylineno);}
#line 1912 "parser.tab.c"
    break;

  case 95: /* IF_STT: IF EXPRESSION ':' BLOCK ELSE error '}'  */
#line 251 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the ELSE statement at line %d\n\n", yylineno);}
#line 1918 "parser.tab.c"
    break;

  case 97: /* $@21: %empty  */
#line 253 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 1924 "parser.tab.c"
    break;

  case 99: /* $@22: %empty  */
#line 254 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the IF statement at line %d\n\n", yylineno);}
#line 1930 "parser.tab.c"
    break;

  case 101: /* IF_STT: IF EXPRESSION ':' error '}'  */
#line 255 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing '{' for the IF statement at line %d\n\n", yylineno);}
#line 1936 "parser.tab.c"
    break;

  case 104: /* $@23: %empty  */
#line 267 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing expression for the WHILE loop at line %d\n\n", yylineno);}
#line 1942 "parser.tab.c"
    break;

  case 106: /* $@24: %empty  */
#line 268 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the WHILE loop at line %d\n\n", yylineno);}
#line 1948 "parser.tab.c"
    break;

  case 108: /* ERRONOUS_WHILE_STT: WHILE EXPRESSION ':' error '}'  */
#line 269 "parser.y"
                                                                 {printf("\n\n=====ERROR====\n Missing '{' for the WHILE loop at line %d\n\n", yylineno);}
#line 1954 "parser.tab.c"
    break;

  case 110: /* $@25: %empty  */
#line 279 "parser.y"
                        {in_loop = 1;}
#line 1960 "parser.tab.c"
    break;

  case 111: /* $@26: %empty  */
#line 279 "parser.y"
                                                                        {in_loop = 0;}
#line 1966 "parser.tab.c"
    break;

  case 113: /* assignmentSTT: IDENTIFIER EQ EXPRESSION SEMICOLON  */
#line 284 "parser.y"
                                                            {printf("#[Parsed_Assignment]# ");}
#line 1972 "parser.tab.c"
    break;

  case 114: /* $@27: %empty  */
#line 289 "parser.y"
                    {scope_start();}
#line 1978 "parser.tab.c"
    break;

  case 115: /* $@28: %empty  */
#line 289 "parser.y"
                                                 {scope_end();}
#line 1984 "parser.tab.c"
    break;

  case 116: /* BLOCK: '{' $@27 PROGRAM '}' $@28  */
#line 289 "parser.y"
                                                                                    {printf("#[Parsed_Block]# ");}
#line 1990 "parser.tab.c"
    break;

  case 117: /* FUNC_CALL: IDENTIFIER '(' USED_ARGS ')'  */
#line 296 "parser.y"
                                                        {printf("#[Parsed_Func_Call]# ");}
#line 1996 "parser.tab.c"
    break;

  case 118: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 297 "parser.y"
                                                        {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 2002 "parser.tab.c"
    break;

  case 120: /* USED_ARGS: error ',' USED_ARGS  */
#line 302 "parser.y"
                                                        {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 2008 "parser.tab.c"
    break;

  case 124: /* EXPRESSION: DIGIT  */
#line 310 "parser.y"
                        { symbolTable[st_index-1].intValue= (yyvsp[0].num) ;}
#line 2014 "parser.tab.c"
    break;

  case 125: /* EXPRESSION: FLOAT_DIGIT  */
#line 311 "parser.y"
                              { symbolTable[st_index-1].floatValue= (yyvsp[0].float_val) ;}
#line 2020 "parser.tab.c"
    break;

  case 126: /* EXPRESSION: BOOL_LITERAL  */
#line 312 "parser.y"
                                { symbolTable[st_index-1].boolValue= (yyvsp[0].bool_val) ;}
#line 2026 "parser.tab.c"
    break;

  case 127: /* EXPRESSION: STRING_LITERAL  */
#line 313 "parser.y"
                                  { symbolTable[st_index-1].strValue= (yyvsp[0].str) ;}
#line 2032 "parser.tab.c"
    break;

  case 149: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 344 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 2038 "parser.tab.c"
    break;

  case 150: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 345 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 2044 "parser.tab.c"
    break;

  case 151: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 346 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 2050 "parser.tab.c"
    break;

  case 152: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 347 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 2056 "parser.tab.c"
    break;

  case 153: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 348 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 2062 "parser.tab.c"
    break;

  case 154: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 349 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 2068 "parser.tab.c"
    break;

  case 155: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 350 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 2074 "parser.tab.c"
    break;

  case 156: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 351 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 2080 "parser.tab.c"
    break;

  case 157: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 352 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 2086 "parser.tab.c"
    break;

  case 158: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 353 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 2092 "parser.tab.c"
    break;

  case 159: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 354 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 2098 "parser.tab.c"
    break;

  case 160: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 355 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 2104 "parser.tab.c"
    break;

  case 161: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 356 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 2110 "parser.tab.c"
    break;

  case 162: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 357 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 2116 "parser.tab.c"
    break;

  case 163: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 358 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 2122 "parser.tab.c"
    break;

  case 164: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 359 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 2128 "parser.tab.c"
    break;

  case 165: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 360 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 2134 "parser.tab.c"
    break;


#line 2138 "parser.tab.c"

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

#line 379 "parser.y"




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
