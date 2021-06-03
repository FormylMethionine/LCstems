#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <string.h>
#include "misc.h"

typedef struct {
    char* str;
    size_t len;
    size_t capacity;
} string;

string* str_void_create();
string* str_create(char*);

void str_free(string*);

void str_char_append(string*, char);
void str_str_append(string*, string*);
void str_append(string*, char*);

void str_insert(string*, char*, unsigned int);
void str_char_insert(string*, char, unsigned int);
void str_string_insert(string*, string*, unsigned int);

char str_get(string*, unsigned int);

char* strcopy(const char*, char*);

char* cstr(string*);

#endif
