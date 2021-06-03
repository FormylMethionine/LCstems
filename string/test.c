#include <stdio.h>
#include <stdlib.h>
#include "misc.h"
#include "string.h"

int main(void) {
    printf("Hello\n");
    string* test = str_create("Ho");
    printf("len:%lu\n", test->len);
    printf("capacity:%lu\n", test->capacity);
    char* ctest = cstr(test);
    printf("string:%s\n\n", ctest);
    free(ctest);

    printf("append char\n");
    str_char_append(test, '.');
    ctest = cstr(test);
    printf("string:%s\n\n", ctest);
    free(ctest);

    printf("append string\n");
    str_append(test, "World!");
    ctest = cstr(test);
    printf("string:%s\n", ctest);
    free(ctest);
    printf("len:%lu\n", test->len);
    printf("capacity:%lu\n\n", test->capacity);

    printf("insert char\n");
    str_char_insert(test, 'e', 1);
    ctest = cstr(test);
    printf("string:%s\n", ctest);
    free(ctest);
    str_free(test);

    printf("long hello\n");
    test = str_create("Helllloooooooo");
    printf("len:%lu\n", test->len);
    printf("capacity:%lu\n", test->capacity);
    ctest = cstr(test);
    printf("string:%s\n", ctest);
    free(ctest);
    str_free(test);

    return 0;
}
