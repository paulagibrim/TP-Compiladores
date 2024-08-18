%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    //int yywrap();
    void add(char c);
    void insert_type();
    int search(char *);
    void insert_type();

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
    } symbol_table[40];

    int count = 0;
    int q;
    char type[10];
    extern int lc;  // Linha do lexer
%}

%token IDENTIFICADOR TIPO
%token NUMERO 
%token STRING BOOL CHAR 
%token VAI_SER
%token NAQUELE_NAIPE 
%token FRAGA NAO INTERROGACAO VAI_FAZENDO_ATE PRA PICA_MULA ARREDA
%token ANOTA
%token AI_CE_JUNTA AI_CE_DIMINUI CE_MULTIPLICA_POR CE_DIVIDE_POR
%token ENGUAL NADA_A_VER_COM MAIOR_QUE MENOR_QUE
%token LBRACE RBRACE COLLON COMMA DOT
%token UNDERSCORE OR_OP AND_OP NOT_OP 
%token END_COMMAND

%left AI_CE_JUNTA AI_CE_DIMINUI
%left CE_MULTIPLICA_POR CE_DIVIDE_POR
%nonassoc ENGUAL NADA_A_VER_COM
%nonassoc MAIOR_QUE MENOR_QUE

%union {
    char *str;
    int num;
}

%%

programa:
    declaracoes
    ;

declaracoes:
    declaracao
    | declaracao declaracoes
    ;

declaracao:
    declaracao_variavel
    | declaracao_funcao
    | declaracao_estrutura
    ;

declaracao_variavel:
    TIPO{add('K');} IDENTIFICADOR{add('V');} VAI_SER{add('K');} expressao DOT{add('K');}
    ;

declaracao_funcao:
    NAQUELE_NAIPE IDENTIFICADOR LBRACE parametros RBRACE COLLON bloco {
        add('F');
    }
    ;

parametros:
    parametro
    | parametro COMMA parametros
    ;

parametro:
    IDENTIFICADOR {
        add('V');
    }
    ;

declaracao_estrutura:
    if
    | while
    | for
    | break
    | print
    | return
    ;

if:
    FRAGA expressao INTERROGACAO bloco END_COMMAND
    ;

while:
    VAI_FAZENDO_ATE expressao COLLON bloco
    ;

for:
    PRA LBRACE expressao RBRACE COLLON bloco
    ;

break:
    PICA_MULA
    ;

return:
    ARREDA expressao
    ;

expressao:
    termo
    | termo operador expressao
    ;

print:
    ANOTA COLLON expressao
    ;

termo:
    IDENTIFICADOR 
    | NUMERO
    | STRING
    | BOOL
    | CHAR
    ;

operador:
    AI_CE_JUNTA
    | AI_CE_DIMINUI
    | CE_MULTIPLICA_POR
    | CE_DIVIDE_POR
    | ENGUAL
    | NADA_A_VER_COM
    | MAIOR_QUE
    | MENOR_QUE
    | OR_OP 
    | AND_OP 
    | NOT_OP
    ;

bloco:
    LBRACE declaracoes RBRACE
    | declaracao
    ;

%%

int main() {
  yyparse();
  printf("\n\n");
  printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
  printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
  printf("_______________________________________\n\n");
  int i = 0;
  for (i = 0; i < count; i++) {
    printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
  }
  for (i = 0; i < count; i++) {
    free(symbol_table[i].id_name);
    free(symbol_table[i].type);
  }
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
    if (c == 'H') {
      symbol_table[count].id_name = strdup(yytext);
      symbol_table[count].data_type = strdup("N/A");
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Header");
      count++;
    } else if (c == 'K') {
      symbol_table[count].id_name = strdup(yytext);
      symbol_table[count].data_type = strdup("N/A");
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Keyword");
      count++;
    } else if (c == 'V') {
      symbol_table[count].id_name = strdup(yytext);
      symbol_table[count].data_type = strdup(type);
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Variable");
      count++;
    } else if (c == 'C') {
      symbol_table[count].id_name = strdup(yytext);
      symbol_table[count].data_type = strdup("CONST");
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Constant");
      count++;
    } else if (c == 'F') {
      symbol_table[count].id_name = strdup(yytext);
      symbol_table[count].data_type = strdup(type);
      symbol_table[count].line_no = lc;
      symbol_table[count].type = strdup("Function");
      count++;
    }
  }
}

void insert_type() {
  strcpy(type, yytext);
}

void yyerror(const char* msg) {
  fprintf(stderr, "%s\n", msg);
}
