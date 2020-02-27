#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    char *p = (char *)haystack;
    int len1 = mx_strlen(haystack);
    int len2 = mx_strlen(needle);

    if (needle[0] == '\0')
        return p;
	for (int count = 0; count <= (len1 - len2); count++) {
	    int j = 0;
	    for (int i = 0; p[i] == needle[i] && p[i] != '\0'; i++) {
	        j++;
	    }
	    if (j == len2)
	        return p;
	    p++;
    }
    return NULL;
}
