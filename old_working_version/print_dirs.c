#include "../inc/uls.h"

static void print_dir(char *dir, int flags[]);

void mx_print_dirs(char *arg[], char **dirs, int flags[]) {
    char **list = mx_arrchar_new(flags[11]);
    int j = 0;

    for (int i = flags[0]; i < flags[12]; i++) {
        if (mx_get_arr_index(dirs, arg[i]) >= 0 || MX_ISROOT(arg[i])) {
            list[j] = arg[i];
            j++;
        }
    }
    mx_sort_ascii(list, flags);
    for (int i = 0; list[i]; i++) {
        if (i != 0)
            mx_printchar('\n');
        print_dir(list[i], flags);
    }
    free(list);
}

static void print_dir(char *dir, int flags[]) {
    char **files = mx_read_files(dir, flags);
    struct stat arr_stats[mx_count_arr_el(files)];
    char **dirs = mx_get_stats(files, arr_stats, flags);

    mx_printstr(dir);
    mx_printchar(':');
    mx_printchar('\n');
    mx_print_format(files, flags, arr_stats);
    free(files);
    free(dirs);
}

