NAME	=	unit_tests

SRC	=	../src/panoramix.c\
		../src/villager.c\
		../src/druid.c\

TEST_SRC	=	panoramix_tests.c

OBJ	=	${SRC:.c=.o} ${TEST_SRC:.c=.o}

CFLAGS	=	-Wall -Werror -pthread -lpthread

LDFLAGS = -lcriterion --coverage

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) ${LDFLAGS}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

all:	$(NAME)

.PHONY: $(NAME) clean fclean all
