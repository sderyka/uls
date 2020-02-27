#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    int n = mx_count_words(s, c);
    char **res = malloc(sizeof(char *) * (n + 1));
    int flag = 1;

    for (int i = 0, j = 0, h = 0; s[i] != '\0'; i++) {
    	if (s[i] != c) {
    	    res[j] = mx_realloc(res[j], h * sizeof(char));
    	    res[j][h] = s[i];
    	    h++;
    	    flag = 0;
        }
        if (s[i] == c && flag == 0) {
            res[j][h] = '\0';
            j++;
            h = 0;
            flag = 1;
        }
    }
    res[n] = NULL;
	return((s != NULL) ? (res) : (NULL));
}
