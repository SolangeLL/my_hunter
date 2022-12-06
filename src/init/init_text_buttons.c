#include "../../include/my_hunter.h"

text_button_t *initTextButton(char *str, sfVector3f info, sfColor color, sfFont *font)
{
    text_button_t *btn = malloc(sizeof(text_button_t));
    btn->text = sfText_create();
    btn->font = font;
    btn->pos = SF2F{info.x, info.y};
    btn->color = color;
    btn->pressed = 0;
    sfText_setString(btn->text, str);
    sfText_setFont(btn->text, btn->font);
    sfText_setCharacterSize(btn->text, 50);
    sfText_setPosition(btn->text, btn->pos);
    sfText_setColor(btn->text, btn->color);
    sfText_setCharacterSize(btn->text, info.z);
    sfText_setOrigin(btn->text, (sfVector2f){sfText_getGlobalBounds(btn->text).width / 2, sfText_getGlobalBounds(btn->text).height / 2});
    btn->hitbox = sfText_getGlobalBounds(btn->text);
    return btn;
}

void initSettingsTextButtons(settings_t *settings, sfFont *font)
{
    settings->text_btn = malloc(sizeof(text_button_t *) * 4);
    settings->text_btn[0] = initTextButton("General", (sfVector3f){322, 150, 50}, sfWhite, font);
    settings->text_btn[1] = initTextButton("Sound", (sfVector3f){322, 300, 50}, sfWhite, font);
    settings->text_btn[2] = initTextButton("Graphics", (sfVector3f){322, 450, 50}, sfWhite, font);
    settings->text_btn[3] = NULL;

    settings->text_btn[0]->template = GENERAL;
    settings->text_btn[1]->template = AUDIO;
    settings->text_btn[2]->template = GRAPHICS;
}

void initScenesTextButtons(game_t *game)
{
    initSettingsTextButtons(game->settings, game->display->fonts[PIXELED]);
}
