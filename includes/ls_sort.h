/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:41:03 by wzei              #+#    #+#             */
/*   Updated: 2019/10/20 12:36:22 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "ft_ls_m.h"

typedef unsigned char	t_1b;
typedef unsigned short	t_2b;
typedef unsigned int	t_4b;
typedef unsigned long	t_8b;

# define timercmp(a, b, CMP)                                                  \
  (((a)->tv_sec == (b)->tv_sec) ?                                             \
   ((a)->tv_nsec CMP (b)->tv_nsec) :                                          \
   ((a)->tv_sec CMP (b)->tv_sec))

typedef struct				s_test
{
	struct	stat			ft_stat;
	char					*name;
}							t_test;

typedef struct				s_maxlen
{
	short				maxtype;
    t_8b			maxl_mode;
    t_8b			maxl_nlink;
    t_8b			maxl_uname;//username
    t_8b			maxl_gname;//groupname
    t_8b			maxl_size;
    t_8b			maxl_time;
    t_8b			maxl_filename;
}						t_maxlen;

typedef struct				s_lstat
{
    char 	name[PATH_MAX + 1];
    size_t  namelen;
}					t_lstat;

;

/*
 * * ls_sort_args.c
 */
void ls_sort_args();

/*
 * * ls_sort.c
 */

void				swap(void **a, void **b);
int					partition (t_vector *v, int low, int high, int (*f)(void *, void *));
void				quicksort(t_vector *v, int low, int high, int (*f)(void *, void *));


/*
 * * ft_lstsort.c
 */

void				merge_sort(t_list **headRef, int (*f)(void *, void *));
t_list				*SortedMerge(t_list *a, t_list *b, int (*f)(void *, void *));
void				FrontBackSplit(t_list *source,
					t_list **frontRef, t_list **backRef);

/*
 * * ls_cmp.c
 */

int					ls_isdir(void *a, void *b);
int					ls_cmp_lex(void *a, void *b);
int					ls_cmp_atime(void *a, void *b);
int					ls_cmp_mtime(void *a, void *b);
int					ls_cmp_size(void *a, void *b);

#endif
