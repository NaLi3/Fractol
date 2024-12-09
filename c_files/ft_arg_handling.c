/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:09:46 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/09 17:54:51 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

int		ft_choose_fractal(char *str)
{
	int			i;
	const char	*s;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	s = (const char *)str;
	if (!strncmp(s, "mandelbrot", 9))
		return (1);
	if (!strncmp(s, "julia", 5))
		return (2);
	return (0);
}
