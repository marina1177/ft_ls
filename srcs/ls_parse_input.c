//
// Created by AN515-52-51JP on 16.10.2019.
//

#include "ft_ls_m.h"

t_2b g_aflags[] = {OUT_LCOL, OUT_CBCOL, OUT_1COL,
                   DIR_ASFI, RECUR_LS,
                   SORTI_R_, SORTI_T_, SORTI_F_, SORTI_SB, SORTI_A_,
                   SORTI_U_, SORTI_C_};
char *g_sflags = "lC1dRrtfSauc";

void    parse_ifiles(char *av)
{
	int         status;
	int         i;
	t_fileinfo  file;

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

static  void    set_flags(char cf, long offset)
{
	if (cf == 'l' || cf == 'C' || cf == '1')
		g_flags.f_output1 = g_aflags[offset];
	if (cf == 'd' || cf == 'R' )
		g_flags.f_recur |= g_aflags[offset];
	if (cf == 'r' || cf == 't' || cf == 'f' || cf == 'S' || cf == 'a')
		g_flags.f_sort_ |= g_aflags[offset];
	if (cf == 'u' || cf == 'c')
		g_flags.f_sort_t = g_aflags[offset];
}

static void    parse_flags(char *s_avflgs)
{
	char    *p;
	char    *ch;

	g_flags.exist = 1;
	p = s_avflgs;
	while((p++) && *p != '\0')
	{
		if((ch = (char*)ft_memchr(&(g_sflags[0]), *p, NUMBER_FLAGS)) != NULL)
			set_flags(*p, ch - g_sflags);
		else
		{
			ft_putstr_fd("ft_ls: invalid options -- ", STDERR_FILENO);
			ft_putchar_fd(*p, STDERR_FILENO);
			ft_putstr_fd("\nusage: ft_ls [-", STDERR_FILENO);
			ft_putstr_fd(g_sflags, STDERR_FILENO);
			ft_putendl_fd("] [file ...]",  STDERR_FILENO);
			exit(0);
		}
	}
}

int parse_input(int ac, char **av)
{
	char    **argv;
	int     argc;
	int     fcnt;


	g_flags.exist = 0;
    if (ac == 1)
    	return (0); //ls <empty>
	argv = av;
	argc = ac;
    while(*(++argv) && **argv == '-') //ls -flags
    	parse_flags(*argv);
	--argv;
	fcnt = 0;
    while(*(++argv))
    {
	   parse_ifiles(*argv);
	   fcnt++;
    }
    return (fcnt);
}


