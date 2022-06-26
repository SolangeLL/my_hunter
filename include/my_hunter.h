/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** Regroup alla variables for my_hunter
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
    #include "includes.h"
    #include "struct.h"
    #include "init.h"
    #include "macros.h"
    #include "my.h"

void game_loop(game_t *game);
void menu_loop(game_t *game);

void my_hunter(void);
void get_mouse_hitbox(game_t *game);

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

void refresh_count(game_t *game);
char *create_str(int nb, char *str);
char *my_revstr(char *str);
int length_nb(int nb);

#endif
