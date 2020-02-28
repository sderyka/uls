#include "../inc/uls.h"

static bool check_valid_arg(char *arg, t_obj *filelist);
static void add_folder(char **folders_arr, char *folder, int folders_count);

char **mx_get_args(int argc, char *argv[], t_obj *filelist) {
    char **folders = NULL;
    int i = 1;

    for (; i < argc && argv[i][0] == '-'
        && !MX_IS2MINUS(argv[i]) && !MX_ISMINUS(argv[i]); i++);
    for (; i < argc; i++) {
        if (check_valid_arg(argv[i]))
            add_folder(folders, argv[i], argc - i);
        else
            mx_check_error(2, argv[i], '-');
    }
    return folders;
}

static void add_folder(char **folders_arr, char *folder, int folders_count) {
    int i;

    if (folders_arr == NULL) {
        folders_arr = malloc(sizeof(char *) * (folders_count + 1));
        folders_arr[folders_count] = NULL;
    }
    for (i = 0; folders_arr; i++);
    folders_arr[i] = mx_strdup(folder);
}

static bool check_valid_arg(char *arg, t_obj *filelist) {
    bool rez = 1;
    char **files = mx_extract_filenames(filelist);

    if (mx_get_arr_index(files, arg) < 0 && !MX_ISROOT(arg))
        rez = 0;
    return rez;
}
