#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *temp = mx_create_node(data);

    if ((temp == NULL) || (list == NULL))
        return;
    temp -> data = data;
    temp -> next = NULL;
    if(*list == NULL)
        *list = temp;
    else {
        t_list *last = *list;
        while(last -> next != NULL)
            last = last -> next;
        last -> next = temp;
    }
}
