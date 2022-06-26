/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "../include/my_hunter.h"
#include <string.h>

void show_usage(void)
{
    my_printf("WHAT IS IT ?\n");
    my_printf("    This is a shooter game where you must protect your all\n");
    my_printf("    mighty majesty by killing the monsters you will see, \n");
    my_printf("    which are on their way to the castle, in order to \n");
    my_printf("    breaking peace and creating chaos.\n\n");
    my_printf("HOW TO PLAY ?\n");
    my_printf("    Just use your fabulous aim skill to click on \n");
    my_printf("    the monsters, the whole kingdom is counting on you.\n");
    exit(0);
}

int check_errors(int ac, char **av)
{
    if (ac == 2 && !strcmp(av[1], "-h"))
        show_usage();
    if (ac != 1)
        return (1);
    return 0;
}

int main(int ac, char **av)
{
    if (check_errors(ac, av))
        return (84);
    my_hunter();
    return EXIT_SUCCESS;
}
