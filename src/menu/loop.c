/*
** EPITECH PROJECT, 2022
** loop
** File description:
** Main menu loop
*/

#include "../../include/my_hunter.h"

void menuLoop(game_t *game)
{
    if (sfSound_getStatus(game->sound->menu) != sfPlaying)
        sfSound_play(game->sound->menu);
    while (game->scene == MENU)
    {
        getMouseHitbox(game);
        manageMenuEvents(game);
        drawMenu(game);
    }
}