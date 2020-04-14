# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 18:13:16 by fmanetti          #+#    #+#              #
#    Updated: 2020/04/14 11:07:16 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE = ft_printf.c \
		write/integer.c \
		write/uinteger.c \
		write/character.c \
		write/string.c \
		write/pointer.c \
		write/hexadecimal.c \
		write/floatw.c \
		write/percent.c \
		write/number.c \
		flags/flags.c \
		flags/flagstools.c \
		tools/tools.c \
		tools/tools1.c \
		tools/tools2.c \
		tools/ft_conv_hexa.c \
		tools/ft_ftoa.c \
		tools/ft_bigint_add.c \
		tools/ft_bigint_trim.c \
		tools/ft_bigint_shift_right.c \
		tools/ft_bigint_divide_by_two.c \
		tools/ft_bigint_multiply_by_two.c \
		tools/ft_bigint_round.c \
		libft/ft_atoi.c \
		libft/ft_putchar.c \
		libft/my_putnbr.c \
		libft/my_putstr.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		libft/ft_toupper.c \
		libft/ft_strdup.c \
		libft/ft_itoa.c \
		libft/ft_strjoin.c \
		libft/ft_strncmp.c

OBJ			= $(SOURCE:%.c=%.o) 

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME) $(SOURCE)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
