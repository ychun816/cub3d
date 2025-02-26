# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #

NAME	= cub3D

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
          srcs/display/moves.c \
          srcs/display/rotate.c \
          srcs/display/display_tools.c \
          srcs/tools/ft_strdup.c \
          srcs/tools/ft_split.c \
          srcs/tools/tools_1.c \
          srcs/tools/tools_2.c \
          srcs/tools/tools_3.c \
          srcs/cleanup.c \
          srcs/bonus/minimap.c \
          srcs/bonus/mouse.c \
          srcs/bonus/minimap_tool.c

OBJS	= $(FILES:.c=.o)
MLX_DIR	= ./mlx
MLX		= $(MLX_DIR)/libmlx.a
INCLUDE = -I$(MLX_DIR)
LIB	    = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# Silence all commands in Makefile
MAKEFLAGS += --silent

# **************************************************************************** #
#            Rules                                                             #
# **************************************************************************** #

all : $(NAME)

$(NAME) : $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(INCLUDE) -o $(NAME)
	@echo "$(BABEBLUEB)╔═════════════════════════════════════════╗$(RESET)"
	@$(TYP_EFF)
	@$(EMOJI_EFF)
	@echo "$(BABEBLUEB)╚═════════════════════════════════════════╝$(RESET)"

$(MLX) :
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	make -s -C $(MLX_DIR)

clean:
		rm -f $(OBJS)
		@if [ -d "$(MLX_DIR)" ]; then \
			make -C $(MLX_DIR) clean; \
		fi

fclean: clean
		rm -rf $(MLX_DIR)
		rm -f $(NAME)
		@echo "$(BLUE_BBG) $(MLX_DIR) and $(NAME) ALL REMOVED!$(RESET)"

re: fclean all


.PHONY : all clean fclean re bonus

# **************************************************************************** #
#                       COLORS & SOME FANCY THINGY                             #
# **************************************************************************** #

COLOR_RESET = \033[0m
PINKB = \033[1;95m
REDB = \033[1;91m
ROSEB = \033[1;38;5;225m
BLUEB = \033[1;34m
BABEBLUEB = \033[1;38;5;153m
GREENB = \033[1;38;5;85m
PURPLEB = \033[1;38;5;55m
PSTL_YELLOWB = \033[1;38;2;255;253;208m
PSTL_ORGB = \033[1;38;2;255;179;102m
PSTL_PURPLEB =\033[1;38;2;204;153;255m

GREEN_BBG = \033[1;42m
BLUE_BBG = \033[1;44m
YELLOW_BBG = \033[1;43m
ORANGE_BBG = \033[1;48;5;214m

### Typing effect animation ###
define TYP_EFF
	@echo -n "$(BABEBLUEB)║         $(RESET)"
	@for char in C o m p i l i n g \  . . . ; do \
		printf "%s" "$$char"; \
		sleep 0.1; \
	done
	@echo -n "$(BABEBLUEB)                   ║$(RESET)"
endef

### Exploding dots effect animation ###
define EMOJI_EFF
    @for i in '🌍' '🌎' '🌏' '🌍' '🌎' '🌏' '🌍' '🌎' '🌏'; do \
		printf "\r$(BABEBLUEB)║                $$i                       ║$(RESET)"; \
		sleep 0.2; \
	done
    @printf "\r$(BABEBLUEB)║    $(NAME) 🫵 created successfully!!!     ║\n$(RESET)"
endef
	# @for i in '🖐🏻' '✋🏻' '🖖🏻' '🖐🏻' '✋🏻' '🖖🏻' '🖐🏻' '✋🏻' '🖖🏻'; do \
    # @for i in '🌍' '🌎' '🌏' '🌍' '🌎' '🌏' '🌍' '🌎' '🌏'; do \
    # @for i in '⛄' '☃️ ' '⛄' '☃️ '  '⛄' '☃️ '  '⛄' '☃️ ' ; do \
    #   @for i in '🌑' '🌒' '🌓' '🌔' '🌕' '🌖'  '🌗' '🌘'; do \
    # @for i in '🍛' '🥟' '🍕' '🍜' '🍙' '🦀' '🌯' '🍲'; do \