/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:57:57 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 02:27:13 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "libft.h"
# include "../../mlx_linux/mlx.h"
# include "../../mlx_linux/mlx_int.h"
# include <math.h>

typedef struct s_fractol
{
	double	real;
	double	imag;
	double	j_real;
	double	j_imag;
	double	max_r;
	double	min_r;
	double	max_i;
	double	min_i;
	int		x;
	int		y;
	int		color;
	int		i;
	int		max_i;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	char	*name;
}			t_fractol;

// ft_utils.c
double		ft_atof(char *str, double intp, double floatp);
void		*ft_create_img(void *mlx, int width, int height, int *img_data);

// ft_utils.c

double		ft_atof(char *str, double intp, double floatp);
t_fractol	ft_initialize_f(double a, double b, int max_i);
int			ft_color_mngmnt(t_fractol *f, u_int64_t clr_int, u_int64_t clr_ext);

// ft_mandelbrot.c
int			ft_calculate_mandelbrot(t_fractol *fractol);
void		ft_draw_mandelbrot(t_fractol *f);
int			ft_color_mngmnt(t_fractol *f, u_int64_t a, u_int64_t b);

// ft_julia.c
int			ft_calculate_julia(t_fractol *fractol);
void		ft_draw_julia(t_fractol *f);


// ft_error_handling.c
int			ft_argument_handling(int argc, char **argv);
int			ft_choose_fractal(char *str);

#endif
