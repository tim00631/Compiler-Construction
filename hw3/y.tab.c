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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

#include "global.h" // include header if needed
#define BUF_SIZE 1000

extern int yylineno;
extern int yylex();
extern char *yytext; // Get current token from lex
extern char buf[BUF_SIZE]; // Get current code line from lex
char code_buf[100];
FILE *file; // To generate .j file for Jasmin
int table_not_create =0;
void yyerror(char *s);

/* Symbol Table Structure, Variable Definition */
typedef struct Entry Entry;
struct Entry {
    int index;
    char* name;
    char* kind;
    char* type;
    int scope;
    char* attribute;
    Entry *next;
};
typedef struct Header Header;
struct Header {
    int depth;
    int entry_num;
    Entry *table_root;
    Entry *table_tail;
    Header *pre;
};
Header *header_root = NULL; // connect these headers
Header *cur_header = NULL; // current header
int depth = 0;
Value NaV;

extern int syntax_error;
extern int semantic_error;
extern int NumberOfError;
extern int syn_error_number;
extern int dump_flag;
extern char* error_msg[20];
extern char* syn_error_msg[20];
void redeclared_check(char* name,char* kind);
void undeclared_check(char* name,char* kind);
char* add_attribute(Header *header);
/* symbol table functions */
char* convert_type(Type type);
int lookup_symbol(Header *header, char* name);
void create_symbol_table();
void free_symbol_table();
void insert_symbol(Header *header, Value id, char* kind, Value type, Value R_val);
void dump_symbol();
void debug(char* s);
/* code generation functions, just an example! */
void gencode(char * s);
void do_declaration_stat(int index, Value type, Value id, Value R_val);
void do_function_definition(Entry *temp);
void do_function_call(Value id);
void do_assign_expr(Value term1, Operator op, Value term2);
void do_return_stat(Value term1);
void do_print(Value term1);
void find_return_type(Value term);
Value find_assign_type(Value term, Value term2);                
Value do_postfix_expr(Value term1, Operator op);
Value do_multiplication_expr(Value term1, Operator op, Value term2);
Value do_addition_expr(Value term1, Operator op, Value term2);
Value do_comparison_expr(Value term1, Operator op, Value term2);
Value find_original_type(Value term1,int cast);
char* str_replace(char* string, const char* substr, const char* replacement);

#line 139 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    RETURN = 262,
    SEMICOLON = 263,
    PRINT = 264,
    ADDASGN = 265,
    SUBASGN = 266,
    MULASGN = 267,
    DIVASGN = 268,
    MODASGN = 269,
    INC = 270,
    DEC = 271,
    MTE = 272,
    LTE = 273,
    EQ = 274,
    NE = 275,
    VOID = 276,
    INT = 277,
    FLOAT = 278,
    BOOL = 279,
    STRING = 280,
    TRUE = 281,
    FALSE = 282,
    I_CONST = 283,
    F_CONST = 284,
    STR_CONST = 285,
    ID = 286
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define RETURN 262
#define SEMICOLON 263
#define PRINT 264
#define ADDASGN 265
#define SUBASGN 266
#define MULASGN 267
#define DIVASGN 268
#define MODASGN 269
#define INC 270
#define DEC 271
#define MTE 272
#define LTE 273
#define EQ 274
#define NE 275
#define VOID 276
#define INT 277
#define FLOAT 278
#define BOOL 279
#define STRING 280
#define TRUE 281
#define FALSE 282
#define I_CONST 283
#define F_CONST 284
#define STR_CONST 285
#define ID 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 75 "compiler_hw3.y" /* yacc.c:355  */

    Value val;
    Operator op;

#line 246 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 263 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    38,     2,     2,    41,     2,     2,
      33,    34,    39,    42,    35,    43,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    32,    45,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   106,   106,   107,   110,   111,   112,   113,   114,   115,
     116,   117,   120,   121,   124,   125,   126,   127,   128,   131,
     131,   131,   134,   135,   136,   139,   142,   142,   145,   146,
     147,   150,   151,   152,   155,   155,   158,   159,   160,   161,
     162,   163,   166,   167,   168,   171,   174,   177,   180,   183,
     186,   189,   190,   191,   194,   195,   198,   199,   200,   203,
     204,   207,   208,   209,   210,   211,   212,   215,   216,   217,
     218,   219,   220,   223,   224,   227,   228,   231,   232,   235,
     236,   239,   240,   243,   244
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "RETURN",
  "SEMICOLON", "PRINT", "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN",
  "MODASGN", "INC", "DEC", "MTE", "LTE", "EQ", "NE", "VOID", "INT",
  "FLOAT", "BOOL", "STRING", "TRUE", "FALSE", "I_CONST", "F_CONST",
  "STR_CONST", "ID", "'='", "'('", "')'", "','", "'{'", "'}'", "'\"'",
  "'*'", "'/'", "'%'", "'+'", "'-'", "'<'", "'>'", "$accept", "program",
  "stat", "declaration", "type", "func_declaration", "$@1", "$@2",
  "parameter_list", "parameter", "function_call", "$@3", "argument_list",
  "compound_stat", "assign_stat", "$@4", "assign_op", "if_stat",
  "while_stat", "block", "lb", "rb", "expression_stat", "expression",
  "constant", "post_op", "mul_op", "add_op", "cmp_op",
  "parenthesis_clause", "postfix_expr", "multiplication_expr",
  "addition_expr", "comparison_expr", "return_stat", "print_func", YY_NULLPTR
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
     285,   286,    61,    40,    41,    44,   123,   125,    34,    42,
      47,    37,    43,    45,    60,    62
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -73

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -93,     6,   -93,   102,   102,    66,   -93,   -25,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   106,   102,    10,
     -93,   -93,    38,   -93,    70,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,    -5,   -93,    16,     9,     5,   -93,   -93,    40,
     -93,    35,    35,   -93,    73,   118,    42,   111,    49,    58,
      46,   -93,   -93,   -93,   -93,   -93,   -93,   102,   -93,   -93,
     102,   -93,   -93,   -93,   -93,   -93,   -93,   102,   -93,    94,
     -93,   -93,   -93,    11,    69,    74,   -93,   -93,   -93,   -93,
     -93,   -93,   102,   -93,   -93,   -93,   102,   -93,   -93,    16,
       9,     2,    39,    62,    98,   -93,    24,    99,   100,    -4,
     -93,   -93,   -93,   -93,    92,   -93,   119,   101,   -93,   -93,
     103,    67,   -93,   128,   -93,   -93,   -93,   -93,    -4,   -93,
      35,   -93,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,    11,     0,    18,    14,
      15,    16,    17,    70,    71,    51,    52,    68,     0,     0,
       2,     4,     0,     5,     6,     7,    31,    32,    33,     8,
      49,    67,    73,    75,    77,    79,    50,     9,    10,    68,
      72,     0,     0,    81,     0,     0,     0,     0,     0,     0,
       0,    54,    55,    74,    56,    57,    58,     0,    59,    60,
       0,    63,    64,    65,    66,    61,    62,     0,    47,    42,
       3,    45,    82,     0,     0,    30,    37,    38,    39,    40,
      41,    36,     0,    69,    53,    13,     0,    19,    76,    78,
      80,     0,     0,     0,     0,    28,     0,     0,     0,    24,
      44,    43,    48,    46,     0,    83,     0,     0,    35,    12,
       0,     0,    22,     0,    27,    29,    25,    20,     0,    84,
       0,    23,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,    71,   -93,   -93,   -92,   -93,   -93,   -93,   -93,    19,
      -1,   -93,   -93,   -93,   -93,   -93,   -93,    51,   -93,   -38,
     -93,   -93,   -93,    -2,   -93,   -93,   -93,   -93,   -93,   -93,
      91,    90,    85,   -93,   -93,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    20,    21,    22,    23,    99,   120,   111,   112,
      40,    46,    96,    25,    26,    47,    82,    27,    28,    69,
      70,   103,    29,    30,    31,    53,    57,    60,    67,    32,
      33,    34,    35,    36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,    41,    42,    44,    71,     3,     2,   110,    45,     3,
      51,    52,     4,     5,     6,     7,    48,     8,     9,    10,
      11,    12,    61,    62,    63,    64,   110,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    93,    17,    68,    18,
      49,    49,     3,    74,    19,     4,     5,     6,     7,    65,
      66,    58,    59,   101,    85,    54,    55,    56,   106,   107,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    50,
      17,    68,    18,   -26,    43,    75,   102,    19,    86,    87,
      97,    72,   122,    83,    98,   -72,   -72,   -72,   -72,   -72,
     -72,    24,    13,    14,    15,    16,    84,    39,    91,    18,
     104,   117,   118,    94,    19,    95,   105,   108,   109,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -34,   -34,   -34,   -34,
     -34,    76,    77,    78,    79,    80,   113,   114,    13,    14,
      15,    16,   115,    39,   116,    18,   119,   121,   -34,   -26,
      19,    92,   100,    81,    13,    14,    15,    16,    88,    39,
      89,    18,    90,     0,     0,     0,    73
};

static const yytype_int8 yycheck[] =
{
       1,     3,     4,     5,    42,     3,     0,    99,    33,     3,
      15,    16,     6,     7,     8,     9,    18,    21,    22,    23,
      24,    25,    17,    18,    19,    20,   118,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    25,    31,    36,    33,
      30,    30,     3,    45,    38,     6,     7,     8,     9,    44,
      45,    42,    43,    91,     8,    39,    40,    41,    34,    35,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    31,
      31,    36,    33,    33,     8,    33,    37,    38,    32,    33,
      82,     8,   120,    34,    86,    15,    16,    17,    18,    19,
      20,    92,    26,    27,    28,    29,    38,    31,     4,    33,
      38,    34,    35,    34,    38,    31,     8,     8,     8,    39,
      40,    41,    42,    43,    44,    45,    10,    11,    12,    13,
      14,    10,    11,    12,    13,    14,    34,     8,    26,    27,
      28,    29,    31,    31,    31,    33,     8,   118,    32,    33,
      38,    70,    91,    32,    26,    27,    28,    29,    57,    31,
      60,    33,    67,    -1,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,     0,     3,     6,     7,     8,     9,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    31,    33,    38,
      48,    49,    50,    51,    56,    59,    60,    63,    64,    68,
      69,    70,    75,    76,    77,    78,    79,    80,    81,    31,
      56,    69,    69,     8,    69,    33,    57,    61,    69,    30,
      31,    15,    16,    71,    39,    40,    41,    72,    42,    43,
      73,    17,    18,    19,    20,    44,    45,    74,    36,    65,
      66,    65,     8,    38,    69,    33,    10,    11,    12,    13,
      14,    32,    62,    34,    38,     8,    32,    33,    76,    77,
      78,     4,    47,    25,    34,    31,    58,    69,    69,    52,
      63,    65,    37,    67,    38,     8,    34,    35,     8,     8,
      50,    54,    55,    34,     8,    31,    31,    34,    35,     8,
      53,    55,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    52,
      53,    51,    54,    54,    54,    55,    57,    56,    58,    58,
      58,    59,    59,    59,    61,    60,    62,    62,    62,    62,
      62,    62,    63,    63,    63,    64,    65,    66,    67,    68,
      69,    70,    70,    70,    71,    71,    72,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    75,    75,    75,
      75,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    80,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     3,     1,     1,     1,     1,     1,     0,
       0,     8,     1,     3,     0,     2,     0,     6,     1,     3,
       0,     1,     1,     1,     0,     5,     1,     1,     1,     1,
       1,     1,     3,     5,     5,     3,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       3,     2,     3,     5,     7
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
        case 12:
#line 120 "compiler_hw3.y" /* yacc.c:1646  */
    { insert_symbol(cur_header, (yyvsp[-3].val), "variable", (yyvsp[-4].val), (yyvsp[-1].val)); }
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 121 "compiler_hw3.y" /* yacc.c:1646  */
    { insert_symbol(cur_header, (yyvsp[-1].val), "variable", (yyvsp[-2].val), NaV); }
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 124 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 131 "compiler_hw3.y" /* yacc.c:1646  */
    { create_symbol_table(); }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 131 "compiler_hw3.y" /* yacc.c:1646  */
    {insert_symbol(cur_header->pre, (yyvsp[-4].val), "function", (yyvsp[-5].val), NaV); }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 131 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_flag = 1; }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 134 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 136 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = NaV;}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 139 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[-1].val); insert_symbol(cur_header, (yyvsp[0].val), "parameter", (yyvsp[-1].val), NaV); }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 142 "compiler_hw3.y" /* yacc.c:1646  */
    { undeclared_check((yyvsp[0].val).string, "function"); }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 142 "compiler_hw3.y" /* yacc.c:1646  */
    {do_function_call((yyvsp[-5].val));}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 145 "compiler_hw3.y" /* yacc.c:1646  */
    { undeclared_check((yyvsp[0].val).string, "variable"); }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 146 "compiler_hw3.y" /* yacc.c:1646  */
    { undeclared_check((yyvsp[0].val).string, "variable"); }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 147 "compiler_hw3.y" /* yacc.c:1646  */
    { }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 155 "compiler_hw3.y" /* yacc.c:1646  */
    { undeclared_check((yyvsp[0].val).string, "variable"); }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 155 "compiler_hw3.y" /* yacc.c:1646  */
    { do_assign_expr((yyvsp[-4].val), (yyvsp[-2].op), (yyvsp[-1].val));}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 158 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.op) = ASGN_OP;}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 159 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.op) = ADDASGN_OP;}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 160 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.op) = SUBASGN_OP;}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 161 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.op) = MULASGN_OP;}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 162 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.op) = DIVASGN_OP;}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 163 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.op) = MODASGN_OP;}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 183 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 186 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 189 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 190 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[-1].val); }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 194 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = INC_OP; }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 195 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = DEC_OP; }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 198 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = MUL_OP; }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 199 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = DIV_OP; }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 200 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = MOD_OP; }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 203 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = ADD_OP; }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 204 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = SUB_OP; }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 207 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = LT_OP; }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 208 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = MT_OP; }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 209 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = MTE_OP; }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 210 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = LTE_OP; }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 211 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = EQ_OP; }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 212 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op) = NE_OP; }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 215 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 216 "compiler_hw3.y" /* yacc.c:1646  */
    { undeclared_check((yyvsp[0].val).string, "variable"); (yyval.val) = (yyvsp[0].val);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 217 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[-1].val); }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 218 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 219 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val);  }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 220 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 223 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 224 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = do_postfix_expr((yyvsp[-1].val), (yyvsp[0].op)); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 227 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 228 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = do_multiplication_expr((yyvsp[-2].val), (yyvsp[-1].op), (yyvsp[0].val)); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 231 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 232 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = do_addition_expr((yyvsp[-2].val), (yyvsp[-1].op), (yyvsp[0].val)); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 235 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 236 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.val) = do_comparison_expr((yyvsp[-2].val), (yyvsp[-1].op), (yyvsp[0].val)); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 239 "compiler_hw3.y" /* yacc.c:1646  */
    { debug("void return"); do_return_stat(NaV); }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 240 "compiler_hw3.y" /* yacc.c:1646  */
    { do_return_stat((yyvsp[-1].val)); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 243 "compiler_hw3.y" /* yacc.c:1646  */
    { do_print((yyvsp[-2].val)); }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 244 "compiler_hw3.y" /* yacc.c:1646  */
    { do_print((yyvsp[-3].val)); }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1812 "y.tab.c" /* yacc.c:1646  */
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
#line 247 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
    NaV.type = NAT;
    NaV.i_val = 0;
    NaV.f_val = 0.0;
    NaV.string = "";
    create_symbol_table();
    file = fopen("compiler_hw3.j","w");
    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
    yyparse();
    // fprintf(file, "\treturn\n"
    //               ".end method\n");
    if(!syntax_error){
        dump_symbol();
        printf("\nTotal lines: %d \n",yylineno);
    }
    fclose(file);

    return 0;
}

// void yyerror(char *s)
// {
//     printf("\n|-----------------------------------------------|\n");
//     printf("| Error found in line %d: %s\n", yylineno, buf);
//     printf("| %s", s);
//     printf("\n| Unmatched token: %s", yytext);
//     printf("\n|-----------------------------------------------|\n");
//     exit(-1);
// }
void yyerror(char *s)
{
    if(!strcmp(s,"syntax error")){
        printf("%d: %s\n", yylineno, buf);
        syntax_error = 1;
        if(semantic_error){
            for (int i = 0; i< NumberOfError;i++){
                printf("\n|-----------------------------------------------|\n");
                printf("| Error found in line %d: %s\n", yylineno, buf);
                printf("| %s", error_msg[i]);
                printf("\n|-----------------------------------------------|\n\n");
                memset(error_msg[i],'\0', 200);
            }
            semantic_error = 0;
            NumberOfError = 0;
        }
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");        
    } else {     
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");
    }
}

/* symbol table functions */
void create_symbol_table() {
    Header *ptr = malloc(sizeof(Header));
    ptr->depth = depth++;
    ptr->entry_num = 0;
    ptr->table_root = malloc(sizeof(Entry));
    ptr->table_root->next = NULL;
    ptr->table_tail = ptr->table_root;
    if(cur_header == NULL) header_root = ptr;
    printf("create a table: %d\n", ptr->depth);
    ptr->pre = cur_header;
    cur_header = ptr;
}
void insert_symbol(Header *header, Value id, char* kind, Value type, Value R_val){
    printf("insert_symbol %s\n",id.string);
    if(header == NULL){
        debug("fuck");
        header = header_root;
    }
    if(cur_header == NULL){
        create_symbol_table();
        // header_root = cur_header;
        header = cur_header;
    }
    if(lookup_symbol(cur_header, id.string) == -1){
        Entry *temp = malloc(sizeof(Entry));
        temp->index = header->entry_num++;
        temp->name = id.string;
        id.type =type.type;
        temp->kind = kind;
        temp->type = type.string;
        temp->scope = header->depth;
        temp->next = NULL;
        if(!strcmp(kind,"function")){
            char* attr = add_attribute(cur_header);
            temp->attribute = attr;
        }
        header->table_tail->next = temp;
        header->table_tail = header->table_tail->next;
        if(!strcmp(kind,"variable")){
            do_declaration_stat(temp->index, type, id, R_val);
        }
        // else if(!strcmp(kind,"parameter")){
        //     do_declaration_stat(temp->index, type, id, R_val);
        // }
        else if(!strcmp(kind, "function")){ 
            do_function_definition(temp);
        }
        // printf("%-10d%-10s%-12s%-10s%-10d%-10s\n", temp->index, temp->id, temp->kind, temp->type, temp->scope, temp->attribute);
    } 
    else{
        redeclared_check(id.string, kind);
    }
}
char* add_attribute(Header *header){
    int n = 0;
    Entry *cur = header->table_root->next;
    char* temp = malloc(50);
    while(cur != NULL){
        if(!strcmp(cur->kind,"parameter")){
            if(n == 0){
                n++;
                strcpy(temp,cur->type);
                //attribute_gencode(cur->index, cur->type, cur, NAV);
            }
            else{
                strcat(temp,",");
                strcat(temp,cur->type);
            }
        }
        cur = cur->next;
    }
    return temp;
}

int lookup_symbol(Header *header, char* id) { 
    // return index 0~n :redeclared
    // return -1, undeclared
    if(header->table_root == NULL){
        return -1;
    }
    Entry *cur = header->table_root->next;
    while(cur != NULL){
        if(!strcmp(cur->name,id))
        {
            return cur->index;
        }
        else{
            cur = cur->next;
        }
    }
    return -1;
}

void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
    Entry *cur_entry = cur_header->table_root->next;
    while(cur_entry != NULL) {
        if(cur_entry->attribute != NULL) {
            printf("%-10d%-10s%-12s%-10s%-10d%s\n", cur_entry->index, cur_entry->name, cur_entry->kind, cur_entry->type, cur_entry->scope, cur_entry->attribute);
        }
        else {
            printf("%-10d%-10s%-12s%-10s%-10d\n", cur_entry->index, cur_entry->name, cur_entry->kind, cur_entry->type, cur_entry->scope);
        }
        Entry *temp = cur_entry;
        cur_entry = cur_entry->next;
        free(temp);
        temp = NULL;
    }
    printf("\n");
    cur_header->entry_num = 0;
    Header* tmp = cur_header;
    cur_header = cur_header->pre;
    free(tmp);
    tmp = NULL;
    depth = depth -1;
}

void free_symbol_table(){

}

void undeclared_check(char* name, char* kind){
        int undeclared = 1;
        Header *ptr = cur_header;
        while(ptr != NULL){
            if(lookup_symbol(ptr,name) != -1){
                undeclared = 0;
                break;
            } else {
                ptr = ptr->pre; // goto parent scope
            }
        }
        if(undeclared){
            if(!strcmp(kind, "function")){
                error_msg[NumberOfError] = malloc(200);
                sprintf(error_msg[NumberOfError++],"Undeclared function %s", name);
                semantic_error = 1;
            } else if(!strcmp(kind, "variable")){
                error_msg[NumberOfError] = malloc(200);
                sprintf(error_msg[NumberOfError++],"Undeclared variable %s", name);
                semantic_error = 1;
            }
        }
}
void redeclared_check(char* name, char* kind){
    //printf("%s\n",type);
    if(!strcmp(kind, "function")){
        sprintf(error_msg[NumberOfError++],"Redeclared function %s", name);
        semantic_error = 1;
    } else if(!strcmp(kind, "variable")){
        sprintf(error_msg[NumberOfError++],"Redeclared variable %s", name);
        semantic_error = 1;
    }
}

/* code generation functions */
void gencode(char *s) {
    fprintf(file, "%s", s);
}
// void attribute_gencode(int index, char* type, Value R_val){
//     debug("do_declaration");
//     if(index == -1){
//         debug("not found declaration");
//     }
//     switch (type.type){
//         case INT_T:
//             sprintf(code_buf,"\tiload %d\n", R_val.i_val, index);
//             strcat(attr_codebuf,code_buf);
//             break;
//         case FLOAT_T:
//             sprintf(code_buf,"\tiload %i\n", R_val.f_val, index); 
//             strcat(attr_codebuf,code_buf);
//             break;
//         case STRING_T:
//             sprintf(code_buf,"\tldc \"%s\"\n\tastore %i\n", R_val.string, index);
//             strcat(attr_codebuf,code_buf); 
//             break;
//         case BOOL_T:
//             sprintf(code_buf,"\tldc %i\n\tistore %i\n", R_val.i_val, index);
//             strcat(attr_codebuf,code_buf); 
//             break;
//         default:
//             printf("%s,%d\n",id,type.type);
//             debug("variable type is not int,float,string,bool. line 475");
//     }
// }

void do_declaration_stat(int index, Value type, Value id, Value R_val){
    debug("do_declaration");
    int global = 0;
    if(cur_header->depth == 0){
        global = 1;
    }
    char* asm_type = convert_type(type.type);
    if(index == -1){
        debug("not found declaration");
    }
    if(global){
        switch (type.type){
            case INT_T:
                sprintf(code_buf,".field public static %s %s = %d\n",id.string, asm_type, R_val.i_val); 
                gencode(code_buf);
                break;
            case FLOAT_T:
                sprintf(code_buf,".field public static %s %s = %f\n",id.string, asm_type, R_val.f_val);
                gencode(code_buf); 
                break;
            case STRING_T:
                sprintf(code_buf,".field public static %s %s = \"%s\"\n",id.string, asm_type, R_val.string);
                gencode(code_buf); 
                break;
            case BOOL_T:
                sprintf(code_buf,".field public static %s %s = \"%d\"\n",id.string, asm_type, R_val.i_val);
                gencode(code_buf); 
                break;
            default:
                printf("%d\n",type.type);
                debug("variable type is not int,float,string,bool. line 455");
                break;
        }
    }
    else if(!strcmp(R_val.string,"calculated")){ 
        switch (type.type){
            case INT_T:
                sprintf(code_buf,"\tistore %d\n", index);
                gencode(code_buf); 
                break;
            case FLOAT_T:
                sprintf(code_buf,"\tfstore %i\n", index); 
                gencode(code_buf);
                break;
            case STRING_T:
                sprintf(code_buf,"\tastore %i\n", index);
                gencode(code_buf); 
                break;
            case BOOL_T:
                sprintf(code_buf,"\tistore %i\n",  index);
                gencode(code_buf); 
                break;
            default:
                printf("%s,%d\n",id.string,type.type);
                debug("variable type is not int,float,string,bool. line 475");
        }
    }
    else{
        switch (type.type){
            case INT_T:
                sprintf(code_buf,"\tldc %d\n\tistore %d\n", R_val.i_val, index);
                gencode(code_buf); 
                break;
            case FLOAT_T:
                sprintf(code_buf,"\tldc %f\n\tfstore %i\n", R_val.f_val, index); 
                gencode(code_buf);
                break;
            case STRING_T:
                sprintf(code_buf,"\tldc \"%s\"\n\tastore %i\n", R_val.string, index);
                gencode(code_buf); 
                break;
            case BOOL_T:
                sprintf(code_buf,"\tldc %i\n\tistore %i\n", R_val.i_val, index);
                gencode(code_buf); 
                break;
            default:
                printf("%s,%d\n",id.string,type.type);
                debug("variable type is not int,float,string,bool. line 475");
        }
    }
}
void debug(char* s){
    printf("%s\n",s);
}
char* convert_type(Type type){
    switch (type){
        case INT_T:
            return "I";
            break;
        case FLOAT_T:
            return "F";
            break;
        case STRING_T:
            return "Ljava/lang/String;";
            break;
        case BOOL_T:
            return "Z";
            break;
        case VOID_T:
            return "V";
            break;     
        default :
            debug("type is not I, F, STRING, Z, V");
            break;
    }
}
void do_function_definition(Entry* temp){
    char* parameter = str_replace(temp->attribute,",","");
    parameter = str_replace(parameter,"int","I");
    parameter = str_replace(parameter,"float","F");
    parameter = str_replace(parameter,"bool", "Z");
    parameter = str_replace(parameter,"string","Ljava/lang/String;");
    if(!strcmp(temp->name,"main")){
        parameter = "[Ljava/lang/String;";
    }
    char* return_type = str_replace(temp->type,"int","I");
    return_type = str_replace(return_type,"float","F");
    return_type = str_replace(return_type,"bool", "Z");
    return_type = str_replace(return_type,"void", "V");
    return_type = str_replace(return_type,"string","Ljava/lang/String;");
    sprintf(code_buf,".method public static %s(%s)%s\n", temp->name,parameter,return_type);
    gencode(code_buf);
    sprintf(code_buf,".limit stack 50\n");
    gencode(code_buf);
    sprintf(code_buf,".limit locals 50\n");
    gencode(code_buf);
    //gencode(attr_codebuf);

}
char* str_replace(char* string, const char* substr, const char* replacement) {
	char* tok = NULL;
	char* newstr = NULL;
	char* oldstr = NULL;
	int   oldstr_len = 0;
	int   substr_len = 0;
	int   replacement_len = 0;

	newstr = strdup(string);
	substr_len = strlen(substr);
	replacement_len = strlen(replacement);

	if (substr == NULL || replacement == NULL) {
		return newstr;
	}

	while ((tok = strstr(newstr, substr))) {
		oldstr = newstr;
		oldstr_len = strlen(oldstr);
		newstr = (char*)malloc(sizeof(char) * (oldstr_len - substr_len + replacement_len + 1));

		if (newstr == NULL) {
			free(oldstr);
			return NULL;
		}

		memcpy(newstr, oldstr, tok - oldstr);
		memcpy(newstr + (tok - oldstr), replacement, replacement_len);
		memcpy(newstr + (tok - oldstr) + replacement_len, tok + substr_len, oldstr_len - substr_len - (tok - oldstr));
		memset(newstr + oldstr_len - substr_len + replacement_len, 0, 1);

		free(oldstr);
	}
	return newstr;
}
void do_assign_expr(Value term1, Operator op, Value term2){
    debug("do_assign_expr.");
    int toint = 0;
    int tofloat = 0;
    Value result;    
    // if(result.type == INT_T){
    //     if(term2.type == FLOAT_T){
    //         toint = 1;
    //     }
    // }
    // else if(result.type == FLOAT_T){
    //     if(term2.type == INT_T){
    //         tofloat = 1;
    //     }
    // }
    // else {
    //     debug("term1 is string");
    // }
    switch (op){
        case ASGN_OP:
            find_assign_type(term1,term2); //Lval must be a variable
            break;
        case ADDASGN_OP:
            term2 = do_addition_expr(term1,ADD_OP,term2);
            find_assign_type(term1,term2);  
            break;
        case SUBASGN_OP:
            term2 = do_addition_expr(term1,SUB_OP,term2);
            find_assign_type(term1,term2);
            break;
        case MULASGN_OP:
            term2 = do_multiplication_expr(term1,MUL_OP,term2);
            find_assign_type(term1,term2);
            break;
        case DIVASGN_OP:
            term2 = do_multiplication_expr(term1,DIV_OP,term2);
            find_assign_type(term1,term2);
            break;
        case MODASGN_OP:
            term2 = do_multiplication_expr(term1,MOD_OP,term2);
            find_assign_type(term1,term2);
            break;
        default:
            break;
    }
    int R_int;
    float R_float;
    int cast = 0;
    if(term2.type == ID_T){
        term2 = find_original_type(term2, cast);
    }
    if(term1.type == INT_T){
        if(term2.type == INT_T)
            R_int = term2.i_val;
        else{
            R_int = (int)term2.f_val;
        }
    }
    else if(term1.type == FLOAT_T){
        if(term2.type == INT_T)
            R_float = (float)term2.i_val;
        else{
            R_float = term2.f_val;
        }
    }
    switch(op){
        case ASGN_OP:
            if(term1.type == INT_T){
                term1.i_val = R_int;
            }
            else {
                term1.f_val = R_float;
            }
            break;
        case ADDASGN_OP:
            if(term1.type == INT_T){
                term1.i_val += R_int;
            }
            else {
                term1.f_val += R_float;
            }
            break;
        case SUBASGN_OP:
            if(term1.type == INT_T){
                term1.i_val -= R_int;
            }
            else {
                term1.f_val -= R_float;
            }
            break;
        case MULASGN_OP:
            if(term1.type == INT_T){
                term1.i_val *= R_int;
            }
            else {
                term1.f_val *= R_float;
            }
            break;
        case DIVASGN_OP:
            if(term1.type == INT_T){
                term1.i_val /= R_int;
            }
            else {
                term1.f_val /= R_float;
            }
            break;
        case MODASGN_OP:
            if(term1.type == INT_T){
                term1.i_val %= R_int;
            }
            else {
                debug("cannot MODASGN float type");
            }
            break;
        default:
            debug("NOT ASSIGN OP!!!");
            break;
    }
}
void do_return_stat(Value term1){
    printf("return type %d.\n",term1.type);

    if(term1.type == VOID_T || term1.type == NAT){
        sprintf(code_buf,"\treturn\n.end method\n");
        gencode(code_buf);
    }
    else{
        switch(term1.type){
            case ID_T:
                find_return_type(term1);                
                break;
            case INT_T:
                sprintf(code_buf,"\tldc %d\n",term1.i_val);
                gencode(code_buf);
                sprintf(code_buf,"\tireturn\n");
                gencode(code_buf);
                break;
            case FLOAT_T:
                sprintf(code_buf,"\tldc %f\n",term1.f_val);
                gencode(code_buf);
                sprintf(code_buf,"\tfreturn\n");
                gencode(code_buf);
                break;
            case STRING_T:
                sprintf(code_buf,"\tldc \"%s\"\n",term1.string);
                gencode(code_buf);
                sprintf(code_buf,"\tareturn\n");
                gencode(code_buf);
                break;
            case BOOL_T:
                sprintf(code_buf,"\tldc %d\n",term1.i_val);
                gencode(code_buf);
                sprintf(code_buf,"\tireturn\n");
                gencode(code_buf);
                break;
        }
        sprintf(code_buf,".end method\n");
        gencode(code_buf);
    }
}
void do_print(Value term1){
    debug("do_print");
    switch(term1.type){
        case ID_T:
            term1 = find_original_type(term1,0);
            break;
        case INT_T:
            sprintf(code_buf,"\tldc %d\n",term1.i_val);
            gencode(code_buf);
            break;
        case FLOAT_T:
            sprintf(code_buf,"\tldc %f\n",term1.f_val);
            gencode(code_buf);
            break;
        case STRING_T:
            sprintf(code_buf,"\tldc %s\n",term1.string);
            gencode(code_buf);
            break;
    }
    sprintf(code_buf,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
    gencode(code_buf);
    sprintf(code_buf,"\tswap\n\tinvokevirtual java/io/PrintStream/println(%s)V\n", convert_type(term1.type));
    gencode(code_buf);
}
Value do_postfix_expr(Value term1, Operator op){
    Value result;
    if(!strcmp(term1.string,"calculated")){

    }
    else{
        switch (term1.type){
            case ID_T:
                term1 = find_original_type(term1,0);
                break;
            case INT_T:
                sprintf(code_buf,"\tldc %d\n",term1.i_val);
                gencode(code_buf);
                break;
            default:
                debug("error type in postfix expr.");
                break;
        }
    }
    switch(op){
        case INC_OP:
            gencode("\tiinc\n");
            break;
        case DEC_OP:
            gencode("\tldc -1\n");
            gencode("\tiadd\n");
            break;
        default:
            debug("NOT INC , DEC OP!!!");
            break;
    }
    result.string = "calculated";
    return term1;
}
Value do_multiplication_expr(Value term1, Operator op, Value term2){
    debug("do_multiplication");
    Value result;
    int cast = 0;
    if(!strcmp(term1.string,"calculated")){
        debug("calculated, don't need to load Lvalue.");
        if(term1.type == FLOAT_T){
            cast = 1;
        }
    }
    else{
        switch (term1.type){
            case ID_T:
                term1 = find_original_type(term1,0);
                break;
            case INT_T:
                sprintf(code_buf,"\tldc %d\n",term1.i_val);
                gencode(code_buf);
                break;
            case FLOAT_T:
                sprintf(code_buf,"\tldc %f\n",term1.f_val);
                gencode(code_buf);
                cast = 1;
                break;
            default:
                debug("error type of addition");
                break;
        }
    }
    switch (term2.type){
        case ID_T:
            term2 = find_original_type(term2, cast);
            break;
        case INT_T:
            if(!strcmp(term2.string,"calculated")){
                debug("calculated, don't need to reload Rvalue.");
                if(!strcmp(term1.string,"calculated")){
                    if(term1.type == FLOAT_T){
                        gencode("\ti2f\n");
                    }   
                    else{
                        debug("both are calculated.");
                    }  
                }
                else{
                    if(term1.type == FLOAT_T){
                        gencode("\tswap\n");
                        gencode("\ti2f\n");
                    }
                }              
            }
            else{
                sprintf(code_buf,"\tldc %d\n",term2.i_val);
                gencode(code_buf);
                if(term1.type == FLOAT_T){
                    sprintf(code_buf,"\ti2f\n");
                    gencode(code_buf);
                }
            }
            break;
        case FLOAT_T:
            if(!strcmp(term2.string,"calculated")){
                if(!strcmp(term1.string,"calculated")){
                    if(term1.type == INT_T){
                        gencode("\tswap\n");
                        gencode("\ti2f\n");
                    }
                }
            }
            else{
                if(term1.type == INT_T){
                    gencode("\ti2f\n");
                }
                sprintf(code_buf,"\tldc %f\n",term2.f_val);
                gencode(code_buf);
            }
            break;
        default:
            debug("error type of addition");
            break;
    }
    printf("term1:%d term2:%d \n",term1.type,term2.type);
    if(term1.type == FLOAT_T || term2.type == FLOAT_T){
        result.type = FLOAT_T;
    }
    else {
        result.type = INT_T;
    }
    printf("result type: %d\n",result.type);
    switch (op){
        case MUL_OP:
            if(result.type == INT_T){
                sprintf(code_buf,"\timul\n");
                gencode(code_buf);
                // result.i_val = L_int + R_int;
            }
            else {
                sprintf(code_buf,"\tfmul\n");
                gencode(code_buf);
                // result.f_val = L_float + R_float;
            }
            break;
        case DIV_OP:
            if(result.type == INT_T){
                sprintf(code_buf,"\tidiv\n");
                gencode(code_buf);
                // result.i_val = L_int - R_int;
            }
            else {
                sprintf(code_buf,"\tfdiv\n");
                gencode(code_buf);
                // result.f_val = L_float - R_float;
            }
            break;
        case MOD_OP:
            if(result.type == INT_T){
                sprintf(code_buf,"\tirem\n");
                gencode(code_buf);
                // result.i_val = L_int - R_int;
            }
            else {
                debug("float cannot be modulized!!");
                // result.f_val = L_float - R_float;
            }
            break;
        default:
            debug("NOT * / % OP!!!");
            break;
    }
    result.string = "calculated";
    return result;
}
Value do_addition_expr(Value term1, Operator op, Value term2){
    debug("do_addition");
    Value result;
    int cast = 0;
    if(!strcmp(term1.string,"calculated")){
        debug("calculated, don't need to load Lvalue.");
        if(term1.type == FLOAT_T){
            cast = 1;
        }
    }
    else{
        switch (term1.type){
            case ID_T:
                term1 = find_original_type(term1,0);
                break;
            case INT_T:
                sprintf(code_buf,"\tldc %d\n",term1.i_val);
                gencode(code_buf);
                break;
            case FLOAT_T:
                sprintf(code_buf,"\tldc %f\n",term1.f_val);
                gencode(code_buf);
                cast = 1;
                break;
            default:
                debug("error type of addition");
                break;
        }
    }
    switch (term2.type){
        case ID_T:
            term2 = find_original_type(term2, cast);
            break;
        case INT_T:
            if(!strcmp(term2.string,"calculated")){
                debug("calculated, don't need to reload Rvalue.");
                if(!strcmp(term1.string,"calculated")){
                    if(term1.type == FLOAT_T){
                        gencode("\ti2f\n");
                    }   
                    else{
                        debug("both are calculated.");
                    }  
                }
                else{
                    if(term1.type == FLOAT_T){
                        gencode("\tswap\n");
                        gencode("\ti2f\n");
                    }
                }              
            }
            else{
                sprintf(code_buf,"\tldc %d\n",term2.i_val);
                gencode(code_buf);
                if(term1.type == FLOAT_T){
                    sprintf(code_buf,"\ti2f\n");
                    gencode(code_buf);
                }
            }
            break;
        case FLOAT_T:
            if(!strcmp(term2.string,"calculated")){
                if(!strcmp(term1.string,"calculated")){
                    if(term1.type == INT_T){
                        gencode("\tswap\n");
                        gencode("\ti2f\n");
                    }
                }
            }
            else{
                if(term1.type == INT_T){
                    gencode("\ti2f\n");
                }
                sprintf(code_buf,"\tldc %f\n",term2.f_val);
                gencode(code_buf);
            }
            break;
        default:
            debug("error type of addition");
            break;
    }
    printf("term1:%d term2:%d \n",term1.type,term2.type);
    if(term1.type == FLOAT_T || term2.type == FLOAT_T){
        result.type = FLOAT_T;
    }
    else {
        result.type = INT_T;
    }
    printf("result type: %d\n",result.type);
    switch (op){
        case ADD_OP:
            if(result.type == INT_T){
                gencode("\tiadd\n");
            }
            else if(result.type == FLOAT_T){
                gencode("\tfadd\n");
            }
            else{
                debug("result type is not int or float\n");
            }
            break;
        case SUB_OP:
            if(result.type == INT_T){
                gencode("\tisub\n");
            }
            else {
                gencode("\tfsub\n");
            }
            break;
        default:
            debug("NOT + - OP!!!");
            break;
    }
    result.string = "calculated";
    return result;
}

Value do_comparison_expr(Value term1, Operator op, Value term2){
//     debug("do compare");
//     Value result;
//     result.type = BOOL_T;
//     Type t;
//     int L_int;
//     float L_float;
//     int R_int;
//     float R_float;

//     if(term1.type == ID_T){
//         term1 = find_original_type(term1);
//     }
//     if(term2.type == ID_T){
//         term2 = find_original_type(term2);
//     }

//     if(term1.type == INT_T){
//         if(term2.type == INT_T){
//             L_int = term1.i_val;
//             R_int = term2.i_val;
//             t = INT_T;
//         }
//         else{
//             L_float = (float)term2.i_val;
//             R_float = term2.f_val;
//             t = FLOAT_T;
//         }
//     }
//     else if(term1.type == FLOAT_T){
//         if(term2.type == INT_T){
//             L_float = term1.f_val;
//             R_float = (float)term2.i_val;
//             t = FLOAT_T;
//         }
//         else{
//             L_float = term1.f_val;
//             R_float = term2.f_val;
//             t = FLOAT_T;
//         }
//     }
//     switch (op){
//         case EQ_OP:
//             if(t == INT_T){
//                 result.i_val = (int)(L_int == R_int);
//             }
//             else {
//                 result.i_val = (int)(L_float == R_float);
//             }
//             break;
//         case NE_OP:
//             if(t == INT_T){
//                 result.i_val = (int)(L_int != R_int);
//             }
//             else {
//                 result.i_val = (int)(L_float != R_float);
//             }
//             break;
//         case LT_OP:
//             if(t == INT_T){
//                 result.i_val = (int)(L_int < R_int);
//             }
//             else {
//                 result.i_val = (int)(L_float < R_float);
//             }
//             break;
//         case LTE_OP:
//             if(t == INT_T){
//                 result.i_val = (int)(L_int <= R_int);
//             }
//             else {
//                 result.i_val = (int)(L_float <= R_float);
//             }
//             break;
//         case MT_OP:
//             if(t == INT_T){
//                 result.i_val = (int)(L_int > R_int);
//             }
//             else {
//                 result.i_val = (int)(L_float > R_float);
//             }
//             break;
//         case MTE_OP:
//             if(t == INT_T){
//                 result.i_val = (int)(L_int >= R_int);
//             }
//             else {
//                 result.i_val = (int)(L_float >= R_float);
//             }
//             break;
//         default:
//             debug("NOT A CMP_OP!!!");
//             break;
//     }

//     return result;
}

Value find_original_type(Value term, int cast){
    debug("find_original_type");
    Header *ptr = cur_header;
        while(ptr != NULL){
            Entry* cur_entry = ptr->table_root->next;
            while(cur_entry != NULL){
                if(!strcmp(cur_entry->name,term.string))
                {
                    if(!strcmp(cur_entry->type,"int")){
                        term.type = INT_T;
                        if(ptr->depth == 0){
                            sprintf(code_buf,"\tgetstatic compiler_hw3/%s %s\n",term.string,convert_type(INT_T));
                            gencode(code_buf);
                            if(cast){
                                sprintf(code_buf,"\ti2f\n");
                                gencode(code_buf);
                            }
                        }
                        else{
                            sprintf(code_buf,"\tiload %d\n",cur_entry->index);
                            gencode(code_buf);
                            if(cast){
                                sprintf(code_buf,"\ti2f\n");
                                gencode(code_buf);
                            }
                        }
                    }
                    else if(!strcmp(cur_entry->type,"float")){
                        term.type = FLOAT_T;
                        if(ptr->depth == 0){
                            sprintf(code_buf,"\tgetstatic compiler_hw3/%s %s\n",term.string,convert_type(FLOAT_T));
                            gencode(code_buf);
                        }
                        else{
                            sprintf(code_buf,"\tfload %d\n",cur_entry->index);
                            gencode(code_buf);
                        }
                    }
                    else{
                        debug("original type is not int or float.");
                    }
                    //printf("ID_T original type is:%d\n",term1.type);
                    return term;
                }
                else{
                    cur_entry = cur_entry->next;
                }
            }
            ptr = ptr->pre;
        }
        debug("not found ID_T original type");
}
Value find_assign_type(Value term, Value term2){
    debug("find_assign_type");
    printf("term1: %d term2: %d\n",term.type,term2.type);
    Header *ptr = cur_header;
        while(ptr != NULL){
            Entry* cur_entry = ptr->table_root->next;
            while(cur_entry != NULL){
                if(!strcmp(cur_entry->name,term.string)){
                    if(!strcmp(cur_entry->type,"int")){
                        term.type = INT_T;
                        if(ptr->depth == 0){
                            if(term2.type == FLOAT_T){
                                sprintf(code_buf,"\tf2i\n");
                                gencode(code_buf);
                            }
                            sprintf(code_buf,"\tputstatic compiler_hw3/%s %s\n",term.string,convert_type(INT_T));
                            gencode(code_buf);
                        }
                        else{
                            if(term2.type == FLOAT_T){
                                sprintf(code_buf,"\tf2i\n");
                                gencode(code_buf);
                            }
                            sprintf(code_buf,"\tistore %d\n",cur_entry->index);
                            gencode(code_buf);
                        }
                    }
                    else if(!strcmp(cur_entry->type,"float")){
                        term.type = FLOAT_T;
                        if(ptr->depth == 0){
                            if(term2.type == INT_T){
                                sprintf(code_buf,"\ti2f\n");
                                gencode(code_buf);
                            }
                            sprintf(code_buf,"\tputstatic compiler_hw3/%s %s\n",term.string,convert_type(FLOAT_T));
                            gencode(code_buf);
                        }
                        else{
                            if(term2.type == INT_T){
                                sprintf(code_buf,"\ti2f\n");
                                gencode(code_buf);
                            }
                            sprintf(code_buf,"\tfstore %d\n",cur_entry->index);
                            gencode(code_buf);
                        }
                    }
                    else{
                        debug("original type is not int or float.");
                    }
                    //printf("ID_T original type is:%d\n",term1.type);
                    return term;
                }
                else{
                    cur_entry = cur_entry->next;
                }
            }
        }
            ptr = ptr->pre;
        debug("not found ID_T original type");   
}

void find_return_type(Value term){
    debug("find_return_type");
    Header *ptr = cur_header;
        while(ptr != NULL){
            Entry* cur_entry = ptr->table_root->next;
            while(cur_entry != NULL){
                if(!strcmp(cur_entry->name,term.string)){
                    if(ptr->depth == 0){
                        if(!strcmp(cur_entry->type,"int")){
                            sprintf(code_buf,"\tgetstatic compiler_hw3/%s I\n",term.string);
                            gencode(code_buf);
                            sprintf(code_buf,"\tireturn\n");
                            gencode(code_buf);
                        }
                        else if(!strcmp(cur_entry->type,"float")){
                            sprintf(code_buf,"\tgetstatic compiler_hw3/%s F\n",term.string);
                            gencode(code_buf);
                            sprintf(code_buf,"\tfreturn\n");
                            gencode(code_buf);
                        }
                        else if(!strcmp(cur_entry->type,"string")){
                            sprintf(code_buf,"\tgetstatic compiler_hw3/%s Ljava/lang/String;\n",term.string);
                            gencode(code_buf);
                            sprintf(code_buf,"\tareturn\n");
                            gencode(code_buf);
                        }
                        else if(!strcmp(cur_entry->type,"bool")){
                            sprintf(code_buf,"\tgetstatic compiler_hw3/%s Z;\n",term.string);
                            gencode(code_buf);
                            sprintf(code_buf,"\tireturn\n");
                            gencode(code_buf);
                        }
                        else{
                            debug("original type is not int,float,string,bool.");
                        }
                    }
                    else{
                        if(!strcmp(cur_entry->type,"int")){
                            sprintf(code_buf,"\tiload %d\n",cur_entry->index);
                            gencode(code_buf);
                            sprintf(code_buf,"\tireturn\n");
                            gencode(code_buf);
                        }
                        else if(!strcmp(cur_entry->type,"float")){
                            sprintf(code_buf,"\tfload %d\n",cur_entry->index);
                            gencode(code_buf);
                            sprintf(code_buf,"\tfreturn\n");
                            gencode(code_buf);
                        }
                        else if(!strcmp(cur_entry->type,"string")){
                            sprintf(code_buf,"\taload %d\n",cur_entry->index);
                            gencode(code_buf);
                            sprintf(code_buf,"\tareturn\n");
                            gencode(code_buf);
                        }
                        else if(!strcmp(cur_entry->type,"bool")){
                            sprintf(code_buf,"\tiload %d\n",cur_entry->index);
                            gencode(code_buf);
                            sprintf(code_buf,"\tireturn\n");
                            gencode(code_buf);
                        }
                        else{
                            debug("original type is not int,float,string,bool.");
                        }
                    }
                    // sprintf(code_buf,".end method\n");
                    // gencode(code_buf);
                    break;
                    //printf("ID_T original type is:%d\n",term1.type);
                }
                else{
                    cur_entry = cur_entry->next;
                    }
                }
            ptr = ptr->pre;
        }
        debug("not found ID_T original type");
}
void do_function_call(Value id){
    Entry *cur = header_root->table_root->next;
    char* name = malloc(50);
    char* type = malloc(50);
    char* argument = malloc(50);
    while(cur != NULL){
        if(!strcmp(cur->kind,"function")){
            strcpy(name,cur->name);
            strcpy(type,cur->type);
            strcpy(argument,cur->attribute);
            break;
        }
        cur = cur->next;
    }
    argument = str_replace(argument,",","");
    argument = str_replace(argument,"int","I");
    argument = str_replace(argument,"float","F");
    argument = str_replace(argument,"bool", "Z");
    argument = str_replace(argument,"string","Ljava/lang/String;");
    type = str_replace(type,"int","I");
    type = str_replace(type,"float","F");
    type = str_replace(type,"bool", "Z");
    type = str_replace(type,"void", "V");
    type = str_replace(type,"string","Ljava/lang/String;");
    sprintf(code_buf,"invokestatic compiler_hw3/%s(%s)%s",name,argument,type);
    gencode(code_buf);

}
