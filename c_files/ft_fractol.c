/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:03:33 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 20:26:19 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*f;

	ft_error_checking(argc, argv);
	f = (t_fractol *)malloc(1 * sizeof(t_fractol));
	if (!f)
		return (1);
	ft_initialize_full(argv, f);
	if (argc == 5)
		ft_draw_mandelbrot(f);
	else if (argc == 7)
		ft_draw_julia(f);
	mlx_hook(f->win, KeyPress, KeyPressMask, ft_key_handler, f);
	mlx_loop(f->init);
	return (0);
}

int	ft_zooming(int button, t_fractol *f)
{
	double	zoom_factor;

	zoom_factor = 0.9;
	if (button == 4)
	{
		printf("addr of min_x %f\n", f->min_x);
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
	if (!strncmp(f->name, "mandelbrot", 10))
	{
		mlx_clear_window(f->init, f->win);
		ft_draw_mandelbrot(f);
	}
	else if (!strncmp(f->name, "julia", 6))
	{
		mlx_clear_window(f->init, f->win);
		ft_draw_julia(f);
	}
	return (0);
}
