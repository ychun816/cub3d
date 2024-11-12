# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 14:25:13 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/11/12 15:33:07 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###	NAME ###

NAME	= cub3d

### SOURCES	###

FILES	=	srcs/main.c \
			srcs/parsing.c \
			srcs/get_map.c \
			srcs/floodfill.c \
			srcs/tools_1.c \
			srcs/tools_2.c \
			srcs/cleanup.c \


INCLUDES	= 	include/cub3d.h

### MACROS ###

CC	= cc


CFLAGS	= -g -Wall -Werror -Wextra

OBJ	= $(FILES:.c=.o)

### RULES ###

all	: $(NAME)

$(NAME)	: $(OBJ) $(INCLUDES)
		$(CC) $(OBJ) -o  $(NAME) 

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY:	clean fclean re                