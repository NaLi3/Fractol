/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:19:27 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/13 16:45:34 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	n;
	double	div;

	n = 0.0;
	div = 0.1;
	sign = 1;
	i = ft_skip_whitespace(str, &sign);
	while (str[i] && ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ft_isdigit(str[i]))
		{
			n = n + ((str[i] - '0') * div);
			div /= 10;
			i++;
		}
	}
	return (n * sign);
}

int	ft_color_mngmnt(t_fractol *f, u_int64_t clr_int, u_int64_t clr_ext)
{
	if (f->i == f->max_it)
		f->color = clr_int;
	else
	{
		f->color = clr_ext * f->i;
		if (f->color == 0xFFFFFF)
			f->color = f->color >> 16;
	}
	return (f->color);
}

int	ft_skip_whitespace(char *str, int *sign)
{
	int		i;

	if (!str || !sign)
		return (-1);
	i = 0;
	while (ft_iswhitespace(str[i]) && str[i])
		i++;
	*sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		*sign = -1;
	}
	return (i);
}

char	*ft_str_to_lower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
