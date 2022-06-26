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
    sfSoundBuffer_destroy(sound->game_buf);
    sfSoundBuffer_destroy(sound->skel_death_buf);
    sfSoundBuffer_destroy(sound->slime_buf);
}

void destroy_texts(display_t *display)
{
    sfFont_destroy(display->sign->font);
    sfText_destroy(display->sign->count);
}

void destroy_all(game_t *game)
{
    sfRenderWindow_destroy(game->window->window);
    destroy_sprites(game->display);
    destroy_textures(game->display);
    destroy_sounds(game->sound);
}
