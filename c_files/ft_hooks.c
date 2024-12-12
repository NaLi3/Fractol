/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:45:20 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 20:30:13 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int		ft_key_handler(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
		ft_cleanup_and_free(f);
	else if (keycode == XK_Left)
		f->move_x += 0.1;
	else if (keycode == XK_Right)
		f->move_x -= 0.1;
	else if (keycode == XK_Up)
		f->move_y += 0.1;
	else if (keycode == XK_Down)
		f->move_y -= 0.1;
	if (!ft_strncmp(f->name, "mandelbrot", 10))
		ft_draw_mandelbrot(f);
	else
		ft_draw_julia(f);
	return (0);
}
