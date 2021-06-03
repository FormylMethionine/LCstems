#include "misc.h"
#include <stdio.h>

size_t nextPowerOfTwo(size_t n){
    size_t ret = 0;
    for (n; n>0; n >>= 1)
        ret++;
    return 1 << ret;
}
