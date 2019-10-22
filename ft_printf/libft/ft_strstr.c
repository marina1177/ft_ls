/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 03:30:17 by wzei              #+#    #+#             */
/*   Updated: 2018/12/18 02:43:12 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	char	*sub_str;

	sub_str = (char *)needle;
	if (*sub_str == 0)
		return ((char *)haystack);
	while (*haystack != 0)
	{
		if (*haystack != *sub_str)
		{
			haystack += 1;
			continue ;
		}
		str = (char *)haystack;
		while (1)
		{
			if (*sub_str == 0)
				return ((char *)haystack);
			if (*str++ != *sub_str++)
				break ;
		}
		sub_str = (char *)needle;
		haystack += 1;
	}
	return (NULL);
}
