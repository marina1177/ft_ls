/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:26:36 by wzei              #+#    #+#             */
/*   Updated: 2018/12/16 08:46:57 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			iter;
	unsigned char	uc_c;
	unsigned char	*up_s;

	uc_c = (unsigned char)c;
	up_s = (unsigned char*)s;
	iter = 0;
	while (iter < n)
	{
		if (up_s[iter] == uc_c)
			return ((void *)(up_s + iter));
		iter++;
	}
	return (NULL);
}
