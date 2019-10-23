/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_device.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:00:59 by wzei              #+#    #+#             */
/*   Updated: 2019/10/23 15:37:49 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

void	print_device(t_long_out *l_o, t_fileinfo *file, t_max_out *max)
{
	int	major;
	int	minor;

	major = (int)major((l_o->st).st_rdev);
	minor = (int)minor((l_o->st).st_rdev);
	ft_printf("%c%s%c %*.d %-*.*s  %-*.*s  %*.*d, %*.*d %s %s\n",
		l_o->f_type, l_o->rgh, l_o->x_attr,
		(int)max->lnk, (int)((l_o->st).st_nlink),
		(int)max->user, (int)ft_strlen((l_o->pass)->pw_name),
		(l_o->pass)->pw_name,
		(int)max->group, (int)ft_strlen((l_o->gr)->gr_name),
		(l_o->gr)->gr_name,
		(int)max->major, (int)num_len(major), major,
		(int)max->minor, (int)num_len(minor), minor,
		l_o->time, file->name);
}
