#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int i = 0;

void	ft_usr(int a)
{
	static char ch;

	(void) a;
	if (a == 30)
	{
		ch = (ch << 1);
		i++;
		usleep(250);
	}

	if (a == 31)
	{
		ch = (ch << 1) + 1;
		i++;
		usleep(250);
	}
	if (i == 8)
	{
		write(1, &ch, 1);;
		ch = '\0';
		i = 0;
		usleep(250);
	}
}

int	main(void)
{
	printf("Server´s pid is %d\n", getpid());
	signal(SIGUSR1, ft_usr);
	signal(SIGUSR2, ft_usr);
	while (1)
		;
	return (0);
}
