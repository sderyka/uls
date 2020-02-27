#include "libmx.h"

int mx_sqrt(int x) {
    int measure = 1000;
    int i = 0;

    if (x == 0 || x == 1)
        return x;
    if (x <= 1000000)
        measure = 2;
    while (i <= x / measure) {
        if (i * i == x)
            return(i);
        i++;
    }
    return 0;
}

