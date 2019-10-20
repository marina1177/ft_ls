//
// Created by AN515-52-51JP on 20.10.2019.
//

#include "ft_mlst.h"

void    ft_mlstdel(t_mlist **mlst, size_t n)
{
	t_mlist *tmp;

	if (!mlst || !(*mlst))
		return ;
	while ((tmp = *mlst) && n--)
	{
		if (tmp->content && tmp->tag)
			free(tmp->content);
		(*mlst) = (*mlst)->next;
		if (*mlst)
			(*mlst)->prev = 0;
		free(tmp);
	}
}