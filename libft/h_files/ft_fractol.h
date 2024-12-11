/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:57:57 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/10 23:08:26 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "libft.h"
# include "../../mlx_linux/mlx.h"
# include "../../mlx_linux/mlx_int.h"
# include <math.h>

typedef struct s_data
{
	char	*name;
	char	*data_addr;
	void	*init;
	void	*win;
	void	*img;
	int		height;
	int		width;
	int		bpp;
	int		size_line;
	int		endian;
}			t_data;

typedef struct s_fractol
{
	double	real;
	double	imag;
	double	c_real;
	double	c_imag;
	int		x;
	int		y;
	int		color;
	int		i;
	int		max_i;
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
}			t_fractol;

// ft_utils.c
double		ft_atof(char *str, double intp, double floatp);
void		*ft_create_img(void *mlx, int width, int height, int *img_data);

// ft_utils.c

double		ft_atof(char *str, double intp, double floatp);
t_fractol	*ft_initialize_f(double a, double b, int max_i);
t_data		*ft_initialize_data(char **argv);
int			ft_color_mngmnt(t_fractol *f, u_int64_t clr_int, u_int64_t clr_ext);

// ft_mandelbrot.c
int			ft_calculate_mandelbrot(t_fractol *fractol);
void		ft_draw_mandelbrot(t_data *mlx, t_fractol *f);
int			ft_color_mngmnt(t_fractol *f, u_int64_t a, u_int64_t b);

// ft_julia.c
int			ft_calculate_julia(t_fractol *fractol);
void		ft_draw_julia(t_data *mlx, t_fractol *f);

// ft_win_handling.c
int			ft_close(int keycode, t_data *mlx);
int			ft_close_2(t_data *mlx);

// ft_error_handling.c
int			ft_argument_handling(int argc, char **argv);

// ft_arg_handling.c
int			ft_choose_fractal(char *str);
int			ft_resized(void);

int			ft_zooming(int keycode, t_data *mlx, t_fractol *f);

#endif
