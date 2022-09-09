/*
** EPITECH PROJECT, 2022
** init enemies
** File description:
** Initialize list of enemies
*/

#include "../../include/my_hunter.h"

static int randomValueInRange(int min, int max)
{
    srand(time(0));
    return (rand() % (max - min + 1) + min);
}

static skeleton_t *create_skeleton(int id)
{
    skeleton_t *skeleton = malloc(sizeof(skeleton_t));
    int randX = randomValueInRange(-300, -100);

    skeleton->id = id;
    skeleton->animSec = 0;
    skeleton->moveSec = 0;
    skeleton->shoot = 0;
    skeleton->scale = SF2F {2.7, 2.7};
    skeleton->pos = SF2F {randX, 795};
    skeleton->rect = (sfIntRect) {0, 128, 64, 64};
    skeleton->rect_scaled = (sfFloatRect) {randX, 795, \
    64 * skeleton->scale.x, 64 * skeleton->scale.y};
    skeleton->sp = sfSprite_create();
    skeleton->texture = CREATE_TEXTURE("res/img/Skeleton_enemy.png", NULL);
    sfSprite_setTextureRect(skeleton->sp, skeleton->rect);
    sfSprite_setTexture(skeleton->sp, skeleton->texture, 0);
    sfSprite_setScale(skeleton->sp, skeleton->scale);
    sfSprite_setPosition(skeleton->sp, skeleton->pos);
    skeleton->next = NULL;
    return skeleton;
}

static slime_t *create_slime(int id)
{
    slime_t *slime = malloc(sizeof(slime_t));
    int randomX = randomValueInRange(-60, -20);
    int randomY = randomValueInRange(200, 350);

    slime->id = id;
    slime->sp = sfSprite_create();
    slime->texture = CREATE_TEXTURE("res/img/Slime.png", NULL);
    slime->death_texture = CREATE_TEXTURE("res/img/Slime_death.png", NULL);
    slime->scale = SF2F {-3, 3};
    slime->shoot = 0;
    slime->alpha = 255;
    slime->animSec = 0;
    slime->moveSec = 0;
    slime->pos = SF2F {randomX, randomY};
    slime->rect = (sfIntRect) {0, 0, 32, 32};
    slime->rect_scaled = (sfFloatRect) {slime->pos.x, slime->pos.y, \
    32 * slime->scale.x, 32 * slime->scale.y};
    slime->wave = 0;
    sfSprite_setTextureRect(slime->sp, slime->rect);
    sfSprite_setTexture(slime->sp, slime->texture, 0);
    sfSprite_setScale(slime->sp, slime->scale);
    sfSprite_setPosition(slime->sp, slime->pos);
    slime->next = NULL;
    return slime;
}

skeleton_t *addSkeleton(skeleton_t *skeletons, int id)
{
    skeleton_t *enemy = create_skeleton(id);

    if (skeletons == NULL) {
        skeletons = enemy;
        return enemy;
    }
    enemy->next = skeletons;
    skeletons = enemy;
    return skeletons;
}
slime_t *addSlime(slime_t *slimes, int id)
{
    slime_t *enemy = create_slime(id);

    if (slimes == NULL) {
        slimes = enemy;
        return enemy;
    }
    enemy->next = slimes;
    slimes = enemy;
    return slimes;
}

void spawn_enemy(enemies_t *enemies, animation_t *anim)
{
    //* Enimies initially spawn each 5 seconds
    if (enemies->coef == 5 && \
    enemies->spawnEnemies - 0.2 >= 1) {
        enemies->spawnEnemies -= 0.2;
        enemies->coef = 0;
    }
    if (anim->spawnSec >= enemies->spawnEnemies) {
        enemies->nbEnemies++;
        enemies->skeletons = addSkeleton(enemies->skeletons, ++enemies->idSkeleton);
        enemies->slimes = addSlime(enemies->slimes, ++enemies->idSlime);
        anim->spawnSec -= anim->spawnSec;
    }
}