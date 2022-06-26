/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** blabla
*/

#include "../../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (my_strlen(s1) > my_strlen(s2) || my_strlen(s1) < my_strlen(s2))
        return (0);
    for (int a = 0; a < n; a++) {
        if (s1[a] > s2[a])
            return (1);
        if (s1[a] < s2[a])
            return (-1);
    }
    return (0);
}
