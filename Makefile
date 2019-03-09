# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:25:57 by thorker           #+#    #+#              #
#    Updated: 2019/03/09 16:32:56 by thorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAG = -Wall -Wextra -Werror -g
SRC = create_struct.c hook.c put_img.c key_hook.c mouse_hook.c main.c move.c
INC = -I /usr/local/include -I libft/ -I ./includes
LIB = -L /usr/local/lib -lmlx -L libft/ -lft
FRWR = -framework OpenGL -framework OpenCL -framework AppKit
OBJS = $(addprefix objects/, $(SRC:.c=.o))
OBJDIR = objects
SRCDIR = src

.PHONY: all clean fclean re git_%

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	make lib_ft
	$(CC) $(FLAG) $(OBJS) $(INC) $(LIB) $(FRWR) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(FLAG) $(INC) -c $^ -o $@

lib_ft:
	make -C libft

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
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
