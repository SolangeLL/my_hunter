/*
** EPITECH PROJECT, 2021
** put2
** File description:
** File for one function (Correcting Coding Style)
*/

int my_putchar2(int c);

int my_put_nbr(long nb)
{
    int len = 0;

    if (nb < 0) {
        my_putchar2('-');
        nb = -nb;
        len++;
    }
    if (nb > 9) {
        len += my_put_nbr(nb / 10);
        len += my_put_nbr(nb % 10);
    } else
        len += my_putchar2(nb + '0');
    return (len);
}
