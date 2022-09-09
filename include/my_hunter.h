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
void browseSlimesAnim(game_t *game);
void browseSkeletonAnim(game_t *game);
void moveSkeletons(game_t *game);
void moveSlimes(game_t *game);
void spawn_enemy(enemies_t *enemies, animation_t *anim);
void respawn_slime(game_t *game);
void killMissedEnemies(game_t *game);
skeleton_t *addSkeleton(skeleton_t *skeletons, int id);
slime_t *add_slime(slime_t *slimes, int id);

void deleteSkeleton(skeleton_t **skeletons, int id);
void deleteSlime(slime_t **slimes, int id);
void destroy_all(game_t *game);

void draw_all(game_t *game);
void draw_menu(game_t *game);

void refresh_count(game_t *game);
char *create_str(int nb, char *str);
char *my_revstr(char *str);
int get_length_nb(int nb);

void go_to_game(button_t *btn, sfSound *sound, int *status);
void go_to_settings(button_t *btn, sfSound *sound, int *status);
void go_to_menu(button_t *btn, sfSound *sound, int *status);
void go_to_quit(button_t *btn, sfSound *sound, int *status);

void darken_button(button_t **btn, sfFloatRect mouse);
void enlarge_buttons(button_t **btn, sfFloatRect mouse);
void set_normal_buttons(button_t **btn, sfFloatRect mouse);
void set_dark_button(button_t *button, float scale);
void set_large_button(button_t *button, float scale, int gap);
void reset_button(button_t *button, float scale);

void loadBestScore(sign_t *sign);

#endif
