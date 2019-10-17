/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:46:27 by wzei              #+#    #+#             */
/*   Updated: 2018/12/27 18:43:09 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static int	word_count(const char *s, char sep)
{
	int count;
	int	wrd_flg;

	count = 0;
	wrd_flg = 0;
	while (*s != '\0')
	{
		if (*s != sep && wrd_flg == 0)
			wrd_flg = 1;
		if (*s == sep && wrd_flg == 1)
		{
			count++;
			wrd_flg = 0;
		}
		s++;
	}
	if (*s == '\0' && wrd_flg == 1)
	{
		count++;
		wrd_flg = 0;
	}
	return (count);
}

inline static char	**init_return_array(const char *s, char c)
{
	return ((char **)ft_memalloc(sizeof(char *) * (word_count(s, c) + 1)));
}

inline static char	**failure(char **ret, size_t ret_itr)
{
	size_t itr;

	itr = 0;
	while (itr < ret_itr)
		free(ret[itr]);
	free(ret);
	return (NULL);
}

char				**ft_strsplit(const char *s, char c)
{
	char	**ret;
	size_t	src_itr;
	size_t	ret_itr;
	size_t	len;

	if (!s || !c || (!(ret = init_return_array(s, c))))
		return (0);
	src_itr = 0;
	ret_itr = 0;
	while (s[src_itr])
	{
		if (s[src_itr] == c)
			src_itr++;
		else
		{
			len = 0;
			while (s[src_itr + len] && (s[src_itr + len] != c))
				len++;
			if (!(ret[ret_itr++] = ft_strsub(s, src_itr, len)))
				return (failure(ret, ret_itr));
			src_itr += len;
		}
	}
	ret[ret_itr] = NULL;
	return (ret);
}
