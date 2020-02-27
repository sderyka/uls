#include "libmx.h"

void mx_printstr(const char *s) {
    int len = mx_strlen(s);

    for (int i = 0; i < len; i++) {
        write(1, &s[i], 1);
    }
}
