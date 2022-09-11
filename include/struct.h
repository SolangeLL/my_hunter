/*
** EPITECH PROJECT, 2022
** struct
** File description:
** Regroup all the structures
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

enum SCENES {
    MENU, SETTINGS, GAME, QUIT
};

typedef struct button_s {
    int pressed;
    sfSprite *sprite;
    sfTexture *texture;
    sfFloatRect btn_rect;
    sfVector2f pos;
    sfColor color;
    void (*change_scene)(struct button_s *, sfSound *, int *);
    // void (*modify)(struct global_s *, int);
} button_t;

typedef struct heart_s {
    sfSprite *sp;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} heart_t;

typedef struct skeleton_s {
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

typedef struct slime_s {
    int id;
    int shoot;
    int alpha;
    float wave;
    float moveSec;
    float animSec;
    sfTexture *texture;
    sfTexture *death_texture;
    sfSprite *sp;
    sfVector2f pos;
    sfIntRect rect;
    sfFloatRect rect_scaled;
    sfVector2f scale;
    struct slime_s *next;
} slime_t;

typedef struct enemies_s {
    int idSkeleton;
    int idSlime;
    int nbEnemies;
    int kills;
    int coef;
    float spawnEnemies;
    skeleton_t *skeletons;
    slime_t *slimes;
} enemies_t;

typedef struct sign_s {
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

typedef struct background_s {
    sfTexture *back_texture;
    sfSprite *back_sp;
    sfVector2f back_scale;
    sfVector2f back_pos;
} background_t;

typedef struct display_s {
    heart_t **heart;
    sign_t *sign;
    background_t *background;
} display_t;

typedef struct animation_s {
    sfClock *clock;
    sfTime time;
    float seconds;
    float spawnSec;
} animation_t;

typedef struct window_s {
    sfVector2f dimension;
    sfRenderWindow* win;
    sfVideoMode mode;
} window_t;

typedef struct gameplay_s {
    bool isScoreBetter;
    int count;
    int life;
    sfFloatRect mouse_rect;
    sfFloatRect pos_rect;
    sfEvent event;
} gameplay_t;

typedef struct sound_s {
    sfSoundBuffer *skel_death_buf;
    sfSoundBuffer *slime_buf;
    sfSoundBuffer *game_buf;
    sfSoundBuffer *click_buf;
    sfSoundBuffer *miss_buf;
    sfSoundBuffer *highScoreBuf;
    sfSoundBuffer *levelUpBuf;
    sfSound *slime_death;
    sfSound *skel_death;
    sfSound *game;
    sfSound *click;
    sfSound *miss;
    sfSound *highScore;
    sfSound *levelUp;
} sound_t;

typedef struct menu_s {
    sfSprite *back_sp;
    sfTexture *back_texture;
    button_t **btn;
} menu_t;

typedef struct game_s {
    int scene;
    window_t *win;
    sound_t *sound;
    display_t *display;
    gameplay_t *gameplay;
    enemies_t *enemies;
    animation_t *animation;
    menu_t *menu;
} game_t;

#endif /* !STRUCT_H_ */
