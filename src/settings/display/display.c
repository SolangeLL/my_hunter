#include "../../../include/my_hunter.h"

void drawTemplate(template_t *template, sfRenderWindow *window)
{
    for (int i = 0; template->btn[i] != NULL; i++)
        sfRenderWindow_drawSprite(window, template->btn[i]->sprite, NULL);
    for (int i = 0; template->text_btn[i] != NULL; i++)
        sfRenderWindow_drawText(window, template->text_btn[i]->text, NULL);
    if (template->texts != NULL)
        for (int i = 0; template->texts[i] != NULL; i++)
            sfRenderWindow_drawText(window, template->texts[i], NULL);
}

void drawSettings(game_t *game)
{
    sfRenderWindow_clear(game->win->win, (sfColor)sfBlack);
    sfRenderWindow_drawSprite(game->win->win, game->settings->back_sp, NULL);
    sfRenderWindow_drawSprite(game->win->win, game->settings->titles_sp, NULL);
    sfRenderWindow_drawSprite(game->win->win, game->settings->content_sp, NULL);
    for (int i = 0; game->settings->text_btn[i] != NULL; i++)
        sfRenderWindow_drawText(game->win->win, game->settings->text_btn[i]->text, 0);
    drawTemplate(game->settings->templates[game->settings->templateIndex], game->win->win);
    sfRenderWindow_display(game->win->win);
}
