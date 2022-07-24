/*
** EPITECH PROJECT, 2021
** move_enmies
** File description:
** Functions to move sprites
*/

#include "../../../include/my_hunter.h"

void move(skeleton_t *skeleton)
{
    while (skeleton->moveSec > 0.015 \
    && skeleton->rect.top != 64) {
        sfSprite_move(skeleton->sp, (sfVector2f) {2, 0});
        skeleton->moveSec -= 0.015;
    }
}

void move_skeleton(game_t *game)
{
    skeleton_t *skeleton = game->display->skeleton;
    skeleton_t *tmp = game->enemies->skeletons;

    // while (game->animation->moveSkeleton > 0.015 \
    // && skeleton->rect.top != 64) {
    //     sfSprite_move(skeleton->sp, (sfVector2f) {2, 0});
    //     game->animation->moveSkeleton -= 0.015;
    // }
    for (; tmp != NULL; tmp = tmp->next)
        move(tmp);
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

    while (game->animation->moveSlime > 0.02) {
        if (slime->shoot == 0) {
            sfSprite_move(slime->sp, (sfVector2f) {2, sin(slime->wave)});
            slime->wave += 0.02;
            game->animation->moveSlime -= 0.02;
        } else {
            slime->alpha -= 20;
            sfSprite_setColor(slime->sp, (sfColor) {200, 200, 255, slime->alpha});
            do_vanish_slime(slime);
            game->animation->moveSlime -= 0.05;
        }
    }
}
