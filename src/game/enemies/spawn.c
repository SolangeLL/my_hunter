/*
** EPITECH PROJECT, 2021
** spawn
** File description:
** Functions about monsters' respawn
*/

#include "../../../include/my_hunter.h"

void respawn_slime(game_t *game)
{
    slime_t *slime = game->display->slime;

    if (sfSprite_getPosition(slime->sp).x > 2000) {
        slime->pos.x = -50;
        sfSprite_setPosition(slime->sp, slime->pos);
        game->gameplay->life -= 1;
    }
    if (game->gameplay->life == 0)
        game->scene = MENU;
}
void respawn_skeleton(game_t *game)
{
    skeleton_t *skeleton = game->display->skeleton;
    skeleton_t *tmp = game->enemies->skeletons;

    for (; tmp != NULL; tmp = tmp->next)
        if (sfSprite_getPosition(tmp->sp).x > 1920) {
            printf("Respawn\n");
            tmp->pos.x = -100;
            sfSprite_setPosition(tmp->sp, tmp->pos);
            game->gameplay->life -= 1;
        }
    if (game->gameplay->life == 0)
        game->scene = MENU;
}
