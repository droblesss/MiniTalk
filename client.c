#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

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


void	sender(int pidi, char *text)
{
	char ch;
	int i;
	char pos;
	int cont;

	ch = '\0';
	i = 0;
	cont = 128;
	while(text[i] !='\0')
	{
		pos = text[i];
		while (cont > 0)
		{
			if (pos & cont)
			{
				ch = (ch << 1) + 1;
				kill(pidi,SIGUSR2);
			}
			else if (!(pos & cont))
			{
				ch = ch << 1;
				kill(pidi,SIGUSR1);
			}
			usleep(250);
			cont = cont /2;
		}
		write(1, &ch, 1);
		i++;
		cont = 128;
		usleep(250);
	}
}


int main(int argc, char **argv)
{
	char *message;
	pid_t pidi;
	pidi = ft_atoi(argv[1]);
	message = argv[2];
	sender(pidi, message);
	argc = 0;
	return(0);
}