/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:34:38 by rfrieda           #+#    #+#             */
/*   Updated: 2019/10/11 06:49:07 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_percent(t_pf *data, int w)
{
	if (data->width != 0)
	{
		if (data->flags & F_MINUS)
			w += ft_print_out("%", 1);
		while (data->width != 1)
		{
			w += ft_print_out(" ", 1);
			data->width--;
		}
		if (data->flags & ~F_MINUS || data->flags == 0)
			w += ft_print_out("%", 1);
	}
	else
		w += ft_print_out("%", 1);
	data->written += w;
	return (data->written);
}

static int	ft_arg(va_list *ap, t_pf *data)
{
	int w;

	w = 0;
	if (data->spec == 'd' || data->spec == 'i' || data->spec == 'u')
		return (ft_diu(ap, data));
	if (data->spec == 'o' || data->spec == 'x' || data->spec == 'X' ||
		data->spec == 'p')
		return (ft_oxp(ap, data));
	if (data->spec == 'c' || data->spec == 's' || data->spec == 'S')
		return (ft_cs(ap, data));
	if (data->spec == '%')
		return (handle_percent(data, w));
	if (data->spec == 'f' || data->spec == 'F')
		return (ft_f(ap, data));
	return (0);
}

static void	ft_printf_internal(const char *format, va_list *ap, t_pf *data)
{
	int	n;

	while (data->spec != END_OF_FORMAT && *format)
	{
		n = 0;
		while (format[n] && format[n] != '%')
			n++;
		if ((n = ft_print_out(format, n)) < 0)
		{
			data->written = -1;
			return ;
		}
		data->written += n;
		format += n;
		if (*format == '%')
		{
			format = ft_format(format + 1, data);
			if ((n = ft_arg(ap, data)) < 0)
			{
				data->written = -1;
				return ;
			}
		}
	}
	ft_print_out(NULL, 0);
}

int			ft_printf(const char *format, ...)
{
	t_pf	data;
	va_list ap;

	va_start(ap, format);
	data.written = 0;
	ft_printf_internal(format, &ap, &data);
	va_end(ap);
	return (data.written);
}
