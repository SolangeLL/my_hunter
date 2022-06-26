/*
** EPITECH PROJECT, 2021
** mouse
** File description:
** mouse
*/

#include "../../../include/my_hunter.h"

void get_mouse_hitbox(game_t *game)
{
    game->gameplay->mouse_rect.top = \
    sfMouse_getPositionRenderWindow(game->window->window).y;
    game->gameplay->mouse_rect.left = \
    sfMouse_getPositionRenderWindow(game->window->window).x;
    game->gameplay->mouse_rect.width = 1;
    game->gameplay->mouse_rect.height = 1;
}
