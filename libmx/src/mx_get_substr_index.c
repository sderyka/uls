#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int len1 = mx_strlen(str);
    int len2 = mx_strlen(sub);

    if (sub == NULL || str == NULL)
        return -2;
    for (int count = 0; count <= (len1 - len2); count++) {
        int j = 0;
        for (int i = 0; str[count + i] == sub[i] && sub[i] != '\0'; i++) {
            j++;
        }
        if (j == len2)
            return count;
    }
    return -1;
}
