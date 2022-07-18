/*
** EPITECH PROJECT, 2021
** initialize3
** File description:
** Other functions to initialize
*/

#include "../../include/my_hunter.h"

void init_animation(animation_t *animation)
{
    animation->seconds = 0;
    animation->sec_slime = 0;
    animation->secSkeleton = 0;
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