/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:46:11 by wzei              #+#    #+#             */
/*   Updated: 2019/10/21 17:21:22 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_vector
{
	void	**data;
	int		size;
	int		count;
}				t_vector;

typedef struct	s_mlist
{
	void			**content;
	size_t          tag;
	struct s_mlist	*prev;
	struct s_mlist	*next;
}				t_mlist;

# define BUFF_SIZE 32
# define FT_ERRORINDICATOR 1
# define FT_EOFINDICATOR 2
# define FT_EOF -1
# define COND_STR_TERM(CND, STR, POS) if ((CND)) {STR[POS] = '\0'; break ;}

typedef struct	s_file
{
	int				fd;
	int				flags;
	size_t			b_s;
	size_t			b_off;
	size_t			b_len;
	char			buf[BUFF_SIZE + 1];
}				t_file;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isupper(int c);
int				ft_iswhtspc(int c);
char			*ft_itoa(int n);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr(char const *s);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strsgnstat(const char *inp, int *sgn_flg);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnotwhgt(const char *inp);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(const char *s, char c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
long			ft_strtol(const char *nptr, char **endptr, int base);
int				ft_tolower(int c);
int				ft_toupper(int c);

t_vector		*ft_vecnew(void);
int				ft_veccnt(t_vector *v);
void			ft_vecadd(t_vector *v, void *e);
void			ft_vecset(t_vector *v, int index, void *e);
void			*ft_vecget(t_vector *v, int index);
void			*ft_vecgetfirst(t_vector *v);
void			*ft_vecgetlast(t_vector *v);
void			ft_vecdel(t_vector *v, int index);
void			ft_vecfree(t_vector *v);
void			*ft_vecsel(t_vector *vec, size_t off, void *tst, size_t s);

t_mlist			*ft_mlstnew(void *content, size_t tag);
void			ft_mlstpush(t_mlist **mlst, t_mlist *nlst);
void			ft_mlstdel(t_mlist **mlst, size_t tag);
void			ft_mlstpurge(t_mlist **mlst);
void			ft_mlstswap(t_mlist *a, t_mlist *b);
void			ft_mlst_sort(t_mlist **list, int (*cmp)(void *, void *));
void			ft_mlst_revsort(t_mlist **list, int (*cmp)(void *, void *));

#endif
