/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 6 "compilador.y" /* yacc.c:339  */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "compilador.h"
#include "tab_simbolos.h"
#include "pilha.h"

extern int yylex(void);
extern char *yytext;

TabSimb *tabela, TabSimbDin;
SimbTabela *simb, *simb_aux, *proc_atual, *func, *proc, *fun_aux;
PilhaTab pilha_simbolos, pilha_tipos, pilha_rotulos, pilha_aloc;
TipoTab tipo_aux, *tipo;
int num_vars, total_vars, nivel_lexico, deslocamento, cont_rotulos, temp_num, indice, num_param;
char *rotulo_mepa, *rotulo_aux, *rotulo_if, *rotulo_temp;
bool chamada_proc = false;
bool chamada_fun = false;
int vars[60000], cont, param[60000], cont2 = 0, cont_param = 0;

#define geraCodigoCarregaValor(simbolo) \
	if ( proc && (proc->lista_parametros[indice].passagem == p_referencia)){\
		if (simbolo->categoria == VS){\
			geraCodigoArgs (NULL, "CREN %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
		else if (simbolo->categoria == PF){\
			if(simbolo->passagem == p_valor){\
				geraCodigoArgs (NULL, "CREN %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
			else if (simbolo->passagem == p_referencia)\
				{geraCodigoArgs (NULL, "CRVL %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
			}\
	}\
	else if (func && (func->lista_parametros[indice].passagem == p_referencia)){\
		if (simbolo->categoria == VS){\
			geraCodigoArgs (NULL, "CREN %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
		else if (simbolo->categoria == PF){\
			if(simbolo->passagem == p_valor){\
				geraCodigoArgs (NULL, "CREN %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
			else if (simbolo->passagem == p_referencia)\
				{geraCodigoArgs (NULL, "CRVL %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
			}\
	}\
	else{\
		if (simbolo->categoria == VS)\
			{geraCodigoArgs (NULL, "CRVL %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
		else if (simbolo->categoria == PF){\
			if(simbolo->passagem == p_valor)\
				{geraCodigoArgs (NULL, "CRVL %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
			else if (simbolo->passagem == p_referencia)\
				{geraCodigoArgs (NULL, "CRVI %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
		}\
	}\

#define geraCodigoArmazenaValor(simbolo)\
	if (simbolo->categoria == PF && simbolo->passagem == p_referencia)\
	{\
		{geraCodigoArgs(NULL, "ARMI %d, %d", simbolo->nivel_lexico, simbolo->deslocamento); }\
	}\
	else\
	{\
		{geraCodigoArgs (NULL, "ARMZ %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
	}\

#line 132 "compilador.tab.c" /* yacc.c:339  */

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
   by #include "compilador.tab.h".  */
#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
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
    PROGRAM = 258,
    ABRE_PARENTESES = 259,
    FECHA_PARENTESES = 260,
    VIRGULA = 261,
    PONTO_E_VIRGULA = 262,
    DOIS_PONTOS = 263,
    PONTO = 264,
    T_BEGIN = 265,
    T_END = 266,
    VAR = 267,
    IDENT = 268,
    ATRIBUICAO = 269,
    LABEL = 270,
    TYPE = 271,
    ARRAY = 272,
    OF = 273,
    PROCEDURE = 274,
    FUNCTION = 275,
    GOTO = 276,
    IF = 277,
    THEN = 278,
    ELSE = 279,
    WHILE = 280,
    DO = 281,
    ABRE_CHAVES = 282,
    FECHA_CHAVES = 283,
    ABRE_COLCHETES = 284,
    FECHA_COLCHETES = 285,
    IGUAL = 286,
    DIFERENTE = 287,
    MAIOR = 288,
    MENOR = 289,
    MAIOR_IGUAL = 290,
    MENOR_IGUAL = 291,
    BAND = 292,
    BOR = 293,
    OTHER_BOR = 294,
    BNOT = 295,
    BLSO = 296,
    BRSO = 297,
    SOMA = 298,
    MENOS = 299,
    MULTI = 300,
    MOD = 301,
    DIV = 302,
    OR = 303,
    AND = 304,
    NOT = 305,
    XOR = 306,
    TRUE = 307,
    FALSE = 308,
    WRITE = 309,
    READ = 310,
    NUMERO = 311,
    INTEGER = 312,
    BOOLEAN = 313,
    LOWER_THAN_ELSE = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "compilador.tab.c" /* yacc.c:358  */

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
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    92,    88,   102,   113,   101,   127,   128,
     131,   138,   147,   147,   148,   151,   151,   152,   152,   155,
     155,   164,   169,   176,   177,   180,   181,   185,   196,   185,
     211,   223,   223,   211,   237,   240,   240,   249,   240,   259,
     258,   263,   267,   266,   269,   269,   270,   273,   283,   295,
     300,   308,   310,   312,   316,   319,   320,   323,   324,   327,
     327,   335,   336,   339,   340,   341,   342,   343,   344,   345,
     346,   349,   352,   358,   361,   365,   368,   374,   379,   379,
     386,   389,   389,   403,   406,   403,   421,   423,   423,   430,
     433,   430,   446,   446,   449,   449,   452,   452,   455,   455,
     458,   458,   461,   464,   464,   467,   467,   470,   470,   473,
     476,   476,   479,   479,   482,   482,   485,   488,   489,   493,
     497,   501,   505,   506,   512,   511,   529,   529,   533,   537,
     536,   539,   542
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA", "DOIS_PONTOS", "PONTO",
  "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO", "LABEL", "TYPE",
  "ARRAY", "OF", "PROCEDURE", "FUNCTION", "GOTO", "IF", "THEN", "ELSE",
  "WHILE", "DO", "ABRE_CHAVES", "FECHA_CHAVES", "ABRE_COLCHETES",
  "FECHA_COLCHETES", "IGUAL", "DIFERENTE", "MAIOR", "MENOR", "MAIOR_IGUAL",
  "MENOR_IGUAL", "BAND", "BOR", "OTHER_BOR", "BNOT", "BLSO", "BRSO",
  "SOMA", "MENOS", "MULTI", "MOD", "DIV", "OR", "AND", "NOT", "XOR",
  "TRUE", "FALSE", "WRITE", "READ", "NUMERO", "INTEGER", "BOOLEAN",
  "LOWER_THAN_ELSE", "$accept", "programa", "$@1", "$@2", "bloco", "$@3",
  "$@4", "rotulos", "num_list", "parte_declara_vars", "$@5",
  "declara_vars", "$@6", "$@7", "declara_var", "$@8", "lista_id_var",
  "lista_idents", "parte_declara_procedure_function", "procedure_function",
  "$@9", "$@10", "$@11", "$@12", "$@13", "bloco_PF", "$@14", "$@15",
  "$@16", "param_ProcedureFunction", "$@17", "lista_de_parametrosPF",
  "$@18", "$@19", "parametrosPF", "lista_parametrosPF", "tipo",
  "comando_composto", "comandos_todos", "comandos", "comando", "$@20",
  "com_sem_rotulo", "lista_leit", "lista_impr", "desvio", "atribui",
  "$@21", "atribui_var", "$@22", "repeticao", "$@23", "$@24",
  "condicional", "$@25", "if_cond", "$@26", "$@27", "expressao", "$@28",
  "$@29", "$@30", "$@31", "$@32", "expressao_simples", "$@33", "$@34",
  "$@35", "termo", "$@36", "$@37", "$@38", "fator", "chamada_funcao",
  "$@39", "lista_parametros", "$@40", "lista_expressao", "$@41",
  "identificador", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -164

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-164)))

#define YYTABLE_NINF -125

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -164,    19,    24,  -164,     9,  -164,    27,    26,  -164,    90,
      28,    41,    42,  -164,     8,    52,    57,  -164,   106,  -164,
    -164,  -164,    30,  -164,  -164,    96,  -164,    62,    65,    68,
      76,  -164,    96,    65,  -164,  -164,    22,  -164,  -164,    97,
    -164,  -164,    87,     5,   110,   110,     4,  -164,  -164,  -164,
    -164,  -164,  -164,    35,   122,   120,  -164,    77,  -164,  -164,
     127,   130,  -164,  -164,   124,   129,  -164,  -164,  -164,  -164,
    -164,  -164,   113,  -164,   131,   132,   105,  -164,     5,  -164,
       0,     0,    -7,   128,   134,  -164,    11,  -164,   126,  -164,
    -164,   138,   133,  -164,  -164,    84,  -164,    42,  -164,     0,
       0,  -164,  -164,  -164,    75,   -28,    25,  -164,  -164,   140,
      75,  -164,   117,  -164,   119,  -164,    66,  -164,    11,     0,
    -164,   141,   105,  -164,    95,   135,     5,   142,    57,   143,
      63,  -164,   136,   114,   116,   118,   125,   123,   112,   109,
     108,   115,   111,   137,   141,   144,  -164,    -1,  -164,   128,
    -164,  -164,  -164,    75,  -164,  -164,  -164,     5,  -164,  -164,
    -164,  -164,  -164,  -164,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -164,    11,  -164,  -164,
    -164,     0,  -164,    96,  -164,  -164,   -28,   -28,   -28,   -28,
     -28,    25,    25,    25,  -164,  -164,  -164,  -164,    75,   121,
    -164,   150,  -164,  -164,    97,  -164,     0,  -164,    75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     0,     0,    24,     0,
       0,     0,     9,    23,     0,     0,    14,    11,     0,     4,
      12,     5,     0,     8,    17,    26,    10,    13,     0,     0,
       0,     6,    26,     0,    22,    18,     0,    27,    30,     0,
      25,    16,     0,     0,    41,    41,    56,     7,    21,    53,
      51,    52,    19,    44,     0,     0,   132,     0,    89,    83,
       0,     0,    59,    61,     0,    55,    58,    62,    69,    64,
      65,    66,    86,    78,     0,    39,     0,    35,     0,    77,
       0,     0,     0,     0,     0,    54,    63,    87,    81,    20,
      42,     0,     0,    50,    45,     0,    28,     9,    31,     0,
       0,   119,   120,   118,    90,   102,   109,   116,   122,   121,
      84,    76,     0,    75,     0,    72,    63,    57,    63,     0,
      79,   128,     0,    40,     0,     0,     0,     0,    14,     0,
      92,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,    68,     0,    67,     0,
      70,    60,    88,    80,   126,    82,    43,     0,    49,    48,
      29,    36,    35,   117,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,    63,    74,    73,
      71,     0,    47,    34,    32,    91,    93,    95,    97,    99,
     101,   104,   106,   108,   111,   113,   115,    85,   131,     0,
      37,     0,   127,   129,     0,    33,     0,    38,   130
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,  -164,  -164,  -164,  -164,    67,  -164,    34,
    -164,  -164,  -164,  -164,   139,  -164,  -164,  -164,   145,   -20,
    -164,  -164,  -164,  -164,  -164,     6,  -164,  -164,  -164,   146,
    -164,  -164,  -164,  -164,    44,    79,   -75,   -39,  -164,  -164,
     -84,  -164,    51,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,   -76,  -164,
    -164,  -164,  -164,  -164,  -121,  -164,  -164,  -164,  -163,  -164,
    -164,  -164,   -90,  -164,  -164,    29,  -164,  -164,  -164,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,    15,    25,    39,    16,    18,    21,
      24,    27,    33,    28,    35,    74,    36,     9,    31,    32,
      44,   127,    45,   129,   201,    96,    97,   183,   204,    54,
      91,    75,   122,    76,    94,    95,    52,    63,    64,    65,
      66,    84,    67,   114,   112,    68,    69,    88,   120,   121,
      70,    81,   145,    71,   118,    72,    80,   132,   104,   133,
     134,   135,   136,   137,   105,   138,   139,   140,   106,   141,
     142,   143,   107,   108,   144,   155,   181,   199,   206,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    73,   117,    98,    99,   110,    56,   191,   192,   193,
     131,   -63,    56,    56,    46,  -103,  -105,    56,    49,     3,
    -107,    46,     5,   130,    56,    57,    58,     4,    42,    59,
      43,     7,    57,    58,   152,    12,    59,   113,   115,     8,
     -46,    73,   -46,   153,   186,   187,   188,   189,   190,   111,
     100,   159,   101,   102,    13,   178,   103,    14,    60,    61,
      62,    19,    50,    51,    17,    60,    61,    62,   163,    20,
    -110,    73,  -112,    73,  -114,   -15,    46,   150,    34,    56,
     185,    37,   182,   194,   195,   196,    26,    57,    58,    38,
     125,    59,   126,   197,  -100,    10,    11,   -96,   -94,   -98,
      48,   125,   179,   157,   180,   198,  -100,    46,   -92,   -96,
     -94,   -98,    22,    23,    53,    29,    30,    92,    93,    73,
      60,    61,   146,   147,   148,   149,   202,   203,    78,    77,
     208,    82,    73,    79,    83,    85,    86,    87,    89,    90,
     119,    56,   116,   123,  -124,   154,    93,   165,   158,   160,
     162,   166,   167,   171,   169,   170,   172,   205,   174,   164,
     173,   168,   161,   200,   128,   207,   156,   151,   184,     0,
     177,   124,    41,   176,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,    55
};

static const yytype_int16 yycheck[] =
{
      39,    46,    86,    78,     4,    81,    13,   170,   171,   172,
     100,     7,    13,    13,    10,    43,    44,    13,    13,     0,
      48,    10,    13,    99,    13,    21,    22,     3,     6,    25,
       8,     4,    21,    22,   118,     7,    25,    82,    83,    13,
       5,    86,     7,   119,   165,   166,   167,   168,   169,    56,
      50,   126,    52,    53,    13,    56,    56,    15,    54,    55,
      56,     9,    57,    58,    56,    54,    55,    56,     5,    12,
      45,   116,    47,   118,    49,    13,    10,   116,    13,    13,
     164,    13,   157,   173,   174,   175,    56,    21,    22,    13,
       6,    25,     8,   177,    31,     5,     6,    34,    35,    36,
      13,     6,   147,     8,   149,   181,    31,    10,    33,    34,
      35,    36,     6,     7,     4,    19,    20,    12,    13,   164,
      54,    55,     5,     6,     5,     6,     5,     6,     8,     7,
     206,     4,   177,    56,     4,    11,     7,    24,     7,     7,
      14,    13,     8,     5,     4,     4,    13,    33,    13,     7,
       7,    35,    34,    44,    31,    43,    48,     7,    47,    23,
      45,    36,   128,   183,    97,   204,   122,   116,   162,    -1,
      26,    92,    33,   144,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    62,     0,     3,    13,    63,     4,    13,    77,
       5,     6,     7,    13,    15,    64,    67,    56,    68,     9,
      12,    69,     6,     7,    70,    65,    56,    71,    73,    19,
      20,    78,    79,    72,    13,    74,    76,    13,    13,    66,
      78,    74,     6,     8,    80,    82,    10,    97,    13,    13,
      57,    58,    96,     4,    89,    89,    13,    21,    22,    25,
      54,    55,    56,    97,    98,    99,   100,   102,   105,   106,
     110,   113,   115,   139,    75,    91,    93,     7,     8,    56,
     116,   111,     4,     4,   101,    11,     7,    24,   107,     7,
       7,    90,    12,    13,    94,    95,    85,    86,    96,     4,
      50,    52,    53,    56,   118,   124,   128,   132,   133,   139,
     118,    56,   104,   139,   103,   139,     8,   100,   114,    14,
     108,   109,    92,     5,    95,     6,     8,    81,    67,    83,
     118,   132,   117,   119,   120,   121,   122,   123,   125,   126,
     127,   129,   130,   131,   134,   112,     5,     6,     5,     6,
      97,   102,   100,   118,     4,   135,    94,     8,    13,    96,
       7,    69,     7,     5,    23,    33,    35,    34,    36,    31,
      43,    44,    48,    45,    47,    49,   135,    26,    56,   139,
     139,   136,    96,    87,    85,   100,   124,   124,   124,   124,
     124,   128,   128,   128,   132,   132,   132,   100,   118,   137,
      79,    84,     5,     6,    88,     7,   138,    97,   118
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    62,    63,    61,    65,    66,    64,    67,    67,
      68,    68,    70,    69,    69,    72,    71,    73,    71,    75,
      74,    76,    76,    77,    77,    78,    78,    80,    81,    79,
      82,    83,    84,    79,    79,    86,    87,    88,    85,    90,
      89,    89,    92,    91,    93,    91,    91,    94,    94,    95,
      95,    96,    96,    96,    97,    98,    98,    99,    99,   101,
     100,   100,   100,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   104,   104,   104,   104,   105,   107,   106,
     108,   109,   108,   111,   112,   110,   113,   114,   113,   116,
     117,   115,   119,   118,   120,   118,   121,   118,   122,   118,
     123,   118,   118,   125,   124,   126,   124,   127,   124,   124,
     129,   128,   130,   128,   131,   128,   128,   132,   132,   132,
     132,   132,   132,   132,   134,   133,   136,   135,   135,   138,
     137,   137,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,    10,     0,     0,     6,     3,     0,
       3,     1,     0,     3,     0,     0,     3,     0,     2,     0,
       5,     3,     1,     3,     1,     2,     0,     0,     0,     8,
       0,     0,     0,    11,     0,     0,     0,     0,     7,     0,
       4,     0,     0,     4,     0,     2,     0,     4,     3,     3,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     0,
       4,     1,     1,     0,     1,     1,     1,     4,     4,     1,
       1,     3,     1,     3,     3,     1,     1,     2,     0,     3,
       2,     0,     2,     0,     0,     6,     1,     0,     4,     0,
       0,     6,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     1,     0,     4,     0,     4,     0,     4,     1,
       0,     4,     0,     4,     0,     4,     1,     3,     1,     1,
       1,     1,     1,     2,     0,     3,     0,     4,     0,     0,
       4,     1,     1
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
#line 88 "compilador.y" /* yacc.c:1646  */
    { 
		geraCodigo (NULL, "INPP"); 
		nivel_lexico = 0; 
		deslocamento = 0 ; }
#line 1495 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 92 "compilador.y" /* yacc.c:1646  */
    { 
		simb = InsereSimb(tabela, token, Prog, 0); 
		Empilha(&pilha_simbolos, simb); }
#line 1503 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 97 "compilador.y" /* yacc.c:1646  */
    { 
		geraCodigo (NULL, "PARA"); }
#line 1510 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "compilador.y" /* yacc.c:1646  */
    { 
		  Empilha (&pilha_aloc, &deslocamento);
		  GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos);
		  geraCodigoArgs (NULL, "DSVS %s", rotulo_mepa);
	  //    	 ImprimeTabela (tabela);
		  rotulo_temp = rotulo_mepa;
		  vars[0] = total_vars;
		  cont++;
		  vars[cont] = num_vars;
		 cont++;
		}
#line 1526 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 113 "compilador.y" /* yacc.c:1646  */
    {  
		  geraCodigo (rotulo_temp, "NADA");}
#line 1533 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "compilador.y" /* yacc.c:1646  */
    { 
		  cont--;
		  num_vars = vars[cont];
		  cont--;
		  total_vars = vars[0];
		if(total_vars){
			geraCodigoArgs (NULL, "DMEM %d", total_vars);
		}
		}
#line 1547 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 131 "compilador.y" /* yacc.c:1646  */
    {
		simb = InsereSimb(tabela, token, Label, nivel_lexico);
		GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos);
		simb->rotulo = rotulo_mepa;
                Empilha(&pilha_simbolos, simb);
		//ImprimeTabela (tabela);
		}
#line 1559 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 138 "compilador.y" /* yacc.c:1646  */
    {
		simb = InsereSimb(tabela, token, Label, nivel_lexico);
		GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos);
		simb->rotulo = rotulo_mepa;
                Empilha(&pilha_simbolos, simb);
	//	ImprimeTabela (tabela);
		}
#line 1571 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 147 "compilador.y" /* yacc.c:1646  */
    { deslocamento=0; num_vars=0;}
#line 1577 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 151 "compilador.y" /* yacc.c:1646  */
    { num_vars=0; }
#line 1583 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 152 "compilador.y" /* yacc.c:1646  */
    { num_vars=0; }
#line 1589 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 155 "compilador.y" /* yacc.c:1646  */
    { 
		  geraCodigoArgs (NULL, "AMEM %d", num_vars);
		  AtribuiTipoTab(tabela, tipo_aux);
		  simb->passagem = p_valor;   
		}
#line 1599 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 164 "compilador.y" /* yacc.c:1646  */
    { 
		num_vars++;
		total_vars++; 
		simb = InsereSimb(tabela, token, VS, nivel_lexico); 
		simb->deslocamento = deslocamento++; }
#line 1609 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 169 "compilador.y" /* yacc.c:1646  */
    { 
		num_vars++; 
		total_vars++;
		simb = InsereSimb(tabela, token, VS, nivel_lexico); 
		simb->deslocamento = deslocamento++; }
#line 1619 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 185 "compilador.y" /* yacc.c:1646  */
    {
  			GeradorRotulos(&pilha_rotulos,&rotulo_mepa, &cont_rotulos);
    			geraCodigoArgs (Desempilha(&pilha_rotulos), "ENPR %d", ++nivel_lexico);
      			simb = InsereSimb(tabela, token, Proc, nivel_lexico);
        		simb->rotulo = rotulo_mepa; 
          		Empilha(&pilha_simbolos, simb); 
			vars[cont] = num_vars;
			cont++;
            		simb->num_parametros=num_vars = 0;
		//	ImprimeTabela (tabela);
			}
#line 1635 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 196 "compilador.y" /* yacc.c:1646  */
    {
			cont--;
			num_vars = vars[cont];
		//	ImprimeTabela (tabela);
			num_param = simb->num_parametros;	
			simb = Desempilha(&pilha_simbolos);
			RemoveNSimb(tabela, simb);
			cont2--;
			simb->num_parametros = param[cont2];
			if(num_vars){
				geraCodigoArgs (NULL, "DMEM %d", num_vars);
			}
		//	ImprimeTabela (tabela);
			geraCodigoArgs (NULL, "RTPR %d, %d", nivel_lexico--, simb->num_parametros); 
			}
#line 1655 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 211 "compilador.y" /* yacc.c:1646  */
    {
  			GeradorRotulos(&pilha_rotulos,&rotulo_mepa, &cont_rotulos);
    			geraCodigoArgs (Desempilha(&pilha_rotulos), "ENPR %d", ++nivel_lexico);
      			simb = InsereSimb(tabela, token, Fun, nivel_lexico);
        		simb->rotulo = rotulo_mepa; 
         		Empilha(&pilha_simbolos, simb); 
			vars[cont] = num_vars;
	 		cont++;
			fun_aux = simb;
           		simb->num_parametros=num_vars = 0;
		//	ImprimeTabela (tabela);
			}
#line 1672 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 223 "compilador.y" /* yacc.c:1646  */
    {fun_aux->tipo = tipo_aux; }
#line 1678 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 223 "compilador.y" /* yacc.c:1646  */
    {
			cont--;
			num_vars = vars[cont];
			//ImprimeTabela (tabela);
			num_param = simb->num_parametros;	
			simb = Desempilha(&pilha_simbolos);
			RemoveNSimb(tabela, simb);
			cont2--;
			if(num_vars){
				geraCodigoArgs (NULL, "DMEM %d", num_vars);
			}
		//	ImprimeTabela (tabela);
			geraCodigoArgs (NULL, "RTPR %d, %d", nivel_lexico--, simb->num_parametros); 
			}
#line 1697 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 240 "compilador.y" /* yacc.c:1646  */
    {num_vars = 0; }
#line 1703 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 240 "compilador.y" /* yacc.c:1646  */
    {

		Empilha (&pilha_aloc, &deslocamento);
	  	GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos);
                geraCodigoArgs (NULL, "DSVS %s", rotulo_mepa);
                vars[cont] = num_vars;
			cont++;
	//	ImprimeTabela (tabela);
			}
#line 1717 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 249 "compilador.y" /* yacc.c:1646  */
    {   
	  // ImprimeTabela (tabela);
                   geraCodigo (Desempilha(&pilha_rotulos), "NADA");}
#line 1725 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 252 "compilador.y" /* yacc.c:1646  */
    {
	//ImprimeTabela (tabela);
		}
#line 1733 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 259 "compilador.y" /* yacc.c:1646  */
    {
				DeslocamentoTab(tabela, simb->num_parametros);
				simb->end_retorno = (-4) - (simb->num_parametros);}
#line 1741 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 267 "compilador.y" /* yacc.c:1646  */
    { num_vars=0; }
#line 1747 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 269 "compilador.y" /* yacc.c:1646  */
    { num_vars =0; }
#line 1753 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 273 "compilador.y" /* yacc.c:1646  */
    {
		AtribuiPassagemTab(tabela, p_referencia, num_vars);
		InsereParametro (simb, tipo_aux, p_referencia, num_vars);
		simb_aux->tipo = tipo_aux;
		simb_aux->passagem = p_referencia;
		simb_aux->categoria = PF;
		num_param = simb->num_parametros;
		param[cont2] = simb->num_parametros;
		cont2++;
		}
#line 1768 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 283 "compilador.y" /* yacc.c:1646  */
    {
		AtribuiPassagemTab(tabela, p_valor, num_vars);
		InsereParametro (simb, tipo_aux, p_valor, num_vars);
		simb_aux->tipo = tipo_aux;
		simb_aux->passagem = p_valor;
		simb_aux->categoria = PF;
		param[cont2] = simb->num_parametros;
		cont2++;
		num_param = simb->num_parametros;
		}
#line 1783 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 295 "compilador.y" /* yacc.c:1646  */
    {
			simb->num_parametros++;
			num_vars++;
			simb_aux = InsereSimb (tabela, token, PF, nivel_lexico);
			simb_aux->simbpai = simb;}
#line 1793 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 300 "compilador.y" /* yacc.c:1646  */
    {
			simb->num_parametros++;
			num_vars++;
			simb_aux = InsereSimb (tabela, token, PF, nivel_lexico);
			simb_aux->simbpai = simb;}
#line 1803 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 308 "compilador.y" /* yacc.c:1646  */
    { tipo_aux = tipo_integer;
		    AtribuiTipoTab (tabela, tipo_integer); }
#line 1810 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 310 "compilador.y" /* yacc.c:1646  */
    { tipo_aux = tipo_boolean;
		    AtribuiTipoTab (tabela, tipo_boolean); }
#line 1817 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 312 "compilador.y" /* yacc.c:1646  */
    { tipo_aux = tipo_semtipo;
	           AtribuiTipoTab (tabela, tipo_semtipo); }
#line 1824 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 327 "compilador.y" /* yacc.c:1646  */
    {
		simb = ProcuraSimb (tabela, token, nivel_lexico);
		cont--;
		num_vars = vars[cont];
		if(nivel_lexico != simb->nivel_lexico)
			puts("\nErro Semantico\n");
		geraCodigoArgs (simb->rotulo, "ENRT %d %d", nivel_lexico, num_vars);}
#line 1836 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 349 "compilador.y" /* yacc.c:1646  */
    { 
		geraCodigo (NULL, "LEIT"); 
		geraCodigoArmazenaValor(simb);}
#line 1844 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 352 "compilador.y" /* yacc.c:1646  */
    { 
		geraCodigo (NULL, "LEIT"); 
		simb = ProcuraSimb(tabela, token, nivel_lexico); 
		geraCodigoArmazenaValor (simb);}
#line 1853 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 358 "compilador.y" /* yacc.c:1646  */
    { 
		geraCodigoCarregaValor(simb);
		geraCodigo(NULL, "IMPR"); }
#line 1861 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 361 "compilador.y" /* yacc.c:1646  */
    {
                 geraCodigoArgs (NULL, "CRCT %d", atoi(token));
                 geraCodigo(NULL, "IMPR"); }
#line 1869 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 365 "compilador.y" /* yacc.c:1646  */
    { 
		geraCodigoCarregaValor(simb);
		geraCodigo(NULL, "IMPR"); }
#line 1877 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 368 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigoArgs (NULL, "CRCT %d", atoi(token));
                geraCodigo(NULL, "IMPR"); }
#line 1885 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 374 "compilador.y" /* yacc.c:1646  */
    {
		simb = ProcuraSimb (tabela, token, nivel_lexico);
		geraCodigoArgs (NULL, "DSVR %s, %d, %d", simb->rotulo, simb->nivel_lexico, nivel_lexico);}
#line 1893 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 379 "compilador.y" /* yacc.c:1646  */
    { 
		simb_aux = ProcuraSimb(tabela, token, nivel_lexico); 
		EmpilhaTipos(&pilha_tipos, simb_aux->tipo);
		}
#line 1902 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 386 "compilador.y" /* yacc.c:1646  */
    { 
		ConfereTipos(&pilha_tipos, atribuicao);
		geraCodigoArmazenaValor (simb_aux);}
#line 1910 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 389 "compilador.y" /* yacc.c:1646  */
    {
		if (!simb_aux) {
		puts("procedure nao declarada.");
		exit(1);
		}
		proc = simb_aux;
	     }
#line 1922 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 396 "compilador.y" /* yacc.c:1646  */
    {

		geraCodigoArgs (NULL, "CHPR %s, %d", proc->rotulo, nivel_lexico);
		proc = NULL;
	   }
#line 1932 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 403 "compilador.y" /* yacc.c:1646  */
    { 
		GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos); /*gera o rotulo do inicio*/
		geraCodigo(rotulo_mepa, "NADA"); }
#line 1940 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 406 "compilador.y" /* yacc.c:1646  */
    { 
		GeradorRotulos(&pilha_rotulos, &rotulo_mepa, &cont_rotulos); /*gera o rotulo do fim*/
		tipo = (TipoTab *) Desempilha(&pilha_tipos);
		if (*tipo != tipo_boolean){
			puts("\nSYNTAX ERROR: Operação não é booleana \n");
			exit(-1);
		}
		geraCodigoArgs(NULL, "DSVF %s", rotulo_mepa) }
#line 1953 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 414 "compilador.y" /* yacc.c:1646  */
    { 
		rotulo_aux = Desempilha(&pilha_rotulos);
		rotulo_mepa = Desempilha(&pilha_rotulos);
		geraCodigoArgs (NULL, "DSVS %s", rotulo_mepa);
		geraCodigo(rotulo_aux, "NADA"); }
#line 1963 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 421 "compilador.y" /* yacc.c:1646  */
    { 
		geraCodigo (Desempilha(&pilha_rotulos), "NADA"); }
#line 1970 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 423 "compilador.y" /* yacc.c:1646  */
    {
		}
#line 1977 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 425 "compilador.y" /* yacc.c:1646  */
    {
		geraCodigo (Desempilha(&pilha_rotulos), "NADA"); }
#line 1984 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 430 "compilador.y" /* yacc.c:1646  */
    {	GeradorRotulos (&pilha_rotulos, &rotulo_aux, &cont_rotulos);
		GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos); 
	   }
#line 1992 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 433 "compilador.y" /* yacc.c:1646  */
    {
		tipo = (TipoTab *) Desempilha(&pilha_tipos);
		if (*tipo != tipo_boolean){
			puts("\nSYNTAX ERROR: Operação não é booleana \n");
			exit(-1);
		}
		geraCodigoArgs (NULL, "DSVF %s", rotulo_mepa); }
#line 2004 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 440 "compilador.y" /* yacc.c:1646  */
    {
		rotulo_mepa = Desempilha(&pilha_rotulos);
                geraCodigoArgs (NULL, "DSVS %s", rotulo_aux);
                geraCodigo (rotulo_mepa, "NADA"); }
#line 2013 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 446 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2019 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 446 "compilador.y" /* yacc.c:1646  */
    { 
		ConfereTipos(&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CMMA"); }
#line 2027 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 449 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2033 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 449 "compilador.y" /* yacc.c:1646  */
    { 
		ConfereTipos(&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CMAG"); }
#line 2041 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 452 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2047 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 452 "compilador.y" /* yacc.c:1646  */
    { 
		ConfereTipos(&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CMME"); }
#line 2055 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 455 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2061 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 455 "compilador.y" /* yacc.c:1646  */
    { 
		ConfereTipos(&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CMEG"); }
#line 2069 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 458 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2075 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 458 "compilador.y" /* yacc.c:1646  */
    { 
		ConfereTipos(&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CMIG"); }
#line 2083 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 464 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2089 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 464 "compilador.y" /* yacc.c:1646  */
    { 
			ConfereTipos (&pilha_tipos, calculo); 
			geraCodigo (NULL, "SOMA"); }
#line 2097 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 467 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2103 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 467 "compilador.y" /* yacc.c:1646  */
    { 
			ConfereTipos (&pilha_tipos, calculo); 
			geraCodigo (NULL, "SUBT"); }
#line 2111 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 470 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2117 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 470 "compilador.y" /* yacc.c:1646  */
    { 
			ConfereTipos (&pilha_tipos, comparacao); 
			geraCodigo (NULL, "DISJ"); }
#line 2125 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 476 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2131 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 476 "compilador.y" /* yacc.c:1646  */
    { 
		ConfereTipos (&pilha_tipos, calculo); 
		geraCodigo (NULL, "MULT"); }
#line 2139 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 479 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2145 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 479 "compilador.y" /* yacc.c:1646  */
    { 
		ConfereTipos (&pilha_tipos, calculo); 
		geraCodigo (NULL, "DIVI"); }
#line 2153 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 482 "compilador.y" /* yacc.c:1646  */
    { chamada_proc = false; }
#line 2159 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 482 "compilador.y" /* yacc.c:1646  */
    { 
		ConfereTipos (&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CONJ"); }
#line 2167 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 489 "compilador.y" /* yacc.c:1646  */
    { 
		geraCodigoArgs (NULL, "CRCT %d", atoi(token)); 
		EmpilhaTipos(&pilha_tipos, tipo_integer); 
		}
#line 2176 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 493 "compilador.y" /* yacc.c:1646  */
    { 
		geraCodigo (NULL, "CRCT 1"); 
		EmpilhaTipos(&pilha_tipos, tipo_boolean); 
		}
#line 2185 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 497 "compilador.y" /* yacc.c:1646  */
    { 
		geraCodigo (NULL, "CRCT 0"); 
		EmpilhaTipos(&pilha_tipos, tipo_boolean); 
		}
#line 2194 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 501 "compilador.y" /* yacc.c:1646  */
    {  
		EmpilhaTipos(&pilha_tipos, simb->tipo);  
		geraCodigoCarregaValor(simb);
		}
#line 2203 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 506 "compilador.y" /* yacc.c:1646  */
    {
		ConfereTipos (&pilha_tipos, comparacao); 
		geraCodigo (NULL, "NEGA"); }
#line 2211 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 512 "compilador.y" /* yacc.c:1646  */
    {
	   chamada_fun = true;
		geraCodigoArgs (NULL, "AMEM %d", 1);
	if (!simb) {
		puts("funcao nao declarada.");
		exit(1);
	}
	func = simb;
 }
#line 2225 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 522 "compilador.y" /* yacc.c:1646  */
    { 	
	geraCodigoArgs (NULL, "CHPR %s, %d", func->rotulo, nivel_lexico);
	func = NULL;
  	chamada_fun = false;
 }
#line 2235 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 529 "compilador.y" /* yacc.c:1646  */
    {
		  indice = 0;}
#line 2242 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 537 "compilador.y" /* yacc.c:1646  */
    { indice++;}
#line 2248 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 542 "compilador.y" /* yacc.c:1646  */
    {
	if (simb){
		simb = ProcuraSimb(tabela, token, nivel_lexico); 
	}
	else{
		simb_aux = ProcuraSimb(tabela, token, nivel_lexico); 
	}	
}
#line 2261 "compilador.tab.c" /* yacc.c:1646  */
    break;


#line 2265 "compilador.tab.c" /* yacc.c:1646  */
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
#line 551 "compilador.y" /* yacc.c:1906  */


main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }

/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos Dinamica e Variaveis de Controle
 * ------------------------------------------------------------------- */

  tabela = &TabSimbDin;
  tabela->num_simb = 0;
  tabela->p_inicio = tabela->p_final = NULL;
  InicializaPilha(&pilha_simbolos);
  InicializaPilha(&pilha_tipos);
  InicializaPilha(&pilha_rotulos); 
  InicializaPilha(&pilha_aloc);

  num_vars = 0;
  cont_rotulos = 0;
  total_vars = 0;

/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos
 * ------------------------------------------------------------------- */

   yyin=fp;
   yyparse();

   return 0;
}

