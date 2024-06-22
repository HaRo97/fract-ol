/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:20:56 by hrochd            #+#    #+#             */
/*   Updated: 2024/06/22 20:50:10 by hrochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

double	decimal_part(const char *str, int *i)
{
	double	result_decimal;
	double	div;

	result_decimal = 0;
	div = 10;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result_decimal = result_decimal + ((1 / div) * (str[*i] - 48));
		div *= 10;
		(*i)++;
	}
	return (result_decimal);
}

double	ft_atod(const char *str)
{
	int		i;
	double	sign;
	double	result_int;
	double	result_fract;
	double	div;

	(1 && (i = 0, result_int = 0, result_fract = 0, div = 10, sign = 1));
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result_int = 10 * result_int + (str[i] - 48);
		i++;
	}
	if (str[i++] == '.')
		result_fract = decimal_part(str, &i);
	return (sign * (result_int + result_fract));
}
