#include "misc.h"

size_t nextPowerOfTwo(size_t n){
    size_t ret = 0;
    for (n; n>0; n >>= 1)
        ret++;
    return 1 << ret;
}

char* strcopy(const char* from, char* to) {
    for (size_t i=0; i<strlen(from); i++)
        to[i] = from[i];
    return to;
}
