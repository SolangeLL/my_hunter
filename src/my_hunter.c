/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** Main game functions
*/

#include "../include/my_hunter.h"

void init_scenes_tab(void (*scene_loop[]) (game_t *))
{
    scene_loop[MENU] = &menuLoop;
    scene_loop[GAME] = &gameLoop;
    scene_loop[SETTINGS] = &settingsLoop;
}

void my_hunter(void)
{
    game_t *game = malloc(sizeof(game_t));
    void (*scene_loop[2]) (game_t *);

    initAll(game);
    init_scenes_tab(scene_loop);
    while (game->scene != QUIT)
        scene_loop[game->scene](game);
    saveBestScore(game);
    destroyAll(game);
}
