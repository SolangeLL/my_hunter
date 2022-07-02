/*
** EPITECH PROJECT, 2021
** display
** File description:
** Functions concerning display
*/

#include "../../../include/my_hunter.h"

void set_TextRect_and_clear(game_t *game)
{
    display_t *disp = game->display;

    sfSprite_setTextureRect(disp->skeleton->sp, disp->skeleton->rect);
    sfSprite_setTextureRect(disp->slime->sp, disp->slime->rect);
    sfRenderWindow_clear(game->win->win, sfBlack);
}

void draw_all(game_t *game)
{
    sfRenderWindow *window = game->win->win;
    display_t *disp = game->display;

    sfRenderWindow_drawSprite(window, disp->background->back_sp, NULL);
    sfRenderWindow_drawSprite(window,disp->skeleton->sp, NULL);
    sfRenderWindow_drawSprite(window, disp->slime->sp, NULL);
    sfRenderWindow_drawSprite(window, disp->sign->sp, NULL);
    for (int i = 0; i < game->gameplay->life; i++)
        sfRenderWindow_drawSprite(window, disp->heart[i]->sp, NULL);
    sfRenderWindow_drawText(window, disp->sign->count, NULL);
    sfRenderWindow_display(game->win->win);
}
