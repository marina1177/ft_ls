/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:25:55 by wzei              #+#    #+#             */
/*   Updated: 2019/10/11 06:39:38 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_big_input(t_print_buf *out, const char *str, size_t len)
{
	size_t	wr;

	wr = 0;
	while (len > wr + BUF_LEN)
	{
		write(1, str + wr, BUF_LEN);
		wr += BUF_LEN;
	}
	ft_strncpy(out->buf, str + wr, len - wr);
	out->pos = len - wr;
	return (len);
}

static int	write_buf(t_print_buf *out, const char *str, size_t len)
{
	write(1, out->buf, out->pos);
	ft_strncpy(out->buf, str, len);
	out->pos = len;
	return (len);
}

static void	init_buf(t_print_buf *buf)
{
	ft_bzero(buf->buf, BUF_LEN);
	buf->pos = 0;
}

int			ft_print_out(const char *str, size_t len)
{
	static t_print_buf	out;
	static int			ini = 0;

	if (ini == 0)
	{
		init_buf(&out);
		ini++;
	}
	if (!str && len == 0)
		return (ft_print_force(&out));
	if (!str && len == 1)
		return (ft_print_round(&out));
	if (out.pos + len < BUF_LEN)
	{
		ft_strncpy(out.buf + out.pos, str, len);
		out.pos += len;
		return (len);
	}
	else if (len < BUF_LEN)
		write_buf(&out, str, len);
	else
		return (handle_big_input(&out, str, len));
	return (0);
}
