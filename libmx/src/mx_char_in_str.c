#include "libmx.h"

char *mx_char_in_str(const char *str, char c) {
    int i = mx_get_char_index(str, c);

    return((i >= 0) ? ((char *)&str[i]) : (NULL));
}
