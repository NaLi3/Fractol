/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:42:44 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/09 19:29:51 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int		ft_argument_handling(int argc, char **argv)
{
	if (argc != 7)
	{
		ft_printf("Usage: [Name], [Width], [Height], [Real], [Imaginary] ");
		ft_printf("[Precision].\n");
		return (1);
	}
	if (!ft_choose_fractal(argv[1]))
{
		ft_printf("Incorrect name: Available fractals are\n");
		ft_printf("Mandelbrot, Julia\n");
		return (1);
	}
	return (0);
}
