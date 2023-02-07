#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	ft_usr1(int a)
{
	(void) a;
	printf("USR1\n");
}

void	ft_usr2(int a)
{
	(void) a;
	printf("USR2\n");
}
int	main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, ft_usr1);
	signal(SIGUSR2, ft_usr2);
	while (1)
		;
	return (0);
}
