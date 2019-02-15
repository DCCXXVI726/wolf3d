# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 17:47:33 by thorker           #+#    #+#              #
#    Updated: 2019/02/15 16:35:48 by bfalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
INC=libft.h get_next_line.h
SRC= check_error_n_exit.c init_opencl.c ft_vctdel.c ft_vctadd.c ft_vctnew.c ft_advatoi.c ft_filedel.c get_next_line.c ft_power.c ft_lstcount.c ft_lstaddlast.c ft_strrev.c ft_putnbrln.c ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstnew.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
FLAGS = -Wall -Wextra -Werror
OBJ= $(SRC:.c=.o) 
$(NAME):
	gcc $(FLAGS) -c $(SRC) -I $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean $(NAME)

test_%:
	gcc $(FLAGS) test/$@.c libft.a -o $@
	./$@

git: clean
	git add --all
	git status
	git commit -m "make git"
	git push
