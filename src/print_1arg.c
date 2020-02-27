#include "../inc/uls.h"

// flags: [0] - № of first non-flag arg
void mx_print_1arg(char *dir, int flags[]) {
    t_cur_dir cur;

    if (flags[0] == 0)
        dir = ".";
    cur = mx_set_current_dir(dir, NULL, flags);
    mx_print_format(t_files *files, flags);
    
    system("leaks -q uls");
    exit(0);
}
