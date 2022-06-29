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
    sound->click = sfSound_create();
    sound->game_buf = CREATE_SOUND_BUF("res/sound/game_sound.wav");
    sound->slime_buf = CREATE_SOUND_BUF("res/sound/hit_slime.ogg");
    sound->skel_death_buf = CREATE_SOUND_BUF("res/sound/skel_death.ogg");
    sound->click_buf = CREATE_SOUND_BUF("res/sound/click.ogg");
    sfSound_setBuffer(sound->skel_death, sound->skel_death_buf);
    sfSound_setBuffer(sound->slime_death, sound->slime_buf);
    sfSound_setBuffer(sound->game, sound->game_buf);
    sfSound_setBuffer(sound->click, sound->click_buf);
    sfSound_setVolume(sound->game, 20);
    sfSound_setLoop(sound->game, sfTrue);
}
