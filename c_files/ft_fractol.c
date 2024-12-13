/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:03:33 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/13 16:47:06 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*f;

	ft_error_checking(argc, argv);
	if (!ft_choose_fractal(argv[1]))
	{
		ft_putendl_fd("Incorrect name or argument count, fractal names:", 2);
		ft_putendl_fd("Mandelbrot and Ship (4 args); Julia (6 args)", 2);
		exit(1);
	}
	f = (t_fractol *)malloc(1 * sizeof(t_fractol));
	if (!f)
		return (1);
	ft_initialize_full(argv, f);
	if (argc == 5 && !ft_strncmp(f->name, "mandelbrot", 10))
		ft_draw_mandelbrot(f);
	else if (argc == 5 && !ft_strncmp(f->name, "ship", 5))
		ft_draw_burning(f);
	else if (argc == 7 && !ft_strncmp(f->name, "julia", 6))
		ft_draw_julia(f);
	mlx_hook(f->win, KeyPress, KeyPressMask, ft_key_handler, f);
	mlx_hook(f->win, ButtonPress, ButtonPressMask, ft_mouse_handler, f);
	mlx_hook(f->win, DestroyNotify, StructureNotifyMask, ft_cross, f);
	mlx_loop(f->init);
	return (0);
}
