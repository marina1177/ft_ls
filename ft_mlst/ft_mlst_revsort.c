//
// Created by AN515-52-51JP on 20.10.2019.
//

#include "ft_mlst.h"

void    ft_mlst_revsort(t_mlist **list, int (*cmp)(void *, void *))
{
	t_mlist		*clist;
	t_mlist		*plist;

	if (!list || !(*list) || !((*list)->next))
		return ;
	plist = (*list)->next;
	clist = plist->next;
	while (plist)
	{
		if (!plist->prev || ((*cmp)(plist->prev->content, plist->content) >= 0))
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

