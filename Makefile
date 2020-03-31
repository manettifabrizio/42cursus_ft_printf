# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 18:13:16 by fmanetti          #+#    #+#              #
#    Updated: 2020/03/31 16:56:54 by fmanetti         ###   ########.fr        #
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
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm $(OBJ)

fclean: clean
	@/bin/rm $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
