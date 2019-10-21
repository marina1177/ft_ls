/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:27:09 by rfrieda           #+#    #+#             */
/*   Updated: 2019/10/11 07:05:26 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_data(t_pf *data)
{
	data->width = 0;
	data->precision = NOT_SET;
	data->flags = 0;
	data->mod = 0;
	data->spec = 0;
}

static char	find_spec(const char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'p' ||
		ch == 'd' || ch == 'i' || ch == 'o' ||
		ch == 'u' || ch == 'x' || ch == 'X' ||
		ch == 'f' || ch == 'c' || ch == 's' ||
		ch == 'S' || ch == '%')
		return (ch);
	else if (ft_isdigit(ch) ||
		ch == 'h' || ch == 'l' || ch == 'z' ||
		ch == '-' || ch == '+' || ch == ' ' ||
		ch == '.' || ch == '#' || ch == '_' ||
		ch == 'L')
		return (0);
	else if (!ch)
		return (END_OF_FORMAT);
	return (UNKNOWN_SPEC);
}

static int	ft_modif(const char *format)
{
	if (*format == 'h' && *(format - 1) != 'h' && *(format + 1) != 'h')
		return (M_H);
	else if (*format == 'h')
		return (M_HH);
	else if (*format == 'l' && *(format - 1) != 'l' && *(format + 1) != 'l')
		return (M_L);
	else if (*format == 'l')
		return (M_LL);
	else if (*format == 'z')
		return (M_Z);
	else if (*format == 'L')
		return (M_LD);
	return (0);
}

static int	ft_toint(const char *format)
{
	long	num;

	num = ft_strtol(format, NULL, 10);
	if (num > 2147483647)
		return (NOT_SET);
	return ((int)num);
}

const char	*ft_format(const char *format, t_pf *data)
{
	ft_init_data(data);
	while (!(find_spec(*format)))
	{
		if (*format == '-')
			data->flags |= F_MINUS;
		else if (*format == '+')
			data->flags |= F_PLUS;
		else if (*format == ' ')
			data->flags |= F_SPACE;
		else if (*format == '#')
			data->flags |= F_SHARP;
		else if (*format == '.')
			check_zero_p(&format, data);
		else if (*format == '0' &&
			!(ft_isdigit(*(format - 1))) && *(format - 1) != '.')
			check_zero_w(&format, data);
		else if (ft_isdigit(*format) &&
			!(ft_isdigit(*(format - 1))) && *(format - 1) != '.')
			data->width = ft_toint(format);
		else if (!(ft_isdigit(*format)))
			data->mod |= ft_modif(format);
		format++;
	}
	data->spec = find_spec(*format);
	return (++format);
}
