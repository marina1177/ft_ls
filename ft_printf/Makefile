# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzei <wzei@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 21:31:52 by rfrieda           #+#    #+#              #
#    Updated: 2019/10/01 23:08:20 by wzei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -g 

LIBFT = libft

DIR_S = sources

DIR_O = temporary

HEADER = includes

SOURCES = ft_printf.c \
		  ft_cs_flags.c \
		  ft_diu_flags.c \
		  ft_f_flag.c \
		  ft_format.c \
		  ft_oxp_flags.c \
		  ft_print_force.c \
		  ft_print_out.c \
		  ft_print_round.c \
		  ft_print_f.c \
		  ft_print_lf.c \
		  ft_print_sign.c \
		  ft_print_spaces.c \
		  ft_print_xp.c \
		  ft_print_o.c \
		  ft_print_diu.c \
		  ft_print_pre_zeros.c \
		  check_zero_p.c \
		  check_zero_w.c \
		  ft_rnd.c \
		  is_zero.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all