#include "../inc/uls.h"

int main(int argc, char *argv[]) {

    char *flags = mx_get_input_flags(argc, argv);
    t_obj *filelist = mx_set_current_dir(".", NULL, flags);
    char **args = mx_get_args(argc, argv, filelist);

    system("leaks -q uls");
    return 0;
}
