#include "symbol_table.h"

// Declare externamente a função yyerror para evitar o warning
extern void yyerror(const char *s);

// Função de Hash: Transforma uma string em um índice da tabela
unsigned int hash(const char *str) {
    unsigned int hash = 0;
    int c;
    while ((c = *str++)) {
        hash = hash * 33 + c;
    }
    return hash % TABLE_SIZE;
}

// Criação da tabela de símbolos
SymbolTable* create_table() {
    SymbolTable *table = (SymbolTable*) malloc(sizeof(SymbolTable));
    table->table = (SymbolNode**) malloc(TABLE_SIZE * sizeof(SymbolNode*));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->table[i] = NULL;
    }
    return table;
}

// Deletar tabela de símbolos
void delete_table(SymbolTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        SymbolNode *node = table->table[i];
        while (node) {
            SymbolNode *temp = node;
            node = node->next;
            free(temp->symbol.name);
            free(temp->symbol.type);
            free(temp);
        }
    }
    free(table->table);
    free(table);
}

// Inserir símbolo na tabela
void insert_symbol(SymbolTable *table, const char *name, const char *type) {
    if (name == NULL || type == NULL) {
        yyerror("Nome ou tipo inválido ao inserir na Tabela de Símbolos");
        yyerror(name);
        yyerror(type);
        return;
    }
    unsigned int index = hash(name);
    SymbolNode *new_node = (SymbolNode*) malloc(sizeof(SymbolNode));
    if (new_node == NULL) {
        yyerror("Falha ao alocar memória para novo nó na Tabela de Símbolos");
        return;
    }
    new_node->symbol.name = strdup(name);
    new_node->symbol.type = strdup(type);
    new_node->next = table->table[index];
    table->table[index] = new_node;
}


// Procurar símbolo na tabela
Symbol* lookup_symbol(SymbolTable *table, const char *name) {
    unsigned int index = hash(name);
    SymbolNode *node = table->table[index];
    while (node) {
        if (strcmp(node->symbol.name, name) == 0) {
            return &node->symbol;
        }
        node = node->next;
    }
    return NULL;
}

// Imprimir a tabela de símbolos
void print_table(SymbolTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        SymbolNode *node = table->table[i];
        while (node) {
            printf("Nome: %s, Tipo: %s\n", node->symbol.name, node->symbol.type);
            node = node->next;
        }
    }
}
