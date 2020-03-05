#include "../inc/uls.h"

static void split_modes(t_obj **filelist, t_obj **files, t_obj **dirs);
static void separate_files(t_obj *first_file, t_obj *first_dir, char *flags);

void mx_print_args(char **args, char *flags) {
    t_obj **filelist = mx_get_list(args, NULL);
    int n = mx_count_arr_el(args);
    t_obj **files = malloc(sizeof(t_obj) * (n + 1));
    t_obj **dirs = malloc(sizeof(t_obj) * (n + 1));

    split_modes(filelist, files, dirs);
    free(filelist);
    mx_print_format(files, flags);
    separate_files(files[0], dirs[0], flags);
    for (int i = 0; dirs[i]; i++) {
        filelist = mx_set_current_dir((dirs[i])->name, (dirs[i])->path, flags);
        if (i != 0)
            mx_printchar('\n');
        if (n != 1) {
            mx_printstr((dirs[i])->name);
            mx_printstr(":\n");
        }
        mx_print_format(filelist, flags);
        // free(dirs);
        // free(files);
        // free(filelist);
    }
}

static void split_modes(t_obj **filelist, t_obj **files, t_obj **dirs) {
    int f = 0;
    int d = 0;

    for (int i = 0; filelist[i]; i++) {
        if (MX_ISDIR(((filelist[i])->stat).st_mode)) {
            dirs[d] = filelist[i];
            d++;
        }
        else {
            files[f] = filelist[i];
            f++;
        }
    }
    files[f] = NULL;
    dirs[d] = NULL;
}

static void separate_files(t_obj *first_file, t_obj *first_dir, char *flags) {
    if (first_file && first_dir) {
    	if (mx_is_flag_present(flags, 'm'))
    	    mx_printchar(',');
        mx_printchar('\n');
    }
}
