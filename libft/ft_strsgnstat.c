/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsgnstat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 06:27:57 by wzei              #+#    #+#             */
/*   Updated: 2019/01/05 07:41:00 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsgnstat(const char *inp, int *sgn_flg)
{
	if (*inp == '-')
	{
		inp++;
		*sgn_flg = -1;
	}
	else if (*inp == '+')
	{
		inp++;
		*sgn_flg = 1;
	}
	else
		*sgn_flg = 0;
	return ((char *)inp);
}
