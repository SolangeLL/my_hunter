#include "../../include/my_hunter.h"

static void destroy_txt_btn(text_button_t *btn)
{
    sfText_destroy(btn->text);
    free(btn);
}

static void destroy_btn(button_t *btn)
{
    sfSprite_destroy(btn->sprite);
    sfTexture_destroy(btn->texture);
    free(btn);
}

void destroy_btn_tab(button_t **button_tab)
{
    for (int i = 0; button_tab[i] != NULL; i++)
        destroy_btn(button_tab[i]);
    free(button_tab);
}

void destroy_txt_btn_tab(text_button_t **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        destroy_txt_btn(tab[i]);
    free(tab);
}

void destroy_text_tab(sfText **text_tab)
{
    for (int i = 0; text_tab[i] != NULL; i++)
        sfText_destroy(text_tab[i]);
    free(text_tab);
}