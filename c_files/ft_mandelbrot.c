/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:14:14 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/07 19:22:50 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	ft_calculate_mandelbrot(double a, double b, int max_i)
{
	int			i;
	double		real;
	double		imag;
	double		temp;

	i = 0;
	imag = 0;
	real = 0;
	while ((real * real) + (imag * imag) <= 4 && i < max_i)
	{
		temp = (real * real - imag * imag) + a;
		imag = (2 * real * imag) + b;
		real = temp;
		i++;
	}
	return (i);
}

void	ft_draw_mandelbrot(void *mlx, void *win, int x, int y)
{
	int			max_i;
	t_fractol	*f;
	double		x_step;
	double		y_step;

	max_i = 100;
	x_step = (X_MAX - X_MIN) / (double)WIDTH;
	y_step = (Y_MAX - Y_MIN) / (double)HEIGHT;
	while (x++ < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			f = ft_initialize_f((X_MIN + x * x_step), Y_MIN + y * y_step, x, y);
			if (!f)
				return ;
			f->i = ft_calculate_mandelbrot(f->real, f->imag, max_i);
			f->color = ft_color_mngmnt(f, max_i, 0x000000, 0xF4A4C4);
			mlx_pixel_put(mlx, win, x, y++, f->color);
			free(f);
		}
	}
}

int	ft_color_mngmnt(t_fractol *f, int max_i, u_int64_t clr_f, u_int64_t clr_ext)
{
	if (clr_f > 0xFFFFFF)
		clr_f = 0xFFFFFF;
	if (clr_ext > 0xFFFFFF)
		clr_ext = 0xFFFFFF;
	if (f->i == max_i)
		f->color = clr_f;
	else
		f->color = f->i * clr_ext;
	return (f->color);
}
