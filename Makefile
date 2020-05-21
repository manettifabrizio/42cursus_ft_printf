# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 18:13:16 by fmanetti          #+#    #+#              #
#    Updated: 2020/05/21 08:13:02 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

SOURCE = 	srcs/ft_printf.c \
			srcs/print_conv/integer.c \
			srcs/print_conv/uinteger.c \
			srcs/print_conv/character.c \
			srcs/print_conv/string.c \
			srcs/print_conv/pointer.c \
			srcs/print_conv/hexadecimal.c \
			srcs/print_conv/percent.c \
			srcs/print_conv/number.c \
			srcs/print_conv/float_f.c \
			srcs/print_conv/float_e.c \
			srcs/flags/flags.c \
			srcs/flags/flagstools.c \
			srcs/tools/convert_float.c \
			srcs/tools/dec_to_e.c \
			srcs/tools/tools.c \
			srcs/tools/tools1.c \
			srcs/tools/tools2.c \
			srcs/tools/tools3.c \
			srcs/tools/ft_ftoa.c \
			srcs/tools/ft_bigint_add.c \
			srcs/tools/ft_bigint_trim.c \
			srcs/tools/ft_bigint_shift_right.c \
			srcs/tools/ft_bigint_divide_by_two.c \
			srcs/tools/ft_bigint_multiply_by_two.c \
			srcs/tools/ft_bigint_round.c \
			srcs/tools/my_putnbr.c \
			srcs/tools/my_putnbrx.c \
			srcs/tools/my_putstr.c \
			srcs/tools/my_substr.c \
			srcs/tools/my_strjoin.c

OBJ			= $(SOURCE:%.c=%.o) 

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@printf "[ ft_printf ] Compiling.  \r"
	@gcc $(FLAGS) -c -g $< -o $@
	@printf "[ ft_printf ] Compiling . \r"
	@printf "[ ft_printf ] Compiling  .\r"

$(NAME): $(OBJ)
	@printf "[ ft_printf ] Compiled \033[0;32mSuccessfully\n\033[0m"
	@make -C include/libft/
	@cp include/libft/libft.a ./$(NAME)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@printf "[ $(NAME) ] Created \033[0;32mSuccessfully\n\033[0m" $(SUCCESS)

bonus: $(NAME)
	@printf "[ $(NAME) + bonus] Created \033[0;32mSuccessfully\n\033[0m" $(SUCCESS)
	
clean:
	@make clean -C include/libft/
	@/bin/rm -f $(OBJ)
	@printf "Object files \033[0;31mremoved\n\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C include/libft/
	@printf "[ $(NAME) ] \033[0;31mremoved\n\033[0m"

re: fclean all

.PHONY: all clean fclean re
