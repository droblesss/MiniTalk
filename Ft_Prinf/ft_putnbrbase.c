/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:31:22 by drobles           #+#    #+#             */
/*   Updated: 2022/11/16 18:11:20 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	ft_putnbrbase(unsigned int number, char *base)
{
	static int	i;
	size_t		numero;

	numero = (size_t)number;
	i = 0;
	if (numero >= ft_strlenp(base))
	{
		ft_putnbrbase(numero / ft_strlenp(base), base);
		numero = numero % ft_strlenp(base);
	}
	i++;
	ft_putcharp(base[numero]);
	return (i);
}
