/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:05:23 by wzei              #+#    #+#             */
/*   Updated: 2019/03/04 21:24:10 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ret;

	ret = NULL;
	if (!s)
		return (NULL);
	s_len = (size_t)ft_strlen((char *)s);
	if ((len > s_len) || (start > s_len))
		return (NULL);
	if (!(ret = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ret[len] = '\0';
	while (len)
	{
		ret[len - 1] = s[start + len - 1];
		len--;
	}
	return (ret);
}
