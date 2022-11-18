/*
** EPITECH PROJECT, 2022
** tools_button
** File description:
** Buttons' tools
*/

#include "../../include/my_hunter.h"

void resizeButton(button_t *button, sfVector2f scale)
{
    button->btn_rect.height *= scale.y;
    button->btn_rect.width *= scale.x;
    button->scale = scale;
    sfSprite_setScale(button->sprite, (sfVector2f) {scale.x, scale.y});
}

static void colorButton(button_t *button, int modify)
{
    sfSprite_setColor(button->sprite, (sfColor)
    {button->color.r + modify,
    button->color.g + modify,
    button->color.b + modify,
    255});
}

static void setDarkButton(button_t *button)
{
    colorButton(button, -100);
    sfSprite_setPosition(button->sprite, SF2F {button->pos.x, button->pos.y});
    sfSprite_setScale(button->sprite, button->scale);
    button->pressed = 1;
}

static void setLargeButton(button_t *button)
{
    sfVector2f scale = SF2F {button->scale.x * 1.1,
    button->scale.y * 1.1};

    sfSprite_setScale(button->sprite, scale);
    sfSprite_setPosition(button->sprite, SF2F {button->pos.x - scale.x * 0.8,
    button->pos.y - scale.y * 0.8});
}

static void setNormalButton(button_t *button)
{
    sfSprite_setColor(button->sprite, sfWhite);
    sfSprite_setScale(button->sprite, button->scale);
    sfSprite_setPosition(button->sprite, SF2F {button->pos.x,
    button->pos.y});
    button->pressed = 0;
}

void darkenButton(button_t **btn, sfFloatRect mouse)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (MOUSE_OVER_BUTTON && btn[i]->pressed == 0)
            setDarkButton(btn[i]);
}

void enlargeButton(button_t **btn, sfFloatRect mouse)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (MOUSE_OVER_BUTTON &&
        btn[i]->pressed == 0)
            setLargeButton(btn[i]);
}

void resetButton(button_t **btn, sfFloatRect mouse)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (!MOUSE_OVER_BUTTON)
            setNormalButton(btn[i]);
}
