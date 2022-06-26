/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** blabla
*/

#include "../../include/my.h"

int my_is_prime(int nb)
{
    if (nb == 1 || nb == 0) {
        return (0);
    }
    for (int a = 2; a < nb; a++) {
        if (nb % a == 0)
            return (0);
    }
    return (1);
}
