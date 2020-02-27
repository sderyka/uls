#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);

    if (len1 > 0 && len2 > 0) {
        char *res = mx_strnew(len1 + len2);
        return (mx_strcat(mx_strcpy(res, s1), s2));
    }
    else if (len1 > 0)
        return (mx_strdup(s1));
    else
        return ((len2 > 0) ? (mx_strdup(s2)) : (NULL));
}

// char *mx_strjoin(char const *s1, char const *s2) {
//     char *rez = NULL;

//     if (!s1 && !s2)
//         return NULL;
//     if (!s1 || !s2)
//         return (s1) ? mx_strdup(s1) : mx_strdup(s2);
//     rez = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
//     if (rez) {
//         mx_strcpy(rez, s1);
//         mx_strcat(rez, s2);
//     }
//     return rez;
// }
