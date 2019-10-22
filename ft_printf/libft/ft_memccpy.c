/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:57:41 by wzei              #+#    #+#             */
/*   Updated: 2018/12/18 02:32:28 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		ch;
	unsigned char		*tp;
	const unsigned char	*fp;

	ch = (unsigned char)c;
	tp = (unsigned char *)dst;
	fp = (const unsigned char *)src;
	if (n != 0)
	{
		while (n-- != 0)
		{
			if ((*tp++ = *fp++) == ch)
				return ((void *)tp);
		}
	}
	return (NULL);
}
