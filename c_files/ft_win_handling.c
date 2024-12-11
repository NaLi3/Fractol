/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:44:35 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/10 22:04:54 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	ft_close(int keycode, t_data *mlx)
{
	if (keycode == 65307)
	{
		if (mlx ->img)
			mlx_destroy_image(mlx->init, mlx->img);
		if (mlx -> win)
		{
			mlx_clear_window(mlx->init, mlx->win);
			mlx_destroy_window(mlx->init, mlx->win);
		}
		if (mlx -> data_addr)
			free(mlx->data_addr);
		free(mlx);
		exit(0);
	}
	return (1);
}
