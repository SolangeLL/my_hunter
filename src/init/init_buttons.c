/*
** EPITECH PROJECT, 2022
** init_button
** File description:
** Regroup all functions about buttons' initializing
*/

#include "../../include/my_hunter.h"

button_t *initButton(char *texture_path, sfVector2f pos)
{
    sfVector2u size = (sfVector2u){0, 0};
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
    btn->btn_rect = (sfFloatRect){pos.x, pos.y, size.x, size.y};
    return btn;
}

static void initMenuButtons(menu_t *menu)
{
    menu->btn = malloc(sizeof(button_t *) * 4);
    menu->btn[0] = initButton("res/img/buttons/play.png", SF2F{100, 780});
    menu->btn[1] = initButton("res/img/buttons/settings.png", SF2F{880, 780});
    menu->btn[2] = initButton("res/img/buttons/no.png", SF2F{1660, 780});
    menu->btn[3] = NULL;
    resizeButton(menu->btn[0], SF2F{10, 10});
    resizeButton(menu->btn[1], SF2F{10, 10});
    resizeButton(menu->btn[2], SF2F{10, 10});
}

void initScenesButtons(game_t *game)
{
    initMenuButtons(game->menu);
}
