/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:23:03 by ilevy             #+#    #+#             */
/*   Updated: 2024/11/20 13:03:45 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/libft.h"

int	ft_printf(const char *str, ...);
int	ft_format_choice(va_list arg, char traveler);

int	ft_format_choice(va_list arg, char traveler)
{
	int	byte_size;

	byte_size = 0;
	if (traveler == 'c')
		byte_size += ft_printchar_fd(va_arg(arg, int), 1);
	else if (traveler == 's')
		byte_size += ft_printstr_fd(va_arg(arg, char *), 1);
	else if (traveler == '%')
		byte_size += ft_printpercent_fd(1);
	else if (traveler == 'p')
		byte_size += ft_printpoint_fd(va_arg(arg, uintptr_t), 1);
	else if (traveler == 'd' || traveler == 'i')
		byte_size += ft_printnumber_fd(va_arg(arg, int), 1);
	else if (traveler == 'X')
		byte_size += ft_print_big_hex_fd(va_arg(arg, unsigned int), 1);
	else if (traveler == 'x')
		byte_size += ft_print_lil_hex_fd(va_arg(arg, unsigned int), 1);
	else if (traveler == 'u')
		byte_size += ft_printunsigned_fd(va_arg(arg, unsigned int), 1);
	return (byte_size);
}

int	ft_printf(const char *str, ...)
{
	int		byte_size;
	va_list	arg;
	int		i;

	i = 0;
	if (!str)
		return (-1);
	va_start(arg, str);
	byte_size = 0;
	while (str[i])
	{
		if (str[i] != '%')
			byte_size += ft_printchar_fd(str[i], 1);
		else
		{
			byte_size += ft_format_choice(arg, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (byte_size);
}	
