#include "libmx.h"

void mx_pop_front(t_list **list) {
    t_list *new_list;

    if (list == NULL || *list == NULL)
        return;
    new_list = (*list)->next;
    free(*list);
    *list = new_list;
}
