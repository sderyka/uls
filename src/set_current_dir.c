#include "../inc/uls.h"

static char *set_path(char *filename, char *past_path);
static struct stat get_stats(char *path);

t_obj *mx_set_current_dir(char *dir, char *past_path, char *flags) {
    t_obj *filelist;
    char **files = mx_read_files(dir);
    if (!MX_ISSTART_DIR(dir))
        mx_del_hidden(files, flags);
    mx_sort_ascii(files, flags);
    return (mx_get_list(files, past_path, flags));
}

t_obj *mx_get_list(char **files, char *past_path, char *flags) {
    t_obj *filelist = NULL;

    for (int i = 0; files[i]; i++) {
        filelist = mx_add_obj(files[i], filelist);
        filelist->path = set_path(files[i], past_path);
        filelist->stat = get_stats(filelist->path);
    }
    return filelist;
}

static char *set_path(char *filename, char *past_path) {
    char *temp = NULL;
    char *rez = NULL;

    if (!past_path)
        temp = mx_strjoin(".", "/");
    else
        temp = mx_strjoin(past_path, "/");
    rez = mx_strjoin(temp, filename);
    mx_strdel(&temp);
    return rez;
}

static struct stat get_stats(char *path) {
    struct stat s_curstat;

    stat(path, &s_curstat);
    return s_curstat;
}
// пофрішити все
