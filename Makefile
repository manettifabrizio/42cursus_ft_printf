# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 18:13:16 by fmanetti          #+#    #+#              #
#    Updated: 2022/04/24 19:19:00 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	libftprintf.a

FILES			=	ft_printf.c							\
					print_conv/integer.c				\
					print_conv/uinteger.c				\
					print_conv/character.c				\
					print_conv/string.c					\
					print_conv/pointer.c				\
					print_conv/hexadecimal.c			\
					print_conv/percent.c				\
					print_conv/number.c					\
					print_conv/float_f.c				\
					print_conv/float_e.c				\
					flags/flags.c						\
					flags/flagstools.c					\
					tools/convert_float.c				\
					tools/dec_to_e.c					\
					tools/tools.c						\
					tools/tools1.c						\
					tools/tools2.c						\
					tools/tools3.c						\
					tools/ft_ftoa.c						\
					tools/ft_bigint_add.c				\
					tools/ft_bigint_trim.c				\
					tools/ft_bigint_shift_right.c		\
					tools/ft_bigint_divide_by_two.c		\
					tools/ft_bigint_multiply_by_two.c	\
					tools/ft_bigint_round.c				\
					tools/my_putnbr.c					\
					tools/my_putnbrx.c					\
					tools/my_putstr.c					\
					tools/my_substr.c					\
					tools/my_strjoin.c
FILES_PATH		=	./srcs/

HFILES			=	libftprintf.h
HFILES_PATH		=	./include/

SOURCE			=	$(addprefix $(FILES_PATH), $(FILES))
HEADERS			=	$(addprefix $(HFILES_PATH), $(HFILES))

OBJ				=	$(SOURCE:%.c=%.o) 

CC				=	clang

CFLAGS			=	-Wall -Wextra -Werror
FSANITIZE		= 	-g3 -O0 -fsanitize=address

RED				=	\033[0;31m
GREEN			=	\033[0;32m
RESET			=	\033[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@make -C include/libft/
	@cp include/libft/libft.a ./$(NAME)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@printf "$(GREEN)"
	@printf "    _|_|    _|                                  _|              _|          _|_|  \n"
	@printf "  _|      _|_|_|_|          _|_|_|    _|  _|_|      _|_|_|    _|_|_|_|    _|      \n"
	@printf "_|_|_|_|    _|              _|    _|  _|_|      _|  _|    _|    _|      _|_|_|_|  \n"
	@printf "  _|        _|              _|    _|  _|        _|  _|    _|    _|        _|      \n"
	@printf "  _|          _|_|          _|_|_|    _|        _|  _|    _|      _|_|    _|      \n"
	@printf "                            _|                                                    \n"
	@printf "                _|_|_|_|_|  _|                                                    \n"
	@printf "$(RESET)"
	@printf " ___         __                     _   _   _  \n"
	@printf "| _ )_  _   / _|_ __  __ _ _ _  ___| |_| |_(_) \n"
	@printf "| _ \ || | |  _| '  \/ _' | ' \/ -_)  _|  _| | \n"
	@printf "|___/\_, | |_| |_|_|_\__,_|_||_\___|\__|\__|_| \n"
	@printf "     |__/                                      \n"

bonus: all $(NAME)
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

.SILENT: