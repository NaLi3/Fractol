/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:19:27 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/10 22:01:50 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

double	ft_atof(char *str, double intp, double floatp)
{
	int		sign;
	int		div;
	int		flag;

	div = 1;
	sign = 1;
	flag = 0;
	if (*str == '-')
	{
		++str;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (flag)
			{
				floatp = floatp * 10 +(*str - '0');
				div *= 10;
			}
			else
				intp = intp * 10 + (*str - '0');
		}
		else if (*str == '.')
		{
			if (flag)
				break ;
			else
				flag = 1;
		}
		else
			break;
		str++;
	}
	return sign * (intp + floatp/div);
}

t_fractol	*ft_initialize_f(double a, double b, int max_i)
{
	t_fractol	*f;

	f = (t_fractol *)malloc(1 * sizeof(t_fractol));
	if (!f)
		return (NULL);
	(*f).real = 0;
	(*f).imag = 0;
	(*f).c_real = a;
	(*f).c_imag = b;
	(*f).max_i = max_i;
	(*f).x = 0;
	(*f).y = 0;
	(*f).i = 0;
	(*f).color = 0;
	(*f).max_x = 2;
	(*f).max_y = 1.2;
	(*f).min_x = -2;
	(*f).min_y = -1.2;
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
