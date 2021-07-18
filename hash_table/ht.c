#include "ht.h"

#define INITIAL_SIZE 32
#define MAX(A, B) (A > B ? A : B)

ht_item* item_create(char* key, char* value) {
    ht_item* ret = (ht_item*)malloc(sizeof(ht_item));

    ret->key = (char*)malloc((strlen(key)+1)*sizeof(char));
    strcpy(ret->key, key);

    ret->value = (char*)malloc((strlen(key)+1)*sizeof(char));
    strcpy(ret->value, value);

    return ret;
}

void item_free(ht_item* item) {
    free(item->key);
    free(item->value);
    free(item);
}

HashTable* ht_create(size_t size) {
    HashTable* ret = (HashTable*)malloc(sizeof(HashTable));

    ret->capacity = nextPowerOfTwo(size);
    ret->capacity = MAX(INITIAL_SIZE, ret->len);
    ret->capacity = ret->capacity*sizeof(ht_item);
    
    ret->len = 0;

    ret->items = (ht_item*)malloc(ret->capacity);
    ret->indices = (size_t*)malloc(ret->len*sizeof(size_t));

    return ret;
}

void ht_free(HashTable* ht) {
    for (int i=0; i<ht->len; i++)
        item_free(&ht->items[ht->indices[i]]);

    free(ht->indices);
    free(ht->items);
}

void ht_insert(HashTable* ht, char* key, char* value) {

} 
