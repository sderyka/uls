#include "../inc/uls.h"

static void print_arr_separeted(char **arr, const char *delim, int flags[]);

// flags: [5] - 1, [6] - C, [7] - m
void mx_print_format(t_files *files, int flags[]) {
	if (flags[5] == 1)
	    print_arr_separeted(files, "\n", flags);
	else if (flags[7] == 1)
	    print_arr_separeted(files, ",", flags);
    else if (flags[1] == 1)
        mx_print_long_output(files, flags, arr_stats);
	else
	    mx_print_cols(files);
}

static void print_arr_separeted(char **arr, const char *delim, int flags[]) {
    if (arr != NULL && delim != NULL) {
        for (int i = 0; arr[i]; i++) {
            mx_printstr(arr[i]);
            if (arr[i + 1] != NULL)
                write(1, delim, 1);
                if (flags[7] == 1)
                    mx_printchar(' ');
        }
        mx_printchar('\n');
    }
}
