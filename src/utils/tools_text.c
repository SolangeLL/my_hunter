#include "../../include/my_hunter.h"

void resizeText(text_button_t *text, sfVector2f scale)
{
    text->hitbox.height *= scale.y;
    text->hitbox.width *= scale.x;
    text->pos = SF2F{text->pos.x * scale.x, text->pos.y * scale.y};
    sfText_setScale(text->text, (sfVector2f){scale.x, scale.y});
}

static void colorText(text_button_t *text, int modify)
{
    sfText_setColor(text->text, (sfColor){text->color.r + modify,
                                          text->color.g + modify,
                                          text->color.b + modify,
                                          255});
}

static void setDarkText(text_button_t *text)
{
    colorText(text, -100);
    sfText_setPosition(text->text, SF2F{text->pos.x, text->pos.y});
    sfText_setScale(text->text, SF2F{1, 1});
    text->pressed = 1;
}

static void setLargeText(text_button_t *text)
{
    sfVector2f scale = SF2F{1.1, 1.1};

    sfText_setScale(text->text, scale);
    sfText_setPosition(text->text, SF2F{text->pos.x - scale.x * 0.8,
                                        text->pos.y - scale.y * 0.8});
}

void setNormalText(text_button_t *text)
{
    sfText_setColor(text->text, sfWhite);
    sfText_setScale(text->text, SF2F{1, 1});
    sfText_setPosition(text->text, SF2F{text->pos.x,
                                        text->pos.y});
    text->pressed = 0;
}

void darkenText(text_button_t **text, sfFloatRect mouse)
{
    for (int i = 0; text[i] != NULL; i++)
        if (MOUSE_OVER_TEXT && text[i]->pressed == 0)
            setDarkText(text[i]);
}

void enlargeText(text_button_t **text, sfFloatRect mouse)
{
    for (int i = 0; text[i] != NULL; i++)
        if (MOUSE_OVER_TEXT && text[i]->pressed == 0)
            setLargeText(text[i]);
}

void resetText(text_button_t **text, sfFloatRect mouse)
{
    for (int i = 0; text[i] != NULL; i++)
        if (!MOUSE_OVER_TEXT && text[i]->pressed == 0)
            setNormalText(text[i]);
}
