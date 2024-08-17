/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    VOID_TYPE = 258,               /* VOID_TYPE  */
    BOOL_TYPE = 259,               /* BOOL_TYPE  */
    STRING_TYPE = 260,             /* STRING_TYPE  */
    INT_TYPE = 261,                /* INT_TYPE  */
    FLOAT_TYPE = 262,              /* FLOAT_TYPE  */
    TIPO = 263,                    /* TIPO  */
    BOOL = 264,                    /* BOOL  */
    STRING = 265,                  /* STRING  */
    NUMERO = 266,                  /* NUMERO  */
    IDENTIFICADOR = 267,           /* IDENTIFICADOR  */
    FRAGA = 268,                   /* FRAGA  */
    NAO = 269,                     /* NAO  */
    VAI_FAZENDO_ATE = 270,         /* VAI_FAZENDO_ATE  */
    PRA = 271,                     /* PRA  */
    ARREDA = 272,                  /* ARREDA  */
    PICA_MULA = 273,               /* PICA_MULA  */
    VAI_SER = 274,                 /* VAI_SER  */
    AI_CE_JUNTA = 275,             /* AI_CE_JUNTA  */
    AI_CE_DIMINUI = 276,           /* AI_CE_DIMINUI  */
    CE_MULTIPLICA_POR = 277,       /* CE_MULTIPLICA_POR  */
    CE_DIVIDE_POR = 278,           /* CE_DIVIDE_POR  */
    OR_OP = 279,                   /* OR_OP  */
    AND_OP = 280,                  /* AND_OP  */
    NOT_OP = 281,                  /* NOT_OP  */
    ENGUAL = 282,                  /* ENGUAL  */
    NADA_A_VER_COM = 283,          /* NADA_A_VER_COM  */
    MAIOR_QUE = 284,               /* MAIOR_QUE  */
    MENOR_QUE = 285,               /* MENOR_QUE  */
    NAQUELE_NAIPE = 286,           /* NAQUELE_NAIPE  */
    ANOTA = 287,                   /* ANOTA  */
    END_COMMAND = 288,             /* END_COMMAND  */
    DOT = 289,                     /* DOT  */
    INTERROGACAO = 290,            /* INTERROGACAO  */
    LBRACE = 291,                  /* LBRACE  */
    RBRACE = 292,                  /* RBRACE  */
    COMMA = 293,                   /* COMMA  */
    UNDERSCORE = 294,              /* UNDERSCORE  */
    COLLON = 295                   /* COLLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VOID_TYPE 258
#define BOOL_TYPE 259
#define STRING_TYPE 260
#define INT_TYPE 261
#define FLOAT_TYPE 262
#define TIPO 263
#define BOOL 264
#define STRING 265
#define NUMERO 266
#define IDENTIFICADOR 267
#define FRAGA 268
#define NAO 269
#define VAI_FAZENDO_ATE 270
#define PRA 271
#define ARREDA 272
#define PICA_MULA 273
#define VAI_SER 274
#define AI_CE_JUNTA 275
#define AI_CE_DIMINUI 276
#define CE_MULTIPLICA_POR 277
#define CE_DIVIDE_POR 278
#define OR_OP 279
#define AND_OP 280
#define NOT_OP 281
#define ENGUAL 282
#define NADA_A_VER_COM 283
#define MAIOR_QUE 284
#define MENOR_QUE 285
#define NAQUELE_NAIPE 286
#define ANOTA 287
#define END_COMMAND 288
#define DOT 289
#define INTERROGACAO 290
#define LBRACE 291
#define RBRACE 292
#define COMMA 293
#define UNDERSCORE 294
#define COLLON 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "parser.y"

    char *str;
    int num;

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
