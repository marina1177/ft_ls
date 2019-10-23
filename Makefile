# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 19:46:53 by wzei              #+#    #+#              #
#    Updated: 2019/10/23 18:34:07 by wzei             ###   ########.fr        #
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
				print_reg_dir.c \
				$(MUL_O)

MUL_O =	ft_bzero.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_mlst_revsort.c \
		ft_mlst_sort.c \
		ft_mlstnew.c \
		ft_mlstpurge.c \
		ft_mlstpush.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnew.c

DIR_S = srcs
DIR_H = includes
DIR_O = obj
DIR_MUL = mul

FT_PRINTF = ./ft_printf

SRCS = $(addprefix $(DIR_S)/,$(FT_LS_M_SRC))

OBJS = $(addprefix $(DIR_O)/,$(FT_LS_M_SRC:.c=.o))

all: $(NAME)

libftprintf.a:
	@mkdir -p $(DIR_O)
	make -C ft_printf
	@printf "\e[32mft_printf build success \e[36m$<\n"
	@cp ./ft_printf/libftprintf.a ./$(DIR_O)/libftprintf.a
	@ar x ./$(DIR_O)/libftprintf.a
	@cp ./*.o ./$(DIR_O)/
	@rm -f *.o __.SYMDEF

$(NAME): libftprintf.a $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(DIR_O)/libftprintf.a

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

mul_clean:
	@rm -rf $(DIR_MUL)

mul: mul_clean fclean
	@mkdir -p $(DIR_MUL)
	@mkdir -p $(DIR_MUL)/$(DIR_S)
	@mkdir -p $(DIR_MUL)/$(DIR_H)
	@echo 'WFLAGS = -Wall -Werror -Wextra' > $(DIR_MUL)/Makefile
	@echo 'FLAGS = -g $$(WFLAGS)' >> $(DIR_MUL)/Makefile
	@echo 'CC = gcc' >> $(DIR_MUL)/Makefile
	@echo 'SRC = srcs' >> $(DIR_MUL)/Makefile
	@echo 'INC = includes' >> $(DIR_MUL)/Makefile
	@echo 'NAME = ft_ls' >> $(DIR_MUL)/Makefile
	@cp -R $(DIR_S)/*.c $(DIR_MUL)/$(DIR_S)
	@cp -R $(FT_PRINTF)/sources/*.c $(DIR_MUL)/$(DIR_S)
	@cp -R $(FT_PRINTF)/libft/*.c $(DIR_MUL)/$(DIR_S)
	@cp -RHf $(DIR_H)/*.h $(DIR_MUL)/$(DIR_H)
	@cp -RHf $(FT_PRINTF)/includes/*.h $(DIR_MUL)/$(DIR_H)
	@cp -RHf $(FT_PRINTF)/libft/*.h $(DIR_MUL)/$(DIR_H)
	@ls -1 $(DIR_MUL)/$(DIR_S) > tmp_src.txt
	@sed 's/.c$$/.c \\/g' tmp_src.txt > tmp_src2.txt
	@sed '$$s/.c \\$$/.c/g' tmp_src2.txt > tmp_src.txt
	@rm tmp_src2.txt
	@echo "SRCS_S = \\" >> $(DIR_MUL)/Makefile
	@cat tmp_src.txt >> $(DIR_MUL)/Makefile
	@echo '\nSRCS = $$(addprefix $$(DIR_S)/,$$(SRCS_S))' >> $(DIR_MUL)/Makefile
	@echo 'OBJS = $$(addprefix $$(DIR_O)/,$$(SRCS_S:.c=.o))' >> $(DIR_MUL)/Makefile
	@echo '\nDIR_S = srcs' >> $(DIR_MUL)/Makefile
	@echo 'DIR_H = includes' >> $(DIR_MUL)/Makefile
	@echo 'DIR_O = obj' >> $(DIR_MUL)/Makefile
	@echo '\nall: $$(NAME)\n' >> $(DIR_MUL)/Makefile
	@echo '\n$$(NAME): $$(OBJS)' >> $(DIR_MUL)/Makefile
	@echo '\t$$(CC) $$(FLAGS) -o $$(NAME) $$(OBJS)' >> $(DIR_MUL)/Makefile
	@echo '\n$$(DIR_O)/%.o: $$(DIR_S)/%.c' >> $(DIR_MUL)/Makefile
	@echo '\t@mkdir -p $$(DIR_O)' >> $(DIR_MUL)/Makefile
	@echo '\t@$$(CC) $$(FLAGS) -I $$(DIR_H) -c -o $$@ $$<' >> $(DIR_MUL)/Makefile
	@echo '\nclean:' >> $(DIR_MUL)/Makefile
	@echo '\t@rm -rf *.o' >> $(DIR_MUL)/Makefile
	@echo '\t@rm -rf $$(DIR_O)' >> $(DIR_MUL)/Makefile
	@echo '\nfclean: clean' >> $(DIR_MUL)/Makefile
	@echo '\t@rm -f $$(NAME)' >> $(DIR_MUL)/Makefile
	@echo '\nre: fclean all' >> $(DIR_MUL)/Makefile

mul_mul: mul
	make -C mul


#.PHONY: all clean fclean re