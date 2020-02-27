#include "libmx.h"

static char *replace_cycle(const char *str, const char *sub,
                           const char *replace, int newlen) {
    char *res = mx_strnew(newlen);

    for (int count = 0, j = 0, s = 0; count < newlen; count++) {
        for (int i = 0; str[count + i] == sub[i] && sub[i] != '\0'; i++)
            j++;
        if (j == mx_strlen(sub)) {
            for (int r = 0; r < mx_strlen(replace); r++, s++)
                res[s] = replace[r];
            count = count + mx_strlen(replace) - 1;
        }
        else {
            res[s] = str[count];
            s++;
        }
        j = 0;
    }
    return res;
}

char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace) {
    int n = mx_count_substr(str, sub);
    int len3 = mx_strlen(replace);
    int newlen = mx_strlen(str) + (len3 - mx_strlen(sub)) * n;

    if (str == NULL || sub == NULL || replace == NULL)
        return NULL;
	return(replace_cycle(str, sub, replace, newlen));
}
