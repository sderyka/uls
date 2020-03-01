#include "../inc/uls.h"

int main(int argc, char *argv[]) {

    char *flags = mx_get_input_flags(argc, argv);
    printf("%s\n", flags);
    char **args = mx_get_args(argc, argv);
    mx_print_strarr(args, " ");
    t_obj *filelist = mx_set_current_dir(".", NULL, flags);

    mx_print_strarr(args, "%");
    system("leaks -q uls");
    printf("%s\n", (char *)filelist);
    return 0;
}
