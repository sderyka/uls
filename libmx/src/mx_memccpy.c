#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
                 int c, size_t n) {
    unsigned char *dst1 = (unsigned char *)dst;
    unsigned char *src1 = (unsigned char *)src;
    unsigned char s = (unsigned char)c;
    size_t i = 0;

    for (; i < n && src1[i] != s; i++) {
        dst1[i] = src1[i];
    }
    if (src1[i] == s) {
        dst1[i] = src1[i];
        return (void *)&dst1[i + 1];
    }
    return NULL;
}
