/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** Main game functions
*/

#include "../include/my_hunter.h"

void do_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window->window) \
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
}

int my_hunter(void)
{
    game_t *game = malloc(sizeof(game_t));

    init_all(game);
    do_loop(game);
    destroy_all(game);
    return (EXIT_SUCCESS);
}
