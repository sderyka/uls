#include "../inc/uls.h"

// flags: [0] - 1st non-flag arg,
// [11] - count of elements in all, [12] - argc
int main(int argc, char *argv[]) {
    int flags[13];
    mx_write_flags(argc, argv, flags);
    t_cur_dir cur = mx_set_current_dir(".", NULL, flags);

    if (flags[0] == 0 || (mx_valid_args(flags[0], argc, argv) == 1
        && (mx_get_arr_index(cur.dir_files, argv[argc - 1]) >= 0))
        || MX_ISROOT(argv[flags[0]])) {
        mx_print_1arg(argv[argc - 1], flags);
    }
    mx_print_files(argv, cur.files, flags);
    mx_print_dirs(argv, cur.dir_files, flags);
    system("leaks -q uls");
    return 0;
}
