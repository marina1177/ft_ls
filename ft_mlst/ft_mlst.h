//
// Created by AN515-52-51JP on 20.10.2019.
//

#ifndef FT_LS_FT_MLST_H
#define FT_LS_FT_MLST_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"
typedef struct	s_mlist
{
	void			**content;
	size_t          tag;
	struct s_mlist	*prev;
	struct s_mlist	*next;
}				t_mlist;

t_mlist	            *ft_mlstnew(void *content, size_t tag);
void                ft_mlstpush(t_mlist **mlst, t_mlist *nlst);
void                ft_mlstdel(t_mlist **mlst, size_t tag);
void				ft_mlstswap(t_mlist *a, t_mlist *b);
void				ft_mlst_sort(t_mlist **list, int (*cmp)(void *, void *));
void				ft_mlst_revsort(t_mlist **list, int (*cmp)(void *, void *));


#endif //FT_LS_FT_MLST_H
