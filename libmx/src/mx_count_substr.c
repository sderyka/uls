#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (sub == NULL || str == NULL)
        return -1;
    else {
        int res = 0;
        int len1 = mx_strlen(str);
        int len2 = mx_strlen(sub);
        for (int count = 0; count <= (len1 - len2); count++) {
            int j = 0;
            for (int i = 0; str[count + i] == sub[i] && sub[i] != '\0'; i++) {
                j++;
            }
            if (j == len2)
                res++;
        }
        return res;
    }
}
