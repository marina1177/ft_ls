//
// Created by Buster Charity on 19/10/2019.
//

#include "ft_ls_m.h"

void ls_sort_args()
{
	ft_mlst_sort(&g_files, &ls_cmp_lex);
	//ft_printf("\nafter_lexsort:\n"); print_list(g_files);ft_printf("\n");
	if (g_flags.f_sort_ & SORTI_SB)
		ft_mlst_sort(&g_files, &ls_cmp_size);
	else if ((g_flags.f_sort_ & SORTI_T_) && \
				!(g_flags.f_sort_t & SORTI_U_))
		ft_mlst_revsort(&g_files, &ls_cmp_mtime);
	else if (g_flags.f_sort_t & SORTI_U_)
		ft_mlst_sort(&g_files, &ls_cmp_atime);

	ft_mlst_sort(&g_files, &ls_isdir);

}

void ls_sort_args_file(t_mlist *files)
{
	if (g_flags.f_sort_  & SORTI_R_)
	{
		ft_mlst_revsort(&files, &ls_cmp_lex);
		if (g_flags.f_sort_ & SORTI_SB)
			ft_mlst_revsort(&files, &ls_cmp_size);
		else if ((g_flags.f_sort_ & SORTI_T_) && \
					!(g_flags.f_sort_t & SORTI_U_))
			ft_mlst_sort(&files, &ls_cmp_mtime);
		else if (g_flags.f_sort_t & SORTI_U_)
			ft_mlst_revsort(&files, &ls_cmp_atime);
	}
	else
	{
		ft_mlst_sort(&files, &ls_cmp_lex);
		if (g_flags.f_sort_ & SORTI_SB)
			ft_mlst_sort(&files, &ls_cmp_size);
		else if ((g_flags.f_sort_ & SORTI_T_) && \
				!(g_flags.f_sort_t & SORTI_U_))
			ft_mlst_revsort(&files, &ls_cmp_mtime);
		else if (g_flags.f_sort_t & SORTI_U_)
			ft_mlst_sort(&files, &ls_cmp_atime);
	}
}

/*void ls_sort_args()
{
	merge_sort(&g_files, &ls_cmp_lex);
	ft_printf("\nafter_lexsort:\n"); print_list(g_files);ft_printf("\n");
	if (g_flags.f_sort_ & SORTI_SB)
		merge_sort(&g_files, &ls_cmp_size);
	else if ((g_flags.f_sort_ & SORTI_T_) && \
				!(g_flags.f_sort_t & SORTI_U_))
		merge_sort(&g_files, &ls_cmp_mtime);
	else if (g_flags.f_sort_t & SORTI_U_)
		merge_sort(&g_files, &ls_cmp_atime);

	merge_sort(&g_files, &ls_isdir);

}*/