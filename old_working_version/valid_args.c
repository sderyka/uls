#include "../inc/uls.h"

static _Bool is_minus(char *file);

int mx_valid_args(int start, int argc, char *arg[], char **all) {
    _Bool flag = 0;
    int count = 0;

    if (start != 0) {
        for (int i = start; i < argc; i++) {
            if ((mx_get_arr_index(all, arg[i]) < 0 && !MX_ISROOT(arg[i])) 
                || is_minus(arg[i])) {
                if (!is_minus(arg[i]) || (is_minus(arg[i]) && i == argc - 1))
            	    flag = 1;
                mx_check_error(2, arg[i], '-');
            }
            count++;
        }
        if (flag)
            exit(0);
    }
    return count;
}

static _Bool is_minus(char *file) {
    _Bool rez = 0;

    if (mx_strcmp(file, "-") == 0)
        rez = 1;
    return rez;
}
