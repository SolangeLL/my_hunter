/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** blabla
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] > 57 || str[a] < 48)
            return (0);
    return (1);
}
