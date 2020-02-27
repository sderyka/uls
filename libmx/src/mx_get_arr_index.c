#include "libmx.h"

int mx_get_arr_index(char **arr, char *str) {
    for (int i = 0; arr[i]; ++i) {
        if (mx_strcmp(arr[i], str) == 0) {
            return i;
        }
    }
    return -1;
}
