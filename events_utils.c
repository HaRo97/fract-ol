/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:55:25 by hrochd            #+#    #+#             */
/*   Updated: 2024/06/10 01:22:22 by hrochd           ###   ########.fr       */
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
    if(button == 4)
    {
		// fractal->zoom *= 0.95;
		// fractal->zoom.start_x = fractal->zoom.start_x * ((WIDTH - x) / WIDTH);
		// fractal->zoom.end_x = fractal->zoom.end_x * (x / WIDTH);
		// fractal->zoom.start_y = fractal->zoom.start_y * (HEIGHT - y) / HEIGHT;
		// fractal->zoom.end_y = fractal->zoom.end_y * (y / HEIGHT);
		// // fractal->start_y = fractal->start_y * (y / HEIGHT);
		// fractal->end_y = fractal->end_y * ((HEIGHT - y) / HEIGHT);
        fractal->range /= 1.05;
    }
    else if(button == 5)
    {
		// fractal->zoom *= 1.05;
        // fractal->start_x *= 1.1 * ((double)WIDTH / (double)x);
		// fractal->start_y *= 1.1 * ((double)HEIGHT / (double)y);
        fractal->range *= 1.05;
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
        fractal->shift_y -= fractal->range / 8;
    if (keycode == 126)
        fractal->shift_y += fractal->range / 8;
    if (keycode == 69)
        fractal->iterations += 5;
    if (keycode == 78)
        fractal->iterations -= 5;
    if (keycode == 49)
        change_palette(fractal);

    fractal_render(fractal);

    return 0;
}