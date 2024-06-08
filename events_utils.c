/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:55:25 by hrochd            #+#    #+#             */
/*   Updated: 2024/06/08 20:42:51 by hrochd           ###   ########.fr       */
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
int mousedown_handler(int button, int x, int y, t_fractal *fractal)
{
	printf("button = %d, x = %d, y = %d\n", button, x, y);
    if(button == 4)
    {
        // fractal->start_x *= 0.9 * ((double)WIDTH / (double)x);
		// fractal->start_y *= 0.9 * ((double)HEIGHT / (double)y);
        fractal->range /= 1.05;
    }
    else if(button == 5)
    {
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