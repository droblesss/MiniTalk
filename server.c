/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:01:17 by drobles           #+#    #+#             */
/*   Updated: 2023/02/21 18:31:00 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_usr(int a)
{
	static char	ch;
	static int	i;


	(void) a;
	if (a == 30)
	{
		ch = (ch << 1);
		i++;
		usleep(1000);
	}
	if (a == 31)
	{
		ch = (ch << 1) + 1;
		i++;
		usleep(1000);
	}
	if (i == 8)
	{
		write(1, &ch, 1);
		ch = '\0';
		i = 0;
		usleep(1000);
	}
}

int	main(void)
{
	// struct sigaction act;
	// act.sa_handler = &ft_usr;
	// act.sa_flags = SA_RESTART;
	// sigfillset(&act.sa_mask);
	printf("Server´s pid is %d\n", getpid());
	signal(SIGUSR1, ft_usr);
	signal(SIGUSR2, ft_usr);
	// sigaction(SIGUSR1, &act, NULL);
	// sigaction(SIGUSR2, &act, NULL);
	while (1)
		;
	return (0);
}
