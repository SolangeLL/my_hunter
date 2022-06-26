/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** blabla
*/

#include "../../include/my.h"

int my_str_isprintable(char const *str)
{
    for (int a = 0; a != '\0'; a++)
        if (str[a] < 32 || str[a] > 126)
            return (0);
    return (1);
}
