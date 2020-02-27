#include "libmx.h"

void mx_pop_back(t_list **list) {
    t_list *last = *list;

    if (list == NULL || *list == NULL)
        return;
    if ((*list) -> next == NULL) {
        free(*list);
        *list = NULL;
        return;
    }
    while(last -> next -> next != NULL)
        last = last -> next;
    free(last -> next);
    last -> next = NULL;
}
