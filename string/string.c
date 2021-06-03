#include "string.h"
#include <stdio.h>

string* str_create(char* init) {
    string* ret = (string*)malloc(sizeof(string));
    if (!ret) return NULL;

    ret->len = strlen(init);
    ret->capacity = nextPowerOfTwo(ret->len << 1);

    ret->str = (char*)malloc(ret->capacity*sizeof(char));
    strcopy(init, ret->str);

    return ret;
}

char* strcopy(const char* from, char* to) {
    for (int i=0; i<strlen(from); i++)
        to[i] = from[i];
    return to;
}

void str_free(string* s) {
    free(s->str);
    free(s);
}

char str_get(string* s, unsigned int i) {
    if (i>s->len)
        return EXIT_FAILURE;
    return s->str[i];
}

char* cstr(string* s) {
    char* ret = (char*)malloc(s->len*sizeof(char));
    strcopy(s->str, ret);
    ret[s->len] = '\0';
    return ret;
}

void str_char_append(string* s, char c) {
    s->len += 1;
    if (s->len > (s->capacity >> 1))
        s->str = (char*)realloc((void*)s->str, s->capacity << 1);
    s->str[s->len-1] = c;
}

void str_append(string* s, char* cstr) {
    size_t cstr_len = strlen(cstr);
    size_t newlen = strlen(cstr) + s->len;

    if (newlen > (s->capacity >> 1)) {
        s->capacity = nextPowerOfTwo(newlen << 1);
        s->str = (char*)realloc(s->str, s->capacity*sizeof(char));
    }

    for (size_t i=0; i<cstr_len; i++)
        s->str[(s->len)+i] = cstr[i];
    s->len = newlen;
}

void str_str_append(string* s, string* s_app) {
    size_t newlen = s->len + s_app->len;

    if (newlen > (s->capacity >> 1)) {
        s->capacity = nextPowerOfTwo(newlen << 1);
        s->str = (char*)realloc(s->str, s->capacity*sizeof(char));
    }

    for (size_t i=0; i<s_app->len; i++)
        s->str[(s->len)+i] = s_app->str[i];
    s->len = newlen;
}
