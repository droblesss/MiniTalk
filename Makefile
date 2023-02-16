SERVER = server 
CLIENT = client
CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc

SRCS1 = server.c 
OBJS1 = $(SRCS1: .c=.o)
SRCS2 = client.c
OBJS2 = $(SRCS2: .c=.o)




all: $(SERVER), $(ClIENT)

$(SERVER): $(OBJS1)
    $(CC) $(CFLAGS) $(SERVER)
    
$(CLIENT): $(OBJS2)
    $(CC) $(CFLAGS) $(CLIENT)