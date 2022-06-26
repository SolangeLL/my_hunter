/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** blabla
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int nbr = 1;
    int resp = 0;
    int i = 0;

    for (int a = 0; str[a] == '-' || str[a] == '+'; a++) {
        if (str[a] == '-')
            nbr = nbr * -1;
    }
    if (nbr == -1)
        i = 1;
    for (; str[i] != '\0'; i++) {
        if (str[i] <= '9' && str[i] >= '0') {
            resp = resp * 10;
            resp = resp + str[i] - '0';
        } else
            return (nbr * resp);
    }
    return (nbr * resp);
}
