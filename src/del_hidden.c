#include "../inc/uls.h"

static _Bool is_a_flag(char *file);

void mx_del_hidden(char **files, char *flags) {
    int count = 0;
    int i = 0;
    int temp = 0;

    if (!mx_is_flag_present(flags, 'a') && !mx_is_flag_present(flags, 'f')) {
        for (; files[i]; i++) {
            if ((mx_is_flag_present(flags, 'A') && is_a_flag(files[i]))
                || (!mx_is_flag_present(flags, 'A') && files[i][0] == '.')) {
                count++;
                temp = i + 1;
            }
        }
        for (i = temp - count; files[temp]; i++) {
            files[i] = files[temp];
            temp++;
        }
        for (; files[i]; i++)
            files[i] = NULL;
    }
}

static _Bool is_a_flag(char *file) {
    _Bool rez = 0;

    if (mx_strcmp(file, "..") == 0 || mx_strcmp(file, ".") == 0)
        rez = 1;
    return rez;
}
