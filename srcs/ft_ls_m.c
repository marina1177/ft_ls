/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:49:01 by wzei              #+#    #+#             */
/*   Updated: 2019/10/21 19:50:38 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

static void	use_default_file(void)
{
	t_fileinfo	file;
	DIR			*dir;

	if (!(g_flags.f_recur & DIR_ASFI))
	{
		dir = opendir(".");
		get_dir_entries(dir, ".", &g_files);
		closedir(dir);
	}
	else
	{
		get_fileinfo(&file, ".", ".");
		ft_mlstpush(&g_files, ft_mlstnew(&file, sizeof(t_fileinfo)));
	}
}

int			main(int ac, char **av)
{
	if ((g_file_count = parse_input(ac, av)) == 0)
		use_default_file();
	ls_sort_args_file(g_files);
	ft_mlst_sort(&g_err_f, &ls_cmp_lex);
	ls_sort_args_file(g_dirs);
	print_err(g_err_f);
	printList(g_files);
	trav_dirs(g_dirs);
	return (0);
}

/*
**		ft_printf("before_sort:\n");
**	for (int i = 0; i < g_files->count; i++)
**	{
**		ft_printf("data[%d] = %s\n", i,
**        ((t_fileinfo*)(g_files->data)[i])->name);
**	}
**	ls_sort_args();
**	ft_printf("ater_sort:\n");
**	for (int i = 0; i < g_files->count; i++)
**	{
**		ft_printf("data[%d] = %s\n", i,
**      ((t_fileinfo*)(g_files->data)[i])->name);
**	}
*/

/*
**    while (g_files)
**        //grand_loop();
**
**        DIR				*dir;
**    struct dirent	*f_d;
**    t_vector		*v;
**    t_test			*tst;
**    struct	ft_stat	ft_stat;
**
**    int ch;
**    t_flgs          flgs;
**    //ls_parse_input()
**
**
**    //v = ft_vecnew();
**    dir = opendir(argv[1]);
**    while ((f_d = readdir(dir)))
**    {
**        tst = (t_test *)malloc(sizeof(t_test ));
**        ft_printf ("{%s}\n",f_d->d_name);
**        ft_stat(ft_strjoin(argv[1], f_d->d_name), &(tst->ft_stat));
** //tmp - delete
**
**        tst->name = f_d->d_name;
**       // ft_printf ("size[%s] = {%lld}\n ",
**    tst->name,tst->ft_stat.st_blocks);
**        ft_vecadd(v, tst);
**    }
**
**    char *sort_flg = "rat";
**    int ifun = cmpfun_indx(&flgs);
**
**    quicksort(v, 0, v->count - 1, &flgs);
**
**    ft_printf("ater_sort:\n");
**    for (int i = 0; i < v->count; i++)
**    {
**        ft_printf("data[%d] = %s\n", i, ((t_test*)(v->data)[i])->name);
**    }-
*/
