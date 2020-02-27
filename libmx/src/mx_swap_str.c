#include "libmx.h"

void mx_swap_str(char *str1, char *str2) {
    char *temp = mx_strdup(str1);

    str1 = mx_strcpy(str1, str2);
    str2 = mx_strcpy(str2, temp);
    mx_strdel(&temp);
}
