#include "libmx.h"

char **mx_arrchar_new(int size) {
    char **arr;

    arr = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++)
        arr[i] = NULL;
    arr[size] = NULL;
    return arr;
}

