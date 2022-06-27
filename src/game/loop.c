/*
** EPITECH PROJECT, 2022
** loop
** File description:
** Game loop
*/

#include "../../include/my_hunter.h"

void game_loop(game_t *game)
{
    sfSound_play(game->sound->game);
    while (sfRenderWindow_isOpen(game->win->win) \
    && game->gameplay->life > 0)
    {
        get_mouse_hitbox(game);
        analyse_events(game);
        get_seconds(game);
        do_slime_animation(game);
        do_skeleton_animation(game);
        move_skeleton(game);
        move_slime(game);
        respawn_slime(game);
        respawn_skeleton(game);
        set_TextRect_and_clear(game);
        draw_all(game);
    }
    game->scene = QUIT;
}
