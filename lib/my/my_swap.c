/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** blabla
*/

#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int x = *b;
    *b = *a;
    *a = x;
}
