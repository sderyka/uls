#include "libmx.h"

char *mx_add_char(char *s, char c) {
    int len = mx_strlen(s);

    s = mx_realloc(s, (len + 1));
    s[len] = c;
    s[len + 1] = '\0';
    return s;
}
