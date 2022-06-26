/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Display string and return number of characters
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int my_strlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++, count++);
    return (count);
}

void give_flag_c(int (*flag_characters[])())
{
    flag_characters[0] = check_sharp;
    flag_characters[1] = put_plus;
    flag_characters[2] = put_space;
}

int get_flags(int (*functions[])(), char *s, int *i, va_list param)
{
    int len = 0;
    int (*flag_characters[3])(char *, int *, long);
    char *conv_spec = "disuoxXcp%b";
    char *flag_char = "#+ ";

    give_flag_c(flag_characters);
    for (int a = 0; a < my_strlen(conv_spec); a++)
        if (s[*i + 1] == conv_spec[a])
            len += functions[a](va_arg(param, void*));
    for (int a = 0; a < my_strlen(flag_char); a++)
        if (s[*i + 1] == flag_char[a])
            len += flag_characters[a](s, i, va_arg(param, long));
    if (s[*i + 1] == 'S')
        len += put_octal_value_in_string(va_arg(param, char *), i);
    if (len != 0)
        *i += 1;
    return (len);
}

void give_functions(int (*functions[])())
{
    functions[0] = my_put_nbr;
    functions[1] = my_put_nbr;
    functions[2] = my_putstr2;
    functions[3] = my_put_unsigned;
    functions[4] = conv_base8;
    functions[5] = conv_base16_low;
    functions[6] = conv_base16_high;
    functions[7] = my_putchar2;
    functions[8] = show_adress_ptr;
    functions[9] = percent;
    functions[10] = conv_binary;
}

int my_printf(char *s, ...)
{
    int len = 0;
    va_list param;
    int (*functions[11])();

    give_functions(functions);
    va_start(param, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%')
            len += get_flags(functions, s, &i, param);
        else
            len += my_putchar2(s[i]);
    }
    va_end(param);
    return (len);
}
