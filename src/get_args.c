#include "../inc/uls.h"

static bool check_valid_arg(char *arg, char **cur_dir_files);
static void add_name(char **args_arr, char *name, int *count);
static int get_last_char_index(const char *str, char c);
static char *write_part_of_str(char *str, int start, int end);

char **mx_get_args(int argc, char *argv[]) {
    char **args = mx_arrchar_new(argc);
    char **cur_dir_files = mx_read_files(".");
    int args_count = 0;
    int i = 1;

    for (; i < argc && argv[i][0] == '-'
        && !MX_IS2MINUS(argv[i]) && !MX_ISMINUS(argv[i]); i++);
    for (; i < argc; i++) {
        if (!MX_IS2MINUS(argv[i])) {
            if (check_valid_arg(argv[i], cur_dir_files))
                add_name(args, argv[i], &args_count);
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
    int slash_index = get_last_char_index(arg, '/');
    char **slash_dir_files;
    char *dir = NULL;
    char *name = NULL;

    if (MX_ISROOT(arg))
        return 1;
    if (slash_index < 0 && mx_get_arr_index(cur_dir_files, arg) < 0)
        return 0;
    dir = write_part_of_str(arg, 0, slash_index);
    name = write_part_of_str(arg, slash_index + 1, mx_strlen(arg));
    slash_dir_files = mx_read_files(dir);
    if (mx_get_arr_index(slash_dir_files, name) < 0)
        rez = 0;
    free(slash_dir_files);
    free(dir);
    free(name);
    return rez;
}

static int get_last_char_index(const char *str, char c) {
    int i = mx_strlen(str) - 1;

    for (; i >= 0; i--) {
        if (str[i] == c)
            return i;
    }
    return -1;
}

static char *write_part_of_str(char *str, int start, int end) {
    char *rez = mx_strnew(end - start);

    for (int i = 0; i < end; i++) {
        rez[i] = str[start];
        start++;
    }
    return rez;
}
