/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 04:43:58 by wzei              #+#    #+#             */
/*   Updated: 2018/12/18 05:15:56 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;
	int				iter;

	if (n == 0)
		return (0);
	iter = 0;
	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while (u_s1[iter] != '\0' && u_s2[iter] != '\0' && n > 1)
	{
		if (u_s1[iter] != u_s2[iter])
			break ;
		iter++;
		n--;
	}
	return (u_s1[iter] - u_s2[iter]);
}
