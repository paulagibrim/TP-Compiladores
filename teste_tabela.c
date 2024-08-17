#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbol_table.c"

// Implementacao de yyerror para evitar erros de linkagem
void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
}

int main() {
    // Criacao da tabela de simbolos
    SymbolTable *table = create_table();
    
    // Insercao de simbolos na tabela
    insert_symbol(table, "x", "int");
    insert_symbol(table, "y", "float");
    insert_symbol(table, "z", "char");
    insert_symbol(table, "w", "double");
    
    // Procurar e imprimir simbolos
    Symbol *sym;
    sym = lookup_symbol(table, "x");
    if (sym) {
        printf("Simbolo encontrado - Nome: %s, Tipo: %s\n", sym->name, sym->type);
    } else {
        printf("Simbolo 'x' nao encontrado.\n");
    }
    
    sym = lookup_symbol(table, "y");
    if (sym) {
        printf("Simbolo encontrado - Nome: %s, Tipo: %s\n", sym->name, sym->type);
    } else {
        printf("Simbolo 'y' nao encontrado.\n");
    }
    
    sym = lookup_symbol(table, "a");
    if (sym) {
        printf("Simbolo encontrado - Nome: %s, Tipo: %s\n", sym->name, sym->type);
    } else {
        printf("Simbolo 'a' nao encontrado.\n");
    }

    // Imprimir a tabela de simbolos
    printf("\nTabela de Simbolos:\n");
    print_table(table);
    
    // Deletar a tabela de simbolos
    delete_table(table);

    return 0;
}
