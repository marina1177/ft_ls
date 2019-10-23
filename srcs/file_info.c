/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:22:28 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/23 13:55:19 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

static enum e_filetype	get_e_filetype(mode_t m)
{
	m &= S_IFMT;
	if (m == S_IFIFO)
		return (fifo);
	if (m == S_IFCHR)
		return (chardev);
	if (m == S_IFDIR)
	{
		if (g_flags.f_recur == DIR_ASFI)
			return (arg_directory);
		else
			return (directory);
	}
	if (m == S_IFBLK)
		return (blockdev);
	if (m == S_IFREG)
		return (regular);
	if (m == S_IFLNK)
		return (symbolic_link);
	if (m == S_IFSOCK)
		return (socket);
	return (unknown);
}

static void				init_str(char *path, char *name,
								char **acc, char **filename)
{
	if (ft_strcmp(path, name) != 0)
	{
		*acc = ft_strjoin(path, name);
		*filename = *acc;
	}
	else
		*filename = *path;
}

int						get_fileinfo(t_fileinfo *file, char *path, char *name)
{
	acl_t	acl;
	char	*filename;
	char	*acc;

	acc = NULL;
	init_str(path, name, &acc, &filename);
	if (lstat(filename, &(file->ft_stat)) == -1)
		return (-1);
	acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
	file->sz_xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
	if (acl == NULL)
		file->i_acl = 0;
	else
	{
		file->i_acl = 1;
		acl_free(acl);
	}
	file->type = get_e_filetype(file->ft_stat.st_mode);
	ft_strcpy(file->name, name);
	ft_strcpy(file->path, path);
	free(acc);
	return (0);
}
