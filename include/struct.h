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

typedef struct button_s
{
    int pressed;
    sfSprite *sprite;
    sfTexture *texture;
    sfFloatRect btn_rect;
    sfVector2f scale;
    sfVector2f pos;
    sfColor color;
    void (*callback)(struct game_s *game, struct button_s *btn);
} button_t;

typedef struct text_button_s
{
    int pressed;
    int template;
    sfText *text;
    sfFont *font;
    sfFloatRect rect;
    sfVector2f pos;
    sfColor color;
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
    char *char_count;
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
    sfSoundBuffer *skel_death_buf;
    sfSoundBuffer *slime_buf;
    sfSoundBuffer *game_buf;
    sfSoundBuffer *click_buf;
    sfSoundBuffer *miss_buf;
    sfSoundBuffer *highScoreBuf;
    sfSoundBuffer *levelUpBuf;
    sfSoundBuffer *menuBuf;
    sfSound *slime_death;
    sfSound *skel_death;
    sfSound *game;
    sfSound *click;
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
    sfTexture *back_texture;
    sfSprite *titles_sp;
    sfTexture *titles_texture;
    sfVector2f titles_pos;
    sfVector2f titles_scale;
    sfSprite *content_sp;
    sfTexture *content_texture;
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
