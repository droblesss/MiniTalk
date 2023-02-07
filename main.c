#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "minitalk.h"

void fprint(int sig)
{
	printf("señal recibida %d\n", sig);
}

int main(int argc, char **argv)
{
	/*signal(int signum, signhandler_t handler);*/
	/*el primer argumento de la funcion es la señal a capturar, cada una tiene un numerito, el segundo argumento es la fución que llama el programa cuando recibe esa señal*/
	//30    SIGUSR1      terminate process    User defined signal 1
     //31    SIGUSR2      terminate process    User defined signal 2//

	//// if argc[1] == 30 || 29 ) while c < argc printf argc[c]  Esot en caso de que hubiera que meter por parametros la señanl y el mensaje que tiene que recibir el server y replicar el cliente. Un poco dificil porque el mensaje no iria entre comillas entonces es jodido aplicar printf creo
	
	struct sigaction sa;
	sa.sa_handler = &fprint;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	argc = 0;
	*argv = NULL;

	pid_t pidi = getpid();
	
	//signal(SIGUSR1, &fprint);
	printf("El PID es %d zzzzzz\n", pidi);
	while(1)
	{
		//printf("El PID es %d zzzzzz\n", pidi);
		sleep(2);
	}
	return(0);

}


// char *str = "abcd";

// int i = 0;

// char srvch = '\0';
// char ch = str[i];

// 	srvch += 1; if (ch & 128)
// 	srvch = srvch << 1 + 1; if (ch & 64)
// 	ch & 32
// 	ch & 16

// srvch = 10
