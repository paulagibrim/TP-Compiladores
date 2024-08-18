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
    LPAREN = 282,                  /* LPAREN  */
    RPAREN = 283,                  /* RPAREN  */
    LBRACE = 284,                  /* LBRACE  */
    RBRACE = 285,                  /* RBRACE  */
    COLLON = 286,                  /* COLLON  */
    COMMA = 287,                   /* COMMA  */
    DOT = 288,                     /* DOT  */
    UNDERSCORE = 289,              /* UNDERSCORE  */
    OR_OP = 290,                   /* OR_OP  */
    AND_OP = 291,                  /* AND_OP  */
    NOT_OP = 292,                  /* NOT_OP  */
    END_COMMAND = 293              /* END_COMMAND  */
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
#define LPAREN 282
#define RPAREN 283
#define LBRACE 284
#define RBRACE 285
#define COLLON 286
#define COMMA 287
#define DOT 288
#define UNDERSCORE 289
#define OR_OP 290
#define AND_OP 291
#define NOT_OP 292
#define END_COMMAND 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "parser.y"

    char *str;
    int num;

#line 148 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
