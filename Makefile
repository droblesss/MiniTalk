NAME = all
SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
PRINTF = Ft_Prinf/
PRINTFPATH= Ft_Prinf/libftprintf.a

%.o: %.c
	$(CC) -c $(CFLAGS) $?

all: server client

server: server.o
	@$(MAKE) -C $(PRINTF)
	$(CC) $(CFLAGS) $(PRINTFPATH) -o $@ $< 

client: client.o
	$(CC) $(CFLAGS) $(PRINTFPATH) -o $@ $< 

clean:
	rm -f server.o client.o
	@$(MAKE) clean -C $(PRINTF)

fclean: clean
	rm -f server client
	rm -f $(PRINTFPATH)

re: fclean all

norme:
	@norminette server.c client.c
