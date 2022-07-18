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
    sound->miss = sfSound_create();
    sound->game_buf = CREATE_SOUND_BUF("res/sound/game_sound.wav");
    sound->slime_buf = CREATE_SOUND_BUF("res/sound/hit_slime.ogg");
    sound->skel_death_buf = CREATE_SOUND_BUF("res/sound/skel_death.ogg");
    sound->click_buf = CREATE_SOUND_BUF("res/sound/click.ogg");
    sound->miss_buf = CREATE_SOUND_BUF("res/sound/missclick.ogg");
    sfSound_setBuffer(sound->skel_death, sound->skel_death_buf);
    sfSound_setBuffer(sound->slime_death, sound->slime_buf);
    sfSound_setBuffer(sound->game, sound->game_buf);
    sfSound_setBuffer(sound->click, sound->click_buf);
    sfSound_setBuffer(sound->miss, sound->miss_buf);
    sfSound_setVolume(sound->game, 20);
    sfSound_setLoop(sound->game, sfTrue);
}

void loadBestScore(sign_t *sign)
{
    FILE *file = NULL;
    struct stat info;
    char best[6] = "Best ";
    sfFloatRect bounds = {0, 0, 0, 0};

    file = fopen("config/bestScore.txt", "r");
    stat("config/bestScore.txt", &info);
    sign->bestScore = malloc(sizeof(char) * (info.st_size + 1));
    sign->bestScoreTxt = sfText_create();
    fread(sign->bestScore, 1, info.st_size, file);
    sign->bestScore[info.st_size] = '\0';
    sfText_setFont(sign->bestScoreTxt, sign->font);
    sfText_setCharacterSize(sign->bestScoreTxt, 30);
    sfText_setOutlineColor(sign->bestScoreTxt, sfBlack);
    sfText_setOutlineThickness(sign->bestScoreTxt, 2);
    sfText_setColor(sign->bestScoreTxt, (sfColor) {200, 200, 200, 255});
    sfText_setString(sign->bestScoreTxt, strcat(best, sign->bestScore));
    bounds = sfText_getGlobalBounds(sign->bestScoreTxt);
    sfText_setPosition(sign->bestScoreTxt, SF2F {120 - (bounds.width / 2), 90});
    fclose(file);
}