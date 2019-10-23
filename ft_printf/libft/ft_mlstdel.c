/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:15:50 by wzei              #+#    #+#             */
/*   Updated: 2019/10/23 11:57:09 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mlstdel(t_mlist **mlst, size_t n)
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
