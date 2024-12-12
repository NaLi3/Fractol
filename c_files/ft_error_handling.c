/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:42:44 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/12 18:51:53 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/h_files/ft_fractol.h"

void	ft_error_checking(int argc, char **argv);
int		ft_verify_arguments(int argc, char **argv);
int		ft_choose_fractal(char *str, int argc);
void	ft_cleanup_and_free(t_fractol *f);

void	ft_error_checking(int argc, char **argv)
{
	if (argc != 7 && argc != 5)
	{
		ft_putendl_fd("Usage: Mandelbrot, [Width], [Height], [Precision]", 2);
		ft_putstr_fd("Usage: Julia, [Width], [Height], [Real], [Imaginary]", 2);
		ft_putendl_fd(" [Precision].", 2);
		exit(1);
	}
	if (ft_verify_arguments(argc, argv))
		ft_putendl_fd("Invalid arg: Width Height Precision cant be <= 0", 2);
	if (!ft_choose_fractal(argv[1], argc))
	{
		ft_putendl_fd("Incorrect name or argument count: Available fractals are:", 2);
		ft_putendl_fd("Mandelbrot (4 args), Julia (6 args)", 2);
		exit(1);
	}
	if (ft_choose_fractal(argv[1], argc) == 1)
	{
		if (argc == 7)
		{
			ft_putstr_fd("Usage: Mandelbrot, [Width], [Height], ", 2);
			ft_putendl_fd(" [Precision]", 2);
			exit(1);
		}
	}
}

int	ft_verify_arguments(int argc, char **argv)
{
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0)
		return (1);
	if (argc == 5)
	{
		if (ft_atoi(argv[4]) <= 0)
			return (1);
	}
	else if (argc == 7)
	{
		if (ft_atoi(argv[6]) <= 0)
			return (1);
	}
	return (0);
}

int	ft_choose_fractal(char *str, int argc)
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
	if (!strncmp(s, "mandelbrot", 10) && argc == 5)
		return (1);
	if (!strncmp(s, "julia", 6) && argc == 7)
		return (2);
	return (0);
}

void	ft_cleanup_and_free(t_fractol *f)
{
	if (f->img_ptr && f->init)
		mlx_destroy_image(f->init, f->img_ptr);
	if (f->win && f->init)
		mlx_destroy_window(f->init, f->win);
	if (f->init)
	{
		mlx_destroy_display(f->init);
		free(f->init);
	}
	free(f);
	exit(1);
}
