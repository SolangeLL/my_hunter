/*
** EPITECH PROJECT, 2022
** init
** File description:
** Regroup function prototypes about iitialization
*/

#ifndef INIT_H_
#define INIT_H_
#include "struct.h"

void initAll(game_t *game);
void initSprites(game_t *game);
void initSounds(sound_t *sound);
void initButtonsCallbacks(game_t *game);
void initScenesButtons(game_t *game);

#endif /* !INIT_H_ */
