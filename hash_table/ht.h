#ifndef HT_H
#define HT_H

#include "../string/string.h"
#include "../string/misc.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} ht_item;

ht_item* item_create(char*, char*);
void item_free(ht_item*);

typedef struct {
    ht_item* items;
    size_t* indices; // indices of items in table
    size_t len; // actual number of objets contained in the table
    size_t capacity; // number of bytes of the items array
} HashTable;

HashTable* ht_create(size_t);
void ht_free(HashTable*);

void ht_insert(HashTable*, char* key, char* value);
char* ht_search(HashTable*, char* key);

#endif
