/*
** EPITECH PROJECT, 2021
** initialize2
** File description:
** Other functions to initialize
*/

#include "../../include/my_hunter.h"

void init_rect(display_t *enemy)
{
    // enemy->skeleton->rect.top = 128;
    // enemy->skeleton->rect.left = 0;
    // enemy->skeleton->rect.width = 64;
    // enemy->skeleton->rect.height = 64;
    enemy->slime->rect.top = 0;
    enemy->slime->rect.left = 0;
    enemy->slime->rect.width = 32;
    enemy->slime->rect.height = 32;
}

void init_rect_scaled(display_t *display)
{
    // display->skeleton->rect_scaled = (sfFloatRect) \
    // {.top = sfSprite_getPosition(display->skeleton->sp).y,
    // .left = sfSprite_getPosition(display->skeleton->sp).x,
    // .width = display->skeleton->rect.width * 2,
    // .height = display->skeleton->rect.height * 2};
    display->slime->rect_scaled = (sfFloatRect) \
    {.top = sfSprite_getPosition(display->slime->sp).y,
    .left = sfSprite_getPosition(display->slime->sp).x - 64,
    .width = display->slime->rect.width * 3,
    .height = display->slime->rect.height * 3};
}
