//
// Created by Buster Charity on 19/10/2019.
//

#include "../includes/ft_ls_m.h"

void printList(t_list* node)
{
	while (node != NULL)
	{
		printf("%s\n", ((t_fileinfo *)(node->content))->name);
		node = node->next;
	}
}

void ls_sort_args()
{

	merge_sort(&g_args, &ls_cmp_lex);
	merge_sort(&g_args, &ls_isdir);
}
