/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlstswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:22:47 by wzei              #+#    #+#             */
/*   Updated: 2019/10/22 20:22:47 by wzei             ###   ########.fr       */
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
