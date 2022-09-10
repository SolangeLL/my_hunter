/*
** EPITECH PROJECT, 2022
** display
** File description:
** Functions to display on the screen
*/

#include "../../../include/my_hunter.h"

void drawMenu(game_t *game)
{
    sfRenderWindow_clear(game->win->win, (sfColor) sfBlack);
    sfRenderWindow_drawSprite(game->win->win, game->menu->back_sp, NULL);
    for (int i = 0; game->menu->btn[i] != NULL; i++)
        sfRenderWindow_drawSprite(game->win->win, game->menu->btn[i]->sprite, 0);
    sfRenderWindow_display(game->win->win);
}