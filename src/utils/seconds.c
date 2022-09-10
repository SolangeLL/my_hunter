/*
** EPITECH PROJECT, 2022
** seconds
** File description:
** Get seconds through each frame
*/

#include "../../include/my_hunter.h"

void getSeconds(game_t *game)
{
    animation_t *anim = game->animation;
    skeleton_t *tmpSkeleteton = game->enemies->skeletons;
    slime_t *tmpSlime = game->enemies->slimes;

    anim->time = sfClock_restart(anim->clock);
    anim->seconds = anim->time.microseconds / 1000000.0;
    anim->spawnSec += anim->seconds;
    for (; tmpSkeleteton != NULL; tmpSkeleteton = tmpSkeleteton->next) {
        tmpSkeleteton->animSec += anim->seconds;
        tmpSkeleteton->moveSec += anim->seconds;
    }
    for (; tmpSlime != NULL; tmpSlime = tmpSlime->next) {
        tmpSlime->animSec += anim->seconds;
        tmpSlime->moveSec += anim->seconds;
    }
}
