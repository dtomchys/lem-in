	#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 12:46:46 by dtomchys          #+#    #+#              #
#    Updated: 2018/03/27 12:46:48 by dtomchys         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in
CC = gcc -Wall -Werror -Wextra -g3
RM = rm -f
HD = ft_lem_in.h
MFLIB = ./libft
SRC = ft_lem_in.c ft_make_rooms.c ft_error_managment.c ft_make_links.c\
queue_manag.c ft_find_ways.c ft_ways.c ft_tools.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

OBJ: $(SRC) $(HD)
	$(CC) $(SRC) $(HD) -c

$(NAME):  $(OBJ) $(HD)
	make -C $(MFLIB)
	$(CC) -o $(NAME) $(OBJ) -I.$(HD) libft/libft.a

clean:
	make clean -C $(MFLIB)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: clean fclean
