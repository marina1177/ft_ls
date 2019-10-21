/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:04:40 by wzei              #+#    #+#             */
/*   Updated: 2019/10/11 07:05:12 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero_w(const char **format, t_pf *data)
{
	char	*stop;
	int		wid;
	int		off;

	off = 1;
	if ((*format)[1] == '-')
	{
		off++;
		data->flags |= F_MINUS;
	}
	if ((*format)[1] == '+')
	{
		off++;
		data->flags |= F_PLUS;
	}
	wid = (int)ft_strtol(*format + off, &stop, 10);
	if (stop - (*format + off) == 0)
	{
		wid = 0;
		data->flags |= F_ZERO_LEN;
	}
	data->width = wid;
	*format = stop - 1;
	if (wid != 0)
		data->flags |= F_NULL;
}
