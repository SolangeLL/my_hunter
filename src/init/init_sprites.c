/*
** EPITECH PROJECT, 2022
** init_sprites
** File description:
** Initialize sprites
*/

#include "../../include/my_hunter.h"

static void create_sprites(game_t *game)
{
    // game->display->skeleton->sp = sfSprite_create();
    game->display->heart[0]->sp = sfSprite_create();
    game->display->heart[1]->sp = sfSprite_create();
    game->display->heart[2]->sp = sfSprite_create();
    // game->display->slime->sp = sfSprite_create();
    game->display->sign->sp = sfSprite_create();
    game->display->background->back_sp = sfSprite_create();
    game->menu->back_sp = sfSprite_create();
}

static void create_textures(game_t *game)
{
    game->display->background->back_texture = CREATE_TEXTURE("res/img/Background.png", NULL);
    // game->display->skeleton->texture = CREATE_TEXTURE("res/img/Skeleton_enemy.png", NULL);
    // game->display->slime->texture = CREATE_TEXTURE("res/img/Slime.png", NULL);
    // game->display->slime->death_texture = CREATE_TEXTURE("res/img/Slime_death.png", NULL);
    game->display->sign->texture = CREATE_TEXTURE("res/img/sign.png", NULL);
    game->display->heart[0]->texture = CREATE_TEXTURE("res/img/heart.png", NULL);
    game->display->heart[1]->texture = CREATE_TEXTURE("res/img/heart.png", NULL);
    game->display->heart[2]->texture = CREATE_TEXTURE("res/img/heart.png", NULL);
    game->menu->back_texture = CREATE_TEXTURE("res/img/menu_back.jpg", NULL);
}

static void init_textures(game_t *game)
{
    background_t *back = game->display->background;

    // sfSprite_setTexture(game->display->skeleton->sp, game->display->skeleton->texture, 0);
    // sfSprite_setTexture(game->display->slime->sp, game->display->slime->texture, 0);
    sfSprite_setTexture(back->back_sp, back->back_texture, 0);
    sfSprite_setTexture(game->display->sign->sp, game->display->sign->texture, 0);
    sfSprite_setTexture(game->display->heart[0]->sp, game->display->heart[0]->texture, 0);
    sfSprite_setTexture(game->display->heart[1]->sp, game->display->heart[1]->texture, 0);
    sfSprite_setTexture(game->display->heart[2]->sp, game->display->heart[2]->texture, 0);
    sfSprite_setTexture(game->menu->back_sp, game->menu->back_texture, 0);
}

static void init_scale_val(game_t *game)
{
    // game->display->skeleton->scale.x = 2.7;
    // game->display->skeleton->scale.y = 2.7;
    // game->display->slime->scale.x = -3;
    // game->display->slime->scale.y = 3;
    game->display->sign->scale.x = 0.06;
    game->display->sign->scale.y = 0.05;
    game->display->background->back_scale.x = 2.1;
    game->display->background->back_scale.y = 1.725;
    game->display->heart[0]->scale = (sfVector2f) {0.1, 0.1};
    game->display->heart[1]->scale = (sfVector2f) {0.1, 0.1};
    game->display->heart[2]->scale = (sfVector2f) {0.1, 0.1};

}

static void set_scales(game_t *game)
{
    // sfSprite_setScale(game->display->skeleton->sp, game->display->skeleton->scale);
    sfSprite_setScale(game->display->heart[0]->sp, game->display->heart[0]->scale);
    sfSprite_setScale(game->display->heart[1]->sp, game->display->heart[1]->scale);
    sfSprite_setScale(game->display->heart[2]->sp, game->display->heart[2]->scale);
    // sfSprite_setScale(game->display->slime->sp, game->display->slime->scale);
    sfSprite_setScale(game->display->sign->sp, game->display->sign->scale);
    sfSprite_setScale(game->display->background->back_sp, game->display->background->back_scale);
    sfSprite_setScale(game->menu->back_sp, (sfVector2f) {1, 0.98});
    // sfSprite_setColor(game->display->slime->sp, (sfColor) {200, 200, 255, 255});
}

static void init_pos_val(game_t *game)
{
    // game->display->skeleton->pos.x = 0;
    // game->display->skeleton->pos.y = 795;
    // game->display->slime->pos.x = 100;
    // game->display->slime->pos.y = 280;
    game->display->background->back_pos.x = 0;
    game->display->background->back_pos.y = -335;
    game->display->sign->pos.x = 0;
    game->display->sign->pos.y = -20;
    game->display->heart[0]->pos = (sfVector2f) {35, 965};
    game->display->heart[1]->pos = (sfVector2f) {91, 965};
    game->display->heart[2]->pos = (sfVector2f) {147, 965};
}

static void set_positions(game_t *game)
{
    sfSprite_setPosition(game->display->background->back_sp, game->display->background->back_pos);
    // sfSprite_setPosition(game->display->skeleton->sp, game->display->skeleton->pos);
    sfSprite_setPosition(game->display->heart[0]->sp, game->display->heart[0]->pos);
    sfSprite_setPosition(game->display->heart[1]->sp, game->display->heart[1]->pos);
    sfSprite_setPosition(game->display->heart[2]->sp, game->display->heart[2]->pos);
    // sfSprite_setPosition(game->display->slime->sp, game->display->slime->pos);
    sfSprite_setPosition(game->display->sign->sp, game->display->sign->pos);
}

void init_sprites(game_t *game)
{
    create_sprites(game);
    create_textures(game);
    init_textures(game);
    init_scale_val(game);
    init_pos_val(game);
    set_scales(game);
    set_positions(game);
}

