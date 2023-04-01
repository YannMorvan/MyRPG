/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_quadtree.c
*/

#include <stdlib.h>

#include "ice/memory.h"
#include "engine/collider.h"
#include "engine/collision/collision.h"

quadtree_t *create_quadtree(sfFloatRect rect, ui_t depth)
{
    quadtree_t *quadtree = ice_calloc(1, sizeof(quadtree_t));

    if (!quadtree)
        return NULL;
    quadtree->rect = rect;
    quadtree->depth = depth;
    quadtree->colliders = list_create();
    if (!quadtree->colliders)
        return NULL;
    return quadtree;
}
