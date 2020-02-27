#include "../inc/uls.h"

// flags: [0] - № of first non-flag arg
void mx_print_1arg(char **files, int flags[], char *dir, 
	               struct stat arr_stats[]) {
    if (flags[0] == 0)
        mx_print_format(files, flags, arr_stats);
    else {
        free(files);
        files = mx_read_files(dir, flags);
        struct stat current_stats[mx_count_arr_el(files)];
        char **dirs = mx_get_stats(files, current_stats, flags);
        mx_print_format(files, flags, current_stats);
        free(dirs);
    }
    exit(0);
}
