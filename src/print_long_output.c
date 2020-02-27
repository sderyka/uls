#include "../inc/uls.h"

static char *get_groupname(struct stat s_stat);
static void print_long(t_longout output[], int n);

void mx_print_long_output(char **files, int flags[], 
	                      struct stat arr_stat[]) {
    // int max_lens[5];
    // char **sizes = mx_arrchar_new(flags[11]);
    struct passwd *pwd;
    int n = mx_count_arr_el(files);
    t_longout output[n];

    for (int i = 0; files[i] && flags[1] == 1; i++) {
        output[i].filename = files[i];
        output[i].mode = arr_stat[i].st_mode;
        output[i].nlink = (int)(arr_stat[i].st_nlink);
        output[i].size = (int)(arr_stat[i].st_size);
    	pwd = getpwuid(arr_stat[i].st_uid);
        output[i].username = pwd->pw_name;
        output[i].groupname = get_groupname(arr_stat[i]);
    }
    print_long(output, n);
}

static char *get_groupname(struct stat s_stat) {
    struct group *grp;
    char *rez;

    grp = getgrgid(s_stat.st_gid);
        if (grp)
            rez = grp->gr_name;
        else
            rez = mx_itoa(s_stat.st_gid);
    return rez;
}

static void print_long(t_longout output[], int n) {
    for (int i = 0; i < n; i++) {
        mx_print_type_permissions(output[i].mode);
        mx_printchar(' ');
        mx_printint(output[i].nlink);
        mx_printchar(' ');
        mx_printstr(output[i].username);
        mx_printchar(' ');
        mx_printstr(output[i].groupname);
        mx_printchar(' ');
        mx_printint(output[i].size);
        mx_printchar(' ');
        // mx_printstr(output[i].filename);
        mx_printchar('\n');
    }
}
