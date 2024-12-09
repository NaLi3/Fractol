/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:14:14 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/09 17:59:11 by ilevy            ###   ########.fr       */
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
	while ((real * real) + (imag * imag) <= 4 && f -> i < f -> max_i)
	{
		temp = (real * real - imag * imag) + f -> real;
		imag = (2 * real * imag) + f -> imag;
		real = temp;
		(f -> i)++;
	}
	return (f -> i);
}

// void	ft_draw_mandelbrot(t_data *mlx, void *win, int x, int y)
// {
// 	int			max_i;
// 	t_fractol	*f;
// 	double		x_step;
// 	double		y_step;

// 	max_i = 100;
// 	x_step = (X_MAX - X_MIN) / (double)WIDTH;
// 	y_step = (Y_MAX - Y_MIN) / (double)HEIGHT;
// 	while (x++ < WIDTH)
// 	{
// 		y = 0;
// 		while (y < HEIGHT)
// 		{
// 			f = ft_initialize_f((X_MIN + x * x_step), Y_MIN + y * y_step, x, y);
// 			if (!f)
// 				return ;
// 			f->i = ft_calculate_mandelbrot(f);
// 			f->color = ft_color_mngmnt(f, max_i, 0x000000, 0xF4A4C4);
// 			mlx_pixel_put(mlx->init, win, x, y++, f->color);
// 			free(f);
// 		}
// 	}
// }

void	ft_draw_mandelbrot(t_data *mlx, t_fractol *f)
{
	double	x_step;
	double	y_step;

	f -> x = -1;
	x_step = (f->max_x - f->min_x) / (double)mlx->width;
	y_step = (f->max_y - f->min_y) / (double)mlx->height;
	while (++(f -> x) < mlx -> width)
	{
		f -> y = 0;
		while (f -> y < mlx -> height)
		{
			f -> real = f -> min_x + f -> x * x_step;
			f -> imag = f -> min_y + f -> y * y_step;
			f -> i = ft_calculate_mandelbrot(f);
			f -> color = ft_color_mngmnt(f, 0x000000, 0xF4A4C4);
			mlx_pixel_put(mlx->init, mlx->win, f -> x, f->y++, f->color);
		}
	}
}
