#include "ht.h"

#define INITIAL_SIZE 32
#define MAX(A, B) (A > B ? A : B)

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL
static size_t hash(const char* key) {
    size_t hash = FNV_OFFSET;
    for (const char* p = key; *p; p++) {
        hash ^= (size_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

HashTable* ht_create(size_t size) {
    HashTable* ret = (HashTable*)malloc(sizeof(HashTable));

    ret->capacity = nextPowerOfTwo(size);
    ret->capacity = MAX(INITIAL_SIZE, ret->len);
    //ret->capacity = ret->capacity*sizeof(ht_item);
    
    ret->len = 0;

    ret->items = (ht_item*)calloc(ret->capacity, sizeof(ht_item));
    if (ret->items == NULL) {
        free(ret->items);
        return NULL;
    }

    return ret;
}

void ht_free(HashTable* ht) {
    for (size_t i = 0; i < ht->capacity; i++) {
        if (ht->items[i].key != NULL)
            free(ht->items[i].key);
        if (ht->items[i].value != NULL)
            free(ht->items[i].value);
    }
    free(ht->items);
    free(ht);
}

void ht_insert(HashTable* ht, char* key, char* value) {
    size_t index = hash(key) & (ht->capacity - 1);

    while ((void*)ht->items[index].key != NULL) {
        if (strcmp(key, ht->items[index].key) == 0) {
            break;
        }

        index++;
        if (index >= ht->capacity) {
            index = 0;
        }
    }

    if (ht->items[index].key != NULL && strcmp(key, ht->items[index].key) == 1)
        ht->len++;

    key = strdup(key);
    value = strdup(value);
    
    ht->items[index].key = key;
    ht->items[index].value = value;
    
} 

char* ht_search(HashTable* ht, char* key) {
    size_t index = hash(key) & (ht->capacity-1);
    
    while ((void*)ht->items[index].key != NULL) {
        if(strcmp(key, ht->items[index].key) == 0)
            return ht->items[index].value;
        index ++;
        if (index >= ht->capacity)
            index = 0;
    }

    return NULL;

}
