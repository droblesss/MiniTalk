/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:26:57 by drobles           #+#    #+#             */
/*   Updated: 2022/11/16 18:11:36 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthexa(unsigned long int nbr)
{
	char		*base;
	static int	i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_puthexa(nbr / 16);
		nbr = nbr % 16;
	}
	i++;
	ft_putcharp(base[nbr]);
	return (i);
}
