/*
** EPITECH PROJECT, 2022
** init buttons callbacks
** File description:
** Initialize buttons callbacks
*/

#include "../../include/my_hunter.h"

static void init_menu_callbacks(button_t **btn)
{
    btn[0]->change_scene = &go_to_game;
    btn[1]->change_scene = &go_to_settings;
    btn[2]->change_scene = &go_to_quit;
}

void init_buttons_callbacks(game_t *game)
{
    init_menu_callbacks(game->menu->btn);
}
