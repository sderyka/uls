#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (str == NULL)
        return -2;
    else {
        int i = 0;

        for (; str[i] != '\0'; i++) {
            if (str[i] == c)
                return i;
        }
        return -1;
    }
}
