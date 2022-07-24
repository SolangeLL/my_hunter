/*
** EPITECH PROJECT, 2022
** init enemies
** File description:
** Initialize list of enemies
*/

#include "../../include/my_hunter.h"

static int random_x(int min, int max)
{
    srand(time(0));
    return (rand() % (max - min + 1) + min);
}

//TODO Create hitbox (rect_scaled)
skeleton_t *create_skeleton(void)
{
    skeleton_t *skeleton = malloc(sizeof(skeleton_t));
    int randX = random_x(100, 300);

    skeleton->sp = sfSprite_create();
    skeleton->animSec = 0;
    skeleton->moveSec = 0;
    skeleton->shoot = 0;
    skeleton->texture = CREATE_TEXTURE("res/img/Skeleton_enemy.png", NULL);
    skeleton->scale = SF2F {2.7, 2.7};
    skeleton->pos = SF2F {randX, 795};
    skeleton->rect = (sfIntRect) {0, 128, 64, 64};
    skeleton->rect_scaled = (sfFloatRect) {randX, 795, 64 * skeleton->scale.x, 64 * skeleton->scale.y};
    sfSprite_setTextureRect(skeleton->sp, skeleton->rect);
    sfSprite_setTexture(skeleton->sp, skeleton->texture, 0);
    sfSprite_setScale(skeleton->sp, skeleton->scale);
    sfSprite_setPosition(skeleton->sp, skeleton->pos);
    skeleton->next = NULL;
    return skeleton;
}

slime_t *create_slime(void)
{
    slime_t *slime = malloc(sizeof(slime_t));

    slime->sp = sfSprite_create();
    slime->texture = CREATE_TEXTURE("res/img/Slime.png", NULL);
    slime->death_texture = CREATE_TEXTURE("res/img/Slime_death.png", NULL);
    slime->scale = SF2F {-3, 3};
    slime->pos = SF2F {random_x(-60, -20), 280};
    slime->rect = (sfIntRect) {0, 0, 32, 32};
    sfSprite_setTextureRect(slime->sp, slime->rect);
    sfSprite_setTexture(slime->sp, slime->texture, 0);
    sfSprite_setScale(slime->sp, slime->scale);
    sfSprite_setPosition(slime->sp, slime->pos);
    return slime;
}

skeleton_t *add_skeleton(skeleton_t *skeletons)
{
    skeleton_t *enemy = create_skeleton();

    if (skeletons == NULL) {
        skeletons = enemy;
        return enemy;
    }
    enemy->next = skeletons;
    skeletons = enemy;
    return skeletons;
}
slime_t *add_slime(slime_t *slimes);

void spawn_enemy(enemies_t *enemies, animation_t *anim)
{
    if ((int) anim->spawnSec == 5) {
        enemies->nbEnemies++;
        printf("Enemies: %d\n", enemies->nbEnemies);
        enemies->skeletons = add_skeleton(enemies->skeletons);
        // enemies->slimes = add_slime();
        anim->spawnSec -= anim->spawnSec;
    }
}