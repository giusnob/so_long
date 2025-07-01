# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giusnob <giusnob@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 20:58:41 by giusnob           #+#    #+#              #
#    Updated: 2025/07/01 16:14:27 by giusnob          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I. -Iinclude -Ift_printf/libft -Ift_printf

FT_DIR   = ft_printf
MLX_DIR  = mlx
INCLUDES = -Iinclude -I$(FT_DIR)/libft -I$(FT_DIR)

SRC = $(addprefix srcs/, \
    main.c load_map.c map_parser_utils.c map_utils.c check_map.c \
    flood_fill.c init_game.c handle_input.c render_map.c sprite.c)

OBJ = $(SRC:.c=.o)

# MLX_LIBS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
# Per Linux, usa invece:
MLX_LIBS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz -lbsd

LIBFT = $(FT_DIR)/libft/libft.a
FTPRINTF = $(FT_DIR)/libftprintf.a

.PHONY: all clean fclean re libft mlx

all: $(LIBFT) $(FTPRINTF) mlx $(NAME)

$(LIBFT):
	$(MAKE) -C $(FT_DIR)/libft

$(FTPRINTF):
	$(MAKE) -C $(FT_DIR)

mlx:
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBFT) $(FTPRINTF) $(MLX_LIBS) -o $@

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(FT_DIR)/libft clean
	$(MAKE) -C $(FT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT) $(FTPRINTF)

re: fclean all
