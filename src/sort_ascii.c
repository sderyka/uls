#include "../inc/uls.h"

void mx_sort_ascii(char **files, char *flags) {
    int count = mx_count_arr_el(files);

    if (mx_is_flag_present(flags, 'f'))
        mx_bubble_sort(files, count);
}
