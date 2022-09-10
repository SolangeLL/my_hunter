/*
** EPITECH PROJECT, 2022
** tools_button
** File description:
** Buttons' tools
*/

#include "../../include/my_hunter.h"

void colorButton(button_t *button, int modify)
{
    sfSprite_setColor(button->sprite, (sfColor)
    {button->color.r + modify,
    button->color.g + modify,
    button->color.b + modify,
    255});
}

void resizeButton(button_t *button, sfVector2f scale)
{
    button->btn_rect.height *= scale.y;
    button->btn_rect.width *= scale.x;
    sfSprite_setScale(button->sprite, (sfVector2f) {scale.x, scale.y});
}

void setDarkButton(button_t *button, float scale)
{
    colorButton(button, -100);
    sfSprite_setPosition(button->sprite, SF2F {button->pos.x, button->pos.y});
    sfSprite_setScale(button->sprite, SF2F {scale, scale});
    button->pressed = 1;
}

void setLargeButton(button_t *button, float scale, int gap)
{
    sfSprite_setScale(button->sprite, SF2F {scale, scale});
    sfSprite_setPosition(button->sprite, SF2F {button->pos.x - gap,
    button->pos.y});
}

void resetButton(button_t *button, float scale)
{
    sfSprite_setColor(button->sprite, sfWhite);
    sfSprite_setScale(button->sprite, SF2F {scale, scale});
    sfSprite_setPosition(button->sprite, SF2F {button->pos.x,
    button->pos.y});
    button->pressed = 0;
}
