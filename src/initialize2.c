/*
** EPITECH PROJECT, 2021
** initialize2
** File description:
** Other functions to initialize
*/

#include "../include/my_hunter.h"

void init_sprites(display_t *sprite)
{
    sprite->background->back_texture = \
    CREATE_TEXTURE("res/img/Background.png", NULL);
    sprite->skeleton->texture = \
    CREATE_TEXTURE("res/img/Skeleton_enemy.png", NULL);
    sprite->slime->texture = \
    CREATE_TEXTURE("res/img/Slime.png", NULL);
    sprite->slime->death_texture = \
    CREATE_TEXTURE("res/img/Slime_death.png", NULL);
    sprite->sign->texture = \
    CREATE_TEXTURE("res/img/sign.png", NULL);
    sprite->heart->texture = \
    CREATE_TEXTURE("res/img/heart.png", NULL);
    sprite->skeleton->sp = sfSprite_create();
    sprite->heart->sp = sfSprite_create();
    sprite->slime->sp = sfSprite_create();
    sprite->sign->sp = sfSprite_create();
    sprite->background->back_sp = sfSprite_create();
}

void init_textures(display_t *sprite)
{
    background_t *back = sprite->background;

    sfSprite_setTexture(sprite->skeleton->sp, sprite->skeleton->texture, 0);
    sfSprite_setTexture(sprite->slime->sp, sprite->slime->texture, 0);
    sfSprite_setTexture(back->back_sp, back->back_texture, 0);
    sfSprite_setTexture(sprite->sign->sp, sprite->sign->texture, 0);
    sfSprite_setTexture(sprite->heart->sp, sprite->heart->texture, 0);
}

void init_scales(display_t *sprite)
{
    sprite->skeleton->scale.x = 2.7;
    sprite->skeleton->scale.y = 2.7;
    sprite->slime->scale.x = -3;
    sprite->slime->scale.y = 3;
    sprite->sign->scale.x = 0.06;
    sprite->sign->scale.y = 0.05;
    sprite->background->back_scale.x = 2.1;
    sprite->background->back_scale.y = 1.725;
    sprite->heart->scale = (sfVector2f) {0.1, 0.1};
    sfSprite_setScale(sprite->skeleton->sp, sprite->skeleton->scale);
    sfSprite_setScale(sprite->heart->sp, sprite->heart->scale);
    sfSprite_setScale(sprite->slime->sp, sprite->slime->scale);
    sfSprite_setScale(sprite->sign->sp, sprite->sign->scale);
    sfSprite_setScale(sprite->background->back_sp,\
    sprite->background->back_scale);
    sfSprite_setColor(sprite->slime->sp, (sfColor) {200, 200, 255, 255});
}

void init_rect(display_t *enemy)
{
    enemy->skeleton->rect.top = 128;
    enemy->skeleton->rect.left = 0;
    enemy->skeleton->rect.width = 64;
    enemy->skeleton->rect.height = 64;
    enemy->slime->rect.top = 0;
    enemy->slime->rect.left = 0;
    enemy->slime->rect.width = 32;
    enemy->slime->rect.height = 32;
}

void init_rect_scaled(display_t *display)
{
    display->skeleton->rect_scaled = (sfFloatRect) \
    {.top = sfSprite_getPosition(display->skeleton->sp).y,
    .left = sfSprite_getPosition(display->skeleton->sp).x,
    .width = display->skeleton->rect.width * 2,
    .height = display->skeleton->rect.height * 2};
    display->slime->rect_scaled = (sfFloatRect) \
    {.top = sfSprite_getPosition(display->slime->sp).y,
    .left = sfSprite_getPosition(display->slime->sp).x - 64,
    .width = display->slime->rect.width * 3,
    .height = display->slime->rect.height * 3};
}
