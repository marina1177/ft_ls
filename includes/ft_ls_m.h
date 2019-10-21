//
// Created by Buster Charity on 13/10/2019.
//

#ifndef FT_LS_M_H
#define FT_LS_M_H


# include <stdio.h>
# include <unistd.h>

# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/xattr.h>
# include <uuid/uuid.h>
# include <sys/acl.h>

# include <errno.h>
# include <sys/ioctl.h>
# include <time.h>
# include <limits.h>

# include "libft.h"
# include "ft_printf.h"

# include "flags.h"
# include "file_info.h"
# include "ls_sort.h"

typedef unsigned char	t_1b;
typedef unsigned short	t_2b;
typedef unsigned int	t_4b;
typedef unsigned long	t_8b;

t_mlist					*g_files;
t_mlist					*g_dirs;
t_mlist					*g_err_f;
t_flags					g_flags;
t_mlist					*g_files;
int						g_file_count;

int						parse_input(int ac, char **av);
void					printList(t_mlist* node);

/*
** Error handling
*/

void					ls_file_error(char *av);
void					print_err(t_mlist *lst);

/*
** Directory traverce
*/
void					traverce_cur_dir(char *dir_name);
void					trav_dirs(t_mlist *dirs);
#endif
