/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:22:28 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/22 18:59:06 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

int		ls_isdir(void *a, void *b)
{
	t_fileinfo		*tfa;
	t_fileinfo		*tfb;

	tfa = (t_fileinfo *)a;
	tfb = (t_fileinfo *)b;
	if (tfa->type == directory)
		return (-1);
	if (tfb->type == directory)
		return (1);
	return (0);
}

int		ls_cmp_lex(void *a, void *b)
{
	t_fileinfo		*tfa;
	t_fileinfo		*tfb;

	tfa = (t_fileinfo*)a;
	tfb = (t_fileinfo*)b;
	return (ft_strcmp(tfa->name, tfb->name));
}

int		ls_cmp_atime(void *a, void *b)
{
	struct stat		sa;
	struct stat		sb;

	sb = ((t_fileinfo *)(b))->ft_stat;
	sa = ((t_fileinfo *)(a))->ft_stat;
	if (sa.st_atime > sb.st_atime)
		return (1);
	else if (sa.st_atime < sb.st_atime)
		return (-1);
	return (0);
}

int		ls_cmp_mtime(void *a, void *b)
{
	struct stat		sa;
	struct stat		sb;

	sb = ((t_fileinfo *)(b))->ft_stat;
	sa = ((t_fileinfo *)(a))->ft_stat;
	if (sa.st_mtime > sb.st_mtime)
		return (1);
	else if (sa.st_mtime < sb.st_mtime)
		return (-1);
	return (0);
}

int		ls_cmp_size(void *a, void *b)
{
	struct stat		sa;
	struct stat		sb;

	sb = ((t_fileinfo *)(b))->ft_stat;
	sa = ((t_fileinfo *)(a))->ft_stat;
	if (sa.st_size > sb.st_size)
		return (1);
	else if (sa.st_size < sb.st_size)
		return (-1);
	return (0);
}