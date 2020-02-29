#include "../inc/uls.h"

int main(int argc, char *argv[]) {

    char *flags = mx_get_input_flags(argc, argv);
    char **args = mx_get_args(argc, argv);
    t_obj *filelist = mx_set_current_dir(".", NULL, flags);

    mx_print_strarr(args, "$");
    printf("%s\n", filelist->name);
    system("leaks -q uls");
    return 0;
}
