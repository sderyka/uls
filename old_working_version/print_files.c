#include "../inc/uls.h"

static _Bool is_root(char *file);

void mx_print_files(char *arg[], struct stat arr_stat[], char **dirs, 
                    int flags[]) {
    char **files = mx_arrchar_new(flags[11]);
    int j = 0;

    for (int i = flags[0]; i < flags[12]; i++) {
        if (mx_get_arr_index(dirs, arg[i]) < 0 && !is_root(arg[i])) {
            files[j] = arg[i];
            j++;
        }
    }
    mx_sort_ascii(files, flags);
    mx_print_format(files, flags, arr_stat);
    free(files);
    if (j != 0 && j < flags[12] - flags[0])
        mx_printchar('\n');
}

static _Bool is_root(char *file) {
    _Bool rez = 0;

    if (mx_strcmp(file, "/") == 0)
        rez = 1;
    return rez;
}
