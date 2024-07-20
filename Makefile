# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 02:37:53 by hrochd            #+#    #+#              #
#    Updated: 2024/07/20 02:16:03 by hrochd           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = fractol

SRC = fractol.c string_utils.c complex_maths_utils.c maths_utils.c\
	pixel_handlers.c events_utils.c color_utils.c parsing.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Imlx

LFLAGS = -lmlx -framework OpenGL -framework AppKit -O3

all : $(NAME)

$(NAME): $(OBJ) fractol.h 
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME) $(CFLAGS)

%.o: %.c 
	$(CC)  $(CFLAGS)  -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
