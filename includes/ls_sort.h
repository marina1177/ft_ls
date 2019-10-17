/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 00:41:03 by wzei              #+#    #+#             */
/*   Updated: 2019/10/17 16:56:38 by bcharity         ###   ########.fr       */
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
 * * ls_sort.c
 */
//int cmpfun_indx(t_flgs *flgs);
void	swap(void **a, void **b);
int		partition (t_vector *v, int low, int high, t_flags *flgs);
void	quicksort(t_vector *v, int low, int high, t_flags *flgs);


#endif
