//
// Created by AN515-52-51JP on 16.10.2019.
//
#include "ft_ls_m.h"

void    ls_file_error(char *av)
{
	ft_putstr_fd("ft_ls: ", STDERR_FILENO);
	perror(av);
	//exit(-1);
}

void    print_err(t_mlist *lst)
{
	while (lst != NULL)
	{
		ls_file_error(((t_fileinfo *)(lst->content))->name);
		lst = lst->next;
	}
}