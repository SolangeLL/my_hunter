/*
** EPITECH PROJECT, 2021
** tool
** File description:
** Functions to create a char *
*/

#include "../../../include/my_hunter.h"
#include <string.h>

static int getNumberLength(int nb)
{
    int len = 0;

    for (; nb >= 10; len++)
        nb = nb / 10;
    return (len + 1);
}

static char *createString(int nb, char *str)
{
    int unit = 0;
    int i = 0;
    int minus = 0;

    while (nb > 9) {
        unit = nb % 10;
        str[i++] = unit + '0';
        nb -= unit;
        nb /= 10;
    }
    str[i++] = nb + '0';
    if (minus == 1)
        str[i++] = '-';
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}

void refreshCount(game_t *game)
{
    char *counter = game->display->sign->char_count;

    int len = getNumberLength(game->gameplay->count);
    counter = malloc(sizeof(char) * (len + 1));
    counter = createString(game->gameplay->count, counter);
    sfText_setString(game->display->sign->count, strdup(counter));
    //* Color text in green if the player improve his highscore
    if (game->gameplay->count > my_getnbr(game->display->sign->bestScore) \
    && game->gameplay->isScoreBetter == false) {
        sfText_setColor(game->display->sign->count, sfGreen);
        sfSound_play(game->sound->highScore);
        game->gameplay->isScoreBetter = true;
    }
    free(counter);
}
