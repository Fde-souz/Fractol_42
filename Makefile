# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by fde-souz          #+#    #+#              #
#    Updated: 2018/01/23 13:04:22 by fde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fractol

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LFT_PATH = ./libft/
MLX_PATH = ./minilibx_macos/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = fractol.h

SRC_NAME = main.c \
		   image.c \
		   mandelbrot.c \
		   julia.c \
		   mouse_hook.c \
		   key_hook.c \
		   complex.c \
		   colors.c \
		   burning_ship.c


all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@make -C $(MLX_PATH)
	$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft -lmlx -lm -framework OpenGL -framework AppKit


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
clean_o:
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re: fclean all
