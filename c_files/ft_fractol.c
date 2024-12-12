/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:03:33 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 02:20:12 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*mlx;

	ft_argument_handling(argc, argv);
	

}

int	ft_zooming(int button, t_fractol *mlx)
{
	double	zoom_factor;

	zoom_factor = 0.9;
	if (button == 4)
	{
		printf("addr of min_x %f\n", mlx->f.min_x);
		mlx->f.min_x *= zoom_factor;
		mlx->f.max_x *= zoom_factor;
		mlx->f.min_y *= zoom_factor;
		mlx->f.max_y *= zoom_factor;
	}
	else if (button == 5)
	{
		mlx->f.min_x /= zoom_factor;
		mlx->f.max_x /= zoom_factor;
		mlx->f.min_y /= zoom_factor;
		mlx->f.max_y /= zoom_factor;
	}
	if (!strncmp(mlx->name, "mandelbrot", 10))
	{
		mlx_clear_window(mlx->init, mlx->win);
		ft_draw_mandelbrot(mlx, &mlx->f);
	}
	else if (!strncmp(mlx->name, "julia", 6))
		ft_draw_julia(mlx, &mlx->f);
	return (0);
}
