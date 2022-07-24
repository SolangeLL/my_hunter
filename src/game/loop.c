/*
** EPITECH PROJECT, 2022
** loop
** File description:
** Game loop
*/

#include "../../include/my_hunter.h"
static void prepareGameScene(game_t *game)
{
    sfSound_play(game->sound->game);
    game->animation->clock = sfClock_create();
}

void game_loop(game_t *game)
{
    prepareGameScene(game);
    while (game->scene == GAME \
    && game->gameplay->life > 0)
    {
        get_mouse_hitbox(game);
        analyse_events(game);
        get_seconds(game);
        spawn_enemy(game->enemies, game->animation);
        do_slime_animation(game);
        // do_skeleton_animation(game);
        browseSkeletonAnim(game);
        move_skeleton(game);
        // move_slime(game);
        respawn_slime(game);
        respawn_skeleton(game);
        set_TextRect_and_clear(game);
        draw_all(game);
    }
    printf("%d", game->scene);
    sfSound_pause(game->sound->game);
}
