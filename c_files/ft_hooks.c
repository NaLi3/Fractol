/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:45:20 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 18:47:21 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int		ft_close(int keycode, t_fractol *f)
{
	if (keycode == 0xff1b)
		ft_cleanup_and_free(f);
	return (0);
}
