#include "../../../include/my_hunter.h"

static void manageButtons(game_t *game)
{
    text_button_t **txt_btn = game->settings->text_btn;
    button_t **btn = game->settings->templates[game->settings->templateIndex]->btn;

    for (int i = 0; game->settings->text_btn[i] != NULL; i++)
        if (CLICK_ON_TXT_BUTTON)
            txt_btn[i]->callback(game, txt_btn[i]);
    for (int i = 0; btn[i] != NULL; i++)
        if (CLICK_ON_BUTTON)
            btn[i]->callback(game, btn[i]);
}

void manageSettingsEvents(game_t *game)
{
    button_t **btn = game->settings->templates[game->settings->templateIndex]->btn;
    while (IS_EVENT)
    {
        if (game->gameplay->event.type == sfEvtClosed)
        {
            sfRenderWindow_close(game->win->win);
            game->scene = QUIT;
        }
        if (ESCAPE_IS_PRESSED)
            game->scene = MENU;
        if (CLICK_IS_PRESSED)
            darkenButton(btn, game->gameplay->mouse_rect);
        if (CLICK_IS_DETECTED)
            manageButtons(game);
    }
    enlargeButton(btn, game->gameplay->mouse_rect);
    resetButton(btn, game->gameplay->mouse_rect);
}
