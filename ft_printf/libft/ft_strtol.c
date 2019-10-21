/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 20:20:18 by wzei              #+#    #+#             */
/*   Updated: 2019/01/05 11:07:59 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef ULONG_MAX
# define ULONG_MAX ((unsigned long)(~0L))
#endif

#ifndef LONG_MAX
# define LONG_MAX ((long)(ULONG_MAX >> 1))
#endif

#ifndef LONG_MIN
# define LONG_MIN ((long)(~LONG_MAX))
#endif

static size_t	proc_base(const char *inp, int *bs)
{
	const char	*s;

	s = inp;
	if ((*bs == 0 || *bs == 16) && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		s += 2;
		*bs = 16;
	}
	if (*bs == 0)
		*bs = (s[0] == '0' ? 8 : 10);
	return (s - inp);
}

static int		chk_valid_char(int c)
{
	if (ft_isdigit(c))
	{
		c -= '0';
		return (c);
	}
	else if (ft_isalpha(c))
	{
		c -= (ft_isupper(c) ? 'A' - 10 : 'a' - 10);
		return (c);
	}
	return (-1);
}

static void		init_lim(unsigned long *o, int *l, int sgn, int base)
{
	*o = ((sgn == -1) ? -(unsigned long)LONG_MIN : LONG_MAX);
	*l = (int)(*o % (unsigned long)base);
	*o /= (unsigned long)base;
	return ;
}

static char		*proc_digits(int sb, unsigned long *ac, int *an, const char *s)
{
	unsigned long	cutoff;
	int				cutlim;
	int				c;
	int				base;

	base = ((sb < 0) ? -sb : sb);
	init_lim(&cutoff, &cutlim, sb / base, base);
	*ac = 0;
	*an = 0;
	while ((c = *s++))
	{
		if ((c = chk_valid_char(c)) == -1)
			break ;
		if (c >= base)
			break ;
		if (*an < 0 || *ac > cutoff || (*ac == cutoff && c > cutlim))
			*an = -1;
		else
		{
			*an = 1;
			*ac = *ac * base + c;
		}
	}
	return ((char *)s);
}

long			ft_strtol(const char *nptr, char **endptr, int base)
{
	const char		*s;
	unsigned long	acc;
	int				sgn;
	int				any;

	any = 0;
	sgn = 0;
	s = ft_strnotwhgt(nptr);
	s = ft_strsgnstat(s, &sgn);
	s += proc_base(s, &base);
	base = ((sgn == 0) ? ((sgn + 1) * base) : (sgn * base));
	s = proc_digits(base, &acc, &any, s);
	if (any < 0)
	{
		acc = ((sgn == -1) ? LONG_MIN : LONG_MAX);
	}
	else if (sgn == -1)
		acc = -(acc);
	if (endptr != NULL)
		*endptr = (char *)(any ? s - 1 : nptr);
	return (acc);
}
