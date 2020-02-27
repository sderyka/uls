#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int low = 0;
    int high = size - 1;

    for ((*count) = 1; (*count) <= size / 2 + 1; (*count)++) {
        int mid = low + (high - low) / 2;
        int dif = mx_strcmp(s, arr[mid]);
        if (dif == 0)
            return(mid);
        else {
            if (dif < 0)
                high = mid - 1;
            else {
                low = mid + 1;
            }
        }
    }
    (*count) = 0;
    return -1;
}

