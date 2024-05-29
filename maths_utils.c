/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrochd <hrochd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:19:00 by hrochd            #+#    #+#             */
/*   Updated: 2024/05/28 17:21:38 by hrochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_complex_num complex_num_sum(t_complex_num z1, t_complex_num z2)
{
    t_complex_num result;

    result.real = z1.real + z2.real;
    result.imaginary = z1.imaginary + z2.imaginary;
    return result;

}

t_complex_num complex_num_square(t_complex_num z)
{
    t_complex_num   result;

    result.real = (z.real * z.real) - (z.imaginary * z.imaginary);
    result.imaginary = 2 * z.real *z.imaginary;
    return result;
}

t_complex_num complex_mp_num(t_complex_num z, double num)
{
    z.real = z.real * num;
    z.imaginary = z.imaginary * num;
    return z;
}
t_complex_num complex_minus_complex(t_complex_num z, t_complex_num z2)
{
    z.real = z.real - z2.real;
    z.imaginary = z.imaginary - z2.imaginary;
    return z;
}

t_complex_num complex_plus_num(t_complex_num z, double num)
{
    z.real = z.real + num;
    return z;
}