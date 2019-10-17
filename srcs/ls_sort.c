/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:37:39 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/13 16:06:42 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls_sort.h"

/*int cmpfun_indx(t_flgs *flgs)
{
	int i;

	i =  (flgs->f_reversesort == 0) ? 0 : 4;
	if (flgs->f_timesort)
	{
		if (flgs->f_accesstime == 1)
			return (i++);
		else if (flgs->f_statustime == 1)
			return (i + 2);
		else
			return (i);
	}
	else if (flgs->f_allfiles)
		return (i + 3);
}*/

void	swap(void **a, void **b)
{
	void	*t;

	t = *a;
	*a = *b;
	*b = t;
}


int partition (t_vector *v, int low, int high, t_flags *flgs)
{
	t_test	*pivot;//arr[high];    // pivot
	int		i;
	t_test	*tmp;

	pivot = (t_test*)v->data[high];
	i = (low - 1);  // Index of smaller element
	for (int j = low; j <= high - 1; j++)
	{
	//	char *name = ((t_test*)(v->data[j]))->name;
       tmp = (t_test*)(v->data[j]);
//		 ft_strcmp(((t_test*)(v->data)[j])->name, pivot->name) > 0.0)
//		 timercmp(&(pivot->ft_stat.st_mtimespec),&(tmp->ft_stat.st_mtimespec),<=)
       // if ()
		{
			i++;
			swap(&((v->data)[i]), &((v->data)[j]));
		}
	}
	swap(&((v->data)[i + 1]), &((v->data)[high]));
	return (i + 1);
}


void quicksort(t_vector *v, int low, int high, t_flags *flgs)
{
	if (low < high)
	{
		int pi = partition(v, low, high, flgs);
		quicksort(v, low, pi - 1, flgs);
		quicksort(v, pi + 1, high, flgs);
	}
}

/*static long timer_cmp(struct timespec *a, struct	timespec *b)
{
	long i;

	if (a->tv_sec == b->tv_sec)
	{
		return (a->tv_nsec - b->tv_nsec);
	}
	i = a->tv_sec - b->tv_sec;
	return (i);
}*/



