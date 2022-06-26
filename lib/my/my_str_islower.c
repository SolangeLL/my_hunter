/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** blabla
*/

#include "../../include/my.h"

int my_str_islower(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] > 122 || str[a] < 97)
            return (0);
    return (1);
}
