##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## create a makefile
##

SRC 	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include
	cp my.h ../../include
clean:
	rm -f $(wildcard *~)
	rm -f $(wildcard *#)
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
