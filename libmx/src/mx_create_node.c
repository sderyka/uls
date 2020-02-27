#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *tmp;
    tmp = malloc(sizeof(t_list));
    if (tmp) {
        tmp -> data = data;
        tmp -> next = NULL;
    }
    return tmp;
}
