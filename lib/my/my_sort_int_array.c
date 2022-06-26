/*
** EPITECH PROJECT, 2021
** my_sort_int_arry
** File description:
** blabla
*/

#include "../../include/my.h"

void my_sort_int_array(int *tab, int size)
{
    int b = 0;
    int temp_var = 0;
    int a = 0;

    for (; a < size; a++)
        b = 0;
    for (; b < size; b++) {
        if (tab[b] > tab[a]) {
            temp_var = tab[a];
            tab[a] = tab[b];
            tab[b] = temp_var;
        }
    }
}
