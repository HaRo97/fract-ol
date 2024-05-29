/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:29:52 by hrochd            #+#    #+#             */
/*   Updated: 2024/05/28 22:32:02 by hrochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color calculate_gradient(t_color start, t_color end, int i, int steps) {
    t_color result;
    float t = (float)i / (steps - 1);

    result.red = start.red + t * (end.red - start.red);
    result.green = start.green + t * (end.green - start.green);
    result.blue = start.blue + t * (end.blue - start.blue);
    return result;
}

int interpolate(int start, int end, int steps, int return_index) {
    int result[steps];
    t_color start_color;
    t_color end_color;
    t_color result_color;
    int i;

    start_color.red = (start >> 16) & 0xFF;
    start_color.green = (start >> 8) & 0xFF;
    start_color.blue = start & 0xFF;
    end_color.red = (end >> 16) & 0xFF;
    end_color.green = (end >> 8) & 0xFF;
    end_color.blue = end & 0xFF;
    i = 0;
    while (i < steps)
    {
        result_color = calculate_gradient(start_color, end_color, i, steps);
        result[i] = (result_color.red << 16) | (result_color.green << 8) | result_color.blue;
        i++;
    }
    return result[return_index];
}

void set_palette(int complementary, int start, int end, t_fractal *fractal)
{
    fractal->palette.complementary = complementary;
    fractal->palette.start = start;
    fractal->palette.end = end;
}

void   change_palette(t_fractal *fractal) 
{
    fractal->palette_index++;
    if (fractal->palette_index % 8 == 0)
        set_palette(0xffd900, 0x191971, 0xffd900, fractal);
    else if (fractal->palette_index % 8 == 1)
        set_palette(BLACK, 0x2f3293, 0x19ffff, fractal);
    else if (fractal->palette_index % 8 == 2)
        set_palette(0x00FFFF, 0x1d2672, 0xc33763, fractal);
    else if (fractal->palette_index % 8 == 3)
        set_palette(BLACK, 0x023140, 0x38aecc, fractal);
    else if (fractal->palette_index % 8 == 4)
        set_palette(0x1E212B, 0x4e8c31, 0xffc800, fractal);
    else if (fractal->palette_index % 8 == 5)
        set_palette(0x262626, 0x255b98, 0xb3001b, fractal);
    else if (fractal->palette_index % 8 == 6)
        set_palette(0x141B41, 0x306cab, 0xffffff, fractal);
    else if (fractal->palette_index % 8 == 7)
        set_palette(BLACK, 0x00ff2a, 0x001801, fractal);
}

