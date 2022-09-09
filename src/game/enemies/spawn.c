/*
** EPITECH PROJECT, 2021
** spawn
** File description:
** Functions about monsters' respawn
*/

#include "../../../include/my_hunter.h"

// void respawn_slime(game_t *game)
// {
//     slime_t *slime = game->display->slime;

//     if (sfSprite_getPosition(slime->sp).x > 2000) {
//         slime->pos.x = -50;
//         sfSprite_setPosition(slime->sp, slime->pos);
//         game->gameplay->life--;
//     }
//     if (game->gameplay->life == 0)
//         game->scene = MENU;
// }

void killMissedEnemies(game_t *game)
{
    //TODO Kill missed slimes too
    skeleton_t *tmp = game->enemies->skeletons;

    for (; tmp != NULL; tmp = tmp->next)
        if (sfSprite_getPosition(tmp->sp).x > 1920) {
            deleteSkeleton(&game->enemies->skeletons, tmp->id);
            game->gameplay->life--;
            break;
        }
    //TODO When the player looses, move to end scene (Do you want to restart / leave ?) + Display highscore
    if (game->gameplay->life == 0)
        game->scene = MENU;
}
