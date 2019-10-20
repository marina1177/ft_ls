//
// Created by AN515-52-51JP on 20.10.2019.
//

#include "ft_mlst.h"

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
