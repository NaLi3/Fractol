/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:03:33 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/11 00:32:45 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_data	*mlx;
	t_fractol *f;

	if (ft_argument_handling(argc, argv))
		return (1);
	mlx = ft_initialize_data(argv);
	if (!mlx)
		return (1);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, mlx->width, mlx->height, mlx->name);
	f = ft_initialize_f(ft_atof(argv[4], 0 , 0), ft_atof(argv[5], 0 , 0), ft_atoi(argv[6]));
	if (!f)
		return (1);
	if (ft_choose_fractal(mlx->name) == 1)
	{
		ft_draw_mandelbrot(mlx, f);
		mlx_hook(mlx->win, KeyPress, KeyPressMask, ft_close, mlx);
		ft_printf("%d\n", f->min_x);
		mlx_hook(mlx->win, ButtonPress, ButtonPressMask, ft_zooming, mlx);
		mlx_loop(mlx -> init);
	}
	else if(ft_choose_fractal(mlx->name) == 2)
	{
		ft_draw_julia(mlx, f);
		mlx_hook(mlx->win, KeyPress, KeyPressMask, ft_close, mlx);
		mlx_hook(mlx->win, ButtonPress, ButtonPressMask, ft_zooming, mlx);
		mlx_loop(mlx -> init);
	}
	free(f);
	return (0);
}

int	ft_zooming(int button, t_data *mlx, t_fractol *f)
{
	double	zoom_factor;

	zoom_factor = 0.9;
	if (button == 4)
	{
		f->min_x *= zoom_factor;
		f->max_x *= zoom_factor;
		f->min_y *= zoom_factor;
		f->max_y *= zoom_factor;
	}
	else if (button == 5)
	{
		f->min_x /= zoom_factor;
		f->max_x /= zoom_factor;
		f->min_y /= zoom_factor;
		f->max_y /= zoom_factor;
	}
	if (!strncmp(mlx->name, "mandelbrot", 10))
		ft_draw_mandelbrot(mlx, f);
	else if (!strncmp(mlx->name, "julia", 6))
		ft_draw_julia(mlx, f);
	return (0);
}
