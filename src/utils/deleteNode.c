/*
** EPITECH PROJECT, 2022
** deleteNode
** File description:
** Functions to delete a node in a linked list
*/

#include "../../include/my_hunter.h"

static skeleton_t *freeNode(skeleton_t *node)
{
    sfSprite_destroy(node->sp);
    sfTexture_destroy(node->texture);
    free(node);
    return node;
}

void deleteNode(skeleton_t **skeletons, int id)
{
    skeleton_t *tmp = *skeletons;
    skeleton_t *save = NULL;

    if (tmp->next != NULL) {
        for (; tmp->next->id != id; tmp = tmp->next);
        if (tmp->next->next != NULL)
            save = tmp->next->next;
        tmp->next = freeNode(tmp->next);
        tmp->next = save;
    } else {
        tmp = freeNode(tmp);
        *skeletons = NULL;
    }
}