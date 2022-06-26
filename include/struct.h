/*
** EPITECH PROJECT, 2022
** struct
** File description:
** Regroup all the structures
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct heart_s {
    sfSprite *sp;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} heart_t;

typedef struct skeleton_s {
    int shoot;
    sfTexture *texture;
    sfSprite *sp;
    sfVector2f pos;
    sfIntRect rect;
    sfFloatRect rect_scaled;
    sfVector2f scale;
} skeleton_t;

typedef struct slime_s {
    int shoot;
    int alpha;
    float wave;
    sfTexture *texture;
    sfTexture *death_texture;
    sfSprite *sp;
    sfVector2f pos;
    sfIntRect rect;
    sfFloatRect rect_scaled;
    sfVector2f scale;
} slime_t;

typedef struct sign_s {
    char *char_count;
    sfSprite *sp;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f text_pos;
    sfVector2f scale;
    sfFont *font;
    sfText *count;
} sign_t;

typedef struct background_s {
    sfTexture *back_texture;
    sfSprite *back_sp;
    sfVector2f back_scale;
    sfVector2f back_pos;
} background_t;

typedef struct display_s {
    skeleton_t *skeleton;
    heart_t *heart;
    sign_t *sign;
    slime_t *slime;
    background_t *background;
} display_t;

typedef struct animation_s {
    sfClock *clock;
    sfTime time;
    float seconds;
    sfClock *slime_clk;
    sfTime slime_time;
    float sec_slime;
} animation_t;

typedef struct window_s {
    sfVector2f dimension;
    sfRenderWindow* window;
    sfVideoMode mode;
} window_t;

typedef struct gameplay_s {
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
    sfSound *slime_death;
    sfSound *skel_death;
    sfSound *game;
} sound_t;

typedef struct game_s {
    window_t *window;
    sound_t *sound;
    display_t *display;
    gameplay_t *gameplay;
    animation_t *animation;
} game_t;

#endif /* !STRUCT_H_ */
