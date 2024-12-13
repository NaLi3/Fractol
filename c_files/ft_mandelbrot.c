/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:14:14 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/13 11:40:05 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	ft_calculate_mandelbrot(t_fractol *f)
{
	double		real;
	double		imag;
	double		temp;
	double		s_real;
	double		s_imag;

	imag = 0;
	real = 0;
	f->i = 0;
	s_real = real * real;
	s_imag = imag * imag;
	while (s_real + s_imag <= 4 && f->i < f->max_it)
	{
		temp = (s_real - s_imag) + f->real;
		imag = (2 * real * imag) + f->imag;
		real = temp;
		s_real = real * real;
		s_imag = imag * imag;
		(f->i)++;
	}
	return (f->i);
}

void	ft_draw_mandelbrot(t_fractol *f)
{
	double	x_step;
	double	y_step;

	f->x = 0;
	x_step = ((f->max_x - f->min_x) / (double)f->width) * f->zoom_x;
	y_step = ((f->max_y - f->min_y) / (double)f->height) * f->zoom_y;
	while ((f->x) < f->width)
	{
		f->y = 0;
		while (f->y < f->height)
		{
			f->real = (f->min_x + f->x * x_step + f->move_x);
			f->imag = (f->min_y + f->y * y_step + f->move_y);
			f->i = ft_calculate_mandelbrot(f);
			f->color = ft_color_mngmnt(f, 0x000000, 0X50C878);
			f->buf[f->y * f->width + f->x] = f->color;
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->init, f->win, f->img_ptr, 0, 0);
}
