#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    void *t = malloc(len);

    t = mx_memcpy(t, src, len);
    dst = mx_memcpy(dst, t, len);
    free(t);
    return dst;
}
