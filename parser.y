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

%token VOID_TYPE BOOL_TYPE STRING_TYPE INT_TYPE FLOAT_TYPE
%token TIPO BOOL STRING NUMERO IDENTIFICADOR
%token FRAGA NAO VAI_FAZENDO_ATE PRA ARREDA PICA_MULA VAI_SER
%token AI_CE_JUNTA AI_CE_DIMINUI CE_MULTIPLICA_POR CE_DIVIDE_POR
%token OR_OP AND_OP NOT_OP ENGUAL NADA_A_VER_COM MAIOR_QUE MENOR_QUE
%token NAQUELE_NAIPE ANOTA END_COMMAND
%token DOT INTERROGACAO LBRACE RBRACE COMMA UNDERSCORE COLLON NUMERO

%union {
    char *str;
    int num;
}
%token <str> NUMERO


%%

program: main_body END_COMMAND
;

main_body: headers main_func body ARREDA NUMERO ';'
;

headers: headers NAQUELE_NAIPE { add('H'); }
| /* Vazio */
;

main_func: TIPO IDENTIFICADOR { add('F'); }
;

body: body statement
| /* Vazio */
;

statement: VAI_SER expression ';'
| IDENTIFICADOR '=' expression ';' { add('V'); }
| PRINT_CMD
| flow_control
;

expression: IDENTIFICADOR AI_CE_JUNTA IDENTIFICADOR { add('E'); }
| IDENTIFICADOR CE_MULTIPLICA_POR IDENTIFICADOR { add('E'); }
| NUMERO { add('C'); }
| STRING { add('C'); }
| BOOL { add('C'); }
;

PRINT_CMD: ANOTA '(' STRING ')' ';' { add('P'); }
;

flow_control: FRAGA '(' condition ')' '{' body '}' NAO { add('K'); }
| VAI_FAZENDO_ATE '(' condition ')' '{' body '}' { add('K'); }
;

condition: IDENTIFICADOR ENGUAL IDENTIFICADOR
| IDENTIFICADOR MAIOR_QUE IDENTIFICADOR
| BOOL
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
