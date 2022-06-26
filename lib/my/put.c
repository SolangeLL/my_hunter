/*
** EPITECH PROJECT, 2021
** put
** File description:
** Regroup all put functions
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int my_putchar2(int c)
{
    if (c >= 7 && c <= 13) {
        write(1, &c, 1);
        return (1);
    }
    if ((c < 32 || c == 127) || (c >= 7 && c <= 13))
        return (0);
    write(1, &c, 1);
    return (1);
}

int percent(int c)
{
    int len = 0;

    len += my_putchar2(37);
    return (len);
}

int my_putstr2(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++, len++)
        my_putchar2(str[i]);
    return (len);
}

int my_put_unsigned(long nb)
{
    unsigned long a = 0;
    int len = 0;

    if (nb < 0) {
        a = 4294967294 - nb;
        len += my_put_nbr(a);
        return (len);
    }
    if (nb > 9) {
        len += my_put_nbr(nb / 10);
        len += my_put_nbr(nb % 10);
    } else
        len += my_putchar2(nb + '0');
    return (len);
}

int put_octal_value_in_string(char *s, int *i)
{
    int len = 0;

    for (int a = 0; s[a] != '\0'; a++) {
        if (s[a] < 32 || s[a] >= 127) {
            len += my_putchar2(92);
            len += conv_base8(s[a]);
        } else
            len += my_putchar2(s[a]);
    }
    return (len);
}
