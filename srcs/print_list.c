/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 00:50:50 by wzei              #+#    #+#             */
/*   Updated: 2019/10/23 13:47:05 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

void	print_list(t_mlist *node, t_max_out *max, char *dir_name)
{
	while (node != NULL)
	{
		if (g_flags.f_output1 & OUT_LCOL)
			print_long_entry((t_fileinfo *)(node->content), max, dir_name);
		else
			ft_printf("%s\n", ((t_fileinfo *)(node->content))->name);
		node = node->next;
	}
}
