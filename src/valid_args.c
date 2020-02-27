#include "../inc/uls.h"

int mx_valid_args(int argc, char *arg[], int flags[]) {
    char **files = mx_read_files(".", flags);
    _Bool flag = 0;
    int count = 0;

    for (int i = flags[0]; i != 0 && i < argc; i++) {
        if ((mx_get_arr_index(files, arg[i]) < 0 && !MX_ISROOT(arg[i]))
            || MX_ISMINUS(arg[i])) {
            if (!MX_ISMINUS(arg[i]) 
                || (MX_ISMINUS(arg[i]) && i == argc - 1)) {
        	    flag = 1;
            }
            mx_check_error(2, arg[i], '-');
        }
        count++;
    }
    if (flag)
        exit(0);
    return count;
}
