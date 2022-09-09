/*
** EPITECH PROJECT, 2021
** animations
** File description:
** Functions converning animations
*/

#include "../../../include/my_hunter.h"

void get_seconds(game_t *game)
{
    animation_t *anim = game->animation;
    skeleton_t *tmpSkeleteton = game->enemies->skeletons;
    slime_t *tmpSlime = game->enemies->slimes;

    anim->time = sfClock_restart(anim->clock);
    anim->seconds = anim->time.microseconds / 1000000.0;
    anim->spawnSec += anim->seconds;
    anim->sec_slime += anim->seconds;
    for (; tmpSkeleteton != NULL; tmpSkeleteton = tmpSkeleteton->next) {
        tmpSkeleteton->animSec += anim->seconds;
        tmpSkeleteton->moveSec += anim->seconds;
    }
    for (; tmpSlime != NULL; tmpSlime = tmpSlime->next) {
        tmpSlime->animSec += anim->seconds;
        tmpSlime->moveSec += anim->seconds;
    }
}

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

void browseSkeletonAnim(game_t *game)
{
    skeleton_t *tmp = game->enemies->skeletons;

    for (int i = 1; tmp != NULL; tmp = tmp->next, i++) {
        if (doSkeletonAnim(tmp))
            deleteSkeleton(&(game->enemies->skeletons), tmp->id);
        if (game->enemies->skeletons == NULL)
            break;
    }
}

void browseSlimesAnim(game_t *game)
{
    slime_t *tmp = game->enemies->slimes;

    for (int i = 1; tmp != NULL; tmp = tmp->next, i++)
        doSlimeAnim(tmp);
}
