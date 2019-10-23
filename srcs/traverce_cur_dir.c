/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverce_cur_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:22:18 by wzei              #+#    #+#             */
/*   Updated: 2019/10/23 20:26:14 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

int			g_r;
const char	*g_program_name = "ft_ls";

static void	print_head(const char *filename, t_max_out *max)
{
	static int	count = 0;

	if (!g_print_header)
	{
		count++;
		g_print_header = 1;
		if (g_flags.f_output1 & OUT_LCOL)
			ft_printf("total %llu\n", max->blk);
		return ;
	}
	if (count++)
		ft_printf("\n");
	ft_printf("%s:\n", filename);
	if (g_flags.f_output1 & OUT_LCOL)
		ft_printf("total: %llu\n", max->blk);
}

static void	traverce_subdir(size_t len, char *dir_name,
							char *file_name)
{
	char			*new_name;

	new_name = NULL;
	if ((new_name = ft_strnew(len)))
	{
		ft_strncpy(new_name, dir_name, len);
		if (ft_strcmp(dir_name, "/"))
			ft_strlcat(new_name, "/", len);
		ft_strlcat(new_name, file_name, len);
		traverce_cur_dir(new_name);
		ft_strdel(&new_name);
	}
}

static void	handle_dirs(char *dir_name, t_mlist *entries)
{
	char			*file_name;
	t_fileinfo		file;
	size_t			len;
	char			*dir_name_slash;

	while (entries != NULL)
	{
		file_name = ((t_fileinfo *)(entries->content))->name;
		len = ft_strlen(dir_name) + ft_strlen(file_name) + 2;
		dir_name_slash = ft_strjoin(dir_name, "/");
		get_fileinfo(&file, dir_name_slash, file_name);
		if (file.type == directory &&
				ft_strncmp(".", file_name, 1) &&
				ft_strncmp("..", file_name, 2))
			traverce_subdir(len, dir_name, file_name);
		entries = entries->next;
		ft_strdel(&dir_name_slash);
	}
}

static void	err_msg(char *dir_name)
{
	char			*new_name;
	size_t			len;

	len = ft_strlen(g_program_name) + ft_strlen(dir_name) + 2;
	new_name = ft_strnew(len);
	ft_strlcat(new_name, g_program_name, len);
	ft_strlcat(new_name, ": ", len);
	ft_strlcat(new_name, dir_name, len);
	perror(new_name);
	free(new_name);
}

void		traverce_cur_dir(char *dir_name)
{
	DIR				*dir;
	t_mlist			*list_files;
	t_max_out		max;

	dir = opendir(dir_name);
	list_files = NULL;
	init_max(&max);
	if (!dir)
	{
		err_msg(dir_name);
		return ;
	}
	get_dir_entries(dir, dir_name, &list_files, &max);
	ls_sort_args_file(list_files);
	print_head(dir_name, &max);
	print_list(list_files, &max, dir_name);
	if (g_flags.f_recur == 1)
	{
		handle_dirs(dir_name, list_files);
	}
	closedir(dir);
	ft_mlstpurge(&list_files);
}
