# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:25:57 by thorker           #+#    #+#              #
#    Updated: 2019/02/14 18:09:16 by bfalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAG = -Wall -Wextra -Werror -g
SRC = create_struct.c main.c put_img.c
INC = -I /usr/local/include -I libft/
LIB = -L /usr/local/lib -lmlx -L libft/ -lft
FRWR = -framework OpenGL -framework OpenCL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make lib_ft
	$(CC) $(FLAGS) $(OBJS) -I $(INC) $(LIB) $(FRWR) -o $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

lib_ft:
	make -C libft

clean:
	/bin/rm -f *.o
	make -C libft/ clean

fclean: 
	make clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

git: clean
	git add --all
	git status
	git commit -m "auto git"
	git push
