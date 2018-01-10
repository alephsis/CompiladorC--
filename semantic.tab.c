/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "semantic.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "attribs.h"
#include "symbols.h"
#include "intermediate_code.h"

extern FILE *yyout;
extern FILE *yyin;
extern int yylex();
void yyerror(char *s);


int dir;
int dirTemp;
int temporales;
int siginst;
char* tipoGlobal;
int dimGlobal;
NodeParam globalList;
int globalListLength;
 
void init();
int existe(char *id);
int existeLocal(char *id);
expresion operacion(expresion e1, expresion e2, char *op);
expresion numero(int n);
expresion identificador(char *s);
condition relacional(expresion e1, expresion e2, char *oprel);
condition and(condition c1, condition c2);
condition or(condition c1, condition c2);
void newLabel(char *s);
char* getArrayType(int n, char* t);


#line 102 "semantic.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "semantic.tab.h".  */
#ifndef YY_YY_SEMANTIC_TAB_H_INCLUDED
# define YY_YY_SEMANTIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUM = 259,
    INT = 260,
    PRINT = 261,
    VOID = 262,
    IF = 263,
    WHILE = 264,
    BREAK = 265,
    PYC = 266,
    LKEY = 267,
    RKEY = 268,
    TRUE = 269,
    FALSE = 270,
    FLOAT = 271,
    DOUBLE = 272,
    CHAR = 273,
    SWITCH = 274,
    FOR = 275,
    FUNC = 276,
    DEFAULT = 277,
    RETURN = 278,
    STRUCT = 279,
    RLC = 280,
    LLC = 281,
    SC = 282,
    COMMA = 283,
    LBRACK = 284,
    RBRACK = 285,
    GTE = 286,
    LTE = 287,
    ASIG = 288,
    OR = 289,
    AND = 290,
    EQUAL = 291,
    NE = 292,
    GT = 293,
    LT = 294,
    ADD = 295,
    SUB = 296,
    MUL = 297,
    DIV = 298,
    RPAR = 299,
    LPAR = 300,
    IFX = 301,
    ELSE = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "semantic.y" /* yacc.c:355  */

    char sval[32];
    char ssval[3];
    expresion eval;
    condition cval;  
    sentence stval;
    int nval;
    int line;
    type tval;
    arrayType arrtval;

 

#line 204 "semantic.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SEMANTIC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "semantic.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   104

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    96,   102,   102,   106,   108,   112,   116,
     120,   124,   128,   133,   147,   162,   168,   176,   192,   176,
     214,   218,   220,   224,   226,   224,   244,   244,   269,   273,
     281,   284,   289,   294,   298,   298,   310,   315,   321,   328,
     336,   342,   348,   351,   354,   359,   360,   361,   362,   364,
     365,   366,   367,   368,   369,   370
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "INT", "PRINT", "VOID",
  "IF", "WHILE", "BREAK", "PYC", "LKEY", "RKEY", "TRUE", "FALSE", "FLOAT",
  "DOUBLE", "CHAR", "SWITCH", "FOR", "FUNC", "DEFAULT", "RETURN", "STRUCT",
  "RLC", "LLC", "SC", "COMMA", "LBRACK", "RBRACK", "GTE", "LTE", "ASIG",
  "OR", "AND", "EQUAL", "NE", "GT", "LT", "ADD", "SUB", "MUL", "DIV",
  "RPAR", "LPAR", "IFX", "ELSE", "$accept", "program", "$@1", "decl",
  "$@2", "tipo", "idlist", "tipoarreglo", "function", "$@3", "$@4",
  "paramlistdef", "paramlist", "$@5", "$@6", "$@7", "arrayparam", "block",
  "sents", "sent", "$@8", "goto_else", "cond", "rel", "exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -24

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -62,     7,    32,   -62,   -62,   -62,   -62,   -62,   -62,    -1,
      -3,   -62,    32,    32,   -62,    12,    29,    41,    -9,    -6,
     -62,   -62,    42,   -62,   -62,    50,     9,    25,    -9,    32,
      -9,   -62,   -62,    13,    30,   -62,    56,    48,    44,    45,
      32,    32,    83,   -62,    67,   -62,    58,   -62,    -2,    46,
      47,    60,    76,    67,   -62,    87,    45,    61,   -62,   -62,
      -2,    43,    -2,    -2,   -62,   -62,   -62,    45,   -62,    -2,
      38,    -2,    -2,    -2,    -2,   -25,    26,    17,    -3,   -62,
      -8,   -62,   -12,   -12,   -62,   -62,    -2,    -2,    81,   -62,
     -62,   -62,   -62,    -2,    84,   -62,   -62,    62,   -62,    67,
      43,    67,    82,    85,    52,   -62,   -62,    88,    67,    89,
     -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,     7,    11,     8,     9,    10,     0,
      20,     4,     6,     0,     3,     0,     0,     0,    16,     0,
      12,    17,     0,    14,     5,     0,     0,     0,    16,    22,
      16,    13,    26,     0,    21,    15,     0,     0,     0,    29,
       6,     0,     0,    27,    31,    24,     0,    34,     0,     0,
       0,     0,     0,    30,    33,     0,    29,     0,    54,    53,
       0,    38,     0,     0,    40,    18,    32,    29,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    25,
       0,    55,    49,    50,    51,    52,     0,     0,     0,    45,
      46,    47,    48,     0,     0,    19,    35,    42,    43,    31,
      44,    31,     0,     0,    36,    39,    41,     0,    31,     0,
      37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   -62,    -4,   -62,     0,   -62,   -14,    23,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -50,   -61,   -62,    51,
     -62,   -62,   -59,   -62,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    10,    15,    11,    19,    23,    14,    26,
      78,    33,    34,    38,    55,    36,    43,    52,    53,    54,
      57,   107,    75,    93,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      61,    58,    59,    96,    77,    24,    68,     3,    16,    86,
      87,    12,    70,    17,    31,    18,    35,    79,    13,    88,
      22,    80,    25,    82,    83,    84,    85,    97,    98,    32,
      73,    74,    71,    72,    73,    74,    44,     4,   102,     5,
     103,    45,    20,    60,    21,   100,    27,   109,     6,     7,
       8,    86,    87,    28,    29,    30,     9,    37,   -23,    39,
      40,    94,    89,    90,    91,    92,    71,    72,    73,    74,
      47,    64,    41,    48,    42,    49,    50,    51,    71,    72,
      73,    74,    81,    71,    72,    73,    74,    46,    56,    65,
      67,    62,    63,    99,    69,   104,   101,    87,   105,   106,
     108,    95,   110,     0,    66
};

static const yytype_int8 yycheck[] =
{
      48,     3,     4,    11,    63,    11,    56,     0,    12,    34,
      35,    12,    60,    13,    28,     3,    30,    67,    21,    44,
      29,    69,    28,    71,    72,    73,    74,    86,    87,    29,
      42,    43,    40,    41,    42,    43,    40,     5,    99,     7,
     101,    41,    13,    45,     3,    93,     4,   108,    16,    17,
      18,    34,    35,     3,    45,    30,    24,    44,    28,     3,
      12,    44,    36,    37,    38,    39,    40,    41,    42,    43,
       3,    11,    28,     6,    29,     8,     9,    10,    40,    41,
      42,    43,    44,    40,    41,    42,    43,     4,    30,    13,
       3,    45,    45,    12,    33,    13,    12,    35,    13,    47,
      12,    78,    13,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     5,     7,    16,    17,    18,    24,
      51,    53,    12,    21,    56,    52,    51,    53,     3,    54,
      13,     3,    29,    55,    11,    28,    57,     4,     3,    45,
      30,    55,    53,    59,    60,    55,    63,    44,    61,     3,
      12,    28,    29,    64,    51,    53,     4,     3,     6,     8,
       9,    10,    65,    66,    67,    62,    30,    68,     3,     4,
      45,    72,    45,    45,    11,    13,    67,     3,    64,    33,
      72,    40,    41,    42,    43,    70,    72,    70,    58,    64,
      72,    44,    72,    72,    72,    72,    34,    35,    44,    36,
      37,    38,    39,    71,    44,    56,    11,    70,    70,    12,
      72,    12,    65,    65,    13,    13,    47,    69,    12,    65,
      13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    50,    49,    52,    51,    51,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    55,    57,    58,    56,
      56,    59,    59,    61,    62,    60,    63,    60,    64,    64,
      65,    65,    66,    66,    68,    67,    67,    67,    67,    67,
      67,    69,    70,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     4,     0,     1,     1,     1,
       1,     1,     4,     4,     2,     4,     0,     0,     0,    13,
       0,     1,     0,     0,     0,     7,     0,     4,     4,     0,
       1,     0,     2,     1,     0,     5,     7,    12,     2,     7,
       2,     0,     3,     3,     3,     1,     1,     1,     1,     3,
       3,     3,     3,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 96 "semantic.y" /* yacc.c:1646  */
    {init();}
#line 1374 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 97 "semantic.y" /* yacc.c:1646  */
    {
            print_table();
            print_code();
         }
#line 1383 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 102 "semantic.y" /* yacc.c:1646  */
    {      
      tipoGlobal = (yyvsp[0].tval).tipo;
      dimGlobal  = (yyvsp[0].tval).dim;
}
#line 1392 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 108 "semantic.y" /* yacc.c:1646  */
    {
       (yyval.tval).tipo = "int";
       (yyval.tval).dim = 4;
	  }
#line 1401 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 112 "semantic.y" /* yacc.c:1646  */
    {
       (yyval.tval).tipo = "float";
       (yyval.tval).dim = 4;
	  }
#line 1410 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 116 "semantic.y" /* yacc.c:1646  */
    {
       (yyval.tval).tipo = "double";
       (yyval.tval).dim = 8;
  }
#line 1419 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 120 "semantic.y" /* yacc.c:1646  */
    {
       (yyval.tval).tipo = "char";
       (yyval.tval).dim = 1;
	  }
#line 1428 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 124 "semantic.y" /* yacc.c:1646  */
    {
       (yyval.tval).tipo = "void";
       (yyval.tval).dim = -1;
       }
#line 1437 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "semantic.y" /* yacc.c:1646  */
    {
  (yyval.tval).tipo = "struct";
  (yyval.tval).dim = -1;
	  }
#line 1446 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 133 "semantic.y" /* yacc.c:1646  */
    {
	     if(existeLocal((yyvsp[-1].sval))==-1){
	       printf("insertando %s\n",(yyvsp[-1].sval));
	       symbol sym;
	       strcpy(sym.id, (yyvsp[-1].sval));
	       sym.dir = dir;
	       sym.type = (yyvsp[0].arrtval).tipo;
	       sym.var = NULL;
	       insert(sym);
	       dir+= (yyvsp[0].arrtval).dim;
	     }else{
	       yyerror("Identificador duplicado");
	     }
           }
#line 1465 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 147 "semantic.y" /* yacc.c:1646  */
    {
	   if(existeLocal((yyvsp[-1].sval))==-1){	     
	     printf("insertando %s \n",(yyvsp[-1].sval));	     
	     symbol sym;
	     strcpy(sym.id, (yyvsp[-1].sval));
	     sym.dir = dir;
	     sym.type = (yyvsp[0].arrtval).tipo;
	     sym.var = NULL;
	     insert(sym);
	     dir += (yyvsp[0].arrtval).dim;
	   }else{	     
	     yyerror("Identificador duplicado");
	   }	    
}
#line 1484 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 162 "semantic.y" /* yacc.c:1646  */
    {
  if(dimGlobal == -1)
    yyerror("Tipo invalido para un arreglo");
  (yyval.arrtval).tipo = getArrayType((yyvsp[-2].nval), (yyvsp[0].arrtval).tipo);
  (yyval.arrtval).dim = (yyvsp[-2].nval) * (yyvsp[0].arrtval).dim;
  }
#line 1495 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 168 "semantic.y" /* yacc.c:1646  */
    {
  if(strcmp("void",tipoGlobal) == 0)
    yyerror("Tipo void válido solo a funciones");
  (yyval.arrtval).tipo = tipoGlobal;
  (yyval.arrtval).dim = dimGlobal;
  }
#line 1506 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 176 "semantic.y" /* yacc.c:1646  */
    {
              if(existe((yyvsp[0].sval)) != -1){
                  yyerror("Identificador duplicado");
              }else{
                  /* generate new symbols table */                  
                  symbols_table* sym_tab;
		  
		  sym_tab  = (symbols_table *)malloc(1000*sizeof(symbol)+5);
                  sym_tab->next = 0;
                  pushST(*sym_tab);
		  /* store the current dir (the method must be different for structs) */
		  dirTemp = dir;
		  dir = 0;		  
                  /* generate label of function */
                  gen_code("label","","",(yyvsp[0].sval)); 
              }
	  }
#line 1528 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 192 "semantic.y" /* yacc.c:1646  */
    {
//Here the tipe of block and tipo must be the same, but for now block doesnt have type, begin that if here
char* endLabel = (char*)malloc(100 * sizeof(char));
    sprintf(endLabel,"%s end",(yyvsp[-8].sval));
    siginst = gen_code("label","","",endLabel);
    backpatch((yyvsp[-1].stval).lnext, siginst);
//end if here
    /* destroy sym table */
    popST();
    /* restore the previous dir */
    dir = dirTemp;
    /* insert id of function */
    printf("insertando %s\n",(yyvsp[-8].sval));
    symbol sym;
    strcpy(sym.id, (yyvsp[-8].sval));
    sym.dir = -1;
    sym.type = (yyvsp[-9].tval).tipo;
    sym.var =  "func";
    sym.listLength = globalListLength;
    sym.list = globalList;
    insert(sym);
}
#line 1555 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 214 "semantic.y" /* yacc.c:1646  */
    {

  }
#line 1563 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 218 "semantic.y" /* yacc.c:1646  */
    {
}
#line 1570 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 220 "semantic.y" /* yacc.c:1646  */
    {
  globalListLength = 0;
}
#line 1578 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 224 "semantic.y" /* yacc.c:1646  */
    {

  }
#line 1586 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 226 "semantic.y" /* yacc.c:1646  */
    {
            tipoGlobal = (yyvsp[0].tval).tipo;
	    dimGlobal  = (yyvsp[0].tval).dim;	    
	   }
#line 1595 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 229 "semantic.y" /* yacc.c:1646  */
    {
             if(existeLocal((yyvsp[-1].sval)) != -1){
                 yyerror("Identificador duplicado");
	     }
	     printf("insertando %s\n",(yyvsp[-1].sval));
	     symbol sym;
	     strcpy(sym.id, (yyvsp[-1].sval));
	     sym.dir = dir;
	     sym.type = (yyvsp[0].arrtval).tipo;
	     sym.var = "param";
	     insert(sym);
	     dir = dir + (yyvsp[0].arrtval).dim;
	     addParam(globalList,(yyvsp[0].arrtval).tipo);
	     globalListLength++;
	     }
#line 1615 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 244 "semantic.y" /* yacc.c:1646  */
    {
  if(strcmp((yyvsp[0].tval).tipo, "void") == 0)
    yyerror("Tipo void inválido para un parámetro de función");
  tipoGlobal = (yyvsp[0].tval).tipo;
  dimGlobal  = (yyvsp[0].tval).dim;
  }
#line 1626 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 249 "semantic.y" /* yacc.c:1646  */
    {
	    if(existeLocal((yyvsp[-1].sval)) != -1)
	      yyerror("Identificador duplicado");
	    printf("insertando %s\n",(yyvsp[-1].sval));
	    symbol sym;
	    strcpy(sym.id, (yyvsp[-1].sval));
	    sym.dir = dir;
	    sym.type = (yyvsp[0].arrtval).tipo;
	    sym.var = "param";
	    insert(sym);
	    dir = dir + (yyvsp[0].arrtval).dim;
	    /* $$.lista = newLista() */
	    NodeParam nuevo;
	    nuevo.data = (yyvsp[0].arrtval).tipo;
	    nuevo.next = NULL;
	    globalList = nuevo;
	    globalListLength = 1;
 
	  }
#line 1650 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 269 "semantic.y" /* yacc.c:1646  */
    {
  (yyval.arrtval).tipo = getArrayType((yyvsp[-2].nval), (yyvsp[0].arrtval).tipo);
  (yyval.arrtval).dim = (yyvsp[-2].nval) * (yyvsp[0].arrtval).dim;
  }
#line 1659 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 273 "semantic.y" /* yacc.c:1646  */
    {
  if(dimGlobal == -1)
    yyerror("Tipo inválido para un arreglo");
  (yyval.arrtval).tipo = tipoGlobal;
  (yyval.arrtval).dim = dimGlobal;
	  }
#line 1670 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 281 "semantic.y" /* yacc.c:1646  */
    {
            (yyval.stval)= (yyvsp[0].stval);
        }
#line 1678 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 284 "semantic.y" /* yacc.c:1646  */
    {
            
        }
#line 1686 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 289 "semantic.y" /* yacc.c:1646  */
    {
            backpatch((yyvsp[-1].stval).lnext, (yyvsp[0].stval).first);
            (yyval.stval).lnext = (yyvsp[0].stval).lnext;
            (yyval.stval).first = (yyvsp[-1].stval).first;
        }
#line 1696 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 294 "semantic.y" /* yacc.c:1646  */
    {
            (yyval.stval).lnext = (yyvsp[0].stval).lnext;
        }
#line 1704 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 298 "semantic.y" /* yacc.c:1646  */
    {
            if(existe((yyvsp[0].sval))==-1){
                yyerror("el identificador no ha sido declarado");
            }
        }
#line 1714 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 303 "semantic.y" /* yacc.c:1646  */
    {
                siginst = gen_code("=", (yyvsp[-1].eval).dir, "", (yyvsp[-4].sval));               
                if((yyvsp[-1].eval).first != -1)
                    (yyval.stval).first = (yyvsp[-1].eval).first;
                else
                    (yyval.stval).first = siginst;
        }
#line 1726 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 310 "semantic.y" /* yacc.c:1646  */
    { 
                backpatch((yyvsp[-4].cval).ltrue, (yyvsp[-1].stval).first);
                (yyval.stval).lnext = merge((yyvsp[-4].cval).lfalse, (yyvsp[-1].stval).lnext);
                (yyval.stval).first = (yyvsp[-4].cval).first;                
        }
#line 1736 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 315 "semantic.y" /* yacc.c:1646  */
    {
                backpatch((yyvsp[-9].cval).ltrue, (yyvsp[-6].stval).first);
                backpatch((yyvsp[-9].cval).lfalse, (yyvsp[-1].stval).first);
                label temp = merge((yyvsp[-6].stval).lnext, (yyvsp[-3].stval).lnext);
                (yyval.stval).lnext = merge(temp, (yyvsp[-1].stval).lnext); 
        }
#line 1747 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 321 "semantic.y" /* yacc.c:1646  */
    {
            siginst = gen_code("print", (yyvsp[0].eval).dir, "", "");            
            if((yyvsp[0].eval).first != -1)
                (yyval.stval).first = (yyvsp[0].eval).first;
            else
                (yyval.stval).first = siginst;
        }
#line 1759 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 328 "semantic.y" /* yacc.c:1646  */
    {                
                backpatch((yyvsp[-1].stval).lnext, (yyvsp[-4].cval).first);
                backpatch((yyvsp[-4].cval).ltrue, (yyvsp[-1].stval).first);
                (yyval.stval).lnext = (yyvsp[-4].cval).lfalse;
                char temp[15];
                sprintf(temp,"%d", (yyvsp[-4].cval).first);
                gen_code("goto", "", "", temp);
        }
#line 1772 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 336 "semantic.y" /* yacc.c:1646  */
    {
            (yyval.stval).first = -1;
            siginst = gen_code("goto", "", "", "");
            (yyval.stval).lnext = create_list(siginst);
        }
#line 1782 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 342 "semantic.y" /* yacc.c:1646  */
    {
                siginst = gen_code("goto","","", "");             
                (yyval.stval).lnext = create_list(siginst);
                (yyval.stval).first = -1;
            }
#line 1792 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 348 "semantic.y" /* yacc.c:1646  */
    {
            (yyval.cval) = or((yyvsp[-2].cval), (yyvsp[0].cval));
        }
#line 1800 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 351 "semantic.y" /* yacc.c:1646  */
    {
            (yyval.cval) = and((yyvsp[-2].cval), (yyvsp[0].cval));
        }
#line 1808 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 354 "semantic.y" /* yacc.c:1646  */
    {
            (yyval.cval) = relacional((yyvsp[-2].eval), (yyvsp[0].eval), (yyvsp[-1].ssval));
        }
#line 1816 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 359 "semantic.y" /* yacc.c:1646  */
    {strcpy((yyval.ssval), (yyvsp[0].ssval));}
#line 1822 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 360 "semantic.y" /* yacc.c:1646  */
    {strcpy((yyval.ssval), (yyvsp[0].ssval));}
#line 1828 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 361 "semantic.y" /* yacc.c:1646  */
    {strcpy((yyval.ssval), (yyvsp[0].ssval));}
#line 1834 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 362 "semantic.y" /* yacc.c:1646  */
    {strcpy((yyval.ssval), (yyvsp[0].ssval));}
#line 1840 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 364 "semantic.y" /* yacc.c:1646  */
    { (yyval.eval) = operacion((yyvsp[-2].eval), (yyvsp[0].eval),(yyvsp[-1].ssval));}
#line 1846 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 365 "semantic.y" /* yacc.c:1646  */
    { (yyval.eval) = operacion((yyvsp[-2].eval), (yyvsp[0].eval),(yyvsp[-1].ssval));}
#line 1852 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 366 "semantic.y" /* yacc.c:1646  */
    { (yyval.eval) = operacion((yyvsp[-2].eval), (yyvsp[0].eval),(yyvsp[-1].ssval));}
#line 1858 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 367 "semantic.y" /* yacc.c:1646  */
    { (yyval.eval) = operacion((yyvsp[-2].eval), (yyvsp[0].eval),(yyvsp[-1].ssval));}
#line 1864 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 368 "semantic.y" /* yacc.c:1646  */
    {(yyval.eval)= numero((yyvsp[0].nval));}
#line 1870 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 369 "semantic.y" /* yacc.c:1646  */
    {(yyval.eval)= identificador((yyvsp[0].sval));}
#line 1876 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 370 "semantic.y" /* yacc.c:1646  */
    {(yyval.eval) = (yyvsp[-1].eval);}
#line 1882 "semantic.tab.c" /* yacc.c:1646  */
    break;


#line 1886 "semantic.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 374 "semantic.y" /* yacc.c:1906  */


void yyerror(char* s){
    printf("ERROR:%s, en  la linea %d\n",s, yylval.line);
    exit(1);
}

void newLabel(char *s){
    
}

void init(){
    dir = 0;
    temporales = 0;    
    init_table();
}

int existe(char *id){
    return search(id);
}

int existeLocal(char *id){
    return searchLocal(id);
}


expresion operacion(expresion e1, expresion e2, char *op){
    temporales++;
    expresion e;
    
    char num[5];
    sprintf(num,"%d",temporales);
    strcpy(e.dir, "t");
    strcat(e.dir, num);    
    e.type = 1;
    siginst = gen_code(op, e1.dir, e2.dir, e.dir);
    if(e1.first != -1){
        e.first = e1.first;
    }else{
        if(e2.first!=-1){
            e.first = e2.first;
        }else{
            e.first = siginst;
        }        
    }
    
    return e;
}

expresion numero(int n){
    expresion e;
    sprintf(e.dir, "%d", n);
    e.first=-1;
    return e;    
}

expresion identificador(char *s){
    expresion e;
    if(existe(s)!=-1){        
        e.first=-1;
        strcpy(e.dir, s);
    }else{
      print_table();
      printf("%s",s);
      yyerror("El identificador no ha sido declarado");
    }
    return e;
}

condition relacional(expresion e1, expresion e2, char *oprel){
    condition c;    
    char arg1[50];
    sprintf(arg1, "%s %s %s", e1.dir, oprel, e2.dir);
    siginst = gen_code("if",arg1, "goto", "");
    c.ltrue = create_list(siginst);
    siginst = gen_code("goto", "", "", "");
    c.lfalse = create_list(siginst);
    if(e1.first != -1){
        c.first = e1.first;
    }else{
        if(e2.first!=-1){
            c.first = e2.first;
        }else{
            c.first = siginst-1;
        }        
    }
    return c;
}

condition or(condition c1, condition c2){
    condition c;
    backpatch(c1.lfalse, c2.first);
    c.ltrue= merge(c1.ltrue, c2.ltrue);
    c.lfalse = c2.lfalse;
    return c;
}

condition and(condition c1, condition c2){
    condition c;
    backpatch(c1.ltrue, c2.first);
    c.ltrue= c2.ltrue;
    c.lfalse = merge(c1.lfalse,c2.lfalse);
    return c;
}

char* getArrayType(int n, char* t){
    char* ret= (char*)malloc(100*sizeof(char)); 
    sprintf(ret,"array [%d] of type %s",n,t);
    return ret;
}

int main(int argc, char** argv){
    if(argc>1){
        yyin = fopen(argv[1], "r");
        if(!yyin) return 1;
        yyparse();
        fclose(yyin);
    }
}
/*
#include "attribs.h"
#include "intermediate_code.c"
#include "symbols.c"
*/
