/*
** EPITECH PROJECT, 2021
** event
** File description:
** Functions about events
*/

#include "../../../include/my_hunter.h"

int shoot_slime(game_t *game)
{
    slime_t *slime = game->enemies->slimes;

    for (; slime != NULL; slime = slime->next) {
        slime->rect_scaled.top = sfSprite_getPosition(slime->sp).y;
        slime->rect_scaled.left = sfSprite_getPosition(slime->sp).x - 32;
        if (CLICK_ON_SLIME) {
            slime->shoot = 1;
            game->gameplay->count++;
            refresh_count(game);
            sfSound_play(game->sound->slime_death);
            sfSprite_setTexture(slime->sp, slime->death_texture, 0);
            return (1);
        }
    }
    return (0);
}

static void updateValues(game_t *game)
{
    game->enemies->nbEnemies--;
    game->enemies->coef++;
    game->enemies->kills++;
    game->gameplay->count++;
}

int shoot_skeleton(game_t *game)
{
    skeleton_t *tmp = game->enemies->skeletons;

    for (; tmp != NULL; tmp = tmp->next) {
        tmp->rect_scaled.top = sfSprite_getPosition(tmp->sp).y;
        tmp->rect_scaled.left = sfSprite_getPosition(tmp->sp).x;
        if (CLICK_ON_SKELETON) {
            tmp->shoot = 1;
            updateValues(game);
            refresh_count(game);
            sfSound_play(game->sound->skel_death);
            tmp->rect.top = 64;
            tmp->rect.left = 0;
            return (1);
        }
    }
    return (0);
}

void shoot(game_t *game)
{
    if (shoot_slime(game) == 0 && shoot_skeleton(game) == 0) {
        game->gameplay->life--;
        sfSound_play(game->sound->miss);
    }
    // //TODO! Replace this condition with shoot slime
    // if (shoot_skeleton(game) == 0) {
    //     game->gameplay->life--;
    //     sfSound_play(game->sound->miss);
    // }
    if (game->gameplay->life <= 0)
        game->scene = MENU;
}

void analyse_events(game_t *game)
{
    while (IS_EVENT) {
        if (game->gameplay->event.type == sfEvtClosed)
            sfRenderWindow_close(game->win->win);
            // game->scene = QUIT;
        if (ESCAPE_IS_PRESSED)
            game->scene = MENU;
        if (game->gameplay->event.type == sfEvtMouseButtonReleased)
            shoot(game);
    }
}
