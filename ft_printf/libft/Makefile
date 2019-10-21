# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 21:30:36 by wzei              #+#    #+#              #
#    Updated: 2019/10/21 17:21:45 by wzei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRC= ft_atoi.c \
ft_bzero.c \
ft_fgetc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isupper.c \
ft_iswhtspc.c \
ft_itoa.c \
ft_lstadd.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_mlst_revsort.c \
ft_mlstdel.c \
ft_mlstnew.c \
ft_mlstpurge.c \
ft_mlstpush.c \
ft_mlstsort.c \
ft_mlstswap.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnotwhgt.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strsgnstat.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtol.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \
ft_vecadd.c \
ft_veccnt.c \
ft_vecdel.c \
ft_vecfree.c \
ft_vecget.c \
ft_vecgetfirst.c \
ft_vecgetlast.c \
ft_vecnew.c \
ft_vecsel.c \
ft_vecset.c

OBJ = $(SRC:.c=.o)

FLAGS = -g -Wall -Werror -Wextra

INC = -Iinclude

RM = /bin/rm -f

TEST_NAME = test.cut

TEST_SRC = test.c

cc = gcc

.c.o:
	@$(cc) $(INC) $(FLAGS) -c $< -o $@
	@printf "\e[32m😲 😲 😲  build success \e[36m$<\n"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "\e[36m 🏁  👍  👍  👍  $(NAME) 👍  👍  👍  🏁  !\n"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@printf "\e[33mCleaned 😵 😵 😵 😵  !!!\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "\e[31mFull cleaned 💀 💀 💀 💀  !!!\n"

re: fclean all