#include <stdio.h>
#include <stdlib.h>
#include "misc.h"
#include "ht.h"

int main(void) {
    HashTable* ht = ht_create(12);
    printf("size:%lu\n", ht->len);
    printf("capacity:%lu\n\n", ht->capacity);
    printf("insert object\n");

    ht_insert(ht, "A", "AB");
    printf("size:%lu\n", ht->len);
    printf("capacity:%lu\n\n", ht->capacity);
    
    ht_insert(ht, "A", "ABC");
    printf("size:%lu\n", ht->len);
    printf("capacity:%lu\n\n", ht->capacity);

    printf("%s\n", ht_search(ht, "A"));

    ht_free(ht);

    return 0;
}
