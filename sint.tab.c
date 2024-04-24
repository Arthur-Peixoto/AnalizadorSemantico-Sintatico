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
#line 1 "sint.y"

    
    #include <iostream>
    #include <stdio.h>
    #include <map>
    #include <vector>
    #include "semanticAnalyzer.cpp"
    using std::vector;
    using std::string;
    using std::cout;
    using std::endl;

    int yylex(void);
    int yyparse(void);
    void yyerror(const char *);

    semanticAnalyzer * semantico = new semanticAnalyzer();

    bool isSubclassOf = false;

    string operadorAtual;
    string classeAtual;
    string precedente;
    string coercao;
    string numCoercao = "";

    vector<string> sintaticErrors;
    string sintClass = "";

    std::string propriedadeAtual;

    

    extern char *yytext;
    extern int yylineno; 


#line 109 "sint.tab.c"

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

#include "sint.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SOME = 3,                       /* SOME  */
  YYSYMBOL_ALL = 4,                        /* ALL  */
  YYSYMBOL_VALUE = 5,                      /* VALUE  */
  YYSYMBOL_MIN = 6,                        /* MIN  */
  YYSYMBOL_MAX = 7,                        /* MAX  */
  YYSYMBOL_EXACTLY = 8,                    /* EXACTLY  */
  YYSYMBOL_THAT = 9,                       /* THAT  */
  YYSYMBOL_NOT = 10,                       /* NOT  */
  YYSYMBOL_OR = 11,                        /* OR  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_ONLY = 13,                      /* ONLY  */
  YYSYMBOL_INVERSE = 14,                   /* INVERSE  */
  YYSYMBOL_CLASS = 15,                     /* CLASS  */
  YYSYMBOL_PROPRIETY = 16,                 /* PROPRIETY  */
  YYSYMBOL_INSTANCY = 17,                  /* INSTANCY  */
  YYSYMBOL_SSYMBOL = 18,                   /* SSYMBOL  */
  YYSYMBOL_DTYPE = 19,                     /* DTYPE  */
  YYSYMBOL_CARDINALIDADE = 20,             /* CARDINALIDADE  */
  YYSYMBOL_RCLASS = 21,                    /* RCLASS  */
  YYSYMBOL_RSUBCLASS = 22,                 /* RSUBCLASS  */
  YYSYMBOL_REQUIVALENT = 23,               /* REQUIVALENT  */
  YYSYMBOL_RINDIVIDUALS = 24,              /* RINDIVIDUALS  */
  YYSYMBOL_RDISJOINT = 25,                 /* RDISJOINT  */
  YYSYMBOL_26_ = 26,                       /* '['  */
  YYSYMBOL_27_ = 27,                       /* ']'  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_classe = 34,                    /* classe  */
  YYSYMBOL_rclass = 35,                    /* rclass  */
  YYSYMBOL_classeComum = 36,               /* classeComum  */
  YYSYMBOL_classeComumProbs = 37,          /* classeComumProbs  */
  YYSYMBOL_classePrimitiva = 38,           /* classePrimitiva  */
  YYSYMBOL_classePrimitivaProbs = 39,      /* classePrimitivaProbs  */
  YYSYMBOL_classeDefinida = 40,            /* classeDefinida  */
  YYSYMBOL_classeDefinidaProbs = 41,       /* classeDefinidaProbs  */
  YYSYMBOL_operprecedente = 42,            /* operprecedente  */
  YYSYMBOL_operprecedenteProbs = 43,       /* operprecedenteProbs  */
  YYSYMBOL_equivalent = 44,                /* equivalent  */
  YYSYMBOL_subclass = 45,                  /* subclass  */
  YYSYMBOL_individuals = 46,               /* individuals  */
  YYSYMBOL_disjoint = 47,                  /* disjoint  */
  YYSYMBOL_requivalent = 48,               /* requivalent  */
  YYSYMBOL_rsubclass = 49,                 /* rsubclass  */
  YYSYMBOL_rindividuals = 50,              /* rindividuals  */
  YYSYMBOL_rdisjoint = 51,                 /* rdisjoint  */
  YYSYMBOL_equivProbs = 52,                /* equivProbs  */
  YYSYMBOL_seqClasses = 53,                /* seqClasses  */
  YYSYMBOL_instancies = 54,                /* instancies  */
  YYSYMBOL_connect = 55,                   /* connect  */
  YYSYMBOL_seqProp = 56,                   /* seqProp  */
  YYSYMBOL_prop = 57,                      /* prop  */
  YYSYMBOL_propName = 58,                  /* propName  */
  YYSYMBOL_only = 59,                      /* only  */
  YYSYMBOL_onlyMultClasses = 60,           /* onlyMultClasses  */
  YYSYMBOL_auxOnlyClass = 61,              /* auxOnlyClass  */
  YYSYMBOL_multClasses = 62,               /* multClasses  */
  YYSYMBOL_className = 63,                 /* className  */
  YYSYMBOL_some = 64,                      /* some  */
  YYSYMBOL_especificardtype = 65,          /* especificardtype  */
  YYSYMBOL_qntd = 66,                      /* qntd  */
  YYSYMBOL_num = 67,                       /* num  */
  YYSYMBOL_dtype = 68,                     /* dtype  */
  YYSYMBOL_value = 69,                     /* value  */
  YYSYMBOL_exactly = 70,                   /* exactly  */
  YYSYMBOL_all = 71                        /* all  */
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
      28,    29,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    50,    51,    52,    53,    54,    57,    60,
      63,    64,    65,    66,    69,    72,    73,    74,    75,    78,
      81,    82,    83,    84,    85,    86,    87,    88,    91,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   111,   112,   115,   116,   117,   118,
     121,   124,   127,   130,   133,   136,   139,   140,   141,   142,
     145,   146,   147,   150,   151,   152,   155,   156,   159,   160,
     161,   162,   163,   164,   167,   168,   169,   170,   171,   172,
     173,   176,   179,   180,   183,   184,   187,   190,   191,   194,
     197,   198,   199,   200,   204,   205,   208,   209,   210,   211,
     214,   217,   220,   221,   222,   225,   226,   229,   230
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
  "\"end of file\"", "error", "\"invalid token\"", "SOME", "ALL", "VALUE",
  "MIN", "MAX", "EXACTLY", "THAT", "NOT", "OR", "AND", "ONLY", "INVERSE",
  "CLASS", "PROPRIETY", "INSTANCY", "SSYMBOL", "DTYPE", "CARDINALIDADE",
  "RCLASS", "RSUBCLASS", "REQUIVALENT", "RINDIVIDUALS", "RDISJOINT", "'['",
  "']'", "'('", "')'", "','", "'{'", "'}'", "$accept", "classe", "rclass",
  "classeComum", "classeComumProbs", "classePrimitiva",
  "classePrimitivaProbs", "classeDefinida", "classeDefinidaProbs",
  "operprecedente", "operprecedenteProbs", "equivalent", "subclass",
  "individuals", "disjoint", "requivalent", "rsubclass", "rindividuals",
  "rdisjoint", "equivProbs", "seqClasses", "instancies", "connect",
  "seqProp", "prop", "propName", "only", "onlyMultClasses", "auxOnlyClass",
  "multClasses", "className", "some", "especificardtype", "qntd", "num",
  "dtype", "value", "exactly", "all", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-82)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-8)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    11,    12,    46,   111,    11,   -82,    11,   -82,    11,
     -82,    11,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
      97,    85,    -3,   120,    57,    64,     8,   -14,   -82,   -82,
     -82,   -82,   125,    71,   101,   125,    71,   101,    59,   -82,
      59,   -82,   -82,     6,   102,     8,   -82,    61,    43,   -82,
      69,   -82,    52,   110,   -82,   107,   -14,   -82,   -82,   101,
     -82,   -82,    71,   101,   -82,   -82,    71,   101,   -82,   -82,
       6,    69,   -82,    79,     8,   108,    56,    69,    69,   122,
      69,    69,    83,    -6,   112,   128,   128,    81,    72,   -82,
     -82,   -82,   -82,   -82,   -82,   -14,   123,   -82,   -82,   -82,
     -82,   -82,   126,   -82,   -82,   -82,   -82,    92,   -82,   -82,
      69,    69,   -82,   -82,   -82,   -82,   -82,   -82,   -82,    79,
     -82,   127,   -82,   139,   -82,   -82,   127,   -82,    37,    37,
       8,   139,   -82,   141,   -82,   -82,   -82,   -82,   139,   -82,
     -82,   129,   142,   -82,   130,   -82,   -82,   -82,   -82,   -82,
     131,   -82,   132,    92,   -82,   -82,   128,   -82,   -82,   -82,
     141,   135,   -82,   -82
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    13,     0,     9,     0,    14,     0,
      19,     0,    28,     6,     8,     1,    53,    52,    54,    55,
      23,    18,    12,    11,     0,     0,     0,     0,     4,     3,
       2,     5,    27,    22,    21,    29,    17,    16,    41,    40,
      43,    42,    10,     0,    63,     0,    45,     0,    46,    81,
       0,    47,    68,     0,    50,    60,     0,    51,    26,    25,
      35,    20,    32,    33,    34,    15,    38,    39,    66,    67,
       0,     0,    44,     0,     0,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      74,    77,    76,    78,    79,     0,     0,    24,    31,    30,
      36,    37,     0,    56,    89,    57,    58,    87,    64,    65,
       0,     0,    49,    48,    80,    70,    69,    90,   101,     0,
      93,    95,   107,     0,   102,   103,    95,   100,     0,     0,
       0,     0,    86,     0,    82,    61,    62,    59,     0,    73,
      72,     0,     0,    92,     0,   104,    98,    96,    99,    97,
       0,   105,     0,    84,    88,    91,     0,   108,   106,    83,
       0,     0,    85,    94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   119,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   124,    -7,     3,     9,   -82,   -82,   -82,   -82,    87,
     -46,   -24,   -48,   -20,   -39,   -82,   -82,     4,    77,   -54,
      10,   -82,    40,   -82,   -80,   -81,   -82,   -82,   -82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    20,    21,    22,    23,    24,    25,    26,    27,    72,
      57,    46,    73,    79,    52,    53,    89,   152,   153,   106,
     107,    90,   143,    91,   128,   121,    92,    93,    94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    55,    54,   126,    81,    51,   129,   131,    76,   122,
      96,    -7,     1,    32,    56,    39,    41,    68,    69,    16,
      17,    75,   123,    33,    36,    44,    42,    14,   111,    34,
      37,    66,     2,    67,    70,    58,    71,    61,    62,    45,
      65,    59,    60,   120,    63,    64,    15,   147,   149,   135,
     108,   103,   104,   105,    68,    69,   118,   112,   113,   138,
     115,   116,    97,    68,    69,   141,    99,    68,    69,   144,
     101,    98,    43,    77,    44,   100,   161,    49,    47,    48,
      49,    16,    80,    47,   154,    49,   110,   132,    45,    50,
     139,   140,    50,    47,   104,    49,    19,    50,   117,    49,
     133,   127,   118,    68,    69,   160,   150,    50,    17,    18,
      19,   119,   130,    82,    83,    84,    85,    86,    87,    16,
      13,    18,    19,    88,    28,    18,    29,   124,    30,   125,
      31,   118,    74,    16,    17,    18,    19,    95,   146,   148,
     109,   151,    16,    17,    18,    35,    38,    40,   127,    18,
      19,   114,   136,   142,   104,   137,   132,   102,   155,   157,
     156,   159,   163,   158,   162,   134,   145
};

static const yytype_uint8 yycheck[] =
{
      48,    15,    26,    84,    52,    25,    86,    87,    47,    15,
      56,     0,     1,    20,    28,    22,    23,    11,    12,    22,
      23,    45,    28,    20,    21,    17,    23,    15,    76,    20,
      21,    38,    21,    40,    28,    32,    30,    34,    35,    31,
      37,    32,    33,    82,    35,    36,     0,   128,   129,    95,
      74,    71,    15,    73,    11,    12,    19,    77,    78,   107,
      80,    81,    59,    11,    12,   119,    63,    11,    12,   123,
      67,    62,    15,    30,    17,    66,   156,    16,    14,    15,
      16,    22,    30,    14,   138,    16,    30,    15,    31,    28,
     110,   111,    28,    14,    15,    16,    25,    28,    15,    16,
      28,    20,    19,    11,    12,   153,   130,    28,    23,    24,
      25,    28,    31,     3,     4,     5,     6,     7,     8,    22,
       1,    24,    25,    13,     5,    24,     7,    15,     9,    17,
      11,    19,    30,    22,    23,    24,    25,    30,   128,   129,
      32,   131,    22,    23,    24,    21,    22,    23,    20,    24,
      25,    29,    29,    26,    15,    29,    15,    70,    29,    29,
      18,    29,    27,    32,   160,    88,   126
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    21,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    34,    15,     0,    22,    23,    24,    25,
      44,    45,    46,    47,    48,    49,    50,    51,    34,    34,
      34,    34,    45,    46,    47,    44,    46,    47,    44,    45,
      44,    45,    46,    15,    17,    31,    54,    14,    15,    16,
      28,    56,    57,    58,    54,    15,    28,    53,    46,    47,
      47,    46,    46,    47,    47,    46,    45,    45,    11,    12,
      28,    30,    52,    55,    30,    54,    57,    30,    55,    56,
      30,    55,     3,     4,     5,     6,     7,     8,    13,    59,
      64,    66,    69,    70,    71,    30,    53,    46,    47,    46,
      47,    46,    52,    56,    15,    56,    62,    63,    54,    32,
      30,    55,    56,    56,    29,    56,    56,    15,    19,    28,
      57,    68,    15,    28,    15,    17,    68,    20,    67,    67,
      31,    67,    15,    28,    61,    53,    29,    29,    55,    56,
      56,    62,    26,    65,    62,    65,    63,    68,    63,    68,
      54,    63,    60,    61,    62,    29,    18,    29,    32,    29,
      55,    67,    60,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    34,    34,    34,    34,    35,    36,
      37,    37,    37,    37,    38,    39,    39,    39,    39,    40,
      41,    41,    41,    41,    41,    41,    41,    41,    42,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    44,    44,    45,    45,    45,    45,
      46,    47,    48,    49,    50,    51,    52,    52,    52,    52,
      53,    53,    53,    54,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    58,    59,    59,    60,    60,    61,    62,    62,    63,
      64,    64,    64,    64,    65,    65,    66,    66,    66,    66,
      67,    68,    69,    69,    69,    70,    70,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     0,     2,     1,
       3,     2,     2,     1,     1,     4,     3,     3,     2,     1,
       4,     3,     3,     2,     5,     4,     4,     3,     1,     3,
       5,     5,     4,     4,     4,     4,     5,     5,     4,     4,
       3,     3,     3,     3,     3,     2,     2,     2,     4,     4,
       2,     2,     1,     1,     1,     1,     2,     2,     2,     3,
       1,     3,     3,     1,     3,     3,     1,     1,     1,     3,
       3,     2,     4,     4,     2,     2,     2,     2,     2,     2,
       3,     1,     2,     4,     1,     3,     1,     1,     3,     1,
       2,     4,     3,     2,     4,     0,     3,     3,     3,     3,
       1,     1,     2,     2,     3,     3,     4,     2,     4
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
  case 8: /* rclass: RCLASS CLASS  */
#line 57 "sint.y"
                     { classeAtual = yytext; semantico->precAux.clear(); semantico->onlys.clear(); sintClass = ""; }
#line 1283 "sint.tab.c"
    break;

  case 9: /* classeComum: classeComumProbs  */
#line 60 "sint.y"
                                { sintClass += "Classe Comum -> " + classeAtual + "\n"; }
#line 1289 "sint.tab.c"
    break;

  case 14: /* classePrimitiva: classePrimitivaProbs  */
#line 69 "sint.y"
                                        { sintClass += "Classe Primitiva -> " + classeAtual + "\n";  }
#line 1295 "sint.tab.c"
    break;

  case 19: /* classeDefinida: classeDefinidaProbs  */
#line 78 "sint.y"
                                    { sintClass += "Classe Definida -> " + classeAtual + "\n"; }
#line 1301 "sint.tab.c"
    break;

  case 28: /* operprecedente: operprecedenteProbs  */
#line 91 "sint.y"
                                      { sintClass += "Classe Desconhecida -> " + classeAtual + "\n"; semantico->onlyCheck(operadorAtual, yylineno); }
#line 1307 "sint.tab.c"
    break;

  case 45: /* equivalent: requivalent instancies  */
#line 112 "sint.y"
                              { sintClass += "Classe enumerada, "; }
#line 1313 "sint.tab.c"
    break;

  case 52: /* requivalent: REQUIVALENT  */
#line 127 "sint.y"
                            { operadorAtual = yytext; isSubclassOf = false; }
#line 1319 "sint.tab.c"
    break;

  case 53: /* rsubclass: RSUBCLASS  */
#line 130 "sint.y"
                            { operadorAtual = yytext; isSubclassOf = true; }
#line 1325 "sint.tab.c"
    break;

  case 54: /* rindividuals: RINDIVIDUALS  */
#line 133 "sint.y"
                            { operadorAtual = yytext; }
#line 1331 "sint.tab.c"
    break;

  case 55: /* rdisjoint: RDISJOINT  */
#line 136 "sint.y"
                            { operadorAtual = yytext; }
#line 1337 "sint.tab.c"
    break;

  case 58: /* equivProbs: connect multClasses  */
#line 141 "sint.y"
                          { sintClass += "Classe coberta, "; }
#line 1343 "sint.tab.c"
    break;

  case 75: /* prop: propName only  */
#line 168 "sint.y"
                           { sintClass += "Axioma de fechamento, "; semantico->onlyCheck(propriedadeAtual, yylineno); }
#line 1349 "sint.tab.c"
    break;

  case 81: /* propName: PROPRIETY  */
#line 176 "sint.y"
                            { propriedadeAtual = yytext;}
#line 1355 "sint.tab.c"
    break;

  case 86: /* auxOnlyClass: CLASS  */
#line 187 "sint.y"
                                { if(isSubclassOf) semantico->onlys.push_back(yytext); }
#line 1361 "sint.tab.c"
    break;

  case 89: /* className: CLASS  */
#line 194 "sint.y"
                            { precedente = yytext; coercao = yytext; }
#line 1367 "sint.tab.c"
    break;

  case 90: /* some: SOME CLASS  */
#line 197 "sint.y"
                       { }
#line 1373 "sint.tab.c"
    break;

  case 91: /* some: SOME '(' multClasses ')'  */
#line 198 "sint.y"
                               {  semantico->precAux.push_back(precedente); precedente = ""; }
#line 1379 "sint.tab.c"
    break;

  case 92: /* some: SOME dtype especificardtype  */
#line 199 "sint.y"
                                  {  }
#line 1385 "sint.tab.c"
    break;

  case 93: /* some: SOME prop  */
#line 200 "sint.y"
                            { sintClass += "Descrição aninhada, "; }
#line 1391 "sint.tab.c"
    break;

  case 94: /* especificardtype: '[' SSYMBOL num ']'  */
#line 204 "sint.y"
                                        { semantico->coercionChecker(coercao, numCoercao, yylineno); }
#line 1397 "sint.tab.c"
    break;

  case 96: /* qntd: MIN num dtype  */
#line 208 "sint.y"
                      { semantico->coercionChecker(coercao, numCoercao, yylineno); }
#line 1403 "sint.tab.c"
    break;

  case 97: /* qntd: MAX num dtype  */
#line 209 "sint.y"
                      { semantico->coercionChecker(coercao, numCoercao, yylineno); }
#line 1409 "sint.tab.c"
    break;

  case 98: /* qntd: MIN num className  */
#line 210 "sint.y"
                          { semantico->coercionChecker(coercao, numCoercao, yylineno); }
#line 1415 "sint.tab.c"
    break;

  case 99: /* qntd: MAX num className  */
#line 211 "sint.y"
                          { semantico->coercionChecker(coercao, numCoercao, yylineno); }
#line 1421 "sint.tab.c"
    break;

  case 100: /* num: CARDINALIDADE  */
#line 214 "sint.y"
                        { numCoercao = yytext; }
#line 1427 "sint.tab.c"
    break;

  case 101: /* dtype: DTYPE  */
#line 217 "sint.y"
                        { coercao = yytext; }
#line 1433 "sint.tab.c"
    break;

  case 105: /* exactly: EXACTLY num className  */
#line 225 "sint.y"
                                    { semantico->coercionChecker(coercao, numCoercao, yylineno); }
#line 1439 "sint.tab.c"
    break;


#line 1443 "sint.tab.c"

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

#line 233 "sint.y"


/* definido pelo analisador léxico */
extern FILE * yyin;  
int main(int argc, char ** argv)
{

    /* se foi passado um nome de arquivo */
	if (argc > 1)
	{
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file)
		{
			cout << "Arquivo " << argv[1] << " não encontrado!\n";
			exit(1);
		}

		/* entrada ajustada para ler do arquivo */
		yyin = file;
	}

	yyparse();

    cout << "Arquivo lido: " << argv[1] << endl;

            cout << "-------------------------------------------------------------------------------" << std::endl;
            cout << "\t\t\t\t ERROS SEMÂNTICOS" << std::endl;
            cout << "-------------------------------------------------------------------------------" << std::endl;
            for(string e : semantico->semanticErrors){
                cout << "ERRO SEMÂNTICO: " << e;
            }  
            if(semantico->semanticErrors.size() == 0){
                cout << "Nenhum erro semântico encontrado. Verifique os sintáticos.\n";
            }

            cout << "-------------------------------------------------------------------------------" << std::endl;
            cout << "\t\t\t\t ERROS SINTÁTICOS" << std::endl;
            cout << "-------------------------------------------------------------------------------" << std::endl;
            for(string e: sintaticErrors){
                cout << e;
            }
            if(sintaticErrors.size() == 0){
                cout << "Nenhum erro sintático encontrado.\n";
            }
}

void yyerror(const char * s)
{
	/* variáveis definidas no analisador léxico */   
	extern char * yytext;   


    string aux = "";

    aux += "ERRO SINTÁTICO: símbolo \"" + std::string(yytext) + "\" (linha " + std::to_string(yylineno) + " do arquivo)\n";
    aux += "NA PROPRIEDADE: \"" + operadorAtual + "\" DA CLASSE " + classeAtual + "\n";

    sintaticErrors.push_back(aux);
    aux = "";
}
