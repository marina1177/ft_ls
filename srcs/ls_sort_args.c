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

/*void ls_sort_args()
{
	quicksort(g_args, 0, g_args->count - 1, &ls_cmp_lex);
	printf("\nafter_lexsort:\n");printf("\n");
	if (g_flags.f_sort_ & SORTI_SB)
		quicksort(g_args, 0, g_args->count - 1, &ls_cmp_size);
	else if ((g_flags.f_sort_ & SORTI_T_) && \
				!(g_flags.f_sort_t & SORTI_U_))
		quicksort(g_args, 0, g_args->count - 1, &ls_cmp_mtime);
	else if (g_flags.f_sort_t & SORTI_U_)
		quicksort(g_args, 0, g_args->count - 1, &ls_cmp_atime);
	quicksort(g_args, 0, g_args->count - 1, &ls_isdir);
}
*/

void ls_sort_args()
{
	merge_sort(&g_args, &ls_cmp_lex);
	printf("\nafter_lexsort:\n"); printList(g_args);printf("\n");
	if (g_flags.f_sort_ & SORTI_SB)
		merge_sort(&g_args, &ls_cmp_size);
	else if ((g_flags.f_sort_ & SORTI_T_) && \
				!(g_flags.f_sort_t & SORTI_U_))
		merge_sort(&g_args, &ls_cmp_mtime);
	else if (g_flags.f_sort_t & SORTI_U_)
		merge_sort(&g_args, &ls_cmp_atime);

	//merge_sort(&g_args, &ls_isdir);

}



/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	t_list* res = NULL;
	t_list* a = NULL;

	/* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */

	ft_lstadd(&a, ft_lstnew("marina", 1));
	ft_lstadd(&a, ft_lstnew("asdf", 1));
	ft_lstadd(&a, ft_lstnew("vqwert", 1));

	/* Sort the above created Linked List */
	merge_sort(&a, );

	cout << "Sorted Linked List is: \n";
	printList(a);

	return 0;
}