#include "../../../include/my_hunter.h"

static void manageButtons(game_t *game)
{
    text_button_t **txt_btn = game->settings->text_btn;
    text_button_t **template_txt_btn = game->settings->templates[game->settings->templateIndex]->text_btn;
    button_t **btn = game->settings->templates[game->settings->templateIndex]->btn;

    for (int i = 0; game->settings->text_btn[i] != NULL; i++)
        if (CLICK_ON_TXT_BUTTON)
            txt_btn[i]->callback(game, txt_btn[i]);
    for (int i = 0; template_txt_btn[i] != NULL; i++)
        if (CLICK_ON_TEMPLATE_TXT_BUTTON)
            template_txt_btn[i]->callback(game, template_txt_btn[i]);
    for (int i = 0; btn[i] != NULL; i++)
        if (CLICK_ON_BUTTON)
            btn[i]->modifSound(game, btn[i], btn[i]->modifValue);
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
        {
            darkenButton(btn, game->gameplay->mouse_rect);
            darkenText(game->settings->text_btn, game->gameplay->mouse_rect);
            darkenText(game->settings->templates[game->settings->templateIndex]->text_btn, game->gameplay->mouse_rect);
        }
        if (CLICK_IS_DETECTED)
            manageButtons(game);
    }
    enlargeButton(btn, game->gameplay->mouse_rect);
    enlargeText(game->settings->text_btn, game->gameplay->mouse_rect);
    enlargeText(game->settings->templates[game->settings->templateIndex]->text_btn, game->gameplay->mouse_rect);
    resetButton(btn, game->gameplay->mouse_rect);
    resetText(game->settings->text_btn, game->gameplay->mouse_rect);
    resetText(game->settings->templates[game->settings->templateIndex]->text_btn, game->gameplay->mouse_rect);
}
