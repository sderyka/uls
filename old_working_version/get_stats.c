#include "../inc/uls.h"

char **mx_get_stats(char **all, struct stat arr_stat[], int flags[]) {
    struct stat s_stat;
    char **chosen_files = mx_arrchar_new(flags[11]);
    int j = 0;

    for (int i = 0; all[i]; i++) {
        stat(all[i], &s_stat);
        arr_stat[i] = s_stat;
        if (MX_ISDIR(s_stat.st_mode)) {
            chosen_files[j] = all[i];
            j++;
        }
    }
    mx_sort_ascii(chosen_files, flags);
    return chosen_files;
}

