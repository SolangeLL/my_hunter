/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** Create 2D array of strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_valid(char c)
{
    if (c >= 48 && c <= 57 ||
    c >= 65 && c <= 90 ||
    c >= 97 && c <= 122) {
        return (1);
    }
    return (0);
}

int count_words(char const *str)
{
    int nb = 1;

    if (str[0] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i++)
        if (isalnum(str[i]) == 0)
            nb += 1;
    return (nb);
}

int word_length(char const *str, int *index)
{
    int nb = 1;

    for (; isalnum(str[*index]) && isalnum(str[*index + 1]);\
    *index += 1, nb += 1);
    *index += 1;
    if (str[*index] != '\0')
        for (; !isalnum(str[*index]); *index += 1);
    return (nb);
}

char **my_str_to_word_array(char const *str)
{
    int nb_words = count_words(str);
    int index = 0;
    int len = 0;
    char **tab = malloc(sizeof(char *) * (nb_words + 1));

    for (int i = 0, start = 0; i < nb_words; i++) {
        len = word_length(str, &index);
        tab[i] = malloc(sizeof(char) * (len + 1));
        for (int a = start, j = 0; a < index; a++, j++)
            tab[i][j] = str[a];
        tab[i][len] = '\0';
        start = index;
    }
    tab[nb_words] = NULL;
    return (tab);
}
