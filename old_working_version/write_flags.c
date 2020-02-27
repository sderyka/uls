#include "../inc/uls.h"

static int check_j_for_segfault(int j, int argc, char *arg[]);
// [-laAf1Cmdi?np]
// flags: [0] - № of non-flag arg, [10] - the value of wrong flag
void mx_write_flags(int argc, char *arg[], int flags[]) {
    char symbols[11] = {' ', 'l', 'a', 'A', 'f', '1', 'C', 'm', 'd', 'i', ' '};
    int j = (argc > 1) ? 1 : 0;

    for (int f; j < argc && arg[j][0] == '-' && arg[j][1] != '-'; j++) {
        for (int i = 1; i < mx_strlen(arg[j]); i++) {
            for (f = 1; f < 10; f++) {
                if (flags[f] != 1)
                    flags[f] = (arg[j][i] == symbols[f]) ? 1 : 0;
                if (arg[j][i] == symbols[f])
                    break;
            }
            if (f == 10)
                mx_check_error(1, NULL, arg[j][i]);
        }
    }
    flags[0] = check_j_for_segfault(j, argc, arg);
    flags[12] = argc;
}

static int check_j_for_segfault(int j, int argc, char *arg[]) {
    // if there were just flags-type arguments, set j on 0
    int rez = ((j <= argc - 1) ? j : 0);

    // if "--" is found, set j on the next argument, if case it exits, or on 0
    if (arg[rez][0] == '-' && arg[rez][1] == '-') {
        if (rez + 1 < argc)
            rez++;
        else
            rez = 0;
    }
    return rez;
}

// static void verify_flags(int flags, int argc, char *arg[]) {
    
// }
