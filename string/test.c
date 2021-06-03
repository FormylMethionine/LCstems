#include <stdio.h>
#include <stdlib.h>
#include "misc.h"
#include "string.h"

int main(void) {
    printf("Hello\n");
    string* test = str_create("Hello");
    printf("len:%lu\n", test->len);
    printf("capacity:%lu\n", test->capacity);
    printf("string:%s\n\n", cstr(test));

    printf("append char\n");
    str_char_append(test, '.');
    printf("string:%s\n\n", cstr(test));

    printf("append string\n");
    str_append(test, "World!");
    printf("string:%s\n", cstr(test));
    printf("len:%lu\n", test->len);
    printf("capacity:%lu\n\n", test->capacity);
    free(test);

    printf("long hello\n");
    test = str_create("Helllloooooooo");
    printf("len:%lu\n", test->len);
    printf("capacity:%lu\n", test->capacity);
    printf("string:%s\n", cstr(test));
    free(test);

    return 0;
}
