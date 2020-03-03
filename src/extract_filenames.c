#include "../inc/uls.h"

char **mx_extract_filenames(t_obj **filelist) {
    char **files;
    int count = 0;

    for (; filelist[count]; count++);
    files = mx_arrchar_new(count * 2);
    for (int i = 0; i < count; i++) {
        files[i] = (filelist[i])->name;
    }
    return files;
}
