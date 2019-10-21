/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 07:28:30 by wzei              #+#    #+#             */
/*   Updated: 2019/10/07 07:53:24 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_round(t_print_buf *buf)
{
	size_t	i;

	i = buf->pos - 1;
	if (buf->buf[i] == ':')
	{
		buf->buf[i--] = '0';
		while (1)
		{
			if (buf->buf[i] == '.')
				i--;
			if (buf->buf[i] == '9')
			{
				buf->buf[i--] = '0';
				continue ;
			}
			else
			{
				buf->buf[i]++;
				break ;
			}
		}
	}
	return (0);
}
