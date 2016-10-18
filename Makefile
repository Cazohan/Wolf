# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/28 13:19:17 by lherbelo          #+#    #+#              #
#*   Updated: 2016/10/06 10:01:33 by lherbelo         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

#Dir

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./Object

#Files

SRC_NAME = *.c
INC_NAME = -I ./inc/
LIBS = -L./libft/ -lft

#Util

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

#DIV

CC = clang
F_MLX = -L./minilibx/ -lmlx -framework OpenGL -framework AppKit
F_42 = -Werror -Wall -Wextra

#Rules

all: $(NAME)

$(NAME): makeo makec

makeo:
	make -C ./libft/
	make -C ./minilibx/
	mkdir -p $(OBJ_DIR)
	$(CC) $(F_42) $(INC) -c $(SRC)
	mv $(SRC_NAME:.c=.o) $(OBJ_DIR)

makec:
	$(CC) -g -o $(NAME) $(OBJ) $(LIBS) $(INC_NAME) $(F_MLX) $(F_42)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/
	make clean -C ./minilibx/

re: fclean all

.PHONY: all, clean, fclean, re

