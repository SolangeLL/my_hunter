/*
** EPITECH PROJECT, 2022
** struct
** File description:
** Regroup all the structures
*/

#ifndef STRUCT_H_
#define STRUCT_H_
#include "includes.h"

struct game_s;

enum SCENES
{
    MENU,
    SETTINGS,
    GAME,
    QUIT
};

enum TEMPLATES
{
    GENERAL,
    AUDIO,
    GRAPHICS
};

enum FONTS
{
    PIXELED,
    GOLDEN_AGE,
    CREAM,
    END,
};

typedef struct resolution_s
{
    int width;
    int height;
    sfUint32 style;
} resolution_t;

typedef struct button_s
{
    int pressed;
    int modifValue;
    int linkedText;
    sfSprite *sprite;
    sfTexture *texture;
    sfFloatRect btn_rect;
    sfVector2f scale;
    sfVector2f pos;
    sfColor color;
    void (*callback)(struct game_s *game, struct button_s *btn);
    void (*modifSound)(struct game_s *game, struct button_s *btn, int val);
} button_t;

typedef struct text_button_s
{
    int pressed;
    int template;
    int framerate;
    sfText *text;
    sfFont *font;
    sfFloatRect hitbox;
    sfVector2f pos;
    sfColor color;
    resolution_t resolution;
    void (*callback)(struct game_s *game, struct text_button_s *btn);
} text_button_t;

typedef struct heart_s
{
    sfSprite *sp;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} heart_t;

typedef struct skeleton_s
{
    int id;
    int shoot;
    float moveSec;
    float animSec;
    sfTexture *texture;
    sfSprite *sp;
    sfVector2f pos;
    sfIntRect rect;
    sfFloatRect rect_scaled;
    sfVector2f scale;
    struct skeleton_s *next;
} skeleton_t;

typedef struct slime_s
{
    int id;
    int shoot;
    float wave;
    float moveSec;
    float animSec;
    sfTexture *texture;
    sfTexture *death_texture;
    sfSprite *sp;
    sfColor color;
    sfVector2f pos;
    sfIntRect rect;
    sfFloatRect rect_scaled;
    sfVector2f scale;
    struct slime_s *next;
} slime_t;

typedef struct enemies_s
{
    int idSkeleton;
    int idSlime;
    int nbEnemies;
    int kills;
    int coef;
    float spawnEnemies;
    skeleton_t *skeletons;
    slime_t *slimes;
} enemies_t;

typedef struct sign_s
{
    char *bestScore;
    sfSprite *sp;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f text_pos;
    sfVector2f scale;
    sfFont *font;
    sfText *count;
    sfText *bestScoreTxt;
} sign_t;

typedef struct background_s
{
    sfTexture *back_texture;
    sfSprite *back_sp;
    sfVector2f back_scale;
    sfVector2f back_pos;
} background_t;

typedef struct display_s
{
    heart_t **heart;
    sign_t *sign;
    background_t *background;
    sfFont *fonts[4];
} display_t;

typedef struct animation_s
{
    sfClock *clock;
    sfTime time;
    float seconds;
    float spawnSec;
} animation_t;

typedef struct window_s
{
    sfVector2f dimension;
    sfRenderWindow *win;
    sfVideoMode mode;
    int isFullscreen;
    int framerate;
} window_t;

typedef struct gameplay_s
{
    bool isScoreBetter;
    int count;
    int life;
    sfFloatRect mouse_rect;
    sfFloatRect pos_rect;
    sfEvent event;
} gameplay_t;

typedef struct sound_s
{
    bool isMute;
    int master_volume;
    int music_volume;
    int effects_volume;
    sfSoundBuffer *skel_death_buf;
    sfSoundBuffer *slime_buf;
    sfSoundBuffer *game_buf;
    sfSoundBuffer *click_buf;
    sfSoundBuffer *click2_buf;
    sfSoundBuffer *miss_buf;
    sfSoundBuffer *highScoreBuf;
    sfSoundBuffer *levelUpBuf;
    sfSoundBuffer *menuBuf;
    sfSound *slime_death;
    sfSound *skel_death;
    sfSound *game;
    sfSound *click;
    sfSound *click2;
    sfSound *miss;
    sfSound *highScore;
    sfSound *levelUp;
    sfSound *menu;
} sound_t;

typedef struct menu_s
{
    sfSprite *back_sp;
    sfTexture *back_texture;
    button_t **btn;
} menu_t;

typedef struct template_s
{
    sfText **texts;
    button_t **btn;
    text_button_t **text_btn;
} template_t;

typedef struct settings_s
{
    int templateIndex;
    sfSprite *back_sp;
    sfSprite *titles_sp;
    sfSprite *content_sp;
    sfTexture *back_texture;
    sfTexture *titles_texture;
    sfTexture *content_texture;
    sfVector2f titles_pos;
    sfVector2f titles_scale;
    sfVector2f content_pos;
    sfVector2f content_scale;
    text_button_t **text_btn;
    template_t **templates;
} settings_t;

typedef struct game_s
{
    int scene;
    window_t *win;
    sound_t *sound;
    display_t *display;
    gameplay_t *gameplay;
    enemies_t *enemies;
    animation_t *animation;
    menu_t *menu;
    settings_t *settings;
} game_t;

#endif /* !STRUCT_H_ */
