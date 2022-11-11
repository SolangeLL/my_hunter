/*
** EPITECH PROJECT, 2022
** init buttons callbacks
** File description:
** Initialize buttons callbacks
*/

#include "../../include/my_hunter.h"

static void init_menu_callbacks(button_t **btn)
{
    btn[0]->callback = &goToGame;
    btn[1]->callback = &goToSettings;
    btn[2]->callback = &goToQuit;
}

static void initSettingsCallbacks(button_t **btn)
{
    btn[0]->callback = &goToMenu;
    btn[1]->callback = &goToMenu;
}

void initButtonsCallbacks(game_t *game)
{
    init_menu_callbacks(game->menu->btn);
    initSettingsCallbacks(game->settings->btn);
}
