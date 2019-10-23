/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:22:28 by bcharity          #+#    #+#             */
/*   Updated: 2019/10/23 21:34:38 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

t_2b g_aflags[] =
{
	OUT_LCOL,
	OUT_CBCOL,
	OUT_1COL,
	DIR_ASFI,
	RECUR_LS,
	SORTI_R_,
	SORTI_T_,
	SORTI_F_,
	SORTI_SB,
	SORTI_A_,
	SORTI_U_,
	SORTI_C_
};

char *g_sflags = "lC1dRrtfSauc";

void			parse_ifiles(char *av)
{
	int			status;
	t_fileinfo	file;

	status = get_fileinfo(&file, av, av);
	if (status < 0)
	{
		ft_strncpy(file.name, av, sizeof(file.name));
		ft_mlstpush(&g_err_f, ft_mlstnew(&file, sizeof(t_fileinfo)));
	}
	else if ((file.type == directory) && !(g_flags.f_recur & DIR_ASFI))
	{
		ft_mlstpush(&g_dirs, ft_mlstnew(&file, sizeof(t_fileinfo)));
	}
	else
		ft_mlstpush(&g_files, ft_mlstnew(&file, sizeof(t_fileinfo)));
}

static void		set_flags(char cf, long offset)
{
	if (cf == 'l' || cf == 'C' || cf == '1')
		g_flags.f_output1 = g_aflags[offset];
	if (cf == 'd' || cf == 'R')
		g_flags.f_recur |= g_aflags[offset];
	if (cf == 'r' || cf == 't' || cf == 'f' || cf == 'S' || cf == 'a')
		g_flags.f_sort_ |= g_aflags[offset];
	if (cf == 'u' || cf == 'c')
		g_flags.f_sort_t = g_aflags[offset];
}

static int		parse_flags(char *s_avflgs)
{
	char	*p;
	char	*ch;

	g_flags.exist = 1;
	p = s_avflgs;
	while ((p++) && *p != '\0')
	{
		if (*p == '-')
			return (1);
		if ((ch = (char*)ft_memchr(&(g_sflags[0]), *p, NUMBER_FLAGS)) != NULL)
			set_flags(*p, ch - g_sflags);
		else
		{
			ft_putstr_fd("ft_ls: invalid options -- ", STDERR_FILENO);
			ft_putchar_fd(*p, STDERR_FILENO);
			ft_putstr_fd("\nusage: ft_ls [-", STDERR_FILENO);
			ft_putstr_fd(g_sflags, STDERR_FILENO);
			ft_putendl_fd("] [file ...]", STDERR_FILENO);
			exit(1);
		}
	}
	return (0);
}

int				parse_input(int ac, char **av)
{
	char	**argv;
	int		argc;
	int		fcnt;

	g_flags.exist = 0;
	if (ac == 1)
		return (0);
	argv = av;
	argc = 1;
	while (argv[argc] && argv[argc][0] == '-')
		if (parse_flags(argv[argc++]))
			break ;
	fcnt = 0;
	while (argv[argc])
	{
		parse_ifiles(argv[argc++]);
		fcnt++;
	}
	if (fcnt < 2)
		g_print_header = 0;
	else
		g_print_header = 1;
	return (fcnt);
}
