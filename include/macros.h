/*
** EPITECH PROJECT, 2022
** macro
** File description:
** Regroup all macros
*/

#ifndef MACROS_H_
    #define MACROS_H_
    #define WINDOW_INFO window->mode, "MY HUNTER", sfDefaultStyle, NULL
    #define CREATE_SOUND_BUF sfSoundBuffer_createFromFile
    #define CREATE_TEXTURE sfTexture_createFromFile
    #define IS_EVENT \
    sfRenderWindow_pollEvent(game->win->win, &game->gameplay->event)
    #define ESCAPE_IS_PRESSED game->gameplay->event.type == sfEvtKeyPressed \
    && sfKeyboard_isKeyPressed(sfKeyEscape)
    #define CLICK_ON_SLIME sfFloatRect_intersects(&slime->rect_scaled, \
    &game->gameplay->mouse_rect, NULL) == sfTrue && slime->shoot == 0
    #define CLICK_ON_SKELETON sfFloatRect_intersects(&tmp->rect_scaled, \
    &game->gameplay->mouse_rect, NULL) == sfTrue && tmp->shoot == 0
    #define SF2F (sfVector2f)
    #define CLICK_ON_TEMPLATE_TXT_BUTTON sfFloatRect_intersects(&template_txt_btn[i]->hitbox, &game->gameplay->mouse_rect, NULL)
    #define CLICK_ON_TXT_BUTTON sfFloatRect_intersects(&txt_btn[i]->hitbox, &game->gameplay->mouse_rect, NULL)
    #define CLICK_ON_BUTTON sfFloatRect_intersects(&btn[i]->btn_rect, &game->gameplay->mouse_rect, NULL)
    #define MOUSE_OVER_BUTTON sfFloatRect_intersects(&btn[i]->btn_rect, &mouse, NULL)
    #define MOUSE_OVER_TEXT sfFloatRect_intersects(&text[i]->hitbox, &mouse, NULL)
    #define CLICK_IS_DETECTED game->gameplay->event.type == sfEvtMouseButtonReleased
    #define CLICK_IS_PRESSED game->gameplay->event.type == sfEvtMouseButtonPressed

#endif
