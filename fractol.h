/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:05:32 by hrochd            #+#    #+#             */
/*   Updated: 2024/07/20 02:08:13 by hrochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"

# define WIDTH 1080.0
# define HEIGHT 1080.0

# define BLACK 0x000000
# define WHITE 0xFFFFFF

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_img;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_palette
{
	int	complementary;
	int	start;
	int	end;
}	t_palette;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	int			iterations;
	double		escape_value;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		range;
	double		start_x;
	double		start_y;
	double		end_x;
	double		end_y;
	double		julia_x;
	double		julia_y;
	t_palette	palette;
	int			palette_index;
}	t_fractal;

typedef struct s_complex_num
{
	double	real;
	double	imaginary;
}	t_complex_num;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
double			ft_atod(const char *str);
t_complex_num	complex_num_sum(t_complex_num z1, t_complex_num z2);
t_complex_num	complex_num_square(t_complex_num z);
t_complex_num	complex_mp_num(t_complex_num z, double num);
t_complex_num	complex_minus_complex(t_complex_num z, t_complex_num z2);
t_complex_num	complex_plus_num(t_complex_num z, double num);
int				destroy_handler(t_fractal *fractal);
int				mousedown_handler(int button, int x, int y, t_fractal *fractal);
int				keydown_handler(int keycode, t_fractal *fractal);
void			fractal_render(t_fractal *fractal);
int				interpolate(int start, int end, int steps, int return_index);
void			set_palette(int complementary, int start, int end,
					t_fractal *fractal);
void			change_palette(t_fractal *fractal);
int				parsing(int argc, char **argv, t_fractal *fractal);
double			scale(double num, double new_min,
					double new_max, double old_max);
int				abs(int num);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif