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
%token ENGUAL NADA_A_VER_COM MAIOR_QUE MENOR_QUE ELEVADO_A
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
	| redefinicao_variavel
    ;

redefinicao_variavel:
	IDENTIFICADOR{add('V');} VAI_SER{add('K');} expressao DOT{add('K');};

declaracao_variavel:
    TIPO{add('K');} IDENTIFICADOR{add('V');} VAI_SER{add('K');} expressao DOT{add('K');}
    ;

declaracao_funcao:
    NAQUELE_NAIPE{add('K');} IDENTIFICADOR{add('F');} LBRACE{add('K');} parametros RBRACE{add('K');} COLLON{add('K');} bloco 
    ;

parametros:
    parametro
    | parametro COMMA{add('K');} parametros
    ;

parametro:
    IDENTIFICADOR {add('V');}
    ;

declaracao_estrutura:
    if
    | while
//    | for
    | break
    | print
    | return
    ;

// @FIXME: SE ADD {add('K');} NO FRAGA OU EM ALGUM TERMINAL AQUI, DÁ ERRO DE SHIFT-REDUCE
if:
    FRAGA expressao INTERROGACAO declaracoes END_COMMAND
	| FRAGA expressao INTERROGACAO declaracoes NAO if
	| FRAGA expressao INTERROGACAO declaracoes NAO INTERROGACAO declaracoes END_COMMAND
    ;

while:
    VAI_FAZENDO_ATE{add('K');} expressao COLLON{add('K');} declaracoes END_COMMAND{add('K');}
    ;

//for:
    //PRA LBRACE declaracao_variavel DOT 
			//expressao DOT 
			//expressao RBRACE COLLON 
			//declaracoes 
			//END_COMMAND
   // ;


break:
    PICA_MULA{add('K');} DOT{add('K');}
    ;

return:
    ARREDA{add('K');} expressao
    ;

expressao:
    termo
    | termo operador expressao
	| operadores_pos termo termo
    ;

print:
    ANOTA{add('K');} COLLON{add('K');} expressao DOT{add('K');}
    ;

termo:
    IDENTIFICADOR // { insert_type(); }
    | NUMERO{ insert_type(); }
    | STRING{ insert_type(); }
    | BOOL{ insert_type(); }
    | CHAR{ insert_type(); }
    ;

operador:
    AI_CE_JUNTA{add('K');}
    | AI_CE_DIMINUI{add('K');}
    | CE_MULTIPLICA_POR{add('K');}
    | CE_DIVIDE_POR{add('K');}
	| ELEVADO_A{add('K');}
    | ENGUAL{add('K');}
    | NADA_A_VER_COM{add('K');}
    | MAIOR_QUE{add('K');}
    | MENOR_QUE{add('K');}
	
operadores_pos:
	 OR_OP {add('K');}
    | AND_OP {add('K');}
    | NOT_OP {add('K');}
    ;

bloco:
    // declaracoes
	LBRACE{add('K');} declaracoes RBRACE{add('K');}
	// | INTERROGACAO declaracoes END_COMMAND
    | declaracao
    ;

%%

int main() {
  yyparse();
printf("\n\n");
printf("\t\t Análise Léxica \n\n");
printf("\n%-20s %-15s %-15s %-10s\n", "[SÍMBOLO]", "[TIPO DE DADO]", "[TIPO TOKEN]", "[LINHA]");
printf("__________________________________________________________\n\n");

for (int i = 0; i < count; i++) {
    printf("%-20s %-15s %-15s %-10d\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
}

for (int i = 0; i < count; i++) {
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
    if (c == 'K') {
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
  // printf("\nXaleibs: %s\n", yytext);
  strcpy(type, yytext);
}

void insert_type_manual(char * string){
  strcpy(type, string);
}

void yyerror(const char* msg) {
  fprintf(stderr, "Identificado um erro na linha %i: %s. \nO último token identificado não era o esperado.\n", lc, msg);
}
