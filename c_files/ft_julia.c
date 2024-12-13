/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:20:39 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/13 16:43:53 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	ft_calculate_julia(t_fractol *f)
{
	double		real;
	double		imag;
	double		temp;
	double		s_real;
	double		s_imag;

	real = f->real;
	imag = f->imag;
	f->i = 0;
	s_real = real * real;
	s_imag = imag * imag;
	while (s_real + s_imag <= 4 && (f->i < f->max_it))
	{
		temp = s_real - s_imag + f->j_real;
		imag = 2 * real * imag + f->j_imag;
		real = temp;
		s_real = real * real;
		s_imag = imag * imag;
		f->i++;
	}
	return (f->i);
}

void	ft_draw_julia(t_fractol *f)
{
	double	x_step;
	double	y_step;

	f->x = 0;
	x_step = ((f->max_x - f->min_x) / (double)f->width);
	y_step = ((f->max_y - f->min_y) / (double)f->height);
	while ((f->x) < f->width)
	{
		f->y = 0;
		while (f->y < f->height)
		{
			f->real = f->min_x + f ->x * x_step + f->move_x;
			f->imag = f->min_y + f ->y * y_step + f->move_y;
			f->i = ft_calculate_julia(f);
			f->color = ft_color_mngmnt(f, 0xFF0000, 0x0000FF);
			f->buf[f->y * f->width + f->x] = f->color;
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->init, f->win, f->img_ptr, 0, 0);
}
