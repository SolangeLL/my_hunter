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
    skeleton_t *temp = *skeletons, *prev;

    if (temp != NULL && temp->id == id) {
        *skeletons = temp->next;
        freeNodeSkeleton(temp);
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void deleteSlime(slime_t **slimes, int id)
{
    slime_t *temp = *slimes, *prev;

    if (temp != NULL && temp->id == id) {
        *slimes = temp->next;
        freeNodeSlime(temp);
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
