#include "../inc/uls.h"

// flags: [0] - 1st non-flag arg, [10] - the value of wrong flag
// [11] - count of elements in all, [12] - argc
int main(int argc, char *argv[]) {
    int flags[13];
    mx_write_flags(argc, argv, flags);
    char **all = mx_read_files(".", flags);
    struct stat arr_stat[flags[11]];
    char **dirs = mx_get_stats(all, arr_stat, flags);

    if (flags[0] == 0 || (mx_valid_args(flags[0], argc, argv, all) < 2 
        && (mx_get_arr_index(dirs, argv[argc - 1]) >= 0)) || MX_ISROOT(argv[flags[0]])) {
        mx_print_1arg(all, flags, argv[argc - 1], arr_stat);
    }
    mx_print_files(argv, arr_stat, dirs, flags);
    mx_print_dirs(argv, dirs, flags);
    system("leaks -q uls");
    return 0;
}
