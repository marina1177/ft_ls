/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diu_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:32:45 by rfrieda           #+#    #+#             */
/*   Updated: 2019/10/12 09:01:16 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_flag(t_pf *data, t_ulli num)
{
	char	numarr[INT_SIZE];
	int		i;

	if (data->precision != NOT_SET || data->flags & F_MINUS)
		data->flags &= ~F_NULL;
	if ((data->flags & F_NULL) && !(data->flags & F_SPACE))
		data->precision = data->width;
	else if ((data->flags & F_NULL) && (data->flags & F_SPACE))
		data->precision = data->width - 1;
	if (data->flags & F_ZERO_LEN)
		data->width = 0;
	i = INT_SIZE - 1;
	!num ? numarr[i--] = '0' : 0;
	while (num)
	{
		numarr[i] = '0' + num % 10;
		num /= 10;
		i--;
	}
	i = ft_print_diu(data, numarr + i + 1, i + 1);
	data->written += i;
	return (i);
}

static int	d_flag(t_pf *data, t_lli num)
{
	if (num >= 0)
		return (u_flag(data, (t_ulli)num));
	data->flags |= F_NEG;
	return (u_flag(data, (t_ulli)(num * -1)));
}

int			ft_diu(va_list *ap, t_pf *data)
{
	if (data->spec == 'd' || data->spec == 'i')
	{
		if (data->mod & M_LL || data->mod & M_Z)
			return (d_flag(data, va_arg(*ap, long long int)));
		if (data->mod & M_L)
			return (d_flag(data, (t_lli)va_arg(*ap, long int)));
		if (data->mod & M_H)
			return (d_flag(data, (t_lli)((short int)va_arg(*ap, int))));
		if (data->mod & M_HH)
			return (d_flag(data, (t_lli)((char)va_arg(*ap, int))));
		return (d_flag(data, (t_lli)va_arg(*ap, int)));
	}
	if (data->mod & M_LL || data->mod & M_Z)
		return (u_flag(data, va_arg(*ap, t_ulli)));
	if (data->mod & M_L)
		return (u_flag(data, (t_ulli)va_arg(*ap, unsigned long int)));
	if (data->mod & M_H)
		return (d_flag(data, (t_lli)((t_usi)va_arg(*ap, int))));
	if (data->mod & M_HH)
		return (d_flag(data, (t_lli)((unsigned char)va_arg(*ap, int))));
	return (u_flag(data, (t_ulli)va_arg(*ap, unsigned int)));
}
