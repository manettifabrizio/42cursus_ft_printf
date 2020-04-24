# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 18:13:16 by fmanetti          #+#    #+#              #
#    Updated: 2020/04/24 12:21:59 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

SOURCE = 	src/ft_printf.c \
			src/print_conv/integer.c \
			src/print_conv/uinteger.c \
			src/print_conv/character.c \
			src/print_conv/string.c \
			src/print_conv/pointer.c \
			src/print_conv/hexadecimal.c \
			src/print_conv/percent.c \
			src/print_conv/number.c \
			src/print_conv/float_f.c \
			src/print_conv/float_e.c \
			src/flags/flags.c \
			src/flags/flagstools.c \
			src/tools/convert_float.c \
			src/tools/dec_to_e.c \
			src/tools/tools.c \
			src/tools/tools1.c \
			src/tools/tools2.c \
			src/tools/tools3.c \
			src/tools/ft_ftoa.c \
			src/tools/ft_bigint_add.c \
			src/tools/ft_bigint_trim.c \
			src/tools/ft_bigint_shift_right.c \
			src/tools/ft_bigint_divide_by_two.c \
			src/tools/ft_bigint_multiply_by_two.c \
			src/tools/ft_bigint_round.c \
			src/tools/my_putnbr.c \
			src/tools/my_putstr.c \
			src/tools/my_strjoin.c

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
	@printf "\033[0;31mObject files removed\n\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/
	@printf "\033[0;31m[ $(NAME) ] removed\n\033[0m"

re: fclean all

.PHONY: all clean fclean re