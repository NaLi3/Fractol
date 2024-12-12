/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:45:20 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 23:01:37 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int		ft_key_handler(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
		ft_cleanup_and_free(f);
	else if (keycode == XK_Right)
		f->move_x += 0.1 * f->zoom_y;
	else if (keycode == XK_Left)
		f->move_x -= 0.1 * f->zoom_y;
	else if (keycode == XK_Down)
		f->move_y += 0.1 * f->zoom_y;
	else if (keycode == XK_Up)
		f->move_y -= 0.1 * f->zoom_y;
	if (!ft_strncmp(f->name, "mandelbrot", 10))
		ft_draw_mandelbrot(f);
	else if (!ft_strncmp(f->name, "julia", 6))
		ft_draw_julia(f);
	else
		ft_draw_burning(f);
	return (0);
}

int		ft_mouse_handler(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == Button4)
	{
		f->zoom_x *= 0.9;
		f->zoom_y *= 0.9;
	}
	else if (button == Button5)
	{
		f->zoom_x /= 0.9;
		f->zoom_y /= 0.9;
	}
	if (!ft_strncmp(f->name, "mandelbrot", 10))
		ft_draw_mandelbrot(f);
	else if (!ft_strncmp(f->name, "julia", 6))
		ft_draw_julia(f);
	else
		ft_draw_burning(f);
	return (0);
}

int		ft_cross(t_fractol *f)
{
	ft_cleanup_and_free(f);
	return (0);
}
