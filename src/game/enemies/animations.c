/*
** EPITECH PROJECT, 2021
** animations
** File description:
** Functions converning animations
*/

#include "../../../include/my_hunter.h"

void move_skeleton_rect(skeleton_t *skeleton, int max_value, int increment)
{
    skeleton->rect.left += increment;
    if (skeleton->rect.left >= max_value)
        skeleton->rect.left = 0;
}

void move_slime_rect(slime_t *slime, int max, int increment)
{
    slime->rect.left += increment;
    if (slime->rect.left >= max)
        slime->rect.left = 0;
}

void get_seconds(game_t *game)
{
    animation_t *anim = game->animation;
    skeleton_t *tmpSkelteton = game->enemies->skeletons;

    anim->time = sfClock_restart(anim->clock);
    anim->seconds = anim->time.microseconds / 1000000.0;
    anim->spawnSec += anim->seconds;
    anim->sec_slime += anim->seconds;
    anim->secSkeleton += anim->seconds;
    anim->moveSkeleton += anim->seconds;
    anim->moveSlime += anim->seconds;
    for (; tmpSkelteton != NULL; tmpSkelteton = tmpSkelteton->next) {
        tmpSkelteton->animSec += anim->seconds;
        tmpSkelteton->moveSec += anim->seconds;
    }
}

void do_slime_animation(game_t *game)
{
    int shoot = game->display->slime->shoot;

    while (game->animation->sec_slime > 0.08) {
        if (shoot == 0) {
            move_slime_rect(game->display->slime, 128, 32);
            game->animation->sec_slime -= 0.08;
        } else {
            move_slime_rect(game->display->slime, 288, 32);
            game->animation->sec_slime -= 0.08;
        }
    }
}

int do_skeleton_animation(skeleton_t *skeleton)
{
    while (skeleton->animSec > 0.065) {
        if (skeleton->shoot == 0) {
            move_skeleton_rect(skeleton, 760, 64);
            skeleton->animSec -= 0.065;
        } else {
            skeleton->animSec -= 0.065;
            skeleton->rect.left += 64;
            if (skeleton->rect.left > 832) {
                //? Return 1 if can delete enemy
                sfSprite_setTextureRect(skeleton->sp, skeleton->rect);
                return 1;
                // skeleton->shoot = 0;
                // skeleton->rect.top = 128;
                // skeleton->rect.left = 0;
                // sfSprite_setPosition(skeleton->sp, (sfVector2f) {-200, 795});
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
        if (do_skeleton_animation(tmp))
            deleteNode(&(game->enemies->skeletons), tmp->id);
        if (game->enemies->skeletons == NULL)
            break;
    }
}
