/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:26:57 by rfrieda           #+#    #+#             */
/*   Updated: 2019/10/12 08:54:10 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include "libft.h"

# define INT_SIZE		64

# define UNKNOWN_SPEC	-1
# define END_OF_FORMAT	-2

# define NOT_SET		-1

# define F_MINUS		1
# define F_PLUS			2
# define F_SPACE		4
# define F_SHARP		8
# define F_NULL			16
# define F_NEG			32
# define F_ZERO_LEN		64

# define M_NONE			1
# define M_H			2
# define M_HH			4
# define M_L			8
# define M_LL			16
# define M_LD			32
# define M_Z			64

# define BUF_LEN		1024

typedef struct					s_print_buf
{
	char			buf[BUF_LEN];
	size_t			pos;
}								t_print_buf;

typedef struct					s_pf
{
	int				written;
	int				width;
	int				precision;
	unsigned char	flags;
	unsigned int	mod;
	char			spec;
}								t_pf;

typedef struct					s_ldbl_trv
{
	char		acc;
	long double	div;
	char		pnt;
	char		sign;
	int			wrt;
	int			prec;
	int			len;
}								t_ldbl_trv;

typedef struct					s_dbl_trv
{
	char		acc;
	double		div;
	char		pnt;
	char		sign;
	int			wrt;
	int			prec;
	int			len;
}								t_dbl_trv;

typedef unsigned long long int	t_ulli;
typedef long long int			t_lli;
typedef unsigned short int		t_usi;

const char						*ft_format(const char *format, t_pf *data);
int								ft_diu(va_list *ap, t_pf *data);
int								ft_oxp(va_list *ap, t_pf *data);
int								ft_cs(va_list *ap, t_pf *data);
int								ft_f(va_list *ap, t_pf *data);
int								ft_putwchar(wchar_t wch);

/*
** Printing functions
*/

int								ft_print_out(const char *str, size_t len);
int								ft_print_force(t_print_buf *buf);
int								ft_print_round(t_print_buf *buf);
int								ft_printf(const char *format, ...);
int								ft_print_lf(long double num, t_pf *data);
int								ft_print_sign(char sgn);
int								ft_print_spaces(int len);
int								ft_print_f(double num, t_pf *data);
int								ft_print_lf(long double num, t_pf *data);
int								ft_print_xp(t_pf *data, char *numarr, int i);
int								ft_print_o(t_pf *data, char *numarr, int i);
int								ft_print_diu(t_pf *data, char *numarr, int i);
int								pre_zeros_print(t_pf *data, int i);

char							ft_rnd(double a, double div);

void							check_zero_w(const char **format, t_pf *data);
void							check_zero_p(const char **format, t_pf *data);
int								is_zero(t_pf *data, char *numarr, int i);
#endif
