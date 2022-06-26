/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** Regroup alla variables for my_hunter
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
    #define WINDOW_INFO window->mode, "MY HUNTER", sfResize | sfClose, NULL
    #define CREATE_SOUND_BUF sfSoundBuffer_createFromFile
    #define CREATE_TEXTURE sfTexture_createFromFile
    #define IS_EVENT \
    sfRenderWindow_pollEvent(game->window->window, &game->gameplay->event)
    #define ESCAPE_IS_PRESSED game->gameplay->event.type == sfEvtKeyPressed \
    && sfKeyboard_isKeyPressed(sfKeyEscape)
    #define CLICK_ON_SLIME sfFloatRect_intersects(&slime->rect_scaled, \
    &game->gameplay->mouse_rect, NULL) == sfTrue && slime->shoot == 0
    #define CLICK_ON_SKELETON sfFloatRect_intersects(&game->display->skeleton->rect_scaled, \
    &game->gameplay->mouse_rect, NULL) == sfTrue && game->display->skeleton->shoot == 0

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics.h>

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

int my_hunter(void);
void get_mouse_hitbox(game_t *game);

void init_all(game_t *game);
void initialize(game_t *game);
void init_window(window_t *window);
void init_animation(animation_t *animation);
void init_rect(display_t *enemy);
void init_rect_scaled(display_t *display);
void init_sprites(display_t *sprite);
void init_position(display_t *sprite);
void init_sound(sound_t *sound);
void init_text(display_t *display);
void init_textures(display_t *sprite);
void init_scales(display_t *sprite);

void analyse_events(game_t *game);

void get_seconds(game_t *game);
void do_slime_animation(game_t *game);
void do_skeleton_animation(game_t *game);

void move_skeleton(game_t *game);
void move_slime(game_t *game);

void respawn_slime(game_t *game);
void respawn_skeleton(game_t *game);

void set_TextRect_and_clear(game_t *game);
void draw_all(game_t *game);
void destroy_all(game_t *game);

char *my_revstr(char *str);
void refresh_count(game_t *game);
char *create_str(int nb, char *str);
char *my_revstr(char *str);
int length_nb(int nb);

#endif
