/*
** EPITECH PROJECT, 2022
** init enemies
** File description:
** Initialize list of enemies
*/

#include "../../include/my_hunter.h"

skeleton_t *create_skeleton(void)
{
    skeleton_t *skeleton = malloc(sizeof(skeleton_t));

    skeleton->sp = sfSprite_create();
    skeleton->texture = CREATE_TEXTURE("res/img/Skeleton_enemy.png", NULL);
    skeleton->scale = SF2F {2.7, 2.7};
    skeleton->pos = SF2F {0, 795};
    sfSprite_setTexture(skeleton->sp, skeleton->texture, 0);
    sfSprite_setScale(skeleton->sp, skeleton->scale);
    sfSprite_setPosition(skeleton->sp, skeleton->pos);
    return skeleton;
}

slime_t *create_slime(void)
{
    slime_t *slime = malloc(sizeof(slime_t));

    slime->sp = sfSprite_create();
    slime->texture = CREATE_TEXTURE("res/img/Slime.png", NULL);
    slime->death_texture = CREATE_TEXTURE("res/img/Slime_death.png", NULL);
    slime->scale = SF2F {-3, 3};
    slime->pos = SF2F {100, 280};
    sfSprite_setTexture(slime->sp, slime->texture, 0);
    sfSprite_setScale(slime->sp, slime->scale);
    sfSprite_setPosition(slime->sp, slime->pos);
    return slime;
}
