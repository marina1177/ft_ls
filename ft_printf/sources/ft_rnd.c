/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rnd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 06:36:11 by wzei              #+#    #+#             */
/*   Updated: 2019/10/08 06:36:47 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_rnd(double a, double div)
{
	char	acc;

	acc = 0;
	if (div > 10.0)
	{
		acc = (char)(a / div) % 10;
		a -= (double)acc * div;
		div /= 10;
		acc = (char)(a / div) % 10;
		if (acc >= 5)
			return (1);
	}
	else
	{
		acc = (char)(a) % 10;
		a -= (double)acc;
		a *= 10.0;
		acc = (char)(a) % 10;
		if (acc >= 5)
			return (1);
	}
	return (0);
}
