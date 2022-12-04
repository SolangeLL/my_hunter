/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** Regroup alla variables for my_hunter
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_
#include "includes.h"
#include "struct.h"
#include "init.h"
#include "macros.h"
#include "my.h"

void my_hunter(void);
void gameLoop(game_t *game);
void menuLoop(game_t *game);
void settingsLoop(game_t *game);

void getMouseHitbox(game_t *game);
void analyzeGameEvents(game_t *game);

void getSeconds(game_t *game);
void browseEnemiesAnim(game_t *game);
void moveEnemies(game_t *game);
void spawnEnemies(enemies_t *enemies, animation_t *anim, sfSound *levelUpSound);
void killMissedEnemies(game_t *game);
skeleton_t *addSkeleton(skeleton_t *skeletons, int id);

void deleteSkeleton(skeleton_t **skeletons, int id);
void deleteSlime(slime_t **slimes, int id);
void destroyAll(game_t *game);

void drawGame(game_t *game);
void drawMenu(game_t *game);
void drawSettings(game_t *game);
void manageMenuEvents(game_t *game);
void manageSettingsEvents(game_t *game);
void refreshCount(game_t *game);
char *createString(int nb);

//* Callbacks
void goToGame(game_t *game, button_t *btn);
void goToSettings(game_t *game, button_t *btn);
void goToMenu(game_t *game, button_t *btn);
void goToQuit(game_t *game, button_t *btn);
void updateMasterVolume(game_t *game, button_t *button, int val);
void updateMusicVolume(game_t *game, button_t *button, int val);
void updateEffectsVolume(game_t *game, button_t *button, int val);
void muteVolume(game_t *game, button_t *btn);
void changeSettingsTemplate(game_t *game, text_button_t *btn);
void changeWindow(game_t *game, text_button_t *btn);
void modifVolume(sfSound *sound, int volume);
void setFullscreen(game_t *game, text_button_t *btn);

void darkenButton(button_t **btn, sfFloatRect mouse);
void enlargeButton(button_t **btn, sfFloatRect mouse);
void resetButton(button_t **btn, sfFloatRect mouse);
void resizeButton(button_t *button, sfVector2f scale);

void darkenText(text_button_t **btn, sfFloatRect mouse);
void enlargeText(text_button_t **btn, sfFloatRect mouse);
void resetText(text_button_t **btn, sfFloatRect mouse);
void resizeText(text_button_t *button, sfVector2f scale);
void setNormalText(text_button_t *text);

void loadBestScore(sign_t *sign);
void saveBestScore(game_t *game);

#endif
