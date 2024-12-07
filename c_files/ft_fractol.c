/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:03:33 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/07 19:43:29 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

// 1) Handle the pedantic stuff of taking in arguments.
// 2) Handle opening the window with said arguments.
// 3) Find which numbers belong in the Mandelbrot set.
// 4) Display them on screen.

void	ft_opt_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data -> size_line + x * (data -> bpp / 8);
	dst = data -> addr + offset;
	*(unsigned int *)dst = color;
}

int	main(void/*int argc, char **argv*/)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");
	ft_draw_mandelbrot(mlx, mlx_win, 0, 0);
	mlx_loop(mlx);
}
