/*
** EPITECH PROJECT, 2022
** event
** File description:
** Manage menu event
*/

#include "../../../include/my_hunter.h"

static void manageButtons(button_t **btn, game_t *game)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (CLICK_ON_BUTTON)
            btn[i]->callback(game, btn[i]);
}

void manageMenuEvents(game_t *game)
{
    while (IS_EVENT)
    {
        if (game->gameplay->event.type == sfEvtClosed)
        {
            sfRenderWindow_close(game->win->win);
            game->scene = QUIT;
        }
        if (ESCAPE_IS_PRESSED)
        {
            sfRenderWindow_close(game->win->win);
            game->scene = QUIT;
        }
        if (CLICK_IS_PRESSED)
            darkenButton(game->menu->btn, game->gameplay->mouse_rect);
        if (CLICK_IS_DETECTED)
            manageButtons(game->menu->btn, game);
    }
    enlargeButton(game->menu->btn, game->gameplay->mouse_rect);
    resetButton(game->menu->btn, game->gameplay->mouse_rect);
}