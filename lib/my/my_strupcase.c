/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** blabla
*/

#include "../../include/my.h"

char *my_strupcase(char *str)
{
    for (int i = 0;str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return (str);
}
