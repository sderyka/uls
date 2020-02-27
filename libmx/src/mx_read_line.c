#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd && lineptr) {
        char *buf = malloc(buf_size);
        size_t n = read(fd, buf, buf_size);
        int res = 0;

        while(n > 0) {
            for (size_t i = 0; i < n; i++) {
                if (buf[i] == delim) {
                    free(buf);
                    return(res + (int)i);
                }
                *lineptr = mx_add_char(*lineptr, buf[i]);
            }
            res = res + (int)n;
            n = read(fd, buf, buf_size);
        }
    }
    return(fd && lineptr) ? (-2) : (-1);
}
