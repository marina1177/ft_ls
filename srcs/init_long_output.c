/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_long_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:55:23 by wzei              #+#    #+#             */
/*   Updated: 2019/10/23 15:44:10 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

static void	rights(char *rgh, struct stat *file_stat)
{
	rgh[0] = (file_stat->st_mode & S_IRUSR) ? 'r' : '-';
	rgh[1] = (file_stat->st_mode & S_IWUSR) ? 'w' : '-';
	rgh[2] = (file_stat->st_mode & S_IXUSR) ? 'x' : '-';
	rgh[3] = (file_stat->st_mode & S_IRGRP) ? 'r' : '-';
	rgh[4] = (file_stat->st_mode & S_IWGRP) ? 'w' : '-';
	rgh[5] = (file_stat->st_mode & S_IXGRP) ? 'x' : '-';
	rgh[6] = (file_stat->st_mode & S_IROTH) ? 'r' : '-';
	rgh[7] = (file_stat->st_mode & S_IWOTH) ? 'w' : '-';
	rgh[8] = (file_stat->st_mode & S_IXOTH) ? 'x' : '-';
	rgh[9] = '\0';
}

static char	file_type(struct stat *file_stat)
{
	if (S_ISDIR(file_stat->st_mode))
		return ('d');
	else if (S_ISLNK(file_stat->st_mode))
		return ('l');
	else if (S_ISBLK(file_stat->st_mode))
		return ('b');
	else if (S_ISCHR(file_stat->st_mode))
		return ('c');
	else if (S_ISFIFO(file_stat->st_mode))
		return ('f');
	else if (S_ISSOCK(file_stat->st_mode))
		return ('s');
	return ('-');
}

static char	xattr(t_fileinfo *file)
{
	if (file->sz_xattr < 0)
		file->sz_xattr = 0;
	if (file->sz_xattr > 0)
		return ('@');
	else if (file->i_acl != 0)
		return ('+');
	else
		return (' ');
	return (' ');
}

static char	*get_time(struct stat *st)
{
	static char	rtn[13];
	char		*tm;	
	time_t		cur_time;
	time_t		targ_time;

	cur_time = time(NULL);
	targ_time = ((st->st_mtimespec).tv_sec);
	tm = ctime(&targ_time);
	if ((cur_time - targ_time) < (31536000 / 2))
	{
		ft_memmove(rtn, tm + 4, 12);
		rtn[12] = '\0';
	}
	else
	{
		ft_memmove(rtn, tm + 4, 6);
		rtn[6] = ' ';
		ft_memmove(rtn + 7, tm + 19, 5);
		rtn[12] = '\0';
	}
	return (rtn);
}

void		init_long_output(t_long_out *l_o, t_fileinfo *file)
{
	l_o->st = (file->ft_stat);
	l_o->f_type = file_type(&(l_o->st));
	rights(l_o->rgh, &(l_o->st));
	l_o->gr = getgrgid((l_o->st).st_gid);
	l_o->pass = getpwuid((l_o->st).st_uid);
	l_o->time = get_time(&(l_o->st));
	l_o->x_attr = xattr(file);
	ft_bzero(l_o->lnk, 1024);
}
