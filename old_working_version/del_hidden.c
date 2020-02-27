#include "../inc/uls.h"

static _Bool is_A_flag(char *file);

// flags: [a] - 1, [A] - 2, [4] - f
void mx_del_hidden(char **files, int flags[]) {
    int count = 0;
    int i = 0;
    int temp = 0;

    mx_sort_ascii(files, flags);
    if (flags[2] != 1 && flags[4] != 1) {
        for (; files[i]; i++) {
            if ((flags[3] == 1 && is_A_flag(files[i])) 
                || (flags[3] == 0 && files[i][0] == '.')) {
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

static _Bool is_A_flag(char *file) {
    _Bool rez = 0;

    if (mx_strcmp(file, "..") == 0 || mx_strcmp(file, ".") == 0)
        rez = 1;
    return rez;
}
