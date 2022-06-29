/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** Functions to destroy
*/

#include "../include/my_hunter.h"

void destroy_sprites(display_t *display)
{
    sfSprite_destroy(display->skeleton->sp);
    sfSprite_destroy(display->slime->sp);
    sfSprite_destroy(display->sign->sp);
    sfSprite_destroy(display->background->back_sp);
}

void destroy_textures(display_t *display)
{
    sfTexture_destroy(display->background->back_texture);
    sfTexture_destroy(display->sign->texture);
    sfTexture_destroy(display->skeleton->texture);
    sfTexture_destroy(display->slime->texture);
}

void destroy_sounds(sound_t *sound)
{
    sfSound_destroy(sound->game);
    sfSound_destroy(sound->skel_death);
    sfSound_destroy(sound->slime_death);
    sfSound_destroy(sound->click);
    sfSoundBuffer_destroy(sound->game_buf);
    sfSoundBuffer_destroy(sound->skel_death_buf);
    sfSoundBuffer_destroy(sound->slime_buf);
    sfSoundBuffer_destroy(sound->click_buf);
}

void destroy_texts(display_t *display)
{
    sfFont_destroy(display->sign->font);
    sfText_destroy(display->sign->count);
}

void destroy_btn(button_t *btn)
{
    sfSprite_destroy(btn->sprite);
    sfTexture_destroy(btn->texture);
    free(btn);
}

void destroy_btn_tab(button_t **button_tab)
{
    for (int i = 0; button_tab[i] != NULL; i++)
        destroy_btn(button_tab[i]);
    free(button_tab);
}

void destroy_btn_tabs(game_t *game)
{
    destroy_btn_tab(game->menu->btn);
}

void destroy_all(game_t *game)
{
    sfRenderWindow_destroy(game->win->win);
    destroy_sprites(game->display);
    destroy_textures(game->display);
    destroy_sounds(game->sound);
    destroy_btn_tabs(game);
}
