# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yilin <yilin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 14:25:13 by ahadj-ar          #+#    #+#              #
#    Updated: 2025/02/10 17:55:06 by yilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### VARIABLES

NAME	= cub3d

CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror

FILES   = srcs/main.c \
          srcs/init.c \
          srcs/init_mlx.c \
          srcs/parsing/parsing.c \
          srcs/parsing/get_map.c \
          srcs/parsing/get_data.c \
          srcs/parsing/get_rgb.c \
          srcs/parsing/check_map.c \
          srcs/parsing/check_walls.c \
          srcs/parsing/floodfill.c \
          srcs/display/display.c \
          srcs/display/walls.c \
          srcs/display/minimap.c \
          srcs/display/moves.c \
          srcs/display/rotate.c \
          srcs/display/display_tools.c \
          srcs/tools/ft_strdup.c \
          srcs/tools/ft_split.c \
          srcs/tools/tools_1.c \
          srcs/tools/tools_2.c \
          srcs/tools/tools_3.c \
          srcs/cleanup.c
		  
OBJS	= $(FILES:.c=.o)
MLX_DIR	= ./mlx
MLX		= $(MLX_DIR)/libmlx.a
INCLUDE = -I$(MLX_DIR)
LIB	    = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz


################################################################################
### RULES

all : $(NAME)

$(NAME) : $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(INCLUDE) -o $(NAME)

$(MLX) :
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	make -C $(MLX_DIR)

clean:
		rm -f $(OBJS)
		@if [ -d "$(MLX_DIR)" ]; then \
			make -C $(MLX_DIR) clean; \
		fi

fclean: clean
		rm -rf $(MLX_DIR)
		rm -f $(NAME)

re: fclean all


.PHONY : all clean fclean re bonus