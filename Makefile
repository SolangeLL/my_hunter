##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=		src/destroy.c \
				src/main.c \
				src/my_hunter.c

SRC_DISP	=	src/display/display.c \
				src/display/event.c \
				src/display/mouse.c \
				src/display/tool_char.c

SRC_ENMY	=	src/enemies/animations.c \
				src/enemies/move_enemies.c \
				src/enemies/spawn.c

SRC_INIT	=	src/init/initialize.c \
				src/init/initialize2.c \
				src/init/initialize3.c

OBJ		=	$(SRC:.c=.o)

OBJ_DISP =		$(SRC_DISP:.c=.o)

OBJ_ENMY =		$(SRC_ENMY:.c=.o)

OBJ_INIT =		$(SRC_INIT:.c=.o)

NAME	=		my_hunter

CFLAGS += -g2 -Wall -Wextra -L lib/my -lmy

LFLAGS = -lcsfml-system -lcsfml-audio -lcsfml-window -lcsfml-graphics -lm

all: libs $(NAME)

libs:
	make -C lib/my

$(NAME): $(OBJ) $(OBJ_DISP) $(OBJ_ENMY) $(OBJ_INIT)
	gcc $(OBJ) $(OBJ_DISP) $(OBJ_ENMY) $(OBJ_INIT) -o $(NAME) $(LFLAGS) $(CFLAGS)

clean:
	make clean -C lib/my
	rm -f $(OBJ)
	rm -f *.o
	rm -f *~

fclean: clean
	rm $(NAME)
	make fclean -C lib/my

re: fclean all
