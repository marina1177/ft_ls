# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 19:46:53 by wzei              #+#    #+#              #
#    Updated: 2019/10/23 15:58:58 by wzei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WFLAGS = -Wall -Werror -Wextra
FLAGS = -g $(WFLAGS)
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
				traverce_cur_dir.c \
				get_dir_entries.c \
				print_long_entry.c \
				print_list.c \
				udate_max.c \
				init_max.c \
				num_len.c \
				init_long_output.c \
				print_device.c \
				print_link.c \
				print_reg_dir.c

DIR_S = srcs
DIR_H = includes
DIR_O = obj

FT_PRINTF = ./ft_printf

SRCS = $(addprefix $(DIR_S)/,$(FT_LS_M_SRC))

OBJS = $(addprefix $(DIR_O)/,$(FT_LS_M_SRC:.c=.o))

all: $(NAME)

libftprintf.a:
	@mkdir -p $(DIR_O)
	make -C ft_printf re
	@printf "\e[32mft_printf build success \e[36m$<\n"
	@cp ./ft_printf/libftprintf.a ./$(DIR_O)/libftprintf.a

$(NAME): libftprintf.a $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(DIR_O)/*

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(DIR_H) -c -o $@ $<
	@printf "\e[32mbuild success \e[36m$<\n"

#$(FT_PRINTF):
#	make -C ft_printf
#	@printf "\e[32mft_printf build success \e[36m$<\n"
#
#$(NAME): $(FT_PRINTF) $(OBJS)
#	$(CC) $(FLAGS) $(DIR_O)/* -o $(NAME)
#
#$(DIR_O)/%.o: $(DIR_S)/%.c $(FT_PRINTF)
#	@mkdir -p $(DIR_O)
#	@$(CC) $(FLAGS) -I $(DIR_H) -c $^ -o $@
#	@printf "\e[32mbuild success \e[36m$<\n"

clean:
	rm -rf *.o
	rm -rf $(DIR_O)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

norme:
	norminette ./ft_printf/*.[ch]
	@echo
	norminette ./$(DIR_H)/*.[ch]
	@echo
	norminette ./$(DIR_S)/*.[ch]

.PHONY: all clean fclean re