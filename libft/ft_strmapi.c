/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:36:41 by wzei              #+#    #+#             */
/*   Updated: 2018/12/18 02:32:28 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		len;
	int		iter;
	int		jter;

	ret = NULL;
	jter = 0;
	if (s != NULL)
		len = ft_strlen((char *)s);
	else
		len = 0;
	if (len != 0)
		ret = (char *)malloc((len + 1) * sizeof(char));
	iter = 0;
	if (ret != NULL)
	{
		while (iter < len)
		{
			ret[iter] = f(jter++, s[iter]);
			iter++;
		}
		ret[len] = '\0';
	}
	return (ret);
}
