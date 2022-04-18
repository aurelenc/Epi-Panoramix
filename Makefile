##
## EPITECH PROJECT, 2022
## Panoramix
## File description:
## Makefile
##

NAME	=	panoramix

TESTS_NAME	=	unit_tests

SRC	=	src/main.c\
		src/panoramix.c\
		src/villager.c\
		src/druid.c\

OBJ	=	${SRC:.c=.o}

CFLAGS	=	-Wall -Werror -I include/

LDFLAGS	=	-lpthread

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make -C tests clean

fclean: clean
	rm -f $(NAME)
	rm -f ${TESTS_NAME}
	make -C tests fclean

re: fclean
	make

unit_tests: re
	make -C tests
	cp tests/$(TESTS_NAME) .

tests_run: unit_tests
	./$(TESTS_NAME)

all:	$(NAME)

.PHONY: $(NAME) clean fclean re all unit_tests tests_run
