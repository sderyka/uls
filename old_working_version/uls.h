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

#ifndef __stats_h__
#define __stats_h__

typedef struct s_stats {
	char *filename;
    struct stat s_stat;
    // char **dir_files;
    // struct s_stats *next;
} t_stats;

typedef struct s_longout {
	char *filename;
    mode_t	mode;
    int nlink;
    char *username;
    char *groupname;
    int size;
    // time_t	mod_time;
} t_longout;

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

#endif

#ifndef __file_permissions__
#define __file_permissions__

#define	MX_ISUID(m) (m & 0004000)
#define	MX_IXUSR(m) (m & 0000100)
#define	MX_ISGID(m) (m & 0002000)
#define	MX_IXGRP(m) (m & 0000010)
#define	MX_ISTXT(m) (m & 0001000)
#define	MX_IXOTH(m) (m & 0000001)

#endif

#define MX_ISROOT(arg) (mx_strcmp(arg, "/") == 0)

void mx_write_flags(int argc, char *arg[], int flags[]);
void mx_check_error(int errnum, char *filename, char c);
char **mx_read_files(char *dir, int flags[]);
void mx_del_hidden(char **files, int flags[]);
void mx_sort_ascii(char **files, int flags[]);
int mx_valid_args(int start, int argc, char *arg[], char **all);
char **mx_get_stats(char **all, struct stat arr_stat[], int flags[]);
int mx_find_max(char **strs);
void mx_print_cols(char **files);
void mx_print_format(char **files, int flags[], struct stat arr_stats[]);
void mx_print_1arg(char **files, int flags[], char *dir, 
	               struct stat arr_stats[]);
void mx_print_files(char *arg[], struct stat arr_stat[], char **dirs, 
                    int flags[]);
void mx_print_dirs(char *arg[], char **dirs, int flags[]);
void mx_print_long_output(char **files, int flags[], 
	                      struct stat arr_stats[]);
void mx_print_type_permissions(mode_t mode);

#endif
