/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:23:49 by drobles           #+#    #+#             */
/*   Updated: 2022/09/19 12:24:20 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	ft_putadress(void *numero)
{
	int		i;
	size_t	aux;

	i = 0;
	aux = (size_t)numero;
	i = write(1, "0x", 2);
	i = i + ft_puthexa(aux);
	return (i);
}
// int main()
// {
// 	void *hola;

// 	hola = 9223372036854775807L;
// 	ft_putadress("%p", hola);
// 	printf("\n");
// 	printf("%p",hola);
// 	printf("\n");
// 	printf("%x",(unsigned int) hola);

// 	return 0;
// }
