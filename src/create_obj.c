#include "../inc/uls.h"

t_obj *mx_create_obj(char *filename) {
    t_obj *new_obj;

    new_obj = malloc(sizeof(t_obj));
    if (new_obj) {
        new_obj->name = filename;
    }
    return new_obj;
}
