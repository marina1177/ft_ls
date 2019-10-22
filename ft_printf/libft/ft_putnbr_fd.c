/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:56:28 by wzei              #+#    #+#             */
/*   Updated: 2018/12/31 01:54:06 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_arr(char *arr)
{
	int iter;

	iter = 0;
	while (iter < 10)
	{
		arr[iter] = '0' + iter;
		iter++;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	char	arr[10];
	long	acc;
	long	inp;
	int		iter;

	inp = (long)n;
	if (inp < 0)
	{
		write(fd, "-", 1);
		inp *= -1;
	}
	acc = 1;
	iter = 0;
	init_arr(arr);
	while ((inp / acc) > 9)
		acc *= 10;
	while (acc != 0)
	{
		iter = inp / acc;
		inp %= acc;
		write(fd, arr + iter, 1);
		acc /= 10;
	}
}
