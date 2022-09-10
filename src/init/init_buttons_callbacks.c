/*
** EPITECH PROJECT, 2022
** init buttons callbacks
** File description:
** Initialize buttons callbacks
*/

#include "../../include/my_hunter.h"

static void init_menu_callbacks(button_t **btn)
{
    btn[0]->change_scene = &goToGame;
    btn[1]->change_scene = &goToSettings;
    btn[2]->change_scene = &goToQuit;
}

void initButtonsCallbacks(game_t *game)
{
    init_menu_callbacks(game->menu->btn);
}
