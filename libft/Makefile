# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 17:50:17 by fmanetti          #+#    #+#              #
#    Updated: 2020/04/20 23:43:38 by fmanetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strlcpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c 

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c 

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
