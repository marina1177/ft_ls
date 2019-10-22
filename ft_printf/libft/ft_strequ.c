/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:48:32 by wzei              #+#    #+#             */
/*   Updated: 2018/12/18 02:32:28 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*ucp_s1;
	unsigned char	*ucp_s2;

	ucp_s1 = (unsigned char *)s1;
	ucp_s2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	while (*ucp_s1++ == *ucp_s2++)
	{
		if (*ucp_s1 == 0 && *ucp_s2 == 0)
			return (1);
	}
	return (0);
}
