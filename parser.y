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
    int contains_letter(const char *str);
    void insert_content_manual(char * string);
    void change_variable_content(const char* variable_name, char * newval);

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
%}

%token <thisProd> IDENTIFICADOR TIPO
%token <thisProd> NUMERO 
%token <thisProd> STRING BOOL CHAR 
%token <thisProd> VAI_SER
%token <thisProd> NAQUELE_NAIPE 
%token <thisProd> FRAGA NAO INTERROGACAO VAI_FAZENDO_ATE PRA PICA_MULA ARREDA
%token <thisProd> ANOTA
%token <thisProd> AI_CE_JUNTA AI_CE_DIMINUI CE_MULTIPLICA_POR CE_DIVIDE_POR
%token <thisProd> ENGUAL NADA_A_VER_COM MAIOR_QUE MENOR_QUE ELEVADO_A
%token <thisProd> LBRACE RBRACE COLLON COMMA DOT
%token <thisProd> UNDERSCORE OR_OP AND_OP NOT_OP 
%token <thisProd> END_COMMAND

%type <thisProd> programa declaracoes declaracao 
%type <thisProd> declaracao_variavel redefinicao_variavel declaracao_funcao declaracao_estrutura parametro parametros
%type <thisProd> if while break print return

%left AI_CE_JUNTA AI_CE_DIMINUI
%left CE_MULTIPLICA_POR CE_DIVIDE_POR
%nonassoc ENGUAL NADA_A_VER_COM
%nonassoc MAIOR_QUE MENOR_QUE

%union {
    char *str;
    int num;
    struct prod { 
		char name[100]; 
		struct node* nd;
	} thisProd; 
}

%%

programa:
    declaracoes {
        $$.nd = mknode(NULL,NULL, "[PROGRAMA]"); head=$$.nd; 
        
    }
    ;

declaracoes:
    declaracao {$$.nd = mknode(NULL, NULL, "[DECLARACAO]"); printf("\n%s\n",$$.nd->token);
    }
    | declaracao declaracoes
    ;

declaracao:
    declaracao_variavel
    | declaracao_funcao
    | declaracao_estrutura
	| redefinicao_variavel
    ;

termo:
    IDENTIFICADOR {
        // se variavel investigada nao estiver na tabela de simbolos
        if (!get_variable_content($1.name)){
            semantic_error = 1;
            printf("\n\e[0;31mERRO DE SEMANTICA proximo a linha %i: VARIAVEL NAO DECLARADA \"%s\" \e[0m\n", lc, $1.name);

        }}
    | NUMERO {insert_content();}
    | STRING {insert_content();}
    | BOOL {insert_content();}
    | CHAR {insert_content();}
    ;

redefinicao_variavel:
	IDENTIFICADOR{strcpy(name, $1.name);} VAI_SER{add('K');} expressao DOT{add('K');}
    ;

declaracao_variavel:
    TIPO {insert_type(); add('K');} IDENTIFICADOR {strcpy(name, $3.name);} VAI_SER{add('K');} expressao{add('V');} DOT{add('K');}
    ;

declaracao_funcao:
    NAQUELE_NAIPE{add('K');} IDENTIFICADOR{strcpy(name, $3.name);} LBRACE{add('K');} parametros RBRACE{add('K');} COLLON{add('K');} bloco
    ;

parametros:
    parametro
    | parametro COMMA{add('K');} parametros
    ;

parametro:
    IDENTIFICADOR{strcpy(name, $1.name); add('V');}
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
    FRAGA expressao INTERROGACAO declaracoes END_COMMAND {add('K');}
	| FRAGA expressao INTERROGACAO declaracoes NAO{add('K');}
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
    int last_content_int = atoi(last_content);
    int content_int = atoi(content);
    // as duas variaveis acima retornam 0 caso não haja numeros no array sendo passado para a funcao
    // mas como e possivel que elas de fato tenham o valor 0, nao da para usa-las para verificar
    // erros de sintaxe
    // ALEM DISSO ISSO AQUI SO FUNCIONA PRA INT EM

    // as variaveis abaixo verificam se existe uma letra ou virgula nas variaveis sendo manipuladas
    int last_is_not_int = contains_letter(last_content);
    int content_is_not_int = contains_letter(content);

    if (last_is_not_int || content_is_not_int ){
        printf("\n\e[0;31mERRO DE SEMANTICA proximo a linha %i: tipos incompatíveis para operação \"%s\" [%s] [%s]\e[0m\n", lc, operator, content, last_content);
        semantic_error = 1;
        return;
    }
    if (operator == "AI_CE_JUNTA"){
        sprintf(operacao, "%d",  last_content_int + content_int);
        change_variable_content(name, operacao);
    }
    else if (operator == "AI_CE_DIMINUI"){
        sprintf(operacao, "%d", last_content_int - content_int);
    }
    else if (operator == "CE_MULTIPLICA_POR"){
        sprintf(operacao, "%d", last_content_int * content_int);
    }
    else if (operator == "CE_DIVIDE_POR"){
        sprintf(operacao, "%d", last_content_int / content_int);
    }
    strcpy(content, operacao);
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

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}