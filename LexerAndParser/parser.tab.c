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
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_53_4 = 53,                      /* $@4  */
  YYSYMBOL_ERRONOUS_SWITCH_STT = 54,       /* ERRONOUS_SWITCH_STT  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_57_7 = 57,                      /* $@7  */
  YYSYMBOL_58_8 = 58,                      /* $@8  */
  YYSYMBOL_FUNC_CALL = 59,                 /* FUNC_CALL  */
  YYSYMBOL_USED_ARGS = 60,                 /* USED_ARGS  */
  YYSYMBOL_FUNC_DECLARATION_STT = 61,      /* FUNC_DECLARATION_STT  */
  YYSYMBOL_62_9 = 62,                      /* $@9  */
  YYSYMBOL_63_10 = 63,                     /* $@10  */
  YYSYMBOL_ARGS = 64,                      /* ARGS  */
  YYSYMBOL_ARG_DECL = 65,                  /* ARG_DECL  */
  YYSYMBOL_ENUM_DECLARATION_STT = 66,      /* ENUM_DECLARATION_STT  */
  YYSYMBOL_ENUM_ARGS = 67,                 /* ENUM_ARGS  */
  YYSYMBOL_ENUM_DEFINED_ARGS = 68,         /* ENUM_DEFINED_ARGS  */
  YYSYMBOL_IF_STT = 69,                    /* IF_STT  */
  YYSYMBOL_WHILE_STT = 70,                 /* WHILE_STT  */
  YYSYMBOL_DO_WHILE_STT = 71,              /* DO_WHILE_STT  */
  YYSYMBOL_FOR_STT = 72,                   /* FOR_STT  */
  YYSYMBOL_73_11 = 73,                     /* $@11  */
  YYSYMBOL_74_12 = 74,                     /* $@12  */
  YYSYMBOL_assignmentSTT = 75,             /* assignmentSTT  */
  YYSYMBOL_BLOCK = 76,                     /* BLOCK  */
  YYSYMBOL_77_13 = 77,                     /* $@13  */
  YYSYMBOL_78_14 = 78,                     /* $@14  */
  YYSYMBOL_EXPRESSION = 79,                /* EXPRESSION  */
  YYSYMBOL_COMPARISONSTT = 80,             /* COMPARISONSTT  */
  YYSYMBOL_ERRONOUS_COMPARISONSTT = 81     /* ERRONOUS_COMPARISONSTT  */
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
#define YYLAST   945

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

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
       0,    97,    97,    98,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   124,   125,
     126,   127,   131,   131,   132,   132,   133,   134,   139,   140,
     141,   142,   146,   147,   150,   151,   151,   152,   152,   153,
     157,   157,   158,   158,   159,   159,   160,   160,   165,   166,
     170,   171,   172,   173,   177,   177,   178,   178,   182,   183,
     184,   188,   192,   193,   196,   197,   200,   201,   205,   206,
     207,   211,   215,   219,   219,   219,   223,   227,   227,   227,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280
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
  "$@2", "DECLARATION_TAIL", "SWITCH_STT", "CASES", "$@3", "$@4",
  "ERRONOUS_SWITCH_STT", "$@5", "$@6", "$@7", "$@8", "FUNC_CALL",
  "USED_ARGS", "FUNC_DECLARATION_STT", "$@9", "$@10", "ARGS", "ARG_DECL",
  "ENUM_DECLARATION_STT", "ENUM_ARGS", "ENUM_DEFINED_ARGS", "IF_STT",
  "WHILE_STT", "DO_WHILE_STT", "FOR_STT", "$@11", "$@12", "assignmentSTT",
  "BLOCK", "$@13", "$@14", "EXPRESSION", "COMPARISONSTT",
  "ERRONOUS_COMPARISONSTT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-137)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-96)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -137,   210,  -137,   792,  -137,  -137,  -137,  -137,   -25,   410,
     -26,   427,  -137,  -137,  -137,   -19,    18,     1,   445,  -137,
     169,  -137,  -137,   427,  -137,   -13,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,   818,  -137,
    -137,    21,   120,  -137,    32,   427,   427,   427,   427,    47,
    -137,  -137,    37,   409,    87,   427,   665,  -137,   687,    69,
      45,  -137,     6,    14,   125,    52,   427,   306,  -137,   731,
    -137,    62,   427,   333,   349,  -137,   374,   392,   427,   427,
     462,   480,   497,   515,   427,   106,   427,    83,  -137,   125,
     125,   918,   918,  -137,   168,   752,   -19,   290,   -19,    67,
      76,    77,    90,    11,  -137,   838,   635,    85,   613,   250,
    -137,    10,   168,    10,    73,    14,   532,   106,   112,   550,
      83,  -137,     5,  -137,   106,   151,   125,    14,   125,    14,
     125,     3,   918,     3,   918,   106,   106,    96,    57,  -137,
     591,   109,   290,  -137,   427,   -10,    97,    98,   110,   107,
     117,  -137,    56,  -137,   306,  -137,   306,  -137,   427,   567,
    -137,  -137,    75,  -137,    14,   106,   112,   106,  -137,  -137,
     168,   119,   -19,   290,   773,   427,   127,  -137,  -137,    56,
     123,    56,    56,   427,   427,   130,  -137,  -137,  -137,   858,
     659,   878,  -137,   -19,  -137,  -137,  -137,   122,  -137,   633,
     136,  -137,   143,    56,   144,   153,   898,   709,  -137,  -137,
    -137,  -137,   -19,  -137,  -137,   156,  -137,   157,  -137,  -137,
     154,    12,  -137,   -19,   179,  -137,  -137,   -19,  -137,    56,
    -137,    56,    56,  -137,  -137,  -137
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,     0,    18,    19,    20,    21,     0,     0,
       0,     0,    83,    84,    85,     0,     0,     0,     0,    81,
       0,    82,    77,     0,     2,     0,     4,    12,    33,    94,
       5,    13,     8,     9,    11,    10,     6,    14,     0,    93,
     105,     0,     0,    15,     0,     0,     0,     0,     0,     0,
      16,    17,     0,     0,     0,     0,     0,    73,     0,     0,
       0,    40,     0,   114,   104,     0,     0,     0,     3,     0,
      24,    22,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,   108,    27,   110,
     112,   115,   117,    26,    60,     0,     0,     0,     0,     0,
       0,     0,    42,     0,    49,     0,     0,     0,    52,     0,
      95,     0,    60,     0,    91,   107,     0,    96,   109,     0,
      97,    86,    88,    87,    89,    90,    92,   111,   100,   113,
     101,   116,   102,   118,   103,   121,   119,     0,     0,    59,
       0,    68,     0,    71,     0,    65,     0,     0,     0,     0,
       0,    46,     0,    76,     0,    48,     0,    78,     0,     0,
      31,    25,     0,    23,   122,    99,   120,    98,    61,    56,
       0,     0,     0,     0,     0,     0,     0,    62,    63,     0,
       0,     0,     0,     0,     0,     0,    51,    50,    79,     0,
       0,     0,    54,     0,    58,    70,    69,     0,    72,    67,
      65,    64,     0,     0,     0,     0,    35,     0,    32,    29,
      30,    28,     0,    57,    74,     0,    41,     0,    45,    47,
       0,     0,    55,     0,     0,    66,    43,     0,    37,     0,
      75,     0,     0,    34,    36,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,   133,   -93,   -88,  -137,  -137,  -137,    89,  -137,  -136,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,   -94,  -137,
    -137,  -137,    86,    33,  -137,    28,     7,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,   -15,  -137,  -137,    -8,  -137,  -137
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    24,    25,    26,   113,   111,   161,    27,   185,
     220,   232,    28,   101,   149,   150,   182,    29,   107,    30,
     212,   193,   138,   139,    31,   146,   147,    32,    33,    34,
      35,    97,   223,    36,    37,    68,   188,    38,    39,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    56,    61,    58,   142,   175,   137,   102,    70,    52,
      64,   158,   151,   228,    57,    69,    41,    42,    73,    74,
      22,    71,    53,    77,   137,   159,   160,    41,    42,    45,
      46,   176,    12,    85,    87,    62,    84,    89,    90,    91,
      92,    13,    14,   202,   103,   204,   205,    95,    88,   173,
     152,    22,    60,    18,    19,    54,    21,   183,   105,   108,
     186,    23,   187,    93,   114,   117,   120,   217,   122,   124,
     125,   126,   128,   130,   132,   134,   135,    94,   136,    99,
     197,   141,   137,   143,   100,   184,    73,    74,    65,   104,
      76,    77,   -39,   233,   169,   234,   235,    74,   170,   -80,
     -80,   -80,   112,   -80,   -80,   -80,   -80,   144,   165,   -80,
     145,   167,   192,   -80,   -80,   148,   170,   -80,   -80,    73,
      74,    53,   155,   -80,   -80,   -80,    42,    67,   -80,   -44,
     168,    12,   172,   177,   178,    86,   174,    72,    73,    74,
      13,    14,    76,    77,    78,   180,   108,    79,   108,   179,
     189,   191,    18,    19,    54,    21,   181,   196,   195,   214,
      23,   200,   203,    72,    73,    74,   208,   199,    76,    77,
      65,     4,     5,     6,     7,   206,   207,   176,   213,   216,
     218,   -80,   -80,   -80,    66,   -80,   -80,   -80,   -80,   219,
     224,   -80,   227,   226,   175,   -80,   -80,   222,   162,   -80,
     -80,   109,   163,   194,   201,     0,   229,     0,   230,    67,
       2,     3,   231,     4,     5,     6,     7,     8,     9,    10,
      11,    12,   225,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,    15,    16,     0,     0,    17,     0,
       0,     0,    18,    19,    20,    21,     0,     0,     0,    22,
      23,     3,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,    15,    16,     0,     0,    17,     0,
       0,     0,    18,    19,    20,    21,   157,     0,     0,    22,
      23,     3,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,     0,     0,     0,     0,   106,     0,     0,
      13,    14,     0,     0,    15,    16,     0,    12,    17,     0,
       0,     0,    18,    19,    20,    21,    13,    14,     0,    22,
      23,     0,     0,     0,   115,     0,     0,     0,    18,    19,
      54,    21,     0,   -53,    12,     0,    23,     0,   116,     0,
     118,     0,     0,    13,    14,     0,     0,     0,     0,     0,
      12,     0,     0,     0,   119,    18,    19,    54,    21,    13,
      14,     0,     0,    23,     0,    53,     0,     0,     0,     0,
       0,    18,    19,    54,    21,    12,     0,     0,     0,    23,
       0,   121,     0,    53,    13,    14,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,    18,    19,    54,    21,
     123,    53,    13,    14,    23,     0,     0,     0,     0,     0,
       0,    12,    41,    42,    18,    19,    54,    21,    53,     0,
      13,    14,    23,     0,     0,    45,    46,     0,    12,    47,
      48,     0,    18,    19,    54,    21,    63,    13,    14,     0,
      55,     0,     0,     0,     0,     0,    12,     0,     0,    18,
      19,    54,    21,   127,     0,    13,    14,    23,     0,     0,
       0,     0,     0,    12,     0,     0,     0,    18,    19,    54,
      21,   129,    13,    14,     0,    23,     0,     0,     0,     0,
       0,    12,     0,     0,    18,    19,    54,    21,   131,     0,
      13,    14,    23,     0,     0,     0,     0,     0,    12,     0,
       0,     0,    18,    19,    54,    21,   133,    13,    14,     0,
      23,     0,     0,     0,     0,     0,    12,     0,     0,    18,
      19,    54,    21,   164,     0,    13,    14,    23,     0,     0,
       0,     0,     0,    12,     0,     0,     0,    18,    19,    54,
      21,   166,    13,    14,     0,    23,     0,     0,     0,     0,
       0,    12,     0,     0,    18,    19,    54,    21,   190,     0,
      13,    14,    23,     0,     0,     0,     0,     0,    12,     0,
       0,     0,    18,    19,    54,    21,     0,    13,    14,     0,
      23,     0,   171,     0,     0,     0,     0,     0,     0,    18,
      19,    54,    21,   -95,   -95,   -95,     0,    23,   -95,   -95,
     -95,     0,     0,   -95,     0,     0,     0,   -95,   -95,     0,
       0,   -95,   -95,     0,     0,    72,    73,    74,     0,   -95,
      76,    77,    78,     0,     0,    79,     0,     0,     0,    80,
      81,     0,     0,    82,    83,    72,    73,    74,    41,    42,
      76,    77,    78,     0,   156,    79,     0,     0,     0,    80,
      81,    45,    46,    82,    83,    47,    48,     0,     0,     0,
       0,     0,    41,    42,   215,   210,   154,    72,    73,    74,
       0,     0,    76,    77,    78,    45,    46,    79,     0,    47,
      48,    80,    81,     0,     0,    82,    83,     0,     0,    72,
      73,    74,     0,    96,    76,    77,    78,     0,     0,    79,
       0,     0,     0,    80,    81,     0,     0,    82,    83,     0,
       0,    72,    73,    74,     0,    98,    76,    77,    78,     0,
       0,    79,     0,     0,     0,    80,    81,     0,     0,    82,
      83,     0,     0,    72,    73,    74,     0,   221,    76,    77,
      78,     0,     0,    79,     0,     0,     0,    80,    81,     0,
       0,    82,    83,     0,    72,    73,    74,     0,   110,    76,
      77,    78,     0,     0,    79,     0,     0,     0,    80,    81,
       0,     0,    82,    83,     0,    72,    73,    74,     0,   140,
      76,    77,    78,     0,     0,    79,     0,     0,     0,    80,
      81,     0,     0,    82,    83,    41,    42,     0,    43,     0,
     198,     0,     0,    44,     0,     0,     0,     0,    45,    46,
       0,     0,    47,    48,     0,     0,    49,     0,    50,    51,
      72,    73,    74,     0,    75,    76,    77,    78,     0,     0,
      79,     0,     0,     0,    80,    81,     0,     0,    82,    83,
      72,    73,    74,     0,   153,    76,    77,    78,     0,     0,
      79,     0,     0,     0,    80,    81,     0,     0,    82,    83,
      72,    73,    74,     0,   209,    76,    77,    78,     0,     0,
      79,     0,     0,     0,    80,    81,     0,     0,    82,    83,
      72,    73,    74,     0,   211,    76,    77,    78,     0,     0,
      79,     0,     0,     0,    80,    81,     0,     0,    82,    83,
      72,    73,    74,     0,     0,    76,    77,    78,     0,     0,
      79,     0,     0,     0,    80,    81,     0,     0,    82,    83,
      72,    73,    74,     0,     0,    76,    77,    78,     0,     0,
      79,     0,     0,     0,    80,    81
};

static const yytype_int16 yycheck[] =
{
      15,     9,     1,    11,    97,    15,    94,     1,    21,    34,
      18,     1,     1,     1,    40,    23,    13,    14,    13,    14,
      39,    34,     1,    18,   112,    15,    16,    13,    14,    26,
      27,    41,    11,    41,    42,    34,    15,    45,    46,    47,
      48,    20,    21,   179,    38,   181,   182,    55,    16,   142,
      39,    39,    34,    32,    33,    34,    35,     1,    66,    67,
     154,    40,   156,    16,    72,    73,    74,   203,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    40,    86,    10,
     173,    96,   170,    98,    39,    29,    13,    14,     1,    37,
      17,    18,    36,   229,    37,   231,   232,    14,    41,    12,
      13,    14,    40,    16,    17,    18,    19,    40,   116,    22,
      34,   119,    37,    26,    27,    38,    41,    30,    31,    13,
      14,     1,    37,    36,    37,    38,    14,    40,    41,    39,
      34,    11,    23,    36,    36,    15,   144,    12,    13,    14,
      20,    21,    17,    18,    19,    38,   154,    22,   156,    39,
     158,   159,    32,    33,    34,    35,    39,   172,    39,    37,
      40,    34,    39,    12,    13,    14,    36,   175,    17,    18,
       1,     3,     4,     5,     6,   183,   184,    41,   193,    36,
      36,    12,    13,    14,    15,    16,    17,    18,    19,    36,
      34,    22,    38,    36,    15,    26,    27,   212,   112,    30,
      31,    68,   113,   170,   176,    -1,   221,    -1,   223,    40,
       0,     1,   227,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    -1,    -1,    24,    25,    -1,    -1,    28,    -1,
      -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    -1,    -1,    24,    25,    -1,    -1,    28,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      20,    21,    -1,    -1,    24,    25,    -1,    11,    28,    -1,
      -1,    -1,    32,    33,    34,    35,    20,    21,    -1,    39,
      40,    -1,    -1,    -1,     1,    -1,    -1,    -1,    32,    33,
      34,    35,    -1,    37,    11,    -1,    40,    -1,    15,    -1,
       1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    15,    32,    33,    34,    35,    20,
      21,    -1,    -1,    40,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    11,    -1,    -1,    -1,    40,
      -1,    17,    -1,     1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    32,    33,    34,    35,
      18,     1,    20,    21,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    13,    14,    32,    33,    34,    35,     1,    -1,
      20,    21,    40,    -1,    -1,    26,    27,    -1,    11,    30,
      31,    -1,    32,    33,    34,    35,     1,    20,    21,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    32,
      33,    34,    35,     1,    -1,    20,    21,    40,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    32,    33,    34,
      35,     1,    20,    21,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    32,    33,    34,    35,     1,    -1,
      20,    21,    40,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    32,    33,    34,    35,     1,    20,    21,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    32,
      33,    34,    35,     1,    -1,    20,    21,    40,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    32,    33,    34,
      35,     1,    20,    21,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    32,    33,    34,    35,     1,    -1,
      20,    21,    40,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    32,    33,    34,    35,    -1,    20,    21,    -1,
      40,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    12,    13,    14,    -1,    40,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    -1,    -1,    12,    13,    14,    -1,    38,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    12,    13,    14,    13,    14,
      17,    18,    19,    -1,    41,    22,    -1,    -1,    -1,    26,
      27,    26,    27,    30,    31,    30,    31,    -1,    -1,    -1,
      -1,    -1,    13,    14,    41,    16,    41,    12,    13,    14,
      -1,    -1,    17,    18,    19,    26,    27,    22,    -1,    30,
      31,    26,    27,    -1,    -1,    30,    31,    -1,    -1,    12,
      13,    14,    -1,    38,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,
      -1,    12,    13,    14,    -1,    38,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,
      31,    -1,    -1,    12,    13,    14,    -1,    38,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    -1,    12,    13,    14,    -1,    37,    17,
      18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    -1,    12,    13,    14,    -1,    37,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    13,    14,    -1,    16,    -1,
      37,    -1,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    -1,    -1,    34,    -1,    36,    37,
      12,    13,    14,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      12,    13,    14,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      12,    13,    14,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      12,    13,    14,    -1,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      12,    13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      12,    13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    20,    21,    24,    25,    28,    32,    33,
      34,    35,    39,    40,    44,    45,    46,    50,    54,    59,
      61,    66,    69,    70,    71,    72,    75,    76,    79,    80,
      81,    13,    14,    16,    21,    26,    27,    30,    31,    34,
      36,    37,    34,     1,    34,    40,    79,    40,    79,    76,
      34,     1,    34,     1,    79,     1,    15,    40,    77,    79,
      21,    34,    12,    13,    14,    16,    17,    18,    19,    22,
      26,    27,    30,    31,    15,    79,    15,    79,    16,    79,
      79,    79,    79,    16,    40,    79,    38,    73,    38,    10,
      39,    55,     1,    38,    37,    79,     1,    60,    79,    43,
      37,    48,    40,    47,    79,     1,    15,    79,     1,    15,
      79,    17,    79,    18,    79,    79,    79,     1,    79,     1,
      79,     1,    79,     1,    79,    79,    79,    45,    64,    65,
      37,    76,    44,    76,    40,    34,    67,    68,    38,    56,
      57,     1,    39,    16,    41,    37,    41,    36,     1,    15,
      16,    49,    64,    49,     1,    79,     1,    79,    34,    37,
      41,     1,    23,    44,    79,    15,    41,    36,    36,    39,
      38,    39,    58,     1,    29,    51,    60,    60,    78,    79,
       1,    79,    37,    63,    65,    39,    76,    44,    37,    79,
      34,    67,    51,    39,    51,    51,    79,    79,    36,    16,
      16,    16,    62,    76,    37,    41,    36,    51,    36,    36,
      52,    38,    76,    74,    34,    68,    36,    38,     1,    76,
      76,    76,    53,    51,    51,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    45,    45,
      45,    45,    47,    46,    48,    46,    46,    46,    49,    49,
      49,    49,    50,    50,    51,    52,    51,    53,    51,    51,
      55,    54,    56,    54,    57,    54,    58,    54,    59,    59,
      60,    60,    60,    60,    62,    61,    63,    61,    64,    64,
      64,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      69,    70,    71,    73,    74,    72,    75,    77,    78,    76,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     0,     4,     0,     4,     3,     3,     3,     3,
       3,     1,     6,     1,     5,     0,     6,     0,     6,     0,
       0,     7,     0,     8,     0,     7,     0,     7,     4,     3,
       3,     3,     1,     0,     0,     7,     0,     7,     3,     1,
       0,     2,     5,     5,     3,     1,     5,     3,     4,     6,
       6,     4,     6,     0,     0,     9,     4,     0,     0,     5,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     4,     4,
       3,     3,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     4,
       4,     4,     4
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
#line 97 "parser.y"
                                                            {printf("\n ----> Parsing Succesful :D <---- \n");}
#line 1492 "parser.tab.c"
    break;

  case 5: /* STATEMENT: FUNC_DECLARATION_STT  */
#line 103 "parser.y"
                                                            {printf("#[Parsed_Func_Declaration]# ");}
#line 1498 "parser.tab.c"
    break;

  case 8: /* STATEMENT: IF_STT  */
#line 106 "parser.y"
                                                            {printf("#[Parsed_If_STT]# ");}
#line 1504 "parser.tab.c"
    break;

  case 9: /* STATEMENT: WHILE_STT  */
#line 107 "parser.y"
                                                            {printf("#[Parsed_While_LOOP]# ");}
#line 1510 "parser.tab.c"
    break;

  case 10: /* STATEMENT: FOR_STT  */
#line 108 "parser.y"
                                                            {printf("#[Parsed_For_LOOP]# ");}
#line 1516 "parser.tab.c"
    break;

  case 11: /* STATEMENT: DO_WHILE_STT  */
#line 109 "parser.y"
                                                            {printf("#[Parsed_DO_WHILE_LOOP]# ");}
#line 1522 "parser.tab.c"
    break;

  case 12: /* STATEMENT: SWITCH_STT  */
#line 110 "parser.y"
                                                            {printf("#[Parsed_SWITCH_STT]# ");}
#line 1528 "parser.tab.c"
    break;

  case 13: /* STATEMENT: ENUM_DECLARATION_STT  */
#line 111 "parser.y"
                                                            {printf("#[Parsed_Enum_Declaration]# ");}
#line 1534 "parser.tab.c"
    break;

  case 15: /* STATEMENT: error SEMICOLON  */
#line 113 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1540 "parser.tab.c"
    break;

  case 16: /* STATEMENT: error '}'  */
#line 114 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1546 "parser.tab.c"
    break;

  case 17: /* STATEMENT: error ')'  */
#line 115 "parser.y"
                                                            {printf("\n\n=====ERROR====\n ERRONOUS STATEMENT at line %d\n\n", yylineno);}
#line 1552 "parser.tab.c"
    break;

  case 18: /* TYPE: INT  */
#line 124 "parser.y"
                    { (yyval.str) = "int"; }
#line 1558 "parser.tab.c"
    break;

  case 19: /* TYPE: FLOAT  */
#line 125 "parser.y"
                        { (yyval.str) = "float"; }
#line 1564 "parser.tab.c"
    break;

  case 20: /* TYPE: BOOL  */
#line 126 "parser.y"
                        { (yyval.str) = "bool"; }
#line 1570 "parser.tab.c"
    break;

  case 21: /* TYPE: STRING  */
#line 127 "parser.y"
                         { (yyval.str) = "string"; }
#line 1576 "parser.tab.c"
    break;

  case 22: /* $@1: %empty  */
#line 131 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",0); }
#line 1582 "parser.tab.c"
    break;

  case 23: /* DECLARATION_STT: TYPE IDENTIFIER $@1 DECLARATION_TAIL  */
#line 131 "parser.y"
                                                                                            {printf("#[Parsed_Declaration]# ");}
#line 1588 "parser.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 132 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"const",0);}
#line 1594 "parser.tab.c"
    break;

  case 25: /* DECLARATION_STT: TYPE CONSTANT $@2 DECLARATION_TAIL  */
#line 132 "parser.y"
                                                                                  {printf("#[Parsed_CONST_Declaration]# "); }
#line 1600 "parser.tab.c"
    break;

  case 26: /* DECLARATION_STT: error IDENTIFIER SEMICOLON  */
#line 133 "parser.y"
                                                              {printf("\n\n=====ERROR====\n MISSING variable type at line %d\n\n", yylineno);}
#line 1606 "parser.tab.c"
    break;

  case 27: /* DECLARATION_STT: error CONSTANT SEMICOLON  */
#line 134 "parser.y"
                                                              {printf("\n\n=====ERROR====\n MISSING constant type at line %d\n\n", yylineno);}
#line 1612 "parser.tab.c"
    break;

  case 29: /* DECLARATION_TAIL: error EXPRESSION SEMICOLON  */
#line 140 "parser.y"
                                                              {printf("\n\n=====ERROR====\n MISSING '=' at line %d\n\n", yylineno);}
#line 1618 "parser.tab.c"
    break;

  case 30: /* DECLARATION_TAIL: EQ error SEMICOLON  */
#line 141 "parser.y"
                                                              {printf("\n\n=====ERROR====\n unexpected '=' without second operand at line %d\n\n", yylineno);}
#line 1624 "parser.tab.c"
    break;

  case 35: /* $@3: %empty  */
#line 151 "parser.y"
                                   {printf("\n\n=====ERROR====\n MISSING 'case' at line %d\n\n", yylineno);}
#line 1630 "parser.tab.c"
    break;

  case 37: /* $@4: %empty  */
#line 152 "parser.y"
                                            {printf("\n\n=====ERROR====\n MISSING case block at line %d\n\n", yylineno);}
#line 1636 "parser.tab.c"
    break;

  case 40: /* $@5: %empty  */
#line 157 "parser.y"
                             {printf("\n\n=====ERROR====\n MISSING identifier for switch statement at line %d\n\n", yylineno);}
#line 1642 "parser.tab.c"
    break;

  case 42: /* $@6: %empty  */
#line 158 "parser.y"
                                          {printf("\n\n=====ERROR====\n unexpected identifier %s at switch statement at line %d\n\n",yylval, yylineno); }
#line 1648 "parser.tab.c"
    break;

  case 44: /* $@7: %empty  */
#line 159 "parser.y"
                                          {printf("\n\n=====ERROR====\n MISSING colon ':' for switch statement (switchs must have a colon) at line %d\n\n", yylineno);}
#line 1654 "parser.tab.c"
    break;

  case 46: /* $@8: %empty  */
#line 160 "parser.y"
                                              {printf("\n\n=====ERROR====\n MISSING '{' for switch statement at line %d\n\n", yylineno);}
#line 1660 "parser.tab.c"
    break;

  case 48: /* FUNC_CALL: IDENTIFIER '(' USED_ARGS ')'  */
#line 165 "parser.y"
                                                        {printf("#[Parsed_Func_Call]# ");}
#line 1666 "parser.tab.c"
    break;

  case 49: /* FUNC_CALL: IDENTIFIER error ')'  */
#line 166 "parser.y"
                                              {printf("\n\n=====ERROR====\n unhandled function parenthesis at line %d\n\n", yylineno);}
#line 1672 "parser.tab.c"
    break;

  case 51: /* USED_ARGS: error ',' USED_ARGS  */
#line 171 "parser.y"
                                                 {printf("\n\n=====ERROR====\n Missing first argument in function's argument list or erronous ',' at line %d\n\n", yylineno);}
#line 1678 "parser.tab.c"
    break;

  case 54: /* $@9: %empty  */
#line 177 "parser.y"
                                             {st_insert((yyvsp[-4].str), (yyvsp[-3].str),"func",0);}
#line 1684 "parser.tab.c"
    break;

  case 56: /* $@10: %empty  */
#line 178 "parser.y"
                                               {st_insert("void", (yyvsp[-3].str),"func",0);}
#line 1690 "parser.tab.c"
    break;

  case 61: /* ARG_DECL: TYPE IDENTIFIER  */
#line 188 "parser.y"
                                {st_insert((yyvsp[-1].str), (yyvsp[0].str),"var",1);}
#line 1696 "parser.tab.c"
    break;

  case 62: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_ARGS '}'  */
#line 192 "parser.y"
                                                   { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 1702 "parser.tab.c"
    break;

  case 63: /* ENUM_DECLARATION_STT: ENUM IDENTIFIER '{' ENUM_DEFINED_ARGS '}'  */
#line 193 "parser.y"
                                                            { st_insert("enum" , (yyvsp[-3].str), "var" , 0); }
#line 1708 "parser.tab.c"
    break;

  case 70: /* IF_STT: IF '(' EXPRESSION ')' error '{'  */
#line 207 "parser.y"
                                                              {printf("\n\n=====ERROR====\n Missing ':' for the IF statement at line %d\n\n", yylineno);}
#line 1714 "parser.tab.c"
    break;

  case 73: /* $@11: %empty  */
#line 219 "parser.y"
                        {in_loop = 1;}
#line 1720 "parser.tab.c"
    break;

  case 74: /* $@12: %empty  */
#line 219 "parser.y"
                                                                        {in_loop = 0;}
#line 1726 "parser.tab.c"
    break;

  case 76: /* assignmentSTT: IDENTIFIER EQ EXPRESSION SEMICOLON  */
#line 223 "parser.y"
                                                            {printf("#[Parsed_Assignment]# ");}
#line 1732 "parser.tab.c"
    break;

  case 77: /* $@13: %empty  */
#line 227 "parser.y"
                    {scope_start();}
#line 1738 "parser.tab.c"
    break;

  case 78: /* $@14: %empty  */
#line 227 "parser.y"
                                                 {scope_end();}
#line 1744 "parser.tab.c"
    break;

  case 79: /* BLOCK: '{' $@13 PROGRAM '}' $@14  */
#line 227 "parser.y"
                                                                                    {printf("#[Parsed_Block]# ");}
#line 1750 "parser.tab.c"
    break;

  case 81: /* EXPRESSION: DIGIT  */
#line 233 "parser.y"
                        { symbolTable[st_index-1].intValue= (yyvsp[0].num) ;}
#line 1756 "parser.tab.c"
    break;

  case 82: /* EXPRESSION: FLOAT_DIGIT  */
#line 234 "parser.y"
                              { symbolTable[st_index-1].floatValue= (yyvsp[0].float_val) ;}
#line 1762 "parser.tab.c"
    break;

  case 83: /* EXPRESSION: BOOL_LITERAL  */
#line 235 "parser.y"
                                { symbolTable[st_index-1].boolValue= (yyvsp[0].bool_val) ;}
#line 1768 "parser.tab.c"
    break;

  case 84: /* EXPRESSION: STRING_LITERAL  */
#line 236 "parser.y"
                                  { symbolTable[st_index-1].strValue= (yyvsp[0].str) ;}
#line 1774 "parser.tab.c"
    break;

  case 106: /* ERRONOUS_COMPARISONSTT: error GT EXPRESSION  */
#line 264 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>' at line %d\n\n", yylineno);}
#line 1780 "parser.tab.c"
    break;

  case 107: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT error  */
#line 265 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>' at line %d\n\n", yylineno);}
#line 1786 "parser.tab.c"
    break;

  case 108: /* ERRONOUS_COMPARISONSTT: error LT EXPRESSION  */
#line 266 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<' at line %d\n\n", yylineno);}
#line 1792 "parser.tab.c"
    break;

  case 109: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT error  */
#line 267 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<' at line %d\n\n", yylineno);}
#line 1798 "parser.tab.c"
    break;

  case 110: /* ERRONOUS_COMPARISONSTT: error EQUALITY EXPRESSION  */
#line 268 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '==' at line %d\n\n", yylineno);}
#line 1804 "parser.tab.c"
    break;

  case 111: /* ERRONOUS_COMPARISONSTT: EXPRESSION EQUALITY error  */
#line 269 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '==' at line %d\n\n", yylineno);}
#line 1810 "parser.tab.c"
    break;

  case 112: /* ERRONOUS_COMPARISONSTT: error NEG_EQUALITY EXPRESSION  */
#line 270 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '!=' at line %d\n\n", yylineno);}
#line 1816 "parser.tab.c"
    break;

  case 113: /* ERRONOUS_COMPARISONSTT: EXPRESSION NEG_EQUALITY error  */
#line 271 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '!=' at line %d\n\n", yylineno);}
#line 1822 "parser.tab.c"
    break;

  case 114: /* ERRONOUS_COMPARISONSTT: LOGIC_NOT error  */
#line 272 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after the negating operator '!' at line %d\n\n", yylineno);}
#line 1828 "parser.tab.c"
    break;

  case 115: /* ERRONOUS_COMPARISONSTT: error LOGIC_AND EXPRESSION  */
#line 273 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'and' operator at line %d\n\n", yylineno);}
#line 1834 "parser.tab.c"
    break;

  case 116: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_AND error  */
#line 274 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'and' operator at line %d\n\n", yylineno);}
#line 1840 "parser.tab.c"
    break;

  case 117: /* ERRONOUS_COMPARISONSTT: error LOGIC_OR EXPRESSION  */
#line 275 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before 'or' operator at line %d\n\n", yylineno);}
#line 1846 "parser.tab.c"
    break;

  case 118: /* ERRONOUS_COMPARISONSTT: EXPRESSION LOGIC_OR error  */
#line 276 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after 'or' operator at line %d\n\n", yylineno);}
#line 1852 "parser.tab.c"
    break;

  case 119: /* ERRONOUS_COMPARISONSTT: error LT EQ EXPRESSION  */
#line 277 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '<=' operator at line %d\n\n", yylineno);}
#line 1858 "parser.tab.c"
    break;

  case 120: /* ERRONOUS_COMPARISONSTT: EXPRESSION LT EQ error  */
#line 278 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '<=' operator at line %d\n\n", yylineno);}
#line 1864 "parser.tab.c"
    break;

  case 121: /* ERRONOUS_COMPARISONSTT: error GT EQ EXPRESSION  */
#line 279 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing left operand before '>=' operator at line %d\n\n", yylineno);}
#line 1870 "parser.tab.c"
    break;

  case 122: /* ERRONOUS_COMPARISONSTT: EXPRESSION GT EQ error  */
#line 280 "parser.y"
                                                                    {printf("\n\n=====ERROR====\n Missing right operand after '>=' operator at line %d\n\n", yylineno);}
#line 1876 "parser.tab.c"
    break;


#line 1880 "parser.tab.c"

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

#line 288 "parser.y"

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
