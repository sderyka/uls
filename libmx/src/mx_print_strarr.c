#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (arr != NULL && delim != NULL) {
        for (int i = 0; arr[i] != NULL; i++) {
            mx_printstr(arr[i]);
            write(1, delim, 1);
        }
        mx_printchar('\n');
    }
}
