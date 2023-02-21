SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) -c $(CFLAGS) $?

all: server client

server: server.o
	$(CC) -o $@ $< 

client: client.o
	$(CC) -o $@ $< 

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f server client 

re: fclean all

