/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udate_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:31:08 by wzei              #+#    #+#             */
/*   Updated: 2019/10/22 19:34:29 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

void	udate_max(t_fileinfo *file, t_max_out *max)
{
	unsigned long	acc;
	struct stat		st;
	struct passwd	*pass;
	struct group	*gr;

	st = file->ft_stat;
	gr = getgrgid(st.st_gid);
	pass = getpwuid(st.st_uid);
	if ((acc = ft_strlen(file->name)) > max->name)
		max->name = acc;
	if ((acc = ft_strlen((gr->gr_name))) > max->group)
		max->group = acc;
	if ((acc = ft_strlen((pass->pw_name))) > max->user)
		max->user = acc;
	if ((acc = num_len(st.st_nlink)) > max->lnk)
		max->lnk = acc;
	if ((acc = num_len(st.st_size)) > max->size)
		max->size = acc;
	if (((acc = num_len(major(st.st_rdev))) > max->major) &&
			file->type != directory &&
			file->type != regular &&
			file->type != symbolic_link)
		max->major = acc;
	if ((acc = num_len(minor(st.st_rdev))) > max->minor)
		max->minor = acc;
	max->blk += st.st_blocks;
}
