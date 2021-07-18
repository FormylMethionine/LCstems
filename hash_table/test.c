#include <stdio.h>
#include <stdlib.h>
#include "misc.h"
#include "ht.h"

int main(void) {
    printf("insert string\n");
    HashTable* ht = ht_create(12);
    printf("size:%lu\n", ht->len);
    printf("capacity:%lu\n\n", ht->capacity);
    ht_free(ht);
    free(ht);

    return 0;
}
