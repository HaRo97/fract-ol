CC = cc 
NAME = fractol
SRC = fractol.c string_utils.c complex_maths_utils.c maths_utils.c pixel_handlers.c events_utils.c color_utils.c parsing.c
OBJ = $(SRC:.c=.o)
# CFLAGS = -Wall -Wextra -Werror -Imlx
LFLAGS = -lmlx -framework OpenGL -framework AppKit -O3

$(NAME): $(OBJ) fractol.h 
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)
# $(CC) -g -fsanitize=address $(OBJ) $(LFLAGS) -o $(NAME)

# %.o: %.c 
# 	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.c 
	$(CC) $(LFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


