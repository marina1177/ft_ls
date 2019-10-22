/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:37:39 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/22 20:07:15 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_mlstpush(t_mlist **mlst, t_mlist *nlst)
{
	t_mlist		*tmp;

	if (!mlst || !nlst)
		return ;
	if (!(tmp = *mlst))
	{
		*mlst = nlst;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nlst;
	nlst->prev = tmp;
}
