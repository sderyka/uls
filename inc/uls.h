#ifndef ____uls_h____
#define ____uls_h____

#include "libmx.h"

#include <sys/types.h>
#include <sys/acl.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>
#include <pwd.h>
#include <sys/xattr.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#ifndef __structures_uls__
#define __structures_uls__

// typedef struct s_files {
// 	char *filename;
//     struct stat s_stat;
//     // struct s_files *next;
// } t_files;

// typedef struct s_cur_dir {
//     char *path;
//     int count;
//     t_files *files;
//     char **dir_files;
// } t_cur_dir;


typedef struct s_obj {
    char *name; 
    struct stat stat;
    struct s_obj *content;
    char *path;
    struct s_obj *next;
} t_obj;

#endif

#ifndef __file_mode__
#define __file_mode__

#define	MX_ISDIR(m) ((m & 0170000) == 0040000)	/* directory */
#define	MX_ISCHR(m) ((m & 0170000) == 0020000)	/* char special */
#define	MX_ISBLK(m) ((m & 0170000) == 0060000)	/* block special */
#define	MX_ISREG(m) ((m & 0170000) == 0100000)	/* regular file */
#define	MX_ISFIFO(m) ((m & 0170000) == 0010000)	/* fifo */
#define	MX_ISLNK(m) ((m & 0170000) == 0120000)	/* symbolic link */
#define	MX_ISSOCK(m) ((m & 0170000) == 0140000)	/* socket */

#define	MX_ISUID(m) (m & 0004000)
#define	MX_IXUSR(m) (m & 0000100)
#define	MX_ISGID(m) (m & 0002000)
#define	MX_IXGRP(m) (m & 0000010)
#define	MX_ISTXT(m) (m & 0001000)
#define	MX_IXOTH(m) (m & 0000001)

#endif

#define MX_ISROOT(arg) (mx_strcmp(arg, "/") == 0)
#define MX_ISMINUS(arg) (mx_strcmp(arg, "-") == 0)
#define MX_ISSTART_DIR(arg) (mx_strcmp(arg, ".") == 0)

// void mx_write_flags(int argc, char *arg[], int flags[]);
void mx_check_error(int errnum, char *filename, char c);
t_cur_dir mx_set_current_dir(char *dir, char *past_path, int flags[]);
char **mx_read_files(char *dir);
void mx_del_hidden(char **files, int flags[]);
void mx_sort_ascii(char **files, int flags[]);
int mx_valid_args(int argc, char *arg[], int flags[]);
char **mx_get_stats(char **all, t_files *files, int flags[]);
int mx_find_max(char **strs);
void mx_print_cols(char **files);
void mx_print_format(t_files *files, int flags[]);
void mx_print_1arg(char *dir, int flags[]);
void mx_print_files(char *arg[], t_files *files, char **dirs, 
                    int flags[]);
void mx_print_dirs(char *arg[], char **dirs, int flags[]);
void mx_print_long_output(t_files *files, int flags[]);
void mx_print_type_permissions(mode_t mode);

#endif
