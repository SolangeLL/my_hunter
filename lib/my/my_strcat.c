/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** blabla
*/

#include "../../include/my.h"
#include <string.h>

int count(char const *str)
{
    int nb = 0;

    for (; str[nb] != '\0'; nb++);
    return (nb);
}

char *my_strcat(char *dest, char const *src)
{
    int nb = count(dest);
    int nb_two = count(src);
    int b = nb + nb_two;
    int c = 0;

    for (int a = nb; a < b; a++){
        dest[a] = src[c];
        c++;
    }
    dest[b] = '\0';
    return (dest);
}
