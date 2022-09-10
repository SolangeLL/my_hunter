/*
** EPITECH PROJECT, 2022
** loop
** File description:
** Main menu loop
*/

#include "../../include/my_hunter.h"

void manage_buttons(button_t **btn, game_t *game)
{
    for (int i = 0; btn[i] != NULL; i++)
        if (CLICK_ON_BUTTON)
            btn[i]->change_scene(btn[i], game->sound->click, &game->scene);
}

void manage_events(game_t *game)
{
    while (IS_EVENT) {
        if (game->gameplay->event.type == sfEvtClosed)
            sfRenderWindow_close(game->win->win);
        if (ESCAPE_IS_PRESSED)
            game->scene = QUIT;
        if (CLICK_IS_PRESSED)
            darkenButton(game->menu->btn, game->gameplay->mouse_rect);
        if (CLICK_IS_DETECTED)
            manage_buttons(game->menu->btn, game);
    }
    enlargeButton(game->menu->btn, game->gameplay->mouse_rect);
    setNormalButton(game->menu->btn, game->gameplay->mouse_rect);
}

void menuLoop(game_t *game)
{
    while (game->scene == MENU)
    {
        getMouseHitbox(game);
        manage_events(game);
        drawMenu(game);
    }
}