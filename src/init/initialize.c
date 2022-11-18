/*
** EPITECH PROJECT, 2021
** initialize
** File description:
** Functions for initializations
*/

#include "../../include/my_hunter.h"

static void initStructures(game_t *game)
{
    game->win = malloc(sizeof(window_t));
    game->display = malloc(sizeof(display_t));
    game->gameplay = malloc(sizeof(gameplay_t));
    game->animation = malloc(sizeof(animation_t));
    game->display->background = malloc(sizeof(background_t));
    game->display->sign = malloc(sizeof(sign_t));
    game->display->heart = malloc(sizeof(heart_t *) * 4);
    for (int i = 0; i < 3; game->display->heart[i] = malloc(sizeof(heart_t)), i++)
        ;
    game->display->heart[3] = NULL;
    game->sound = malloc(sizeof(sound_t));
    game->menu = malloc(sizeof(menu_t));
    game->enemies = malloc(sizeof(enemies_t));
    game->settings = malloc(sizeof(settings_t));
}

static void initWindow(window_t *window)
{
    window->dimension = (sfVector2f){1920, 1080};
    window->mode = (sfVideoMode){1920, 1080, 32};
    window->win = sfRenderWindow_create(WINDOW_INFO);
    sfRenderWindow_setFramerateLimit(window->win, 60);
}

static void initTexts(display_t *display)
{
    display->sign->text_pos.x = 100;
    display->sign->text_pos.y = 30;
    display->sign->font =
        sfFont_createFromFile("res/fonts/cream-DEMO.ttf");
    display->sign->count = sfText_create();
    display->sign->char_count = "0";
    sfText_setFont(display->sign->count, display->sign->font);
    sfText_setString(display->sign->count, display->sign->char_count);
    sfText_setCharacterSize(display->sign->count, 45);
    sfText_setPosition(display->sign->count, display->sign->text_pos);
    sfText_setColor(display->sign->count, (sfColor){200, 200, 200, 255});
    sfText_setOutlineColor(display->sign->count, sfBlack);
    sfText_setOutlineThickness(display->sign->count, 3);
}

static void initValues(game_t *game)
{
    game->scene = MENU;
    game->gameplay->isScoreBetter = false;
    game->gameplay->life = 3;
    game->gameplay->count = 0;
    game->sound->isMute = false;
    game->enemies->spawnEnemies = 5;
    game->enemies->nbEnemies = 1;
    game->enemies->coef = 0;
    game->animation->spawnSec = 0;
    game->animation->seconds = 0;
    game->enemies->kills = 0;
    game->enemies->skeletons = NULL;
    game->enemies->slimes = NULL;
    game->enemies->idSkeleton = 0;
    game->enemies->idSlime = 0;
    game->settings->template = GENERAL;
}

void initAll(game_t *game)
{
    initStructures(game);
    initWindow(game->win);
    initSounds(game->sound);
    initSprites(game);
    initTexts(game->display);
    initValues(game);
    initScenesButtons(game);
    initScenesTextButtons(game);
    initButtonsCallbacks(game);
    initTemplates(game);
    loadBestScore(game->display->sign);
    game->enemies->skeletons = addSkeleton(game->enemies->skeletons, 0);
}
