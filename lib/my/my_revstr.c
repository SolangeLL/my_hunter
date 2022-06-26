/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** blabla
*/

#include "../../include/my.h"

static int count_tree(char const *str)
{
    int nb = 0;

    while (*str != '\0') {
        *str++;
        nb++;
    }
    return (nb);
}

int swap(char *a, char *b)
{
    int x = *b;
    *b = *a;
    *a = x;
}

char *my_revstr(char *str)
{
    int cont = count_tree(str) - 1;

    for (int b = 0; b < cont; b++, cont--) {
        swap(&str[b], &str[cont]);
    }
    return (str);
}
