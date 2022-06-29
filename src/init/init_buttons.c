/*
** EPITECH PROJECT, 2022
** init_button
** File description:
** Regroup all functions about buttons' initializing
*/

#include "../../include/my_hunter.h"

void resize_button(button_t *button, sfVector2f scale);

button_t *init_button(char *texture_path, sfVector2f pos)
{
    sfVector2u size = (sfVector2u) {0, 0};
    button_t *btn = NULL;

    btn = malloc(sizeof(button_t));
    btn->sprite = sfSprite_create();
    btn->texture = CREATE_TEXTURE(texture_path, NULL);
    size = sfTexture_getSize(btn->texture);
    btn->pos = pos;
    btn->color = sfSprite_getColor(btn->sprite);
    sfSprite_setTexture(btn->sprite, btn->texture, 0);
    sfSprite_setPosition(btn->sprite, btn->pos);
    btn->pressed = 0;
    btn->btn_rect = (sfFloatRect) {pos.x, pos.y, size.x, size.y};
    return btn;
}

void init_menu_buttons(menu_t *menu)
{
    menu->btn = malloc(sizeof(button_t *) * 4);
    menu->btn[0] = init_button("res/img/buttons/play.png", SF2F {100, 780});
    menu->btn[1] = init_button("res/img/buttons/settings.png", SF2F {880, 780});
    menu->btn[2] = init_button("res/img/buttons/no.png", SF2F {1660, 780});
    menu->btn[3] = NULL;
    resize_button(menu->btn[0], SF2F {10, 10});
    resize_button(menu->btn[1], SF2F {10, 10});
    resize_button(menu->btn[2], SF2F {10, 10});

}

//! Tools for buttons

void color_button(button_t *button, int modify)
{
    sfSprite_setColor(button->sprite, (sfColor)
    {button->color.r + modify,
    button->color.g + modify,
    button->color.b + modify,
    255});
}

void resize_button(button_t *button, sfVector2f scale)
{
    button->btn_rect.height *= scale.y;
    button->btn_rect.width *= scale.x;
    sfSprite_setScale(button->sprite, (sfVector2f) {scale.x, scale.y});
}

void set_dark_button(button_t *button, float scale)
{
    color_button(button, -100);
    sfSprite_setPosition(button->sprite, SF2F {button->pos.x, button->pos.y});
    sfSprite_setScale(button->sprite, SF2F {scale, scale});
    button->pressed = 1;
}

void set_large_button(button_t *button, float scale, int gap)
{
    sfSprite_setScale(button->sprite, SF2F {scale, scale});
    sfSprite_setPosition(button->sprite, SF2F {button->pos.x - gap,
    button->pos.y});
}

void reset_button(button_t *button, float scale)
{
    sfSprite_setColor(button->sprite, sfWhite);
    sfSprite_setScale(button->sprite, SF2F {scale, scale});
    sfSprite_setPosition(button->sprite, SF2F {button->pos.x,
    button->pos.y});
    button->pressed = 0;
}
