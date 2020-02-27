#include "../inc/uls.h"

void mx_sort_ascii(char **files, int flags[]) {
    int count = mx_count_arr_el(files);

    if (flags[4] != 1)
        mx_bubble_sort(files, count);
}
