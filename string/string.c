#include "string.h"

#define INITIAL_CAPACITY 16
#define MAX(A, B) (A > B ? A : B)

string* str_create(char* init) {
    string* ret = (string*)malloc(sizeof(string));
    if (!ret) return NULL;

    ret->len = strlen(init);
    ret->capacity = nextPowerOfTwo(ret->len << 1);
    ret->capacity = MAX(ret->capacity, INITIAL_CAPACITY);

    ret->str = (char*)malloc(ret->capacity*sizeof(char));
    strcopy(init, ret->str);

    return ret;
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
    char* ret = (char*)malloc((s->len+1)*sizeof(char));
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
    size_t newlen = s->len + cstr_len;

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

void str_char_insert(string*s, char c, unsigned int i) {
    s->len += 1;

    if (s->len > (s->capacity >> 1))
        s->str = (char*)realloc((void*)s->str, s->capacity << 1);

    for (size_t k=s->len-1; k>i; k--)
        s->str[k] = s->str[k-1];
    s->str[i] = c;
}

void str_insert(string* s, char* cstr, unsigned int i) {
    size_t cstr_len = strlen(cstr);
    size_t newlen = s->len + cstr_len;

    if (newlen > (s->capacity >> 1)) {
        s->capacity = nextPowerOfTwo(newlen << 1);
        s->str = (char*)realloc(s->str, s->capacity*sizeof(char));
    }

    for (size_t k=newlen-1; k>=i+cstr_len-1; k--)
        s->str[k] = s->str[k-cstr_len];
    for (size_t k=i; k<i+cstr_len; k++)
        s->str[k] = cstr[k-i];

    s->len = newlen;
}

void str_string_insert(string* s1, string* s2, unsigned int i) {
    size_t newlen = s1->len + s2->len;

    if (newlen > (s1->capacity >> 1)) {
        s1->capacity = nextPowerOfTwo(newlen << 1);
        s1->str = (char*)realloc(s1->str, s1->capacity*sizeof(char));
    }

    for (size_t k=newlen-1; k>=i+s2->len-1; k--)
        s1->str[k] = s1->str[k-s2->len];
    for (size_t k=i; k<i+s2->len; k++)
        s1->str[k] = s2->str[k-i];

    s1->len = newlen;
}
