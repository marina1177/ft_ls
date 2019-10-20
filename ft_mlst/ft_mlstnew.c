//
// Created by AN515-52-51JP on 20.10.2019.
//

#include "ft_mlst.h"

t_mlist *ft_mlstnew(void *content, size_t tag)
{
	t_mlist		*res;

	if (!(res = (t_mlist *)malloc(sizeof(t_mlist))))
		return (0);
	res->tag = 0;
	if (tag || (res->content = 0))
	{
		if ((res->content = malloc(tag)))
			ft_memcpy(res->content, content, tag);
		res->tag = tag;
	}
	res->next = 0;
	res->prev = 0;
	return (res);
}
