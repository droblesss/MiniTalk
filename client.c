/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:01:05 by drobles           #+#    #+#             */
/*   Updated: 2023/02/22 11:24:18 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

int	ft_atoi(const char *str)
{
	int		c;
	int		sign;
	size_t	numero;

	c = 0;
	sign = 1;
	numero = 0;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
			c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			sign *= -1;
		c++;
	}
	while (str[c] > 47 && str[c] < 58)
	{
		numero = numero * 10 + (str[c] - 48);
		c++;
	}
	if (numero > 9223372036854775807 && sign == 1)
		return (-1);
	else if (numero > 9223372036854775807 && sign == -1)
		return (0);
	return (numero * sign);
}

void	bitmove(int pidi, int pos, char ch, int cont)
{
	if (pos & cont)
	{
		ch = (ch << 1) + 1;
		kill(pidi, SIGUSR2);
	}
	else if (!(pos & cont))
	{
		ch = ch << 1;
		kill(pidi, SIGUSR1);
	}
}

void	sender(int pidi, char *text)
{
	char	ch;
	int		i;
	char	pos;
	int		cont;

	ch = '\0';
	i = 0;
	cont = 128;
	while (text[i] != '\0')
	{
		pos = text[i];
		while (cont > 0)
		{
			bitmove(pidi, pos, ch, cont);
			usleep(1000);
			cont = cont / 2;
		}
		i++;
		cont = 128;
		usleep(1500);
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	pid_t	pidi;

	if (argc == 3)
	{
		pidi = ft_atoi(argv[1]);
		if (pidi > 0)
		{
			message = argv[2];
			sender(pidi, message);
		}
		else
			ft_printf("ERROR: Invalid PID");
	}
	else if (argc != 3)
		ft_printf("ERROR: Invalid PID");
	return (0);
}
