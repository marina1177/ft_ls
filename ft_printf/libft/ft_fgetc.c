/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 09:56:33 by wzei              #+#    #+#             */
/*   Updated: 2019/03/11 12:13:56 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fgetc(t_file *file)
{
	unsigned char	c;
	ssize_t			len;

	if (file->b_off < file->b_s)
		return ((unsigned char)file->buf[file->b_off++]);
	if (file->b_off >= file->b_s)
	{
		len = read(file->fd, file->buf, BUFF_SIZE);
		if (len == 0)
		{
			file->flags |= FT_EOFINDICATOR;
			return (-1);
		}
		else if (len < 0)
		{
			file->flags |= FT_ERRORINDICATOR;
			return (-1);
		}
		file->b_off = 0;
		file->b_s = len;
	}
	c = file->buf[file->b_off];
	file->b_off++;
	return (c);
}
