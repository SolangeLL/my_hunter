#include "../../include/my_hunter.h"

static sfText *createText(char *str, sfVector2f pos, sfColor color, sfFont *font, int size)
{
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setColor(text, color);
    sfText_setOrigin(text, (sfVector2f){sfText_getLocalBounds(text).width / 2,\
    sfText_getLocalBounds(text).height / 2});
    return text;
}

static template_t *initGeneralTemplate()
{
    template_t *template = malloc(sizeof(template_t));
    template->btn = malloc(sizeof(button_t *) * 2);
    template->btn[0] = initButton("res/img/buttons/pause.png", SF2F{1200, 340});
    template->btn[1] = NULL;
    resizeButton(template->btn[0], SF2F{10, 10});

    template->texts = NULL;
    template->text_btn = NULL;
    return template;
}

static template_t *initAudioTemplate()
{
    sfFont *font = sfFont_createFromFile("res/fonts/Golden Age.ttf");
    template_t *template = malloc(sizeof(template_t));
    template->btn = malloc(sizeof(button_t *) * 7);
    template->btn[0] = initButton("res/img/buttons/resume.png", SF2F{1120, 280});
    template->btn[1] = initButton("res/img/buttons/resume.png", SF2F{1390, 280});
    template->btn[2] = initButton("res/img/buttons/resume.png", SF2F{1120, 530});
    template->btn[3] = initButton("res/img/buttons/resume.png", SF2F{1390, 530});
    template->btn[4] = initButton("res/img/buttons/resume.png", SF2F{1120, 780});
    template->btn[5] = initButton("res/img/buttons/resume.png", SF2F{1390, 780});
    template->btn[6] = NULL;
    resizeButton(template->btn[0], SF2F{-4, 4});
    resizeButton(template->btn[1], SF2F{4, 4});
    resizeButton(template->btn[2], SF2F{-4, 4});
    resizeButton(template->btn[3], SF2F{4, 4});
    resizeButton(template->btn[4], SF2F{-4, 4});
    resizeButton(template->btn[5], SF2F{4, 4});

    template->texts = malloc(sizeof(sfText *) * 7);
    template->texts[0] = createText("Master", SF2F{1256, 200}, (sfColor) {12, 133, 9, 255}, font, 70);
    template->texts[1] = createText("100", SF2F{1256, 290}, sfWhite, font, 60);
    template->texts[2] = createText("Music", SF2F{1256, 450}, (sfColor) {12, 133, 9, 255}, font, 70);
    template->texts[3] = createText("100", SF2F{1256, 540}, sfWhite, font, 60);
    template->texts[4] = createText("Sound", SF2F{1256, 700}, (sfColor) {12, 133, 9, 255}, font, 70);
    template->texts[5] = createText("100", SF2F{1256, 790}, sfWhite, font, 60);
    template->texts[6] = NULL;

    template->text_btn = NULL;
    return template;
}

static template_t *initGraphicsTemplate()
{
    template_t *template = malloc(sizeof(template_t));
    template->btn = malloc(sizeof(button_t *) * 2);
    template->btn[0] = initButton("res/img/buttons/yes.png", SF2F{1400, 400});
    template->btn[1] = NULL;
    resizeButton(template->btn[0], SF2F{10, 10});

    template->texts = NULL;
    template->text_btn = NULL;
    return template;
}

void initTemplates(game_t *game)
{
    game->settings->templates = malloc(sizeof(template_t *) * 4);
    game->settings->templates[0] = initGeneralTemplate();
    game->settings->templates[1] = initAudioTemplate();
    game->settings->templates[2] = initGraphicsTemplate();
    game->settings->templates[3] = NULL;
}
