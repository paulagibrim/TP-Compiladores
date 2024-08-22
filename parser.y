%{
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
%}

%token <str> IDENTIFICADOR TIPO
%token NUMERO 
%token STRING BOOL CHAR 
%token VAI_SER
%token NAQUELE_NAIPE 
%token <str> FRAGA NAO INTERROGACAO VAI_FAZENDO_ATE PRA PICA_MULA ARREDA
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
	IDENTIFICADOR{strcpy(name, $1);} VAI_SER{add('K');} expressao {add('V');} DOT
    ;

declaracao_variavel:
    TIPO {insert_type();add('K');} IDENTIFICADOR {strcpy(name, $3);} VAI_SER{add('K');} expressao{add('V'); } DOT
    ;

declaracao_funcao:
    NAQUELE_NAIPE{add('K');} IDENTIFICADOR{strcpy(name, $3);} LBRACE parametros RBRACE COLLON bloco
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
    FRAGA expressao INTERROGACAO declaracoes END_COMMAND{add('K');}
	| FRAGA expressao INTERROGACAO declaracoes NAO{add('K');} if
	| FRAGA expressao INTERROGACAO declaracoes NAO{add('K');} INTERROGACAO{add('K');} declaracoes END_COMMAND{add('K');}
    ;

while:
    VAI_FAZENDO_ATE {add('K');} expressao COLLON{add('K');} declaracoes END_COMMAND {add('K');}
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
    ARREDA{add('K');} expressao DOT{add('K');}
    ;

expressao:
    termo
    | termo AI_CE_JUNTA{add('K');} expressao {get_operation("AI_CE_JUNTA");}
    | termo AI_CE_DIMINUI{add('K');} expressao {get_operation("AI_CE_DIMINUI");}
    | termo CE_MULTIPLICA_POR{add('K');} expressao {get_operation("CE_MULTIPLICA_POR");}
    | termo CE_DIVIDE_POR{add('K');} expressao {get_operation("CE_DIVIDE_POR");}
	| operadores_pos termo termo
    | termo operador expressao
    ;

print:
    ANOTA{add('K');} COLLON{add('K');} expressao DOT{add('K');}
    ;

operador:
	ELEVADO_A{add('K');}
    | ENGUAL{add('K');}
    | NADA_A_VER_COM{add('K');}
    | MAIOR_QUE{add('K');}
    | MENOR_QUE{add('K');}
	
operadores_pos:
	 OR_OP {add('K');}
    | AND_OP {add('K');}
    | NOT_OP{add('K');}
    ;

bloco:
    // declaracoes
	LBRACE{add('K');} declaracoes RBRACE{add('K');}
	// | INTERROGACAO declaracoes END_COMMAND
    | declaracao
    ;

%%

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
