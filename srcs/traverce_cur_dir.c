/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverce_cur_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:22:18 by wzei              #+#    #+#             */
/*   Updated: 2019/10/21 19:33:08 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

int			g_r;
const char	*g_program_name = "ft_ls";

/*static void	init_lst(t_mlist *lst)
{
	lst->next = NULL;
	lst->prev = NULL;
	lst->content = NULL;
	lst->tag = 0;
}*/

static void	print_head(const char *filename)
{
	ft_printf("\n%s:\n", filename);
}
/*
**static void	get_dir_entries(DIR *dir, char *dir_name, t_mlist **entries)
**{
**	//int				status;
**	struct dirent	*d_d;
**	long			*acc;
**	t_fileinfo		file;
**	char			*dir_name_slash;
**
**	d_d = NULL;
**	dir_name_slash = ft_strjoin(dir_name, "/");
**	while ((d_d = readdir(dir)) && dir->__dd_loc < 4080)
**	{
**		get_fileinfo(&file, dir_name_slash, d_d->d_name);
**		ft_mlstpush(entries, ft_mlstnew(&file, sizeof(t_fileinfo)));
**	}
**	if (dir->__dd_loc == 4080)
**	{
**		get_fileinfo(&file, dir_name_slash, d_d->d_name);
**		ft_mlstpush(entries, ft_mlstnew(&file, sizeof(t_fileinfo)));
**	}
**	ft_strdel(&dir_name_slash);
**}
*/
static void	print_dir_entries(t_mlist *entries)
{
	/*struct dirent *d_d;

	d_d = NULL;
	ft_printf("%s\n", f_d->d_name);
	dir->__dd_loc = *((long *)ft_vecgetfirst(entries));
	dir->__dd_size = *((long *)ft_vecgetlast(entries));
	while ((d_d = readdir(dir)))
	{
		ft_printf("%s\n", d_d->d_name);
	}
	dir->__dd_loc = *((long *)ft_vecgetfirst(entries));
	dir->__dd_size = *((long *)ft_vecgetlast(entries));*/
	while (entries != NULL)
	{
		ft_printf("%s\n", ((t_fileinfo *)(entries->content))->name);
		entries = entries->next;
	}
}

static void traverce_subdir(size_t len, char *dir_name,
							char *file_name)
{
	char			*new_name;

	new_name = NULL;
	if ((new_name = ft_strnew(len)))
	{
		ft_strncpy(new_name, dir_name, len);
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
		get_fileinfo(&file, dir_name, file_name);
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
	DIR *dir;

	//t_vector		*entries;

	struct dirent	*f_d;
	//struct stat *stat = NULL;
	t_mlist			*list_files;
	//entries = ft_vecnew();

	//list_files = ft_mlstnew();
	list_files = NULL;
	dir = opendir(dir_name);
	if (!dir)
	{
		err_msg(dir_name);
		return ;
	}
	//stat(d_d->d_name, &f_st);
	print_head(dir_name);
	get_dir_entries(dir, dir_name, &list_files);
	ls_sort_args_file(list_files);
	print_dir_entries(list_files);
	if (g_flags.f_recur == 1)
	{
		handle_dirs(dir_name, list_files);
	}
	closedir(dir);
	ft_mlstpurge(&list_files);
}