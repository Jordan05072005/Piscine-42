OBJ = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
COMP = gcc -Wall -Wextra -Werror -I includes

all: libft.a

libft.a:
	$(COMP) -c srcs/ft_putchar.c -o srcs/ft_putchar.o
	$(COMP) -c srcs/ft_swap.c -o srcs/ft_swap.o
	$(COMP) -c srcs/ft_putstr.c -o srcs/ft_putstr.o
	$(COMP) -c srcs/ft_strlen.c -o srcs/ft_strlen.o
	$(COMP) -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o
	ar rcs libft.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libft.a

re: fclean all
