all: libft.a

libft.a:
	gcc -Wall -Wextra -Werror -I includes -c srcs/ft_putchar.c -o srcs/ft_putchar.o
	gcc -Wall -Wextra -Werror -I includes -c srcs/ft_swap.c -o srcs/ft_swap.o
	gcc -Wall -Wextra -Werror -I includes -c srcs/ft_putstr.c -o srcs/ft_putstr.o
	gcc -Wall -Wextra -Werror -I includes -c srcs/ft_strlen.c -o srcs/ft_strlen.o
	gcc -Wall -Wextra -Werror -I includes -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o
	ar rcs libft.a srcs/*.o

clean:
	rm -f srcs/*.o

fclean: clean
	rm -f libft.a

re: fclean all
