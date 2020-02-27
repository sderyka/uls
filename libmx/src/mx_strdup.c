#include "libmx.h"

char *mx_strdup(const char *str) {
    int size = mx_strlen(str);
    char *s = mx_strnew(size);

    s = mx_strcpy(s, str);
    return s;
}
