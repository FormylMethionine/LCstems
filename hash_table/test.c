#include <stdio.h>
#include <stdlib.h>
#include "misc.h"
#include "ht.h"

int main(void) {
    HashTable* ht = ht_create(12);
    printf("size:%lu\n", ht->len);
    printf("capacity:%lu\n\n", ht->capacity);
    printf("insert object\n");
    char* key = "A";
    char* value = "AB";
    ht_insert(ht, key, value);
    printf("size:%lu\n", ht->len);
    printf("capacity:%lu\n\n", ht->capacity);
    ht_free(ht);
    free(ht);

    return 0;
}
