/*
** EPITECH PROJECT, 2022
** init sounds
** File description:
** Init sounds
*/

#include "../../include/my_hunter.h"

static void create_sounds(sound_t *sound)
{
    sound->game = sfSound_create();
    sound->skel_death = sfSound_create();
    sound->slime_death = sfSound_create();
    sound->click = sfSound_create();
    sound->miss = sfSound_create();
    sound->highScore = sfSound_create();
    sound->levelUp = sfSound_create();
}

static void createSoundBuffers(sound_t *sound)
{
    sound->game_buf = CREATE_SOUND_BUF("res/sound/game_sound.wav");
    sound->slime_buf = CREATE_SOUND_BUF("res/sound/hit_slime.ogg");
    sound->skel_death_buf = CREATE_SOUND_BUF("res/sound/skel_death.ogg");
    sound->click_buf = CREATE_SOUND_BUF("res/sound/click.ogg");
    sound->miss_buf = CREATE_SOUND_BUF("res/sound/missclick.ogg");
    sound->highScoreBuf = CREATE_SOUND_BUF("res/sound/highScore.ogg");
    sound->levelUpBuf = CREATE_SOUND_BUF("res/sound/level_up.ogg");
}

static void setSounds(sound_t *sound)
{
    sfSound_setBuffer(sound->skel_death, sound->skel_death_buf);
    sfSound_setBuffer(sound->slime_death, sound->slime_buf);
    sfSound_setBuffer(sound->game, sound->game_buf);
    sfSound_setBuffer(sound->click, sound->click_buf);
    sfSound_setBuffer(sound->miss, sound->miss_buf);
    sfSound_setBuffer(sound->highScore, sound->highScoreBuf);
    sfSound_setBuffer(sound->levelUp, sound->levelUpBuf);
}

void initSounds(sound_t *sound)
{
    create_sounds(sound);
    createSoundBuffers(sound);
    setSounds(sound);
    sfSound_setVolume(sound->game, 20);
    sfSound_setLoop(sound->game, sfTrue);
}
