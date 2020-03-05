#include "../inc/uls.h"

static bool check_valid_arg(char *arg, char **cur_dir_files);
static void add_name(char **args_arr, char *name, int *count);

char **mx_get_args(int argc, char *argv[]) {
    char **args = mx_arrchar_new(argc);
    char **cur_dir_files = mx_read_files(".");
    int args_count = 0;
    int i = 1;

    for (; i < argc && argv[i][0] == '-'
        && !MX_IS2MINUS(argv[i]) && !MX_ISMINUS(argv[i]); i++);
    for (; i < argc; i++) {
        if (!MX_IS2MINUS(argv[i])) {
            if (check_valid_arg(argv[i], cur_dir_files)) {
                add_name(args, argv[i], &args_count);
            }
            else
                mx_check_error(2, argv[i], '-');
        }
    }
    free(cur_dir_files);
    return ((mx_count_arr_el(args) > 0) ? args : NULL);
}

static void add_name(char **args_arr, char *name, int *count) {
    args_arr[*count] = mx_strdup(name);
    (*count)++;
}

static bool check_valid_arg(char *arg, char **cur_dir_files) {
    bool rez = 1;

    if (mx_get_arr_index(cur_dir_files, arg) < 0 && !MX_ISROOT(arg))
        rez = 0;
    return rez;
}
