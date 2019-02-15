# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:25:57 by thorker           #+#    #+#              #
#    Updated: 2019/02/15 14:53:47 by bfalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAG = -Wall -Wextra -Werror -g
SRC = create_struct.c main.c kernel.c hook.c key_hook.c player.c
OBJ = $(SRC:.c=.o)
INC = -I /usr/local/include -I libft/
LIB = -L /usr/local/lib -lmlx -L libft/ -lft
FRWR = -framework OpenGL -framework OpenCL -framework AppKit
.PHONY: all clean fclean re git_%

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAG) $(INC) $(LIB) $(SRC) $(FRWR) -o $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o objects/$@

clean:
	make -C libft/ clean
	rm -f objects/*.o

fclean:
	make clean
	make -C libft/ fclean
	rm -f $(NAME)
	
re:
	make fclean
	make

git_%: clean
	git add --all
	git status
	git commit -m "$@"
	git push
