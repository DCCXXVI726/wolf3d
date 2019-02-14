# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:25:57 by thorker           #+#    #+#              #
#    Updated: 2019/02/14 19:01:01 by bfalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAG = -Wall -Wextra -Werror -g
SRC = create_struct.c main.c put_img.c hook.c key_hook.c
INC = -I /usr/local/include -I libft/
LIB = -L /usr/local/lib -lmlx -L libft/ -lft
FRWR = -framework OpenGL -framework OpenCL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAG) $(INC) $(LIB) $(SRC) $(FRWR) -o $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make -C libft/ clean
	rm -f *.o

fclean:
	rm -f $(NAME)
	make clean
	make -C libft/ fclean
	
re:
	make fclean
	make

git: clean
	git add --all
	git status
	git commit -m "auto git"
	git push
