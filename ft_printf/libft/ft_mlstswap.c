/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlstswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:37:39 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/22 20:08:01 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mlstswap(t_mlist *a, t_mlist *b)
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
