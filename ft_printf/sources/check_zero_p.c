/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:03:49 by wzei              #+#    #+#             */
/*   Updated: 2019/10/11 07:04:06 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero_p(const char **format, t_pf *data)
{
	char	*stop;
	int		p;
	int		off;

	off = 1;
	if ((*format)[off] == '0')
		off++;
	if ((*format)[off] == '-')
		off++;
	p = (int)ft_strtol(*format + off, &stop, 10);
	if (stop - (*format + off) == 0)
		p = 0;
	else
		data->flags |= F_NULL;
	data->precision = p;
	*format = stop - 1;
}
