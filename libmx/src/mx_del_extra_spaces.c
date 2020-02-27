#include "libmx.h"

static char *del_spaces(const char *str, int flag) {
    char *res = mx_strnew(mx_strlen(str));

    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i]) != 1) {
            res[j] = str[i];
            j++;
            flag = 0;
        }
        else if (flag == 0) {
            res[j] = ' ';
            j++;
            flag = 1;
        }
        else
            flag = 1;
    }
    return res;
}

char *mx_del_extra_spaces(const char *str) {
    str = mx_strtrim(str);
    int len = mx_strlen(str);
    int flag = 0;

    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i]) == 1) {
            if (flag == 1)
                len--;
            flag = 1;
        }
        else
            flag = 0;
    }
    return(del_spaces(str, flag));
}
