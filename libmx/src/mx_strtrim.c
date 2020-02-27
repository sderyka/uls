#include "libmx.h"

char *mx_strtrim(const char *str) {
    int len = mx_strlen(str);
    int a = 0;
    int b = 0;

    if (str == NULL)
        return NULL;
    for (; mx_isspace(str[a]) == 1; a++);
    for (int c = len - 1; mx_isspace(str[c]) == 1; c--)
        b++;
    char *res = mx_strnew(len - a - b);
    for (int i = 0; a < (len - b); a++) {
        res[i] = str[a];
        i++;
    }
    return res;
}
