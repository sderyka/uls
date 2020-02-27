#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    char str[5] = {0};

    if (c < 128)
        str[0] = ((c >> 0) & 127) | 0;
    else if (c < 2048) {
        str[0] = ((c >> 6) & 31) | 192;
        str[1] = ((c >> 0) & 63) | 128;
    }
    else if (c < 65536) {
        str[0] = ((c >> 12) & 15) | 224;
        str[1] = ((c >> 6 ) & 63) | 128;
        str[2] = ((c >> 0 ) & 63) | 128;
    }
    else {
        str[0] = ((c >> 18) & 7) | 240;
        str[1] = ((c >> 12) & 63) | 128;
        str[2] = ((c >> 6 ) & 63) | 128;
        str[3] = ((c >> 0 ) & 63) | 128;
    }
    write(1, str, mx_strlen(str));
}
