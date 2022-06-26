/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** blabla
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int nb = 0;

    while (str[nb] != ('\0')) {
        nb++;
    }
    return (nb);
}
