#include "../inc/uls.h"

static char *set_path(char *filename, char *past_path);
static struct stat get_stats(char *path);

t_obj **mx_set_current_dir(char *dir, char *past_path, char *flags) {
    t_obj **filelist = NULL;
    char **files = mx_read_files(dir);

    mx_sort_ascii(files, flags);
    mx_del_hidden(files, flags);
    filelist = mx_get_list(files, past_path);
    free(files);
    return filelist;
}

t_obj **mx_get_list(char **files, char *past_path) {
    t_obj **filelist = malloc(sizeof(t_obj) * (mx_count_arr_el(files) + 1));
    t_obj *current;

    filelist[mx_count_arr_el(files)] = NULL;
    for (int i = 0; files[i]; i++) {
        current = mx_create_obj(files[i]);
        current->path = set_path(files[i], past_path);
        current->stat = get_stats(current->path);
        filelist[i] = current;
    }
    return filelist;
}

static char *set_path(char *filename, char *past_path) {
    char *temp = NULL;
    char *temp2 = NULL;
    char *rez = NULL;

    if (!past_path) {
        if (!MX_ISROOT(filename))
            temp = mx_strjoin(".", "/");
    }
    else
        temp = mx_strjoin(past_path, "/");
    temp2 = mx_strjoin(temp, filename);
    rez = temp2;
    mx_strdel(&temp);
    mx_strdel(&temp2);
    return rez;
}

static struct stat get_stats(char *path) {
    struct stat s_curstat;

    stat(path, &s_curstat);
    return s_curstat;
}

// пофрішити все
