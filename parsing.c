/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:05:35 by hrochd            #+#    #+#             */
/*   Updated: 2024/06/22 19:41:10 by hrochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parsing(int argc, char **argv, t_fractal *fractal)
{
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12))
		|| (argc == 2 && !ft_strncmp(argv[1], "phoenix", 7))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal->name = argv[1];
		if (argc == 4)
		{
			fractal->julia_x = (ft_atod(argv[2]));
			fractal->julia_y = (ft_atod(argv[3]));
		}
		return (1);
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		return (0);
	}
}
