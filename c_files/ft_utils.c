/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:19:27 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 02:18:36 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

double	ft_atof(char *str)
{
	int	sign;
	int	i;
	double	n;
	double	div;

	sign = 1;
	n = 0;
	div = 0.1;
	i = ft_skipwhitespace(str, &sign);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{

			n = (n * 10) + (str[i] - '0');
			i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		n = n + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	return (n * sign)
}


t_fractol	ft_initialize_f(double a, double b, int max_i)
{
	t_fractol	f;

	f.real = 0;
	f.imag = 0;
	f.c_real = a;
	f.c_imag = b;
	f.max_i = max_i;
	f.x = 0;
	f.y = 0;
	f.i = 0;
	f.color = 0;
	f.max_x = 2;
	f.max_y = 1.2;
	f.min_x = -2;
	f.min_y = -1.2;
	return (f);
}

t_data	*ft_initialize_data(char **argv)
{
	t_data	*mlx;

	mlx = (t_data*)malloc(1 * sizeof(t_data));
	if (!mlx)
		return (NULL);
	mlx->init = 0;
	mlx->win = 0;
	mlx->img = 0;
	mlx->width = ft_atoi(argv[2]);
	mlx->height = ft_atoi(argv[3]);
	mlx->name = argv[1];
	mlx->endian = 0;
	mlx->bpp = 0;
	mlx->size_line = 0;
	mlx->data_addr = NULL;
	printf("Height %d\n", mlx->height);
	return (mlx);
}

int	ft_color_mngmnt(t_fractol *f, u_int64_t clr_int, u_int64_t clr_ext)
{
	if (clr_int > 0xFFFFFF)
		clr_int = 0xFFFFFF;
	if (clr_ext > 0xFFFFFF)
		clr_ext = 0xFFFFFF;
	if (f->i == f -> max_i)
		f->color = clr_int;
	else
		f->color = f->i * clr_ext;
	return (f->color);
}

int	ft_skip_whitespace(char *str, int *sign)
{
	int		i;

	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		*sign = -1;
	}
	return (i);
}
