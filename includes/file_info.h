/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:44:12 by wzei              #+#    #+#             */
/*   Updated: 2019/10/22 19:44:12 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_SORT_FILE_INFO_H
#define LS_SORT_FILE_INFO_H

#include "ft_ls_m.h"

typedef unsigned char	t_1b;

enum filetype
{
	unknown,
	fifo,
	chardev,
	directory,
	blockdev,
	regular,
	symbolic_link,
	socket,
	whiteout,
	arg_directory
};

typedef struct		s_fileinfo
{
	char			name[256];
	char			linkname[256];
	char			path[1024];
	int				_acl;
	ssize_t			_xattr;
	struct stat		ft_stat;
	enum filetype	type;
}					t_fileinfo;

typedef struct		s_max_out
{
	unsigned long			lnk;
	unsigned long			size;
	unsigned long			major;	
	unsigned long			minor;
	unsigned long			name;
	unsigned long			user;
	unsigned long			group;
	unsigned long			blk;
}					t_max_out;

typedef struct		s_long_out
{
	struct stat		st;
	struct passwd	*pass;
	struct group	*gr;
	char			*time;
	char			lnk[1024];
	char			rgh[10];
	char			f_type;
	char			x_attr;
}					t_long_out;

int					get_fileinfo(t_fileinfo *file, char *path, char *name);
void				udate_max(t_fileinfo *file, t_max_out *max);
void				init_max(t_max_out *max);

#endif
