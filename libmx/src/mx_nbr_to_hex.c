#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int d = 1;
    int count = 1;

    for (; nbr / (d * 16) >= 1; count++)
        d = d * 16;
    char *s = mx_strnew(count);
    for (int i = 0, c = 0; i < count; i++) {
        c = nbr / d;
        if (c >= 0 && c <= 9)
            s[i] = '0' + c;
        if (c >= 10 && c <= 15)
            s[i] = 87 + c;
        nbr = nbr % d;
        d = d / 16;
    }
    return s;
}
