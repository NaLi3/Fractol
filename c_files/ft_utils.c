/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:19:27 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/07 19:14:12 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"
#include <math.h>

double	ft_atof(char *str, int i, int j)
{
	int		flag;
	double	val;

	val = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] != '.')
		{
			val += (str[i] - '0') * 10;
			if (flag)
				j--;
		}
		if (str[i++] == '.')
		{
			if (flag)
				return (0);
			flag = 1;
		}
	}
	val = val * pow(10, j);
	return (val);
}

t_fractol	*ft_initialize_f(double a, double b, int x, int y)
{
	t_fractol	*f;

	f = (t_fractol *)malloc(1 * sizeof(t_fractol));
	if (!f)
		return (NULL);
	(*f).real = a;
	(*f).imag = b;
	(*f).x = x;
	(*f).y = y;
	(*f).color = 0;
	return (f);
}

int	ft_decide_color(int i)
{
	int	color;

	color = 0;
	if (i % 2)
		return (0);
	return (0);
}
