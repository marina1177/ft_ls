/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:22:28 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/23 21:28:36 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

static void	use_default_files(t_mlist **files)
{
	t_fileinfo	file;

	if (!(g_flags.f_recur & DIR_ASFI))
	{
		traverce_cur_dir(".");
	}
	else
	{
		get_fileinfo(&file, ".", ".");
		ft_mlstpush(files, ft_mlstnew(&file, sizeof(t_fileinfo)));
	}
}

int			main(int argc, char **argv)
{
	t_max_out max;

	init_max(&max);
	if ((g_file_count = parse_input(argc, argv)) == 0)
		use_default_files(&g_files);
	ls_sort_args_file(g_files);
	ft_mlst_sort(&g_err_f, &ls_cmp_lex);
	ls_sort_args_file(g_dirs);
	print_err(g_err_f);
	print_list(g_files, &max, ".");
	trav_dirs(g_dirs);
	return (0);
}
