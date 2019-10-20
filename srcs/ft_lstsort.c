//
// Created by Buster Charity on 19/10/2019.
//

#include "../includes/ft_ls_m.h"

t_list  *SortedMerge(t_list *a, t_list *b, int (*f)(void *, void *))
{
    t_list	*result;
	int rev;

	result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if ((rev = f(a->content, b->content)) >= 0)
    {
        result = a;
        result->next = SortedMerge(a->next, b,f);
    }
    else
	{
        result = b;
        result->next = SortedMerge(a, b->next, f);
    }
    return (result);
}

void    front_back_split(t_list *source,
						 t_list **frontRef, t_list **backRef)
{
    t_list  *fast;
    t_list  *slow;

    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void    merge_sort(t_list **headRef, int (*f)(void *, void *))
{
    t_list  *head;
    t_list  *a;
    t_list  *b;

    head = *headRef;
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
	front_back_split(head, &a, &b);
    merge_sort(&a,f);
    merge_sort(&b,f);
    *headRef = SortedMerge(a, b, f);
}


