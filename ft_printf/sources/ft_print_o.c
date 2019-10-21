/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 09:09:44 by wzei              #+#    #+#             */
/*   Updated: 2019/10/12 09:13:16 by wzei             ###   ########.fr       */
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

static int	pre_zer_print(t_pf *data, int i)
{
	int	written;
	int	p_i;

	written = 0;
	p_i = 0;
	if (data->spec == 'o' && data->flags & F_SHARP)
		p_i = 1;
	while ((data->precision) - p_i++ > INT_SIZE - i)
		written += ft_print_out("0", 1);
	return (written);
}

static int	print_num(t_pf *data, char *numarr, int i)
{
	int	written;

	written = 0;
	if (data->precision != 0 && !is_zero(data, numarr, i))
		written += ft_print_out(numarr, INT_SIZE - i);
	else if (data->precision != 0 && !(data->flags & F_SHARP))
		written += ft_print_out(numarr, INT_SIZE - i);
	else if (data->precision == 0 && (data->flags & F_SHARP) &&
			!is_zero(data, numarr, i))
		written += ft_print_out(numarr, INT_SIZE - i);
	return (written);
}

int			ft_print_o(t_pf *data, char *numarr, int i)
{
	int	written;
	int	len;
	int	p_i;

	p_i = 0;
	if (i == 62 && numarr[0] == '0' && numarr[1] == '0' && data->spec == 'o')
		i++;
	len = (INT_SIZE - i < data->precision) ? data->precision : INT_SIZE - i;
	(check_data(data) && !is_zero(data, numarr, i)) ?
		len += 1 : 0;
	written = 0;
	while (!(data->flags & F_MINUS) && data->width - len > written)
		written += ft_print_out(" ", 1);
	print_prefix(&written, data);
	written += pre_zer_print(data, i);
	written += print_num(data, numarr, i);
	while (written < data->width && written >= 0)
		written += ft_print_out(" ", 1);
	return (written);
}
