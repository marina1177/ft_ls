/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 00:05:07 by wzei              #+#    #+#             */
/*   Updated: 2019/10/23 15:04:15 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

void	print_long_entry(t_fileinfo *file, t_max_out *max, char *path)
{
	t_long_out	l_o;

	init_long_output(&l_o, file);
	if (l_o.f_type == '-' || l_o.f_type == 'd')
		print_reg_dir(&l_o, file, max);
	if (l_o.f_type == 'l')
		print_link(&l_o, file, path, max);
	if (l_o.f_type == 'b' || l_o.f_type == 'c' ||
		l_o.f_type == 'f' || l_o.f_type == 's')
		print_device(&l_o, file, max);
	return ;
}
