/*
** EPITECH PROJECT, 2021
** spawn
** File description:
** Functions about monsters' respawn
*/

#include "../../../include/my_hunter.h"

void killMissedEnemies(game_t *game)
{
    skeleton_t *tmpSkeletons = game->enemies->skeletons;

    for (; tmpSkeletons != NULL; tmpSkeletons = tmpSkeletons->next)
        if (sfSprite_getPosition(tmpSkeletons->sp).x > 1920) {
            deleteSkeleton(&game->enemies->skeletons, tmpSkeletons->id);
            game->gameplay->life--;
            break;
        }
    //TODO When the player loses, move to end scene (Do you want to restart / leave ?) + Display highscore
    if (game->gameplay->life == 0)
        game->scene = MENU;
}
