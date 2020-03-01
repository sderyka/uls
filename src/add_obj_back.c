#include "../inc/uls.h"

void mx_add_obj_back(t_obj *obj, t_obj **list) {
    t_obj *last;

    if ((obj == NULL) || (list == NULL))
        return;
    if (*list == NULL)
        *list = obj;
    else {
        last = *list;
        while(last->next != NULL)
            last = last->next;
        last->next = obj;
    }
}
