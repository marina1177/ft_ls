/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:37:39 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/22 20:07:32 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mlst_sort(t_mlist **list, int (*cmp)(void *, void *))
{
	t_mlist		*clist;
	t_mlist		*plist;

	if (!list || !(*list) || !((*list)->next))
		return ;
	plist = (*list)->next;
	clist = plist->next;
	while (plist)
	{
		if (!plist->prev ||
				((*cmp)(plist->prev->content, plist->content) <= 0))
		{
			plist = clist;
			(clist ? clist = clist->next : clist);
		}
		else
		{
			ft_mlstswap(plist->prev, plist);
			plist = plist->prev;
			if (plist == 0)
			{
				plist = clist;
				(clist ? clist = clist->next : clist);
			}
		}
	}
}
