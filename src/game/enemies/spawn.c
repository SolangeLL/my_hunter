/*
** EPITECH PROJECT, 2021
** spawn
** File description:
** Functions about monsters' respawn
*/

#include "../../../include/my_hunter.h"

void respawn_slime(game_t *game)
{
    slime_t *slime = game->display->slime;

    if (sfSprite_getPosition(slime->sp).x > 2000) {
        slime->pos.x = -50;
        sfSprite_setPosition(slime->sp, slime->pos);
    }
}
void respawn_skeleton(game_t *game)
{
    skeleton_t *skeleton = game->display->skeleton;

    if (sfSprite_getPosition(skeleton->sp).x > 1920) {
        skeleton->pos.x = -100;
        sfSprite_setPosition(skeleton->sp, skeleton->pos);
    }
}
