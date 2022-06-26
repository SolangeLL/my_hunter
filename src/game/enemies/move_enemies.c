/*
** EPITECH PROJECT, 2021
** move_enmies
** File description:
** Functions to move sprites
*/

#include "../../../include/my_hunter.h"

void move_skeleton(game_t *game)
{
    skeleton_t *skeleton = game->display->skeleton;

    if (game->animation->seconds > 0.02 && skeleton->rect.top != 64)
        sfSprite_move(skeleton->sp, (sfVector2f) {5, 0});
}

void do_vanish_slime(slime_t *slime)
{
    if (slime->alpha <= 0) {
        slime->shoot = 0;
        slime->alpha = 255;
        sfSprite_setPosition(slime->sp, (sfVector2f) {-100, 280});
        sfSprite_setTexture(slime->sp, slime->texture, 0);
    }
}

void move_slime(game_t *game)
{
    slime_t *slime = game->display->slime;

    if (game->animation->seconds > 0.02 && slime->shoot == 0) {
        sfSprite_move(slime->sp, (sfVector2f) {5, sin(slime->wave) * 3});
        slime->wave += 0.1;
    } else if (game->animation->seconds > 0.02 && slime->shoot == 1) {
        slime->alpha -= 20;
        sfSprite_setColor(slime->sp, (sfColor) {200, 200, 255, slime->alpha});
        do_vanish_slime(slime);
    }
}
