/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:57:57 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 20:41:01 by ilevy            ###   ########.fr       */
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
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	move_x;
	double	move_y;
	double	zoom_x;
	double	zoom_y;

	char	*buf;
	int		x;
	int		y;
	int		color;
	int		i;
	int		max_it;

	void	*init;

	void	*win;
	char	*name;
	int		width;
	int		height;

	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;

}			t_fractol;

// ft_utils.c
double		ft_atof(char *str);
char		*ft_str_to_lower(char *str);
int			ft_skip_whitespace(char *str, int *sign);
int			ft_color_mngmnt(t_fractol *f, u_int64_t clr_int, u_int64_t clr_ext);


// ft_init.c
void		ft_initialize_full(char **argv, t_fractol *f);
void		ft_init_f(t_fractol *f, double a, double b, int max_i);

// ft_mandelbrot.c
int			ft_calculate_mandelbrot(t_fractol *fractol);
void		ft_draw_mandelbrot(t_fractol *f);
int			ft_color_mngmnt(t_fractol *f, u_int64_t a, u_int64_t b);

// ft_julia.c
int			ft_calculate_julia(t_fractol *fractol);
void		ft_draw_julia(t_fractol *f);

// ft_error_handling.c
void		ft_error_checking(int argc, char **argv);
int			ft_verify_arguments(int argc, char **argv);
void		ft_cleanup_and_free(t_fractol *f);
int			ft_choose_fractal(char *str, int argc);

// ft_hooks.c
int			ft_key_handler(int keycode, t_fractol *f);
int			ft_mouse_handler(int button, int x, int y, t_fractol *f);

#endif
