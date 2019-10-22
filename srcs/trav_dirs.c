/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trav_dirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:33:39 by wzei              #+#    #+#             */
/*   Updated: 2019/10/22 01:42:24 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

void	trav_dirs(t_mlist *dirs)
{
	while (dirs != NULL)
	{
		traverce_cur_dir(((t_fileinfo *)(dirs->content))->name);
		dirs = dirs->next;
	}
}
