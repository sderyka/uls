#include "../inc/uls.h"

char **mx_get_stats(char **all, t_files *files, int flags[]) {
    struct stat s_curstat;
    char **dirs = mx_arrchar_new(flags[11]);
    int j = 0;

    for (int i = 0; all[i]; i++) {
        stat(all[i], &s_curstat);
        (*files[i].s_stat) = s_curstat;
        if (MX_ISDIR(s_curstat.st_mode)) {
            dirs[j] = all[i];
            j++;
        }
    }
    mx_sort_ascii(dirs, flags);
    return dirs;
}

