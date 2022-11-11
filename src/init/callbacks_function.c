/*
** EPITECH PROJECT, 2022
** callbacks_function
** File description:
** Regroup all callbacks functions
*/

#include "../../include/my_hunter.h"

// TODO! Make goToX generic in one function
void goToGame(game_t *game, button_t *btn)
{
    game->scene = GAME;
    btn->pressed = 0;
    sfSound_play(game->sound->click);
}

void goToSettings(game_t *game, button_t *btn)
{
    game->scene = SETTINGS;
    btn->pressed = 0;
    sfSound_play(game->sound->click);
}

void goToMenu(game_t *game, button_t *btn)
{
    game->scene = MENU;
    btn->pressed = 0;
    sfSound_play(game->sound->click);
}

void goToQuit(game_t *game, button_t *btn)
{
    game->scene = QUIT;
    btn->pressed = 0;
    sfSound_play(game->sound->click);
}

void turnOnOrOffVolume(game_t *game, button_t *btn)
{
    if (game->sound->isMute)
        sfSound_setVolume(game->sound->game, 100);
    else
        sfSound_setVolume(game->sound->game, 0);
    game->sound->isMute = !game->sound->isMute;
    if (game->sound->isMute == true)
    {
        printf("this is true\n");
    }
    else
        printf("false it is\n");
    btn->pressed = 0;
}
