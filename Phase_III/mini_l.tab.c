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
#line 1 "mini_l.y" /* yacc.c:339  */

    #define YY_NO_INPUT
    #include <stdio.h>
    #include <stdlib.h>
    #include <map>
    #include <string.h>
    #include <set>
    /*Phase_3*/
    int tempCount = 0;
    int labelCount = 0;
    extern char* yytext;
    extern int currPos;
    bool mainFunc = false;
    std::set<std::string> funcs;
    std::map<std::string, std::string> varTemp;
    std::map<std::string, int> arrSize;
    std::set<std::string> reserved {"FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS",  
        "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER", "ARRAY", "OF" , "IF", "THEN",
        "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", 
        "TRUE", "FALSE", "SEMICOLON", "COLON" ,"RETURN", "COMMA", "FALSE", "SEMICOLON", "COLON", "RETURN", "COMMA",
        "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "MULT", "DIV", "MOD","PLUS" "MINUS", "LT", "LTE" 
        "GT", "GTE" , "EQ", "NEQ", " NOT", "AND", "OR ","ASSIGN", "Function", "Declarations", "Declaration", "Vars", "Var", "Expressions", "Expression", "Ident", "Idents", "Bool_exp",
         "Relation_and_expr", "Relation_expr_inv", "Relation_expr", "Comp", "Multiplicative_expr", "Term", "Statements", "Statement"
        };
    std::string new_label();
    std::string new_temp();
    /*Pahse_2*/
    void yyerror(const char* msg);
    int yylex();
//     extern int currLine;
//     extern FILE* yyin;

#line 99 "mini_l.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "mini_l.tab.h".  */
#ifndef YY_YY_MINI_L_TAB_H_INCLUDED
# define YY_YY_MINI_L_TAB_H_INCLUDED
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
    IDENT = 258,
    NUMBER = 259,
    FUNCTION = 260,
    BEGIN_PARAMS = 261,
    END_PARAMS = 262,
    BEGIN_LOCALS = 263,
    END_LOCALS = 264,
    BEGIN_BODY = 265,
    END_BODY = 266,
    INTEGER = 267,
    ARRAY = 268,
    OF = 269,
    IF = 270,
    THEN = 271,
    ENDIF = 272,
    ELSE = 273,
    WHILE = 274,
    DO = 275,
    BEGINLOOP = 276,
    ENDLOOP = 277,
    CONTINUE = 278,
    READ = 279,
    WRITE = 280,
    TRUE = 281,
    FALSE = 282,
    SEMICOLON = 283,
    COLON = 284,
    RETURN = 285,
    COMMA = 286,
    L_PAREN = 287,
    R_PAREN = 288,
    L_SQUARE_BRACKET = 289,
    R_SQUARE_BRACKET = 290,
    MULT = 291,
    DIV = 292,
    MOD = 293,
    PLUS = 294,
    MINUS = 295,
    LT = 296,
    LTE = 297,
    GT = 298,
    GTE = 299,
    EQ = 300,
    NEQ = 301,
    NOT = 302,
    AND = 303,
    OR = 304,
    ASSIGN = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "mini_l.y" /* yacc.c:355  */

    int num_val;
    char* id_val;
    struct S{
            char* code;
    } statement;
    struct E{
            char* place;
            char* code;
            bool arr;
    } expression;

#line 203 "mini_l.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINI_L_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 220 "mini_l.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    73,    79,   111,   119,   126,   172,   227,
     234,   239,   264,   279,   294,   319,   342,   353,   365,   369,
     378,   383,   399,   404,   421,   433,   440,   450,   457,   464,
     480,   485,   490,   495,   500,   505,   511,   516,   531,   547,
     558,   569,   574,   592,   609,   627,   655,   667,   672,   687,
     716,   728,   741,   754,   761,   766,   776,   792,   809,   824
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "NUMBER", "FUNCTION",
  "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY",
  "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE",
  "TRUE", "FALSE", "SEMICOLON", "COLON", "RETURN", "COMMA", "L_PAREN",
  "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "MULT", "DIV", "MOD",
  "PLUS", "MINUS", "LT", "LTE", "GT", "GTE", "EQ", "NEQ", "NOT", "AND",
  "OR", "ASSIGN", "$accept", "prog_start", "Function", "Declartions",
  "Declartion", "Statements", "Statement", "Bool_exp", "Relation_and_expr",
  "Relation_expr_inv", "Relation_expr", "Comp", "Expression",
  "Expressions", "Mutiplicative_expr", "Term", "FuncIdent", "Ident",
  "Idents", "Vars", "Var", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,    15,    34,    -3,   -61,   -24,   -61,   -61,    30,    36,
     -61,    40,    23,    28,    38,    57,    36,    36,     1,    36,
     -61,   -61,   -61,    41,    62,    72,    67,    44,    93,    69,
      54,    54,    64,   -61,    36,    36,    13,    76,    60,    55,
      43,    78,   -61,   -61,   -61,    54,    37,    54,    81,    49,
      51,   -61,    92,     4,   -16,    -2,   -61,    79,    93,   -61,
      71,   -61,    13,   -61,   -61,    93,    13,    13,   -61,    70,
      86,   -61,    13,   -61,   -61,    93,    54,    54,   -61,   -61,
     -61,   -61,   -61,   -61,    13,    13,    13,    13,    13,    13,
      13,    93,    82,    36,    73,   -61,    75,   -61,   -61,   -61,
      87,    45,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
      74,    88,    89,    95,   -61,   -61,   -61,   -61,    93,    13,
     -61,   -61,    54,    98,   -61,   -61,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     2,    52,     0,     1,     3,     0,     6,
      53,     0,     0,    54,     0,     0,     6,     0,     0,     6,
       5,    55,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,    58,
       0,     0,    46,    27,    28,     0,     0,     0,     0,    20,
      22,    25,     0,    36,    41,    58,    45,     0,     0,    16,
      57,    17,     0,    19,     4,    10,     0,     0,     8,     0,
       0,    50,     0,    49,    24,     0,     0,     0,    32,    34,
      33,    35,    30,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    11,    29,    47,
       0,     0,    21,    23,    26,    37,    38,    42,    43,    44,
      40,     0,     0,     0,    56,    59,    51,    12,     0,     0,
      48,    14,     0,     0,    39,    15,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   119,   -61,   -10,   -61,   -27,   -61,   -30,    47,    94,
     -61,   -61,   -12,     6,   -60,   -61,   -61,    -9,   109,   -32,
     -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    11,    12,    37,    38,    48,    49,    50,
      51,    84,    52,   111,    53,    54,     5,    55,    14,    59,
      56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    57,     1,    61,     8,    40,    20,    13,    13,    24,
      13,    60,    60,    22,    23,    69,    10,    42,     4,    39,
      87,    88,    89,    73,    63,    39,    39,   107,   108,   109,
      90,    92,    66,    70,     6,    40,     9,    39,    95,    10,
      10,    71,    40,    85,    86,    62,   102,    15,   101,    39,
      94,    16,    40,    46,    96,    97,    39,    10,    42,    17,
     100,   114,   117,   118,   112,    19,    39,    18,    40,    72,
      60,    26,   104,   105,   106,    25,    27,    28,   110,    29,
      43,    44,    39,    41,    39,    58,    45,    64,    65,    66,
      68,   123,   125,    67,    46,    40,    10,    75,    76,    77,
      91,    47,    93,    98,   113,   119,    99,   110,    30,    39,
     115,   121,    31,    32,   122,   126,    33,    34,    35,    99,
     116,   120,     7,    36,   103,   124,    21,    78,    79,    80,
      81,    82,    83,    78,    79,    80,    81,    82,    83,     0,
       0,    74
};

static const yytype_int8 yycheck[] =
{
       9,    31,     5,    35,    28,    28,    16,    16,    17,    19,
      19,    34,    35,    12,    13,    45,     3,     4,     3,    28,
      36,    37,    38,    46,    36,    34,    35,    87,    88,    89,
      32,    58,    34,    45,     0,    58,     6,    46,    65,     3,
       3,     4,    65,    39,    40,    32,    76,     7,    75,    58,
      62,    28,    75,    40,    66,    67,    65,     3,     4,    31,
      72,    93,    17,    18,    91,     8,    75,    29,    91,    32,
      93,     9,    84,    85,    86,    34,     4,    10,    90,    35,
      26,    27,    91,    14,    93,    21,    32,    11,    28,    34,
      12,   118,   122,    50,    40,   118,     3,    16,    49,    48,
      21,    47,    31,    33,    22,    31,    33,   119,    15,   118,
      35,    22,    19,    20,    19,    17,    23,    24,    25,    33,
      33,    33,     3,    30,    77,   119,    17,    41,    42,    43,
      44,    45,    46,    41,    42,    43,    44,    45,    46,    -1,
      -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    52,    53,     3,    67,     0,    52,    28,     6,
       3,    54,    55,    68,    69,     7,    28,    31,    29,     8,
      54,    69,    12,    13,    54,    34,     9,     4,    10,    35,
      15,    19,    20,    23,    24,    25,    30,    56,    57,    68,
      71,    14,     4,    26,    27,    32,    40,    47,    58,    59,
      60,    61,    63,    65,    66,    68,    71,    58,    21,    70,
      71,    70,    32,    63,    11,    28,    34,    50,    12,    58,
      63,     4,    32,    71,    60,    16,    49,    48,    41,    42,
      43,    44,    45,    46,    62,    39,    40,    36,    37,    38,
      32,    21,    56,    31,    63,    56,    63,    63,    33,    33,
      63,    56,    58,    59,    63,    63,    63,    65,    65,    65,
      63,    64,    56,    22,    70,    35,    33,    17,    18,    31,
      33,    22,    19,    56,    64,    58,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      62,    62,    62,    62,    62,    62,    63,    63,    63,    64,
      64,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    67,    68,    69,    69,    70,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,    12,     3,     0,     3,     8,     3,
       2,     3,     5,     7,     5,     6,     2,     2,     1,     2,
       1,     3,     1,     3,     2,     1,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     1,     3,     3,     3,     1,     1,     3,     4,     2,
       2,     4,     1,     1,     1,     3,     3,     1,     1,     4
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
#line 68 "mini_l.y" /* yacc.c:1646  */
    {
                if(!mainFunc){
                     printf("No main function declared!\n");
                }
        }
#line 1392 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "mini_l.y" /* yacc.c:1646  */
    { 
        }
#line 1399 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 80 "mini_l.y" /* yacc.c:1646  */
    {
                    std::string temp = "func ";
                    temp.append((yyvsp[-10].expression).place);
                    temp.append("\n");
                    std::string s = (yyvsp[-10].expression).place;
                    if(s == "main"){
                        mainFunc = true;
                    }
                    temp.append((yyvsp[-7].expression).code);
                    std::string decs = (yyvsp[-7].expression).code;
                    int decNum = 0;
                    while(decs.find(".") != std::string::npos){
                        int pos = decs.find(".");
                        decs.replace(pos,1,"=");
                        std::string part = ", $" + std::to_string(decNum) + "\n";
                        decNum ++;
                        decs.replace(decs.find("\n",pos), 1, part);
                    }
                    temp.append(decs);
                    temp.append((yyvsp[-4].expression).code);
                    std::string statements = (yyvsp[-1].statement).code;
                    if(statements.find("continue") != std::string::npos){
                            printf("ERROR: Continue outside loop in function %s\n", (yyvsp[-10].expression).place);

                    }
                    temp.append(statements);
                    temp.append("endfunc\n\n");
                    printf(temp.c_str());
            }
#line 1433 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 112 "mini_l.y" /* yacc.c:1646  */
    {
                     std::string temp;
                     temp.append((yyvsp[-2].expression).code);
                     temp.append((yyvsp[0].expression).code);
                     (yyval.expression).code = strdup(temp.c_str());
                     (yyval.expression).place = strdup("");
             }
#line 1445 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "mini_l.y" /* yacc.c:1646  */
    {       (yyval.expression).code = strdup("");
                    (yyval.expression).place = strdup("");
                    
            }
#line 1454 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 127 "mini_l.y" /* yacc.c:1646  */
    {
                    size_t left = 0;
                    size_t right = 0;
                    std::string parse((yyvsp[-2].expression).place);
                    std::string temp;
                    bool ex = false;
                    while(!ex){
                        right = parse.find("|", left);
                        temp.append(". ");
                        if(right == std::string::npos){
                                std::string ident = parse.substr(left, right);
                                if(reserved.find(ident) != reserved.end()){
                                        printf("Identifier %s's name is a reserved word. \n",ident.c_str());
                                }
                                if(funcs.find(ident) != funcs.end() || varTemp.find(ident) != varTemp.end()){
                                        printf("Identifier %s is previously declared. \n", ident.c_str());
                                }
                                else{
                                        varTemp[ident] = ident;
                                        arrSize[ident] = 1;
                                }
                                temp.append(ident);
                                ex = true;
                        }
                        else{
                                std::string ident = parse.substr(left,right-left);
                                if(reserved.find(ident) != reserved.end()){
                                        printf("Identifier %s's name is a reserved word. \n", ident.c_str());
                                }
                                if(funcs.find(ident) != funcs.end() || varTemp.find(ident) != varTemp.end()){
                                        printf("Identifier %s is previously declared. \n", ident.c_str());
                                }
                                else{
                                        varTemp[ident] = ident;
                                        arrSize[ident] = 1;
                                }
                                temp.append(ident);
                                left = right + 1;
                        }
                        temp.append("\n");
                    }
                    (yyval.expression).code = strdup(temp.c_str());
                    (yyval.expression).place  = strdup("");
            }
#line 1503 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 173 "mini_l.y" /* yacc.c:1646  */
    {
                    size_t left = 0;
                    size_t right = 0;
                    std::string parse((yyvsp[-7].expression).place);
                    std::string temp;
                    bool ex = false;
                    while(!ex){
                            right = parse.find("|",left);
                            temp.append(".[] ");
                            if(right == std::string::npos){
                                    std::string ident = parse.substr(left, right);
                                    if(reserved.find(ident) != reserved.end()){
                                        printf("Identifier %s's name is a reserved word. \n", ident.c_str());
                                    }
                                    if(funcs.find(ident) != funcs.end() || varTemp.find(ident) != varTemp.end()){
                                        printf("Identifier %s is previously declared. \n", ident.c_str());
                                    }
                                    else{
                                        if((yyvsp[-3].num_val) <= 0){
                                        printf("Declaring array ident %s of size <= 0. \n", ident.c_str()); 
                                        }
                                        varTemp[ident] = ident;
                                        varTemp[ident] = (yyvsp[-3].num_val);
                                    }
                                    temp.append(ident);
                                    ex = true;
                            }
                            else{
                                    std::string ident = parse.substr(left,right-left);
                                    if(reserved.find(ident) != reserved.end()){
                                        printf("Identifier %s's name is a reserved word. \n", ident.c_str());
                                    }
                                    if(funcs.find(ident) != funcs.end() || varTemp.find(ident) != varTemp.end()){
                                        printf("Identifier %s is previously declared. \n", ident.c_str());
                                    }
                                    else{
                                        if((yyvsp[-3].num_val) <= 0){
                                        printf("Declaring array ident %s of size <= 0. \n", ident.c_str()); 
                                        }
                                        varTemp[ident] = ident;
                                        varTemp[ident] = (yyvsp[-3].num_val);
                                    }
                                    temp.append(ident);
                                    left = right + 1;
                            }
                            temp.append(", ");
                            temp.append(std::to_string((yyvsp[-3].num_val)));
                            temp.append("\n");
                    }
                    (yyval.expression).code = strdup(temp.c_str());
                    (yyval.expression).place = strdup("");
            }
#line 1560 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 228 "mini_l.y" /* yacc.c:1646  */
    {
                    std::string temp;
                    temp.append((yyvsp[-2].statement).code);
                    temp.append((yyvsp[0].statement).code);
                    (yyval.statement).code = strdup(temp.c_str());
            }
#line 1571 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 235 "mini_l.y" /* yacc.c:1646  */
    {
                    (yyval.statement).code = strdup((yyvsp[-1].statement).code);
            }
#line 1579 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 240 "mini_l.y" /* yacc.c:1646  */
    {
                    std::string temp;
                    temp.append((yyvsp[-2].expression).code);
                    temp.append((yyvsp[0].expression).code);
                    std::string middle = (yyvsp[0].expression).place;
                    if((yyvsp[-2].expression).arr && (yyvsp[0].expression).arr){
                            temp += "[]= ";
                    }
                    else if((yyvsp[-2].expression).arr){
                            temp += "[]= ";
                    }
                    else if((yyvsp[0].expression).arr){
                            temp += "=[] ";
                    }
                    else{
                            temp += "= ";   
                    }
                    temp.append((yyvsp[-2].expression).place);
                    temp.append(", ");
                    temp.append(middle);
                    temp += "\n";
                    (yyval.statement).code = strdup(temp.c_str());

            }
#line 1608 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 265 "mini_l.y" /* yacc.c:1646  */
    {
                    std::string begin_if = new_label();
                    std::string after = new_label();
                    std::string temp;
                    temp.append((yyvsp[-3].expression).code);
                    temp = temp + "?:= " + begin_if+ ", " + (yyvsp[-3].expression).place + "\n";
                    temp = temp + ":= " + after + "\n";
                    temp = temp + ": " + begin_if + "\n";
                    // declaring a label
                    temp.append((yyvsp[-1].statement).code);
                    temp = temp + ": " + after + "\n ";
                    (yyval.statement).code = strdup(temp.c_str());

            }
#line 1627 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 280 "mini_l.y" /* yacc.c:1646  */
    {
                    std::string begin_if = new_label();
                    std::string after = new_label();
                    std::string temp;
                    temp.append((yyvsp[-5].expression).code);
                    temp = temp + "?:= " + begin_if + ", " + (yyvsp[-5].expression).place + "\n";
                    temp.append((yyvsp[-1].statement).code);
                    temp = temp + ":= " + after + "\n";
                    temp = temp + ": " + begin_if + "\n";
                    temp.append((yyvsp[-3].statement).code);
                    temp = temp + ": " + after + "\n";
                    (yyval.statement).code = strdup(temp.c_str());

            }
#line 1646 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 295 "mini_l.y" /* yacc.c:1646  */
    {
                    std::string begin = new_label();
                    std::string first = new_label();
                    std::string after = new_label();
                    std::string temp;
                    std::string code = (yyvsp[-1].statement).code;
                    size_t pos = code.find("continue");
                    while(pos != std::string::npos){
                            code.replace(pos,8,":= " +begin);
                            pos = code.find("continue");
                    }
                    temp.append(": ");
                    temp += begin + "\n";
                    temp.append((yyvsp[-3].expression).code);
                    temp += "?:=" + first + ", ";
                    temp.append((yyvsp[-3].expression).place);
                    temp.append("\n");
                    temp += ":= " + after + "\n";
                    temp += ": " + first + "\n";
                    temp.append((yyvsp[-1].statement).code);
                    temp += ":= " + begin + "\n";
                    temp += ": " + after + "\n";
                    (yyval.statement).code = strdup(temp.c_str());
            }
#line 1675 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 320 "mini_l.y" /* yacc.c:1646  */
    {
                    std::string begin = new_label();
                    std::string after = new_label();
                    std::string temp;
                    std::string code = (yyvsp[-3].statement).code;
                    size_t pos = code.find("continue");
                    while(pos != std::string::npos){
                        code.replace(pos,8,":= " + after);
                        pos = code.find("continue");
                    }
                    temp.append(": ");
                    temp += begin +"\n";
                    temp.append((yyvsp[-3].statement).code);
                    temp += ": " + after + "\n";
                    temp.append((yyvsp[0].expression).code);
                    temp += "?:= " + begin + ",";
                    temp.append((yyvsp[0].expression).place);
                    temp.append("\n");
                    (yyval.statement).code = strdup(temp.c_str());


            }
#line 1702 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 343 "mini_l.y" /* yacc.c:1646  */
    {
                    std::string temp;
                    temp.append((yyvsp[0].expression).code);
                    size_t pos = temp.find("|", 0);
                    while(pos != std::string::npos){
                            temp.replace(pos, 1, "<");
                            pos = temp.find("|",pos);
                    }
                    (yyval.statement).code = strdup(temp.c_str());
            }
#line 1717 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 354 "mini_l.y" /* yacc.c:1646  */
    {
                    std::string temp;
                    temp.append((yyvsp[0].expression).code);
                    size_t pos = temp.find("|",0);
                    while(pos != std::string::npos){
                            temp.replace(pos,1,">");
                            pos = temp.find("|", pos);
                    }
                    (yyval.statement).code = strdup(temp.c_str());

            }
#line 1733 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 366 "mini_l.y" /* yacc.c:1646  */
    {
                    (yyval.statement).code = strdup("continue");
            }
#line 1741 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 370 "mini_l.y" /* yacc.c:1646  */
    {
                    std::string temp;
                    temp.append((yyvsp[0].expression).code);
                    temp.append((yyvsp[0].expression).place);
                    temp.append("\n");
                    (yyval.statement).code = strdup(temp.c_str());
            }
#line 1753 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 379 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code =strdup((yyvsp[0].expression).code);
                            (yyval.expression).place = strdup((yyvsp[0].expression).place);
                    }
#line 1762 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 384 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append((yyvsp[-2].expression).code);
                            temp.append((yyvsp[0].expression).code);
                            temp += ". "+ dst + "\n";
                            temp += "|| " + dst + ",";
                            temp.append((yyvsp[-2].expression).place);
                            temp += ",";
                            temp.append((yyvsp[0].expression).place);
                            temp += "\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                    }
#line 1781 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 400 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code =strdup((yyvsp[0].expression).code);
                            (yyval.expression).place = strdup((yyvsp[0].expression).place);
                    }
#line 1790 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 405 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append((yyvsp[-2].expression).code);
                            temp.append((yyvsp[0].expression).code);
                            temp += ". "+ dst + "\n";
                            temp += "&& " + dst + ",";
                            temp.append((yyvsp[-2].expression).place);
                            temp += ",";
                            temp.append((yyvsp[0].expression).place);
                            temp += "\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                    }
#line 1809 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 422 "mini_l.y" /* yacc.c:1646  */
    {
                           std::string temp;
                           std::string dst = new_temp();
                           temp.append((yyvsp[0].expression).code);
                           temp += ". " + dst + "\n";
                           temp == "! " + dst + ",";
                           temp.append((yyvsp[0].expression).place);
                           temp.append("\n");
                           (yyval.expression).code = strdup(temp.c_str());
                           (yyval.expression).place = strdup((yyvsp[0].expression).place);
                   }
#line 1825 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 433 "mini_l.y" /* yacc.c:1646  */
    {
                           (yyval.expression).code = strdup((yyvsp[0].expression).code);
                           (yyval.expression).place = strdup((yyvsp[0].expression).place);

        }
#line 1835 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 441 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string dst = new_temp();
                            std::string temp;
                            temp.append((yyvsp[-2].expression).code);
                            temp.append((yyvsp[0].expression).code);
                            temp = temp + ". " + dst + "\n" + (yyvsp[-1].expression).place + dst + ", " + (yyvsp[-2].expression).place + ", " + (yyvsp[0].expression).place + "\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                    }
#line 1849 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 451 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            temp.append("1");
                            (yyval.expression).code = strdup("");
                            (yyval.expression).place = strdup(temp.c_str());
                    }
#line 1860 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 458 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            temp.append("0");
                            (yyval.expression).code = strdup("");
                            (yyval.expression).place = strdup(temp.c_str());
                    }
#line 1871 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 465 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code = strdup((yyvsp[-1].expression).code);
                            (yyval.expression).place = strdup((yyvsp[-1].expression).place);
                    }
#line 1880 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 481 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code = strdup("");
                            (yyval.expression).place = strdup("==");
                    }
#line 1889 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 486 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code = strdup("");
                            (yyval.expression).place = strdup("!=");
                    }
#line 1898 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 491 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code = strdup("");
                            (yyval.expression).place = strdup("<");
                    }
#line 1907 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 496 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code = strdup("");
                            (yyval.expression).place = strdup(">");
                    }
#line 1916 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 501 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code = strdup("");
                            (yyval.expression).place = strdup(">=");
                    }
#line 1925 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 506 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code = strdup("");
                            (yyval.expression).place = strdup("<=");
                    }
#line 1934 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 512 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code = strdup((yyvsp[0].expression).code);
                            (yyval.expression).place = strdup((yyvsp[0].expression).place);
                    }
#line 1943 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 517 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append((yyvsp[-2].expression).code);
                            temp.append((yyvsp[0].expression).code);
                            temp += ". "+ dst + "\n";
                            temp += "+ " + dst + ",";
                            temp.append((yyvsp[-2].expression).place);
                            temp += ",";
                            temp.append((yyvsp[0].expression).place);
                            temp += "\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                    }
#line 1962 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 532 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append((yyvsp[-2].expression).code);
                            temp.append((yyvsp[0].expression).code);
                            temp += ". "+ dst + "\n";
                            temp += "- " + dst + ",";
                            temp.append((yyvsp[-2].expression).place);
                            temp += ",";
                            temp.append((yyvsp[0].expression).place);
                            temp += "\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                    }
#line 1981 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 548 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            temp.append((yyvsp[-2].expression).code);
                            temp.append("param ");
                            temp.append((yyvsp[-2].expression).place);
                            temp.append("\n");
                            temp.append((yyvsp[0].expression).code);
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup("");
                    }
#line 1996 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 559 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            temp.append((yyvsp[0].expression).code);
                            temp.append("param ");
                            temp.append((yyvsp[0].expression).place);
                            temp.append("\n");
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup("");
                    }
#line 2010 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 570 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code = strdup((yyvsp[0].expression).code);
                            (yyval.expression).place = strdup((yyvsp[0].expression).place);
                    }
#line 2019 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 575 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append((yyvsp[-2].expression).code);
                            temp.append((yyvsp[0].expression).code);
                            temp.append(".");
                            temp.append(dst);
                            temp.append("\n");
                            temp += "* " + dst + ", ";
                            temp.append((yyvsp[-2].expression).place);
                            temp += ",";
                            temp.append((yyvsp[0].expression).place);
                            temp += "\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());

                    }
#line 2041 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 593 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append((yyvsp[-2].expression).code);
                            temp.append((yyvsp[0].expression).code);
                            temp.append(".");
                            temp.append(dst);
                            temp.append("\n");
                            temp += "/ " + dst + ", ";
                            temp.append((yyvsp[-2].expression).place);
                            temp += ",";
                            temp.append((yyvsp[0].expression).place);
                            temp += "\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                    }
#line 2062 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 610 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            std::string dst = new_temp();
                            temp.append((yyvsp[-2].expression).code);
                            temp.append((yyvsp[0].expression).code);
                            temp.append(".");
                            temp.append(dst);
                            temp.append("\n");
                            temp += "%" + dst + ", ";
                            temp.append((yyvsp[-2].expression).place);
                            temp += ",";
                            temp.append((yyvsp[0].expression).place);
                            temp += "\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                    }
#line 2083 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 628 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string dst = new_temp();
                            std::string temp;
                            if((yyvsp[0].expression).arr){
                                    temp.append((yyvsp[0].expression).code);
                                    temp.append(". ");
                                    temp.append(dst);
                                    temp.append("\n");
                                    temp += "=[] " + dst + ", ";
                                    temp.append((yyvsp[0].expression).place);
                                    temp.append("\n");
                            }
                            else{
                                    temp.append(". ");
                                    temp.append(dst);
                                    temp.append("\n");
                                    temp = temp + "= " + dst + ", ";
                                    temp.append((yyvsp[0].expression).place);
                                    temp.append("\n");
                                    temp.append((yyvsp[0].expression).code);
                            }
                            if(varTemp.find((yyvsp[0].expression).place) != varTemp.end()){
                                    varTemp[(yyvsp[0].expression).place] = dst;
                            }
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                    }
#line 2115 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 656 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string dst = new_temp();
                            std::string temp;
                            temp.append(". ");
                            temp.append(dst);
                            temp.append("\n");
                            temp = temp + "= " + dst + "," + std::to_string((yyvsp[0].num_val)) + "\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                            
                    }
#line 2131 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 668 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).code = strdup((yyvsp[-1].expression).code);
                            (yyval.expression).place = strdup((yyvsp[-1].expression).place);
                    }
#line 2140 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 673 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            std::string func = (yyvsp[-3].expression).place;
                            if(funcs.find(func) == funcs.end()){
                                    printf("Calling undeclared function %s. \n", func.c_str());
                            }
                            std::string dst = new_temp();
                            temp.append((yyvsp[-1].expression).code);
                            temp += ". " + dst + "\ncall ";
                            temp.append((yyvsp[-3].expression).place);
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                    }
#line 2158 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 688 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string dst = new_temp();
                            std::string temp;
                            if((yyvsp[0].expression).arr){
                                    temp.append((yyvsp[0].expression).code);
                                    temp.append(". ");
                                    temp.append(dst);
                                    temp.append("\n");
                                    temp += "=[] " + dst + ", ";
                                    temp.append((yyvsp[0].expression).place);
                                    temp.append("\n");
                            }
                            else{
                                    temp.append(". ");
                                    temp.append(dst);
                                    temp.append("\n");
                                    temp = temp + "= " + dst + ", ";
                                    temp.append((yyvsp[0].expression).place);
                                    temp.append("\n");
                                    temp.append((yyvsp[0].expression).code);
                            }
                            if(varTemp.find((yyvsp[0].expression).place) != varTemp.end()){
                                    varTemp[(yyvsp[0].expression).place] = dst;
                            }
                            temp += "* " + dst + ", " + dst + ", -1\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());
                    }
#line 2191 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 717 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string dst = new_temp();
                            std::string temp;
                            temp.append(". ");
                            temp.append(dst);
                            temp.append("\n");
                            temp = temp + "= " + dst + ", -" + std::to_string((yyvsp[0].num_val)) + "\n";
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup(dst.c_str());

                    }
#line 2207 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 729 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            temp.append((yyvsp[-1].expression).code);
                            temp.append("* ");
                            temp.append((yyvsp[-1].expression).place);
                            temp.append(", ");
                            temp.append(", -1\n");
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup((yyvsp[-1].expression).place);
                    }
#line 2222 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 742 "mini_l.y" /* yacc.c:1646  */
    {
                        if(funcs.find((yyvsp[0].id_val)) != funcs.end()){
                                printf("function name %s already declared.\n",(yyvsp[0].id_val));
                        }
                        else{
                                funcs.insert((yyvsp[0].id_val));
                        }
                        (yyval.expression).place = strdup((yyvsp[0].id_val));
                        (yyval.expression).code = strdup("");
                }
#line 2237 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 755 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).place = strdup((yyvsp[0].id_val));
                            (yyval.expression).code = strdup("");
                    }
#line 2246 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 762 "mini_l.y" /* yacc.c:1646  */
    {
                            (yyval.expression).place = strdup((yyvsp[0].expression).place);
                            (yyval.expression).code = strdup("");
                    }
#line 2255 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 767 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            temp.append((yyvsp[-2].expression).place);
                            temp.append("|");
                            temp.append((yyvsp[0].expression).place);
                            (yyval.expression).place = strdup(temp.c_str());
                            (yyval.expression).code = strdup("");
                    }
#line 2268 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 777 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            temp.append((yyvsp[-2].expression).code);
                            if((yyvsp[-2].expression).arr){
                                    temp.append(".[]| ");
                            }
                            else{
                                    temp.append(".| ");
                            }
                            temp.append((yyvsp[-2].expression).place);
                            temp.append("\n");
                            temp.append((yyvsp[0].expression).code);
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup("");
                    }
#line 2288 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 793 "mini_l.y" /* yacc.c:1646  */
    {
                            std::string temp;
                            temp.append((yyvsp[0].expression).code);
                            if((yyvsp[0].expression).arr){
                                    temp.append(".[]| ");
                            }
                            else{
                                    temp.append(".|");
                            }
                            temp.append((yyvsp[0].expression).place);
                            temp.append("\n");
                            (yyval.expression).code = strdup(temp.c_str());
                            (yyval.expression).place = strdup("");
                    }
#line 2307 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 810 "mini_l.y" /* yacc.c:1646  */
    {
                             std::string temp;
                             std::string ident = (yyvsp[0].expression).place;
                             if(funcs.find(ident) == funcs.end() && varTemp.find(ident) == varTemp.end()){
                                     printf("Identifier %s is not declared. \n", ident.c_str());
                             }
                             else if(arrSize[ident] > 1){
                                     printf("Did not provide index for array Identifier %s\n", ident.c_str());
                             }
                             (yyval.expression).code = strdup("");
                             (yyval.expression).place = strdup(ident.c_str());
                             (yyval.expression).arr = false;
                     }
#line 2325 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 825 "mini_l.y" /* yacc.c:1646  */
    {
                             std::string temp;
                             std::string ident = (yyvsp[-3].expression).place;
                             if( funcs.find(ident) == funcs.end() && varTemp.find(ident) == varTemp.end()){
                                     printf("Identifier %s is not declared. \n", ident.c_str());

                             }
                             else if(arrSize[ident] > 1){
                                     printf("Did not provide index for array Identifier %s\n", ident.c_str());
                             }
                             temp.append((yyvsp[-3].expression).place);
                             temp.append(", ");
                             temp.append((yyvsp[-1].expression).place);
                             (yyval.expression).code = strdup((yyvsp[-1].expression).code);
                             (yyval.expression).place = strdup(temp.c_str());
                             (yyval.expression).arr = true;
                     }
#line 2347 "mini_l.tab.c" /* yacc.c:1646  */
    break;


#line 2351 "mini_l.tab.c" /* yacc.c:1646  */
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
#line 843 "mini_l.y" /* yacc.c:1906  */


void yyerror(const char *msg){
        extern int yylineno;
        extern char* yytext;
        printf("%s on line %d at char %d at symbol \"%s\"\n",msg, yylineno,currPos,yytext);
        exit(1);
}
std::string new_temp(){
    std::string t = 't' + std::to_string(tempCount);
    tempCount++;
    return t;
}
std::string new_label(){
    std::string l = "L" + std::to_string(labelCount);
    labelCount++;
    return l;
}
