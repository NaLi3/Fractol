/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:27:45 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 19:48:27 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

void ft_initialize_full(char **argv, t_fractol *f)
{
	f->init = mlx_init();
	if (!f->init)
		ft_cleanup_and_free(f);
	f->width = ft_atoi(argv[2]);
	f->height = ft_atoi(argv[3]);
	f->name = argv[1];
	f->win = mlx_new_window(f->init, f->width, f->height, f->name);
	if (!f->win)
		ft_cleanup_and_free(f);
	f->img_ptr = mlx_new_image(f->init, f->width, f->height);
	if (!f->img_ptr)
		ft_cleanup_and_free(f);
	f->buf = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->size_line, &f->endian);
	if (!ft_strncmp(ft_str_to_lower(f->name), "mandelbrot", 10))
		ft_init_f(f, 0, 0, ft_atoi(argv[4]));
	else
		ft_init_f(f, ft_atof(argv[4]), ft_atof(argv[5]), ft_atoi(argv[6]));
	// printf("The val of atof(argv[4]) is %f\n %f\n", ft_atof(argv[4]), ft_atof(argv[5]));
}

void	ft_init_f(t_fractol *f, double a, double b, int max_i)
{
	f->real = 0;
	f->imag = 0;
	f->j_real = a;
	f->j_imag = b;
	f->max_it = max_i;
	f->x = 0;
	f->y = 0;
	f->i = 0;
	f->color = 0;
	f->max_x = 2;
	f->max_y = 1.2;
	f->min_x = -2;
	f->min_y = -1.2;
}
