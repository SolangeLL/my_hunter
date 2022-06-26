/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** Copy a string
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int n_dest = my_strlen(dest);
    int n_src = my_strlen(src);

    for (int i = 0; i < n_dest; i++)
        dest[i] = '\0';
    for (int i = 0; i < n_src; i++)
        dest[i] = src[i];
    return (dest);
}
