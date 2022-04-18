NAME	=	unit_tests

SRC	=	../src/panoramix.c\
		../src/villager.c\
		../src/druid.c\

TEST_SRC	=	panoramix_tests.c

CFLAGS	=	-Wall -Werror

LDFLAGS = -lpthread -lcriterion --coverage -I ../include/

$(NAME):
	gcc $(SRC) $(TEST_SRC) -o $(NAME) ${LDFLAGS}

clean:
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

all:	$(NAME)

.PHONY: $(NAME) clean fclean all
