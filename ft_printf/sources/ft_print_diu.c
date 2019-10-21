/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 07:12:15 by wzei              #+#    #+#             */
/*   Updated: 2019/10/12 09:20:47 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flg_print(t_pf *data, int len)
{
	int	written;

	written = 0;
	if (data->spec != 'u' && data->flags & F_NEG)
	{
		written += ft_print_out("-", 1);
		if (data->flags & F_NULL)
			(data->precision)--;
	}
	else if (data->spec != 'u' && data->flags & F_PLUS)
	{
		written += ft_print_out("+", 1);
		if (data->flags & F_NULL)
			(data->precision)--;
	}
	else if (data->spec != 'u' && data->flags & F_SPACE)
		written += ft_print_out(" ", 1);
	else if (data->spec != 'u' && data->flags & F_NULL && data->width > len)
		written += ft_print_out("0", 1);
	return (written);
}

static int	pre_off_print(t_pf *data, int len)
{
	int	written;

	written = 0;
	while (!(data->flags & F_MINUS) && data->width - len > written)
		written += ft_print_out(" ", 1);
	return (written);
}

int			ft_print_diu(t_pf *data, char *numarr, int i)
{
	int	written;
	int	len;

	len = (INT_SIZE - i < data->precision) ? data->precision : INT_SIZE - i;
	if (data->spec != 'u' && data->flags & (F_PLUS | F_SPACE | F_NEG | F_NULL)
	&& data->precision != 0)
		len++;
	written = 0;
	written += pre_off_print(data, len);
	written += flg_print(data, len);
	written += pre_zeros_print(data, i);
	if (data->precision != 0)
		written += ft_print_out(numarr, INT_SIZE - i);
	else if (data->precision == 0 && !is_zero(data, numarr, i))
		written += ft_print_out(numarr, INT_SIZE - i);
	while (written < data->width && written >= 0)
		written += ft_print_out(" ", 1);
	return (written);
}
