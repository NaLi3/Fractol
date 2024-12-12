/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:14:14 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 20:32:32 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	ft_calculate_mandelbrot(t_fractol *f)
{
	double		real;
	double		imag;
	double		temp;

	imag = 0;
	real = 0;
	f -> i = 0;
	while ((real * real) + (imag * imag) <= 4 && f -> i < f -> max_it)
	{
		temp = (real * real - imag * imag) + f->real;
		imag = (2 * real * imag) + f -> imag;
		real = temp;
		(f -> i)++;
	}
	return (f -> i);
}

void	ft_draw_mandelbrot(t_fractol *f)
{
	double	x_step;
	double	y_step;

	f -> x = -1;
	x_step = ((f->max_x - f->min_x) / (double)f->width);
	y_step = ((f->max_y - f->min_y) / (double)f->height);
	while (++(f -> x) < f->width)
	{
		f -> y = 0;
		while (f -> y < f->height)
		{
			f -> real = f -> min_x + f -> x * x_step + f->move_x;
			f -> imag = f -> min_y + f -> y * y_step + f->move_y;
			f -> i = ft_calculate_mandelbrot(f);
			f -> color = ft_color_mngmnt(f, 0x000000, 0xF4A4C4);
			mlx_pixel_put(f->init, f->win, f -> x, f->y++, f->color);
		}
	}
}
