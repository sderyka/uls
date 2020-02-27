#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *b1 = (unsigned char *)b;
    unsigned char s = (unsigned char)c;

    for (size_t i = 0; i < len; i++) {
	    b1[i] = s;
    }
    return b1;
}
