/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:20:39 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 02:27:00 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int		ft_calculate_julia(t_fractol *f)
{
	double		real;
	double		imag;
	double		temp;

	real = f->real;
	imag = f->imag;
	f -> i = 0;
	while (real * real + imag * imag <= 4 && (f -> i < f -> max_i))
	{
		temp = (real * real - imag * imag) + f->c_real;
		imag = (2 * real * imag) + f->c_imag;
		real = temp;
		(f -> i)++;
	}
	return (f -> i);
}

void	ft_draw_julia(t_fractol *f)
{
	double	x_step;
	double	y_step;

	f -> x = 0;
	x_step = (f->max_r - f->min_r) / (double)f->width;
	y_step = (f->max_i - f->min_i) / (double)f->height;
	while ((f -> x) < mlx -> width)
	{
		f -> y = 0;
		while (f -> y < mlx -> height)
		{
			f -> real = f -> min_x + f -> x * x_step;
			f -> imag = f -> min_y + f -> y * y_step *1.25;
			f -> i = ft_calculate_julia(f);
			f -> color = ft_color_mngmnt(f, 0xAA0000, 0x0000AA);
			mlx_pixel_put(mlx->init, mlx->win, f -> x, f->y++, f->color);
		}
		f -> x++;
	}
}
