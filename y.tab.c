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
    void get_operation2(char *);
    void replaceChar(char *str, char oldChar, char newChar);
    int search(char *);
    char* get_penultimate_variable_type();
    char* get_variable_content(const char* variable_name);
    void print_numbered_source();
    int contains_letter(const char *str);
    void insert_content_manual(char * string);
    void change_variable_content(const char* variable_name, char * newval);
    void printtree(struct node*);
    void draw_tree_hor2(struct node *tree, int depth, char *path, int right);
    void draw_tree_hor(struct node *tree);
    int contains_letter_not_comma(const char *str);

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        char * content;
        int line_no;
    } symbol_table[1000];

    struct node* mknode(struct node *left, struct node *right, char *token);
	struct node *head;
    
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
        char *content;
    };

    int count = 0;
    int q;
    char type[20];
    extern int lc;  // Linha do lexer
    char name[50];
    char content[50];
    char last_content[50];
    char operacao[50];
    int syntax_error = 0;
    int semantic_error = 0;
    char current_var[50];
    char last_var[50];
    struct node * temp;

#line 131 "y.tab.c"

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
    PICA_MULA = 270,               /* PICA_MULA  */
    ARREDA = 271,                  /* ARREDA  */
    ANOTA = 272,                   /* ANOTA  */
    AI_CE_JUNTA = 273,             /* AI_CE_JUNTA  */
    AI_CE_DIMINUI = 274,           /* AI_CE_DIMINUI  */
    CE_MULTIPLICA_POR = 275,       /* CE_MULTIPLICA_POR  */
    CE_DIVIDE_POR = 276,           /* CE_DIVIDE_POR  */
    ENGUAL = 277,                  /* ENGUAL  */
    NADA_A_VER_COM = 278,          /* NADA_A_VER_COM  */
    MAIOR_QUE = 279,               /* MAIOR_QUE  */
    MENOR_QUE = 280,               /* MENOR_QUE  */
    ELEVADO_A = 281,               /* ELEVADO_A  */
    LBRACE = 282,                  /* LBRACE  */
    RBRACE = 283,                  /* RBRACE  */
    COLLON = 284,                  /* COLLON  */
    COMMA = 285,                   /* COMMA  */
    DOT = 286,                     /* DOT  */
    OR_OP = 287,                   /* OR_OP  */
    AND_OP = 288,                  /* AND_OP  */
    NOT_OP = 289,                  /* NOT_OP  */
    END_COMMAND = 290              /* END_COMMAND  */
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
#define PICA_MULA 270
#define ARREDA 271
#define ANOTA 272
#define AI_CE_JUNTA 273
#define AI_CE_DIMINUI 274
#define CE_MULTIPLICA_POR 275
#define CE_DIVIDE_POR 276
#define ENGUAL 277
#define NADA_A_VER_COM 278
#define MAIOR_QUE 279
#define MENOR_QUE 280
#define ELEVADO_A 281
#define LBRACE 282
#define RBRACE 283
#define COLLON 284
#define COMMA 285
#define DOT 286
#define OR_OP 287
#define AND_OP 288
#define NOT_OP 289
#define END_COMMAND 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 61 "parser.y"

    char *str;
    int num;
    struct prod { 
		char name[100]; 
		struct node* nd;
	} thisProd; 

#line 263 "y.tab.c"

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
  YYSYMBOL_PICA_MULA = 15,                 /* PICA_MULA  */
  YYSYMBOL_ARREDA = 16,                    /* ARREDA  */
  YYSYMBOL_ANOTA = 17,                     /* ANOTA  */
  YYSYMBOL_AI_CE_JUNTA = 18,               /* AI_CE_JUNTA  */
  YYSYMBOL_AI_CE_DIMINUI = 19,             /* AI_CE_DIMINUI  */
  YYSYMBOL_CE_MULTIPLICA_POR = 20,         /* CE_MULTIPLICA_POR  */
  YYSYMBOL_CE_DIVIDE_POR = 21,             /* CE_DIVIDE_POR  */
  YYSYMBOL_ENGUAL = 22,                    /* ENGUAL  */
  YYSYMBOL_NADA_A_VER_COM = 23,            /* NADA_A_VER_COM  */
  YYSYMBOL_MAIOR_QUE = 24,                 /* MAIOR_QUE  */
  YYSYMBOL_MENOR_QUE = 25,                 /* MENOR_QUE  */
  YYSYMBOL_ELEVADO_A = 26,                 /* ELEVADO_A  */
  YYSYMBOL_LBRACE = 27,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 28,                    /* RBRACE  */
  YYSYMBOL_COLLON = 29,                    /* COLLON  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_DOT = 31,                       /* DOT  */
  YYSYMBOL_OR_OP = 32,                     /* OR_OP  */
  YYSYMBOL_AND_OP = 33,                    /* AND_OP  */
  YYSYMBOL_NOT_OP = 34,                    /* NOT_OP  */
  YYSYMBOL_END_COMMAND = 35,               /* END_COMMAND  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_programa = 37,                  /* programa  */
  YYSYMBOL_declaracoes = 38,               /* declaracoes  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_declaracao = 40,                /* declaracao  */
  YYSYMBOL_termo = 41,                     /* termo  */
  YYSYMBOL_redefinicao_variavel = 42,      /* redefinicao_variavel  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_44_3 = 44,                      /* $@3  */
  YYSYMBOL_declaracao_variavel = 45,       /* declaracao_variavel  */
  YYSYMBOL_46_4 = 46,                      /* $@4  */
  YYSYMBOL_47_5 = 47,                      /* $@5  */
  YYSYMBOL_48_6 = 48,                      /* $@6  */
  YYSYMBOL_49_7 = 49,                      /* $@7  */
  YYSYMBOL_declaracao_funcao = 50,         /* declaracao_funcao  */
  YYSYMBOL_51_8 = 51,                      /* $@8  */
  YYSYMBOL_52_9 = 52,                      /* $@9  */
  YYSYMBOL_53_10 = 53,                     /* $@10  */
  YYSYMBOL_54_11 = 54,                     /* $@11  */
  YYSYMBOL_55_12 = 55,                     /* $@12  */
  YYSYMBOL_parametros = 56,                /* parametros  */
  YYSYMBOL_57_13 = 57,                     /* $@13  */
  YYSYMBOL_parametro = 58,                 /* parametro  */
  YYSYMBOL_declaracao_estrutura = 59,      /* declaracao_estrutura  */
  YYSYMBOL_if = 60,                        /* if  */
  YYSYMBOL_61_14 = 61,                     /* $@14  */
  YYSYMBOL_62_15 = 62,                     /* $@15  */
  YYSYMBOL_while = 63,                     /* while  */
  YYSYMBOL_64_16 = 64,                     /* $@16  */
  YYSYMBOL_65_17 = 65,                     /* $@17  */
  YYSYMBOL_break = 66,                     /* break  */
  YYSYMBOL_67_18 = 67,                     /* $@18  */
  YYSYMBOL_return = 68,                    /* return  */
  YYSYMBOL_69_19 = 69,                     /* $@19  */
  YYSYMBOL_expressao = 70,                 /* expressao  */
  YYSYMBOL_71_20 = 71,                     /* $@20  */
  YYSYMBOL_72_21 = 72,                     /* $@21  */
  YYSYMBOL_73_22 = 73,                     /* $@22  */
  YYSYMBOL_74_23 = 74,                     /* $@23  */
  YYSYMBOL_print = 75,                     /* print  */
  YYSYMBOL_76_24 = 76,                     /* $@24  */
  YYSYMBOL_77_25 = 77,                     /* $@25  */
  YYSYMBOL_operador = 78,                  /* operador  */
  YYSYMBOL_operadores_pos = 79,            /* operadores_pos  */
  YYSYMBOL_bloco = 80,                     /* bloco  */
  YYSYMBOL_81_26 = 81                      /* $@26  */
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
#define YYLAST   92

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    95,    95,   102,   105,   105,   109,   110,   111,   112,
     116,   126,   127,   128,   129,   133,   133,   133,   137,   137,
     141,   143,   137,   155,   155,   155,   155,   155,   155,   159,
     160,   160,   164,   168,   169,   171,   172,   173,   177,   178,
     179,   179,   179,   183,   183,   183,   196,   196,   200,   200,
     204,   205,   205,   206,   206,   207,   207,   208,   208,   209,
     210,   214,   214,   214,   218,   219,   220,   221,   222,   225,
     226,   227,   232,   232,   234
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
  "FRAGA", "NAO", "INTERROGACAO", "VAI_FAZENDO_ATE", "PICA_MULA", "ARREDA",
  "ANOTA", "AI_CE_JUNTA", "AI_CE_DIMINUI", "CE_MULTIPLICA_POR",
  "CE_DIVIDE_POR", "ENGUAL", "NADA_A_VER_COM", "MAIOR_QUE", "MENOR_QUE",
  "ELEVADO_A", "LBRACE", "RBRACE", "COLLON", "COMMA", "DOT", "OR_OP",
  "AND_OP", "NOT_OP", "END_COMMAND", "$accept", "programa", "declaracoes",
  "$@1", "declaracao", "termo", "redefinicao_variavel", "$@2", "$@3",
  "declaracao_variavel", "$@4", "$@5", "$@6", "$@7", "declaracao_funcao",
  "$@8", "$@9", "$@10", "$@11", "$@12", "parametros", "$@13", "parametro",
  "declaracao_estrutura", "if", "$@14", "$@15", "while", "$@16", "$@17",
  "break", "$@18", "return", "$@19", "expressao", "$@20", "$@21", "$@22",
  "$@23", "print", "$@24", "$@25", "operador", "operadores_pos", "bloco",
  "$@26", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      65,   -43,   -43,   -43,     4,   -43,   -43,   -43,   -43,     8,
     -43,     6,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,    -5,    10,    12,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,    66,     3,    39,     4,   -14,     4,    -9,   -43,
      65,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,     4,    65,    39,    -8,   -43,    -7,   -43,
     -43,     4,    13,    -4,     4,     4,     4,     4,   -43,   -10,
     -43,   -43,   -43,     4,    -3,   -43,   -43,   -43,   -43,   -43,
     -43,    16,   -43,    65,     9,   -43,     4,    32,    35,    14,
     -43,   -43,   -43,    25,    24,   -43,   -43,    28,   -43,   -43,
      65,   -43,    26,    32,    21,   -43,   -43,   -43,    47,   -43,
     -43,   -43,    65,    37,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    15,    18,    23,     0,    43,    46,    48,    61,     0,
       2,     4,     9,     6,     7,     8,    33,    34,    35,    37,
      36,     0,     0,     0,    10,    11,    12,    13,    14,    69,
      70,    71,    50,     0,     0,     0,     0,     0,     0,     1,
       0,    16,    19,    24,    51,    53,    55,    57,    65,    66,
      67,    68,    64,     0,     0,     0,     0,    47,     0,    62,
       5,     0,     0,     0,     0,     0,     0,     0,    60,     0,
      59,    44,    49,     0,     0,    20,    25,    52,    54,    56,
      58,    39,    38,     0,     0,    17,     0,     0,     0,     0,
      63,    21,    32,     0,    29,    41,    45,     0,    26,    30,
       0,    22,     0,     0,     0,    27,    31,    42,     0,    72,
      74,    28,     0,     0,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   -40,   -43,   -42,   -29,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -36,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -34,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    40,    11,    32,    12,    21,    61,    13,
      22,    62,    86,    97,    14,    23,    63,    87,   102,   108,
      93,   103,    94,    15,    16,    88,   100,    17,    35,    83,
      18,    36,    19,    37,    33,    64,    65,    66,    67,    20,
      38,    73,    53,    34,   111,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      60,    56,    81,    58,    41,    55,    -3,    24,    39,    25,
      26,    27,    28,    42,    69,    43,    54,    57,    -3,    68,
      59,    71,    75,    76,    72,    82,    70,    74,    85,   -40,
      77,    78,    79,    80,    -3,    92,    29,    30,    31,    84,
      90,    -3,    24,    89,    25,    26,    27,    28,    95,    96,
       1,     2,    91,    98,    99,   105,   107,     3,     4,   101,
     104,     5,     6,     7,     8,   114,   110,   106,     1,     2,
       0,     0,   113,     0,   109,     3,     4,     0,     0,     5,
       6,     7,     8,     0,    44,    45,    46,    47,    48,    49,
      50,    51,    52
};

static const yytype_int8 yycheck[] =
{
      40,    35,    12,    37,     9,    34,     0,     3,     0,     5,
       6,     7,     8,     3,    54,     3,    13,    31,    12,    53,
      29,    29,     9,    27,    31,    35,    55,    61,    31,    13,
      64,    65,    66,    67,    28,     3,    32,    33,    34,    73,
      31,    35,     3,    83,     5,     6,     7,     8,    13,    35,
       3,     4,    86,    28,    30,    29,    35,    10,    11,    31,
     100,    14,    15,    16,    17,    28,   108,   103,     3,     4,
      -1,    -1,   112,    -1,    27,    10,    11,    -1,    -1,    14,
      15,    16,    17,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    10,    11,    14,    15,    16,    17,    37,
      38,    40,    42,    45,    50,    59,    60,    63,    66,    68,
      75,    43,    46,    51,     3,     5,     6,     7,     8,    32,
      33,    34,    41,    70,    79,    64,    67,    69,    76,     0,
      39,     9,     3,     3,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    78,    13,    41,    70,    31,    70,    29,
      38,    44,    47,    52,    71,    72,    73,    74,    70,    38,
      41,    29,    31,    77,    70,     9,    27,    70,    70,    70,
      70,    12,    35,    65,    70,    31,    48,    53,    61,    38,
      31,    70,     3,    56,    58,    13,    35,    49,    28,    30,
      62,    31,    54,    57,    38,    29,    56,    35,    55,    27,
      40,    80,    81,    38,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    39,    38,    40,    40,    40,    40,
      41,    41,    41,    41,    41,    43,    44,    42,    46,    47,
      48,    49,    45,    51,    52,    53,    54,    55,    50,    56,
      57,    56,    58,    59,    59,    59,    59,    59,    60,    60,
      61,    62,    60,    64,    65,    63,    67,    66,    69,    68,
      70,    71,    70,    72,    70,    73,    70,    74,    70,    70,
      70,    76,    77,    75,    78,    78,    78,    78,    78,    79,
      79,    79,    81,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     0,     6,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,    12,     1,
       0,     4,     1,     1,     1,     1,     1,     1,     5,     5,
       0,     0,    10,     0,     0,     7,     0,     3,     0,     4,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       3,     0,     0,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1
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
  case 2: /* programa: declaracoes  */
#line 95 "parser.y"
                {
        (yyval.thisProd).nd = mknode(NULL,temp, "[PROGRAMA]"); head=(yyval.thisProd).nd; 
        //printf("\n%s\n", $1.name);
    }
#line 1408 "y.tab.c"
    break;

  case 3: /* declaracoes: declaracao  */
#line 102 "parser.y"
               {
        temp = mknode(temp, NULL, "[DECLARACAO]");
    }
#line 1416 "y.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 105 "parser.y"
                 {}
#line 1422 "y.tab.c"
    break;

  case 5: /* declaracoes: declaracao $@1 declaracoes  */
#line 105 "parser.y"
                                {temp = mknode(temp, (yyvsp[-2].thisProd).nd, "[DECLARACOES]");}
#line 1428 "y.tab.c"
    break;

  case 6: /* declaracao: declaracao_variavel  */
#line 109 "parser.y"
                        {temp = mknode(temp, mknode(NULL, NULL, content), "[DECLARACAO VARIAVEL]");}
#line 1434 "y.tab.c"
    break;

  case 7: /* declaracao: declaracao_funcao  */
#line 110 "parser.y"
                        {temp = mknode(temp, NULL, "[DECLARACAO FUNCAO]");}
#line 1440 "y.tab.c"
    break;

  case 8: /* declaracao: declaracao_estrutura  */
#line 111 "parser.y"
                           {temp = mknode(temp, NULL, "[DECLARACAO ESTRUTURA]");}
#line 1446 "y.tab.c"
    break;

  case 9: /* declaracao: redefinicao_variavel  */
#line 112 "parser.y"
                               {temp = mknode(temp, mknode(NULL, NULL, content), "[REDEF VARIAVEL]");}
#line 1452 "y.tab.c"
    break;

  case 10: /* termo: IDENTIFICADOR  */
#line 116 "parser.y"
                  {
            // se variavel investigada nao estiver na tabela de simbolos
            if (!get_variable_content((yyvsp[0].thisProd).name)){
                semantic_error = 1;
                printf("\n\e[0;31mERRO DE SEMANTICA proximo a linha %i: VARIAVEL NAO DECLARADA \"%s\" \e[0m\n", lc, (yyvsp[0].thisProd).name);

            } else {
                (yyvsp[0].thisProd).nd = mknode(NULL, NULL, (yyvsp[0].thisProd).name);
            }
        }
#line 1467 "y.tab.c"
    break;

  case 11: /* termo: NUMERO  */
#line 126 "parser.y"
             {insert_content();  (yyvsp[0].thisProd).nd = mknode(NULL, NULL, "[INT]");}
#line 1473 "y.tab.c"
    break;

  case 12: /* termo: STRING  */
#line 127 "parser.y"
             {insert_content();  (yyvsp[0].thisProd).nd = mknode(NULL, NULL, "[STRING]");}
#line 1479 "y.tab.c"
    break;

  case 13: /* termo: BOOL  */
#line 128 "parser.y"
           {insert_content();  (yyvsp[0].thisProd).nd = mknode(NULL, NULL, "[BOOL]");}
#line 1485 "y.tab.c"
    break;

  case 14: /* termo: CHAR  */
#line 129 "parser.y"
           {insert_content();  (yyvsp[0].thisProd).nd = mknode(NULL, NULL, "[CHAR]");}
#line 1491 "y.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 133 "parser.y"
                     {strcpy(name, (yyvsp[0].thisProd).name);}
#line 1497 "y.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 133 "parser.y"
                                                     {add('K');}
#line 1503 "y.tab.c"
    break;

  case 17: /* redefinicao_variavel: IDENTIFICADOR $@2 VAI_SER $@3 expressao DOT  */
#line 133 "parser.y"
                                                                              {add('K');}
#line 1509 "y.tab.c"
    break;

  case 18: /* $@4: %empty  */
#line 137 "parser.y"
         {insert_type(); add('K');}
#line 1515 "y.tab.c"
    break;

  case 19: /* $@5: %empty  */
#line 137 "parser.y"
                                                  {
            strcpy(name, (yyvsp[0].thisProd).name);
            (yyvsp[0].thisProd).nd = mknode(NULL, NULL, (yyvsp[0].thisProd).name);
            temp = (yyvsp[0].thisProd).nd;}
#line 1524 "y.tab.c"
    break;

  case 20: /* $@6: %empty  */
#line 141 "parser.y"
                   {add('K');
            
        }
#line 1532 "y.tab.c"
    break;

  case 21: /* $@7: %empty  */
#line 143 "parser.y"
                    {
            int res = contains_letter_not_comma(content);
            if (!strcmp(type,"trem inteiro")){
                if (res){
                    semantic_error = 1;
                    printf("\n\e[0;31mErro proximo da linha %i: TIPO INCOMPATÍVEL [%s] [%s].\n\n\e[0m", lc, type, content);}
                }
            add('V');
            }
#line 1546 "y.tab.c"
    break;

  case 22: /* declaracao_variavel: TIPO $@4 IDENTIFICADOR $@5 VAI_SER $@6 expressao $@7 DOT  */
#line 151 "parser.y"
                 {add('K');}
#line 1552 "y.tab.c"
    break;

  case 23: /* $@8: %empty  */
#line 155 "parser.y"
                 {add('K');}
#line 1558 "y.tab.c"
    break;

  case 24: /* $@9: %empty  */
#line 155 "parser.y"
                                          {strcpy(name, (yyvsp[0].thisProd).name);}
#line 1564 "y.tab.c"
    break;

  case 25: /* $@10: %empty  */
#line 155 "parser.y"
                                                                         {add('K');}
#line 1570 "y.tab.c"
    break;

  case 26: /* $@11: %empty  */
#line 155 "parser.y"
                                                                                                      {add('K');}
#line 1576 "y.tab.c"
    break;

  case 27: /* $@12: %empty  */
#line 155 "parser.y"
                                                                                                                        {add('K');}
#line 1582 "y.tab.c"
    break;

  case 30: /* $@13: %empty  */
#line 160 "parser.y"
                     {add('K');}
#line 1588 "y.tab.c"
    break;

  case 32: /* parametro: IDENTIFICADOR  */
#line 164 "parser.y"
                 {strcpy(name, (yyvsp[0].thisProd).name); add('V');}
#line 1594 "y.tab.c"
    break;

  case 33: /* declaracao_estrutura: if  */
#line 168 "parser.y"
       {temp = mknode(temp, NULL, "[DECLARACAO IF]");}
#line 1600 "y.tab.c"
    break;

  case 34: /* declaracao_estrutura: while  */
#line 169 "parser.y"
            {temp = mknode(temp, NULL, "[DECLARACAO WHILE]");}
#line 1606 "y.tab.c"
    break;

  case 35: /* declaracao_estrutura: break  */
#line 171 "parser.y"
            {temp = mknode(temp, NULL, "[DECLARACAO BREAK]");}
#line 1612 "y.tab.c"
    break;

  case 36: /* declaracao_estrutura: print  */
#line 172 "parser.y"
            {temp = mknode(temp, NULL, "[DECLARACAO PRINT]");}
#line 1618 "y.tab.c"
    break;

  case 37: /* declaracao_estrutura: return  */
#line 173 "parser.y"
             {temp = mknode(temp, NULL, "[DECLARACAO RETURN]");}
#line 1624 "y.tab.c"
    break;

  case 38: /* if: FRAGA expressao INTERROGACAO declaracoes END_COMMAND  */
#line 177 "parser.y"
                                                         {add('K');}
#line 1630 "y.tab.c"
    break;

  case 39: /* if: FRAGA expressao INTERROGACAO declaracoes NAO  */
#line 178 "parser.y"
                                                      {add('K');}
#line 1636 "y.tab.c"
    break;

  case 40: /* $@14: %empty  */
#line 179 "parser.y"
                                                      {add('K');}
#line 1642 "y.tab.c"
    break;

  case 41: /* $@15: %empty  */
#line 179 "parser.y"
                                                                              {add('K');}
#line 1648 "y.tab.c"
    break;

  case 42: /* if: FRAGA expressao INTERROGACAO declaracoes NAO $@14 INTERROGACAO $@15 declaracoes END_COMMAND  */
#line 179 "parser.y"
                                                                                                                 {add('K');}
#line 1654 "y.tab.c"
    break;

  case 43: /* $@16: %empty  */
#line 183 "parser.y"
                    {add('K');}
#line 1660 "y.tab.c"
    break;

  case 44: /* $@17: %empty  */
#line 183 "parser.y"
                                                {add('K');}
#line 1666 "y.tab.c"
    break;

  case 45: /* while: VAI_FAZENDO_ATE $@16 expressao COLLON $@17 declaracoes END_COMMAND  */
#line 183 "parser.y"
                                                                                    {add('K');}
#line 1672 "y.tab.c"
    break;

  case 46: /* $@18: %empty  */
#line 196 "parser.y"
             {add('K');}
#line 1678 "y.tab.c"
    break;

  case 47: /* break: PICA_MULA $@18 DOT  */
#line 196 "parser.y"
                            {add('K');}
#line 1684 "y.tab.c"
    break;

  case 48: /* $@19: %empty  */
#line 200 "parser.y"
          {add('K');}
#line 1690 "y.tab.c"
    break;

  case 49: /* return: ARREDA $@19 expressao DOT  */
#line 200 "parser.y"
                                   {add('K');}
#line 1696 "y.tab.c"
    break;

  case 51: /* $@20: %empty  */
#line 205 "parser.y"
                       {add('K');}
#line 1702 "y.tab.c"
    break;

  case 52: /* expressao: termo AI_CE_JUNTA $@20 expressao  */
#line 205 "parser.y"
                                             {get_operation("AI_CE_JUNTA");}
#line 1708 "y.tab.c"
    break;

  case 53: /* $@21: %empty  */
#line 206 "parser.y"
                         {add('K');}
#line 1714 "y.tab.c"
    break;

  case 54: /* expressao: termo AI_CE_DIMINUI $@21 expressao  */
#line 206 "parser.y"
                                               {get_operation("AI_CE_DIMINUI");}
#line 1720 "y.tab.c"
    break;

  case 55: /* $@22: %empty  */
#line 207 "parser.y"
                             {add('K');}
#line 1726 "y.tab.c"
    break;

  case 56: /* expressao: termo CE_MULTIPLICA_POR $@22 expressao  */
#line 207 "parser.y"
                                                   {get_operation("CE_MULTIPLICA_POR");}
#line 1732 "y.tab.c"
    break;

  case 57: /* $@23: %empty  */
#line 208 "parser.y"
                         {add('K');}
#line 1738 "y.tab.c"
    break;

  case 58: /* expressao: termo CE_DIVIDE_POR $@23 expressao  */
#line 208 "parser.y"
                                               {get_operation("CE_DIVIDE_POR");}
#line 1744 "y.tab.c"
    break;

  case 61: /* $@24: %empty  */
#line 214 "parser.y"
         {add('K');}
#line 1750 "y.tab.c"
    break;

  case 62: /* $@25: %empty  */
#line 214 "parser.y"
                           {add('K');}
#line 1756 "y.tab.c"
    break;

  case 63: /* print: ANOTA $@24 COLLON $@25 expressao DOT  */
#line 214 "parser.y"
                                                    {add('K');}
#line 1762 "y.tab.c"
    break;

  case 64: /* operador: ELEVADO_A  */
#line 218 "parser.y"
                 {add('K');}
#line 1768 "y.tab.c"
    break;

  case 65: /* operador: ENGUAL  */
#line 219 "parser.y"
            {add('K');}
#line 1774 "y.tab.c"
    break;

  case 66: /* operador: NADA_A_VER_COM  */
#line 220 "parser.y"
                    {add('K');}
#line 1780 "y.tab.c"
    break;

  case 67: /* operador: MAIOR_QUE  */
#line 221 "parser.y"
               {add('K');}
#line 1786 "y.tab.c"
    break;

  case 68: /* operador: MENOR_QUE  */
#line 222 "parser.y"
               {add('K');}
#line 1792 "y.tab.c"
    break;

  case 69: /* operadores_pos: OR_OP  */
#line 225 "parser.y"
               {add('K');}
#line 1798 "y.tab.c"
    break;

  case 70: /* operadores_pos: AND_OP  */
#line 226 "parser.y"
             {add('K');}
#line 1804 "y.tab.c"
    break;

  case 71: /* operadores_pos: NOT_OP  */
#line 227 "parser.y"
            {add('K');}
#line 1810 "y.tab.c"
    break;

  case 72: /* $@26: %empty  */
#line 232 "parser.y"
              {add('K');}
#line 1816 "y.tab.c"
    break;

  case 73: /* bloco: LBRACE $@26 declaracoes RBRACE  */
#line 232 "parser.y"
                                            {add('K');}
#line 1822 "y.tab.c"
    break;


#line 1826 "y.tab.c"

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

#line 237 "parser.y"


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

    printtree(head); 

    if (!syntax_error)
        printf("\n\n\e[0;32m Programa Sintaticamente Correto.");
    else{
        printf("\n\n\e[0;31m Programa Sintaticamente Incorreto.");
        return 0;
    }
    if (!semantic_error)
        printf("\n\e[0;32m Programa Semanticamente Correto.");
    else
        printf("\n\e[0;31m Programa Semanticamente Incorreto.");
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
  if (c == 'V') {
      symbol_table[count].id_name = strdup(name);
      symbol_table[count].data_type = strdup(type);
      symbol_table[count].content = strdup(content);
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Variable");
      count++;
  }

  if (!q) {
    if (c == 'K') {
      symbol_table[count].id_name = strdup(yytext);
      symbol_table[count].data_type = strdup("N/A");
      symbol_table[count].content = strdup("N/A");
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Keyword");
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

void change_variable_content(const char* variable_name, char * newval) {
    for (int i = 0; i < count; i++) {
        //printf("%s\n",symbol_table[i].id_name);
        if (strcmp(symbol_table[i].type, "Variable") == 0 && strcmp(symbol_table[i].id_name, variable_name) == 0) {
            symbol_table[i].content = newval;
        }
    }
}

void insert_content() {
  //printf("\nXaleibs: %s\n", yytext);
  strcpy(last_content, content);
  strcpy(content, yytext);
}

void insert_type() {
    strcpy(type, yytext);
}

void insert_type_manual(char * string){
  strcpy(type, string);
}

void insert_varname_manual(char * string){
    if (string){
            strcpy(current_var, string);
    }
    else {
        // SO ACONTECE CASO VARIAVEL NAO TENHA SIDO DECLARADA
        semantic_error = 1;
        printf("\n\e[0;31mErro proximo da linha %i: VARIAVEL NAO DECLARADA[ %s].\n\n\e[0m", lc, current_var);
    }
}

void yyerror(const char* msg) {
    syntax_error = 1;
  fprintf(stderr, "\n\e[0;31mErro proximo da linha %i: %s.\n\n\e[0m", lc, msg);
}

void get_operation(char *operator){
    if (contains_letter_not_comma(last_content) || contains_letter_not_comma(content)){
            printf("\n\e[0;31mERRO DE SEMANTICA proximo a linha %i: tipos incompatíveis para operação \"%s\" [%s] [%s]\e[0m\n", lc, operator, content, last_content);
            semantic_error = 1;
            return;
    }
    replaceChar(last_content, ',', '.');
    replaceChar(content, ',', '.');
    double final = 0;

    if (operator == "AI_CE_JUNTA"){
        // conta = atof(last_int) + atof(content)
        final = atof(last_content) + atof(content);
    }
    else if (operator == "AI_CE_DIMINUI"){
        final = atof(last_content) - atof(content);
    }
    else if (operator == "CE_MULTIPLICA_POR"){
        final = atof(last_content) * atof(content);
    }
    else if (operator == "CE_DIVIDE_POR"){
        final = atof(last_content) / atof(content);
    }

    sprintf(operacao, "%f", final);
    replaceChar(operacao, '.', ',');

    strcpy(content, operacao);
}

void replaceChar(char *str, char oldChar, char newChar) {
    while (*str != '\0') {  // Percorre a string até o terminador nulo
        if (*str == oldChar) {
            *str = newChar;  // Substitui o caractere
        }
        str++;  // Avança para o próximo caractere
    }
}

int contains_letter(const char *str) {
    while (*str != '\0') {  // Loop through each character in the string
        if (isalpha((unsigned char)*str) || *str == ',') {  // Check if the character is a letter
            return 1;  // Return 1 if a letter is found
        }
        str++;
    }
    return 0;  // Return 0 if no letters were found (i.e., all characters are numbers)
}

int contains_letter_not_comma(const char *str) {
    while (*str != '\0') {  // Loop through each character in the string
        if (isalpha((unsigned char)*str)) {  // Check if the character is a letter
            return 1;  // Return 1 if a letter is found
        }
        str++;
    }
    return 0;  // Return 0 if no letters were found (i.e., all characters are numbers)
}

void printtree(struct node* tree) {
	printf("\n\n Arvore Sintatica: Impressa em ordem: \n\n");
	draw_tree_hor(tree);   
	printf("\n\n");
}

void draw_tree_hor2(struct node *tree, int depth, char *path, int right)
{
    // stopping condition
    if (tree== NULL)
        return;

    // increase spacing
    depth++;

    // start with right node
    draw_tree_hor2(tree->right, depth, path, 1);

    if(depth > 1)
    {
        // set | draw map
        path[depth-2] = 0;

        if(right)
            path[depth-2] = 1;
    }

    if(tree->left)
        path[depth-1] = 1;

    // print root after spacing
    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      	if(i == depth-2)
        	printf("+");
     	else if(path[i])
        	printf("|");
      	else
        	printf(" ");

      	for(int j=1; j < 3; j++)
      	if(i < depth-2)
        	printf(" ");
      	else
        	printf("-");
    }

	switch(tree->token[0]){
		case '-':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			printf("> %s\n",tree->token);
			break;
		default:
			printf("%s\n", tree->token);
			break;
	}
    // vertical spacers below
    for(int i=0; i<depth; i++)
    {
      	if(path[i])
        	printf("|");
      	else
          	printf(" ");

      	for(int j=1; j < 3; j++)
          	printf(" ");
    }

    // go to left node
    draw_tree_hor2(tree->left, depth, path, 0);
}

void draw_tree_hor(struct node *tree)
{
    // should check if we don't exceed this somehow..
    char path[255] = {};

    //initial depth is 0
    draw_tree_hor2(tree, 0, path, 0);
}

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}
