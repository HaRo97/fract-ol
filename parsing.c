/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:05:35 by hrochd            #+#    #+#             */
/*   Updated: 2024/07/20 01:57:35 by hrochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_str_numeric(char *str)
{
	int	i;
	int	points;

	i = 0;
	points = 0;
	if (str[i] == '.')
		return (0);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.'
			&& str[i] != '+' && str[i] != '-')
			return (0);
		if ((str[i] == '+' || str[i] == '-') && i > 0)
			return (0);
		if (str[i] == '.')
			points++;
		i++;
	}
	i--;
	if (str[i] == '.' || points > 1)
		return (0);
	return (1);
}

int	parsing(int argc, char **argv, t_fractal *fractal)
{
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12))
		|| (argc == 2 && !ft_strncmp(argv[1], "phoenix", 7))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)
			&& is_str_numeric(argv[2]) && is_str_numeric(argv[3])))
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
		ft_putstr_fd("ERROR : Please enter \n\t", STDERR_FILENO);
		ft_putstr_fd("./fractol (fractol name)\n", STDERR_FILENO);
		ft_putstr_fd("\tor\n\t./fractol julia ", STDERR_FILENO);
		ft_putstr_fd("<real_part> <imaginary part>", STDERR_FILENO);
		return (0);
	}
}
