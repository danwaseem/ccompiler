/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "icg.y"

	void yyerror(char* s);
	int yylex();
	#include "stdio.h"
	#include "stdlib.h"
	#include "ctype.h"
	#include "string.h"
	void insert();
	void insertvariable();
	int flag=0;

	extern char CID[20];
	extern char CTYPE[20];
	extern char CVAL[20];
	extern int currnest;
	void deletedata (int );
	int checkscope(char*);
	int check_id_is_func(char *);
	void insertST(char*, char*);
	void insertSTnest(char*, int);
	void insertSTparamscount(char*, int);
	int getSTparamscount(char*);
	int check_duplicate(char*);
	int check_declaration(char*, char *);
	int check_params(char*);
	int duplicate(char *s);
	int checkarray(char*);
	char currfunctype[100];
	char currfunc[100];
	char currfunccall[100];
	void insertSTF(char*);
	char gettype(char*,int);
	char getfirst(char*);
	void push(char *s);
	void codegen();
	void codeassign();
	char* itoa(int num, char* str, int base);
	void reverse(char str[], int length);
	void swap(char*,char*);
	void label1();
	void label2();
	void label3();
	void label4();
	void label5();
	void label6();
	void genunary();
	void codegencon();
	void funcgen();
	void funcgenend();
	void arggen();
	void callgen();
	int params_count=0;
	int call_params_count=0;

	int top = 0,count=0,ltop=0,lno=0;
	char temp[3] = "t";



#line 130 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    INT = 259,
    CHAR = 260,
    FLOAT = 261,
    DOUBLE = 262,
    LONG = 263,
    SHORT = 264,
    SIGNED = 265,
    UNSIGNED = 266,
    STRUCT = 267,
    UNION = 268,
    RETURN = 269,
    MAIN = 270,
    VOID = 271,
    WHILE = 272,
    FOR = 273,
    DO = 274,
    BREAK = 275,
    CONTINUE = 276,
    ENDIF = 277,
    IDEN = 278,
    ARRAYIDEN = 279,
    FUNCIDEN = 280,
    INTEGER = 281,
    STRING = 282,
    FLOATC = 283,
    CHARACTER = 284,
    SEMICOLON = 285,
    COMMA = 286,
    OP = 287,
    CP = 288,
    OB = 289,
    CB = 290,
    OSB = 291,
    CSB = 292,
    COLON = 293,
    FULLSTOP = 294,
    ELSE = 295,
    LSHIFT = 296,
    RSHIFT = 297,
    XORA = 298,
    ORA = 299,
    ANDA = 300,
    MODA = 301,
    MULA = 302,
    DIVA = 303,
    ADDA = 304,
    SUBA = 305,
    ASS = 306,
    OR = 307,
    AND = 308,
    PIPE = 309,
    UP = 310,
    SAND = 311,
    EQ = 312,
    NEQ = 313,
    LESSTHANA = 314,
    LESSTHAN = 315,
    GRETHANA = 316,
    GRETHAN = 317,
    LEFTSHIFT = 318,
    RIGHTSHIFT = 319,
    ADD = 320,
    SUB = 321,
    MUL = 322,
    DIV = 323,
    MOD = 324,
    SIZEOF = 325,
    QUO = 326,
    EXC = 327,
    INCRI = 328,
    DECRI = 329
  };
#endif
/* Tokens.  */
#define IF 258
#define INT 259
#define CHAR 260
#define FLOAT 261
#define DOUBLE 262
#define LONG 263
#define SHORT 264
#define SIGNED 265
#define UNSIGNED 266
#define STRUCT 267
#define UNION 268
#define RETURN 269
#define MAIN 270
#define VOID 271
#define WHILE 272
#define FOR 273
#define DO 274
#define BREAK 275
#define CONTINUE 276
#define ENDIF 277
#define IDEN 278
#define ARRAYIDEN 279
#define FUNCIDEN 280
#define INTEGER 281
#define STRING 282
#define FLOATC 283
#define CHARACTER 284
#define SEMICOLON 285
#define COMMA 286
#define OP 287
#define CP 288
#define OB 289
#define CB 290
#define OSB 291
#define CSB 292
#define COLON 293
#define FULLSTOP 294
#define ELSE 295
#define LSHIFT 296
#define RSHIFT 297
#define XORA 298
#define ORA 299
#define ANDA 300
#define MODA 301
#define MULA 302
#define DIVA 303
#define ADDA 304
#define SUBA 305
#define ASS 306
#define OR 307
#define AND 308
#define PIPE 309
#define UP 310
#define SAND 311
#define EQ 312
#define NEQ 313
#define LESSTHANA 314
#define LESSTHAN 315
#define GRETHANA 316
#define GRETHAN 317
#define LEFTSHIFT 318
#define RIGHTSHIFT 319
#define ADD 320
#define SUB 321
#define MUL 322
#define DIV 323
#define MOD 324
#define SIZEOF 325
#define QUO 326
#define EXC 327
#define INCRI 328
#define DECRI 329

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

#define YYUNDEFTOK  2
#define YYMAXUTOK   329


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   105,   107,   108,   110,   111,   113,   115,
     116,   121,   121,   122,   122,   125,   126,   128,   129,   131,
     132,   134,   135,   136,   139,   140,   141,   142,   144,   145,
     146,   147,   149,   150,   152,   153,   156,   158,   160,   160,
     160,   162,   163,   165,   165,   167,   169,   170,   172,   172,
     174,   175,   177,   177,   179,   180,   182,   183,   185,   185,
     185,   187,   188,   190,   190,   190,   191,   191,   191,   192,
     192,   192,   194,   195,   198,   200,   201,   203,   205,   207,
     209,   210,   212,   212,   213,   213,   214,   214,   215,   215,
     216,   216,   217,   217,   218,   219,   220,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   234,   234,   235,   238,
     238,   239,   242,   242,   243,   245,   246,   249,   250,   251,
     252,   253,   254,   256,   257,   259,   260,   262,   263,   265,
     266,   267,   269,   270,   272,   273,   273,   276,   277,   278,
     280,   280,   285,   286,   288,   289,   291,   291,   291,   291,
     291,   293,   294,   295,   296,   297,   298,   299,   302,   303,
     304,   305
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "INT", "CHAR", "FLOAT", "DOUBLE",
  "LONG", "SHORT", "SIGNED", "UNSIGNED", "STRUCT", "UNION", "RETURN",
  "MAIN", "VOID", "WHILE", "FOR", "DO", "BREAK", "CONTINUE", "ENDIF",
  "IDEN", "ARRAYIDEN", "FUNCIDEN", "INTEGER", "STRING", "FLOATC",
  "CHARACTER", "SEMICOLON", "COMMA", "OP", "CP", "OB", "CB", "OSB", "CSB",
  "COLON", "FULLSTOP", "ELSE", "LSHIFT", "RSHIFT", "XORA", "ORA", "ANDA",
  "MODA", "MULA", "DIVA", "ADDA", "SUBA", "ASS", "OR", "AND", "PIPE", "UP",
  "SAND", "EQ", "NEQ", "LESSTHANA", "LESSTHAN", "GRETHANA", "GRETHAN",
  "LEFTSHIFT", "RIGHTSHIFT", "ADD", "SUB", "MUL", "DIV", "MOD", "SIZEOF",
  "QUO", "EXC", "INCRI", "DECRI", "$accept", "START", "DECLAREL", "D",
  "DECLARE", "VDECLARE", "VDECLAREL", "VDECLAREI", "$@1", "$@2", "vdi",
  "IDENARRAY", "INITPARAM", "INIT", "UG", "SIGNG", "LG", "SG", "FDECLARE",
  "FDECLARETYPE", "FDECLAREPARAM", "$@3", "$@4", "PARAMS", "PARAMLIST",
  "$@5", "PARAMIDENL", "PARAMIDENLBR", "PARAMIDEN", "$@6", "PARAMIDENBR",
  "COMPST", "$@7", "STATEMENTLIST", "EXPRST", "CONDST", "$@8", "$@9",
  "CONDSTBR", "ITER", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "RETURNS", "BREAKS", "BREAKCON", "STRINIT", "ARRINIT", "ARRINTD",
  "ARRINTDB", "EXPR", "$@16", "$@17", "$@18", "$@19", "$@20", "@21",
  "TYPE", "SEXPR", "$@22", "ANDEXPR", "@23", "UNARY", "@24", "REXPR",
  "RELATIONAL", "SUMEXPR", "sum_operators", "TERM", "MULOP", "FACTOR",
  "MUTABLE", "$@25", "IMMUTABLE", "CALL", "@26", "ARGUMENTS", "ARGLIST",
  "EXP", "STATEMENT", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      88,  -135,  -135,  -135,  -135,    34,    50,   163,   170,  -135,
      75,  -135,    88,  -135,  -135,  -135,    49,  -135,  -135,  -135,
    -135,  -135,    34,    50,  -135,  -135,    34,    50,  -135,  -135,
    -135,  -135,  -135,    88,    45,  -135,   -22,  -135,  -135,  -135,
    -135,  -135,    55,  -135,  -135,  -135,    25,    25,  -135,   167,
    -135,    60,    14,    58,  -135,  -135,  -135,  -135,  -135,   117,
    -135,  -135,    82,    92,    81,  -135,   107,  -135,  -135,  -135,
    -135,  -135,    58,  -135,  -135,    90,    95,  -135,   126,   127,
      83,  -135,   108,  -135,  -135,  -135,   136,    -2,   141,   143,
    -135,  -135,  -135,  -135,  -135,   146,  -135,  -135,  -135,   175,
    -135,  -135,   165,   166,   167,  -135,   161,    88,  -135,   147,
     172,  -135,  -135,   164,   168,    58,    58,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,   137,  -135,  -135,   137,  -135,  -135,
    -135,   137,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
      58,  -135,   173,  -135,    58,    39,   117,  -135,  -135,   169,
    -135,  -135,   -17,  -135,  -135,  -135,  -135,    80,    58,  -135,
    -135,  -135,    95,    58,   127,    83,  -135,    58,    58,    58,
      58,    58,    58,   -21,  -135,    58,   174,   176,    39,   185,
    -135,   179,  -135,  -135,  -135,  -135,  -135,   177,   178,  -135,
     171,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
     -19,  -135,  -135,  -135,   180,   182,   181,  -135,    80,  -135,
     117,  -135,    58,    58,   179,  -135,  -135,  -135,  -135,   117,
     -29,   -15,  -135,   183,  -135,  -135,  -135,   117,  -135,    58,
     184,  -135,   186,  -135,   117,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    97,    98,    99,   100,    33,    35,    31,    27,   105,
       0,     2,     5,     6,     7,    38,     0,    32,   101,    34,
     102,    28,    33,    35,   104,    24,    33,    35,   103,     1,
       4,     3,    36,    42,    11,    13,     0,    10,    29,    30,
      25,    26,     0,    41,    43,    37,    18,    18,     8,     0,
      39,     0,     0,     0,    12,    15,    14,    11,     9,    52,
      48,    44,    47,     0,     0,    17,   134,   135,   158,   159,
     160,   161,     0,   112,    16,    96,   108,   111,   114,   116,
     124,   128,   133,   132,   138,   139,     0,     0,     0,     0,
      75,    76,    57,   157,   152,     0,   151,   153,   154,     0,
     155,   156,     0,     0,     0,    40,    51,     0,    45,    23,
       0,    20,   140,     0,     0,     0,     0,   109,   121,   122,
     118,   120,   117,   119,     0,   125,   126,     0,   129,   130,
     131,     0,    92,    88,    90,    84,    86,    82,    94,    95,
       0,    72,     0,    63,     0,    52,    52,    74,    56,     0,
      49,    46,     0,    19,    21,    22,    77,   143,     0,   137,
     113,   133,   106,     0,   115,   123,   127,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,     0,    52,     0,
      50,     0,   146,   147,   148,   149,   150,     0,   142,   145,
       0,   107,   110,    93,    89,    91,    85,    87,    83,    58,
       0,    66,    53,    54,     0,    81,     0,   141,     0,   136,
      52,    64,     0,     0,     0,    79,    78,   144,    59,    52,
       0,     0,    80,    62,    65,    67,    70,    52,    60,     0,
       0,    61,     0,    71,    52,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   195,  -135,  -135,   100,  -135,   187,  -135,  -135,
     188,  -135,  -135,  -135,  -135,  -135,    13,   -16,  -135,  -135,
    -135,  -135,  -135,  -135,   110,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,    37,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,   109,
    -135,     6,  -135,   -53,  -135,  -135,  -135,  -135,  -135,  -135,
       3,  -134,  -135,   105,  -135,   -83,  -135,  -135,  -135,    98,
    -135,    97,  -135,    94,  -111,  -135,  -135,  -135,  -135,  -135,
    -135,    18,   -57,  -135
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    31,    12,    93,    36,    37,    46,    47,
      54,    55,    65,   153,    28,    24,    18,    20,    14,    15,
      32,    33,    59,    42,    43,    51,    61,   108,    62,   106,
     150,    94,    95,   177,    96,    97,   210,   223,   228,    98,
     175,   219,   212,   229,    99,   230,   100,   101,   102,   111,
     155,   206,   215,   103,   172,   170,   171,   168,   169,   167,
     104,    75,   191,    76,   163,    77,   115,    78,   124,    79,
     127,    80,   131,    81,    82,   113,    83,    84,   157,   187,
     188,   189,   178,    85
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,   225,   105,    16,   161,   161,   173,    39,    48,    49,
     156,    41,   199,   161,   211,    16,   161,   181,   226,   114,
     161,    66,    67,   116,    68,    69,    70,    71,   141,   161,
      72,   116,   160,   116,   142,    38,    44,   116,    17,    40,
      63,   200,    86,     1,     2,     3,     4,     5,     6,     7,
       8,    64,   161,    87,    19,     9,    88,    89,   -69,    90,
      91,    52,    66,    67,   161,    68,    69,    70,    71,    92,
      73,    72,    34,    35,   -55,    29,    53,    45,   220,   221,
     192,    66,    67,    60,    68,    69,    70,    71,    50,   179,
      72,   176,     1,     2,     3,     4,     5,     6,     7,     8,
      13,   161,   161,   182,     9,   190,   183,   184,   185,   186,
      44,    73,    13,   107,   193,   194,   195,   196,   197,   198,
      86,     1,     2,     3,     4,     5,     6,     7,     8,   109,
      73,    87,   110,     9,    88,    89,   -69,    90,    91,   112,
      66,    67,   116,    68,    69,    70,    71,    92,   117,    72,
     128,   129,   130,   218,   132,   133,   134,   135,   136,   137,
      66,    67,   224,    68,    69,    70,    71,    21,   140,    72,
     231,    22,    23,   143,    25,   144,   232,   235,    26,    27,
     145,   138,   139,   118,   119,   120,   121,   122,   123,    73,
      57,    35,   125,   126,   146,   147,   148,   149,   152,   156,
     158,   159,   204,   174,   201,   205,   180,    30,   209,   208,
     207,   202,   213,   214,   233,   203,   216,   151,   154,   234,
     222,   162,   164,   227,   165,   166,   217,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    58
};

static const yytype_int16 yycheck[] =
{
      53,    30,    59,     0,   115,   116,   140,    23,    30,    31,
      27,    27,    33,   124,    33,    12,   127,    34,    33,    72,
     131,    23,    24,    52,    26,    27,    28,    29,    30,   140,
      32,    52,   115,    52,    87,    22,    33,    52,     4,    26,
      26,   175,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    37,   163,    14,     4,    16,    17,    18,    19,    20,
      21,    36,    23,    24,   175,    26,    27,    28,    29,    30,
      72,    32,    23,    24,    35,     0,    51,    32,   212,   213,
     163,    23,    24,    23,    26,    27,    28,    29,    33,   146,
      32,   144,     4,     5,     6,     7,     8,     9,    10,    11,
       0,   212,   213,    23,    16,   158,    26,    27,    28,    29,
     107,    72,    12,    31,   167,   168,   169,   170,   171,   172,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    37,
      72,    14,    51,    16,    17,    18,    19,    20,    21,    32,
      23,    24,    52,    26,    27,    28,    29,    30,    53,    32,
      67,    68,    69,   210,    46,    47,    48,    49,    50,    51,
      23,    24,   219,    26,    27,    28,    29,     4,    32,    32,
     227,     8,     9,    32,     4,    32,   229,   234,     8,     9,
      34,    73,    74,    57,    58,    59,    60,    61,    62,    72,
      23,    24,    65,    66,    19,    30,    30,    36,    51,    27,
      36,    33,    17,    30,    30,    26,    37,    12,    37,    31,
      33,    35,    32,    31,    30,   178,    35,   107,   109,    33,
     214,   116,   124,    40,   127,   131,   208,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    16,
      76,    77,    79,    80,    93,    94,   135,     4,    91,     4,
      92,     4,     8,     9,    90,     4,     8,     9,    89,     0,
      77,    78,    95,    96,    23,    24,    81,    82,    91,    92,
      91,    92,    98,    99,   135,    32,    83,    84,    30,    31,
      33,   100,    36,    51,    85,    86,    85,    23,    82,    97,
      23,   101,   103,    26,    37,    87,    23,    24,    26,    27,
      28,    29,    32,    72,   128,   136,   138,   140,   142,   144,
     146,   148,   149,   151,   152,   158,     3,    14,    17,    18,
      20,    21,    30,    80,   106,   107,   109,   110,   114,   119,
     121,   122,   123,   128,   135,   157,   104,    31,   102,    37,
      51,   124,    32,   150,   128,   141,    52,    53,    57,    58,
      59,    60,    61,    62,   143,    65,    66,   145,    67,    68,
      69,   147,    46,    47,    48,    49,    50,    51,    73,    74,
      32,    30,   128,    32,    32,    34,    19,    30,    30,    36,
     105,    99,    51,    88,   124,   125,    27,   153,    36,    33,
     140,   149,   138,   139,   144,   146,   148,   134,   132,   133,
     130,   131,   129,   136,    30,   115,   128,   108,   157,   157,
      37,    34,    23,    26,    27,    28,    29,   154,   155,   156,
     128,   137,   140,   128,   128,   128,   128,   128,   128,    33,
     136,    30,    35,   108,    17,    26,   126,    33,    31,    37,
     111,    33,   117,    32,    31,   127,    35,   156,   157,   116,
     136,   136,   126,   112,   157,    30,    33,    40,   113,   118,
     120,   157,   128,    30,    33,   157
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    78,    78,    79,    79,    80,    81,
      81,    83,    82,    84,    82,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    89,    89,    89,    89,    90,    90,
      90,    90,    91,    91,    92,    92,    93,    94,    96,    97,
      95,    98,    98,   100,    99,   101,   102,   102,   104,   103,
     105,   105,   107,   106,   108,   108,   109,   109,   111,   112,
     110,   113,   113,   115,   116,   114,   117,   118,   114,   119,
     120,   114,   121,   121,   122,   123,   123,   124,   125,   126,
     127,   127,   129,   128,   130,   128,   131,   128,   132,   128,
     133,   128,   134,   128,   128,   128,   128,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   137,   136,   136,   139,
     138,   138,   141,   140,   140,   142,   142,   143,   143,   143,
     143,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     147,   147,   148,   148,   149,   150,   149,   151,   151,   151,
     153,   152,   154,   154,   155,   155,   156,   156,   156,   156,
     156,   157,   157,   157,   157,   157,   157,   157,   158,   158,
     158,   158
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     1,     1,     3,     3,
       1,     0,     3,     0,     3,     1,     2,     2,     0,     3,
       2,     1,     1,     0,     1,     2,     2,     0,     1,     2,
       2,     0,     1,     0,     1,     0,     2,     3,     0,     0,
       5,     1,     0,     0,     3,     2,     2,     0,     0,     3,
       2,     0,     0,     4,     2,     0,     2,     1,     0,     0,
       8,     2,     0,     0,     0,     7,     0,     0,    11,     0,
       0,     9,     2,     3,     2,     1,     1,     2,     4,     2,
       2,     0,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     0,     4,     1,     0,
       4,     1,     0,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     3,     1,     1,
       0,     5,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 11:
#line 121 "icg.y"
                       { if(duplicate(CID)){printf("Duplicate\n");exit(0);}insertSTnest(CID,currnest); insert(); }
#line 1700 "y.tab.c"
    break;

  case 13:
#line 122 "icg.y"
                                                          {if(duplicate(CID)){printf("Duplicate\n");exit(0);}insertSTnest(CID,currnest); insert(); }
#line 1706 "y.tab.c"
    break;

  case 19:
#line 131 "icg.y"
                                   {if(yyval < 1) {printf("Wrong array size\n"); exit(0);} }
#line 1712 "y.tab.c"
    break;

  case 37:
#line 158 "icg.y"
                                { strcpy(currfunctype, CTYPE); strcpy(currfunc, CID); check_duplicate(CID); insertSTF(CID);  insert();}
#line 1718 "y.tab.c"
    break;

  case 38:
#line 160 "icg.y"
                          {params_count=0;}
#line 1724 "y.tab.c"
    break;

  case 39:
#line 160 "icg.y"
                                                      {funcgen();}
#line 1730 "y.tab.c"
    break;

  case 40:
#line 160 "icg.y"
                                                                             {funcgenend();}
#line 1736 "y.tab.c"
    break;

  case 41:
#line 162 "icg.y"
                    { insertSTparamscount(currfunc, params_count); }
#line 1742 "y.tab.c"
    break;

  case 42:
#line 163 "icg.y"
                                  { insertSTparamscount(currfunc, params_count); }
#line 1748 "y.tab.c"
    break;

  case 43:
#line 165 "icg.y"
                       { check_params(CTYPE); }
#line 1754 "y.tab.c"
    break;

  case 48:
#line 172 "icg.y"
                       { insert(); insertSTnest(CID,1); params_count++; }
#line 1760 "y.tab.c"
    break;

  case 52:
#line 177 "icg.y"
          {currnest++;}
#line 1766 "y.tab.c"
    break;

  case 53:
#line 177 "icg.y"
                                             {deletedata(currnest);currnest--;}
#line 1772 "y.tab.c"
    break;

  case 58:
#line 185 "icg.y"
                         {label1(); if(yyvsp[-1]!=1){printf("Condition checking is not of type int\n");exit(0);}}
#line 1778 "y.tab.c"
    break;

  case 59:
#line 185 "icg.y"
                                                                                                                     {label2();}
#line 1784 "y.tab.c"
    break;

  case 61:
#line 187 "icg.y"
                                 {label3();}
#line 1790 "y.tab.c"
    break;

  case 62:
#line 188 "icg.y"
                                          {label3();}
#line 1796 "y.tab.c"
    break;

  case 63:
#line 190 "icg.y"
                    {label4();}
#line 1802 "y.tab.c"
    break;

  case 64:
#line 190 "icg.y"
                                         {label1(); if(yyvsp[-1]!=1){printf("Condition checking is not of type int\n");exit(0);}}
#line 1808 "y.tab.c"
    break;

  case 65:
#line 190 "icg.y"
                                                                                                                                     {label5();}
#line 1814 "y.tab.c"
    break;

  case 66:
#line 191 "icg.y"
                                                {label4();}
#line 1820 "y.tab.c"
    break;

  case 67:
#line 191 "icg.y"
                                                                            {label1(); if(yyvsp[-1]!=1){printf("Condition checking is not of type int\n");exit(0);}}
#line 1826 "y.tab.c"
    break;

  case 68:
#line 191 "icg.y"
                                                                                                                                                                                {label5();}
#line 1832 "y.tab.c"
    break;

  case 69:
#line 192 "icg.y"
                          {label4();}
#line 1838 "y.tab.c"
    break;

  case 70:
#line 192 "icg.y"
                                                                     {label1();label5(); if(yyvsp[-1]!=1){printf("Condition checking is not of type int\n");exit(0);}}
#line 1844 "y.tab.c"
    break;

  case 72:
#line 194 "icg.y"
                                 {if(strcmp(currfunctype,"void")) {printf("Returning void of a non-void function\n"); exit(0);}}
#line 1850 "y.tab.c"
    break;

  case 73:
#line 195 "icg.y"
                                                        {if(!strcmp(currfunctype, "void")){yyerror("Function is void\n");} if((currfunctype[0]=='i' || currfunctype[0]=='c') && yyvsp[-1]!=1)	{	printf("Expression doesn't match return type of function\n"); exit(0); } }
#line 1856 "y.tab.c"
    break;

  case 77:
#line 203 "icg.y"
                     { insertvariable(); }
#line 1862 "y.tab.c"
    break;

  case 82:
#line 212 "icg.y"
                      {push("=");}
#line 1868 "y.tab.c"
    break;

  case 83:
#line 212 "icg.y"
                                        {if(yyvsp[-3]==1 && yyvsp[0]==1)  { yyval=1; } else  {yyval=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
#line 1874 "y.tab.c"
    break;

  case 84:
#line 213 "icg.y"
                                       {push("+=");}
#line 1880 "y.tab.c"
    break;

  case 85:
#line 213 "icg.y"
                                                          {if(yyvsp[-3]==1 && yyvsp[0]==1)  { yyval=1; } else  {yyval=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
#line 1886 "y.tab.c"
    break;

  case 86:
#line 214 "icg.y"
                                       {push("-=");}
#line 1892 "y.tab.c"
    break;

  case 87:
#line 214 "icg.y"
                                                          {if(yyvsp[-3]==1 && yyvsp[0]==1)   { yyval=1; } else  {yyval=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
#line 1898 "y.tab.c"
    break;

  case 88:
#line 215 "icg.y"
                                       {push("*=");}
#line 1904 "y.tab.c"
    break;

  case 89:
#line 215 "icg.y"
                                                          {if(yyvsp[-3]==1 && yyvsp[0]==1)  { yyval=1; } else  {yyval=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
#line 1910 "y.tab.c"
    break;

  case 90:
#line 216 "icg.y"
                                       {push("/=");}
#line 1916 "y.tab.c"
    break;

  case 91:
#line 216 "icg.y"
                                                          {if(yyvsp[-3]==1 && yyvsp[0]==1)  { yyval=1; } else  {yyval=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
#line 1922 "y.tab.c"
    break;

  case 92:
#line 217 "icg.y"
                                       {push("%=");}
#line 1928 "y.tab.c"
    break;

  case 93:
#line 217 "icg.y"
                                                          {if(yyvsp[-3]==1 && yyvsp[-1]==1)  { yyval=1; } else  {yyval=-1; printf("Type mismatch\n"); exit(0);} codeassign(); }
#line 1934 "y.tab.c"
    break;

  case 94:
#line 218 "icg.y"
                                              {push("++"); if(yyvsp[-1] == 1) yyval=1; else yyval=-1; genunary(); }
#line 1940 "y.tab.c"
    break;

  case 95:
#line 219 "icg.y"
                                        {push("--"); if(yyvsp[-1] == 1) yyval=1; else yyval=-1;}
#line 1946 "y.tab.c"
    break;

  case 96:
#line 220 "icg.y"
                                {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1952 "y.tab.c"
    break;

  case 106:
#line 234 "icg.y"
                           {push("||");}
#line 1958 "y.tab.c"
    break;

  case 107:
#line 234 "icg.y"
                                         {if(yyvsp[-3] == 1 && yyvsp[-1]==1) yyval=1; else yyval=-1; codegen(); }
#line 1964 "y.tab.c"
    break;

  case 108:
#line 235 "icg.y"
                                  {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1970 "y.tab.c"
    break;

  case 109:
#line 238 "icg.y"
                      {push("&&");}
#line 1976 "y.tab.c"
    break;

  case 110:
#line 238 "icg.y"
                                          {if(yyvsp[-3] == 1 && yyvsp[-1]==1) yyval=1; else yyval=-1;codegen(); }
#line 1982 "y.tab.c"
    break;

  case 111:
#line 239 "icg.y"
                                        {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1988 "y.tab.c"
    break;

  case 112:
#line 242 "icg.y"
              {push("!");}
#line 1994 "y.tab.c"
    break;

  case 113:
#line 242 "icg.y"
                                 {if(yyvsp[-1]==1) yyval=1; else yyval=-1; codegen(); }
#line 2000 "y.tab.c"
    break;

  case 114:
#line 243 "icg.y"
                                {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 2006 "y.tab.c"
    break;

  case 115:
#line 245 "icg.y"
                                   {if(yyvsp[-2] == 1 && yyvsp[0]==1) yyval=1; else yyval=-1; codegen(); }
#line 2012 "y.tab.c"
    break;

  case 116:
#line 246 "icg.y"
                                  {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 2018 "y.tab.c"
    break;

  case 117:
#line 249 "icg.y"
                           {push(">=");}
#line 2024 "y.tab.c"
    break;

  case 118:
#line 250 "icg.y"
                                                            {push("<=");}
#line 2030 "y.tab.c"
    break;

  case 119:
#line 251 "icg.y"
                                                          {push(">");}
#line 2036 "y.tab.c"
    break;

  case 120:
#line 252 "icg.y"
                                                           {push("<");}
#line 2042 "y.tab.c"
    break;

  case 121:
#line 253 "icg.y"
                                                     {push("==");}
#line 2048 "y.tab.c"
    break;

  case 122:
#line 254 "icg.y"
                                                      {push("!=");}
#line 2054 "y.tab.c"
    break;

  case 123:
#line 256 "icg.y"
                                     {if(yyvsp[-2] == 1 && yyvsp[0]==1) yyval=1; else yyval=-1; codegen(); }
#line 2060 "y.tab.c"
    break;

  case 124:
#line 257 "icg.y"
                                        {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 2066 "y.tab.c"
    break;

  case 125:
#line 259 "icg.y"
                      {push("+");}
#line 2072 "y.tab.c"
    break;

  case 126:
#line 260 "icg.y"
                                                              {push("-");}
#line 2078 "y.tab.c"
    break;

  case 127:
#line 262 "icg.y"
                            {if(yyvsp[-2] == 1 && yyvsp[0]==1) yyval=1; else yyval=-1;}
#line 2084 "y.tab.c"
    break;

  case 128:
#line 263 "icg.y"
                                 {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 2090 "y.tab.c"
    break;

  case 129:
#line 265 "icg.y"
              {push("*");}
#line 2096 "y.tab.c"
    break;

  case 130:
#line 266 "icg.y"
                              {push("/");}
#line 2102 "y.tab.c"
    break;

  case 131:
#line 267 "icg.y"
                              {push("%");}
#line 2108 "y.tab.c"
    break;

  case 132:
#line 269 "icg.y"
                    {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 2114 "y.tab.c"
    break;

  case 133:
#line 270 "icg.y"
                                          {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 2120 "y.tab.c"
    break;

  case 134:
#line 272 "icg.y"
               { push(CID); if(check_id_is_func(CID))  {printf("Function name used as Identifier\n"); exit(8);} if(!checkscope(CID))  {printf("%s\n",CID);printf("Undeclared\n");exit(0);} if(!checkarray(CID)) {printf("%s\n",CID );printf("Array ID has no subscript\n");exit(0);} if(gettype(CID,0)=='i' || gettype(CID,1)== 'c') yyval = 1; else yyval = -1;}
#line 2126 "y.tab.c"
    break;

  case 135:
#line 273 "icg.y"
                                            {if(!checkscope(CID)){printf("%s\n",CID);printf("Undeclared\n");exit(0);}}
#line 2132 "y.tab.c"
    break;

  case 136:
#line 273 "icg.y"
                                                                                                                                     {if(gettype(CID,0)=='i' || gettype(CID,1)== 'c')	yyval = 1;	else	yyval = -1;	}
#line 2138 "y.tab.c"
    break;

  case 137:
#line 276 "icg.y"
                             {if(yyvsp[-1]==1) yyval=1; else yyval=-1;}
#line 2144 "y.tab.c"
    break;

  case 138:
#line 277 "icg.y"
                                               {if(yyvsp[0]==-1) yyval=-1; else yyval=1;}
#line 2150 "y.tab.c"
    break;

  case 139:
#line 278 "icg.y"
                                                   {if(yyvsp[0]==1) yyval=1; else yyval=-1;}
#line 2156 "y.tab.c"
    break;

  case 140:
#line 280 "icg.y"
                  {if(!check_declaration(CID, "Function")) { printf("Function not declared\n"); exit(0);} insertSTF(CID); strcpy(currfunccall,CID);  if(gettype(CID,0)=='i' || gettype(CID,1)== 'c') { yyval = 1; } else yyval = -1; call_params_count=0;}
#line 2162 "y.tab.c"
    break;

  case 141:
#line 281 "icg.y"
                                             { if(strcmp(currfunccall,"printf")){if(getSTparamscount(currfunccall)!=call_params_count){yyerror("Number of arguments in function call doesn't match number of parameters\n");
							exit(8);}	} callgen(); }
#line 2169 "y.tab.c"
    break;

  case 144:
#line 288 "icg.y"
                            { call_params_count++; }
#line 2175 "y.tab.c"
    break;

  case 145:
#line 289 "icg.y"
                                      { call_params_count++; }
#line 2181 "y.tab.c"
    break;

  case 146:
#line 291 "icg.y"
           {arggen(1);}
#line 2187 "y.tab.c"
    break;

  case 147:
#line 291 "icg.y"
                                  {arggen(2);}
#line 2193 "y.tab.c"
    break;

  case 148:
#line 291 "icg.y"
                                                        {arggen(3);}
#line 2199 "y.tab.c"
    break;

  case 149:
#line 291 "icg.y"
                                                                              {arggen(4);}
#line 2205 "y.tab.c"
    break;

  case 150:
#line 291 "icg.y"
                                                                                                       {arggen(5);}
#line 2211 "y.tab.c"
    break;

  case 158:
#line 302 "icg.y"
                                { insertvariable(); codegencon(); yyval=1; }
#line 2217 "y.tab.c"
    break;

  case 159:
#line 303 "icg.y"
                                                        { insertvariable(); codegencon(); yyval=-1; }
#line 2223 "y.tab.c"
    break;

  case 160:
#line 304 "icg.y"
                                                        { insertvariable(); codegencon(); }
#line 2229 "y.tab.c"
    break;

  case 161:
#line 305 "icg.y"
                                                    { insertvariable(); codegencon(); yyval=1;  }
#line 2235 "y.tab.c"
    break;


#line 2239 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 307 "icg.y"


extern FILE *yyin;
extern int yylineno;
extern char *yytext;
void insertSymboltype(char *,char *);
void insertSymbolvalue(char *, char *);
void incertconstant(char *, char *);
void printsymbol();
void printconstant();

struct stack
{
	char value[100];
	int labelvalue;
}s[100],label[100];


void push(char *x)
{
	strcpy(s[++top].value,x);
}

void swap(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap((str+start), (str+end));
        start++;
        end--;
    }
}

char* itoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative = 0;


    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }


    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';


    reverse(str, i);

    return str;
}

void codegen()
{
	strcpy(temp,"t");
	char buffer[100];
	itoa(count,buffer,10);
	strcat(temp,buffer);
	printf("%s = %s %s %s\n",temp,s[top-2].value,s[top-1].value,s[top].value);
	top = top - 2;
	strcpy(s[top].value,temp);
	count++;
}

void codegencon()
{
	strcpy(temp,"t");
	char buffer[100];
	itoa(count,buffer,10);
	strcat(temp,buffer);
	printf("%s = %s\n",temp,CVAL);
	push(temp);
	count++;

}

int isunary(char *s)
{
	if(strcmp(s, "--")==0 || strcmp(s, "++")==0)
	{
		return 1;
	}
	return 0;
}

void genunary()
{
	char temp1[100], temp2[100], temp3[100];
	strcpy(temp1, s[top].value);
	strcpy(temp2, s[top-1].value);

	if(isunary(temp1))
	{
		strcpy(temp3, temp1);
		strcpy(temp1, temp2);
		strcpy(temp2, temp3);
	}
	strcpy(temp, "t");
	char buffer[100];
	itoa(count, buffer, 10);
	strcat(temp, buffer);
	count++;

	if(strcmp(temp2,"--")==0)
	{
		printf("%s = %s - 1\n", temp, temp1);
		printf("%s = %s\n", temp1, temp);
	}

	if(strcmp(temp2,"++")==0)
	{
		printf("%s = %s + 1\n", temp, temp1);
		printf("%s = %s\n", temp1, temp);
	}

	top = top -2;
}

void codeassign()
{
	printf("%s = %s\n",s[top-2].value,s[top].value);
	top = top - 2;
}

void label1()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(lno,buffer,10);
	strcat(temp,buffer);
	printf("IF not %s GoTo %s\n",s[top].value,temp);
	label[++ltop].labelvalue = lno++;
}

void label2()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(lno,buffer,10);
	strcat(temp,buffer);
	printf("GoTo %s\n",temp);
	strcpy(temp,"L");
	itoa(label[ltop].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	ltop--;
	label[++ltop].labelvalue=lno++;
}

void label3()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(label[ltop].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	ltop--;

}

void label4()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(lno,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	label[++ltop].labelvalue = lno++;
}


void label5()
{
	strcpy(temp,"L");
	char buffer[100];
	itoa(label[ltop-1].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("GoTo %s:\n",temp);
	strcpy(temp,"L");
	itoa(label[ltop].labelvalue,buffer,10);
	strcat(temp,buffer);
	printf("%s:\n",temp);
	ltop = ltop - 2;


}

void funcgen()
{
	printf("func begin %s\n",currfunc);
}

void funcgenend()
{
	printf("func end\n\n");
}

void arggen(int i)
{
    if(i==1)
    {
	printf("refparam %s\n", CID);
	}
	else
	{
	printf("refparam %s\n", CVAL);
	}
}

void callgen()
{
	printf("refparam result\n");
	push("result");
	printf("call %s, %d\n",currfunccall,call_params_count);
}



int main()
{
	yyin = fopen("test10.c", "r");
	yyparse();

	if(flag == 0)
	{
		printsymbol();

		printconstant();
	}
}

void yyerror(char *s)
{
	printf("On Line Number %d %s %s\n", yylineno, s, yytext);
	flag=1;
	printf("Parsing Failed\n");
}

void insert()
{
	insertSymboltype(CID,CTYPE);
}

void insertvariable()
{
	insertSymbolvalue(CID,CVAL);
}

int yywrap()
{
	return 1;
}
