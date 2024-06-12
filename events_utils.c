/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:55:25 by hrochd            #+#    #+#             */
/*   Updated: 2024/06/12 20:30:54 by hrochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int destroy_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    exit(EXIT_SUCCESS);
    return 0;
}

int abs(int num)
{
	if (num < 0)
		return -num;
	return num;
}

int mousedown_handler(int button, int x, int y, t_fractal *fractal)
{
	printf("button = %d, x = %d, y = %d\n", button, x, y);
	double xplane;
	double yplane;

	xplane = (double)scale(x, fractal->start_x, fractal->end_x, WIDTH);
	yplane = (double)scale(y, fractal->start_y, fractal->end_y, WIDTH);
    if(button == 4)
    {
		// fractal->zoom *= 0.95;
		fractal->start_x = xplane - (xplane - fractal->start_x) * 0.9;
		fractal->start_y = yplane - (yplane - fractal->start_y) * 0.9;
		fractal->end_x = xplane + (fractal->end_x - xplane) * 0.9;
		fractal->end_y = yplane + (fractal->end_y - yplane) * 0.9;
        fractal->range *= 0.9;
    }
    else if(button == 5)
    {
		fractal->start_x = xplane - (xplane - fractal->start_x) * 1.1;
		fractal->start_y = yplane - (yplane - fractal->start_y) * 1.1;
		fractal->end_x = xplane + (fractal->end_x - xplane) * 1.1;
		fractal->end_y = yplane + (fractal->end_y - yplane) * 1.1;
        fractal->range *= 1.1;
    }
    fractal_render(fractal);
    return 0;
}

int keydown_handler(int keycode, t_fractal *fractal)
{
    // printf("keycode = %d\n", keycode);
    if (keycode == 53)
    {
        destroy_handler(fractal);
    }
    if (keycode == 123)
        fractal->shift_x -= fractal->range / 8;
    if (keycode == 124)
        fractal->shift_x += fractal->range / 8;
    if (keycode == 125)
        fractal->shift_y += fractal->range / 8;
    if (keycode == 126)
        fractal->shift_y -= fractal->range / 8;
    if (keycode == 69)
        fractal->iterations += 5;
    if (keycode == 78)
        fractal->iterations -= 5;
    if (keycode == 49)
        change_palette(fractal);

    fractal_render(fractal);

    return 0;
}