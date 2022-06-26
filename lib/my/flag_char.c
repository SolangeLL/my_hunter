/*
** EPITECH PROJECT, 2021
** flag char
** File description:
** Regroup function for flag characters
*/

#include "my.h"
#include <stdio.h>

int check_sharp(char *s, int *i, long data)
{
    int len = 0;

    if (s[*i + 1] == 'o') {
        if (data != 0)
            len += my_putchar2('0');
        *i += 1;
        len += conv_base8(data);
    }
    if (s[*i + 1] == 'x') {
        *i += 1;
        len += show_adress_ptr(data);
    }
    if (s[*i + 1] == 'X') {
        len += my_putstr("0X");
        *i += 1;
        len += conv_base16_high(data);
    }
    return (len);
}

int put_plus(char *s, int *i, int data)
{
    int len = 0;

    *i += 1;
    if (data >= 0) {
        len += my_putchar2('+');
        len += my_put_nbr(data);
    } else {
        len += my_put_nbr(data);
    }
    return (len);
}

int put_space(char *s, int *i, int data)
{
    int len = 0;

    *i += 1;
    if (data >= 0)
        len += my_putchar2(' ');
    len += my_put_nbr(data);
    return (len);
}
