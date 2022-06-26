/*
** EPITECH PROJECT, 2021
** my
** File description:
** blabla
*/

#ifndef MY_H
    #define MY_H

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_printf(char *s, ...);
int my_putstr2(char const *str);
int my_putchar2(int c);
int my_put_unsigned(long nb);
int conv_base8(long nb);
int conv_base16_low(long nb);
int conv_base16_high(long nb);
int show_adress_ptr(long nb);
int check_sharp(char *c, int *i, long data);
int put_plus(char *s, int *i, int data);
int put_space(char *s, int *i, int data);
int conv_binary(long nb);
int put_octal_value_in_string(char *s, int *i);
int percent(int c);

#endif
