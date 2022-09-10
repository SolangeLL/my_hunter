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

void gameLoop(game_t *game)
{
    prepareGameScene(game);
    while (game->scene == GAME \
    && game->gameplay->life > 0)
    {
        getMouseHitbox(game);
        analyzeGameEvents(game);
        getSeconds(game);
        spawnEnemies(game->enemies, game->animation);
        browseEnemiesAnim(game);
        moveEnemies(game);
        killMissedEnemies(game);
        drawGame(game);
    }
    sfSound_pause(game->sound->game);
}
