#include "../../include/my_hunter.h"

void initTextButton(text_button_t *btn, char *str, sfVector2f pos, sfColor color)
{
    btn->text = sfText_create();
    btn->font = sfFont_createFromFile("res/txt/Minercraftory.ttf");
    btn->pos = pos;
    btn->color = color;
    btn->pressed = 0;
    sfText_setString(btn->text, str);
    sfText_setFont(btn->text, btn->font);
    sfText_setCharacterSize(btn->text, 50);
    sfText_setPosition(btn->text, btn->pos);
    sfText_setColor(btn->text, btn->color);
    btn->btn_rect = (sfFloatRect){pos.x, pos.y, 0, 0};
}

void initSettingsTextButtons(settings_t *settings)
{
    settings->text_btn = malloc(sizeof(text_button_t *) * 4);
    settings->text_btn[0] = malloc(sizeof(text_button_t));
    settings->text_btn[1] = malloc(sizeof(text_button_t));
    settings->text_btn[2] = malloc(sizeof(text_button_t));
    settings->text_btn[3] = NULL;
    initTextButton(settings->text_btn[0], "General", SF2F{190, 150}, sfWhite);
    initTextButton(settings->text_btn[1], "Sound", SF2F{190, 300}, sfWhite);
    initTextButton(settings->text_btn[2], "Graphics", SF2F{190, 450}, sfWhite);
}

void initScenesTextButtons(game_t *game)
{
    initSettingsTextButtons(game->settings);
}
