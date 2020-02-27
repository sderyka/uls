#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *src1 = (unsigned char *)src;
    unsigned char *dst1 = (unsigned char *)dst;

    for (size_t i = 0; i < n; i++)
        dst1[i] = src1[i];
    return dst1;
}
