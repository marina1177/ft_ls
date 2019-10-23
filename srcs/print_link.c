/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:59:15 by wzei              #+#    #+#             */
/*   Updated: 2019/10/23 15:49:33 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

void	print_link(t_long_out *l_o, t_fileinfo *file,
						char *path, t_max_out *max)
{
	size_t	len;
	char	*filename;

	filename = NULL;
	len = ft_strlen(path) + ft_strlen(file->name) + 2;
	filename = ft_strnew(len);
	ft_strlcat(filename, path, len);
	ft_strlcat(filename, "/", len);
	ft_strlcat(filename, file->name, len);
	readlink(filename, l_o->lnk, 1024);
	free(filename);
	ft_printf("%c%s%c %*.d %-*.*s  %-*.*s  %s%*.*d %s %s -> %s\n",
		l_o->f_type, l_o->rgh, l_o->x_attr,
		(int)max->lnk, (int)((l_o->st).st_nlink),
		(int)max->user, (int)ft_strlen((l_o->pass)->pw_name),
		(l_o->pass)->pw_name,
		(int)max->group, (int)ft_strlen((l_o->gr)->gr_name),
		(l_o->gr)->gr_name,
		((int)max->major == 0 ? "" : "\t "),
		(int)max->size, (int)num_len((l_o->st).st_size),
		(int)(l_o->st).st_size, l_o->time,
		file->name, l_o->lnk);
}
