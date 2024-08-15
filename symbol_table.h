#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TABLE_SIZE 100

// Estrutura para os dados de cada símbolo
typedef struct {
    char *name;      // Nome do identificador
    char *type;      // Tipo do identificador
} Symbol;

// Estrutura de um nó na tabela hash
typedef struct SymbolNode {
    Symbol symbol;
    struct SymbolNode *next;
} SymbolNode;

// Estrutura da tabela de símbolos (hash table)
typedef struct {
    SymbolNode **table;
} SymbolTable;

// Funções da Tabela de Símbolos
SymbolTable* create_table();
void delete_table(SymbolTable* table);
unsigned int hash(const char *str);
void insert_symbol(SymbolTable *table, const char *name, const char *type);
Symbol* lookup_symbol(SymbolTable *table, const char *name);
void print_table(SymbolTable *table);

#endif
