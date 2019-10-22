/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:22:28 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/22 19:41:23 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

t_list	*sorted_merge(t_list *a, t_list *b, int (*f)(void *, void *))
{
	t_list	*result;
	int		rev;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if ((rev = f(a->content, b->content)) >= 0)
	{
		result = a;
		result->next = sorted_merge(a->next, b, f);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next, f);
	}
	return (result);
}

void	front_back_split(t_list *source,
							t_list **front_ref, t_list **back_ref)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}

void	merge_sort(t_list **head_ref, int (*f)(void *, void *))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
	{
		return ;
	}
	front_back_split(head, &a, &b);
	merge_sort(&a, f);
	merge_sort(&b, f);
	*head_ref = sorted_merge(a, b, f);
}
