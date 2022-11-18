#include "../../include/my_hunter.h"

void initTextButton(text_button_t *btn, char *str, sfVector2f pos, sfColor color)
{
    btn->text = sfText_create();
    btn->font = sfFont_createFromFile("res/fonts/Pixeled.ttf");
    btn->pos = pos;
    btn->color = color;
    btn->pressed = 0;
    sfText_setString(btn->text, str);
    sfText_setFont(btn->text, btn->font);
    sfText_setCharacterSize(btn->text, 50);
    sfText_setPosition(btn->text, btn->pos);
    sfText_setColor(btn->text, btn->color);
    sfText_setOrigin(btn->text, (sfVector2f){sfText_getGlobalBounds(btn->text).width / 2, sfText_getGlobalBounds(btn->text).height / 2});
    btn->rect = sfText_getGlobalBounds(btn->text);
}

void initSettingsTextButtons(settings_t *settings)
{
    settings->text_btn = malloc(sizeof(text_button_t *) * 4);
    settings->text_btn[0] = malloc(sizeof(text_button_t));
    settings->text_btn[1] = malloc(sizeof(text_button_t));
    settings->text_btn[2] = malloc(sizeof(text_button_t));
    settings->text_btn[3] = NULL;
    initTextButton(settings->text_btn[0], "General", SF2F{322, 150}, sfWhite);
    initTextButton(settings->text_btn[1], "Sound", SF2F{322, 300}, sfWhite);
    initTextButton(settings->text_btn[2], "Graphics", SF2F{322, 450}, sfWhite);
    settings->text_btn[0]->template = GENERAL;
    settings->text_btn[1]->template = AUDIO;
    settings->text_btn[2]->template = GRAPHICS;}

void initScenesTextButtons(game_t *game)
{
    initSettingsTextButtons(game->settings);
}
