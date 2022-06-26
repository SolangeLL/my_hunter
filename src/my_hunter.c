/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** Main game functions
*/

#include "../include/my_hunter.h"

void init_scenes_tab(void (*scene_loop[]) (game_t *))
{
    scene_loop[MENU] = &menu_loop;
    scene_loop[GAME] = &game_loop;
}

void my_hunter(void)
{
    game_t *game = malloc(sizeof(game_t));
    void (*scene_loop[2]) (game_t *);

    init_all(game);
    init_scenes_tab(scene_loop);
    while (game->scene != QUIT)
        scene_loop[game->scene](game);
    destroy_all(game);
}
