/*
** EPITECH PROJECT, 2021
** initialize
** File description:
** Functions for initializations
*/

#include "../../include/my_hunter.h"

void init_struct(game_t *game)
{
    game->win = malloc(sizeof(window_t));
    game->display = malloc(sizeof(display_t));
    game->gameplay = malloc(sizeof(gameplay_t));
    game->animation = malloc(sizeof(animation_t));
    game->display->skeleton = malloc(sizeof(skeleton_t));
    game->display->slime = malloc(sizeof(slime_t));
    game->display->background = malloc(sizeof(background_t));
    game->display->sign = malloc(sizeof(sign_t));
    game->display->heart = malloc(sizeof(heart_t *) * 4);
    for (int i = 0; i < 3; game->display->heart[i] = malloc(sizeof(heart_t)), i++);
    game->display->heart[3] = NULL;
    game->sound = malloc(sizeof(sound_t));
    game->menu = malloc(sizeof(menu_t));
}

void init_window(window_t *window)
{
    window->dimension = (sfVector2f) {1920, 1080};
    window->mode = (sfVideoMode) {1920, 1080, 32};
    window->win = sfRenderWindow_create(WINDOW_INFO);
    sfRenderWindow_setFramerateLimit(window->win, 30);
}

void init_text(display_t *display)
{
    display->sign->text_pos.x = 100;
    display->sign->text_pos.y = 30;
    display->sign->font = \
    sfFont_createFromFile("res/txt/cream-DEMO.ttf");
    display->sign->count = sfText_create();
    display->sign->char_count = "0";
    sfText_setFont(display->sign->count, display->sign->font);
    sfText_setString(display->sign->count, display->sign->char_count);
    sfText_setCharacterSize(display->sign->count, 45);
    sfText_setPosition(display->sign->count, display->sign->text_pos);
    sfText_setColor(display->sign->count, (sfColor) {200, 200, 200, 255});
    sfText_setOutlineColor(display->sign->count, sfBlack);
    sfText_setOutlineThickness(display->sign->count, 3);
}

void init_values(game_t *game)
{
    game->scene = MENU;
    game->gameplay->life = 3;
    game->gameplay->count = 0;
    game->display->slime->alpha = 255;
    game->display->slime->wave = 0;
    game->display->slime->shoot = 0;
    game->display->skeleton->shoot = 0;
}

void init_all(game_t *game)
{
    init_struct(game);
    init_window(game->win);
    init_rect(game->display);
    init_animation(game->animation);
    init_sound(game->sound);
    init_sprites(game);
    init_rect_scaled(game->display);
    init_text(game->display);
    init_values(game);
    init_menu_buttons(game->menu);
    init_buttons_callbacks(game);
    loadBestScore(game->display->sign);
}
