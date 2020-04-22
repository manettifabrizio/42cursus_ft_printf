# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 18:13:16 by fmanetti          #+#    #+#              #
#    Updated: 2020/04/20 23:43:04 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

SOURCE = 	ft_printf.c \
			write/integer.c \
			write/uinteger.c \
			write/character.c \
			write/string.c \
			write/pointer.c \
			write/hexadecimal.c \
			write/percent.c \
			write/number.c \
			write/float_f.c \
			write/float_e.c \
			flags/flags.c \
			flags/flagstools.c \
			tools/convert_float.c \
			tools/dec_to_e.c \
			tools/tools.c \
			tools/tools1.c \
			tools/tools2.c \
			tools/tools3.c \
			tools/ft_ftoa.c \
			tools/ft_bigint_add.c \
			tools/ft_bigint_trim.c \
			tools/ft_bigint_shift_right.c \
			tools/ft_bigint_divide_by_two.c \
			tools/ft_bigint_multiply_by_two.c \
			tools/ft_bigint_round.c \
			tools/my_putnbr.c \
			tools/my_putstr.c 

OBJ			= $(SOURCE:%.c=%.o) 

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@printf "[ ft_printf ] Compiling.  \r"
	@gcc $(FLAGS) -c -g $< -o $@
	@printf "[ ft_printf ] Compiling . \r"
	@printf "[ ft_printf ] Compiling  .\r"

$(NAME): $(OBJ)
	@printf "\033[0;32m[ ft_printf ] Compiled Successfully\n\033[0m"
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@printf "\033[0;32m[ $(NAME) ] Created Successfully\n\033[0m" $(SUCCESS)

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "\033[0;31m\nObject files removed\n\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/
	@printf "\033[0;31m[ $(NAME) ] removed\n\033[0m"

re: fclean all

.PHONY: all clean fclean re