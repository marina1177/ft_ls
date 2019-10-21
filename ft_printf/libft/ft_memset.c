/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:46:33 by wzei              #+#    #+#             */
/*   Updated: 2018/11/27 01:15:34 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	u_c;
	unsigned char	*uptr_s;
	size_t			iter;

	u_c = (unsigned char)c;
	uptr_s = (unsigned char*)s;
	iter = 0;
	while (iter < n)
	{
		uptr_s[iter] = u_c;
		iter++;
	}
	return (s);
}
