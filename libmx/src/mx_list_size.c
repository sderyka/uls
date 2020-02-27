#include "libmx.h"

int mx_list_size(t_list *list) {
    int count = 0;
    t_list *tmp;

    tmp = list;
    while(tmp -> data != NULL) {
        count++;
        tmp = tmp -> next;
    }
    return count;
}
