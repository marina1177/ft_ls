/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlstpurge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:20:11 by wzei              #+#    #+#             */
/*   Updated: 2019/10/21 17:20:49 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mlstpurge(t_mlist **mlst)
{
	t_mlist *tmp;

	if (!mlst || !(*mlst))
		return ;
	while ((tmp = *mlst))
	{
		if (tmp->content && tmp->tag)
			free(tmp->content);
		(*mlst) = (*mlst)->next;
		if (*mlst)
			(*mlst)->prev = 0;
		free(tmp);
	}
}
