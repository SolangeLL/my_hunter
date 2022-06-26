/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** blabla
*/

#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    int a = 0;

    if (nb < 0)
        return (0);
    for (; (a * a) != nb;) {
        a++;
        if ((a * a) > nb)
            return (0);
    }
    return (a);
}
