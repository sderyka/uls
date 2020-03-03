#include "../inc/uls.h"

static void print_arr_separeted(char **arr, const char *delim, char *flags);

void mx_print_format(t_obj **filelist, char *flags) {
    char **files = mx_extract_filenames(filelist);

    if (mx_is_flag_present(flags, '1'))
        print_arr_separeted(files, "\n", flags);
    else if (mx_is_flag_present(flags, 'm'))
        print_arr_separeted(files, ",", flags);
    // else if (mx_is_flag_present(flags, 'l'))
    //     mx_print_long_output(filelist, flags);
    else
        mx_print_cflag(files);
    free(files);
}

static void print_arr_separeted(char **arr, const char *delim, char *flags) {
    if (arr != NULL && delim != NULL) {
        for (int i = 0; arr[i]; i++) {
            mx_printstr(arr[i]);
            if (arr[i + 1] != NULL)
                write(1, delim, 1);
                if (mx_is_flag_present(flags, 'm'))
                    mx_printchar(' ');
        }
        mx_printchar('\n');
    }
}
// переробити під таби і вивід m
