/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:57:57 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/07 19:21:22 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# define WIDTH 1500
# define HEIGHT 900
# define X_MAX 2
# define X_MIN -2
# define Y_MIN -1.2
# define Y_MAX 1.2

# include "libft.h"
# include "../../mlx_linux/mlx.h"
# include "../../mlx_linux/mlx_int.h"
# include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_data;

typedef struct s_fractol
{
	double	real;
	double	imag;
	int		x;
	int		i;
	int		y;
	int		color;
}	t_fractol;

// ft_utils.c
double		ft_atof(char *str, int i, int j);
void		*ft_create_img(void *mlx, int width, int height, int *img_data);

t_fractol	*ft_initialize_f(double a, double b, int x, int y);

int			ft_calculate_mandelbrot(double a, double b, int max_i);
void		ft_draw_mandelbrot(void *mlx, void *win, int x, int y);
int			ft_color_mngmnt(t_fractol *f, int max, u_int64_t a, u_int64_t b);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
