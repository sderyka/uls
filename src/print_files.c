#include "../inc/uls.h"

// flags: [0] - 1st non-flag arg, [12] - argc
void mx_print_files(char *arg[], t_files *cur_files, int flags[]) {
    t_files *chosen = malloc(sizeof(t_files) * (flags[11]));
    int j = 0;

    for (int i = flags[0]; i < flags[12]; i++) {
        if (mx_get_arr_index(dirs, arg[i]) < 0 && !MX_ISROOT(arg[i])) {
            files[j] = arg[i];
            j++;
        }
    }
    mx_sort_ascii(files, flags);
    mx_print_format(cur_files, flags);
    free(files);
    if (j != 0 && j < flags[12] - flags[0])
        mx_printchar('\n');
}

