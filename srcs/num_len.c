/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:05:52 by wzei              #+#    #+#             */
/*   Updated: 2019/10/22 15:07:08 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

unsigned long num_len(unsigned long num)
{
    unsigned long  mul;
    unsigned long  len;

    mul = 10;
    len = 1;
    while (num > mul)
    {
        len++;
        mul *= 10;
    }
    return (len);
}