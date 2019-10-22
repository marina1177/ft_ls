/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 13:18:10 by wzei              #+#    #+#             */
/*   Updated: 2019/01/05 14:18:20 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*ptr_next;

	if (alst != NULL && *alst != NULL && del != NULL)
	{
		ptr = *alst;
		while (ptr != NULL)
		{
			ptr_next = ptr->next;
			del(ptr->content, ptr->content_size);
			free(ptr);
			ptr = ptr_next;
		}
		*alst = NULL;
	}
}
