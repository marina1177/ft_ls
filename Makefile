# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 19:46:53 by wzei              #+#    #+#              #
#    Updated: 2019/10/21 16:41:54 by wzei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WFLAGS = -Wall -Werror -Wextra
FLAGS = -g #$(WFLAGS)
CC = gcc
SRC = srcs
INC = includes
NAME = ft_ls
FT_LS_M_SRC =   file_info.c \
				ft_ls_m.c \
				ft_lstsort.c \
				ls_cmp.c \
				ls_error.c \
				ls_parse_input.c \
				ls_sort.c \
				ls_sort_args.c \
				trav_dirs.c \
				traverce_cur_dir.c

DIR_S = srcs
DIR_H = includes
DIR_O = obj

SRCS = $(addprefix $(DIR_S)/,$(FT_LS_M_SRC))

OBJS = $(addprefix $(DIR_O)/,$(FT_LS_M_SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf re
	@cp ft_printf/libftprintf.a ./$(DIR_O)/libftprintf.a
	$(CC) $(FLAGS) -o $(NAME) $(DIR_O)/*

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(DIR_H) -o $@ -c $<

clean:
	rm -rf *.o
	rm -rf $(DIR_O)
	make -C ft_printf clean

fclean: clean
	rm -f *.bin
	make -C ft_printf fclean

re: fclean all

norme:
	norminette ./libft/*.[ch]
	@echo
	norminette ./$(DIR_H)/*.[ch]
	@echo
	norminette ./$(DIR_S)/*.[ch]

.PHONY: re
