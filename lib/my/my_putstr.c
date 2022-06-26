/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** blabla
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int a = 0;
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return (0);
}
