#include "../../include/my_hunter.h"

static sfText *createText(char *str, sfVector2f pos, sfColor color, sfFont *font, int size)
{
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setColor(text, color);
    sfText_setOrigin(text, (sfVector2f){sfText_getLocalBounds(text).width / 2,
                                        sfText_getLocalBounds(text).height / 2});
    return text;
}

static template_t *initGeneralTemplate(sfFont *font)
{
    template_t *template = malloc(sizeof(template_t));
    template->btn = malloc(sizeof(button_t *) * 1);
    template->btn[0] = NULL;
    template->texts = malloc(sizeof(sfText *) * 1);
    template->texts[0] = NULL;
    template->text_btn = malloc(sizeof(text_button_t *) * 1);
    template->text_btn[0] = NULL;
    return template;
}

static template_t *initAudioTemplate(sfFont *font)
{
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
    template->btn[0]->modifSound = &updateMasterVolume;
    template->btn[1]->modifSound = &updateMasterVolume;
    template->btn[2]->modifSound = &updateMusicVolume;
    template->btn[3]->modifSound = &updateMusicVolume;
    template->btn[4]->modifSound = &updateEffectsVolume;
    template->btn[5]->modifSound = &updateEffectsVolume;

    template->btn[0]->modifValue = -10;
    template->btn[1]->modifValue = 10;
    template->btn[2]->modifValue = -10;
    template->btn[3]->modifValue = 10;
    template->btn[4]->modifValue = -10;
    template->btn[5]->modifValue = 10;

    template->btn[0]->linkedText = 1;
    template->btn[1]->linkedText = 1;
    template->btn[2]->linkedText = 3;
    template->btn[3]->linkedText = 3;
    template->btn[4]->linkedText = 5;
    template->btn[5]->linkedText = 5;

    template->texts = malloc(sizeof(sfText *) * 7);
    template->texts[0] = createText("Master", SF2F{1256, 200}, (sfColor){12, 133, 9, 255}, font, 70);
    template->texts[1] = createText("100", SF2F{1256, 290}, sfWhite, font, 60);
    template->texts[2] = createText("Music", SF2F{1256, 450}, (sfColor){12, 133, 9, 255}, font, 70);
    template->texts[3] = createText("100", SF2F{1256, 540}, sfWhite, font, 60);
    template->texts[4] = createText("Effects", SF2F{1256, 700}, (sfColor){12, 133, 9, 255}, font, 70);
    template->texts[5] = createText("100", SF2F{1256, 790}, sfWhite, font, 60);
    template->texts[6] = NULL;

    template->text_btn = malloc(sizeof(text_button_t *) * 1);
    template->text_btn[0] = NULL;
    return template;
}

static template_t *initGraphicsTemplate(sfFont *font)
{
    template_t *template = malloc(sizeof(template_t));
    template->btn = malloc(sizeof(button_t *) * 1);
    template->btn[0] = NULL;

    template->text_btn = malloc(sizeof(text_button_t *) * 4);
    template->text_btn[0] = malloc(sizeof(text_button_t));
    template->text_btn[1] = malloc(sizeof(text_button_t));
    template->text_btn[2] = malloc(sizeof(text_button_t));
    initTextButton(template->text_btn[0], "1920x1080", (sfVector3f){900, 300, 30}, sfWhite);
    initTextButton(template->text_btn[1], "800x600", (sfVector3f){1256, 300, 30}, sfWhite);
    initTextButton(template->text_btn[2], "Fullscreen", (sfVector3f){1612, 300, 30}, sfWhite);
    template->text_btn[0]->resolution = (resolution_t) {1920, 1080, sfDefaultStyle};
    template->text_btn[1]->resolution = (resolution_t) {800, 600, sfDefaultStyle};
    template->text_btn[3] = NULL;

    template->text_btn[0]->callback = &changeWindow;
    template->text_btn[1]->callback = &changeWindow;
    template->text_btn[2]->callback = &setFullscreen;

    template->texts = malloc(sizeof(sfText *) * 2);
    template->texts[0] = createText("Resolution", SF2F{1256, 200}, (sfColor){12, 133, 9, 255}, font, 70);
    template->texts[1] = NULL;
    return template;
}

void initTemplates(game_t *game)
{
    sfFont *font = sfFont_createFromFile("res/fonts/Golden Age.ttf");
    game->settings->templates = malloc(sizeof(template_t *) * 4);
    game->settings->templates[0] = initGeneralTemplate(font);
    game->settings->templates[1] = initAudioTemplate(font);
    game->settings->templates[2] = initGraphicsTemplate(font);
    game->settings->templates[3] = NULL;
}
