/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** blabla
*/

#include "../../include/my.h"

int my_str_isupper(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] > 90 || str[a] < 65)
            return (0);
    }
    return (1);
}
