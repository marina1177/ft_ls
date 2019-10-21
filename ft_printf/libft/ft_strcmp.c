/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 04:41:37 by wzei              #+#    #+#             */
/*   Updated: 2018/12/31 01:53:10 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;
	int				iter;

	iter = 0;
	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while (u_s1[iter] != '\0' && u_s2[iter] != '\0')
	{
		if (u_s1[iter] != u_s2[iter])
			break ;
		iter++;
	}
	return (u_s1[iter] - u_s2[iter]);
}
