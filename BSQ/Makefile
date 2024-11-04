GCCW = gcc -Wall -Wextra -Werror -g

SRC = srcs/main.c\
		srcs/utility1.c\
		srcs/utility2.c\
		srcs/utility3.c\
		srcs/handle_list.c\
		srcs/solver.c\
		srcs/read_files.c\
		srcs/error_handling.c\
		srcs/write.c\
		srcs/read_stdin.c\
		srcs/freeing.c

INCLUDE = includes/bsq.h

OBJ = ${SRC:.c=.o}

NAME = bsq

.c.o:
	${GCCW} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${GCCW} ${OBJ} -I ${INCLUDE} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re