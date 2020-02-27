#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int count = 0;
    int flag = 1;

	if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c && flag == 1) {
            count++;
            flag = 0;
        }
        if (str[i] == c) {
            flag = 1;
        }
    }
    return count;
}
