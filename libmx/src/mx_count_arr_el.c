#include "libmx.h"

int mx_count_arr_el(char **arr) {
    int count = 0;

    while(arr[count] != NULL) {
        count++;
    }
    return count;
}
