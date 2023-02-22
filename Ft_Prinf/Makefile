FILES = ft_strlen.c ft_putstr.c ft_putnbr.c\
	   ft_putchar.c ft_putnbrbase.c ft_printf.c ft_putadress.c\
	   ft_puthexa.c

OBJS = $(FILES:.c=.o)

Cflags = -Wall -Wextra -Werror #Flags necesarias para compilar, habrá que ponerlas si no respeta el comp

NAME = libftprintf.a

LIB = libftprintf.h


##################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
		
$(OBJS): $(FILES) $(LIB)
	gcc $(Cflags) -c $(FILES) 

clean:
	rm  -f $(OBJS) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
