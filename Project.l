%{#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOL 1000 // Size of the Hash Table
#define CONSTANT 1000 // Size of the Hash Table


unsigned long hash_function(char* str) {
    unsigned long i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];
    return i % SYMBOL;
}

typedef struct Ht_item Ht_item;

// Define the Hash Table Item here
struct Ht_item {
    char* key;
    char* value;
};

typedef struct HashTable HashTable;

// Define the Hash Table here
struct HashTable {
    // Contains an array of pointers
    // to items
    Ht_item** items;
    int size;
    int count;
};

Ht_item* create_item(char* key, char* value) {
    // Creates a pointer to a new hash table item
    Ht_item* item = (Ht_item*) malloc (sizeof(Ht_item));
    item->key = (char*) malloc (strlen(key) + 1);
    item->value = (char*) malloc (strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

HashTable* create_table(int size) {
    // Creates a new HashTable
    HashTable* table = (HashTable*) malloc (sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**) calloc (table->size, sizeof(Ht_item*));
    for (int i=0; i<table->size; i++)
        table->items[i] = NULL;

    return table;
}
char* ht_search(HashTable* table, char* key) {
    // Searches the key in the hashtable
    // and returns NULL if it doesn't exist
    int index = hash_function(key);
    Ht_item* item = table->items[index];

    // Ensure that we move to a non NULL item
    if (item != NULL) {
        if (strcmp(item->key, key) == 0)
            return item->value;
    }
    return NULL;
}



void handle_collision(HashTable* table, unsigned long index, Ht_item* item) {
}

void ht_insert(HashTable* table, char* key, char* value) {

    if (ht_search(HashTable* table, char* key))
    {// Create the item
      Ht_item* item = create_item(key, value);

    // Compute the index
      unsigned long index = hash_function(key);

      Ht_item* current_item = table->items[index];

      if (current_item == NULL) {
        // Key does not exist.
        if (table->count == table->size) {
            // Hash Table Full
            printf("Insert Error: Hash Table is full\n");
            // Remove the create item
            free_item(item);
            return;
        }

        // Insert directly
        table->items[index] = item;
        table->count++;
      }

      else {
            // Scenario 1: We only need to update value
            if (strcmp(current_item->key, key) == 0) {
                strcpy(table->items[index]->value, value);
                return;
            }

            else {
            // Scenario 2: Collision
            // We will handle case this a bit later
            handle_collision(table, index, item);
            return;
        }
    }
}
}


void print_table(HashTable* table) {
    printf("\nSymbol Table\n-------------------\n");
    for (int i=0; i<table->size; i++) {
        if (table->items[i]) {
            printf("%s\t\t%s\n", table->items[i]->key, table->items[i]->value);
        }
    }
    printf("-------------------\n\n");
}

HashTable* st = create_table(SYMBOL);
HashTable* ct = create_table(CONSTANT);

%}

digit [0-9]
letter [a-zA-Z_]
KEY "while"|"if"|"else"|"for"|"int"|"float"|"return"|"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"enum"|"extern"|"goto"|"long"|"register"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"
OPER "<="|"=="|"="|"++"|"-"|"*"|"+"|"%"|"<"|">"|"=>"|"!="|"/"
IDEN {letter}({letter}|{digit})*
INTE {digit}+

%%

\/\*(.*\n)*.*\*\/ {} ;
\/\* {del();}
\/\/(.*) {};
#(.*) {};
{KEY} {printf("Keyword: %s\n",yytext);ht_insert(st, yytext, "Keyword");}

{IDEN}/= {printf("Variable %s\n",yytext);}

(\".*\")|(\'.*\') {printf("String: %s\n",yytext);}
{INTE} {printf("Constant: %s\n",yytext);}
[(){}|,;] {printf("Seperator: %s\n",yytext);}
{IDEN} {printf("Identifier: %s\n",yytext);}
{OPER} {printf("Operator: %s\n",yytext);}
(\")[^\n\"]* {del1();}
(\')[^\n\']* {del1();}
[ \t\n]+ {};
. ;


%%

int del()
{
  printf ("\n\n\n***ERROR: INCOMPLETE MULTI LINE COMMENT***\n\n\n***PROGRAM TERMINATED***\n\n\n");
  exit(0);
}

int del1()
{
  printf ("\n\n\n***ERROR: INCOMPLETE STRING***\n\n\n***PROGRAM TERMINATED***\n\n\n");
  exit(0);
}

int del2()
{
  printf ("\n\n\n***ERROR: UNKNOWN CHARACTER***\n\n\n***PROGRAM TERMINATED***\n\n\n");
  exit(0);
}

int main()
{
  yyin=fopen("input.c","r");
  yylex();
  print_table(st);
  return 0;
}
