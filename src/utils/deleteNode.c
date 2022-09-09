/*
** EPITECH PROJECT, 2022
** deleteNode
** File description:
** Functions to delete a node in a linked list
*/

#include "../../include/my_hunter.h"

static skeleton_t *freeNodeSkeleton(skeleton_t *node)
{
    sfSprite_destroy(node->sp);
    sfTexture_destroy(node->texture);
    free(node);
    return node;
}

static slime_t *freeNodeSlime(slime_t *node)
{
    sfSprite_destroy(node->sp);
    sfTexture_destroy(node->texture);
    free(node);
    return node;
}

void deleteSkeleton(skeleton_t **skeletons, int id)
{
    skeleton_t *tmp = *skeletons;
    skeleton_t *save = NULL;

    if (tmp->next != NULL) {
        for (; tmp->next->id != id; tmp = tmp->next);
        if (tmp->next->next != NULL)
            save = tmp->next->next;
        tmp->next = freeNodeSkeleton(tmp->next);
        tmp->next = save;
    } else {
        tmp = freeNodeSkeleton(tmp);
        *skeletons = NULL;
    }
}

void deleteSlime(slime_t **slimes, int id)
{
    slime_t *tmp = *slimes;
    slime_t *save = NULL;

    if (tmp->next != NULL) {
        for (; tmp->next->id != id; tmp = tmp->next);
        if (tmp->next->next != NULL)
            save = tmp->next->next;
        tmp->next = freeNodeSlime(tmp->next);
        tmp->next = save;
    } else {
        tmp = freeNodeSlime(tmp);
        *slimes = NULL;
    }
}