/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:46:45 by hrochd            #+#    #+#             */
/*   Updated: 2024/06/22 20:01:41 by hrochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel_burningship(int x, int y, t_fractal *f)
{
	t_complex_num	z;
	t_complex_num	c;
	int				i;
	int				color;

	z.real = (scale(x, f->start_x, f->end_x, WIDTH)) + f->shift_x;
	z.imaginary = (scale(y, f->start_y, f->end_y, HEIGHT)) + f->shift_y;
	c.real = z.real;
	c.imaginary = z.imaginary;
	i = -1;
	while (++i < f->iterations)
	{
		if (z.real < 0)
			z.real = -z.real;
		if (z.imaginary < 0)
			z.imaginary = -z.imaginary;
		z = complex_num_sum(complex_num_square(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > f->escape_value)
		{
			color = interpolate(f->palette.start, f->palette.end,
					40, (int)scale(i, 0, 39, f->iterations));
			return (my_mlx_pixel_put(&f->img, x, y, color));
		}
	}
	my_mlx_pixel_put(&f->img, x, y, f->palette.complementary);
}

void	handle_pixel_phoenix(int x, int y, t_fractal *f)
{
	t_complex_num	z;
	int				i;
	int				color;
	t_complex_num	t;
	t_complex_num	t2;

	(1 && (t.real = 0, t.imaginary = 0, t2.real = 0, t2.imaginary = 0, i = -1));
	z.real = (scale(x, f->start_x, f->end_x, WIDTH)) + f->shift_x;
	z.imaginary = (scale(y, f->start_y, f->end_y, HEIGHT)) + f->shift_y;
	while (++i < f->iterations)
	{
		t2 = z;
		z = complex_minus_complex(complex_num_square(z),
				complex_mp_num(t, 0.5));
		z.real = z.real + 0.56667;
		t = t2;
		t2 = z;
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > f->escape_value)
		{
			color = interpolate(f->palette.start, f->palette.end,
					40, (int)scale(i, 0, 39, f->iterations));
			return (my_mlx_pixel_put(&f->img, x, y, color));
		}
	}
	my_mlx_pixel_put(&f->img, x, y, f->palette.complementary);
}

void	handle_pixel_julia(int x, int y, t_fractal *fractal)
{
	t_complex_num	z;
	t_complex_num	c;
	int				i;
	int				color;

	z.real = (scale(x, fractal->start_x, fractal->end_x, WIDTH))
		+ fractal->shift_x;
	z.imaginary = (scale(y, fractal->start_y, fractal->end_y, HEIGHT))
		+ fractal->shift_y;
	c.real = fractal->julia_x;
	c.imaginary = fractal->julia_y;
	i = -1;
	while (++i < fractal->iterations)
	{
		z = complex_num_sum(complex_num_square(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary)
			> fractal->escape_value)
		{
			color = interpolate(fractal->palette.start, fractal->palette.end,
					40, (int)scale(i, 0, 39, fractal->iterations));
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&fractal->img, x, y, fractal->palette.complementary);
}

void	handle_pixel_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex_num	z;
	t_complex_num	c;
	int				i;
	int				color;

	z.real = (scale(x, fractal->start_x, fractal->end_x, WIDTH))
		+ fractal->shift_x;
	z.imaginary = (scale(y, fractal->start_y, fractal->end_y, HEIGHT))
		+ fractal->shift_y;
	c.real = z.real;
	c.imaginary = z.imaginary;
	i = -1;
	while (++i < fractal->iterations)
	{
		z = complex_num_sum(complex_num_square(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary)
			> fractal->escape_value)
		{
			color = interpolate(fractal->palette.start, fractal->palette.end,
					40, (int)scale(i, 0, 39, fractal->iterations));
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&fractal->img, x, y, fractal->palette.complementary);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
				handle_pixel_mandelbrot(x, y, fractal);
			else if (ft_strncmp(fractal->name, "julia", 5) == 0)
				handle_pixel_julia(x, y, fractal);
			else if (ft_strncmp(fractal->name, "burning_ship", 12) == 0)
				handle_pixel_burningship(x, y, fractal);
			else if (ft_strncmp(fractal->name, "phoenix", 7) == 0)
				handle_pixel_phoenix(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img, 0, 0);
}
