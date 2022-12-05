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
    char *newValue = NULL;
    sfSound_play(game->sound->click2);
    if (game->sound->master_volume + val <= 100 && game->sound->master_volume + val >= 0)
    {
        game->sound->master_volume += val;
        newValue = createString(game->sound->master_volume);
        sfText_setString(game->settings->templates[AUDIO]->texts[button->linkedText], newValue);
        modifVolume(game->sound->click, val);
        modifVolume(game->sound->click2, val);
        modifVolume(game->sound->slime_death, val);
        modifVolume(game->sound->skel_death, val);
        modifVolume(game->sound->game, val);
        modifVolume(game->sound->miss, val);
        modifVolume(game->sound->highScore, val);
        modifVolume(game->sound->levelUp, val);
        modifVolume(game->sound->menu, val);
        button->pressed = 0;
    }
}

void updateMusicVolume(game_t *game, button_t *button, int val)
{
    char *newValue = NULL;
    sfSound_play(game->sound->click2);
    game->sound->music_volume += val;
    if (game->sound->music_volume > 100)
        game->sound->music_volume = 100;
    if (game->sound->music_volume < 0)
        game->sound->music_volume = 0;
    newValue = createString(game->sound->music_volume);
    sfText_setString(game->settings->templates[AUDIO]->texts[button->linkedText], newValue);
    modifVolume(game->sound->game, val);
    modifVolume(game->sound->menu, val);
    button->pressed = 0;
}

void updateEffectsVolume(game_t *game, button_t *button, int val)
{
    char *newValue = NULL;
    sfSound_play(game->sound->click2);
    game->sound->effects_volume += val;
    if (game->sound->effects_volume > 100)
        game->sound->effects_volume = 100;
    if (game->sound->effects_volume < 0)
        game->sound->effects_volume = 0;
    newValue = createString(game->sound->effects_volume);
    sfText_setString(game->settings->templates[AUDIO]->texts[button->linkedText], newValue);
    modifVolume(game->sound->click, val);
    modifVolume(game->sound->click2, val);
    modifVolume(game->sound->slime_death, val);
    modifVolume(game->sound->skel_death, val);
    modifVolume(game->sound->miss, val);
    modifVolume(game->sound->highScore, val);
    modifVolume(game->sound->levelUp, val);
    button->pressed = 0;
}

//* To keep or not ?
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
//* To keep or not ?

void changeSettingsTemplate(game_t *game, text_button_t *btn)
{
    sfSound_play(game->sound->click);
    game->settings->templateIndex = btn->template;
    setNormalText(btn);
    btn->pressed = 0;
}

void changeWindow(game_t *game, text_button_t *btn)
{
    // Change the resolution of the window
    sfSound_play(game->sound->click);
    sfRenderWindow_destroy(game->win->win);
    game->win->win = sfRenderWindow_create(game->win->mode, "MY HUNTER", sfClose, NULL);
    printf("Resolution : %d x %d\n", btn->resolution.width, btn->resolution.height);
    sfRenderWindow_setSize(game->win->win, (sfVector2u){btn->resolution.width, btn->resolution.height});
    setNormalText(btn);
    btn->pressed = 0;
    game->win->isFullscreen = 0;
}

void setFullscreen(game_t *game, text_button_t *btn)
{
    sfRenderWindow_destroy(game->win->win);
    if (game->win->isFullscreen) {
        game->win->win = sfRenderWindow_create(game->win->mode, "MY HUNTER", sfDefaultStyle, NULL);
        sfRenderWindow_setSize(game->win->win, (sfVector2u){game->win->mode.width, game->win->mode.height});
    } else
        game->win->win = sfRenderWindow_create(game->win->mode, "MY HUNTER", sfFullscreen, NULL);
    game->win->isFullscreen = !game->win->isFullscreen;
    setNormalText(btn);
    btn->pressed = 0;
}
