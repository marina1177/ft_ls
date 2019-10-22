/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_m.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:44:32 by wzei              #+#    #+#             */
/*   Updated: 2019/10/22 19:51:55 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_M_H
# define FT_LS_M_H


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
int						g_print_header;

int						parse_input(int ac, char **av);
void					print_list(t_mlist *node, t_max_out *max,
										char *dir_name);
void					print_long_entry(t_fileinfo *file,
										t_max_out *max, char *path);

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
void					get_dir_entries(DIR *dir, char *dir_name,
										t_mlist **entries, t_max_out *max);
unsigned long			num_len(unsigned long num);
#endif
