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

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    void add(char c);
    void insert_type();
    void insert_content();
    void get_operation(char *);
    int search(char *);
    char* get_penultimate_variable_type();
    char* get_variable_content(const char* variable_name);
    void print_numbered_source();

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        char * content;
        int line_no;
    } symbol_table[1000];

    int count = 0;
    int q;
    char type[20];
    extern int lc;  // Linha do lexer
    char name[50];
    char content[50];
    char last_int[50];
    char operacao[50];
    int error = 0;

#line 108 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFICADOR = 258,           /* IDENTIFICADOR  */
    TIPO = 259,                    /* TIPO  */
    NUMERO = 260,                  /* NUMERO  */
    STRING = 261,                  /* STRING  */
    BOOL = 262,                    /* BOOL  */
    CHAR = 263,                    /* CHAR  */
    VAI_SER = 264,                 /* VAI_SER  */
    NAQUELE_NAIPE = 265,           /* NAQUELE_NAIPE  */
    FRAGA = 266,                   /* FRAGA  */
    NAO = 267,                     /* NAO  */
    INTERROGACAO = 268,            /* INTERROGACAO  */
    VAI_FAZENDO_ATE = 269,         /* VAI_FAZENDO_ATE  */
    PRA = 270,                     /* PRA  */
    PICA_MULA = 271,               /* PICA_MULA  */
    ARREDA = 272,                  /* ARREDA  */
    ANOTA = 273,                   /* ANOTA  */
    AI_CE_JUNTA = 274,             /* AI_CE_JUNTA  */
    AI_CE_DIMINUI = 275,           /* AI_CE_DIMINUI  */
    CE_MULTIPLICA_POR = 276,       /* CE_MULTIPLICA_POR  */
    CE_DIVIDE_POR = 277,           /* CE_DIVIDE_POR  */
    ENGUAL = 278,                  /* ENGUAL  */
    NADA_A_VER_COM = 279,          /* NADA_A_VER_COM  */
    MAIOR_QUE = 280,               /* MAIOR_QUE  */
    MENOR_QUE = 281,               /* MENOR_QUE  */
    ELEVADO_A = 282,               /* ELEVADO_A  */
    LBRACE = 283,                  /* LBRACE  */
    RBRACE = 284,                  /* RBRACE  */
    COLLON = 285,                  /* COLLON  */
    COMMA = 286,                   /* COMMA  */
    DOT = 287,                     /* DOT  */
    UNDERSCORE = 288,              /* UNDERSCORE  */
    OR_OP = 289,                   /* OR_OP  */
    AND_OP = 290,                  /* AND_OP  */
    NOT_OP = 291,                  /* NOT_OP  */
    END_COMMAND = 292              /* END_COMMAND  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFICADOR 258
#define TIPO 259
#define NUMERO 260
#define STRING 261
#define BOOL 262
#define CHAR 263
#define VAI_SER 264
#define NAQUELE_NAIPE 265
#define FRAGA 266
#define NAO 267
#define INTERROGACAO 268
#define VAI_FAZENDO_ATE 269
#define PRA 270
#define PICA_MULA 271
#define ARREDA 272
#define ANOTA 273
#define AI_CE_JUNTA 274
#define AI_CE_DIMINUI 275
#define CE_MULTIPLICA_POR 276
#define CE_DIVIDE_POR 277
#define ENGUAL 278
#define NADA_A_VER_COM 279
#define MAIOR_QUE 280
#define MENOR_QUE 281
#define ELEVADO_A 282
#define LBRACE 283
#define RBRACE 284
#define COLLON 285
#define COMMA 286
#define DOT 287
#define UNDERSCORE 288
#define OR_OP 289
#define AND_OP 290
#define NOT_OP 291
#define END_COMMAND 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 56 "parser.y"

    char *str;
    int num;

#line 240 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFICADOR = 3,              /* IDENTIFICADOR  */
  YYSYMBOL_TIPO = 4,                       /* TIPO  */
  YYSYMBOL_NUMERO = 5,                     /* NUMERO  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_VAI_SER = 9,                    /* VAI_SER  */
  YYSYMBOL_NAQUELE_NAIPE = 10,             /* NAQUELE_NAIPE  */
  YYSYMBOL_FRAGA = 11,                     /* FRAGA  */
  YYSYMBOL_NAO = 12,                       /* NAO  */
  YYSYMBOL_INTERROGACAO = 13,              /* INTERROGACAO  */
  YYSYMBOL_VAI_FAZENDO_ATE = 14,           /* VAI_FAZENDO_ATE  */
  YYSYMBOL_PRA = 15,                       /* PRA  */
  YYSYMBOL_PICA_MULA = 16,                 /* PICA_MULA  */
  YYSYMBOL_ARREDA = 17,                    /* ARREDA  */
  YYSYMBOL_ANOTA = 18,                     /* ANOTA  */
  YYSYMBOL_AI_CE_JUNTA = 19,               /* AI_CE_JUNTA  */
  YYSYMBOL_AI_CE_DIMINUI = 20,             /* AI_CE_DIMINUI  */
  YYSYMBOL_CE_MULTIPLICA_POR = 21,         /* CE_MULTIPLICA_POR  */
  YYSYMBOL_CE_DIVIDE_POR = 22,             /* CE_DIVIDE_POR  */
  YYSYMBOL_ENGUAL = 23,                    /* ENGUAL  */
  YYSYMBOL_NADA_A_VER_COM = 24,            /* NADA_A_VER_COM  */
  YYSYMBOL_MAIOR_QUE = 25,                 /* MAIOR_QUE  */
  YYSYMBOL_MENOR_QUE = 26,                 /* MENOR_QUE  */
  YYSYMBOL_ELEVADO_A = 27,                 /* ELEVADO_A  */
  YYSYMBOL_LBRACE = 28,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 29,                    /* RBRACE  */
  YYSYMBOL_COLLON = 30,                    /* COLLON  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_UNDERSCORE = 33,                /* UNDERSCORE  */
  YYSYMBOL_OR_OP = 34,                     /* OR_OP  */
  YYSYMBOL_AND_OP = 35,                    /* AND_OP  */
  YYSYMBOL_NOT_OP = 36,                    /* NOT_OP  */
  YYSYMBOL_END_COMMAND = 37,               /* END_COMMAND  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_programa = 39,                  /* programa  */
  YYSYMBOL_declaracoes = 40,               /* declaracoes  */
  YYSYMBOL_declaracao = 41,                /* declaracao  */
  YYSYMBOL_termo = 42,                     /* termo  */
  YYSYMBOL_redefinicao_variavel = 43,      /* redefinicao_variavel  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_declaracao_variavel = 47,       /* declaracao_variavel  */
  YYSYMBOL_48_4 = 48,                      /* $@4  */
  YYSYMBOL_49_5 = 49,                      /* $@5  */
  YYSYMBOL_50_6 = 50,                      /* $@6  */
  YYSYMBOL_51_7 = 51,                      /* $@7  */
  YYSYMBOL_declaracao_funcao = 52,         /* declaracao_funcao  */
  YYSYMBOL_53_8 = 53,                      /* $@8  */
  YYSYMBOL_54_9 = 54,                      /* $@9  */
  YYSYMBOL_parametros = 55,                /* parametros  */
  YYSYMBOL_parametro = 56,                 /* parametro  */
  YYSYMBOL_declaracao_estrutura = 57,      /* declaracao_estrutura  */
  YYSYMBOL_if = 58,                        /* if  */
  YYSYMBOL_59_10 = 59,                     /* $@10  */
  YYSYMBOL_60_11 = 60,                     /* $@11  */
  YYSYMBOL_61_12 = 61,                     /* $@12  */
  YYSYMBOL_while = 62,                     /* while  */
  YYSYMBOL_63_13 = 63,                     /* $@13  */
  YYSYMBOL_64_14 = 64,                     /* $@14  */
  YYSYMBOL_break = 65,                     /* break  */
  YYSYMBOL_66_15 = 66,                     /* $@15  */
  YYSYMBOL_return = 67,                    /* return  */
  YYSYMBOL_68_16 = 68,                     /* $@16  */
  YYSYMBOL_expressao = 69,                 /* expressao  */
  YYSYMBOL_70_17 = 70,                     /* $@17  */
  YYSYMBOL_71_18 = 71,                     /* $@18  */
  YYSYMBOL_72_19 = 72,                     /* $@19  */
  YYSYMBOL_73_20 = 73,                     /* $@20  */
  YYSYMBOL_print = 74,                     /* print  */
  YYSYMBOL_75_21 = 75,                     /* $@21  */
  YYSYMBOL_76_22 = 76,                     /* $@22  */
  YYSYMBOL_operador = 77,                  /* operador  */
  YYSYMBOL_operadores_pos = 78,            /* operadores_pos  */
  YYSYMBOL_bloco = 79,                     /* bloco  */
  YYSYMBOL_80_23 = 80                      /* $@23  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   98

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  113

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    68,    69,    73,    74,    75,    76,    80,
      81,    82,    83,    84,    88,    88,    88,    88,    92,    92,
      92,    92,    92,    96,    96,    96,   100,   101,   105,   111,
     112,   114,   115,   116,   120,   121,   121,   122,   122,   122,
     126,   126,   126,   139,   139,   143,   143,   147,   148,   148,
     149,   149,   150,   150,   151,   151,   152,   153,   157,   157,
     157,   161,   162,   163,   164,   165,   168,   169,   170,   175,
     175,   177
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFICADOR",
  "TIPO", "NUMERO", "STRING", "BOOL", "CHAR", "VAI_SER", "NAQUELE_NAIPE",
  "FRAGA", "NAO", "INTERROGACAO", "VAI_FAZENDO_ATE", "PRA", "PICA_MULA",
  "ARREDA", "ANOTA", "AI_CE_JUNTA", "AI_CE_DIMINUI", "CE_MULTIPLICA_POR",
  "CE_DIVIDE_POR", "ENGUAL", "NADA_A_VER_COM", "MAIOR_QUE", "MENOR_QUE",
  "ELEVADO_A", "LBRACE", "RBRACE", "COLLON", "COMMA", "DOT", "UNDERSCORE",
  "OR_OP", "AND_OP", "NOT_OP", "END_COMMAND", "$accept", "programa",
  "declaracoes", "declaracao", "termo", "redefinicao_variavel", "$@1",
  "$@2", "$@3", "declaracao_variavel", "$@4", "$@5", "$@6", "$@7",
  "declaracao_funcao", "$@8", "$@9", "parametros", "parametro",
  "declaracao_estrutura", "if", "$@10", "$@11", "$@12", "while", "$@13",
  "$@14", "break", "$@15", "return", "$@16", "expressao", "$@17", "$@18",
  "$@19", "$@20", "print", "$@21", "$@22", "operador", "operadores_pos",
  "bloco", "$@23", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-35)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,   -35,   -35,   -35,    -1,   -35,   -35,   -35,   -35,     8,
     -35,     6,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,     2,    10,    11,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,    53,     5,    52,    -1,    -7,    -1,    -9,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,    -1,     6,    52,    -3,   -35,    -4,   -35,
      -1,    32,    14,    -1,    -1,    -1,    -1,   -35,     0,   -35,
     -35,   -35,    -1,   -35,   -35,    41,   -35,   -35,   -35,   -35,
      35,   -35,     6,    13,    17,    -1,   -35,    27,    30,    51,
      50,    28,   -35,   -35,   -35,    37,    41,   -35,   -35,   -35,
      34,    36,   -35,     6,   -35,   -35,   -35,   -35,    31,     6,
     -35,    40,   -35
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    14,    18,    23,     0,    40,    43,    45,    58,     0,
       2,     3,     8,     5,     6,     7,    29,    30,    31,    33,
      32,     0,     0,     0,     9,    10,    11,    12,    13,    66,
      67,    68,    47,     0,     0,     0,     0,     0,     0,     1,
       4,    15,    19,    24,    48,    50,    52,    54,    62,    63,
      64,    65,    61,     0,     0,     0,     0,    44,     0,    59,
       0,     0,     0,     0,     0,     0,     0,    57,     0,    56,
      41,    46,     0,    16,    20,     0,    49,    51,    53,    55,
      35,    34,     0,     0,     0,     0,    28,     0,    26,     0,
       0,     0,    60,    17,    21,     0,     0,    36,    38,    42,
       0,     0,    27,     0,    22,    69,    71,    25,     0,     0,
      39,     0,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,   -11,   -31,   -19,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,   -35,   -15,   -35,   -35,
      -6,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -34,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    32,    12,    21,    60,    84,    13,
      22,    61,    85,   100,    14,    23,    62,    87,    88,    15,
      16,    89,    90,   103,    17,    35,    82,    18,    36,    19,
      37,    33,    63,    64,    65,    66,    20,    38,    72,    53,
      34,   107,   109
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      40,    56,    24,    58,    25,    26,    27,    28,    39,     1,
       2,    41,    80,    42,    43,    55,     3,     4,    54,    67,
       5,    59,     6,     7,     8,    57,    73,    70,    71,    76,
      77,    78,    79,    29,    30,    31,    69,    81,    83,     1,
       2,    74,    75,    68,    86,    92,     3,     4,   -37,    93,
       5,    94,     6,     7,     8,    24,    95,    25,    26,    27,
      28,    96,     4,    98,   105,    99,   104,   101,   110,   112,
     106,    91,    44,    45,    46,    47,    48,    49,    50,    51,
      52,   102,     0,    97,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,     0,     0,   111
};

static const yytype_int8 yycheck[] =
{
      11,    35,     3,    37,     5,     6,     7,     8,     0,     3,
       4,     9,    12,     3,     3,    34,    10,    11,    13,    53,
      14,    30,    16,    17,    18,    32,    60,    30,    32,    63,
      64,    65,    66,    34,    35,    36,    55,    37,    72,     3,
       4,     9,    28,    54,     3,    32,    10,    11,    13,    32,
      14,    85,    16,    17,    18,     3,    29,     5,     6,     7,
       8,    31,    11,    13,    28,    37,    32,    30,    37,    29,
     101,    82,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    96,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,   109
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    10,    11,    14,    16,    17,    18,    39,
      40,    41,    43,    47,    52,    57,    58,    62,    65,    67,
      74,    44,    48,    53,     3,     5,     6,     7,     8,    34,
      35,    36,    42,    69,    78,    63,    66,    68,    75,     0,
      40,     9,     3,     3,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    77,    13,    42,    69,    32,    69,    30,
      45,    49,    54,    70,    71,    72,    73,    69,    40,    42,
      30,    32,    76,    69,     9,    28,    69,    69,    69,    69,
      12,    37,    64,    69,    46,    50,     3,    55,    56,    59,
      60,    40,    32,    32,    69,    29,    31,    58,    13,    37,
      51,    30,    55,    61,    32,    28,    41,    79,    40,    80,
      37,    40,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    42,
      42,    42,    42,    42,    44,    45,    46,    43,    48,    49,
      50,    51,    47,    53,    54,    52,    55,    55,    56,    57,
      57,    57,    57,    57,    58,    59,    58,    60,    61,    58,
      63,    64,    62,    66,    65,    68,    67,    69,    70,    69,
      71,    69,    72,    69,    73,    69,    69,    69,    75,    76,
      74,    77,    77,    77,    77,    77,    78,    78,    78,    80,
      79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     0,     7,     0,     0,
       0,     0,     9,     0,     0,     9,     1,     3,     1,     1,
       1,     1,     1,     1,     5,     0,     7,     0,     0,    10,
       0,     0,     7,     0,     3,     0,     4,     1,     0,     4,
       0,     4,     0,     4,     0,     4,     3,     3,     0,     0,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     1
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
  case 10: /* termo: NUMERO  */
#line 81 "parser.y"
             {insert_content();}
#line 1381 "y.tab.c"
    break;

  case 11: /* termo: STRING  */
#line 82 "parser.y"
             {insert_content();}
#line 1387 "y.tab.c"
    break;

  case 12: /* termo: BOOL  */
#line 83 "parser.y"
           {insert_content();}
#line 1393 "y.tab.c"
    break;

  case 13: /* termo: CHAR  */
#line 84 "parser.y"
           {insert_content();}
#line 1399 "y.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 88 "parser.y"
                     {strcpy(name, (yyvsp[0].str));}
#line 1405 "y.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 88 "parser.y"
                                                {add('K');}
#line 1411 "y.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 88 "parser.y"
                                                                      {add('V');}
#line 1417 "y.tab.c"
    break;

  case 18: /* $@4: %empty  */
#line 92 "parser.y"
         {insert_type();add('K');}
#line 1423 "y.tab.c"
    break;

  case 19: /* $@5: %empty  */
#line 92 "parser.y"
                                                 {strcpy(name, (yyvsp[0].str));}
#line 1429 "y.tab.c"
    break;

  case 20: /* $@6: %empty  */
#line 92 "parser.y"
                                                                            {add('K');}
#line 1435 "y.tab.c"
    break;

  case 21: /* $@7: %empty  */
#line 92 "parser.y"
                                                                                                 {add('V'); }
#line 1441 "y.tab.c"
    break;

  case 23: /* $@8: %empty  */
#line 96 "parser.y"
                 {add('K');}
#line 1447 "y.tab.c"
    break;

  case 24: /* $@9: %empty  */
#line 96 "parser.y"
                                          {strcpy(name, (yyvsp[0].str));}
#line 1453 "y.tab.c"
    break;

  case 28: /* parametro: IDENTIFICADOR  */
#line 105 "parser.y"
                  {
        add('V');
    }
#line 1461 "y.tab.c"
    break;

  case 34: /* if: FRAGA expressao INTERROGACAO declaracoes END_COMMAND  */
#line 120 "parser.y"
                                                        {add('K');}
#line 1467 "y.tab.c"
    break;

  case 35: /* $@10: %empty  */
#line 121 "parser.y"
                                                      {add('K');}
#line 1473 "y.tab.c"
    break;

  case 37: /* $@11: %empty  */
#line 122 "parser.y"
                                                      {add('K');}
#line 1479 "y.tab.c"
    break;

  case 38: /* $@12: %empty  */
#line 122 "parser.y"
                                                                              {add('K');}
#line 1485 "y.tab.c"
    break;

  case 39: /* if: FRAGA expressao INTERROGACAO declaracoes NAO $@11 INTERROGACAO $@12 declaracoes END_COMMAND  */
#line 122 "parser.y"
                                                                                                                 {add('K');}
#line 1491 "y.tab.c"
    break;

  case 40: /* $@13: %empty  */
#line 126 "parser.y"
                    {add('K');}
#line 1497 "y.tab.c"
    break;

  case 41: /* $@14: %empty  */
#line 126 "parser.y"
                                                {add('K');}
#line 1503 "y.tab.c"
    break;

  case 42: /* while: VAI_FAZENDO_ATE $@13 expressao COLLON $@14 declaracoes END_COMMAND  */
#line 126 "parser.y"
                                                                                    {add('K');}
#line 1509 "y.tab.c"
    break;

  case 43: /* $@15: %empty  */
#line 139 "parser.y"
             {add('K');}
#line 1515 "y.tab.c"
    break;

  case 44: /* break: PICA_MULA $@15 DOT  */
#line 139 "parser.y"
                            {add('K');}
#line 1521 "y.tab.c"
    break;

  case 45: /* $@16: %empty  */
#line 143 "parser.y"
          {add('K');}
#line 1527 "y.tab.c"
    break;

  case 46: /* return: ARREDA $@16 expressao DOT  */
#line 143 "parser.y"
                                   {add('K');}
#line 1533 "y.tab.c"
    break;

  case 48: /* $@17: %empty  */
#line 148 "parser.y"
                       {add('K');}
#line 1539 "y.tab.c"
    break;

  case 49: /* expressao: termo AI_CE_JUNTA $@17 expressao  */
#line 148 "parser.y"
                                             {get_operation("AI_CE_JUNTA");}
#line 1545 "y.tab.c"
    break;

  case 50: /* $@18: %empty  */
#line 149 "parser.y"
                         {add('K');}
#line 1551 "y.tab.c"
    break;

  case 51: /* expressao: termo AI_CE_DIMINUI $@18 expressao  */
#line 149 "parser.y"
                                               {get_operation("AI_CE_DIMINUI");}
#line 1557 "y.tab.c"
    break;

  case 52: /* $@19: %empty  */
#line 150 "parser.y"
                             {add('K');}
#line 1563 "y.tab.c"
    break;

  case 53: /* expressao: termo CE_MULTIPLICA_POR $@19 expressao  */
#line 150 "parser.y"
                                                   {get_operation("CE_MULTIPLICA_POR");}
#line 1569 "y.tab.c"
    break;

  case 54: /* $@20: %empty  */
#line 151 "parser.y"
                         {add('K');}
#line 1575 "y.tab.c"
    break;

  case 55: /* expressao: termo CE_DIVIDE_POR $@20 expressao  */
#line 151 "parser.y"
                                               {get_operation("CE_DIVIDE_POR");}
#line 1581 "y.tab.c"
    break;

  case 58: /* $@21: %empty  */
#line 157 "parser.y"
         {add('K');}
#line 1587 "y.tab.c"
    break;

  case 59: /* $@22: %empty  */
#line 157 "parser.y"
                           {add('K');}
#line 1593 "y.tab.c"
    break;

  case 60: /* print: ANOTA $@21 COLLON $@22 expressao DOT  */
#line 157 "parser.y"
                                                    {add('K');}
#line 1599 "y.tab.c"
    break;

  case 61: /* operador: ELEVADO_A  */
#line 161 "parser.y"
                 {add('K');}
#line 1605 "y.tab.c"
    break;

  case 62: /* operador: ENGUAL  */
#line 162 "parser.y"
            {add('K');}
#line 1611 "y.tab.c"
    break;

  case 63: /* operador: NADA_A_VER_COM  */
#line 163 "parser.y"
                    {add('K');}
#line 1617 "y.tab.c"
    break;

  case 64: /* operador: MAIOR_QUE  */
#line 164 "parser.y"
               {add('K');}
#line 1623 "y.tab.c"
    break;

  case 65: /* operador: MENOR_QUE  */
#line 165 "parser.y"
               {add('K');}
#line 1629 "y.tab.c"
    break;

  case 66: /* operadores_pos: OR_OP  */
#line 168 "parser.y"
               {add('K');}
#line 1635 "y.tab.c"
    break;

  case 67: /* operadores_pos: AND_OP  */
#line 169 "parser.y"
             {add('K');}
#line 1641 "y.tab.c"
    break;

  case 68: /* operadores_pos: NOT_OP  */
#line 170 "parser.y"
            {add('K');}
#line 1647 "y.tab.c"
    break;

  case 69: /* $@23: %empty  */
#line 175 "parser.y"
              {add('K');}
#line 1653 "y.tab.c"
    break;

  case 70: /* bloco: LBRACE $@23 declaracoes RBRACE  */
#line 175 "parser.y"
                                            {add('K');}
#line 1659 "y.tab.c"
    break;


#line 1663 "y.tab.c"

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

#line 180 "parser.y"


int main(int argc, char **argv) {
    printf("Linha:0|  ");
    yyparse();
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t Análise Léxica \n\n");
    printf("\n%-30s %-15s %-15s %-15s %-10s\n", "[SÍMBOLO]", "[TIPO DE DADO]", "[TIPO TOKEN]", "[CONTEÚDO]", "[LINHA]");
    printf("________________________________________________________________________________\n\n");

    for (int i = 0; i < count; i++) {
        printf("%-30s %-15s %-15s %-15s %-10d\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].content, symbol_table[i].line_no);
    }

    for (int i = 0; i < count; i++) {
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }
    if (!error)
        printf("\n\n\e[0;32m Programa Sintaticamente Correto.");
    else
        printf("\n\n\e[0;31mPrograma Sintaticamente Incorreto.");
    printf("\n\n");

    return 0;
}

int search(char *type) {
  int i;
  for (i = count - 1; i >= 0; i--) {
    if (strcmp(symbol_table[i].id_name, type) == 0) {
      return -1;
    }
  }
  return 0;
}


void add(char c) {
  q = search(yytext);
  if (!q) {
    if (c == 'K') {
      symbol_table[count].id_name = strdup(yytext);
      symbol_table[count].data_type = strdup("N/A");
      symbol_table[count].content = strdup("N/A");
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Keyword");
      count++;
    } else if (c == 'V') {
      symbol_table[count].id_name = strdup(name);
      symbol_table[count].data_type = strdup(type);
      symbol_table[count].content = strdup(content);
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Variable");
      count++;
    } else if (c == 'C') {
      symbol_table[count].id_name = strdup(yytext);
      symbol_table[count].data_type = strdup(type);
      symbol_table[count].content = strdup(content);
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Constant");
      count++;
    } else if (c == 'F') {
      symbol_table[count].id_name = strdup(yytext);
      symbol_table[count].data_type = strdup("N/A");
      symbol_table[count].content = strdup(content);
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Function");
      count++;
    }
  }
}

char* get_penultimate_variable_type() {
    int found_count = 0;
    int total_count = 0;
    char* penultimate_type = NULL;

    for (int i = 0; i < count; i++) {
        if (strcmp(symbol_table[i].type, "Variable") == 0) {
            found_count++;
            if (found_count == 2) {
                penultimate_type = symbol_table[i].content;
            } else if (found_count > 2) {
                penultimate_type = symbol_table[i - 1].content;
            }
        }
    }

    return penultimate_type;
}

char* get_variable_content(const char* variable_name) {
    for (int i = 0; i < count; i++) {
        //printf("%s\n",symbol_table[i].id_name);
        if (strcmp(symbol_table[i].type, "Variable") == 0 && strcmp(symbol_table[i].id_name, variable_name) == 0) {
            return symbol_table[i].content;
        }
    }
    return NULL;
}

void insert_content() {
  //printf("\nXaleibs: %s\n", yytext);
  strcpy(last_int, content);
  strcpy(content, yytext);
}

void insert_type() {
    strcpy(type, yytext);
}

void insert_type_manual(char * string){
  strcpy(type, string);
}

void yyerror(const char* msg) {
    error = 1;
  fprintf(stderr, "\n\e[0;31mErro proximo da linha %i: %s.\n\n\e[0m", lc, msg);
}

void get_operation(char *operator){
    if (operator == "AI_CE_JUNTA"){
        sprintf(operacao, "%d", atoi(last_int) + atoi(content));
    }
    else if (operator == "AI_CE_DIMINUI"){
        sprintf(operacao, "%d", atoi(last_int) - atoi(content));
    }
    else if (operator == "CE_MULTIPLICA_POR"){
        sprintf(operacao, "%d", atoi(last_int) * atoi(content));
    }
    else if (operator == "CE_DIVIDE_POR"){
        sprintf(operacao, "%d", atoi(last_int) / atoi(content));
    }
    strcpy(content, operacao);
}
