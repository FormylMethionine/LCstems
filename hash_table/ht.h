#ifndef HT_H
#define HT_H

#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} ht_item;

// Hash function
static size_t hash(const char*);

typedef struct {
    ht_item* items;
    size_t len; // actual number of objets contained in the table
    size_t capacity; // max number of elements in the array
} HashTable;

HashTable* ht_create(size_t);
void ht_free(HashTable*);

void ht_insert(HashTable*, char* key, char* value);
char* ht_search(HashTable*, char* key);

#endif
