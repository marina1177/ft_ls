/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:37:39 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/22 19:02:53 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_sort.h"

static void	swap(void **a, void **b)
{
	void	*t;

	t = *a;
	*a = *b;
	*b = t;
}


static int	partition(t_vector *v, int low, int high, int (*f)(void *, void *))
{
	t_fileinfo	*pivot;
	int			i;
	t_fileinfo	*tmp;

	pivot = (t_fileinfo*)v->data[high];
	i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
       tmp = (t_fileinfo*)(v->data[j]);
        if (f(tmp, pivot) <= 0)
		{
			i++;
			swap(&((v->data)[i]), &((v->data)[j]));
		}
	}
	swap(&((v->data)[i + 1]), &((v->data)[high]));
	return (i + 1);
}

void		quicksort(t_vector *v, int low, int high, int (*f)(void *, void *))
{
	if (low < high)
	{
		int pi = partition(v, low, high, f);
		quicksort(v, low, pi - 1, f);
		quicksort(v, pi + 1, high, f);
	}
}



