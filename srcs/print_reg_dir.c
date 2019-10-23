/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_reg_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:57:42 by wzei              #+#    #+#             */
/*   Updated: 2019/10/23 15:12:11 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

void	print_reg_dir(t_long_out *l_o, t_fileinfo *file, t_max_out *max)
{
	ft_printf("%c%s%c %*.d %-*.*s  %-*.*s  %s%*.*d %s %s\n",
		l_o->f_type, l_o->rgh, l_o->x_attr,
		(int)max->lnk, (int)((l_o->st).st_nlink),
		(int)max->user, (int)ft_strlen((l_o->pass)->pw_name),
		(l_o->pass)->pw_name,
		(int)max->group, (int)ft_strlen((l_o->gr)->gr_name),
		(l_o->gr)->gr_name,
		((int)max->major == 0 ? "" : "\t "),
		(int)max->size, (int)num_len((l_o->st).st_size),
		(int)(l_o->st).st_size, time,
		file->name);
}
