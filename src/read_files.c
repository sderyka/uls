#include "../inc/uls.h"

char **mx_read_files(char *dir) {
    DIR *s_dir = opendir(dir);
    struct dirent *s_file;
    char **file_names = NULL;
    int count = 0;

    if (s_dir) {
        s_file = readdir(s_dir);
        for (; readdir(s_dir) != NULL; count++);
        closedir(s_dir);
        s_dir = opendir(dir);
        file_names = mx_arrchar_new(count + 1);
        for (int i = 0; (s_file = readdir(s_dir)) != NULL; i++) {
            file_names[i] = mx_strdup(s_file->d_name);
        }
        closedir(s_dir);
    }
    return file_names;
}

