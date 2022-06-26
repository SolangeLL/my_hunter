##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=		$(wildcard src/*.c)

OBJ		=		$(SRC:.c=.o)

NAME	=		my_hunter

CFLAGS += -g2 -Wall -Wextra -L lib/my -lmy

LFLAGS = -lcsfml-system -lcsfml-audio -lcsfml-window -lcsfml-graphics -lm

all: libs $(NAME)

libs:
	make -C lib/my

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(LFLAGS) $(CFLAGS)

clean:
	make clean -C lib/my
	rm -f $(OBJ)
	rm -f *.o
	rm -f *~

fclean: clean
	rm $(NAME)
	make fclean -C lib/my

re: fclean all
