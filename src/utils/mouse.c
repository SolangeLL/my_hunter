/*
** EPITECH PROJECT, 2021
** mouse
** File description:
** mouse
*/

#include "../../include/my_hunter.h"

void getMouseHitbox(game_t *game)
{
    game->gameplay->mouse_rect.top = \
    sfMouse_getPositionRenderWindow(game->win->win).y;
    game->gameplay->mouse_rect.left = \
    sfMouse_getPositionRenderWindow(game->win->win).x;
    game->gameplay->mouse_rect.width = 1;
    game->gameplay->mouse_rect.height = 1;
}
