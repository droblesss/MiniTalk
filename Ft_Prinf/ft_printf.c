/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:14:36 by drobles           #+#    #+#             */
/*   Updated: 2022/11/16 18:09:36 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int	ft_format(va_list print, char format)
{
	int	dest;

	dest = 0;
	if (format == '%')
		dest += ft_putcharp('%');
	else if (format == 'c')
		dest += ft_putcharp(va_arg(print, int));
	else if (format == 's')
		dest += ft_putstrp(va_arg(print, char *));
	else if (format == 'd' || format == 'i')
		dest += ft_putnbrp(va_arg(print, int));
	else if (format == 'X')
		dest += ft_putnbrbase(va_arg(print, int), "0123456789ABCDEF");
	else if (format == 'x')
		dest += ft_putnbrbase(va_arg(print, int), "0123456789abcdef");
	else if (format == 'u')
		dest += ft_putnbrbase(va_arg(print, int), "0123456789");
	else if (format == 'p')
		dest += ft_putadress(va_arg(print, void *));
	return (dest);
}

int	ft_printf(char const *cadena, ...)
{
	int		size;
	int		contador;
	va_list	print;

	size = 0;
	contador = 0;
	va_start (print, cadena);
	while (cadena[contador])
	{
		if (cadena[contador] == '%')
		{
			size = size + ft_format(print, cadena[contador +1]);
			contador++;
		}
		else
			size = size + ft_putcharp(cadena[contador]);
		contador++;
	}
	va_end (print);
	return (size);
}
