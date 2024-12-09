/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:03:33 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/09 19:44:20 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_data	*mlx;
	t_fractol *f;
	int		i;

	if (ft_argument_handling(argc, argv))
		return (1);
	i = 0;
	mlx = prout(argv);
	if (!mlx)
		return (1);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, mlx->width, mlx->height, mlx->name);
	f = ft_initialize_f(ft_atof(argv[4], 0 , 0), ft_atof(argv[5], 0 , 0), ft_atoi(argv[6]));
	if (!f)
		return (1);
	ft_printf("%s\n", mlx->name);
	if (ft_choose_fractal(mlx->name) == 1)
	{
		ft_draw_mandelbrot(mlx, f);
		mlx_hook(mlx->win, KeyPress, KeyPressMask, ft_close, &mlx);
		mlx_loop(mlx -> init);
	}
	else if(ft_choose_fractal(mlx->name) == 2)
	{
		ft_draw_julia(mlx, f);
		mlx_hook(mlx->win, KeyPress, KeyPressMask, ft_close, &mlx);
		mlx_loop(mlx -> init);
	}
	free(mlx);
	free(f);
	return (0);
}
