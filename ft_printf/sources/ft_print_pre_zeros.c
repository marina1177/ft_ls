/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pre_zeros.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 08:53:09 by wzei              #+#    #+#             */
/*   Updated: 2019/10/12 08:53:52 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pre_zeros_print(t_pf *data, int i)
{
	int	written;
	int	p_i;

	written = 0;
	p_i = 0;
	while ((data->precision) - p_i++ > INT_SIZE - i)
		written += ft_print_out("0", 1);
	return (written);
}
