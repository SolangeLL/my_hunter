##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

GAME	=	src/game

MENU	=	src/menu

UTILS	=	src/utils

SETTINGS = src/settings

INIT = src/init

SRC		=	src/main.c \
			src/my_hunter.c \
			$(INIT)/initialize.c \
			$(INIT)/init_sprites.c \
			$(INIT)/init_enemies.c \
			$(INIT)/init_sounds.c \
			$(INIT)/init_buttons.c \
			$(INIT)/init_text_buttons.c \
			$(INIT)/callbacks_function.c \
			$(INIT)/init_buttons_callbacks.c \
			$(INIT)/init_templates.c

SRC_GAME	=	$(GAME)/display/display.c \
				$(GAME)/display/event.c \
				$(GAME)/enemies/animations.c \
				$(GAME)/enemies/move_enemies.c \
				$(GAME)/enemies/miss_enemies.c \
				$(GAME)/loop.c \

SRC_MENU	=	$(MENU)/loop.c \
				$(MENU)//display/event.c \
				$(MENU)/display/display.c \

SRC_SETTINGS =	$(SETTINGS)/loop.c \
				$(SETTINGS)/display/display.c \
				$(SETTINGS)/display/event.c \

SRC_UTILS	=	$(UTILS)/deleteNode.c \
				$(UTILS)/destroy.c \
				$(UTILS)/destroy_assets.c \
				$(UTILS)/mouse.c \
				$(UTILS)/score.c \
				$(UTILS)/seconds.c \
				$(UTILS)/tools_buttons.c \
				$(UTILS)/tools_text.c \
				$(UTILS)/tools_sound.c \
				$(UTILS)/tool_char.c \


OBJ		=	$(SRC:.c=.o) \
			$(SRC_GAME:.c=.o) \
			$(SRC_MENU:.c=.o) \
			$(SRC_SETTINGS:.c=.o) \
			$(SRC_UTILS:.c=.o)

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
	rm -f $(OBJ_GAME)
	rm -f $(OBJ_MENU)
	rm -f $(OBJ_UTILS)
	rm -f $(NAME)
	rm -f *.o
	rm -f *~
	rm -f vgcore.*

fclean: clean
	make fclean -C lib/my

re: fclean all
