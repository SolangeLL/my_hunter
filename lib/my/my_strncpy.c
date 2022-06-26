/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Copy a string
*/

#include <stdlib.h>

int my_strlen(const char *str);

char *my_strncpy(char *dest, char *src, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return (dest);
}
