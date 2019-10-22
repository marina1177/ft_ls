/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_entries.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:30:32 by wzei              #+#    #+#             */
/*   Updated: 2019/10/22 10:52:13 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

static int  chck_cnd(const char *name)
{
	if (g_flags.f_sort_ & SORTI_A_)
		return (1);
	if (name[0] != '.')
        return (1);
	return (0);
}

void	get_dir_entries(DIR *dir, char *dir_name, t_mlist **entries,
                        t_max_out *max)
{
	struct dirent	*d_d;
	t_fileinfo		file;
	char			*dir_name_slash;

	d_d = NULL;
	dir_name_slash = ft_strjoin(dir_name, "/");
	while ((d_d = readdir(dir)) && dir->__dd_loc < 4080)
	{
		get_fileinfo(&file, dir_name_slash, d_d->d_name);
		if (chck_cnd(d_d->d_name))
		{
			udate_max(&file, max);
			ft_mlstpush(entries, ft_mlstnew(&file, sizeof(t_fileinfo)));
		}
	}
	if (dir->__dd_loc == 4080)
	{
		get_fileinfo(&file, dir_name_slash, d_d->d_name);
		if (chck_cnd(d_d->d_name))
		{
			udate_max(&file, max);
			ft_mlstpush(entries, ft_mlstnew(&file, sizeof(t_fileinfo)));
		}
	}
	ft_strdel(&dir_name_slash);
}
