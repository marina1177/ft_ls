/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:37:39 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/22 20:06:40 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
