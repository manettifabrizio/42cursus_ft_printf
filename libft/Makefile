# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 17:50:17 by fmanetti          #+#    #+#              #
#    Updated: 2020/04/24 12:32:05 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = src/ft_memset.c \
		src/ft_bzero.c \
		src/ft_memcpy.c \
		src/ft_memccpy.c \
		src/ft_memmove.c \
		src/ft_memalloc.c \
		src/ft_memdel.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_strlen.c \
		src/ft_isalpha.c \
		src/ft_isdigit.c \
		src/ft_isalnum.c \
		src/ft_isascii.c \
		src/ft_isprint.c \
		src/ft_toupper.c \
		src/ft_tolower.c \
		src/ft_strchr.c \
		src/ft_strrchr.c \
		src/ft_strcmp.c \
		src/ft_strncmp.c \
		src/ft_strcpy.c \
		src/ft_strncpy.c \
		src/ft_strlcpy.c \
		src/ft_strcat.c \
		src/ft_strncat.c \
		src/ft_strlcat.c \
		src/ft_strnstr.c \
		src/ft_atoi.c \
		src/ft_calloc.c \
		src/ft_strdup.c \
		src/ft_substr.c \
		src/ft_strjoin.c \
		src/ft_strtrim.c \
		src/ft_split.c \
		src/ft_itoa.c \
		src/ft_strmapi.c \
		src/ft_putchar.c \
		src/ft_putchar_fd.c \
		src/ft_putstr.c \
		src/ft_putstr_fd.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr.c \
		src/ft_putnbr_fd.c 

BONUS = src/ft_lstnew.c \
		src/ft_lstadd_front.c \
		src/ft_lstsize.c \
		src/ft_lstlast.c \
		src/ft_lstadd_back.c \
		src/ft_lstdelone.c \
		src/ft_lstclear.c \
		src/ft_lstiter.c \
		src/ft_lstmap.c 

OBJ			= $(SOURCE:%.c=%.o)

OBJB		= $(BONUS:%.c=%.o) $(OBJ)

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@printf "[ libft ] Compiling.  \r"
	@gcc $(FLAGS) -c -g $< -o $@
	@printf "[ libft ] Compiling . \r"
	@printf "[ libft ] Compiling  .\r"

$(NAME): $(OBJ)
	@printf "\033[0;32m[ libft ] Compiled Successfully\n\033[0m"
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@printf "\033[0;32m[ $(NAME) ] Created Successfully\n\033[0m" $(SUCCESS)

bonus: $(OBJB)
	@ar rc $(NAME) $(OBJB)
	@ranlib $(NAME)
	@printf "\033[0;32m[ $(NAME) + bonus] Created Successfully\n\033[0m" $(SUCCESS)

clean:
	@/bin/rm -f $(OBJ) $(OBJB)

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "\033[0;31m[ $(NAME) ] removed\n\033[0m"

re: fclean all

.PHONY: all bonus clean fclean re
