/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 13:54:27 by wzei              #+#    #+#             */
/*   Updated: 2019/01/05 14:03:57 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*cur;

	ret = NULL;
	if (f != NULL && lst != NULL)
	{
		ret = f(lst);
		cur = ret;
		lst = lst->next;
		while (lst != NULL)
		{
			if ((cur->next = f(lst)))
				cur = cur->next;
			lst = lst->next;
		}
	}
	return (ret);
}
