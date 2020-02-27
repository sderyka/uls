#include "libmx.h"

char *mx_itoa(int number) {
    int flag = (number < 0) ? (1) : (0);
    unsigned int n = (unsigned int)number;
    int i = 0;
    int d = 1;
    
    for (; n / d >= 10; d = d * 10);
    char *res = mx_strnew(d + flag);
    if (flag == 1) {
        res[i] = '-';
        i++;
    }
    for(int current; d >= 1; i++) {
        current = n / d;
        res[i] = ('0' + current);
        n = n % d;
        d = d / 10;
    }
    return res;
}
