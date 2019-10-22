/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 00:05:07 by wzei              #+#    #+#             */
/*   Updated: 2019/10/22 19:33:02 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_m.h"

static void rights(char *rgh, struct stat *file_stat)
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

static char file_type(struct stat *file_stat)
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

static char xattr(t_fileinfo *file)
{
	if (file->_xattr < 0)
		file->_xattr = 0;
	if (file->_xattr > 0)
		return ('@');
	else if (file->_acl != 0)
		return ('+');
	else
		return (' ');
	return (' ');
}

static char *get_time(struct stat *st)
{
	char	*tm;
	time_t cur_time;
	time_t targ_time;
	
	cur_time = time(NULL);
	targ_time = ((st->st_mtimespec).tv_sec);
	tm = ctime(&targ_time);
	if ((cur_time - targ_time) < (31536000 / 2))
	{
		ft_memmove(tm, tm + 4, 12);
		tm[12] = '\0';
	}
	else
	{
		ft_memmove(tm, tm + 4, 6);
		tm[6] = ' ';
		ft_memmove(tm + 7, tm + 19, 5);
		tm[12] = '\0';
	}	
	return (tm);
}

static void	print_device(t_long_out *l_o, t_fileinfo *file, t_max_out *max)
{
	int			 major;
	int			 minor;

	major = (int)major((l_o->st).st_rdev);
	minor = (int)minor((l_o->st).st_rdev);
	ft_printf("%c%s%c %*.d %-*.*s  %-*.*s  %*.*d, %*.*d %s %s\n",
		l_o->f_type, l_o->rgh, l_o->x_attr,
		(int)max->lnk, (int)((l_o->st).st_nlink),
		(int)max->user, (int)ft_strlen((l_o->pass)->pw_name),
		(l_o->pass)->pw_name,
		(int)max->group, (int)ft_strlen((l_o->gr)->gr_name),
		(l_o->gr)->gr_name,
		(int)max->major, (int)num_len(major), major,
		(int)max->minor, (int)num_len(minor), minor,
		time, file->name);
}

static void	print_link(t_long_out *l_o, t_fileinfo *file,
						char *path, t_max_out *max)
{
	size_t	len;
	char	*filename;

	filename = NULL;
	len = ft_strlen(path) + ft_strlen(file->name) + 2;
	filename = ft_strnew(len);
	ft_strlcat(filename, path, len);
	ft_strlcat(filename, "/", len);
	ft_strlcat(filename, file->name, len);
	readlink(filename, l_o->lnk, 1024);
	free(filename);
	ft_printf("%c%s%c %*.d %-*.*s  %-*.*s  %s%*.*d %s %s -> %s\n",
		l_o->f_type, l_o->rgh, l_o->x_attr,
		(int)max->lnk, (int)((l_o->st).st_nlink),
		(int)max->user, (int)ft_strlen((l_o->pass)->pw_name),
		(l_o->pass)->pw_name,
		(int)max->group, (int)ft_strlen((l_o->gr)->gr_name),
		(l_o->gr)->gr_name,
		((int)max->major == 0 ? "" : "\t "),
		(int)max->size, (int)num_len((l_o->st).st_size),
		(int)(l_o->st).st_size, time,
		file->name, l_o->lnk);
}

static void	print_reg_dir(t_long_out *l_o, t_fileinfo *file, t_max_out *max)
{
	ft_printf("%c%s%c %*.d %-*.*s  %-*.*s  %s%*.*d %s %s\n",
		l_o->f_type, l_o->rgh, l_o->x_attr,
		(int)max->lnk, (int)((l_o->st).st_nlink),
		(int)max->user, (int)ft_strlen((l_o->pass)->pw_name),
		(l_o->pass)->pw_name,
		(int)max->group, (int)ft_strlen((l_o->gr)->gr_name),
		(l_o->gr)->gr_name,
		((int)max->major == 0 ? "" : "\t "),
		(int)max->size, (int)num_len((l_o->st).st_size),
		(int)(l_o->st).st_size, time,
		file->name);
}

static void	init_long_output(t_long_out *l_o, t_fileinfo *file)
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

void		print_long_entry(t_fileinfo *file, t_max_out *max, char *path)
{
	t_long_out l_o;
	
	init_long_output(&l_o, file);
	if (l_o.f_type == '-' || l_o.f_type == 'd')
		print_reg_dir(&l_o, file, max);
	if (l_o.f_type == 'l')
		print_link(&l_o, file, path, max);
	if (l_o.f_type == 'b' || l_o.f_type == 'c' ||
		l_o.f_type == 'f' || l_o.f_type == 's')
		print_device(&l_o, file, max);
	return ;
}
