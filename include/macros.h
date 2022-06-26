/*
** EPITECH PROJECT, 2022
** macro
** File description:
** Regroup all macros
*/

#ifndef MACROS_H_
    #define MACROS_H_
    #define WINDOW_INFO window->mode, "MY HUNTER", sfResize | sfClose, NULL
    #define CREATE_SOUND_BUF sfSoundBuffer_createFromFile
    #define CREATE_TEXTURE sfTexture_createFromFile
    #define IS_EVENT \
    sfRenderWindow_pollEvent(game->window->window, &game->gameplay->event)
    #define ESCAPE_IS_PRESSED game->gameplay->event.type == sfEvtKeyPressed \
    && sfKeyboard_isKeyPressed(sfKeyEscape)
    #define CLICK_ON_SLIME sfFloatRect_intersects(&slime->rect_scaled, \
    &game->gameplay->mouse_rect, NULL) == sfTrue && slime->shoot == 0
    #define CLICK_ON_SKELETON sfFloatRect_intersects(&game->display->skeleton->rect_scaled, \
    &game->gameplay->mouse_rect, NULL) == sfTrue && game->display->skeleton->shoot == 0

#endif /* !MACROS_H_ */
