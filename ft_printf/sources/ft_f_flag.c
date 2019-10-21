/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:38:53 by rfrieda           #+#    #+#             */
/*   Updated: 2019/10/08 06:42:32 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ld_flag(t_pf *data, long double num)
{
	int		written;

	written = ft_print_lf(num, data);
	data->written += written;
	return (written);
}

static int		d_flag(t_pf *data, double num)
{
	int		written;

	written = ft_print_f(num, data);
	data->written += written;
	return (written);
}

int				ft_f(va_list *ap, t_pf *data)
{
	if (data->mod & M_LD)
		return (ld_flag(data, va_arg(*ap, long double)));
	return (d_flag(data, va_arg(*ap, double)));
}
