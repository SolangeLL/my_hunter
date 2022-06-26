/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** blabla
*/

#include "../../include/my.h"

int my_str_isalpha(char *str)
{
    char *temp = str;

    my_strlowcase(temp);
    for (int a = 0; temp[a] != '\0'; a++) {
        if (temp[a] > 122 || temp[a] < 97) {
            return (0);
        }
    }
    return (1);
}
