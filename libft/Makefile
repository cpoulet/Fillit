# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mploux <mploux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:20:21 by mploux            #+#    #+#              #
#    Updated: 2016/11/08 17:20:42 by mploux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_iswhitespace.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
		ft_memset.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c\
		ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
		ft_striter.c ft_striteri.c ft_strlen.c ft_strlenf.c ft_strjoin.c \
		ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		ft_strstr.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strsub.c \
		ft_putchar.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putnbr.c ft_itoa.c ft_nbrlen.c ft_strlcat.c \
		ft_lstnew.c ft_isupper.c ft_islower.c ft_memdup.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
