/*
** EPITECH PROJECT, 2022
** callbacks_function
** File description:
** Regroup all callbacks functions
*/

#include "../../include/my_hunter.h"

void goToGame(button_t *btn, sfSound *sound, int *status)
{
    *status = GAME;
    btn->pressed = 0;
    sfSound_play(sound);
}

void goToSettings(button_t *btn, sfSound *sound, int *status)
{
    *status = SETTINGS;
    btn->pressed = 0;
    sfSound_play(sound);
}

void goToMenu(button_t *btn, sfSound *sound, int *status)
{
    *status = MENU;
    btn->pressed = 0;
    sfSound_play(sound);
}

void goToQuit(button_t *btn, sfSound *sound, int *status)
{
    *status = QUIT;
    btn->pressed = 0;
    sfSound_play(sound);
}
