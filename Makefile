# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 14:25:13 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/11/23 12:52:40 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### VARIABLES

NAME	= cub3d

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

FILES   = srcs/main.c \
          srcs/init.c \
          srcs/parsing/parsing.c \
          srcs/parsing/get_map.c \
          srcs/parsing/get_data.c \
          srcs/parsing/get_rgb.c \
          srcs/parsing/check_map.c \
          srcs/parsing/check_walls.c \
          srcs/parsing/floodfill.c \
          srcs/display/display.c \
          srcs/display/walls.c \
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
LIB	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz


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

clean :
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean

fclean : clean
	rm -rf $(MLX_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus