#include "../inc/uls.h"

static int find_len(char **files, int count, int *rows);
static void print_file(char *file, int max);

void mx_print_cflag(char **files) {
    int rows;
    int max;
    int count = mx_count_arr_el(files);
    int p = 0;
    int i = 0;

    max = find_len(files, count, &rows);
    while (files[i] && p < rows) {
        print_file(files[i], max);
        if (!files[i + rows]) {
            mx_printchar('\n');
            i = ++p;
        }
        else
            i = i + rows;
    }
}

static int find_len(char **files, int count, int *rows) {
    int max = mx_find_max(files);
    struct winsize s_w;
    int cols;

    ioctl(0, TIOCGWINSZ, &s_w);
    cols = s_w.ws_col / max;
    *rows = (count % cols == 0) ? (count / cols) : (count / cols + 1);
    return max;
}

static void print_file(char *file, int max) {
    int len = mx_strlen(file);
    int spaces = max - len;

    mx_printstr(file);
    while (spaces > 0) {
        write(1, " ", 1);
        spaces--;
    }
}
