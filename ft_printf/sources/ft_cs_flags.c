/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:33:50 by rfrieda           #+#    #+#             */
/*   Updated: 2019/10/11 04:54:54 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**int			ft_putwchar(wchar_t wch)
**{
**	if (wch)
**		return (wch);
**	return (-1);
**}
*/

static int	ft_len(int n, void *ptr, char ww)
{
	const char	*str;
	wchar_t		*wstr;
	int			len;

	len = 0;
	if (!ptr)
		return (-1);
	if (!ww)
	{
		str = ptr;
		if (n == NOT_SET)
			return ((int)ft_strlen(str));
		while (str[len] && len < n)
			len++;
		return (len);
	}
	wstr = ptr;
	while (wstr[len] && (len < n || n == NOT_SET))
		len++;
	return (len);
}

/*
**static int	ls_flag(t_pf *data, wchar_t *str)
**{
**	int len;
**	int written;
**
** 	if (data->spec == 'c')
**		data->precision = 1;
**	written = 0;
**	len = ft_len(data->precision, str, 1);
**	if (len == -1)
**	{
**		str = L"(null)";
**		len = ft_len(data->precision, str, 0);
**	}
**	if (!(data->flags & F_MINUS))
**		while (data->width > written + len)
**			if (ft_putwchar(' ') == -1 || !(++written))
**				return (-1);
**	while (len--)
**		if (ft_putwchar(*(str++)) == -1 || !(++written))
**			return (-1);
**	if (data->flags & F_MINUS)
**		while (data->width > written)
**			if (ft_putwchar(' ') == -1 || !(++written))
**				return (-1);
**	data->written += written;
**	return (written);
**}
*/

static int	length(t_pf *data, char *str)
{
	if (data->spec == 'c')
	{
		data->precision = 1;
		return (1);
	}
	else
		return (ft_len(data->precision, str, 0));
}

static int	s_flag(t_pf *data, char *str)
{
	int len;
	int written;

	len = length(data, str);
	written = 0;
	if (len == -1)
	{
		str = "(null)";
		len = ft_len(data->precision, str, 0);
	}
	if (!(data->flags & F_MINUS))
		while (data->width > written + len)
			if (ft_print_out(" ", 1) != 1 || !(++written))
				return (-1);
	if ((ft_print_out(str, len)) != len || (written += len) < 0)
		return (-1);
	if (data->flags & F_MINUS)
		while (data->width > written)
			if (ft_print_out(" ", 1) != 1 || !(++written))
				return (-1);
	data->written += written;
	return (written);
}

int			ft_cs(va_list *ap, t_pf *data)
{
	int ch;

	if (data->spec == 'S' || (data->spec == 's' && data->mod & M_L))
		return (s_flag(data, va_arg(*ap, char*)));
	if (data->spec == 's')
		return (s_flag(data, va_arg(*ap, char*)));
	if (data->spec == 'c' && data->mod & M_L)
	{
		ch = va_arg(*ap, int);
		return (s_flag(data, (char*)(&ch)));
	}
	ch = va_arg(*ap, int);
	return (s_flag(data, (char*)(&ch)));
}
