# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mploux <mploux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 15:30:27 by mploux            #+#    #+#              #
#    Updated: 2016/11/14 20:50:45 by mploux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FILES =	fillit.c\
		ft_readfile.c\
		ft_origin.c\
		ft_solve.c\
		vec2.c\
		ft_check.c

SRC = $(addprefix srcs/,$(FILES))
OBJ = $(FILES:.c=.o)

INCLUDES = -I includes/ -I libft/
LIBS = -L libft/ -lft
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	gcc -o $@ $(OBJ) $(CFLAGS) $(INCLUDES) $(LIBS)

%.o: srcs/%.c
	gcc -o $@ -c $< $(CFLAGS) $(INCLUDES)

clean :
	rm -f $(OBJ)
	@make clean -C libft/

fclean : clean
	rm -f $(NAME)
	@make fclean -C libft/

re : fclean all

.PHONY : all clean fclean re
