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
    void insert_content();
    int search(char *);

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
%}

%token <str> IDENTIFICADOR TIPO
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

termo:
    IDENTIFICADOR
    | NUMERO {insert_content();}
    | STRING {insert_content();}
    | BOOL {insert_content();}
    | CHAR {insert_content();}
    ;

redefinicao_variavel:
	IDENTIFICADOR{strcpy(name, $1);} VAI_SER{add('K');} expressao {add('V');} DOT;

declaracao_variavel:
    TIPO{insert_type(type, $1);} IDENTIFICADOR {strcpy(name, $3);} VAI_SER{add('K');} expressao{add('V'); } DOT
    ;

declaracao_funcao:
    NAQUELE_NAIPE IDENTIFICADOR LBRACE parametros RBRACE COLLON bloco
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
//    | for
    | break
    | print
    | return
    ;

if:
    FRAGA expressao INTERROGACAO declaracoes END_COMMAND
	| FRAGA expressao INTERROGACAO declaracoes NAO if
	| FRAGA expressao INTERROGACAO declaracoes NAO INTERROGACAO declaracoes END_COMMAND
    ;

while:
    VAI_FAZENDO_ATE expressao COLLON declaracoes END_COMMAND
    ;

//for:
    //PRA LBRACE declaracao_variavel DOT 
			//expressao DOT 
			//expressao RBRACE COLLON 
			//declaracoes 
			//END_COMMAND
   // ;


break:
    PICA_MULA DOT
    ;

return:
    ARREDA expressao
    ;

expressao:
    termo
    | termo AI_CE_JUNTA expressao //{$$ = $1 + $2}
    | termo AI_CE_DIMINUI expressao //{$$ = $1 - $2}
    | termo CE_MULTIPLICA_POR expressao //{$$ = $1 * $2}
    | termo CE_DIVIDE_POR expressao //{$$ = $1 / $2}
	| operadores_pos termo termo
    | termo operador expressao
    ;

print:
    ANOTA COLLON expressao DOT
    ;

operador:
	ELEVADO_A
    | ENGUAL
    | NADA_A_VER_COM
    | MAIOR_QUE
    | MENOR_QUE
	
operadores_pos:
	 OR_OP 
    | AND_OP 
    | NOT_OP
    ;

bloco:
    // declaracoes
	LBRACE declaracoes RBRACE
	// | INTERROGACAO declaracoes END_COMMAND
    | declaracao
    ;

%%

int main() {
  yyparse();
printf("\n\n");
printf("\t\t\t\t\t\t\t\t Análise Léxica \n\n");
printf("\n%-20s %-15s %-15s %-15s %-10s\n", "[SÍMBOLO]", "[TIPO DE DADO]", "[TIPO TOKEN]", "[CONTEÚDO]", "[LINHA]");
printf("________________________________________________________________________________\n\n");

for (int i = 0; i < count; i++) {
    printf("%-20s %-15s %-15s %-15s %-10d\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].content, symbol_table[i].line_no);
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

void insert_content() {
  //printf("\nXaleibs: %s\n", yytext);
  strcpy(content, yytext);
}

void insert_type() {
    strcpy(type, yytext);
}

void insert_type_manual(char * string){
  strcpy(type, string);
}

void yyerror(const char* msg) {
  fprintf(stderr, "Identificado um erro na linha %i: %s. \nO último token identificado não era o esperado.\n", lc, msg);
}