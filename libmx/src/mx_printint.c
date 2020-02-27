#include "libmx.h"

void mx_printint(int n) {
    int d = 1;
    int f;

    if (n < 0) {
        mx_printchar('-');
        if (n == -2147483648) {
            write(1, "214748364", 9);
            n = n % 10;
        }
        n = -n;
    }
    for (; n / d >= 10; d = d * 10);
    while(d >= 1) {
        f = (n / d);
        mx_printchar('0' + f);
        n = n % d;
        d = d / 10;
    }
}

