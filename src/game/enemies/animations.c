/*
** EPITECH PROJECT, 2021
** animations
** File description:
** Functions converning animations
*/

#include "../../../include/my_hunter.h"

void move_skeleton_rect(game_t *game, int max_value, int increment)
{
    game->display->skeleton->rect.left += increment;
    if (game->display->skeleton->rect.left >= max_value)
        game->display->skeleton->rect.left = 0;
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

    anim->time = sfClock_restart(anim->clock);
    anim->seconds = anim->time.microseconds / 1000000.0;
    anim->sec_slime += anim->seconds;
    anim->secSkeleton += anim->seconds;
}

void do_slime_animation(game_t *game)
{
    int shoot = game->display->slime->shoot;

    if (game->animation->sec_slime > 0.1 && shoot == 0) {
            move_slime_rect(game->display->slime, 128, 32);
            game->animation->sec_slime -= 0.1;
    } else if (game->animation->sec_slime > 0.1 && shoot == 1) {
            move_slime_rect(game->display->slime, 288, 32);
            game->animation->sec_slime -= 0.1;
    }
}

void do_skeleton_animation(game_t *game)
{
    int *shoot = &game->display->skeleton->shoot;
    sfSprite *skeleton_sprite = game->display->skeleton->sp;

    if (game->animation->secSkeleton > 0.075 && *shoot == 0) {
        move_skeleton_rect(game, 760, 64);
        game->animation->secSkeleton -= 0.075;
    } else if (game->animation->secSkeleton > 0.075 && *shoot == 1) {
        game->animation->secSkeleton -= 0.075;
        game->display->skeleton->rect.left += 64;
        if (game->display->skeleton->rect.left > 832) {
            *shoot = 0;
            game->display->skeleton->rect.top = 128;
            game->display->skeleton->rect.left = 0;
            sfSprite_setPosition(skeleton_sprite, (sfVector2f) {-200, 795});
        }
    }
}
