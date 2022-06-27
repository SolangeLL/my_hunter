/*
** EPITECH PROJECT, 2022
** loop
** File description:
** Main menu loop
*/

#include "../../include/my_hunter.h"

void manage_events(game_t *game)
{
    while (IS_EVENT) {
        if (game->gameplay->event.type == sfEvtClosed)
            sfRenderWindow_close(game->win->win);
        if (ESCAPE_IS_PRESSED)
            game->scene = GAME;
    }
}

void menu_loop(game_t *game)
{
    while (game->scene == MENU)
    {
        manage_events(game);
        draw_menu(game);
    }
}