/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oxp_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:27:47 by rfrieda           #+#    #+#             */
/*   Updated: 2019/10/12 09:02:24 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	x_flag(t_pf *data, t_ulli num)
{
	char	numarr[INT_SIZE];
	int		i;

	if (data->precision != NOT_SET || data->flags & F_MINUS)
		data->flags &= ~F_NULL;
	if (data->flags & F_NULL)
		data->precision = data->width - 2 * !(!(data->flags & F_SHARP));
	i = INT_SIZE - 1;
	!num ? numarr[i--] = '0' : 0;
	while (num)
	{
		numarr[i] = num % 16;
		if (numarr[i] < 10)
			numarr[i] += '0';
		else
			numarr[i] += (data->spec == 'X') ? 'A' - 10 : 'a' - 10;
		num /= 16;
		i--;
	}
	i = ft_print_xp(data, numarr + i + 1, i + 1);
	data->written += i;
	return (i);
}

static int	o_flag(t_pf *data, t_ulli num)
{
	char	numarr[INT_SIZE];
	int		i;

	if (data->precision != NOT_SET || data->flags & F_MINUS)
		data->flags &= ~F_NULL;
	if (data->flags & F_NULL)
		data->precision = data->width;
	i = INT_SIZE - 1;
	!num ? numarr[i--] = '0' : 0;
	while (num)
	{
		numarr[i] = num % 8 + '0';
		num /= 8;
		i--;
	}
	i = ft_print_o(data, numarr + i + 1, i + 1);
	data->written += i;
	return (i);
}

static int	p_flag(t_pf *data, t_ulli num)
{
	data->flags |= F_SHARP;
	return (x_flag(data, num));
}

int			ft_oxp(va_list *ap, t_pf *data)
{
	if (data->spec == 'p')
		return (p_flag(data, va_arg(*ap, t_ulli)));
	else if (data->spec == 'x' || data->spec == 'X')
	{
		if (data->mod & M_LL)
			return (x_flag(data, va_arg(*ap, t_ulli)));
		if (data->mod & M_L)
			return (x_flag(data, (t_ulli)va_arg(*ap, unsigned long int)));
		if (data->mod & M_H)
			return (x_flag(data, (t_ulli)((t_usi)va_arg(*ap, int))));
		if (data->mod & M_HH)
			return (x_flag(data, (t_ulli)((unsigned char)va_arg(*ap, int))));
		return (x_flag(data, (t_ulli)va_arg(*ap, unsigned int)));
	}
	if (data->mod & M_LL)
		return (o_flag(data, va_arg(*ap, t_ulli)));
	if (data->mod & M_L)
		return (o_flag(data, (t_ulli)va_arg(*ap, unsigned long int)));
	if (data->mod & M_H)
		return (o_flag(data, (t_ulli)((unsigned short int)va_arg(*ap, int))));
	if (data->mod & M_HH)
		return (o_flag(data, (t_ulli)((unsigned char)va_arg(*ap, int))));
	return (o_flag(data, (t_ulli)va_arg(*ap, unsigned int)));
}
