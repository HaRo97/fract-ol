CC = cc
NAME = fractol
SRC = fractol.c string_utils.c
OBJ = $(SRC:.c=.o)
# CFLAGS = -Wall -Wextra -Werror -Imlx
LFLAGS = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ) fractol.h
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

# %.o: %.c 
# 	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.c 
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


