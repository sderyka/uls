#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    char *s;
    int count = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (mx_strcmp(arr[i], arr[j]) > 0) {
                s = arr[i];
                arr[i] = arr[j];
                arr[j] = s;
                count++;
            }
        }
    }
    return count;
}

