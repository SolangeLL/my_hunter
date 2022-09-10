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
        browseSlimesAnim(game);
        browseSkeletonAnim(game);
        moveSkeletons(game);
        moveSlimes(game);
        // respawn_slime(game);
        killMissedEnemies(game);
        draw_all(game);
    }
    sfSound_pause(game->sound->game);
}
