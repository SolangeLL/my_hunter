#include "../../../include/my_hunter.h"

void drawSettings(game_t *game)
{
    sfRenderWindow_clear(game->win->win, (sfColor)sfBlack);
    sfRenderWindow_display(game->win->win);
}
