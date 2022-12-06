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
void initScenesTextButtons(game_t *game);
void initTemplates(game_t *game);

button_t *initButton(char *texture_path, sfVector2f pos);
text_button_t *initTextButton(char *str, sfVector3f info, sfColor color, sfFont *font);

#endif /* !INIT_H_ */
