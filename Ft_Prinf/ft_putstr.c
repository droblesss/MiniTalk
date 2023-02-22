/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:57:20 by drobles           #+#    #+#             */
/*   Updated: 2022/11/16 18:10:15 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstrp(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_putstrp("(null)"));
	else
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

// int main()
// {
// 	ft_putstr(NULL);
// 	write(1, "\n", 1);
// 	printf("%s", NULL);
// 	return 0;
// }
