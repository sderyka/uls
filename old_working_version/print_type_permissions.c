#include "../inc/uls.h"

static void print_permissions(mode_t mode);

void mx_print_type_permissions(mode_t mode) {
    mx_printstr((MX_ISDIR(mode)) ? "d" : "");
    mx_printstr((MX_ISREG(mode)) ? "-" : "");
    mx_printstr((MX_ISLNK(mode)) ? "l" : "");
    mx_printstr((MX_ISCHR(mode)) ? "c" : "");
    mx_printstr((MX_ISBLK(mode)) ? "b" : "");
    mx_printstr((MX_ISSOCK(mode)) ? "s" : "");
    mx_printstr((MX_ISFIFO(mode)) ? "p" : "");
    print_permissions(mode);
}

static void print_permissions(mode_t mode) {
    mx_printstr((mode & S_IRUSR) ? "r" : "-");
    mx_printstr((mode & S_IWUSR) ? "w" : "-");
    if (MX_ISUID(mode))
		mx_printstr((MX_IXUSR(mode)) ? "s" : "S");
	else
		mx_printstr(MX_IXUSR(mode) ? "x" : "-");
    mx_printstr((mode & S_IRGRP) ? "r" : "-");
    mx_printstr((mode & S_IWGRP) ? "w" : "-");
	if (MX_ISGID(mode))
		mx_printstr((MX_IXGRP(mode)) ? "s" : "S");
	else
		mx_printstr((MX_IXGRP(mode)) ? "x" : "-");
    mx_printstr((mode & S_IROTH) ? "r" : "-");
    mx_printstr((mode & S_IWOTH) ? "w" : "-");
	if (MX_ISTXT(mode))
		mx_printstr((MX_IXOTH(mode)) ? "t" : "T");
	else
		mx_printstr((MX_IXOTH(mode)) ? "x" : "-");
}
