NAME	=	unit_tests

SRC	=	../src/main.c
SRC	=	../src/panoramix.c

TEST_SRC	=	panoramix_tests.c

OBJ	=	${SRC:.c=.o} ${TEST_SRC:.c=.o}

CFLAGS	=	-Wall -Werror -lpthread

LDFLAGS = -lcriterion --coverage

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) ${LDFLAGS}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

all:	$(NAME)

.PHONY: $(NAME) clean fclean all
