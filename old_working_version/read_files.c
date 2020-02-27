#include "../inc/uls.h"

char **mx_read_files(char *dir, int flags[]) {
    DIR *s_dir = opendir(dir);
    struct dirent *s_file = readdir(s_dir);
    char **file_names;
    int count = 0;

    for (; readdir(s_dir) != NULL; count++);
    closedir(s_dir);
    s_dir = opendir(dir);
    file_names = mx_arrchar_new(count * 2);
    for (int i = 0; (s_file = readdir(s_dir)) != NULL; i++) {
        file_names[i] = s_file->d_name;
    }
    closedir(s_dir);
    mx_del_hidden(file_names, flags);
    flags[11] = mx_count_arr_el(file_names);
    return file_names;
}
