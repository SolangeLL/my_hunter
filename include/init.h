/*
** EPITECH PROJECT, 2022
** init
** File description:
** Regroup function prototypes about iitialization
*/

#ifndef INIT_H_
    #define INIT_H_

void init_all(game_t *game);
void initialize(game_t *game);
void init_window(window_t *window);
void init_animation(animation_t *animation);
void init_rect(display_t *enemy);
void init_rect_scaled(display_t *display);
void init_sprites(game_t *game);
void init_sound(sound_t *sound);
void init_text(display_t *display);

#endif /* !INIT_H_ */
