//
// Created by AN515-52-51JP on 20.10.2019.
//
#include "ft_mlst.h"

void    ft_mlstswap(t_mlist *a, t_mlist *b)
{
	void		*tmpc;
	size_t		tmpt;

	if (!a || !b)
		return ;
	tmpc = a->content;
	tmpt = a->tag;
	a->content = b->content;
	a->tag = b->tag;
	b->content = tmpc;
	b->tag = tmpt;
}
