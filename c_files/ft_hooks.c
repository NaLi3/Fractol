/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:45:20 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/13 16:43:29 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	ft_key_handler(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
		ft_cleanup_and_free(f);
	else if (keycode == XK_Right)
		f->move_x -= 0.1 * f->min_x;
	else if (keycode == XK_Left)
		f->move_x += 0.1 * f->min_x;
	else if (keycode == XK_Down)
		f->move_y -= 0.1 * f->min_y;
	else if (keycode == XK_Up)
		f->move_y += 0.1 * f->min_y;
	else if (keycode == XK_m)
		f->max_it += 5;
	else if (keycode == XK_b)
		f->max_it -= 5;
	if (!ft_strncmp(f->name, "mandelbrot", 10))
		ft_draw_mandelbrot(f);
	else if (!ft_strncmp(f->name, "julia", 6))
		ft_draw_julia(f);
	else
		ft_draw_burning(f);
	return (0);
}

int	ft_mouse_handler(int button, int x, int y, t_fractol *f)
{
	double	mousere;
	double	mouseim;

	mousere = (double)x / (f->width / (f->max_x - f->min_x)) + f->min_x;
	mouseim = (double)y / (f->height / (f->max_y - f->min_y)) + f->min_y;
	if (button == Button4)
		interpolate(f, mousere, mouseim, 0.9);
	else if (button == Button5)
		interpolate(f, mousere, mouseim, 1.1);
	mlx_clear_window(f->init, f->win);
	if (!ft_strncmp(f->name, "mandelbrot", 10))
		ft_draw_mandelbrot(f);
	else if (!ft_strncmp(f->name, "julia", 6))
		ft_draw_julia(f);
	else
		ft_draw_burning(f);
	return (0);
}

int	ft_cross(t_fractol *f)
{
	ft_cleanup_and_free(f);
	return (0);
}

void	interpolate(t_fractol *f, double mousere, double mouseim, double i)
{
	f->min_x = mousere + ((f->min_x - mousere) * i);
	f->max_x = mousere + ((f->max_x - mousere) * i);
	f->min_y = mouseim + ((f->min_y - mouseim) * i);
	f->max_y = mouseim + ((f->max_y - mouseim) * i);
}
