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

void getMouseHitbox(game_t *game);
void analyzeGameEvents(game_t *game);

void getSeconds(game_t *game);
void browseEnemiesAnim(game_t *game);
void moveEnemies(game_t *game);
void spawnEnemies(enemies_t *enemies, animation_t *anim);
void killMissedEnemies(game_t *game);
skeleton_t *addSkeleton(skeleton_t *skeletons, int id);

void deleteSkeleton(skeleton_t **skeletons, int id);
void deleteSlime(slime_t **slimes, int id);
void destroyAll(game_t *game);

void drawGame(game_t *game);
void drawMenu(game_t *game);

void refreshCount(game_t *game);

void goToGame(button_t *btn, sfSound *sound, int *status);
void goToSettings(button_t *btn, sfSound *sound, int *status);
void goToMenu(button_t *btn, sfSound *sound, int *status);
void goToQuit(button_t *btn, sfSound *sound, int *status);

void darkenButton(button_t **btn, sfFloatRect mouse);
void enlargeButton(button_t **btn, sfFloatRect mouse);
void setNormalButton(button_t **btn, sfFloatRect mouse);
void setDarkButton(button_t *button, float scale);
void setLargeButton(button_t *button, float scale, int gap);
void resetButton(button_t *button, float scale);
void resizeButton(button_t *button, sfVector2f scale);
void colorButton(button_t *button, int modify);

void loadBestScore(sign_t *sign);

#endif
