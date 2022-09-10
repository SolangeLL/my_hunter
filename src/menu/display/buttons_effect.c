/*
** EPITECH PROJECT, 2022
** buttons effect
** File description:
** Manage buttons' effects
*/

#include "../../../include/my_hunter.h"

void darkenButton(button_t **btn, sfFloatRect mouse)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (MOUSE_OVER_BUTTON)
            setDarkButton(btn[i], 10);
}

void enlargeButton(button_t **btn, sfFloatRect mouse)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (MOUSE_OVER_BUTTON &&
        btn[i]->pressed == 0)
            setLargeButton(btn[i], 11, 8);
}

void setNormalButton(button_t **btn, sfFloatRect mouse)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (!MOUSE_OVER_BUTTON)
            resetButton(btn[i], 10);
}