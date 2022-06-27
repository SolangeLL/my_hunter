##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

GAME	=	src/game

MENU	=	src/menu

SRC		=	src/destroy.c \
			src/main.c \
			src/my_hunter.c \
			src/init/initialize.c \
			src/init/init_rect.c \
			src/init/init_sprites.c \
			src/init/init_assets.c \
			src/init/init_buttons.c

SRC_GAME	=	$(GAME)/display/display.c \
				$(GAME)/display/event.c \
				$(GAME)/display/mouse.c \
				$(GAME)/display/tool_char.c \
				$(GAME)/enemies/animations.c \
				$(GAME)/enemies/move_enemies.c \
				$(GAME)/enemies/spawn.c \
				$(GAME)/loop.c \

SRC_MENU	=	$(MENU)/loop.c \
				$(MENU)/display/display.c

OBJ		=	$(SRC:.c=.o)

OBJ_GAME	=	$(SRC_GAME:.c=.o)

OBJ_MENU	=	$(SRC_MENU:.c=.o)

NAME	=		my_hunter

CFLAGS += -g2 -Wall -Wextra -L lib/my -lmy

LFLAGS = -lcsfml-system -lcsfml-audio -lcsfml-window -lcsfml-graphics -lm

all: libs $(NAME)

libs:
	make -C lib/my

$(NAME): $(OBJ) $(OBJ_GAME) $(OBJ_MENU)
	gcc $(OBJ) $(OBJ_GAME) $(OBJ_MENU) -o $(NAME) $(LFLAGS) $(CFLAGS)

clean:
	make clean -C lib/my
	rm -f $(OBJ)
	rm -f $(OBJ_GAME)
	rm -f $(OBJ_MENU)
	rm -f $(NAME)
	rm -f *.o
	rm -f *~

fclean: clean
	make fclean -C lib/my

re: fclean all
