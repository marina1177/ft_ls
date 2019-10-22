/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:22:28 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/22 18:55:31 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

static enum filetype get_filetype(mode_t m)
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

int	get_fileinfo(t_fileinfo *file, char *path, char *name)
{
	acl_t   acl;
	char	*filename;
	char	*acc;

	acc = NULL;
	if (ft_strcmp(path, name) != 0)
	{
		acc = ft_strjoin(path, name);
		filename = acc;
	}
	else
		filename = path;
	if (lstat(filename, &(file->ft_stat)) == -1)
		return (-1);
	acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
	file->_xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
	if (acl == NULL)
		file->_acl = 0;
	else
	{
		file->_acl = 1;
		acl_free(acl);
	}
	file->type = get_filetype(file->ft_stat.st_mode);
	ft_strcpy(file->name, name);
	ft_strcpy(file->path, path);
	free(acc);
	return (0);
}