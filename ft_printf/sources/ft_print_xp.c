/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 06:56:23 by wzei              #+#    #+#             */
/*   Updated: 2019/10/12 09:10:58 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_data(t_pf *data)
{
	if (data->flags & F_SHARP)
		return (1);
	return (0);
}

static void	print_prefix(int *written, t_pf *data)
{
	if (data->spec == 'p')
		data->spec = 'x';
	if (data->spec == 'x' && data->flags & F_SHARP)
		*written += ft_print_out("0x", 2);
	if (data->spec == 'X' && data->flags & F_SHARP)
		*written += ft_print_out("0X", 2);
	if (data->spec == 'o' && data->flags & F_SHARP)
		*written += ft_print_out("0", 1);
}

int			ft_print_xp(t_pf *data, char *numarr, int i)
{
	int	written;
	int	len;
	int	p_i;

	p_i = 0;
	if (i == 62 && numarr[0] == '0' && numarr[1] == '0' && data->spec == 'o')
		i++;
	len = (INT_SIZE - i < data->precision) ? data->precision : INT_SIZE - i;
	(check_data(data) && !is_zero(data, numarr, i)) ?
		len += 2 : 0;
	written = 0;
	while (!(data->flags & F_MINUS) && data->width - len > written)
		written += ft_print_out(" ", 1);
	if (*numarr != '0' || data->spec == 'p')
		print_prefix(&written, data);
	written += pre_zeros_print(data, i);
	if (data->precision != 0)
		written += ft_print_out(numarr, INT_SIZE - i);
	while (written < data->width && written >= 0)
		written += ft_print_out(" ", 1);
	return (written);
}
