/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** blabla
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int n = my_strlen(dest);
    int c = 0;

    for (int a = n; c < nb; a++){
        dest[a] = src[c];
        c++;
    }
    return (dest);
}
