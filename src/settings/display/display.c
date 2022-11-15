#include "../../../include/my_hunter.h"

void drawSettings(game_t *game)
{
    sfRenderWindow_clear(game->win->win, (sfColor)sfBlack);
    sfRenderWindow_drawSprite(game->win->win, game->settings->back_sp, NULL);
    sfRenderWindow_drawSprite(game->win->win, game->settings->titles_sp, NULL);
    sfRenderWindow_drawSprite(game->win->win, game->settings->content_sp, NULL);
    for (int i = 0; game->settings->btn[i] != NULL; i++)
        sfRenderWindow_drawSprite(game->win->win, game->settings->btn[i]->sprite, 0);
    for (int i = 0; game->settings->text_btn[i] != NULL; i++)
        sfRenderWindow_drawText(game->win->win, game->settings->text_btn[i]->text, 0);
    sfRenderWindow_display(game->win->win);
}
