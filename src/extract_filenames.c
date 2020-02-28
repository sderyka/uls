#include "../inc/uls.h"

char **mx_extract_filenames(t_obj *filelist) {
	t_obj *temp = filelist;
    char **files;
    int count = 0;

    for (; temp; temp = temp->next)
        count++;
    temp = filelist;
    files = mx_arrchar_new(count * 2);
    for (int i = 0; i < count; i++) {
        files[i] = temp->name;
        temp = temp->next;
    }
    return files;
}
