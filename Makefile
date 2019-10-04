# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angkim <angkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 12:44:36 by angkim            #+#    #+#              #
#    Updated: 2019/10/02 11:37:53 by angkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
		get_mod_arg.c \
		get_format.c \
		put_perc.c \
		put.c \
		put_cp.c \
		put_s.c \
		put_diu.c \
		put_int_pad.c \
		put_ox_xx.c \
		put_ox_xx_val.c \
		put_f.c \
		ft_atoi.c \
		ft_digitcount.c \
		ft_isdigit.c \
		ft_iswhitespace.c \
		ft_memalloc.c \
		ft_bzero.c \
		ft_putchar.c \
		ft_puthex.c \
		ft_puthex_long.c \
		ft_putnbr.c \
		ft_putoctal.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_ltoa.c \
		ft_llutoa.c

FLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@echo "\x1b[31mmaking libftprintf.a...\x1b[0m"
	@gcc -c $(FLAGS) $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@echo "\x1b[31mcleaning libftprintf.a...\x1b[0m"
	@rm -f $(OBJS)

fclean: clean
	@echo "\x1b[31mremoving libftprintf.a...\x1b[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
