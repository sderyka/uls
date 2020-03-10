#include "../inc/uls.h"

static bool check_if_change_dir(char **args, int argc, char *last_arg);

int main(int argc, char *argv[]) {
    char *flags = mx_get_input_flags(argc, argv);
    // printf("%s\n", flags);
    char **args = mx_get_args(argc, argv);
    t_obj **filelist = mx_set_current_dir(".", NULL, flags);

    if (check_if_change_dir(args, argc, argv[argc - 1]))
        mx_print_format(filelist, flags);
    else {
        mx_sort_ascii(args, flags);
        mx_print_args(args, flags);
    }
    // free(filelist);
    // free(args);
    // free(flags);
    // system("leaks -q uls");
    // printf("%s\n", "\n");
    // char **test = mx_read_files("/dev");
    // mx_print_strarr(test, " ");
    // free(test);
    return 0;
}

static bool check_if_change_dir(char **args, int argc, char *last_arg) {
    bool rez = 0;

    if (args == NULL) {
        if (argc == 1 || MX_IS2MINUS(last_arg)
        	|| (last_arg[0] == '-' && !MX_ISMINUS(last_arg))) {
            rez = 1;
        }
    }
    return rez;
}
