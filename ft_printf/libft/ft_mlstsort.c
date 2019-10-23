/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:22:42 by wzei              #+#    #+#             */
/*   Updated: 2019/10/23 12:44:14 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	switch_to_next(t_mlist **clist, t_mlist **plist)
{
	*plist = *clist;
	(*clist ? *clist = (*clist)->next : *clist);
}

void		ft_mlst_sort(t_mlist **list, int (*cmp)(void *, void *))
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
			switch_to_next(&clist, &plist);
		else
		{
			ft_mlstswap(plist->prev, plist);
			plist = plist->prev;
			if (plist == 0)
				switch_to_next(&clist, &plist);
		}
	}
}
