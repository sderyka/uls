#include "../inc/uls.h"

t_obj *mx_add_obj(char *filename, t_obj *list) {
    t_obj *new_obj = malloc(sizeof(t_obj));

    new_obj->name = filename;
    if (list)
        list->next = new_obj;
    return new_obj;
}
