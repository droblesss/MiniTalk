#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

int main()
{
	char *str = "holaquetal";
	int i = 0;
	char ch = '\0';
	char pos = str[i];
	int cont = 128;

	while (str[i] != '\0')
	{
		pos = str[i];
		while (cont > 0)
		{
		if (pos & cont)
		{
			numero[j]= '1';
			ch = (ch << 1) + 1;
		}
		else if (!(pos & cont))
		{
			numero[j] = '0';
			ch = ch << 1;
		}
		cont  = cont /2;
		j++;
		}
		write(1, &ch, 1);
		i++;
		cont = 128;
	}
}