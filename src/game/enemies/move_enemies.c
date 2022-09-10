/*
** EPITECH PROJECT, 2021
** move_enmies
** File description:
** Functions to move sprites
*/

#include "../../../include/my_hunter.h"

static void moveOneSkeleton(skeleton_t *skeleton)
{
    while (skeleton->moveSec > 0.015 \
    && skeleton->rect.top != 64) {
        sfSprite_move(skeleton->sp, (sfVector2f) {2, 0});
        skeleton->moveSec -= 0.015;
    }
}

static int moveOneSlime(slime_t *slime)
{
     while (slime->moveSec > 0.02) {
        if (slime->shoot == 0) {
            sfSprite_move(slime->sp, (sfVector2f) {2, sin(slime->wave)});
            slime->wave += 0.02;
            slime->moveSec -= 0.02;
        } else {
            slime->alpha -= 20;
            sfSprite_setColor(slime->sp, (sfColor) {200, 200, 255, slime->alpha});
            //* Return 1 if we can delete the slime
            if (slime->alpha <= 0)
                return (1);
            slime->moveSec -= 0.05;
        }
    }
    return (0);
}

static void moveSkeletons(game_t *game)
{
    skeleton_t *skeleton = game->enemies->skeletons;

    for (; skeleton != NULL; skeleton = skeleton->next)
        moveOneSkeleton(skeleton);
}

static void moveSlimes(game_t *game)
{
    slime_t *slime = game->enemies->slimes;

    for (; slime != NULL; slime = slime->next)
        if (moveOneSlime(slime)) {
            deleteSlime(&(game->enemies->slimes), slime->id);
            break;
        }
}

void moveEnemies(game_t *game)
{
    moveSlimes(game);
    moveSkeletons(game);
}
