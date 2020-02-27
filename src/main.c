#include "../inc/uls.h"

// flags: [0] - 1st non-flag arg,
int main(int argc, char *argv[]) {

    char *flags = mx_get_input_flags(argc, argv);
    char **args = mx_get_args(argc, argv);
    t_obj *filelist = mx_set_current_dir(char *dir, char *flags);

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
