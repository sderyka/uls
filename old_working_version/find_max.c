#include "../inc/uls.h"

int mx_find_max(char **strs) {
    int max = 8;
    int len;

    for (int i = 0; strs[i]; i++) {
        len = mx_strlen(strs[i]);
        if (len >= max)
            max = len - (len % 8) + 8;
    }
    return max;
}
