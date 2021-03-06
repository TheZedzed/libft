# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azeraoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 11:57:47 by azeraoul          #+#    #+#              #
#    Updated: 2021/04/18 10:38:21 by thezedzed        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a

SRC 	:=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
			ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_strndup.c ft_isspace.c ft_strcmp.c get_next_line.c \
			ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstiter.c \
			ft_lstdelone.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

OBJ 	:=	$(SRC:.c=.o)
DEP		:=	./include
CC		:=	gcc
CFLAGS	+=	-Wall -Wextra -Werror
RM		:=	rm -f
AR		:=	ar -rcs

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) -I$(DEP) -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
