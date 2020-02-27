#include "libmx.h"

void mx_print_error(char *s) {
    int len = mx_strlen(s);

    for (int i = 0; i < len; i++) {
        write(2, &s[i], 1);
    }
}
