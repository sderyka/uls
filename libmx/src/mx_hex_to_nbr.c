#include "libmx.h"

static int count_current(int c, const char *hex) {
    int current;

    if (hex[c] >= 'A' && hex[c] <= 'F') {
        current = hex[c] - 55;
    }
    if (hex[c] >= 'a' && hex[c] <= 'f') {
        current = hex[c] - 87;
    }
    if (hex[c] >= '0' && hex[c] <= '9') {
        current = hex[c] - 48;
    }
    return current;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long dem = 0;
    int n = 0;
    double pow = 1;
    for (; hex[n] != '\0'; n++) {
        pow = pow * 16;
    }
    for (int c = 0; c < n; c++) {
        int current = count_current(c, hex);
        pow = pow / 16;
        dem = dem + pow * current;
    }
    return dem;
}

