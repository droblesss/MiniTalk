#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	char *str = "jl";
	int i = 0;
	//char ch = '\0';
	char pos = str[i];
	int cont = 128;

	while (str[i] != '\0')
	{
		pos = str[i];
		while (cont > 0)
		{
		// 	if (cont == 128)
		// 	{	if(pos & cont)
		// 			ch = ch +1;
		// 		else if (pos & cont)
		// 			ch = ch >> 1;
		// 	}
		// 	else
		// 		if(str[i] & cont)
		// 			ch = (ch << 1) + 1;
		// 		ch = ch << 1;
		// 	cont = cont / 2;
		// 	printf("binary = %d\n", ch);
		if (pos & cont)
			printf("1\n");
		else
			printf("0\n");
		cont  = cont /2;
		}
		printf("next character\n");
		i++;
		cont = 128;
	}
}