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

void updateMasterVolume(game_t *game, button_t *button, int val)
{
    sfSound_play(game->sound->click2);
    game->sound->master_volume += val;
    if (game->sound->master_volume > 100)
        game->sound->master_volume = 100;
    if (game->sound->master_volume < 0)
        game->sound->master_volume = 0;
    sfSound_setVolume(game->sound->click, game->sound->master_volume);
    sfSound_setVolume(game->sound->click2, game->sound->master_volume);
    sfSound_setVolume(game->sound->slime_death, game->sound->master_volume);
    sfSound_setVolume(game->sound->skel_death, game->sound->master_volume);
    sfSound_setVolume(game->sound->game, game->sound->master_volume);
    sfSound_setVolume(game->sound->miss, game->sound->master_volume);
    sfSound_setVolume(game->sound->highScore, game->sound->master_volume);
    sfSound_setVolume(game->sound->levelUp, game->sound->master_volume);
    sfSound_setVolume(game->sound->menu, game->sound->master_volume);
    button->pressed = 0;
}

void muteVolume(game_t *game, button_t *btn)
{
    if (game->sound->isMute)
        sfSound_setVolume(game->sound->game, 100);
    else
        sfSound_setVolume(game->sound->game, 0);
    game->sound->isMute = !game->sound->isMute;
    btn->pressed = 0;
    sfSprite_setColor(btn->sprite, sfWhite);
}

void changeSettingsTemplate(game_t *game, text_button_t *btn)
{
    sfSound_play(game->sound->click);
    game->settings->templateIndex = btn->template;
    btn->pressed = 0;
}
