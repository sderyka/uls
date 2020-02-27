#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *s1 = (unsigned char *)s;
    unsigned char b = (unsigned char)c;
    size_t i = 0;

    for (; i < n; i++) {
        if (s1[i] == b)
            return (&s1[i]);
    }
    return NULL;
}
