/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** blabla
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) > my_strlen(s2) || my_strlen(s1) < my_strlen(s2))
        return (1);
    for (int a = 0; a < my_strlen(s1); a++) {
        if (s1[a] > s2[a])
            return (1);
        if (s1[a] < s2[a])
            return (-1);
    }
    return (0);
}
