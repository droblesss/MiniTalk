#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

void	ft_usr1(int a)
{
	(void) a;
	printf("0\n");
}

void	ft_usr2(int a)
{
	(void) a;
	printf("1\n");
}

int	main(void)
{
	printf("Server´s pid is %d\n", getpid());
	signal(SIGUSR1, ft_usr1);
	signal(SIGUSR2, ft_usr2);
	while (1)
	//write(1, &ch, 1);
		;
	return (0);
}
