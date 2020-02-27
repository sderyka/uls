#include "libmx.h"

void mx_str_reverse(char *s) {
    int len = mx_strlen(s);
    int i = 0;

    for (; i < len - 1; i++) {
        mx_swap_char(&s[i], &s[len - 1]);
        len--;
    }
}

