//
// Created by AN515-52-51JP on 16.10.2019.
//

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
   } ;

typedef struct      s_fileinfo
{
  char              name[256];
  char              linkname[256];
  char              path[1024];
  int				_acl;
  ssize_t			_xattr;
  struct stat       ft_stat;
  enum filetype     type;
}                   t_fileinfo;

typedef struct      s_max_out
{
	unsigned long			lnk;
	unsigned long			size;
	unsigned long			major;	
	unsigned long			minor;
	unsigned long			name;
	unsigned long			user;
	unsigned long			group;
	unsigned long			blk;
}                   t_max_out;

int					get_fileinfo(t_fileinfo *file, char *path, char *name);
void				udate_max(t_fileinfo *file, t_max_out *max);
void				init_max(t_max_out *max);

#endif //LS_SORT_FILE_INFO_H
