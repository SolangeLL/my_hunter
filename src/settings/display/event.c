#include "../../../include/my_hunter.h"

static void manageButtons(game_t *game)
{
    text_button_t **txt_btn = game->settings->text_btn;

    for (int i = 0; game->settings->text_btn[i] != NULL; i++)
        if (CLICK_ON_TXT_BUTTON)
            txt_btn[i]->callback(game, txt_btn[i]);
}

void manageSettingsEvents(game_t *game)
{
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
            darkenButton(game->menu->btn, game->gameplay->mouse_rect);
        if (CLICK_IS_DETECTED)
            manageButtons(game);
    }
    enlargeButton(game->menu->btn, game->gameplay->mouse_rect);
    resetButton(game->menu->btn, game->gameplay->mouse_rect);
}
