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
    printf("string:%s\n\n", ctest);
    free(ctest);

    printf("insert char*\n");
    str_insert(test, "ll", 2);
    ctest = cstr(test);
    printf("string:%s\n", ctest);
    printf("capacity:%lu\n\n", test->capacity);
    free(ctest);

    printf("insert char* 2\n");
    str_insert(test, "llllllllllllllllllllllllllllllllllllllllllll", 2);
    ctest = cstr(test);
    printf("string:%s\n", ctest);
    printf("capacity:%lu\n\n", test->capacity);
    free(ctest);
    str_free(test);

    printf("insert string\n");
    string* s1 = str_create("Heo Word!");
    string* s2 = str_create("lllllllllllllllllllllllll");
    str_string_insert(s1, s2, 2);
    char* cs1 = cstr(s1);
    printf("string:%s\n\n");
    free(cs1);
    str_free(s1);
    str_free(s2);

    return 0;
}
