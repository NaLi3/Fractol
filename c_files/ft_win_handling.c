/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:44:35 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/09 16:49:00 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int	ft_close(int keycode, t_data *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(mlx->init, mlx->img);
		mlx_destroy_window(mlx->init, mlx->win);
		return (0);
	}
	return (1);
}

int	ft_resized()
{
	printf("Salut");
	return (0);
}
