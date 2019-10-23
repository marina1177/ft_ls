/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:22:28 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/23 13:41:42 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

void	ls_file_error(char *av)
{
	ft_putstr_fd("ft_ls: ", STDERR_FILENO);
	perror(av);
}

void	print_err(t_mlist *lst)
{
	while (lst != NULL)
	{
		ls_file_error(((t_fileinfo *)(lst->content))->name);
		lst = lst->next;
	}
}
