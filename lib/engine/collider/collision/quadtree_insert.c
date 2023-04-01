/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** quadtree_insert.c
*/


#include "engine/collision/collision.h"

static void quadtree_subdivide_insert(quadtree_t *quadtree,
    collider_t *collider)
{
    quadtree_insert(quadtree->nw, collider);
    quadtree_insert(quadtree->ne, collider);
    quadtree_insert(quadtree->sw, collider);
    quadtree_insert(quadtree->se, collider);
}

sfBool quadtree_insert(quadtree_t *quadtree, collider_t *collider)
{
    if (!sfFloatRect_intersects(&quadtree->rect, &collider->rect, NULL))
        return sfTrue;
    if (list_add(quadtree->colliders, collider))
        return sfFalse;
    if (quadtree->colliders->size < MAX_OBJECTS || quadtree->depth == MAX_DEPTH)
        return sfTrue;
    if (!quadtree->nw) {
        if (!create_child_quadtree(quadtree))
            return sfFalse;
        for (list_node_t *node = quadtree->colliders->head; node;
            node = node->next)
            quadtree_subdivide_insert(quadtree, node->value);
    }
    quadtree_subdivide_insert(quadtree, collider);
    return sfTrue;
}
