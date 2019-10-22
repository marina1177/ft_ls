/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:21:06 by wzei              #+#    #+#             */
/*   Updated: 2018/12/18 02:34:16 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*uptr_s;
	size_t			iter;

	iter = 0;
	uptr_s = (unsigned char*)s;
	while (iter < n)
	{
		uptr_s[iter] = 0;
		iter++;
	}
}
