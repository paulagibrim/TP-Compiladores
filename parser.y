%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"

SybolTable *sym_table

void yyerror(const char *s);
int yylex(void);

void insert_symbol_to_table(const char *name, const char *type) {
    insert_symbol(sym_table, name, type);
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

/* Definição de tokens */
%token IDENTIFICADOR NUMERO STRING BOOL CHAR TIPO
%token VAI_SER
%token NAQUELE_NAIPE FRAGA NAO INTERROGACAO VAI_FAZENDO_ATE PRA PICA_MULA ARREDA
%token ANOTA
%token AI_CE_JUNTA AI_CE_DIMINUI CE_MULTIPLICA_POR CE_DIVIDE_POR
%token ENGUAL NADA_A_VER_COM MAIOR_QUE MENOR_QUE
%token LPAREN RPAREN LBRACE RBRACE COLLON COMMA PERIOD

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
    TIPO IDENTIFICADOR VAI_SER expressao PERIOD
    ;

declaracao_funcao:
    NAQUELE_NAIPE IDENTIFICADOR LBRACE parametros RBRACE COLLON bloco
    ;

parametros:
    parametro
    | parametro COMMA parametros
    ;

parametro:
    IDENTIFICADOR
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
    return yyparse();
}
