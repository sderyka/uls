#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *s3 = (unsigned char *)s1;
    unsigned char *s4 = (unsigned char *)s2;
    int res = 0;
    size_t i = 0;

    for (; i < n && s3[i] == s4[i]; i++);
    res = s3[i] - s4[i];
    return res;
}
