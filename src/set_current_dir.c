#include "../inc/uls.h"

static char *set_path(char *dir, char *past_path);

t_cur_dir mx_set_current_dir(char *dir, char *past_path, int flags[]) {
    t_cur_dir current;
    char **files = mx_read_files(dir, flags);

    current.path = set_path(dir, past_path);
    current.count = mx_count_arr_el(files);
    current.files = malloc(sizeof(t_files) * current.count);
    current.dir_files = mx_get_stats(files, current.files, flags);
    return current;
}

static char *set_path(char *dir, char *past_path) {
    char *temp = NULL;
    char *rez = NULL;

    if (past_path)
        temp = mx_strjoin(past_path, "/");
    rez = mx_strjoin(temp, dir);
    mx_strdel(&temp);
    return rez;
}
// пофрішити все
