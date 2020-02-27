#include "../inc/uls.h"

void mx_check_error(int errnum, char *filename, char c) {
    char *errors[] = {"usage: uls [-la1dfinp] [file ...]\n", 
                      "uls: illegal option -- ", "uls: ",
                      "\n", ": No such file or directory\n"};
    char *s = &c;

    if (errnum == 1 || errnum == 2) {
            mx_print_error(errors[errnum]);
            mx_print_error((errnum == 1) ? s : filename);
            mx_print_error(errors[errnum + 2]);
    }
    if (errnum == 1 || errnum == 0)
        mx_print_error(errors[0]);
    if (errnum != 2)
        exit(0);
}
