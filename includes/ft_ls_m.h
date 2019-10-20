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
//# include <uuid/uuid.h>
//# include <sys/acl.h>

# include <errno.h>
# include <sys/ioctl.h>
# include <time.h>
# include <limits.h>

# include "../libft/libft.h"

# include "./flags.h"
# include "./file_info.h"
# include "./ls_sort.h"
# include "../ft_mlst/ft_mlst.h"

typedef unsigned char	t_1b;
typedef unsigned short	t_2b;
typedef unsigned int	t_4b;
typedef unsigned long	t_8b;

t_mlist					*g_args;
t_mlist					*g_argsf;
t_flags                 g_flags;
t_mlist                 *g_files;
int                     g_file_count;

int                     parse_input(int ac, char **av);
void printList(t_mlist* node);
#endif
