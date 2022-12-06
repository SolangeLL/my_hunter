/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** Functions to destroy
*/

#include "../../include/my_hunter.h"

static void destroy_sprites(game_t *game)
{
    sfSprite_destroy(game->display->sign->sp);
    sfSprite_destroy(game->display->background->back_sp);
    sfSprite_destroy(game->display->heart[0]->sp);
    sfSprite_destroy(game->display->heart[1]->sp);
    sfSprite_destroy(game->display->heart[2]->sp);
    sfSprite_destroy(game->menu->back_sp);
    sfSprite_destroy(game->settings->back_sp);
    sfSprite_destroy(game->settings->titles_sp);
    sfSprite_destroy(game->settings->content_sp);
}

static void destroy_textures(game_t *game)
{
    sfTexture_destroy(game->display->background->back_texture);
    sfTexture_destroy(game->display->sign->texture);
    sfTexture_destroy(game->display->heart[0]->texture);
    sfTexture_destroy(game->display->heart[1]->texture);
    sfTexture_destroy(game->display->heart[2]->texture);
    sfTexture_destroy(game->menu->back_texture);
    sfTexture_destroy(game->settings->back_texture);
    sfTexture_destroy(game->settings->titles_texture);
    sfTexture_destroy(game->settings->content_texture);
}

static void destroy_sound_buffers(sound_t *sound)
{
    sfSoundBuffer_destroy(sound->game_buf);
    sfSoundBuffer_destroy(sound->skel_death_buf);
    sfSoundBuffer_destroy(sound->slime_buf);
    sfSoundBuffer_destroy(sound->click_buf);
    sfSoundBuffer_destroy(sound->click2_buf);
    sfSoundBuffer_destroy(sound->miss_buf);
    sfSoundBuffer_destroy(sound->highScoreBuf);
    sfSoundBuffer_destroy(sound->levelUpBuf);
    sfSoundBuffer_destroy(sound->menuBuf);
}

static void destroy_sounds(sound_t *sound)
{
    sfSound_destroy(sound->game);
    sfSound_destroy(sound->skel_death);
    sfSound_destroy(sound->slime_death);
    sfSound_destroy(sound->click);
    sfSound_destroy(sound->click2);
    sfSound_destroy(sound->miss);
    sfSound_destroy(sound->highScore);
    sfSound_destroy(sound->levelUp);
    sfSound_destroy(sound->menu);
}

static void destroy_texts(display_t *display)
{
    free(display->sign->bestScore);
    sfFont_destroy(display->fonts[PIXELED]);
    sfFont_destroy(display->fonts[GOLDEN_AGE]);
    sfFont_destroy(display->fonts[CREAM]);
    sfText_destroy(display->sign->count);
    sfText_destroy(display->sign->bestScoreTxt);
}

static void destroy_btn_tabs(game_t *game)
{
    destroy_btn_tab(game->menu->btn);
    destroy_btn_tab(game->settings->templates[0]->btn);
    destroy_btn_tab(game->settings->templates[1]->btn);
    destroy_btn_tab(game->settings->templates[2]->btn);
}

static void destroy_txt_btn_tabs(game_t *game)
{
    destroy_txt_btn_tab(game->settings->text_btn);
    destroy_txt_btn_tab(game->settings->templates[0]->text_btn);
    destroy_txt_btn_tab(game->settings->templates[1]->text_btn);
    destroy_txt_btn_tab(game->settings->templates[2]->text_btn);
}

static void destroy_structures(game_t *game)
{
    free(game->win);
    free(game->display->background);
    free(game->display->sign);
    free(game->display->heart[0]);
    free(game->display->heart[1]);
    free(game->display->heart[2]);
    free(game->display->heart);
    free(game->display);
    free(game->enemies);
    free(game->gameplay);
    free(game->sound);
    free(game->animation);
    free(game->menu);
    free(game->settings->templates[0]);
    free(game->settings->templates[1]);
    free(game->settings->templates[2]);
    free(game->settings);
    free(game);
}

static void destroySkeletonList(skeleton_t **list)
{
    skeleton_t *tmp = NULL;

    while ((*list) != NULL)
    {
        tmp = (*list)->next;
        sfSprite_destroy((*list)->sp);
        sfTexture_destroy((*list)->texture);
        free((*list));
        (*list) = tmp;
    }
}

static void destroySlimeList(slime_t **list)
{
    slime_t *tmp = NULL;

    while ((*list) != NULL)
    {
        tmp = (*list)->next;
        sfSprite_destroy((*list)->sp);
        sfTexture_destroy((*list)->texture);
        sfTexture_destroy((*list)->death_texture);
        free((*list));
        (*list) = tmp;
    }
}

void destroyAll(game_t *game)
{
    sfClock_destroy(game->animation->clock);
    sfRenderWindow_destroy(game->win->win);
    destroySkeletonList(&(game->enemies->skeletons));
    destroySlimeList(&(game->enemies->slimes));
    destroy_sprites(game);
    destroy_textures(game);
    destroy_texts(game->display);
    destroy_text_tab(game->settings->templates[0]->texts);
    destroy_text_tab(game->settings->templates[1]->texts);
    destroy_text_tab(game->settings->templates[2]->texts);
    destroy_sounds(game->sound);
    destroy_sound_buffers(game->sound);
    destroy_btn_tabs(game);
    destroy_txt_btn_tabs(game);
    destroy_structures(game);
}
