#include "ht.h"

#define INITIAL_SIZE 32
#define MAX(A, B) (A > B ? A : B)

ht_item* item_create(char* key, char* value) {
    ht_item* ret = (ht_item*)malloc(sizeof(ht_item));
    
    ret->key = NULL;
    ret->value = NULL;

    if (key != NULL) {
        ret->key = (char*)malloc((strlen(key)+1)*sizeof(char));
        strcpy(ret->key, key);
    }

    if (key != NULL) {
        ret->value = (char*)malloc((strlen(key)+1)*sizeof(char));
        strcpy(ret->value, value);
    }
    return ret;
}

void item_free(ht_item* item) {
    free(item->key);
    free(item->value);
    free(item);
}

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

    ret->items = (ht_item*)malloc(ret->capacity*sizeof(ht_item*));
    
    for (size_t i=0; i<ret->capacity; i++)
        ret->items[i] = item_create((char*)NULL, (char*)NULL);

    return ret;
}

void ht_free(HashTable* ht) {
    for (size_t i=0; i<ht->capacity; i++)
        item_free(ht->items[i]);

    free(ht->items);
}

void ht_insert(HashTable* ht, char* key, char* value) {
    size_t index = hash(key) & (ht->capacity - 1);

    while ((void*)ht->items[index]->key != NULL) {
        if (strcmp(key, ht->items[index]->key) == 0) {
            ht->items[index]->value = value;
            break;
        }

        index++;
        if (index >= ht->capacity) {
            index = 0;
        }
    }

    key = strdup(key);
    value = strdup(value);
    
    ht->items[index]->key = key;
    ht->items[index]->value = value;
    ht->len++;
} 

char* ht_search(HashTable* ht, char* key) {
    size_t index = hash(key) & (ht->capacity-1);
    
    while ((void*)ht->items[index]->key == NULL) {
        if(strcmp(key, ht->items[index]->key) == 0)
            return ht->items[index]->value;
        index ++;
        if (index >= ht->capacity)
            index = 0;
    }

    return NULL;

}
