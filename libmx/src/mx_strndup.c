#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *s = malloc(n + 1);

    for (size_t i = 0; i < n; i++) {
        s[i] = s1[i];
    }
    s[n] = '\0';
    return s;
}
