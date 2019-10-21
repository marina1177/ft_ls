/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 06:31:05 by wzei              #+#    #+#             */
/*   Updated: 2019/10/12 05:47:48 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	iter(t_dbl_trv *trv, double *num)
{
	if (trv->div > 1.0)
	{
		*num -= (double)trv->acc * trv->div;
		trv->div /= 10;
	}
	else
	{
		*num -= (double)trv->acc;
		*num *= 10.0;
		trv->prec--;
	}
}

static void	traverse_d(t_dbl_trv *trv, double *num, t_pf *data)
{
	while (trv->prec >= 0)
	{
		if (trv->div > 1.0)
			trv->acc = (char)(*num / trv->div) % 10;
		else
			trv->acc = (char)(*num) % 10;
		trv->acc += '0';
		if (trv->prec == 0 && *num < 10.0)
			trv->acc += ft_rnd(*num, trv->div);
		trv->wrt += ft_print_out(&(trv->acc), 1);
		(void)ft_print_out(NULL, 1);
		if (((trv->div == 1.0 && trv->prec != 0) ||
		data->flags & F_SHARP) && trv->pnt != 1)
		{
			trv->wrt += ft_print_out(".", 1);
			trv->pnt = 1;
		}
		trv->acc -= '0';
		iter(trv, num);
	}
}

static char	sgn(double *num, t_pf *data)
{
	if (*num < 0.0)
	{
		*num *= -1;
		return (-1);
	}
	else if (data->flags & F_PLUS)
		return (1);
	return (0);
}

static void	rewind_digit(double *num, t_dbl_trv *trv)
{
	if (*num > 1.0)
	{
		while ((*num / trv->div) > 10.0)
		{
			trv->div *= 10;
			trv->len++;
		}
	}
}

int			ft_print_f(double num, t_pf *data)
{
	t_dbl_trv dbl_trv;

	dbl_trv.acc = 0;
	dbl_trv.div = 1.0;
	dbl_trv.pnt = 0;
	dbl_trv.wrt = 0;
	dbl_trv.len = 1;
	dbl_trv.prec = (data->precision != -1 ? data->precision : 6);
	dbl_trv.sign = sgn(&num, data);
	rewind_digit(&num, &dbl_trv);
	if (data->flags & F_SHARP || dbl_trv.prec != 0)
		dbl_trv.len++;
	if (!(data->flags & F_MINUS) && dbl_trv.len + dbl_trv.prec < data->width)
		dbl_trv.wrt += ft_print_spaces(data->width - dbl_trv.len -
			dbl_trv.prec - dbl_trv.sign * dbl_trv.sign);
	else if (data->flags & F_SPACE && dbl_trv.sign == 0)
		dbl_trv.wrt += ft_print_spaces(1);
	dbl_trv.wrt += ft_print_sign(dbl_trv.sign);
	traverse_d(&dbl_trv, &num, data);
	if (data->flags & F_MINUS && dbl_trv.wrt < data->width)
		dbl_trv.wrt += ft_print_spaces(data->width - dbl_trv.wrt);
	return (dbl_trv.wrt);
}
