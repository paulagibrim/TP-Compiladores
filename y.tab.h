#ifndef _yy_defines_h_
#define _yy_defines_h_

#define VOID_TYPE 257
#define BOOL_TYPE 258
#define STRING_TYPE 259
#define INT_TYPE 260
#define FLOAT_TYPE 261
#define TIPO 262
#define BOOL 263
#define STRING 264
#define NUMERO 265
#define IDENTIFICADOR 266
#define FRAGA 267
#define NAO 268
#define VAI_FAZENDO_ATE 269
#define PRA 270
#define ARREDA 271
#define PICA_MULA 272
#define VAI_SER 273
#define AI_CE_JUNTA 274
#define AI_CE_DIMINUI 275
#define CE_MULTIPLICA_POR 276
#define CE_DIVIDE_POR 277
#define OR_OP 278
#define AND_OP 279
#define NOT_OP 280
#define ENGUAL 281
#define NADA_A_VER_COM 282
#define MAIOR_QUE 283
#define MENOR_QUE 284
#define NAQUELE_NAIPE 285
#define ANOTA 286
#define END_COMMAND 287
#define DOT 288
#define INTERROGACAO 289
#define LBRACE 290
#define RBRACE 291
#define COMMA 292
#define UNDERSCORE 293
#define COLLON 294
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    char *str;
    int num;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
