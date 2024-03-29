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

static void initSettingsTemplateCallbacks(text_button_t **txt_btn)
{
    txt_btn[0]->callback = &changeSettingsTemplate;
    txt_btn[1]->callback = &changeSettingsTemplate;
    txt_btn[2]->callback = &changeSettingsTemplate;
}

void initButtonsCallbacks(game_t *game)
{
    init_menu_callbacks(game->menu->btn);
    initSettingsTemplateCallbacks(game->settings->text_btn);
}
