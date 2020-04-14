# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 18:13:16 by fmanetti          #+#    #+#              #
#    Updated: 2020/04/14 15:10:31 by fmanetti         ###   ########.fr        #
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
			tools/my_putnbr.c \
			tools/my_putstr.c 

OBJ			= $(SOURCE:%.c=%.o) 

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@printf "[ft_printf] Compiling.  \r"
	@gcc $(FLAGS) -c $< -o $@
	@printf "[ft_printf] Compiling . \r"
	@printf "[ft_printf] Compiling  .\r"

$(NAME): $(OBJ)
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "[ft_printf] Removed object files!\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

re: fclean all

.PHONY: all bonus clean fclean re