/*
** EPITECH PROJECT, 2021
** display
** File description:
** Functions concerning display
*/

#include "../../../include/my_hunter.h"

void draw_all(game_t *game)
{
    sfRenderWindow *window = game->win->win;
    display_t *disp = game->display;
    skeleton_t *skeletons = game->enemies->skeletons;
    slime_t *slimes = game->enemies->slimes;

    sfRenderWindow_clear(game->win->win, sfBlack);
    sfRenderWindow_drawSprite(window, disp->background->back_sp, NULL);
    for (; skeletons != NULL; skeletons = skeletons->next)
        sfRenderWindow_drawSprite(window, skeletons->sp, NULL);
    for (; slimes != NULL; slimes = slimes->next)
        sfRenderWindow_drawSprite(window, slimes->sp, NULL);
    sfRenderWindow_drawSprite(window, disp->sign->sp, NULL);
    for (int i = 0; i < game->gameplay->life; i++)
        sfRenderWindow_drawSprite(window, disp->heart[i]->sp, NULL);
    sfRenderWindow_drawText(window, disp->sign->count, NULL);
    sfRenderWindow_drawText(window, disp->sign->bestScoreTxt, NULL);
    sfRenderWindow_display(game->win->win);
}
