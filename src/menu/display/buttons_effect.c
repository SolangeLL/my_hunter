/*
** EPITECH PROJECT, 2022
** buttons effect
** File description:
** Manage buttons' effects
*/

#include "../../../include/my_hunter.h"

void darken_button(button_t **btn, sfFloatRect mouse)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (MOUSE_OVER_BUTTON)
            set_dark_button(btn[i], 10);
}

void enlarge_buttons(button_t **btn, sfFloatRect mouse)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (MOUSE_OVER_BUTTON &&
        btn[i]->pressed == 0)
            set_large_button(btn[i], 11, 8);
}

void set_normal_buttons(button_t **btn, sfFloatRect mouse)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (!MOUSE_OVER_BUTTON)
            reset_button(btn[i], 10);
}