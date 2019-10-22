/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:27:16 by wzei              #+#    #+#             */
/*   Updated: 2018/12/18 02:32:28 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_left_trim(char const *s)
{
	int l;

	l = 0;
	while (s[l] == ' ' || s[l] == '\n' || s[l] == '\t')
		l++;
	return (l);
}

static int	get_right_trim(char const *s, int sl)
{
	int r;

	sl--;
	r = 0;
	while (s[sl - r] == ' ' || s[sl - r] == '\n' || s[sl - r] == '\t')
		r++;
	return (r);
}

static char	*empty(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char));
	*ret = '\0';
	return (ret);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	int		sl;
	int		l;
	int		r;
	int		i;

	if (!s)
		return (NULL);
	sl = ft_strlen((char *)s);
	i = 0;
	l = get_left_trim(s);
	if (l == sl)
		return (empty());
	r = get_right_trim(s, sl);
	if (!(ret = (char *)malloc((sl - l - r + 1) * sizeof(char))))
		return (NULL);
	ret[sl - l - r] = '\0';
	while ((l + i) < (sl - r))
	{
		ret[i] = s[l + i];
		i++;
	}
	return (ret);
}
