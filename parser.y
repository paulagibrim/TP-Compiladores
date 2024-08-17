%{
#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>
// #include "lexer.l" 
#include "symbol_table.h"

SymbolTable *sym_table;
int yydebug = 1;

void yyerror(const char *s);
int yylex(void);

void insert_symbol_to_table(const char *name, const char *type) {
    if (lookup_symbol(sym_table, name) != NULL) {
        yyerror("Erro: Símbolo já declarado.");
    } else {
        insert_symbol(sym_table, name, type);
    }
}

void lookup_symbol_in_table(const char *name) {
    Symbol *s = lookup_symbol(sym_table, name);
    if (s) {
        printf("Símbolo encontrado: Nome: %s, Tipo: %s\n", s->name, s->type);
    } else {
        printf("Símbolo %s não encontrado\n", name);
    }
}

%}

/* Defina YYSTYPE como char* */
%union {
    char *str;
}

/* Definição de tokens */
%token <str> IDENTIFICADOR TIPO
%token NUMERO STRING BOOL CHAR 
%token VAI_SER
%token <str> NAQUELE_NAIPE 
%token FRAGA NAO INTERROGACAO VAI_FAZENDO_ATE PRA PICA_MULA ARREDA
%token ANOTA
%token AI_CE_JUNTA AI_CE_DIMINUI CE_MULTIPLICA_POR CE_DIVIDE_POR
%token ENGUAL NADA_A_VER_COM MAIOR_QUE MENOR_QUE
%token LPAREN RPAREN LBRACE RBRACE COLLON COMMA DOT
%token UNDERSCORE OR_OP AND_OP NOT_OP 
%token <str> END_COMMAND

%left AI_CE_JUNTA AI_CE_DIMINUI
%left CE_MULTIPLICA_POR CE_DIVIDE_POR

%%

/* Regras de produção */
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
    TIPO IDENTIFICADOR VAI_SER expressao DOT {
        insert_symbol_to_table($2, $1);
    }
    ;

declaracao_funcao:
    NAQUELE_NAIPE IDENTIFICADOR LBRACE parametros RBRACE COLLON bloco {
        insert_symbol_to_table($2, $1);
    }
    ;

parametros:
    parametro
    | parametro COMMA parametros
    ;

parametro:
    IDENTIFICADOR {
        insert_symbol_to_table($1, "param");
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
    FRAGA expressao bloco NAO bloco INTERROGACAO
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
    IDENTIFICADOR {
        lookup_symbol_in_table($1);  // Verifica se o identificador já foi declarado
    }
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
    ;

bloco:
    declaracoes
    ;

%%

/* Função de erro */
void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
}

/* Função principal */
int main(void) {
    sym_table = create_table();  // Cria a Tabela de Símbolos
    int result = yyparse();  // Inicia a análise sintática
    print_table(sym_table);  // Imprime a Tabela de Símbolos ao final
    delete_table(sym_table);  // Deleta a Tabela de Símbolos e libera memória
    // printf("Linhas: %d\n", lc);
    return result;
}
