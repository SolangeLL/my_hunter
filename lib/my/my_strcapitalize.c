/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** blabla
*/

#include "../../include/my.h"
#include <string.h>

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    for (int a = 0; a < strlen(str); a++) {
        if (str[0] > 96 && str[0] < 123) {
            str[0] = str[0] -32;
        }
        if (str[a - 1] == ' ' && str[a] > 96 && str[a] < 123) {
            str[a] = str[a] -32;
        }
    }
    return (str);
}
