# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 14:25:13 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/11/12 14:26:09 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###	NAME ###

NAME	= cub3d

### SOURCES	###

FILES	=	srcs/main.c

INCLUDES	= 	includes/cub3d.h

### MACROS ###

CC	= cc

LDFLAGS = -lreadline

CFLAGS	= -g -Wall -Werror -Wextra

OBJ	= $(FILES:.c=.o)

### RULES ###

all	: $(NAME)

$(NAME)	: $(OBJ) $(INCLUDES)
		$(CC) $(OBJ) $(LDFLAGS) -o  $(NAME) 

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY:	clean fclean re                