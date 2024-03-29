/*
** EPITECH PROJECT, 2022
** init_sprites
** File description:
** Initialize sprites
*/

#include "../../include/my_hunter.h"

static void createSprites(game_t *game)
{
    game->display->heart[0]->sp = sfSprite_create();
    game->display->heart[1]->sp = sfSprite_create();
    game->display->heart[2]->sp = sfSprite_create();
    game->display->sign->sp = sfSprite_create();
    game->display->background->back_sp = sfSprite_create();
    game->menu->back_sp = sfSprite_create();
    game->settings->back_sp = sfSprite_create();
    game->settings->titles_sp = sfSprite_create();
    game->settings->content_sp = sfSprite_create();
}

static void createTextures(game_t *game)
{
    game->display->background->back_texture = CREATE_TEXTURE("res/img/Background.png", NULL);
    game->display->sign->texture = CREATE_TEXTURE("res/img/sign.png", NULL);
    game->display->heart[0]->texture = CREATE_TEXTURE("res/img/heart.png", NULL);
    game->display->heart[1]->texture = CREATE_TEXTURE("res/img/heart.png", NULL);
    game->display->heart[2]->texture = CREATE_TEXTURE("res/img/heart.png", NULL);
    game->menu->back_texture = CREATE_TEXTURE("res/img/menu_back.jpg", NULL);
    game->settings->back_texture = CREATE_TEXTURE("res/img/menu_back.jpg", NULL);
    game->settings->titles_texture = CREATE_TEXTURE("res/img/settings_titles.png", NULL);
    game->settings->content_texture = CREATE_TEXTURE("res/img/settings_content.png", NULL);
}

static void initTextures(game_t *game)
{
    background_t *back = game->display->background;

    sfSprite_setTexture(back->back_sp, back->back_texture, 0);
    sfSprite_setTexture(game->display->sign->sp, game->display->sign->texture, 0);
    sfSprite_setTexture(game->display->heart[0]->sp, game->display->heart[0]->texture, 0);
    sfSprite_setTexture(game->display->heart[1]->sp, game->display->heart[1]->texture, 0);
    sfSprite_setTexture(game->display->heart[2]->sp, game->display->heart[2]->texture, 0);
    sfSprite_setTexture(game->menu->back_sp, game->menu->back_texture, 0);
    sfSprite_setTexture(game->settings->back_sp, game->settings->back_texture, 0);
    sfSprite_setTexture(game->settings->titles_sp, game->settings->titles_texture, 0);
    sfSprite_setTexture(game->settings->content_sp, game->settings->content_texture, 0);
}

static void initScaleValues(game_t *game)
{
    game->display->sign->scale.x = 0.06;
    game->display->sign->scale.y = 0.05;
    game->display->background->back_scale.x = 2.1;
    game->display->background->back_scale.y = 1.725;
    game->display->heart[0]->scale = (sfVector2f){0.1, 0.1};
    game->display->heart[1]->scale = (sfVector2f){0.1, 0.1};
    game->display->heart[2]->scale = (sfVector2f){0.1, 0.1};
    game->settings->titles_scale = (sfVector2f){2, 2};
    game->settings->content_scale = (sfVector2f){2.2, 3};
}

static void setScales(game_t *game)
{
    sfSprite_setScale(game->display->heart[0]->sp, game->display->heart[0]->scale);
    sfSprite_setScale(game->display->heart[1]->sp, game->display->heart[1]->scale);
    sfSprite_setScale(game->display->heart[2]->sp, game->display->heart[2]->scale);
    sfSprite_setScale(game->display->sign->sp, game->display->sign->scale);
    sfSprite_setScale(game->display->background->back_sp, game->display->background->back_scale);
    sfSprite_setScale(game->settings->titles_sp, game->settings->titles_scale);
    sfSprite_setScale(game->settings->content_sp, game->settings->content_scale);
}

static void initPosValues(game_t *game)
{
    game->display->background->back_pos.x = 0;
    game->display->background->back_pos.y = -292;
    game->display->sign->pos.x = 0;
    game->display->sign->pos.y = -20;
    game->display->heart[0]->pos = (sfVector2f){35, 1008};
    game->display->heart[1]->pos = (sfVector2f){91, 1008};
    game->display->heart[2]->pos = (sfVector2f){147, 1008};
    game->settings->titles_pos = (sfVector2f){50, 30};
    game->settings->content_pos = (sfVector2f){650, 45.5};
}

static void setPositions(game_t *game)
{
    sfSprite_setPosition(game->display->background->back_sp, game->display->background->back_pos);
    sfSprite_setPosition(game->display->heart[0]->sp, game->display->heart[0]->pos);
    sfSprite_setPosition(game->display->heart[1]->sp, game->display->heart[1]->pos);
    sfSprite_setPosition(game->display->heart[2]->sp, game->display->heart[2]->pos);
    sfSprite_setPosition(game->display->sign->sp, game->display->sign->pos);
    sfSprite_setPosition(game->settings->titles_sp, game->settings->titles_pos);
    sfSprite_setPosition(game->settings->content_sp, game->settings->content_pos);
}

void initSprites(game_t *game)
{
    createSprites(game);
    createTextures(game);
    initTextures(game);
    initScaleValues(game);
    initPosValues(game);
    setScales(game);
    setPositions(game);
}
