/*
** EPITECH PROJECT, 2021
** tool
** File description:
** Functions to create a char *
*/

#include "../../../include/my_hunter.h"
#include <string.h>

int get_length_nb(int nb)
{
    int len = 0;

    for (; nb >= 10; len++)
        nb = nb / 10;
    return (len + 1);
}

char *create_str(int nb, char *str)
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

void refresh_count(game_t *game)
{
    char *counter = game->display->sign->char_count;

    int len = get_length_nb(game->gameplay->count);
    counter = malloc(sizeof(char) * (len + 1));
    counter = create_str(game->gameplay->count, counter);
    sfText_setString(game->display->sign->count, strdup(counter));
    if (game->gameplay->count > my_getnbr(game->display->sign->bestScore))
        sfText_setColor(game->display->sign->count, sfGreen);
    free(counter);
}
