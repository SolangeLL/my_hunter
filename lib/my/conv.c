/*
** EPITECH PROJECT, 2021
** conv
** File description:
** Regroup conversion functions
*/

#include "my.h"

int conv_base8(long nb)
{
    int len = 0;

    if (nb > 8) {
        len += conv_base8(nb / 8);
        len += conv_base8(nb % 8);
    } else
        len += my_putchar2(nb + '0');
    return (len);
}

int conv_base16_low(long nb)
{
    char base[16] = "0123456789abcdef";
    int len = 0;

    if (nb < 0) {
        nb *= -1;
        nb = 4294967295 - nb;
    }
    if (nb > 16) {
        len += conv_base16_low(nb / 16);
        len += conv_base16_low(nb % 16);
    } else
        len += my_putchar2(base[nb]);
    return (len);
}

int conv_base16_high(long nb)
{
    char base[16] = "0123456789ABCDEF";
    int len = 0;

    if (nb < 0) {
        nb *= -1;
        nb = 4294967295 - nb;
    }
    if (nb > 16) {
        len += conv_base16_high(nb / 16);
        len += conv_base16_high(nb % 16);
    } else
        len += my_putchar2(base[nb]);
    return (len);
}

int show_adress_ptr(long nb)
{
    int len = 0;

    if (nb < 0) {
        nb *= -1;
        nb = 4294967295 - nb;
    }
    len += my_putstr("0x");
    len += conv_base16_low(nb);
    return (len);
}

int conv_binary(long nb)
{
    int len = 0;

    if (nb > 1) {
        len += conv_binary(nb / 2);
        len += conv_binary(nb % 2);
    } else
        len += my_putchar2(nb + 48);
    return (len);
}
