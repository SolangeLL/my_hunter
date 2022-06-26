/*
** EPITECH PROJECT, 2021
** initialize3
** File description:
** Other functions to initialize
*/

#include "../../include/my_hunter.h"

void init_animation(animation_t *animation)
{
    animation->clock = sfClock_create();
    animation->slime_clk = sfClock_create();
    animation->seconds = 0;
    animation->sec_slime = 0;
}

void init_sound(sound_t *sound)
{
    sound->game = sfSound_create();
    sound->skel_death = sfSound_create();
    sound->slime_death = sfSound_create();
    sound->game_buf = CREATE_SOUND_BUF("res/sound/game_sound.wav");
    sound->slime_buf = CREATE_SOUND_BUF("res/sound/hit_slime.ogg");
    sound->skel_death_buf = CREATE_SOUND_BUF("res/sound/skel_death.ogg");
    sfSound_setBuffer(sound->skel_death, sound->skel_death_buf);
    sfSound_setBuffer(sound->slime_death, sound->slime_buf);
    sfSound_setBuffer(sound->game, sound->game_buf);
    sfSound_play(sound->game);
    sfSound_setVolume(sound->game, 20);
    sfSound_setLoop(sound->game, sfTrue);
}

void init_position(display_t *sprite)
{
    sprite->skeleton->pos.x = 0;
    sprite->skeleton->pos.y = 795;
    sprite->slime->pos.x = 100;
    sprite->slime->pos.y = 280;
    sprite->background->back_pos.x = 0;
    sprite->background->back_pos.y = -335;
    sprite->sign->pos.x = 0;
    sprite->sign->pos.y = -20;
    sprite->heart->pos = (sfVector2f) {35, 80};
    sfSprite_setPosition(sprite->background->back_sp,\
    sprite->background->back_pos);
    sfSprite_setPosition(sprite->skeleton->sp, sprite->skeleton->pos);
    sfSprite_setPosition(sprite->heart->sp, sprite->heart->pos);
    sfSprite_setPosition(sprite->slime->sp, sprite->slime->pos);
    sfSprite_setPosition(sprite->sign->sp, sprite->sign->pos);
}
