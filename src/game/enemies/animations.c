/*
** EPITECH PROJECT, 2021
** animations
** File description:
** Functions converning animations
*/

#include "../../../include/my_hunter.h"

static void moveRect(sfIntRect *rect, int max, int increment)
{
    (*rect).left += increment;
    if ((*rect).left >= max)
        (*rect).left = 0;
}

static void doSlimeAnim(slime_t *slime)
{
    while (slime->animSec > 0.09) {
        if (slime->shoot == 0) {
            moveRect(&(slime->rect), 128, 32);
            slime->animSec -= 0.09;
        } else {
            moveRect(&(slime->rect), 288, 32);
            slime->animSec -= 0.09;
        }
    }
    sfSprite_setTextureRect(slime->sp, slime->rect);
}

static int doSkeletonAnim(skeleton_t *skeleton)
{
    while (skeleton->animSec > 0.065) {
        if (skeleton->shoot == 0) {
            moveRect(&(skeleton->rect), 760, 64);
            skeleton->animSec -= 0.065;
        } else {
            skeleton->animSec -= 0.065;
            skeleton->rect.left += 64;
            if (skeleton->rect.left > 832) {
                //? Return 1 if can delete enemy
                sfSprite_setTextureRect(skeleton->sp, skeleton->rect);
                return 1;
            }
        }
    }
    sfSprite_setTextureRect(skeleton->sp, skeleton->rect);
    return 0;
}

static void browseSkeletonAnim(game_t *game)
{
    skeleton_t *tmp = game->enemies->skeletons;

    for (int i = 1; tmp != NULL; tmp = tmp->next, i++) {
        if (doSkeletonAnim(tmp)) {
            deleteSkeleton(&(game->enemies->skeletons), tmp->id);
            break;
        }
    }
}

static void browseSlimesAnim(game_t *game)
{
    slime_t *tmp = game->enemies->slimes;

    for (int i = 1; tmp != NULL; tmp = tmp->next, i++)
        doSlimeAnim(tmp);
}

void browseEnemiesAnim(game_t *game)
{
    browseSkeletonAnim(game);
    browseSlimesAnim(game);
}
