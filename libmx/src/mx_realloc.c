#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *res;

    if (ptr == NULL)
        return(malloc(size));
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    res = malloc(size);
    res = mx_memcpy(res, ptr, malloc_size(ptr));
    if (ptr)
        free(ptr);
    return res;
}
