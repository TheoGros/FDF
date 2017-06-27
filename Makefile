# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgros <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 12:06:23 by tgros             #+#    #+#              #
#    Updated: 2017/03/03 16:27:38 by tgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT_NAME = libft.a

SRC_PATH = src/
MLX_PATH = mlx/
INC_PATH = inc/
LIB_PATH = libft/

SRC_NAME = fdf read_file parse util render key_pressed pts_op calcul free \
		   color modif
SRC_NAME_PATH = $(addprefix $(SRC_PATH), $(SRC_NAME))
SRC = $(addsuffix $(EXT), $(SRC_NAME_PATH))

OBJ = $(SRC:.c=.o)

EXT = .c
CC	= gcc
FLG = -Werror -Wextra -Wall
MLX = -framework OpenGL -framework AppKit 

all: $(NAME)

%.o : %.c
	@$(CC) $(FLG) -I$(INC_PATH) -I$(LIB_PATH) -c -o $@ $^ 

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) ./mlx/libmlx.a $(FLG) $(MLX) $(LIB_PATH)$(LIBFT_NAME) $(OBJ) -o $(NAME)
	@echo "fdf: done"

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIB_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all
