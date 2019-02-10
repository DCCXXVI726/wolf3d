# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thorker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:25:57 by thorker           #+#    #+#              #
#    Updated: 2019/02/10 17:26:42 by thorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAG = -Wall -Wextra -Werror
SRC = 
INC = -I /usr/local/include -I libft/
LIB = -L /usr/local/lib -lmlx -L libft/ -lft
FRWR = -framework OpenGL -framework OpenCL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAG) $(INC) $(LIB) $(SRC) $(FRWR) -o $(NAME)

clean:
	make -C libft/ clean
	rm -rf *.o

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

git: clean
	make -C libft/ git
	git add --all
	git status
	git commit -m "auto git"
	git push
