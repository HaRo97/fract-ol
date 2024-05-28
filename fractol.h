#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"

#define ERROR_MSG "ERROR : Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <real_part> <imaginary part>\"\n"

#define WIDTH 1080
#define HEIGHT 1080

#define BLACK   0x000000
#define WHITE   0xFFFFFF
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF
#define YELLOW  0xFFFF00
#define CYAN    0x00FFFF
#define MAGENTA 0xFF00FF
#define GRAY    0x808080
#define ORANGE  0xFFA500
#define PURPLE  0x800080

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct  s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_lenght;
    int     endian;
}               t_img;

typedef struct  s_fractal
{
    char    *name;
    void    *mlx_connection;
    void    *mlx_window;
    t_img   img;
    int     iterations;
    double  escape_value;
    double  shift_x;
    double  shift_y;
    double  zoom;
    double  range;
    double  julia_x;
    double  julia_y;
}               t_fractal;

typedef struct  s_complex_num
{
    double real;
    double imaginary;
}               t_complex_num;




int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
double	ft_atod(const char *str);

#endif