#include "../inc/uls.h"

static void add_to_flags(char **flags_arr, char flag, int *i);
static void error_illegal_option(char c);

char *mx_get_input_flags(int argc, char *argv[]) {
    char *flags = NULL;
    int index = 0;

    if (argc > 1) {
        for (int i = 1; i < argc && argv[i][0] == '-'; i++) {
            if (mx_strcmp(argv[i], "--") == 0 || mx_strcmp(argv[i], "-") == 0)
                break;
            for (int j = 1; j < mx_strlen(argv[i]); j++) {
                if (mx_get_char_index(MX_MYFLAGS, argv[i][j]) == -1)
                    error_illegal_option(argv[i][j]);
                add_to_flags(&flags, argv[i][j], &index);
            }
        }
    }
    // flags = mx_flag_priority(flags);
    return flags;
}

static void add_to_flags(char **flags_arr, char flag, int *i) {
    if (*flags_arr == NULL)
        *flags_arr = mx_strnew(mx_strlen(MX_MYFLAGS) * 2);
    if (*i >= mx_strlen(MX_MYFLAGS) * 2)
        mx_realloc(flags_arr, (mx_strlen(*flags_arr) + 1));
    (*flags_arr)[*i] = flag;
    (*i)++;
}

static void error_illegal_option(char c) {
    mx_print_error("uls: illegal option -- ");
    mx_print_error(&c);
    mx_print_error("\nusage: ls [-");
    mx_print_error(MX_MYFLAGS);
    mx_print_error("] [file ...]\n");
    exit(1);
}
// пофрішити флаги
