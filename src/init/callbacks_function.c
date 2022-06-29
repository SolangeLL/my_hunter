/*
** EPITECH PROJECT, 2022
** callbacks_function
** File description:
** Regroup all callbacks functions
*/

#include "../../include/my_hunter.h"

void go_to_game(button_t *btn, sfSound *sound, int *status)
{
    *status = GAME;
    btn->pressed = 0;
    sfSound_play(sound);
}

void go_to_settings(button_t *btn, sfSound *sound, int *status)
{
    *status = SETTINGS;
    btn->pressed = 0;
    sfSound_play(sound);
}

void go_to_menu(button_t *btn, sfSound *sound, int *status)
{
    *status = MENU;
    btn->pressed = 0;
    sfSound_play(sound);
}

void go_to_quit(button_t *btn, sfSound *sound, int *status)
{
    *status = QUIT;
    btn->pressed = 0;
    sfSound_play(sound);
}
