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
  char              *linkname[256];
  char              path[1024];
  int				_acl;
  ssize_t			_xattr;
  struct stat       stat;
  enum filetype     type;
}                   t_fileinfo;

int                 get_fileinfo(t_fileinfo *file, char *path, char *name);

#endif //LS_SORT_FILE_INFO_H
