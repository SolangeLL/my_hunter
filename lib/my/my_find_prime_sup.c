/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** blabla
*/

#include "../../include/my.h"

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    for (int param = nb; param != 4630; param++) {
        if (my_is_prime(param) == 1) {
            return (param);
        }
    }
}
