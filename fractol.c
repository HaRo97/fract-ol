/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:31:07 by hrochd            #+#    #+#             */
/*   Updated: 2024/06/28 07:02:12 by hrochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_lenght) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

static void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, ON_KEYDOWN, 0, keydown_handler, fractal);
	mlx_hook(fractal->mlx_window, ON_MOUSEDOWN, 0, mousedown_handler, fractal);
	mlx_hook(fractal->mlx_window, ON_DESTROY, 0, destroy_handler, fractal);
}

static void	malloc_failed(void)
{
	perror("malloc failed");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	if (!fractal)
		return ;
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_failed();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		free(fractal->mlx_connection);
		malloc_failed();
	}
	fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_failed();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&(fractal->img.bits_per_pixel),
			&(fractal->img.line_lenght),
			&(fractal->img.endian));
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	int			parsing_success;

	fractal.escape_value = 4;
	fractal.iterations = 18;
	fractal.shift_x = 0.0;
	fractal.shift_y = 0.0;
	fractal.zoom = 1.0;
	fractal.range = 4.0;
	fractal.start_x = -2;
	fractal.start_y = -2;
	fractal.end_x = 2;
	fractal.end_y = 2;
	fractal.palette_index = 0;
	set_palette(0xffd900, 0x191971, 0xffd900, &fractal);
	parsing_success = parsing(argc, argv, &fractal);
	if (parsing_success == 0)
		return (EXIT_FAILURE);
	else
	{
		fractal_init(&fractal);
		fractal_render(&fractal);
		event_init(&fractal);
		mlx_loop(&fractal.mlx_connection);
	}
}
